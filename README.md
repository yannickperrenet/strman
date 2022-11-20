# `ctypes` in Python to call C function

```sh
# In case you want to run the executable: ./strman
gcc -o strman strman.c

# Make sure to run this if you update the strman.c file!
gcc -fPIC -shared -o strman.so strman.c

python3 example.py
```

Produces the output:
```plain
Python answer: ['Hello,', 'world!']
C answer: ['Hello,', 'world!']
```

## Project context
I was toying around with C to better understand memory allocation and felt like implementing string
splitting (e.g. split `"Hello, world!"` on `" "` gives `"Hello,"` and `"world!"`) would be a good
first project. Then after implementing it, I figured why don't I try to call this function from
Python. I might as well learn something new that I can use that knowledge again in the future to
optimize some Python code.
