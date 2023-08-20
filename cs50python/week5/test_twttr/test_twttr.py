from twttr import shorten


def test_uppercase():
    assert shorten("TWITTER") == "TWTTR"
    assert shorten("HELLO") == "HLL"


def test_lowercase():
    assert shorten("twitter") == "twttr"
    assert shorten("hello") == "hll"


def test_mixedcase():
    assert shorten("TWItter") == "TWttr"
    assert shorten("HEllo") == "Hll"


def test_spaces():
    assert shorten("hello, world") == "hll, wrld"
    assert shorten("twitter rules") == "twttr rls"


def test_numbers():
    assert shorten("tw1tt3r") == "tw1tt3r"
    assert shorten("h3ll0") == "h3ll0"