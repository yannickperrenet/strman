import ctypes
import pathlib


libname = pathlib.Path().absolute() / "strman.so"
C_LIB = ctypes.CDLL(str(libname))


class _SplitResult(ctypes.Structure):
    _fields_ = [
        ("len", ctypes.c_int),
        ("storage", ctypes.c_char_p),
        ("p", ctypes.POINTER(ctypes.c_char_p)),
    ]


def _free_split_result(p: _SplitResult) -> None:
    c_free = C_LIB.free_split_result
    c_free.argtypes = [_SplitResult]
    c_free(p)


def split(s: str, char: str) -> list[str]:
    c_split = C_LIB.split
    c_split.argtypes = [ctypes.c_char_p, ctypes.c_char]
    c_split.restype = _SplitResult

    c_res = c_split(s.encode("utf-8"), char.encode("utf-8"))
    res = [c_res.p[i].decode("utf-8") for i in range(c_res.len)]
    _free_split_result(c_res)
    return res
