from working import convert
import pytest


def test_minutes():
    assert convert("9:30 AM to 5:30 PM") == "09:30 to 17:30"
    assert convert("9:57 AM to 5:22 PM") == "09:57 to 17:22"


def test_hours():
    assert convert("12 AM to 5 AM") == "00:00 to 05:00"
    assert convert("2 AM to 12 PM") == "02:00 to 12:00"


def test_misc():
    with pytest.raises(ValueError):
        convert("9 AM - 5 PM")
    with pytest.raises(ValueError):
        convert("12:74 AM to 5:82 PM")