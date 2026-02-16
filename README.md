# hjlib

This repository is about my custom C Library.

## How to build

### Build

```sh
make
```

### Install

```sh
sudo make install
```

### Uninstall

```sh
sudo make uninstall
```

### Test

```sh
make test
```

## How to use

- After installing a library, use it like below.

```c
#include <stdio.h>
#include <hjlib/hjlib.h>
#include <hjlib/ds/linked_list.h>
#include <hjlib/ds/stack.h>

int main(void) {
    hj_hello();
    print_linked_list();
    print_stack();
    return 0;
}
```

## To generate compile_commands.json

`bear -- <build_commands>`

```sh
bear -- make test
```

OR

```sh
bear clang -I/usr/local/include -L/usr/local/lib -lhjlib -o build/test test.c
```
