/*
 * gdal_image-io.cpp -- Load GIS data into OpenCV Containers using the Geospatial Data Abstraction Library
*/

// OpenCV Headers
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace cv;

// C++ Standard Libraries
#include <iostream>
using namespace std;

vector<Mat> planes;
int n_bands = 0, bands_slider = 1;

/*
 * @function on_trackbar
 * @brief Callback for trackbar
 */
void on_trackbar( int, void* )
{
  Mat plane_vis;

  if (bands_slider == 0)
    plane_vis = planes[0];
  else
    plane_vis = planes[bands_slider-1];

  //cout << "Showing image with index " << bands_slider-1 << endl;
  //resize(plane_vis, plane_vis, Size(), 0.5, 0.5);
  //normalize(plane_vis, plane_vis, 0, 255, NORM_MINMAX, CV_8UC1);
  imshow( "Multispectral bands", plane_vis );
}


/*
 * Main Function
*/
int main( int argc, char* argv[] ){

  if ( argc != 2 )
  {
    printf("usage: gdal-image-io <Image_Path>\n");
    return -1;
  }

  Mat image;
  image = imread( argv[1], IMREAD_LOAD_GDAL );

  cout << "-- Output script" << endl;
  cout << "   Size: " << image.size() << endl;
  cout << "   Channels: " << image.channels() << endl;

  if ( !image.data )
  {
    printf("No image data \n");
    return -1;
  }

  int n_bands = image.channels();

  split(image, planes);

  namedWindow("Multispectral bands", WINDOW_AUTOSIZE );

  createTrackbar( "Band", "Multispectral bands", &bands_slider, n_bands, on_trackbar );
  on_trackbar( bands_slider, 0 );

  waitKey(0);
  return 0;
}
