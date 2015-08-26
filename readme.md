
cxx-image [![LICENSE](https://img.shields.io/github/license/tsu-complete/cxx-image.svg)](https://github.com/tsu-complete/cxx-image/blob/master/LICENSE)
===

> image structure for c++

Requirements
---

Minimum `C++11`
Requires `tsu-complete/cxx-array`

Install
---

```sh
$ npm install -g bower

$ bower install tsu-complete/cxx-array
```

Usage
---

```c++
#include <cxx-image/index.hxx>

int main ( int argc, char *argv[] )
{
    Image image<Pixel3Byte>(3, 3);

    // load 3x3 RGB image ...

    // manipulate data
    image[0][0] = { 0, 0, 0 }; // zero out top left pixel

    return 0;
}
```

```sh
$ c++ -std=c++11 -Ibower_components
```

Todo
---

- add helper functionality
 - normalize
 - greyscale
- add iterators
- document
- add testing

