#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17

using namespace cv;
using namespace std;
extern "C" uchar* _start(
   uchar* new_image,
    uchar* old_image,
    short  brit,
    // Size_<int>  size
    int size
);

int main( int argc, char** argv )
{
    CommandLineParser parser( argc, argv, "{@input | lena.jpg | input image}" );
    Mat image = imread( samples::findFile( parser.get<String>( "@input" ) ) );
    clock_t time_req;
    time_req = clock();
    if( image.empty() )
    {
      cout << "Could not open or find the image!\n" << endl;
      cout << "Usage: " << argv[0] << " <Input image>" << endl;
      return -1;
    }
    Mat new_image = Mat::zeros( image.size(), image.type() );
    double alpha = 1.0; /*< Simple contrast control */
    int beta = 0;       /*< Simple brightness control */
   
    // cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
    // cout << "* Enter the beta value [0-100]: ";    cin >> beta;
   
    
    uchar* image_data = image.data;
    uchar* new_image_data = new_image.data;
    // cout<< "image size"<<image.size();
    // int image_size = static_cast<int>(image.size());
    short brightnessValue = beta;

   
    _start(new_image.data, image.data, 75, image.rows * image.cols * image.channels());


    // new_image.data = img_data_ptr;
  
    //  cout<< "image size" << img_data_ptr;

    // cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    time_req = clock() - time_req;
     cout << "Running Time " << time_req << std::endl;

    imwrite( "orginal.jpeg", image );
    imwrite( "newImage1.jpeg", new_image);
    
    
    waitKey();
    return 0;
}