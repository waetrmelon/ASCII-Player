#include <Magick++.h>
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>

#include "ImageRenderer.h"

int main(int argc, char** argv) {
	Magick::InitializeMagick(*argv);

	int fps = 15; // Frames Per Second (duh)
	int widthScale = 2; // Renderers width of scaling 
	int heightScale = 1; // Renderers width of scaling 
	int frames = 58; // How many frames to load.


	// For Rendering Videos

	while (true) {
		for (int i = 1; i < frames; i++) {
			std::string directory = "images\\NerdRadar\\x(" + std::to_string(i) + ").jpg";
			RenderImage(directory, widthScale, heightScale);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000) / fps);
			system("cls");
		}
	}

	// For Rendering Images

	std::string directory = "images\\YourImageHere.jpg";
	RenderImage(directory, widthScale, heightScale);

	return 0;
}