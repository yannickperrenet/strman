from strmanwrapper import split


def main():
    ex = "Hello, world!"
    c_ans = split(ex, " ")
    py_ans = ex.split(" ")
    print("Python answer:", py_ans)
    print("C answer:", c_ans)
    assert py_ans == c_ans


if __name__ == "__main__":
    main()
