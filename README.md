# EduCloud-Backend




### Installation

1. Install visual studio 2022 with C++ development tools for desktop

2. Install vcpkg in a different directory than the project directory

```
git clone https://github.com/microsoft/vcpkg.git
.\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
```

3. Add your vcpkg directory to Clion

Press `double Shift` in Clion and search for `vcpkg` and add `<your path>` as the vcpkg directory

4. Install the required libraries

Run the project in Clion, and it will install the required libraries `Shift + F10`  
This will take a while

5. Set up linker in Clion

Go to `Build, Execution, Deployment -> Toolchains` and add the `Visual Studio` compiler  
Then go to `Build, Execution, Deployment -> CMake` and set in `Debug` Toolchain to `Visual Studio`

6. Set the styling in Clion

In Clion, go to `Editor -> Code Style -> C/C++` and set `Clion formatter` to `ClangFormat`

7. Set up `drogon_ctl`

Add the following to your user `PATH` environment variable


```
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\tools\drogon
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\bin
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\lib
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\include
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\share
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\debug\bin
<your_path_to_the_project_folder>\cmake-build-debug\vcpkg_installed\x64-windows\debug\lib
```

8. Don't forget to reload CMake when adding a new .h or .cpp file

9. Run the project

#### Extra resources:
- cmake complaining about missing MSVC [link](https://github.com/microsoft/vcpkg/issues/22074)
- drogon installation video [link](https://www.youtube.com/watch?v=0ojHvu0Is6A)
- linker complaining [link](https://github.com/davisking/dlib/issues/2921)