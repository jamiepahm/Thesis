// Convert String^ to std::string
#include <msclr/marshal_cppstd.h>

// For string to become filesystem path
#include <experimental/filesystem>

// Math
#include <cmath>

// For C++
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
//Canny
#include <cmath>
#include <vector>
#include "canny.h"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>

using namespace std;
using namespace cv;
using std::vector;
	
#pragma once

namespace form1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for rgb_hsi_form
	/// </summary>
	public ref class rgb_hsi_form : public System::Windows::Forms::Form
	{
	public:
		rgb_hsi_form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~rgb_hsi_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::OpenFileDialog^  openFile;
	public: System::Windows::Forms::PictureBox^  img_Hue;
	private:
	public: System::Windows::Forms::PictureBox^  img_Saturation;




	private: System::Windows::Forms::Label^  lblHue;
	private: System::Windows::Forms::Label^  lblSaturation;

	private:


	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->img_Hue = (gcnew System::Windows::Forms::PictureBox());
			this->img_Saturation = (gcnew System::Windows::Forms::PictureBox());
			this->lblHue = (gcnew System::Windows::Forms::Label());
			this->lblSaturation = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_Hue))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_Saturation))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(12, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(123, 28);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Open File";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &rgb_hsi_form::btnOpen_Click);
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFile";
			// 
			// img_Hue
			// 
			this->img_Hue->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->img_Hue->Location = System::Drawing::Point(12, 46);
			this->img_Hue->Name = L"img_Hue";
			this->img_Hue->Size = System::Drawing::Size(336, 222);
			this->img_Hue->TabIndex = 1;
			this->img_Hue->TabStop = false;
			// 
			// img_Saturation
			// 
			this->img_Saturation->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->img_Saturation->Location = System::Drawing::Point(354, 46);
			this->img_Saturation->Name = L"img_Saturation";
			this->img_Saturation->Size = System::Drawing::Size(336, 222);
			this->img_Saturation->TabIndex = 2;
			this->img_Saturation->TabStop = false;
			// 
			// lblHue
			// 
			this->lblHue->AutoSize = true;
			this->lblHue->Location = System::Drawing::Point(321, 271);
			this->lblHue->Name = L"lblHue";
			this->lblHue->Size = System::Drawing::Size(27, 13);
			this->lblHue->TabIndex = 3;
			this->lblHue->Text = L"Hue";
			// 
			// lblSaturation
			// 
			this->lblSaturation->AutoSize = true;
			this->lblSaturation->Location = System::Drawing::Point(635, 271);
			this->lblSaturation->Name = L"lblSaturation";
			this->lblSaturation->Size = System::Drawing::Size(55, 13);
			this->lblSaturation->TabIndex = 4;
			this->lblSaturation->Text = L"Saturation";
			// 
			// rgb_hsi_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(703, 391);
			this->Controls->Add(this->lblSaturation);
			this->Controls->Add(this->lblHue);
			this->Controls->Add(this->img_Saturation);
			this->Controls->Add(this->img_Hue);
			this->Controls->Add(this->btnOpen);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"rgb_hsi_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RGB to HSI";
			this->TopMost = true;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_Hue))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->img_Saturation))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	#pragma endregion

	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ message = "";
		System::String^ final_path = "";
		System::String^ img_change = "";

		rgb_hsi_form::openFile->InitialDirectory = "C://Users/Acer User/Pictures/Inspirations";
		openFile->Filter = "JPG (*.jpg)|*.jpg|All files (*.*)|*.*";
		openFile->FilterIndex = 2;
		openFile->RestoreDirectory = true;

		if (openFile->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			float r, g, b, h, s, in;

			cv::String img_path = msclr::interop::marshal_as<std::string>(openFile->FileName);
			cv::Mat image = cv::imread(img_path);
			//resize(image, image, Size(), 0.5, 0.5);

			string img_path2 = img_path;

			//*** GET FILENAME FROM PATH ***//
			const size_t last_slash_idx = img_path2.find_last_of("\\/");
			if (std::string::npos != last_slash_idx) {
				img_path2.erase(0, last_slash_idx + 1);
			}

			//*** Remove extension if present //***
			const size_t period_idx = img_path2.rfind('.');
			if (std::string::npos != period_idx) {
				img_path2.erase(period_idx);
			}

			System::String^ final_path = gcnew System::String(img_path2.c_str());
			//MessageBox::Show(final_path);

			if (image.data && !image.empty()) {
				Mat h1(image.rows, image.cols, image.type());
				Mat s1(image.rows, image.cols, image.type());
				Mat i1(image.rows, image.cols, image.type());

				float r, g, b, h, s, in;

				for (int i = 0; i < image.rows; i++)
				{
					for (int j = 0; j < image.cols; j++)
					{
						b = image.at<Vec3b>(i, j)[0];
						g = image.at<Vec3b>(i, j)[1];
						r = image.at<Vec3b>(i, j)[2];

						in = (b + g + r) / 3;
						// Intensity = 1/3 (r + g + b)

						float min_val = 0;
						min_val = std::min(r, std::min(b, g));

						s = 1 - 3 * (min_val / (b + g + r));
						if (s < 0.00001) {
							s = 0;	// Dark saturation
						}
						else if (s > 0.99999) {
							s = 1;	// Light saturation
						}

						if (s != 0) {
							h = 0.5 * ((r - g) + (r - b)) / sqrt(((r - g)*(r - g)) + ((r - b)*(g - b)));
							h = acos(h);

							if (b <= g)
							{
								h = h;
							}
							else {
								h = ((360 * 3.14159265) / 180.0) - h;
								//h = (2 * 3.14169265 - h);	// same result as above
							}
						}
						h1.at<Vec3b>(i, j)[0] = (h * 180) / 3.14159265;
						h1.at<Vec3b>(i, j)[1] = (h * 180) / 3.14159265;
						h1.at<Vec3b>(i, j)[2] = (h * 180) / 3.14159265;

						s1.at<Vec3b>(i, j)[0] = s * 100;
						s1.at<Vec3b>(i, j)[1] = s * 100;
						s1.at<Vec3b>(i, j)[2] = s * 100;
					}
				}

				//*** Filenames ***//
				std::string final_path2 = msclr::interop::marshal_as<std::string>(final_path);
				std::string h1_path = std::string("Image Processing/HUE__") + final_path2 + std::string(".jpg");
				std::string s1_path = std::string("Image Processing/SAT__") + final_path2 + std::string(".jpg");

				imwrite(h1_path, h1); imwrite(s1_path, s1);
				//imwrite("h1_final.jpg", h1);

				delete img_Hue->Image;
				img_Hue->Image = nullptr;
				delete img_Saturation->Image;
				img_Saturation->Image = nullptr;

				std::string open_hue = "C://Users/Acer User/Desktop/form1/form1" + h1_path;
				std::string open_sat = "C://Users/Acer User/Desktop/form1/form1" + s1_path;
				System::String^ open_hue2 = gcnew System::String(open_hue.c_str());
				System::String^ open_sat2 = gcnew System::String(open_sat.c_str());

				img_Hue->BackgroundImage = System::Drawing::Image::FromFile(open_hue2);
				img_Saturation->BackgroundImage = System::Drawing::Image::FromFile(open_sat2);

#pragma region

				/* CANNY EDGE */
				cv::Mat toCanny; //ORIGINAL IMG
				cv::Mat imgGray;
				cv::Mat Blur;
				cv::Mat imgCanny; //OUTPUT

				//*** END OF CANNY EDGE ***//
				toCanny = cv::imread(img_addr);            // open image

				cv::cvtColor(toCanny, imgGray, CV_BGR2GRAY);        // convert to grayscale

				cv::Canny(Blur,            // input image
					imgCanny,                    // output image
					100,                        // low threshold
					200);                        // high threshold


												 // Declare windows
												 // Note: you can use CV_WINDOW_NORMAL which allows resizing the window
												 // or CV_WINDOW_AUTOSIZE for a fixed size window matching the resolution of the image
												 // CV_WINDOW_AUTOSIZE is the default
				cv::namedWindow("toCanny", CV_WINDOW_AUTOSIZE);
				cv::namedWindow("imgCanny", CV_WINDOW_AUTOSIZE);

				//Show windows
				cv::imshow("toCanny", toCanny);
				cv::imshow("imgCanny", imgCanny);

				cv::waitKey(0);                    // hold windows open until user presses a key

				// Shape detect
				std::vector<std::vector<cv::Point>> contours;
				std::vector<cv::Point> approx;

				cv::findContours(imgCanny.clone(), contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

				for (int i = 0; i < contours.size(); i++)
				{
					// Approximate contour with accuracy proportional
					// to the contour perimeter
					cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);

					// Skip small or non-convex objects
					if (std::fabs(cv::contourArea(contours[i])) < 100 || !cv::isContourConvex(approx))
						continue;

					if (approx.size() == 3)
					{
						//setLabel(dst, "TRI", contours[i]);    // Triangles
					}
					else if (approx.size() >= 4 && approx.size() <= 6)
					{
						// Number of vertices of polygonal curve
						int vtc = approx.size();

						// Get the cosines of all corners
						std::vector<float> cos;
						for (int j = 2; j < vtc + 1; j++) {
							cv::Point pt1 = approx[j%vtc];
							cv::Point pt2 = approx[j - 2];
							cv::Point pt0 = approx[j - 1];

							double dx1 = pt1.x - pt0.x;
							double dy1 = pt1.y - pt0.y;
							double dx2 = pt2.x - pt0.x;
							double dy2 = pt2.y - pt0.y;
							double answer = (dx1*dx2 + dy1*dy2) / sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
							cos.push_back(answer);
						}

						// Sort ascending the cosine values
						std::sort(cos.begin(), cos.end());

						// Get the lowest and the highest cosine
						double mincos = cos.front();
						double maxcos = cos.back();

						// Use the degrees obtained above and the number of vertices
						// to determine the shape of the contour
						if (vtc == 4) {
							//setLabel(dst, "RECT", contours[i]);
						}
						else if (vtc == 5) {
							//setLabel(dst, "PENTA", contours[i]);
						}
						else if (vtc == 6) {
							//setLabel(dst, "HEXA", contours[i]);
						}
						else
						{
							// Detect and label circles
							double area = cv::contourArea(contours[i]);
							cv::Rect r = cv::boundingRect(contours[i]);
							int radius = r.width / 2;

							if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
								std::abs(1 - (area / (CV_PI * (radius*radius)))) <= 0.2) {
								//setLabel(dst, "CIR", contours[i]);
							}
						}

					}
						// Shape Size			
						/*
						cv::Mat size_width;
						cv::Mat size_height;

						size_width = imgCanny.size().width;
						size_height = imgCanny.size().height;
						*/

						;
					}
				}
			}
			else {
				System::String^ error = gcnew System::String("Please select another file.");
				MessageBox::Show(error);
				MessageBox::Show(openFile->FileName);
			}		
		MessageBox::Show("Done");
		}
	};
	}