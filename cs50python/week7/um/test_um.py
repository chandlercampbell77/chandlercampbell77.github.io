from um import count


def test_word():
    assert count("yummy") == 0
    assert count("my tummy hurts") == 0

def test_space():
    assert count(" um ") == 1
    assert count("Um yeah") == 1


def test_multiple():
    assert count("um, um I'm not sure") == 2
    assert count("um, the food was yummy but it hurt my tummy") == 1