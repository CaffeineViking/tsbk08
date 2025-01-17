libaac
======

Here is another tiny implementation of the Adaptive Arithmetic Coding (AAC) entropy coding method. It contains both the compression and decompression algorithm. It's composed of two parts: the library (`libaac`) and the program (`aacx` and `aacz`) that can be used to decompress and compress binary data. `aacz <input> <output>` compresses the `<input>` to a new file `<output>` using the AAC algorithm. Decompression happens in the same way but with the `aacx` program instead.

Building
--------

1. Place yourself in the root directory of this project.
2. Acquire the latest version of the `premake5` build system.
3. Thereafter, execute `premake5 gmake` if building on Make.
4. Finally, issue the command `make -C build` and wait.
5. When complete, either `bin` or `lib` are built.
6. Tests can be run with `bin/*-tests` program.

Structure
---------

* `bin`: contains the built software and accompanying testing suite.
* `build`: stores intermediate object files and generated GNU Make files.
    * `obj`: has all of the generated object files given under compilation.
    * `Makefile`: automatically generated by executing `premake5 gmake`.
    * `*.make`: program specific make config for augmenting `Makefile`.
* `docs`: any generated documentation for this project is over here.
* `include`: both external and internal project headers are here.
    * `foreign`: any foreign headers which should be included.
    * `project directories`: internal headers for the project.
* `lib`: any generated libraries from the project reside here.
* `license.md`: please look through this very carefully.
* `premake5.lua`: configuration file for the build system.
* `readme.md`: this file, contains information on the project.
* `share`: any extra data that needs to be bundled should be here.
* `src`: all source code for the project should be located below here.
    * `project directories`: source code for specific project build.
    * `foreign`: any external source files which might be needed.
* `tests`: source code for the project's testing suite, using Catch syntax.
    * `project directories`: project specific testing suite for one build.
