from bank import value


def test_hello():
    assert value("hello") == 0
    assert value("HELLO") == 0
    assert value(" hello ") == 0


def test_h():
    assert value("hey") == 20
    assert value("HEY") == 20
    assert value(" hey ") == 20


def test_no_h():
    assert value("yo") == 100
    assert value("sup") == 100
    assert value(" What's going on? ") == 100