#include "Image.h"
using namespace cs225;

void Image::lighten() {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.l += .1;
            if (p.l > 1) {
                p.l = 1;
            }
        }
    }
}

void Image::lighten(double amount) {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.l += amount;
            if (p.l > 1) {
                p.l = 1;
            }
        }
    }
}

void Image::darken() {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.l -= .1;
            if (p.l < 0) {
                p.l = 0;
            }
        }
    }
}

void Image::darken(double amount) {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.l -= amount;
            if (p.l < 0) {
                p.l = 0;
            }
        }
    }
}

void Image::saturate() {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.s += .1;
            if (p.s > 1) {
                p.s = 1;
            }
        }
    }
}

void Image::saturate(double amount) {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.s += amount;
            if (p.s > 1) {
                p.s = 1;
            }
        }
    }
}

void Image::desaturate() {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.s -= .1;
            if (p.s < 0) {
                p.s = 0;
            }
        }
    }
}

void Image::desaturate(double amount) {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.s -= amount;
            if (p.s < 0) {
                p.s = 0;
            }
        }
    }
}

void Image::grayscale() {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.s = 0;
        }
    }
}

void Image::rotateColor(double degrees) {
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            p.h += degrees;
            if (p.h > 360) {
                p.h -= 360;
            }

            if (p.h < 0) {
                p.h += 360;
            }
        }
    }
}

void Image::illinify() {
    // “Illini Orange” has a hue of 11
    // “Illini Blue” has a hue of 216
    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            if (p.h >= 113.5 && p.h < 293.5) {
                p.h = 216;
            } else {
                p.h = 11;
            }
        }
    }
}

void Image::scale(double factor) {
    if (factor == 1) return;
    unsigned int nWidth = this->width() * factor;
    unsigned int nHeight = this->height() * factor;
    Image *copy = new Image(*this);
    //check this line
    this->resize(nWidth,nHeight);

    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            HSLAPixel &pCopy = copy->getPixel(r/factor,c/factor);
            p = pCopy;
        }
    }

    delete copy;

}

void Image::scale(unsigned w, unsigned h) {
    Image *copy = new Image(*this);
    this->resize(w,h);

    double wScalar = w / this->width();
    double hScalar = h / this->width();

    for (unsigned int r = 0; r < this->width(); r++) {
        for (unsigned int c = 0; c < this->height(); c++) {
            HSLAPixel &p = this->getPixel(r,c);
            HSLAPixel &copyP = copy->getPixel(r/wScalar,c/hScalar);
            copyP = p;
        }
    }
    delete copy;
}