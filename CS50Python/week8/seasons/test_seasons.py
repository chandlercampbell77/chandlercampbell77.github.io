from seasons import convert_date, convert_minutes


def test_seasons():
    assert convert_date("1999-07-03") == 12687840
    assert convert_minutes(1) == "One"