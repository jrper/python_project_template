"""Test Module."""

def test_import():
    import example

def test_Example():
    import example

    ex = example.Example("Test")

    assert(ex.name=="Test") 

    ex.name = "Test2"

    assert(ex.name=="Test2")