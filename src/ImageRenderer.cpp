#include <Magick++.h>
#include <iostream>


char CorrespondingCharacter(double Lumeninance) {
	if (Lumeninance > 0 && Lumeninance < 0.05) { return   '_'; }
	else if (Lumeninance > 0.05 && Lumeninance < 0.1) { return '/'; }
	else if (Lumeninance > 0.1 && Lumeninance < 0.15) { return '\\'; }
	else if (Lumeninance > 0.15 && Lumeninance < 0.2) { return '-'; }
	else if (Lumeninance > 0.2 && Lumeninance < 0.25) { return '+'; }
	else if (Lumeninance > 0.25 && Lumeninance < 0.3) { return '='; }
	else if (Lumeninance > 0.3 && Lumeninance < 0.35) { return '('; }
	else if (Lumeninance > 0.35 && Lumeninance < 0.4) { return ')'; }
	else if (Lumeninance > 0.4 && Lumeninance < 0.45) { return '<'; }
	else if (Lumeninance > 0.45 && Lumeninance < 0.5) { return '>'; }
	else if (Lumeninance > 0.5 && Lumeninance < 0.55) { return ':'; }
	else if (Lumeninance > 0.55 && Lumeninance < 0.6) { return '.'; }
	else if (Lumeninance > 0.6 && Lumeninance < 0.65) { return '?'; }
	else if (Lumeninance > 0.65 && Lumeninance < 0.7) { return '@'; }
	else if (Lumeninance > 0.7 && Lumeninance < 0.75) { return '#'; }
	else if (Lumeninance > 0.75 && Lumeninance < 0.8) { return ';'; }
	else if (Lumeninance > 0.8 && Lumeninance < 0.85) { return '{'; }
	else if (Lumeninance > 0.85 && Lumeninance < 0.9) { return '}'; }
	else if (Lumeninance > 0.9 && Lumeninance < 0.95) { return '$'; }
	else if (Lumeninance > 0.95 && Lumeninance < 1) { return   '!'; }
	return ' ';
}

void RenderImage(std::string ImageLocation, int wScale, int hScale) {
	Magick::Image img(ImageLocation);

	std::string data = "";
	for (int x = 0; x < img.size().width() * hScale; x++) {
		for (int y = 0; y < img.size().height() * wScale; y++) {
			Magick::ColorRGB rgb(img.pixelColor(y, x));
			double Lumeninance = 0.2126 * rgb.red() + 0.7152 * rgb.green() + 0.0722 * rgb.blue();
			data += CorrespondingCharacter(Lumeninance);
			data += " ";

		}
		data += "\n";
	}
	std::cout << data << "\n";
}