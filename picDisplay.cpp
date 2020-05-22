#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstdio>

using namespace cv;
using namespace std;

// int readFileList(char *basePath)
// {
//     DIR *dir;
//     struct dirent *ptr;
//     char base[1000];

//     if ((dir=opendir(basePath)) == NULL)
//     {
//         perror("Open dir error...");
//         exit(1);
//     }

//     while ((ptr=readdir(dir)) != NULL)
//     {
//         if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
//             continue;
//         else if(ptr->d_type == 8)    ///file
//             printf("d_name:%s/%s\n",basePath,ptr->d_name);
//         else if(ptr->d_type == 10)    ///link file
//             printf("d_name:%s/%s\n",basePath,ptr->d_name);
//         else if(ptr->d_type == 4)    ///dir
//         {
//             memset(base,'\0',sizeof(base));
//             strcpy(base,basePath);
//             strcat(base,"/");
//             strcat(base,ptr->d_name);
//             readFileList(base);
//         }
//     }
//     closedir(dir);
//     return 1;
// }
bool expiration()
{
    return false;
}

void display(string& pic, int& timeDuration)
{
    Mat img = imread(pic);
    if(img.empty())
    {
        cout << "can not load image... try next" << endl;
    }
    else
    {
        imshow("FullScreen", img);
        waitKey(timeDuration);
    }
}

int main(int argc, const char** argv)
{

    DIR *dir = NULL;
    struct dirent *ptr = NULL;
    int timeDuration = 5000;
    string picPath = "/home/root/pic/";
    string fullPath = "/*.jpg";
    string fixedPic = "/home/liul/lliu/temp/picDisplay/test.jpg";

    namedWindow("FullScreen", WINDOW_GUI_EXPANDED);
    setWindowProperty("FullScreen", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN );

    if(argc != 3)
    {
        cout << "usage: picDisplay <path> <timeDuration(second)>"<< endl;
    }
    else
    {
        timeDuration = atoi(argv[2])*1000;
        picPath = argv[1];
        cout << "timeDuration = " << timeDuration << endl;
        cout << "picPath = " << picPath << endl;
        // fullPath = picPath + fullPath;
        // cout << "fullPath = " << fullPath << endl;
    }

    if(expiration())
    {
        cout << "Expiration for DEMO..." << endl;
        return -1;
    }


    while(true)
    {
        if ((dir=opendir(picPath.c_str())) == NULL)
        {
            cout << "Open dir error..." << endl;
            return -1;
        }
        while ((ptr=readdir(dir)) != NULL)
        {
            if(strcmp(ptr->d_name,".")==0 || strcmp(ptr->d_name,"..")==0)    ///current dir OR parrent dir
                continue;
            else if(ptr->d_type == 8)    ///file
            {
                fullPath = picPath + "/" + ptr->d_name;
                cout << "fullPath = " << fullPath << endl;
                display(fullPath, timeDuration);
                remove(fullPath.c_str());
            }
        }
        cout << "refresh file list" << endl;
        // usleep(3000000);
        closedir(dir);
        display(fixedPic, timeDuration);
    }
 
    cout << "done ~~~" << endl;
    return 0;
}
