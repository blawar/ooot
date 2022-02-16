#include "tas.h"
#include <stdio.h>
#include "../player/players.h"
#include "../options.h"
#include "tas.h"


using namespace oot::hid::tas;

bool g_tasPlaying = false;
bool g_tasEnded   = false;
std::string g_tasFilename;


bool oot::hid::tas::isTasPlaying()
{
    return g_tasPlaying;
}

void oot::hid::tas::playTas(bool enable)
{
    g_tasPlaying = enable;
}

void oot::hid::tas::setTasFileName(const std::string& newFilename)
{
    g_tasFilename = newFilename;
}

std::string oot::hid::tas::getTasFileName()
{
    if (g_tasFilename.empty())
        g_tasFilename = "last-run.tas";
    return g_tasFilename;
    /*std::error_code error;
    std::filesystem::create_directory(TAS_DIR, error);

    time_t now = time(0);
    tm* ltm = localtime(&now);

    if (!ltm)
        return TAS_DIR"/record.tas";

    char buf[64] = { 0 };
    sprintf(buf, TAS_DIR"/%04d.%02d.%02d-%04d.tas", ltm->tm_year, ltm->tm_mon + 1, ltm->tm_mday, ltm->tm_hour * 60 + ltm->tm_min);
    return buf;*/
}

void oot::hid::tas::TasEnded()
{
    g_tasEnded = true;
}

bool oot::hid::tas::hasTasEnded()
{
    return g_tasEnded;
}


/*namespace controller
{
    class Tas : public Controller
    {
        public:
        Tas() : Controller()
        {
            fp = fopen("cont.tas", "rb");

            if(fp != NULL)
            {
                fread(&oot::config(), 1, sizeof(oot::config()), fp);
                g_tasPlaying = true;
            }
        }

        virtual ~Tas()
        {
            if(fp)
            {
                fclose(fp);
            }
        }

        void update()
        {
            if(fp != NULL)
            {
                auto r = fread(&m_state, 1, sizeof(m_state), fp);
                if (m_state.button)
                {
                    int x = 0;
                }
            }
        }

        protected:
            FILE* fp;
    };
} // namespace controller

Tas::Tas() : Driver()
{
}

Tas::~Tas()
{
}

void Tas::scan(class Controllers* controllers)
{
    if (!size())
    {
        auto controller = std::make_shared<controller::Tas>();
        m_controllers.push_back(controller);
        players().attach(controller, 0);
    }
}*/