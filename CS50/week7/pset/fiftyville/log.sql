-- Keep a log of any SQL queries you execute as you solve the mystery.

-- find out description of crime
SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
AND street = 'Humphrey Street';

-- search interviews
SELECT transcript FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bake%";

-- follow first lead: search security log from bakery and find names of suspects using license plates
SELECT name FROM people
WHERE license_plate IN
(
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 14
    AND minute < 26
);

-- follow second lead: search atm transactions and find names of suspects using account numbers of suspects
SELECT name FROM people
WHERE id IN
(
    SELECT person_id FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
);

-- follow third lead: search flights the day after the crime
SELECT id FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour ASC
LIMIT 1;

-- search airports
SELECT * FROM airports;

-- search passengers on flight
SELECT passport_number FROM passengers
WHERE flight_id IN
(
    SELECT id FROM flights
    WHERE year = 2021
    AND month = 7
    AND day = 29
    ORDER BY hour ASC
    LIMIT 1

);

-- find names of suspects
SELECT name FROM people
WHERE passport_number IN
(
    SELECT passport_number FROM passengers
    WHERE flight_id IN
    (
        SELECT id FROM flights
        WHERE year = 2021
        AND month = 7
        AND day = 29
        ORDER BY hour ASC
        LIMIT 1
    )
)
AND license_plate IN
(
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute > 14
    AND minute < 26
)
AND id IN
(
    SELECT person_id FROM bank_accounts
    WHERE account_number IN
    (
        SELECT account_number FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = 'Leggett Street'
        AND transaction_type = 'withdraw'
    )
)
AND phone_number IN
(
    SELECT caller FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 61
);

-- find phone number of Bruce
SELECT phone_number FROM people
WHERE name = 'Bruce';

-- find accomplice of Bruce
SELECT name FROM people
WHERE phone_number IN
(
    SELECT receiver FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 61
    AND caller =
    (
        SELECT phone_number FROM people
        WHERE name = 'Bruce'
    )
);