from plates import is_valid


def test_start():
    assert is_valid("X50") == False
    assert is_valid("50CS") == False


def test_max_min():
    assert is_valid("L") == False
    assert is_valid("computer") == False


def test_numbers():
    assert is_valid("CS50HA") == False
    assert is_valid("CS05") == False


def test_special_char():
    assert is_valid(" ") == False
    assert is_valid("cs##50") == False
