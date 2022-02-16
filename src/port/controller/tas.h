#pragma once
#include <string>



namespace oot::hid
{
    namespace tas
    {
        bool isTasPlaying();
        void playTas(bool enable);

        std::string getTasFileName();
        void setTasFileName(const std::string& newFilename);

        void TasEnded();//Called when the TAS has ended (end of file of .tas file reached)
        bool hasTasEnded();//Returns true when playback was complete
    }
}