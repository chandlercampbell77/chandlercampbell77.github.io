from numb3rs import validate


def test_ipranges():
    assert validate("255.255.255.255")
    assert validate("192.168.1.1")
    assert validate("192.168.1.255")
    assert validate("0.0.0.0")
    assert not validate("192.168.1")
    assert not validate("192.168.1.256")
    assert not validate("192.168.1.255.1")
    assert not validate("512.512.512.512")
    assert not validate("512.512.512.512.512")
    assert not validate("cat")


def test_mixed():
    assert validate("1.22.164.255")
    assert validate("0.255.1.33")
    assert not validate("cat.dog.hamster.snake")
    assert not validate("300.521.524.275")
    assert not validate("1000.1000.1000.1000")
    assert not validate("-1.-5.-10.-100")
    assert not validate("0.0.0.0.0")