Mac vscode配置opencv
步骤：
1. 安装cmake,pkg-config,opencv
   ```
   brew install cmake
   brew install pkg-config
   brew install opencv
   ```
2. 修改c_cpp_properties.json,task.json
   ```
    c_cpp_properties.json
    {
        "configurations": [
            {
                "name": "Mac",
                "includePath": [
                    "${workspaceFolder}/**",
                    "/Library/Developer/CommandLineTools/usr/include/c++/v1",
                    "/usr/local/Cellar/opencv/4.5.5_1/include/opencv4/opencv2",
                    "/Library/Developer/CommandLineTools/usr/lib/clang/13.1.6/include",
                    "/usr/local/Cellar/opencv/4.5.5_1/include",
                    "/usr/local/Cellar/opencv/4.5.5_1/lib",
                    "/usr/local/Cellar/opencv/4.5.5_1/include/opencv4",
                    "/Library/Developer/CommandLineTools/usr/include",
                    "/usr/local/include/opencv4"
                ],
                "defines": [],
                "macFrameworkPath": [
                    "/System/Library/Frameworks",
                    "/Library/Frameworks"
                ],
                "compilerPath": "/usr/bin/clang",
                "cStandard": "c11",
                "cppStandard": "c++17",
                "intelliSenseMode": "clang-x64"
            }
        ],
        "version": 4
    }
   ```
   ```
   task.json
   {
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: clang 生成活动文件",
            "command": "/usr/bin/clang",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}",
                "-I",
                "/usr/local/opt/opencv/include/opencv4",
                "-L",
                "/usr/local/opt/opencv/lib",
                "-l",
                "opencv_gapi",
                "-l",
                "opencv_stitching",
                "-l",
                "opencv_alphamat",
                "-l",
                "opencv_aruco",
                "-l",
                "opencv_barcode",
                "-l",
                "opencv_bgsegm",
                "-l",
                "opencv_bioinspired",
                "-l",
                "opencv_ccalib",
                "-l",
                "opencv_dnn_objdetect",
                "-l",
                "opencv_dnn_superres",
                "-l",
                "opencv_dpm",
                "-l",
                "opencv_face",
                "-l",
                "opencv_freetype",
                "-l",
                "opencv_fuzzy",
                "-l",
                "opencv_hfs",
                "-l",
                "opencv_img_hash",
                "-l",
                "opencv_intensity_transform",
                "-l",
                "opencv_line_descriptor",
                "-l",
                "opencv_mcc",
                "-l",
                "opencv_quality",
                "-l",
                "opencv_rapid",
                "-l",
                "opencv_reg",
                "-l",
                "opencv_rgbd",
                "-l",
                "opencv_saliency",
                "-l",
                "opencv_sfm",
                "-l",
                "opencv_stereo",
                "-l",
                "opencv_structured_light",
                "-l",
                "opencv_phase_unwrapping",
                "-l",
                "opencv_superres",
                "-l",
                "-l",
                "opencv_surface_matching",
                "-l",
                "opencv_tracking",
                "-l",
                "opencv_highgui",
                "-l",
                "opencv_datasets",
                "-l",
                "opencv_text",
                "-l",
                "opencv_plot",
                "-l",
                "opencv_videostab",
                "-l",
                "opencv_videoio",
                "-l",
                "opencv_viz",
                "-l",
                "opencv_wechat_qrcode",
                "-l",
                "opencv_xfeatures2d",
                "-l",
                "opencv_shape",
                "-l",
                "opencv_ml",
                "-l",
                "opencv_ximgproc",
                "-l",
                "opencv_video",
                "-l",
                "opencv_xobjdetect",
                "-l",
                "opencv_objdetect",
                "-l",
                "opencv_calib3d",
                "-l",
                "opencv_imgcodecs",
                "-l",
                "opencv_features2d",
                "-l",
                "opencv_dnn",
                "-l",
                "opencv_flann",
                "-l",
                "opencv_xphoto",
                "-l",
                "opencv_photo",
                "-l",
                "opencv_imgproc",
                "-l",
                "opencv_core",
                "-std=c++17"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build",
            "detail": "编译器: /usr/bin/clang"
        }
    ]
    }
   ```
c_cpp_properties.json中的includePath中的部分基础库路径可以通过一下途径获取
```
gcc -v -E -x c++ -
...
#include "..." search starts here:
#include <...> search starts here:
 /usr/local/include
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1
 /Library/Developer/CommandLineTools/usr/lib/clang/13.1.6/include
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include
 /Library/Developer/CommandLineTools/usr/include
 /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks (framework directory)
End of search list.
```
task.json中添加的链接库可以通过一下途径获得
```
pkg-config --cflags --libs opencv4
-I/usr/local/opt/opencv/include/opencv4 -L/usr/local/opt/opencv/lib -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_barcode -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_wechat_qrcode -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_dnn -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core
```
如果使用code runner运行程序，需要在其设置里增加动态链接库以及指定C++标准
操作方法：https://blog.csdn.net/weixin_45774350/article/details/123135372
结果：
```
"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt `pkg-config --cflags --libs opencv4` -std=c++11 && $dir$fileNameWithoutExt",
```

其他报错参考：
opencv 报错
```
In file included from test.cpp:2:
/usr/local/include/opencv4/opencv2/core.hpp:52:10: fatal error: 'opencv2/core/cvdef.h' file not found
#include "opencv2/core/cvdef.h"
```
建立一个软链接
```
ln -s /usr/local/include/opencv4/opencv2/ /usr/local/include/opencv2
```
vscode配置c++11
https://blog.csdn.net/weixin_45774350/article/details/123135372

opencv 报错
```
Undefined symbols for architecture x86_64:
  "cv::Mat::~Mat()", referenced from:
      _main in test-a34b4f.o
  "cv::imread(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, int)", referenced from:
      _main in test-a34b4f.o
  "cv::imshow(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> > const&, cv::_InputArray const&)", referenced from:
      _main in test-a34b4f.o
  "cv::waitKey(int)", referenced from:
      _main in test-a34b4f.o
ld: symbol(s) not found for architecture x86_64
```
没有引入链接库，使用code runner运行时，需要配置一下
```
"cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt `pkg-config --cflags --libs opencv4` -std=c++11 && $dir$fileNameWithoutExt",
```

https://blog.csdn.net/AIhub/article/details/123516775

https://blog.csdn.net/Bacon_Lee/article/details/117598884