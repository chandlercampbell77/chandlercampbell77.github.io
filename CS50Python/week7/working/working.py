import re


def main():
    print(convert(input("Hours: ")))


def convert(s):
    s.strip().upper()
    if ":" in s:
        if re.search(r"([0-9]:[0-5][0-9]|1[0-2]:[0-5][0-9]) (AM|PM) to ([0-9]:[0-5][0-9]|1[0-2]:[0-5][0-9]) (AM|PM)", s, re.IGNORECASE):
            begin, end = s.split(" to ")
            if "AM" in begin:
                begin = begin.replace(" AM", "")
                begin_hour, begin_min = begin.split(":")
                begin_hour = int(begin_hour)
                begin_min = int(begin_min)
                if begin_hour == 12:
                    begin_hour = 0
            else:
                begin = begin.replace(" PM", "")
                begin_hour, begin_min = begin.split(":")
                begin_hour = int(begin_hour)
                begin_min = int(begin_min)
                if begin_hour != 12:
                    begin_hour = begin_hour + 12
            if "AM" in end:
                end = end.replace(" AM", "")
                end_hour, end_min = end.split(":")
                end_hour = int(end_hour)
                end_min = int(end_min)
                if end_hour == 12:
                    end_hour = 0
            else:
                end = end.replace(" PM", "")
                end_hour, end_min = end.split(":")
                end_hour = int(end_hour)
                end_min = int(end_min)
                if end_hour != 12:
                    end_hour = end_hour + 12
            return f"{begin_hour:02}:{begin_min:02} to {end_hour:02}:{end_min:02}"
        else:
            raise ValueError
    else:
        if re.search(r"([0-9]|1[0-2]) (AM|PM) to ([0-9]|1[0-2]) (AM|PM)", s, re.IGNORECASE):
            begin, end = s.split(" to ")
            if "AM" in begin:
                begin_hour = begin.replace(" AM", "")
                begin_hour = int(begin_hour)
                if begin_hour == 12:
                    begin_hour = 0
            else:
                begin_hour = begin.replace(" PM", "")
                begin_hour = int(begin_hour)
                if begin_hour != 12:
                    begin_hour = begin_hour + 12
            if "AM" in end:
                end_hour = end.replace(" AM", "")
                end_hour = int(end_hour)
                if end_hour == 12:
                    end_hour = 0
            else:
                end_hour = end.replace(" PM", "")
                end_hour = int(end_hour)
                if end_hour != 12:
                    end_hour = end_hour + 12
            return f"{begin_hour:02}:00 to {end_hour:02}:00"
        else:
            raise ValueError



if __name__ == "__main__":
    main()