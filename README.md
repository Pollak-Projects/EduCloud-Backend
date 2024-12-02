# EduCloud-Backend

### New Installation v2

1. Install Visual Studio 2022 with C++ development tools for desktop
2. Install vcpkg in a different directory than the project directory
```shell
git clone https://github.com/microsoft/vcpkg.git
.\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
```
3. Clone the whole project and update all submodules
```shell
git clone https://github.com/Pollak-Projects/EduCloud.git
git submodule update --init --recursive
```
4. Set up linker in Clion  
Go to `Build, Execution, Deployment -> Toolchains` and add `Visual Studio` compiler
5. Set up and build drogon
    > Note this only works on Windows x64
   1. Open the `drogon` folder in Clion
   2. Copy and fill out `CMakeUserPresets.json` according to `CMakeUserPresets.json.example`
   3. Add your vcpkg directory to Clion  
      Press `double Shift` in Clion and search for `vcpkg` and add `<your path>` as the vcpkg directory
   4. Reload the cmake project (you can find the cmake tab in the bottom left corner)
   5. Make sure `Debug Build Drogon-Visual Studio` is selected as the cmake profile (you can find it in the top right corner)
   6. Make sure `drogon` is selected as the run configuration (you can find it in the top right corner)
   7. Build `drogon`
   8. Add the following to your user and system `PATH` environment variables
   ```
   <your_path_to_EduCloud-Backend>\drogon\install\bin;
   <your_path_to_EduCloud-Backend>\drogon\install\lib\cmake\Drogon;
   <your_path_to_EduCloud-Backend>\drogon\install\lib\cmake\Trantor;
   <your_path_to_EduCloud-Backend>\drogon\build\vcpkg_installed\x64-windows\bin;
   <your_path_to_EduCloud-Backend>\drogon\build\vcpkg_installed\x64-windows\debug\bin;
   ```
   8. Test by running `drogon_ctl` in the terminal
6. Set up and build the project
   1. Open the `EduCloud-Backend` folder in Clion
   2. Copy and fill out `CMakeUserPresets.json` according to `CMakeUserPresets.json.example`
   3. Add your vcpkg directory to Clion  
      Press `double Shift` in Clion and search for `vcpkg` and add `<your path>` as the vcpkg directory
   4. Reload the cmake project (you can find the cmake tab in the bottom left corner)
   5. Make sure `Debug-Visual Studio` is selected as the cmake profile (you can find it in the top right corner)
   6. Make sure `EduCloud-Backend` is selected as the run configuration (you can find it in the top right corner)
   7. Build the project
   8. Run the project
   9. Test by going to `http://localhost:3300/` in your browser
   10. Don't forget to reload CMake when adding a new .h or .cpp file

#### Extra resources:
- cmake complaining about missing MSVC [link](https://github.com/microsoft/vcpkg/issues/22074)
- drogon installation video [link](https://www.youtube.com/watch?v=0ojHvu0Is6A) (Note: This is NOT for compiling by source like we do here)
- linker complaining [link](https://github.com/davisking/dlib/issues/2921)


### Installation (**Outdated**)

> Important:  
> THIS IS OUTDATED, PLEASE REFER TO THE NEW INSTALLATION GUIDE

You can find the new guide at the top of this file

> The following is here for reference

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