from project import get_number, get_country_json, get_facts, generate_question, check_guess, calculate_percent
import pytest


def test_get_country_json():
    with pytest.raises(Exception):
        get_country_json(["Cat", "Dog"])
    with pytest.raises(Exception):
        get_country_json([1, 2])


def test_get_facts():
    with pytest.raises(Exception):
        get_facts("test")
    with pytest.raises(Exception):
        get_facts({"key": "value"})


def test_calculate_percent():
    assert calculate_percent(2, 5) == 40.0
    assert calculate_percent(1, 10) == 10.0