#include "mainwindow.h"
Mat Gcode(Mat intial_imge)
{
    Mat canny_output;
    Mat gray_imge;//定义灰度图
    int nThresh = 80;//初始阈值
    cvtColor(intial_imge, gray_imge, CV_BGR2GRAY);// 转成灰度
    blur(gray_imge, gray_imge, Size(3, 3));//模糊化降噪

    // 创建窗口
    //imshow("原图", intial_imge);

    // 用Canny算子检测边缘
    Canny(gray_imge, canny_output, nThresh, nThresh * 2, 3);
    //return canny_output;
     ProcesseImage(canny_output);
	 return canny_output;
}

