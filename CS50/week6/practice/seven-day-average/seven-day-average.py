import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases_dict = calculate(reader)

    # Create a list to store selected states
    states_list = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases_dict:
            states_list.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases_dict, states_list)


# Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    new_cases_dict = dict()
    total_cases_dict = dict()

    for row in reader:
        state = row["state"]
        date = row["date"]
        current_cases = int(row["cases"])

        if state not in total_cases_dict:
            total_cases_dict[state] = current_cases
            new_cases_dict[state] = []
        else:
            new_case_amount = current_cases - total_cases_dict[state]
            total_cases_dict[state] = current_cases

            if state not in new_cases_dict:
                new_cases_dict[state] = []
            if len(new_cases_dict[state]) >= 14:
                new_cases_dict[state].pop(0)
            new_cases_dict[state].append(new_case_amount)

    return new_cases_dict


# Calculate and print out seven day average for given state
def comparative_averages(new_cases_dict, states_list):
    for state in states_list:
        this_week_cases = new_cases_dict[state][7:]
        last_week_cases = new_cases_dict[state][:7]
        avg_this_week = round(sum(this_week_cases) / 7)
        avg_last_week = round(sum(last_week_cases) / 7)

        difference = avg_this_week - avg_last_week

        if difference > 0:
            msg = "an increase"
        else:
            msg = "a decrease"

        try:
            difference = difference / avg_last_week
            difference = round(difference * 100, 2)
        except ZeroDivisionError:
            raise ZeroDivisionError
        print(f"{state} had a 7-day average of {avg_this_week} and {msg} of {difference}%.")

main()