DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "Du lånade ett " COLOR(RED) "Fick-ägg" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"En fick-Cucco kommer att kläckas ur\n"
"det över natten. Se till att ge tillbaka\n"
"den då du är klar med den."
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "Du lämnade tillbaka fick-Cucco'n\n"
"och fick " COLOR(RED) "Cojiro" COLOR(DEFAULT) " istället!" QUICKTEXT_DISABLE "\n"
"Till skillnad från andra Cuccos,\n"
"så galer Cojiro sällan."
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Märklig Svamp" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"En färsk svamp som den här blir\n"
"snart för gammal! Ta den till\n"
"brygdbutiken i Kakariko, fort!"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Märklig Brygd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du vet inte vad den här\n"
"kvinnan och mannen håller på med,\n"
"men ta den till den Förlorade Skogen!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "Du återlämnade den Märkliga Brygden \n"
"och fick " COLOR(RED) "Tjuvjägaren's såg" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den där rackaren måste\n"
"ha lämnat kvar den här."
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomber   20 Stycken   80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "Du fick en \n"
COLOR(RED) "Dekufrö-Kulpåse" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Den här påsen kan bära upp till " COLOR(YELLOW) "40" COLOR(DEFAULT) "\n"
"slangbell-kulor."
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "Du bytte Tjuvjägaren's såg \n"
"emot ett " COLOR(RED) "trasigt Goron-Svärd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Besök Storgoron för att få det reparerat!"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "Du lämnade in det trasiga \n"
"Goron-Svärdet och fick ett \n"
COLOR(RED) "Läkemedelsrecept" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Besök Kung Zora!"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "Storgoron's Svärd..." QUICKTEXT_DISABLE "\n"
"du fick en " COLOR(RED) "Anspråksblankett " COLOR(DEFAULT) "för det!\n"
"Du klarar knappt av att vänta på\n"
"att svärdet ska bli färdigt!"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Du bytte Jätten's Kniv \n"
"emot " COLOR(RED) "Storgoron's Svärd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här klingan smiddes utav en \n"
"mästersmed och går aldrig sönder!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Du lämnade in Anspråksblanketten\n"
"och fick " COLOR(RED) "Storgoron's Svärd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här klingan smiddes utav en \n"
"mästarsmed och går aldrig sönder!"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "Du använde Läkemedelsreceptet och\n"
"fick en " COLOR(RED) "Ögonglobsgroda" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Leverera den till Hyliasjön \n"
"medans den är kall!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "Du bytte Ögonglobsgrodan \n"
"emot " COLOR(RED) "Världens Bästa Ögondroppar" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Skynda! Ta dem till Storgoron\n"
"innan de blir dåliga!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x41")  COLOR(RED) "VINNARE!!" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Dödskallemask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp den!\n"
"Du känner dig som ett monster medans\n"
"du har på dig den här masken!"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Spökmask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp\n"
"den! Du kan skrämma många människor\n"
"med den här masken!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Keaton-mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp\n"
"den! Du kommer att bli en populär grabb\n"
"med den här masken på!"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Kaninhuva" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp\n"
"den! Huvan's långa öron är så\n"
"söta!"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Goronmask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp\n"
"den! Den kommer att få ditt huvud att\n"
"se stort ut däremot."
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Zora Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp\n"
"den! Med den här masken på så\n"
"kommer du att bli en Zora!"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Gerudomask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp den!\n"
"den! Med den här masken på kommer du\n"
"att se ut som en...flicka?"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "Du lånade en " COLOR(RED) "Sanningen's Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ta på dig den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att visa upp den!\n"
"den! Visa upp den för så många du kan!"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Välkommen till vårat banbrytande \n"
"underhållningscenter:" BOX_BREAK SHIFT("\x15")  COLOR(RED) "Bombchu-Bowlinghallen!" COLOR(DEFAULT)  BOX_BREAK "Vill du veta vad du \n"
"Kan vinna? Ptja, det är en " TEXT_SPEED("\x03") "hemlighet." TEXT_SPEED("\x00") "\n"
"Jag kan inte berätta det förrän du har\n"
"betalt för att spela." BOX_BREAK "Det kostar " COLOR(RED) "30 Rupees" COLOR(DEFAULT) " per spel.\n"
"Vill du spela?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "OKEJ!!" QUICKTEXT_DISABLE  BOX_BREAK "Sikta emot hålet i mitten \n"
"och släpp " COLOR(RED) "Bombchun " COLOR(DEFAULT) "kör!\n"
"Du har " COLOR(RED) "tio försök" COLOR(DEFAULT) ". Redo..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "DÅ BOWLAR VI!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vill du spela igen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, Jag höll visst på att glömma!\n"
"Det här kan du vinna!" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomber  (20 stycken)   80 Rupees\n"
COLOR(DEFAULT) "Ta ut dem med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck på \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " igen för att kasta. Du kan inte\n"
"köpa ut dem utan en bombväska." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomber  (30 stycken)   120 Rupees\n"
COLOR(DEFAULT) "Ta ut dem med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck på \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " igen för att kasta. Du kan inte\n"
"köpa ut dem utan en bombväska." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomber  30 Stycken   120 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag är så glad att alla har blivit\n"
"återställda till det vanliga igen!"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Snälla rädda mina andra bröder\n"
"också! De kommer säkerligen att\n"
"ge dig något mycket bättre!" BOX_BREAK "Kan du göra det?!"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Färbannelsen har blivit bruten!\n"
"Tack så mycket!\n"
"Här får du en belöning!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah! Det vilar en förbannelse över mig!!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi ska vara försiktiga så att vi inte\n"
"får en förbannelse på oss igen!"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Efter att du besegrade " COLOR(RED)  TOKENS  COLOR(DEFAULT) "\n"
"Förbannelse-spindlar, så har förbannelsen\n"
"börjat försvagas!" BOX_BREAK "Gav barnen dig någon belöning\n"
"efter att de blev återstållda?" BOX_BREAK "Något du borde känna till, är att\n"
"det enda sättet att bli " COLOR(RED) "väldigt rik " COLOR(DEFAULT) "är att\n"
"besegra så många Förbannelse-spindlar\n"
"som möjligt!" BOX_BREAK "Det finns ett par trick för att finna\n"
"dem alla! För det första så måste du\n"
"jaga nattetid. För det andra, tänk på\n"
"att de tycker om mjuk jord..." BOX_BREAK "Var uppmärksam på din\n"
"omgivning!\n"
"Snälla, vi räknar med din hjälp!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vi ser ut såhär på grund utav \n"
"spindeln's förbannelse. men..." TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi alla ser ut såhär på grund utav\n"
"spindeln's förbannelse." BOX_BREAK "Om varje " COLOR(RED) "Förbannelse-spindel " COLOR(DEFAULT) "i\n"
"hela världen blev besegrad,\n"
"så skulle förbannelsen lyftas." BOX_BREAK "Då du besegrar en Förbannelse-spindel \n"
"så kommer en amulett att framträda. Samla\n"
"in den som bevis för din prestation." BOX_BREAK ITEM_ICON("\x71") "Siffran jämte den här " COLOR(YELLOW) "ikonen" COLOR(DEFAULT) " på\n"
" " COLOR(LIGHTBLUE) "Uppdrags-skärmen" COLOR(BLUE) " \n"
COLOR(DEFAULT) "visar hur många Förbannelse-spindlar \n"
"du har besegrat såhär långt." BOX_BREAK ITEM_ICON("\x71") "Då denna " COLOR(YELLOW) "ikon" COLOR(DEFAULT) " visas \n"
"jämsides med namnet på platsen\n"
"på " COLOR(RED) "Kart-fönstret" COLOR(DEFAULT) ", så finns där inga\n"
"mer Spindlar kvar på den platsen." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du bryter förbannelsen över min\n"
"familj, så kommer vi att belöna dig " COLOR(RED) "mycket\n"
"rikt" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Efter " COLOR(RED)  TOKENS  COLOR(DEFAULT) " besegrade Förbannelse-spindlar\n"
"så har förbannelsen över mig \n"
"blivit bruten." BOX_BREAK UNSKIPPABLE "Tack så mycket! Här får du en belöning\n"
"som bevis för min uppskattning! Snälla ta emot den." EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tack för att du räddade mina barn." BOX_BREAK "Va? Jag? Åh, Det är Okej..." BOX_BREAK "Du har redan besegrat " COLOR(RED)  TOKENS  COLOR(DEFAULT) "\n"
"Förbannelse-spindlar, så...\n"
"det är okej...oroa dig inte för mig..."
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu   20 Stycken   180 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du spela?\n"
"Det kostar " COLOR(RED) "20 Rupees " COLOR(DEFAULT) "per spel.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du kan inte! Du behöver en pilbåge!" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Okej. Du behöver inte spela\n"
"Om du inte vill." EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OKEJ!!" QUICKTEXT_DISABLE "\n"
"Detta spelet är för vuxna!\n"
"Hyrule's berömda " COLOR(RED) "Skyttegalleri" COLOR(DEFAULT) "!" BOX_BREAK "Sikta på måltavlorna ifrån \n"
"plattformen där borta! Kan du träffa\n"
COLOR(RED) "tio stycken" COLOR(DEFAULT) "? Du får " COLOR(RED) "femton \n"
COLOR(DEFAULT) "skott!" BOX_BREAK "Dra ditt vapen med " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". \n"
"Är du redo?\n"
"Försök att få en fullpoängare!\n"
"Lycka till!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du ser en liten hög med\n"
"mjuk jord här."
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Älvslangbellan" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Tryck " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att ta ut och hålla\n"
"den. Medan du håller inne " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "så kan du sikta \n"
"med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Släpp " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att skjuta \n"
"ett " COLOR(RED) "Dekufrö" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Om du vill skjuta på\n"
"en gång då du trycker " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", \n"
"håll nere " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "lite längre för att \n"
"redogöra ett frö."
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Älvpilbågen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x03") "Tryck " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att ta ut\n"
"och hålla den. Medan du håller inne\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " så kan du sikta med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "." COLOR(YELLOW) " " COLOR(DEFAULT) "Släpp\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att skjuta iväg en " COLOR(RED) "pil" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Bomber" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera dem på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x02") "Använd " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att lyfta och placera\n"
"en. Tryck " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " medans du springer för att\n"
"kasta den. Om du ser något\n"
"misstänksamt, bomba det!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera dem på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x09") " Lyft och placera med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"Det här är en ny typ utav bomb\n"
"som kan krypa upp för väggar.\n"
"Sikta smart och släpp lös den!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Dekunötter" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera dem på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x01") "Sätt den på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "och prova att \n"
"kasta den! Den kommer att blixtra till \n"
"och bedöva fienden!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Bumerang" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera dem på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0E") "Tryck " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att kasta den \n"
"på avlägsna fiender!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Krokskottet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det är en fjäderladdad kedja som\n"
"du kan ta fram för att kroka fast saker." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Du kan använda den för att dra\n"
"till dig avlägsna föremål, eller\n"
"så kan du använda den för att dra\n"
"dig själv emot någonting." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Medan du håller inne " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", så kan du\n"
"sikta med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Skjut genom att\n"
"släppa " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Dekukäpp" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera dem på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x00") "Sätt den på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och svinga den\n"
"med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x00") "Då du vill stoppa undan den, \n"
"stå still och tryck " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". \n"
"Du kan bära upp till 10 käppar,\n"
"men slösa inte bort dem."
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Megatonhammaren" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Tryck " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to krossa och förstöra \n"
"skrot! Den är så tung, att du behöver \n"
"använda två händer för att svinga den!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Sanningslinsen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sätt den på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att \n"
"titta genom den! Mystiska \n"
"saker är dolda överallt!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0F") "Försök att även använda den\n"
"utanför brunnen. Att se sanningen\n"
"kostar dig magisk kraft, tryck " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "igen för att sluta använda den."
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Tidsokarinan" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Detta är en utav den Kungliga Familjens \n"
"dolda skatter som Zelda lämnade efter sig.\n"
"Den skimrar med ett mystiskt ljus..."
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du kastar Farore's Vind!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Återvänd till Warp-Punkten\n"
"Avskingra Warp-Punkten\n"
"Lämna" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Eldmedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Darunia vaknade upp som en Vise och\n"
"skänker dig härmed sina krafter!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Vattenmedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ruto vaknade upp som en Vise och\n"
"skänker dig härmed sina krafter!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "Du fick " COLOR(ADJUSTABLE) "Skogsmedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Saria vaknade upp som en Vise och\n"
"skänker dig härmed sina krafter!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "Du fick " COLOR(YELLOW) "Själamedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nabooru vaknade upp som en Vise och\n"
"skänker dig härmed sina krafter!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "Du fick " COLOR(LIGHTBLUE) "Ljusmedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru den Vise skänker dig\n"
"härmed sina krafter!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "Du fick " COLOR(PURPLE) "Skuggmedaljen\n"
" " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Impa vaknade upp som en Vise och\n"
"skänker dig härmed sina krafter!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Tom Flaska" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Då du har något i den här\n"
"flaskan så kan du placera den på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " då du\n"
"vill använda föremålet inuti."
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Röd Brygd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x15") "Drick den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att återhämta\n"
"din livsenergi.\n"
"Du bär den här brygden i\n"
"en utav dina flaskor."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "Du fick en " COLOR(ADJUSTABLE) "Grön Brygd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x16") "Drick den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att återhämta\n"
"din magiska kraft.\n"
"Du bär den här brygden i\n"
"en utav dina flaskor."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "Du fick en " COLOR(BLUE) "Blå Brygd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Drick den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att återhämta\n"
"din livsenergi och din magiska kraft."
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "Du fångade en " COLOR(RED) "Älva" COLOR(DEFAULT) " i en flaska!" QUICKTEXT_DISABLE "\n"
"På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x18") "Den här lilla älvan är en pålitlig \n"
"partner som återhämtar dig\n"
"så fort din livsenergi tar \n"
"slut." BOX_BREAK ITEM_ICON("\x18") "Då du placerar den på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"så kan du be om dess hjälp\n"
"när du vill."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Fisk" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Använd den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " så kanske \n"
"någonting händer... Den ser \n"
"färsk och mumsig ut!" BOX_BREAK ITEM_ICON("\x19") "På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", tryck sedan\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att använda den."
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Magic Bean" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Find a suitable spot for a garden\n"
"and plant it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Then, wait\n"
"for something fun to happen!" BOX_BREAK ITEM_ICON("\x10") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", and then use that\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to plant it."
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ursäkta mig...okej..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "DÅ BOWLAR VI" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Älvokarinan" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är ett minne ifrån Saria.\n"
"Placera den på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"för att börja spela på den!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", använd sedan\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att börja spela." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "Du kan spela olika noter\n"
"med " COLOR(BLUE) "[A]" COLOR(DEFAULT) " och de fyra " COLOR(YELLOW) "[C] Knapparna" COLOR(DEFAULT) ". \n"
"Tryck " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " för att sluta spela, eller \n"
"för att spela din sång från början."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Du fick " COLOR(ADJUSTABLE) "Jätten's Kniv" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Håll den med båda händerna och använd \n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "för att attackera! Den är så lång, så att\n"
"du inte kan använda den med en " COLOR(LIGHTBLUE) "sköld" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "Du fick en " COLOR(LIGHTBLUE) "Dekusköld" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Byt till " COLOR(BLUE) "Utrustnings-skärmen \n"
" " COLOR(RED) " " COLOR(DEFAULT) "och välj den här\n"
"skölden. Tryck " COLOR(BLUE) "[A] " COLOR(DEFAULT) "för att utrusta dig med den." BOX_BREAK ITEM_ICON("\x3E") "Tryck " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " för att huka\n"
"och försvara dig. Om du trycker " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " medan du \n"
COLOR(LIGHTBLUE) "[Z] Siktar" COLOR(DEFAULT) ", så kan du röra dig\n"
"medan du försvarar dig."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "Du fick en " COLOR(LIGHTBLUE) "Hyliansk Sköld" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Byt till " COLOR(BLUE) "Utrustnings-skärmen \n"
" " COLOR(DEFAULT) " och välj den här\n"
"skölden, utrusta dig sedan med den genom att trycka " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "Du hittade " COLOR(LIGHTBLUE) "Spegelskölden" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Skölden's polerade yta\n"
"reflekterar ljus eller energi. Tryck " COLOR(LIGHTBLUE) "[R]\n"
COLOR(DEFAULT) "för att använda den."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Långskottet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är ett uppgraderat Krokskott.\n"
"Den sträcker sig " COLOR(RED) "dubbelt" COLOR(DEFAULT) " så långt!"
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Goron-tunika" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Denna värme-resistanta tunika är\n"
"i vuxenstorlek, så den passar inte ett barn...\n"
"Är du på väg till en varm plats? Oroa dig inte!"
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "Du fick en " COLOR(BLUE) "Zora-tunika" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här dykar-uniformen är i vuxenstorlek,\n"
"så den passar inte ett barn. Klä dig i den,\n"
"så att du inte drunknar under vattnet."
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(ADJUSTABLE) "Magisk Kruka" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Din Magi-meter fylldes på!"
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "Du fick ett par " COLOR(RED) "Järnskor" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Så tunga, att du inte kan springa.\n"
"Så tunga, att du inte kan flyta."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "Du fick ett par " COLOR(RED) "Svävarskor" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Med dessa mystiska skor\n"
"så kan du sväva över marken.\n"
"Nackdelen? Ingen dragkraft!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x46") "You can even use these to\n"
"Gå korta perioder över mark\n"
"som inte är fast. Var modig\n"
"och lita på skorna!"
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick ett " COLOR(PURPLE) "Återhämtningshjärta" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Din livsenergi har blivit återhämtad!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Du uppgraderade ditt kågor till\n"
COLOR(RED) "Stort Koger" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du bära fler pilar-\n"
COLOR(YELLOW) "40 " COLOR(DEFAULT) "totalt!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Du uppgraderade ditt kågor till\n"
"det " COLOR(RED) "Största Kogert" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du till och med bära ännu fler \n"
"pilar, ända upp till " COLOR(YELLOW) "50" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Bombväska" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här specialgjorda bombväskan är tillverkad \n"
"utav magen från en Dodongo!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "20 Bomber" COLOR(DEFAULT) " inuti!" QUICKTEXT_DISABLE "\n"
"Nu kan du placera Bomber på " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "och spränga saker! Du är lyckligt \n"
"lottad!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Stor Bombväska" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du bära fler \n"
"Bomber, up till hela " COLOR(YELLOW) "30" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "Du fick den \n"
COLOR(RED) "Största Bombväskan" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du bära upp till \n"
COLOR(YELLOW) "40" COLOR(DEFAULT) " Bomber!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Du hittade " COLOR(BLUE) "Silverhandskarna" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Då du har dem på dig, så känner\n"
"du kraften i dina armar att \n"
"orka lyfta stora saker " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x51") "Men, dessa handskar passar inte\n"
"ett barn... Dessutom så lovade du\n"
"att ge dem till " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Du borde\n"
"stå vid ditt ord..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "Du hittade de " COLOR(BLUE) "Gyllene Handskarna" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du kan till och med känna mer\n"
"kraft strömma genom dina armar!\n"
"Greppa tag med " COLOR(BLUE) "[A] " COLOR(DEFAULT) "och lyft upp saker!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE "Du stoppade en " COLOR(LIGHTBLUE) "Blå Eld" COLOR(DEFAULT) "\n"
"in i Flaskan!" QUICKTEXT_DISABLE "\n"
"Detta här en häftig flamma som du kan\n"
"använda med " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " eller" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "Du fick en " COLOR(BLUE) "Vuxen's Plånbok" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vuxna får lov att ha mycket pengar \n"
"på sig. Nu så kan du bära \n"
"upp till " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "Du fick en " COLOR(BLUE) "Jätte's Plånbok" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vilken enorm plånbok! Nu kan \n"
"du bära upp till " COLOR(YELLOW) "500" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Du hittade en " COLOR(RED) "Liten Nyckel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här nyckeln kan öppna en låst \n"
"dörr. Du kan endast använda den\n"
"i det här området."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (20 Stycken)  180 Rupees\n"
COLOR(DEFAULT) "Det ser ut som en leksaksmus, men\n"
"är i själva verket en självgående tidsinställd\n"
"bomb!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Röd Brygd    40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Röd Brygd    50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Röd Brygd    40 Rupees\n"
COLOR(DEFAULT) "Om du dricker denna, så kommer du\n"
"att återhämta din livsenergi.\n"
"Detta är en enstaka dos." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Röd Brygd    50 Rupees\n"
COLOR(DEFAULT) "Om du dricker denna, så kommer du\n"
"att återhämta din livsenergi.\n"
"Detta är en enstaka dos." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "Du fann en " COLOR(RED) "Områdeskarta" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Tryck " COLOR(RED) "START " COLOR(DEFAULT) "För att komma in i \n"
"Skärmval och titta sedan på\n"
COLOR(RED) "Kartskärmen" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x76")  COLOR(BLUE) "Blå kammare" COLOR(DEFAULT) " är platser \n"
"du inte har besökt tidigare. \n"
"Din nuvarande plats är \n"
"det " COLOR(LIGHTBLUE) "blinkande rummet" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x76") "Rör " COLOR(LIGHTBLUE) "[Control-Pad] upp och ned" COLOR(DEFAULT) " för att \n"
"för att välja våning."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Kompassen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du se vart många\n"
"dolda ting är placerade i den här\n"
"platsen!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "Smärtan's Sten" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Om du kopplar in en " COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", så\n"
"reagerar den då hemligheter är i närheten."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Zelda's Brev" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Wow! Det här brevet har Prinsessan\n"
"Zelda's autograf! Sätt det på " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"och visa upp den med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x23") "På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"du kan placera det på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"och sedan använda det med " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att visa upp\n"
"det för folk."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Välkommen! Hur kan jag stå till tjänst?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Jag vill handla\n"
"Bara tittar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vill du köpa någonting\n"
"annat?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "Din " COLOR(RED) "Dekufrö-kulpåse \n"
COLOR(DEFAULT) "har blivit större!" QUICKTEXT_DISABLE "\n"
"Nu kan du bära fler kulor!\n"
"Den här väska kan bära upp till " COLOR(YELLOW) "50" COLOR(RED) " " COLOR(DEFAULT) "kulor!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Öppna kistan och...Överraskning!\n"
"Om du hittar en nyckel inuti, Så får\n"
"möjlighet att fortsätta. Vänster eller\n"
"höger--testa lyckan!" BOX_BREAK COLOR(RED) "10 Rupees " COLOR(DEFAULT) "för att spela. Vill du göra \n"
"ett försök?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kanon! Du är en riktig hasardspelare!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(ADJUSTABLE) "Grön Rupee" COLOR(DEFAULT) "!\n"
"Det är " COLOR(ADJUSTABLE) "en Rupee" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Eldpilen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sätt den på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "så kommer dina pilar\n"
"att få kraften! Om du träffar\n"
"ditt mål, så kommer det att börja brinna."
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Ispilen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sätt den på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "så kommer dina pilar\n"
"att få kraften! Om du träffar \n"
"ditt mål, så kommer det att frysa." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0C") "Den här pilmagin tillägnas\n"
"endast de som klarar att fullfölja \n"
"Gerudostammen's tuffa träning,\n"
"så använd den med stolthet!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "Du fick " COLOR(LIGHTBLUE) "Ljuspilen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sätt den på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "så kommer dina pilar\n"
"att få kraften! Rättvisan's ljus\n"
"kommer att besegra all ondska!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x2F")  COLOR(ADJUSTABLE) "Skogs-Menuetten" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x37")  COLOR(RED) "Eld's-Bolero" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x29")  COLOR(BLUE) "Vatten-Serenaden" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x2D")  COLOR(YELLOW) "Själen's Klagosång" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x28")  COLOR(PURPLE) "Skuggan's Nocturne" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Du har lärt dig \n"
SHIFT("\x32")  COLOR(LIGHTBLUE) "Ljuset's Preludium" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Goron's Armband" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du rycka upp \n"
"Bomb-Blommor. Stå vid sidan om en och\n"
"använd " COLOR(BLUE) "[A]" COLOR(DEFAULT) " för att rycka upp den!"
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "Du stoppade ett " COLOR(RED) "Kryp " COLOR(DEFAULT) "i flaskan!" QUICKTEXT_DISABLE "\n"
"Du kan släppa lös den genom att trycka\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Denna typen utav kryp tycker om att\n"
"leva i små hål i marken."
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "Du har fått " COLOR(RED) "Gerudo's \n"
"Medlemskort" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har nu tillträde till Gerudo's\n"
"träningsområde i deras gömställe."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomber  10 stycken  50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pilar  50 stycken  90 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fisk   200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Dekunötter   5 stycken   15 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "Du fick " COLOR(ADJUSTABLE) "Kokiri's Smaragd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är Skogen's Själasten \n"
"som hädanefter har anförtrotts \n"
"dig utav det Stora Dekuträdet."
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Goron's Rubin" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är Elden's själasten som \n"
"Goronstammen nu har anförtrott dig!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Zora's Safir" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är Vattnet's Själasten som\n"
"Zorastammen nu har anförtrott dig!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Handla genom att flytta \n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "vänster eller höger.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Tala med ägaren\n"
"Avsluta" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)


DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Tack så mycket!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du har inte tillräckligt med Rupees!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du kan inte få det nu." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Dekunötter   10 stycken  30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Dekukäpp  1 styck   10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Dekusköld   40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pilar   10 stycken   20 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomber   5 stycken   25 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu  10 stycken   100 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du kan inte använda en Stor-Poe här!\n"
"Sälj den till mannen vid Slottet\n"
"Hyrule's portar!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Röd Brygd   30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Grön Brygd   30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Nu kan du samla på dig \n"
"ännu fler " COLOR(RED) "Dekukäppar" COLOR(DEFAULT) "!\n"
"Du kan nu bära upp till " COLOR(YELLOW) "20" COLOR(DEFAULT) " stycken!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Nu kan du samla på dig \n"
"ännu fler " COLOR(RED) "Dekukäppar" COLOR(DEFAULT) "!\n"
"Du kan nu bära upp till " COLOR(YELLOW) "30" COLOR(DEFAULT) " stycken!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hyliansk Sköld   80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Gorontunika   200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Zoratunika   300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Återhämtningshjärta   10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Jag är ledsen...men jag kan inte sälja den till\n"
"dig så länge du inte har en flaska att \n"
"stoppa den i." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "Du fångade en " COLOR(RED) "Poe " COLOR(DEFAULT) "i din flaska!" QUICKTEXT_DISABLE "\n"
"Någonting bra kanske kan hända nu!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Lon Lon-Mjölk" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här mjölken är väldigt näringsrik!\n"
"Använd den med " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att återhämta din \n"
"livsenergi!" BOX_BREAK ITEM_ICON("\x1A") "Du återställer " COLOR(RED) "fem hjärtan" COLOR(DEFAULT) "\n"
"per slurk. Det finns två\n"
"slurkar per flaska." BOX_BREAK ITEM_ICON("\x1A") "På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"använd sedan med " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att ta \n"
"en slurk."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Tom Flaska" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Stoppa någonting i den och \n"
"tryck " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att använda den... Va?\n"
"Det finns redan något där i!?"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "Du fick ett " COLOR(RED) "Konstigt Ägg" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det känns som att det är någonting som\n"
"rör sig på insidan! Placera den på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "och \n"
"se vad som händer!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x21") "På " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"så kan du placera den på " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"tryck sedan " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "för att använda."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pilar   30 stycken   60 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Min nuvarande storsäljare är den\n"
COLOR(LIGHTBLUE) "Hylianska Skölden" COLOR(DEFAULT) ", men det finns risk för att \n"
"den är för stor för dig, grabben." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vi flyttade hit från Slottstaden. \n"
"Jag vet att det är tuffa tider, men\n"
"Jag hoppas på att du kommer att bli en \n"
"stamkund hos oss!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x47") "Välkommen!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Dekusköld   40 Rupees\n"
COLOR(DEFAULT) "Då du har den i handen så kan du försvara dig \n"
"med " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". Eld får den att börja\n"
"brinna!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pilar   (10 stycken)   20 Rupees\n"
COLOR(DEFAULT) "Du behöver en pilbåge för att skjuta dem.\n"
"Du kan inte köpa dem så länge du inte\n"
"har en pilbåge." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Dekukäpp  (1 styck)  10 Rupees\n"
COLOR(DEFAULT) "En lång gren från det\n"
"Stora Dekuträder. Du kan använda den som\n"
"ett vapen, men den kommer att gå sönder." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Dekunötter  (10 stycken) 30 Rupees\n"
COLOR(DEFAULT) "Kasta för att bedöva dina fiender.\n"
"Du kan bara köpa så många\n"
"du faktiskt kan bära." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomber   (5 stycken)   25 Rupees\n"
COLOR(DEFAULT) "Ta ut dem med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " för att kasta. Du kan endast köpa\n"
"dem om du har en Bombväska." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "Du fick " COLOR(ADJUSTABLE) "Kokiri-Svärdet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"På " COLOR(BLUE) "Föremåls-skärmen" COLOR(DEFAULT) ",\n"
"välj det med markören och\n"
"beväpna dig med " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x3B") "Detta är en utav Kokiri's\n"
"dolda skatter, men du kan låna det\n"
"ett tag. Se till att öva \n"
"med det före du slåss på riktigt!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Röd Brygd   30 Rupees\n"
COLOR(DEFAULT) "Drick för att återhåmta din livsenergi.\n"
"Innehåller bara en dos." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Grön Nrygd   30 Rupees\n"
COLOR(DEFAULT) "Drick för att återhåmta din magikraft.\n"
"Innehåller bara en dos." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Nu kan du bära\n"
"fler " COLOR(RED) "Dekunötter" COLOR(DEFAULT) "!\n"
"Du kan bära upp till " COLOR(YELLOW) "30" COLOR(DEFAULT) " nötter!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Nu kan du bära\n"
"ännu fler " COLOR(RED) "Dekunötter" COLOR(DEFAULT) "! Du kan bära\n"
"upp till " COLOR(YELLOW) "40" COLOR(RED) " " COLOR(DEFAULT) "nötter!" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Hyliansk Sköld   80 Rupees\n"
COLOR(DEFAULT) "Detta är en stor, tung sköld \n"
"precis som de Hylianska riddarna använder.\n"
"Den klarar till och med av eldattacker!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Gorontunika   200 Rupees\n"
COLOR(DEFAULT) "En tunika skapad utav Gorons.\n"
"Vuxenstorlek. Skyddar dig från \n"
"värmeskador." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Zoratunika   300 Rupees\n"
COLOR(DEFAULT) "En tunika skapad utav Zoras. Vuxenstorlek.\n"
"Skyddar dig från att drunkna\n"
"under vatten." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Återhämtningshjärta   10 Rupees\n"
COLOR(DEFAULT) "Återställer direkt en utav dina\n"
"hjärtbehållare." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Din's Eld" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Dess eldboll uppslukar allt!\n"
"Använd den här magin\n"
"med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE "Du fick " COLOR(ADJUSTABLE) "Farore's Vind" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Den här warpmagin kan du använda \n"
"med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Warpa då du är \n"
"i fara!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "Du kommer att teleporteras till " COLOR(ADJUSTABLE) " \n"
"Warp-punkten" COLOR(DEFAULT) ". Då du först använder\n"
"magin, så skapar du en \n"
"Warp-punkt." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "Då du använder magin \n"
"igen, så kan du antingen avskingra\n"
"Warp-punkten du skapade senast\n"
"eller warpa till den."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Nayru's Kärlek" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Kasta den här för att skapa en\n"
"skyddande barriär. Detta är en defensiv \n"
"magi som du kan använda med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pilar  (50 stycken)  90 Rupees\n"
COLOR(DEFAULT) "Skjut dessa med en pilbåge. Du kan inte\n"
"köpa dem så länge du inte har en pilbåge." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomber  (10 stycken)  50 Rupees\n"
COLOR(DEFAULT) "Ta ut dem med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " igen för att kasta. Du kan inte\n"
"köpa dem utan en Bombsäck." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Dekunötter  (5 stycken)  15 Rupees\n"
COLOR(DEFAULT) "Kasta dem för att bedöva fiender.\n"
"Du kan endast bära ett begränsat \n"
"antal utav dem." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fisk   200 Rupees\n"
COLOR(DEFAULT) "Precis fångad och så färsk!\n"
"Du kan ha den i en flaska." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du besegrade en " COLOR(RED) "Gyllene Dödskalltella" COLOR(DEFAULT) ".\n"
"Du fick en amulett som bevis \n"
"för att du har besgrat den!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du besegrade en " COLOR(RED) "Gyllene Dödskalltella" COLOR(DEFAULT) ".\n"
"Du fick en amulett som bevis \n"
"för att du har besgrat den!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fairy's Spirit    50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Älva's Själ   50 Rupees\n"
COLOR(DEFAULT) "Du behöver en tom flaska att stoppa\n"
"den i. Gå inte in i strid \n"
"utan en!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Blå Eld    300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Blå Eld   300 Rupees\n"
COLOR(DEFAULT) "Du behöver en tom flaska att stoppa\n"
"den i. Använd för att \n"
"kyla ned dig." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Kryp i flaska   50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Kryp i flaska    50 Rupees\n"
COLOR(DEFAULT) "Du behöver en tom flaska att stoppa\n"
"den i. Det ser ut som ett helt\n"
"vanligt kryp..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (10 stycken)  100 Rupees\n"
COLOR(DEFAULT) "Det ser ut som en leksaksmus, men\n"
"är i själva verket en självgående tidsinställd\n"
"bomb!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Den varan är tyvärr\n"
"tillfälligt slut på lagret." COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Kom igen! Du är för gammal för \n"
"det här spelet!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x40") "Va? Vad i--!" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x50") "Uh-oh!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3E") "En kund!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x39") "zzzzz...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pilar   (30 stycken)   60 Rupees\n"
COLOR(DEFAULT) "Du behöver en pilbåge för att skjuta dem.\n"
"Om du använder dem så tar de slut." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Samla fyra bitar totalt för att få\n"
"ytterligare en Hjärtbehållare. Fler\n"
"behållare betyder mer livsenergi!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har hittills samlat ihop två \n"
"bitar. Med två ytterligare bitar, \n"
"så får du mer livsenergi!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har nu samlat ihop tre \n"
"bitar! Med ytterligare en bit så \n"
"kommer din livsenergi att öka!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har nu färdigställt en hel\n"
"Hjärtbehållare! Din maximala livsenergi\n"
"har därmed ökat!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbehållare" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Din maximala livsenergi har \n"
"ökat med ett hjärta. Din totala\n"
"livsenergi fylls upp."
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Bossnyckeln" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nu kan du ta dig in i \n"
"kammaren där bossen lurar."
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nej, du har inte tillräckligt med\n"
"Rupees!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x24") "Okej, du är färdig!" QUICKTEXT_DISABLE "\n"
"Var snäll och vänta utanför medan jag \n"
"färdigställer nästa utmaning!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomber   5 stycken   35 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomber   (5 stycken)   35 Rupees\n"
COLOR(DEFAULT) "Ta ut dem med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och tryck \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " igen för att kasta. Du kan inte\n"
"köpa dem utan en bombväska." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(BLUE) "Blå Rupee" COLOR(DEFAULT) "!\n"
"Det blir " COLOR(BLUE) "fem Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Silverfjället" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hoppa i vattnet och tryck \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Du kan nu dyka djupare\n"
"än vad du kunde innan."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "Du fick " COLOR(BLUE) "Guldfjället" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hoppa i vattnet och tryck \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Du kan nu dyka ännu djupare\n"
"än vad du kunde innan!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Det verkar som att detta föremålet inte \n"
"fungerar här..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Det går inte att öppna!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Du har lärt dig " COLOR(ADJUSTABLE) "Saria's Visa" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x11") "Du har lärt dig " COLOR(RED) "Epona's Visa" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0B") "Du har lärt dig " COLOR(YELLOW) "Solen's Visa" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x15") "Du har lärt dig " COLOR(BLUE) "Zelda's Vaggvisa" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x05") "Du har lärt dig " COLOR(LIGHTBLUE) "Tids-Visan" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du har lärt dig " COLOR(PURPLE) "Storm-Visan" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Välkommen " NAME "!\n"
"Jag är Kraften's Stora Älva!" BOX_BREAK UNSKIPPABLE "Jag ska bevilja dig en " COLOR(ADJUSTABLE) "svärdsteknik\n"
"" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Mottag den nu!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Välkommen " NAME "!\n"
"Jag är Visdomen's Stora Älva!" BOX_BREAK UNSKIPPABLE "Jag ska förbättra din " COLOR(ADJUSTABLE) "magikraft\n"
"" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Mottag den nu!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Välkommen " NAME "!\n"
"Jag är Modigheten's Stora Älva!" BOX_BREAK UNSKIPPABLE "Jag ska förbättra din \n"
COLOR(LIGHTBLUE) "defensiva kraft" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Mottag den nu!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Var snäll och besök mig igen,\n"
"då du är trött efter strid!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Välkommen " NAME "!\n"
"Jag ska lindra dina sår." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE "Du fick " COLOR(RED) "Dekufrön" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Det här är små, hårda frön\n"
"som du kan använda som kulor\n"
"till din Slangbella."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  UNSKIPPABLE "Du bemästrade den hemliga\n"
"svärdstekniken " COLOR(RED) "Snurr-Attack" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Håll inne " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " för att ladda upp ditt vapen!\n"
"Släpp " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " för att släppa lös en våg\n"
"en våg utav snurrande energi!" BOX_BREAK UNSKIPPABLE "Om du vill släppa lös energin\n"
"utan att ladda upp ditt vapen, så \n"
COLOR(LIGHTBLUE) "rotera [Control-Pad] en gång " COLOR(DEFAULT) "och tryck " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "för" COLOR(ADJUSTABLE) "\n"
COLOR(DEFAULT) "a mycket kraftfull snabb snurr!"
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Dekufrön 30 stycken 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Dekufrön (30 stycken) 30 Rupees\n"
COLOR(DEFAULT) "Du kan använda dem som kulor till\n"
"din slangbella. Du kan inte köpa ut \n"
"dem om du inte har en Slangbella." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Du vill prata med Saria, eller?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Prata med Saria\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Nähä? Men vill du prata \n"
"med mig?\n"
COLOR(DEFAULT)  TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x3C")  NAME "...?\n"
SHIFT("\x0D") "Det är " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Kan du höra mig?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vill du prata med Saria\n"
"igen?" COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Din " COLOR(ADJUSTABLE) "Magimätare" COLOR(DEFAULT) " har förbättrats!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Din " COLOR(LIGHTBLUE) "defensiva kraft" COLOR(DEFAULT) " har förbättrats!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Du fick en " COLOR(YELLOW) "bunt med pilar" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Då du laddar upp kraft för en\n"
"Snurr-Attack, så kommer magisk kraft att\n"
"förbrukas. Håll ett öga på din\n"
"gröna " COLOR(ADJUSTABLE) "Magimätare" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Hallå, pojke! Du är budbärare till\n"
"den Kungliga familjen, eller hur?" BOX_BREAK UNSKIPPABLE "Nästa gång du är i deras\n"
"trakter, så stanna till vid\n"
"min vän som bor vid\n"
"Slottet Hyrule." BOX_BREAK UNSKIPPABLE "Hon kommer garanterat att ge dig\n"
"en ny kraft!"
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Din magiska kraft har blivit \n"
"förbättrad! Nu har du dubbelt\n"
"så mycket " COLOR(RED) "Magikraft" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Din defensiva kraft har blivit \n"
"förbättrad! Skada som \n"
"orsakas utav fiender " COLOR(RED) "kommer att halveras" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Välkommen " NAME "!\n"
"Jag är magin's Stora älva!" BOX_BREAK UNSKIPPABLE "Jag ska ge dig en ny " COLOR(RED) "trollformel" COLOR(DEFAULT) ".\n"
"Var snäll och ta emot den."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Jag är ledsen, men du kan inte låna\n"
"den här masken ännu." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du kan använda " COLOR(RED) "Din's Fire" COLOR(DEFAULT) " inte enbart för att\n"
"attackera utan även för att bränna saker!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kom ihåg, du kan endast använda " COLOR(ADJUSTABLE) "Farore's\n"
"Vind" COLOR(DEFAULT) " i områden\n"
"där det finns en gömd karta, okej?"
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(BLUE) "Nayru's Kärlek" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "är endast i effekt under\n"
"en kort stund, så använd den försiktigt."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Var snäll och besök mig igen,\n"
"då du är trött efter strid!"
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Röd Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(RED) "tjugo Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(PURPLE) "Lila Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(PURPLE) "femtio Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du fick en " COLOR(YELLOW) "Enorm Rupee" COLOR(DEFAULT) "!\n"
"Denna Rupee är värd hejdundrande\n"
COLOR(YELLOW) "tvåhundra Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Dörrnyckel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Använd den här nyckeln för att fortsätta\n"
"till nästa run. Välj en skattkista \n"
"och se om turen är med dig!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Förlorare!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hittade bara " COLOR(ADJUSTABLE) "en Rupee" COLOR(DEFAULT) ".\n"
"Turen är inte med dig." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Förlorare!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hittade " COLOR(BLUE) "fem Rupees" COLOR(DEFAULT) ".\n"
"Trots det, så har du inte så värst tur." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Förlorare!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hittade " COLOR(RED) "tjugo Rupees" COLOR(DEFAULT) ".\n"
"Ditt senaste val var ett misstag,\n"
"eller hur! Så frustrerande!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Vinnare!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hittade " COLOR(YELLOW) "femtio Rupees" COLOR(DEFAULT) ".\n"
"Turen är helt enkelt på din sida grabben!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "Du stoppade en " COLOR(RED) "Stor-Poe " COLOR(DEFAULT) "i en flaska!" QUICKTEXT_DISABLE "\n"
"Vi säljer den i " COLOR(RED) "Spökbutiken" COLOR(DEFAULT) "!\n"
"Någonting bra kan hända!"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINNARE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Samla fyra bitar totalt för att få\n"
"en ytterligare Hjärtbehållare. Fler\n"
"behållare betyder mer livsenergi!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINNARE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hittills så har du samlat två \n"
"bitar. Med två till så kommer, \n"
"din livsenergi att öka!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINNARE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har samlat tre bitar!\n"
"Med ytterligare en bit, så kommer \n"
"din livsenergi att öka!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "WINNER" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du fick en " COLOR(RED) "Hjärtbit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du har färdigställt ytterligare en\n"
"Hjärtbehållare! Din maximala\n"
"livsenergi har ökat!"
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Leta inte bara efter dem utomhus,\n"
"utan även i ruiner, hålor och andra platser." BOX_BREAK "Fast det är klart, det här är bara vår dröm...\n"
"Du behöver inte göra det\n"
"om du inte vill..." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vad är det?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Titta, titta, " NAME "!\n"
"Du kan se ned under " COLOR(DEFAULT) "spindelväven" COLOR(LIGHTBLUE) "\n"
"med hjälp utav " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se på den här väggen! Vinrankorna\n"
"som växer upp för väggen skapar en ojämn\n"
"yta... du kanske kan klättra på \n"
"den, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Du kan öppna en " COLOR(DEFAULT) "dörr" COLOR(LIGHTBLUE) " genom att stå\n"
"framför den och trycka på " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Håll koll på vad som står på\n"
COLOR(BLUE) "Action" COLOR(LIGHTBLUE) " " COLOR(BLUE) "Ikonen" COLOR(LIGHTBLUE) ".\n"
"Det är den " COLOR(BLUE) "blå ikonen" COLOR(LIGHTBLUE) " högst upp på\n"
"skärmen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Titta! Någonting hänger där\n"
"uppe! Det ser ut som en gammal " COLOR(DEFAULT) "stege" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vänta...\n"
"Är inte det samma design som är\n"
"på " COLOR(DEFAULT) "Tidsdörren" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det ser ut som att den där facklan\n"
"har brunnit för inte allt för längesedan..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Härifrån, så kommer vi att gå\n"
"genom ett par trånga passager!\n"
"Om du tar det försiktigt, så kanske\n"
"du kan smyga dig på några fiender." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Använd " COLOR(DEFAULT) "[Z] Markering " COLOR(LIGHTBLUE) "för att alltid titta\n"
"i rätt riktning. Sätt din\n"
"vy så att du kan se ned genom nästa\n"
"korridor före du börjar gå." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Då du har ställt in din vy, håll inne\n"
COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "för att " COLOR(DEFAULT) "gå på sidan " COLOR(LIGHTBLUE) "runt kröken.\n"
"På det viset så behöver du inte bli överraskad\n"
"utav en fiende som väntar på dig i ett bakhåll." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Stå jämsides med " COLOR(DEFAULT) "blocket" COLOR(LIGHTBLUE) " och ta\n"
"tag i det med " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". Medan du håller inne\n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", så kan du knuffa eller dra." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Om du står jämsides med " COLOR(DEFAULT) "blocket" COLOR(LIGHTBLUE) "\n"
"och trycker " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) " medan du trycker " COLOR(DEFAULT) "[Control-Pad]" COLOR(LIGHTBLUE) "\n"
"emot " COLOR(DEFAULT) "blocket" COLOR(LIGHTBLUE) ", så kan du klättra\n"
"upp på det." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Håll utkik på vad " COLOR(BLUE) "Action\n"
"Ikonen " COLOR(LIGHTBLUE) "säger!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0109"
)

DEFINE_MESSAGE(0x010A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"010a"
)

DEFINE_MESSAGE(0x010B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"010b"
)

DEFINE_MESSAGE(0x010C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Då du är i vattnet, om\n"
"du håller nere" COLOR(BLUE) " [A]" COLOR(LIGHTBLUE) ", så kan du dyka!\n"
"Jag slår vad om att det kan finnas en\n"
"hel del intressant under vattnet!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x010D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"010d"
)

DEFINE_MESSAGE(0x010E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"010e"
)

DEFINE_MESSAGE(0x010F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"010f"
)

DEFINE_MESSAGE(0x0110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0110"
)

DEFINE_MESSAGE(0x0111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0111"
)

DEFINE_MESSAGE(0x0112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0112"
)

DEFINE_MESSAGE(0x0113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0113"
)

DEFINE_MESSAGE(0x0114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Wow! Se på alla dessa \n"
COLOR(DEFAULT) "Bomb-blommor" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Finns det något sätt som du kan sätta\n"
"eld på dem allihop på samma gång?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det ser ut som att det finns många " COLOR(DEFAULT) "lavagropar\n"
" " COLOR(LIGHTBLUE) "här omkring, se upp vart\n"
"du går!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Med den brytaren på, så rör sig\n"
COLOR(DEFAULT) "plattformen " COLOR(LIGHTBLUE) "högre upp. Nu kan du\n"
"snabbt nå andra våningen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Man vet aldrig vad som rör sig\n"
"bakom nästa hörn i dessa trånga\n"
"gångar...." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Använd " COLOR(DEFAULT) "[Z] Markering " COLOR(LIGHTBLUE) "för att alltid se\n"
"i rätt riktning. Det här är en\n"
"användbar teknik, eller hur?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x011A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"011a"
)

DEFINE_MESSAGE(0x011B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"011b"
)

DEFINE_MESSAGE(0x011C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"011c"
)

DEFINE_MESSAGE(0x011D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"011d"
)

DEFINE_MESSAGE(0x011E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"011e"
)

DEFINE_MESSAGE(0x011F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", vad tittar \n"
"du på?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0120"
)

DEFINE_MESSAGE(0x0121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0121"
)

DEFINE_MESSAGE(0x0122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0122"
)

DEFINE_MESSAGE(0x0123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0123"
)

DEFINE_MESSAGE(0x0124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ökenkolossen's ansikte...det \n"
"ser verkligen ondskefullt ut!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Jag kan höra andeväsen viska \n"
"i det här rummet..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE "\"Håll utkik efter sanningen's öga...\"\n"
COLOR(LIGHTBLUE) "Det är vad de säger!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Här...jag kan höra andeväsen\n"
"viska i det här rummet..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "\"De som har " COLOR(RED) "heliga fötter " COLOR(DEFAULT) "\n"
"bör låta vinden vägleda dem.\n"
"De kommer då att ledas in på den \n"
"hemliga vägen.\"" BOX_BREAK COLOR(LIGHTBLUE) "Det är vad de säger!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här väggen...det står någonting här...\n"
COLOR(DEFAULT) "\"Fara ovanför...\"" COLOR(LIGHTBLUE) "\n"
"Det är vad som står skrivet." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här väggen...det står någonting här...\n"
COLOR(DEFAULT) "\"Fara underifrån...\"\n"
COLOR(LIGHTBLUE) "Det är vad som står skrivet." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vattnet som flödar ut ur den här \n"
"statyn översvämmar hela rummet." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"012c"
)

DEFINE_MESSAGE(0x012D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"012d"
)

DEFINE_MESSAGE(0x012E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"012e"
)

DEFINE_MESSAGE(0x012F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se upp, " NAME "!\n"
"Elektricitet flödar genom\n"
"den här " COLOR(ADJUSTABLE) "gröna slimiga saken" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se upp " NAME "!\n"
"Elektricitet flödar genom\n"
"den här " COLOR(RED) "röda slimiga saken" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se upp " NAME "!\n"
"Elektricitet flödar genom\n"
"den här " COLOR(BLUE) "blå slimiga saken" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "brytaren" COLOR(LIGHTBLUE) "...\n"
"Det ser inte ut som att du kan trycka\n"
"ned den med enbart din vikt,\n"
NAME "..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0134"
)

DEFINE_MESSAGE(0x0135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0135"
)

DEFINE_MESSAGE(0x0136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0136"
)

DEFINE_MESSAGE(0x0137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den " COLOR(RED) "röda slämmiga saken " COLOR(LIGHTBLUE) "är borta! \n"
"Det måste vara för att du skar av den\n"
COLOR(RED) "röda svansen" COLOR(LIGHTBLUE) "! Kan det fungera med \n"
"de andra också?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det finns en knapp bortom den här\n"
"väggen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det ser ut att finnas någonting\n"
"där uppe på plattformen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42")  COLOR(LIGHTBLUE) "VAAA!?" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Kolla på alla de där " COLOR(DEFAULT) "flaggorna" COLOR(LIGHTBLUE) "!\n"
"Kan du lista ut vilka som är\n"
"riktiga?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Det " COLOR(DEFAULT) "Stora Deku Trädet" COLOR(RED) " " COLOR(LIGHTBLUE) "har \n"
"kallat på dig!\n"
"Följ efter mig, är du snäll!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Kom igen! Var modig!\n"
"Vi går in i det \n"
"Stora Deku Trädet!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Det Stora Deku Trädet ville att\n"
"vi skulle besöka prinsessan i\n"
COLOR(DEFAULT) "Hyrules Slott" COLOR(LIGHTBLUE) ".... Borde vi inte\n"
"börja ta oss dit?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Flickan från ranchen begärde oss\n"
"att hitta hennes " COLOR(DEFAULT) "pappa" COLOR(LIGHTBLUE) "...Jag undrar var\n"
"han är?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Undras var vi kan hitta \n"
COLOR(DEFAULT) "prinsessan " COLOR(LIGHTBLUE) "i det här stora gamla slottet?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vad skulle " COLOR(DEFAULT) "Saria" COLOR(RED) " " COLOR(LIGHTBLUE) "säga om vi berättade\n"
"för henne att vi ska rädda Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Impa " COLOR(LIGHTBLUE) "sa att Själastenen\n"
"av Eld finns någonstans på " COLOR(DEFAULT) "Det Döda\n"
"Berget" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vi tar oss in i Dodongos\n"
"Grotta med hjälp av en " COLOR(DEFAULT) "Bomb Blomma" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Darunia sa att det bor en " COLOR(DEFAULT) "Älva\n"
COLOR(LIGHTBLUE) "på toppen av Det Döda Berget,\n"
"gjorde han inte?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Jag undrar om " COLOR(DEFAULT) "Saria " COLOR(LIGHTBLUE) "vet någonting\n"
"om de andra Själatenarna?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Det verkar  som att " COLOR(DEFAULT) "Prinsessan Ruto " COLOR(LIGHTBLUE) "på något sätt " COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "har hamnat inne i Jabu-Jabu's mage..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Du samlade ihop tre Själastenar!\n"
"Låt oss återvända till " COLOR(DEFAULT) "Hyrule\n"
"Slottet" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "De där två, på den vita hästen...\n"
"det var Zelda och Impa, eller hur?\n"
"Det såg ut som att hon kastade \n"
"någonting i " COLOR(DEFAULT) "vallgraven" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vi går och tittar i \n"
COLOR(DEFAULT) "Tidens Tempel" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Borde vi lita på vad Sheik sa \n"
"och gå till " COLOR(DEFAULT) "Kakariko Byn" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Jag undrar vad som är på gång i \n"
"skogen just nu... Jag är orolig\n"
"för " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) ", också!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Det där molnet över " COLOR(DEFAULT) "Det Döda Berget" COLOR(LIGHTBLUE) "...\n"
"det är någonting oroande med \n"
"det..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "En isande vind blåser in från\n"
COLOR(DEFAULT) "Zora's Flod" COLOR(LIGHTBLUE) "...kan du känna den?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "De där " COLOR(DEFAULT) "Järn Kängorna " COLOR(LIGHTBLUE) "ser ut\n"
"att väga ett ton! Om du tar\n"
"dem på dig, kan du säkert\n"
"gå på botten av en sjö." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Låt oss leta efter någon som kanske\n"
"vet någonting om de andra\n"
COLOR(DEFAULT) "Vise Männen" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Det där monstret! Det kom upp ur \n"
COLOR(DEFAULT) "brunnen i byn" COLOR(LIGHTBLUE) "! Vi går och \n"
"undersöker brunnen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Jag undrar vem som byggde " COLOR(DEFAULT) "Templet" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "av Själar" COLOR(LIGHTBLUE) ", och till vilket ändamål?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Har du ännu provat att spela \n"
COLOR(PURPLE) "Skuggans Nokturna" COLOR(LIGHTBLUE) " som Sheik\n"
"lärde dig?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "I " COLOR(DEFAULT) "öknen" COLOR(LIGHTBLUE) "... det är där\n"
"den Onda Kungen Ganondorf föddes.\n"
"Om vi går dit, kanske vi finner\n"
"någonting..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ta på " COLOR(DEFAULT) "Silver Handskarna \n"
COLOR(LIGHTBLUE) "och försök att lyfta saker som \n"
"du inte ens kunde rubba tidigare!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Personen som väntar på oss vid\n"
"Tidens Tempel... det måste vara..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vi måste befria Prinsessan Zelda\n"
"från hennes fångenskap i Ganons\n"
"Slott!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME "...\n"
"Try to keep moving!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Jag har inget emot att prata med \n"
"dig genom Okarinans magi, men\n"
"jag skulle föredra att se \n"
"dig ansikte mot ansikte!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Skogen är kopplad till många \n"
"olika ställen! Om du kan höra min sång,\n"
"så måste du vara någonstans som har\n"
"förbindelse med skogen!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Jag blev så  glad när jag hörde att\n"
"Herr Darunia älskade min sång väldigt mycket!\n"
BOX_BREAK "Ännu gladare blev jag när fick veta att\n"
"den hjälpte dig på ditt uppdrag,\n"
NAME "!\n"
"Hii hi hi!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Samlar du ihop Själastenarna?\n"
"Du har ännu en kvar att finna?\n"
"Du menar " COLOR(BLUE) "Vattnets \n"
"Stjälasten" COLOR(DEFAULT) ", eller hur?" BOX_BREAK "Det Stora Deku Trädet berättade en gång\n"
"för mig att " COLOR(BLUE) "Kung Zora, härskaren över Zoras \n"
"Domän, " COLOR(DEFAULT) "har den..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Samlar du ihop Själastenarna?\n"
"Du har ännu en kvar att finna?\n"
"Du menar " COLOR(RED) "Eldens \n"
"Stjälasten" COLOR(DEFAULT) ", eller hur?" BOX_BREAK "Det Stora Deku Trädet berättade en gång\n"
"för mig att" COLOR(RED) "Herr Darunia av Goron folket\n"
COLOR(DEFAULT) "har den..." EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Jag vet inte vad det är...\n"
"Jag känner av något fruktansvärt..." BOX_BREAK "Slottet...\n"
"någonting jätte hemsk är på gång\n"
"vid Slottet!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Hmm? Din okarina låter...\n"
"annorlunda på något sätt... \n"
"Du har tränat väldigt mycket, eller hur,\n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Söker du efter ett tempel?\n"
"Jag hörde en gång, från en mystisk fågel..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Ögonen som ser genom\n"
"mörkret, kan öppnas av en storm." COLOR(DEFAULT) "\"\n"
"Har du någon aning vad han kan\n"
"ha menat med det?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Var är du, " NAME "?\n"
"Söker du efter ett tempel?\n"
"Jag hörde en gång, från en mystisk fågel...\n"
BOX_BREAK "\"" COLOR(LIGHTBLUE) "Gå, unge man. Gå till\n"
"Öken Gudinnan med en okarina." COLOR(DEFAULT) "\"\n"
"Har du någon aning vad han kan\n"
"ha menat med det?" EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Har du hittat alla templen ännu?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Så bra! Du är i säkerhet!\n"
"Jag visste att jag skulle höra\n"
"från dig igen!" BOX_BREAK "Jag är i " COLOR(ADJUSTABLE) "Skogstemplet" COLOR(DEFAULT) "!\n"
"Skogsandarna behövde hjälp och kallade på mig,\n"
"så jag kom hit för att titta till dem...\n"
BOX_BREAK "Men stället är fullt av onda monster!\n"
"Hjälp mig, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Från början, ville jag inte bli\n"
COLOR(ADJUSTABLE) "Skogens Vise" COLOR(DEFAULT) "...." BOX_BREAK "Men nu känner jag mig lättad." BOX_BREAK "Eftersom jag  hjälper dig att rädda\n"
"Hyrule, " NAME "!\n"
"Ja, det är jag!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Om alla sex " COLOR(RED) "Vise" COLOR(DEFAULT) " står tillsammans, \n"
"kan vi fängsla Ganondorf,\n"
"Ondskans Konung, i det Heliga Riket." BOX_BREAK "Men, för att skapa en perfekt\n"
"försägling, behöver vi den" COLOR(RED) "sjunde \n"
"Sage" COLOR(DEFAULT) "." BOX_BREAK "Någon som du känner måste vara den\n"
"Sage, " NAME "..." BOX_BREAK "Från och med nu, måste du färdas \n"
"mellan framtiden och det förflutna för att\n"
"väcka de återstående Visa!" BOX_BREAK "Fortsätt i den här stilen,\n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Vi, de Sex Visa, delar\n"
"vår kraft med dig!" BOX_BREAK "Hyrules öde vilar på\n"
"dina axlar!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Jag hör en röst...\n"
"någonstans ifrån..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Den säger:\n"
COLOR(DEFAULT)  SHIFT("\x11") "\"Samla ihop fem silver Rupees...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här väggen... den talar!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Den säger:\n"
COLOR(DEFAULT) "Om du vill se färjan som går till \n"
SHIFT("\x1E") "den andra världen, kom hit..."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Om du vill färdas med " COLOR(DEFAULT) "båten" COLOR(LIGHTBLUE) ", var \n"
"försiktig! Den ser väldigt gammal ut... Vem\n"
"vet när den plötsligt sjunker?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det finns en " COLOR(DEFAULT) "dörr " COLOR(LIGHTBLUE) "här borta... Finns \n"
"det något sätt att ta sig över?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den där " COLOR(DEFAULT) "röda isen" COLOR(LIGHTBLUE) "...den är så konstig!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "blåa elden" COLOR(LIGHTBLUE) "...den verkar inte\n"
"naturlig. Kanske du kan använda den till\n"
"någonting?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(DEFAULT) "Facklornas Lågor " COLOR(LIGHTBLUE) "är borta.\n"
"Det verkar som om spökena tog dem \n"
"med sig!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Titta, " NAME "! En " COLOR(DEFAULT) "fackla" COLOR(LIGHTBLUE) "\n"
"är tänd! Det måste vara för att\n"
"du besegrade ett spöke, eller hur?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det finns " COLOR(DEFAULT) "pilar " COLOR(LIGHTBLUE) "målade på marken" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "korridoren " COLOR(LIGHTBLUE) "är helt förvriden!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se upp för " COLOR(DEFAULT) "skuggorna av\n"
"monster " COLOR(LIGHTBLUE) "som hänger i taket" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Här finns en " COLOR(DEFAULT) "skattkista." COLOR(LIGHTBLUE)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det här... det är samma " COLOR(DEFAULT) "fackla" COLOR(LIGHTBLUE) " som\n"
"vi såg vid ingånden av templet,\n"
"eller hur?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "facklan" COLOR(LIGHTBLUE) " är tänd... det betyder att..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "knappen" COLOR(LIGHTBLUE) " är helt frusen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", se upp!\n"
"Taket faller ned!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0199"
)

DEFINE_MESSAGE(0x019A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019a"
)

DEFINE_MESSAGE(0x019B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019b"
)

DEFINE_MESSAGE(0x019C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019c"
)

DEFINE_MESSAGE(0x019D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019d"
)

DEFINE_MESSAGE(0x019E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019e"
)

DEFINE_MESSAGE(0x019F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"019f"
)

DEFINE_MESSAGE(0x01A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a0"
)

DEFINE_MESSAGE(0x01A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a1"
)

DEFINE_MESSAGE(0x01A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a2"
)

DEFINE_MESSAGE(0x01A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", jag hör " COLOR(DEFAULT) "Goron \n"
"röster " COLOR(LIGHTBLUE) "från nedan." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Du kan se ner härifrån...\n"
"Är inte det där rummet var vi såg\n"
COLOR(DEFAULT) "Darunia" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "statyn" COLOR(LIGHTBLUE) "...har vi inte sett\n"
"den någonstans tidigare?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Den här " COLOR(DEFAULT) "knappen " COLOR(LIGHTBLUE) "ser rostig ut." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Var försiktig!\n"
"Låt dig inte sväljas upp av \n"
"virvelströmmarna!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01ac"
)

DEFINE_MESSAGE(0x01AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01ad"
)

DEFINE_MESSAGE(0x01AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01ae"
)

DEFINE_MESSAGE(0x01AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01af"
)

DEFINE_MESSAGE(0x01B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"01b0"
)

DEFINE_MESSAGE(0x01B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"01B1"
)

DEFINE_MESSAGE(0x0200, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x0F") "Hej där! Jag är en talande dörr!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x06")  COLOR(LIGHTBLUE) "Underligt...den här dörren vägrar öppnas..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x04")  COLOR(LIGHTBLUE) "Starka " COLOR(DEFAULT) "järn galler " COLOR(LIGHTBLUE) "blockerar dörren.\n"
COLOR(DEFAULT)  SHIFT("\x0B")  COLOR(LIGHTBLUE) "Du kan inte öppna dem\n"
COLOR(DEFAULT)  SHIFT("\x40")  COLOR(LIGHTBLUE) "med dina händer!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x09")  COLOR(LIGHTBLUE) "Du behöver en " COLOR(DEFAULT) "Nyckel" COLOR(LIGHTBLUE) " för att öppna en dörr\n"
COLOR(DEFAULT)  SHIFT("\x14")  COLOR(LIGHTBLUE) "under lås och bom." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x21")  COLOR(LIGHTBLUE) "Du behöver en " COLOR(DEFAULT) "speciell nyckel\n"
SHIFT("\x28")  COLOR(LIGHTBLUE) "för att kunna öppna den här dörren." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Var tyst!" QUICKTEXT_DISABLE  BOX_BREAK "Klockan är ju bara " TIME "!\n"
"Jag, " COLOR(RED) "Dampé " COLOR(DEFAULT) "gravskötaren, har\n"
"gått till sängs!" BOX_BREAK "Försvinn och lek någon annanstans! Kanske du\n"
"kan hitta dig ett spöke under dagstid?"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Klockan är nu " TIME ".\n"
COLOR(RED) "Gravgrävarturnén" COLOR(DEFAULT) " är nu över \n"
BOX_BREAK "Jag, " COLOR(RED) "Dampé" COLOR(DEFAULT) " gravskötaren, försöker\n"
"att såva!" BOX_BREAK "Försvinn och lek någon annanstans! Kanske du\n"
"kan hitta dig ett spöke!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Glada Mask Butiken\n"
COLOR(DEFAULT) "Var god och läs denna skylt innan\n"
"du använder digav min butik." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "Hur Butiken Fungerar\n"
COLOR(DEFAULT) "Vi säljer inte masker i den här butiken.\n"
"Vi " COLOR(RED) "lånar" COLOR(DEFAULT) " endast ut dem till dig." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du kan sälja de lånade maskerna\n"
"på egen hand." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du betalar sedan tillbaka " COLOR(RED) "pengarna" COLOR(DEFAULT) " för masken\n"
"och vi lånar dig en\n"
"nyare modell." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du kan låna masker som du redan\n"
"har sålt tidigare igen; men du \n"
"kan endast sälja en mask av varje modell\n"
"en gång." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Var god och pröva på min butik!\n"
SHIFT("\x14") "--Ägaren Av Glada Mask Butiken" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Skuggornas Tempel...\n"
"Här finns samlat Hyrules blodiga \n"
"förflutna av girighet och hat..." EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Det som gömmer sig i mörkret...\n"
"Knep fulla av illvilja...\n"
"Vägen frammåt är dold..." EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Han som finner sig " COLOR(RED) "sanningens öga\n"
COLOR(DEFAULT) "bär förmågan att se vad som gömmer\n"
"sig i mörkret." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ingången är täckt av någonting\n"
"främmande. Du måste lösa\n"
COLOR(DEFAULT) "pusslet" COLOR(LIGHTBLUE) " i rummet för att få\n"
"ingången att öppnas." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gigantisk död Dodongo...\n"
"när dess ögon ser rött,\n"
"kommer en ny väg att\n"
"uppenbara sig." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x1E")  COLOR(LIGHTBLUE) "Skattkiste Tävling\n"
COLOR(DEFAULT)  SHIFT("\x2D") "Tillfälligt Stängd\n"
SHIFT("\x38") "Öppen Inatt!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Medicin Butik\n"
COLOR(DEFAULT) "Stängd för idag"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Skytte Galleria\n"
COLOR(DEFAULT) "Endast öppen under dagstid"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Glada Mask Butiken\n"
COLOR(DEFAULT) "Söker deltidsanställda\n"
"Ansök under dagstid"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Basar\n"
COLOR(DEFAULT) "Öppen endast under dagstid"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Visa mig ljuset!"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Han som bär " COLOR(RED) "sanningens öga " COLOR(DEFAULT) "blir\n"
"ledd till Själarnas Tempel av\n"
"ett inbjudande spöke." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "De som önskar sig öppna vägen\n"
"som såver på sjöns botten\n"
"måste spela " COLOR(RED) "sången som gått i arv\n"
"av Kungafamiljen" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "De som önskar sig öppna porten\n"
"bortom de avlägsna höjderna, spela " COLOR(RED) "sången\n"
"som gått i arv av Kungafamiljen" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"De som finner sig en " COLOR(RED) "Liten Nyckel" COLOR(DEFAULT) " kan\n"
"göra framsteg till nästa rum. Om de inte\n"
"kan, får de gå hem igen!"
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du önskar du tala till mig,\n"
"gör då det från plattformen." EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Hallå, " NAME "!" QUICKTEXT_DISABLE "\n"
"Titta hitåt!" BOX_BREAK "Titta hit med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "knappen, och prata \n"
"med mig genom att trycka " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Klockan är för tillfället: " COLOR(RED)  TIME  COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Skin ett ljus över de levande döda..."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Han som bryter sig in i den Kungliga \n"
"Graven möter förhinder av\n"
COLOR(RED) "de som lurar i mörkret" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hallå där! Unge man, här borta!\n"
"Titta hitåt, inne i fängelsecellen!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Min lilla pojke är inte här just nu \n"
"Jag tror han begav sig till gravgården \n"
"för att leka..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oj, min pojke såver för tillfället.\n"
"Var snäll och kom tillbaka någon annan gång\n"
"om du vill leka med honom!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "När sjön fylls av vattnets brus, \n"
"skjut din pil mot morgonens ljus." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Om du vill färdas till \n"
"framtiden, återvänd då hit \n"
"med " COLOR(BLUE) "kraften av silver " COLOR(DEFAULT) "från det \n"
"förflutna." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Om du vill ta dig till det \n"
"förflutna, återvänd hit med ett\n"
"barns rena hjärta." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Denna dör är för tillfället under\n"
"renovering." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Det ser ut som att det brukade finnas\n"
"något i den här ställningen..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "Få min näbb att peka ut den\n"
SHIFT("\x3A")  COLOR(RED) "sanna dödskallen" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0C") "Ditt andra val är att att sjunka ned i\n"
SHIFT("\x2D") "mörkrets djup." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Detta är inte den korrekta " COLOR(DEFAULT) "nyckeln" COLOR(LIGHTBLUE) "...\n"
"Dörren vägrar öppnas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27")  COLOR(LIGHTBLUE) "Farmors Häxbrygd Butik\n"
COLOR(DEFAULT)  SHIFT("\x4F") "Stängd" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x28") "Borta på Fältstudier\n"
SHIFT("\x28") "Välkommen åter!\n"
SHIFT("\x4A") "--Farmor" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vem där? En sån oförskämd unge,\n"
"försöker ta sig in genom bakdörren!\n"
QUICKTEXT_DISABLE  BOX_BREAK TEXT_SPEED("\x02") "Så oförskämt..." TEXT_SPEED("\x00") "\n"
"Jag har saftigt skvaller!" BOX_BREAK "Byggarbetarnas chef har en son...\n"
"Det är killen som sitter under trädet\n"
"i mitten av byn varje natt..." BOX_BREAK "Säg inte åt Byggmästaren att\n"
"jag berättade det!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Titta på det här!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Malon har gått och såva!\n"
"Jag är också påväg till sängs.\n"
"Kom tillbaka när det är\n"
"ljust ute!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED)  NAME "s Rekord!\n"
COLOR(DEFAULT) "Antal spindlar mosade: " TOKENS "\n"
"Största fiskfångsten: " HIGHSCORE(HS_LARGEST_FISH) " pund" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Maraton tid: " HIGHSCORE(HS_MARATHON) "\n"
"Kapplöpningstid: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Bågskytte från hästrygg: " HIGHSCORE(HS_HORSE_ARCHERY) " poäng" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Kungafamiljen av Hyrules vapen\n"
SHIFT("\x1E") "är inskrivet här." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x54") "R.I.P.\n"
SHIFT("\x08") "Här vilar själarna av dem\n"
SHIFT("\x2A") "som svor trohet till\n"
SHIFT("\x23") "Kungafamiljen av Hyrule" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0F") "Sheikah folket, väktarna av\n"
SHIFT("\x11") "Kungafamiljen och Kakarikos\n"
SHIFT("\x02") "grundare, vaka över dessa själar\n"
SHIFT("\x1E") "i deras eviga sömn." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(BLUE) "Sömnlösa Vattenfall\n"
COLOR(DEFAULT)  SHIFT("\x05") "Flödet från detta vattenfall tjänar\n"
SHIFT("\x02") "Kungen av Hyrule. När Kungen\n"
SHIFT("\x09") "är i vila, går fallen i följe." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Några grodor tittar på dig\n"
"under vattnet ifrån..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du står på en mjuk matta\n"
"för gäster...\n"
"Den känns underbar under dina fötter!"
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Om du kan övervinna " COLOR(RED) "utmaningarna " COLOR(DEFAULT) "i\n"
"kamrarna framför, då och endast då\n"
"är du kvalificerad innehavet av\n"
"vår hemliga klenod!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Om du åtrår att förvärva vår\n"
"gömda skatt, måste du sträva\n"
"efter att beslagta " COLOR(RED) "nycklarna " COLOR(DEFAULT) "som finns gömda\n"
"i varje kammare!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Besegra alla fiender inom " COLOR(RED) "utsatt tid" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Samla ihop " COLOR(RED) "ädelstenarna under vattnet" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Korsa havet av eld!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Finn den hemliga öppningen\n"
"i rummet!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Förblinda " COLOR(RED) "statyns ögon" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Den som bär " COLOR(RED) "händer av silver" COLOR(DEFAULT) " bör förflytta\n"
"ett gigantiskt block!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Utan de nödvändiga föremålen, blir\n"
"du konfunderad över omöjliga\n"
"mysterier."
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Samla ihop de " COLOR(RED) "vita juvelerna" COLOR(DEFAULT) ", och\n"
"undvik de farliga fällorna!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F")  COLOR(LIGHTBLUE) "Fiskedamm" COLOR(DEFAULT) "\n"
SHIFT("\x07") "Fiskarna nappar verkligen bra idag!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4E")  COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Skuggan viker undan endast för den\n"
SHIFT("\x0E") "som bär " COLOR(RED) "sanningens öga" COLOR(DEFAULT) ", efterlämnat\n"
SHIFT("\x1C") " i Kakariko Byn." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Hyrules Slättmarker" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Hyrule Slottsstad" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(LIGHTBLUE) "Tidens Tempel" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47")  COLOR(RED) "Återvändsgränd" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(PURPLE) "Kakariko Byn\n"
COLOR(DEFAULT)  SHIFT("\x28") "Döda Bergets Led\n"
SHIFT("\x3C") "Start Punkt" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(PURPLE) "Kakariko Byns Gravgård" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Mörk! Trång! Läskig!\n"
COLOR(PURPLE)  SHIFT("\x1E") "De Tre Särdragens Brunn" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(RED) "Döda Berget\n"
COLOR(DEFAULT)  SHIFT("\x25") "Ingen slipper förbi utan ett\n"
SHIFT("\x3A") "Kungligt Påbud!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(RED) "Döda Bergets Led" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(YELLOW) "Dodongos Grotta\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Gå inte in utan tillåtelse!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Goron Landet\n"
SHIFT("\x41")  COLOR(RED) "Goron Stad" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x48")  COLOR(BLUE) "Zoras Flod\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Se upp för snabba strömmar \n"
SHIFT("\x23") "och stark underström." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Skuggan viker undan endast för den\n"
SHIFT("\x0E") "som bär sanningens öga, efterlämnat\n"
SHIFT("\x1C") "i Kakariko Byn." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Zoras Domän" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Zoras Fontän\n"
COLOR(DEFAULT)  SHIFT("\x08") "Besvära inte Herr Jabu-Jabu! \n"
SHIFT("\x32") "--Kung Zora XVI" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(PURPLE) "Skogens Träningscenter\n"
COLOR(DEFAULT)  SHIFT("\x15") "Hugg inte ned skyltar hänsynslöst--\n"
SHIFT("\x28") "läs dem först noggrant!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Alla de övermodiga nog att\n"
SHIFT("\x0B") "bege sig ut i öknen -- Var vänliga\n"
SHIFT("\x2F") "och kom ett varv förbi vår butik." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(YELLOW) "Matthandlare" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41") "Just framför:\n"
SHIFT("\x17")  COLOR(ADJUSTABLE) "Stora Deku Trädets Äng" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(ADJUSTABLE) "Skogens Tempel" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(ADJUSTABLE) "Den Förlorade Skogen" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "Talon och Malons\n"
SHIFT("\x3C")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "Den Store Ingos\n"
SHIFT("\x46")  COLOR(YELLOW) "Ingo Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(BLUE) "Hyliasjön" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  COLOR(BLUE) "Laboratoriet vid sjön\n"
COLOR(DEFAULT)  SHIFT("\x04") "Försöker dagligen ta mig till botten\n"
SHIFT("\x09") "av Hyliasjöns mysterier!\n"
SHIFT("\x36") "--Sjöforskaren" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(YELLOW) "Gerudo Dalen" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15")  COLOR(YELLOW) "Bana för Bågskytte från Hästrygg " COLOR(DEFAULT) "\n"
SHIFT("\x12") "Skickliga spelare hjärtligt välkomna!\n"
SHIFT("\x12") "Nuvarande Rekord: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " Poäng" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(YELLOW) "Gerudo Övningsfält\n"
COLOR(DEFAULT)  SHIFT("\x11") "Endast registrerade medlemmar\n"
SHIFT("\x4B") "tillåtna!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(YELLOW) "Hemsökta Ödemarken" COLOR(DEFAULT) "\n"
SHIFT("\x17") "Om du jagar efter hägringar kommer\n"
SHIFT("\x1F") "du sväljas av öknen.\n"
SHIFT("\x21") "Endast en väg är den sanna!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Själarnas Tempel" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(ADJUSTABLE) "Kokiri Butiken\n"
COLOR(DEFAULT)  SHIFT("\x0B") "Vi säljer närproducerade produkter!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "s Hus" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(ADJUSTABLE) "Trädens folk kan ej\n"
COLOR(DEFAULT)  SHIFT("\x2D")  COLOR(ADJUSTABLE) "lämna dessa skogar." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Följ bergsledet längs med klippans kant\n"
SHIFT("\x15") "för att nå" SHIFT("\x06")  COLOR(RED) "Goron Staden" COLOR(DEFAULT) ",\n Goron folkets hem." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36") "Ett av Naturens Under\n"
SHIFT("\x3F")  COLOR(RED) "Bomb Blomma" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Fara! Ryck inte lös från marken!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x26")  COLOR(RED) "Döda Bergets Topp\n"
COLOR(DEFAULT)  SHIFT("\x10") "Infart till kratern framför\n"
SHIFT("\x1E") "Var beredd på överväldigande hätta!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1D")  COLOR(BLUE) "Kung Zoras Tronsal\n"
COLOR(DEFAULT)  SHIFT("\x1E") "För att höra Kungens ädla\n"
SHIFT("\x15") "tillkännagivande, ställ dig inför\n"
SHIFT("\x17") "honom på plattformen och tala." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Får du stop på mitt vilda rullande,\n"
SHIFT("\x0B") "kanske jag ger dig något häftigt.\n"
SHIFT("\x29") "--" COLOR(RED) "Het Rodder Goron" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Endast han med ett öga som ser sanningen\n"
SHIFT("\x15") "kan finna paraplyet av sten\n"
SHIFT("\x1A") "som beskyddar emot\n"
SHIFT("\x39") "regnet av knivblad." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Bara den som besitter " COLOR(RED) "heliga fötter" COLOR(DEFAULT) "\n"
SHIFT("\x04") "kan ta sig över de dödas håla." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Rekordtiden för de som\n"
"tävlade emot mig var:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"--Gravskötaren Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Skytte Galleria\n"
"20 Rupeer per omgång\n"
COLOR(DEFAULT) "Det finns " COLOR(RED) "10 måltavlor" COLOR(DEFAULT) ". Du har " COLOR(RED) "15\n"
"chanser" COLOR(DEFAULT) ". Träffa alla 10 måltavlorna!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Träffa 10 måltavlor -- Perfekta Priset\n"
"Träffa 8 eller fler -- Försök Igen Gratis\n"
"Träffa färre än 8 -- Slutspelat" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Regler vid denna Skytte Galleria\n"
COLOR(DEFAULT) "Luta inte mot disken.\n"
"Stör inte de andra kunderna." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(LIGHTBLUE) "Skattkistebutik" COLOR(DEFAULT) "\n"
SHIFT("\x06") "Vi säljer dem inte nödvändigtvis..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F")  COLOR(LIGHTBLUE) "Övningplats för Högdykning\n"
COLOR(DEFAULT)  SHIFT("\x2F") "Känner du dig självsäker\n"
SHIFT("\x2A") "i din dykarförmåga?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(RED) "Bergstopp" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Allvarlig Fara - Håll Dig Borta!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Glada Maskbutiken!" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Anställer varubud för\n"
SHIFT("\x3C") "att leverera glädje!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Bombchu Bowlinghall" COLOR(DEFAULT) "\n"
SHIFT("\x20") "Du får uppleva det senaste\n"
SHIFT("\x17") "inom Bombteknologin!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x50")  COLOR(LIGHTBLUE) "Basar" COLOR(DEFAULT) "\n"
SHIFT("\x0A") "Vi har lite av allt!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Häxbryggdsbutik\n"
COLOR(DEFAULT)  SHIFT("\x1B") "Vi har häxbrygder av\n"
SHIFT("\x4A") "bästa kvalité!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(RED) "Goron Butik\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Förnödenheter för Bergsklättrare!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(BLUE) "Zora Butik" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Här finns färsk fisk!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Hjärtbultande Gravgrävarturné!\n"
COLOR(DEFAULT)  SHIFT("\x08") "Från 18:00 till 21:00 Hyrule Tid\n"
SHIFT("\x1C") "--Dampé the Gravekeeper" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Hjärtbultande Gravgrävarturné!\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Turnén är " COLOR(RED) "inställd" COLOR(DEFAULT) " tills en ny\n"
SHIFT("\x1B") "gravskötare är funnen. Vi\n"
SHIFT("\x09") "beklagar för besväret." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Skylt för Framstötning!\n"
COLOR(DEFAULT) "För att göra en framstöt med svärdet, för\n"
COLOR(LIGHTBLUE) "[Styr-Spaken]" COLOR(DEFAULT) " mot ditt mål \n"
"Lås Kameran med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", tryck sedan " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "\"Z\" Hålet\n"
COLOR(DEFAULT) "Vi kryper genom det här lilla\n"
"hålet!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Stå framför hålet och\n"
"för " COLOR(LIGHTBLUE) "[Styr-Spaken] " COLOR(DEFAULT) "emot det. När  \n"
COLOR(BLUE) "Händelse Ikonen " COLOR(DEFAULT) "visar \"Gå in,\" tryck\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "för att krypa in i hålet." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Uppmärksamma vad " COLOR(BLUE) "Händelse Ikonen\n"
COLOR(DEFAULT) "visar!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Hugg Ned Gräsmed Svärdet\n"
COLOR(DEFAULT) "Om du står stilla och bara trycker " COLOR(ADJUSTABLE) "[B]\n"
COLOR(DEFAULT) ", svingar du svärdet vågrätt. Om du håller\n"
COLOR(DEFAULT) "in " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " när" COLOR(DEFAULT) "du slår,\n"
COLOR(DEFAULT) "så hugger du lodrätt." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Hyrule Slott" COLOR(DEFAULT) "\n"
SHIFT("\x37")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Du är här: " COLOR(LIGHTBLUE) "Hyrule Slott" COLOR(DEFAULT) "\n"
SHIFT("\x16") "Den här vägen till " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42") "En Bit Fram\n"
SHIFT("\x29")  COLOR(BLUE) "Kung Zoras kammare\n"
COLOR(DEFAULT)  SHIFT("\x19") "Visa ordentlig respekt!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Den Store " COLOR(RED) "Mido" COLOR(DEFAULT) "s Hus\n"
SHIFT("\x2D") "Chef över alla Kokiri" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "De Allkunniga Brödernas Hus" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Tvillingarnas Hus" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "Saria" COLOR(DEFAULT) "s Hus" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Utsiktspunkt med [Z] riktning\n"
COLOR(DEFAULT) "När du inte tittar mot något\n"
"särskilt, kan du rikta kameran frammåt\n"
"med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Stå still och vänd mot\n"
"ett annat håll, eller " COLOR(LIGHTBLUE) "håll\n"
"ned [Z] " COLOR(DEFAULT) "en stund." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Detta hjälper att orientera dig\n"
"åt det håll du vill rikta dig mot.\n"
"Det är väldigt behändingt!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Håll ned [Z]" COLOR(DEFAULT) ", så kan du\n"
COLOR(RED) "gå sidledes" COLOR(DEFAULT) " medan du hålls vänd \n"
"rakt lol." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "Att gå sidledes" COLOR(DEFAULT) " kan vara väldigt\n"
"viktigt att kunna i labyrint\n"
"korridorer. Vänd runt och testa\n"
"detta nu på en gång." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Hoppstenar i dammen\n"
COLOR(DEFAULT) "När du vågat springer i den riktning\n"
"du vill, hoppar du automatiskt \n"
"av kanten." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Om du hoppar runt på stenarna\n"
"kommer det göra dig lycklig!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2F")  COLOR(RED) "All Dykning Förbjuden!\n"
COLOR(DEFAULT)  SHIFT("\x15") "--Det gör dig intet gott!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Byt Kamera Inriktning\n"
COLOR(DEFAULT) "När du ser en " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " ikon ovanför ett \n"
"föremål, kan du rikta in dig med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Med andra ord, tryck " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " när du\n"
"ser en " COLOR(ADJUSTABLE) "▼" COLOR(YELLOW) " ikon " COLOR(DEFAULT) "ovanför ett föremål,\n"
"så låser du in kameran på det." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Tryck " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " igen,\n"
"för att antingen " COLOR(RED) "lösgöra" COLOR(DEFAULT) " kameran eller\n"
"rikta in dig på nästa föremål med\n"
COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " ikonen ovanför sig." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "När du står inför många fiender\n"
"samtidigt och vill fly därifrån,\n"
"tryck " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) " medan du styr\n"
"bakåt med " COLOR(LIGHTBLUE) "[Styr-Spaken]" COLOR(DEFAULT) " för att avbryta inriktningen." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du kan rikta in dig på dessa " COLOR(RED) "stenar" COLOR(DEFAULT) " bredvid\n"
"skylten för att öva!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(ADJUSTABLE) "Skogens Vise" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x14") "Vi väntar på att få se ditt\n"
SHIFT("\x38") "vackra ansikte!\n"
SHIFT("\x28") "Vinn utomordentliga priser!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x48") "Gör ett besök till\n"
SHIFT("\x04")  COLOR(RED) "De Allvetande Brödernas Hus\n"
COLOR(DEFAULT)  SHIFT("\x17") "för att få svar på alla dina\n"
SHIFT("\x22") "frågor angående olika föremål!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Detta är en " COLOR(RED) "Skvallersten" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att du kan simma snabbare\n"
"genom att snabbt trycka " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns något hemligt\n"
"i närheten av det ensamma trädet,\n"
"inte långt ifrån floden i den\n"
"nordvästra delen av Hyrules Slättmarker."
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns något hemligt\n"
"intill vägen som leder till Hyliasjön."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Storgorons Svärd är \n"
"super vasst och att det aldrig går sönder."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Medigoron inte\n"
"riktigt är medveten om sin storlek, \n"
"så hans butik är väldigt trång."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Malon satte\n"
"ursprungliga rekordet i Lon Lon\n"
"Ranchens hinderbana."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Malon från Lon Lon \n"
"Ranchen hoppas på att en riddare i \n"
"skinande rustning kommer och sveper \n"
"henne av fötterna någon dag."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Ruto, Zora Prinsessan \n"
"som är känd för sin själviska natur \n"
"har fattat intresse för en viss ung pojke \n"
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att endast spelare som\n"
"väljer \"HÅLL\" alternativet för \"Z \n"
"INRIKTNING\" är riktiga \"Zelda\n"
"spelare!\""
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns något gömt\n"
"nära trädet i Kakariko Byn ."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att, till skillnad från\n"
"hennes eleganta utseende, är Prinsessan \n"
"Zelda från Hyrule Slottet, \n"
"egentligen riktigt busig!"
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Prinsessan Zeldas \n"
"barnsköterska egentligen är en av \n"
"Sheikah folket, som så många trodde \n"
"att hade dött ut för länge sedan."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns en man som\n"
"alltid kan bli funnen springande\n"
"runt på Hyrules Slättmarker."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det bryter mot\n"
"reglerna att använda glasögon vid \n"
"Skattkistebutiken i Hyrule\n"
"Slottstads Marknad."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Kyckling Damen \n"
"åker till Laboratoriet vid sjön\n"
"för att studera hur man\n"
"föder upp Fick-Cuccos."
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att vissa Gerudo ibland\n"
"kommer till Hyrule Slottsstad\n"
"för att söka efter pojkvänner."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att en tjuv vid namn\n"
"Nabooru, som hemsöker denna\n"
"plats, är en Gerudo."
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att om du tar dig nära\n"
"en fjäril medan du håller i en\n"
"Deku Pinne, kommer något\n"
"trevligt att hända."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att du kan finna\n"
"någonting nytt i labyrinter som\n"
"du redan har besökt och avklarat."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Gerudo folket avgudar \n"
"Ganondorf nästan som om han var en gud."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns\n"
"något dolt runtom vid\n"
"ingången till Gerudo Dalen."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att ugglan vid namn\n"
"Kaepora Gaebora är en av de\n"
"forntida Vise pånyttfödd."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att fastän den konstiga\n"
" ugglan, Kaepora Gaebora, ser stor\n"
"och tung ut, så är han\n"
"väldigt lätt om hjärtat."
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att hästen som\n"
"Ganondorf rider på är en\n"
"bäcksvart Gerudo hingst."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att Ganondorf inte är \n"
"nöjd bara med att härska över\n"
"Gerudo folket och att han ämnar\n"
"erövra hela Hyrule!"
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att skatten du kan förtjäna\n"
"vid Gerudos Träningsområde inte är så\n"
"häftig som du skulle förvänta dig,\n"
"med tanke på hur utmanande det är!"
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det finns en knapp \n"
"som man endast kan aktivera genom\n"
"att använda en Snurrattack."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att det är möjligt att\n"
"hitta totalt 100 Guld Skulltulas \n"
"över hela Hyrule."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att när folk utan älvor\n"
"ger sig in i Den Förlorade Skogen,\n"
"förvandlas de till monster!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att de småa hålen\n"
"i marken som du finner utöver\n"
"Hyrule är perfekta häckningsplatser\n"
"för småkryp."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att alla Kokiri blir \n"
"följda av små älvor."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Det sägs att endast en Kokiri\n"
"någonsin har lämnat skogen,\n"
"dessutom är han fortfarande vid liv!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Vad är det?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "Det är ett av de parasitiska monstren\n"
"idet Stora Deku Trädet! Dess " COLOR(DEFAULT) "öga" COLOR(LIGHTBLUE) " blir\n"
"sårbart när det är rött!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma Ägg\n"
COLOR(LIGHTBLUE) "När detta ägg kläcks, föds en\n"
"Gohma Larv." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma Larv\n"
COLOR(LIGHTBLUE) "Se upp när den förbereder sig\n"
"för att kasta sig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula\n"
COLOR(LIGHTBLUE) "Den mjuka " COLOR(DEFAULT) "undersidan" COLOR(LIGHTBLUE) " är dess svaga punkt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stor Skulltula\n"
COLOR(LIGHTBLUE) "Den mjuka " COLOR(DEFAULT) "undersidan" COLOR(LIGHTBLUE) " är dess svaga punkt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Svanspasaran\n"
COLOR(DEFAULT) "Svansen" COLOR(LIGHTBLUE) " är dess svaga punkt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Hugg när den gör utfall så ställer\n"
"den sig upprätt. Skär snabbt av\n"
"stammen för att få en " COLOR(DEFAULT) "Deku Pinne" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stor Deku Baba\n"
COLOR(LIGHTBLUE) "Hugg när den gör utfall så ställer\n"
"den sig upprätt. Skär snabbt av\n"
"stammen för att få en " COLOR(DEFAULT) "Deku Pinne" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Den kanske ser vissen ut, men den\n"
"anfaller dig om du försöker röra den!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Buske\n"
COLOR(LIGHTBLUE) "Den gömmer sig i gräset om  du\n"
"kommer för nära. Studsa tillbaka nötterna\n"
"som den skjuter!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Kung Dodongo\n"
COLOR(LIGHTBLUE) "Det där är en jättelik Dodongo som\n"
"äter vad som helst! Ge den en smäll, och\n"
"avsluta den med ditt " COLOR(DEFAULT) "svärd" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Se upp för dess brännheta andedräkt!\n"
"Använd " COLOR(DEFAULT) "[Z] Inriktning " COLOR(LIGHTBLUE) "tekniker!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baby Dodongo\n"
COLOR(LIGHTBLUE) "Se upp för dess anfallssprång!\n"
"Den exploderar efter att ha blivit besegrad!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos \n"
COLOR(LIGHTBLUE) "Använd din sköld väl och strid\n"
"med " COLOR(DEFAULT) "[Z] Inriktning" COLOR(LIGHTBLUE) " tekniker!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos \n"
COLOR(LIGHTBLUE) "Använd din sköld väl och strid\n"
"med " COLOR(DEFAULT) "[Z] Inriktning " COLOR(LIGHTBLUE) "tekniker!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eld Keese\n"
COLOR(LIGHTBLUE) "Förstör den före den kan flyga in i\n"
"dig! Annars kommer dess flammor att\n"
"bränna upp din " COLOR(DEFAULT) "Deku Sköld" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese\n"
COLOR(LIGHTBLUE) "När du kommer tillräckligt nära,\n"
"använd "COLOR(DEFAULT) "[Z] Inriktning" COLOR(LIGHTBLUE) ". Du kan hålla kvar siktet på den\n"
"även om den flyger iväg." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armos\n"
COLOR(LIGHTBLUE) "Stoppa den från att röra sig\n"
"och förinta den!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinade\n"
COLOR(LIGHTBLUE) "Många parasitiska maneter svärmar\n"
"runt detta monster. Lägg siktet på dess\n"
"kropp, som ligger i skydd bakom maneterna!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Parasitisk Tentakel\n"
COLOR(LIGHTBLUE) "Verkar som den smala delen \n"
"är dess svaga punkt... Du behöver ett särskilt\n"
"föremål för att förstöra den!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shabom\n"
COLOR(LIGHTBLUE) "Den ser sprickfärdig ut, kan inte\n"
"krävas mycket för att göra hål på den!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "Om du låter den röra dig så\n"
"blir du elektrifierad!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "Om du låter den röra dig så\n"
"blir du elektrifierad!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stinger\n"
COLOR(LIGHTBLUE) "Förgör den innan den hinner anfalla dig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganons Vålnad\n"
COLOR(LIGHTBLUE) "En ond skepnad från Skogstemplet!\n"
"Ha färdas genom tavlorna på\n"
"väggarna." BOX_BREAK COLOR(LIGHTBLUE) "Bemöt hans magiska attack med\n"
"av dina egna attacker!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Lura den mot dig och uppmärksamma dess\n"
"rörelser noggrannt! Anfall så fort den\n"
"ger dig en öppning!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Blå Bubbla\n"
COLOR(LIGHTBLUE) "Ta skydd mot dess blåa flamma bakom\n"
"din " COLOR(DEFAULT) "sköld" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vit Bubbla\n"
COLOR(LIGHTBLUE) "Ta sikte så fort den stannar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grön Bubbla\n"
COLOR(LIGHTBLUE) "Använd ditt svärd när dess\n"
"gröna flamma slocknar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skullväggtula\n"
COLOR(LIGHTBLUE) "Försök att inte låta den röra dig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guld Skulltula\n"
COLOR(LIGHTBLUE) "De här är även kända som Förbannelsens\n"
"Spindlar. När du besegrar den får du\n"
"en " COLOR(DEFAULT) "pollett" COLOR(LIGHTBLUE) " som bevis!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volvagia\n"
COLOR(LIGHTBLUE) "Eldtemplets Boss, återupplivad\n"
"av Kungen av Ondska. Jag vet inte\n"
"vad dess svaga punkt kan va'..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dansande Flamma\n"
COLOR(LIGHTBLUE) "Släck deras " COLOR(DEFAULT) "flammande kläder\n"
COLOR(LIGHTBLUE) "först..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fackelsnigel\n"
COLOR(LIGHTBLUE) "Om elden på dess rygg släcks\n"
"försöker den fly. Förgör den\n"
"innan den återantänds!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Röd Bubbla\n"
COLOR(LIGHTBLUE) "Ta skydd bakom din" COLOR(DEFAULT) "sköld \n" COLOR(LIGHTBLUE)
"när den anfaller" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morpha\n"
COLOR(LIGHTBLUE) "Vattentemplets Härskare. Den har \n"
"fullständig kontrollöver vattnet. Dra\n"
"ut " COLOR(DEFAULT) "kärnan" COLOR(LIGHTBLUE) " och förgör den!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mörk " NAME "\n"
COLOR(LIGHTBLUE) "Besegra dig själv!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Klingmussla\n"
COLOR(LIGHTBLUE) "Den " COLOR(DEFAULT) "interna muskeln " COLOR(LIGHTBLUE) "är dess" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "svaga punkt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spike\n"
COLOR(LIGHTBLUE) "Vänta på att den drar in spikarna!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Skuggtemplets Boss, återuppstådd\n"
"från botten av brunnen. Ta en titt\n"
"med " COLOR(DEFAULT) "ögat av sanning" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "ReDead\n"
COLOR(LIGHTBLUE) "Deras blick paralyserar dig. Om den\n"
"biter sig fast, " COLOR(DEFAULT) "tryck valfri knapp" COLOR(LIGHTBLUE) " för \n"
"att bryta dig  loss!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ganons Vålnad\n"
COLOR(LIGHTBLUE) "Gör anfall" COLOR(RED) " " COLOR(DEFAULT) "när han kommer ut\n"
"ur en av tavlorna" COLOR(LIGHTBLUE) "!\n"
"Se upp för den falska!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Dess blick paralyserar dig. Om den\n"
"biter sig fast, " COLOR(DEFAULT) "tryck valfri knapp" COLOR(LIGHTBLUE) " för \n"
"att bryta dig  loss!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Döda Handens Händer\n"
COLOR(LIGHTBLUE) "Om den tar fast dig, " COLOR(DEFAULT) "tryck valfri knapp\n"
COLOR(LIGHTBLUE) "för att bryta dig loss!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Död Hand\n"
COLOR(LIGHTBLUE) "Se upp för dess ändlösa händer!\n"
"Aim for its head!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Väggmästare\n"
COLOR(LIGHTBLUE) "Se upp för " COLOR(DEFAULT) "skuggan" COLOR(LIGHTBLUE) "den ger\n"
"av på golvet. Förgör den innan den\n"
"hoppar tillbaka upp i taket!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Golvmästare\n"
COLOR(LIGHTBLUE) "När den splittrar sig måste du förgöra\n"
"all delar innan de återförenas!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Koume\n"
COLOR(LIGHTBLUE) "Ganondorfs surrogat moder.\n"
"Flammornas Häxa. Hon verkar\n"
"känslig mot " COLOR(DEFAULT) "låga temperaturer" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Kotake\n"
COLOR(LIGHTBLUE) "Ganondorfs surrogat moder.\n"
"Isens Häxa. Hon verkar\n"
"känslig mot " COLOR(DEFAULT) "höga temperaturer" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Järn Knoge\n"
COLOR(LIGHTBLUE) "Någonting är väldigt fel...\n"
"Det där är ingen vanlig fiende!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Järn Knoge\n"
COLOR(LIGHTBLUE) "Se upp när den anfaller med yxan! \n"
"Den gör stor skada! Ge igen när du\n"
"ser en öppning!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dödskallsunge\n"
COLOR(LIGHTBLUE) "Är detta vad som händer med barn som\n"
"hamnar vilse i skogen...? Han verkar inte\n"
"vara speciellt förtjusen i vuxna." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Like Like\n"
COLOR(LIGHTBLUE) "En fiende som äter " COLOR(DEFAULT) "sköldar " COLOR(LIGHTBLUE) "och\n"
"vissa " COLOR(DEFAULT) "kläder" COLOR(LIGHTBLUE) ". Besegra den snabbt\n"
"för att ta tillbaka dina saker!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beamos\n"
COLOR(LIGHTBLUE) "Se upp för den sökande strålen!\n"
"Jag slår vad om att den inte gillar när\n"
"den får " COLOR(DEFAULT) "rök" COLOR(LIGHTBLUE) " i ögonen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anubis\n"
COLOR(LIGHTBLUE) "Den är känslig mot " COLOR(RED) "Eld" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Freezzard\n"
COLOR(LIGHTBLUE) "Se upp för dess isande\n"
"andedräkt! Förgör den fullständigt\n"
"innan den kan återskapa sig." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf, den Onda Kungen\n"
COLOR(LIGHTBLUE) "Jag har ingen aning om vad hans\n"
"svaghet är!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "Nu har jag verkligen ingen aning om\n"
"vad hans svaghet är!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dödskallsunge\n"
COLOR(LIGHTBLUE) "Är detta vad som händer med barn som\n"
"hamnar vilse i skogen...? Han kanske\n"
"kan bli vår vän om vi gör någonting..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dödskallsunge\n"
COLOR(LIGHTBLUE) "Är detta vad som händer med barn som\n"
"hamnar vilse i skogen...? Han verkar\n"
"olycklig över att inte ha något ansikte..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dödskallsunge\n"
COLOR(LIGHTBLUE) "Är detta vad som händer med barn som\n"
"hamnar vilse i skogen...? Han ser nöjd\n"
"ut över sitt nya skelettansikte." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Studsa tillbaks stenarna som den\n"
"spottar på dig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe från gravgården?\n"
COLOR(LIGHTBLUE) "Om du stirrar på den med " COLOR(DEFAULT) "[Z] \n"
"Inriktning" COLOR(LIGHTBLUE) ", så försvinner den..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "Om du stirrar på den med " COLOR(DEFAULT) "[Z] \n"
"Inriktning" COLOR(LIGHTBLUE) ", så försvinner den..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Röd Tektite\n"
COLOR(LIGHTBLUE) "Rikta in dig med " COLOR(DEFAULT) "[Z]\n"
"Inriktning" COLOR(LIGHTBLUE) " när den hoppar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Blå Tektite\n"
COLOR(LIGHTBLUE) "Den är svår att besegra på vattnet.\n"
"Lura upp den på land!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Håll reda på dess rörelser\n"
"och låt den åka förbi!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "Dess svaghet är " COLOR(DEFAULT) "rötterna" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat Larv\n"
COLOR(LIGHTBLUE) "Försvara dig med din " COLOR(DEFAULT) "sköld" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vargos\n"
COLOR(LIGHTBLUE) "Lura den att komma nära inpå dig och \n"
"håll ett öga på dess rörelsemönster! Attackera \n"
"då den lättar på garden!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Arg Buske\n"
COLOR(LIGHTBLUE) "Om du kommer nära inpå den, så gömmer \n"
"den sig i gräset..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Affärs-buske\n"
COLOR(LIGHTBLUE) "Om du kommer nära inpå den, så gömmer \n"
"den sig i gräset..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dampé's Spöke\n"
COLOR(LIGHTBLUE) "Det är den döde gravvårdaren's\n"
"spöke! Ifall du jagar honom,\n"
"så kanske han ger dig sin " COLOR(DEFAULT) "minnessak" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg - en utav Poe-systrarna\n"
COLOR(LIGHTBLUE) "Då hon delar upp sig i flera spegelbilder,\n"
"så behöver du ta reda på vilken \n"
"som är " COLOR(DEFAULT) "den riktiga" COLOR(LIGHTBLUE) ". Är det den här?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle - en utav Poe-systrarna\n"
COLOR(LIGHTBLUE) "Sikta på henne då hon kommer fram!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beth - en utav Poe-systrarna\n"
COLOR(LIGHTBLUE) "Sikta på henne då hon kommer fram!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy - en utav Poe-systrarna\n"
COLOR(LIGHTBLUE) "Sikta på henne då hon kommer fram!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gerudo-Tjuv\n"
COLOR(LIGHTBLUE) "Då hon sänker garden,\n"
"attackera! Ifall du inte besegrar henne,\n"
"så blir du tillfångatagen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalbarn\n"
COLOR(LIGHTBLUE) "Räds inte Stalbarnen!\n"
"Bara attackera dem upprepade gånger!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Is-Kis\n"
COLOR(LIGHTBLUE) "Besegra den innan den flyger\n"
"in i dig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vit Vargos\n"
COLOR(LIGHTBLUE) "Lura den att komma nära inpå dig och \n"
"håll ett öga på dess rörelsemönster! Attackera \n"
"då den lättar på garden!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guay\n"
COLOR(LIGHTBLUE) "Besegra den innan den flyger\n"
"in i dig!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Storbläckis\n"
COLOR(LIGHTBLUE) "Attackera den bakifrån!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stor-Poe\n"
COLOR(LIGHTBLUE) "Denna Poe försvinner inte\n"
"om du stirrar på den. Den rör sig snabbt\n"
"trots sin storlek!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tvillinghäxa\n"
COLOR(LIGHTBLUE) "Detta är Kotake och Koume's\n"
"kombinerade form. Vänd deras egna\n"
COLOR(DEFAULT) "magiska attacker " COLOR(LIGHTBLUE) "emot dem!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "Denna Poe försvinner inte\n"
"om du stirrar på den. Den är inte så\n"
"värst lättskrämd..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "Spela med hjälp utav " COLOR(BLUE) "[A]" COLOR(DEFAULT) " och " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." COLOR(YELLOW) "\n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spela med hjälp utav " COLOR(BLUE) "[A]" COLOR(DEFAULT) " och " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " för att Avsluta.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
"\n"
"\n"
OCARINA
)

DEFINE_MESSAGE(0x0870, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Spela " COLOR(ADJUSTABLE) "Skogs-Menuetten" COLOR(DEFAULT) "!" COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT)  QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F") "Spela " COLOR(RED) "Eld's-Bolero" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Spela " COLOR(BLUE) "Vatten-Serenaden" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15") "Spela " COLOR(YELLOW) "Själen's Klagosång" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0D") "Spela " COLOR(PURPLE) "Skuggor's Nocturne" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Spela " COLOR(LIGHTBLUE) "Ljuset's Preludium" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0B") "Följ efter i " COLOR(ADJUSTABLE) "Saria's Visa" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "Okej? Det här är " COLOR(RED) "Visan" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27") "Kom ihåg " COLOR(BLUE) "den här visan" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Behåll " COLOR(YELLOW) "Solen's Visa " COLOR(DEFAULT) "i ditt hjärta.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Denna visa" COLOR(DEFAULT) " öppnar Tidsdörren...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17") "Jag kommer aldrig att glömma " COLOR(PURPLE) "den här visan" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spela med hjälp utav " COLOR(BLUE) "[A]" COLOR(DEFAULT) " och " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " för att Avsluta.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(RED) "Du kan inte warpa här!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Warpa till den Förlorade Skogen?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Warpa till Döda Berget's \n"
"Krater?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(BLUE) "Warpa till Hyliasjön?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Warpa till Ökenkolossen?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Warpa till kyrkogården?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Warpa till Tiden's Tempel?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Du spelade " COLOR(ADJUSTABLE) "Skogs-Menuetten" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0E") "Du spelade " COLOR(RED) "Eld's-Bolero" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Du spelade " COLOR(BLUE) "Vatten-Serenaden" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Du spelade " COLOR(YELLOW) "Själen's Klagosång" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Du spelade " COLOR(PURPLE) "Skuggor's Nocturne" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Du spelade " COLOR(LIGHTBLUE) "Ljuset's Preludium" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Du spelade " COLOR(ADJUSTABLE) "Saria's Visa" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Du spelade " COLOR(RED) "Epona's Visa" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x18") "Du spelade " COLOR(BLUE) "Zelda's Vaggvisa" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Du spelade " COLOR(YELLOW) "Solen's Visa" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Du spelade " COLOR(LIGHTBLUE) "Tidsvisan" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Du spelade " COLOR(PURPLE) "Stormvisan" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Du spelade " COLOR(YELLOW) "Fågelskrämman's Visa" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Äntligen vaknar du!\n"
"Jag heter " COLOR(RED) "Navi" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Det Stora Dekuträdet har\n"
"bett mig att bli din " COLOR(RED) "partner " COLOR(LIGHTBLUE) "från\n"
"och med nu! Trevligt att råkas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x12") "Tjohoo! Hej, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wow! En älva!!" BOX_BREAK UNSKIPPABLE "Äntligen så har en älva kommit till dig,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag väntar på dig här.\n"
"Kila iväg nu! Gå och träffa det \n"
"Stora Dekuträdet!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(BLUE) "[A] " COLOR(DEFAULT) "vid stenen, för att plocka upp den!\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "vid stenen, för att plocka upp den!" BOX_BREAK "Dumma gamla" COLOR(RED) " Mido" COLOR(DEFAULT) "...han tvingade mig att \n"
"plocka upp stenarna utanför hans hus."
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Åh, du har en " COLOR(LIGHTBLUE) "älva" COLOR(DEFAULT) " nu?!\n"
"Det var ju jättebra, " NAME "!" BOX_BREAK UNSKIPPABLE "Va?" BOX_BREAK UNSKIPPABLE "Det\n"
COLOR(RED) "Gamla Dekuträdet" COLOR(DEFAULT) " har kallat dig? Vilken ära!" BOX_BREAK UNSKIPPABLE "Han kanske ger dig en speciell gåva!\n"
"Tihi!" BOX_BREAK UNSKIPPABLE "Det är för att det Stora Dekuträdet \n"
"är vår fader, skogen's\n"
"väktare, han gav liv till \n"
"alla oss Kokiri!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag undrar om det " COLOR(RED) "Stora Dekuträdet " COLOR(DEFAULT) "\n"
"skänkte liv till allting som finns\n"
"i skogen, jag menar... utöver oss \n"
"Kokiri?"
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi tar och jobbar på några tekniker!" BOX_BREAK "För att " COLOR(RED) "hoppa åt sidan " COLOR(DEFAULT) "vid " COLOR(LIGHTBLUE) "[Z] \n"
"Markering" COLOR(DEFAULT) ", tryck " COLOR(BLUE) "[A] " COLOR(DEFAULT) "medan du rör dig åt\n"
"höger eller vänster." BOX_BREAK "För att göra en " COLOR(RED) "bakåtvolt" COLOR(DEFAULT) " vid " COLOR(LIGHTBLUE) "[Z] \n"
"Markering" COLOR(DEFAULT) ", tryck " COLOR(BLUE) "[A] " COLOR(DEFAULT) "medan du rör dig\n"
"bakåt." BOX_BREAK "Fär att göra en " COLOR(RED) "rull-attack" COLOR(DEFAULT) " vid " COLOR(LIGHTBLUE) "[Z] \n"
"Markering" COLOR(DEFAULT) ", tryck " COLOR(BLUE) "[A] " COLOR(DEFAULT) "medan du rör dig\n"
"frammåt. Du kan undvika skada\n"
"medan du rullar." BOX_BREAK "Om du har ditt svärd draget vid\n"
COLOR(LIGHTBLUE) "[Z] markering" COLOR(DEFAULT) ", så kan du göra en" COLOR(RED) " \n"
"hopp-attack" COLOR(DEFAULT) " genom att trycka " COLOR(BLUE) "[A]" COLOR(DEFAULT) "! En hopp-attack \n"
"gär dubbelt så mycket skada!" BOX_BREAK "Du kan använda " COLOR(LIGHTBLUE) "[Z] Markering " COLOR(DEFAULT) "på\n"
COLOR(RED) "stenen" COLOR(DEFAULT) " här jämte mig, so kom igen och \n"
"öva nu!"
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du har inte tillåtelse att lämna \n"
"skogen!" TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det Stora Kokiriträdet har sagt det att\n"
"ifall en Kokiri lämnar skogen, så kommer \n"
"hen att dö!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Dumbomen" COLOR(RED) " Mido" COLOR(DEFAULT) " tvingade mig till att klippa \n"
"gräset utanför Saria's hus." BOX_BREAK UNSKIPPABLE "Mido sa att han skulle göra jobbet\n"
"för att hon skulle tycka om honom, men det\n"
"är jag som får utföra allt jobb!" TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du och " COLOR(RED) "Saria" COLOR(DEFAULT) " är ju väldigt nära vänner,\n"
"så kan du hjälpa mig att klippa \n"
"gräset?" BOX_BREAK "Du får behålla allt du hittar \n"
"medan du klipper det."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ja, precis! Det är så man använder en\n"
COLOR(LIGHTBLUE) "älva" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Det är ju jättebra att du äntligen har fått\n"
"en älv-" COLOR(RED) "" COLOR(DEFAULT) "partner!" BOX_BREAK UNSKIPPABLE "Jag ska lära dig hur du pratar med \n"
"folk med hjälp utav din älva!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Då en älva flyger nära en person \n"
"eller sak, så tryck " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " för att " COLOR(RED) "titta " COLOR(DEFAULT) "i den\n"
"riktningen." BOX_BREAK "Om du använder " COLOR(LIGHTBLUE) "[Z] Markering" COLOR(DEFAULT) ", så kan du \n"
"tala med avlägsna personer, \n"
"precis som vi gör nu." BOX_BREAK "Då du inte har någonting som du\n"
"kan markera, så kan du trycka " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " bara för\n"
"att " COLOR(RED) "se frammåt" COLOR(DEFAULT) ".\n"
"Prova!"
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Åh, en " COLOR(LIGHTBLUE) "älva " COLOR(DEFAULT) "har äntligen kommit till dig!" BOX_BREAK UNSKIPPABLE "Nu så har du mycket att lära!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Wow! " QUICKTEXT_ENABLE "Vilka fantastiska nyheter!" QUICKTEXT_DISABLE "\n"
"Jag är så glad för din skull!" BOX_BREAK UNSKIPPABLE "Nu är du en äkta Kikiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Så det säger du? \n"
"Det Stora Dekuträdet har\n"
"kallat på dig?" BOX_BREAK UNSKIPPABLE "Det är en riktigt stor ära att få tala med\n"
"Det Stora Dekuträdet!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh, så du ska redan gå..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Men det är okej, för vi kommer att vara\n"
"vänner för evigt...\n"
"Eller hur?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag vill att du ska ha den här Okarinan...\n"
"Var snäll och ta väl hand om den."
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Då du spelar på min Okarina, så vill\n"
"jag att du tänker på mig och kommer\n"
"tillbaka till skogen på besök."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh... Navi...\n"
"Du har återvänt..." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Välkommen..." BOX_BREAK UNSKIPPABLE "Lyssna noga på vad jag, det Stora\n"
COLOR(RED) "Dekuträdet" COLOR(DEFAULT) ", har att berätta för dig..." BOX_BREAK UNSKIPPABLE "Den gångna tiden's slummer \n"
"borde ha varit rastlös, och\n"
"fylld utav mardrömmar..." BOX_BREAK UNSKIPPABLE "Medan kraften hos ondskan's tjänare\n"
"har ökat, så har ett underliggande\n"
"klimat genomsyrat riket som orsakar mardrömmar\n"
"hos de som är känsliga för det..." BOX_BREAK UNSKIPPABLE "Du har onekligen kännt av det..." BOX_BREAK UNSKIPPABLE  NAME "... \n"
"Tiden har kommit för att testa ditt\n"
"mod..." TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag har fått en " COLOR(RED) "förbannelse" COLOR(DEFAULT) "över mig...\n"
"Jag behöver dig för att lyfta den\n"
"med hjälp utav din listighet och ditt mod." BOX_BREAK "Är du tillräckligt modig\n"
"för att ta dig an denna uppgift?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I så fall inträd, du modige \n"
NAME ", och du med, \n"
"Navi..." BOX_BREAK UNSKIPPABLE "älvan Navi...  \n"
"Du måste ge " NAME "ditt stöd..." BOX_BREAK UNSKIPPABLE "och " NAME "...Då " COLOR(LIGHTBLUE) "Navi \n"
COLOR(DEFAULT) "talar, så använd " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "för att lyssna noga \n"
"på hennes visa ord..."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du kanske ännu inte litar \n"
"på dina förmågor...\n"
"Återvänd till Kokiriskogen för\n"
"att utveckla dina färdigheter i strid..." BOX_BREAK "Då du är redo, så återvänd hit \n"
"och tala med mig genom att använda " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den bästa platsen att lära sig\n"
"nya färdigheter på är i " COLOR(ADJUSTABLE) "Skogen's \n"
"Tränings-center" COLOR(DEFAULT) "." COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "Det är på kullen\n"
"precis ovanför här."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Aj-aj-aj!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Förlåt mig, herrn!" QUICKTEXT_DISABLE "\n"
"Om jag ger dig en ledtråd, låter du mig \n"
"gå i så fall?" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Då du hoppar från en hög avsats,\n"
"om du håller inne " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " frammåt, så kommer du\n"
"att rulla på marken då du landar \n"
"och skadar dig inte från fallet." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Jag kan inte garantera att det\n"
"funkar däremot, om avsatsen är,\n"
"väldigt högt upp, heh heh!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Fast ptja, gör ett försök om du är\n"
"modig nog!\n"
QUICKTEXT_ENABLE "Bah ha hah!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh!\n"
"Är det inte den där Kokirigrabben som gömmer\n"
"sig bakom masken?"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ganska ovanlig mask det där\n"
"ändå. Heh heh! Jag gillar den! Den skulle kanske\n"
"kunna få mig att se lite tuffare ut." BOX_BREAK "Hmmm... Du skulle inte kunna ge den till mig?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Absolut inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nedrans! Det var ju trist för mig det..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tjoho! Jag ska ha på mig den\n"
"jämt och ständigt!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Han gav dig precis " COLOR(RED) "10 Rupees" COLOR(DEFAULT) " för \n"
"den här 20-Rupees masken! Du förlorade \n"
"pengar på den affären!" BOX_BREAK UNSKIPPABLE "Gå tillbaka till Maskbutiken \n"
"och betala " COLOR(RED) "20 Rupees" COLOR(DEFAULT) " för \n"
"masken. Du får själv stå för \n"
"mellanskillnaden."
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mina polare vill verkligen ha den här masken!\n"
"He he he!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, så du är välbehållen? Du lämnade inte skogen\n"
"trots allt då med andra ord, eller gjorde du?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Visste du att om du håller inne " COLOR(LIGHTBLUE) "▼\n"
COLOR(DEFAULT) "frammåt då du hoppar från en avsats,\n"
"så kommer du att rulla då du landar. Det\n"
"absorberar stöten då du landar." BOX_BREAK "Om du faller från för hög höjd däremot,\n"
"så tar du fortfarande skada..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria sa att hon väntar på\n"
"det vanliga stället."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bra jobbat, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du har en häftig Slangbella va?" BOX_BREAK "Vet du vad som är så häftigt med den?\n"
"Du kan sikta genom att hålla inne\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " och skjuta genom at släppa\n"
"knappen! Hur häftigt är inte det?!" BOX_BREAK "om du har Slangbellan redo,\n"
"så kan du använda " COLOR(LIGHTBLUE) "[Z] Markering" COLOR(DEFAULT) " för att \n"
COLOR(RED) "skjuta medan du rör på dig" COLOR(DEFAULT) ".... visste \n"
"du det?"
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nej, " NAME "...\n"
"Jag har inte mycket tid kvar..."
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Så...lyssna noga...\n"
"En " COLOR(RED) "ondskefull man från öknen" COLOR(DEFAULT) " \n"
"har kastat en ödesdiger förbannelse över mig..."
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du letar efter Saria, så är\n"
"i den " COLOR(ADJUSTABLE) "Förlorade Skogen" COLOR(DEFAULT) ", som vanligt." BOX_BREAK "Kom inte här och säg att du inte \n"
"känner till vart det är! Ingången är där uppe\n"
"på avsatsen med utsikt över \n"
"byn!" BOX_BREAK "Jag vet att du kommer att gå vilse! Men \n"
"oroa dig inte, du kommer bara att komma\n"
"tillbaka till ingången!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Fnys!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du får aldrig låta ökenmannen \n"
"i sin svarta rustning lägga \n"
"vantarna på den heliga Trekraften..." BOX_BREAK UNSKIPPABLE "Du får aldrig låta den mannen,\n"
"med sitt onda hjärta, träda in i det \n"
"Heliga Kungariket" COLOR(RED) " " COLOR(DEFAULT) "som legenderna talar om..." BOX_BREAK UNSKIPPABLE "Den onda mannen som kastade dödens \n"
"över mig och tömde mig \n"
"på kraft..." BOX_BREAK UNSKIPPABLE "På grund utav den förbannelsen, så är mitt slut\n"
"nära..." BOX_BREAK UNSKIPPABLE "Trots att dina hjältemodiga insateser \n"
"att lyfta förbannelsen var lyckade, \n"
"så var jag dömd före du ens började..." BOX_BREAK UNSKIPPABLE "Ja, jag kommer att somna in snart...\n"
UNSKIPPABLE "Men sörj mig inte..." BOX_BREAK UNSKIPPABLE "Jag har haft möjlighet att berätta för dig \n"
"om dessa betydelsefulla omständigheter..." BOX_BREAK UNSKIPPABLE "Detta är Hyrule's sista hopp..."
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vår framtid hänger på dig,\n"
NAME "...\n"
"Du är modig..." BOX_BREAK UNSKIPPABLE "Navi...\n"
"Hjälp " NAME " att fullborda \n"
"min vilja..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Jag bönfaller dig... Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "Far...väl..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vi tar oss till Slottet Hyrule,\n"
NAME "!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Far-väl..." COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "Stora Dekuträd..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vilken otur...Heh heh!"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du spela en gång till?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hallå där! \"" COLOR(LIGHTBLUE) "Herr utan Älva" COLOR(DEFAULT) "!\"\n"
"Vad har du för ärende hos\n"
"Det Stora Dekuträdet?" BOX_BREAK UNSKIPPABLE "Utan en älva, så är du inte\n"
"ens en riktig man!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du vill passera härigenom,\n"
"så bör du i alla fall " COLOR(BLUE) "utrusta dig" COLOR(DEFAULT) " med ett " COLOR(ADJUSTABLE) "svärd" COLOR(RED) "\n"
COLOR(DEFAULT) "och en" COLOR(LIGHTBLUE) "sköld" COLOR(DEFAULT) "!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Suck!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x57")  QUICKTEXT_ENABLE "Va?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "vill inte låta dig besöka \n"
"det Stora Dekuträdet?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kan köpa en " COLOR(LIGHTBLUE) "sköld" COLOR(DEFAULT) " i affären,\n"
"men det finns bara ett " COLOR(ADJUSTABLE) "svärd" COLOR(DEFAULT) "\n"
"gömt någonstans i skogen."
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Om du vill träffa \n"
"det Stora Dekuträdet, så bör du i alla fall \n"
"utrusta dig med ett " COLOR(ADJUSTABLE) "svärd" COLOR(DEFAULT) " och en " COLOR(LIGHTBLUE) "sköld" COLOR(DEFAULT) "!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag, den fantastiske Mido," COLOR(RED) " " COLOR(DEFAULT) "kommer aldrig att \n"
"acceptera dig som en utav oss!" BOX_BREAK "Nedrans! Hur blev en sådan som du\n"
"Saria och det Stora Dekuträdet's\n"
"favorit? va?!\n"
"grubbel...grubbel..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag kan lära dig om " COLOR(RED) "ikonerna\n"
COLOR(DEFAULT) "högst upp på skärmen.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Om de gula ikonerna\n"
"Om de blå ikonerna" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"De tre gula ikonerna uppe \n"
"i högra hörnet kallas för " COLOR(YELLOW) "[C] ikoner" COLOR(DEFAULT) "." BOX_BREAK "De visar vad du kan\n"
"använda med " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "och" COLOR(YELLOW) " \n"
"[C-Right] " COLOR(DEFAULT) "knapparna." BOX_BREAK "Så får ett " COLOR(YELLOW) "[C] Knappföremål" COLOR(DEFAULT) ", \n"
"så gå in i " COLOR(YELLOW) "Föremåls-skärmen" COLOR(DEFAULT) " \n"
"och välj det på en utav de tre\n"
COLOR(YELLOW) "[C] Knapparna" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den blå ikonen högst upp på\n"
"skärmen kallas för " COLOR(BLUE) "Actionikonen" COLOR(DEFAULT) "." BOX_BREAK "Actionikonen visar dig \n"
"vilken handling du kan utföra\n"
"då du trycker på " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Se till att stanna upp på många platser\n"
"för att se olika handlingar du kan utföra."
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du vill lära dig om\n"
COLOR(RED) "kartan " COLOR(DEFAULT) "och " COLOR(RED) "föremål" COLOR(DEFAULT) ", så fråga mig bara.\n"
"Men fråga bara om du orkar\n"
"lyssna på en lång förklaring." BOX_BREAK "Vad skulle du vilja veta mer om?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Om kartan \n"
"Om föremål\n"
"Fråga inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du har en " COLOR(RED) "karta" COLOR(DEFAULT) " längst ned\n"
"till höger på skärmen." BOX_BREAK "Den " COLOR(YELLOW) "gula pilen " COLOR(DEFAULT) "visar din \n"
"nuvarande position and riktningen du\n"
"står inför. Den " COLOR(RED) "röda markeringen " COLOR(DEFAULT) "visar\n"
"vart du gick in då du kom till detta området." BOX_BREAK "Du kan stänga av och sätta på kartan\n"
"med hjälp utav " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) "." BOX_BREAK "Om du vill se namnet på en\n"
"plats, tryck " COLOR(RED) "START" COLOR(DEFAULT) "." BOX_BREAK "På den här skärmen så.\n"
"väljer du " COLOR(RED) "Kart-Skärmen" COLOR(DEFAULT) "." BOX_BREAK "På Kart-Skärmen, så kan du \n"
"se en karta över Hyrule.\n"
"Hänger du med?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Det finns tre typer utav föremål:\n"
COLOR(BLUE) "Utrustnings-Föremål" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C] Knapp-Föremål" COLOR(DEFAULT) "\n"
"och " COLOR(LIGHTBLUE) "Uppdrags-Föremål" COLOR(DEFAULT) "." BOX_BREAK COLOR(BLUE) "Utrustnings-Föremål" COLOR(DEFAULT) " är saker som exempelvis \n"
"svärd, sköld och kläder \n"
"som är i effekt då du har utrustat dig med\n"
"dem." BOX_BREAK COLOR(YELLOW) "[C] Knapp-Föremål" COLOR(DEFAULT) " kan bli placerade på \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) ", och " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", och\n"
"används genom att man trycker på dessa knappar." BOX_BREAK COLOR(LIGHTBLUE) "Uppdrags-Föremål " COLOR(DEFAULT) "är saker som du \n"
"samlar på dig under ditt äventyr. Du\n"
"bara bär runt på dem." BOX_BREAK "Om du vill byta utrustning\n"
"eller bara se över dina tillgångar,\n"
"tryck " COLOR(RED) "START" COLOR(DEFAULT) ". \n"
"Du får då upp en ny skärm." BOX_BREAK "Byt mellan de fyra \n"
"olika skärmarna med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " eller\n"
COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "byt eller titta på föremål\n"
"så som du känner. Ta dig en titt!" BOX_BREAK "Då du bestämmer dig för ta på dig ett \n"
COLOR(BLUE) "Utrustnings-Föremål" COLOR(DEFAULT) ", tryck " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". För\n"
COLOR(YELLOW) "[C] Knapp-föremål" COLOR(DEFAULT) ", tryck " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ",\n"
COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "eller " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "." BOX_BREAK "Det där var en ganska så lång förklaring.\n"
"Förstod du allt det där?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ptja, kom ihåg det här bara. Om du\n"
"vill " COLOR(ADJUSTABLE) "spara" COLOR(DEFAULT) ", tryck " COLOR(RED) "START " COLOR(DEFAULT) "för att\n"
"få upp skärmarna, tryck sedan\n"
COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Min syster tog några Rupees och \n"
"fick iväg för att handla i affären\n"
"som har ett rött tak.\n"
"Tihi!" BOX_BREAK "När vi ändå talar om " COLOR(RED) "Rupees" COLOR(DEFAULT) ", en " COLOR(ADJUSTABLE) "grön " COLOR(DEFAULT) "Rupee\n"
"är värd en Rupee, en " COLOR(BLUE) "blå" COLOR(DEFAULT) " är värd\n"
"fem och en " COLOR(RED) "röd" COLOR(DEFAULT) " är värd \n"
"tjugo. Hehehe!"
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den här affären...säljer saker som du\n"
"kan få gratis i skogen!\n"
"Tihi!" BOX_BREAK "Vet du hur du använder en \n"
COLOR(RED) "Dekusköld" COLOR(DEFAULT) "? Tihi!" BOX_BREAK "Då du får skölden, tryck\n"
COLOR(RED) "START " COLOR(DEFAULT) "för att öppna upp skärmarna.\n"
"Välj " COLOR(BLUE) "Utrustnings-skärmen\n"
COLOR(DEFAULT) "med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " eller " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "." BOX_BREAK "På " COLOR(BLUE) "Utrustnings-skärmen" COLOR(DEFAULT) ", \n"
"så väljer du föremålet som du vill utrusta dig med\n"
"och trycerk " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Så fort du använder skölden, håll upp den\n"
"med " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " och byt vinkel med hjälp\n"
"utav " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Tihi!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du veta hur du använder\n"
" " COLOR(YELLOW) "[C-Up] Knappen" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du trycker " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", så kan du\n"
"ändra din vy." BOX_BREAK "På en sådan här plats, så byter du\n"
"kameravinkel till ovanför. Utomhus, på\n"
"exempelvis ett fält, så kommer det istället\n"
"att byta till förstapersons-perspektiv." BOX_BREAK "Då \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\" visas uppe i\n"
"det högra hörnet på din skärm \n"
"så vill hon tala med dig.\n"
"Använd " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " för att lyssna på henne!"
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ptja, om du provar dig fram, \n"
"så kommer du att räkna ut det."
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det där var inte riktigt Saria's Visa..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "är väldigt upprörd!\n"
"Har någonting hänt honom?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va? Vart är du på väg?!" BOX_BREAK "Till slottet?\n"
"Vart är slottet någonstans?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi Kokiri dör om vi lämnar\n"
"skogen!" BOX_BREAK "Du tänker inte att försöka lämna\n"
"skogen, eller?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hallå där, " NAME "!\n"
"Vad har du gjort?!" BOX_BREAK UNSKIPPABLE "Det Stora Dekuträdet...har han...\n"
"dött?" BOX_BREAK UNSKIPPABLE "Vad fick dig att göra något \n"
"sådant?! Allt är ditt fel!!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hallå där!!" QUICKTEXT_DISABLE "\n"
"Vad gör du i mitt hus?!"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", du är i säkerhet!" TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria och " NAME " kommer att vara\n"
"vänner för evigt."
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Har någonting hänt \n"
"Det Stora Dekuträdet?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det känns som att luften i skogen\n"
"har förändrats på något vis."
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", tänker du att\n"
"gå din väg?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kommer du tillbaka om du\n"
"förlorar din sköld?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x80") "Alla vi små Dekubusk-bröder\n"
"håller med...du ser precis \n"
"ut som vår heliga skogstotem!" BOX_BREAK SFX("\x38\x80") "Som en gåva från oss, var\n"
"och acceptera dessa " COLOR(RED) "Dekukäppar" COLOR(DEFAULT) ".\n"
"Vi ska också förbättra din\n"
"bärförmåga!" BOX_BREAK "Abrahadabra!" BOX_BREAK SFX("\x38\x80") "Simsalabim!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sedan det Stora Dekuträdet började\n"
"vissna...så har fler elakingar \n"
"börjat dyka upp i skogen...\n"
"Jag är rädd!"
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "En ondskefull vind blåser \n"
"från Skogstemplets riktning." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Saria" COLOR(DEFAULT) " vänster, säger,\n"
"\"Jag måste göra någonting\n"
"åt det!\"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"" COLOR(ADJUSTABLE) "Skogstemplet " COLOR(DEFAULT) "är beläget \n"
"i den Heliga Skogen's glänta på\n"
"andra sidan av den Förlorade Skogen."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria gick iväg till templet \n"
"och har inte kommit tillbaka..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallå där herrn! Du bör inte\n"
"använda en Dekusköld! De är\n"
"endast till för barn!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vart är Saria? \n"
"Känner du Saria, herrn?\n"
"Det var märkligt..." TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vart har " COLOR(RED) "Mido" COLOR(DEFAULT) " tagit vägen\n"
"under en sådan här kris?"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag förstår. du hade inga som helst \n"
"problem att ta dig in i skogen, \n"
"herrn..." BOX_BREAK "Störde elakingarna där ute dig\n"
"så mycket? Före det Stora Dekuträdet \n"
"dog, så stötte man aldrig på\n"
"sådana där saker här...." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"På grund av att det är farligt utomhus\n"
"så stannar jag alltid hemma. Men \n"
"jag är fruktansvärt uttråkad här inne!"
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kan köpa " COLOR(RED) "pilar " COLOR(DEFAULT) "i affären \n"
"enbart om du har en " COLOR(RED) "pilbåge" COLOR(DEFAULT) ". Har du \n"
"en sådan, herrn?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Har du varit ute och rest\n"
"mycket, herrn?\n"
"Har du någonsin mött en pojke vid namn \n"
NAME "?" BOX_BREAK UNSKIPPABLE "Mido har sagt att det Stora \n"
"Dekuträdet vissnade på grund av att\n"
"den pojken gjorde någonting..." BOX_BREAK UNSKIPPABLE "Endast Saria försvarade \n"
NAME "honom...tills hon lämnade." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi kanske missförstod...."
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Har inte jag sett dig\n"
"förr, herrn?"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Herrn, känner du en pojke \n"
"vid namn " NAME "?" BOX_BREAK UNSKIPPABLE "Han lämnade skogen och kom\n"
"aldrig tillbaka..." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag undrar om " NAME " någonsin \n"
"kommer att återvända?"
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Det hade varit jättehäftigt att \n"
"vara så stor som du, herrn! Jag vill verkligen\n"
"vara stor som du!" BOX_BREAK UNSKIPPABLE "Jag vill vara stor och stark \n"
"så att jag kan ge Dekubuskarna en omgång, men..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi Kokiri blir aldrig så stora \n"
"under hela vår livstid...\n"
"Vilken osis!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Varför följer den där älvan \n"
"efter dig? Du är inte en av oss!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vem är du? Trots att du klär dig \n"
"i Kokirikläder, så kan du inte\n"
"lura mig!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag lovade Saria att jag aldrig\n"
"skulle låta någon passera."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallå där! Jag är ett skott från " COLOR(RED) "det Stora \n"
"Dekuträdet" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Tack vare att du och Saria" COLOR(RED) " " COLOR(DEFAULT) "lyfte\n"
"förbannelsen i Skogstemplet, så \n"
"kan jag gro och växa!" BOX_BREAK UNSKIPPABLE "Tack så mycket!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hej, har du träffat dina gamla\n"
"vänner? ingen utav dem kunde känna\n"
"igen dig i din vuxna kropp,\n"
"eller hur?" BOX_BREAK UNSKIPPABLE "Det är för att " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) " aldrig\n"
"blir vuxna! Även efter sju år\n"
"så förblir de barn!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du måste undra varför just\n"
"du har vuxit upp!" BOX_BREAK UNSKIPPABLE "Ptja, som du kanske redan har \n"
"gissat, så är du inte en Kokiri!\n"
"Du är faktiskt en " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Jag är glad att jag äntligen\n"
"kunde berätta sanningen för dig!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"För många år sedan, före Hyrules\n"
"Konung förenade landet, så pågick\n"
"det ett våldsamt krig i vår värld." BOX_BREAK_DELAYED("\x5A") "En dag, så försökte en\n"
COLOR(RED) "Hyliansk mor " COLOR(DEFAULT) "och hennes " COLOR(RED) "bebis" COLOR(DEFAULT) "fly\n"
"genom att ta sig till den \n"
"förbjudna skogen." BOX_BREAK_DELAYED("\x5A") "Modern var väldigt illa skadad...\n"
"Hennes enda val var att anförtro\n"
"barnet till " COLOR(RED) "Dekuträdet" COLOR(DEFAULT) ", skogens \n"
"väktare." BOX_BREAK_DELAYED("\x5A") "Dekuträdet kunde känna det på sig att\n"
"detta var ett barn med ett särskilt syfte, vars\n"
"öde skulle komma att forma hela världen,\n"
"så vi tog honom hit till skogen." BOX_BREAK_DELAYED("\x5A") "Efter att modern somnade in, \n"
"så uppfostrade vi barnet som en " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) ".\n"
"Och nu, äntligen, så har \n"
"ödets dag kommit!" FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du är en " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) ", och har alltid\n"
"varit menad att lämna den här skogen." BOX_BREAK UNSKIPPABLE "Och nu...\n"
"Så har du lärt dig om \n"
"ditt öde...\n"
"Så nu vet du vad du måste göra..." BOX_BREAK UNSKIPPABLE "Det är helt riktigt...\n"
"Du måste rädda landet \n"
"Hyrule!" BOX_BREAK UNSKIPPABLE NAME ", lyft förbannelsen \n"
"som vilar över alla tempel\n"
"och återställ freden i Hyrule!!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Den melodin?!" BOX_BREAK UNSKIPPABLE "Saria brukar alltid spela\n"
"den visan!\n"
"Du...Känner du Saria?" BOX_BREAK UNSKIPPABLE "Den visan..." BOX_BREAK UNSKIPPABLE "Saria lärde endast sina vänner \n"
"den visan..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Då jag ser dig... \n"
"Jag vet inte varför, men jag kommer ihåg...\n"
"honom..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nu har jag dig!\n"
"I denna avgrund mellan dröm \n"
"och verklighet, snart är allt som\n"
"är kvar utav dig bara en död kropp!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tack så mycket...\n"
"Tack vare dig, så kunde jag vakna upp\n"
"som en Vise..." BOX_BREAK UNSKIPPABLE "Jag är " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"Skogstemplets Vise..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "Saria kommer alltid att förbli...\n"
SHIFT("\x3C") "din vän..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tidens flöde är alltid grym...\n"
"Dess hastighet färdas olika\n"
"från person till person, men ingen \n"
"kan förändra det..." BOX_BREAK UNSKIPPABLE "Något som aldrig förändras däremot\n"
"är minnet från ungdomens dagar..." BOX_BREAK UNSKIPPABLE "För att återkomma hit så,\n"
"spela " COLOR(ADJUSTABLE) "Skogs-Menuetten" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...\n"
"På återseende..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria har inte kommit tillbaka ännu...\n"
"Men jag vet att hon en dag ska återkomma..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Okej...\n"
"Jag litar på dig." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Åh...Jag förstår..." BOX_BREAK UNSKIPPABLE "Saria kommer aldrig mer tillbaka..." BOX_BREAK UNSKIPPABLE "Men...Jag...Jag lovade \n"
"Saria..." BOX_BREAK UNSKIPPABLE "Att om " NAME " kommer tillbaka, så \n"
"skulle jag berätta för honom att \n"
"Saria väntade på honom..." BOX_BREAK UNSKIPPABLE "Därför att " TEXT_SPEED("\x03") "Saria...Gillade...\n"
"Verkligen..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Du." BOX_BREAK "Om du träffar på honom någonstans, snälla\n"
"berätta det för honom..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lär mig om hur man fäktas!\n"
"Det enda jag har gjort i hela mitt liv\n"
"är att spamma" COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "!\n"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag får fortfarande känslan utav\n"
"att jag har träffat dig förr, herrn."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du är så stor och stark!\n"
"Jag vill verkligen bli som du \n"
"en dag trots att jag alltid\n"
"kommer att vara liten."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... Jag undrar om han\n"
"någonsin kommer tillbaka..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det känns som att vi har\n"
"känt varandra länge, herrn!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nu då " COLOR(RED) "Dekuträdets grodd" COLOR(DEFAULT) "\n"
"växer i det Stora Dekuträdets \n"
"glänta, så har skogen\n"
"återvänt till det normala!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi ska alla hjälpas åt att\n"
"beskydda skogen!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nyligen så har en lättsam vind\n"
"börjat blåsa in över oss."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sedan den lättsamma vinden \n"
"började blåsa, så har jag blivit\n"
"övertygad att " NAME " \n"
"kommer att komma tillbaka!"
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag undrar om Saria kommer tillbaka..."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag är säker på att " NAME " kommer \n"
"kommer att återvända!"
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Det Stora Dekuträdet...\n"
COLOR(DEFAULT)  SHIFT("\x48")  COLOR(LIGHTBLUE) "Jag är tillbaka!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Den där onda mannen använder\n"
"oavbrutet sina otäcka magiska krafter\n"
"för att söka det Heliga Kungariket\n"
"som är kopplat till Hyrule..." BOX_BREAK UNSKIPPABLE "För det är i det Heliga \n"
"Kungariket som man kan finna den gudomliga\n"
"reliken, " COLOR(LIGHTBLUE) "Trekraften" COLOR(DEFAULT) ", som innehåller \n"
"gudarnas heliga essens..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Före tiden tog sin början, före\n"
SHIFT("\x31") "andar och liv existerade..." QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Så steg tre gyllene gudinnor\n"
SHIFT("\x04") "ned till den kaos som var Hyrule..." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Din, kraftens gudinna..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Nayru, vishetens gudinna..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Farore, modets gudinna..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "med sina starka flammande armar, hon\n"
SHIFT("\x0A") "brukade landet och skapade\n"
SHIFT("\x3A") "den röda jorden." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Hällde sin vishet över jorden\n"
SHIFT("\x0F") "och skänkte världen\n"
SHIFT("\x45") "lagens prägel." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Med sin rika själ, skapade alla\n"
SHIFT("\x14") "livsformer som skulle komma att\n"
SHIFT("\x4B") "upphålla lagen." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "De tre gudinnorna\n"
SHIFT("\x22") "hade fullbordat sitt arbete,\n"
SHIFT("\x19") "och återgick till himmelriket." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x14") "Det enda som återstod, vid den\n"
SHIFT("\x07") "plats som gudinnorna hade lämnat världen,\n"
SHIFT("\x1B") "var tre heliga gyllene trianglar." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Sedan dess så har de heliga\n"
SHIFT("\x0E") "trianglarna blivit en grundpelare\n"
SHIFT("\x2E") "för vår världs beskydd." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Och platsen där\n"
SHIFT("\x1C") "trianglarna nu mer vilar\n"
SHIFT("\x3B") "är det Heliga Kungariket." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hej grabben, du gjorde rätt bra ifrån dig...\n"
"Det verkar som att du börjar\n"
"kunna det här..." BOX_BREAK_DELAYED("\x3C") "Men du har endast besegrat\n"
"min skugga...\n"
"Då du slåss mot den riktiga jag så \n"
"kommer det inte att bli lika lätt!" BOX_BREAK_DELAYED("\x3C") "Vilken värdelös skapelse det \n"
"där spöket var! Jag ska fördriva det till\n"
"tomhetens fasansfulla avgrunder!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag visste hela tiden att du skulle \n"
"komma. För jag känner dig..." BOX_BREAK UNSKIPPABLE "Nej..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "Du behöver inte förklara\n"
"det för mig..." BOX_BREAK UNSKIPPABLE "För ödet säger det att \n"
"du och jag inte kan leva i samma värld."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag kommer att stanna här som Skogens\n"
"Vise ochj hjälpa dig..." BOX_BREAK UNSKIPPABLE "Så, ta den här \n"
COLOR(ADJUSTABLE) "Medaljen" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du har sannerligen bevisat \n"
"ditt mod..." BOX_BREAK UNSKIPPABLE "Jag visste att du skulle kunna\n"
"utföra min önskan..."
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Så, jag har nu mer att berätta för dig,\n"
"är du beredd att lyssna...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...\n"
"Gå nu till Hyrules Slott..." BOX_BREAK UNSKIPPABLE "Där så kommer du säkerligen att\n"
"möta " COLOR(RED) "Ödets Prinsessa" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Ta den här" COLOR(RED) "stenen " COLOR(DEFAULT) "med dig.\n"
"Stenen som han så innerligt ville\n"
"ha, att han kastade den här\n"
"förbannelsen över mig..."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag" COLOR(RED) " " COLOR(DEFAULT) "visste...\n"
"att du skulle lämna skogen...\n"
"en vacker dag, " NAME "..." BOX_BREAK UNSKIPPABLE "För du är varken lik mig\n"
"eller" COLOR(RED) " " COLOR(DEFAULT) "mina vänner...."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE) "Hej, " QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "!\n"
"Vakna!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Det" COLOR(RED) " Stora Dekuträdet " COLOR(LIGHTBLUE) "vill\n"
"tala med dig!\n"
QUICKTEXT_ENABLE  NAME ", stå upp!" QUICKTEXT_DISABLE  COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Hallå! " QUICKTEXT_ENABLE "Kom igen!" QUICKTEXT_DISABLE  COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Kan Hyrules öde verkligen vila\n"
"på en sådan lat pojke?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Att hoppa är inte trendigt just nu.\n"
"Själv så är jag besatt av att göra " COLOR(RED) "bakåtvolter" COLOR(DEFAULT) "!\n"
SHIFT("\x32") "Kan du också göra en?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Det " COLOR(RED) "Stora Dekuträdet \n"
COLOR(LIGHTBLUE) "har kallat dig!\n"
"Så sätt igång och börja gå, på en gång!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x4B") "Navi...\n"
SHIFT("\x23") "Navi, vart är du?\n"
SHIFT("\x39") "Träd fram...."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh, " COLOR(LIGHTBLUE) "älvan Navi" COLOR(DEFAULT) "...\n"
"Lyssna till mina ord, orden \n"
"från det " COLOR(RED) "Stora Dekuträdet" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Känner du av det?\n"
"Fientliga mörka vindar som\n"
"sveper in över detta rike..." BOX_BREAK UNSKIPPABLE "Ondskefulla krafter bäddar i detta nu\n"
"för att anfalla vårat\n"
"rike Hyrule..." BOX_BREAK UNSKIPPABLE "Under lång tid, har " COLOR(RED) "Kokiriskogen,\n" COLOR(DEFAULT)
"livets källa, tjänat som en \n"
"barriär för att avskräcka utomstående \n"
"samt upprätthålla ordningen i vår värld..." BOX_BREAK UNSKIPPABLE "Men...inför denna onda enorma\n"
"kraft, så är min egen kraft \n"
"ingenting..." BOX_BREAK UNSKIPPABLE "Det verkar som att tiden har kommit \n"
"för " COLOR(RED) "pojken utan älva " COLOR(DEFAULT) "att börja \n"
"sin resa..." BOX_BREAK UNSKIPPABLE "Ynglingen vars öde är att\n"
"leda Hyrule på en väg mot\n"
"sanning och rättvisa..." BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "...gå nu! Finn vår unge\n"
"vän och vägled honom till mig..." BOX_BREAK UNSKIPPABLE "Jag har inte mycket tid kvar." BOX_BREAK UNSKIPPABLE "Flyg, Navi, flyg! Skogens öde\n"
"nej, hela världen, vilar\n"
"på dig!"
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Snälla förlåt mig, herrn! Jag \n"
"ska aldrig göra om det! om du låter mig \n"
"gå, så lär jag dig någonting häftigt." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Du besegrar aldrig mina bröder\n"
"om du inte straffar dem \n"
"i rätt ordning." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Ordningen är..." TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) "2  3  1" COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tjugotre är nummer ett!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Tycker du att jag är en förrädare?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Hur kände du till vår hemlighet?!\n"
"Så " QUICKTEXT_ENABLE "irriterande!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Det stör mig så mycket att\n"
"jag ska avslöja Drottning Gohmas\n"
"hemlighet för dig!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "För att genomföra denna kupp emot\n"
"hennes höghet Drottning Gohma, slå\n"
"med ditt svärd " COLOR(RED) "medan hon är \n"
"bedövad" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Åh, Drottis..." BOX_BREAK SFX("\x38\x80")  QUICKTEXT_ENABLE "Jag beklagar!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"I de vidsträckta skogarna i Hyrule..." BOX_BREAK_DELAYED("\x28")  SHIFT("\x16") "Har jag länge tjänat som\n"
SHIFT("\x33") "skogens väktare...\n"
SHIFT("\x0C") "Jag är känd som Dekuträdet..." FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "Den här skogens barn, de som\n"
SHIFT("\x19") "kallas för Kokiri, bor här med mig." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0B") "Varje Kokiri har sin egen\n"
SHIFT("\x38") "skyddsälva." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "Fast, där finns en pojke" COLOR(RED) " " COLOR(DEFAULT) "who\n"
SHIFT("\x20") "som inte har en älva..." FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ger mig! I gengäld, så kan jag sälja \n"
"din Dekunötter!\n"
COLOR(RED) "5 stycken   20 Rupees" COLOR(DEFAULT) " kostar de!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Utmärkt! Du vinner! I gengäld,\n"
"så kan jag sälja dig Dekukäppar!\n"
COLOR(RED) "1 styck   15 Rupees " COLOR(DEFAULT) "kostar de!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Utmärkt! Du vinner! I gengäld för\n"
"låter mig leva, så kan jag sälja dig en \n"
"Hjärtbit!\n"
COLOR(RED) "1 styck   10 Rupees " COLOR(DEFAULT) "kostar den!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Låt mig komma med ett förslag!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Nej tack" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "USCH!!" QUICKTEXT_DISABLE "\n"
"Då går jag väl hem då!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Inte tillräckligt med Rupees! \n"
"Kom tillbaka senare!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Du kan inte få den nu!\n"
"Kom tillbaka senare!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x2D") "Tack så väldigt mycket!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag har väntat på dig,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Detta är den " COLOR(RED) "Heliga Skogsgläntan" COLOR(DEFAULT) ".\n"
"Det är" COLOR(RED) " " COLOR(DEFAULT) "min hemliga plats!\n"
"Jag känner som..." BOX_BREAK UNSKIPPABLE "Den här platsen kommer att \n"
"betyda väldigt mycket för oss båda en dag.\n"
"Det är så jag känner." BOX_BREAK UNSKIPPABLE "Om du spelar din Okarina här, så \n"
"kan du tala med andarna som bor här \n"
"i skogen." TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kan du tänka dig att spela \n"
"på din Okarina med mig?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Gör det inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Okej, försök att hänga med i\n"
"melodin jag spelar.\n"
"Är du redo?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Va?!\n"
"Så tråkigt!\n"
"Kom igen! Spela med!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x36") "Bra! Bra!" BOX_BREAK UNSKIPPABLE "Glöm inte denna visan är du snäll!\n"
"Lovar du?" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Då du vill höra min röst,\n"
"spela " COLOR(ADJUSTABLE) "Sarias Visa" COLOR(DEFAULT) ". Du kan prata \n"
"med mig när du vill..."
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tar du väl hand om \n"
"min Okarina?"
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x38\x80") "Häftigt!\n"
"Du är grym!  Du satte\n"
"tre stycken mitt i prick!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Jag måste ge en riktigt\n"
"fin present till en sådan fantastisk person!\n"
"Ta emot den här, är du snäll!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido borde veta något om\n"
"vart Sarias håller hus." BOX_BREAK "Jag tror att Mido sitter och tjurar \n"
"i något utav husen häromkring."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT)  SHIFT("\x15")  COLOR(LIGHTBLUE) "Inget svar. Han sover." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cojiro?  Hur så?\n"
"I vanliga fall så kan bara en trevlig \n"
"grabb som jag tämja dig..." BOX_BREAK UNSKIPPABLE "Vilket betyder att..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x01") "Du... " TEXT_SPEED("\x00") "Du måste vara en trevlig grabb!\n"
QUICKTEXT_ENABLE "Så måste det vara!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Du måste vara det!!" QUICKTEXT_DISABLE "\n"
"Snälla Herr trevliga grabb! Snälla!" BOX_BREAK UNSKIPPABLE "Leverera de här sakerna till den " COLOR(RED) "gamla\n"
"haggan i brygdbutiken " COLOR(DEFAULT) "i Kakariko.\n"
"I byn där!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den kommer att försvinna om du tar\n"
"för lång tid på dig, så se till att skynda!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oej\n"
"Jag kan inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jaha, på så vis. " QUICKTEXT_ENABLE "Så det är så det ligger till!" QUICKTEXT_DISABLE "\n"
"Du är inte en trevlig grabb trots allt!!\n"
QUICKTEXT_ENABLE "Försvinn ur min åsyn!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria ville träffa dig...\n"
"Har hon redan hittat dig?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Skynda dig, trevliga grabb!\n"
"Före den försvinner, leverera den\n"
"till den där gamla ragatan...."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Den killen finns inte kvar här längre." BOX_BREAK UNSKIPPABLE "De som vandrar in i skogen \n"
"kommer att bli förlorade." BOX_BREAK UNSKIPPABLE "Alla blir till en Stalfos.\n"
"Precis alla, Stalfos.\n"
"Så, han är inte längre kvar här.\n"
"Endast hans såg är kvar. Hehehe." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den där medicinen är gjord på \n"
"svampar från skogen. Ge tillbaka den!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh.\n"
"Ska även du bli till... en?\n"
"Heh heh!"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vi säljer sköldar, men inte svärd!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Så du kan " COLOR(ADJUSTABLE) "Saria's Visa" COLOR(DEFAULT) "! Vi borde\n"
"bli vänner! Här, ta den!"
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hej! Tycker du att mitt ansikte\n"
"ser medelmåttigt ut?\n"
"det ser inte tillräckligt ovanligt ut..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vi spelar tillsammans igen någon gång!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Följ efter i vår visa med \n"
"din Okarina. Vi leder dig."
)


DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Det var en riktigt bra session.\n"
"Som ett tecken på vår vänskap, \n"
"så var snäll och ta emot denna."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hej, du där borta!\n"
"Hohoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME "...Trevligt att råkas\n"
"igen! Lyssna på det här!\n"
"Hohooo...." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Efter att du har tagit dig genom den\n"
"Förlorade Skogen, så kommer du till den\n"
COLOR(ADJUSTABLE) "Heliga Skogsgläntan" COLOR(DEFAULT) "." BOX_BREAK "Det är en helig plats där\n"
"få någonsin har satt sin fot." BOX_BREAK "Shhhh...Vad är det?\n"
"Jag kan höra mystiska toner..." BOX_BREAK "Du borde lyssna till de tonerna\n"
"du med...\n"
"Hohoohoooooo!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du lyssna på vad jag hade att säga\n"
"igen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Om du är modig, så kommer\n"
"du att klara dig genom skogen\n"
"utan problem..." BOX_BREAK UNSKIPPABLE "följ bara dina öron och\n"
"lyssna till ljuden som kommer från\n"
"skogen! \n"
"Hoohoo!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Lärde du dig en visa på din Okarina\n"
"från Saria?" BOX_BREAK UNSKIPPABLE "Den visan verkar besitta någon\n"
"mystisk kraft." BOX_BREAK UNSKIPPABLE "Det kan finnas andra \n"
"mystiska visor likt den här\n"
"som du kan lära dig i Hyrule." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du håller upp din Okarina med " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"där en melodi är nödvändig, så kommer ett \n"
COLOR(RED) "musikstycke " COLOR(DEFAULT) "att framträda." BOX_BREAK "Jag föreslår att du spelar en\n"
"visa du kan." BOX_BREAK "Jag föreslår även att du spelar\n"
"ifall där inte visas något stycke. \n"
"Precis såhär:\n"
"Hoo hoo hoo hoo hoo hoo!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du lyssna på vad jag hade att\n"
"säga igen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Melodier som du har lärt dig \n"
"kommer att sparas på " COLOR(LIGHTBLUE) "Uppdrags-skärmen. \n"
COLOR(DEFAULT) "Du borde lägga\n"
"alla melodier på minnet."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Jasså...den tiggaren! Jag förstår inte varför \n"
"han är så elak mot alla!" BOX_BREAK UNSKIPPABLE "Det han sa var ju sant dock." TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Skogen..märkliga saker har\n"
"hänt här den senaste tiden..." BOX_BREAK UNSKIPPABLE "Du måste vara redo för vad som helst.\n"
"Du bör hitta ett vapen!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Okej! Du vinner! I gengäld,\n"
"så kan du få köpa " COLOR(RED) "Dekufrön" COLOR(DEFAULT) " utav mig!\n"
COLOR(RED) "30 stycken   40 Rupees" COLOR(DEFAULT) " kostar de!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ger upp! Om du låter mig gå,\n"
"Så kan jag sälja dig en " COLOR(RED) "Dekusköld" COLOR(DEFAULT) "! Den kostar\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ger mig! Om du låter mig gå, så säljer jag \n"
"några " COLOR(RED) "Bomber" COLOR(DEFAULT) " till dig!\n"
COLOR(RED) "5 stycken   40 Rupees" COLOR(DEFAULT) " kostar de!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Sluta! Om du lämnar mig ifred, så \n"
"kan jag sälja " COLOR(RED) "Pilar" COLOR(DEFAULT) " till dig!\n"
COLOR(RED) "30 stycken   70 Rupees" COLOR(DEFAULT) " kostar de!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! If you spare \n"
"me, I will sell you a " COLOR(RED) "Red Potion" COLOR(DEFAULT) " \n"
"for " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Okej! Du vinner! Låt mig leva, så\n"
"kan du få köpa en " COLOR(ADJUSTABLE) "Grön Brygd" COLOR(DEFAULT) " utav mig för \n"
COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Va?! Du har fått en älva?!\n"
"Vad säger du? Det Stora Dekuträdet\n"
"har på riktigt kallat på dig?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vaaaaaaa?!" BOX_BREAK UNSKIPPABLE "Varför har han kallat på dig och inte \n"
"den store " COLOR(RED) "Mido" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Det här var inte alls kul..." BOX_BREAK UNSKIPPABLE "Jag kan inte tro det!\n"
"Du är ju inte ens fullt utrustad\n"
"ännu!" BOX_BREAK UNSKIPPABLE "Hur tror du att du kan \n"
"hjälpa det Stora Dekuträdet utan\n"
"varken ett " COLOR(ADJUSTABLE) "svärd" COLOR(RED) " " COLOR(DEFAULT) "eller en " COLOR(LIGHTBLUE) "sköld" COLOR(RED) " " COLOR(DEFAULT) "redo?" BOX_BREAK "Vad? Du har rätt, jag har inte\n"
"min egen utrsustning redo, men..." TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x2D") "Eh, vad är det?!" BOX_BREAK UNSKIPPABLE "Åh, du har en " COLOR(LIGHTBLUE) "Deksköld" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Och vad är DET?!" BOX_BREAK UNSKIPPABLE "Är det där " COLOR(ADJUSTABLE) "Kokirisvärdet" COLOR(DEFAULT) "?!" BOX_BREAK UNSKIPPABLE "VAD SJUTTON!!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ptja, även om du har allt det där \n"
"så är en mes en mes, eller hur?" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag förlorade! Du kan nu få köpa en\n" COLOR(RED)
"Dekukäpp " COLOR(DEFAULT) "för " COLOR(RED) "15 Rupees" COLOR(DEFAULT) " utav mig." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag förlorade! Du kan få köpa\n" COLOR(RED)
"Dekunötter " COLOR(DEFAULT) "om du lämnar mig ifred.\n"
COLOR(RED) "5 stycken   20 Rupees " COLOR(DEFAULT) "kostar de." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Och dessutom..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0D") "Jag ber om ursäkt att jag var elak emot honom." QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x45") "Berätta det för honom."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee!\n"
"Du tog dig hela vägen upp hit?\n"
"Du är en riktig man!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Titta! Är inte den här utsikten vacker?\n"
"Ändra din vy med hjälp utav " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ",\n"
"så kan du se dig omkring i skogen\n"
"med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vad har du gjort med det Stora\n"
"Dekuträdet?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du vill ta dig till den Förlorade \n"
"Skogen, så bör du utrusta\n"
"dig ordentligt!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x82") "Alla mina Dekubuskbröder säger\n"
"att...\n"
"Du har ett fasansfullt ansikte!" BOX_BREAK SFX("\x38\x82") "Men var inte orolig! Vi kommer att belöna\n"
"dig med många " COLOR(RED) "Dekunötter" COLOR(DEFAULT) "." BOX_BREAK SFX("\x38\x82") "Vi ska även göra det möjligt\n"
"för dig att bära fler utav dem!" BOX_BREAK "Abrahadabra..." BOX_BREAK SFX("\x38\x80") "Simsalabim!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ger upp!" BOX_BREAK SFX("\x38\x80") "För att göra ditt äventyr lite lättare,\n"
"så kan jag göra det möjligt för dig att\n"
"bära fler " COLOR(RED) "Dekukäppar" COLOR(DEFAULT) "!\n"
"Men, det kommer att kosta dig " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ger upp!" BOX_BREAK SFX("\x38\x80") "För att göra ditt äventyr lite lättare,\n"
"så kan jag göra det möjligt för dig att\n"
"plocka upp fler " COLOR(RED) "Dekunötter" COLOR(DEFAULT) "!\n"
"Men, det kommer att kosta dig " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Jag ber om ursäkt!\n"
"Du kan inte köpa det just nu!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den killen är inte här längre." BOX_BREAK "De som vandrar in i skogen \n"
"kommer att bli förlorade." BOX_BREAK "Alla blir till en Stalfos.\n"
"Precis alla, Stalfos.\n"
"Så, han är inte här längre."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tack så mycket för \n"
"häromdan... Jag har inte ens bett\n"
"om ditt namn än..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Jasså?\n"
NAME "!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Då var det som jag trodde!" QUICKTEXT_DISABLE "\n"
"Du är den där älvpojken från\n"
"skogen! Det var ju många år sedan sist!\n"
"Kommer du ihåg mig?" BOX_BREAK UNSKIPPABLE "Gör du? Jag visste att det var du\n"
"därför att Epona kände igen dig!" BOX_BREAK UNSKIPPABLE "Åh, jag måste berätta för dig om\n"
COLOR(RED) "Herr. Ingo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Han var orolig för att den Onda Kungen\n"
"skulle få reda på att Epona\n"
"hade blivit förflyttad...Det gjorde honom verkligen\n"
"upprörd!" BOX_BREAK UNSKIPPABLE "Men rätt som det var en dag, så\n"
"blev han sitt vanliga " COLOR(RED) "snälla\n"
"jag igen" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Nu kommer min pappa tillbaka...Jag\n"
"kan knappt tro det, med frid är\n"
"på väg tillbaka till ranchen!" BOX_BREAK UNSKIPPABLE "Allt är tack vare dig! Jag\n"
"är skyldig dig så mycket!" BOX_BREAK UNSKIPPABLE "Tack! Tack,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hur är det med " COLOR(RED) "Epona " COLOR(DEFAULT) "?" BOX_BREAK "Om du spelar " COLOR(RED) "Eponas Visa " COLOR(DEFAULT) "med\n"
"din Okarina, kommer hon säkerligen\n"
"att komma till dig." BOX_BREAK "Var snäll och besök ranchen\n"
"närhelst du så än önskar " COLOR(RED) "träna med \n"
COLOR(DEFAULT) "Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "ser glad ut!\n"
"Det verkar som att du klarade av\n"
"att tämja henne du med!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vad sägs om att testa dina färdigheter med\n"
"Epona på en " COLOR(RED) "hinderbana" COLOR(DEFAULT) "?" BOX_BREAK "Jag tar tiden åt dig för " COLOR(RED) "två varv" COLOR(DEFAULT) ".\n"
"Det är en utmaning. Om du missar\n"
"att hoppa över ett staket i rätt \n"
"ordning, så misslyckas du." BOX_BREAK "Vad säger du?\n"
"Vill du göra ett försök? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Gör ett försök\n"
"Undviker det" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ptja, din tid blev " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ".\n"
"Du måste träna hårdare!" BOX_BREAK "Kom ihåg, du behöver inte \n"
"accelerera för att hoppa över \n"
"små staket, men du måste springa\n"
"fort för att hoppa över höga staket!"
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME "...kan du höra mig?\n"
"Det är jag, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Muuuuuuuu!" BOX_BREAK "Vilken vacker visa...\n"
"den påminner mig om betesmarker..." BOX_BREAK "Den visan får mig att må så bra,\n"
"så att jag kan producera mycket mjölk!" EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ta lite utav min uppfriskande \n"
"näringsfyllda mjölk!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME ", då du håller\n"
"denna Okarina i din hand..." BOX_BREAK_DELAYED("\x3C") "Så kommer jag inte att finnas här mer..." BOX_BREAK_DELAYED("\x3C") "Jag ville vänta på dig, men jag\n"
"kunde inte ödsla mer tid..." BOX_BREAK_DELAYED("\x3C") "Jag kunde i alla fall lämna dig \n"
"Okarinan och " COLOR(LIGHTBLUE) "denna melodi" COLOR(DEFAULT) "..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Så, " NAME ".\n"
"Spela denna melodi framför\n"
"altaret i Tidens Tempel.\n"
"Du måste beskydda Trekraften!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bah-ha-ha-hah! Tror du att \n"
"du är förklädd, Herr Hjälte?" BOX_BREAK UNSKIPPABLE  SHIFT("\x57") "Åhå?" BOX_BREAK UNSKIPPABLE "Är det en \"Kee...något...\"\n"
"figurmask? Jag har hört att han\n"
"är populär nu för tiden?" BOX_BREAK UNSKIPPABLE "Han är min pojks favorit. Den där\n"
"\"Kee...något...\" masken...\n"
"Om du inte har något emot det..." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Skulle du möjligtvis kunna sälja den?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Absolut inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag ger inte upp! Jag har massvis med\n"
"tålamod. Det måste man ha i detta \n"
"yrket!  Hah hah hah!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mmmm...mummel...mummel...\n"
"Va? Ja, Jag är vaken!" BOX_BREAK UNSKIPPABLE "Va?" BOX_BREAK UNSKIPPABLE "Hej, det är ju du! Välkommen!" BOX_BREAK UNSKIPPABLE "Awww... Det var lite väl hårt!\n"
"Malon gapade på mig väldigt\n"
"länge!" BOX_BREAK UNSKIPPABLE "Du tog hand om oss, så jag kan med \n"
"stolthet ge dig denna " COLOR(RED) "mjölk" COLOR(DEFAULT) "! Du kan \n"
"behålla flaskan för dig själv."
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Vägen är stängd " COLOR(DEFAULT) "bortom denna\n"
"punkt!\n"
"Kan du inte läsa skylten där \n"
"borta?" BOX_BREAK "Eh? Åh, jag förstår. du är bara ett barn\n"
"och kan inte läsa än. \n"
"Ha ha ha!"
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I don't want that!"
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, this is...\n"
"This is surely Princess Zelda's \n"
"handwriting! Well, let's see...\n"
"Hmmm... OK..." BOX_BREAK UNSKIPPABLE  SHIFT("\x06") "\"" COLOR(PURPLE) "This is " NAME "...\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "He is under my orders to save\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "Hyrule." COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "Wah ha ha ha hah!\n"
"What kind of funny game has our\n"
"Princess come up with now?!" BOX_BREAK UNSKIPPABLE "OK, OK, all right.  You can go \n"
"now... Just be careful, Mr. Hero!\n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Mr. Hero!\n"
"Thanks for all your hard work!\n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "!!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Great!\n"
"Your time was " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) "!\n"
"You and Epona are a great\n"
"team!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, that's too bad.\n"
"If you had something to put it in,\n"
"I could give some to you..." EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I am " COLOR(RED) "Ingo" COLOR(DEFAULT) "--Mr. Ingo to you.\n"
"I take care of these horses.\n"
"You're in my way, so scram,\n"
"kid!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "By the way, Mr. Hero..." BOX_BREAK UNSKIPPABLE "If you're going to climb \n"
"Death Mountain, you should equip\n"
"a " COLOR(LIGHTBLUE) "proper shield" COLOR(DEFAULT) "! It is an active\n"
"volcano, after all!" BOX_BREAK UNSKIPPABLE "If you go back to Hyrule Castle\n"
"Town Market, you should check\n"
"out the Bazaar. They sell the\n"
"shield you need there." BOX_BREAK UNSKIPPABLE "Tell 'em I sent you and they\n"
"should give you a special \n"
"discount!" BOX_BREAK UNSKIPPABLE "If you think you're good to go\n"
"already, don't worry about it." BOX_BREAK UNSKIPPABLE "Now, I'd like to ask a favor of \n"
"you. No, I don't expect you to do\n"
"it just because of the great tip I\n"
"just gave you! I'm just asking!" BOX_BREAK UNSKIPPABLE "Have you been to the " COLOR(RED) "Happy\n"
"Mask Shop" COLOR(DEFAULT) " that just opened in\n"
"the Hyrule Castle Town Market?\n"
"Everyone is talking about it!" BOX_BREAK UNSKIPPABLE "My little boy pesters me for a \n"
"popular mask, but I don't have\n"
"time to go there..." BOX_BREAK UNSKIPPABLE "So, could you go and get the\n"
"mask for me next time you are in\n"
"the Market? If you don't feel like\n"
"it, that's OK, but..." BOX_BREAK UNSKIPPABLE "Well, I have no choice, this is my \n"
"job..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4B") "...sigh..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I wish I could go to the " COLOR(RED) "mask\n"
"shop " COLOR(DEFAULT) "in town to buy a present for\n"
"my kid..." BOX_BREAK SHIFT("\x4B") "...sigh..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Oh no... He's not breathing..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x29") "Arrrrgh!" QUICKTEXT_DISABLE " I lost her!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x32") "You, over there! \n"
SHIFT("\x3C")  QUICKTEXT_ENABLE "Little kid!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1C") "You want a piece of me?!\n"
SHIFT("\x3E") "Very funny!\n"
SHIFT("\x2A") "I like your attitude!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2B") "Pathetic little fool!" QUICKTEXT_DISABLE "\n"
SHIFT("\x14") "Do you realize who you are\n"
SHIFT("\x39") "dealing with?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x34") "I am " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x0A") "And soon, I will rule the world!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0D") "You must have seen the white\n"
SHIFT("\x12") "horse gallop past just now...\n"
SHIFT("\x23") "Which way did it go?!\n"
SHIFT("\x3D")  QUICKTEXT_ENABLE "Answer me!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tsk tsk...When your time is\n"
"up, I'll kick you out of here."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My boy will be very happy with \n"
"this! You really are Mr. Hero!\n"
"Wha ha ha hah!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "You sold the 10-Rupee mask for \n"
COLOR(RED) "15 Rupees" COLOR(DEFAULT) ". You earned a little\n"
"profit." BOX_BREAK UNSKIPPABLE "Let's go to the Mask Shop and\n"
"pay back the mask price of \n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Little kids can't go on the \n"
"\"" COLOR(RED) "Heart-Pounding Gravedigging\n"
"Tour" COLOR(DEFAULT) "\" described on the sign." BOX_BREAK "Since I can't do that, I'm just \n"
"imitating Dampé the gravekeeper \n"
"all day." BOX_BREAK "But with my cute face, I'm not\n"
"heart-pounding at all, am I?"
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gyaah!" QUICKTEXT_DISABLE " It's Dampé the \n"
"gravekeeper!" BOX_BREAK SHIFT("\x57") "???" BOX_BREAK "Oh, it's just a mask. I get a \n"
"different kind of fright from that\n"
"mask than I get from Dampé..." BOX_BREAK "Will you give that mask to me?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No way" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I really do have some money, you\n"
"know."
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey! Time's up, young man!\n"
"You only paid 10 Rupees!\n"
"You've played around long enough!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"With this mask, I'll be just like \n"
"Dampé! \n"
"Here's my money!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "You sold the 30-Rupee mask to a\n"
"kid for full price?! \n"
"And he didn't mind paying at all!" BOX_BREAK UNSKIPPABLE "Let's go back to the mask shop to\n"
"pay " COLOR(RED) "30 Rupees " COLOR(DEFAULT) "for the mask. \n"
"You can get the new mask \n"
"model, too."
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm gonna dig and dig! \n"
"Just like Dampé!!"
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"In old times, I heard there were \n"
"many wild rabbits in the land \n"
"of Hyrule. Not anymore, though, \n"
"because of excessive hunting." BOX_BREAK "I want to become a rabbit...\n"
"Listen to the wind with \n"
"those ears, hop across the ground\n"
"with those legs..." BOX_BREAK "Even if I can only pretend."
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I bet with those long ears you \n"
"can hear the voices... \n"
"Oh, these are genuine rabbit\n"
"ears from the animal of legend!" TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I don't care how expensive it is!\n"
"Please sell it to me!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No way" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's not the answer I wanted to \n"
"hear!"
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My long time dream! Returning to\n"
"the wild life! Finally, the actor, \n"
"stage and prop have been united!" EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "It's a 50-Rupee mask, but he paid\n"
"you a crazy amount of money for\n"
"it--more money than you can \n"
"count!" BOX_BREAK UNSKIPPABLE "Go back to the Mask Shop and \n"
"pay back just " COLOR(RED) "50 Rupees " COLOR(DEFAULT) "of this\n"
"money."
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0E") "So, you think you can protect\n"
SHIFT("\x36") "them from me...\n"
SHIFT("\x28") "You've got guts, kid."
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "There are some people in Kakariko\n"
"spreading rumors that I cheated\n"
"Talon out of the ranch, but..." BOX_BREAK UNSKIPPABLE  SHIFT("\x2D") "Don't be " QUICKTEXT_ENABLE "ridiculous!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "That guy Talon was weak!\n"
"I, the hard-working " COLOR(RED) "Ingo" COLOR(DEFAULT) ", poured \n"
"so much energy into this place!" BOX_BREAK UNSKIPPABLE "I don't want any strangers like\n"
"you saying anything bad about me!" BOX_BREAK UNSKIPPABLE "Listen. The " COLOR(RED) "great Ganondorf\n"
COLOR(DEFAULT) "recognized my obvious talents and\n"
"gave the ranch to me!" BOX_BREAK UNSKIPPABLE "I will raise a fine horse and\n"
"win recognition from the great \n"
"Ganondorf!" BOX_BREAK UNSKIPPABLE "Say, young man, do you want\n"
"to ride one of my fine horses?" TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pay me " COLOR(RED) "10 Rupees " COLOR(DEFAULT) "and you can \n"
"ride.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ride\n"
"Don't ride" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All right then, scram \n"
"ya little punk!"
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You don't have enough!\n"
"Save your change and \n"
"come back again!"
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you want to hear how to ride?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Listen\n"
"Don't listen" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Approach the horse quietly and \n"
"stand by its side. Press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to \n"
"mount up." BOX_BREAK "Use the " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "to make it run. \n"
"Once it starts running, press\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " to tap it with the whip. \n"
"It will speed up!" BOX_BREAK "When you want to jump over a\n"
"fence, accelerate and hit it\n"
"head on!" BOX_BREAK "If you try to jump over a fence \n"
"at an angle, the horse won't like\n"
"it, and it won't jump." BOX_BREAK "After the horse comes to a \n"
"complete stop, press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to \n"
"dismount. Now, have fun!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you use " COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", you can \n"
"talk to me from horseback." BOX_BREAK "Are you ready to go home so \n"
"soon?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No, I want to ride.\n"
"Yes, I'm done." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When you want to dismount, stop \n"
"and press " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Hey young man!\n"
"Do I know you? I just felt as \n"
"though I've seen you\n"
"somewhere before..." TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're getting better!\n"
"How about a little race with me?\n"
"One lap around the corral with\n"
"that horse." BOX_BREAK "Let's make a little wager, say\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Do it\n"
"Don't do it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey hey... What's the matter?\n"
"Don't you have even 50 Rupees?!\n"
"I don't want to race with someone\n"
"so poor!"
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x39") "Sh-" QUICKTEXT_ENABLE "shoooot!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "If the great Ganondorf found out\n"
"about this humiliation...\n"
"Hey, you!!  How about another\n"
"race!  If you win..." BOX_BREAK UNSKIPPABLE "You can keep...the horse!!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What's up with that horse?!\n"
"Is that " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "How did you tame that wild horse\n"
"right under my nose?!" BOX_BREAK UNSKIPPABLE "I was going to present that horse\n"
"to the great Ganondorf... But I bet\n"
"it on the race and lost! Shooot!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x36") "Hah ha hah!" BOX_BREAK UNSKIPPABLE "As I promised, I'll give the \n"
"horse to you..." BOX_BREAK UNSKIPPABLE  SHIFT("\x0A") "However..." BOX_BREAK UNSKIPPABLE "I'll never let you leave this ranch!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee... Too bad for you!\n"
"I get your 50 Rupees." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah ha hah!\n"
"You're just a kid, after all!\n"
"Well, come back any time and we'll\n"
"have some more fun..."
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What?  What are you doing \n"
"hanging around here?\n"
"You little weirdo!" BOX_BREAK UNSKIPPABLE "I am " COLOR(RED) "Ingo " COLOR(DEFAULT) "and I mind the ranch." BOX_BREAK UNSKIPPABLE "I've been working at this ranch \n"
"for a long time for that lazy\n"
"bum, Talon." BOX_BREAK UNSKIPPABLE "Today, for example, he's gone\n"
"somewhere for a delivery and he \n"
"hasn't come back yet!" BOX_BREAK UNSKIPPABLE "So, I'm doing all the work around\n"
"here." TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh well...It's tough to be a\n"
"working man."
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, your clothes! They're...\n"
"different...\n"
"You're not from around here, \n"
"are you?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........." TEXT_SPEED("\x00") "........" BOX_BREAK UNSKIPPABLE "Ohh... You're a fairy boy from \n"
"the forest! My name is " COLOR(RED) "Malon" COLOR(DEFAULT) "!\n"
"My dad owns Lon Lon Ranch!" TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dad went to the castle to deliver\n"
"some milk, and he hasn't come\n"
"back yet..."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Are you going to the castle,\n"
"fairy boy?\n"
"Would you mind finding my " COLOR(RED) "dad" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "He must have fallen asleep \n"
"somewhere around the castle. \n"
"What a thing for an adult to do!\n"
"Tee hee!" BOX_BREAK UNSKIPPABLE "Oh yeah, if you'll look for him, I'll \n"
"give this to you." BOX_BREAK UNSKIPPABLE "I've been incubating this\n"
"egg very carefully...\n"
"Tee hee!" EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Set the egg to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to incubate it.\n"
"Hee hee!" BOX_BREAK "My dad is really troublesome,\n"
"for an adult, isn't he?!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I can't believe that I, the great\n"
COLOR(RED) "Ingo" COLOR(DEFAULT) ", am working on this dump of\n"
"a ranch!" BOX_BREAK UNSKIPPABLE "Because the owner is so lazy, I\n"
"always have to do all the work \n"
"around here!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I, the hard-working " COLOR(RED) "Ingo" COLOR(DEFAULT) ", should be \n"
"in charge, not that lazy bum, \n"
"Talon!"
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, it's the fairy boy again!" BOX_BREAK UNSKIPPABLE "I heard that you found my dad!\n"
"How did you like the castle? Did\n"
"you see the Princess? Hee hee!" BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "Dad came home in a hurry after\n"
"you found him. Hee hee!" BOX_BREAK UNSKIPPABLE "Oh yeah, I have to introduce you\n"
"to my friend, fairy boy!" BOX_BREAK UNSKIPPABLE "She's this horse. Her name is\n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". Isn't she cute?"
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It seems like Epona is afraid of \n"
"you, fairy boy..."
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My mother composed this song.  \n"
"Isn't it nice?  Let's sing together."
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Epona!  She's grown fond of\n"
"you, fairy boy."
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "..."
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...a visitor!\n"
"It's been a long time since we've\n"
"had a visitor here...\n"
"Where did you come from?" BOX_BREAK "Since Ganondorf came, people in\n"
"the Castle Town have gone, places\n"
"have been ruined, and monsters\n"
"are wandering everywhere." BOX_BREAK "Mr. Ingo is just using the ranch\n"
"to gain Ganondorf's favor..." BOX_BREAK "Everyone seems to be turning evil..." BOX_BREAK "But Dad...\n"
"He was kicked out of the ranch\n"
"by Mr. Ingo..." BOX_BREAK "If I disobey Mr. Ingo, he will treat\n"
"the horses so badly..." BOX_BREAK "So...\n"
"There's nothing I can do..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I bet nobody is faster than I am \n"
"now! But, I don't know if I \n"
"should be happy or sad...."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "...\n"
"S-stop that song...I...I...\n"
"Mumble... mumble..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Take a good look at that \n"
"mountain. That is " COLOR(RED) "Death Mountain" COLOR(DEFAULT) ",\n"
"home of the Gorons. They hold\n"
"the Spiritual Stone of Fire."
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please keep it secret from \n"
"Mr. Ingo that I sing this song..."
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You...\n"
"Do you know my " COLOR(RED) "mother's song" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Everyone really liked that song...\n"
"My dad... Even Mr. Ingo..." BOX_BREAK UNSKIPPABLE "But...since Ganondorf appeared,\n"
"Mr. Ingo has changed completely." BOX_BREAK UNSKIPPABLE "I can remember the good old days\n"
"only while I sing the song. Also..." TEXTID("\x20\x52")
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Epona" COLOR(DEFAULT) " really liked that song...\n"
"Only I could tame that horse...\n"
"Even Mr. Ingo had a hard time..." BOX_BREAK "Hee hee hee!"
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"This statue's one-eyed gaze \n"
"pierces into your mind..."
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Responding to your mask, this \n"
"strange stone statue talks to \n"
"you..." BOX_BREAK "I overheard this..."
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm gonna turn over a new leaf \n"
"and work real hard from now on."
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mr. Ingo... He must have been \n"
"tempted by evil powers.\n"
"He's not really a bad person \n"
"at all..."
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z Z Z Z...\n"
"Mumble... It's not easy to\n"
"be a working man..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It's been a while...\n"
"Do you want to race?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you change your mind,\n"
"come back anytime!"
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All right then! Scram,\n"
"ya little punk!" EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh... Are you mad because \n"
"you lost? If you're that upset,\n"
"how about another race?" BOX_BREAK "Bet " COLOR(RED) "50 Rupees " COLOR(DEFAULT) "and race again?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Race\n"
"Don't race" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Thank you so much. Heh heh!" EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If I give ya more free of charge,\n"
"Ingo will get mad at me. So I'd\n"
"better sell it to you for the\n"
"normal price."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wanna buy milk for " COLOR(RED) "30 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi there, how are you?\n"
"I am Ingo. I feel so honored\n"
"to be allowed to work here."
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "You brave lad...\n"
"We must protect this beautiful\n"
"land of Hyrule!"
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, cute ocarina!\n"
"Are you going to play this song\n"
"with that ocarina?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "At the foot of Death Mountain\n"
"you will find my village, " COLOR(RED) "Kakariko" COLOR(DEFAULT) ".\n"
"That is where I was born and \n"
"raised." BOX_BREAK UNSKIPPABLE "You should talk to some of the\n"
"villagers there before you go up\n"
"Death Mountain."
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The song I just taught you has\n"
"some mysterious power. Only \n"
"Royal Family members are allowed\n"
"to learn this song." BOX_BREAK UNSKIPPABLE "Remember, it will help to prove\n"
"your connection with the Royal \n"
"Family." BOX_BREAK UNSKIPPABLE "The Princess is waiting for you to \n"
"return to the castle with the\n"
"stones. All right. We're counting\n"
"on you!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hoo hoot!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Look up here!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "It appears that the time has \n"
"finally come for you to start your \n"
"adventure!" BOX_BREAK UNSKIPPABLE "You will encounter many hardships\n"
"ahead... That is your fate. Don't \n"
"feel discouraged, even during the\n"
"toughest times!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Go straight this way and you will\n"
"see " COLOR(RED) "Hyrule Castle" COLOR(DEFAULT) "." BOX_BREAK "You will meet a " COLOR(RED) "princess " COLOR(DEFAULT) "there..." BOX_BREAK "If you are lost and don't know \n"
"which way to go, look at the \n"
COLOR(RED) "Map" COLOR(DEFAULT) "." BOX_BREAK "The areas you have explored will \n"
"be shown on the Map. Press \n"
COLOR(RED) "START " COLOR(DEFAULT) "to enter the Subscreens\n"
"and " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " or " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " to find the Map." BOX_BREAK "On the " COLOR(RED) "Map Subscreen" COLOR(DEFAULT) ", you will\n"
"also see a " COLOR(RED) "flashing dot" COLOR(DEFAULT) " showing\n"
"you which way you should go next." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Did you get all that?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No\n"
"Yes" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "All right then, I'll see you around!\n"
"Hoot hoot hoot ho!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, " NAME "! This way!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "The princess is inside the castle \n"
"just ahead. Be careful not to get \n"
"caught by the guards!\n"
"Ho ho ho hoot!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"On this ground, time flows \n"
"normally." BOX_BREAK "But time stands still while you\n"
"are in Lon Lon Ranch or in a town." BOX_BREAK "If you want time to pass normally,\n"
"you'll need to leave town." BOX_BREAK "Well, well, which way are you \n"
"going to go now?\n"
"Hoo hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Do you want to hear what I said \n"
"again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoooo. You're a smart kid.\n"
"Good luck, then. Hoo hoo."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, " NAME "! \n"
"Wait a second, friend!" BOX_BREAK "Beyond this point you'll find \n"
COLOR(RED) "Kakariko Village" COLOR(DEFAULT) ". Have you seen \n"
"the Princess of Hyrule? If not, \n"
"I suggest you go to the castle." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, " NAME "! \n"
"Look over here!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Beyond this point you'll find\n"
COLOR(RED) "Kakariko Village" COLOR(DEFAULT) ". Watch your step!\n"
"Hoot hoo!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", you're the only\n"
"one who can complete the quest\n"
"ahead!\n"
"You must do your best! Hoo!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "! Wait up, buddy!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28") "Head south from here to reach\n"
COLOR(RED) "Lake Hylia's " COLOR(DEFAULT) "full, rich waters." BOX_BREAK "If you go west, you'll find \n"
COLOR(RED) "Gerudo Valley" COLOR(DEFAULT) ". There's a hideout\n"
"of a gang of thieves on the other\n"
"side of the valley." BOX_BREAK "Well, you're free to go anywhere\n"
"you want!\n"
"Ho ho ho...hooo!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No matter how hard it is, just\n"
"don't get discouraged. Ho Ho Hoo!"
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Beyond this point lies Lake Hylia.\n"
"It is full of deep, pure water." BOX_BREAK_DELAYED("\x28") "The " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", who live all the \n"
"way upstream, guard the sunken\n"
"temple at the lake's bottom, as \n"
"well as Zora's Fountain." BOX_BREAK "If you want to confirm its location \n"
"on the map, press " COLOR(RED) "START " COLOR(DEFAULT) "to \n"
"switch to the Subscreens and " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"or " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " to find the Map." BOX_BREAK "All the places you have visited \n"
"will be shown on the map. \n"
"Ho hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, be careful and go!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What is your name?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Strange...it sounds somehow... \n"
"familiar." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK then, " NAME "..." BOX_BREAK UNSKIPPABLE "I'm going to tell you the secret of\n"
"the Sacred Realm that has been\n"
"passed down by the Royal Family\n"
"of Hyrule." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x26") "The Ocarina of Time!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Did you understand well the story\n"
"I just told you?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "I was spying through this window\n"
"just now..." BOX_BREAK UNSKIPPABLE "The other element from my\n"
"dream...the " COLOR(BLUE) "dark clouds" COLOR(DEFAULT) "...\n"
"I believe they symbolize...\n"
"that man in there!" BOX_BREAK "Will you look through the window\n"
"at him?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Yes." BOX_BREAK UNSKIPPABLE "I told my father about my dream..." BOX_BREAK UNSKIPPABLE "However, he didn't believe it was\n"
"a prophecy..." BOX_BREAK UNSKIPPABLE "But...I can sense that man's evil\n"
"intentions!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What Ganondorf is after must be \n"
"nothing less than the " COLOR(RED) "Triforce \n"
COLOR(DEFAULT) "of the Sacred Realm." BOX_BREAK UNSKIPPABLE "He must have come to Hyrule to\n"
"obtain it!" BOX_BREAK UNSKIPPABLE "And, he wants to conquer Hyrule...\n"
"no, the entire world!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...now, we are the \n"
"only ones who can protect Hyrule!" EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "We must not let Ganondorf get\n"
"the Triforce!" BOX_BREAK UNSKIPPABLE "I will protect the " COLOR(LIGHTBLUE) "Ocarina of Time\n"
COLOR(DEFAULT) "with all my power! \n"
"He shall not have it!" BOX_BREAK UNSKIPPABLE "You go find the other " COLOR(RED) "two\n"
"Spiritual Stones" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Let's get the Triforce before\n"
"Ganondorf does, and then defeat \n"
"him!" EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "One more thing...\n"
"Take this " COLOR(RED) "letter" COLOR(DEFAULT) "...\n"
"I'm sure it will be helpful to you." EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mumble...mumble...\n"
"Huh? I'm awake already!" BOX_BREAK UNSKIPPABLE "What?" BOX_BREAK UNSKIPPABLE "Well I'll be! If it ain't the forest\n"
"kid from the other day!\n"
"By the way, thanks a lot for\n"
"waking me up!" BOX_BREAK UNSKIPPABLE "It took some doing, but I finally \n"
"got Malon back in a good mood." BOX_BREAK UNSKIPPABLE "So, what are you up to today?\n"
"Got some free time on your hands\n"
"you say?\n"
"Well how about a little game?" BOX_BREAK UNSKIPPABLE "These three Cuccos I have here\n"
"are special " COLOR(RED) "Super Cuccos" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "I'm going to throw these Cuccos\n"
"into that there gaggle of normal\n"
"Cuccos." BOX_BREAK UNSKIPPABLE "If you can pick out these three \n"
"special birds from among the\n"
"normal Cuccos within the time \n"
"limit, I'll give you " COLOR(RED) "something good" COLOR(DEFAULT) "." BOX_BREAK "If you can't find them, I win.\n"
"It'll be 10 Rupees... Want to play?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mumble...mumble...\n"
"I'm up! I'm up!" BOX_BREAK "What?" BOX_BREAK "Hey, forest kid!\n"
"Got some free time?\n"
"Then c'mon and play!" BOX_BREAK "I'm going to throw these three\n"
COLOR(RED) "Super Cuccos " COLOR(DEFAULT) "into that gaggle of\n"
"normal Cuccos." BOX_BREAK "If you can pick out these three \n"
"special birds from among the\n"
"normal Cuccos within the time \n"
"limit, I'll give you " COLOR(RED) "something good" COLOR(DEFAULT) "." BOX_BREAK "If you can't find them, I win.\n"
"It'll be 10 Rupees... Want to play?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You have 30 seconds!\n"
"All righty then, get ready.\n"
"Here go the Super Cuccos!" BOX_BREAK SHIFT("\x30") "START LOOKIN'!!" EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Time's up!\n"
"Too baaaaad!!" BOX_BREAK "These are some great Cuccos\n"
"aren't they!\n"
"They're raking in money for me!" BOX_BREAK "Come back to me, my babies!" EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's one of 'em!\n"
"Keep it up! Keep it up!\n"
COLOR(RED) "Two more" COLOR(DEFAULT) " to find!" EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"There's another!\n"
"All right, now, the moment of\n"
"truth! " COLOR(RED) "One more" COLOR(DEFAULT) " to find!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Golly! I'll be darned!\n"
"It's plum incredible!" BOX_BREAK "That's the last one!\n"
"You've found them all!\n"
"Come on over here!" EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Want to try again?" BOX_BREAK "A young man like you must have\n"
"a real fire in your belly!\n"
"Find three of them within\n"
"30 seconds." BOX_BREAK "Try again for 5 Rupees?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, you!\n"
"You've got the talent to be one of\n"
"the world's best cowboys!" BOX_BREAK "How'd you like to marry Malon?\n"
"Huh?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Haw haw! I was just kidding! \n"
"Just kidding! I think you're a little\n"
"young for that, aren't you?\n"
"Haw haw haw!" BOX_BREAK UNSKIPPABLE "Oh...! I'm proud to present to\n"
"you a sample of our very own " COLOR(RED) "Lon\n"
"Lon Milk" COLOR(DEFAULT) ". You'll be energized\n"
"the moment you drink it!" BOX_BREAK UNSKIPPABLE "After you drink it, you can \n"
"bring back the " COLOR(RED) "bottle " COLOR(DEFAULT) "and buy a\n"
"refill, anytime you want!" EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey pardner, you have an honest \n"
"face!" BOX_BREAK "When you grow up, why don't you\n"
"come to work here, on this \n"
"ranch? That's a standing offer!\n"
"I'll be waiting for you." EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Here you go! Take this super\n"
"fresh " COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "!" EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Here you are! Take some super\n"
"fresh milk..." BOX_BREAK "Oh? Too baaaaad!!\n"
"You don't have an empty bottle,\n"
"do you?"
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mumble...mumble...\n"
"I'm awake!" BOX_BREAK "What?" BOX_BREAK "Hey, " NAME "!\n"
"If you're lookin' for Malon,\n"
"she's right outside. Did you \n"
"come here to play?" BOX_BREAK "Well then, how about playing the\n"
COLOR(RED) "Super Cucco-findin' game " COLOR(DEFAULT) "with me?\n"
"Or, do you want to buy some\n"
COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "?" BOX_BREAK "What'll it be?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Lon Lon Milk - 30 Rupees\n"
"Cucco-findin' game - 10 Rupees\n"
"Quit" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "You failed!" COLOR(DEFAULT) "\n"
"You have to jump over all the\n"
"fences!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "One more lap!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Are you making sure to approach\n"
"the fences head on? If you \n"
"approach at an angle, the horse\n"
"won't jump!" BOX_BREAK "If you want to try again, mount\n"
"Epona and get ready!"
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You did it!\n"
COLOR(RED)  RACE_TIME  COLOR(DEFAULT) " is the new course record!" BOX_BREAK UNSKIPPABLE "I have to give you a present to\n"
"commemorate your new record!" BOX_BREAK UNSKIPPABLE "The present is a little too heavy\n"
"to give to you here, so I'll have it\n"
"delivered to your house. Bet you\n"
"can't wait to see it! Hee hee!"
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The record so far is " COLOR(RED) "50 seconds" COLOR(DEFAULT) ".\n"
"Your best time is " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "." BOX_BREAK "If you can beat the record, I'll\n"
"give you a present.\n"
"Give it your best shot, OK?" BOX_BREAK "Let's get going!" EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Your best time is " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "!\n"
"How fast can you go?!\n"
"C'mon, let's get started!" EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The current record is " COLOR(RED) "50 seconds" COLOR(DEFAULT) ".\n"
"First, try to beat this record!" BOX_BREAK "If you can beat the record, I'll\n"
"give you a present!\n"
"Give it your best shot, OK?" BOX_BREAK "All right, let's get started!" EVENT
)

DEFINE_MESSAGE(0x2093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2093"
)

DEFINE_MESSAGE(0x2094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2094"
)

DEFINE_MESSAGE(0x2095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2095"
)

DEFINE_MESSAGE(0x2096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2096"
)

DEFINE_MESSAGE(0x2097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2097"
)

DEFINE_MESSAGE(0x2098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2098"
)

DEFINE_MESSAGE(0x2099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"2099"
)

DEFINE_MESSAGE(0x209A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209A"
)

DEFINE_MESSAGE(0x209B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209B"
)

DEFINE_MESSAGE(0x209C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209C"
)

DEFINE_MESSAGE(0x209D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209D"
)

DEFINE_MESSAGE(0x209E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209E"
)

DEFINE_MESSAGE(0x209F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"209F"
)

DEFINE_MESSAGE(0x3000, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "You don't know what he means by\n"
"\"Sworn Brothers,\" but you've \n"
"collected two Spiritual Stones!\n"
"You have one more to find!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "You don't know what he means by\n"
"\"Sworn Brothers,\" but you've \n"
"finally collected all three Stones!\n"
"Go back to see Princess Zelda!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I maaaade thissss...\n"
"Trrrrade for " COLOR(RED) "claimmm checkkk" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I giiiive thissss to yoooou forrr\n"
"a souvenirrrrr."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kid, I like you!" BOX_BREAK UNSKIPPABLE "How's about you and I become\n"
"Sworn Brothers?!" BOX_BREAK UNSKIPPABLE "No, there's no big ceremony\n"
"involved! Just take this as a\n"
"token of our friendship!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x30") "You did great!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"How 'bout a big Goron hug, \n"
"Brother?!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "Oh!" BOX_BREAK_DELAYED("\x1E")  SHIFT("\x4B") "Oh-oh!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x4B")  QUICKTEXT_ENABLE "C'mon!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x14") "Come on! Come on! " QUICKTEXT_ENABLE "Come on!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x50")  QUICKTEXT_ENABLE "HOT!!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x28") "What a hot beat!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x32") "WHOOOOAH!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YEEEEAH!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YAHOOO!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I am one of the " COLOR(RED) "Gorons" COLOR(DEFAULT) ",\n"
"the stone-eating people who live\n"
"on Death Mountain." BOX_BREAK UNSKIPPABLE "Look at that huge boulder over\n"
"there!" BOX_BREAK UNSKIPPABLE "It blocks the entrance to the\n"
COLOR(RED) "Dodongo's Cavern" COLOR(DEFAULT) ", which was once\n"
"a very important place for us\n"
"Gorons..." BOX_BREAK UNSKIPPABLE "But one day, many Dodongos\n"
"suddenly appeared inside the \n"
"cavern. It became a very \n"
"dangerous place!" BOX_BREAK UNSKIPPABLE "On top of that, a " COLOR(RED) "Gerudo in black\n"
"armor " COLOR(DEFAULT) "used his magic to seal the\n"
"entrance with that boulder!" TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I wish I could roll down the \n"
"mountain like a rock, with a\n"
COLOR(RED) "Bomb Flower " COLOR(DEFAULT) "and..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "BOOOOOOM!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK "If I could do that with a Bomb \n"
"Flower, I could become a real man."
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm standing here to shade the\n"
COLOR(RED) "Bomb Flowers " COLOR(DEFAULT) "from the sun." BOX_BREAK "Do you have a question for me?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ask about Bomb Flowers\n"
"Ask about Dodongo's Cavern" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Those plants growing over there \n"
"are " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ". They are\n"
"\"mining plants\" that grow only on\n"
"this mountain." BOX_BREAK "The flower's fruit is the raw \n"
"material for bombs." BOX_BREAK "But a non-Goron amateur should \n"
"never pick the Bomb Flowers' \n"
"fruit!" BOX_BREAK "They usually grow only in dark \n"
"places, so Bomb Flowers that grow\n"
"in a place like this are extremely\n"
"rare."
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Those plants growing over there \n"
"are " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ". They are\n"
"\"mining plants\" that grow only on\n"
"this mountain." BOX_BREAK "They usually grow only in dark \n"
"places, like caves, so Bomb \n"
"Flowers that grow in a place like\n"
"this are extremely rare." BOX_BREAK "If you have the " COLOR(RED) "Goron's Bracelet" COLOR(DEFAULT) ",\n"
"even a little kid like you could\n"
"easily pick it with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did you see the cavern on your \n"
"way here? That is the " COLOR(RED) "Dodongo's \n"
"Cavern" COLOR(DEFAULT) "." BOX_BREAK "Because the light inside is very \n"
"dim, the " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ", a plant \n"
"unique to this mountain, grow like\n"
"crazy in there!"
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh?" BOX_BREAK UNSKIPPABLE "We don't get many visitors way\n"
"up here. Where are you from?" BOX_BREAK UNSKIPPABLE "The forest?" BOX_BREAK UNSKIPPABLE "What's a \"forest\"?" BOX_BREAK UNSKIPPABLE "Eh?" BOX_BREAK UNSKIPPABLE "It's where a lot of \"trees\" and \n"
"\"plants\" grow?" BOX_BREAK UNSKIPPABLE "Now I'm even more confused! \n"
"Nothing grows around here besides\n"
"the " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "We don't have \"seeds\" or \"nuts\"\n"
"around here either." BOX_BREAK UNSKIPPABLE "Even Deku Sticks are very scarce\n"
"around here!" TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I sealed the entrance because I\n"
"don't have much merchandise to\n"
"sell. But you're quite a persistent\n"
"customer, aren't you." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I'm sorry...\n"
"That Bomb is just for display. \n"
"I'm " COLOR(RED) "sold out " COLOR(DEFAULT) "of real ones." EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Why did you stop me?\n"
"Don't stop me here!" BOX_BREAK "You can't stop my wild rolling!" BOX_BREAK "This wild rolling is the only way\n"
"to relieve my stress!" BOX_BREAK "Now stand in awe of my wild, wild\n"
"rolling!!"
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "All right! I'll give you this\n"
"in praise of your courage!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Thank you! Let me express my joy\n"
"with more wild rolling!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x21") "Oh...I'm so hungry..." BOX_BREAK UNSKIPPABLE "Everyone feels faint from hunger\n"
"because of the food shortage in \n"
"this town. We are in danger of \n"
"extinction!" BOX_BREAK UNSKIPPABLE "It's all because we can't enter\n"
"our quarry, the " COLOR(RED) "Dodongo's Cavern" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "We Gorons live on a diet of \n"
"rocks..." BOX_BREAK UNSKIPPABLE "And the most delicious and \n"
"nutritious rocks around are found \n"
"in the Dodongo's Cavern! But that \n"
"seems like ancient history now..." BOX_BREAK UNSKIPPABLE "We've become such gourmets that \n"
"we can't stand to eat rocks from\n"
"anywhere else!" TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sigh... I want to eat the top\n"
"sirloin rocks from the " COLOR(RED) "Dodongo's \n"
"Cavern" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey!" BOX_BREAK UNSKIPPABLE "It's dangerous for a little kid like\n"
"you to come out here. You might \n"
"fall down!" BOX_BREAK UNSKIPPABLE "If I'm not mistaken, you came out\n"
"here to eat the " COLOR(RED) "red stone" COLOR(DEFAULT) "!\n"
"Well, too bad! It's not here!" BOX_BREAK UNSKIPPABLE "What? That's not why you're\n"
"here?" BOX_BREAK UNSKIPPABLE "You're looking for a \"Spiritual\n"
"Stone?\" You must mean that \n"
"delicious-looking red stone\n"
"that was once displayed here!" BOX_BREAK UNSKIPPABLE "I was so hungry that I thought\n"
"it would be OK to just give it one\n"
"tiny little lick...so I snuck out\n"
"here. But, it was already gone!" BOX_BREAK UNSKIPPABLE "I think Big Brother took it away." BOX_BREAK UNSKIPPABLE "He always says that everyone\n"
"is after that red stone!" TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Big Brother has shut himself up in\n"
"his room saying,\n"
"\"" COLOR(RED) "I will wait in here for the \n"
"Royal Family's messenger!" COLOR(DEFAULT) "\""
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'm so hungry that I can't think\n"
"about anything but food!" BOX_BREAK UNSKIPPABLE "Ask Big Brother about complicated\n"
"things." BOX_BREAK UNSKIPPABLE "If he's in a bad mood, he'll \n"
"probably get mad at you...it\n"
"can be pretty scary. But..." BOX_BREAK UNSKIPPABLE "I know his SECRET." BOX_BREAK UNSKIPPABLE "He may not look like the type,\n"
"but Big Brother loves to dance!\n"
"If he gets in a rhythm, he'll surely..." TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I remember Big Brother used to\n"
"always listen to the " COLOR(ADJUSTABLE) "music that\n"
"comes from the forest" COLOR(DEFAULT) "..." BOX_BREAK "Ah yes, the good old days...\n"
"That music makes me feel\n"
"nostalgic, too..." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What the heck! Who are you?!" BOX_BREAK UNSKIPPABLE "When I heard the " COLOR(BLUE) "song of the\n"
"Royal Family" COLOR(DEFAULT) ", I expected their \n"
"messenger had arrived, but...\n"
"you're just a little kid!" BOX_BREAK UNSKIPPABLE "Has " COLOR(RED) "Darunia" COLOR(DEFAULT) ", the big boss of\n"
"the Gorons, really lost so much\n"
"status to be treated like this\n"
"by his Sworn Brother, the King?" BOX_BREAK UNSKIPPABLE "Now, I'm REALLY angry!\n"
"Get out of my face, now!" BOX_BREAK UNSKIPPABLE "Are you asking why I'm in such a\n"
"bad mood right now?" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Ancient creatures have \n"
"infested the Dodongo's Cavern!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "We've had a poor harvest of our\n"
"special crop, Bomb Flowers!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Starvation and hunger because\n"
"of the rock shortage!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x48") "But..." TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "This is a Goron problem!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x11") "We don't need any help from\n"
SHIFT("\x46") "strangers!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x15") "Heeey!! What a nice tune!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Just like that, my depression is\n"
"all gone! Something just came \n"
"over me! I suddenly wanted to\n"
"dance like crazy!" BOX_BREAK UNSKIPPABLE  SHIFT("\x3C") "I am " COLOR(RED) "Darunia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "I'm the big boss of the Gorons!\n"
"Was there something you wanted \n"
"to ask me about?" BOX_BREAK UNSKIPPABLE  SHIFT("\x50") "What?" BOX_BREAK UNSKIPPABLE "You want the " COLOR(RED) "Spiritual Stone of\n"
"Fire" COLOR(DEFAULT) ", too?" BOX_BREAK UNSKIPPABLE "The Spiritual Stone of Fire, also\n"
"known as the Goron's Ruby, is our\n"
"race's hidden treasure...." BOX_BREAK UNSKIPPABLE "But hold on--I'm not going to give\n"
"it to you that easily.\n"
"If you want it so badly..." BOX_BREAK UNSKIPPABLE "Why don't you go destroy the \n"
"monsters inside of the Dodongo's \n"
"Cavern and prove you're a real man?" BOX_BREAK UNSKIPPABLE "That way, everybody will be \n"
"happy again! If you do it, I \n"
"will give you anything you want,\n"
"even the Spiritual Stone!" BOX_BREAK UNSKIPPABLE "I have something for you. I'm not\n"
"really giving you this in\n"
"return for anything, but take it\n"
"anyway." BOX_BREAK UNSKIPPABLE "If you wear this, even a little \n"
"fella like you can pick a " COLOR(RED) "Bomb \n"
"Flower " COLOR(DEFAULT) "using " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Destroy the monsters in the\n"
COLOR(RED) "Dodongo's Cavern " COLOR(DEFAULT) "and become a \n"
"real man! Then, we can talk about\n"
"the Spiritual Stone!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Brother, play that tune\n"
"again sometime soon!"
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"No matter how many times I hear \n"
"that song, it doesn't get old!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Well, that's not quite what I \n"
"was looking for..." BOX_BREAK "I wanted to hear...a tune...\n"
"something...um...from outside \n"
"the mountains...something...\n"
"green...natural..." BOX_BREAK "That's the kind of music I want \n"
"to hear..."
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, now we can enter the cavern.\n"
"You're so smart!"
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I know a trick to conserve sticks!\n"
"If you light a stick on fire, it will \n"
"burn to ashes. Press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to put it\n"
"away before it completely burns!" BOX_BREAK "By the way, I hid a stick\n"
"somewhere...\n"
"Hehehee..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "It's me, " COLOR(RED) "Darunia" COLOR(DEFAULT) "!\n"
"Well done!" BOX_BREAK UNSKIPPABLE "Thanks to you, we can once again\n"
"eat the delicious rocks from the\n"
"Dodongo's Cavern until our \n"
"stomachs burst!"
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'm so hungry that I can't think\n"
"about anything but food!" BOX_BREAK UNSKIPPABLE "\"Spiritual Stone?\"\n"
"That " COLOR(RED) "red stone" COLOR(DEFAULT) " that was lighting\n"
"up our city?" BOX_BREAK UNSKIPPABLE "Big Brother " COLOR(RED) "Darunia" COLOR(DEFAULT) " took it\n"
"away. Then, he shut himself up in\n"
"his room and won't come out." BOX_BREAK UNSKIPPABLE "Since then, it feels like all\n"
"the lights in the city have gone \n"
"out... Everyone seems so...\n"
"depressed..." TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I want you to bring " COLOR(RED) "fire" COLOR(DEFAULT) " from Big\n"
"Brother's room back here."
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, I see...\n"
"We should have thrown the \n"
"Bomb from the cliff..."
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You are incredible, destroying \n"
"the Dodongos! Do you mind if I \n"
"call you Big Brother?"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Thanks to you, we're all OK!\n"
"Why don't you buy some Bombs \n"
"now?" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You know, I'm so grateful to you.\n"
"When I have a kid, I will name it\n"
"after you!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you want to hear more Goron\n"
"gossip, head up to our city!" BOX_BREAK COLOR(RED) "Goron City" COLOR(DEFAULT) " is just a little\n"
"way up the trail. It won't take\n"
"much longer to get there, even\n"
"on foot."
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You pick the Bomb Flowers with \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Press " COLOR(BLUE) "[A] " COLOR(DEFAULT) "again to set it."
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When all the " COLOR(RED) "torches" COLOR(DEFAULT) " on this floor\n"
"are lit, Goron City is really lively!"
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Are you going to clear out the \n"
"Dodongos? It's a Goron problem,\n"
"though. You're a nosey little kid,\n"
"aren't you?!" BOX_BREAK "Well, of course we'll be happy if \n"
"you fix it so we can get all the\n"
"Bombs we want, like we used to..." BOX_BREAK "Just let me warn you, though...\n"
"Dodongos are scary creatures! \n"
"They'll eat ANYTHING!!" BOX_BREAK "So watch yourself, and don't \n"
"get eaten!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I already told you!\n"
"We're out of Bombs!\n"
"Ohhh... I'm so hungry!" PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How was Big Brother?\n"
"I see..." BOX_BREAK "By the way, do you know the\n"
"music coming from deep inside of\n"
"this tunnel? We all like this music!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I won't let you get me! \n"
"You probably work for Ganondorf!"
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "How could you do this to me?\n"
"You, you're Ganondorf's servant!" BOX_BREAK UNSKIPPABLE "Hear my name and tremble!" BOX_BREAK UNSKIPPABLE "I am " COLOR(RED)  NAME  COLOR(DEFAULT) "! \n"
"Hero of the Gorons!"
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What?" BOX_BREAK UNSKIPPABLE "Your name is also\n"
NAME "?" BOX_BREAK UNSKIPPABLE "Then you must be the legendary\n"
"Dodongo Buster and Hero, \n"
NAME "!" BOX_BREAK UNSKIPPABLE "My dad is " COLOR(RED) "Darunia" COLOR(DEFAULT) "...\n"
"Do you remember him?" BOX_BREAK UNSKIPPABLE "Dad named me " NAME "\n"
"after you, because you're so \n"
"brave!" BOX_BREAK UNSKIPPABLE "It's a cool name!\n"
"I really like it!" BOX_BREAK UNSKIPPABLE  NAME ", you're a hero to \n"
"us Gorons! \n"
"I'm so glad to meet you!" BOX_BREAK UNSKIPPABLE "Please give me your autograph!\n"
"Sign it:\n"
SHIFT("\x05") "\"To my friend, \n"
SHIFT("\x05")  NAME " of the Gorons\"" BOX_BREAK UNSKIPPABLE "Oh..." BOX_BREAK UNSKIPPABLE "I guess it's not a good time\n"
"to ask you for this...\n"
"Please help everyone!" BOX_BREAK UNSKIPPABLE "My dad, Darunia, went to the " COLOR(RED) "Fire\n"
"Temple" COLOR(DEFAULT) ". A dragon is inside!" BOX_BREAK UNSKIPPABLE "If we don't hurry up, even my dad\n"
"will be eaten by the dragon!!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"B-b-b-boooo hooooo!" EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You'd better try to calm him down\n"
"if you can...\n"
"Maybe he will calm down if you \n"
"talk to him?" BOX_BREAK "What do you want to ask him?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "About the dragon\n"
"About the Gorons" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "A long time ago there was an\n"
"evil dragon named " COLOR(RED) "Volvagia " COLOR(DEFAULT) "living \n"
"in this mountain." BOX_BREAK UNSKIPPABLE "That dragon was very scary!\n"
"He ate Gorons!" BOX_BREAK UNSKIPPABLE "Using a huge hammer, the hero of\n"
"the Gorons... BOOOM!" BOX_BREAK UNSKIPPABLE "Destroyed it just like that. This is \n"
"a myth from long ago, but it's \n"
"true!" BOX_BREAK UNSKIPPABLE "I know, because my dad is a\n"
"descendant of the hero!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Everybody was taken to the \n"
COLOR(RED) "Fire Temple" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "While my dad was out...\n"
"Ganondorf's followers" COLOR(RED) " " COLOR(DEFAULT) "came and\n"
"took them all away!" BOX_BREAK UNSKIPPABLE "All of them will be eaten by\n"
COLOR(RED) "Volvagia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Dad said that Ganondorf has\n"
"revived Volvagia..." BOX_BREAK UNSKIPPABLE "As a warning to those who might\n"
"oppose him, Ganondorf is going to\n"
"feed them all to Volvagia!" BOX_BREAK UNSKIPPABLE "Dad went to the Fire Temple all\n"
"by himself to try to save \n"
"everyone..." BOX_BREAK UNSKIPPABLE "Please help, " NAME "!\n"
"I'll give you this " COLOR(RED) "heat-resistant\n"
"tunic" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Dad told me not to let anybody \n"
"follow him to the temple, but..." BOX_BREAK UNSKIPPABLE "Only you, " NAME ", can\n"
"save everyone!" BOX_BREAK UNSKIPPABLE "I'm sure that the shop owner, who\n"
"is hiding somewhere right now, will\n"
"also help you!" BOX_BREAK UNSKIPPABLE "Now, I'll tell you about the secret\n"
"passage to the Fire Temple!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Try to move the " COLOR(RED) "statue " COLOR(DEFAULT) "inside\n"
"Dad's room!"
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Who's there?  Is that you,\n"
NAME "...?" BOX_BREAK UNSKIPPABLE "Oh, it really is " NAME "!" BOX_BREAK UNSKIPPABLE "You've grown so big since I last\n"
"saw you!" BOX_BREAK UNSKIPPABLE "I want to have a man-to-man talk\n"
"with you, but now's not the time." BOX_BREAK UNSKIPPABLE "Ganondorf is causing trouble on\n"
"Death Mountain again!\n"
"He has revived the evil, ancient\n"
"dragon Volvagia!" BOX_BREAK UNSKIPPABLE "On top of that, he is going to\n"
"feed my people to that evil dragon\n"
"as a warning to other races that\n"
"might resist him..." BOX_BREAK UNSKIPPABLE "If that fire-breathing dragon\n"
"escapes from the mountain, all of\n"
"Hyrule will become a burning\n"
"wasteland!" BOX_BREAK UNSKIPPABLE "I will go on ahead to try to seal\n"
"up the evil dragon..." BOX_BREAK UNSKIPPABLE "I'm concerned, though, because I\n"
"don't have the legendary hammer...\n"
"But I have no choice." BOX_BREAK UNSKIPPABLE  NAME "...I'm asking you to\n"
"do this as my Sworn Brother..." BOX_BREAK UNSKIPPABLE "While I'm trying to deal with the\n"
"dragon, please save my people!" BOX_BREAK UNSKIPPABLE "The prisoners' cells are in the\n"
"opposite direction.\n"
"I'm counting on you, \n"
NAME "!"
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm saved!\n"
"Thank you!\n"
"Here, take this!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "...Can't hold... \n"
"anymore...I can't hold\n"
"it any longer..." BOX_BREAK UNSKIPPABLE "Get out of here!!"
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Thank you, Brother!\n"
"I really appreciate what you\n"
"did. I thank you on behalf of\n"
"the entire Goron race!" BOX_BREAK UNSKIPPABLE "You turned out to be a real man,\n"
"just as I thought you would!"
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT("\x36") "Don't forget...\n"
SHIFT("\x03") "Now you and I are true Brothers!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "It is something that grows over\n"
"time... a true friendship.\n"
"A feeling in the heart that \n"
"becomes even stronger over time..." BOX_BREAK UNSKIPPABLE "The passion of friendship will \n"
"soon blossom into a righteous\n"
"power and through it, you will\n"
"know which way to go..." BOX_BREAK UNSKIPPABLE "This song is dedicated to the \n"
"power of the heart...\n"
"Listen to the " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...See you again..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME ", it's so hot in \n"
"here! We can't stay here for\n"
"long!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Brother " NAME "!\n"
"Everybody has come back!" BOX_BREAK UNSKIPPABLE "Dad and you destroyed the dragon\n"
"together, didn't you!" TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When I grow up, I want to be a\n"
"strong man like you, \n"
NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Thank you, " NAME "!!"
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Thank you very much for\n"
"saving us!" PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "By the way, I, the wild Darunia,\n"
"turned out to be the great \n"
COLOR(RED) "Sage of Fire" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Isn't that funny, Brother?\n"
"Well, this must be what they call\n"
"destiny." BOX_BREAK UNSKIPPABLE "Nothing has made me happier\n"
"than helping you seal the evil\n"
"here!"
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, Brother, take this!\n"
"This is a " COLOR(RED) "Medallion " COLOR(DEFAULT) "that contains\n"
"the power of the fire spirits--and\n"
"my friendship."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Big problem!\n"
"Everybody is gone!\n"
"But I'll keep my business open!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What a wild adventure! It will\n"
"make an incredible story..." BOX_BREAK UNSKIPPABLE "I can't believe that the Dodongos\n"
"suddenly appeared in such great \n"
"numbers!" BOX_BREAK UNSKIPPABLE "And that big rock blocking the \n"
"cave..." BOX_BREAK UNSKIPPABLE "All this trouble must have been\n"
"caused by that Gerudo thief, \n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "He said, \n"
"\"" COLOR(LIGHTBLUE) "Give me the Spiritual Stone!\n"
"Only then will I open the cave \n"
"for you!" COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "You, on the other hand, risked \n"
"your life for us..."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Tight fit..."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm working on something really \n"
"cool right now! But I think it's\n"
"going to take a while..." TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you can wait five or six years,\n"
"it should be ready. OK?"
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I just completed a small weapon.\n"
"How about it..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How do you like the feel of it?"
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It looks like there is a problem \n"
"with its durability...\n"
"But still..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How about buying this knife for \n"
"200 Rupees?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All right. Come back again."
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please...Don't...Eat me...\n"
"If you eat something like me,\n"
"you'll get a stomach ache!" BOX_BREAK "You'll be sorry!!"
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, I see. Big Brother Darunia\n"
"asked you to rescue me.\n"
"I owe you big time!" BOX_BREAK "Please help Big Brother!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"My Brotherrrr...\n"
"Opened a new storrrre...\n"
"It's Medigoron's Blade\n"
"Storrrrrrrre..." BOX_BREAK "Howeverrrrr... \n"
"I am betterrrrrr at making\n"
"bladessssss." BOX_BREAK "Hylian carpenterrrrrs praise\n"
"me forrrrrr my skillssssss.\n"
"I'm not lyinnnnng..."
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "That broken knife is surely my \n"
"worrrrrrrrrrk...\n"
"I really want to repairrrrr it, but..." BOX_BREAK UNSKIPPABLE "But because of yesterrrrrday's\n"
"errrrruption, my eyes are \n"
"irrrrrrrritated..." BOX_BREAK UNSKIPPABLE "There are fine eyedrops in Zora's\n"
"Domain... You will find them if you\n"
"go to see " COLOR(RED) "Kinnnnnng Zorrrrrra" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Please go get the eyedrrrrrrops...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Awww nooooo... I'm finished...\n"
"My eyes arrrrrre so itchy...\n"
"Owwwwww..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, no! Everybody's gone!\n"
"Only I was left behind!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I've been waiting forrrrr you,\n"
"with tearrrrrrs in my eyes...\n"
"Please say hello to Kinnng Zorrra!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Rrrrreally? You brrrrought the eye\n"
"drops? I'm so rrrrrelieved!  I'm\n"
"going to use them rrrrrright now!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(RED) "Wowwwwwwwwwwwwww!!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "This is stimulating! It's\n"
"worrrrrking grrrrreat!" BOX_BREAK UNSKIPPABLE "Now I can get back to my blade\n"
"business! My worrrrrk is not \n"
"verrrry consistent, so I'll give this \n"
"to you so you won't forrrrrget." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Everybody has come back!\n"
"It's business as usual!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Afterrrr a few days...\n"
"Please returrrrrrn...\n"
"Wait, just wait patiently..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Not yet...\n"
"Hey you...\n"
"You arrrre impatient..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"That sworrrrd is my finest \n"
"worrrrk!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Your " COLOR(DEFAULT) "shield " COLOR(LIGHTBLUE) "is gone!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "The " COLOR(DEFAULT) "tunic " COLOR(LIGHTBLUE) "you were wearing is \n"
"gone!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Your " COLOR(DEFAULT) "shield " COLOR(LIGHTBLUE) "is gone!\n"
"The " COLOR(DEFAULT) "tunic " COLOR(LIGHTBLUE) "you were wearing has\n"
"also been taken!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You've done well to come all the\n"
"way up here, " NAME ". \n"
"This is the summit of the sacred\n"
"Death Mountain! Hoot!" BOX_BREAK UNSKIPPABLE "It is said that the clouds \n"
"surrounding this peak reflect the\n"
"condition of Death Mountain. When\n"
"they look normal, it is at peace." BOX_BREAK UNSKIPPABLE "Climbing all the way up here\n"
"just proves how smart you are!\n"
"Now I want to see you make\n"
"another smart move..." BOX_BREAK UNSKIPPABLE "The " COLOR(RED) "Great Fairy" COLOR(DEFAULT) " lives on this\n"
"mountaintop, and she will give\n"
"you a new skill! She is the leader\n"
"of the fairies, you know. Hoo!" BOX_BREAK UNSKIPPABLE "I will perch here and wait for you.\n"
"When you're ready to go back\n"
"down, I can help you! \n"
"Now, get going!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hoo hoot!\n"
"Well, it looks like you've grown\n"
"up a little from the Great Fairy's\n"
"power..." BOX_BREAK "But you still don't really look like\n"
"the hero who will save Hyrule. At\n"
"least not yet!" BOX_BREAK "If you are going back " COLOR(RED) "down the\n"
"mountain" COLOR(DEFAULT) ", I can lend you a wing.\n"
"Come here and grab my talons!\n"
"And hold on tight! Hoo hooooooot!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"They say that a " COLOR(RED) "beautiful" COLOR(DEFAULT) " " COLOR(RED) "fairy\n"
COLOR(DEFAULT) "lives on top of Death Mountain!" BOX_BREAK "Don't you want to see her?"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"They say that a " COLOR(RED) "fairy " COLOR(DEFAULT) "lives on top\n"
"of Death Mountain." BOX_BREAK "If you want to make it to the top,\n"
"you'd better take a big " COLOR(LIGHTBLUE) "shield" COLOR(DEFAULT) "\n"
"with you..."
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Look! A " COLOR(DEFAULT) "chicken " COLOR(LIGHTBLUE) "hatched from\n"
"the " COLOR(DEFAULT) "egg " COLOR(LIGHTBLUE) "you were incubating!\n"
"It's the miracle of life!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did you get the red stone?\n"
"Let me get one little lick!" BOX_BREAK "No? Booooo!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Brother! You'll keep brushing up\n"
"on your skills as you travel,\n"
"won't you?" BOX_BREAK UNSKIPPABLE "You should go see the " COLOR(RED) "Great Fairy" COLOR(DEFAULT) "\n"
"on top of Death Mountain! She\n"
"will power you up!" BOX_BREAK UNSKIPPABLE "Hey, everybody! Let's see off our\n"
"Brother!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'll tell you a secret for\n"
"saving me!" BOX_BREAK UNSKIPPABLE "In this temple, there are " COLOR(RED) "doors\n"
"that fall down " COLOR(DEFAULT) "when you try to \n"
"open them. When one of these\n"
"doors starts to fall, move!" BOX_BREAK UNSKIPPABLE "If you use a sample of the\n"
"Goron \"special crop,\" you can\n"
"break it..."
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Let me tell you a secret as\n"
"a reward for releasing me!" BOX_BREAK UNSKIPPABLE "When you are on fire, you can put\n"
"it out by swinging your sword, or\n"
"by rolling forward... Did you know\n"
"that?"
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Here's a tip for rescuing me!" BOX_BREAK UNSKIPPABLE "Somewhere in this temple, you're\n"
"sure to meet up with some \n"
"creatures that dance as they\n"
"attack. Arrows won't hurt them!" BOX_BREAK UNSKIPPABLE "Looks like you might need some of\n"
"the Goron \"special crop!\" That's\n"
"all I have to tell you!"
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'll tell you a secret for\n"
"saving me!" BOX_BREAK UNSKIPPABLE "There are switches in this temple\n"
"that you have to cut to activate.\n"
"But, you can also use the Goron\n"
"\"special crop\" to do the job."
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'll tell you a secret for\n"
"saving me!" BOX_BREAK UNSKIPPABLE "If you find a place that you can\n"
"see on the map, but can't reach,\n"
"try playing your Ocarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'll tell you a secret for\n"
"saving me!" BOX_BREAK UNSKIPPABLE "In order to get into the room\n"
"where Darunia went, you have to\n"
"do something about the pillar\n"
"stuck in the ceiling." BOX_BREAK UNSKIPPABLE "Find a path that leads to a room\n"
"above the ceiling right away!"
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I'll tell you a secret for\n"
"saving me!" BOX_BREAK UNSKIPPABLE "A door is hidden inside the statue\n"
"at the entrance to this temple." BOX_BREAK UNSKIPPABLE "But, the Goron \"special crop\" won't\n"
"work on it... Don't you have\n"
"anything stronger?"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Here's a secret for saving me!" BOX_BREAK UNSKIPPABLE "A wall that you can destroy with\n"
"the Goron's \"special crop\" will\n"
"sound different than a regular\n"
"wall if you hit it with your sword."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Are you releasing me?\n"
"Am I free to go?" EVENT
)

DEFINE_MESSAGE(0x3072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3072"
)

DEFINE_MESSAGE(0x3073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3073"
)

DEFINE_MESSAGE(0x4000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "These eyeballs are so delicious!\n"
"Tonight I will cook fried eyeballs \n"
"for the first time in a long time!\n"
"Uhoy hoy hoo houy hoy!" BOX_BREAK UNSKIPPABLE "Such great stuff! Please say \n"
"thank you to King Zora!\n"
"Eh? What?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "These are for making " COLOR(RED) "Biggoron's \n"
"Eye Drops" COLOR(DEFAULT) "? Oh, how disappointing!\n"
"You should have said so in the \n"
"first place!" EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
"This way!  Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "I wonder what " COLOR(RED) "Saria" COLOR(DEFAULT) " is doing now?\n"
"How about going back to the\n"
"forest sometime?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What are you doing? You've come \n"
"a long way to get up here..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "You should look at the " COLOR(RED) "Map \n"
"Subscreen " COLOR(DEFAULT) "sometimes." BOX_BREAK UNSKIPPABLE  NAME ", this is a beautiful\n"
"lake full of pure, clear water." BOX_BREAK UNSKIPPABLE "At the lake bottom there is\n"
"a " COLOR(BLUE) "Water Temple " COLOR(DEFAULT) "used to worship \n"
"the water spirits. The " COLOR(BLUE) "Zoras " COLOR(DEFAULT) "are\n"
"guardians of the temple. Hoo hoo." BOX_BREAK UNSKIPPABLE "The Zoras come from Zora's\n"
"Domain in northeast Hyrule. An\n"
"aquatic race, they are longtime\n"
"allies of Hyrule's Royal Family." BOX_BREAK UNSKIPPABLE "I heard that only the Royal Family\n"
"of Hyrule can enter Zora's Domain...\n"
"Hoo hoo!" BOX_BREAK UNSKIPPABLE "I'm on my way back to the " COLOR(RED) "castle" COLOR(DEFAULT) ".\n"
"If you want to come with me, hold\n"
"on to my talons!"
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm on my way back to the " COLOR(RED) "castle" COLOR(DEFAULT) ".\n"
"If you want to come with me, hold\n"
"on to my talons!"
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "...Huh?" BOX_BREAK UNSKIPPABLE "It looks like there is something\n"
"already inside this bottle.\n"
"It's a " COLOR(RED) "letter" COLOR(DEFAULT) ":" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C") "\"" COLOR(PURPLE) "Help me.\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(PURPLE) "I'm waiting for you inside\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(YELLOW) "Lord Jabu-Jabu's" COLOR(PURPLE) " belly.\n"
COLOR(DEFAULT)  SHIFT("\x18") "--" COLOR(YELLOW) "Ruto" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C")  COLOR(PURPLE) "PS: Don't tell my father!" COLOR(DEFAULT) "\"" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Who are you?" BOX_BREAK UNSKIPPABLE "We are the " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", the proud\n"
"aquatic people!" BOX_BREAK UNSKIPPABLE "So...you say you have some \n"
"connection with Hyrule's Royal\n"
"Family... \n"
"Well, what do you want from us?"
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We are good at diving!\n"
"How about you?" BOX_BREAK "If you want to be a master diver,\n"
"try the " COLOR(RED) "diving game" COLOR(DEFAULT) " at the top \n"
"of the waterfall!\n"
"Have you tried it already?"
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Zoras fontän är \n"
"älvens källa.\n"
COLOR(RED) "Vår Herre Jabu-Jabu " COLOR(DEFAULT) "bor i den \n"
"fontänen." TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vår Herre Jabu-Jabu är Zoras\n"
"Gud. " COLOR(RED) "Prinsessan Ruto" COLOR(DEFAULT) " ser till \n"
"att förbereda hans måltider \n"
"både morgon och kväll."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vi Zora tjänar alla den store \n"
COLOR(RED) "Kung Zora" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Den store Kung Zora borde hålla\n"
"till i den " COLOR(RED) "Kungliga Kammaren" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Har du mött vår Herre Jabu-Jabu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Enligt \"Legenden om Zora,\"\n"
"så blir du glad utav att skänka " COLOR(RED) "fisk" COLOR(DEFAULT) "\n"
"till vår Herre Jabu-Jabu."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, Det var ju inget vidare." BOX_BREAK "Alla som kommer hit \n"
"borde träffa vår " COLOR(RED) "Herre Jabu-Jabu" COLOR(DEFAULT) " åtminstone \n"
"en gång!" BOX_BREAK "Zoras Fontän är precis \n"
"bortom Kung Zoras tron. Det är där som\n"
"vår Herre Jabu-Jabu simmar. Men..." BOX_BREAK "så vida du inte har vår\n"
"Herre Jabu-Jabus tillåtelse, så kan du inte \n"
"ta dig till Zoras Fontän."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vi har inte hittat " COLOR(RED) "Prinsessan Ruto\n"
COLOR(DEFAULT) "trots att vissa utav oss har \n"
"sökt ända vid " COLOR(BLUE) "Hyliasjön" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du hittar någon ledtråd till vart\n"
COLOR(RED) "Prinsessan Ruto " COLOR(DEFAULT) "befinner sig,\n"
"kan du i så fall visa det för kung Zora?"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Allt vatten i Hyrule flödar\n"
"genom " COLOR(BLUE) "Zoras Fontän" COLOR(DEFAULT) "." BOX_BREAK "Det vattnet flödar genom\n"
"Zoras älv, som sedan sträcker sig till\n"
COLOR(BLUE) "Hyliasjön " COLOR(DEFAULT) "åt söder."
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh--Jag har kommit tillbaka till liv!" BOX_BREAK UNSKIPPABLE "Var det du som räddade mig?\n"
"Var inte nervös!" BOX_BREAK UNSKIPPABLE "Det verkar som att du tycker det är svårt\n"
"att andas under vattnet." BOX_BREAK UNSKIPPABLE "För att visa min tacksamhet,\n"
"så ger jag dig denna " COLOR(RED) "tunika" COLOR(DEFAULT) ". Med den så\n"
"kommer du inte att kvävas under vatten."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Prinsessan Ruto har gått till \n"
"Hyliasjön och har inte återvänt...\n"
"Jag är så orolig...igen!"
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ooh...\n"
"Detta är... Ptja... hmmm...\n"
"Hmmm... " COLOR(RED) "Ögondroppar" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Man kan säga att vi har det,\n"
"men även att vi inte har det...\n"
"Vi har däremot ingredienserna." BOX_BREAK UNSKIPPABLE "Om du tar " COLOR(RED) "ingredienserna " COLOR(DEFAULT) "till\n"
"läkaren vid sjöns laboratorie, så\n"
"kan han göra dropparna åt dig." BOX_BREAK UNSKIPPABLE "Men du måste leverera dem\n"
"färska..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Klarar du det " COLOR(RED) "före de blir\n"
"dåliga" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Så du tror alltså att de blir \n"
"dåliga innan du kommer fram?\n"
"Det är inte så långt dit om du \n"
"färdas på hästrygg..."
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hohoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", det verkar som \n"
"att du blir mer och mer bekväm\n"
"i din roll som äventyrare." BOX_BREAK UNSKIPPABLE "Jag tror att Prinsessan Zelda \n"
"väntar på att du ska besöka henne igen." BOX_BREAK UNSKIPPABLE "Du har redan " COLOR(RED) "Gorons Rubin" COLOR(DEFAULT) "," COLOR(RED) "\n"
COLOR(DEFAULT) "eller hur?"
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallå där, pojke. Jag forskar \n"
"i en process där jag tillverkar \n"
"medicin genom att blanda vatten \n"
"från Hyliasjön med ovanliga ämnen." BOX_BREAK "Du kanske har träffat den gamla \n"
"damen från Brygdbutiken...Hon är som \n"
"en elev till mig...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Åh, wow!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Jag har inte sett en " COLOR(RED) "Ögonglobsgroda" COLOR(DEFAULT) " \n"
"likt denna sedan Zoras Domän frös\n"
"över!" EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Åh, kära, rara " COLOR(RED) "Prinsessan Ruto" COLOR(DEFAULT) "...\n"
"Vart har hon tagit vägen?\n"
"Jag är så orolig..."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho, det här brevet! \n"
"Det är från " COLOR(RED) "Prinsessan Ruto" COLOR(DEFAULT) "!!" BOX_BREAK UNSKIPPABLE "Hmmm...Låt mig se...\n"
"Hon är inuti Jabu-Jabu?\n"
"Det kan inte vara möjligt!" BOX_BREAK UNSKIPPABLE "Vår gud, " COLOR(RED) "Jabu-Jabu" COLOR(DEFAULT) ",\n"
"skulle aldrig äta upp min älskade Prinsessan\n"
"Ruto!" BOX_BREAK UNSKIPPABLE "Men sedan den där främlingen, " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ",\n"
"kom hit, så har vår Herre Jabu-Jabu\n"
"blivit lite grön runt\n"
"gälarna..." BOX_BREAK UNSKIPPABLE "Beviset talar för sig självt.\n"
"Självklart så ska du leta efter Ruto.\n"
"Du kan passera härigenom till \n"
"vår Herre Jabu-Jabus altare." BOX_BREAK UNSKIPPABLE "Jag behåller det här brevet. Behåll du \n"
COLOR(RED) "flaskan " COLOR(DEFAULT) "det kom i. Behåll den \n"
"med vördnad!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Snälla hitta min älskade " COLOR(RED) "Ruto" COLOR(DEFAULT) "\n"
"med en gång... Zora!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Du kan inte andas under vattnet!\n"
"Om du kvävs, så ta av dig\n"
"de där " COLOR(DEFAULT) "skorna" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x36") "Åååååh neeej!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åhhh, nu så kvicknade jag till...\n"
"Var det du som räddade mig?\n"
"Var inte så nervös!" BOX_BREAK UNSKIPPABLE "Jag ska ge dig en " COLOR(BLUE) "Zoratunika " COLOR(DEFAULT) "som\n"
"bevis för min tacksamhet. Om du tar\n"
"på dig... Va?!" BOX_BREAK UNSKIPPABLE "Har du redan en? Du är \n"
"då redo för precis allt du!" BOX_BREAK UNSKIPPABLE "Så från djupet av mitt hjärta...vad \n"
"sägs om en KYSS?! Va? Du vill inte \n"
"ha det?! Jaha..." BOX_BREAK UNSKIPPABLE "Om du inte kan ta emot mina belöningar, så kan\n"
"du väl istället lyssna på mina problem..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag är en " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Har du sett någon \n"
"söt Zoraflicka häromkring?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag är en " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Har du sett\n"
"någpnting märkligt i sjön?\n"
"Älven bär med sig många ting \n"
"till den här sjön!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du..." QUICKTEXT_ENABLE "Du är sen!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Varför tog du sådan tid på dig?" QUICKTEXT_DISABLE "\n"
"Du är " QUICKTEXT_ENABLE "värdelös!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Jag var helt enkelt ensam, det är allt...\n"
"Men bara lite!!"
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Jag var rädd..." QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Lite!" QUICKTEXT_DISABLE " Bara lite!!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Du!" QUICKTEXT_DISABLE "\n"
"Du såg häftig ut...Häftigare än vad \n"
"jag trodde att du skulle göra... \n"
QUICKTEXT_ENABLE "Men bara lite!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ptja, du räddade mig trots allt, så jag \n"
"antar att jag får belöna dig." BOX_BREAK UNSKIPPABLE "Vad önskar du? berätta för mig...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Jag vill ha den där Själastenen.\n"
"Ingenting egentligen..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du menar Vattnets Själasten,\n"
COLOR(BLUE) "Zoras Safir" COLOR(DEFAULT) ", eller hur?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Min mor gav den till mig och sa \n"
"att jag endast skulle ge den till \n"
"mannen som jag kommer att gifta mig med. Du kan\n"
"kalla den för Zoras förlovningsring!" BOX_BREAK UNSKIPPABLE  SHIFT("\x45")  QUICKTEXT_ENABLE "Okej!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Jag ger dig min mest värdefulla\n"
"ägodel: \n"
"Zoras Safir!"
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Säg ingenting till min far..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hihihi... Var inte blyg." BOX_BREAK UNSKIPPABLE "Jag vet vad du tänker på..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag vill köpa en fisk, men de är\n"
"lite för dyra..." BOX_BREAK "Jag har inget annat val än att\n"
"fånga en utav fiskarna\n"
"som simmar omkring där ute."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Åh, " NAME "!\n"
"Så, du räddade prinsessan va?\n"
"Jag uppskattar det verkligen!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Har min käraste ägodel hjälpt\n"
"hjälpt dig på ditt äventyr? Hihi!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, hej " NAME "!\n"
"Du är det enda som Prinsessan Ruto\n"
"pratar om nuförtiden!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, det är du, " NAME "!\n"
"Tack vare dig, så är vår Herre Jabu-Jabu\n"
"frisk igen!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Alla vi Zora respekterar den store\n"
"Kung Zora! Han besitter en Kungs \n"
"värdighet. Åh ja, det gör han." BOX_BREAK UNSKIPPABLE "Den store Kung Zora har en \n"
"dotter vid namn " COLOR(RED) "Ruto" COLOR(DEFAULT) ". Hon är\n"
"hans enda barn." BOX_BREAK UNSKIPPABLE "Hon är en vild pojkflicka,\n"
"och hon hittar ofta på rackartyg\n"
"som ställer till det för kungen!" TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Här är det." BOX_BREAK UNSKIPPABLE "Den här medicinen innehåller\n"
"inga konserveringsmedel. Så den " COLOR(RED) "varar \n"
"inte så länge i " COLOR(DEFAULT) "den här temperaturen." BOX_BREAK UNSKIPPABLE "Spring så fort du kan till \n"
"Dödens Berg. Du har friska ben--\n"
"så du klarar det!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo! Jag ser att du har blivit större\n"
"större och starkare redan,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Precis här borta så ligger " COLOR(BLUE) "Zoras Domän" COLOR(DEFAULT) ". \n"
"Zorerna tjänar Hyrules Kungliga \n"
"Familj genom att beskydda \n"
"källan till allt vatten." BOX_BREAK UNSKIPPABLE "De öppnar inte dörren för \n"
"någon utomstående, så länge de inte\n"
"har någon anknytning till den Kungliga \n"
"Familjen." BOX_BREAK UNSKIPPABLE "Låt dem höra den " COLOR(RED) "Kungliga familjens \n"
"melodi" COLOR(DEFAULT) "!\n"
"Hooo hoo hoooo!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nästa gång du kommer tillbaka, \n"
"så kom ihåg att ta med dig en \n"
"souvenir till mig!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hittade Prinsessan Ruto!\n"
"Nu så kommer Kung Zora att ge dig \n"
COLOR(BLUE) "Vattnets Själasten" COLOR(DEFAULT) "...\n"
"Eller, Ptja." BOX_BREAK UNSKIPPABLE "Kanske?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hennes mest värdefulla ägodel?\n"
"Du förstår inte vad hon babblar\n"
"om, men du har härmed samlat in två \n"
"Själastenar! Bara en till nu!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hennes mest värdefulla ägodel?\n"
"Du förstår inte vad hon babblar\n"
"om, men du har äntligen samlat in\n"
"alla tre Själastenar!!" BOX_BREAK UNSKIPPABLE "Återvänd till Prinsessan Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vi möts igen, " NAME "..."
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Denna is skapades utav en ondskefull\n"
"förbannelse... Monstret i " COLOR(BLUE) "\n"
"Vattentemplet " COLOR(DEFAULT) "är källan till förbannelsen." BOX_BREAK UNSKIPPABLE "Så länge du inte stänger av \n"
"källan så kommer isen aldrig att smälta...." BOX_BREAK UNSKIPPABLE "Om du är modig nog att \n"
"stå upp inför faran och rädda \n"
"Zorerna, så ska jag lära dig en melodi \n"
"som kommer att leda dig in i templet."
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tiden går, folk går vidare....\n"
"Som flödet i en älv, så slutar det aldrig..." BOX_BREAK UNSKIPPABLE "Ett barnsligt sinne\n"
"och ett ädelt ändamål... Ung kärlek förändras\n"
"till djup åtråhet... Det klara \n"
"vattnets yta återspeglar tillväxt..." BOX_BREAK UNSKIPPABLE "Så lyssna nu till " COLOR(BLUE) "Vattenserenaden\n"
COLOR(DEFAULT) " och unna dig själv en tanke...."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Om du har kommit hit för att träffa \n"
"Zorerna, så ödslar du din tid...\n"
"Det här är allt som finns kvar..." BOX_BREAK UNSKIPPABLE "Med ett undantag, Zorerna \n"
"är nu förseglade bakom detta tjocka \n"
"lager av is..." BOX_BREAK UNSKIPPABLE "Jag lyckades rädda Zora-\n"
"Prinsessan från under isen, men... \n"
"hon gav sig iväg till " COLOR(BLUE) "\n"
"Vattentemplet" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du vill köpa fisk, så behöver du\n"
"en behållare att stoppa dem i." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Så du säger att du vill köpa en " COLOR(BLUE) "Zora-\n"
"Tunika" COLOR(DEFAULT) "? Den Tunikan är tillverkad\n"
"utav väldigt bra material, och är således\n"
"ofantligt dyr!" BOX_BREAK "Jag är rädd att endast den " COLOR(RED) "den\n"
"rikaste familjen i Kakarikobyn " COLOR(DEFAULT) "\n"
"har råd med detta fina plagg..." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh...du... Stämmer det att...\n"
NAME "?!" BOX_BREAK UNSKIPPABLE "Det är du som är " NAME ", eller\n"
"hur?" BOX_BREAK UNSKIPPABLE "Det är jag, din fästmö, " COLOR(BLUE) "Ruto" COLOR(DEFAULT) "!\n"
"Prinsessa utav Zorerna!" BOX_BREAK UNSKIPPABLE "Jag glömde aldrig löftena\n"
"vi gav varandra för sju år \n"
"sedan!" BOX_BREAK UNSKIPPABLE "Du är en hemsk man som har \n"
"låtit mig vänta alla dessa sju\n"
"långa år..." BOX_BREAK UNSKIPPABLE "Men just nu så har vi inte tid att \n"
"tala om kärlek..." BOX_BREAK UNSKIPPABLE "Har du märkt av det ännu?!\n"
"att Zoras Domän helt frusit över!" BOX_BREAK UNSKIPPABLE "En ung man vid namn " COLOR(RED) "Sheik" COLOR(DEFAULT) " räddade \n"
"från under isen..." BOX_BREAK UNSKIPPABLE "Men min far och de andra \n"
"Zorerna är kvar där" TEXT_SPEED("\x02") "...fortfarande..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Jag vill rädda dem allihop!\n"
"Jag vill rädda Zoras Domän!" BOX_BREAK UNSKIPPABLE "Du! Du måste hjälpa mig!\n"
"Detta är en begäran från mig,\n"
"kvinnan som ska bli din\n"
"hustru!" BOX_BREAK UNSKIPPABLE  NAME ", du måste \n"
"hjälpa mig att besegra monstret\n"
"i Templet, Okej?!" BOX_BREAK UNSKIPPABLE "I Vattentemplet, så finns där \n"
COLOR(RED) "tre platser" COLOR(DEFAULT) " där du kan \n"
"förändra vatten-nivån." BOX_BREAK UNSKIPPABLE "Jag tar täten.\n"
"Följ efter mig, fort!!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! Look out!\n"
"That isn't normal water over \n"
"there!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "..." BOX_BREAK UNSKIPPABLE "I would have expected no less\n"
"från den man som ska bli till min\n"
"make." BOX_BREAK UNSKIPPABLE "Zoras Domän och dess folk\n"
"kommer i sinom tid återvända\n"
"till det gamla vanliga igen."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Om du träffar på Sheik, \n"
"så var snäll och tacka honom, okej?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Så Ruto tackade mig?" BOX_BREAK UNSKIPPABLE "Jag förstår...." BOX_BREAK UNSKIPPABLE "Vi måste återställa freden \n"
"i även för hennes skull \n"
"Eller hur?"
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, I see...\n"
"Princess Ruto went to the Water\n"
"Temple..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Som belöning...\n"
"Så skänker jag dig min eviga kärlek." BOX_BREAK UNSKIPPABLE "Ptja, det är vad jag önskar säga, \n"
"men jag tror inte att jag kan ge dig\n"
"det just nu."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prinsessan Zelda... Hon lever. Jag kan\n"
"känna det...så tappa inte modet."
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Hjääälp!\n"
SHIFT("\x0F") "Vad är det där?! En bläckfisk?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Som" COLOR(BLUE) "Vattnets Vise" COLOR(DEFAULT) "så måste jag\n"
"vaka över Vattentemplet..." BOX_BREAK UNSKIPPABLE "Och du... Du söker efter\n"
"prinsessan, " COLOR(RED) "Zelda" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Hah!\n"
"Du kan inte dölja någonting för mig!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag märker att ingenting kan stoppa\n"
"dig på din jakt efter fred och  \n"
"rättvisa... Ta emot den här \n"
COLOR(BLUE) "Medaljen" COLOR(DEFAULT) "... Bär den med respekt!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du! Vem är du?!" BOX_BREAK UNSKIPPABLE "Jag heter " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Prinsessa över Zorerna." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Va?!" QUICKTEXT_DISABLE "\n"
"Säger du att min pappa har bett \n"
"dig att komma hit och rädda mig?" BOX_BREAK UNSKIPPABLE "Jag skulle " QUICKTEXT_ENABLE "aldrig" QUICKTEXT_DISABLE " be någon att göra en sådan\n"
"sak!" BOX_BREAK UNSKIPPABLE "\"Ett brev i en flaska?\"  Jag har\n"
QUICKTEXT_ENABLE "ingen aning" QUICKTEXT_DISABLE " vad du pratar för strunt!" BOX_BREAK UNSKIPPABLE "Är min far orolig för mig?" BOX_BREAK UNSKIPPABLE "Jag " QUICKTEXT_ENABLE "bryr mig inte!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Oavsett så kan jag inte gå hem nu.\n"
"Och du... " QUICKTEXT_ENABLE "Gå ut härifrån!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Är det förstått?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hänger du fortfarande kvar här?\n"
"Jag sa ju åt dig att sticka!" BOX_BREAK UNSKIPPABLE "Jag är okej. Jag har gått in i\n"
"vår Herre Jabu-Jabus mage sedan jag var\n"
"liten, men..." BOX_BREAK UNSKIPPABLE "Vår Herre Jabu-Jabu är lite konstig \n"
"idag..." BOX_BREAK UNSKIPPABLE "Där finns elektriska maneter och\n"
"märkliga hål häromkring..." BOX_BREAK UNSKIPPABLE "Som grädde på moset så \n"
"har min älskade sten...den...\n"
QUICKTEXT_ENABLE "Det angår inte dig!" QUICKTEXT_DISABLE "\n"
"Oavsett..." BOX_BREAK UNSKIPPABLE "Du! " QUICKTEXT_ENABLE "Gå hem med dig!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Förstått?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Är du så orolig för mig?" BOX_BREAK UNSKIPPABLE "I så fall så ska du få äran att\n"
"bära mig!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Fast" QUICKTEXT_DISABLE "...Jag kommer att stanna \n"
"kvar här tills vi hittar vad vi letar efter.\n"
"Kom inte och säg något annat!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Så ofärskämt!" QUICKTEXT_DISABLE "\n"
"Hur kunde du lämna kvar mig här?! \n"
"Om du är en man, så bete dig som en! \n"
"Ta lite ansvar!" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Där är den!" QUICKTEXT_DISABLE "\n"
"Det är den som jag har letat efter!\n"
"Kasta upp mig dit! \n"
"Upp på den där plattformen!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Prinsessan Ruto fick \n"
COLOR(BLUE) "Själastenen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Men" TEXT_SPEED("\x00") " varför just Prinsessan Ruto?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Åh herre min skapare!\n"
"Jag hittade den till slut... \n"
"Min mors sten..." BOX_BREAK UNSKIPPABLE "Jag jätteupprörd då vår Herre Jabu-\n"
"Jabu svalde den..." BOX_BREAK UNSKIPPABLE "Medan jag matade honom, så\n"
"svalde han plötsligt mig med! Jag blev \n"
"Så överraskad att jag tappade stenen..." BOX_BREAK UNSKIPPABLE "Men, nu när jag har hittat den, \n"
"så behöver jag inte vara här \n"
"inne mer!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Så, ta med mig hem, på en gång!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dykarspel   20 Rupees\n"
"Vill du spela?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "OKEJ!" QUICKTEXT_DISABLE  BOX_BREAK "Plocka upp alla Rupees jag kastar \n"
"härifrån. Du har bara en begränsak\n"
"tid på dig!" BOX_BREAK "Då du plockat upp alla, \n"
"så återvänd hit! Så ska jag ge dig\n"
"någonting väldigt fint!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hej!  Grattis!" QUICKTEXT_DISABLE "\n"
"Jag har någonting \n"
"väldigt fint till dig!\n"
"Ta emot den!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vilket graciöst dyk!\n"
"Snälla ta emot den här!" BOX_BREAK UNSKIPPABLE "Det är ett \"" COLOR(RED) "fjäll" COLOR(DEFAULT) "\" utav oss.\n"
"Med denna, så kan du dyka\n"
"mycket djupare under vattnet." EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Medan vattenytan stiger, så \n"
"försvinner ondskan från sjön...\n"
NAME ", du gjorde det!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag...tror att du kommer att rädda \n"
"save this world..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se där, " NAME "..." BOX_BREAK UNSKIPPABLE "Tillsammans med Prinsessan Ruto \n"
"besegrade du det onda monstret!" BOX_BREAK UNSKIPPABLE "Ännu en gång, så fylls sjön med\n"
"rent vatten. Allt är som vanligt igen."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(RED) "SÄTT IGÅNG!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gå genom fallet för en genväg." EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ta så mycket du kan bära för \n"
"20 Rupees.  Vill du spela?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hej!  Grattis!!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vad sägs om några" COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "?\n"
"De säljer inte så värst bra..." BOX_BREAK "Hur låter...\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " för en styck?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vad sägs om några" COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "?\n"
"Ptja, de är inte så värst populära än." BOX_BREAK "Vad sägs om...\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) " för en styck?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vad sägs om några" COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "?\n"
"De börjar bli rätt så\n"
"populära..." BOX_BREAK COLOR(RED) "30 Rupees" COLOR(DEFAULT) " för en styck.\n"
"Vad sägs?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vad sägs om några" COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "?\n"
"Alla vill köpa dem!" BOX_BREAK COLOR(RED) "40 Rupees" COLOR(DEFAULT) " för en styck.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Det är vi som säljer de populära " COLOR(RED) "Magiska Bönorna" COLOR(DEFAULT) "!\n"
"Du kommer att ångra dig ifall du inte \n"
"köper dem nu!" BOX_BREAK COLOR(RED) "50 Rupees" COLOR(DEFAULT) " för en styck.\n"
"(tillfälligt pris.)\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Detta är de superpopulära \n"
COLOR(RED) "Magiska Bönorna" COLOR(DEFAULT) "! Ifall du undrar \n"
"så kommer de snart att sälja slut!" BOX_BREAK "Superpris!\n"
COLOR(RED) "60 Rupees" COLOR(DEFAULT) " för en styck!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vi säljer de superovanliga \n"
COLOR(RED) "Magiska Bönorna" COLOR(DEFAULT) "! Detta kan bli din\n"
"sista chans!" BOX_BREAK "Specialpris!\n"
COLOR(RED) "70 Rupees" COLOR(DEFAULT) " för en styck!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vi har de legendariska \n"
COLOR(RED) "Magiska Bönorna" COLOR(DEFAULT) "! Nu har just DU chansen \n"
"att köpa dem!" BOX_BREAK "Superpris!\n"
COLOR(RED) "80 Rupees" COLOR(DEFAULT) " för en styck!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vill du köpa..." COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "?! \n"
"De är inte billiga, men...vill du\n"
"vill du fortfarande köpa?" BOX_BREAK "Jag kan inte släppa dem för mindre än\n"
COLOR(RED) "90 Rupees" COLOR(DEFAULT) " styck!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tugg tugg tugg...\n"
"Vi har..." COLOR(RED) "Magiska Bönor" COLOR(DEFAULT) "! \n"
"Du vill ha dem...va? va?" BOX_BREAK COLOR(RED) "100 Rupees" COLOR(DEFAULT) " för en styck!\n"
"Hahaha!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jaha...\n"
"Tugg tugg..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du har inte tillräckligt med pengar.\n"
"Jag kan inte sälja dem till dig.\n"
"Tugg tugg..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Placera en böna på " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "och använd den på\n"
"jorden här."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, ledsen! Vi är slutsålda!\n"
"Tugg tugg...Va?\n"
"Åh, de där bönorna är inte till salu!"
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om du vill plantera bönor, gå\n"
"runt och leta efter mjuk jord.\n"
"Tugg tugg tugg."
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "1 meter" COLOR(DEFAULT) " precis nu. Men jag skulle \n"
"inte kalla det för ett riktigt dyk."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "2 meter" COLOR(DEFAULT) " precis nu. Men jag skulle \n"
"inte kalla det för ett riktigt dyk."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "3 meter" COLOR(DEFAULT) " precis nu. Men jag skulle \n"
"inte kalla det för ett riktigt dyk."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "4 meter " COLOR(DEFAULT) "precis nu. Fortfarande \n"
"inte tillräckligt djupt!"
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "5 meter " COLOR(DEFAULT) "precis nu. Fortfarande \n"
"inte tillräckligt djupt!"
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "6 meter" COLOR(DEFAULT) " precis nu. Du borde kunna\n"
"dyka djupare!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du dök \n"
COLOR(RED) "7 meter" COLOR(DEFAULT) " precis nu. Du borde kunna\n"
"dyka djupare!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du kanske inte har märkt det, men jag\n"
"har hållit ett öga på dig. Du \n" COLOR(RED) "vidrörde \n"
"botten " COLOR(DEFAULT) "precis nu.  Fantastiskt!\n"
"Du får den här utav mig!"
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du är bäst på att dyka i hela \n"
"världen. Vad sägs om att dyka till \n"
"botten av Hyliasjön?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mitt namn är " COLOR(RED) "Pierre" COLOR(DEFAULT) ", den vandrande\n"
"fågelskrämman. Egentligen så önskar jag\n"
"vandra runt och leta efter vackra låtar,\n"
"men jag är rädd att jag sitter fast här."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Fantastisk låt! Den vidrörde mitt \n"
"hjärta!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du kommer på en vacker låt,\n"
"kom då tillbaka och låt mig höra den!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den låten du först spelade för mig\n"
"finns kvar i mitt hjärta. Får jag\n"
"höra den igen?!" EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den låtem du spelade för mig \n"
"stannar i mitt hjärta!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Så, vill du gå och fiska \n"
"för " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Åh, nej! Du har inte en " COLOR(RED) "Rumble \n"
"Pak" COLOR(DEFAULT) "! Med en Rumble Pak, så kan\n"
"du känna vibrationerna från en fisk som\n"
"fastnar på kroken." BOX_BREAK "Det blir inga vibrationer för din del!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow! du har en " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Idag så kan du känna vibrationerna,\n"
"unge man!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hrmf! Du har inte tillräcklgt \n"
"med pengar."
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Okej, lyssna här!" BOX_BREAK "Gå till kanten av vattnet och\n"
"tryck " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " för att titta på en fisk." BOX_BREAK "Medan du ser på en fisk, så kan du \n"
"kasta en lina med " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". Tryck " COLOR(BLUE) "[A]\n"
COLOR(DEFAULT) "för att bromsa linan." BOX_BREAK "Då draget faller ned i vattnet \n"
"så kan du lirka det med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"Om du är nybörjare, så kan du även\n"
"använda " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." BOX_BREAK "Veva in draget med " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Håll \n"
"ned " COLOR(BLUE) "[A]" COLOR(DEFAULT) " och " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "för att veva in det \n"
"snabbare." BOX_BREAK "Om du känner av en träff, tryck " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "och\n"
COLOR(LIGHTBLUE) "[Control-Pad] ned " COLOR(DEFAULT) "för att sätta kroken.\n"
"Efter det, veva in den med " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "förstår du?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag är så generös, så att jag låter\n"
"dig fiska hur länge du vill. Fast,\n"
"du kan endast behålla en fisk." BOX_BREAK "Den största fisken du har fångat här\n"
"vägde " COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "." BOX_BREAK "Efter du kastar, så kan du ändra\n"
"din vy med " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." BOX_BREAK SHIFT("\x41") "Då fiskar vi!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hah ha haah!\n"
"Satte du kroken genom att trycka\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " och " COLOR(LIGHTBLUE) "[Control-Pad] ned" COLOR(DEFAULT) "?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va, vad hände?\n"
"Du tappade den!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ja, ja...den väger typ " COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) ". \n"
"Vill du behålla den?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vad vill du?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Väg min fisk.\n"
"Vi pratar om någonting.\n"
"Jag vill avsluta." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag är seriös! Enbart passion\n"
"fångar inte många fiskar!!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "OJ!" BOX_BREAK "Den här fisken är enorm! Det ser ut som \n"
"ett nytt rekord! Den väger minst \n"
COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "! Seriöst! \n"
"Okej, här får du ditt pris!" EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va? \n"
"Vad gör du med mig?!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallå där, unge man! Har du inte \n"
"någonting viktigt som du måste\n"
"göra?" BOX_BREAK "Va? Säger du att det är mycket \n"
"roligare att leka här?" BOX_BREAK "Jag har sett många fördärva\n"
"sina liv med den attityden.\n"
"Jag är helt seriös!\n"
"Ja ja..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Den största fisken som fångats\n"
"i den här dammen vägde " FISH_INFO " pund.\n"
"Fiskaren namn var: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du fortsätta att fiska?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"¨Ptja, den väger " COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "...\n"
"Inte illa, men det finns större\n"
"fiskar där i!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallå, kom igen! Du har ju ingen fisk!\n"
"Äsch!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vill du prova ett annat drag?\n"
"Vad snackar du om? Är du verkligen\n"
"så självisk?" BOX_BREAK "Har du inte hört uttrycket,\n"
"\"En bra fiskare väljer aldrig\n"
"sitt eget drag?\""
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vad? Vill du höra några \n"
"fiskehemligheter? Jag kan inte berätta\n"
"det för dig. De är företagshemligheter.\n"
"Helt seriöst!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vad? Vill du veta om jag är en \n"
"bra fiskare?" BOX_BREAK "Självklart så är jag det!\n"
"Jag är ett riktigt proffs?\n"
"Det är så sant som det är sagt!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regler och Reglementen\n" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Använd inte sjunkdrag.\n"
"2. Skräpa inte ned.\n"
"3. Gå tyst." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "4. Kasta inte på någon annan." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow! Detta var en riktig gammelgädda!\n"
"Låt se...den väger\n"
COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "!" BOX_BREAK "Vill du behålla den?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Kom tillbaka då du är äldre!\n"
"Fiskarna kommer att vara större\n"
"då med...Eller...Kanske."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallå där, herrn! Jag kommer ihåg dig!\n"
"Det var länge sedan sist!" BOX_BREAK UNSKIPPABLE "Hur många år sedan är det?\n"
"Sju år?! Vad har du haft för dig\n"
"under den här tiden?!" BOX_BREAK UNSKIPPABLE "Du är min enda kund. Jag har \n"
"nästan varit tvungen att stänga ned!\n"
"På allt detta så har mitt hår..." BOX_BREAK UNSKIPPABLE "Öh, jag menar, glöm det..." BOX_BREAK UNSKIPPABLE "Så, vill du fiska?\n"
"Det kostar endast " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va?" BOX_BREAK "Du vill gå och fiska i \n"
"en annan fiskedamm?!\n"
"Vad snackar du om?" BOX_BREAK "Jag kommer ju att bli ruinerad\n"
"om inte du fiskar här!\n"
"Jag är helt seriös!"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va?" BOX_BREAK "Vill du veta varför jag \n"
"kliar mig hela tiden?\n"
"Vad snackar du om?" BOX_BREAK "Jag har faktiskt ingen aning.\n"
"Jag är helt seriös!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va?" BOX_BREAK "Säger du att du inte kan\n"
"se fiskarna för att vattnet\n"
"är dammigt?" BOX_BREAK "Vad snackar du om?\n"
"Det här är ju den bästa tiden \n"
"på dygnet för att fiska!" BOX_BREAK "Du kan kroka fast en fisk\n"
"rätt som det är då du minst anar det.\n"
"Nu blev jag riktigt peppad!" BOX_BREAK "Seriöst.  det blev jag!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallå där, vad håller du på med?\n"
"Jag sade ju åt dig att inte göra så!\n"
"Fy vad odräglig du är!\n"
"Seriöst!" BOX_BREAK "Ge tillbaka min hatt!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okej\n"
"Aldrig i livet!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va? Jaha? Åhå?\n"
"Jag tror att fisken du redan\n"
"hade var större än den här..." BOX_BREAK "Vill du fortfarande behålla den?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Nä, jag vill inte ha den\n"
"Ja, jag vill behålla den ändå" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oj då! Det var då en konstig fisk\n"
"du fångade där! Som grädde på moset\n"
"så väger den " COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "!" BOX_BREAK "Vad vill du göra med den?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Behåll den ändå\n"
"Jag vill inte ha den" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow!" BOX_BREAK "Är det här vad jag tror det är?\n"
"Häpnadsväckande!\n"
"Du drog upp ett " COLOR(RED) "sjunkdrag" COLOR(DEFAULT) "!" BOX_BREAK "Vad vill du göra med det?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Använd det nu.\n"
"Gör dig av med det." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Men ser man på..." BOX_BREAK "WOW! Vilken ovanlig fisk!\n"
"Det här är en " COLOR(RED) "Hyrulelax" COLOR(DEFAULT) "!" BOX_BREAK "Vad gäller denna fisk, så spelar \n"
"storleken ingen roll. Du har förtjänat \n"
"det här priset!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Senaste tiden, så har antalet\n"
"fiskar minskat oerhört mycket,\n"
"så jag släpper lös den här." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regler och Reglementen\n"
"1. Använd inte sjunkdrag.\n"
"2. Skräpa inte ned.\n"
"3. Gå tyst." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallå där!\n"
"Du kan inte ta med dig ett spö\n"
"härifrån!" BOX_BREAK "Återlämna spöet vid disken \n"
"då du slutar fiska.\n"
"Jag är helt seriös!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh min store!\n"
"Den här fisken är gigantisk!!" BOX_BREAK "En sådan här fisk får inte ens\n"
"plats på skärmen, och jag kan inte väga\n"
"den ordentligt, men den ser ut att\n"
"väga " COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "!!" BOX_BREAK "Du vill definitivt behålla den,\n"
"eller?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Behåll den\n"
"Behåll den inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tja snäckan!\n"
"Jag heter " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", fågelskrämman!\n"
"Du har förmodligen hört om mitt\n"
"fantastiska minne!" BOX_BREAK "Om du har en ny låt,\n"
"så kör igång!" BOX_BREAK "Denna låten spelade du för mig \n"
"sist, snäckan!" BOX_BREAK "Kör igång!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag heter " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", fågelskrämman!\n"
"Ett musikaliskt geni!\n"
"Hör jag en låt, Så glömmer\n"
"jag aldrig bort den, snäckan!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Spela den vanliga låten\n"
"för att kalla på Pierre!\n"
"Om han är i närheten, så kommer\n"
"han för att hjälpa dig, snäckan!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hej! Är inte du den där älvpojken\n"
"som jag mötte för länge sedan?\n"
"Wow, du har vuxit, snubben!" BOX_BREAK "Ptja, här är din låt..." BOX_BREAK "Va?" BOX_BREAK "Nej, jag glömmer aldrig!\n"
"Du, det var du som glömde...\n"
"eller hur? Om du har en \n"
"Okarina, så spela den låten, snäckan!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tjoho! You have an okarina!\n"
"Men du, vad sägs om att du drar\n"
"en låt på den för mig, snäckan?!" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ptja...inte illa!\n"
"Jag ska komma ihåg den åt dig \n"
"i alla fall!" BOX_BREAK "Jag menar, jag kan inte enbart komma\n"
"ihåg åtta noter, men vi håller oss till\n"
"det för tillfället, snäckan!" EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Spelar du sådär illa så kommer\n"
"du aldrig att röra den här\n"
"fågelskrämmans hjärta, snäckan!" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OH YEAHHH!!\n"
"Precis så, där har vi låten!!\n"
"Du rockar!! Jag är helt såld!" BOX_BREAK "Åh, nej, nej! Jag glömde aldrig\n"
"låten...Jag glömmer aldrig något!\n"
"Men just nu känner jag för att\n"
"belöna dig, snäckan!" BOX_BREAK "........\n"
"Jag har en bra idé!" BOX_BREAK "Min polare Pierre vandrar\n"
"omkring, så spela den låten då\n"
"du vill kalla på honom!" BOX_BREAK "Jag ska säga åt honom att\n"
"hjälpa dig om han är i närheten, snäckan!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se där, Det är ju Okarinan!\n"
"Spela en låt med den,\n"
"snäckan!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Unge man, du spelar väldigt\n"
"bra på din okarina...! Den melofin är \n"
"så fin...kväk! Vi alla borde öva\n"
"på den tillsammans, kväk!" BOX_BREAK "Ta emot Rupees som en souvenir!\n"
"Om du kommer på en annan fin \n"
"melodi, så kom tillbaka och spela\n"
"den för oss...kväk kväk!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Wow, den melodin är så grym! \n"
"Kväk!" BOX_BREAK "Ned faller regnet, ned faller regnet,\n"
"spolar spindeln bort! \n"
"Kvvääääk!!" BOX_BREAK "Var snäll och ta emot detta som\n"
"ett tecken på vår grodiska tacksamhet, kväk!\n"
"Då så. Vi ses, kväk!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Se på oss, vi är stora grodor allihop!!\n"
"Vi är de världskända fabulösa\n"
"Fem Grodiska Tenorerna!!\n"
"Kvväääk!!" BOX_BREAK "Få oss att hoppa så vi kan äta \n"
"krypen som flyger över oss, kväääk!" BOX_BREAK "Okej? \n"
"Ett, två, tre, kör!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Unga pojke, Du gjorde brrraa ifrån dig!\n"
"Perrrrrfekt!\n"
"Nu är vi mätta, kväk!" BOX_BREAK "Vill du ha detta som ett tecken\n"
"på vår tacksamhet?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jaha, jag kommer inte ihåg \n"
"den låten, snäckan.\n"
"Varför? Jag har ingen aning!\n"
"Herre min skapare!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Den största fisken som fångats\n"
"i den här dammen vägde " FISH_INFO " pund.\n"
"Fiskaren var: dammens ägare" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va?\n"
"Vill du fiska med ett \n"
"annat drag?\n"
"...Hallå, vad är det där?" BOX_BREAK "Va? Du plockade ju precis upp det?\n"
"I vanliga fall, så säger reglerna att man\n"
"inte får använda en sådan där. I vanliga fall.\n"
"Men, vad sjutton..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"TJOHOOO!\n"
"Den är ENORM!! Ett nytt rekord!!\n"
"Den...Den väger så mycket som...\n"
COLOR(RED)  FISH_INFO " pund" COLOR(DEFAULT) "!!" BOX_BREAK "Meeeen! Det där sjunkdraget\n"
"är emot reglerna!\n"
"Så, inget pris för din del.\n"
"Haaaa ha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Den största fisken som fångats\n"
"i den här dammen vägde " FISH_INFO " pund.\n"
"Fiskaren var: " NAME "\n"
"(NOTERING: Med ett illegalt sjunkdrag.)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du är ett godhjärtat barn!\n"
"Men berätta inte det för någon.\n"
"Seriöst!" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"VAAAAA?!?" BOX_BREAK "Varför gör du såhär mot mig?\n"
"Vad tänker du med egentligen?" BOX_BREAK "Du kommer inte att slippa undan\n"
"så enkelt! Du måste betala mig \n"
COLOR(RED) "50 Rupees " COLOR(DEFAULT) "i böter!\n"
"Seriöst!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Du" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "dödade" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "mig!!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Va? Åh, det är ju du." BOX_BREAK "Försökte du att spela \n"
COLOR(YELLOW) "Solens Visa" COLOR(DEFAULT) "?" BOX_BREAK "Som jag sa till dig innan, med den \n"
"visan, så kan du göra dag till natt \n"
"eller natt till dag när du så än \n"
"önskar." BOX_BREAK "Då du befinner dig i mörker, så \n"
"kan den visan bringa dig solljus.\n"
"Gör ett försök."
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Då jag grävde ett hål, så hittade \n"
"en skatt man kan töja--BOING!\n"
"och som krymper--BOING! Det är jättekul, \n"
"Jag kommer aldrig att ge den till någon!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
COLOR(RED) "Gravvårdarens dagbok " COLOR(DEFAULT) "finns här.\n"
"Vill du läsa den?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Du som läser detta, kom in i\n"
"min grav. Jag låter dig ta min\n"
"töjbara, krympande " COLOR(RED) "minnessak" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Jag väntar på dig.\n"
"--Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Du bestämde dig för att inte läsa..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du besegrade spöket Poe!" BOX_BREAK "Vill du fånga det i \n"
"en flaska?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du vill fånga det men\n"
"du saknar en tom flaska."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du släpper lös den tills vidare."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du fångade en Poe!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x04") "Den annalkande solnedgången är snart kommen  ,\n"
SHIFT("\x19") "Ett nyfött liv bleknar bort." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x05") "Från sol till måne, måne till sol..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x25") "Skänk inre ro till\n"
SHIFT("\x37") "till de levande döde." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Detta är en intressant dikt...\n"
"eller hur?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "Rastlösa själar vandrar\n"
SHIFT("\x1E") "där de ej hemma hör,\n"
SHIFT("\x27") "skänk dem tröst\n"
SHIFT("\x36") "med " COLOR(YELLOW) "Solens Visa" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Någonting är inristat i \n"
"gravstenen..." BOX_BREAK UNSKIPPABLE "Det är Kompositörbrödernas " COLOR(YELLOW) "hemliga melodi." COLOR(DEFAULT)
)


DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den Ultimata brygden! Vad sägs om\n"
COLOR(RED) "100 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Köp\n"
"Köp inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om du ångrar dig så kom \n"
"tillbaka och hälsa på mig...\n"
"Hihihi!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du har inte tillräckligt med Rupees!\n"
"Hihihi!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "GYAAAAH!\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "DU" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DÖDADE" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MIG..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  QUICKTEXT_ENABLE "Otroligt!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Åh, va?\n"
"Du är inte en utav Ganondorfs \n"
"män, eller?" BOX_BREAK UNSKIPPABLE "På grund utav min roll som spöke, så\n"
"var jag tvungen att bete mig som ett. Ursäkta." BOX_BREAK UNSKIPPABLE "Då så, låt mig presentera mig själv.\n"
"Ahem..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag är en utav de spökliga Kompositör- \n"
"bröderna från Kakarikobyn." BOX_BREAK "Alla i den byn är\n"
"födda att tjäna den Kungliga Familjen av\n"
"Hyrule." BOX_BREAK "Vi bröder tjänade också den Kungliga \n"
"Familjen, vi tilldelades arbetet att \n"
"studera de nedärvda mystiska krafter \n"
"som familjen besitter." BOX_BREAK "Även om vi inte kunde lista ut\n"
"den kraft som Trekraften besitter," BOX_BREAK "så hade vi nästan färdigställt vår\n"
COLOR(RED) "forskning i att kontrollera tid" COLOR(DEFAULT) " med hjälp utav\n"
"tonerna från en Okarina." BOX_BREAK "Öh, Jag menar..." BOX_BREAK "Egentligen så blev vi\n"
"klara!" BOX_BREAK "Vi skulle ha blivit berömda, om \n"
"det inte hade varit för att den där hätska Ganondorf\n"
"försökte stjäla våra resultat." BOX_BREAK "Vi skulle aldrig kunna låta \n"
"honom skörda frukterna utav vår forskning!" BOX_BREAK "Det var därför som vi gav vårt \n"
"liv för att skydda hemligheten." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vill du höra vad jag hade \n"
"att säga igen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "JAG ÄR" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DÖD" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "I" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "GEN!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Va? Du igen?" BOX_BREAK UNSKIPPABLE "Du påminner mig om...\n"
"Prinsessan Zelda, på något vis..." BOX_BREAK UNSKIPPABLE "Hmm... Då du verkar ha något form utav band\n"
"till den Kungliga Familjen, så\n"
"ska jag berätta lite mer om oss\n"
"för dig." BOX_BREAK UNSKIPPABLE "På den tiden, så kallades vi för\n"
"stora kompositörer på grund av de många \n"
"musikaliska mästerverk vi skrev." BOX_BREAK UNSKIPPABLE "Fast vi bröder var inte bara \n"
"kompositörer." BOX_BREAK UNSKIPPABLE "Vi hade en uppgift att undersöka\n"
"de mystiska krafter som den\n"
"Kungliga Familjen besitter." BOX_BREAK UNSKIPPABLE "Våra namn hade blivit en del \n"
"utav Hyrules historia om vi hade \n"
"färdigställt vårt arbete!" BOX_BREAK UNSKIPPABLE "Vi var extremt hemliga med \n"
"vårt arbete fram tills att vi var färdiga." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "JAG ÄR" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DÖD" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "I" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "GEN!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Va? Du igen?" BOX_BREAK UNSKIPPABLE "Du påminner mig om...\n"
"Prinsessan Zelda, på något vis..." BOX_BREAK UNSKIPPABLE "Hmm... Då du verkar ha något form utav band\n"
"till den Kungliga Familjen, så\n"
"ska jag berätta lite mer om oss\n"
"för dig." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Om jag ska vara ärlig, så studerade\n"
"vi var sin visa, en\n"
"för att " COLOR(RED) "åkalla solen" COLOR(DEFAULT) " och en annan för att\n"
COLOR(RED) "åkalla månen" COLOR(DEFAULT) "." BOX_BREAK "Om en medlem utav den Kungliga\n"
"Familjen verkligen har skickat dig, så ska\n"
"jag berätta för dig om forskningens\n"
"resultat." BOX_BREAK "Vi ristade in den i på den " COLOR(RED) "kungliga\n"
"gravstenen" COLOR(DEFAULT) "." BOX_BREAK "Som budbärare för den Kungliga \n"
"Familjen, så bör du visa upp ditt\n"
"Kungliga intyg då du står på \n"
"Trekraftens märke..." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z..." BOX_BREAK "Malon...hur går det...\n"
"Mummel...mummel...\n"
"Ledsen att jag oroar dig..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo tog över Lon Lon-Ranchen och\n"
"bytte namn på den till " COLOR(RED) "Ingos Ranch " COLOR(DEFAULT) "." BOX_BREAK "Jag blev utsparkad, och\n"
"se på mig nu! Min flicka, Malon, \n"
"jobbar fortfarande på ranchen..." BOX_BREAK "Jag oroar mig över henne..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Räddade du Malon? Tack!\n"
"I så fall så går jag tillbaka dit, nu!\n"
"Yeehah!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hallå där grabben!" QUICKTEXT_DISABLE "\n"
"Stöka inte runt bland \n"
"gravarna!" BOX_BREAK UNSKIPPABLE "Mitt namn är " COLOR(RED) "Gravvårdaren Dampé" COLOR(DEFAULT) "!\n"
"Mitt ansikte kan vara läskigt, men jag är\n"
"ingen dålig person..." BOX_BREAK UNSKIPPABLE "Låt mig ge dig lite reklam\n"
"för mitt yrke vid sidan om..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Gravvårdaren Dampés" COLOR(DEFAULT) "\n"
"Hjärtpumpande" COLOR(LIGHTBLUE) " Gravgrävar-rundtur " COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Vad kommer fram?!\n"
"Vad kommer fram?!\n"
"Då jag börjar gräva,\n"
"Låt oss se!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vill du att jag gräver ett hål här?\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " för ett hål.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Gör det inte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Nepp, ingenting här!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Håll dig undan, " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....\n"
"En fruktansvärd sak har inträffat!\n"
"Den " COLOR(RED) "onda skugganden" COLOR(DEFAULT) " har\n"
"släppts lös!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", Kakarikobyns ledare,\n"
"hade förseglat den onda skugganden\n"
"i botten av brunnen...." BOX_BREAK UNSKIPPABLE "Men kraften hos den onda anden\n"
"blev så stark att inseglet i brunnen\n"
"gick sönder, och den rymde ut\n"
"i världen!!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Låt mig ta hand om byn!\n"
"Jag litar på dig,\n"
NAME "!"
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "De Kungliga Kompositörbröderna.\n"
SHIFT("\x37") "Sharp den Äldre\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "De Kungliga Kompositörbröderna.\n"
SHIFT("\x33") "Flat den Yngre\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Kungliga Familjens Grav" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1A") "Den här dikten är tillägnad\n"
"minnet av de medlemmar utav den Kungliga\n"
SHIFT("\x10") "Familjen som ej längre är med oss." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Pojken med den ädla Prinsessan \n"
"Zeldas Okarina...som jag förväntade mig, \n"
"du har kommit." BOX_BREAK UNSKIPPABLE "Jag är " COLOR(RED) "Impa" COLOR(DEFAULT) ", en utav Sheikah.\n"
"Jag är Prinsessan Zeldas tjänare,\n"
"jag är även den Vise som\n"
"vakar över Skuggtemplet."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Var snäll och se efter rinsessan Zelda!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", hjälten!" BOX_BREAK UNSKIPPABLE "Äntligen, så har alla vi " COLOR(RED) "sex Vise" COLOR(DEFAULT) ", \n"
"vaknat upp!\n"
"Striden mot Ondskans Konung\n"
"har äntligen kommit!" BOX_BREAK UNSKIPPABLE "Men först, så bör du träffa\n"
"den som väntar på dig...\n"
BOX_BREAK UNSKIPPABLE "Den som väntar på dig i\n"
COLOR(LIGHTBLUE) "Tidens Tempel" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vi Sheikah har tjänat Hyrules \n"
"kungligheter genom många generationer.\n"
"Fast..." BOX_BREAK UNSKIPPABLE "På den dagen för sju år sedan,\n"
"så attackerade Ganondorf plötsligt...\n"
"och slottet Hyrule gav upp\n"
"kort därefter." BOX_BREAK UNSKIPPABLE "Ganondorfs mål var att få en utav\n"
"nycklarna till det Heliga Kungariket...\n"
"den Kungliga Familjens gömda skatt...\n"
"...Tidsokarinan!" BOX_BREAK UNSKIPPABLE "Min plikt blev att föra Zelda \n"
"dit Ganondorf inte kunde nå henne." BOX_BREAK UNSKIPPABLE "När jag senaste såg dig, då\n"
"vi flydde ut ur slottet, så var du\n"
"bara en liten pojke..." BOX_BREAK UNSKIPPABLE "Jag kan nu se att du har blivit \n"
"en fin hjälte..."
)


DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag måste stanna här... Gå till \n"
"Prinsessan Zeldas sida och beskydda \n"
"henne även för min del." BOX_BREAK UNSKIPPABLE "Jag fyller denna " COLOR(BLUE) "Medalj" COLOR(DEFAULT) ",\n"
"med mina krafter, mitt hopp är att de\n"
"ska hjälpa dig!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hur mår din Cucco? Är han glad?\n"
"Ska jag se över honom åt dig?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Jag är " COLOR(RED) "chef över dessa hantverkare\n"
COLOR(DEFAULT) "den där Impa har hyrt in oss för att\n"
"förbättra den här byn och göra den till en riktig\n"
"stad!" BOX_BREAK UNSKIPPABLE "Men dagens ungdom har ingen\n"
"riktig ambition...\n"
"Förstår du vad jag menar grabben?" BOX_BREAK UNSKIPPABLE "Mina arbetare springer bara\n"
"runt i byn hela dagarna, och\n"
"de gör inga riktiga framsteg över\n"
"huvudtaget..." BOX_BREAK UNSKIPPABLE "Till och med min son är \n"
"arbetslös, han gör inget vettigt\n"
"om dagarna!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "De är helt värdelösa allihop\n"
"ska du veta!!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se på den där stackars flickan där borta.\n"
"Hon jobbar så hårt med att ta hand om sina \n"
"höns trots att hon får gåshud av att bara\n"
"röra vid dem..." BOX_BREAK "Vilken kämpe! Jag vill \n"
"verkligen hjälpa henne! Den senaste tiden \n"
"så har jag känt mig så välvillig!\n"
"Känner du precis likadant?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Det finns inget att oroa sig över...\n"
"Prinsessan är i säkerhet nu."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Snart så träffar du Prinsessan Zelda\n"
"öga mot öga, och då kommer hon att\n"
"förklara allt..." BOX_BREAK UNSKIPPABLE "Det är då som vi, de sex Vise, \n"
"kommer att försegla den Onde Konungen\n"
"och återställa freden i Hyrule."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe, unge man...\n"
"Du var väldigt kvick som hängde\n"
"med i mina takter! Hehehe!" BOX_BREAK UNSKIPPABLE "Som belöning, så ska jag ge dig\n"
"min skatt. Den kallas för\n"
COLOR(RED) "Krokskottet" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Det är en fjäderladdad kedja som\n"
"kan dra dig mot en punkt där kroken\n"
"fastnar. Låter inte det häftigt?\n"
"Jag är säker på att den kommer att hjälpa dig!" BOX_BREAK UNSKIPPABLE "Jag bor här nu, så kom tillbaka\n"
"igen någon dag. Jag ger dig\n"
"Någonting häftigt!" BOX_BREAK UNSKIPPABLE "En sak till! Var försiktig\n"
"på din väg tillbaka!\n"
"Heheheh...."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du är tillbaka, unge man...\n"
"Var presenten du fick rolig\n"
"och användbar?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "Din tid för detta loppet var\n"
SHIFT("\x4B")  RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Verkar som att du fixar detta..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Jag tror att Impa har gått till \n"
COLOR(PURPLE) "Skuggtemplet " COLOR(DEFAULT) "för att försegla det igen,\n"
"men...hon är i fara om hon inte får \n"
"någon hjälp!" BOX_BREAK UNSKIPPABLE  NAME "!\n"
"Impa är en utav de sex Vise.\n"
"Besegra den onda skugganden och\n"
"rädda Impa!" BOX_BREAK UNSKIPPABLE "Där finns en ingång till \n"
"Skuggtemplet under kyrkogården \n"
"här bakom byn." BOX_BREAK UNSKIPPABLE "Det enda jag kan göra för dig är\n"
"att lära dig den visa som ska\n"
"leda dig till Skuggtemplet..." BOX_BREAK UNSKIPPABLE "Denna visa är gjord för att\n"
"dra dig ned i ett oändligt mörker \n"
"som även uppslukar tid... Lyssna noga nu \n"
"till " COLOR(PURPLE) "Skuggors Nokturne" COLOR(DEFAULT) "!!"
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Snurra runt! Snurra runt runt runt\n"
"och runt igen! Åh så kul! Jag är så \n"
"glad!" BOX_BREAK "Jag är en musikens man\n"
"som tycker om att snurra runt runt!\n"
"Snurra runt runt!!!" BOX_BREAK "Jag försöker att komma på ett\n"
"musikaliskt tema baserat på den här \n"
"vädekvarnen...som snurrar runt runt\n"
"runt och runt igen!!!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Snurra runt, snurra runt, snurrar runt...\n"
"Va? Nu går det alldeles för fort!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!" BOX_BREAK "Jag kommer aldrig att glömma vad som\n"
"hände den dagen, för sju år sedan!\n"
"Grrrrrrrrr!" BOX_BREAK "Allt är den där Okarinakillens fel!\n"
"Nästa gång som han kommer hit,\n"
"så ska jag spöa upp honom ordentligt!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Va?! Du har en okarina!!" BOX_BREAK UNSKIPPABLE "Vad sjutton!" BOX_BREAK UNSKIPPABLE "Det påminner mig om den där gången\n"
"för sju år sedan!" BOX_BREAK UNSKIPPABLE "Det var en elak liten kille som kom hit \n"
"och spelade en " COLOR(PURPLE) "konstig visa" COLOR(DEFAULT) ".\n"
"Väderkvarnen blev helt tokig efter det!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vad ska jag göra!?\n"
"Mina " COLOR(RED) "Cuccos" COLOR(DEFAULT) " har flugit iväg allihop!" BOX_BREAK "Du, lilla pojke, snälla!\n"
"Snälla hjällp mig att samla in dem \n"
"till hönsgården igen!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mina Cuccos har rymt!\n"
"Snälla hjälp mig att samla in de \n"
"fyra andra till hönsgården igen!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mina Cuccos har rymt!\n"
"Snälla hjälp mig att samla in de \n"
"tre andra till hönsgården igen!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mina Cuccos har rymt!\n"
"Snälla hjälp mig att samla in de \n"
"två sista till hönsgården igen!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mina Cuccos har rymt!\n"
"Snälla hjälp mig att samla in den \n"
"sista utav dem till hönsgården igen!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tack för att du hittade mina Cuccos.\n"
"Jag är allergisk, så jag får \n"
"gåshud bara jag rör vid dem." BOX_BREAK UNSKIPPABLE "Som tack, så ger jag den här\n"
"till dig. Det är jättefint glas, och borde\n"
"komma till användning. Ta väl\n"
"hand om den!" EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallå, vad håller du på med?!\n"
"Se till att samla in dem eller \n"
"betala för dem!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Reta inte mina Cucco är du snäll!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Jag har avlat fram en ny typ utav \n"
"Miniatyr-Cucco! Jag kallar den för en " COLOR(RED) "Fick-\n"
"Cucco" COLOR(DEFAULT) "! Jag får inte gåshud utav\n"
"den här skönheten." BOX_BREAK UNSKIPPABLE  COLOR(RED) "En Cucco " COLOR(DEFAULT) "blir väldigt lätt \n"
"lat, så de vaknar ofta mycket sent.\n"
"Har du inte hört talas om dem \n"
"tidigare?" BOX_BREAK UNSKIPPABLE "De blir väldigt glada av att gala:\n"
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(RED) "CUCKOOO" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"speciellt då de väcker folk som sover \n"
"väldigt tungt!" BOX_BREAK UNSKIPPABLE "Fast, min Cucco är inte riktigt glad\n"
"för tillfället..." BOX_BREAK UNSKIPPABLE "Du..., \n"
"Du ser ut som att du är bra på att \n"
"handskas med Cucco." BOX_BREAK UNSKIPPABLE "Här, ta det här ägget.\n"
"Efter att Cuccon kläcks, så ta den \n"
"hit till mig så kan jag kolla \n"
"hur den mår." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vad tror du? \n"
"Vill du försöka?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Åh, rackarns...blev du pickad\n"
"utav en Cucco då du var liten?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh, unge man!\n"
"Är du snabb på foten?" BOX_BREAK "Det kanske inte verkar så, men jag \n"
"är väldigt snabb!\n"
"Vad sägs om att vi tävlar! \n"
"Följ mig om du vågar!"
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Snälla gör min Cucco glad!\n"
"Okej?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Åh, din Cucco verkar hyffsat \n"
"glad! Han måste ha väckt en riktigt\n"
"lat person!" BOX_BREAK UNSKIPPABLE "Du är en väldigt bra Cuccoägare!\n"
"Jag ska ge dig en ovanlig, värdefull\n"
"Cucco, om du är intresserad..." BOX_BREAK UNSKIPPABLE "Dess namn är " COLOR(RED) "Cojiro" COLOR(DEFAULT) "," COLOR(RED) " " COLOR(DEFAULT) "och den brukade\n"
"vara min brors Cucco. Dess\n"
"blå kropp är ganska charmerande.\n"
"Den är så söt!" BOX_BREAK UNSKIPPABLE "Sedan min bror lämnade, \n"
"det är märkligt, men Cojiro har \n"
"helt slutat gala." TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vill du ha " COLOR(RED) "Cojiro" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det verkar som att du verkligen tycker om\n"
"din andra Cucco. Okej, du kan behålla den\n"
"ett tag." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Det är en gammal häxa som har Brygdbutiken\n"
"här bakom. Du kan ta dig till dit \n"
"genom dörren till vänster\n"
"om disken." EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Min bror måste ha varit väldigt \n"
"ensam..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag hörde att den " COLOR(ADJUSTABLE) "Förlorade Skogen" COLOR(DEFAULT) ", \n"
"där älvorna lever, är en märklig\n"
"plats med många mysteriska dofter." BOX_BREAK "Jag önskar att jag i alla fall \n"
"en gång kunde göra medicin utav de\n"
"märkliga saker jag kan hitta där..." BOX_BREAK "Jag kanske inte ser så bra \n"
"längre, men min näsa fungerar \n"
"fortfarande fint!  Hehehe!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sniff sniff sniff..." BOX_BREAK "Vad är det som luktar så konstigt..." BOX_BREAK "Vad har du i fickan?!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That uslingen! Han var bara tvungen \n"
"att gå in i skogen...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "Jag förstår." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hall dår, ge mig den på en gång!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja\n"
"Nej" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Så sorgligt... Jag behöver bara lite..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Om du ser den dåren, så ge detta till \n"
"honom. Det är den starkaste medicin\n"
"jag någonsin har skapat." BOX_BREAK UNSKIPPABLE "Fast, den här brygden funkar\n"
"inte på ett monster..." EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallå, grabben! Om du vill bära runt på \n"
"medicin, så behöver du en behållare\n"
"att ha den i!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Det sägs att ingen medicin \n"
"kan bota en dåre...\n"
"Jag antar att det stämmer..."
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag kan inte komma ned, så det enda jag kan\n"
"göra är att titta på " COLOR(RED) "Dödens Berg" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag kan inte komma ned, så det enda jag kan\n"
"göra är att titta på stjärnorna."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kan du se det där nedifrån? \n"
"Någonting håller på att hända på " COLOR(RED) "Dödens \n"
"Berg" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kan du se det därifrån?\n"
COLOR(RED) "Döda Berget " COLOR(DEFAULT) "är tillbaka som vanligt!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jag har ingen lust att komma ned,\n"
"någonsin! Vad som än händer, så kommer\n"
"jag fortsätta att titta på Dödens Berg \n"
"här uppifrån."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hej! Kul att se dig igen! Du får\n"
"den här utav mig som ett minne."
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"För att få en bra överblick, använd " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " och \n"
"se dig omkring med " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du! Grabben, brukar du alltid gå in\n"
"i folks hus utan tillåtelse? \n"
"Har inte dina föräldrar \n"
"uppfostrat dig ordentligt?" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Strunt samma." BOX_BREAK UNSKIPPABLE "Har du sett en kvinna bakom detta \n"
"huset? Hon har det väldigt tufft \n"
"just nu." BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Jaja..." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Om den kvinnan frågar dig om höns, \n"
"så bör du se till att lyssna på henne."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tycker du att det är roligt att\n"
"stövla in i folks hus mitt i natten? \n"
"Du måste ha haft en riktigt \n"
"bedrövlig uppväxt." BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Jaja..." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den där kvinnan tar hand om höns,\n"
"men faktum är, att hon är allergisk \n"
"mot dem." BOX_BREAK SHIFT("\x42") "Jaja..."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallå! Unge man! en stor pojke\n"
"som du borde veta bättre än att gå in i\n"
"folks hus utan tillåtelse?! Jag vill tala\n"
"med dina föräldrar!" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Jaja." BOX_BREAK UNSKIPPABLE "Det är inte mitt hus ändå.\n"
"Detta är den " COLOR(RED) "stora Impas" COLOR(DEFAULT) " hus!" BOX_BREAK UNSKIPPABLE "Den stora Impa har gått till\n"
COLOR(RED) "kyrkogården " COLOR(DEFAULT) "för att försegla \n"
"en enorm varelse där." BOX_BREAK UNSKIPPABLE "Sedan Ganondorf dök upp, så har \n"
"mycket monster siktats \n"
"här omkring." BOX_BREAK UNSKIPPABLE "Vi har den stora Impa att \n"
"tacka för den frid som råder här.\n"
"Tänk på det, unge man!" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Jaja." BOX_BREAK UNSKIPPABLE "Då vi talar om den Stora Impa, hon\n"
"har ännu inte kommit tillbaka. Jag undrar \n"
"vad som hänt henne?" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jag hörde att " COLOR(RED) "gravvårdarens\n"
"spöke " COLOR(DEFAULT) "ofta kommer fram på \n"
"kyrkogården bakom byn..." BOX_BREAK SHIFT("\x34") "Men, vem bryr sig?"
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hej pojke! Är det första gången\n"
"du besöker den här byn?" BOX_BREAK UNSKIPPABLE "En stor kvinna, " COLOR(RED) "Impa" COLOR(DEFAULT) ", öppnade upp\n"
"den här byn för oss\n"
"stackars fattiga." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Så, känn dig som hemma.\n"
"Maten är inte klar än dock."
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den stora Impa är inte här. Har\n"
"någonting hänt henne?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Alla har någon gång varit med \n"
"om tuffa saker i sitt liv som de\n"
"inte vill att andra ska känna till." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se bara på den skäggiga gubben\n"
"som sover där borta. Jag slår vad\n"
"om att även han har varit med om\n"
"något tufft i sitt liv..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Den där skäggiga gubben återvände \n"
"till ranchen. Han såg väldigt glad ut!"
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ding dong, ding dong!\n"
"I'm a clock soldier of Kakariko!\n"
"The current time is: " TIME "." BOX_BREAK UNSKIPPABLE "Hello there, son.\n"
"Zelda's attendant, the great " COLOR(RED) "Impa" COLOR(DEFAULT) ",\n"
"opened this village to the common\n"
"people." BOX_BREAK UNSKIPPABLE "We have only a small population \n"
"now, but someday this place will \n"
"be as lively as Hyrule Castle \n"
"Town! Oh, yes! It will!" BOX_BREAK UNSKIPPABLE "Climb up the " COLOR(RED) "stairs at the north\n"
COLOR(DEFAULT) "end of the village to find the trail\n"
"that leads up Death Mountain." BOX_BREAK UNSKIPPABLE "But you need the King's permission\n"
"to actually go up the mountain."
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"The current time is: " TIME "."
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"The current time is: " TIME ".\n"
"By the way, do you know what \n"
"happened in the castle?"
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, son, what are you doing \n"
"wandering around this late at \n"
"night?" BOX_BREAK UNSKIPPABLE "Oh, I get it. You're testing your\n"
"courage, aren't you? You must \n"
"want to go to...a graveyard!" BOX_BREAK UNSKIPPABLE "Wait a minute! What am I doing\n"
"talking to a kid? I've got work to\n"
"do! Work! Work!" TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"The current time is: " TIME "." BOX_BREAK "Head east and you'll find a\n"
COLOR(RED) "graveyard" COLOR(DEFAULT) ". Legends say you can \n"
"calm the souls of the dead with\n"
"an " COLOR(BLUE) "old song of the Royal Family" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"There's a strange guy living in the \n"
"Windmill. Have you already met\n"
"him, Mr. Hero?"
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"People are disgusting. \n"
"My own father and mother are\n"
"disgusting.\n"
"You must be disgusting, too!"
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All day long, we are working on \n"
"many construction projects in the\n"
"village. It's going to take awhile\n"
"before everything is done." BOX_BREAK "Our boss works us very hard!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I'm starving!\n"
"Let's eat dinner, right now!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Those guys each do the work of \n"
"half a man, but they still want a\n"
"full man's portion!\n"
"They're lazy slackers, I tell you!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poe   30 Rupees\n"
COLOR(DEFAULT) "This is a bottled ghost spirit. \n"
"Sell it to someone who is crazy \n"
"about weird things like this." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poe  30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Cuccos have run away!\n"
"Please catch six more!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME "!\n"
"This ship is sinking!\n"
"Abandon ship!\n"
"Get onto a safe platform!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm still missing some Cuccos!\n"
"Please round up five more!"
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Don't cause trouble!\n"
"I'll tell Dampé!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Look at this, kid! My beautiful,\n"
"smooth hands are all worn out \n"
"from working. Sob sob..."
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A job where you can make a lot\n"
"of money without much effort...\n"
"The only thing I can think of is\n"
"thievery... Is that a bad idea?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I heard that our boss's house is\n"
"just behind this house. He doesn't\n"
"want any of us to know, though."
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Have you seen " COLOR(RED) "Mr. Dampé" COLOR(DEFAULT) ", who\n"
"lives in the graveyard up ahead?" BOX_BREAK "It's " TIME " right now, so he's\n"
"probably asleep in his hut." BOX_BREAK "Why don't you go out onto the \n"
"field and kill some time?"
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I'm starving!\n"
"Isn't dinner ready yet?\n"
"It's " TIME " already!"
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "This used to be the " COLOR(RED) "great \n"
"Impa's house" COLOR(DEFAULT) ", but she doesn't\n"
"live here any longer." BOX_BREAK UNSKIPPABLE "It is now open to all \n"
"villagers. You are free to\n"
"go on in." TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This village used to be a \n"
COLOR(BLUE) "Shiekah " COLOR(DEFAULT) "village, but the \n"
"great Impa opened it to \n"
"everyone."
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I tell you, I saw him!" BOX_BREAK "I saw the ghostly figure of Dampé\n"
"the gravekeeper sinking into\n"
"his grave. It looked like he was\n"
"holding some kind of " COLOR(RED) "treasure" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"There he is! It's him!\n"
"He's the one who dropped from\n"
"the sky surrounded by a blue\n"
"light!" BOX_BREAK "Now do you believe me?"
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nobody believes what I've been\n"
"telling them all these past \n"
"seven years!"
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The fire almost consumed us all!\n"
"But together, we all were able to\n"
"put out the fire! Pretty good\n"
"work, don't you think?"
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!" BOX_BREAK "Look at this guy! Ever since\n"
"he escaped from Hyrule Castle\n"
"Town, he's become even more\n"
"timid!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!" BOX_BREAK "He must have been seeing things!\n"
"Wah hah hah hah hah hah!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah hah hah hah hah hah!\n"
"Those are some funny-looking\n"
"clothes, man!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah hah hah hah hah hah!\n"
"When times are tough, laughter is\n"
"the best medicine!\n"
"That's what my dad always said!"
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Look at me! I'm on top of the \n"
"world! It really bothers me to see\n"
"anyone at a higher level than I\n"
"am! I have to be on top!"
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If I fall asleep up here, I'll\n"
"surely fall down..."
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The windmill draws water up from \n"
"the depth of the well." BOX_BREAK "Now the well is dried up, though.\n"
"Hrrrrm..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"The lady here is really\n"
"generous. She even took care of\n"
"the carpenters when they were\n"
"here!"
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A long time ago...\n"
"There was a man in this very\n"
"village who had an eye they said\n"
"could see the truth!" BOX_BREAK "Now usually, you have to train\n"
"your mind's eye most strenuously\n"
"to actually see the truth..." BOX_BREAK "But this fella, no, they say he\n"
"had a different way of doing\n"
"things..." BOX_BREAK "His house stood where the well is\n"
"now..."
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Folks around here tell of a\n"
COLOR(RED) "fabulously rich family " COLOR(DEFAULT) "that once\n"
"lived in one of the houses in this\n"
"village..." BOX_BREAK "But they say that the entire\n"
"family was cursed due to their\n"
"greed!" BOX_BREAK "Who knows what might happen to\n"
"those who are consumed by\n"
"greed..."
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh...." BOX_BREAK "What an annoying person,\n"
"interrupting us like this...\n"
"Don't you agree, my love?"
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee..." BOX_BREAK "Violating our personal space!\n"
"He must have something better\n"
"to do...\n"
"Don't you agree, darling?"
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Look at him...the man with the\n"
"beard. I think he was fired from\n"
"his job at the ranch..." TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"He's always just lazing around, \n"
"morning, noon and night. \n"
"He's an awfully carefree guy \n"
"during such hard times."
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"That lazy man, he kind of \n"
"reminded me of my little Richard..." BOX_BREAK "What's that? You say you've\n"
"never heard of my little Richard?\n"
"He was such a famous puppy! You \n"
"seriously haven't heard of him?"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, no! A storm again!!\n"
"You played the Ocarina again,\n"
"didn't you!!\n"
"Grrrrrrrrrrrrrrr!!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You caught a Big Poe!\n"
"Sell it at the " COLOR(RED) "Ghost Shop " COLOR(DEFAULT) "for a\n"
"lot of money!"
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Halt! Stay where you are!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, newcomer!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, newcomer! Wait a second \n"
"and I'll open the gate for you."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Don't take us so lightly!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I've seen your fine work. To get \n"
"past the guards here, you must \n"
"have good thieving skills." BOX_BREAK UNSKIPPABLE "I used to think that all men, \n"
"besides the great Ganondorf, were \n"
"useless...but now that I've seen\n"
"you, I don't think so anymore!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "The exalted Nabooru" COLOR(DEFAULT) ", our leader, \n"
"put me in charge of this fortress." BOX_BREAK UNSKIPPABLE "Nabooru is the second-in-command\n"
"to the great Ganondorf, King of \n"
"the Gerudo Thieves." BOX_BREAK UNSKIPPABLE "Her headquarters are in the " COLOR(YELLOW) "Spirit\n"
"Temple" COLOR(DEFAULT) ", which is at the end of the\n"
"desert." BOX_BREAK UNSKIPPABLE "Say, you must want to become \n"
"one of us, eh?\n"
"All right, then!\n"
"You're in from now on!" BOX_BREAK UNSKIPPABLE "Take this. With it, you will\n"
"have free access to all areas of\n"
"the fortress!" EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"From now on, you're free to come\n"
"and go as you please through the \n"
"gate to the desert." BOX_BREAK "You'll find the " COLOR(YELLOW) "Spirit Temple" COLOR(DEFAULT) "," COLOR(YELLOW) " \n"
COLOR(DEFAULT) "where the exalted Nabooru lives,\n"
"out there in the desert."
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Stupid Kid!" QUICKTEXT_DISABLE "\n"
"Get in there and keep quiet!"
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I have no idea where you \n"
"come from, but you must have a\n"
"lot of guts to make it past all\n"
"the guards around here!" BOX_BREAK UNSKIPPABLE "All of my fellow carpenters\n"
"are imprisoned somewhere in here." BOX_BREAK UNSKIPPABLE "If you can get us out of here,\n"
"we'll repay the favor somehow!" BOX_BREAK UNSKIPPABLE "But be careful! There're sure\n"
"to be " COLOR(RED) "Gerudo " COLOR(DEFAULT) "guards somewhere \n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "around" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "here" QUICKTEXT_DISABLE "...." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Woo!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Watch out!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "The Entrance to the Past" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "The Entrance to the Present" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "The Entrance to the Future" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\xEC") "I'll be your guide on your way,\n"
"but coming back, I won't play!\n"
"I'll show you the only way to go,\n"
"so follow me and don't be slow!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Past, present, future..." BOX_BREAK UNSKIPPABLE "The Master Sword is a ship with \n"
"which you can sail upstream and\n"
"downstream through time's river..." BOX_BREAK UNSKIPPABLE "The port for that ship is in the\n"
"Temple of Time..." BOX_BREAK UNSKIPPABLE "To restore the Desert Colossus\n"
"and enter the " COLOR(YELLOW) "Spirit Temple" COLOR(DEFAULT) ", you\n"
"must travel back through time's\n"
"flow..." BOX_BREAK UNSKIPPABLE "Listen to this " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "...\n"
"This melody will lead a child back\n"
"to the desert."
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I am the Gerudo master of \n"
"horseback archery! On top of \n"
"that, I'm the Gerudo master of\n"
"horseback riding!" BOX_BREAK "Want to try horseback archery\n"
"for " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You have guts--I like you. \n"
"Follow me."
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It's out of the question if you \n"
"don't have a horse!"
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "I won't have anything to do with a\n"
"coward like you!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, you are not as good as you \n"
"claim. Maybe next time."
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You did well." BOX_BREAK "For today, I admit I lost. \n"
"It seems I have a lot of room for \n"
"improvement."
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is the Gerudo's " COLOR(RED) "Training \n"
"Ground" COLOR(DEFAULT) "." BOX_BREAK "Nobody is allowed to enter \n"
"without a membership card."
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is the Gerudo's " COLOR(RED) "Training\n"
"Ground" COLOR(DEFAULT) "." BOX_BREAK "Membership card verified." BOX_BREAK "One try for 10 Rupees!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Try\n"
"Don't try" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All right, I'll take your 10 Rupees.\n"
"Give it your best shot!" EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You don't have enough money!\n"
QUICKTEXT_ENABLE "Come back again." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, rookie!" BOX_BREAK UNSKIPPABLE "Are you going into the desert?\n"
"I'll open this gate for you, but..." BOX_BREAK UNSKIPPABLE "You can't cross the desert \n"
"unless you pass the " COLOR(RED) "two trials" COLOR(DEFAULT) "." TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The first trial is...the " COLOR(RED) "River of \n"
"Sand" COLOR(DEFAULT) "! You can't walk across this\n"
"river! After you cross it, follow\n"
"the flags we placed there." BOX_BREAK "The second trial is...the " COLOR(RED) "Phantom\n"
"Guide" COLOR(DEFAULT) "!" BOX_BREAK "Those without " COLOR(RED) "eyes that can see\n"
"the truth " COLOR(DEFAULT) "will only find themselves\n"
"returning here." BOX_BREAK "You are going anyway, aren't you?\n"
"I won't stop you...\n"
"Go ahead!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Why did you come all the\n"
"way down here? What? You were\n"
"just about to ask me the same \n"
"thing?" TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well, now that you're down here, \n"
"you may as well make the best of \n"
"things!"
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Good kid! Thanks!\n"
"I'm sorry that I can't give you\n"
"something as good in return, but...\n"
"take this anyway!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I haven't seen you around, kid..." BOX_BREAK "What do you want?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "To see the temple\n"
"Looking for the Sages\n"
"Nothing, really" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're just a kid! The temple is\n"
"no place for kids!"
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A Sage? I don't know anyone\n"
"like that."
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You have nothing to do? What \n"
"good timing! Can you do me a \n"
"favor, kid?" BOX_BREAK UNSKIPPABLE "Wait a second, I want to ask you\n"
"first--you wouldn't happen to be\n"
"one of Ganondorf's..." BOX_BREAK "followers...would you?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "What if I am?\n"
"I hate Ganondorf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha!\n"
"Don't try to act cool, kid.\n"
"I was just asking!" BOX_BREAK UNSKIPPABLE "A kid like you could never be\n"
"one of Ganondorf's followers!" BOX_BREAK UNSKIPPABLE "Well, let's cut to the chase..." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uh-huh!" BOX_BREAK UNSKIPPABLE "You've got guts.\n"
"I think I like you." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "First of all, let me introduce \n"
"myself. I'm " COLOR(RED) "Nabooru " COLOR(DEFAULT) "of the Gerudo.\n"
"I'm a lone wolf thief." BOX_BREAK UNSKIPPABLE "But don't get me wrong!" BOX_BREAK UNSKIPPABLE "Though we're both thieves, I'm \n"
"completely different from\n"
"Ganondorf." BOX_BREAK UNSKIPPABLE "With his followers, he stole\n"
"from women and children, and he \n"
"even killed people!" BOX_BREAK UNSKIPPABLE "A kid like you may not know this, \n"
"but the Gerudo race consists only\n"
"of women. Only one man is born\n"
"every hundred years..." BOX_BREAK UNSKIPPABLE "Even though our laws say that\n"
"lone male Gerudo must become\n"
"King of the Gerudo, I'll never\n"
"bow to such an evil man!" BOX_BREAK UNSKIPPABLE "By the way, what is your name, \n"
"kid?" BOX_BREAK UNSKIPPABLE  NAME "?!" BOX_BREAK UNSKIPPABLE "What kind of name is that?\n"
"Well...anyway..." TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I want to ask you a favor..." BOX_BREAK UNSKIPPABLE "Will you go through this tiny hole\n"
"and get a treasure that's inside?" BOX_BREAK UNSKIPPABLE "The treasure is the " COLOR(BLUE) "Silver\n"
"Gauntlets" COLOR(DEFAULT) ". If you equip them, you\n"
"can easily push and pull very \n"
"heavy things!" BOX_BREAK UNSKIPPABLE "No, no, no, kid! Don't even think\n"
"about taking this treasure for \n"
"yourself!" BOX_BREAK UNSKIPPABLE "The Silver Gauntlets won't fit a\n"
"little kid like you if you try to \n"
"equip them! I want you to be a \n"
"good boy and give them to me!" BOX_BREAK UNSKIPPABLE "Ganondorf and his minions are\n"
"using the Spirit Temple as a \n"
"hideout." BOX_BREAK UNSKIPPABLE "Only the Silver Gauntlets will \n"
"allow me to sneak deep into the\n"
"temple." BOX_BREAK UNSKIPPABLE "Once there, I'm going to steal all\n"
"the treasure inside and mess up\n"
"their plans!" BOX_BREAK "How about it? Will you do it?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Thanks, kid!" BOX_BREAK UNSKIPPABLE "You and I, let's give Ganondorf\n"
"and his followers a big surprise,\n"
"shall we?" TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you can successfully get the \n"
COLOR(BLUE) "Silver Gauntlets" COLOR(DEFAULT) "..." BOX_BREAK "I'll do something great" COLOR(RED) " " COLOR(DEFAULT) "for you!"
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well, what did I expect?\n"
"After all, you're just a kid!"
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey! Where are you taking me?!"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ho ho ho!\n"
"Looks like someone is here, Koume."
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hee hee hee!\n"
"Looks like it, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "What an outrageous fellow he is,\n"
"to intrude so boldly into our \n"
"Temple...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "We should teach this outrageous\n"
"fellow a lesson!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, loyal minion..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Destroy this intruder on \n"
"our behalf!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Great Ganondorf's...Enemy...\n"
"Must die..."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Unnnh...\n"
"Where am I...?"
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Well, well...\n"
"Looks like she's back to normal...\n"
"Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "She's just a little girl,\n"
"but she commands a lot of \n"
"respect among the Gerudo, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Maybe we should make her work\n"
"for the great Ganondorf for\n"
"a little while longer!\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Then we should brainwash her\n"
"again!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kid, let me thank you." BOX_BREAK UNSKIPPABLE "Heheheh...look what the little\n"
"kid has become in the past seven\n"
"years--a competent swordsman!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
"If only I knew you would become \n"
"such a handsome man..." BOX_BREAK_DELAYED("\x50") "I should have kept the promise\n"
"I made back then..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Here, I'll give you " COLOR(RED) "this" COLOR(DEFAULT) "...\n"
"It's a very important thing to me.\n"
"Let's have a competition later!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...see you again!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "By the way..." BOX_BREAK UNSKIPPABLE "I really messed up..." BOX_BREAK UNSKIPPABLE "I was brainwashed by those old\n"
"witches and used by Ganondorf to\n"
"do his evil will..." BOX_BREAK UNSKIPPABLE "But isn't it funny? That a person\n"
"like me could turn out to be the\n"
COLOR(YELLOW) "Sage of Spirit" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "And now, I'm going to fight\n"
"them as one of the six Sages!\n"
"Heh heh..." BOX_BREAK UNSKIPPABLE "I'm going to pay them back for\n"
"what they did to me!"
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kid..." BOX_BREAK UNSKIPPABLE "No...\n"
NAME ", the Hero of Time!" BOX_BREAK UNSKIPPABLE "Instead of keeping the promise I\n"
"made back then, I give you this\n"
COLOR(YELLOW) "Medallion" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Take it!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x12") "Yeearggh!" QUICKTEXT_DISABLE " Let me go!!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x33") "You, " QUICKTEXT_ENABLE "you fiends!" QUICKTEXT_DISABLE "\n"
SHIFT("\x29") "Ganondorf's minions!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x20") "Get out of here! Now!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0C") "These witches! They're using\n"
SHIFT("\x2B") "black magic on me!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, newcomer! This is our \n"
COLOR(RED) "horseback archery field" COLOR(DEFAULT) "." BOX_BREAK "After a lot of hard practice and\n"
"training, we finally have the skill\n"
"to hit the bull's-eye while riding\n"
"like the wind!" BOX_BREAK "When you finally learn how to ride\n"
"a horse, you should come back\n"
"and try it. It's a dangerous sport,\n"
"but it's fun!"
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey newcomer, you have a fine \n"
"horse!" BOX_BREAK "I don't know where you stole \n"
"it from, but..." BOX_BREAK "OK, how about challenging this \n"
COLOR(RED) "horseback archery" COLOR(DEFAULT) "?" BOX_BREAK "Once the horse starts galloping,\n"
"shoot the targets with your\n"
"arrows. " BOX_BREAK "Let's see how many points you \n"
"can score. You get 20 arrows." BOX_BREAK "If you can score " COLOR(RED) "1,000 points" COLOR(DEFAULT) ", I\n"
"will give you something good!" EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you want to try for " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, rookie!\n"
"You're looking good!\n"
"Show me your skill again!" BOX_BREAK "You should set a new goal of\n"
COLOR(RED) "1,500 points" COLOR(DEFAULT) " and try again!" EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What? Do you want to try again?\n"
"Looks like you have some\n"
"potential!" EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'll be darned! You are the ultimate\n"
"master!" BOX_BREAK "I will give you an item suitable\n"
"for the master." BOX_BREAK "This quiver is very important to \n"
"me. I want you to have it.\n"
"Take good care of it, OK?"
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " points...Hmm...\n"
"Wha-ha-ha! You have plenty of \n"
"room for improvement!" EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantastic!\n"
"You are a true master!" BOX_BREAK "I will give this to you.\n"
"Keep improving yourself!"
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " points...\n"
"Quite impressive!" EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Look at that stupid kid!\n"
"He came on his own to offer \n"
"himself as a sacrifice to the\n"
"great Ganondorf..." FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x05") "With my flame, I will burn him to\n"
SHIFT("\x46") "the bone!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"With my frost, I will freeze him to\n"
SHIFT("\x46") "his soul!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x1C") "Shoot, what a fresh kid!\n"
SHIFT("\x15") "This time, we'll get serious,\n"
SHIFT("\x3C") "right Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "What?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x0A") "Hey, Koume, what is that above\n"
SHIFT("\x41") "your head?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0B") "I don't know, but you have one\n"
SHIFT("\x14") "over your head too, Kotake!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "But I'm only 400 years old!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "And I'm just 380 years old!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x0C") "We're twins! Don't try to lie\n"
SHIFT("\x35") "about your age!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x06") "You must have gone senile!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Who are you calling senile?!\n"
SHIFT("\x16") "Is that how you treat your\n"
SHIFT("\x3D") "older sister?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x36") "We are twins! \n"
SHIFT("\x26") "How can you be older?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Keeeyaaah!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x20") "How heartless you are!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x12") "How can you be so ungrateful?" QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x35") "You're heartless!!" QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x33") "You ungrateful..." QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "I'll come back to haunt you!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OK, let's get serious now, Kotake!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x37")  QUICKTEXT_ENABLE "Oh, OK, Koume." QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x14")  SHIFT("\x30")  QUICKTEXT_ENABLE "Kotake" QUICKTEXT_DISABLE " and " QUICKTEXT_ENABLE "Koume's" QUICKTEXT_DISABLE "\n"
SHIFT("\x1C")  QUICKTEXT_ENABLE "Double" QUICKTEXT_DISABLE " Dynamite " QUICKTEXT_ENABLE "Attack!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Did you come here to save me? \n"
"Oh, that's just swell! I'm " COLOR(RED) "Ichiro\n"
"the carpenter" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "We were really interested in \n"
"joining their all-female group, but \n"
"they locked us up like this just\n"
"because we're men!" BOX_BREAK UNSKIPPABLE "We don't care about the Gerudo \n"
"anymore! They're so rude!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Three of my fellows" COLOR(DEFAULT) " have also \n"
"been captured, so please help \n"
"them escape, too!"
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You're a cute kid! Thank you for\n"
"coming to save me! I'm " COLOR(RED) "Jiro, the \n"
"carpenter" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "These women are so scary! I'd\n"
"rather work as a carpenter than\n"
"join them!" BOX_BREAK UNSKIPPABLE "I can't wait to say good-bye to\n"
"this place! " COLOR(RED) "Two of my buddies " COLOR(DEFAULT) "\n"
"are still being held prisoner. Will\n"
"you please get them out, too?"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Thanks, boy! You're fantastic!\n"
"I'm " COLOR(RED) "Sabooro, the carpenter" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Have you seen our boss, boy?\n"
"He's probably worried about me!\n"
"I have to get back to him \n"
QUICKTEXT_ENABLE "immediately!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  COLOR(RED) "One more of our workers " COLOR(DEFAULT) "is still\n"
"a prisoner. Please save him!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I was afraid you were going to \n"
"forget about me! Now I'm free!\n"
"Thanks! I'm " COLOR(RED) "Shiro the carpenter" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "For rescuing me, I'll tell you\n"
"something interesting about the\n"
"desert that I overheard the\n"
"Gerudos talking about." BOX_BREAK UNSKIPPABLE "They said, \"In order to cross the\n"
"Haunted Wasteland, you'll need the\n"
"'" COLOR(RED) "eye of truth" COLOR(DEFAULT) ".' The Colossus is on\n"
"the far side of the wasteland...\"" BOX_BREAK UNSKIPPABLE "OK, now I'm going back to my\n"
COLOR(RED) "tent near Gerudo Valley" COLOR(DEFAULT) ", so, \n"
"drop by sometime. You may find \n"
"something helpful there! Byeee!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"The leader of the gang of thieves\n"
"is " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". She is experimenting \n"
"in brainwashing many people at \n"
"the ruins in the desert."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, it was Ganondorf the Evil\n"
"King who was behind the gang of \n"
"thieves..."
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "When " COLOR(RED) "Nabooru" COLOR(DEFAULT) " was a lone wolf \n"
"thief, she never stole from \n"
"the weak, but..." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Now, Nabooru's gang of thieves \n"
"stands for cruelty and brutality.\n"
"She claims to be a chivalrous \n"
"robber, but...no way!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Like I suspected, Nabooru was \n"
"brainwashed by Ganondorf's \n"
"followers..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "In Gerudo society, those who have\n"
"great skill in horseback riding and\n"
"archery are well respected." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"How about trying horseback \n"
"archery at the Gerudo's Fortress?" BOX_BREAK "If you have a horse, a Gerudo \n"
"from the fortress will set up \n"
"your challenge."
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"You did so great, young man!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Building a bridge over the valley\n"
"is a simple task for four\n"
"carpenters."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Without the old witches, the gang\n"
"of thieves isn't all that scary!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The " COLOR(RED) "Gerudo's Fortress " COLOR(DEFAULT) "is located \n"
"beyond this gate. A kid like you \n"
"has no business there."
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "I am a " COLOR(RED) "master craftsman" COLOR(DEFAULT) ". Those\n"
"Gerudo thieves...they broke the\n"
"bridge." BOX_BREAK UNSKIPPABLE "I want to fix it, but all of my \n"
"workers are gone!" BOX_BREAK UNSKIPPABLE "They said working as carpenters\n"
"isn't cool, and they went to the\n"
COLOR(RED) "Gerudo's Fortress " COLOR(DEFAULT) "to become \n"
"thieves..." TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, you! If you're going to the \n"
"fortress, would you mind finding\n"
"out what my workers are doing\n"
"over there?"
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, I heard you saved my men.\n"
"When they returned, we built this\n"
"bridge." BOX_BREAK "Look at this! \n"
"Isn't it a fine bridge?" BOX_BREAK "They may be wimpy carpenters, \n"
"but once they all got together,\n"
"they got the job done."
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Hey, that saw! It's mine!" BOX_BREAK UNSKIPPABLE "But... I thought I left that saw\n"
"with my old lady... Oh well..." TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Biggoron tool broke, so I was\n"
"going to Goron City to get it\n"
"repaired." BOX_BREAK "Your coming here is great timing.\n"
"Will you give me my saw?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x47")  QUICKTEXT_ENABLE "What?!\n"
SHIFT("\x14") "You're a dirty, rotten thief!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is the Gerudo's " COLOR(RED) "Training \n"
"Ground" COLOR(DEFAULT) ". Unqualified persons are \n"
"not allowed."
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is the Gerudo's" COLOR(RED) " Training\n"
"Ground" COLOR(DEFAULT) ". You're qualified...\n"
"C'mon in and hone your skills\n"
"as much as you want." EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is the Gerudo's" COLOR(RED) " Training \n"
"Ground" COLOR(DEFAULT) ". Even though you're \n"
"qualified, don't hog all the \n"
"treasure here for yourself!"
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, that's too bad." BOX_BREAK "The mark that will lead you to the\n"
"Spirit Temple is the " COLOR(RED) "flag on\n"
"the left " COLOR(DEFAULT) "outside the shop." BOX_BREAK "If you change your mind, please\n"
"come back again!"
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh, not enough Rupees.\n"
"No discounts, even a Rupee."
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh.\n"
"You're already in the middle of \n"
"something, aren't you." BOX_BREAK "If you want to challenge me, you\n"
"have to come here with a clear\n"
"mind. No other distractions!"
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x41") "Well Come!" BOX_BREAK "I am selling stuff, strange and \n"
"rare, from all over the world to \n"
"everybody.\n"
"Today's special is..." BOX_BREAK "A dangerous, running object! \n"
"Terrifying! \n"
"I won't tell you what it is until \n"
"I see the money...." BOX_BREAK "How about " COLOR(RED) "200 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Thank you very much!" BOX_BREAK "What I'm selling is..." TEXT_SPEED("\x02")  COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" TEXT_SPEED("\x00")  BOX_BREAK "The mark that will lead you to\n"
"the Spirit Temple is the " COLOR(RED) "flag on\n"
"the left " COLOR(DEFAULT) "outside the shop.\n"
"Be seeing you!"
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, what's up, " NAME "?\n"
"Surprised to see me?" BOX_BREAK UNSKIPPABLE "A long time in this world is\n"
"almost nothing to you, is it?\n"
"How mysterious!" BOX_BREAK UNSKIPPABLE "Even I thought that the tales of a\n"
"boy who could travel back and\n"
"forth through time was merely a\n"
"legend." BOX_BREAK UNSKIPPABLE  NAME ", you have fully \n"
"matured as an adult." TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"From now on, the future of all the\n"
"people in Hyrule is on your \n"
"shoulders." BOX_BREAK "Maybe it's not my time anymore. \n"
"Here is my last advice." BOX_BREAK "Two witches inhabit this temple. In \n"
"order to destroy them, " COLOR(RED) "turn their \n"
"own magic power against them" COLOR(DEFAULT) ".\n"
"Hoo hoot!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Do you want to hear what I said\n"
"again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I will continue to watch you...\n"
"Hoo hoo hoo hoot!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "I'm the wandering running man!\n"
"I've run all over this land in\n"
"search of true competitive spirit." BOX_BREAK UNSKIPPABLE "I beat all my challengers, man and\n"
"beast." BOX_BREAK UNSKIPPABLE "You're an athletic guy, and you\n"
"look like you might have a true\n"
"killer instinct, too." BOX_BREAK UNSKIPPABLE "Now that the bridge over Gerudo\n"
"Valley is complete, I'm looking for\n"
"a challenger to have a \n"
"commemorative race against." TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"The best time to go from here to \n"
"the " COLOR(ADJUSTABLE) "bridge in the Lost Woods " COLOR(DEFAULT) "was\n"
COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ".  That's my record." BOX_BREAK "Will you challenge my record?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Excellent!\n"
"Then..." BOX_BREAK "You go first.\n"
"I'll give you a headstart." BOX_BREAK "Now! " TEXT_SPEED("\x02") "Go ahead." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"You'll never discover your\n"
"killer instinct with that\n"
"kind of attitude."
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Well, not perfect, but you\n"
"have some guts! Unfortunately,\n"
"you never can beat me. Your\n"
"record is a thing of the past." BOX_BREAK "Your time was " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ", wasn't it?\n"
"That was close, but I beat you\n"
"by one second!" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Please. " TEXT_SPEED("\x02") "Go ahead." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Oh, looks like you quit the race.\n"
"Heh heh heh. I bet you had almost \n"
"rediscovered your killer instinct!" FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh.\n"
"You don't have enough killer\n"
"instinct yet." BOX_BREAK "Just train harder.\n"
QUICKTEXT_ENABLE "Good-bye, then!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Huff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "puff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "huff..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  BOX_BREAK "Huff...huff...whew!\n"
"You did quite well!" BOX_BREAK "But you couldn't beat me!\n"
"Your time was " COLOR(RED)  MARATHON_TIME  COLOR(DEFAULT) ", but I\n"
"just beat you by one second!" BOX_BREAK "Huff...huff... \n"
"You'll have to challenge me\n"
"again sometime!" BOX_BREAK "Huff...huff...\n"
QUICKTEXT_ENABLE "Good-bye, then!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"I'm the wandering running man!\n"
"I've run all over this land in \n"
"search of competitors who have a\n"
"true killer instinct!" BOX_BREAK "I came here to run through the \n"
"Haunted Wasteland, but it doesn't\n"
"look like good timing for that." BOX_BREAK "Though I want to go back to \n"
"Hyrule Field, the bridge is...well,\n"
"you can see it from here. So I'm\n"
"stuck here, inside this tent." BOX_BREAK "I don't think I can accept your\n"
"challenge right now.\n"
"Heh heh!"
)

DEFINE_MESSAGE(0x6087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6087"
)

DEFINE_MESSAGE(0x6088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6088"
)

DEFINE_MESSAGE(0x6089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6089"
)

DEFINE_MESSAGE(0x608A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608A"
)

DEFINE_MESSAGE(0x608B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608B"
)

DEFINE_MESSAGE(0x608C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608C"
)

DEFINE_MESSAGE(0x608D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608D"
)

DEFINE_MESSAGE(0x608E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608E"
)

DEFINE_MESSAGE(0x608F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"608F"
)

DEFINE_MESSAGE(0x7000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I can't catch that Cucco!"
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huff huff! \n"
"I'm late! I'm late!\n"
"For a very important date!"
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Welcome to Hyrule Castle Town.\n"
"It's a peaceful, prosperous town."
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Kids shouldn't be wandering around\n"
"town at nighttime! Stay indoors\n"
"until morning!"
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Man, I am SO bored...\n"
"Things would sure be more\n"
"interesting if there were more...\n"
"troubles in the world..." BOX_BREAK "Hey, that's just between you and\n"
"me, OK?" BOX_BREAK "Anyway, maybe we can let off \n"
"some steam by breaking these \n"
"jars." BOX_BREAK "Stand near a jar and press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to\n"
"lift it. Press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " again to toss it!"
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "That's great!" BOX_BREAK UNSKIPPABLE "I forgot to tell you..." EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "There's a lot going on in the \n"
"castle right now. I can't allow\n"
"even a dog to get into the \n"
"castle!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Unnngh...are you the boy from \n"
"the forest...?" BOX_BREAK UNSKIPPABLE "I-I-I've finally met you...\n"
"I-I-I have something to t-t-tell\n"
"you..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", the Gerudo King of\n"
"Thieves, betrayed our King..." BOX_BREAK UNSKIPPABLE "Zelda's nanny, " COLOR(RED) "Impa" COLOR(DEFAULT) ", sensed danger\n"
"and escaped from the castle with\n"
"our Princess..." BOX_BREAK UNSKIPPABLE "I tried to stop Ganondorf's men\n"
"from chasing them...but..." BOX_BREAK UNSKIPPABLE "The Princess was...waiting for a\n"
"boy from the forest...that's you...\n"
"She wanted to give " COLOR(RED) "something " COLOR(DEFAULT) "to\n"
"the boy..." BOX_BREAK UNSKIPPABLE "If you received it from the \n"
"Princess, " TEXT_SPEED("\x03")  QUICKTEXT_ENABLE "hurry" QUICKTEXT_DISABLE "..." QUICKTEXT_ENABLE "to the" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tem" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "ple" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "of" QUICKTEXT_DISABLE "\n"
"Time" COLOR(DEFAULT) "...." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"He's not moving anymore...."
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Can you see the man with the \n"
"evil eyes?" BOX_BREAK UNSKIPPABLE "That is " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", the leader of \n"
"the Gerudos. They hail from the \n"
"desert far to the west." BOX_BREAK UNSKIPPABLE "Though he swears allegiance to my \n"
"father, I am sure he is not \n"
"sincere." BOX_BREAK UNSKIPPABLE "The dark clouds that covered \n"
"Hyrule in my dream...\n"
"They must symbolize that man!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0E") "Geh heh heh! Excellent work!" BOX_BREAK_DELAYED("\x3C")  SHIFT("\x08") "As I thought, you held the keys\n"
SHIFT("\x26") "to the Door of Time!" BOX_BREAK_DELAYED("\x5A")  SHIFT("\x05") "You have led me to the gates of\n"
SHIFT("\x2D") "the Sacred Realm..." BOX_BREAK_DELAYED("\x50")  SHIFT("\x10") "Yes, I owe it all to you, kid!" FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Please! If you don't hurry,\n"
"he'll be gone!" EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please...with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Please sell me the " COLOR(RED) "contents" COLOR(DEFAULT) " of a\n"
"bottle...\n"
"Please...with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What a strange shop! \n"
"I wonder when it'll be open for\n"
"business. I read the sign there, \n"
"but it still seems weird!"
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It seems like it's taking forever\n"
"for dawn to come..." BOX_BREAK "The view of Hyrule Castle in \n"
"the morning sun is so fantastic!"
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"To save the forest girl, you need\n"
COLOR(RED) "another skill" COLOR(DEFAULT) "... \n"
"Head to Kakariko Village!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It looks like you have the\n"
"skills you need... \n"
"The " COLOR(ADJUSTABLE) "forest girl" COLOR(DEFAULT) " is waiting for your\n"
"help...."
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"If you want potions, you'd better \n"
"bring an empty bottle. Understand,\n"
"young man?" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"I'm sorry, but this is just a model. \n"
"Because of the crisis in Goron \n"
"City, we haven't received any \n"
"shipments lately and we're out." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"If you plan on scaling Death\n"
"Mountain, buy a " COLOR(LIGHTBLUE) "Hylian Shield" COLOR(DEFAULT) ".\n"
"You can defend yourself against\n"
"falling rocks with that shield." BOX_BREAK "But it might be a little bit \n"
"big for a kid...." PERSISTENT
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm not dancing, you know...\n"
"My back itches! \n"
"Ooh! Aaah! Ooh!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"They say we " COLOR(LIGHTBLUE) "Hylians " COLOR(DEFAULT) "have big ears\n"
"in order to hear the voices of the \n"
"gods...but I've never heard them!"
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Kid, have you been to \n"
COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Their milk is delicious!\n"
"There are many horses there, and\n"
"the young daughter of the ranch\n"
"owner is cute!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"To get to " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) ", after\n"
"you leave town, head due south\n"
"across the field. You should visit\n"
"the ranch at least once!"
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I wanted to see " COLOR(RED) "Princess Zelda" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "I avoided the guards..." BOX_BREAK UNSKIPPABLE "Swam through the moat..." BOX_BREAK UNSKIPPABLE "I was almost there when they\n"
"caught me!" TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I found a " COLOR(RED) "small drain hole " COLOR(DEFAULT) "on the\n"
"right side of the castle that I\n"
"thought I could sneak into, but I\n"
"got stuck there."
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x05") "This beard is my pride and joy!\n"
SHIFT("\x07") "Doesn't it look luxuriant, kid?!"
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x05") "This beard is my pride and joy!\n"
SHIFT("\x07") "Doesn't it look luxuriant, kid?!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x51") "What?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "You're looking for the guy from\n"
"Lon Lon Ranch?" BOX_BREAK UNSKIPPABLE "Hmm, maybe..." TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I saw a " COLOR(RED) "guy with a shabby-looking\n"
"beard " COLOR(DEFAULT) "delivering some boxes to \n"
"the castle."
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Do you know about the " COLOR(LIGHTBLUE) "Temple \n"
"of Time " COLOR(DEFAULT) "that we have in the \n"
"northeast part of town?" TEXTID("\x70\x1E")
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Legends say that the Temple of\n"
"Time is the entrance to the \n"
"Sacred Realm..." BOX_BREAK "Did you know that?"
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha! What a crazy guy!" BOX_BREAK UNSKIPPABLE "Can you believe this guy was \n"
"crazy enough to try to sneak into\n"
"the castle to see " COLOR(RED) "Princess Zelda" COLOR(DEFAULT) "?" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All because of this idiot, they've \n"
"tightened security at the castle.\n"
"Wha-ha-hah!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I made a lot of money!" BOX_BREAK UNSKIPPABLE "Maybe I should go look for\n"
"more things to sell!" TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I know! I should go to " COLOR(BLUE) "Lake Hylia" COLOR(DEFAULT) "!\n"
"Many things float down the river\n"
"and end up there!\n"
"Hah hah!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, forest boy! This is the " COLOR(LIGHTBLUE) "city\n"
"of Hyrule" COLOR(DEFAULT) "! Take your time and\n"
"enjoy the sights!" TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you came here to see " COLOR(LIGHTBLUE) "Hyrule\n"
"Castle" COLOR(DEFAULT) ", take the street on your\n"
"right." BOX_BREAK "If you want to see the " COLOR(BLUE) "back \n"
"alleys" COLOR(DEFAULT) " of the town, take the\n"
"street to the left."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..." BOX_BREAK "You are...so handsome..." BOX_BREAK "Just like the King of Hyrule..." BOX_BREAK "Hee hee..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..." BOX_BREAK "You are..." BOX_BREAK "more beautiful..." BOX_BREAK "than Princess Zelda..." BOX_BREAK "Ohh..."
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Have you heard the legend of the\n"
"\"Shadow Folk\"?" BOX_BREAK UNSKIPPABLE "They are the " COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "...the shadows\n"
"of the Hylians." BOX_BREAK UNSKIPPABLE "They say they swore allegiance to\n"
"the King of Hyrule and guarded\n"
"the Royal Family." BOX_BREAK UNSKIPPABLE "But with the long peace, no one\n"
"has seen a Sheikah around here \n"
"for a long time." BOX_BREAK UNSKIPPABLE "However..." TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I heard there is one " COLOR(BLUE) "Sheikah \n"
COLOR(DEFAULT) "woman living in the castle..."
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"So you say you want to see\n"
COLOR(RED) "Princess Zelda" COLOR(DEFAULT) ", eh?" BOX_BREAK "You probably heard about her in\n"
"town and decided you had to meet\n"
"her... Well..." BOX_BREAK QUICKTEXT_ENABLE "Go home!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Get out of here!" QUICKTEXT_DISABLE "\n"
"The Princess would never grant an\n"
"audience to the likes of you!"
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z...." BOX_BREAK "Mumble mumble..." BOX_BREAK "Welcome...our ranch is so fun..." BOX_BREAK "C'mon and look around..."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2D") "What in tarnation?" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Can't a person get a little shut-\n"
"eye around here?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hello, and who might you be?" BOX_BREAK UNSKIPPABLE "Yep, I'm " COLOR(RED) "Talon" COLOR(DEFAULT) ", the owner of Lon \n"
"Lon Ranch." BOX_BREAK UNSKIPPABLE "I went to the castle to deliver\n"
"some milk, but I sat down here to\n"
"rest, and I guess I fell asleep..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4C")  SFX("\x68\x52") "What?!\n"
"Malon was looking for me?\n"
"I'm gonna catch it from her now!" BOX_BREAK UNSKIPPABLE "I messed up bad, leaving Malon\n"
"behind to wait for me!" BOX_BREAK UNSKIPPABLE "She's really gonna let me have it!" EVENT
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Hey you! Stop!\n"
SHIFT("\x28") "You, kid, over there!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x5F") "!" BOX_BREAK_DELAYED("\x0A")  UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Who?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Who are you?" BOX_BREAK UNSKIPPABLE "How did you get past the guards?" EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Do you have it? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Well, that's odd...\n"
"I thought you might be the one\n"
"from my dream...\n"
"You really don't have it?" BOX_BREAK "Tell me the truth..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D") "Just as I thought!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Please keep this a secret from\n"
"everyone...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"C'mon...don't be a blabber-mouth!" EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The legend goes like this..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x12") "The three goddesses hid the\n"
SHIFT("\x07")  COLOR(RED) "Triforce " COLOR(DEFAULT) "containing the power of\n"
SHIFT("\x0D") "the gods somewhere in Hyrule." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x45") "The power\n"
SHIFT("\x03") "to grant the wish of the one who\n"
SHIFT("\x0A") "holds the Triforce in his hands." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x03") "If someone with a righteous heart\n"
SHIFT("\x07") "makes a wish, it will lead Hyrule\n"
SHIFT("\x09") "to a golden age of prosperity...." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x06") "If someone with an evil mind has\n"
SHIFT("\x0A") "his wish granted, the world will\n"
SHIFT("\x02") "be consumed by evil...That is what\n"
SHIFT("\x35") "has been told...." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x16") "So, the ancient Sages built\n"
SHIFT("\x02") "the " COLOR(LIGHTBLUE) "Temple of Time" COLOR(DEFAULT) " to protect the\n"
SHIFT("\x20") "Triforce from evil ones." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"That's right... The Temple of Time\n"
"is the entrance through which you\n"
"can enter the Sacred Realm from\n"
"our world." BOX_BREAK "But the entrance is sealed with\n"
"a stone wall called the \n"
COLOR(LIGHTBLUE) "Door of Time" COLOR(DEFAULT) "." BOX_BREAK "And, in order to open the door,\n"
"it is said that you need to collect\n"
"three " COLOR(RED) "Spiritual Stones" COLOR(DEFAULT) "." BOX_BREAK "And another thing you need...is\n"
"the treasure that the Royal Family\n"
"keeps along with this legend..." EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, I'm sorry. \n"
"I'm not very good at storytelling..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "What happened?" QUICKTEXT_DISABLE " Did he see you?" BOX_BREAK UNSKIPPABLE "Don't worry." BOX_BREAK UNSKIPPABLE "He doesn't have any idea what\n"
"we're planning...yet!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Please!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"I don't believe you." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42") "Thank you!" EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My attendant will guide you out of\n"
"the castle. Don't be afraid to talk\n"
"to her."
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The Spiritual Stone...\n"
"You finally found it!" BOX_BREAK "It is said that the races that hold\n"
"the Spiritual Stones open their\n"
"minds only to one who knows the\n"
COLOR(BLUE) "melody of the Royal Family" COLOR(DEFAULT) "." BOX_BREAK "But you already know that, don't\n"
"you?"
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, have you heard that\n"
"Princess Zelda sees prophetic \n"
"visions in her dreams?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh? What? Shoo, kid! Shoo!"
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"There are three hollows and \n"
"an inscription here...." BOX_BREAK QUICKTEXT_ENABLE "Ye who owns 3 Spiritual Stones " COLOR(BLUE) "\n"
COLOR(DEFAULT) "Stand with the " COLOR(LIGHTBLUE) "Ocarina of Time" COLOR(BLUE) "\n"
COLOR(DEFAULT) "And play the " COLOR(LIGHTBLUE) "Song of Time" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK "That is how the inscription reads." EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'mon, can't you make it any\n"
"cheaper?"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, let go! It's mine!\n"
"I found it first!"
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, who bumped me?!"
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We don't see a lot of Gerudos in\n"
"these parts...\n"
"Something fishy is going on!"
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wasn't that Princess Zelda riding\n"
"on the white horse?!"
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I almost got kicked by that\n"
"black horse!"
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That guy riding on the black horse\n"
"must have been Ganondorf, who is\n"
"renowned as the Gerudo King of \n"
"Thieves."
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What happened?!"
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Look at that guy--he's so scared!\n"
"What a wimp!\n"
"Ha ha hah!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I have a feeling something\n"
"terrible is going to happen...\n"
"Maybe I should leave town soon."
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Something happened in the castle!\n"
"Kid, you'd better be careful!"
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"With that " COLOR(RED) "key" COLOR(DEFAULT) ", proceed to the \n"
"room ahead. Go, go!"
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The one riding on the white horse\n"
"holding the little girl...\n"
"Wasn't that a legendary Sheikah?"
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D")  NAME "..." BOX_BREAK UNSKIPPABLE  SHIFT("\x45") "Wake up...\n"
SHIFT("\x05")  NAME ", the chosen one..."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I am " COLOR(RED) "Rauru" COLOR(DEFAULT) ", one of the ancient\n"
"Sages..." BOX_BREAK UNSKIPPABLE "Ages ago, we ancient Sages\n"
"built the Temple of Time to \n"
"protect the entrance to the\n"
"Sacred Realm..." BOX_BREAK UNSKIPPABLE "This is the " COLOR(RED) "Chamber of Sages" COLOR(DEFAULT) "," COLOR(RED) " \n"
COLOR(DEFAULT) "inside the Temple of Light..." BOX_BREAK UNSKIPPABLE "The Temple of Light, situated in\n"
"the very center of the Sacred \n"
"Realm, is the last stronghold \n"
"against Ganondorf's evil forces." BOX_BREAK UNSKIPPABLE "The " COLOR(RED) "Master Sword" COLOR(DEFAULT) "--the evil-\n"
"destroying sword that you pulled\n"
"out of the Pedestal of Time--was \n"
"the final key to the Sacred Realm." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Don't be alarmed...\n"
"Look at yourself...!"
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Look " NAME "!\n"
COLOR(DEFAULT)  SHIFT("\x32")  COLOR(LIGHTBLUE) "You're big now!!\n"
COLOR(DEFAULT)  SHIFT("\x31")  COLOR(LIGHTBLUE) "You've grown up!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The Master Sword is a sacred\n"
"blade which evil ones may never\n"
"touch...." BOX_BREAK UNSKIPPABLE "Only one worthy of the title of\n"
"\"" COLOR(RED) "Hero of Time" COLOR(DEFAULT) "\"" COLOR(RED) " " COLOR(DEFAULT) "can pull it from \n"
"the Pedestal of Time...." BOX_BREAK UNSKIPPABLE "However, you were too young to \n"
"be the Hero of Time...." BOX_BREAK UNSKIPPABLE "Therefore, your spirit was \n"
"sealed here for seven years." BOX_BREAK UNSKIPPABLE "And now that you are old enough,\n"
"the time has come for you to\n"
"awaken" COLOR(RED) " " COLOR(DEFAULT) "as the Hero of Time!" BOX_BREAK "Well, do you understand your \n"
"destiny?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Right, it looks like you are \n"
"confused... Let me tell you \n"
"again, from the beginning." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "But, remember..." BOX_BREAK UNSKIPPABLE "Though you opened the Door of \n"
"Time in the name of peace..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", the Gerudo King of\n"
"Thieves, used it to enter this \n"
"forbidden Sacred Realm!" BOX_BREAK UNSKIPPABLE "He obtained the Triforce from\n"
"the Temple of Light, and with its \n"
"power, he became the " COLOR(RED) "King of Evil" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "His evil power radiated from the\n"
"temples of Hyrule, and in seven\n"
"short years, it transformed Hyrule\n"
"into a world of monsters." BOX_BREAK UNSKIPPABLE "My power now has only little \n"
"influence, even in this Sacred\n"
"Realm..." BOX_BREAK UNSKIPPABLE "Namely, this Chamber of Sages." BOX_BREAK UNSKIPPABLE "But there is still hope..." BOX_BREAK UNSKIPPABLE "The power of the Sages remains." BOX_BREAK UNSKIPPABLE "When the power of all the " COLOR(RED) "Sages\n"
COLOR(DEFAULT) "is awakened..." BOX_BREAK UNSKIPPABLE "The " COLOR(RED) "Sages' Seals" COLOR(DEFAULT) " will contain\n"
"all the evil power in the void of \n"
"the Realm..." BOX_BREAK UNSKIPPABLE "I, Rauru, am one of the Sages...\n"
"And..." BOX_BREAK UNSKIPPABLE "Your power to fight together with\n"
"the Sages makes you the \n"
COLOR(RED) "Hero of Time" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "The Hero of Time, chosen by the\n"
"Master Sword!" BOX_BREAK UNSKIPPABLE "Keep my spirit with you...\n"
"And, find the power of the other\n"
"Sages and add their might to your\n"
"own!"
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "...we're back in the\n"
COLOR(DEFAULT) "Temple of Time" COLOR(LIGHTBLUE) "...\n"
"But have " COLOR(DEFAULT) "seven years" COLOR(LIGHTBLUE) " really\n"
"passed?" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "It looks like you won't be\n"
"able to use some of the " COLOR(DEFAULT) "weapons" COLOR(LIGHTBLUE) "\n"
"you found as a kid anymore..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Let's get out of here!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heyyy, what...? \n"
"What's wrong with loitering\n"
"around all day?" BOX_BREAK "Huh, kid?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I've been waiting for you, \n"
"Hero of Time..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "When evil rules all, an awakening\n"
"voice from the Sacred Realm will\n"
"call those destined to be Sages,\n"
"who dwell in the " COLOR(RED) "five temples" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "One in a " COLOR(ADJUSTABLE) "deep forest" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "One on a " COLOR(RED) "high mountain" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "One under a " COLOR(BLUE) "vast lake" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "One within the " COLOR(PURPLE) "house of the dead" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "One inside a " COLOR(YELLOW) "goddess of the sand" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Together with the Hero of Time, \n"
"the awakened ones will bind the\n"
"evil and return the light of peace\n"
"to the world..." BOX_BREAK UNSKIPPABLE "This is the legend of the temples\n"
"passed down by my people, the\n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, I'm sorry.\n"
"We're not open for business yet.\n"
"Please come back soon!" EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Use the " COLOR(RED) "Master Sword" COLOR(DEFAULT) "!\n"
"Destroy Ganon with the sacred\n"
"sword!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I have been waiting for you,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", the Hero of Time..." BOX_BREAK UNSKIPPABLE "You have overcome many \n"
"hardships and awakened six Sages." BOX_BREAK UNSKIPPABLE "And now you have a final\n"
"challenge, a showdown with \n"
"Ganondorf, the King of Evil...."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x10") "If you would seek the sacred\n"
SHIFT("\x28") "triangle, listen well..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x09") "The resting place of the sacred\n"
SHIFT("\x09") "triangle, the Sacred Realm, is a\n"
SHIFT("\x14") "mirror that reflects what is\n"
SHIFT("\x3B") "in the heart..." BOX_BREAK_DELAYED("\x46")  UNSKIPPABLE  SHIFT("\x05") "the heart of one who enters it...\n"
SHIFT("\x0C") "If an evil heart, the Realm will\n"
SHIFT("\x14") "become full of evil; if pure,\n"
SHIFT("\x04") "the Realm will become a paradise." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x02") "The Triforce...the sacred triangle...\n"
SHIFT("\x0A") "it is a balance that weighs the\n"
SHIFT("\x3C") "three forces:\n"
SHIFT("\x13") "Power, Wisdom and Courage." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x02") "If the heart of the one who holds\n"
SHIFT("\x06") "the sacred triangle has all three\n"
SHIFT("\x0A") "forces in balance, that one will\n"
SHIFT("\x03") "gain the True Force to govern all." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x06") "But, if that one's heart is not in\n"
SHIFT("\x02") "balance, the Triforce will separate\n"
SHIFT("\x32") "into three parts:\n"
SHIFT("\x13") "Power, Wisdom and Courage." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x04") "Only one part will remain for the\n"
SHIFT("\x02") "one who touched the Triforce...the\n"
SHIFT("\x07") "part representing the force that\n"
SHIFT("\x27") "one most believes in." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x04") "If that one seeks the True Force,\n"
SHIFT("\x0C") "that one must acquire the two\n"
SHIFT("\x44") "lost parts." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x12") "Those two parts will be held\n"
SHIFT("\x07") "within others chosen by destiny,\n"
SHIFT("\x0A") "who will bear the Triforce mark\n"
SHIFT("\x11") "on the backs of their hands." FADE("\x5A")
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seven years ago, Ganondorf, the \n"
"King of Thieves, used the door \n"
"you opened in the Temple of Time\n"
"and entered the Sacred Realm." BOX_BREAK UNSKIPPABLE "But when he laid his hands on the\n"
"Triforce, the legend came true."
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The one who holds the " COLOR(RED) "Triforce \n"
"of Courage " COLOR(DEFAULT) "is...\n"
"You, " NAME "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "And the other, who holds the \n"
COLOR(RED) "Triforce of Wisdom" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "is the seventh Sage, who is\n"
"destined to be the leader of\n"
"them all..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "It is I, the Princess of Hyrule,\n"
COLOR(RED) "Zelda" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I apologize for meeting you in \n"
"disguise, but it was necessary to\n"
"hide from the King of Evil. \n"
"Please forgive me..."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"I saw you as I was escaping \n"
"from the castle with my \n"
"attendant, Impa." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As long as you had the Ocarina \n"
"in your possession, I thought \n"
"Ganondorf could never enter the\n"
"Sacred Realm, but..." BOX_BREAK UNSKIPPABLE "something I could never expect\n"
"happened..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x24") "That rumbling...It can't be!?"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Princess Zelda...you foolish \n"
"traitor!" BOX_BREAK UNSKIPPABLE "I commend you for avoiding my \n"
"pursuit for seven long years."
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "If you want to rescue Zelda,\n"
"come to my castle!"
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...can you hear me?\n"
"It's Rauru, the Sage." BOX_BREAK UNSKIPPABLE "We six will gather our power to\n"
"create a bridge to the castle\n"
"where Ganondorf dwells..." BOX_BREAK UNSKIPPABLE "The castle's keep, which is \n"
"known as Ganon's Tower, is \n"
"protected by " COLOR(RED) "six evil barriers" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Bring down the six barriers and\n"
"save Princess Zelda!!"
)

DEFINE_MESSAGE(0x7068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"7068"
)

DEFINE_MESSAGE(0x7069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"7069"
)

DEFINE_MESSAGE(0x706A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"706a"
)

DEFINE_MESSAGE(0x706B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"706b"
)

DEFINE_MESSAGE(0x706C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ancient Creators of Hyrule!" BOX_BREAK_DELAYED("\x3C") "Now, open the sealed door\n"
"and send the Evil Incarnation of\n"
"Darkness into the void of the\n"
"Evil Realm!!" FADE("\x5A")
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "!\n"
"Finish him off with the sword of\n"
"time, the Master Sword!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh sealed door opened by the \n"
"Sages... Close forever with \n"
"the Evil Incarnation of Darkness\n"
"within!!"
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Thank you, " NAME "..." BOX_BREAK UNSKIPPABLE "Thanks to you, Ganondorf has\n"
"been sealed inside the Evil Realm!" BOX_BREAK UNSKIPPABLE "Thus, peace will once again\n"
"reign in this world...for a time."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x3C") "Thank you...\n"
SHIFT("\x32")  NAME "..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  SHIFT("\x32") "Good-bye...." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you really want to go through\n"
"this gate that much? Let me think\n"
"about it... OK, but in return..." TEXTID("\x70\x72")
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Give me 10 Rupees...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Please believe me....\n"
"My prophecies have never been\n"
"wrong!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "You destroyed the wicked\n"
"creatures that haunted the temple\n"
"and awakened the Sage..." BOX_BREAK UNSKIPPABLE "But there are still other Sages\n"
"who need your help." BOX_BREAK UNSKIPPABLE "In order to awaken all the other\n"
"Sages, you must become even\n"
"more powerful." BOX_BREAK UNSKIPPABLE "You must travel over\n"
"mountains..." BOX_BREAK UNSKIPPABLE "under water..." BOX_BREAK UNSKIPPABLE "and even through time..."
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As long as you hold the " COLOR(LIGHTBLUE) "Ocarina\n"
"of Time" COLOR(DEFAULT) " and the " COLOR(LIGHTBLUE) "Master Sword" COLOR(DEFAULT) "," BOX_BREAK UNSKIPPABLE "you hold time itself in your\n"
"hands..." BOX_BREAK UNSKIPPABLE  NAME ", we shall meet \n"
"again!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This is a new type of bomb!\n"
"It's available only in limited\n"
"quantities, and when I'm sold \n"
"out, that's it!" EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I am " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"Survivor of the Sheikahs..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As I see you standing there\n"
"holding the mythical " COLOR(RED) "Master \n"
"Sword" COLOR(DEFAULT) ", you really do look like the \n"
"legendary Hero of Time..."
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "If you believe the legend, you\n"
"have no choice. You must look for\n"
"the five temples and awaken the\n"
COLOR(RED) "five Sages" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "One Sage is waiting for the time\n"
"of awakening in the " COLOR(ADJUSTABLE) "Forest Temple" COLOR(DEFAULT) ".\n"
"The Sage is a girl I am sure you\n"
"know..." BOX_BREAK UNSKIPPABLE "Because of the evil power in the\n"
"temple, she cannot hear the\n"
"awakening call from the Sacred\n"
"Realm..." BOX_BREAK UNSKIPPABLE "Unfortunately, equipped as you \n"
"currently are, you cannot even\n"
"enter the temple..." BOX_BREAK UNSKIPPABLE "But, if you believe what I'm saying,\n"
"you should head to " COLOR(RED) "Kakariko \n"
"Village" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Do you understand, \n"
NAME "?"
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"I thought I should entrust the\n"
"Ocarina to you... I thought that \n"
"would be our best chance..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Before that...I have things I want \n"
"to tell only to you. Please listen." BOX_BREAK UNSKIPPABLE "Another unknown legend of the \n"
"Triforce passed down by the \n"
"shadow folk, the Sheikahs...."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The Triforce separated into three \n"
"parts. Only the " COLOR(RED) "Triforce of Power" COLOR(DEFAULT) "\n"
"remained in Ganondorf's hand."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The strength of the Triforce of\n"
"Power enabled him to become a\n"
"mighty, evil king, but his dark\n"
"ambitions were not satisfied."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "To gain complete mastery of the \n"
"world, Ganondorf started looking\n"
"for " COLOR(RED) "those chosen by destiny" COLOR(DEFAULT) " to \n"
"hold the two other Triforce parts."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "On that day, seven years ago,\n"
"Ganondorf attacked Hyrule Castle."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "After you opened the door of \n"
"time, the Master Sword sealed you\n"
"away in the Sacred Realm..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Your spirit remained in the Sacred\n"
"Realm...and then the Triforce fell \n"
"into Ganondorf's hands. He went\n"
"on to invade the Sacred Realm..." BOX_BREAK UNSKIPPABLE "Ganondorf had become the Evil\n"
"King, and the Sacred Realm\n"
"became a world of evil. All of\n"
"this is an unfortunate coincidence." BOX_BREAK UNSKIPPABLE "I passed myself off as a Sheikah\n"
"and hoped that you would return.\n"
"I waited for seven years..."
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "And...now you are back. The \n"
"dark age ruled by Ganondorf the\n"
"Evil King will end!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The six Sages will open the sealed\n"
"door and lure Ganondorf back into\n"
"the Sacred Realm." BOX_BREAK UNSKIPPABLE "I will then seal the door to the \n"
"Sacred Realm from this world." BOX_BREAK UNSKIPPABLE "Thus, Ganondorf the Evil King will\n"
"vanish from Hyrule." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"In order to do this, I need your \n"
"courage again. Please protect me\n"
"while I do my part." BOX_BREAK UNSKIPPABLE "And here is a weapon that can \n"
"penetrate the Evil King's defenses...\n"
"The power given to the chosen \n"
"ones..." BOX_BREAK UNSKIPPABLE  SHIFT("\x0F") "The sacred " COLOR(LIGHTBLUE) "Arrow of Light" COLOR(DEFAULT) "!!!"
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "But you let your guard down...\n"
"I knew you would appear if I let\n"
"this kid wander around!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "My only mistake was to slightly\n"
"underestimate the power of this\n"
"kid..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No...\n"
"It was not the kid's power I\n"
"misjudged, it was the power of\n"
"the Triforce of Courage!" BOX_BREAK UNSKIPPABLE "But, with the Triforce of Wisdom\n"
"that Zelda has...\n"
"When I obtain these two Triforces..." BOX_BREAK UNSKIPPABLE "Then, I will become the true\n"
"ruler of the world!!"
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "The Ocarina of Time opened the\n"
"door. The Hero of Time, with the\n"
"Master Sword, descended here." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It seems strange that packs of\n"
"dogs roam our streets at night...\n"
"Doesn't that seem weird to you?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, sonny, I'll tell you something\n"
"helpful..." BOX_BREAK "I heard there is a " COLOR(RED) "mysterious \n"
"fountain" COLOR(DEFAULT) " somewhere near the \n"
"castle..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "If you want to return to your\n"
"original time, return the Master \n"
"Sword to the " COLOR(RED) "Pedestal of Time" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "By doing this, you will travel back\n"
"in time seven years...."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The time will come when you will\n"
"have to return here quickly...\n"
"I will teach this to you for when \n"
"that time comes..." BOX_BREAK UNSKIPPABLE "The song to return you to the \n"
"Temple of Time...\n"
COLOR(LIGHTBLUE) "The Prelude of Light" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I am " COLOR(RED) "Impa " COLOR(DEFAULT) "of the Sheikahs.\n"
"I am responsible for protecting\n"
"Princess Zelda. Everything is \n"
"exactly as the Princess foretold."
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If the castle soldiers find you,\n"
"there will be trouble. Let me \n"
"lead you out of the castle."
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hey you! Don't cause any trouble!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "You are a courageous boy...\n"
"You are heading out on a big, new \n"
"adventure, aren't you?" BOX_BREAK UNSKIPPABLE "My role in the Princess's dream\n"
"was to teach a melody" COLOR(RED) " " COLOR(DEFAULT) "to the one\n"
"from the forest." BOX_BREAK UNSKIPPABLE "This is an ancient " COLOR(BLUE) "melody passed \n"
"down by the Royal Family" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "I have played this song for \n"
"Princess Zelda as a lullaby ever\n"
"since she was a baby..." BOX_BREAK UNSKIPPABLE "There is mysterious power in \n"
"these notes." BOX_BREAK UNSKIPPABLE "Now listen carefully..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "All the tragedy that has befallen\n"
"Hyrule was my doing..." BOX_BREAK UNSKIPPABLE "I was so young...I could not\n"
"comprehend the consequences of \n"
"trying to control the Sacred Realm." BOX_BREAK UNSKIPPABLE "I dragged you into it, too." BOX_BREAK UNSKIPPABLE "Now it is time for me to make up \n"
"for my mistakes..." BOX_BREAK UNSKIPPABLE "You must lay the Master Sword to \n"
"rest and close the Door of Time..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "However, by doing this, the road\n"
"between times will be closed..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ",\n"
"give the Ocarina to me..." BOX_BREAK UNSKIPPABLE "As a Sage, I can return you\n"
"to your original time with it."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "When peace returns to Hyrule..." BOX_BREAK UNSKIPPABLE "It will be time for us to say \n"
"good-bye..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Now, go home, " NAME ".\n"
"Regain your lost time!" BOX_BREAK UNSKIPPABLE "Home... \n"
"where you are supposed to be...\n"
"the way you are supposed to be..."
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46")  QUICKTEXT_ENABLE "Tsk" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Tsk." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well, maybe that's too much\n"
"for a kid to pay." EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"OK, I'll let you pass,\n"
"quickly!" EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"KEEP IT A SECRET \n"
"FROM EVERYONE."
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Man, I am SO tired!" BOX_BREAK "The night watch is so boring!\n"
"I wish some ghosts would come \n"
"out or something..." BOX_BREAK "Hey, I'm really interested in \n"
"ghosts!" BOX_BREAK "Studying them is a hobby of mine,\n"
"but you never know...the time\n"
"might come when that kind of\n"
"knowledge might be useful!"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My precious little puppy's fur coat\n"
"is very special compared to the \n"
"other mutts around here!"
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My precious puppy can run faster\n"
"than any of the other mutts\n"
"around here!"
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I can't find my puppy anywhere!\n"
"I need you to look for it! Please!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"That is not my dog! \n"
"How could you mix up my puppy\n"
"with a mutt like that?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x46")  QUICKTEXT_ENABLE "Richard!" QUICKTEXT_DISABLE  BOX_BREAK "This is my little Richard!\n"
"Thank you! Thank you!\n"
"I'll give this to you as a\n"
"reward!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"At night it's dangerous to go out\n"
"with all the wild dogs around...\n"
"No, I wasn't warning you! \n"
"I'm worried about my puppy!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hiyeee!\n"
"Welcome to the " COLOR(RED) "Happy Mask Shop" COLOR(DEFAULT) "!\n"
"We deal in masks that bring \n"
"happiness to everyone!" BOX_BREAK "How would you like to be a \n"
"happiness salesman? I'll lend you\n"
"a mask. You sell the mask and \n"
"bring the " COLOR(RED) "money " COLOR(DEFAULT) "back here." BOX_BREAK "If you want to read the fine \n"
"print, take a look at the " COLOR(RED) "sign \n"
COLOR(DEFAULT) "right over there." BOX_BREAK "After you've sold all the masks,\n"
"you will become happy" COLOR(RED) " " COLOR(DEFAULT) "yourself!" BOX_BREAK SHIFT("\x40") "Have faith..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Select a mask with left or right\n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Talk to the shop owner.\n"
"Don't borrow" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A " COLOR(RED) "mask " COLOR(DEFAULT) "is a " COLOR(YELLOW) "[C] Button " COLOR(DEFAULT) "item. Set\n"
"it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to wear it." BOX_BREAK "If you talk to someone with a \n"
"mask on, you might get a reaction." BOX_BREAK "If anyone is interested in the\n"
"mask, he or she will ask you \n"
"about it. Someone may want the \n"
"mask." BOX_BREAK "Somewhere in the world, somebody\n"
"is waiting for these masks." BOX_BREAK SHIFT("\x32") "Just have faith..." EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I might have seen a cute little\n"
"girl around here...\n"
"Maybe she went to the castle?\n"
"Who knows?"
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, great! You sold it!\n"
"Please pay back " COLOR(RED) "10 Rupees " COLOR(DEFAULT) "for\n"
"the Keaton Mask now." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! You haven't sold the newest\n"
"mask yet. Just have faith... Keep\n"
"trying a little longer." EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Payment received!" EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "What?!" QUICKTEXT_DISABLE "\n"
"You don't have my money?!" BOX_BREAK QUICKTEXT_ENABLE "How dare you!" QUICKTEXT_DISABLE  BOX_BREAK "You'd better bring me my money...\n"
"or else!" EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh yeah!" BOX_BREAK "Very well done!\n"
"All the masks are sold out." BOX_BREAK "I knew I could trust you!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As a reward...\n"
"I will lend you this special mask." BOX_BREAK UNSKIPPABLE "This is the " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". It is a\n"
"mysterious mask passed down by \n"
"the Sheikah." BOX_BREAK UNSKIPPABLE "With this mask you can see into \n"
"other people's minds...\n"
"It's useful, but scary!" BOX_BREAK UNSKIPPABLE "Why is it scary?" BOX_BREAK UNSKIPPABLE "You may find out as you grow\n"
"older and discover the true \n"
"meaning of life..." BOX_BREAK UNSKIPPABLE "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"From now on you can borrow any\n"
"mask you want.\n"
"Just have faith..." EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Welcome!\n"
"Which mask can I lend to you?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Choose a mask with left or right \n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ask about Mask of Truth\n"
"Don't borrow a mask" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"This is the " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". It is a\n"
"mysterious mask passed down by \n"
"the Sheikah." BOX_BREAK "With this mask you can see into \n"
"other people's minds. It's useful,\n"
"but scary!" BOX_BREAK "Why is it scary?" BOX_BREAK "You'll find out as you grow older!" BOX_BREAK "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Mask of Truth -- Not for Sale" COLOR(DEFAULT) "\n"
"This mask has special powers." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Skull Mask -- Price 20 Rupees" COLOR(DEFAULT) "\n"
"A horned skull mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Spooky Mask -- Price 30 Rupees\n"
COLOR(DEFAULT) "A sad, wooden mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Keaton Mask -- Price 10 Rupees\n"
COLOR(DEFAULT) "Keaton stuff is hot, hot, hot!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bunny Hood -- Price 50 Rupees\n"
COLOR(DEFAULT) "With swinging rabbit ears!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Skull Mask -- Free to Borrow" COLOR(DEFAULT) "\n"
"A horned skull mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Spooky Mask -- Free to Borrow\n"
COLOR(DEFAULT) "A sad, wooden mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Keaton Mask -- Free to Borrow\n"
COLOR(DEFAULT) "Keaton stuff is hot, hot, hot!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bunny Hood -- Free to Borrow\n"
COLOR(DEFAULT) "With swinging rabbit ears!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Goron Mask -- Free to Borrow\n"
COLOR(DEFAULT) "This round face makes you \n"
"a little happier!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Zora Mask -- Free to Borrow" COLOR(DEFAULT) "\n"
"You'll look cool while you're\n"
"swimming if you wear this mask!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Gerudo Mask -- Free to Borrow\n"
COLOR(DEFAULT) "With its charming eyes, it makes\n"
"a great lady's disguise." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Mask of Truth -- Free to Borrow" COLOR(DEFAULT) "\n"
"Mysterious mask to see into other\n"
"people's minds." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the " COLOR(RED) "Skull \n"
"Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Spooky Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Keaton Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Bunny Hood" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Goron Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Zora Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Gerudo Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Mask of Truth" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "20 Rupees \n"
COLOR(DEFAULT) "for the Skull Mask now." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "30 Rupees \n"
COLOR(DEFAULT) "for the Spooky Mask now." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "50 Rupees \n"
COLOR(DEFAULT) "for the Bunny Hood now." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! You haven't sold the mask\n"
"yet. Just have faith for a \n"
"little while longer." BOX_BREAK "Or, do you want to trade it\n"
"for another mask?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The Triforce parts are resonating...\n"
"They are combining into one again..."
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The two Triforce parts that I \n"
"could not capture on that day\n"
"seven years ago..." BOX_BREAK UNSKIPPABLE "I didn't expect they would be \n"
"hidden within you two!"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "And now, finally, all the Triforce\n"
"parts have gathered here!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "These toys are too much for you!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I command you to return them \n"
"to me!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"I can't help you!\n"
"Because of the waves of\n"
"darkness, I can't get close!" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "I'm sorry, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "The Great Evil King Ganondorf...\n"
"beaten by this kid?!"
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf...pitiful man..." BOX_BREAK UNSKIPPABLE "Without a strong, righteous mind,\n"
"he could not control the power of\n"
"the gods...and..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", listen to me!\n"
"This tower will collapse soon!" BOX_BREAK UNSKIPPABLE "With his last breath, Ganondorf is\n"
"trying to crush us in the ruins of\n"
"the tower! We need to hurry and\n"
"escape!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Please follow me!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "It's over...it's finally over..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... \n"
"I'm sorry I couldn't help you in the\n"
"battle before!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "What is that sound?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "There's no way he's going to hold\n"
"me back again!\n"
COLOR(DEFAULT)  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "This time, we fight together!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! The Master \n"
"Sword is here! \n"
QUICKTEXT_ENABLE "Hurry up!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I'm using my power to hold the\n"
"Evil King! You use your sword and\n"
"deliver the final blow!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x41") "Six Sages...\n"
QUICKTEXT_ENABLE  SHIFT("\x50") "Now!!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "YOU..." TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "CURSE YOU...ZELDA!\n"
TEXT_SPEED("\x02") "CURSE YOU...SAGES!!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "CURSE YOU..." QUICKTEXT_ENABLE  NAME "!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Someday...\n"
"When this seal is broken...." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "That is when I will exterminate\n"
"your descendants!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As long as the Triforce of Power\n"
"is in my hand...." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
TEXT_SPEED("\x02") "You..." TEXT_SPEED("\x00") "who are you?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0A") "The " COLOR(ADJUSTABLE) "Forest Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x14") "Hurry up, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "The " COLOR(RED) "Fire Barrier" COLOR(DEFAULT) " is dispelled!\n"
SHIFT("\x14") "Hurry up, Brother!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "The " COLOR(BLUE) "Water Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x46") "Hurry up!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "The " COLOR(PURPLE) "Shadow Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x1E") "Please save the Princess!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "The " COLOR(YELLOW) "Spirit Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x37") "Hurry up, kid!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "The " COLOR(LIGHTBLUE) "Light Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x4B") "Hurry!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME ", isn't that...?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "It's that legendary blade..." COLOR(DEFAULT)  FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "The Master Sword!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Find the other Sages" COLOR(RED) "\n"
COLOR(DEFAULT) "and save Hyrule!" FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That scary-looking man took\n"
"off out of here really fast!"
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh so scary...\n"
"Oh so scary..."
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, what do you want?\n"
"I don't have time to talk\n"
"to you!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please...with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Please sell me something...\n"
"Please...with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"No...\n"
"That's not what I want...\n"
"I want " COLOR(RED) "something inside a bottle" COLOR(DEFAULT) "...\n"
"I didn't mean that thing..."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"No...\n"
"I can't take that...\n"
"That's not what I want to buy..."
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, that's " COLOR(LIGHTBLUE) "Blue Fire" COLOR(DEFAULT) "!\n"
"I'll buy it for " COLOR(RED) "150 Rupees" COLOR(DEFAULT) "!\n"
"All sales final, OK?"
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, a " COLOR(PURPLE) "Fish" COLOR(DEFAULT) "!\n"
"I'll buy it for " COLOR(RED) "100 Rupees" COLOR(DEFAULT) "!\n"
"All sales final, OK?"
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, it's a cute little " COLOR(ADJUSTABLE) "Bug" COLOR(DEFAULT) "!\n"
"I'll buy it for " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!\n"
"All sales final, OK?"
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, a darling little " COLOR(LIGHTBLUE) "Fairy" COLOR(DEFAULT) "!\n"
"I'll buy it for " COLOR(RED) "25 Rupees" COLOR(DEFAULT) "!\n"
"All sales final, OK?"
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...you are quite an energetic\n"
"young man. You're brave and\n"
"handsome, too." BOX_BREAK UNSKIPPABLE "Heh heh heh...your name is\n"
NAME ", isn't it." BOX_BREAK UNSKIPPABLE "Heh heh he...don't be surprised.\n"
"I can read people's minds." BOX_BREAK UNSKIPPABLE "If I looked as good as you, I\n"
"could run a different kind of \n"
"business...heh he heh..." BOX_BREAK UNSKIPPABLE "My shop is the only " COLOR(RED) "Ghost Shop" COLOR(DEFAULT) "\n"
"in Hyrule." BOX_BREAK UNSKIPPABLE "Because of the great Ganondorf, \n"
"it is a fine time for a business \n"
"like this...heh heh heh..." BOX_BREAK UNSKIPPABLE "Oh...I can only hope the world \n"
"gets even worse!" BOX_BREAK UNSKIPPABLE "The ghosts, called " COLOR(RED) "Poes" COLOR(DEFAULT) ", are \n"
"spirits of concentrated hatred \n"
"that appear in the fields and \n"
"graveyard. They hate the world!" BOX_BREAK UNSKIPPABLE "Young man, if you catch a Poe, I\n"
"will pay a lot of money for it...\n"
"Heh heh hee!"
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, young man. What's happening \n"
"today? If you have a " COLOR(RED) "Poe" COLOR(DEFAULT) ", I will \n"
"buy it." BOX_BREAK "Your card now has " COLOR(PURPLE)  HIGHSCORE(HS_POE_POINTS) " " COLOR(DEFAULT) "points.\n"
"Come back again!\n"
"Heh heh heh!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, you brought a Poe today!" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Hmmm..." BOX_BREAK UNSKIPPABLE "This is a " COLOR(RED) "normal" COLOR(DEFAULT) " " COLOR(RED) "Poe" COLOR(DEFAULT) ".\n"
"Here are your " COLOR(RED) "10 Rupees" COLOR(DEFAULT) ".\n"
"Take them." BOX_BREAK UNSKIPPABLE "Heh heh."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, you brought a Poe today!" BOX_BREAK UNSKIPPABLE "Hmmmm!" BOX_BREAK UNSKIPPABLE "Very interesting!\n"
"This is a " COLOR(RED) "Big Poe" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "I'll buy it for " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "On top of that, I'll put " COLOR(RED) "100\n"
"points " COLOR(DEFAULT) "on your card." BOX_BREAK UNSKIPPABLE "If you earn " COLOR(RED) "1,000 points" COLOR(DEFAULT) ", you'll\n"
"be a happy man! Heh heh."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wait a minute! WOW!" BOX_BREAK UNSKIPPABLE "You have earned " COLOR(RED) "1,000 points" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Young man, you are a genuine\n"
COLOR(RED) "Ghost Hunter" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Is that what you expected me to\n"
"say? Heh heh heh!" BOX_BREAK UNSKIPPABLE "Because of you, I have extra\n"
"inventory of " COLOR(RED) "Big Poes" COLOR(DEFAULT) ", so this will\n"
"be the last time I can buy a \n"
"ghost." BOX_BREAK UNSKIPPABLE "You're thinking about what I \n"
"promised would happen when you\n"
"earned 1,000 points. Heh heh." BOX_BREAK UNSKIPPABLE "Don't worry, I didn't forget.\n"
"Just take this."
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh? What's that?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Is" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "that" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "a fairy" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!" BOX_BREAK UNSKIPPABLE "Then, are you...\n"
"Are you from the forest?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Then...then...you wouldn't happen to\n"
"have...the " COLOR(ADJUSTABLE) "Spiritual Stone of the \n"
"Forest" COLOR(DEFAULT) ", would you?! That green \n"
"and shining stone..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I had a dream...In the dream,\n"
"dark storm clouds were billowing\n"
"over the land of Hyrule..." BOX_BREAK UNSKIPPABLE "But suddenly, a ray of light shot\n"
"out of the forest, parted the\n"
"clouds and lit up the ground..." BOX_BREAK UNSKIPPABLE "The light turned into a figure\n"
"holding a " COLOR(ADJUSTABLE) "green and shining stone" COLOR(DEFAULT) ",\n"
"followed by a " COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I know this is a prophecy that\n"
"someone would come from the\n"
COLOR(ADJUSTABLE) "forest" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Yes, I thought you might\n"
"be the one..." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Oh, I'm sorry!" BOX_BREAK UNSKIPPABLE "I got carried away with my story \n"
"and didn't even properly introduce \n"
"myself!" EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0C") "I am " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ", Princess of Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What? Have we met before?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Awww... That's so cute!\n"
"Could you tell me where you\n"
"found it?"
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeeeah!\n"
"Help me!"
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh...yeah? So what?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I hate foxes!"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How irritating!"
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, you look good!"
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "YEEEAH! What's your problem?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh...is that a Zora?\n"
"Those cool eyes are really\n"
"fascinating..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh no! You're scary!\n"
"Don't come any closer!"
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow...how nostalgic! That\n"
"reminds me of when I was a\n"
"little kid."
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's kind of funny...it\n"
"makes me laugh!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Uh-oh!" QUICKTEXT_DISABLE " I'm sorry, mom!\n"
"Oh...hey, it's you!\n"
"Don't scare me like\n"
"that!"
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What a big head you have!"
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, don't do that!\n"
"I'm shy..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Is there a mask competition\n"
"going on? \n"
QUICKTEXT_ENABLE "I'm going to vote for you!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! A rabbit!\n"
"Speaking of rabbits, I saw a \n"
"strange man chasing rabbits \n"
"around..."
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh, what a pretty lady!\n"
"But you're kind of short,\n"
"aren't you?"
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well...I can't think of anything\n"
"funny to say...sorry, kid!"
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A mask... When I was a little \n"
"kid, I also wore masks around...\n"
"What? You say you can't imagine\n"
"me doing that?"
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohhhh...I see...\n"
"It's an illusion..."
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, kid, don't grow up to be\n"
"like me..."
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AAAAAAAAAAAH!\n"
"A GERUDO!!!!" QUICKTEXT_DISABLE  BOX_BREAK "Wha-? A mask?\n"
"Why do you have a mask \n"
"like that?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sorry, I'm busy right now."
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh wow! It's Keaton!\n"
"Hi, Keaton!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How spooky!\n"
"There's a boy in Kakariko\n"
"Village who was looking for a\n"
"mask like that!"
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm...well...don't you have any\n"
"other masks?"
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What a strange mask!\n"
"Hee hah haa!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey kid! Can't you see we're\n"
"busy?! Leave us alone!"
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm sorry. I don't even want to\n"
"look at any other woman!"
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee.\n"
"Don't pay any attention to that\n"
"kid, my dear... Just pretend we're\n"
"in our own, private little world..."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, please!\n"
"Go bother someone \n"
"else!"
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"There's a rumor going around that\n"
"there is a Potion Shop that can\n"
"make the ultimate medicine!"
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I heard a rumor that there is a \n"
"monster that eats " COLOR(LIGHTBLUE) "Hylian Shields" COLOR(DEFAULT) "\n"
"somewhere out there in the world.\n"
"Have you ever seen it?"
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I came here to sell bombs...\n"
"Please buy some!"
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I...I am afraid...\n"
"I have a feeling that man is going\n"
"to destroy Hyrule." BOX_BREAK UNSKIPPABLE "He has such terrifying power!" BOX_BREAK UNSKIPPABLE "But it's fortunate that you have \n"
"come..." EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What? If you want something,\n"
"just make it clear!"
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm busy! Get out of my way,\n"
"you bum!"
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, you have some good,\n"
"quality wood there, kid!"
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm!\n"
"Get out of my face!\n"
"You good for nothin'..."
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"EEEEEEAAAAH!\n"
"Whoops, I shouldn't scream like\n"
"that or the boss will yell at me!"
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, sorry boss! \n"
"I didn't mean to slack off!\n"
"I'll get busy!" BOX_BREAK "Oh, that's not you, boss?"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gerudos are beautiful and brave...\n"
"They are just so fascinating!"
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Someday, when I have more skill,\n"
"I'll carve a mask like that one!"
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, that's the mask\n"
"everyone is talking about!\n"
"Looks kind of strange..."
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wa-ha-hah!\n"
"How's business,\n"
"Mr. Hero?\n"
"Hah hah hah!"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm on duty.\n"
"Understand?\n"
"ON DUTY!"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm, well, I don't really know\n"
"what to say about that one..."
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh wow! Cute!\n"
"But Cuccos are much cuter!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eh, what?\n"
"Are you sad?\n"
"Happy?\n"
"I really can't tell..."
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm sorry, I'm not really\n"
"interested in that."
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The little kid playing in the\n"
"graveyard was saying something\n"
"about his face..."
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I really am a good man.\n"
"Don't you believe me?"
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHAAAA--!\n"
"I thought you were that old hag!\n"
"Don't scare me like that!"
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I remember my father talking\n"
"about a swordsmith...but that\n"
"doesn't really matter to me\n"
"anyway."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm not afraid of any forest \n"
"monsters! Are you trying to\n"
"make fun of me?"
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What is that? I can't see it\n"
"very well from here..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi again! How are you today?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Everything's fine today!"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tired...I'm so tired..."
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I don't care about any\n"
"foxes!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's irritating!\n"
"It bothers my eyes!"
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That looks quite handsome!"
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaaaah!\n"
"What is wrong with you?\n"
"Do you have a bad attitude?"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You idiot! \n"
"When you talk to someone, you\n"
"should make eye contact!"
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You idiot!\n"
"When you talk to someone, you\n"
"shouldn't stare!"
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You idiot!\n"
"When you talk to someone, you\n"
"should take off your mask!"
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You idiot!\n"
"I don't know why I'm calling\n"
"you that, but...you are one!"
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Where did you get that?\n"
"What?\n"
"It's a mask?"
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh, leave me alone...\n"
"Can't you see I'm in a groove\n"
"right now?"
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A mask is just like a musical \n"
"instrument--it reflects the\n"
"character of its owner. I like\n"
"your originality, kid!"
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What a big head!\n"
"How'd you fit through that door?!"
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I HATE foxes, sonny!"
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Now if that isn't the most\n"
"irritating face I've seen in\n"
"all my days, I don't know what\n"
"is!"
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, that's a fine face\n"
"you got there, sonny!"
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Have you got any complaints?\n"
"Speak up, then!"
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please quit playing around\n"
"and dispel our curse!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If I wore something like that...\n"
"I'd be a real Skulltula...\n"
"AAAAAAAAAAH!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please understand if I don't\n"
"laugh... It's hard to be happy\n"
"in this condition... \n"
"Being cursed and all..."
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "Hyaaaaah!\n"
"That's scary!\n"
"I know I'm scary, but...man!\n"
"That's really scary!"
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh?! Wha--!" BOX_BREAK "Oh, it's just a kid.\n"
"Don't scare me like that!\n"
"I may not look like it, but I'm a\n"
"very sensitive guy!"
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well, will you lookit the noggin on \n"
"this kid! It's HUGE!\n"
"Mine is huge too, though..."
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you know what kind of\n"
"mask you're wearing...?\n"
"And you're still wearing it?"
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'm on duty now... \n"
"If you want me to dig, don't\n"
"bother me."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What is that? It's something\n"
"that hops around in a field...\n"
"I forgot what those things are\n"
"called..."
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! It's a Keaton Mask!!\n"
"I asked my daddy to get me one,\n"
"too!"
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's not very different from\n"
"Mr. Dampé, is it?"
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That doesn't look anything like\n"
"Mr. Dampé, huh?"
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Hey, cool mask...but a little\n"
"scary, don't you think?"
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! That looks familiar...\n"
"I think I saw something like it\n"
"in the Lost Woods, no?"
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "That makes me feel...happy..."
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...uh...sniff...\n"
"That mask...\n"
"It makes me feel...sad..."
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah! That mask won't do you any\n"
"good! You're just afraid of me,\n"
"the great Mido...aren't you?!"
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaah! What?\n"
"Hey, I'm not scared of you!\n"
"Just don't come any closer,\n"
"understand?!"
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, that's a cool mask.\n"
"I want it!\n"
"JUST KIDDING! Hah!\n"
"I don't want that stupid mask!"
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah ha hah!\n"
"That really suits you!"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaah!\n"
"I-I'm gonna tell Mido about \n"
"this!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeeeeah!\n"
"I-I'm gonna tell Mido to beat\n"
"you up!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whooooah!\n"
"Are you some kind of forest\n"
"ghost?"
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's so cool!\n"
"Uh...don't tell Mido I said that!"
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What?!\n"
"You came back!\n"
"I can tell who you are, even\n"
"with that mask on!"
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I wonder what Mido would say if\n"
"he saw that?\n"
"I really would like to see his\n"
"reaction!"
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I see...\n"
"You're going to scare Mido with\n"
"that mask, aren't you?!"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah hah hah!\n"
"What a funny face!\n"
"I bet Saria would think it's\n"
"pretty funny, too!"
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee hee!\n"
"A mask made of wood?\n"
"It looks like you're wearing\n"
"a shield on your face!"
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What a weird face!" BOX_BREAK "Speaking of weird faces, one of\n"
"the forest kids was complaining\n"
"about his face..."
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What an enormous head you have!"
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee!\n"
"Where did you get that?\n"
"Outside the forest?\n"
"No way! I don't believe it!"
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Kind of funny, but it's not\n"
"really my style..."
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Right on! \n"
"Wearing this mask makes me feel\n"
"really tough and scary!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"There sure are a lot of different\n"
"people in the world!"
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"I don't need a new one...\n"
"I like the one I have, thanks!"
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Wow, that makes your head\n"
"look huge!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "What a cute little mouse!\n"
"What?\n"
"Oh, it's not a mouse?"
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "What are those floppy things\n"
"on your head?\n"
"Ears? That mask makes you look\n"
"like you have four ears!"
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "It must be exciting to sneak\n"
"past the guards while wearing\n"
"that mask!"
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi, fairy boy!\n"
"What?\n"
"You think you're in disguise?\n"
"But it's so obvious who you are!"
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow!\n"
"What big eyes you have!\n"
"Gorons are so cute, aren't they!"
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, I know that character!\n"
"It's Keaton!\n"
"He's very hot in Hyrule Castle\n"
"Town right now!"
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, brother!\n"
"Boys will be boys!"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wait...wait...\n"
"I know who ya are...\n"
"Yer... Kin-ton!\n"
"Ain't that right?!"
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's a scary one, ain't it?\n"
"Almost as scary as...Ingo!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, that reminds me of my wife...\n"
"On second thought, it doesn't...\n"
"It doesn't look like her at all!"
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAWWN...\n"
"I'm kinda tired right now...\n"
"Show it to me later..."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Scram, kid!\n"
"Can't you see I'm busy?!"
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Humph!\n"
"It's fine to play like that when \n"
"you're a kid, but just wait until\n"
"you grow up! Work, work, work!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YEOW!\n"
"Humph. It's just a mask...\n"
"Scram, kid! Get out of here!"
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh...\n"
"Well, that cheered me up a little,\n"
"kid.\n"
"Thanks!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm... Let's see...\n"
"Yes, I'm quite sure of it...\n"
"That was manufactured from a \n"
"plank from a coffin. Yes, it was!"
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhh...yes. Let's see...\n"
"Very fine craftsmanship.\n"
"But I don't think it would make\n"
"a good ingredient for my medicine."
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Very interesting! A Goron!\n"
"Speaking of Gorons, I wonder\n"
"how my old friend, Biggoron of\n"
"Death Mountain, is doing?"
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Very unusual construction...\n"
"I don't think it's water soluble,\n"
"so it wouldn't make a good \n"
"ingredient for my medicines..."
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"OK, OK, a mask.\n"
"Do you want to buy some beans?"
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Nope, I don't want to buy it."
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Nope, it's not my style."
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Well...no, I don't think I \n"
"want it."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What do you want?"
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You don't look like you can\n"
"swim very well..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Red hair...tan skin...\n"
"I've seen people like that before..."
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeah, right.\n"
"You look a little small for a\n"
"Zora..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho ho ho!\n"
"You Hylians...you are such silly\n"
"creatures!"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That face...it gives me the chills..."
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Talk about a nostalgia trip!\n"
"That reminds me of my childhood\n"
"friend, Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I don't think that's funny at all.\n"
"Are you mocking me?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're a funny guy!"
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Your head--it's gigantic!"
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Don't do that...\n"
"It's embarrassing me!"
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All right! You actually decided\n"
"to become a Zora!\n"
"Are you actually ready to marry\n"
"me now?"
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHOA!\n"
"My heart...started to beat \n"
"so fast!"
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's an unpleasant mask...\n"
"Good-bye."
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm...\n"
"I don't know what to say."
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You shouldn't be so picky about\n"
"what you eat! Do you eat all your\n"
"green rocks? If you don't, you \n"
"won't grow up big and strong!"
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Leave me alone!"
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Are you trying to make me laugh?\n"
"Well, that's not that funny..."
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're making me mad!"
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I hate Gerudos!!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quit pestering me!\n"
"Go away!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah!\n"
"Do you think you're in disguise?\n"
"How funny!"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Out of my way!\n"
"Get out of here!\n"
"You're asking for it, aren't you?"
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, kid, you've got guts coming\n"
"around here wearing that!\n"
"Still, you can't fool us that\n"
"easily!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What is that?\n"
"What does it have to do with\n"
"us?"
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"You've got guts to spare, don't\n"
"you kid? \n"
"I like you!"
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'mon! It's time to get serious!"
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's odd...it kind of looks like\n"
"me...\n"
"No...not really.  Not at all,\n"
"if you look at it closely."
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm. No, no, no!\n"
"The ears aren't right at all!\n"
"They should be, you know, longer!"
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aren't you kind of scared, \n"
"walking around in the middle of\n"
"the night looking like that?"
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"You really like those things,\n"
"don't you?!"
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I think I've seen a stone that\n"
"looks like that somewhere...\n"
"Now where was that?\n"
"Hmmmm...."
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hurry up, " NAME "!\n"
"Any second now, the tower is \n"
"going to collapse!!"
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Watch out for falling rubble!"
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "!\n"
"Help me!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"The exit is just over there!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Thank you, " NAME ".\n"
"Now, let's hurry!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Too bad!" BOX_BREAK "Practice hard and come back!" EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Almost!!" BOX_BREAK "Well...all right!\n"
"I'll let you try one more time for\n"
"free...\n"
"This time, you gotta do it!" EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wonderful!!!\n"
"Bravo!!!\n"
"Perfect!!!" BOX_BREAK "Here's a fantastic present!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh, no! " COLOR(RED) "Time's up!\n"
COLOR(LIGHTBLUE) "The thing you were going to \n"
"deliver has spoiled!\n"
"Let's try again!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "BOINNG! BOINNG!\n"
"The current time is: " TIME "!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You heard about us from the\n"
"guard at Death Mountain gate?\n"
"Well, I have to give\n"
"you a good deal then!"
)

