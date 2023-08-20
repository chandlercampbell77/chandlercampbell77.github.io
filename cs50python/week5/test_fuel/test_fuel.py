from fuel import convert, gauge
import pytest


def test_convert():
    assert convert("3/4") == 75
    assert convert("1/2") == 50
    with pytest.raises(ValueError):
          convert("cat/dog")
    with pytest.raises(ValueError):
          convert("10/5")
    with pytest.raises(ZeroDivisionError):
          convert("6/0")


def test_gauge():
      assert gauge(50) == "50%"
      assert gauge(99) == "F"
      assert gauge(1) == "E"