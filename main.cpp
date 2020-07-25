#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;
using namespace cv;
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
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    // cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
    // cout << "* Enter the beta value [0-100]: ";    cin >> beta;
    alpha = 1;
    beta = 45;
    for( int y = 0; y < image.rows; y++ ) {
        for( int x = 0; x < image.cols; x++ ) {
            for( int c = 0; c < image.channels(); c++ ) {
                new_image.at<Vec3b>(y,x)[c] =
                  saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
            }
        }
    }
       uchar* image_data = image.data;
    uchar* new_image_data = new_image.data;
    cout << "Running Time" << clock() - time_req<<endl;
    // cout << "The image is" << image_data <<endl;



    imwrite( "orginal.jpeg", image );
    imwrite( "newImage1.jpeg", new_image );
    
    waitKey();
    return 0;
}