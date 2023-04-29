DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "Ti presta un " COLOR(RED) "Uovo Magico" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Un piccolo Cucco si schiudera'\n"
"dopo la notte. Ricordati che lo \n"
"dovrai restituire.             "
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "Restituisci il Cucco e prendi\n"
"un " COLOR(RED) "Cojiro" COLOR(DEFAULT) " in cambio!" QUICKTEXT_DISABLE "\n"
"Non é come gli altri Cucco,     \n"
"canta poco..."
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Ti da uno " COLOR(RED) "Strano Fungo" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Un fungo fresco come questo  \n"
"si guasta velocemente! Portalo \n"
"al negozio di Pozioni, fai presto!! "
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "Ti consegna una " COLOR(RED) "Strana Pozione" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Potrebbe essere utile...     \n"
"Corri ai Boschi Perduti!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "Consegnata l'insolita Pozione\n"
"ottieni una" COLOR(RED) " sega usata" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Lo strano ragazzo deve\n"
"averla dimenticata...  "
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombe   20 Pezzi    80 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "Ricevi una\n"
COLOR(RED) "Borsa Porta-Semi Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Questa borsa puo' contenere\n"
"fino a " COLOR(YELLOW) "40" COLOR(DEFAULT) " semi.  "
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "Hai scambiato la sega usata  \n"
"con una " COLOR(RED) "Spada Goron rotta" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Vai da Biggoron per ripararla!    "
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "Hai controllato la Spada Goron  \n"
"e hai trovato una " COLOR(RED) "Ricetta" COLOR(DEFAULT) "!           " QUICKTEXT_DISABLE "\n"
"Vai dal Re Zora! "
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "La Spada Biggoron...   " QUICKTEXT_DISABLE "\n"
"Ottieni un" COLOR(RED) " Buono Ritiro Spada" COLOR(DEFAULT) "!\n"
"Devi solo aspettare che\n"
"sia riparata...     "
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Hai barattato la Grossa Lama  \n"
"per la " COLOR(RED) "Spada Biggoron  " COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"La lama, forgiata da un Mastro\n"
"Fabbro, é indistruttibile!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Mostrando il Buono di Ritiro,\n"
"ottieni la " COLOR(RED) "Spada Biggoron" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"E' stata forgiata da un\n"
"Mastro Fabbro, non si rompera'!  "
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "Hai usato la Ricetta e hai\n"
"ottenuto un " COLOR(RED) "Occhio di Rana" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Svelto, portalo al grande Lago \n"
"Hylia finche' é freddo!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "Scambi l'Occhio di Rana     \n"
"per le " COLOR(RED) "Lacrime Strabilianti" COLOR(DEFAULT) "!     " QUICKTEXT_DISABLE "\n"
"Corri! Portale al Biggoron \n"
"prima che sia tardi!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x41")  COLOR(RED) "VINTO!!!" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "Prestata la " COLOR(RED) "Maschera Teschio" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e la indosserai!   \n"
"Ti sentirai un vero Mostro\n"
"con questa maschera!!  "
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "Prendi una " COLOR(RED) "Maschera Demone" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!     \n"
"Spaventerai la gente con\n"
"questa maschera!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "Prendi una " COLOR(RED) "Maschera Keaton" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!    \n"
"Sarai molto popolare con  \n"
"questa maschera!"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "Prestata una " COLOR(RED) "Bugs Bunny" COLOR(DEFAULT) ".  " QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!\n"
"Le lunghe orecchie divertono!         "
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "Prestata: " COLOR(RED) "Maschera Goron" COLOR(DEFAULT) ". " QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!     \n"
"Rendera' la tua testa piu'...\n"
"GROSSA! .."
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "Prestata: " COLOR(RED) "Maschera Zora" COLOR(DEFAULT) ". " QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!     \n"
"Con questa maschera, \n"
"diverrai uno degli Zoras! "
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "Prestata: " COLOR(RED) "Maschera Gerudo" COLOR(DEFAULT) ". " QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e te la metterai!     \n"
"Ti permettera' di sembrare \n"
"una...ragazza??"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "Presa " COLOR(RED) "Maschera della Verita'" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e la indosserai!      \n"
"Mostrala pure a tutti! "
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Benvenuto al Centro del puro\n"
"divertimento:    "
BOX_BREAK
SHIFT("\x15")  COLOR(RED) "Il Vicolo Bombchu-Bowling!" COLOR(DEFAULT)
BOX_BREAK
"Vuoi sapere cosa potresti\n"
"vincere? Beh, é un " TEXT_SPEED("\x03") "segreto." TEXT_SPEED("\x00") "\n"
"Non posso dirtelo finche' non paghi\n"
"per giocare. "
BOX_BREAK
"Sono " COLOR(RED) "30 Rupié " COLOR(DEFAULT) "ogni partita.\n"
"Vuoi giocare?    \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "OKAY!!" QUICKTEXT_DISABLE
BOX_BREAK
"Mira al buco che e' al centro. \n"
"Tira il " COLOR(RED) "Bombchu " COLOR(DEFAULT) "e vai! \n"
"Hai " COLOR(RED) "10 chance" COLOR(DEFAULT) ". Pronto.."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "VAI ORA!!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi giocare ancora?      \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, dimenticavo!\n"
"Ecco cosa potrai vincere:    " EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombe   (20 pezzi)    80 Rupié \n"
COLOR(DEFAULT) "Estraile con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e premi ancora\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per lanciarle. Non le puoi\n"
"comprare senza la borsa bombe." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombe   (30 pezzi)    120 Rupié \n"
COLOR(DEFAULT) "Estraile con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e premi ancora\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per lanciarle. Non le puoi\n"
"comprare senza la borsa bombe." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombe   30 pezzi    120 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono felice che ogni cosa\n"
"sia a posto!!  "
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salva un altro dei miei fratelli!\n"
"Sono sicuro che otterrai\n"
"qualcosa di persino migliore!"
BOX_BREAK
"Lo farai?!    "
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La maledizione é spezzata!\n"
"GRAZIE!!  \n"
"Questa e' la ricompensa!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aargh! La Maledizione!!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stai attento a non essere \n"
"colpito ancora"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un momento!\n"
"Hai ucciso " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Ragni Maledetti!\n"
"La Maledizione si sta indebolendo!   "
BOX_BREAK
"I ragazzi che sono ritornati\n"
"normali ti ricompenseranno?!"
BOX_BREAK
"Devi sapere che il modo migliore\n"
"per diventare " COLOR(DEFAULT) "ricchi" COLOR(DEFAULT) ", é eliminare \n"
"il maggior numero di Ragni  \n"
"Maledetti!! "
BOX_BREAK
"Ci sono dei trucchi per scovarli tutti!\n"
"Innanzitutto, cacciali anche di notte.\n"
"Poi, ricordati che amano stare\n"
"nel terreno soffice...     "
BOX_BREAK
"Controlla tutto cio' che ti circonda!   \n"
"Per favore, contiamo su di te!!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Noi siamo cosi' per colpa della \n"
"Maledizione. Ma se...  " TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noi siamo cosi' per colpa della \n"
"Maledizione del Ragno."
BOX_BREAK
"Se ogni" COLOR(RED) " Ragno Maledetto   " COLOR(DEFAULT) "  \n"
"nel regno intero sara' ucciso,  \n"
"la Maledizione finira'... "
BOX_BREAK
"Quando uccidi uno dei Ragni,  \n"
"apparira' un simbolo magico. Prendilo,\n"
"sara' la prova del tuo successo."
BOX_BREAK
ITEM_ICON("\x71") "Il numero accanto all'" COLOR(YELLOW) "Icona" COLOR(DEFAULT) ",   \n"
"sul " COLOR(LIGHTBLUE) "SottoMenu Quest Status" COLOR(BLUE) " \n"
COLOR(DEFAULT) "indica quanti Ragni Maledetti hai \n"
"distrutto sino ad ora.          "
BOX_BREAK
ITEM_ICON("\x71") "Quando l'" COLOR(YELLOW) "icona" COLOR(DEFAULT) " appare accanto\n"
"al nome dell'area sul         \n"
COLOR(RED) "SottoMenu Mappa" COLOR(DEFAULT) ", non ci sono   \n"
"altri Ragni in quell'area." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se libererai la mia Famiglia\n"
"dalla Maledizione,\n"
"ti faro' " COLOR(DEFAULT) "ricco" COLOR(DEFAULT) "!..."
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Poiche' hai distrutto  " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Ragni Maledetti,la Maledizione e' stata\n"
"spezzata...    "
BOX_BREAK
UNSKIPPABLE "Grazie! Questo é un segno della \n"
"mia gratitudine! Prendilo... " EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie hai salvato i piccoli."
BOX_BREAK
"Cosa? Io? Oh, pazienza... "
BOX_BREAK
"Hai gia' distrutto ben " COLOR(RED)  TOKENS  COLOR(DEFAULT) "    \n"
"Ragni Maledetti, dunque...        \n"
"Non ti devi preoccupare per me...    "
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu   20 Pezzi    180 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi giocare una partita?  \n"
"Costa" COLOR(RED) " 20 Rupie " COLOR(DEFAULT) "         \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Non puoi!  Non hai l'arco!" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va bene.\n"
"Non devi mica farlo per forza!!               " EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OKAY!!" QUICKTEXT_DISABLE "\n"
"Questo é un gioco da adulti!\n"
"Il Famosissimo " COLOR(RED) "Tiro al Bersaglio" COLOR(DEFAULT) "!"
BOX_BREAK
"Prendi la mira al bersaglio dalla \n"
"piattaforma li' sopra! \n"
"Colpirai " COLOR(RED) "10 Bersagli" COLOR(DEFAULT) "?\n"
"Hai solo" COLOR(RED) " 15" COLOR(DEFAULT) " colpi!     "
BOX_BREAK
"Estrai l'arma premendo " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".\n"
"Sei pronto?   \n"
"Vai per il record! \n"
"Buona Fortuna!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' una piccola pozza di\n"
"terreno soffice."
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "Hai trovato la" COLOR(RED) " Fionda Magica" COLOR(DEFAULT) "!  \n"
"Sul " COLOR(YELLOW) "Sottomenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarla a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x06") "Premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per estrarla e armarti.\n"
"Premendo " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "potrai mirare      \n"
"con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Lascia " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e tirerai   \n"
"i " COLOR(RED) "Semi Deku" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x06") "Se vuoi tirare con maggior \n"
"cura, una volta premuto " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"non rilasciarlo subito\n"
"il tiro sara' di sicuro migliore. "
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "Trovi l'" COLOR(RED) "Arco Magico" COLOR(DEFAULT) "!    " QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x03") "Premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per estrarlo e\n"
"afferrarlo. Tieni premuto    \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e poi mira con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". " COLOR(YELLOW)  COLOR(DEFAULT) "Lascia   \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per scagliare la " COLOR(RED) "Freccia" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Prese le" COLOR(RED) " Bombe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",  \n"
"puoi assegnarle a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x02") "Usa " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per piazzarle.   \n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " mentre corri per\n"
"lanciarle. Hai visto qualcosa\n"
"di sospetto, bombardalo!!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "Presa la" COLOR(RED) " Bombchu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarla a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x09") "Per tirarla premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".    \n"
"E' un nuovo tipo di bomba che\n"
"si arrampica sui muri. \n"
"Mira bene e lanciala!!  "
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Trovi le " COLOR(RED) "Noci Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",   \n"
"puoi assegnarle a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x01") "Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", e prova a tirarle! \n"
"Scoppieranno, stordendo\n"
"i tuoi nemici. "
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Boomerang" COLOR(DEFAULT) "!     " QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selez. Items" COLOR(DEFAULT) ",  \n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0E") "Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per attaccare\n"
"dei nemici a distanza! "
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "Hai trovato l'" COLOR(RED) "Arpione" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"E' munito di una catena a molla\n"
"puoi tirarlo ed agganciare cose."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0A") "Potrai trascinare  \n"
"oggetti lontani verso di te, o\n"
"usarlo per issarti verso qualche \n"
"direzione.      "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0A") "Tieni premuto " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", e mira\n"
"spostando " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Per sparare\n"
"rilascia " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Ottieni il" COLOR(RED) " Ramo Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vai al " COLOR(YELLOW) "Sottomenu Selez.Item" COLOR(DEFAULT) ", \n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x00") "Usalo con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e colpisci  \n"
"con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "! "
BOX_BREAK
ITEM_ICON("\x00") "Quando lo vuoi riporre fermati\n"
"un attimo, poi premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".  \n"
"Puoi portare sino a 10 Rami,  \n"
"ma non li sprecare.  "
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Martello Megaton" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per spaccare tutto!\n"
"E' talmente pesante, che ti\n"
"servono due mani per usarlo!    "
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Lente della Verita'" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assegnala a " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per\n"
"esaminare le cose! Ci sono \n"
"misteri nascosti ovunque!    "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0F") "Assicurati di usarla al di fuori\n"
"del pozzo. Guardare con la lente\n"
"consuma magia, percio' premi " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "di nuovo per riporla.  "
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Ottieni l' " COLOR(RED) "Ocarina del Tempo" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Questo e' il tesoro segreto della \n"
"Famiglia Reale che Zelda ha perso.\n"
"Emana una luce mistica...       "
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Usi il Vento di Farore!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Ritorna al Teletrasporto\n"
"Spegni Teletrasporto \n"
"Esci" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "Ricevi il " COLOR(RED) "Medaglione del Fuoco" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Riaffiora il Saggio in Darunia e\n"
"ti dona il suo potere!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "Ricevi il " COLOR(BLUE) "Medaglione dell'Acqua" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Riaffiora il Saggio in Ruta,\n"
"ti dona il suo potere!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "Ricevi il " COLOR(ADJUSTABLE) "Medaglione della Foresta" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"Riemerge il Saggio in Saria e\n"
"ti dona il suo potere!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "Ricevi il " COLOR(YELLOW) "Medaglione Spirituale" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Riaffiora il Saggio in Nabooru\n"
"e ti dona il suo potere!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "Ricevi il " COLOR(LIGHTBLUE) "Medaglione della Luce" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru il Saggio ti dona il suo \n"
"potere! "
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "Ricevi il " COLOR(PURPLE) "Medaglione del Buio" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"Riaffiora il Saggio in Impa\n"
"e ti dona il suo potere!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Bottiglia Vuota" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Quando metterai qualcosa nella\n"
"bottiglia, premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e potrai  \n"
"usare cio' che c'é dentro. "
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "Hai la " COLOR(RED) "Pozione Rossa" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selez. Items" COLOR(DEFAULT) ",\n"
"assegnala a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x15") "Bevila con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", recupererai  \n"
"Energia Vita.   \n"
"Puoi portare la pozione in\n"
"una tua bottiglia."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "Prendi la " COLOR(ADJUSTABLE) "Pozione Verde" COLOR(DEFAULT) "!\n"
"Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",\n"
"assegnala a  " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x16") "Bevila con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e recupererai\n"
"Potere Magico.   \n"
"Puoi portare la pozione in\n"
"una tua bottiglia."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "Prendi la " COLOR(BLUE) "Pozione Blu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Bevila con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e recupererai\n"
"Energia Vita e Potere Magico.    "
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "Hai imbottigliato una " COLOR(RED) "Fatina" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Sul " COLOR(YELLOW) "SottoMenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarla a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
ITEM_ICON("\x18") "Questa Fatina e' un ottima \n"
"fonte di energia Vita nel \n"
"momento in cui ti troverai\n"
"in difficolta'!!"
BOX_BREAK
ITEM_ICON("\x18") "Assegnala ai tasti " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"e avrai il suo aiuto in ogni\n"
"momento...  "
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "Hai preso un " COLOR(RED) "Pesce" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e qualche cosa \n"
"succedera'...E' talmente\n"
"fresco! Sara' delizioso! "
BOX_BREAK
ITEM_ICON("\x19") "Sul " COLOR(YELLOW) "SottoMenu Selezione Item" COLOR(DEFAULT) ",\n"
"assegnalo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",   \n"
"e di nuovo premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "\n"
"per usarlo.     "
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "E' un " COLOR(RED) "Fagiolo Magico" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trova un punto adatto sul terreno\n"
"e piantalo premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Dopo di\n"
"che non dovrai che aspettare!"
BOX_BREAK
ITEM_ICON("\x10") "Sul " COLOR(YELLOW) "Sottomenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", \n"
"e poi piantarlo premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".     "
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi dispiace tanto..OK, bene..."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "SI BOCCIA" COLOR(DEFAULT) "!!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "Hai ricevuto l'" COLOR(RED) "Ocarina Fatata" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Questo e' un ricordo di Saria.\n"
"Attivala con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", e poi prova\n"
"a farla suonare!   "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x07") "Sul " COLOR(YELLOW) "SottoMenu Selezione Item" COLOR(DEFAULT) ",\n"
"puoi assegnarla a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e poi premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",  \n"
"comincerai a suonare."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x07") "Puoi suonare diverse note   \n"
"con: " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e i quattro " COLOR(YELLOW) "[C] Tasti" COLOR(DEFAULT) ".    \n"
"Premi " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " per smettere, oppure\n"
"per ricominciare la canzone.  "
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Prendi la" COLOR(ADJUSTABLE) " Lama Gigante" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Tienila con entrambe le mani, usa\n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "per attaccare. E' enorme, devi\n"
"rinunciare allo " COLOR(LIGHTBLUE) "Scudo" COLOR(DEFAULT) "!   "
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "Ottieni lo" COLOR(LIGHTBLUE) " Scudo Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Spostati sul " COLOR(BLUE) "SottoMenu  \n"
"Equipagg." COLOR(RED) " " COLOR(DEFAULT) "e seleziona lo\n"
"scudo. Premi " COLOR(BLUE) "[A] " COLOR(DEFAULT) "e indossalo. "
BOX_BREAK
ITEM_ICON("\x3E") "Premi " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " e ti abbasserai\n"
"difendendoti. Con " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " e lo   \n"
COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", ti muoverai  \n"
"difendendoti.   "
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "Prendi lo " COLOR(LIGHTBLUE) "Scudo Hylian" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Attiva il " COLOR(BLUE) "SottoMenu \n"
"Equipaggiam." COLOR(DEFAULT) " e seleziona lo  \n"
"scudo, poi indossalo con " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "Trovi lo " COLOR(LIGHTBLUE) "Scudo Riflettente" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"La superficie liscia dello scudo\n"
"puo' riflettere la luce.\n"
"Premi " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "per usarlo."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "Trovi il " COLOR(RED) "Super Arpione" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' una versione potenziata.\n"
"Si estende il " COLOR(RED) "doppio" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "Ricevi la" COLOR(RED) " Tunica Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' una tunica resistente al calo-\n"
"re di misura XL...Vai in posti\n"
"molto caldi? Nessun problema!  "
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "Prendi la " COLOR(BLUE) "Tunica Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' una tuta subacquea, di una \n"
"misura XL. Indossala, e potrai \n"
"respirare sott'acqua...        "
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "E' " COLOR(ADJUSTABLE) "Pozione Magica" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Aumenta la barra magia!    "
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "Sono " COLOR(RED) "Stivali di Ferro" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Non puoi ne' correre, né\n"
"galleggiare, pesano troppo!"
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "Sono " COLOR(RED) "Stivali Sollevanti" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Con questi misteriosi stivali\n"
"puoi sorvolare il terreno.  \n"
"L'attrito? Niente trazione!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x46") "Puoi persino usarli per  \n"
"camminare brevemente laddove \n"
"il terreno non é solido.\n"
"Coraggio, fidati degli stivali!  "
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hai preso un" COLOR(PURPLE) " Cuore Vita" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"La tua energia vitale aumenta!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Hai potenziato la faretra, \n"
"in " COLOR(RED) "Maxi Faretra" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ora puoi portare sino a    \n"
COLOR(YELLOW) "40 " COLOR(DEFAULT) "frecce!  "
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Hai potenziato la faretra  \n"
"in " COLOR(RED) "Super Faretra" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ora puoi portare ancora piu'\n"
"frecce con te, fino a " COLOR(YELLOW) "50" COLOR(DEFAULT) "!    "
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Borsa Bombe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Questa borsa e' stata ottenuta\n"
"da uno stomaco Dodongo!! "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Ci sono " COLOR(RED) "20 bombe" COLOR(DEFAULT) " dentro!  " QUICKTEXT_DISABLE "\n"
"Assegna le bombe con " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "e falle scoppiare!\n"
"Che ragazzo fortunato!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "Hai la " COLOR(RED) "Maxi Borsa Bombe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ora ne potrai portare con te,\n"
"addirittura " COLOR(YELLOW) "30" COLOR(DEFAULT) "!       "
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "Ora hai una\n"
COLOR(RED) "Super Borsa Bombe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Potrai portare fino a    \n"
COLOR(YELLOW) "40" COLOR(DEFAULT) " Bombe!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Trovi i " COLOR(BLUE) "Guanti d'Argento" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"Indossandoli, proverai un senso \n"
"di potere, come se potessi\n"
"sollevare grossi oggetti con " COLOR(BLUE) "[A]" COLOR(DEFAULT) "! "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x51") "Ma, questi guanti non sono per\n"
"un ragazzino...E poi, hai\n"
"promesso di darli a" COLOR(RED) " Nabooru" COLOR(DEFAULT) ".\n"
"Devi mantenere la parola..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "Trovi i " COLOR(BLUE) "Guanti d'Oro" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Senti ancora piu' potenza nelle\n"
"tue braccia! Potrai afferrare gli\n"
"oggetti con " COLOR(BLUE) "[A] " COLOR(DEFAULT) "e sollevarli su'!!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE "Metti del" COLOR(LIGHTBLUE) " Fuoco Blu" COLOR(DEFAULT) " nella\n"
"bottiglia!" QUICKTEXT_DISABLE "\n"
"Userai questa fiamma magica \n"
"premendo " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " o" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "Ottieni un " COLOR(BLUE) "Portafoglio da Adulti" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"A loro é consentito portare\n"
"molti piu' soldi.\n"
"Porterai sino a " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupié" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "Ottieni il" COLOR(BLUE) " Portafoglio Gigante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' enorme! Ora potrai\n"
"portare sino a " COLOR(YELLOW) "500" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupié" COLOR(DEFAULT) ".   "
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Trovi una " COLOR(RED) "Piccola Chiave" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Potrai aprire una porta\n"
"chiusa. La potrai usare solo\n"
"nei dungeons.  "
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (20 pezzi)   180 Rupié \n"
COLOR(DEFAULT) "Sembra un topo giocattolo, ma\n"
"é una bomba auto-propellente!         \n"
"     " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pozione Rossa 40 Rupié" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pozione Rossa 50 Rupié" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pozione Rossa 40 Rupié\n"
COLOR(DEFAULT) "Se la bevi, recupererai    \n"
"rapidamente energia-vita.\n"
"E' una dose singola.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pozione Rossa 50 Rupié\n"
COLOR(DEFAULT) "Se la bevi, recupererai    \n"
"rapidamente energia-vita.\n"
"E' una dose singola.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Mappa dei Dungeon" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Premi " COLOR(RED) "START" COLOR(DEFAULT) " e vai al Quadro\n"
"Menu', controlla il \n"
COLOR(RED) "SottoMenu Mappa" COLOR(DEFAULT) "!    "
BOX_BREAK
ITEM_ICON("\x76")  COLOR(BLUE) "Le camere blu" COLOR(DEFAULT) " sono posti \n"
"che hai gia' visitato.    \n"
"La tua posizione attuale\n"
"e' " COLOR(LIGHTBLUE) "Lampeggiante" COLOR(DEFAULT) ".   "
BOX_BREAK
ITEM_ICON("\x76") "Muovi " COLOR(LIGHTBLUE) "[Control-Pad] su e giu' " COLOR(DEFAULT) "per \n"
"selezionare il piano.  "
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "Trovi una" COLOR(RED) " Bussola" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"Ora potrai vedere la posizione\n"
"di molte cose nascoste nei  \n"
"dungeon!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "Ottieni la " COLOR(RED) "Pietra dell'Agonia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Se hai il " COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", (non credo)\n"
"reagira' vicino ai...segreti."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "Ottieni la " COLOR(RED) "Lettera di Zelda" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Wow! In questa lettera c'e' la\n"
"firma di Zelda! Assegnala a " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"e mostrala con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".  "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x23") "Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",   \n"
"puoi assegnarla a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", \n"
"e poi premere " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per mostrarla\n"
"alla gente."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE " Salve!  Posso aiutarti?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Vuoi comprare \n"
"Guarda pure " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Intendi comprare qualcos'altro?\n"
"     " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "La " COLOR(RED) "Borsa Porta-Semi Deku  \n"
COLOR(DEFAULT) "e' piu' grande ora!" QUICKTEXT_DISABLE "\n"
"Puoi portare piu' munizioni! \n"
"Infatti contiene ben" COLOR(YELLOW) " 50" COLOR(RED)  COLOR(DEFAULT) " colpi! "
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Apri il baule e...Sorpresa!!  \n"
"Se trovi una chiave, sarai in \n"
"grado di avanzare. Sinistra o\n"
"destra? Buona Fortuna!"
BOX_BREAK
COLOR(RED) "10 Rupié " COLOR(DEFAULT) "per poter giocare.\n"
"Vuoi provare? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grande! Sei un vero giocatore!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Trovi la " COLOR(ADJUSTABLE) "Rupia' Verde" COLOR(DEFAULT) "!\n"
"Vale " COLOR(ADJUSTABLE) "Una Rupia" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "Hai le " COLOR(RED) "Frecce di Fuoco" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assegnale a " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e le tue frecce \n"
"si potenzieranno! Se colpirai\n"
"il bersaglio, si infiammera'! "
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "Trovi le " COLOR(BLUE) "Frecce di Ghiaccio" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e le tue frecce si\n"
"potenzieranno! Colpisci il bersaglio\n"
"e si congelera'!  "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0C") "Queste magie per le frecce \n"
"sono solo per chi completa il\n"
"difficile allenamento dei Gerudos,\n"
"percio' sii orgoglioso!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "Prendi le " COLOR(LIGHTBLUE) "Frecce di Luce" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Premendo " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "le tue frecce si \n"
"potenzieranno! La Luce della\n"
"Giustizia prevarra'!      "
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x34") "Hai imparato il\n"
SHIFT("\x1F")  COLOR(ADJUSTABLE) "Minuetto dei Boschi" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3E") "Hai imparato il\n"
SHIFT("\x37")  COLOR(RED) "Bolero del Fuoco" COLOR(DEFAULT) "!   "
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3D") "Hai imparato la\n"
SHIFT("\x26")  COLOR(BLUE) "Serenata dell'Acqua" COLOR(DEFAULT) "!    "
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42") "Hai imparato il\n"
SHIFT("\x2D")  COLOR(YELLOW) "Requiem dello Spirito" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3B") "Hai imparato il\n"
SHIFT("\x28")  COLOR(PURPLE) "Notturno delle Ombre" COLOR(DEFAULT) "!    "
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3B") "Hai imparato il\n"
SHIFT("\x32")  COLOR(LIGHTBLUE) "Preludio alla Luce" COLOR(DEFAULT) "!    "
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "Ti da il " COLOR(RED) "Braccialetto Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ora puoi prendere i Fiori Bomba!\n"
"Bastera' premere il tasto " COLOR(BLUE) "[A]" COLOR(DEFAULT) "\n"
"dinanzi ai fiori."
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "Preso un " COLOR(RED) "Insettone" COLOR(DEFAULT) "!         " QUICKTEXT_DISABLE "\n"
"Potrai rilasciarlo premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"Questo tipo d'insetto vive    \n"
"in piccole buche nel terreno.     "
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "Ottieni la\n"
COLOR(RED) "Carta di Membro dei Gerudos" COLOR(DEFAULT) "!    " QUICKTEXT_DISABLE "\n"
"Ora puoi accedere al centro di\n"
"allenamento, nel loro rifugio..."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombe  10 pezzi   50 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Frecce  50 pezzi   90 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pesce  200 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Noci Deku   5 Pezzi    15 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "Ottieni lo " COLOR(ADJUSTABLE) "Smeraldo Kokiri" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"E' una delle Pietre Spirituali \n"
"della foresta, ti e' stata  \n"
"affidata dal Grande Albero. "
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "Ottieni il " COLOR(RED) "Rubino dei Gorons" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"E' la Pietra Spirituale del    \n"
"Fuoco ereditata dai Gorons!    "
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "Ottieni lo " COLOR(BLUE) "Zaffiro dei Zoras" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' la Pietra Spirituale della\n"
"Acqua ereditata dagli Zoras!\n"
"   "
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Scegli l'articolo con \n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "sinistra o destra.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parla al padrone \n"
"Esci" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Grazie molte!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Non hai abbastanza soldi!!   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Non lo puoi prendere.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Noci Deku   10 pezzi   30 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ramo Deku   1 pezzo   10 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Scudo Deku    40 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Frecce  10 pezzi    20 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombe  5 pezzi    25 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu  10 pezzi    100 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Non puoi usare il Poe qui! \n"
"Vendilo all'uomo che sta all'entrata\n"
"della Citta'!  "
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pozione Rossa 30 Rupié" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pozione Verde  30 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Adesso puoi portare  \n"
"piu' " COLOR(RED) "Rami Deku" COLOR(DEFAULT) "! \n"
"Ne puoi portare ben " COLOR(YELLOW) "20" COLOR(DEFAULT) " con te! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Adesso puoi portare\n"
"ancora piu'" COLOR(RED) " Rami Deku " COLOR(DEFAULT) "!\n"
"Ne puoi portare ben " COLOR(YELLOW) "30" COLOR(DEFAULT) " con te! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Scudo Hylian    80 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Tunica Goron  200 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Tunica Zora  300 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE " Cuori Energia   10 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Spiacente...Non posso vendertelo\n"
"sino a che non avrai una bottiglia.\n"
"       " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "Preso un " COLOR(RED) "Poe " COLOR(DEFAULT) "nella bottiglia!" QUICKTEXT_DISABLE "\n"
"Puo' accadere  qualcosa ora!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "Hai il " COLOR(RED) "Latte Lon Lon" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' un latte molto nutritivo! \n"
"Se premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "recupererai la tua\n"
"energia-vita!"
BOX_BREAK
ITEM_ICON("\x1A") "Recupererai ben " COLOR(RED) "cinque cuori" COLOR(DEFAULT) "\n"
"a bevuta. Ci sono due \n"
"bevute a bottiglia. "
BOX_BREAK
ITEM_ICON("\x1A") "Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",   \n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e dopo usarlo con " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per bere\n"
"il latte."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "Hai una " COLOR(RED) "Bottiglia Vuota" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Mettici qualcosa dentro e\n"
"premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per usarla...Cosa?\n"
"C'e' gia' qualcosa dentro!? "
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "Ti da uno " COLOR(RED) "Strano Uovo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ehi, ma qualcosa si muove  \n"
"qui dentro! Assegnalo a " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",    \n"
"cosa succedera'?!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x21") "Sul " COLOR(YELLOW) "SottoMenu Selez.Items" COLOR(DEFAULT) ",   \n"
"puoi assegnarlo a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", \n"
"poi premi " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "per usarlo.    "
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Frecce   30 pezzi    60 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"L'articolo piu' richiesto é lo\n"
COLOR(LIGHTBLUE) "Scudo Hylian" COLOR(DEFAULT) ", ma mi sembra\n"
"grosso per te, ragazzino." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ci siamo spostati qui dalla \n"
"citta'. Sono tempi duri questi, ma \n"
"spero tu sia un buon cliente\n"
"per noi ragazzo!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x47") "  Salve!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Scudo Deku    40 Rupié \n"
COLOR(DEFAULT) "Una volta preso, ti difenderai\n"
"con " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". Se esposto al fuoco,\n"
"brucera'!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Frecce  (10 pezzi)    20 Rupié \n"
COLOR(DEFAULT) "Ti serve un arco per usarle. \n"
"Non puoi comprarle se non hai\n"
"un arco.   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Ramo Deku   (1 pezzo)  10 Rupié \n"
COLOR(DEFAULT) "Un lungo ramo si protende dal\n"
"Grande Albero Deku. Puoi usarlo \n"
"come arma, ma si potra' rompere." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Noci Deku  (10  pezzi) 30 Rupié \n"
COLOR(DEFAULT) "Lanciale per stordire i nemici. \n"
"Comprane non piu' di quelle che\n"
"puoi trasportare.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombe   (5  pezzi)   25 Rupié \n"
COLOR(DEFAULT) "Estraile premendo" COLOR(YELLOW) " [C]" COLOR(DEFAULT) " e premi \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per lanciarle. Le puoi comprare\n"
"solo se hai la borsa bombe." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "Trovata la " COLOR(ADJUSTABLE) "Spada Kokiri" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Sul " COLOR(BLUE) "Menu' Equipaggiamento" COLOR(DEFAULT) ", \n"
"selezionala con il cursore e \n"
"indossala con " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x3B") "Questo e' un tesoro nascosto\n"
"dei Kokiri, ma ti sara' prestato\n"
"per un po' di tempo. Pero' alle-\n"
"nati prima di una vera battaglia! "
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pozione Rossa 30 Rupié\n"
COLOR(DEFAULT) "Bevila e recupererai Energia-Vita.\n"
"Questa e' una sola dose.   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pozione Verde  30 Rupié \n"
COLOR(DEFAULT) "Bevila e otterrai Potere x Magia. \n"
"Questa e' una sola dose.   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Ora puoi portare\n"
"piu' " COLOR(RED) "Noci Deku" COLOR(DEFAULT) "!\n"
"Puoi portare sino a " COLOR(YELLOW) "30" COLOR(DEFAULT) " noci!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Ora puoi portare ancora\n"
"piu'" COLOR(RED) "Noci Deku" COLOR(DEFAULT) "! Puoi portare\n"
"sino a " COLOR(YELLOW) "40" COLOR(RED) " " COLOR(DEFAULT) "noci!" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Scudo Hylian    80 Rupié \n"
COLOR(DEFAULT) "Questo e' uno scudo grosso e  \n"
"pesante usato dai cavalieri Hylian. \n"
"Resiste persino alle fiamme!     " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Tunica Goron  200 Rupié \n"
COLOR(DEFAULT) "Una tunica fatta dai Gorons.  \n"
"Ti proteggera' dal calore intenso. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Tunica Zoran 300 Rupié\n"
COLOR(DEFAULT) "E' costruita dagli Zoras. Misura XL.\n"
"Potrai respirare sott'acqua.\n"
"        " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Cuore Vita       10 Rupié \n"
COLOR(DEFAULT) "Recupererai rapidamente vita  \n"
"utilizzandolo.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE "Hai il " COLOR(RED) "Fuoco di Din" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Una palla di fuoco dirompente! \n"
"Un attacco magico che usi\n"
"premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE "E' il " COLOR(ADJUSTABLE) "Vento di Farore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E' un teletrasporto che usi\n"
"premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Usalo quando\n"
"sei in pericolo!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0D") "Ti smaterializzerai al " COLOR(ADJUSTABLE) "Punto \n"
"Warp" COLOR(DEFAULT) ". Quando usi questa magia\n"
"la prima volta, crei un Punto\n"
"Warp. "
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0D") "Quando la userai di nuovo potrai\n"
"o modificare il tuo Punto Warp\n"
"creato in precedenza,\n"
"o teletrasportarti li'.   "
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "Hai l'" COLOR(BLUE) "Amore di Nayru" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Usandolo creerai una potente\n"
"barriera difensiva. E' una magia di\n"
"difesa che attiverai con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Frecce  (50 pezzi)   90 Rupié \n"
COLOR(DEFAULT) "Tirale con un arco. Non le puoi\n"
"comprare se non hai un arco.     " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombe  (10 pezzi)   50 Rupié \n"
COLOR(DEFAULT) "Estraile premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e premi  \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per lanciarle. Non le puoi\n"
"comprare senza la borsa bombe." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Noci Deku  (5 pezzi)   15 Rupié \n"
COLOR(DEFAULT) "Lanciale e stordirai i nemici.  \n"
"Ne puoi portare un numero\n"
"limitato, attento. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pesce  200 Rupié \n"
COLOR(DEFAULT) "E' fresco! Appena preso! \n"
"Lo puoi tenere in bottiglia." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Hai ucciso l'" COLOR(RED) "AracnoTeschio Aureo" COLOR(DEFAULT) "!\n"
"Questo segno ne prova l'eliminazione!   "
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Hai ucciso l'" COLOR(RED) "AracnoTeschio Aureo" COLOR(DEFAULT) "!\n"
"Questo simbolo ne prova \n"
"l'eliminazione!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Spirito di Fatina  50 Rupié" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Spirito di Fatina 50 Rupié\n"
COLOR(DEFAULT) "Ti serve una bottiglia vuota\n"
"per mettercelo.\n"
"Non combattere senza!\n"
"     " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fuoco Blu    300 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fuoco Blu   300 Rupié \n"
COLOR(DEFAULT) "Ti serve una bottiglia vuota per\n"
"mettercelo. Usalo quando\n"
"sara' il momento..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Insettone    50 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Insettone     50 Rupié \n"
COLOR(DEFAULT) "Ti serve una bottiglia vuota per\n"
"mettercelo. Sembra un classico\n"
"insetto...  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (10 pezzi)   100 Rupié \n"
COLOR(DEFAULT) "Sembra un giocattolino, ma, in\n"
"realta' é una bomba motorizzata\n"
"a tempo!   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Siamo temporaneamente a \n"
"corto dell'articolo" COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Forza! Mi sembri vecchio per\n"
"questo gioco!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x40") "Huh? Cos--!"
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x50") "Uh-oh!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x3E") "Un cliente!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x39") "zzzzz...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Frecce   (30 pezzi)    60 Rupié \n"
COLOR(DEFAULT) "Ti serve un arco per usarle.\n"
"Scagliale, e finiranno presto." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Con quattro pezzi potrai avere  \n"
"un'altro Contieni-Cuori. Piu' ne\n"
"hai e piu' energia-vita avrai!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"E' cosi', ne hai trovati due\n"
"pezzi. Altri due e potrai avere\n"
"piu' energia-vita per giocare! "
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Adesso ne hai ben tre!             \n"
"Un ultimo pezzo, e la tua\n"
"energia-vita sara' potenziata! "
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "\n"
"Bravo!! Hai completato il\n"
"Contieni-Cuori! La tua\n"
"energia vitale é aumentata!    "
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Trovi un " COLOR(RED) "Contieni-Cuori" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Il numero dei cuori aumenta. \n"
"Inoltre ti viene ripristinata\n"
"tutta la tua energia vitale.     "
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Chiave Boss" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Adesso puoi accedere alla\n"
"stanza del Mostro Finale.      "
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"No, bello, ti mancano i soldi!     " EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x24") "Va bene, ce l'hai fatta!" QUICKTEXT_DISABLE "\n"
"Aspettami fuori, mentre preparo\n"
"la tua prossima prova!!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombe   5 pezzi    35 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombe   (5 pezzi)    35 Rupié \n"
COLOR(DEFAULT) "Estraile con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e premi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"di nuovo per lanciarle. Senza la\n"
"borsa non le puoi comprare.   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Trovi la " COLOR(BLUE) "Rupia' Blu" COLOR(DEFAULT) "! \n"
"Vale " COLOR(BLUE) "5 Rupié" COLOR(DEFAULT) "!      " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "Hai la " COLOR(BLUE) "Scaglia d'Argento" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Tuffati in acqua e premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".   \n"
"Potrai immergerti piu' a fondo   \n"
"di prima..."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "Hai la " COLOR(BLUE) "Scaglia Dorata" COLOR(DEFAULT) "!   " QUICKTEXT_DISABLE "\n"
"Tuffati in acqua e premi      \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Ora puoi immergerti  \n"
"molto piu' a fondo di prima! "
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Sembra che questo non sia il \n"
"luogo giusto..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Non si apre!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Ora sai la " COLOR(ADJUSTABLE) "Canzone di Saria" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x11") "Ora sai la " COLOR(RED) "Canzone di Epona" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0B") "Ora sai la " COLOR(YELLOW) "Canzone del Sole" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x15") "Ora sai la " COLOR(BLUE) "Ninnananna di Zelda" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x05") "Ora sai la " COLOR(LIGHTBLUE) "Canzone del Tempo" COLOR(DEFAULT) "!   "
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ora sai la " COLOR(PURPLE) "Canzone della Tempesta" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Benvenuto " NAME "!\n"
"Sono la Grande Fata del Potere!!"
BOX_BREAK
UNSKIPPABLE "Ti donero' un\n"
"nuovo " COLOR(ADJUSTABLE) "colpo di spada" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Ecco il mio dono!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ciao " NAME "!\n"
"Sono la Grande Fata della Saggezza!"
BOX_BREAK
UNSKIPPABLE "Potenziero' i tuoi\n"
COLOR(ADJUSTABLE) "poteri magici" COLOR(DEFAULT) ".  "
BOX_BREAK
UNSKIPPABLE "Ecco il mio dono! "
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ciao " NAME "! \n"
"Sono la Grande Fata del Coraggio! "
BOX_BREAK
UNSKIPPABLE "Sto per potenziare i tuoi\n"
COLOR(LIGHTBLUE) "poteri difensivi" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Eccoti il dono!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando sei stanco per la battaglia,\n"
"torna pure a trovarmi! " EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ciao " NAME "!   \n"
"Curero' le tue ferite...  " EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE "Sono i " COLOR(RED) "Semi Deku" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Questi piccoli semi sono  \n"
"duri, li puoi tirare con la \n"
"Fionda Magica.     "
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  UNSKIPPABLE "Ora conosci l'antica tecnica \n"
"segreta dell'" COLOR(RED) "Attacco Rotante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Premi " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " e caricherai l'arma! \n"
"Lascia " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " e si sprigionera'\n"
"un onda di energia!!      "
BOX_BREAK
UNSKIPPABLE "Se vuoi sprigionare energia\n"
"senza caricare prima l'arma, basta \n"
COLOR(LIGHTBLUE) "ruotare [Control-Pad] una volta" COLOR(DEFAULT) " e poi " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "per" COLOR(ADJUSTABLE) "\n"
COLOR(DEFAULT) "una rapida giravolta!       "
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Semi Deku  30 pezzi  30 Rupies" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Semi Deku (30 pezzi)  30 Rupié \n"
COLOR(DEFAULT) "Li puoi usare come proiettili  \n"
"per la Fionda. Non li puoi\n"
"comprare sino a che non l'avrai.     " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Volevi parlare con Saria, giusto?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parla a Saria\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Davvero? Sicuro che non volevi\n"
"parlarle?\n"
COLOR(DEFAULT)  TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x3C")  NAME "...?\n"
SHIFT("\x0D") "Sono " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Mi puoi sentire?   " EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vuoi riparlare con Saria?   \n"
"      " COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "L' " COLOR(ADJUSTABLE) "Indica-Magia" COLOR(DEFAULT) " é potenziato!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Le tue " COLOR(LIGHTBLUE) "difese" COLOR(DEFAULT) " sono migliorate!   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Trovi un " COLOR(YELLOW) "gruppo di frecce" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando utilizzerai l'Attacco\n"
"Rotante, consumerai del potere   \n"
"magico. Segui attentamente\n"
"l'" COLOR(ADJUSTABLE) "Indica-Magia" COLOR(DEFAULT) " verde!"
BOX_BREAK
UNSKIPPABLE "Ragazzo! Sei un messaggero della\n"
"Famiglia Reale, vero?       "
BOX_BREAK
UNSKIPPABLE "La prossima volta che sei\n"
"nei loro paraggi, fai visita ad \n"
"una mia amica che vive nel\n"
"Castello di Hyrule. "
BOX_BREAK
UNSKIPPABLE "Ti donera' sicuramente un altro\n"
"potere!   "
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il tuo potere magico é\n"
"stato potenziato!\n"
"Hai il doppio del " COLOR(RED) "Potere Magico" COLOR(DEFAULT) "!   "
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I tuoi poteri difensivi sono \n"
"migliorati! I danni inflitti dai\n"
"nemici sono " COLOR(RED) "ridotti alla meta'" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ciao " NAME "!\n"
"Sono la Grande Fata della Magia! "
BOX_BREAK
UNSKIPPABLE "Ti donero' un " COLOR(RED) "Incantesimo" COLOR(DEFAULT) ".\n"
"Ecco il mio dono..."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Spiacente, ma non puoi prestare\n"
"la maschera.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Puoi usare il" COLOR(RED) " Fuoco Din" COLOR(DEFAULT) " anche per    \n"
"bruciare delle cose!        "
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ricorda puoi usare il " COLOR(ADJUSTABLE) "Vento di Farore" COLOR(DEFAULT) ",\n"
"solo nei dungeons dove \n"
"é nascosta una mappa, OK?       "
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "L'" COLOR(BLUE) "Amore di Nayru" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "ha effetto solo  \n"
"per un tempo limitato, stai attento."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando sarai debole per la bat-\n"
"taglia, ritorna a trovarmi."
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Trovi la " COLOR(RED) "Rupia' Rossa" COLOR(DEFAULT) "!\n"
"Vale " COLOR(RED) "venti Rupié" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Prendi la " COLOR(PURPLE) "Rupia' Viola" COLOR(DEFAULT) "!  \n"
"Vale " COLOR(PURPLE) "50 Rupié" COLOR(DEFAULT) "!    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Prendi la " COLOR(YELLOW) "Rupia' Enorme" COLOR(DEFAULT) "!\n"
"Questa Rupia' vale una cifra,\n"
COLOR(YELLOW) "Duecento Rupié" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Trovi una " COLOR(RED) "Chiave" COLOR(DEFAULT) "!  " QUICKTEXT_DISABLE "\n"
"Puoi avanzare alla stanza suc-\n"
"cessiva. Scegli uno dei bauli e\n"
"vediamo se hai davvero fortuna."
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perso!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Trovi solo " COLOR(ADJUSTABLE) "Una Rupia'" COLOR(DEFAULT) ".   \n"
"Non hai molta fortuna. " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perso!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Trovi solo" COLOR(BLUE) " 5 Rupié" COLOR(DEFAULT) ".   \n"
"Ciononostante,non hai fortuna.  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perso!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Trovi ben " COLOR(RED) "venti Rupié" COLOR(DEFAULT) ".  \n"
"L'ultima scelta e' stata \n"
"un errore! Che RABBIA!              " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Vinci! " COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Trovi ben " COLOR(YELLOW) "50 Rupié" COLOR(DEFAULT) "!    \n"
"Sei un vero fortunello!!      " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "Metti un " COLOR(RED) "Grosso Poe" COLOR(DEFAULT) " in bottiglia!" QUICKTEXT_DISABLE "\n"
"Vendilo al " COLOR(RED) "Negozio di Spettri" COLOR(DEFAULT) "!\n"
"Puo' succedere qualcosa!   "
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINTO " COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Prendi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Collezionane quattro e otterrai \n"
"un Contieni-Cuori. Piu' ne \n"
"hai e piu' energia vita avrai!     "
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINTO" COLOR(DEFAULT) "! "
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Prendi un " COLOR(RED) "Pezzo di Cuore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"E cosi', ne hai ben due pezzi\n"
"ora. Ne bastano solo altri due,\n"
"per avere piu' energia vitale!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINTO" COLOR(DEFAULT) "! "
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ottieni un" COLOR(RED) " Pezzo di Cuore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ne hai trovati gia' tre pezzi!\n"
"Ancora un altro, e la tua\n"
"energia-vita sara' potenziata!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49")  COLOR(RED) "VINTO" COLOR(DEFAULT) "! "
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ottieni un" COLOR(RED) " Pezzo di Cuore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hai completato un altro\n"
"Contieni-Cuori! La tua energia-vita\n"
"é aumentata ora!   "
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cercali non solo all'aperto ma   \n"
"anche, all'interno dei dungeons. "
BOX_BREAK
"Naturalmente, e' la nostra speranza...\n"
"Non devi farlo per forza, se\n"
"non ti va...      " TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ma cos'e'?  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ehi, guarda " NAME "!\n"
"Si vede il fondo dalla " COLOR(DEFAULT) "ragnatela" COLOR(LIGHTBLUE) "\n"
"con " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Guarda la parete! L'edera che ci\n"
"cresce sopra ti offre un appiglio.\n"
"Forse puoi arrampicarti " NAME "!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Puoi aprire la " COLOR(DEFAULT) "porta" COLOR(LIGHTBLUE) " standogli\n"
"di fronte e premendo " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ".  " COLOR(DEFAULT) "      "
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Stai attento sempre  \n"
"all'" COLOR(BLUE) "Action" COLOR(LIGHTBLUE) " " COLOR(BLUE) "Icon" COLOR(LIGHTBLUE) ".    \n"
"E' l'" COLOR(BLUE) "Icona Blu " COLOR(LIGHTBLUE) "che si trova\n"
"proprio qui sopra! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Guarda! C'é qualcosa qui sopra!     \n"
"Sembra una vecchia " COLOR(DEFAULT) "scala" COLOR(LIGHTBLUE) "!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ehi...\n"
"Non e' lo stesso disegno visto \n"
"sulla " COLOR(DEFAULT) "Porta del Tempo" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sembra che quella torcia, poco\n"
"fa stava bruciando...    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Da qui in poi, passeremo  \n"
"attraverso stretti passaggi!   \n"
"Se vai piano, potrai riuscire \n"
"ad evitare alcuni nemici...  "
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Usa " COLOR(DEFAULT) "[Z] Attivato" COLOR(LIGHTBLUE) " per guardare sempre\n"
"nella giusta direzione.      \n"
"Cerca sempre di controllare il\n"
"corridoio successivo prima di girare."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Con la visuale giusta, premi    \n"
COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "per" COLOR(DEFAULT) " camminare di lato" COLOR(LIGHTBLUE) ".        \n"
"In questo modo i nemici non ti \n"
"sorprenderanno con un agguato." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Stai di fronte al " COLOR(DEFAULT) "blocco" COLOR(LIGHTBLUE) " e prendi-\n"
"lo (grab) con " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". Tieni premuto \n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", per spingerlo o tirarlo."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Per scalare (climb) il " COLOR(DEFAULT) "blocco" COLOR(LIGHTBLUE) "\n"
"premi " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", e allo stesso tempo" COLOR(DEFAULT) " [Control-Pad]" COLOR(LIGHTBLUE) "\n"
"in avanti, cosi' ti potrai arrampicare.\n"
"         "
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Controlla i segnali\n"
"dell'" COLOR(BLUE) "Action Icon" COLOR(LIGHTBLUE) "!      " COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Quando sei nell'acqua, se tieni\n"
"premuto " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", nuoterai sul fondo! \n"
"Scommetto che ci sono cose impor-\n"
"tanti sott'acqua!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Wow! Guarda tutti quei " COLOR(DEFAULT) "Fiori Bomba" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) " \n"
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ci sara' un modo per farli\n"
"esplodere tutti insieme?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sembra ci siano molte " COLOR(DEFAULT) "fosse di   \n"
"lava " COLOR(LIGHTBLUE) "qui intorno, stai molto\n"
"attento!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Grazie all'interruttore la  \n"
COLOR(DEFAULT) "piattaforma " COLOR(LIGHTBLUE) "fa su e giu'. Potrai\n"
"arrivare velocemente sulla volta!  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Non potrai mai sapere cosa \n"
"c'é dietro l'angolo in questi  \n"
"corridoi... "
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Usa " COLOR(DEFAULT) "[Z] Attivato " COLOR(LIGHTBLUE) "per guardare\n"
"sempre nella giusta direzione.\n"
"E' una tecnica utile, vero?       " COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", cosa stai    \n"
"guardando? " COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il viso del Colosso del Deserto..\n"
"sembra maligno!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Posso sentire gli spiriti sospirare\n"
"qui dentro... "
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE "\"Cerca l'Occhio della Verita'\"\n"
COLOR(LIGHTBLUE) "Ecco cosa stanno dicendo!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Qui...Sento i sospiri degli\n"
"spiriti in questa stanza... " COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE "\"Coloro dai " COLOR(RED) "Sacri Piedi   " COLOR(DEFAULT) "\n"
"si lascino guidare dal vento...\n"
"Solo cosi', troveranno\n"
"il percorso segreto...\""
BOX_BREAK
COLOR(LIGHTBLUE) "Ecco cosa stanno dicendo!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Questo muro...dice qualche cosa...\n"
COLOR(DEFAULT) "\"Pericolo sopra...\" " COLOR(LIGHTBLUE) "\n"
"Ecco cosa dice.     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Questo muro...dice qualche cosa... \n"
COLOR(DEFAULT) "\"Pericolo sotto...\"\n"
COLOR(LIGHTBLUE) "Ecco cosa dice.     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "L'acqua che fuoriesce dalla\n"
"statua alimenta l'intero labirinto.    " COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Attento, " NAME "!  \n"
"Scorre l'elettricita' attraverso\n"
"il " COLOR(ADJUSTABLE) "Viscidume verde" COLOR(LIGHTBLUE) "!  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Attento, " NAME "! \n"
"Scorre l'elettricita' attraverso\n"
"il " COLOR(RED) "Viscidume rosso" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Attento, " NAME "! \n"
"Scorre l'elettricita' attraverso\n"
"il " COLOR(BLUE) "Viscidume blu" COLOR(LIGHTBLUE) "!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Un" COLOR(DEFAULT) " pulsante" COLOR(LIGHTBLUE) "...\n"
"Che sembra tu non possa attivare  \n"
"solo con il peso del tuo corpo,\n"
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il " COLOR(RED) "Viscidume Rosso " COLOR(LIGHTBLUE) "é scappato!\n"
"Sara' perché hai tagliato il\n"
COLOR(RED) "tentacolo rosso" COLOR(LIGHTBLUE) "? Funzionera'    \n"
"anche con gli altri?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "C'é un pulsante dietro\n"
"queste mura!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sembra che ci sia qualcosa li'\n"
"sulla cima della piattaforma!     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42")  COLOR(LIGHTBLUE) "COOOSA!?"
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Guarda quelle " COLOR(DEFAULT) "bandiere" COLOR(LIGHTBLUE) "!\n"
"Sapresti capire quale di quelle\n"
"é reale?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "Grande Albero" COLOR(RED) " " COLOR(LIGHTBLUE) "ti ha convocato!     \n"
"Su, vieni con me!   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Andiamo! Dai!   \n"
"Entriamo dentro il\n"
"Grande Albero!  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Il Grande Albero ha detto di\n"
"andare dalla principessa del\n"
COLOR(DEFAULT) "Castello di Hyrule" COLOR(LIGHTBLUE) "...\n"
"Che dici ce la faremo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "La ragazzina ci ha chiesto di  \n"
"trovare suo " COLOR(DEFAULT) "padre" COLOR(LIGHTBLUE) "... Mi chiedo, dove\n"
"sara'?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Mi chiedo, dove troveremo la\n"
COLOR(DEFAULT) "Principessa" COLOR(LIGHTBLUE) " in questo castello?   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Chissa' " COLOR(DEFAULT) "Saria" COLOR(RED) " " COLOR(LIGHTBLUE) "cosa direbbe se\n"
"sapesse che noi salveremo Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Impa " COLOR(LIGHTBLUE) "ha detto che la Pietra Spirituale\n"
"del fuoco é sulla " COLOR(DEFAULT) "Montagna" COLOR(LIGHTBLUE) ".\n"
"       " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Entriamo nelle caverne Dodongo\n"
"usando un " COLOR(DEFAULT) "Fiore Bomba" COLOR(LIGHTBLUE) "!    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Darunia ha detto che sulla \n"
"cima della Montagna vive una     \n"
COLOR(DEFAULT) "Fata" COLOR(LIGHTBLUE) "! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Chissa' se " COLOR(DEFAULT) "Saria " COLOR(LIGHTBLUE) "sa qualcosa  \n"
"dell'altra Pietra Spirituale?     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Sembra che la " COLOR(DEFAULT) "Principessa Ruta" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "sia all'interno di Jabu-Jabu..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Hai tutte e tre le Pietre Spirituali!\n"
"Torniamo al " COLOR(DEFAULT) "Castello di Hyrule" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Quella gente sul cavallo bianco...\n"
"erano Zelda ed Impa, non e' vero?\n"
"Mi é sembrato che tirassero     \n"
"qualcosa nel " COLOR(DEFAULT) "fossato" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) "   "
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Andiamo a controllare il\n"
COLOR(DEFAULT) "Tempio del Tempo" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dobbiamo credere a Sheik e      \n"
"andare al " COLOR(DEFAULT) "Villaggio Kakariko" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Mi chiedo cosa stia succedendo \n"
"nella foresta...\n"
"Sono preoccupata per" COLOR(DEFAULT) " Saria" COLOR(LIGHTBLUE) "!     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Le nuvole sulla " COLOR(DEFAULT) "Montagna della Morte" COLOR(LIGHTBLUE) "...\n"
"Sono...Non so...STRANE...  \n"
"     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Un vento gelido proviene dal \n"
COLOR(DEFAULT) "Fiume Zora" COLOR(LIGHTBLUE) "...lo senti anche tu?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Quegli" COLOR(DEFAULT) " Stivali di Ferro" COLOR(LIGHTBLUE) "\n"
"peseranno una tonnellata!\n"
"Se li indossi, sarai in grado di \n"
"camminare sino al fondo del lago. " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Cerchiamo qualcuno che ci possa \n"
"dire qualcosa sugli altri " COLOR(DEFAULT) "Saggi" COLOR(LIGHTBLUE) "!     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Quel mostro! E' venuto fuori dal \n"
COLOR(DEFAULT) "pozzo del villaggio" COLOR(LIGHTBLUE) "!\n"
"Andiamo a controllare!       " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Chi avra' costruito il " COLOR(DEFAULT) "Tempio" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "dello Spirito" COLOR(LIGHTBLUE) ", e a che scopo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Hai mai suonato il \n"
COLOR(PURPLE) "Notturno delle Ombre" COLOR(LIGHTBLUE) " che ti\n"
"ha insegnato Sheik?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "deserto" COLOR(LIGHTBLUE) "...é li' che é\n"
"nato Ganondorf, il Re del Male.    \n"
"Se ci andiamo, qualche cosa\n"
"scopriremo... " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Indossa i " COLOR(DEFAULT) "Guanti d'Argento \n"
COLOR(LIGHTBLUE) "e muovi quegli oggetti\n"
"che prima pesavano troppo! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Colui che ci aspetta al Tempio  \n"
"del Tempo...Potrebbe essere...     " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dobbiamo salvare la Principessa\n"
"Zelda, dalle prigioni del\n"
"Castello!    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME "...\n"
"Prova a muoverti!!  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Non intendevo parlare con te\n"
"usando l'Ocarina magica, ma  \n"
"volevo parlarti realmente,  \n"
"faccia-a-faccia!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"La foresta é collegata a molti  \n"
"posti!  Se puoi sentire la mia\n"
"canzone, sei in un posto che é\n"
"connesso alla foresta!   " EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Sono felice di sapere che a\n"
"Mr. Darunia piace la mia\n"
"canzone! "
BOX_BREAK
"E lo sono ancora di piu' sapendo\n"
"che ti é stata utile!!         \n"
NAME "!\n"
"Tee hee hee!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Stai recuperando le Pietre\n"
"Spirituali? Te ne manca ancora\n"
"una? Intendi la \n"
COLOR(BLUE) "Pietra Spirituale dell'Acqua" COLOR(DEFAULT) ", vero?    "
BOX_BREAK
"Il Grande Albero Deku mi disse\n"
"che l'aveva il " COLOR(BLUE) "Re Zora Signore \n"
"delle terre Zoras" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Stai recuperando le Pietre\n"
"Spirituali? Te ne manca ancora\n"
"una? Intendi la\n"
COLOR(RED) "Pietra Spirituale del Fuoco" COLOR(DEFAULT) ", vero?     "
BOX_BREAK
"Il Grande Albero Deku mi disse\n"
"che l'aveva " COLOR(RED) "Mr.Darunia dei Gorons" COLOR(DEFAULT) "...\n"
"     " EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Non so proprio cosa sia...\n"
"Ho questa sensazione di paura..."
BOX_BREAK
"Il castello...\n"
"Si, qualcosa di brutto\n"
"accade al castello!! " EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Cosa? La tua Ocarina suona...\n"
"Differente, non so...\n"
"Ti sei esercitato parecchio,  \n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Stai cercando un tempio? Una\n"
"volta, uno strano gufo mi disse..."
BOX_BREAK
"\"" COLOR(LIGHTBLUE) "Occhi che vedono nelle\n"
"tenebre si apriranno in tempesta." COLOR(DEFAULT) "\" \n"
"Hai idea di cosa stesse parlando?\n"
"          " EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Dove ti trovi, " NAME "?\n"
"Stai cercando un tempio?\n"
"Una volta uno strano gufo mi      \n"
"disse..."
BOX_BREAK
"\"" COLOR(LIGHTBLUE) "Vai, giovane. Vai dalla\n"
"Dea del Deserto con una ocarina." COLOR(DEFAULT) "\"\n"
"Hai idea di cosa            \n"
"volesse dire?          " EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Hai gia' trovato tutti i templi? " EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Evviva! Sei salvo!!\n"
"Sapevo che ti avrei     \n"
"risentito!"
BOX_BREAK
"Sono nel " COLOR(ADJUSTABLE) "Tempio della Foresta" COLOR(DEFAULT) "!\n"
"Gli spiriti della foresta\n"
"chiedevano aiuto, dovevo controllare..."
BOX_BREAK
"Ma é pieno di mostri demoniaci!\n"
"Aiutami, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"All'inizio, non volevo divenire   \n"
"il " COLOR(ADJUSTABLE) "Saggio della Foresta" COLOR(DEFAULT) "..."
BOX_BREAK
"Ma va bene, ora."
BOX_BREAK
"Perche' ti sto aiutando a salvare\n"
"Hyrule, " NAME "!\n"
"Si, Io!   " EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Se i sei " COLOR(RED) "Saggi" COLOR(DEFAULT)  COLOR(DEFAULT) " torneranno, \n"
"potremo imprigionare Ganondorf,  \n"
"il Re del Male, nel Sacro Reame.   "
BOX_BREAK
"Ma, per sigillarlo perfettamente\n"
"é necessario il " COLOR(RED) "settimo\n"
"Saggio" COLOR(DEFAULT) "."
BOX_BREAK
"Qualcuno che conosci, deve\n"
"esserlo, " NAME "..."
BOX_BREAK
"D'ora in poi, devi viaggiare\n"
"tra passato e futuro per\n"
"risvegliare i Saggi restanti! "
BOX_BREAK
"In bocca al lupo,     \n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Noi, Sei Saggi, ti trasferiamo il\n"
"nostro potere!   "
BOX_BREAK
"Il destino di Hyrule dipende\n"
"da te ora!!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sento una voce da qualche\n"
"parte...  " COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sta dicendo:\n"
COLOR(DEFAULT)  SHIFT("\x11") "\"Prendi le 5 Rupié d'Argento..\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Quel muro...sta dicendo qualcosa! " COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Dice:   \n"
COLOR(DEFAULT) "Se vuoi vedere un traghetto per  \n"
SHIFT("\x0E") "l'altro mondo, vieni qui."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se vuoi salire su quella " COLOR(DEFAULT) "barca" COLOR(LIGHTBLUE) ", stai\n"
"attento! Sembra vecchia... Chi \n"
"puo' dire se affondera'? " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "C'é una " COLOR(DEFAULT) "porta " COLOR(LIGHTBLUE) " li' sopra... Ci\n"
"sara' un modo per arrivarci?  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Quel " COLOR(DEFAULT) "Ghiaccio rossso" COLOR(LIGHTBLUE) ", strano!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Quel " COLOR(DEFAULT) "fuoco blu" COLOR(LIGHTBLUE) "...Non sembra...  \n"
"naturale. Forse lo puoi usare\n"
"per qualcosa? " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "fuoco sulle torce" COLOR(LIGHTBLUE) " é sparito... \n"
"Sembra l'abbiano preso i\n"
"fantasmi!    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ehi " NAME "! Una " COLOR(DEFAULT) "torcia" COLOR(LIGHTBLUE) "\n"
"é accesa! Sara' perché\n"
"hai sconfitto uno spettro?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ci sono delle " COLOR(DEFAULT) "frecce" COLOR(LIGHTBLUE) "\n"
"sul pavimento!    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Questo " COLOR(DEFAULT) "corridoio" COLOR(LIGHTBLUE) " é capovolto!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Attento alle " COLOR(DEFAULT) "ombre dei mostri  \n"
COLOR(LIGHTBLUE) "che penzolano dal soffitto. " COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "C'é una specie di" COLOR(DEFAULT) " scrigno" COLOR(LIGHTBLUE) " qui." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Questa...é simile alla " COLOR(DEFAULT) "torcia" COLOR(LIGHTBLUE) " che\n"
"abbiamo visto all'entrata del  \n"
"tempio, no?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "La " COLOR(DEFAULT) "torcia" COLOR(LIGHTBLUE) " é accesa...Significa..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il" COLOR(DEFAULT) " pulsante" COLOR(LIGHTBLUE) " é gelato!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", attento!  \n"
"Il soffitto sta cadendo!!   " COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", Sento " COLOR(DEFAULT) "voci \n"
"Gorons" COLOR(LIGHTBLUE) " la' sotto.   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ehi, guarda la' sotto...   \n"
"Non é la stanza dove abbiamo visto\n"
COLOR(DEFAULT) "Darunia" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Quella " COLOR(DEFAULT) "statua" COLOR(LIGHTBLUE) "... Non l'abbiamo  \n"
"gia' vista prima?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "La " COLOR(DEFAULT) "pedana " COLOR(LIGHTBLUE) "é arrugginita!" COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Attento! \n"
"Non farti ingoiare\n"
"da uno dei vortici!!" COLOR(DEFAULT)
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
SHIFT("\x0F") "Sono una porta parlante"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x06")  COLOR(LIGHTBLUE) "Strano...Questa porta e' chiusa... " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x04")  COLOR(LIGHTBLUE) "Forti " COLOR(DEFAULT) "sbarre di ferro" COLOR(LIGHTBLUE) " bloccano la\n"
COLOR(DEFAULT)  SHIFT("\x04")  COLOR(LIGHTBLUE) "porta. Non potrai aprirla a   \n"
COLOR(DEFAULT)  SHIFT("\x04")  COLOR(LIGHTBLUE) "mani nude! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x09")  COLOR(LIGHTBLUE) "Serve una " COLOR(DEFAULT) "chiave" COLOR(LIGHTBLUE) " per aprire  \n"
COLOR(DEFAULT)  SHIFT("\x1D")  COLOR(LIGHTBLUE) "la porta incatenata!       " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x21")  COLOR(LIGHTBLUE) "Serve una " COLOR(DEFAULT) "chiave speciale\n"
SHIFT("\x41")  COLOR(LIGHTBLUE) "per aprirla.   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Silenzio!" QUICKTEXT_DISABLE
BOX_BREAK
"Sono solo le " TIME "!\n"
COLOR(DEFAULT) "Sono il custode e sto \n"
"riposando!      "
BOX_BREAK
"Vattene via! Si é mai visto un\n"
"fantasma durante il giorno?  "
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sono le " TIME "  \n"
"Il " COLOR(RED) "Tour dei Tombaroli" COLOR(DEFAULT) "\n"
"é finito ora!"
BOX_BREAK
"Il custode del cimitero   \n"
"dorme adesso!"
BOX_BREAK
"Vattene via!\n"
"Gira che un fantasma lo trovi! "
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Felici Maschere\n"
COLOR(DEFAULT) "Prima di tutto, leggere il  \n"
"presente cartello."
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(RED) "Funziona cosi':    \n"
COLOR(DEFAULT) "Qui non vendiamo le maschere, ma, \n"
"le " COLOR(RED) "Prestiamo" COLOR(DEFAULT) " al cliente. " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Tu vendi la maschera\n"
"per conto tuo.   " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Poi ci rendi i " COLOR(RED) "soldi" COLOR(DEFAULT) " guadagnati,  \n"
"e noi te ne prestiamo un'altra...\n"
"    " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Puoi prestare la tua maschera\n"
"anche se gia' venduta; ma, puoi \n"
"vendere ogni maschera, solo una\n"
"volta. " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Provare x credere  !\n"
SHIFT("\x14") "--Il proprietario.     " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Tempio delle Ombre...\n"
"Raccoglie il sangue di Hyrule\n"
"storia di odio ed egoismo... " EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sei...Otto...Cosa c'é li' sotto?\n"
"Lo Spettro nel Buio forse...\n"
"Non puoi andare avanti...      " EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Chi ottiene l'" COLOR(RED) "Occhio della Verita'" COLOR(DEFAULT) "\n"
"potra' vedere cosa si nasconde\n"
"nelle tenebre..." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Qualcosa di strano ricopre\n"
"l'entrata...\n"
"Devi risolvere questo " COLOR(DEFAULT) "enigma" COLOR(LIGHTBLUE) " \n"
"e potrai far riaprire la porta.        " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grande Testa Dodongo...\n"
"Se vede rosso, si aprira' una\n"
"nuova via... \n"
"  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x1E")  COLOR(LIGHTBLUE) "   Caccia al Tesoro   \n"
COLOR(DEFAULT)  SHIFT("\x38") "Chiuso per ora.   \n"
SHIFT("\x38") "Solo di sera!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Farmacia     \n"
COLOR(DEFAULT) "Chiuso di notte     "
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Tiro ai Bersagli\n"
COLOR(DEFAULT) "Aperto solo di giorno.  "
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Negozio Maschere\n"
COLOR(DEFAULT) "Noleggio part-time\n"
"Solo di giorno pero'."
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Bazaar\n"
COLOR(DEFAULT) "Aperto solo di giorno   "
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Mostrami la luce! "
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Colui con l'" COLOR(RED) "Occhio della Verita'" COLOR(DEFAULT) "\n"
"sara' guidato al Tempio dello\n"
"Spirito dallo spettro" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Coloro che sul fondo di questo\n"
"Tempio vogliono camminare,     \n"
"suonino qui la " COLOR(RED) "Canzone della       \n"
"Famiglia Reale" COLOR(DEFAULT) ".    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Coloro che le acque vogliono\n"
"riguardare, suonino proprio qui la \n"
COLOR(RED) "Canzone della Famiglia Reale" COLOR(DEFAULT) ".    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Chi trova una " COLOR(RED) "Piccola Chiave" COLOR(DEFAULT) "  \n"
"avanza alla stanza successiva. \n"
"Altrimenti...a casa!  "
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se vuoi parlarmi, allora,\n"
"fallo dalla piattaforma.  " EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Ehi " NAME "!" QUICKTEXT_DISABLE "\n"
"Ciao sono qui! "
BOX_BREAK
"Guardami premendo " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", e parlami\n"
"premendo " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".   "
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'ora attuale e'   " COLOR(RED)  TIME  COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Luccicanza sui Morti Viventi...  "
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Colui che entrera' nella Tomba \n"
"Reale sara' ostacolato dai    \n"
COLOR(RED) "Mostri del Buio" COLOR(DEFAULT) ".    "
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ehi, tu! Giovanotto, laggiu'!   \n"
"Guarda qua, dentro la cella!    " EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Il mio piccolo non e' qui ora...      \n"
"Penso sia andato a giocare nel \n"
"cimitero... "
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, il piccolo dorme ora.      \n"
"Per favore torna un altra volta\n"
"a giocare con lui!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Quando l'acqua colma il lago\n"
"tira alla luce del mattino." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se vuoi tornare al futuro,   \n"
"dovrai ritornare qui con il    \n"
COLOR(BLUE) "Potere dell'Argento" COLOR(DEFAULT) " dal passato...\n"
"     " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se vuoi spostarti al passato, \n"
"dovrai tornare qui con il   \n"
"cuore puro di un bambino...    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Questa porta, adesso é in   \n"
"riparazione." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Sembra come se qui ci fosse un\n"
"oggetto di solito...    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x34") "Sia il mio volto un\n"
SHIFT("\x3A")  COLOR(RED) "Teschio Sincero" COLOR(DEFAULT) ". " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x0C") "     Altrimenti cadrai nelle  \n"
SHIFT("\x2D") "profonde tenebre..." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Questa non é la " COLOR(DEFAULT) "chiave" COLOR(LIGHTBLUE) " giusta.\n"
"La porta non si apre" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27")  COLOR(LIGHTBLUE) "Pozioni della Nonna.\n"
COLOR(DEFAULT)  SHIFT("\x44") "Chiuso" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x28") "Studio nei campi ora\n"
SHIFT("\x28") "Ritorna di nuovo! \n"
SHIFT("\x4A") "--Nonna." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Ma? ...Che ragazzaccio,\n"
"volevi entrare dalla porta\n"
"di servizio! " QUICKTEXT_DISABLE
BOX_BREAK
TEXT_SPEED("\x02") "Che monello!     " TEXT_SPEED("\x00") "\n"
"Ti svelero' un...Pettegolezzo! "
BOX_BREAK
"Il carpentiere capo ha un figlio, \n"
"é il ragazzo che si siede sotto\n"
"l'albero ogni sera..."
BOX_BREAK
"Ma non dire al boss che\n"
"te l'ho detto!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Guarda qui!! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Malon sta dormendo!   \n"
"Anch'io vado a dormire, ora.\n"
"Ritorna piu' tardi con la\n"
"luce!!    "
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Record di " NAME "!\n"
COLOR(DEFAULT) "Ragni distrutti : " TOKENS "\n"
"Pesce piu' grosso : " HIGHSCORE(HS_HORSE_ARCHERY) " chili " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Tempo Maratona " HIGHSCORE(HS_MARATHON) "\n"
"Corsa di cavalli " HIGHSCORE(HS_HORSE_RACE) "\n"
"Tiro con l'arco : " HIGHSCORE(HS_HORSE_ARCHERY) " punti  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "    C'é inciso lo stemma della  \n"
SHIFT("\x1E") "Famiglia Reale di Hyrule." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x54") "R.I.P.\n"
SHIFT("\x0E") "Qui giace l'anima di coloro che\n"
SHIFT("\x26") "giurarono fedelta' alla \n"
SHIFT("\x2B") "  Famiglia Reale." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x0E") "Gli Sheikah, guardiani della\n"
SHIFT("\x0E") "Famiglia Reale e fondatori di\n"
SHIFT("\x02") "Kakariko, veglia sulle loro anime \n"
SHIFT("\x19") "nel loro eterno riposo.  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(BLUE) "Cascate Senza Sonno\n"
COLOR(DEFAULT)  SHIFT("\x05") "L'acqua di queste cascate serve  \n"
SHIFT("\x0F") "il Re di Hyrule. Quando il Re\n"
SHIFT("\x05") "sonnecchia, cosi' fanno le cascate. " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Alcune rane ti guardano dal\n"
"fondale del fiume..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ti trovi su di un soffice tappeto\n"
"per ospiti...\n"
"Che lusso, sotto i tuoi piedi!   "
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se supererai le " COLOR(RED) "prove" COLOR(DEFAULT) " che ti   \n"
"aspettano piu' avanti, allora e solo\n"
"allora, sarai in grado di ricevere\n"
"il nostro tesoro!  "
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se vuoi possedere il nostro \n"
"tesoro segreto, devi sforzarti \n"
"di ottenere le " COLOR(RED) "chiavi" COLOR(DEFAULT) " nascoste!!  \n"
"        "
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sconfiggi i nemici in un " COLOR(RED) "tempo\n"
"limitato" COLOR(DEFAULT) "! "
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Prendi le " COLOR(RED) "Gemme sott'acqua" COLOR(DEFAULT) "! "
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Supera il fuoco!!     "
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Trova il passaggio segreto!  \n"
"     "
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Acceca l'" COLOR(RED) "occhio della statua" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Con le " COLOR(RED) "mani d'argento" COLOR(DEFAULT) " muoverai\n"
"l'enorme blocco!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Senza gli oggetti necessari,    \n"
"sarai confuso da impossibili    \n"
"misteri..."
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Prendi le " COLOR(RED) "gemme lucenti" COLOR(DEFAULT) ", evitando\n"
"le trappole e i pericoli! "
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F")  COLOR(LIGHTBLUE) " Laghetto   " COLOR(DEFAULT) "\n"
SHIFT("\x07") "Oggi i pesci abboccano davvero!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4E")  COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Le Ombre si alzeranno solo per\n"
SHIFT("\x03") "colui che ha l'" COLOR(RED) "occhio della verita'\n"
SHIFT("\x29")  COLOR(DEFAULT) "del villaggio Kakariko" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Campi erbosi" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Citta' di Hyrule  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(LIGHTBLUE) "Tempio del Tempo  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47")  COLOR(RED) "Chiuso  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2A")  COLOR(PURPLE) "Villaggio Kakariko\n"
COLOR(DEFAULT)  SHIFT("\x28") "Monte della Morte\n"
SHIFT("\x34") "Inizio Sentiero" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(PURPLE) "Cimitero del Villaggio    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Scuro!Pauroso! E' il\n"
COLOR(PURPLE)  SHIFT("\x1E") "Pozzo dei tre desideri" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2B")  COLOR(RED) "Montagna della Morte\n"
COLOR(DEFAULT)  SHIFT("\x3A") " Necessario il\n"
SHIFT("\x3F") "Decreto Reale" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(RED) "Sentiero della Morte" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(YELLOW) "Caverne Dodongo \n"
COLOR(DEFAULT)  SHIFT("\x0A") "       Vietato l'ingresso!!    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32") "Terre dei Gorons  \n"
SHIFT("\x41")  COLOR(RED) "Goron City" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(BLUE) "Fiume Zora  \n"
COLOR(DEFAULT)  SHIFT("\x0F") "Attenzione, correnti veloci \n"
SHIFT("\x28") "e forti mulinelli.  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Le Ombre si alzeranno silo per\n"
SHIFT("\x0E") "colui che ha l'occhio della verita'\n"
SHIFT("\x1C") "del Villaggio Kakariko" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Terre Zoras  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Fontana Zora   \n"
COLOR(DEFAULT)  SHIFT("\x08") "Non disturbare Lord Jabu-Jabu!\n"
SHIFT("\x32") "--RE Zora XVI  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(PURPLE) "Centro di Allenamento \n"
COLOR(DEFAULT)  SHIFT("\x15") "Non tagliare i vari cartelli\n"
SHIFT("\x28") "leggili bene invece!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") " Tutti quelli che osano\n"
SHIFT("\x07") "  avventurarsi nel deserto--\n"
SHIFT("\x0B") "passino prima al negozio." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(YELLOW) "Negozio Tappeti" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41") "Piu' Avanti\n"
SHIFT("\x17")  COLOR(ADJUSTABLE) " Radura dell'Albero Deku" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(ADJUSTABLE) "Tempio Boschi" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(ADJUSTABLE) "Boschi Perduti" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "    Talon & Malon\n"
SHIFT("\x3C")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "Il Grande Ingo  \n"
SHIFT("\x46")  COLOR(YELLOW) "Ingo Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(BLUE) "Laboratorio del Lago\n"
COLOR(DEFAULT)  SHIFT("\x04") "Ogni giorno cerchiamo di svelare\n"
SHIFT("\x09") "   i misteri del Lago Hylia!!  \n"
SHIFT("\x36") "--Scienziato    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(YELLOW) "Valle Gerudo " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15")  COLOR(YELLOW) "Zona Arcieri a Cavallo " COLOR(DEFAULT) "\n"
SHIFT("\x12") "Richiesti bravi cavalieri!  \n"
SHIFT("\x12") "Record attuale: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " Punti " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(YELLOW) "Centro Atletico Gerudo\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Ingresso consentito solo ai\n"
SHIFT("\x4B") "membri! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(YELLOW) "Terre Infestate  " COLOR(DEFAULT) "\n"
SHIFT("\x17") "Se insegui un miraggio,\n"
SHIFT("\x1A") "il deserto ti ingoiera'.   \n"
SHIFT("\x1C") "Una sola via é vera!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Casa Spiriti " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x22")  COLOR(ADJUSTABLE) "Negozio Kokiri\n"
COLOR(DEFAULT)  SHIFT("\x0B") " Abbiamo merci originali!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
SHIFT("\x28") "Casa di " NAME " " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(ADJUSTABLE) "I Kokiri non possono \n"
COLOR(DEFAULT)  SHIFT("\x30")  COLOR(ADJUSTABLE) "lasciare il bosco." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Segui il sentiero lungo i bordi\n"
"dello strapiombo e raggiungerai  \n"
SHIFT("\x06")  COLOR(RED) "Goron City" COLOR(DEFAULT) ",patria dei Gorons.  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36") " 8' Meraviglia\n"
SHIFT("\x3F")  COLOR(RED) "Fiori Bomba" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Pericolo! Non muovere!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x22")  COLOR(RED) "Cima della Montagna  \n"
COLOR(DEFAULT)  SHIFT("\x15") "Entrata cratere piu' avanti \n"
SHIFT("\x1E") "Attenti calore intenso!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1D")  COLOR(BLUE) " Stanza del Trono Zora \n"
COLOR(DEFAULT)  SHIFT("\x1E") "Per ascoltare i proclami\n"
SHIFT("\x25") "Reali, posizionati sulla   \n"
SHIFT("\x19") "piattaforma e parla al Re." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Se fermerai il mio rotolamento, \n"
SHIFT("\x15") "otterrai qualcosa di utile.   \n"
SHIFT("\x29") "--" COLOR(RED) "Goron Rotolatore" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Solo chi vede la verita' potra'\n"
SHIFT("\x12") "trovare l'ombrello di pietra\n"
SHIFT("\x22") "che lo riparera' dalla \n"
SHIFT("\x30") "pioggia di lame." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Solo colui che ha" COLOR(RED) " piedi sacri" COLOR(DEFAULT) "\n"
SHIFT("\x04") "attraversa la valle della morte." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Il tempo record dei miei\n"
"avversari é stato finora:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"--Dampé Il Custode.    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tiro al Bersaglio \n"
"20 Rupié a partita.   \n"
COLOR(DEFAULT) "Ci sono " COLOR(RED) "10 bersagli" COLOR(DEFAULT) ". Hai solo " COLOR(RED) "15 \n"
"chances" COLOR(DEFAULT) ". Colpiscili tutti!! " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Con 10 centri -- Primo Premio  \n"
"Con 8 o piu'  -- Giro Gratis\n"
"Meno di 8    -- Game Over  " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Regole del Tiro al Bersaglio  \n"
COLOR(DEFAULT) "Non chiedere prestiti.    \n"
"Non disturbare i clienti.     " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(LIGHTBLUE) "Caccia al Tesoro   " COLOR(DEFAULT) "\n"
SHIFT("\x06") "Non vendiamo tesori qui...       " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F")  COLOR(LIGHTBLUE) "Punto Pratica Nuoto    \n"
COLOR(DEFAULT)  SHIFT("\x2F") "Sei sicuro di    \n"
SHIFT("\x1D") "saper nuotare bene?  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(RED) "Vetta Montagna " COLOR(DEFAULT) "\n"
SHIFT("\x24") "Attenzione - Pericolo  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Maschere Felici!" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Cerchiamo agenti per\n"
SHIFT("\x3C") "la felicita'!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Vicolo Bowling Bombchu" COLOR(DEFAULT) "\n"
SHIFT("\x20") "Potrai sperimentare  \n"
SHIFT("\x17") "le ultime tecnologie!     " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x50")  COLOR(LIGHTBLUE) "Bazaar" COLOR(DEFAULT) "\n"
SHIFT("\x0A") "Abbiamo un po' di tutto!       " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Negozio Pozioni\n"
COLOR(DEFAULT)  SHIFT("\x1B") "Le pozioni di buona\n"
SHIFT("\x4A") "qualita'!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(RED) "Negozio Goron\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Articoli montanari!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(BLUE) "Negozio Zora" COLOR(DEFAULT) "\n"
SHIFT("\x42") "Pesce fresco!   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Emozionante Tour dei Tombaroli!! \n"
COLOR(DEFAULT)  SHIFT("\x08") "     Dalle 18:00 alle 21:00    \n"
SHIFT("\x1C") "   --Dampé Il Custode. " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Emozionante Tour dei Tombaroli!! \n"
COLOR(DEFAULT)  SHIFT("\x0A") "Tours " COLOR(RED) "sospesi" COLOR(DEFAULT) ", sino assunzione \n"
SHIFT("\x1B") "del nuovo Custode del   \n"
SHIFT("\x09") "Cimitero. Spiacenti del disagio." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Colpi di Scherma!   \n"
COLOR(DEFAULT) "Per colpire con la spada, muovi \n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " punta il bersaglio con   \n"
COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", poi premi " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Buco di \"Z\"\n"
COLOR(DEFAULT) "Prova ad attraversare il \n"
"buco!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Mettiti davanti al tunnel e premi\n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Quando apparira' la scritta\n"
"\"ENTER\" sull'" COLOR(BLUE) "Action Icon" COLOR(DEFAULT) ",\n"
"premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e striscerai dentro. " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Controlla attentamente\n"
"l'" COLOR(BLUE) "Action Icon" COLOR(DEFAULT) "!      " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Falciare l'erba con la spada\n"
COLOR(DEFAULT) "Se colpisci solo con" COLOR(ADJUSTABLE) " [B]" COLOR(DEFAULT) ", taglierai \n"
"orizzontalmente. Premendo " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "   " COLOR(LIGHTBLUE) " \n"
COLOR(DEFAULT) "il tuo colpo, sara' in verticale." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Hyrule Castle" COLOR(DEFAULT) "\n"
SHIFT("\x37")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Ti trovi al " COLOR(LIGHTBLUE) "Castello Hyrule" COLOR(DEFAULT) "\n"
SHIFT("\x16") "Di qua x il " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42") "Qui avanti\n"
SHIFT("\x29")  COLOR(BLUE) "Camera del RE Zora \n"
COLOR(DEFAULT)  SHIFT("\x25") "Mostrare del rispetto!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "  Casa del Grande " COLOR(RED) "Mido " COLOR(DEFAULT) "\n"
SHIFT("\x2D") "Boss dei Kokiri   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Casa Fratelli Sappiamo-Tutto-Noi " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Casa Gemelline" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D") "Casa di " COLOR(RED) "Saria" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Utilizzo dello [Z] Attivato  \n"
COLOR(DEFAULT) "Quando non ci sono oggetti da  \n"
"osservare, guarda avanti e  \n"
"premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Fermati e cambia la direzione \n"
"verso cui sei orientato, oppure tieni\n"
"premuto " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "...           " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Ti aiutera' a stabilire la dire- \n"
"zione verso cui vuoi andare.   \n"
"Prova e' conveniente! " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Se " COLOR(LIGHTBLUE) "tieni premuto [Z]" COLOR(DEFAULT) ",\n"
COLOR(RED) "Camminerai di lato" COLOR(DEFAULT) "\n"
"con la visuale rivolta in avanti." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(RED) "Camminare di lato" COLOR(DEFAULT) " é un ottima \n"
"tecnica per i corridoi dei  \n"
"Dungeons. Girati e prova a farlo \n"
"subito, allenati..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Pietre dei Tre Saltelli  \n"
COLOR(DEFAULT) "Se vai deciso nella direzione ove\n"
"vuoi saltare, il salto avverra'\n"
"automaticamente." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "E ricorda se farai bene i 3 salti,\n"
"sarai molto felice! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2F")  COLOR(RED) "Vietato Bagnarsi \n"
COLOR(DEFAULT)  SHIFT("\x15") "--Non ti fara' molto bene! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Modifica Mirino \n"
COLOR(DEFAULT) "Se appare l'Icona " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " su di un\n"
"oggetto, lo potrai mirare con " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ".  " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "In altre parole, se premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "    \n"
"quando vedi " COLOR(ADJUSTABLE) "▼" COLOR(YELLOW) " " COLOR(DEFAULT) "su di un oggetto, \n"
"lo potrai inquadrare." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Se premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ancora, verra'     \n"
"tolto il" COLOR(RED) " Mirino" COLOR(DEFAULT) " oppure si \n"
"trasferira' al bersaglio piu' vicino\n"
"con " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " sopra.   " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Quando ci sono molti nemici  \n"
"nelle vicinanze ed intendi     \n"
"scappare, premi: " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "tenendo premuto:     \n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " togli il mirino.    " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Puoi mirare alle " COLOR(RED) "pietre" COLOR(DEFAULT) " vicine  \n"
"al cartello per provare!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(ADJUSTABLE) "SottoBosco  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x14") "Stiamo aspettando di vedere\n"
SHIFT("\x38") "la tua faccia!\n"
SHIFT("\x28") "Vincerai bei premi! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x48") "Visita la\n"
SHIFT("\x04")  COLOR(RED) "Casa Fratelli-Sappiamo-Tutto-Noi \n"
COLOR(DEFAULT)  SHIFT("\x17") " e otterrai risposte alle \n"
SHIFT("\x20") "tue domande sugli Item!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"E' una " COLOR(RED) "Pietra Pettegola" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che puoi nuotare piu' veloce,\n"
"tenendo premuto il tasto " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é un segreto vicino\n"
"all'albero solitario che si trova \n"
"non lontano dal fiume giu' \n"
"a nord-est dei Campi Erbosi.   "
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é un segreto sulla\n"
"strada che porta sino al Lago     \n"
"Hylia."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che la Spada Biggoron é super  \n"
"affilata ed é indistruttibile.   "
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che Medigoron non tiene per \n"
"niente conto della sua misura,\n"
"ed il suo negozio é minuscolo.    "
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che il record originale \n"
"della corsa ad ostacoli del Lon\n"
"Lon Ranch é di Malon.   "
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che Malon, del Lon Lon Ranch,\n"
"sogna che un cavaliere dalla  \n"
"scintillante armatura la porti via \n"
"per sposarla...  "
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che Ruta, la principessa\n"
"Zora, il cui egoismo é ben noto; \n"
"sia innamorato di un certo\n"
"ragazzo... "
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che il giocatore che seleziona\n"
"l'opzione \"HOLD\" con\n"
"\"Z ATTIVATO\" é un vero\n"
"\"Giocatore di Zelda\"!"
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é un segreto vicino \n"
"all'albero del Villaggio Kakariko."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che contrariamente alla sua \n"
"immagine elegante, la Principessa\n"
"Zelda sia in realta', una monella!   "
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che la governante della\n"
"Principessa é una donna di razza  \n"
"Sheikah, che molti pensavano  \n"
"estinta. "
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é un uomo che corre senza\n"
"sosta, laggiu' nei Campi Erbosi \n"
"di Hyrule...    "
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che é contro le regole      \n"
"usare delle lenti al Negozio\n"
"della Caccia al Tesoro, nella\n"
"citta' di Castello."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che la donna dei polli va \n"
"spesso al Laboratorio del Lago\n"
"per studiare come nutrire i\n"
"Pocket Cuccos...   "
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che i Gerudos, a volte, \n"
"vanno in citta' alla ricerca di   \n"
"una fidanzata...   "
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che il ladro di nome Nabooru,\n"
"che infesta la zona, sia' un   \n"
"Gerudo.  "
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che se ti avvicini ad una farfalla\n"
"mentre porti un Ramo Deku   \n"
"nelle tue mani, qualcosa di  \n"
"buono, succedera'."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che puoi trovare qualcosa\n"
"di nuovo nei dungeons che\n"
"hai gia' visitato...         "
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che i Gerudos venerano\n"
"Ganondorf quasi come un dio...   "
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é un segreto vicino    \n"
"all'entrata alla Valle dei   \n"
"Gerudo. "
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che il gufo di nome     \n"
"Kaepora Gaebora é la\n"
"reincarnazione di un antico Saggio."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che lo strano gufo,    \n"
"Kaepora Gaebora, puo' sembrare  \n"
"scontroso, ma é di carattere        \n"
"generoso...  "
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che XXcentury ha inserito\n"
"8 citazioni da cinema,\n"
"libri, canzoni etc..."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che Ganondorf non si accontenta\n"
"di governare solamente i   \n"
"Gerudo, punta a conquistare   \n"
"Hyrule!!  "
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che il premio che puoi     \n"
"ottenere nel campo di allenamento\n"
"Gerudo non é poi cosi' grande \n"
"in confronto alla difficolta'!    "
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che c'é una grata nascosta che\n"
"puo' essere aperta solo con \n"
"l'Attacco Rotante.    "
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che é possibile trovare un\n"
"massimo di 100 AracnoTeschi Aurei \n"
"nel regno di Hyrule."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che quelli senza una Fatina, \n"
"nei Boschi Perduti, diventino\n"
"dei mostri!   "
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che le piccole buche nel \n"
"terreno, che puoi trovare in tutta\n"
"Hyrule siano un ottimo nascondiglio\n"
"per gli insetti."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che i Kokiri sono sempre  \n"
"seguiti da piccole fatine...     "
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"...Che ci sia un Kokiro che ha lasciato\n"
"la foresta ma é ancora\n"
"vivo!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Ma cos'é??  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "E' un mostruoso parassita che vive\n"
"all'interno dell'Albero! L'" COLOR(DEFAULT) "occhio" COLOR(LIGHTBLUE) "\n"
" é debole quando é rosso" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Uovo Gohma\n"
COLOR(LIGHTBLUE) "Quando l'uovo si schiude, nasce\n"
"una Larva Gohma. " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larva Gohma\n"
COLOR(LIGHTBLUE) "Controlla quando e' pronta al \n"
"salto! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Aracnoteschio\n"
COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "ventre" COLOR(LIGHTBLUE) " é il punto debole! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "MaxiAracnoTeschio\n"
COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "ventre" COLOR(LIGHTBLUE) " é il punto debole! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tailpasaran\n"
COLOR(LIGHTBLUE) "La" COLOR(DEFAULT) " coda " COLOR(LIGHTBLUE) "é il punto debole! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Colpiscilo mentre balza su di te,\n"
"si irrigidira' subito. Taglialo\n"
"e otterrai un " COLOR(DEFAULT) "Ramo Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) "   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Super Baba   \n"
COLOR(LIGHTBLUE) "Colpiscilo mentre balza su di te,\n"
"si irrigidira' subito. Taglialo\n"
"e otterrai un " COLOR(DEFAULT) "Ramo Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) "   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Sebbene sembri avvizzito, ti fara'\n"
"male se solo lo tocchi! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Arbusto Deku\n"
COLOR(LIGHTBLUE) "Si nasconde nella pianta se ti\n"
"avvicini. Quando sputa la noce  \n"
"ritiragliela addosso!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "King Dodongo\n"
COLOR(LIGHTBLUE) "Questo é un immenso Dodongo,\n"
"mangia tutto! Causagli uno shock,\n"
"e finiscilo con la " COLOR(DEFAULT) "spada" COLOR(LIGHTBLUE) "!       " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Attento al suo alito di fuoco!\n"
"Usa la tecnica dello " COLOR(DEFAULT) "[Z] premuto" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baby Dodongo\n"
COLOR(LIGHTBLUE) "Attento ai suoi balzi d'attacco! \n"
"Esplodera' una volta sconfitto!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos \n"
COLOR(LIGHTBLUE) "Usa bene lo scudo e combatti con \n"
"la tecnica dello " COLOR(DEFAULT) "[Z] Attivato" COLOR(LIGHTBLUE) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos \n"
COLOR(LIGHTBLUE) "Usa bene lo scudo e combatti con \n"
"la tecnica dello " COLOR(DEFAULT) "[Z] Attivato" COLOR(LIGHTBLUE) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pipistrelllo Infiammato\n"
COLOR(LIGHTBLUE) "Colpiscilo prima che plani su\n"
"di te o la sua fiamma\n"
"brucera' il tuo" COLOR(DEFAULT) " Scudo Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pipistrello\n"
COLOR(LIGHTBLUE) "Avvicinati e usa lo     \n"
COLOR(DEFAULT) "[Z] Attivato" COLOR(LIGHTBLUE) ". Anche se vola via,\n"
"potrai averlo nel mirino.    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armos\n"
COLOR(LIGHTBLUE) "Ferma i suoi movimenti e \n"
"distruggilo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinade\n"
COLOR(LIGHTBLUE) "Molte meduse parassita circondano\n"
"questo mostro. Punta al suo\n"
"corpo, protetto dalle meduse!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tentacolo Parassita?\n"
COLOR(LIGHTBLUE) "Sembra che la parte piu' stretta\n"
"sia il punto debole...Ti serve\n"
"un arma particolare pero'!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shabom\n"
COLOR(LIGHTBLUE) "Se provi a tagliarla, rimbalzera' via\n"
"dalla lama!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "Se lo tocchi, sarai elettrificato!\n"
"       " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "Se lo tocchi, sarai elettrificato!\n"
"        " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stinger\n"
COLOR(LIGHTBLUE) "Eliminalo prima che plani su di te! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spettro Ganon\n"
COLOR(LIGHTBLUE) "E' un fantasma malvagio del Tempio\n"
"della Foresta!\n"
"E' uscito da uno dei quadri!"
BOX_BREAK
COLOR(LIGHTBLUE) "Rispondi all'attacco magico\n"
"con la sua magia!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Attiralo vicino a te e guarda i\n"
"suoi movimenti bene!\n"
"Attaccalo quando abbassa la guardia! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "TeschioBlu \n"
COLOR(LIGHTBLUE) "Difenditi dalla sua fiamma blu\n"
"con lo " COLOR(DEFAULT) "scudo" COLOR(LIGHTBLUE) "!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "TeschioBianco\n"
COLOR(LIGHTBLUE) "Colpisci quando é fermo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "TeschioVerde\n"
COLOR(LIGHTBLUE) "Usa la spada quando sparisce\n"
"la fiamma verde" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AracnoTeschio\n"
COLOR(LIGHTBLUE) "Attento a non toccarlo!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AracnoTeschio Aureo\n"
COLOR(LIGHTBLUE) "E' conosciuto anche come \n"
"Ragno Maledetto. Sconfiggilo e otterrai\n"
"un" COLOR(DEFAULT) " simbolo" COLOR(LIGHTBLUE) "!!        " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volvagia\n"
COLOR(LIGHTBLUE) "E' il Boss del Tempio del Fuoco,\n"
"resuscitato dal Re del Male. Non\n"
"so se ha punti deboli..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "DanzaFiamme \n"
COLOR(LIGHTBLUE) "Spegni prima le" COLOR(DEFAULT) " sue lingue di \n"
"fuoco" COLOR(LIGHTBLUE) "... " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Blob Infuocato\n"
COLOR(LIGHTBLUE) "Quando il fuoco sul dorso si\n"
"estingue, scappera' via...\n"
"Eliminalo prima che si riformi!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Teschio Rosso\n"
COLOR(LIGHTBLUE) "Difenditi dal suo attacco\n"
"con lo " COLOR(DEFAULT) "scudo" COLOR(LIGHTBLUE) "! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morpha\n"
COLOR(LIGHTBLUE) "Signore del Tempio dell'Acqua. \n"
"Ha un controllo assoluto dell'acqua.\n"
"Estrai il " COLOR(DEFAULT) "nucleo" COLOR(LIGHTBLUE) " e attaccalo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  NAME " Oscuro\n"
COLOR(LIGHTBLUE) "Combattiti!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "LamOstrica\n"
COLOR(LIGHTBLUE) "Il " COLOR(DEFAULT) "muscolo interno" COLOR(LIGHTBLUE) " é la sua" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "debolezza! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spike\n"
COLOR(LIGHTBLUE) "Colpiscilo quando ritrae le sue\n"
"spine! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Signore del Tempio Ombra,\n"
"resuscitato dalla tomba. Guardalo\n"
"con l'" COLOR(DEFAULT) "occhio di verita'" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Zombie\n"
COLOR(LIGHTBLUE) "Il suo sguardo ti paralizza. Se\n"
"ti morde, " COLOR(DEFAULT) "premi un bottone" COLOR(LIGHTBLUE) " per\n"
"fuggire!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Spettro Ganon\n"
COLOR(LIGHTBLUE) "Attaccalo" COLOR(RED) " " COLOR(DEFAULT) "quando esce da uno   \n"
"dei quadri" COLOR(LIGHTBLUE) "!         \n"
"Attento a quello falso!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Il suo sguardo ti paralizza. Se\n"
"ti morde, " COLOR(DEFAULT) "premi un bottone " COLOR(LIGHTBLUE) "per\n"
"fuggire" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grande Mano Morta\n"
COLOR(LIGHTBLUE) "Se ti prende, " COLOR(DEFAULT) "premi un bottone\n"
COLOR(LIGHTBLUE) "per fuggire!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mano Morta\n"
COLOR(LIGHTBLUE) "Attento alle sue mani infinite! \n"
"Punta alla testa!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wallmaster\n"
COLOR(LIGHTBLUE) "Attento alla sua " COLOR(DEFAULT) "ombra" COLOR(LIGHTBLUE) " sul\n"
"pavimento. Distruggilo prima che\n"
"discenda giu' dal soffitto! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Floormaster\n"
COLOR(LIGHTBLUE) "Quando si separa, elimina tutti i\n"
"pezzi prima che si riformi! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Koume\n"
COLOR(LIGHTBLUE) "E' una delle Madri di Ganondorf.\n"
"Strega del Fuoco.\n"
"E' vulnerabile al " COLOR(DEFAULT) "freddo intenso" COLOR(LIGHTBLUE) ".      " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Kotake\n"
COLOR(LIGHTBLUE) "E' una delle madri di Ganondorf.\n"
"Strega del Ghiaccio.\n"
"E' vulnerabile al " COLOR(DEFAULT) "caldo intenso" COLOR(LIGHTBLUE) ".   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Nocca Metallica\n"
COLOR(LIGHTBLUE) "E' qualcosa di strano...\n"
"Non é un classico nemico!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Nocca Metallica\n"
COLOR(LIGHTBLUE) "Attento al suo attacco!\n"
"Fa molto male! Colpisci quando\n"
"abbassa la guardia!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ragazzo Perduto\n"
COLOR(LIGHTBLUE) "Succede questo a quelli che\n"
"si perdono nella foresta? Sembra\n"
"che non abbia voluto crescere" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Like Like\n"
COLOR(LIGHTBLUE) "Un nemico che mangia" COLOR(DEFAULT) " scudi " COLOR(LIGHTBLUE) "e\n"
"alcuni " COLOR(DEFAULT) "vestiti" COLOR(LIGHTBLUE) ". Colpiscilo\n"
"velocemente per riaverli!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Raggios\n"
COLOR(LIGHTBLUE) "Attento ai loro raggi laser!\n"
"Credo che non gli piaccia il" COLOR(DEFAULT) "\n"
"fumo" COLOR(LIGHTBLUE) " nei loro occhi! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anubis\n"
COLOR(LIGHTBLUE) "E' vulnerabile al " COLOR(RED) "fuoco" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Freezzard\n"
COLOR(LIGHTBLUE) "Attento al suo respiro\n"
"congelante! Distruggilo totalmente\n"
"o si riformera'. " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf il Re del Male\n"
COLOR(LIGHTBLUE) "Non conosco il suo\n"
"punto debole!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "Non so davvero quale sia il suo\n"
"punto debole!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ragazzo Perduto\n"
COLOR(LIGHTBLUE) "Succede questo a chi si perde\n"
"nella foresta? Diverra' nostro \n"
"amico se facciamo qualcosa...    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ragazzo Perduto\n"
COLOR(LIGHTBLUE) "Succede questo a chi si perde\n"
"nella foresta? Sembra infelice\n"
"di non avere una faccia..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ragazzo Perduto\n"
COLOR(LIGHTBLUE) "Succede questo a chi si perde\n"
"nella foresta? Sembra contento \n"
"della sua faccia da teschio.." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Ritiragli le rocce che ti sputa\n"
"addosso" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe del cimitero?    \n"
COLOR(LIGHTBLUE) "Se lo inquadri con lo " COLOR(DEFAULT) "[Z]   \n"
"Attivato" COLOR(LIGHTBLUE) ", sparira' subito...   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "Se lo inquadri con lo " COLOR(DEFAULT) "[Z]   \n"
"Attivato" COLOR(LIGHTBLUE) ", sparira' subito...   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tektite Rossa\n"
COLOR(LIGHTBLUE) "Quando salta utilizza lo " COLOR(DEFAULT) "[Z]  \n"
"Attivato" COLOR(LIGHTBLUE) "!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tektite Blu \n"
COLOR(LIGHTBLUE) "E' difficile batterla sull'acqua.\n"
"Attirala fuori!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Segui bene i suoi movimenti e\n"
"lascialo andare" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "E' debole nelle sue " COLOR(DEFAULT) "radici" COLOR(LIGHTBLUE) "! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat Larva\n"
COLOR(LIGHTBLUE) "Difenditi con lo " COLOR(DEFAULT) "scudo" COLOR(LIGHTBLUE) "! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lupos \n"
COLOR(LIGHTBLUE) "Attiralo vicino a te e segui \n"
"bene i suoi movimenti!\n"
"Attaccalo quando abbassa la guardia!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Scrub Pazzo\n"
COLOR(LIGHTBLUE) "Avvicinati e si nascondera'\n"
"veloce nell'erba...    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Scrub Affarista\n"
COLOR(LIGHTBLUE) "Se ti avvicini, si nascondera'      \n"
"nell'erba...   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spettro Dampé\n"
COLOR(LIGHTBLUE) "E' il fantasma del custode\n"
"del cimitero! Se lo catturerai,\n"
"forse, ti dara' il suo " COLOR(DEFAULT) "tesoro" COLOR(LIGHTBLUE) "...  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg - una delle sorelle Poe \n"
COLOR(LIGHTBLUE) "Se si divide in piu' immagini,     \n"
"dovrai capire quale di queste é \n"
"quella " COLOR(DEFAULT) "reale" COLOR(LIGHTBLUE) ". Sara' forse questa?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle - una delle sorelle Poe \n"
COLOR(LIGHTBLUE) "Colpiscila quando appare!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beth - una delle sorelle Poe \n"
COLOR(LIGHTBLUE) "Colpiscila quando appare!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy - una delle sorelle Poe \n"
COLOR(LIGHTBLUE) "Colpiscila quando appare!    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ladro Gerudo\n"
COLOR(LIGHTBLUE) "Quando abbassa la guardia,\n"
"attacca! Se vieni sconfitto,\n"
"verrai catturato!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalchild\n"
COLOR(LIGHTBLUE) "Non aver paura dello Stalchild!\n"
"Devi colpirlo senza sosta!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pipistrello dei Giacci\n"
COLOR(LIGHTBLUE) "Colpiscilo subito!     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lupos Bianco\n"
COLOR(LIGHTBLUE) "Attiralo vicino a te, ma attento\n"
"ai suoi movimenti! Attaccalo quando\n"
"abbassa la guardia!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guay\n"
COLOR(LIGHTBLUE) "Eliminalo prima che plani\n"
"su di te! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "BigOcto\n"
COLOR(LIGHTBLUE) "Attaccala da dietro!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grosso Poe\n"
COLOR(LIGHTBLUE) "Questo Poe non sparisce\n"
"anche se lo inquadri. Anche se é\n"
"grosso é velocissimo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova\n"
COLOR(LIGHTBLUE) "E' l'unione delle due streghe\n"
"Kotake e Koume. Rivolgi i\n"
COLOR(DEFAULT) "colpi magici" COLOR(LIGHTBLUE) " contro di loro!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "Questo Poe non sparisce anche se  \n"
"lo inquadri. Non sparisce molto  \n"
"facilmente...     " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "Suona con " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".     \n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Suona con " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; con " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " smetti.\n"
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
QUICKTEXT_ENABLE  SHIFT("\x16") "E' il " COLOR(ADJUSTABLE) "Minuetto dei Boschi" COLOR(DEFAULT) "!" COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT)  QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F") "E' il " COLOR(RED) "Bolero del Fuoco" COLOR(DEFAULT) "! \n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "E' la " COLOR(BLUE) "Serenata dell'Acqua" COLOR(DEFAULT) "! \n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15") "E' il " COLOR(YELLOW) "Requiem dello Spirito" COLOR(DEFAULT) "\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0D") "E' il " COLOR(PURPLE) "Notturno delle Ombre" COLOR(DEFAULT) "! \n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "E' il " COLOR(LIGHTBLUE) "Preludio alla Luce" COLOR(DEFAULT) "! \n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0B") "Seguimi con la " COLOR(ADJUSTABLE) "Canzone di Saria" COLOR(DEFAULT) "\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "E' la " COLOR(RED) "Canzone di Epona" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27") "Ricorda " COLOR(BLUE) "la canzone" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tieni la " COLOR(YELLOW) "Canzone del Sole" COLOR(DEFAULT) " nel cuore\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "La Canzone " COLOR(DEFAULT) "apre la Porta del Tempo.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17") "Non la dimentichero' " COLOR(PURPLE) "MAI" COLOR(DEFAULT) "!!  \n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Suona con " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; con " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " smetti.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(RED) "Non funziona qui!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Vola ai Boschi Perduti?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Vola al Cratere della\n"
"Montagna?    " COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(BLUE) "Vola al Lago Hylia?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Vola al Colosso del Deserto?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Vola al Cimitero?     " COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Vola al Tempio del Tempo?  " COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Suoni il " COLOR(ADJUSTABLE) "Minuetto dei Boschi" COLOR(DEFAULT) ".   \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0E") "Suoni il " COLOR(RED) "Bolero del Fuoco" COLOR(DEFAULT) ".    \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Suoni la " COLOR(BLUE) "Serenata dell'Acqua" COLOR(DEFAULT) ".    \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Suoni il " COLOR(YELLOW) "Requiem dello Spirito" COLOR(DEFAULT) ".  \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Suoni il " COLOR(PURPLE) "Notturno delle Ombre" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Suoni il " COLOR(LIGHTBLUE) "Preludio alla Luce" COLOR(DEFAULT) ".    \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Suoni: " COLOR(ADJUSTABLE) "Canzone di Saria" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Suoni: " COLOR(RED) "Canzone di Epona" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x18") "Suoni: " COLOR(BLUE) "Ninnananna di Zelda" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Suoni: " COLOR(YELLOW) "Canzone del Sole" COLOR(DEFAULT) ".  \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Suoni la " COLOR(LIGHTBLUE) "Canzone del Tempo" COLOR(DEFAULT) ". \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Suoni: " COLOR(PURPLE) "Canzone della Tempesta" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Suoni: " COLOR(YELLOW) "Canzone Spaventapasseri" COLOR(DEFAULT) ". \n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Era ora, sei sveglio!\n"
"Sono" COLOR(RED) " Navi" COLOR(LIGHTBLUE) " la Fata!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "L'Albero Deku mi ha inviato\n"
"come tua " COLOR(RED) "Guida" COLOR(LIGHTBLUE) " sono     \n"
"contenta di conoscerti!! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x12") "Ciao! Ehi, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma...Una Fata!"
BOX_BREAK
UNSKIPPABLE "Alla fine anche tu ne hai una\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti aspettero' qui...   \n"
"Vai ora! \n"
"Vai dal Grande Albero!!      "
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(BLUE) "[A] " COLOR(DEFAULT) "sui sassi, li solleverai!\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "sui sassi, li solleverai!"
BOX_BREAK
"Malefico" COLOR(RED) " Mido" COLOR(DEFAULT) "...mi ha mandato a \n"
"spostare le pietre da casa sua.    "
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Anche tu hai una " COLOR(LIGHTBLUE) "Fatina" COLOR(DEFAULT) "?! \n"
"E' grandioso, " NAME "!"
BOX_BREAK
UNSKIPPABLE "Cosa?"
BOX_BREAK
UNSKIPPABLE "Sei stato chiamato dal   \n"
COLOR(RED) "Grande Albero" COLOR(DEFAULT) "? Che onore!!     "
BOX_BREAK
UNSKIPPABLE "Ti dara' un regalo speciale!!  \n"
"Tee hee!"
BOX_BREAK
UNSKIPPABLE "Questo perche' il Sacro Albero\n"
"Deku e' nostro Padre, nostro \n"
"protettore. Ha dato la vita a tutti\n"
"noi Kokiri!  "
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi chiedo se il " COLOR(RED) "Grande Albero  " COLOR(DEFAULT) "\n"
"ha dato la vita a ogni cosa \n"
"nella foresta, l'ha data anche\n"
"a noi Kokiri?"
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ok, ti svelero' qualche mossa!"
BOX_BREAK
"Il " COLOR(RED) "Salto di Lato " COLOR(DEFAULT) "con " COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) "\n"
"si fa con " COLOR(BLUE) "[A] " COLOR(DEFAULT) "a sinistra o destra. "
BOX_BREAK
"Per fare una " COLOR(RED) "Capriola " COLOR(DEFAULT) "tieni  \n"
COLOR(LIGHTBLUE) "[Z] Attivato " COLOR(DEFAULT) "e premi " COLOR(BLUE) "[A] " COLOR(DEFAULT) "muovendoti\n"
"indietro."
BOX_BREAK
"Farai un " COLOR(RED) "Attacco Basso" COLOR(DEFAULT) " con \n"
COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", se premi " COLOR(BLUE) "[A] " COLOR(DEFAULT) "e vai in  \n"
"avanti. Rotolando, potrai evitare\n"
"colpi nemici."
BOX_BREAK
"Se hai la Spada sguainata con lo \n"
COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", potrai fare un" COLOR(RED) "\n"
"Colpo Aereo" COLOR(DEFAULT) " premendo" COLOR(BLUE) " [A]" COLOR(DEFAULT) "!\n"
"Un colpo aereo causa doppio danno!"
BOX_BREAK
"Prova ad usare lo " COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) " sul\n"
COLOR(RED) "sasso" COLOR(DEFAULT) " qui vicino.\n"
"Dai prova e impara! "
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non ti e' permesso lasciare la \n"
"foresta." TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il Sacro Albero Deku dice che se\n"
"un Kokiro lascia i boschi, morira'\n"
"di sicuro!  "
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Il malvagio " COLOR(RED) "Mido" COLOR(DEFAULT) ", mi ha obbligato\n"
"a tagliare l'erba qui a\n"
"casa di Saria.    "
BOX_BREAK
UNSKIPPABLE "Gli piace, e si prendera' \n"
"tutto il merito.\n"
"Ma a faticare sono io!      " TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu e " COLOR(RED) "Saria" COLOR(DEFAULT) " siete grandi amici,   \n"
"mi aiuteresti a sfalciare l'erba? "
BOX_BREAK
"Ti lascero' tenere tutto cio'   \n"
"che troverai tagliandola. "
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Si, Si!\n"
"E' cosi' che si usa la " COLOR(LIGHTBLUE) "Fatina" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "E' meraviglioso che anche tu abbia\n"
"una " COLOR(RED) "Fatina" COLOR(DEFAULT) " ora! "
BOX_BREAK
UNSKIPPABLE "Ti spieghero' come si puo'\n"
"parlare tramite la Fatina!  " TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando la Fatina é vicina a persone\n"
"o cose, premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " e potrai\n"
COLOR(RED) "Osservare" COLOR(DEFAULT) " meglio."
BOX_BREAK
"Se tieni " COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", potrai \n"
"parlare con persone distanti, cosi'\n"
"come facciamo noi ora."
BOX_BREAK
"Quando non c' é niente a cui  \n"
"mirare (target), premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " solo   \n"
"per" COLOR(RED) " Osservare" COLOR(DEFAULT) ".  \n"
"Prova! "
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, anche tu hai una " COLOR(LIGHTBLUE) "Fata" COLOR(DEFAULT) " ora!  "
BOX_BREAK
UNSKIPPABLE "Dovrai imparare tante cose! " TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Wow! " QUICKTEXT_ENABLE "Grande notizia!!  " QUICKTEXT_DISABLE "\n"
"Sono felice per te!  "
BOX_BREAK
UNSKIPPABLE "Ora sei un vero Kokiro,  \n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma e' vero?    \n"
"Il Sacro Albero Deku ti \n"
"ha convocato?"
BOX_BREAK
UNSKIPPABLE "E' un grande onore parlare con il \n"
"Grande Albero!! " TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, vai via allora..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ma va bene, perche' noi saremo \n"
"amici per sempre..\n"
"E' vero? "
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti voglio dare questa Ocarina...  \n"
"Ti prego tienila da conto.  "
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando la suonerai, io spero, che\n"
"ti ricorderai di me, e che un\n"
"giorno ci potremo rivedere."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh... Navi...\n"
"Sei dunque tornata..."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Benvenuto."
BOX_BREAK
UNSKIPPABLE "Ascolta attentamente cio' che  \n"
COLOR(RED) "Io Deku" COLOR(DEFAULT) ", sto per raccontarti...    "
BOX_BREAK
UNSKIPPABLE "Nelle scorse lune i tuoi sogni\n"
"sono stati agitati,\n"
"dei veri e propri incubi...  "
BOX_BREAK
UNSKIPPABLE "I servi del Male hanno ottenuto  \n"
"forza, e il male si é diffuso \n"
"nel Regno causando incubi ai\n"
"Kokiri piu' sensibili..."
BOX_BREAK
UNSKIPPABLE "In verita', tu lo hai percepito."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Il tempo del coraggio e'  \n"
"arrivato...  " TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono stato" COLOR(RED) " STREGATO" COLOR(DEFAULT) ". \n"
"Devi spezzare la maledizione \n"
"con coraggio e saggezza.     "
BOX_BREAK
"Te la senti di intraprendere \n"
"questo duro compito?   \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "..Allora entra,   \n"
NAME ",\n"
"e anche tu, Navi...   "
BOX_BREAK
UNSKIPPABLE "Oh Fata Navi... \n"
"Devi aiutare " NAME "...   "
BOX_BREAK
UNSKIPPABLE "E tu " NAME ", quando" COLOR(LIGHTBLUE) " Navi " COLOR(DEFAULT) "\n"
"parla, usa " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "per ascoltare\n"
"le sue parole di aiuto...  "
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Forse non hai ancora chiare\n"
"quali siano le tue abilita'...  \n"
"Ritorna alla Foresta Kokiri ad\n"
"imparare l'arte di combattere"
BOX_BREAK
"Quando sarai pronto, torna pure  \n"
"qui e parlami premendo " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "...    "
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il miglior luogo per imparare\n"
"delle nuove abilita' é il " COLOR(ADJUSTABLE) "Centro \n"
"Di Allenamento" COLOR(DEFAULT) "." COLOR(ADJUSTABLE)  COLOR(DEFAULT) " E' sulla collina\n"
"proprio la sopra."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Ow-ow-ow!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Perdonami, padrone!" QUICKTEXT_DISABLE "\n"
"Se ti daro' un indizio mi lascerai\n"
"andare?"
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Quando salti da un burrone alto\n"
"tieni premuto " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " in avanti,  \n"
"rotolerai sul terreno e atterrando  \n"
"non ti farai male per la caduta. "
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Non ti posso garantire   \n"
"che funzioni, se il burrone e' molto,\n"
"molto alto, hee heee!"
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Bene, provaci se ti senti un \n"
"eroe!! \n"
QUICKTEXT_ENABLE "Wah ha hah!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Sotto la maschera...\n"
"Sei il ragazzo Kokiri?  "
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma che strana maschera che hai!\n"
"Anche se, eeh eeh! Mi piace!  \n"
"Mi farebbe sembrare un vero duro... "
BOX_BREAK
"Ehi, perche' non me la vendi?    \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dai! Ci...tenevo molto...    "
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yowza! La indossero' tutto \n"
"il tempo!!   "
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Ti ha dato solo " COLOR(RED) "10 Rupié" COLOR(DEFAULT) " per   \n"
"una maschera da 20!\n"
"Non é stato un buon affare!  "
BOX_BREAK
UNSKIPPABLE "Al Negozio di Maschere, devi\n"
"ridare " COLOR(RED) "20 Rupié" COLOR(DEFAULT) " per la maschera.\n"
"La differenza dovra' venir\n"
"fuori dalle tue tasche!    "
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tutti i miei amici invidiano la\n"
"mia maschera!!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, stai bene? E cosi' non hai  \n"
"lasciato la foresta dopotutto?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lo sapevi che tenundo premuto " COLOR(LIGHTBLUE) "▼\n"
COLOR(DEFAULT) " in avanti quando salterai da un  \n"
"burrone rotolerai per terra. Questo \n"
"attenuera' il tuo atterraggio. "
BOX_BREAK
"Comunque se salti da troppo alto, ti\n"
"ferirai lo stesso!"
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria ti sta aspettando al\n"
"solito posto... "
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ben fatto, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai una Fionda proprio forte, eh?"
BOX_BREAK
"E sai cosa é proprio forte? \n"
"Il fatto che puoi mirare con  \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e tirare rilasciando il tasto!\n"
"Che forza!   "
BOX_BREAK
"Se hai gia' estratto la fionda, \n"
"e il tasto " COLOR(LIGHTBLUE) "[Z] é attivato" COLOR(DEFAULT) "    \n"
COLOR(RED) "tirerai muovendoti" COLOR(DEFAULT) ".\n"
"...Di, lo sapevi?     "
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"No, " NAME "...\n"
"Dovresti sapere che ho poco tempo."
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Allora, ascoltami bene...\n"
"Un" COLOR(RED) " Malvagio Stregone Nomade" COLOR(DEFAULT) "\n"
"mi ha lanciato una maledizione...  "
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se stai cercando Saria, si trova, \n"
"come sempre, nei " COLOR(ADJUSTABLE) "Boschi Perduti" COLOR(DEFAULT)
BOX_BREAK
"Non dirmi che non sai dove\n"
"sono! L'entrata si trova proprio \n"
"sulla rupe che domina il villaggio!  "
BOX_BREAK
"Lo so gia', ti perderai! Non ti\n"
"preoccupare, bastera'\n"
"tornare indietro!        "
BOX_BREAK
SHIFT("\x51")  QUICKTEXT_ENABLE "Harumph!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non devi consentire al nomade   \n"
"dalla nera armatura di mettere \n"
"le mani sulla sacra TriForza..."
BOX_BREAK
UNSKIPPABLE "Non devi tollerare, che il suo  \n"
"nero cuore, possa accedere al     \n"
"Sacro Reame." COLOR(RED) " " COLOR(DEFAULT) "            "
BOX_BREAK
UNSKIPPABLE "Quel demonio mi ha lanciato una \n"
"maledizione che non lascia\n"
"scampo..."
BOX_BREAK
UNSKIPPABLE "Per questo la mia fine é vicina.\n"
"...aah..."
BOX_BREAK
UNSKIPPABLE "Nonostante i tuoi eroici sforzi\n"
"per spezzare questa maledizione,  \n"
"ero gia' condannato da tempo...  "
BOX_BREAK
UNSKIPPABLE "Si,..moriro' molto presto...\n"
UNSKIPPABLE "Ma non state in pena per me."
BOX_BREAK
UNSKIPPABLE "Ho avuto la possibilita' di dirvi  \n"
"cose importantissime..."
BOX_BREAK
UNSKIPPABLE "Siete la mia unica speranza..."
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il futuro dipende da te...   \n"
NAME "...\n"
"Dal tuo, coraggio...  "
BOX_BREAK
UNSKIPPABLE "Navi e anche tu..\n"
NAME " fate...la mia... \n"
"volonta'..."
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "Io..vado..ora...Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "Aaa...ddio..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Al Castello di Hyrule ora,\n"
NAME "!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Addio...   " COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "Grande Albero...  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Peccato...Heh heh!"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi giocare di nuovo?        \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi Tu! \"" COLOR(LIGHTBLUE) "Mr.Senza Fata" COLOR(DEFAULT) "\"!\n"
"Perche' dovresti andare dal  \n"
"Grande Albero?"
BOX_BREAK
UNSKIPPABLE "Senza una Fatina, non sei \n"
"nemmeno un Kokiro! " TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se vorrai passare di qua dovrai, \n"
"quantomeno " COLOR(BLUE) "indossare " COLOR(DEFAULT) "la " COLOR(ADJUSTABLE) "Spada" COLOR(RED) "    \n"
COLOR(DEFAULT) "e lo" COLOR(LIGHTBLUE) " Scudo" COLOR(DEFAULT) "!"
BOX_BREAK
SHIFT("\x51")  QUICKTEXT_ENABLE "Sheesh!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x43")  QUICKTEXT_ENABLE "COSA?!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "non ti vuol lasciare  \n"
"vedere il Grande Deku?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puoi comprare lo " COLOR(LIGHTBLUE) "Scudo" COLOR(DEFAULT) " al negozio,\n"
"ma c'e' solo una " COLOR(LIGHTBLUE) "Spada " COLOR(DEFAULT) "\n"
"nascosta bene nella foresta...    "
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se vuoi andare dal    \n"
"Grande Albero Deku, dovrai trovare  \n"
"almeno la " COLOR(ADJUSTABLE) "Spada" COLOR(DEFAULT) " e lo" COLOR(LIGHTBLUE) " Scudo" COLOR(DEFAULT) "!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Io, il Grande " COLOR(RED) "Mido" COLOR(DEFAULT) ", non ti\n"
"riterro' mai un vero Kokiro!"
BOX_BREAK
"Dimmi! Come fai ad essere il  \n"
"preferito di Saria ed ora\n"
"del Grande Albero? Huh?!\n"
"Grumble...grumble..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ti insegnero' l'uso delle " COLOR(RED) "Icone\n"
COLOR(DEFAULT) "in alto sullo schermo.   \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Spiega l'Icona Gialla \n"
"Spiega l'Icona Blu " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I tre cerchi gialli in alto a \n"
"destra si chiamano " COLOR(YELLOW) "Icone Item" COLOR(DEFAULT) ". "
BOX_BREAK
"Essi visualizzano le cose che  \n"
"userai con i tasti " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "e " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ".     "
BOX_BREAK
"Ottenuto un " COLOR(YELLOW) "[C] Item idoneo" COLOR(DEFAULT) ",  \n"
"spostati sul " COLOR(YELLOW) "Menu' Selezione Item  " COLOR(DEFAULT) " \n"
"ed applicalo ad uno dei tre   \n"
"tasti " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"L'Icona Blu in alto sullo schermo  \n"
"e' la cosiddetta " COLOR(BLUE) "Action Icon" COLOR(DEFAULT) "."
BOX_BREAK
"Questa Action Icon mostra  \n"
"quale azione effettuerai \n"
"premendo il tasto " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
"Fermati in piu' posti e studia\n"
"le varie combinazioni...   "
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se vuoi imparare qualcosa su: \n"
COLOR(RED) "Mappa" COLOR(DEFAULT) " e " COLOR(RED) "Oggetti" COLOR(DEFAULT) " chiedi pure.\n"
"Ma sappi che dovrai ascoltare\n"
"una lunga spiegazione...  "
BOX_BREAK
"Allora cosa vuoi sapere?       \n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Della Mappa   \n"
"Gli Oggetti\n"
"Niente   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Guarda la " COLOR(RED) "Mappa" COLOR(DEFAULT) " visualizzata in\n"
"basso a destra,            "
BOX_BREAK
"la " COLOR(YELLOW) "Punta Gialla " COLOR(DEFAULT) "ti mostra   \n"
"l'attuale posizione e direzione in\n"
"cui ti trovi. La " COLOR(RED) "Rossa " COLOR(DEFAULT) "indica \n"
"l'area da dove sei entrato.     "
BOX_BREAK
"Puoi attivare o disattivare la \n"
"mappa premendo " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) ".  "
BOX_BREAK
"Sei vuoi sapere in quale luogo ti\n"
"trovi premi " COLOR(RED) "START" COLOR(DEFAULT) "."
BOX_BREAK
"Si attivera' l'Area SottoMenu. \n"
"Seleziona " COLOR(RED) "Il Menu' Map" COLOR(DEFAULT) ".  "
BOX_BREAK
"Sul Menu' Mappa, potrai vedere\n"
"la mappa di HYRULE. \n"
"Ti é piu' chiaro ora?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ci sono 3 categorie di Oggetti:\n"
COLOR(BLUE) "Equipaggiamento" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C] Item Magici " COLOR(DEFAULT) "\n"
"e " COLOR(LIGHTBLUE) "Utensili" COLOR(DEFAULT) ".     "
BOX_BREAK
COLOR(BLUE) "Equipaggiamento" COLOR(DEFAULT) " e' tutto cio'   \n"
"che puoi indossare quindi spade, \n"
"scudi, vestiti e cosi' via... \n"
"    "
BOX_BREAK
"Gli " COLOR(YELLOW) "Item Magici" COLOR(DEFAULT) " sono assegnati\n"
"a " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) ", e " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", sono usati\n"
"premendo questi tasti.  "
BOX_BREAK
COLOR(LIGHTBLUE) "Gli Utensili" COLOR(DEFAULT) " sono tutte quelle    \n"
"cose che trovi nell'avventura   \n"
"e ti porti dietro."
BOX_BREAK
"Se vuoi cambiare equipaggiamento\n"
"o solo controllare l'inventario\n"
"premi " COLOR(RED) "START" COLOR(DEFAULT) ". \n"
"Si attiveranno i SottoMenu.      "
BOX_BREAK
"Scegli uno dei quattro    \n"
"differenti SottoMenu con " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " o  \n"
COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "e cambia o controlla come  \n"
"meglio credi. Dai un'occhiata!  "
BOX_BREAK
"Quando hai deciso ad esempio\n"
COLOR(BLUE) "Equipaggiamento" COLOR(DEFAULT) ", premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".\n"
"Per gli " COLOR(YELLOW) "[C] Items" COLOR(DEFAULT) ", premerai " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "o " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". "
BOX_BREAK
"E' stata una buona,\n"
"ma lunga spiegazione.\n"
"Ti é tutto chiaro ora? "
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Va bene, ma ricordati che... \n"
"Se vuoi " COLOR(ADJUSTABLE) "Salvare" COLOR(DEFAULT) ", premi " COLOR(RED) "START " COLOR(DEFAULT) "ed  \n"
"accederai ai SottoMenu,\n"
"poi premi " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mia sorella ha preso i soldi,\n"
"ed e' andata al negozio,\n"
"quello dal tetto rosso! \n"
"Tee hee!"
BOX_BREAK
"Parlando di " COLOR(RED) "Rupié" COLOR(DEFAULT) ", la " COLOR(ADJUSTABLE) "Verde " COLOR(DEFAULT) "ne\n"
"vale solo una, la" COLOR(BLUE) " Blu" COLOR(DEFAULT) " ne vale cinque  \n"
"e la" COLOR(RED) " Rossa" COLOR(DEFAULT) " ne vale ben venti!  \n"
"Hee hee! "
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo negozio, vende cose che\n"
"si trovano gratis nella foresta!\n"
"Tee hee!"
BOX_BREAK
"Sai come si deve usare lo  \n"
COLOR(RED) "Scudo Deku" COLOR(DEFAULT) "? Tee hee! "
BOX_BREAK
"Quando avrai lo scudo, premi  \n"
COLOR(RED) "START " COLOR(DEFAULT) "per accedere ai SubMenu'.  \n"
"Seleziona: " COLOR(BLUE) "Equipaggiamento     \n"
COLOR(DEFAULT) "con " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " o " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". "
BOX_BREAK
"Dal " COLOR(BLUE) "Menu' Equipaggiamento" COLOR(DEFAULT) ",  \n"
"scegli l'oggetto che vuoi usare  \n"
"e premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " per indossarlo.  "
BOX_BREAK
"Una volta indossato, alzalo \n"
"premendo " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " e cambia\n"
"l'angolazione con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"Tee hee!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi sapere come utilizzare   \n"
"il " COLOR(YELLOW) "Tasto [C-Up]" COLOR(DEFAULT) "?  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Premendo " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", potrai cambiare\n"
"la visuale.  "
BOX_BREAK
"In un posto come questo, otterrai\n"
"una visuale dall'alto.\n"
"All'esterno, ad esempio in un campo,\n"
"otterrai una visuale in Prima-Persona.    "
BOX_BREAK
"Se appare \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\" in alto sulla \n"
"destra dello schermo, significa \n"
"che la Fatina Navi ti vuole parlare.  \n"
"Usa " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " per ascoltarla!  "
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, allora prova da solo e  \n"
"capirai come funziona... "
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non é la Canzone di Saria...    "
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "e' sconvolto! \n"
"Ma gli e' successo qualcosa?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa? Dove stai andando?!  "
BOX_BREAK
"Al castello? \n"
"E dov'e' il castello?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noi Kokiri moriamo\n"
"se lasciamo la foresta."
BOX_BREAK
"Non mi dire che stai provando a \n"
"lasciare la foresta?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, " NAME "!\n"
"Cosa hai fatto?! "
BOX_BREAK
UNSKIPPABLE "Il Sacro Albero Deku...é\n"
"...é morto?"
BOX_BREAK
UNSKIPPABLE "Come hai potuto fare una cosa \n"
"simile?! E' tutta colpa tua!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ehi!!" QUICKTEXT_DISABLE "\n"
"Cosa stai facendo in casa mia?! "
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", sei salvo!  " TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria e " NAME " saranno  \n"
"amici per sempre"
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' successo qualcosa  al    \n"
"Grande Albero?  "
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Comunque, sembra che l'aria nella\n"
"foresta sia cambiata.  "
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", stai forse \n"
"andando via? "
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se perderai lo scudo, ritornerai\n"
"qui da noi?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x80") "Tutti i giovani Arbusti Deku\n"
"sono d'accordo...\n"
"Sei uguale al nostro sacro Totem!            "
BOX_BREAK
SFX("\x38\x80") "Come nostra offerta, per favore,\n"
"accetta questi " COLOR(RED) "Rami Deku" COLOR(DEFAULT) "!\n"
"Inoltre, da ora potrai\n"
"portarne di piu'!"
BOX_BREAK
"Abracadabra!"
BOX_BREAK
SFX("\x38\x80") "Alakazaaaam!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Da quando il Grande Albero\n"
"é avvizzito...Sono apparsi\n"
"molti mostri nella foresta...    \n"
"Ho paura!  "
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Un vento cattivo soffia da dove \n"
"sorge il Tempio della Foresta..."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Saria" COLOR(DEFAULT) " allora disse,\n"
"\"Devo vedere cosa sta\n"
"succedendo!\"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il " COLOR(ADJUSTABLE) "Tempio della Foresta" COLOR(DEFAULT) " si\n"
"trova nella Sacra Radura, lassu'\n"
"nei Boschi Perduti..            "
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria é andata al tempio e non\n"
"é piu' tornata... "
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ciao, signore! Niente Scudo Deku\n"
"per te! E' roba da bambini!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dov'é Saria?\n"
"Conosci Saria, per caso?     \n"
"E' strano...   " TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dov'é " COLOR(RED) "Mido" COLOR(DEFAULT) " durante una simile  \n"
"emergenza?   "
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vedo. Non hai avuto problemi\n"
"ad entrare nella foresta,   \n"
"signore..."
BOX_BREAK
"Quei mostriciattoli non ti hanno\n"
"infastidito? Prima che il Grande\n"
"Albero morisse, non si vedevano\n"
"cose simili qua in giro...  " TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Siccome é pericoloso stare fuori,\n"
"io sto sempre in casa. Ma mi\n"
"annoio a morte qui dentro!     "
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puoi comprare le " COLOR(RED) "frecce" COLOR(DEFAULT) " al\n"
"negozio solo se hai l'" COLOR(RED) "Arco" COLOR(DEFAULT) ".\n"
"Tu ne hai uno, signore?  "
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hai viaggiato molto in queste \n"
"terre, mister?\n"
"Hai mai incontrato un certo   \n"
NAME "?"
BOX_BREAK
UNSKIPPABLE "Mido ci disse che il Grande\n"
"Albero é morto a causa di quello\n"
"che fece quel ragazzino..."
BOX_BREAK
UNSKIPPABLE "Soltanto Saria difese \n"
NAME ", poi scomparse..." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo capimmo...   "
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ci siamo mai visti prima da \n"
"qualche parte? "
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Scusi, conosce un bambino\n"
"di nome " NAME "?"
BOX_BREAK
UNSKIPPABLE "Ha lasciato la foresta senza\n"
"ritornare.." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi chiedo se " NAME "     \n"
"ritornera'? "
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sarebbe magnifico essere grande\n"
"come te, mister! Vorrei proprio\n"
"essere grande come te!"
BOX_BREAK
UNSKIPPABLE "Vorrei essere grande e forte\n"
"per scacciare i mostri, ma...  " TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noi Kokiri non cresciamo mai per\n"
"tutta la nostra vita...     \n"
"Che fortunaaa!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cos'e quella Fatina che ti sta\n"
"seguendo? Non sei uno di noi!  "
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma chi sei tu? Anche se indossi\n"
"vestiti Kokiri, non mi   \n"
"imbrogli!!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho promesso a Saria che nessuno\n"
"sarebbe passato di qui...  "
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehila'!\n"
"Sono il" COLOR(RED) " Germoglio Deku" COLOR(DEFAULT) "!     "
BOX_BREAK
UNSKIPPABLE "Poiché tu e Saria avete " COLOR(DEFAULT) "spezzato \n"
"la maledizione della Foresta,\n"
"crescero' rigoglioso!  "
BOX_BREAK
UNSKIPPABLE "Grazie molte!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, hai visto i tuoi vecchi amici?\n"
"Nessuno di loro ti ha riconosciuto\n"
"cosi' cresciuto, vero?\n"
"     "
BOX_BREAK
UNSKIPPABLE "Questo perché i " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) " non possono\n"
"crescere! Anche dopo 7 anni,\n"
"restano dei bambini!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti starai chiedendo perché tu\n"
"solo sei cresciuto!"
BOX_BREAK
UNSKIPPABLE "Bene, come forse avrai gia'\n"
"immaginato, tu non sei un Kokiro!  \n"
"In realta' sei un " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Sono felice di rivelarti, infine,\n"
"questo segreto!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Tanto tempo fa, prima che il Re di\n"
"Hyrule unificasse il Regno, c'era\n"
"una feroce guerra nel paese..." BOX_BREAK_DELAYED("\x5A") "Un giorno, fuggendo i fuochi della\n"
"guerra, una" COLOR(RED) " donna Hylian" COLOR(DEFAULT) " e il\n"
"suo" COLOR(RED) " piccolo" COLOR(DEFAULT) " entrarano in questa\n"
"foresta...    " BOX_BREAK_DELAYED("\x5A") "La madre era gravemente ferita...\n"
"La sua unica possibilita' era\n"
"affidare il suo piccolo al " COLOR(RED) "Grande\n"
"Albero Deku" COLOR(DEFAULT) ".                  " BOX_BREAK_DELAYED("\x5A") "Il Grande Albero senti' che quel\n"
"bambino poteva essere il prescelto\n"
"il cui destino avrebbe cambiato il\n"
"mondo, dunque lo tenne con sé." BOX_BREAK_DELAYED("\x5A") "Dopo la morte della madre, il\n"
"piccolo fu cresciuto come " COLOR(ADJUSTABLE) "Kokiro" COLOR(DEFAULT) ".\n"
"E ora, infine, il giorno del\n"
"destino é giunto! " FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tu sei un " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) ", e sei \n"
"destinato a lasciare questa foresta."
BOX_BREAK
UNSKIPPABLE "E ora...\n"
"Conosci il tuo destino...   \n"
"Ora sai...\n"
"Sai quello che devi fare...    "
BOX_BREAK
UNSKIPPABLE "Va bene...\n"
"Devi salvare il Regno di Hyrule!\n"
"      "
BOX_BREAK
UNSKIPPABLE "Ora, " NAME ", spezza la\n"
"maledizione di tutti i Templi,\n"
"e riporta la pace ad Hyrule!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Questa musica?!"
BOX_BREAK
UNSKIPPABLE "Saria la suona tutto il   \n"
"giorno!\n"
"Tu...Tu conosci Saria?  "
BOX_BREAK
UNSKIPPABLE "La musica..."
BOX_BREAK
UNSKIPPABLE "Saria l'ha insegnata soltanto\n"
"ai suoi amici..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Piu' ti guardo... \n"
"Non so perché, ma mi ricordi...    \n"
"Lui..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti ho preso!   \n"
"In questa dimensione tra sogno\n"
"e realta', presto quello che rimarra'\n"
"di te sara' un cadavere!    "
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Grazie...\n"
"Con il tuo aiuto, si é risvegliato\n"
"il Saggio. "
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"Saggio del Tempio della Foresta."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "Saria sara' sempre...  \n"
SHIFT("\x3C") "Tua amica...  " FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Lo scorrere del tempo é crudele... \n"
"Sembra scorrere in modo diverso\n"
"per ciascuno di noi, senza\n"
"fermarsi... "
BOX_BREAK
UNSKIPPABLE "Ma una cosa resta sempre la  \n"
"stessa, la memoria della giovinezza... "
BOX_BREAK
UNSKIPPABLE "Per ritornare qui di nuovo,\n"
"suona il " COLOR(ADJUSTABLE) "Minuetto dei Boschi" COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...\n"
"Ci rivedremo ancora. "
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria non é ritornata?... \n"
"Ma sento che un giorno tornera'...    "
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "OK...\n"
"Mi fido...  " TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...Vedo... "
BOX_BREAK
UNSKIPPABLE "Saria non é voluta tornare..."
BOX_BREAK
UNSKIPPABLE "Ma...Io...Le ho fatto una\n"
"promessa...  "
BOX_BREAK
UNSKIPPABLE "Se " NAME " ritornera'   \n"
"devo dirgli che Saria lo ha    \n"
"sempre aspettato...              "
BOX_BREAK
UNSKIPPABLE "Perché a" TEXT_SPEED("\x03") " Saria...Lui...\n"
"Piaceva..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Ehi, tu. "
BOX_BREAK
"Se lo vedi in qualche posto,\n"
"faglielo sapere... " TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Insegnami l'arte della spada!\n"
"Non ho fatto che premere " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "da\n"
"sempre!  "
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu, sinceramente, mi ricordi      \n"
"qualcuno che ho gia' visto...     "
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei cosi' grosso e forte!     \n"
"Vorrei diventare come te un  \n"
"giorno, anche se restero' sempre\n"
"piccolo."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... Mi chiedo se\n"
"tornera' un giorno. "
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi sembra come se ci conoscessimo\n"
"da tanto tempo!  "
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ora che il " COLOR(RED) "Germoglio Deku" COLOR(DEFAULT) "      \n"
"sta crescendo nella Grande\n"
"Radura, la foresta é            \n"
"ritornata normale! "
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noi collaboreremo per proteggere la foresta!  "
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Di recente un vento fatato si\n"
"é alzato in zona. "
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Grazie al vento magico, sono \n"
"sicuro che " NAME " potra' tornare!     "
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mi chiedo se Saria ritornera'...   "
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sicuramente  \n"
NAME " tornera'!       "
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Grande Albero...  \n"
COLOR(DEFAULT)  SHIFT("\x3E")  COLOR(LIGHTBLUE) "Sono Io! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Questo demonio ha usato senza \n"
"sosta, i suoi maligni poteri alla\n"
"ricerca del Sacro Reame che e'  \n"
"collegato ad Hyrule...   "
BOX_BREAK
UNSKIPPABLE "Poiche' e' proprio nel Sacro  \n"
"Reame che si trova la divina\n"
"reliquia, la " COLOR(LIGHTBLUE) "TriForza" COLOR(DEFAULT) ", che contiene \n"
"l'essenza degli antichi Dei."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Prima del Tempo, prima dello Spirito\n"
SHIFT("\x31") "e della Vita... " QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Tre perfette Divinita' discesero\n"
SHIFT("\x16") "sul caos che era Hyrule...       " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Din, Dea della Forza...     " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Nayru, Dea della Saggezza...   " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Farore, Dea del Coraggio...      " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Con le sue forti e ardenti braccia\n"
SHIFT("\x22") "creo' la Madre Terra...       \n"
SHIFT("\x3A") "              " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Riverso' la sua saggezza sulla terra\n"
SHIFT("\x05") "  e ci fece dono della giustizia...   " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Dalla sua anima, vennero tutte  \n"
SHIFT("\x2A") "le forme di vita...        \n"
SHIFT("\x4B") "        " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x01") "Le tre grandi Divinita', dopo aver\n"
SHIFT("\x01") "creato tutto, ritornarono ai Cieli.        " QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "Un Sacro Triangolo Aureo, rimase li'\n"
SHIFT("\x01") "dove le Dee lasciarono questo mondo...            " QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x01") "Da allora, il Triangolo Sacro é divenuto   \n"
SHIFT("\x01") "   fonte di vita per il nostro mondo.  " QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "E, l'ultima dimora del Sacro Triangolo\n"
SHIFT("\x0F") "   e' adesso il Sacro Reame... " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi piccolo sei stato bravo...\n"
"Sembra che tu stia migliorando  \n"
"le tue abilita'...  " BOX_BREAK_DELAYED("\x3C") "Ma hai sconfitto solo il mio\n"
"fantasma...\n"
"Quando ci incontreremo, non sara'\n"
"cosi' facile!  " BOX_BREAK_DELAYED("\x3C") "Che inutile creazione é stata \n"
"questo spettro! La bandiro'\n"
"nello spazio tra le dimensioni!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho sempre creduto che saresti\n"
"tornato. Perché ti conosco...  "
BOX_BREAK
UNSKIPPABLE "No..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "Non mi devi alcuna   \n"
"spiegazione... "
BOX_BREAK
UNSKIPPABLE "Perché il nostro destino non é\n"
"quello di vivere nello stesso mondo."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Io restero' qui come Saggio\n"
"della Foresta...       "
BOX_BREAK
UNSKIPPABLE "Ora, prendi questo \n"
COLOR(ADJUSTABLE) "Medaglione" COLOR(DEFAULT) "...  "
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hai davvero dimostrato il   \n"
"tuo coraggio..."
BOX_BREAK
UNSKIPPABLE "Sentivo che saresti riuscito a   \n"
"superare questa prova... "
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ora, ho molto da raccontarvi,   \n"
"volete ascoltare...   \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...\n"
"Vai al Castello di Hyrule."
BOX_BREAK
UNSKIPPABLE "Li, di certo, incontrerai la\n"
COLOR(RED) "Principessa del Destino" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Tieni questa " COLOR(RED) "Pietra" COLOR(DEFAULT) ".\n"
"E' per questa pietra, che il nomade\n"
"mi ha stregato, voleva rubarla... " UNSKIPPABLE
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Lo " COLOR(RED)  COLOR(DEFAULT) "sapevo.\n"
"Sapevo che prima o poi saresti....\n"
"Partito, " NAME "..."
BOX_BREAK
UNSKIPPABLE "Perche' tu sei diverso da me e\n"
"da" COLOR(RED) " " COLOR(DEFAULT) "tutti gli altri..."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE) "Ciao, " QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "! \n"
"Sveglia!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il " COLOR(RED) "Grande Albero" COLOR(LIGHTBLUE) " ti      \n"
"vuole parlare! \n"
QUICKTEXT_ENABLE  NAME ", forza! " QUICKTEXT_DISABLE  COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Ehi! " QUICKTEXT_ENABLE "Forza!" QUICKTEXT_DISABLE  COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il destino di Hyrule puo' dipendere  \n"
"da un pigrone?  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saltare é fuori moda ormai. Adesso\n"
"va parecchio fare le " COLOR(RED) "capriole" COLOR(DEFAULT) "!  \n"
SHIFT("\x0B") "Tu ci riesci?  "
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il " COLOR(RED) "Grande Albero" COLOR(LIGHTBLUE) " ci ha convocato!     \n"
"Non perdiamo tempo, andiamo!! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x4B") "Navi...\n"
SHIFT("\x23") "  Navi, dove sei?    \n"
SHIFT("\x39") "Avvicinati...  "
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, " COLOR(LIGHTBLUE) "Fata Navi...  " COLOR(DEFAULT) "   \n"
"Ascolta le parole di un vecchio  \n"
COLOR(RED) "Albero Deku" COLOR(DEFAULT) "...  "
BOX_BREAK
UNSKIPPABLE "Riesci a percepire?\n"
"Percepisci il Male discendere  \n"
"sul nostro Regno? "
BOX_BREAK
UNSKIPPABLE "Persino ora le forze del Male \n"
"si radunano per attaccare   \n"
"Hyrule...   "
BOX_BREAK
UNSKIPPABLE "Per lungo tempo, " COLOR(RED) "la Foresta" COLOR(DEFAULT) ", sacra \n"
"sorgente di vita, e' stata una \n"
"barriera che ha impedito al Male \n"
"di entrare, portando pace al Regno..."
BOX_BREAK
UNSKIPPABLE "Ma....contro questa enorme Forza \n"
"del Male, il mio potere e' \n"
"inutile..."
BOX_BREAK
UNSKIPPABLE "Sembra sia venuto il tempo per \n"
"il " COLOR(RED) "Ragazzo senza Fata " COLOR(DEFAULT) "di iniziare   \n"
"il Viaggio."
BOX_BREAK
UNSKIPPABLE "Il suo destino e' leggenda, egli\n"
"portera' Hyrule verso un   \n"
"futuro di pace.     "
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "...Vai ora! Trovalo e poi\n"
"guidalo sino a me..."
BOX_BREAK
"E' rimasto poco tempo, ormai...        "
BOX_BREAK
UNSKIPPABLE "Vola, Navi, ora! Il destino della\n"
"foresta e del Regno, dipendono\n"
"da Te!   "
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Ti prego perdonami, padrone! Non\n"
"lo faro' mai piu'! Se mi risparmi,  \n"
"ti svelero' un grande segreto."
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Non batterai mai i miei fratelli\n"
"sino a che non li colpirai nel  \n"
"giusto ordine...    "
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "L'ordine e'... " TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) " 2 3 1 " COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Ventitre' é il Numero Uno! " COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
UNSKIPPABLE  SFX("\x38\x80") "Pensi io sia un traditore? " EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Chi ti ha detto il segreto?! \n"
"Che " QUICKTEXT_ENABLE "rabbia!!   " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Uffa, ti dovro' rivelare il     \n"
"segreto della Grande Regina Gohma.\n"
"Allora."
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Per inferire il colpo di grazia  \n"
"alla Regina Gohma, colpiscila\n"
"con la spada " COLOR(RED) "mentre é stordita" COLOR(DEFAULT) ".\n"
"    "
BOX_BREAK
UNSKIPPABLE "Oh, mia Regina."
BOX_BREAK
SFX("\x38\x80")  QUICKTEXT_ENABLE "Mi dispiace!!    " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"Nella lontana foresta di Hyrule...   " BOX_BREAK_DELAYED("\x28")  SHIFT("\x16") " Ho servito a lungo come \n"
SHIFT("\x33") " Spirito Guida... \n"
SHIFT("\x0C") "Sono Deku l'Antico Albero...  " FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "I bambini della foresta, detti,\n"
SHIFT("\x10") "Kokiri, vivono qui con me." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0B") "Ogni Kokiro ha una Fatina\n"
SHIFT("\x2A") "che lo protegge...  " FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") " Ma, c'é un ragazzo che" COLOR(RED) " " COLOR(DEFAULT) "non \n"
SHIFT("\x20") "ha una propria Fatina... " FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Mi arrendo! In cambio, ti vendero'\n"
"delle Noci Deku!\n"
COLOR(RED) "5 pezzi    20 Rupié " COLOR(DEFAULT) " Eccole!! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Va bene! Hai vinto! In cambio,\n"
"ti vendero' un Ramo Deku!   \n"
COLOR(RED) "1 pezzo   15 Rupié  " COLOR(DEFAULT) "Eccolo!  " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Va bene! Hai vinto! Per avermi   \n"
"separato, ti vendero' un      \n"
"Pezzo di Cuore!\n"
COLOR(RED) "1 pezzo   10 Rupié " COLOR(DEFAULT) "ecco!  " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Facciamo l'affare!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No    " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "YIKES!!" QUICKTEXT_DISABLE "\n"
"Me ne vado allora!! "
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Hai poche Rupié!   \n"
"Ritorna ancora! "
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Non lo puoi avere ora!! \n"
"Ritorna ancora! "
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x2D") "Grazie di cuore!    " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti stavo aspettando,\n"
NAME "!  "
BOX_BREAK
UNSKIPPABLE "Sei nella " COLOR(RED) "Sacra Radura della Foresta  " COLOR(DEFAULT) "\n"
"E' " COLOR(RED)  COLOR(DEFAULT) "il mio posto segreto!!     "
BOX_BREAK
UNSKIPPABLE "Sento...Che sara' molto \n"
"importante per noi un giorno... \n"
"Lo sento veramente."
BOX_BREAK
UNSKIPPABLE "Se suoni qui la tua Ocarina,\n"
"potrai parlare con gli spiriti\n"
"della foresta... " TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti va di suonare l'Ocarina \n"
"con me?         \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"Non mi va. " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, prova a seguire la melodia  \n"
"che suonero'...    \n"
"Sei pronto?   "
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Huh?!\n"
"Ufffaaaa!  \n"
"Forza! Suoniamo!! "
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x36") "Grandioso!!  "
BOX_BREAK
UNSKIPPABLE "Ti prego non dimenticarla!  \n"
"Me lo prometti?  " TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sentirai la mia voce, suonando\n"
"la " COLOR(ADJUSTABLE) "Canzone di Saria" COLOR(DEFAULT) ". \n"
"Puoi parlarmi quando vuoi...  "
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti stai prendendo cura\n"
"dell'Ocarina?    "
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x38\x80") "Forte!\n"
"Sei grande!!\n"
"Hai fatto ben tre centri perfetti!    "
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Devo assolutamente premiare\n"
"una persona cosi' in gamba!  \n"
"Prendi questo! " EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido dovrebbe sapere qualcosa di\n"
"Saria...           "
BOX_BREAK
"Penso che Mido sia incavolato in\n"
"una casa qua vicino.     "
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT)  SHIFT("\x15")  COLOR(LIGHTBLUE) "Nessuna risposta. Dorme... " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cojiro? Ma come?\n"
"Di solito solo un bravo ragazzo\n"
"puo' averlo..."
BOX_BREAK
UNSKIPPABLE "Ma allora...  "
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x01") "Tu...De" TEXT_SPEED("\x00") "vi essere buono!       \n"
QUICKTEXT_ENABLE "Devi!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Devi esserlo!" QUICKTEXT_DISABLE "\n"
"Per favore Mr. Bravo Ragazzo."
BOX_BREAK
UNSKIPPABLE "Consegna questa cosa alla " COLOR(RED) "vecchia\n"
"strega al negozio" COLOR(DEFAULT) " del Villaggio\n"
"Kakariko!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Svanira' se ci metterai troppo \n"
"tempo, percio' sbrigati, vai!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Non ora" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, yeah. " QUICKTEXT_ENABLE "E cosi'..." QUICKTEXT_DISABLE "\n"
"Non sei cosi' bravo dopotutto!!  \n"
QUICKTEXT_ENABLE "Lasciami solo!   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria ti vuole vedere...  \n"
"O l'hai gia' incontrata? "
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sbrigati, bello!  \n"
"Prima che scompaia, consegnalo\n"
"alla vecchia arpia...   "
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quel tizio non é piu' qui.  "
BOX_BREAK
UNSKIPPABLE "Chiunque venga nella foresta\n"
"si perdera'...     "
BOX_BREAK
UNSKIPPABLE "Anche tu diverrai uno Stalfos...\n"
"Tutti...Tutti Stalfos\n"
"Cosi' non é piu' qui... \n"
"E' rimasta solo la sua sega.  " TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quella medicina contiene \n"
"funghi della foresta. Dammela! \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh.\n"
"Lo diventerai...Anche tu?  \n"
"Heh heh!"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Qui vendo scudi, ma non spade!  " EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sai la " COLOR(ADJUSTABLE) "Canzone di Saria" COLOR(DEFAULT) "!\n"
"Siamo amici allora! \n"
"Prendi questo! "
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ciao! Pensi che la mia\n"
"faccia sia strana? \n"
"E' solo fuori dal comune...  "
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Proviamo a risuonare!!    "
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prova a seguire la nostra \n"
"canzone con la tua Ocarina,\n"
"ti guidero'..."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E' stata una buona sessione.  \n"
"Come segno di amicizia,\n"
"prendi questa cosa...   "
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, qui sopra!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME "...Ti rivedo con piacere!\n"
"Ascoltami bene!\n"
"Hoot hoot...." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se ti inoltrerai nei Boschi\n"
"Perduti, potrai trovare la\n"
COLOR(ADJUSTABLE) "Sacra Radura della Foresta" COLOR(DEFAULT) "."
BOX_BREAK
"E' un posto sacro e poche persone\n"
"vi hanno messo piede.  "
BOX_BREAK
"Shhhh...Cos'é questo?\n"
"Sento una musica misteriosa..."
BOX_BREAK
"Anche tu dovresti ascoltarla...\n"
"Vai...\n"
"Hoo hoo ho!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi risentire quello che ti ho\n"
"detto?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se sei coraggioso, troverai\n"
"la tua strada nella foresta,   \n"
"ascolta... "
BOX_BREAK
UNSKIPPABLE "Devi solo seguire le tue orecchie\n"
"e ascoltare la voce della foresta!   \n"
"Hoot hoot!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Conosci la canzone per Ocarina\n"
"di Saria? "
BOX_BREAK
UNSKIPPABLE "Quella melodia ha dei poteri  \n"
"misteriosi...    "
BOX_BREAK
UNSKIPPABLE "Ci possono essere altre \n"
"canzoni misteriose che potrai  \n"
"imparare qui ad Hyrule. " TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Userai l'Ocarina premendo " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". \n"
"Dove si puo' suonare una melodia\n"
"apparira' un" COLOR(RED) " rigo musicale" COLOR(DEFAULT) "."
BOX_BREAK
"Cerca di suonare melodie che   \n"
"conosci. "
BOX_BREAK
"Ti suggerisco di suonare anche se\n"
"non appare il rigo musicale.  \n"
"Suona ad esempio\n"
"Hoo hoo hoo hoot hoot hoot!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi risentire quello che \n"
"ho detto?  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Le melodie imparate saranno\n"
"registrate sul " COLOR(LIGHTBLUE) "SottoMenu     \n"
"Status Quest" COLOR(DEFAULT) ". Dovresti memo- \n"
"rizzarle comunque...    "
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ohh...Quel maleducato! Non so perché  \n"
"é cosi' cattivo con tutti!"
BOX_BREAK
UNSKIPPABLE "Anche se cio' che dice é vero." TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono successe strane cose nella \n"
"foresta ultimamente...       "
BOX_BREAK
UNSKIPPABLE "Devi essere pronto a tutto.  \n"
"E' meglio trovare qualche arma! " TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Va bene! Hai vinto! In cambio,\n"
"ti vendero' i " COLOR(RED) "Semi Deku" COLOR(DEFAULT) "!   \n"
COLOR(RED) "30 pezzi    40 Rupié " COLOR(DEFAULT) "eccoli!   " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Mi arrendo! Lasciami andare,\n"
"e ti vendero' uno " COLOR(RED) "Scudo Deku" COLOR(DEFAULT) "! \n"
"Solo " COLOR(RED) "50 Rupié" COLOR(DEFAULT) "! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Basta! Se mi lasci andare,\n"
"ti vendero' delle " COLOR(RED) "Bombe" COLOR(DEFAULT) "! \n"
COLOR(RED) "5 pezzi    40 Rupié " COLOR(DEFAULT) "eccole!   " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Non colpirmi! Lasciami andare e ti\n"
"vendero' delle " COLOR(RED) "Frecce" COLOR(DEFAULT) "! \n"
COLOR(RED) "30 pezzi    70 Rupié " COLOR(DEFAULT) "Eccole!   " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Va bene! Hai vinto! Risparmiami e\n"
"ti vendero' una " COLOR(RED) "Pozione Rossa" COLOR(DEFAULT) "    \n"
"per " COLOR(RED) "40 Rupié" COLOR(DEFAULT) "! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Va bene! Hai vinto! Risparmiami e\n"
"ti vendero' una " COLOR(ADJUSTABLE) "Pozione Verde" COLOR(DEFAULT) "per   \n"
COLOR(RED) "40 Rupié" COLOR(DEFAULT) "! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cosa?! Ora hai una Fata?!  \n"
"Cosa dici? Il Grande Albero  \n"
"ti ha CONVOCATO? A TE?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "COOOOOOSAA?!"
BOX_BREAK
UNSKIPPABLE "E avrebbe convocato te e non il \n"
"Grande " COLOR(RED) "Mido" COLOR(DEFAULT) "? "
BOX_BREAK
UNSKIPPABLE "Non sei divertente..."
BOX_BREAK
UNSKIPPABLE "Non ti credo!\n"
"E non sei nemmeno equipaggiato!!    \n"
"    "
BOX_BREAK
UNSKIPPABLE "Come pensi di poter aiutare il   \n"
"Grande Albero Deku senza almeno \n"
"una " COLOR(ADJUSTABLE) "Spada" COLOR(RED) " " COLOR(DEFAULT) "ed uno " COLOR(LIGHTBLUE) "Scudo" COLOR(RED)  COLOR(DEFAULT) "?      "
BOX_BREAK
"Cosa? Hai ragione, non ho nessun\n"
"equipaggiamento con me ma.." TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x2D") "Ehi cos'é quello?"
BOX_BREAK
UNSKIPPABLE "Oh, hai uno " COLOR(LIGHTBLUE) "Scudo Deku" COLOR(DEFAULT) " ora..."
BOX_BREAK
UNSKIPPABLE "...NON CI CREDO?!"
BOX_BREAK
UNSKIPPABLE "E'... e' la " COLOR(ADJUSTABLE) "Spada Kokiri" COLOR(DEFAULT) "?!"
BOX_BREAK
UNSKIPPABLE "MALEDIZIONE!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bene, anche se hai tutto rimani,\n"
"comunque, un fesso, hruumpf!" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ho perso! Ora ti vendero' un" COLOR(RED) " Ramo\n"
"Deku " COLOR(DEFAULT) "per " COLOR(RED) "15 Rupié" COLOR(DEFAULT) ".  " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ho perso! Ti vendero' le " COLOR(RED) "Noci  \n"
"Deku " COLOR(DEFAULT) "se mi lasci andare... \n"
COLOR(RED) "5 pezzi    20 Rupié  " COLOR(DEFAULT) "eccole..." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Inoltre... "
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x0D") "Mi spiace di averlo maltrattato." QUICKTEXT_DISABLE
BOX_BREAK
SHIFT("\x45") "Digli anche questo."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee heee!\n"
"Ti sei arrampicato sino a qui?\n"
"Sei un vero Kokiro! " TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Guarda! E' un bel panorama?\n"
"Cambia il punto di vista con " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ",\n"
"potrai ammirare l'intera foresta \n"
"con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa hai fatto al\n"
"Grande Albero Deku?  "
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se vuoi andare nei Boschi Perduti,\n"
"sara' meglio equipaggiarsi bene!     \n"
"Hee hee!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x82") "Tutti i giovani Arbusti Deku\n"
"dicono...\n"
"Che hai una faccia orrenda!"
BOX_BREAK
SFX("\x38\x82") "Ma non ti preoccupare!\n"
"Ti regaleremo molte " COLOR(RED) "Noci Deku" COLOR(DEFAULT) ".  "
BOX_BREAK
SFX("\x38\x82") "Naturalmente, ti consentiremo di\n"
"portarne anche di piu'!  "
BOX_BREAK
"Abracadabra..."
BOX_BREAK
SFX("\x38\x80") "Alakazaaaam!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Mi arrendo! "
BOX_BREAK
SFX("\x38\x80") "Per renderti la vita facile,\n"
"ti potro' far portare piu'    \n"
COLOR(RED) "Rami Deku" COLOR(DEFAULT) "!  \n"
"Ma, ti costera' ben " COLOR(RED) "40 Rupié" COLOR(DEFAULT) "! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Mi arrendo! "
BOX_BREAK
SFX("\x38\x80") "Per renderti la vita piu' facile,\n"
"ti posso far portare piu'\n"
COLOR(RED) "Noci Deku" COLOR(DEFAULT) "!\n"
"Ma, ti costera' ben " COLOR(RED) "40 Rupié" COLOR(DEFAULT) "! " TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Mi spiace!\n"
"Non lo puoi ancora comprare!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quel tizio non é piu' qui..."
BOX_BREAK
"Chiunque venga nella     \n"
"foresta si perdera'..."
BOX_BREAK
"Tutti diventeranno degli Stalfos.\n"
"...Tutti Stalfos...\n"
"Cosi' non é piu' qui.    "
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie tante per l'altro  \n"
"giorno...Non ti ho nemmeno\n"
"chiesto come ti chiami...    "
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Davvero?\n"
NAME "!"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Proprio come pensavo!" QUICKTEXT_DISABLE "\n"
"Sei il ragazzo fatato della \n"
"foresta! E' stato tanti anni fa!\n"
"Ti ricordi di me?"
BOX_BREAK
UNSKIPPABLE "Si? Ero sicura fossi tu\n"
"perché Epona ti ha riconosciuto! "
BOX_BREAK
UNSKIPPABLE "Oh, devo dirti di           \n"
COLOR(RED) "Mr. Ingo" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Era terrorrizato che il Re del Male\n"
"potesse scoprire che Epona\n"
"era stata portata via...    \n"
"         "
BOX_BREAK
UNSKIPPABLE "Ma un giorno, d'improvviso, é\n"
"ritornato ad essere normale,\n"
"un " COLOR(RED) "brav'uomo" COLOR(DEFAULT) "!  "
BOX_BREAK
UNSKIPPABLE "Ora mio padre é ritornato...\n"
"Non posso crederci, ma la pace\n"
"é ritornata al ranch!    "
BOX_BREAK
UNSKIPPABLE "Tutto grazie a te! Sono in\n"
"debito con te!  "
BOX_BREAK
UNSKIPPABLE "Grazie! Grazie molte,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Come sta " COLOR(RED) "Epona" COLOR(DEFAULT) "?    "
BOX_BREAK
"Se suoni la " COLOR(RED) "sua Canzone " COLOR(DEFAULT) "con la\n"
"tua Ocarina, sicuramente ti \n"
"raggiunge..."
BOX_BREAK
"Ti prego torna pure al ranch \n"
"quando vuoi per " COLOR(RED) "allenare   \n"
COLOR(DEFAULT) "Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "sembra in forma!\n"
"Sei stato in grado di  \n"
"domarla, allora! " TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Provami se sei un buon cavaliere\n"
"in una " COLOR(RED) "Corsa ad Ostacoli" COLOR(DEFAULT) "!   "
BOX_BREAK
"Il tempo sara' per" COLOR(RED) " due giri" COLOR(DEFAULT) ".\n"
"E' una bella sfida. Se manchi \n"
"un cancello nel giusto      \n"
"ordine, hai perso la gara."
BOX_BREAK
"Che ne pensi?\n"
"Vuoi provare?       \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Andiamo \n"
"Non lo fare" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il tuo tempo é stato " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ".\n"
"Allenati duramente!     "
BOX_BREAK
"Ricorda, non serve accellerare\n"
"per saltare i cancelli    \n"
"bassi, ma serve farlo per    \n"
"quelli che sono piu' alti!   "
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME "...Puoi sentirmi?  \n"
"Sono io, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Moooooooooo!"
BOX_BREAK
"Che bella musica...\n"
"Mi ricorda tanto il foraggio..."
BOX_BREAK
"Mi fa sentire cosi' bene, che riesco\n"
"a produrre molto latte! " EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prendi pure un po' del mio latte,\n"
"é nutriente!  " EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME ", quando avrai\n"
"questa Ocarina nelle mani... " BOX_BREAK_DELAYED("\x3C") "Non potevo restare oltre... " BOX_BREAK_DELAYED("\x3C") "Volevo aspettarti, ma non mi \n"
"rimaneva molto tempo...       " BOX_BREAK_DELAYED("\x3C") "Potevo solo lasciarti la mia\n"
"Ocarina e " COLOR(LIGHTBLUE) "questa melodia" COLOR(DEFAULT) "...  " FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ora, " NAME ".\n"
"Suonala dinanzi all'altare che si\n"
"trova nel Tempio del Tempo.\n"
"Devi proteggere la TriForza!  "
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha-hah! Pensi di es- \n"
"sere in incognito, Mr. Eroe? "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x57") "Oh?"
BOX_BREAK
UNSKIPPABLE "Ma é...la \"Kee...qualcosa...\" \n"
"é di quel personaggio..? Beh,\n"
"é molto popolare vero?"
BOX_BREAK
UNSKIPPABLE "E' il preferito di mio figlio,\n"
"é la maschera che vorrebbe...\n"
"Se non ti serve.." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Me la venderesti?      \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No mai" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non rinuncio! Ho un sacco di   \n"
"pazienza. Ce ne vuole col mio\n"
"lavoro! Hah hah hah!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mmmm...Mumble...Mumble...\n"
"Huh? Si,sono sveglio!"
BOX_BREAK
UNSKIPPABLE "Cosa?"
BOX_BREAK
UNSKIPPABLE "Ehi, sei tu! Benvenuto!"
BOX_BREAK
UNSKIPPABLE "Awww... E' stata dura! \n"
"Malon mi ha rimproverato a \n"
"lungo! "
BOX_BREAK
UNSKIPPABLE "Ti sei preso cura di noi, sono\n"
"felice di darti del " COLOR(RED) "latte" COLOR(DEFAULT) "! \n"
"Tieni pure la bottiglia, é tua.      "
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La " COLOR(RED) "strada é chiusa" COLOR(DEFAULT) "\n"
"dopo questo punto!\n"
"Non hai letto il cartello?!  \n"
"      "
BOX_BREAK
"Eh? Oh, vedo. Sei solo\n"
"un monello, e non sai leggere.     \n"
"Ha ha hah!"
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non lo voglio!    "
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, ma e'...\n"
"Questa e' la calligrafia della \n"
"Principessa Zelda! Bene, vediamo...\n"
"Hmmm...OK..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x06") "\"" COLOR(PURPLE) "Questo é " NAME "..\n"
COLOR(DEFAULT)  SHIFT("\x0F")  COLOR(PURPLE) "E' ai miei ordini\n"
"  per salvare" COLOR(DEFAULT)  COLOR(PURPLE) " Hyrule." COLOR(DEFAULT) "\""
BOX_BREAK
UNSKIPPABLE "Wah ha ha ha hah!\n"
"Ma che razza di gioco sta giocando\n"
"la nostra Principessa?! "
BOX_BREAK
UNSKIPPABLE "OK, OK, va bene. Puoi andare   \n"
"ora...Ma attento, Mister \"Eroe\"! \n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Mr. Eroe!\n"
"Grazie per il tuo duro lavoro!\n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "!!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Grande!\n"
"Un tempo di " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) "!\n"
"Tu ed Epona fate un'ottimo\n"
"team!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, che peccato.  .\n"
"Se hai qualcosa per mettercelo, te\n"
"ne posso dare un po'...    " EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono " COLOR(RED) "Ingo" COLOR(DEFAULT) "--Mr. Ingo per te.\n"
"Mi occupo di questi cavalli.\n"
"Mi sei d'impiccio, fila    \n"
"via!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "In ogni caso, eroe...  "
BOX_BREAK
UNSKIPPABLE "Se vai a scalare la Montagna \n"
"della Morte, ti conviene\n"
"avere lo " COLOR(LIGHTBLUE) "Scudo giusto" COLOR(DEFAULT) "! C'e'\n"
"un vulcano attivo dopotutto!"
BOX_BREAK
UNSKIPPABLE "Se ritorni al Castello di Hyrule,\n"
"dai un occhiata al bazaar della\n"
"citta', li' ti venderanno lo\n"
"scudo che ti serve."
BOX_BREAK
UNSKIPPABLE "Digli che ti ho mandato io e\n"
"ti faranno uno sconto speciale!\n"
"    "
BOX_BREAK
UNSKIPPABLE "Se invece sei ben equipaggiato\n"
"puoi pure andare sicuro...    "
BOX_BREAK
UNSKIPPABLE "Ora, ti vorrei chiedere un favore.\n"
"No, non mi aspetto che tu me lo\n"
"faccia in cambio del consiglio che\n"
"ti ho dato! Sto solo chiedendo!"
BOX_BREAK
UNSKIPPABLE "Sei mai stato al " COLOR(RED) "negozio\n"
"di maschere" COLOR(DEFAULT) ", che ha aperto da\n"
"poco al mercato della citta'?   \n"
"Ne parlano tutti!!           "
BOX_BREAK
UNSKIPPABLE "Mio figlio mi tormenta per una\n"
"maschera popolare, ma non ho\n"
"tempo di andarci...  "
BOX_BREAK
UNSKIPPABLE "Percio', potresti gentilmente\n"
"prendere una maschera per me al \n"
"negozio? Se non te la senti, beh,\n"
"va bene lo stesso..."
BOX_BREAK
UNSKIPPABLE "Non ho...Scelta,    \n"
"questo é il mio lavoro."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x4B") "...Sigh..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vorrei trovare al negozio di" COLOR(RED) " maschere" COLOR(DEFAULT) " \n"
"qualcosa da regalare a mio figlio."
BOX_BREAK
SHIFT("\x4B") "...Sigh..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Oh no... Non sta respirando..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x29") "Arrrrgh!" QUICKTEXT_DISABLE " L'ho persa!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x32") "Ehi, tu laggiu'! \n"
SHIFT("\x3C")  QUICKTEXT_ENABLE "Ragazzino! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1C") "Vuoi farmi a pezzi?!    \n"
SHIFT("\x3E") "Divertente!\n"
SHIFT("\x1C") "Hai un bel coraggio!!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2B") "Sei proprio patetico!" QUICKTEXT_DISABLE "\n"
SHIFT("\x14") "Ti rendi conto con chi stai\n"
SHIFT("\x39") "parlando?!   "
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x26") "Sono " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x0A") "E presto, dominero' il mondo!   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0D") "Devi aver visto il cavallo  \n"
SHIFT("\x12") "bianco scappare poc'anzi...  \n"
SHIFT("\x1E") "Che via hanno preso?!\n"
SHIFT("\x3D")  QUICKTEXT_ENABLE "Rispondimi!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tsk tsk...Quando verra' il \n"
"tempo, ti caccero' via di qui."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il mio ragazzo sara' cosi' felice!\n"
"Sei davvero un Mr. Eroe!   \n"
"Wha ha ha hah!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Vendi una maschera da 10 Rupié a\n"
COLOR(RED) "15 Rupié" COLOR(DEFAULT) ". Ci hai guadagnato qualcosa."
BOX_BREAK
UNSKIPPABLE "Quando torni al negozio di maschere \n"
"dovrai restituire le " COLOR(RED) "10 Rupié" COLOR(DEFAULT) ". " EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ai piccoli é vietato\n"
"l'\"" COLOR(RED) "Emozionante tour degli \n"
"scava tombe" COLOR(DEFAULT) "\" indicato nel cartello.   "
BOX_BREAK
"Per questo mi limito, ad imitare\n"
"Dampé il custode del cimitero\n"
"di giorno. "
BOX_BREAK
"Ma con la mia facciuzza, non  \n"
"c'é il batticuore vero?     "
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gyaah!" QUICKTEXT_DISABLE " Sei Dampé      \n"
"il custode!!"
BOX_BREAK
SHIFT("\x57") "???"
BOX_BREAK
"Oh, é solo una maschera. Mi ha\n"
"fatto una paura diversa rispetto a\n"
"quando vedo Dampé, il custode."
BOX_BREAK
"Mi darai quella maschera?    \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No mai" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho davvero dei soldi, sai...?   \n"
"     "
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi! Tempo scaduto, bello!\n"
"Hai pagato solo 10 Rupié!\n"
"Ti sei divertito abbastanza!    " EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Con questa maschera, saro'   \n"
"come Dampé! \n"
"Ecco i soldi!   "
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Hai venduto una maschera da 30\n"
"Rupié ad un bambino?\n"
"A prezzo pieno! E ha pagato subito!"
BOX_BREAK
UNSKIPPABLE "Quando torni al negozio di maschere\n"
"dovrai pagare " COLOR(RED) "30 Rupié" COLOR(DEFAULT) ".\n"
"Potrai anche prendere il nuovo\n"
"modello. "
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vado a scavare e scavare!\n"
"Come Dampé!!   "
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nei tempi antichi, c'erano molti \n"
"conigli selvaggi nelle nostre\n"
"terre. Oggi, a causa della caccia\n"
"eccessiva, sono molti di meno."
BOX_BREAK
"Vorrei essere un coniglio...\n"
"Ascoltare il vento con\n"
"le sue orecchie, balzare in giro\n"
"con le sue zampe... "
BOX_BREAK
"Anche se é solo un sogno..."
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Scommetto che con le orecchie\n"
"lunghe sentirei le voci. \n"
"Oh, ma sono proprio le orecchie\n"
"di coniglio della leggenda! " TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non importa quanto costano!      \n"
"Ti prego vendimele!  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No mai" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non é la risposta che\n"
"volevo sentire!   "
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il mio sogno piu' grande! Tornare\n"
"alla vita selvaggia! Il sogno e   \n"
"la realta' sono state riunite!! " EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "E' una maschera da 50 Rupié, ma\n"
"ti ha dato un somma di denaro\n"
"enorme. Non riesci nemmeno a \n"
"contarlo."
BOX_BREAK
UNSKIPPABLE "Il bello é che dovrai pagare solo\n"
COLOR(RED) "50 Rupié" COLOR(DEFAULT) " al negozio di maschere!  "
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0E") "E cosi', pensi di poterle\n"
SHIFT("\x0F") "proteggere da me...\n"
SHIFT("\x0E") "Hai del fegato, bimbo"
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "C'é della gente a Kakariko, che \n"
"dice in giro che io ho rubato   \n"
"il ranch a Talon, ma... "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x2D") "Mi faccia il" QUICKTEXT_ENABLE " piacere!!    " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Quel Talon era un debole!\n"
"Io " COLOR(RED) "Ingo" COLOR(DEFAULT) ", il super-lavoratore ho\n"
"lavorato con tutte le mie forze!"
BOX_BREAK
UNSKIPPABLE "Non permetto a uno straniero come\n"
"te di dire tali bugie!!"
BOX_BREAK
UNSKIPPABLE "La verita' é che il " COLOR(RED) "Grande Ganondorf" COLOR(DEFAULT) ",\n"
"ha riconosciuto il mio talento\n"
"e mi ha dato il ranch!"
BOX_BREAK
UNSKIPPABLE "Io crescero' un buon cavallo\n"
"e saro' premiato dal grande     \n"
"Ganondorf!"
BOX_BREAK
UNSKIPPABLE "Di', giovanotto, vuoi   \n"
"cavalcare uno dei miei cavalli?  " TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dammi " COLOR(RED) "10 Rupié" COLOR(DEFAULT) ", potrai\n"
"cavalcare.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Cavalca\n"
"Non farlo" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Allora piccolo verme,  \n"
"vattene via!! "
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non hai i soldi! Barbone!\n"
"Risparmiane un po'\n"
"e torna ancora! "
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi sapere come si cavalca?    \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ascolta\n"
"Non sentire" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Avvicinati con calma al cavallo\n"
"stagli di fianco.\n"
"Premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " per montarlo. "
BOX_BREAK
"Premi " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "per farlo correre.\n"
"Quando inizia a correre, premi\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " per colpirlo sul fianco.\n"
"Correra' di piu'!"
BOX_BREAK
"Se vuoi saltare una cancellata,\n"
"accellera e colpiscilo!! \n"
"        "
BOX_BREAK
"Se provi a saltare un ostacolo\n"
"ad un angolo, che non piace al\n"
"cavallo, non saltera'!     "
BOX_BREAK
"Quando il cavallo si fermera'\n"
"totalmente, premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " per\n"
"smontare. Ora, divertiti!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se usi lo " COLOR(LIGHTBLUE) "[Z] Attivato" COLOR(DEFAULT) ", puoi parlarmi\n"
"anche se sei a cavallo."
BOX_BREAK
"Sei pronto a tornare a casa \n"
"ora? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No, voglio cavalcare \n"
"Si, ho fatto" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando vuoi smontare, fermati   \n"
"e premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".  "
BOX_BREAK
"Ehi giovane!  \n"
"Ti conosco? Ho la sensazione  \n"
"di averti gia' visto prima...\n"
"          " TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stai migliorando! \n"
"che ne pensi di una piccola corsa?\n"
"Facciamo il giro del ranch con\n"
"quel cavallo?"
BOX_BREAK
"Una piccola scommessa, diciamo\n"
COLOR(RED) "50 Rupié" COLOR(DEFAULT) "? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Va bene\n"
"Non mi va" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahi Ahi... Qual'é il problema?\n"
"Non hai nemmeno 50 Rupié?!   \n"
"Non corro con un simile poveraccio!\n"
"       "
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x39") "Noo" QUICKTEXT_ENABLE "ooooooo!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Se il Grande Ganondorf sapesse\n"
"di questa umiliazione...   \n"
"Ehi, tu!! Che dici corriamo di\n"
"nuovo! Se vinci... "
BOX_BREAK
UNSKIPPABLE "Puoi tenerti...Il cavallo!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Cosa é successo a quel cavallo?\n"
"Ma é" COLOR(RED) " Epona" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Come hai domato quel selvaggio\n"
"sotto il mio naso?!   "
BOX_BREAK
UNSKIPPABLE "Volevo donare quel cavallo       \n"
"al Grande Ganondorf... Ma ho puntato\n"
"sulla corsa e ho perso! Nooooo!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x36") "Hah ha hah!"
BOX_BREAK
UNSKIPPABLE "Come promesso, ti daro' il   \n"
"cavallo...     "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x0A") "Comunque..."
BOX_BREAK
UNSKIPPABLE "Non ti faro' mai lasciare il ranch!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee... Peccato per te!\n"
"Mi prendo le 50 Rupié." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah ha hah!\n"
"Sei solo un ragazzo, dopotutto!\n"
"Bene, torna quando vuoi e ci \n"
"divertiremo ancora...   "
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cosa? Cosa stai bighellonando\n"
"qui in giro?     \n"
"Tu demonietto!!   "
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(RED) "Ingo " COLOR(DEFAULT) "e bado al ranch.     "
BOX_BREAK
UNSKIPPABLE "Lavoro qui, ormai da molti anni,\n"
"per quel lazzarone di Talon. \n"
"           "
BOX_BREAK
UNSKIPPABLE "Oggi, per esempio, e' andato \n"
"al castello per una consegna e\n"
"ancora non si vede!!  "
BOX_BREAK
UNSKIPPABLE "Ed io, intanto porto avanti\n"
"il lavoro.\n"
" " TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eh si...E' dura essere un\n"
"vero stalliere."
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, i tuoi vestiti!\n"
"Sono...Diversi...    \n"
"Non sei di queste parti, vero?\n"
"       "
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........." TEXT_SPEED("\x00") "........"
BOX_BREAK
UNSKIPPABLE "Ohh... Sei un elfo, un elfo della\n"
"foresta! Mi chiamo " COLOR(RED) "Malon" COLOR(DEFAULT) "!\n"
"Mio padre possiede un Ranch." TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Papa' e' andato al castello per\n"
"vendere il latte, ma non é piu'\n"
"ritornato.."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Stai andando al castello, elfo? \n"
"Mi aiuteresti a ritrovare mio " COLOR(RED) "Padre" COLOR(DEFAULT) "? "
BOX_BREAK
UNSKIPPABLE  SFX("\x68\x6D") "Deve essersi addormentato \n"
"da qualche parte al castello. \n"
"Che roba eh? Da un adulto poi!  \n"
"Tee hee!"
BOX_BREAK
UNSKIPPABLE "Ah si, se mi aiuti a cercarlo,\n"
"ti daro' questo uovo...  "
BOX_BREAK
UNSKIPPABLE "L'ho incubato con molta  \n"
"attenzione...        \n"
"Tee hee!" EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Assegna l'uovo a " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " per incubarlo.\n"
"Hee hee!"
BOX_BREAK
"Mio padre e' proprio un     \n"
"pasticcione, vero?!     \n"
"Hee hee!"
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non posso crederci, io il grande \n"
COLOR(RED) "Ingo" COLOR(DEFAULT) ", lavoro in questo schifo di\n"
"ranch!  "
BOX_BREAK
UNSKIPPABLE "Il proprietario é cosi' pigro, \n"
"che tocca sempre a me il lavoro\n"
"qui intorno!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Io, l'unico, vero lavoratore,\n"
"sono a carico di quel\n"
"lazzarone di Talon!       "
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, di nuovo l'elfo dei boschi!"
BOX_BREAK
"Alla fine hai trovato papa'!\n"
"Ti é piaciuto il castello? \n"
"Hai visto la Principessa?..Hee hee!"
BOX_BREAK
UNSKIPPABLE  SFX("\x68\x6D") "Papa' é tornato a casa di corsa\n"
"appena si é svegliato!"
BOX_BREAK
UNSKIPPABLE "Ah gia', devo presentarti il mio\n"
"grande amico!           "
BOX_BREAK
UNSKIPPABLE "E' il mio pony. Si chiama    \n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". Non é bellino? "
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sembra che Epona abbia paura di\n"
"te, elfo fatato... "
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mia madre cantava questa canzone\n"
"Ti piace? Dai cantiamola insieme.  "
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Epona, si é affezionata  \n"
"a te adesso!     "
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "..."
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...Uno straniero!\n"
"E' da tanto tempo che non \n"
"abbiamo visite qui...   \n"
"Da dove vieni?      "
BOX_BREAK
"Dall'arrivo di Ganondorf, la gente\n"
"della Citta' di Castello é scappata,\n"
"tutto é in rovina, e i mostri\n"
"scorrazzano ovunque.    "
BOX_BREAK
"Mr. Ingo usa il ranch per guadagnarsi\n"
"i favori di Ganondorf.."
BOX_BREAK
"Sembrano tutti dalla parte del male."
BOX_BREAK
"E papa'... \n"
"E' stato cacciato via da     \n"
"da Mr. Ingo..."
BOX_BREAK
"Se io non faccio quello che dice,\n"
"maltratta i cavalli...   "
BOX_BREAK
"Cosi'...\n"
"Non posso fare niente..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Penso nessuno sia veloce quanto\n"
"me ora! Ma, non so se essere  \n"
"triste o felice adesso...."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "...\n"
"B-basta con la musica...Io,\n"
"Mumble... mumble..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Guarda bene quella montagna,\n"
"é la " COLOR(RED) "Montagna della Morte" COLOR(DEFAULT) ",\n"
"rifugio dei Gorons. Loro hanno\n"
"la Pietra Spirituale del Fuoco."
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Per favore non dire a Mr. Ingo\n"
"che ho suonato questa canzone."
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu...\n"
"Conosci la " COLOR(RED) "canzone della mamma" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Questa canzone piace a tutti...\n"
"A papa'...anche a Mr. Ingo..."
BOX_BREAK
UNSKIPPABLE "Ma...Da quando c'é Ganondorf, \n"
"Mr. Ingo é totalmente cambiato. "
BOX_BREAK
UNSKIPPABLE "Ricordo i bei vecchi giorni,\n"
"solo cantando quella melodia...  Anche ad "
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Epona" COLOR(DEFAULT) " piace molto quella musica.\n"
"Solo io so trattare Epona...  \n"
"Mr. Ingo non gli tiene testa... "
BOX_BREAK
"Hee hee hee!"
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Questo strano disegno sulla\n"
"roccia ti colpisce...     "
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Rispondendo alla maschera, la \n"
"strana statua di pietra ti  \n"
"parla..."
BOX_BREAK
"Per caso sentii... "
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cambiero' totalmente vita e\n"
"lavorero' duramente da oggi in poi."
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mr. Ingo... E' stato tentato  \n"
"dalle forze del Male.  \n"
"Non é veramente una cattiva\n"
"persona... "
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z Z Z Z...\n"
"Mumble... Non é facile essere\n"
"un lavoratore..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' un po' di tempo..\n"
"Vuoi fare una corsa?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se cambi idea, torna pure\n"
"quando vuoi!     "
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va bene allora! Fila,\n"
"via verme!      " EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh... Hai rosicato per la \n"
"sconfitta? Se sei cosi' nero,\n"
"che ne pensi di rifarla? "
BOX_BREAK
COLOR(RED) "50 Rupié" COLOR(DEFAULT) " vuoi correre ancora?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Corri\n"
"Non farlo" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie mille. Heh heh heh!!" EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se ti faccio ancora credito,     \n"
"Ingo mi sgridera' molto. Percio'\n"
"é meglio che paghi il     \n"
"prezzo normale."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi del latte per " COLOR(RED) "30 Rupié" COLOR(DEFAULT) "? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ciao, come stai oggi? \n"
"Sono Ingo. Mi sento onorato \n"
"di poter lavorare qui.     "
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Bravo ragazzo...\n"
"Dobbiamo proteggere le belle\n"
"terre di Hyrule! "
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Che bella ocarina!\n"
"Suonerai questa canzone con la\n"
"tua ocarina?      "
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ai piedi della Montagna trove-\n"
"rai il mio villaggio, " COLOR(RED) "Kakariko" COLOR(DEFAULT) ".   \n"
"E' il luogo dove sono nata.  \n"
" "
BOX_BREAK
UNSKIPPABLE "Ti conviene parlare agli abitanti\n"
"del villaggio prima di salire\n"
"sulla Montagna...    "
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La canzone della ninnananna ha\n"
"poteri misteriosi. Solo ai\n"
"Membri della Famiglia Reale é  \n"
"permesso impararla... "
BOX_BREAK
UNSKIPPABLE "Ricorda, ti servira' a dimostrare\n"
"i tuoi legami con la\n"
"Famiglia Reale. "
BOX_BREAK
UNSKIPPABLE "La Principessa aspetta il tuo ritorno\n"
"al castello con le pietre. \n"
"Vai ora...        \n"
"Noi contiamo su di te!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hoo hoot!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Ehi quassu'! " BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Sembra che alla fine sia   \n"
"venuto il tempo di iniziare la \n"
"tua avventura!  "
BOX_BREAK
UNSKIPPABLE "Incontrerai molte avversita' piu'\n"
"avanti...Ma é il tuo destino.\n"
"Non ti scoraggiare, anche nei\n"
"momenti piu' duri!      " TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Piu' avanti sulla strada c'é il \n"
COLOR(RED) "Castello di Hyrule" COLOR(DEFAULT) "."
BOX_BREAK
"Incontrerai una " COLOR(RED) "Principessa" COLOR(DEFAULT) " li'.."
BOX_BREAK
"Se ti perdi e non sai quale via\n"
"prendere, controlla sulla " COLOR(RED) "Mappa" COLOR(DEFAULT) ".  "
BOX_BREAK
"Le aree che hai gia' esplorato ti\n"
"saranno mostrate. Premi " COLOR(RED) "START" COLOR(DEFAULT) "    \n"
"e accederai ai SottoMenu \n"
"e " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " o " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " fino alla Mappa. "
BOX_BREAK
"Sul " COLOR(RED) "SottoMenu Mappa" COLOR(DEFAULT) ", vedrai  \n"
"anche un " COLOR(RED) "Punto lampeggiante" COLOR(DEFAULT) " che \n"
"ti mostra dove dover andare dopo." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hai compreso tutto?  \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No\n"
"Si " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Benissimo, ci rivediamo allora!     \n"
"Hoot hoot hoot ho!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, " NAME "! Di qua!  " BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "La principessa e' nel castello di\n"
"fronte. Ma attento a non farti  \n"
"prendere dalle guardie! \n"
"Ho ho ho hoot!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Qui il tempo scorre \n"
"normalmente...  "
BOX_BREAK
"Ma il tempo resta fermo quando \n"
"sei al Lon Lon Ranch o in citta'. "
BOX_BREAK
"Se vuoi far passare il tempo, devi\n"
"lasciare la citta'.       "
BOX_BREAK
"Bene, bene, e ora che via     \n"
"prenderai?      \n"
"Hoo hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi risentire quello che ho    \n"
"detto?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si\n"
"No" COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoot. Sei sveglio ragazzo.\n"
"In bocca al lupo. Hoooot."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, " NAME "! \n"
"Aspetta un attimo!!   "
BOX_BREAK
"Piu' avanti potrai trovare il\n"
COLOR(RED) "Villaggio Kakariko" COLOR(DEFAULT) ". Hai visto la \n"
"Principessa di Hyrule? No??     \n"
"Ti conviene andare al castello." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, " NAME "! \n"
"Guarda qui su'!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE " Dopo il sentiero troverai il\n"
COLOR(RED) "Villaggio Kakariko" COLOR(DEFAULT) ". Stai attento! \n"
"Hoot hoo!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", sei il solo che\n"
"puo' completare l'avventura.\n"
"Attento!\n"
"Fai del tuo meglio! Ho Hoo!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "! Aspettami, ehi!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28") "A sud di qui raggiungerai il \n"
COLOR(RED) "Lago Hylia " COLOR(DEFAULT) "dalle acque limpide."
BOX_BREAK
"Se vai a ovest, troverai la\n"
COLOR(RED) "Valle dei Gerudo" COLOR(DEFAULT) ".\n"
"E' il rifugio di una banda di ladri\n"
"che stanno sull'altro versante.  "
BOX_BREAK
"Bene, sei libero di scegliere ma,\n"
"attento!\n"
"Ho ho ho...hooo!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non cercare di essere migliore\n"
"conviciti di esserlo. Ho Ho Hoo! "
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Per di qua troverai il Lago Hylia.\n"
"E' ricco di acque cristalline. " BOX_BREAK_DELAYED("\x28") "Gli " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", che vivono nei \n"
"fondali, sorvegliano il Tempio \n"
"Sommerso in fondo al lago, e,  \n"
"anche la loro Fontana.   "
BOX_BREAK
"Se vuoi confermare la sua posizione \n"
"sulla mappa, premi " COLOR(RED) "START " COLOR(DEFAULT) "e  \n"
"accederai ai SottoMenu poi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "    \n"
"o " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " fino alla Mappa."
BOX_BREAK
"Tutti i posti gia' visitati ti  \n"
"saranno mostrati. Ho Hoo hoot!         " EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, attenzione e vai! "
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Come ti chiami?   " EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Strano...Mi sembra sia...\n"
"Sia, familiare." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Va bene, " NAME "..."
BOX_BREAK
UNSKIPPABLE "Ti diro' il segreto che e' stato \n"
"tramandato di generazione in\n"
"generazione dalla Famiglia Reale. \n"
"Riguarda..." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x26") "L'Ocarina del Tempo!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hai capito bene l'intera storia  \n"
"che ti ho detto?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Stavo spiando dalla finestra  \n"
"poco fa...   "
BOX_BREAK
UNSKIPPABLE "L'altro elemento del mio \n"
"sogno...Le " COLOR(BLUE) "Nere Nuvole" COLOR(DEFAULT) "... \n"
"Penso simbolizzassero...\n"
"quell'uomo li' dentro!"
BOX_BREAK
"Vuoi guardare anche tu\n"
"dalla finestra? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Si.."
BOX_BREAK
UNSKIPPABLE "Ho detto a mio padre dei sogni... "
BOX_BREAK
UNSKIPPABLE "Ma, non ha creduto fosse\n"
"una vera profezia...  "
BOX_BREAK
UNSKIPPABLE "Percepisco il male provenire  \n"
"da quell'uomo!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quello che Ganondorf vuole non é\n"
"nient'altro che la " COLOR(RED) "Triforza" COLOR(DEFAULT) ", \n"
"del Sacro Reame.      "
BOX_BREAK
UNSKIPPABLE "E' venuto qui ad Hyrule\n"
"per ottenerla!   "
BOX_BREAK
UNSKIPPABLE "Con essa conquistera' Hyrule...\n"
"Anzi, il mondo intero!  " EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...Ora, solo noi \n"
"possiamo proteggere Hyrule!        " EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ganondorf non deve\n"
"ottenere la Triforza!   "
BOX_BREAK
UNSKIPPABLE "Proteggero' l'" COLOR(LIGHTBLUE) "Ocarina del Tempo   \n"
COLOR(DEFAULT) "con tutto il mio potere!\n"
"Non l'avra' mai!"
BOX_BREAK
UNSKIPPABLE "Vai e trova le altre\n"
COLOR(RED) "due Pietre Spirituali" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Prendiamo la Triforza prima\n"
"di Ganondorf e lo potremo\n"
"sconfiggere! " EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Un ultima cosa...\n"
"Questa " COLOR(RED) "lettera" COLOR(DEFAULT) "...  \n"
"Sono sicura che ti sara' utile...  " EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mumble...Mumble...\n"
"Huh? Sono gia' sveglio!"
BOX_BREAK
UNSKIPPABLE "Cosa?"
BOX_BREAK
UNSKIPPABLE "Che io sia dannato, se non sei quel\n"
"ragazzo della foresta!\n"
"Comunque, ti ringrazio per\n"
"avermi svegliato!"
BOX_BREAK
UNSKIPPABLE "C'é voluto del tempo, ma alla fine\n"
"Malon é tornata di buon umore."
BOX_BREAK
UNSKIPPABLE "Allora, cosa ti ha portato qui?\n"
"Hai forse del tempo libero?            \n"
"Che ne pensi di giocare?     "
BOX_BREAK
UNSKIPPABLE "Questi tre Cuccos che ho qui  \n"
"sono dei " COLOR(RED) "Super Cuccos" COLOR(DEFAULT) "!   "
BOX_BREAK
UNSKIPPABLE "Tirero' questi Super Cuccos nel\n"
"mucchio di quelli normali...    \n"
"       "
BOX_BREAK
UNSKIPPABLE "Se riuscirai a riprenderli in   \n"
"mezzo ai Cuccos normali     \n"
"entro un tempo limite,        \n"
"io ti regalero' " COLOR(RED) "qualcosa di buono" COLOR(DEFAULT) ".  "
BOX_BREAK
"Se non ci riuscirai, vincero' Io.\n"
"Costa 10 Rupié... Vuoi giocare? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mumble...Mumble...\n"
"Sono sveglio!! "
BOX_BREAK
"Cosa?"
BOX_BREAK
"Ehi, boscaiolo! \n"
"Hai tempo libero?  \n"
"Allora forza gioca! "
BOX_BREAK
"Andro' a tirare questi tre    \n"
COLOR(RED) "Super Cuccos " COLOR(DEFAULT) "nel mucchio di\n"
"quelli normali.    "
BOX_BREAK
"Se riuscirai a riprendere i tre \n"
"speciali dal gruppo di quelli\n"
"normali entro un certo tempo \n"
"limite, ti daro' " COLOR(RED) "qualcosa di buono" COLOR(DEFAULT) ". "
BOX_BREAK
"Se non riuscirai a trovarli,\n"
"vincero' le 10 Rupié... Vuoi giocare?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai solo 30 secondi!\n"
"Allora si parte! Pronto?   \n"
"Via con i Super Cuccos!  "
BOX_BREAK
SHIFT("\x30") "GUARDA BENE!!  " EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Fuori tempo!\n"
"Maaaaaale!!"
BOX_BREAK
"Questi sono veramente dei\n"
"Cuccos super! \n"
"Mi fanno guadagnare bene!      "
BOX_BREAK
"Venite da me, piccolini!   " EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' uno di loro!   \n"
"Sbrigati! Sbrigati!  \n"
COLOR(RED) "Ne mancano due" COLOR(DEFAULT) "!    " EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo é un altro!\n"
"Bene, é il momento della verita'!\n"
COLOR(RED) "Ne manca solo uno" COLOR(DEFAULT) "!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Peste! Che io sia dannato!\n"
"E' incredibile!! "
BOX_BREAK
"Questo é l'ultimo!  \n"
"Li hai trovati tutti!!\n"
"Vieni pure da me! " EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi riprovare?   "
BOX_BREAK
"Un giovanotto come te deve avere\n"
"il fuoco nelle vene!    \n"
"Trova i tre Super entro  \n"
"30 secondi."
BOX_BREAK
"Riprova solo a 5 Rupié?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, tu! \n"
"Hai il talento per divenire il  \n"
"miglior cowboy del mondo!  "
BOX_BREAK
"Che ne pensi di sposare Malon?\n"
"Huh?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Haw haw! Ma scherzavo!\n"
"Stavo solo scherzando! Penso tu sia\n"
"un po' giovane per il matrimonio eh?\n"
"Haw haw haw!"
BOX_BREAK
UNSKIPPABLE "Oh...! Sono orgoglioso di darti\n"
"un campione del nostro " COLOR(RED) "Latte   \n"
"Lon Lon" COLOR(DEFAULT) ". Farai un pieno di\n"
"energia quando lo berrai!  "
BOX_BREAK
UNSKIPPABLE "Dopo averlo finito, potrai\n"
"riportare la " COLOR(RED) "bottiglia" COLOR(DEFAULT) " e pagare per\n"
"riempirla nuovamente!  " EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi amico, hai una faccia onesta!\n"
"    "
BOX_BREAK
"Quando sarai grande, perché non\n"
"provi a lavorare in questo \n"
"ranch? E' un offerta sempre\n"
"valida! Ti aspettero'...    " EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"In arrivo! Ecco il freschissimo\n"
COLOR(RED) "Latte Lon Lon" COLOR(DEFAULT) "!  " EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"In arrivo! Eccoti un po' di\n"
"latte fresco..."
BOX_BREAK
"Oh? Maaaalissimo!!\n"
"Non hai una bottiglia vuota,  \n"
"vero?  "
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mumble...Mumble\n"
"Sono sveglio!"
BOX_BREAK
"Cosa?"
BOX_BREAK
"Ehi, " NAME "!\n"
"Se stai cercando Malon,     \n"
"é proprio qui fuori.   \n"
"O sei venuto a giocare? "
BOX_BREAK
"Bene allora, ti va di giocare al\n"
COLOR(RED) "Trova i Super-Cuccos" COLOR(DEFAULT) " con me?    \n"
"O, vuoi comprare un po' del\n"
COLOR(RED) "Latte Lon Lon" COLOR(DEFAULT) "?"
BOX_BREAK
"Allora decidi?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Latte Lon Lon - 30 Rupié\n"
"Gioco dei Cuccos - 10 Rupié   \n"
"Esci" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Hai fallito" COLOR(DEFAULT) "\n"
"Devi saltare sopra tutti i\n"
"cancelli!!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Ancora uno!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei sicuro di avvicinarti agli\n"
"ostacoli direttamente? Se  \n"
"sbagli l'angolazione, il cavallo\n"
"non salta! "
BOX_BREAK
"Se vuoi riprovare, monta su    \n"
"Epona e preparati!  "
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bravissimo!\n"
COLOR(RED)  RACE_TIME  COLOR(DEFAULT) " é il nuovo record!       "
BOX_BREAK
UNSKIPPABLE "Ti devo fare un regalo per  \n"
"commemorare il nuovo record!   "
BOX_BREAK
UNSKIPPABLE "Il regalo é un po' troppo pesante\n"
"per dartelo qui, percio' te lo spediro'\n"
"a casa tua. Scommetto che non\n"
"vedi l'ora di aprirlo! He hee!"
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il record attuale é " COLOR(RED) "50 secondi" COLOR(DEFAULT) ".   \n"
"Il tuo tempo é  " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "."
BOX_BREAK
"Se supererai il record, ti daro'\n"
"un regalo...       \n"
"Impegnati al massimo, OK?  "
BOX_BREAK
"Forza si parte! " EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il tuo tempo é di " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "!\n"
"Andrai al massimo?!  \n"
"Forza, si comincia!      " EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il record attuale é " COLOR(RED) "50 secondi" COLOR(DEFAULT) ".  \n"
"Prima, prova a superare il record!\n"
"Se batterai il record, ti daro'\n"
"un bel regalo!   \n"
"Impegnati al massimo, OK?  "
BOX_BREAK
"Va bene, si va a cominciare! " EVENT
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
UNSKIPPABLE "Non hai idea di cosa siano dei \n"
"\"Fratelli di Roccia\", ma ora \n"
"hai ben due Pietre Spirituali! \n"
"Te ne manca soltanto una! "
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non sai cosa voglia dire     \n"
"\"Fratelli di Roccia\", ma alla \n"
"fine hai tutte e tre le Pietre!!    \n"
"Torna dalla Principessa Zelda!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"L'ho finitaaaaaaa...\n"
"Scambiaaa per " COLOR(RED) "buono ritirooo" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Teeee looooo daaaaaarooooo' comeee\n"
"souvenirrrrrr."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mi sei piaciuto!"
BOX_BREAK
UNSKIPPABLE "Che ne pensi, diventiamo\n"
"Fratelli di Roccia?!"
BOX_BREAK
UNSKIPPABLE "No, nessuna grande cerimonia\n"
"da fare! Prendi questo come\n"
"segno di grande amicizia!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x30") "Sei un grande!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Un bell'abbraccio Goron,  \n"
"fratello?!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "Oh!" BOX_BREAK_DELAYED("\x1E")  SHIFT("\x4B") "Oh-oh!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x4B")  QUICKTEXT_ENABLE "Forza!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x14") "E andiamo! Vaiii! " QUICKTEXT_ENABLE "Ritmooo!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x50")  QUICKTEXT_ENABLE "SUPER" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x28") "Che musicaaaa!!!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x32") "WHOOOOAH!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YEEEEAH!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YAHOOO!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono uno dei " COLOR(RED) "Gorons" COLOR(DEFAULT) ",   \n"
"il popolo mangia-pietre che\n"
"vive sulla montagna.   "
BOX_BREAK
UNSKIPPABLE "Guarda quel masso enorme\n"
"li' davanti!"
BOX_BREAK
UNSKIPPABLE "Blocca l'entrata alle     \n"
COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) ", che una volta,\n"
"erano un posto importante per noi\n"
"Gorons..."
BOX_BREAK
UNSKIPPABLE "Ma un giorno, apparvero\n"
"improvvisamente moltissimi   \n"
"Dodongos. E divenne un   \n"
"posto pericoloso!  "
BOX_BREAK
UNSKIPPABLE "Erano guidati da un " COLOR(RED) "Gerudo dalla\n"
"armatura nera" COLOR(DEFAULT) " che uso' la magia \n"
"per sigillare l'entrata!    " TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vorrei poter rotolare giu'   \n"
"dalla montagna con un       \n"
COLOR(RED) "Fiore Bomba " COLOR(DEFAULT) " e...."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "BOOOOOOM!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
"Se potessi farlo con un Fiore  \n"
"Bomba, diverrei un vero Goron.    "
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sto in piedi per fare ombra ai\n"
COLOR(RED) "Fiori Bomba " COLOR(DEFAULT) "dal sole.  "
BOX_BREAK
"Vuoi forse chiedermi qualcosa?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Chiedi dei Fiori Bomba\n"
"Chiedi delle Caverne Dodongo " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Queste piante che crescono qui, \n"
"sono" COLOR(RED) " Fiori Bomba" COLOR(DEFAULT) ".\n"
"Sono \"piante minerarie\" e crescono solo \n"
"su questi monti."
BOX_BREAK
"Il loro frutto é il materiale\n"
"grezzo per le bombe."
BOX_BREAK
"Ma un non-Goron difficilmente \n"
"potra' cogliere i Frutti\n"
"delle piante!"
BOX_BREAK
"Crescono solitamente in posti\n"
"oscuri, percio', quelle che crescono\n"
"in zone come queste sono\n"
"molto rare.  "
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Queste piante che crescono qui \n"
"sono " COLOR(RED) "Fiori Bomba" COLOR(DEFAULT) ".\n"
"Sono \"piante minerarie\" che crescono\n"
"solo su questi monti."
BOX_BREAK
"Di solito crescono solo in posti\n"
"oscuri tipo miniere, percio'\n"
"quelle che crescono in zone come\n"
"questa sono molto rare. "
BOX_BREAK
"Avendo il " COLOR(RED) "Braccialetto Goron" COLOR(DEFAULT) ",  \n"
"persino un piccoletto come te puo'\n"
"raccoglierle con " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".   "
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai visto l'entrata lungo il sentiero?  \n"
"Sono le " COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) "...     "
BOX_BREAK
"All'interno, c'é pochissima luce, \n"
"ed i " COLOR(RED) "Fiori Bomba" COLOR(DEFAULT) ", delle piante\n"
"uniche in queste montagne,\n"
"crescono floridamente! "
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh?"
BOX_BREAK
UNSKIPPABLE "Non abbiamo spesso visite qui \n"
"sotto. Da dove vieni?    "
BOX_BREAK
UNSKIPPABLE "La foresta?"
BOX_BREAK
UNSKIPPABLE "Cos'é una \"foresta\"? "
BOX_BREAK
UNSKIPPABLE "Eh?"
BOX_BREAK
UNSKIPPABLE "E' dove crescono \"alberi\" e     \n"
"\"piante\"?     "
BOX_BREAK
UNSKIPPABLE "Capisco sempre di meno!     \n"
"Qui non cresce niente, tranne i  \n"
COLOR(RED) "Fiori Bomba" COLOR(DEFAULT) "...     "
BOX_BREAK
UNSKIPPABLE "Non abbiamo né \"semi\" né \"noci\"\n"
"qui intorno...     "
BOX_BREAK
UNSKIPPABLE "Persino i Rami Deku sono molto  \n"
"scarsi qui! " TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ho sigillato l'entrata perche' \n"
"non avevo molta merce da   \n"
"vendere. Ma poiche' sei un cliente\n"
"insistente ti ascoltero'." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Spiacente...\n"
"Quella bomba é in esposizione. \n"
"Ho " COLOR(RED) "terminato " COLOR(DEFAULT) "le scorte... " EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Perché mi hai fermato?\n"
"Non fermarmi qui!"
BOX_BREAK
"Non puoi fermare il rotolamento!"
BOX_BREAK
"E' il solo modo che ho per \n"
"combattere lo stress!     "
BOX_BREAK
"Ora stai attento al\n"
"rotolamento selvaggio! "
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tutto Ok! Ti daro' questo in\n"
"premio per il tuo coraggio!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie molte! Esprimero' la mia \n"
"gioia rotolando ancora!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x21") "Oh...ho una fame... "
BOX_BREAK
UNSKIPPABLE "Tutti sono deboli dalla fame.\n"
"A causa della mancanza di cibo in\n"
"questa citta' siamo in pericolo\n"
"di estinzione!"
BOX_BREAK
UNSKIPPABLE "Tutto perché non si puo' entrare\n"
"piu' nelle " COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) ".     "
BOX_BREAK
UNSKIPPABLE "Noi Gorons ci cibiamo di   \n"
"pietre..."
BOX_BREAK
UNSKIPPABLE "E le pietre piu' deliziose e\n"
"nutritive dei dintorni si trovano\n"
"nelle Caverne Dodongo! Ma sembra  \n"
"storia antica per noi ora...     "
BOX_BREAK
UNSKIPPABLE "Ormai abbiamo abituato il palato\n"
"e tutto il resto ci sembra non  \n"
"aver sapore!  " TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sigh...Come vorrei mangiarmi \n"
"un pate' di roccia delle\n"
COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi!"
BOX_BREAK
UNSKIPPABLE "E' pericoloso per un ragazzino come \n"
"te arrivare sino qui.\n"
"Potevi cadere giu'!  "
BOX_BREAK
UNSKIPPABLE "Io credo tu sia arrivato fino qui\n"
"per mangiarti la" COLOR(RED) " Pietra Rossa" COLOR(DEFAULT) "!\n"
"Peccato! Non é piu' qui! "
BOX_BREAK
UNSKIPPABLE "Cosa? Non sei qui per questo?    "
BOX_BREAK
UNSKIPPABLE "Sei alla ricerca della \"Pietra\n"
"Spirituale\"? Che sia quella pietra\n"
"rossa dall'aspetto delizioso\n"
"che una volta era qui!"
BOX_BREAK
UNSKIPPABLE "Sono cosi' affamato che mi  \n"
"sarebbe bastato darle appena una\n"
"leccatina...Ma ormai non c'é piu'...\n"
"Resto qui a ricordarla..."
BOX_BREAK
UNSKIPPABLE "Penso l'abbia tolta il\n"
"Grande Fratello. "
BOX_BREAK
UNSKIPPABLE "Diceva sempre che tutti sbavavano\n"
"dietro alla pietra!" TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il Grande Fratello si é chiuso\n"
"dentro dicendo:     \n"
"\"" COLOR(RED) "Aspettero' qui un messaggero\n"
"della Famiglia Reale!!" COLOR(DEFAULT) "\"   "
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono cosi' affamato che non riesco\n"
"a pensare che al cibo!"
BOX_BREAK
UNSKIPPABLE "Parlare al Grande Fratello non\n"
"é facile. "
BOX_BREAK
UNSKIPPABLE "Se é di cattivo umore, non si\n"
"riesce a farlo ragionare...\n"
"Ti avra' spaventato. Ma..."
BOX_BREAK
UNSKIPPABLE "Io so il suo SEGRETO."
BOX_BREAK
UNSKIPPABLE "Forse non sembrera' il tipo, \n"
"ma ama danzare!              \n"
"Se preso dal ritmo, lo fara' di sicuro..." TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ricordo che il Grande Fratello\n"
"di solito ascoltava la " COLOR(ADJUSTABLE) "musica\n"
"che viene dalla foresta" COLOR(DEFAULT) "..."
BOX_BREAK
"Ah si, bei vecchi tempi... \n"
"Quella musica mi provoca\n"
"tanta nostalgia..." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma che diamine! Tu chi sei?!"
BOX_BREAK
UNSKIPPABLE "Ho sentito la " COLOR(BLUE) "Canzone della\n"
"Famiglia Reale" COLOR(DEFAULT) ", e mi aspettavo\n"
"l'arrivo del messaggero, ma... \n"
"Tu sei solo un ragazzino!"
BOX_BREAK
UNSKIPPABLE "Che " COLOR(RED) "Darunia" COLOR(DEFAULT) ", il Gran Capo dei\n"
"Gorons, abbia davvero perso il\n"
"suo status si da essere trattato\n"
"cosi' da suo fratello, il RE?"
BOX_BREAK
UNSKIPPABLE "Sono DAVVERO furioso!\n"
"Togliti di torno, SUBITO!"
BOX_BREAK
UNSKIPPABLE "Ti stai chiedendo perché sono\n"
"di cosi' cattivo umore?"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Antiche creature hanno\n"
"infestato le Caverne Dodongo! " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Abbiamo un misero raccolto del\n"
"nostro cibo, i Fiori Bomba! " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Viviamo la fame a causa della\n"
"carenza di rocce!    " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SHIFT("\x48") "Ma... " TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "E' un nostro problema!  " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x11") "Non ci serve l'aiuto di uno\n"
SHIFT("\x46") "straniero!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x15") "Ehiii!! Che bella musica!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Per merito suo, non sono piu' \n"
"depresso! Mi e' successo qualcosa!\n"
"All'improvviso ho voglia   \n"
"di ballaaareeeee!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x3C") "Sono " COLOR(RED) "Darunia" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Il Gran Capo dei Gorons!       \n"
"C'era qualcosa che intendevi   \n"
"chiedermi?      "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x50") "Cosa?"
BOX_BREAK
UNSKIPPABLE "Vuoi la " COLOR(RED) "Pietra Spirituale del\n"
"Fuoco" COLOR(DEFAULT) "??     "
BOX_BREAK
UNSKIPPABLE "La Pietra del Fuoco, conosciuta\n"
"anche come il Rubino Goron, é un\n"
"tesoro della nostra razza... "
BOX_BREAK
UNSKIPPABLE "Ma aspetta...\n"
"Non te lo daro' cosi' facilmente.\n"
"Se lo desideri cosi' tanto...   "
BOX_BREAK
UNSKIPPABLE "Perché non vai a distruggere il\n"
"mostro delle Caverne Dodongo, pro-\n"
"vando cosi' il tuo vero coraggio?   "
BOX_BREAK
UNSKIPPABLE "In questo modo, tutti ritorneranno\n"
"felici! Se lo farai, \n"
"ti daro' tutto cio' che vuoi, persino\n"
"la Pietra Spirituale!!"
BOX_BREAK
UNSKIPPABLE "Ma ho lo stesso qualcosa per te,\n"
"e non te la sto dando per interesse,\n"
"ma solo perché sono felice...\n"

BOX_BREAK
UNSKIPPABLE "Se lo indosserai, riuscirai persino\n"
"a raccogliere i " COLOR(RED) "Fiori Bomba" COLOR(DEFAULT) " \n"
"premendo " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!    "
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Distruggi i mostri delle  \n"
COLOR(RED) "Caverne Dodongo " COLOR(DEFAULT) "e diverrai un\n"
"vero eroe! Poi, potremo parlare\n"
"della Pietra Spirituale!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, Fratello, suona quel\n"
"motivo un altra volta! "
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Non importa quante volte lo senta,\n"
"non smette mai di piacermi! "
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, non e' proprio quello  \n"
"che mi aspettavo..."
BOX_BREAK
"Volevo sentire...un motivo...\n"
"qualcosa...um...da fuori... \n"
"dalla montagna...qualcosa di \n"
"verde...naturale.."
BOX_BREAK
"Quella e' la musica che volevo  \n"
"sentire..."
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Possiamo rientrare nella caverna.\n"
"Sei in gamba!! "
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'é un trucco per conservare i rami!\n"
"Quando bruci un ramo, si consumera' \n"
"rapidamente. Premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e riponilo \n"
"prima che bruci completamente! "
BOX_BREAK
"Comunque, c'é un ramo,\n"
"nascosto qui... \n"
"Hehehee..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sono io, " COLOR(RED) "Darunia" COLOR(DEFAULT) "!\n"
"Ben fatto!"
BOX_BREAK
UNSKIPPABLE "Grazie a te, possiamo mangiare\n"
"di nuovo le buone rocce delle\n"
"Caverne Dodongo fino a farne     \n"
"indigestione! "
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono cosi' affamato che riesco a\n"
"pensare solo a mangiare!"
BOX_BREAK
UNSKIPPABLE "\"Pietra Spirituale\"?\n"
"Ma intendi la " COLOR(RED) "Pietra Rossa" COLOR(DEFAULT) "\n"
"della citta'?   "
BOX_BREAK
UNSKIPPABLE "L'ha presa " COLOR(RED) "Darunia " COLOR(DEFAULT) "il Grande Fratello.\n"
"Si é chiuso nella sua \n"
"stanza e non vuole uscire..."
BOX_BREAK
UNSKIPPABLE "Da allora, sembra che siano  \n"
"sparite le luci della citta'...  \n"
"...Tutti sembrano cosi'... \n"
"Depressi... " TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vorrei portare il " COLOR(RED) "fuoco" COLOR(DEFAULT) " dalla stanza\n"
"del Grande Fratello.  "
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, capisco...\n"
"Potevamo lanciare giu' la\n"
"bomba dal burrone... "
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei proprio incredibile, hai\n"
"sconfitto i Dodongos! Ti posso\n"
"chiamare Grande Fratello?"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Grazie a te, stiamo meglio! \n"
"Perché non compri delle bombe\n"
"ora?" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti sono veramente grato, e se un\n"
"giorno avro' un figlio, lo chiamero'\n"
"come te!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se vuoi sapere altre notizie\n"
"sui Goron, vai sino in citta'!"
BOX_BREAK
COLOR(RED) "Goron City" COLOR(DEFAULT) " e' appena piu'\n"
"avanti sul sentiero. Non ci vorra'\n"
"molto da qui, anche se sei a \n"
"piedi.  "
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prendi i Fiori Bomba premendo  \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Premi " COLOR(BLUE) "[A] " COLOR(DEFAULT) "e le attiverai. "
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Solo quando le " COLOR(RED) "torce" COLOR(DEFAULT) " saranno accese,\n"
"Goron city sara' davvero viva!!    "
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Stai andando a ripulire le caverne?\n"
"E' un problema dei Goron.  \n"
"Ma tu sei un ragazzino curioso, é \n"
"vero o no?! "
BOX_BREAK
"Bene, naturalmente saremo felici\n"
"se ci riuscirai...Almeno potremo  \n"
"nutrirci con delle buone rocce.  "
BOX_BREAK
"Ma ti devo avvertire...   \n"
"I Dodongos fanno veramente paura!  \n"
"Mangiano di TUTTO!!  "
BOX_BREAK
"Stai molto attento, e non farti\n"
"mangiare!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Te l'ho gia' detto!\n"
"Bombe finite! Nix!!\n"
"Ohhh... Che fame!!    " PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Come sta il Grande Fratello?"
BOX_BREAK
"Comunque, conosci la musica\n"
"che viene dal profondo di questo\n"
"tunnel? A tutti noi piace moltissimo!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non mi faro' prendere!  \n"
"Tu lavori per Ganondorf, vero?! "
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Come hai potuto farmi questo?\n"
"Sei uno dei servi di Ganondorf!"
BOX_BREAK
UNSKIPPABLE "Senti il mio nome e TREMA!"
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(RED)  NAME  COLOR(DEFAULT) "!\n"
"Eroe dei Gorons!   "
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cosa?"
BOX_BREAK
UNSKIPPABLE "Anche tu ti chiami\n"
NAME "?"
BOX_BREAK
UNSKIPPABLE "Allora sei il leggendario\n"
"uccisore di Dodongo ed Eroe, \n"
NAME "!"
BOX_BREAK
UNSKIPPABLE "Mio padre é " COLOR(RED) "Darunia" COLOR(DEFAULT) "...\n"
"Ti ricordi di lui?"
BOX_BREAK
UNSKIPPABLE "Mi ha chiamato " NAME "\n"
"in tuo onore, per il tuo\n"
"coraggio!"
BOX_BREAK
UNSKIPPABLE "E' forte come nome!\n"
"Mi piace molto!"
BOX_BREAK
UNSKIPPABLE  NAME ", tu sei un eroe per\n"
"noi Gorons.\n"
"Che gioia conoscerti!  "
BOX_BREAK
UNSKIPPABLE "Ti prego fammi un autografo!  \n"
"Scrivi:\n"
SHIFT("\x05") "\"Al mio amico,  \n"
SHIFT("\x05")  NAME " dei Gorons\"   "
BOX_BREAK
UNSKIPPABLE "Oh..."
BOX_BREAK
UNSKIPPABLE "Ma non é un buon momento per\n"
"chiedertelo, adesso...\n"
"Ti prego, aiutaci!"
BOX_BREAK
UNSKIPPABLE "Mio padre, Darunia, é andato al\n"
COLOR(RED) "Tempio del Fuoco" COLOR(DEFAULT) ", dal dragone!  "
BOX_BREAK
UNSKIPPABLE "Se non ci sbrighiamo, anche lui  \n"
"sara' mangiato dal dragone!! " TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"B-b-b-boooo hooooo!" EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Sarebbe meglio provare a calmarlo\n"
"se ci riesci...\n"
"Forse riuscirai a calmarlo   \n"
"parlandogli?"
BOX_BREAK
"Cosa vorresti chiedergli?   \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Dell'antico Dragone\n"
"Dei Gorons   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tanto tempo fa c'era un drago\n"
"malvagio di nome " COLOR(RED) "Volvagia " COLOR(DEFAULT) "che\n"
"viveva nella montagna."
BOX_BREAK
UNSKIPPABLE "Era un drago spaventoso!\n"
"Odiava i Gorons!"
BOX_BREAK
UNSKIPPABLE "Usando un enorme martello, l'eroe\n"
"dei Gorons...BOOOM!"
BOX_BREAK
UNSKIPPABLE "Lo uccise in un attimo. E' una\n"
"leggenda del passato, ma realmente\n"
"accaduta!"
BOX_BREAK
UNSKIPPABLE "Lo so, perché mio padre é\n"
"un discendente dell'eroe!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono stati portati tutti al\n"
COLOR(RED) "Tempio del Fuoco" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Mentre papa' era via\n"
"i seguaci di Ganodorf " COLOR(DEFAULT) "vennero\n"
"e presero tutti!    "
BOX_BREAK
UNSKIPPABLE "Saranno tutti mangiati da   \n"
COLOR(RED) "Volvagia" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Papa' disse che Ganondorf\n"
"ha resuscitato Volvagia."
BOX_BREAK
UNSKIPPABLE "Come monito a coloro che si\n"
"oppongono a lui, Ganondorf li dara'\n"
"in pasto a Volvagia!     "
BOX_BREAK
UNSKIPPABLE "Papa' ando' al Tempio di Fuoco \n"
"da solo per tentare di\n"
"salvare tutti..."
BOX_BREAK
UNSKIPPABLE "Aiutalo tu, " NAME "!\n"
"Ti daro' questa " COLOR(RED) "Tunica Ignifuga" COLOR(DEFAULT) "!        "
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Papa' mi ha detto di impedire a\n"
"chiunque di seguirlo, ma...     "
BOX_BREAK
UNSKIPPABLE "Solo tu, " NAME ", puoi\n"
"salvare tutti!"
BOX_BREAK
UNSKIPPABLE "Sono sicuro che il negoziante, che\n"
"si nasconde da qualche parte, potra'\n"
"aiutarti!   "
BOX_BREAK
UNSKIPPABLE "Ora, ti parlero' del passaggio\n"
"segreto per il Tempio del Fuoco!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muovi la " COLOR(RED) "statua" COLOR(DEFAULT) " nella stanza \n"
"di papa'!  "
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chi é la'? Ma chi sei,  \n"
NAME "...? Oh sei proprio tu " NAME "!  "
BOX_BREAK
UNSKIPPABLE "Sei cosi' cresciuto dall'ultima \n"
"volta!  "
BOX_BREAK
UNSKIPPABLE "Vorrei parlarti da uomo-a-uomo  \n"
"ma purtroppo non é il momento... "
BOX_BREAK
UNSKIPPABLE "Ganondorf é ritornato alla     \n"
"Montagna della Morte!\n"
"Ha resuscitato l'antico,       \n"
"dragone Volvagia!"
BOX_BREAK
UNSKIPPABLE "Oltretutto, vuole sacrificare\n"
"il mio popolo al malvagio dragone  \n"
"come monito alle altre razze che\n"
"gli resistono...   "
BOX_BREAK
UNSKIPPABLE "Se quel drago sputa-fuoco scappa\n"
"dalla montagna, l'intera Hyrule\n"
"diverra' un arida terra bruciata!\n"
"    "
BOX_BREAK
UNSKIPPABLE "Io vado avanti per provare a\n"
"sconfiggere il drago...   "
BOX_BREAK
UNSKIPPABLE "Sebbene, sono preoccupato, perché\n"
"non ho con me il mitico martello.\n"
"Ma non ho scelta...  "
BOX_BREAK
UNSKIPPABLE  NAME "...Te lo sto chiedendo\n"
"come Fratello di Roccia...  "
BOX_BREAK
UNSKIPPABLE "Mentre provo a combattere il\n"
"dragone, salva il mio popolo!      "
BOX_BREAK
UNSKIPPABLE "Le celle dei prigionieri sono\n"
"dall'altra parte.    \n"
"Conto su di te, " NAME "!      "
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono salvo!\n"
"Grazie!\n"
"Ecco, prendi pure!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "...Non posso...\n"
"tenerlo... Non ce la faccio\n"
"piu' ormai..."
BOX_BREAK
UNSKIPPABLE "Esci fuori ora!! "
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Grazie, Fratello! \n"
"Ho realmente apprezzato cio'\n"
"che hai fatto. Ti ringrazio a\n"
"nome dell'intera razza!"
BOX_BREAK
UNSKIPPABLE "Ti sei dimostrato un vero eroe, \n"
"proprio come pensavo!!      "
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT("\x36") "Non scordarlo..\n"
SHIFT("\x03") "Ora io e te siamo veri Fratelli!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E' qualcosa che va al di la' del\n"
"tempo...Una vera amicizia.\n"
"Un sentimento che piu' passa il         \n"
"tempo piu' si rafforza."
BOX_BREAK
UNSKIPPABLE "La forza dell'amicizia diverra'       \n"
"presto un vero potere,\n"
"e tramite quest'ultimo saprai\n"
"quale via scegliere..."
BOX_BREAK
UNSKIPPABLE "Questa canzone é dedicata alla\n"
"forza del cuore...   \n"
"Ascolta il " COLOR(RED) "Bolero del Fuoco" COLOR(DEFAULT) "... "
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...Ci rivediamo... "
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME ", é cosi' caldo qui!  \n"
"Non possiamo restarci molto! " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Fratello " NAME "!\n"
"Sono tornati tutti!    "
BOX_BREAK
UNSKIPPABLE "Tu e papa' avete distrutto il   \n"
"drago, insieme!      " TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando crescero', voglio essere\n"
"forte come te,      \n"
NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie, " NAME "!!   "
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Grazie molte per averci\n"
"salvato!  " PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Comunque, Io, Darunia\n"
"il Selvaggio, diverro' il grande  \n"
COLOR(RED) "Saggio del Fuoco" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Non é divertente, Fratello?\n"
"Bene, questo é cio' che chiamano\n"
"destino."
BOX_BREAK
UNSKIPPABLE "Niente mi ha reso piu' felice\n"
"che aiutarti a battere il male!   "
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, Fratello, prendi!  \n"
"Questo " COLOR(RED) "Medaglione" COLOR(DEFAULT) " contiene il    \n"
"potere degli spiriti del fuoco e\n"
"la mia amicizia."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Gran casino!\n"
"Tutti spariti! \n"
"Ma io ho lasciato comunque aperto!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Che grande avventura!\n"
"Diverra' un incredibile storia...   "
BOX_BREAK
UNSKIPPABLE "Non posso credere che i Dodongos \n"
"siano apparsi in cosi' grande numero! "
BOX_BREAK
UNSKIPPABLE "E l'ingresso bloccato da quella\n"
"roccia... "
BOX_BREAK
UNSKIPPABLE "Tutti questi guai sono stati  \n"
"causati da quel ladro Gerudo, \n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Mi disse:\n"
"\"" COLOR(LIGHTBLUE) "Dammi la Pietra Spirituale! \n"
"Solo allora apriro' di nuovo le\n"
"caverne!" COLOR(DEFAULT) "\""
BOX_BREAK
UNSKIPPABLE "Tu, al contrario, hai rischiato \n"
"la vita per noi..."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Sta stretto."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sto lavorando su qualcosa di  \n"
"veramente forte! Ma penso che ci\n"
"vorra' un po' di tempo... " TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se puoi aspettare cinque o sei anni,\n"
"sara' pronto. OK?    "
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho completato una piccola arma. \n"
"Che ne pensi..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che sensazioni ti trasmette?   "
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sembra che ci sia un problema con\n"
"la sua durabilita'...\n"
"Ma se vuoi..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puoi comprare la mia lama per   \n"
"200 Rupié? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va bene. Ritorna di nuovo. "
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti prego...non...mangiarmi...\n"
"Se mi mangi ti verra',\n"
"sicuramente, mal di stomaco!  "
BOX_BREAK
"Ti dispiacera'!! "
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, vedo. Il Grande Fratello\n"
"Darunia, ti ha inviato a \n"
"cercarmi. Scusami! "
BOX_BREAK
"Ti prego, aiuta Darunia!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mio frrratello...\n"
"Ha aperrrto un negozio.\n"
"E' il Negozio di Lame\n"
"Medigorrrrron..."
BOX_BREAK
"Comunque...\n"
"Io sono migliorrrrrre nel\n"
"forgiarrrre lame."
BOX_BREAK
"I carrrrrpentieri di Hylian \n"
"mi hanno prrrregato perrrrr\n"
"la mia abilita'...  "
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quella lama rrrrrotta e' il mio\n"
"lavorrrrrrrro...\n"
UNSKIPPABLE "Vorrrrei verrramente riparrrarla, ma..."
BOX_BREAK
UNSKIPPABLE "Ma a causa dell' errrruzione\n"
"di ierrrrri, i miei occhi\n"
"sono irrrrritati... "
BOX_BREAK
UNSKIPPABLE "Mi serrvono delle lacrrrrime  \n"
"currrrative. Le troverrrrai se andrai \n"
"a visitare" COLOR(RED) " Rrrrrrre Zorrrrrra" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ti prego prendi le lacrrrrrrime...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Awww nooooo... E' finita...   \n"
"Mi prrrrrrudono gli occhi...\n"
"Owwwwww..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, no! Se ne sono andati tutti!\n"
"Resto solo io!  " EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ti stavo asssssspettando, con\n"
"le lacrrrrime per gli occhi...\n"
"Ti prego salutami Rrrrrre Zorrrra!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Davverrrrro? Hai comprrrrato le  \n"
"lacrrrrime? Che sollievo! Le     \n"
"userrrrrro' immediatamente!      " EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(RED) "Wowwwwwwwwwwwwww!!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE "Che bellezza! Funzionano \n"
"alla grrrrrrrande!    "
BOX_BREAK
UNSKIPPABLE "Orrra posso torrrrnare al mio \n"
"lavorrrrro! Anche se ne ho poco  \n"
"adesso, ti darrrrro' questa cosa  \n"
"cosi' non dimenticherrrrrrai..." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tutti sono torrrrrrnati!\n"
"Sono i soliti affarrri!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Trra qualche giorno...\n"
"Rrritorna di nuovo...\n"
"Aspetta, sii paziente...    "
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Non ancora...\n"
"Ehi... \n"
"Sei molto impaziente..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Questa lama é il\n"
"mio miglior lavoro!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Lo " COLOR(DEFAULT) "scudo" COLOR(LIGHTBLUE) " é perso!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "La " COLOR(DEFAULT) "tunica " COLOR(LIGHTBLUE) "che indossavi é   \n"
"andata!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Lo " COLOR(DEFAULT) "scudo" COLOR(LIGHTBLUE) " é andato!  \n"
"Anche la " COLOR(DEFAULT) "tunica" COLOR(LIGHTBLUE) " che indossavi\n"
"é stata presa!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sei stato in gamba ad arrivare\n"
"fino qua sopra " NAME ". \n"
"Questa é la vetta della sacra\n"
"Montagna della Morte!   "
BOX_BREAK
UNSKIPPABLE "Si dice che le nuvole che  \n"
"circondano questa vetta rivelino \n"
"le condizioni della Montagna.\n"
"Quando sembrano normali, c'é la pace."
BOX_BREAK
UNSKIPPABLE "Arrampicarti sino a qui, ha\n"
"dimostrato quanto sei sveglio! \n"
"Ora devi fare un'altra\n"
"mossa intelligente...    "
BOX_BREAK
UNSKIPPABLE "La " COLOR(RED) "Grande Fata" COLOR(DEFAULT) " vive su questa\n"
"cima, e ti potra' donare una\n"
"nuova abilita'! E' la regina di tutte\n"
"le fate, lo sapevi? Hoot hoo!"
BOX_BREAK
UNSKIPPABLE "Io resto appollaiato qui, ti aspetto.\n"
"Quando vorrai tornare giu',\n"
"ti potro' aiutare! Ora sbrigati, vai!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hoo hoot!\n"
"Bene, sembra tu sia migliorato\n"
"un po' grazie al potere della\n"
"Grande Fata... "
BOX_BREAK
"Ma non hai ancora l'aspetto dell'eroe\n"
"che salvera' Hyrule.\n"
"Almeno non ancora!        "
BOX_BREAK
"Se vuoi scendere " COLOR(RED) "giu' dalla \n"
"montagna" COLOR(DEFAULT) ", ti daro' un passaggio.  \n"
"Vieni qui e afferra gli artigli!\n"
"Tieniti bene! Hoooo hooooooot!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si dice che una " COLOR(RED) "bellissima" COLOR(DEFAULT)  COLOR(RED) " Fata\n"
COLOR(DEFAULT) "viva in cima alla Montagna!   "
BOX_BREAK
"Non vuoi provare a vederla?"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si dice che una " COLOR(RED) "Fata" COLOR(DEFAULT) " viva sulla \n"
"cima della Montagna."
BOX_BREAK
"Se vuoi arrivare sino alla vetta, \n"
"dovrai avere un grosso " COLOR(LIGHTBLUE) "scudo " COLOR(DEFAULT) " \n"
"con te...  "
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Ehi! Un " COLOR(DEFAULT) "pulcino " COLOR(LIGHTBLUE) "e' uscito\n"
"dall'" COLOR(DEFAULT) "uovo " COLOR(LIGHTBLUE) "che stavi incubando!\n"
"E' il miracolo della vita!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai preso la pietra rossa?\n"
"Lasciami dare una leccatina!"
BOX_BREAK
"No? Boooo!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Fratello! Ci racconterai delle\n"
"tue abilita' durante il viaggio,\n"
"ti' va'? "
BOX_BREAK
UNSKIPPABLE "Dovresti visitare la " COLOR(RED) "Grande Fata " COLOR(DEFAULT) "\n"
"sulla cima della Montagna!\n"
"Ti potra' potenziare!"
BOX_BREAK
UNSKIPPABLE "Ehi, tutti! Salutiamo il nostro \n"
"Fratello!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti diro' un segreto per\n"
"avermi salvato!"
BOX_BREAK
UNSKIPPABLE "In questo tempio, ci sono " COLOR(RED) "porte\n"
"che cadono " COLOR(DEFAULT) "quando provi ad   \n"
"aprirle. Quando una di queste\n"
"inizia a cadere, muoviti! "
BOX_BREAK
UNSKIPPABLE "Se usi un campione della\n"
"\"crema speciale\" Goron, potrai \n"
"romperle..."
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti rivelero' un segreto come\n"
"premio per avermi salvato!"
BOX_BREAK
UNSKIPPABLE "Quando sei infiammato, puoi\n"
"spegnere le fiamme agitando la\n"
"spada, o rotolando in avanti...\n"
"Lo sapevi?      "
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ecco un suggerimento per te! "
BOX_BREAK
UNSKIPPABLE "Da qualche parte nel tempio,\n"
"incontrerai delle strane creature\n"
"che danzano nel fuoco e\n"
"attaccano. Le frecce non servono!"
BOX_BREAK
UNSKIPPABLE "Per difenderti ti servira' un po'\n"
"di \"crema speciale\" Goron! Mmmmm\n"
"E ho detto tutto!      "
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti diro' un segreto per\n"
"avermi salvato!"
BOX_BREAK
UNSKIPPABLE "Ci sono dei pulsanti nel tempio\n"
"che devi colpire per attivarli.  \n"
"Ma, puoi usare anche la\n"
"\"crema speciale\" Goron per farlo...  "
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti diro' un segreto per\n"
"avermi aiutato!"
BOX_BREAK
UNSKIPPABLE "Se trovi un luogo che puoi\n"
"vedere sulla mappa, ma non puoi\n"
"raggiungerlo, suona l'Ocarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie! Ti svelero' un    \n"
"segreto!  "
BOX_BREAK
UNSKIPPABLE "Per accedere alla stanza dove\n"
"é andato Darunia, devi fare\n"
"qualcosa con quella colonna\n"
"bloccata sulla volta...    "
BOX_BREAK
UNSKIPPABLE "Trova la via che conduce alla\n"
"stanza al di sopra del soffitto!"
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ti diro' un segreto per  \n"
"aiutarti!    "
BOX_BREAK
UNSKIPPABLE "Una porta é nascosta dietro la\n"
"statua all'entrata del Tempio.   "
BOX_BREAK
UNSKIPPABLE "Ma, la \"crema speciale\" Goron non\n"
"ti servira'...Ci vorra' qualcosa\n"
"di piu' potente?"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie! Eccoti un segreto!    "
BOX_BREAK
UNSKIPPABLE "Un muro che puoi abbattere con  \n"
"la \"crema speciale\" Goron, se\n"
"colpito con la spada, emettera'\n"
"un suono diverso da un muro normale."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi stai liberando?\n"
"Me ne posso andare?" EVENT
)

DEFINE_MESSAGE(0x3072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3072"
)

DEFINE_MESSAGE(0x3073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3073"
)

DEFINE_MESSAGE(0x4000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Questi occhi di rana sono ottimi!\n"
"Stasera cucinero' occhi fritti per\n"
"la prima volta da tanto tempo!    \n"
"Uhoy hoy hoo houy hoy!"
BOX_BREAK
UNSKIPPABLE "Ottimo articolo! Ringrazia,\n"
"per me, il Re Zora!      \n"
"Eh? Cosa?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Queste sono per fare le " COLOR(RED) "Lacrime \n"
"Biggoron" COLOR(DEFAULT) "? Oh, come mi dispiace!  \n"
"Avresti dovuto avvisarmi prima!\n"
"            " EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
"Di qua! Hoohoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Mi chiedo coosa fara' ora " COLOR(RED) "Saria" COLOR(DEFAULT) "? \n"
"Che dici, torniamo alla\n"
"foresta ogni tanto? "
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ma cosa stai facendo? Devi averne\n"
"fatta di strada sino a qui." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Dovresti guardare il\n"
COLOR(RED) "SottoMenu Mappa" COLOR(DEFAULT) " talvolta..."
BOX_BREAK
UNSKIPPABLE  NAME ", questo é un bel lago\n"
"ricco di acque pure e chiare. "
BOX_BREAK
UNSKIPPABLE "Proprio in fondo c'é il\n"
COLOR(BLUE) "Tempio dell'Acqua" COLOR(BLUE)  COLOR(DEFAULT) ", usato per evocare\n"
"gli spiriti del lago.\n"
"I custodi del tempio sono gli" COLOR(BLUE) " Zoras" COLOR(DEFAULT) ".       "
BOX_BREAK
UNSKIPPABLE "Gli Zoras vengono dalle terre a\n"
"nord-est di Hyrule.\n"
"Sono una razza acquatica, da molto\n"
"tempo alleata della Famiglia Reale."
BOX_BREAK
UNSKIPPABLE "Ho sentito che solo la Famiglia\n"
"Reale accede ai domini degli Zoras...  \n"
"Hoo hoo!"
BOX_BREAK
UNSKIPPABLE "Sto ritornando al " COLOR(RED) "castello" COLOR(DEFAULT) ".      \n"
"Se vuoi venire con me, afferra i\n"
"miei artigli!    "
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sto ritornando al " COLOR(RED) "castello" COLOR(DEFAULT) ". Se   \n"
"vuoi venire con me afferra i miei\n"
"artigli!        "
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "...Huh?"
BOX_BREAK
UNSKIPPABLE "Sembra ci sia qualcosa all'interno\n"
"della bottiglia.      \n"
"E' una " COLOR(RED) "lettera" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C") "\"" COLOR(PURPLE) "Aiuto!  " COLOR(PURPLE) "\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(PURPLE) "Sono nel ventre del grande\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(YELLOW) "Lord Jabu-Jabu  " COLOR(PURPLE) " " COLOR(PURPLE) "      " COLOR(PURPLE) "\n"
COLOR(DEFAULT)  SHIFT("\x18") "--" COLOR(PURPLE) "Ruta" COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C")  COLOR(PURPLE) "PS:Non dirlo a mio padre!" COLOR(DEFAULT) "\"" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chi sei tu? "
BOX_BREAK
UNSKIPPABLE "Noi siamo " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", la fiera\n"
"razza acquatica! "
BOX_BREAK
UNSKIPPABLE "Cosi'...Hai dei legami con \n"
"la Famiglia Reale di Hyrule...           \n"
"Bene, cosa vuoi da noi?        "
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Siamo bravi a nuotare!\n"
"E tu invece? "
BOX_BREAK
"Vuoi diventare un grande nuotatore,\n"
"prova il " COLOR(RED) "Gioco d'Immersione" COLOR(DEFAULT) ",  \n"
"su alla cascata! \n"
"Hai gia' provato forse?   "
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La Fontana Zora é la\n"
"sorgente del fiume.    \n"
COLOR(RED) "Lord Jabu-Jabu" COLOR(RED) " " COLOR(DEFAULT) "vive nella   \n"
"fontana. " TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lord Jabu-Jabu é la divinita' di  \n"
"noi Zoras. La " COLOR(RED) "Principessa Ruta" COLOR(DEFAULT) " ha\n"
"il dovere di preparargli i pasti,\n"
"mattina e sera..."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noi Zoras serviamo il grande \n"
COLOR(RED) "Re Zora" COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il grande Re Zora dovrebbe stare\n"
"nella " COLOR(RED) "Camera Reale" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai visitato Lord Jabu-Jabu? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Come dice la \"Leggenda di Zora\",   \n"
"l'atto di offrire un " COLOR(RED) "pesce" COLOR(DEFAULT) " a Lord \n"
"Jabu-Jabu ti rendera' felice. "
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, malissimo.      "
BOX_BREAK
"Chiunque venga qui deve         \n"
"visitare " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) " almeno\n"
"una volta!"
BOX_BREAK
"La Fontana Zora é proprio dietro\n"
"il trono di Re Zora. E' li' che\n"
"nuota Lord Jabu-Jabu. Ma..."
BOX_BREAK
"Sino a che non avrai il permesso \n"
"del Re, non entrerai nella\n"
"Fontana Zora. "
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non troviamo la " COLOR(RED) "Principessina " COLOR(RED) "\n"
COLOR(DEFAULT) "anche se alcuni di noi l'hanno\n"
"cercata fino al " COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) "...  "
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se avrai qualche indizio\n"
"su dove si trovi la " COLOR(RED) "Principessa\n"
COLOR(DEFAULT) "lo mostrerai al Re Zora?     "
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tutte le acque di Hyrule scorrono\n"
"dalla " COLOR(BLUE) "Fontana Zora" COLOR(DEFAULT) ". "
BOX_BREAK
"Quell'acqua scorre lungo il\n"
"fiume Zora, e alla fine raggiunge il\n"
COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) " a sud.      "
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh--Di nuovo in vita!      "
BOX_BREAK
UNSKIPPABLE "Sei stato tu a salvarmi?\n"
"Grazie figliolo! "
BOX_BREAK
UNSKIPPABLE "Sembra che per te sia difficile\n"
"respirare sott'acqua... "
BOX_BREAK
UNSKIPPABLE "Come espressione di gratitudine,\n"
"ti regalo questa " COLOR(RED) "Tunica" COLOR(DEFAULT) ". Con questa,\n"
"non affogherai sott'acqua."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"La Principessa Ruta é andata \n"
"al Tempio del Lago Hylia da tempo\n"
"ormai...Sono di nuovo...preoccupato!"
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ooh...\n"
"Ho capito...Ma...Hmmmmm...\n"
"Hmmm... " COLOR(RED) "Lacrime" COLOR(DEFAULT) "...  "
BOX_BREAK
UNSKIPPABLE "Potremmo averle, come\n"
"potremmo non averle...         \n"
"Abbiamo gli ingredienti... "
BOX_BREAK
UNSKIPPABLE "Se porti gli " COLOR(RED) "ingredienti" COLOR(DEFAULT) " al dottore\n"
"del laboratorio vicino al lago, \n"
"potra' aiutarti, penso...  "
BOX_BREAK
UNSKIPPABLE "Ma devi consegnarglieli   \n"
"freschi..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ce la farai " COLOR(RED) "prima che si\n"
"guastino" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Allora pensi che marciscano\n"
"prima di arrivare eh?    \n"
"Non é poi cosi' distante, se la fai\n"
"in groppa ad un cavallo... "
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoot hoot!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", sembra che tu \n"
"ci abbia preso la mano, nel tuo\n"
"ruolo di avventuriero...   "
BOX_BREAK
UNSKIPPABLE "Penso che la Principessa\n"
"Zelda stia aspettando una tua visita."
BOX_BREAK
UNSKIPPABLE "Hai gia' con te il " COLOR(RED) "Rubino Goron" COLOR(DEFAULT) ",  " COLOR(RED) "\n"
COLOR(DEFAULT) "vero?     "
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Buongiorno, figliolo. Sto studiando\n"
"dei metodi per ottenere delle\n"
"medicine mischiando le acque del\n"
"lago con altri ingredienti..."
BOX_BREAK
"Forse hai incontrato una donna\n"
"alla Farmacia della citta',\n"
"e' una mia discepola...        \n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Oh, wow!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Non ho visto un " COLOR(RED) "Occhio di Rana" COLOR(DEFAULT) " \n"
"come questo dai tempi della\n"
"glaciazione! " EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, la mia cara " COLOR(RED) "Principessa Ruta" COLOR(DEFAULT) "...\n"
"Dove se n'é andata?\n"
"Sono preoccupato."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho, una lettera!\n"
"E' della " COLOR(RED) "Principessa Ruta" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Hmmm...Vediamo...  \n"
"E' dentro Lord Jabu-Jabu?   \n"
"Non e' possibile!!  "
BOX_BREAK
UNSKIPPABLE "Il nostro Dio, " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) ",\n"
"non mangerebbe mai la mia\n"
"piccola Ruta!  "
BOX_BREAK
UNSKIPPABLE "Ma da quando é arrivato quello\n"
"straniero, " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", a Lord Jabu-Jabu\n"
"gli sono venute le branchie verdi..."
BOX_BREAK
UNSKIPPABLE "Tutto sembra chiaro ora, \n"
"vai pure a cercare la mia Ruta.\n"
"Puoi passare attraverso l'altare \n"
"di Lord Jabu-Jabu.      "
BOX_BREAK
UNSKIPPABLE "Terro' questa lettera.\n"
"Tu tieni pure la " COLOR(RED) "bottiglia" COLOR(DEFAULT) ".\n"
"Con il massimo rispetto!  " TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Per favore trova la mia cara\n"
COLOR(RED) "Principessa Ruta" COLOR(DEFAULT) "... Zora!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Non puoi respirare sott'acqua!\n"
"Se stai soffocando, levati\n"
"gli " COLOR(DEFAULT) "stivali" COLOR(LIGHTBLUE) "!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x36") "Ooooh Noooooo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ohhh, ancora vivo...\n"
"Sei stato tu a salvarmi?\n"
"Stai tranquillo!    "
BOX_BREAK
UNSKIPPABLE "Ti daro' una " COLOR(BLUE) "Tunica Zora" COLOR(DEFAULT) " come  \n"
"segno di riconoscenza. Con questa\n"
"potrai... Cosa?!!      "
BOX_BREAK
UNSKIPPABLE "Ne hai gia' una? Sei veramente\n"
"pronto a tutto!!              "
BOX_BREAK
UNSKIPPABLE "Dal profondo del cuore...grazie\n"
"Ci vuole un BACIO?!! Che? Non lo\n"
"vuoi?! Va bene...  "
BOX_BREAK
UNSKIPPABLE "Se non vuoi i miei regali, almeno\n"
"ascolta i miei guai...      " TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono uno " COLOR(BLUE) "Zora" COLOR(DEFAULT) ", hai visto una\n"
"ragazzina Zora qui intorno?   "
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono uno " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Hai visto\n"
"qualcosa di strano nell'acqua? \n"
"Il fiume ci porta molte cose\n"
"qui nel lago!    "
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sei" QUICKTEXT_ENABLE " in ritardo!! " QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Perché ci hai messo tanto?" QUICKTEXT_DISABLE "\n"
"Sei " QUICKTEXT_ENABLE "inutile!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Ero cosi' sola, questo é tutto...\n"
"Solo un po'!! "
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Avevo paura... " QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Un po'!! " QUICKTEXT_DISABLE " Solo un po'!!  "
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Tu! " QUICKTEXT_DISABLE "\n"
"Sembri in gamba...Piu' di quello\n"
"che pensassi, comunque...    \n"
QUICKTEXT_ENABLE "Solo un po'!! " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Bene, in ogni caso, mi hai salvato\n"
"e ti devo premiare.  "
BOX_BREAK
UNSKIPPABLE "Cosa desideri? Basta dirmelo...  \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Voglio la Pietra Spirituale.\n"
"Nient'altro...   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Intendi la Pietra Spirituale\n"
"dell'Acqua, lo " COLOR(BLUE) "Zaffiro Zora" COLOR(DEFAULT) ", vero?   " TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Me lo diede mia madre e mi disse \n"
"di darlo solo a colui che sarebbe\n"
"divenuto mio marito. Consideralo \n"
"l'Anello di Fidanzamento Zora!     "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x45")  QUICKTEXT_ENABLE "Va bene!  " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Ti daro' la mia cosa piu' preziosa:\n"
"      lo Zaffiro Zora!  "
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Non dirlo a mio padre. "
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hee hee non essere timido!"
BOX_BREAK
UNSKIPPABLE "Credo di sapere cosa stai pensando" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vorrei comprare un pesce, ma    \n"
"costano veramente troppo..."
BOX_BREAK
"Non ho scelta, dovro' catturarne \n"
"uno nelle pozze d'acqua che\n"
"ci sono qui vicino."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, " NAME "!\n"
"Hai salvato la Principessa, eh?\n"
"L'ho apprezzato molto! "
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La mia cosa piu' preziosa ti   \n"
"é stata utile poi? Hee hee!    "
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ciao " NAME "!  \n"
"La Principessa Ruta non ha\n"
"parlato che di te!   "
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, sei tu, " NAME "!  \n"
"Grazie a te, Lord Jabu-Jabu é \n"
"tornato normale! "
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Noi Zoras rispettiamo il grande\n"
"Re Zora! Ha la dignita' di un\n"
"vero re.  Oh si, e' cosi'. "
BOX_BREAK
UNSKIPPABLE "Il grande Re Zora ha una  \n"
"figlia di nome " COLOR(RED) "Ruta" COLOR(DEFAULT) ". E' solo\n"
"una bambina."
BOX_BREAK
UNSKIPPABLE "Ma é una vera monella, e sembra \n"
"stia causando un sacco di guai \n"
"a suo padre, il Re!       " TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eccola qui."
BOX_BREAK
UNSKIPPABLE "Questa medicina non ha alcuna\n"
"controindicazione. Ma non " COLOR(RED) "durera' \n"
"a lungo" COLOR(RED) " " COLOR(DEFAULT) "a questa temperatura. "
BOX_BREAK
UNSKIPPABLE "Corri piu' che puoi alla\n"
"Montagna della Morte.\n"
"Sei giovane, ce la farai!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo! Sembra tu sia gia'\n"
"divenuto piu' grande e forte,    \n"
NAME "!"
BOX_BREAK
UNSKIPPABLE "Benvenuto nelle " COLOR(BLUE) "Terre dei Zoras" COLOR(DEFAULT) ".\n"
"I Zoras sono alleati della Famiglia\n"
"Reale, proteggono le fonti d'acqua. "
BOX_BREAK
UNSKIPPABLE "La loro porta si apre solo per\n"
"coloro che hanno legami con\n"
"la Famiglia Reale di Hyrule.   \n"
"    "
BOX_BREAK
UNSKIPPABLE "Fagli ascoltare la\n"
COLOR(RED) "Melodia della Famiglia Reale" COLOR(DEFAULT) "!\n"
"Hoooo hoo hoooot!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando ritornerai di nuovo,\n"
"non dimenticare di portarmi\n"
"un souvenir!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Trovi la Principessa Ruta!\n"
"Ora Re Zora ti dara' la   \n"
COLOR(BLUE) "Pietra Spirituale dell'Acqua" COLOR(DEFAULT) "...\n"
"Beh, forse.."
BOX_BREAK
UNSKIPPABLE "Huh?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La sua cosa piu' preziosa?   \n"
"Non hai capito di cosa parlasse,  \n"
"ma ora hai ottenuto ben due    \n"
"Pietre Spirituali! Ne manca una! "
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La sua cosa piu' preziosa?\n"
"Non hai capito di cosa parlasse ma,  \n"
"alla fine ce l'hai fatta. Hai tutte e\n"
"tre le Pietre Spirituali!"
BOX_BREAK
UNSKIPPABLE "Torna dalla Principessa Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ci si rivede, " NAME "... "
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Questo ghiaccio é stato creato\n"
"da una maledizione...Il mostro del\n"
COLOR(BLUE) "Tempio dell'Acqua" COLOR(DEFAULT) " ne é la causa.."
BOX_BREAK
UNSKIPPABLE "Solo se lo sconfiggerai, il\n"
"ghiaccio si sciogliera'...       "
BOX_BREAK
UNSKIPPABLE "Se hai abbastanza coraggio da\n"
"sfidare il pericolo e salvare \n"
"gli Zoras, ti insegnero' la   \n"
"melodia che conduce al tempio...  "
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il tempo passa, la gente va via...  \n"
"Come un fiume senza fine...  "
BOX_BREAK
UNSKIPPABLE "Il sogno di un bambino diviene\n"
"una ambizione...Giovani amori\n"
"divengono affetti profondi...Tutto\n"
"si riflette sulle chiare acque...    "
BOX_BREAK
UNSKIPPABLE "Ora ascolta la\n"
COLOR(BLUE) "Serenata dell'Acqua" COLOR(DEFAULT) "\n"
"riflettersi anche su di te... "
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se sei venuto a cercare gli  \n"
"Zoras, hai perso del tempo... \n"
"Questo é cio' che resta..."
BOX_BREAK
UNSKIPPABLE "Con una sola eccezione, gli\n"
"Zoras sono sigillati sotto questi\n"
"ghiacci... "
BOX_BREAK
UNSKIPPABLE "Ho liberato la Principessa\n"
"Zora dalla prigione di ghiaccio, ma...\n"
"Se n'é andata al " COLOR(BLUE) "Tempio dell'Acqua" COLOR(DEFAULT) "...    "
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se vuoi comprare il pesce, ti serve\n"
"un contenitore adatto.   " EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hai detto che vuoi una " COLOR(BLUE) "Tunica \n"
"Zora" COLOR(DEFAULT) "? E' fatta di materiali     \n"
"molto preziosi, e pertanto é  \n"
"esageratamente costosa!  "
BOX_BREAK
"Infatti, mi dispiace, ma solo una\n"
COLOR(RED) "famiglia molto ricca di Kakariko " COLOR(DEFAULT) "puo'\n"
"acquistare questa tunica.." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh...Ma...Sei proprio tu...\n"
NAME "?!"
BOX_BREAK
UNSKIPPABLE  NAME ", sei tu non é\n"
"vero?"
BOX_BREAK
UNSKIPPABLE "Sono la tua fidanzata, " COLOR(BLUE) "Ruta" COLOR(DEFAULT) "!\n"
"Principessa Zoras!    "
BOX_BREAK
UNSKIPPABLE "Non ho mai dimenticato il nostro \n"
"giuramento di sette anni fa!!"
BOX_BREAK
UNSKIPPABLE "Sei stato crudele a lasciarmi qui\n"
"ad aspettare, per sette    \n"
"lunghi anni..."
BOX_BREAK
UNSKIPPABLE "Ma ora non é il momento\n"
"di pensare all'amore..."
BOX_BREAK
UNSKIPPABLE "Avrai gia' visto i nostri regni...\n"
"Una vera glaciazione!!     "
BOX_BREAK
UNSKIPPABLE "Un giovane di nome" COLOR(RED) " Sheik" COLOR(DEFAULT) " mi ha\n"
"salvato dai ghiacci...  "
BOX_BREAK
UNSKIPPABLE "Ma mio padre e altri Zoras non\n"
"ce l'hanno.." TEXT_SPEED("\x02") "...fatta." TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Li voglio salvare tutti!\n"
"Voglio salvare la razza Zora!"
BOX_BREAK
UNSKIPPABLE "Tu! Tu devi aiutarmi!    \n"
"Questa é una richiesta della  \n"
"donna che diverra' tua moglie!     "
BOX_BREAK
UNSKIPPABLE  NAME ", devi aiutarmi a distruggere\n"
"il malefico mostro del Tempio, OK?!  "
BOX_BREAK
UNSKIPPABLE "All'interno del Tempio, ci sono    \n"
COLOR(RED) "tre posti" COLOR(DEFAULT) " dove puoi cambiare\n"
"il livello dell'acqua."
BOX_BREAK
UNSKIPPABLE "Ti ci portero' io.\n"
"Seguimi, di corsa!! "
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! Attento! \n"
"Non é acqua normale quella!! \n"
"      "
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "..."
BOX_BREAK
UNSKIPPABLE "Non mi aspettavo niente di\n"
"meno dall'uomo che ho scelto\n"
"come marito."
BOX_BREAK
UNSKIPPABLE "I territori e la gente Zora,\n"
"ritorneranno al loro status    \n"
"originale...   "
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Se vedi Sheik,\n"
"per favore ringrazialo per me, OK?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ruta voleva ringraziarmi? "
BOX_BREAK
UNSKIPPABLE "Vedo.... "
BOX_BREAK
UNSKIPPABLE "Dobbiamo riportare la pace\n"
"ad Hyrule anche per lei.   \n"
"Giusto?  "
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, vedo... \n"
"La Principessa Ruta é andata al\n"
"Tempio..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Come premio...\n"
"avrai il mio amore eterno...   "
BOX_BREAK
UNSKIPPABLE "Bene, questo é cio che volevo dire,\n"
"ma non penso che posso farlo    \n"
"ora."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La Principessa Zelda...é viva.\n"
"Posso sentirlo...\n"
"Non demordere ora...   "
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Eeeeyaaaah!\n"
SHIFT("\x0F") "Cos'é questo?! Una piovra?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Devo controllare il Tempio\n"
"dell'Acqua come" COLOR(BLUE) " Saggio dell'Acqua" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "E tu...Tu stai cercando la \n"
"Principessa, " COLOR(RED) "Zelda" COLOR(DEFAULT) "? "
BOX_BREAK
UNSKIPPABLE "Hah!\n"
"Non puoi nascondermi niente!!   "
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Posso dirti che niente ti fermera'\n"
"nella tua ricerca della giustizia\n"
"e della pace...Prendi questo\n"
COLOR(BLUE) "Medaglione" COLOR(DEFAULT) "...Con il mio amore!    "
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tu! Chi sei tu?!"
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(RED) "Ruta" COLOR(DEFAULT) ", Principessa degli Zoras."
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Cosa?!" QUICKTEXT_DISABLE "\n"
"Dici che mio padre ti ha chiesto\n"
"di venire qui a salvarmi?  "
BOX_BREAK
UNSKIPPABLE "Non " QUICKTEXT_ENABLE "ho mai" QUICKTEXT_DISABLE " chiesto\n"
"a nessuno di farlo!  "
BOX_BREAK
UNSKIPPABLE "\"Lettera in Bottiglia\"? Non  \n"
QUICKTEXT_ENABLE "ho idea" QUICKTEXT_DISABLE " di cosa tu stia parlando! "
BOX_BREAK
UNSKIPPABLE "Mio padre é arrabbiato con me?"
BOX_BREAK
UNSKIPPABLE "Non mi" QUICKTEXT_ENABLE " importa" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Comunque, non posso andare a casa\n"
"ora. E tu..." QUICKTEXT_ENABLE "Vattene via!!  " QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Hai capito?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Stai ancora girando qui intorno?\n"
"Ti ho detto di andartene!"
BOX_BREAK
UNSKIPPABLE "Sto bene. Sono entrata nella\n"
"pancia di Lord Jabu-Jabu sin da  \n"
"piccola, ma...  "
BOX_BREAK
UNSKIPPABLE "Lord Jabu-Jabu é\n"
"molto strano oggi...   "
BOX_BREAK
UNSKIPPABLE "Ci sono meduse elettrificate e     \n"
"strani buchi in giro..."
BOX_BREAK
UNSKIPPABLE "Ma soprattutto, la mia preziosa\n"
"pietra...Ma... \n"
QUICKTEXT_ENABLE "Non sono affari tuoi!!     " QUICKTEXT_DISABLE "\n"
"Comunque..."
BOX_BREAK
UNSKIPPABLE "Tu! " QUICKTEXT_ENABLE "Vai a casa!  " QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Hai capito?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sei ancora arrabbiato con me?"
BOX_BREAK
UNSKIPPABLE "Allora ti daro' l'onore di    \n"
"trasportarmi!  "
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Comunque" QUICKTEXT_DISABLE "...Non andro' via sino a\n"
"che non ritrovero' cio' che sto\n"
"cercando. Credimi!!     " EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Che sconsiderato! " QUICKTEXT_DISABLE "\n"
"Come hai potuto lasciarmi indietro?!\n"
"Se se sei un uomo, comportati\n"
"da uomo almeno!!  " EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "E' lei!!  " QUICKTEXT_DISABLE "\n"
"Questa é quella che cercavo!!    \n"
"Lanciami li' sopra! \n"
"Sulla piattaforma!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "La Principessa ha la\n"
COLOR(BLUE) "Pietra Spirituale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Ma." TEXT_SPEED("\x00") "..Non serviva a te?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh Sacre Dee,\n"
"L'ho ritrovata! \n"
"La pietra di mia madre..."
BOX_BREAK
UNSKIPPABLE "Ero cosi' triste quando Lord Jabu\n"
"Jabu l'inghiotti'..."
BOX_BREAK
UNSKIPPABLE "Poi, mentre lo stavo nutrendo\n"
"inghiotti' pure me! Ero   \n"
"cosi' confusa che volli restare... "
BOX_BREAK
UNSKIPPABLE "Ma, ora che l'ho ritrovata,\n"
"Non voglio piu' restare\n"
"qui dentro!   "
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Percio', riportami a casa!  "
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gioco Immersione   20 Rupié \n"
"Giochi? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "OKAY!" QUICKTEXT_DISABLE
BOX_BREAK
"Prendi tutte le Rupié che tirero'  \n"
"da qui. Hai un limite di tempo\n"
"da rispettare! "
BOX_BREAK
"Se riesci a prenderle tutte,\n"
"ritorna qui!\n"
"Ti daro' qualcosa di utile!         " EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ehi! Congratulazioni! " QUICKTEXT_DISABLE "\n"
"Ho qui qualcosa di\n"
"molto utile per te!\n"
"Vieni su adesso!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma che bel tuffo!!   \n"
"Ora, prendi questa!   "
BOX_BREAK
UNSKIPPABLE "E' una \"" COLOR(RED) "scaglia" COLOR(DEFAULT) "\" degli Zoras. \n"
"Con questa, potrai immergerti\n"
"piu' a fondo.         " EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Cosi' come l'acqua risale,\n"
"dal lago svanisce ogni male...\n"
"Ce l'hai fatta! "
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Io...credo che riuscirai a salvare\n"
"questo mondo...   "
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Guarda bene, " NAME "... "
BOX_BREAK
UNSKIPPABLE "Tu e la Principessa Ruta, insieme\n"
"avete sconfitto il mostro!"
BOX_BREAK
UNSKIPPABLE "Ancora una volta, acqua pura riempie\n"
"il lago. Tutto ritorna com'era..."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(RED) "VIA!  " COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Usa la cascata come scorciatoia. " EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prendi piu' Rupié che puoi per\n"
"20 Rupié. Vuoi giocare? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ehi! Congratulazioni!! " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Vorresti dei " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "?\n"
"Non si vendono parecchio...    "
BOX_BREAK
"Che dici....\n"
COLOR(RED) "10 Rupié " COLOR(DEFAULT) "per un pezzo?  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Vorresti dei " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "?\n"
"Non sono ancora molto popolari... "
BOX_BREAK
"Che dici... \n"
COLOR(RED) "20 Rupié " COLOR(DEFAULT) "per un pezzo?  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Vorresti dei " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "?\n"
"Cominciano a essere popolari\n"
"adesso... "
BOX_BREAK
COLOR(RED) "30 Rupié " COLOR(DEFAULT) "per un pezzo?  \n"
"Che ne dici? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Vorresti dei " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "?\n"
"Ora costano un po'! "
BOX_BREAK
COLOR(RED) "40 Rupié " COLOR(DEFAULT) "per un pezzo.  \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Abbiamo i popolari " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "!\n"
"Ti dispiacera' non averli\n"
"comprati ora!   "
BOX_BREAK
COLOR(RED) "50 Rupié " COLOR(DEFAULT) "per un pezzo.  \n"
"(Solo per ora) \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Questi sono i super-popolari\n"
COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "! Se sei sorpreso, \n"
"sappi che sono in svendita!  "
BOX_BREAK
"Super prezzo!!\n"
COLOR(RED) "60 Rupié " COLOR(DEFAULT) "per un pezzo!  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Abbiamo i rarissimi \n"
COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "!\n"
"Puo' essere l'ultima occasione!"
BOX_BREAK
"Prezzo speciale\n"
COLOR(RED) "70 Rupié" COLOR(DEFAULT) " per un pezzo! \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Abbiamo i leggendari " COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "!\n"
"Li vendo solamente a te! "
BOX_BREAK
"Super prezzo! \n"
COLOR(RED) "80 Rupié " COLOR(DEFAULT) "per un pezzo!  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Vuoi forse i..." COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "?\n"
"Non costano poco, ma...\n"
"Li vuoi lo stesso?    "
BOX_BREAK
"Non li posso vendere a meno di  \n"
COLOR(RED) "90 Rupié " COLOR(DEFAULT) "al pezzo!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Abbiamo..." COLOR(RED) "Fagioli Magici" COLOR(DEFAULT) "!\n"
"Li vuoi...Huh? Huh?       "
BOX_BREAK
COLOR(RED) "100 Rupié " COLOR(DEFAULT) "per un pezzo!  \n"
"Keyahahah!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah ecco...\n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non hai abbastanza soldi.   \n"
"Non te li posso vendere. \n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Assegnalo a " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e piantalo nel \n"
"terreno li' a destra"
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, peccato! Tutto venduto! \n"
"Chomp chomp...Cosa?\n"
"Ah, questi ultimi li mangio io!  "
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se vuoi piantare i fagioli, cerca\n"
"in giro del terreno soffice.\n"
"Chomp chomp chomp"
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"solo fino a " COLOR(RED) "1 metro" COLOR(DEFAULT) ". Non é certo \n"
"una vera immersione. ."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"solo fino a " COLOR(RED) "2 metri" COLOR(DEFAULT) ". Non é certo \n"
"una vera immersione.   "
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"solo fino a " COLOR(RED) "3 metri" COLOR(DEFAULT) ". Non é certo \n"
"una vera immersione.   "
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"solo fino a " COLOR(RED) "4 metri" COLOR(DEFAULT) ". Ancora\n"
"troppo poco!  "
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"solo fino a " COLOR(RED) "5 metri" COLOR(DEFAULT) ".Ancora \n"
"troppo poco!  "
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso \n"
"solo fino a " COLOR(RED) "6 metri" COLOR(DEFAULT) ". Dovresti\n"
"riuscire a fare di piu'!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forse non lo hai notato, ma ti ho\n"
"controllato. Ti sei immerso  \n"
"fino a " COLOR(RED) "7 metri" COLOR(DEFAULT) " ora. Dovresti    \n"
"andare piu' a fondo!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Forse non lo hai notato, ma ti ho\n"
"controllato. Stavolta hai " COLOR(RED) "toccato\n"
"il fondo" COLOR(DEFAULT) "!!  Bravissimo!!       \n"
"Ti daro' questa cosa! "
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il tuo stile é il migliore al \n"
"mondo. Perché non ti immergi sul  \n"
"fondo del Lago Hylia?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mi chiamo " COLOR(RED) "Pierre" COLOR(DEFAULT) ", lo spaventa-\n"
"passeri vagabondo. Vorrei tanto andare\n"
"alla ricerca di melodie commoventi,\n"
"ma, come vedi, sono bloccato."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Fantastica!\n"
"Mi ha colpito al cuore!! " EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se conosci una bella canzone,\n"
"ritorna e fammela ascoltare!    " EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quella canzone che hai suonato\n"
"resta nel mio cuore.\n"
"Rifammela ascoltare! " EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quella canzone che suonasti\n"
"mi colpi' molto!!  " EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ciao piccolo, ti va di pescare  \n"
"per " COLOR(RED) "20 Rupie'" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, no! Stai giocando con un \n"
COLOR(RED) "Emulatore N64" COLOR(DEFAULT) "! Mi dispiace\n"
"ma niente effetti di forza sui\n"
"tasti del PC!"
BOX_BREAK
"Puoi comprarti l'N64 e Zelda, pero'." EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi! hai il     " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Spiegami, come hai fatto sul PC?!,\n"
"MAGO!!!!!!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Accidenti!!\n"
"Non ti bastano i soldi!  "
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OK, ascoltami!"
BOX_BREAK
"Cammina lungo il bordo del lago\n"
"premi " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " e scegli un pesce."
BOX_BREAK
"Una volta individuato, potrai  \n"
"tirare la lenza con " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".\n"
"Premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e blocca la lenza.  "
BOX_BREAK
"Quando l'esca cade nell'acqua\n"
"potrai agitarla muovendo " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".     \n"
"Se sei un novellino,\n"
"potrai usare " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".   "
BOX_BREAK
"Ritira l'esca con " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Tieni     \n"
"premuto " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "[R]" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "per ritirare \n"
"veloce."
BOX_BREAK
"Se abbocca, allora premi " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) " \n"
"e " COLOR(LIGHTBLUE) "[Control-Pad] giu' " COLOR(DEFAULT) "per allamarlo.  \n"
"Infine, portalo a riva con " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". "
BOX_BREAK
"Hai capito tutto? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono generoso, e ti lascio pescare\n"
"per tutto il tempo che vuoi. Ma, \n"
"puoi tenere un solo pesce. "
BOX_BREAK
"Il pesce piu' grosso mai preso qui\n"
"pesava " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "."
BOX_BREAK
"Dopo il lancio, puoi cambiare\n"
"visuale premendo " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "."
BOX_BREAK
SHIFT("\x41") "SiiiiPesca!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah ha haah!\n"
"Hai allamato il pesce premendo  \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "[Control-Pad] giu'" COLOR(DEFAULT) "?  "
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, non ci riesci?\n"
"L'hai perso!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, bene...Pesa circa " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) ".  \n"
"Lo vuoi tenere?        \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Che cosa vuoi?   \n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Pesa il pesce.\n"
"Parliamo un po' di...      \n"
"Me ne vado.    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Con la sola passione non  \n"
"prenderai molti pesci!     "
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "WHOA!"
BOX_BREAK
"Ma questo e' enorme!\n"
"Sembra sia il nuovo record!\n"
"Pesa la bellezza di " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "!\n"
"Grandioso! Ok, eccoti il premio!   " EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa? \n"
"Ma cosa mi stai facendo?! " FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, ragazzino!\n"
"Ma non hai proprio nient'altro  \n"
"di importante da fare?"
BOX_BREAK
"Cosa? Dici che ti diverti di piu'\n"
"a giocare qui? "
BOX_BREAK
"Ne ho visti tanti rovinare la \n"
"loro vita con quest'atteggiamento. \n"
"Non scherzo!\n"
"Va bene..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Il piu' grosso pesce mai  \n"
"catturato qui pesava " FISH_INFO " chili.   \n"
"Pescato da: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi continuare a pescare?      \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, pesa circa " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "...\n"
"Non e' male, ma ce ne sono di\n"
"piu' grossi!  " EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"E dai! Non hai nemmeno un pesce!  \n"
"Puaaah!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi cambiare la tua esca?   \n"
"Ma di cosa stai parlando?  \n"
"Sei cosi' egoista? "
BOX_BREAK
"Non lo sai che il saggio dice:\n"
"\"Un grande pescatore non sceglie\n"
"mai l'esca\"?  "
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa? Vuoi conoscere i segreti \n"
"della pesca? Non te ne diro'  \n"
"nemmeno uno. Sono della ditta.   \n"
"Sul serio!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa? Vuoi sapere se sono\n"
"un buon pescatore?    "
BOX_BREAK
"Certo! Un vero professionista! \n"
"E lo sai da cosa si vede? \n"
"Dico sempre la verita'!!  "
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leggi e Regolamenti: " QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Non usare esche da fondo\n"
"2. Fai silenzio \n"
"3. Cammina piano" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "4. Attento quando lanci " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow! Una bel bestione!\n"
"Vediamo...pesa...\n"
"circa... " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "! "
BOX_BREAK
"Lo vuoi tenere?        \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ritorna quando sarai grande! \n"
"Anche il pesce sara' piu' grosso...\n"
"Credo..."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, tu! Mi ricordo di te!\n"
"E' stato tanto tempo fa!"
BOX_BREAK
UNSKIPPABLE "Sono passati quanti anni?  \n"
"Sette anni?! Cosa hai fatto\n"
"in tutto questo tempo?!   "
BOX_BREAK
UNSKIPPABLE "Sei il mio solo cliente.\n"
"Sono fuori dagli affari! \n"
"Non scherzo!\n"
UNSKIPPABLE "E al di sopra, i capelli..."
BOX_BREAK
UNSKIPPABLE "Uh, dicevo, non ricordo.."
BOX_BREAK
UNSKIPPABLE "Bene, allora vuoi pescare?    \n"
"Ti costera' solo" COLOR(RED) " 20 Rupie" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa?"
BOX_BREAK
"Vuoi andare a pescare da una\n"
"altra parte?!!          \n"
"Ma cosa dici? Io vado fallito   \n"
"se te ne vai da qualunque   \n"
"altra parte!   \n"
"Non scherzo!"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa?"
BOX_BREAK
"Vuoi sapere perché resto\n"
"qui a grattarmi tutto il tempo?\n"
"Ma di cosa parli?    "
BOX_BREAK
"Per ora, non ne ho idea. \n"
"Seriamente! "
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa?"
BOX_BREAK
"Stai provando a dirmi che non\n"
"puoi vedere i pesci perché  \n"
"l'acqua e' sporca?"
BOX_BREAK
"Ma cosa cavolo stai dicendo?\n"
"Quest'ora é il momento    \n"
"migliore per pescare! "
BOX_BREAK
"Puoi pescare un pesce proprio \n"
"quando meno te lo aspetti.     \n"
"Ora é eccitante!   "
BOX_BREAK
"Sul serio. Davvero, credimi!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, cosa stai facendo? \n"
"Ti ho detto di non farlo! \n"
"Sei terribile!  \n"
"Davvero!  "
BOX_BREAK
"Ridammi il cappello!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No no " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Cosa? Huh? Oh?\n"
"Penso che il pesce che hai \n"
"appena preso e' piu' grosso...   "
BOX_BREAK
"Lo vuoi tenere lo stesso?    \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No, non lo voglio  \n"
"Si, lo tengo in ogni caso    " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Gosh! Ma che strano pesce hai \n"
"appena preso!  al massimo potra' \n"
"pesare " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "! "
BOX_BREAK
"Che cosa te ne vuoi fare?      \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Lo tengo      \n"
"Non lo voglio  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow!"
BOX_BREAK
"E' proprio cio' che penso?\n"
"Stupefacente!\n"
"Recuperi un  " COLOR(RED) "Esca da fondo" COLOR(DEFAULT) "!"
BOX_BREAK
"Cosa pensi di poterci fare?    \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Usala ora..\n"
"Sbarazzatene. " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, bene..."
BOX_BREAK
"WOW! Ma e' molto raro!\n"
"E'un " COLOR(RED) "Persico di Hyrule" COLOR(DEFAULT) "!"
BOX_BREAK
"Per questo pesce, non conta \n"
"la misura. Ti daro' questo\n"
"premio!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Di recente, il numero di   \n"
"questi pesci si é notevolmente \n"
"ridotto, questo lo rilascero'.      " EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leggi e Regolamenti: \n"
"1. Niente esche da fondo\n"
"2. Fare silenzio\n"
"3. Camminare piano " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi! Ehi!\n"
"Non ti puoi portare\n"
"via la canna!  "
BOX_BREAK
"Finito di pescare,           \n"
"la canna va restituita. \n"
"Non scherzo!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh mio Dio!\n"
"Questo e' E-N-O-R-M-E!!"
BOX_BREAK
"Un pesce di questa misura non \n"
"entra nemmeno sullo shermo, non lo \n"
"posso pesare per bene ma sembra   \n"
"circa " COLOR(RED)  FISH_INFO " chili" COLOR(DEFAULT) "!! "
BOX_BREAK
"Che dici te lo vuoi tenere,\n"
"o no?   \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Tienilo\n"
"Buttalo via  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi! \n"
"Sono " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", lo spaventapasseri!\n"
"Avrai sentito della mia    \n"
"fantasica memoria! "
BOX_BREAK
"Se conosci un nuovo motivo,\n"
"suonalo ora!"
BOX_BREAK
"Questa é la canzone dell'altra\n"
"volta, piccolo!"
BOX_BREAK
"Preso!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono " COLOR(RED) "Bonooru" COLOR(DEFAULT) ",\n"
"spaventapasseri musicista!   \n"
"Sento una canzone,\n"
"e non me la dimentico piu'!  "
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Suona il solito motivo\n"
"e chiamerai Pierre!\n"
"Se é vicino, verra' ad  \n"
"aiutarti, bello! "
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi! Non sei tu il tizio fatato  \n"
"di tanto tempo fa?  \n"
"Wow, sei cresciuto! "
BOX_BREAK
"La tua canzone era...    "
BOX_BREAK
"Cosa?"
BOX_BREAK
"No, Io NON dimentico!\n"
"Casomai TU avrai dimenticato...\n"
"Non é vero? Se hai con te\n"
"l'Ocarina, suona la canzone!    "
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Whoa! Hai una ocarina!    \n"
"Hey, perché non suoni un motivo\n"
"su di me, bello?!  " EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene...Bella!! \n"
"La ricordero' per te,\n"
"per sempre! "
BOX_BREAK
"Non intendo dire che ricordero'\n"
"solo le otto note... ma lasciamo    \n"
"stare per ora, bello!     " EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Suonala a quel modo e questo\n"
"cuore di spaventapasseri non si\n"
"muovera'" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OH YEAHHH!!\n"
"E' questo, questa é musica!!\n"
"Vero rock! Mi esalta!!    "
BOX_BREAK
"Oh, no, no! Non ho dimenticato\n"
"la canzone...Non scordo niente! \n"
"Ma mi sento di ricompensarti, \n"
"bellezza! "
BOX_BREAK
"........\n"
"Ho una buona idea! "
BOX_BREAK
"Il mio amico Pierre vagabonda\n"
"qui in giro, percio' suona la\n"
"melodia per chiamarlo!"
BOX_BREAK
"Gli chiedero' di aiutarti se é\n"
"vicino e sente la tua canzone!     " EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, é l'Ocarina! \n"
"Suona quella canzone, allora!\n"
"   " EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Giovanotto, suoni bene\n"
"l'Ocarina, eh...Mmmmmm...!\n"
"Una melodia splendida...DueGambe!\n"
"Dovremo fare pratica, duegambe!   "
BOX_BREAK
"Prendi queste Rupié!      \n"
"Se ritornerai con una altra bella\n"
"melodia, vieni pure a suonarla \n"
"...Duecra DueGambe!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Wow, che splendida melodia!\n"
"DueGambe!"
BOX_BREAK
"Siiiiingin' in the raaaaaain,\n"
"Che feeling!       \n"
"DuuueGaaambe!!"
BOX_BREAK
"Prego, prendi questo segno  \n"
"della nostra gratitudine anfibia!\n"
"Va bene. Ciao, DueGambe!   " EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Guardaci, siamo rane enormi!      \n"
"Siamo il Favoloso Quintetto dei \n"
"Tenori Ranocchioni!!  \n"
"DuuueGambe!"
BOX_BREAK
"Facci saltare, cosi' possiamo\n"
"nutrirci degli insetti!    b   "
BOX_BREAK
"OK? \n"
"Allora, pronti, via! " EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Giovanotto, sei in gambaaa!\n"
"Brrrraaavoo!\n"
"Siamo piene, ora!   "
BOX_BREAK
"Accetti questo segno della\n"
"nostra gratitudine?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah bravo, ma non mi ricordo questa\n"
"canzone.\n"
"Perché? Questo proprio non lo so\n"
"Diamine!    "
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Il pesce piu' grande mai catturato  \n"
"qui pesava " FISH_INFO " chili. \n"
"Pescato da : Il Proprietario" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa?\n"
"Vuoi pescare con un esca   \n"
"differente?    \n"
"...Ehi, cos'é quella?"
BOX_BREAK
"Cosa? L'hai raccolta qui?\n"
"Di solito, le regole dicono che non\n"
"puoi usare uno di questi. Di solito.\n"
"Ma, che diavolo...  "
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAHOOOOOO!\n"
"E' ENORME!! Un nuovo record!!\n"
"Questo...pesa piu' o meno...    \n"
COLOR(RED)  FISH_INFO " chili" COLOR(RED) "!! "
BOX_BREAK
"Maaaaaaaa! Quel tipo di esca viola\n"
"le regole del laghetto!\n"
"Percio', niente premio.\n"
"Waah ha ha ha ha! " EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Il piu' grosso pesce catturato\n"
"nel laghetto pesava " FISH_INFO " chili.\n"
"Pescatore:  " NAME "\n"
"(NOTA: Preso con un esca illegale)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei un ragazzo di cuore!  \n"
"Ma non dirlo a nessuno.       \n"
"Seriamente!  " EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"COOOOOSA?!?"
BOX_BREAK
"Perché mi stai facendo questo?\n"
"Cosa credi?          "
BOX_BREAK
"Non ti lascero' andare tanto    \n"
"facilmente! Mi devi pagare ben  \n"
COLOR(RED) "50 Rupié " COLOR(DEFAULT) "ora!\n"
"Sul serio! " EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "GYAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Tu " QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "assass" QUICKTEXT_DISABLE "i" QUICKTEXT_ENABLE "no!! " QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Huh? Oh, sei tu. "
BOX_BREAK
"Hai poi suonato la\n"
COLOR(YELLOW) "Canzone del Sole" COLOR(DEFAULT) "? "
BOX_BREAK
"Come ti ho detto, con quella\n"
"canzone, puoi cambiare il giorno in\n"
"notte o viceversa, quando lo\n"
"desideri."
BOX_BREAK
"Quando sarai nelle tenebre, con\n"
"quella melodia tornera' la luce\n"
"del sole. Dovresti provare."
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Scavai una buca, e trovai un\n"
"tesoro che si accorcia e--BOING!\n"
"si allunga --BOING! E' divertente.\n"
"Non lo daro' mai a nessuno!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"E' il " COLOR(RED) "Diario del custode" COLOR(DEFAULT) ".       \n"
"Vuoi proprio leggerlo? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Chiunque legga questo, entri nella\n"
"mia tomba. Potra' avere il mio\n"
COLOR(RED) "tesoro" COLOR(DEFAULT) " allungante, a molla!!\n"
"  " QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Ti sto aspettando.  \n"
"--Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Decidi di non leggerlo...   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Hai sconfitto lo Spettro Poe!"
BOX_BREAK
"Vuoi catturarlo nella   \n"
"bottiglia?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vuoi catturarlo ma purtroppo\n"
"non hai una bottiglia vuota."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Per ora non lo prendi."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Hai preso un Poe!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x04") "Brace d'inverno i capelli tuoi,    \n"
SHIFT("\x19") "dove il mio cuore brucia..." QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x05") "Dal sole alla luna, dalla luna.." QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x25") "..al sole. Riposino  \n"
SHIFT("\x37") "in pace...      " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Interessante come poema...    \n"
"Huh?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Anime senza pace vagano\n"
SHIFT("\x2E") "senza fermarsi mai,  \n"
SHIFT("\x34") "le calmerai con la\n"
SHIFT("\x33")  COLOR(YELLOW) "Canzone del Sole" COLOR(DEFAULT) ". " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Qualcosa é inciso sulla pietra\n"
"tombale...  "
BOX_BREAK
UNSKIPPABLE "E' una " COLOR(YELLOW) "Melodia segreta" COLOR(DEFAULT) " dei    \n"
"Fratelli Battisti!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pozione Finale!\n"
"Costa ben " COLOR(RED) "100 Rupié" COLOR(DEFAULT) "!  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se cambi idea, torna pure a   \n"
"trovarmi...         \n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non hai abbastanza Rupié!    \n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "GYAAAAH!\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "MI " QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "HAI" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "UCCISO..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  QUICKTEXT_ENABLE "Incredibile! " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Ma, cosa?\n"
"Tu non sei uno sgherro di\n"
"Ganondorf vero?   "
BOX_BREAK
UNSKIPPABLE "A causa del mio ruolo di spettro,\n"
"devo comportarmi cosi'. Scusami. "
BOX_BREAK
UNSKIPPABLE "Ora lascia che mi presenti...     \n"
"Ahem..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Io sono il fantasma di uno dei\n"
"fratelli compositori di Kakariko."
BOX_BREAK
"Tutti gli abitanti del villaggio\n"
"sono al servizio della Famiglia   \n"
"Reale. "
BOX_BREAK
"Anche noi fratelli compositori lo\n"
"eravamo, e fummo assegnati allo\n"
"studio dei poteri mistici\n"
"ereditati dalla Famiglia."
BOX_BREAK
"Non ci rendevamo conto del grande\n"
"potere della Triforza,  "
BOX_BREAK
"e dedicavamo i nostri studi al\n"
COLOR(RED) "controllo del Tempo" COLOR(DEFAULT) " con le note  \n"
"di una Ocarina... "
BOX_BREAK
"Uh, cioe'... "
BOX_BREAK
"Adesso, abbiamo completato gli \n"
"studi!"
BOX_BREAK
"Saremmo stati famosi, se\n"
"quell'odioso di Ganondorf non\n"
"avesse rubato il nostro lavoro.  "
BOX_BREAK
"Non dovevamo permettergli di\n"
"sfruttare la nostra ricerca!"
BOX_BREAK
"Abbiamo dato la vita per proteg-\n"
"gere il segreto!   " TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi risentire cio' che ho \n"
"detto?     \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "MORTO" QUICKTEXT_ENABLE "DI.." QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "NUOVOOO!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Cosa? Ancora Tu?"
BOX_BREAK
UNSKIPPABLE "Mi ricordi tanto la...\n"
"Principessa Zelda...   "
BOX_BREAK
UNSKIPPABLE "Hmm... Poiche' sembri avere dei\n"
"legami con la Famiglia Reale, ti\n"
"diro' qualcosa della nostra storia. \n"
"     "
BOX_BREAK
UNSKIPPABLE "Una volta, la gente ci definiva\n"
"grandi compositori per il gran numero\n"
"di sinfonie che scrivemmo"
BOX_BREAK
UNSKIPPABLE "Ma noi due non eravamo solo\n"
"compositori. "
BOX_BREAK
UNSKIPPABLE "Avevamo l'incarico di analizzare\n"
"i misteriosi poteri della\n"
"Famiglia Reale. "
BOX_BREAK
UNSKIPPABLE "Il nostro nome potrebbe far\n"
"parte della storia se completassimo\n"
"le nostre ricerche!"
BOX_BREAK
UNSKIPPABLE "Abbiamo tenuto i nostri studi\n"
"segreti fino alla fine...  " TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "MORTO" QUICKTEXT_ENABLE " DI " QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "NUOVOOO!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Cosa? Ancora Tu?"
BOX_BREAK
UNSKIPPABLE "Mi ricordi la Principessa\n"
"Zelda, comunque"
BOX_BREAK
UNSKIPPABLE "Poiché sembri avere dei legami\n"
"con la Famiglia Reale, ti diro' \n"
"qualcosa in piu' della nostra    \n"
"storia." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A dire la verita', ognuno di\n"
"noi studiava un motivo diverso, uno\n"
"per " COLOR(RED) "invocare il sole" COLOR(DEFAULT) " e uno per \n"
COLOR(RED) "invocare la luna" COLOR(DEFAULT) "."
BOX_BREAK
"Se sei realmente un membro   \n"
"della Famiglia Reale, ti svelero' \n"
"i risultati dei nostri studi.    \n"
"     "
BOX_BREAK
"Abbiamo inscritto sulla " COLOR(RED) "Tomba\n"
"Reale" COLOR(DEFAULT) ".    "
BOX_BREAK
"Come messaggero della Famiglia\n"
"Reale, devi, mostrare le tue\n"
"credenziali Reali sul simbolo\n"
"della Triforza..." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z..."
BOX_BREAK
"Malon...Va tutto bene...  \n"
"Mumble...Mumble...\n"
"Scusami, non arrabbiarti.."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo si é preso il Ranch, e l'ha\n"
"chiamato l'" COLOR(RED) "Ingo Ranch " COLOR(DEFAULT) "adesso.    "
BOX_BREAK
"Sono stato cacciato dal Ranch,\n"
"e ora guardami! Mia figlia,\n"
"Malon, é rimasta li' a lavorare."
BOX_BREAK
"Sono molto preoccupato.."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai salvato Malon? Grazie!!\n"
"Posso tornare al ranch, allora!   \n"
"Yeehah!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ragazzo!" QUICKTEXT_DISABLE "\n"
"Non disturbare il sonno\n"
"dei morti! "
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(RED) "Dampé il Custode" COLOR(DEFAULT) "!    \n"
"Faccio un po' paura, ma non sono \n"
"cattivo...  "
BOX_BREAK
UNSKIPPABLE "Lasciami pubblicizzare   \n"
"la mia attivita'...     "
BOX_BREAK
UNSKIPPABLE  COLOR(DEFAULT) "L'Emozionante Tour dei Tombaroli \n"
COLOR(RED) "di Dampé il custode del cimitero" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Cosa uscira' fuori?! \n"
"Cosa uscira' fuori?!   \n"
"Comincio a scavare,\n"
"poi vedremo!     " TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi farmi scavare qui?    \n"
COLOR(RED) "10 Rupié " COLOR(DEFAULT) "per una buca. \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si\n"
"Non farlo   " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Niente oggetti qui!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ciao, " NAME "!    "
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....\n"
"E' successa una cosa terribile!\n"
"Lo " COLOR(RED) "Spirito Maligno" COLOR(DEFAULT) " si é liberato!!      "
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", la leader del Villaggio\n"
"Kakariko, ha sigillato lo Spirito \n"
"Maligno sul fondo del pozzo...      "
BOX_BREAK
UNSKIPPABLE "Ma la forza del Male é divenuta \n"
"cosi' forte, che il sigillo si\n"
"é spezzato, e lo Spirito si é \n"
"liberato!!  "
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mi prendero' cura del villaggio!\n"
"Conto su di te, " NAME "!     "
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C") "Compositore Reale.  \n"
SHIFT("\x37") "Sharp il grande\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Compositore Reale.  \n"
SHIFT("\x33") "Flat il piccolo \n"
SHIFT("\x47") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Tomba dei Reali.   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1A") "Questo poema é dedicato \n"
"alla memoria dei cari trapassati, \n"
SHIFT("\x10") "membri della Famiglia Reale." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il ragazzo con la nobile Ocarina di Zelda...\n"
"Come pensavo, sei arrivato."
BOX_BREAK
UNSKIPPABLE "Sono " COLOR(RED) "Impa" COLOR(DEFAULT) ", una degli Sheikah. \n"
"Sono la governante di Zelda,    \n"
"nonche' il Saggio che é a \n"
"guardia del Tempio Ombra."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ti prego, cerca la Principessa!  " FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", l'eroe!  "
BOX_BREAK
UNSKIPPABLE "Alla fine, tutti noi, " COLOR(RED) "sei Saggi" COLOR(DEFAULT) ",\n"
"siamo stati risvegliati!\n"
"Il momento dello scontro finale\n"
"con il Re del Male é giunto!!"
BOX_BREAK
UNSKIPPABLE "Ma prima di cio', dovresti\n"
"incontrare una persona\n"
"che ti attende...   "
BOX_BREAK
UNSKIPPABLE "Ti sta aspettando al             \n"
COLOR(LIGHTBLUE) "Tempio del Tempo" COLOR(DEFAULT) "...   "
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Noi Sheikah abbiamo servito\n"
"con lealta', la famiglia Reale da\n"
"moltissime generazioni.     \n"
"Comunque..."
BOX_BREAK
UNSKIPPABLE "Quel giorno di 7 anni fa,  \n"
"Ganondorf attacco' all'improvviso....\n"
"E al Castello si arresero\n"
"in poco tempo. "
BOX_BREAK
UNSKIPPABLE "L'obiettivo di Ganondorf era\n"
"accedere al Sacro Reame con...   \n"
"Il tesoro segreto della Famiglia\n"
"Reale...L'Ocarina del Tempo!"
BOX_BREAK
UNSKIPPABLE "Per fortuna sono riuscita a salvare\n"
"Zelda da Ganondorf..."
BOX_BREAK
UNSKIPPABLE "Quando ti vidi l'ultima volta,\n"
"mentre scappavamo dal castello, \n"
"eri un ragazzino..."
BOX_BREAK
UNSKIPPABLE "Adesso sei diventato\n"
"un vero eroe...         "
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Devo restare qui...Tu devi stare \n"
"al fianco della Principessa Zelda,\n"
"e proteggerla...."
BOX_BREAK
UNSKIPPABLE "Ora ti cedero' il mio potere, fa \n"
"che ti sia utile questo...\n"
COLOR(BLUE) "Medaglione" COLOR(DEFAULT) "! "
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Come sta il tuo Cucco? E' felice? \n"
"Posso dargli un'occhiata?  "
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Sono il " COLOR(RED) "Capo dei Carpentieri" COLOR(DEFAULT) ". \n"
"Impa sta tentando di trasformare\n"
"questo villaggio in una vera citta'.\n"

BOX_BREAK
UNSKIPPABLE "Ma i giovani d'oggi sono privi\n"
"di ogni ambizione...\n"
"Hai capito cosa intendo?     "
BOX_BREAK
UNSKIPPABLE "I miei uomini vagabondano \n"
"senza scopo nel villaggio, e non  \n"
"stanno facendo alcun progresso.\n"
"         "
BOX_BREAK
UNSKIPPABLE "Persino mio figlio non ha un \n"
"lavoro e se ne sta a gironzolare!\n"
"        " TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sono tutti degli scansafatiche!!   "
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Guarda quella povera ragazza laggiu'\n"
"Lavora duramente per badare ai \n"
"suoi polli, e solo a toccarli le \n"
"viene la pelle d'oca...     "
BOX_BREAK
"Che lavoratrice! Vorrei proprio  \n"
"aiutarla! Mi sento cosi'...Cosi'\n"
"...Caritatevole in questi giorni!\n"
"Non ti capita anche a te?    "
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non c'e' di che preoccuparsi...  \n"
"La Principessa e' salva. "
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Presto, incontrerai la Principessa\n"
"Zelda, e lei ti spieghera' ogni \n"
"cosa...      "
BOX_BREAK
UNSKIPPABLE "E' per questo che noi Sei \n"
"Saggi, sigilleremo il RE del Male e\n"
"ritornera' la pace a Hyrule."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Heheh, giovanotto...\n"
"Sei stato molto veloce per \n"
"riuscire a tenermi testa!!    "
BOX_BREAK
UNSKIPPABLE "Come premio, ti daro' questo\n"
"mio tesoro.\n"
"E' un vero e proprio" COLOR(RED) " Arpione" COLOR(DEFAULT) "!   "
BOX_BREAK
UNSKIPPABLE "E' munito di una catena a molla\n"
"che ti portera' sino a dove si\n"
"attacca il gancio! E' forte eh?! \n"
"Ti sara' sicuramente utile!"
BOX_BREAK
UNSKIPPABLE "Adesso vivo qui, torna a trovarmi\n"
"ogni tanto...Ti daro' qualcosa di utile!!"
BOX_BREAK
UNSKIPPABLE "Un'altra cosa! \n"
"Attento quando farai ritorno\n"
"Heheheh...."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei tornato, giovanotto..\n"
"Il regalo che ti ho dato ti  \n"
"e' stato utile?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "Il tuo tempo é stato:    \n"
SHIFT("\x4B")  RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Finalmente ti sei ripreso...      "
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Credo che Impa sia andata al\n"
COLOR(PURPLE) "Tempio delle Ombre" COLOR(DEFAULT) " per eliminarlo,\n"
"ma...Sara' in pericolo senza\n"
"nessun aiuto!    "
BOX_BREAK
UNSKIPPABLE  NAME "!\n"
"Impa e' una dei Sei Saggi... \n"
"Distruggi lo Spirito Ombra\n"
"e salvala!!       "
BOX_BREAK
UNSKIPPABLE "C'e' un entrata per il      \n"
"Tempio Ombra al di sotto\n"
"del cimitero del villaggio.     "
BOX_BREAK
UNSKIPPABLE "L'unica cosa che posso fare\n"
"per te e' insegnarti la melodia \n"
"per accedere al Tempio Ombra...      "
BOX_BREAK
UNSKIPPABLE "Questa melodia ti portera' nella \n"
"infinita oscurita', che assorbe\n"
"persino il tempo...Ascolta bene il  \n"
COLOR(PURPLE) "Valzer Notturno delle Ombre" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gironzolano! Girollano! Girano!\n"
"Girano! Girano! Che bello!\n"
"Che gioia!"
BOX_BREAK
"Sono un musicista che ama\n"
"girare e girare ancora!\n"
"Girano! Girano! Vagano!"
BOX_BREAK
"Sto provando a comporre un  \n"
"tema musicale inspirato da questo\n"
"mulino...Girollano! Girano!\n"
"G-i-r-o-n-z-a-l-o!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Girollano, girano, gironzalo...   \n"
"Cosa? Ma va troppo veloce ora!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!"
BOX_BREAK
"Non dimentichero' mai cosa successe\n"
"quel giorno di 7 anni fa!\n"
"Grrrrrrrrr!"
BOX_BREAK
"E' tutta colpa del ragazzino con\n"
"l'Ocarina!! Ma se ritorna qui,   \n"
"mi sentira' Eh, si!!  "
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Cosa?! Hai una ocarina!!"
BOX_BREAK
UNSKIPPABLE "Che coincidenza!    "
BOX_BREAK
UNSKIPPABLE "Mi ricorda un fatto successo,\n"
"sette anni fa!  "
BOX_BREAK
UNSKIPPABLE "Quando un ragazzaccio venne qui\n"
"e suono' una " COLOR(PURPLE) "strana canzone" COLOR(DEFAULT) ".  \n"
"Incasino' questo mulino!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Come faccio?! \n"
"I miei " COLOR(RED) "Cuccos" COLOR(DEFAULT) " sono volati via tutti!"
BOX_BREAK
"Ti prego aiutami tu!     \n"
"Ti scongiuro rimettili\n"
"nel loro recinto! "
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Cuccos sono scappati! \n"
"Aiutami a riportare gli altri\n"
"quattro al loro recinto!        "
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Cuccos sono scappati! \n"
"Aiutami a riportare gli altri\n"
"tre al loro recinto! Ti prego!   "
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Cuccos sono scappati! \n"
"Aiutami a riportare gli altri\n"
"due nel loro recinto! Ti prego!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Cuccos sono scappati! \n"
"Ti prego ormai ne manca soltanto \n"
"uno nel recinto! Aiutami!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie per aver ritrovato i miei\n"
"Cuccos. Sono allergica, a\n"
"toccarli mi viene la pelle d'oca!"
BOX_BREAK
UNSKIPPABLE "Per avermi aiutato, ti daro' questa.\n"
"E' vetro di qualita' e ti potra'\n"
"essere utile. Tienila da conto!\n"
"     " EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, cosa stai facendo?!\n"
"Ora inseguili oppure pagali!!    \n"
"     " EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non dare fastidio ai Cuccos! "
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ho ottenuto un cucco in miniatura! \n"
"L'ho chiamato il " COLOR(RED) "Pocket Cucco" COLOR(DEFAULT) "! \n"
"Non mi causa allergia il\n"
"piccolino...  "
BOX_BREAK
UNSKIPPABLE "I" COLOR(RED) " Cuccos" COLOR(DEFAULT) " servono ai lazzaroni, \n"
"tiratardi per farli svegliare.\n"
"Non ne avevi mai sentito parlare?\n"

BOX_BREAK
UNSKIPPABLE "Li fa felici sentire cantare:    \n"
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(RED) "CUCCKOOOO" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"specialmente per alzarsi dopo\n"
"una lunga dormita!  "
BOX_BREAK
UNSKIPPABLE "Comunque, i Cuccos non sono del\n"
"tutto felici ora... "
BOX_BREAK
UNSKIPPABLE "Tu...., \n"
"Tu sembri in gamba nel maneg-\n"
"giare i Cuccos. "
BOX_BREAK
UNSKIPPABLE "Ecco, ti do un uovo.\n"
"Quando sbuchera' un Cucco, riporta-\n"
"melo e io controllero' quale sara' \n"
"il suo umore.     " TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che ne pensi? \n"
"Vuoi provare?     \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, malissimo...Sei stato beccato da\n"
"un Cucco da piccolo?!!   " EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh, giovanotto!\n"
"Sei veloce con i piedi?  "
BOX_BREAK
"Non sembrerebbe, ma sono sicuro \n"
"della mia velocita'! \n"
"Facciamo una corsa!\n"
"Seguimi se te la senti!"
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fai felice il mio Cucco!   \n"
"OK?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, il tuo Cucco sembra felice!   \n"
"Deve aver svegliato un \n"
"grandissimo pigrone! "
BOX_BREAK
UNSKIPPABLE "Sai allevare bene i Cuccos! \n"
"Te ne daro' un altro, molto  \n"
"raro e prezioso, se vuoi...   "
BOX_BREAK
UNSKIPPABLE "Si chiama " COLOR(RED) "Cojiro" COLOR(DEFAULT) "," COLOR(RED) " " COLOR(DEFAULT) "ed era il Cucco \n"
"di mio fratello. Il suo\n"
"piumaggio blu é proprio bello. \n"
"E' vero?! "
BOX_BREAK
UNSKIPPABLE "Da quando mio fratello é andato\n"
"via, Cojiro ha smesso di cantare.\n"
"Strano eh?!" TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi tenere con te " COLOR(RED) "Cojiro" COLOR(DEFAULT) "? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sembra che a te piacciano davvero  \n"
"i Cuccos. Ok, lo puoi tenere   \n"
"per un po'..." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Al negozio di Pozioni c'é una\n"
"vecchia strega. Ci puoi andare  \n"
"passando attraverso la porta a\n"
"sinistra del bancone.      " EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mio fratello sara' stato\n"
"cosi' solo...   "
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho sentito che nei " COLOR(ADJUSTABLE) "Boschi Perduti" COLOR(DEFAULT) ",\n"
"la' dove vivono le fate,\n"
"ci sono moltissimi odori misteriosi.  "
BOX_BREAK
"Vorrei poter riuscire a fare \n"
"una medicina con alcune delle\n"
"strane cose che si trovano li'.."
BOX_BREAK
"Ma con l'eta' ci vedo poco,  \n"
"anche se, il mio naso funziona\n"
"ancora bene! Hehehehe! "
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sniff sniff sniff..."
BOX_BREAK
"Che odore misterioso...   "
BOX_BREAK
"Devi avere qualche cosa!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che fortuna! Sei stato nella   \n"
"foresta...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "Vedo. " TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, dammelo a me ora! \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Peccato...Me ne serviva un po'... "
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se vedi quel pazzo, dagli questa  \n"
"cosa. E' la piu' forte medicina che\n"
"abbia mai prodotto. "
BOX_BREAK
UNSKIPPABLE "Comunque, questa pozione non\n"
"funziona sui mostri.." EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ehi, tu! Se vuoi prendere delle\n"
"medicine, ti serve un contenitore!\n"
"         " EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dicono che non esiste una \n"
"medicina che curi la pazzia...  \n"
"Penso che sia vero... "
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non posso scendere, mah! Mi guardo\n"
"la " COLOR(RED) "Montagna della Morte" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non posso scendere, al massimo mi \n"
"guardo le stelle...  "
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puoi vedere da la' sotto? \n"
"Succede qualcosa alla\n"
COLOR(RED) "Montagna della Morte" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lo vedi da li' sotto?\n"
COLOR(RED) "La Montagna della Morte" COLOR(DEFAULT) "\n"
"é normale ora!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non ho alcuna intenzione di\n"
"scendere! Qualunque cosa succeda,\n"
"restero' qui a guardare la\n"
"Montagna...    "
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi! Sono contento di rivederti!\n"
"Ascolta questo suggerimento"
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Per una buona visuale usa " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " e\n"
"girati premendo " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".  "
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi! Ragazzo, entri sempre \n"
"nelle case altrui senza chiedere\n"
"il permesso? Non ti hanno insegna-\n"
"to le buone maniere?"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Ah bene."
BOX_BREAK
UNSKIPPABLE "Hai visto quella signora dietro\n"
"la casa? Sta passando brutti\n"
"momenti.  "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Percio'." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se lei ti chiede aiuto per i\n"
"polli, dovresti almeno ascoltarla. "
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La tua idea di divertimento é      \n"
"visitare le case altrui a  \n"
"quest'ora? A te é mancata una\n"
"buona educazione..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Oh bene." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quella donna che bada ai polli,\n"
"purtroppo, é allergica alle \n"
"loro piume. "
BOX_BREAK
SHIFT("\x42") "Ah bene."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi! Giovane! Un ragazzo grande\n"
"come te che entra in casa altrui\n"
"senza permesso?! Voglio parlare\n"
"ai tuoi genitori! "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Ah bene."
BOX_BREAK
UNSKIPPABLE "Questa non é casa mia comunque.\n"
"E' della" COLOR(RED) " grande Impa" COLOR(DEFAULT) "!!     "
BOX_BREAK
UNSKIPPABLE "La grande Impa si é recata al\n"
COLOR(RED) "cimitero" COLOR(DEFAULT) " per sigillare l'accesso\n"
"ai mostri umanoidi."
BOX_BREAK
UNSKIPPABLE "Da quando é apparso Ganondorf,\n"
"ci sono mostri ovunque qui  \n"
"intorno...  "
BOX_BREAK
UNSKIPPABLE "Solo grazie ad Impa c'é anco-\n"
"ra un po' di pace al villaggio.\n"
"Ricordatelo, giovanotto!   "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Ah bene."
BOX_BREAK
UNSKIPPABLE "Parlando della grande Impa, non\n"
"é ancora tornata. Chissa' cosa \n"
"le é successo?       " TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ho sentito che il" COLOR(RED) " Fantasma del\n"
"custode " COLOR(DEFAULT) "appare spesso nel cimi- \n"
"tero in fondo al villaggio...   "
BOX_BREAK
SHIFT("\x34") "Non é un affare. "
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ciao! E' la prima volta che \n"
"visiti il nostro villaggio?    "
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", una grande donna, ha \n"
"aperto il villaggio ai poveri.  " TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, adesso vai a casa.    \n"
"Non é ancora pronto da mangiare. "
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"La Grande Impa non é qui. Che le\n"
"sia successo qualcosa? "
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tutti hanno avuto delle avversita' \n"
"nel loro passato\n"
"delle quali non parlano a nessuno." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Guarda quell'uomo con la barba la'\n"
"sopra. Scommetto che anche \n"
"uno come lui ha avuto i suoi \n"
"guai in passato...      "
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Il tizio barbuto é tornato al \n"
"ranch. Sembrava cosi' felice! "
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ding dong, ding dong!\n"
"Sono il soldato orologio di Kakariko\n"
"L'ora attuale e' " TIME "."
BOX_BREAK
UNSKIPPABLE "Ciao, piccolo.\n"
"La governante di Zelda,\n"
"di nome " COLOR(RED) "Impa" COLOR(DEFAULT) ", ha aperto il\n"
"villaggio alla povera gente."
BOX_BREAK
UNSKIPPABLE "Per ora abbiamo poca gente qui \n"
"ma un giorno il villaggio sara'\n"
"popoloso come il Castello di Hyrule.\n"
"Diverra' una citta'!"
BOX_BREAK
UNSKIPPABLE "Sali le " COLOR(RED) "scale che stanno a nord \n"
COLOR(DEFAULT) "del villaggio e troverai il sentiero\n"
"per la Montagna della Morte. "
BOX_BREAK
UNSKIPPABLE "Ma ti serve il permesso del RE per\n"
"salire sino alla montagna.     "
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"L' ora attuale é  " TIME ".   "
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"L' ora attuale é  " TIME ".   \n"
"Comunque, sai cosa e' successo\n"
"al castello?          "
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, figliolo, cosa stai  \n"
"facendo in giro cosi' tardi   \n"
"di notte?"
BOX_BREAK
UNSKIPPABLE "Ah, lo so! Stai facendo una prova \n"
"di coraggio vero? Devi entrare\n"
"in un...Cimitero!!         "
BOX_BREAK
UNSKIPPABLE "Un minuto! Ma cosa sto facendo? \n"
"Parlare? Io ho del lavoro da fare!  \n"
"LAVORO!    " TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"L'ora attuale e'  " TIME ".   "
BOX_BREAK
"Vai ad est e troverai un   \n"
COLOR(RED) "cimitero" COLOR(DEFAULT) ". La leggenda dice che \n"
"le anime dei morti si calmano\n"
"con la " COLOR(BLUE) "Vecchia canzone dei Reali" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'e' uno strano tizio che vive nel  \n"
"Mulino. Lo hai gia' incontrato,\n"
"Mr Eroe?     "
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La gente fa schifo.\n"
"Mio padre e mia madre     \n"
"fanno schifo.    \n"
"Anche tu devi fare schifo!  "
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lavoriamo tutto il giorno, per\n"
"progredire nella costruzione del\n"
"villaggio. Ci vorra' del tempo perché\n"
"tutto sia finito.         "
BOX_BREAK
"Il capo ci fa lavorare duro!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono affamato!\n"
"Lasciaci cenare, adesso!   "
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Questi fannulloni lavorano la  \n"
"meta' di un uomo ma mangiano\n"
"come uno intero!        \n"
"Sono dei lazzaroni, te lo dico io!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poe   30 Rupié \n"
COLOR(DEFAULT) "E' l'anima di un fantasma...    \n"
"Vendila a qualcuno che va pazzo \n"
"per cose soprannaturali...   " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poe  30 Rupié " QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Cuccos sono scappati! \n"
"Ne mancano ancora sei!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME "!\n"
"La nave affonda!\n"
"Abbandonare la nave!\n"
"Salta giu', subito!!   " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi mancano ancora dei Cuccos!\n"
"Ti prego altri cinque!     "
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Non combinare guai! \n"
"Lo dico a Dampé!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Guarda qui ragazzo! Le mie belle\n"
"mani sono tutte rovinate dal \n"
"troppo lavoro. Sob sob..."
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un lavoro per fare molti soldi\n"
"senza sforzarsi troppo...\n"
"Cosi' su due piedi mi viene in mente: \n"
"il ladro... Non e' un ideaccia?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ho sentito che la casa del capo \n"
"é proprio dietro questa casa. Ma\n"
"lui non vuole farcelo sapere.    "
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, hai visto " COLOR(RED) "Mr. Dampé" COLOR(DEFAULT) ", che\n"
"vive nel cimitero piu' avanti?"
BOX_BREAK
"Sono le " TIME " adesso, e proba-\n"
"bilmente sta dormendo ora. "
BOX_BREAK
"Perche' non torni nei campi a \n"
"perdere un po' di tempo? "
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ho faaaameee!\n"
"La cena non é pronta?  \n"
"Sono le " TIME "!     "
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Questa e' la casa della  \n"
COLOR(RED) "Grande Impa" COLOR(DEFAULT) ", ma lei non resta \n"
"qui molto a lungo.   "
BOX_BREAK
UNSKIPPABLE "Ora e' aperta a tutti\n"
"gli abitanti.\n"
"Sei libero di entrare. " TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo villaggio era degli\n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) ", ma la grande    \n"
"Impa l'ha aperto a tutti quanti.  "
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lo giuro, l'ho visto!  "
BOX_BREAK
"Ho visto lo spettro di Dampé il\n"
"Custode entrare nella sua tomba.\n"
"Sembrava portare qualcosa... \n"
"...Come una specie di " COLOR(RED) "Tesoro" COLOR(DEFAULT) "!  "
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eccolo! Li'! E' Lui!  \n"
"E' lui che é sceso dal cielo \n"
"circondato da una luce blu! \n"
"      "
BOX_BREAK
"Ora mi crederai?      "
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nessuno crede a quello che ho \n"
"detto in questi lunghissimi \n"
"sette anni! "
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il fuoco ci consumera' tutti!   \n"
"Ma tutti insieme, posssiamo      \n"
"spegnere il fuoco! Ottimo  \n"
"lavoro, non credi?      "
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!"
BOX_BREAK
"Guarda quest'uomo! Da quando\n"
"é scappato dalla Citta' del\n"
"Castello, é divenuto un vero\n"
"idiota!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!"
BOX_BREAK
"Deve aver visto qualche cosa!   \n"
"Wah hah hah hah hah hah!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah hah hah hah hah hah!\n"
"Sono proprio dei vestiti    \n"
"divertenti!! "
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah hah hah hah hah hah!\n"
"Coi tempi che corrono, ridere é la\n"
"migliore medicina!\n"
"Lo diceva sempre mio padre!..."
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Guardami! Sono sulla cima del \n"
"mondo! Mi da' fastidio vedere\n"
"qualcuno piu' in alto di me!      \n"
"Io devo essere in cima!   "
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se mi addormento qua sopra,   \n"
"cadro' di sicuro..."
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il Mulino estrae l'acqua dalle\n"
"profondita' del pozzo.   "
BOX_BREAK
"Ma ora é asciutto, purtroppo.    \n"
"Hrrrrm..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"La signora qui é davvero\n"
"generosa. Si prende persino\n"
"cura dei carpentieri quando sono\n"
"qui! "
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tanto tempo fa... \n"
"C'era un uomo in questo villaggio\n"
"che aveva un occhio col quale\n"
"vedeva la verita'!"
BOX_BREAK
"Attualmente, devi allenare la\n"
"tua mente di continuo\n"
"per riuscire a vedere la verita'...     "
BOX_BREAK
"Ma quel tizio, no, diceva di\n"
"avere un modo differente di fare\n"
"le cose."
BOX_BREAK
"La sua casa era dov'é il pozzo\n"
"oggi...  "
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I vecchi raccontano di una \n"
COLOR(RED) "famiglia favolosamente ricca" COLOR(DEFAULT) ", che\n"
"viveva in una delle case del vil-\n"
"laggio... "
BOX_BREAK
"Ma si dice che furono maledetti\n"
"a causa della loro avarizia!\n"
"     "
BOX_BREAK
"Chi puo' dire cosa sia successo\n"
"ad una famiglia cosi'  \n"
"avara... "
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh...."
BOX_BREAK
"Che persona noiosa, ad\n"
"interromperci a questo modo...\n"
"Non vuoi il mio amore?   "
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee..."
BOX_BREAK
"Violare il nostro spazio!! \n"
"Deve avere qualcosa di meglio\n"
"da fare...\n"
"Non credi, carissimo?    "
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Guardalo...l' uomo con la barba.\n"
"Credo sia stato licenziato dal\n"
"suo lavoro al ranch... " TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sta sempre a poltrire in giro,\n"
"mattina, pomeriggio e sera.\n"
"In questi tempi duri, é un\n"
"uomo senza preoccupazioni!"
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quel lazzarone, mi ricorda\n"
"un po' il mio piccolo Richard...   "
BOX_BREAK
"Come? Non hai mai sentito  \n"
"parlare del mio piccolo Richard? \n"
"E' un cucciolo cosi' famoso! Ma\n"
"veramente non sai niente di lui?"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"OH NO! Ancora una tempesta!\n"
"Hai suonato di nuovo l'Ocarina\n"
"vero?!! Grrrrrrrrrrrrrrr!!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Prendi un Grosso Poe!\n"
"Vai al " COLOR(RED) "Negozio di Spettri " COLOR(DEFAULT) " e   \n"
"vendilo!!    "
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Halt! Rimani fermo li'!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi straniero!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, straniero! Aspetta un  \n"
"attimo e ti apriro' il cancello."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Non ci sottovalutare!    " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ho notato la tua bravura.\n"
"Per aver superato le guardie, devi\n"
"essere un ladro in gamba.      "
BOX_BREAK
UNSKIPPABLE "Ritengo che tutti gli uomini, \n"
"a parte il grande Ganondorf, siano\n"
"inutili...Ma ora che ti ho visto,\n"
"non ne sono piu' tanto certa!"
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Nabooru l'Esaltata" COLOR(DEFAULT) ", nostro capo, \n"
"mi ha assegnato questa fortezza.  "
BOX_BREAK
UNSKIPPABLE "Nabooru é seconda-in-capo solo  \n"
"al grande Ganondorf, Re dei     \n"
"Ladri Gerudo.      "
BOX_BREAK
UNSKIPPABLE "La sua base si trova nel " COLOR(YELLOW) "Tempio\n"
"dello Spirito" COLOR(DEFAULT) ", proprio alla fine del\n"
"deserto."
BOX_BREAK
UNSKIPPABLE "Di', vorresti diventare uno  \n"
"di noi, eh?\n"
"Va bene, allora!   \n"
"Da oggi in poi lo sei!"
BOX_BREAK
UNSKIPPABLE "Prendi questo. Con esso potrai\n"
"accedere a tutte le aree della\n"
"fortezza!    " EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Da ora in poi, sei libero di    \n"
"entrare e uscire attraverso il\n"
"cancello del deserto. "
BOX_BREAK
"Troverai il " COLOR(YELLOW) "Tempio dello Spirito" COLOR(YELLOW) " \n"
COLOR(DEFAULT) "dove vive Nabooru l'esaltata,   \n"
"qui fuori nel deserto.  "
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deficiente!" QUICKTEXT_DISABLE "\n"
"La sotto resta in silenzio! "
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non ho idea da dove tu venga,\n"
"ma hai avuto veramente del   \n"
"fegato, a superare tutte le \n"
"guardie qui intorno!   "
BOX_BREAK
UNSKIPPABLE "Tutti i miei amici carpentieri\n"
"sono imprigionati qui vicino. "
BOX_BREAK
UNSKIPPABLE "Se ci porterai fuori di qui, \n"
"ti restituiremo il favore!     "
BOX_BREAK
UNSKIPPABLE "Ma attento! Ci sono guardie    \n"
COLOR(RED) "Gerudo" COLOR(DEFAULT) " ovunque              \n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "qui" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "intorno" QUICKTEXT_DISABLE "...." TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Woo!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Attento!! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "L'Entrata per il Passato" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "L'Entrata per il Presente  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "L'Entrata per il Futuro   " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\xEC") "Saro' la tua guida nel cammino,\n"
"ma al ritorno, non si gioca!  \n"
"Ti mostrero' l'unica via giusta, \n"
"percio' seguimi in fretta!     " FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Passato, presente, futuro..."
BOX_BREAK
UNSKIPPABLE "La Spada Suprema é la \"nave\" \n"
"per navigare lungo le tumultuose\n"
"correnti del fiume del Tempo... "
BOX_BREAK
UNSKIPPABLE "Il porto di questa nave é il\n"
"Tempio del Tempo...  "
BOX_BREAK
UNSKIPPABLE "Per ritornare al Colosso del\n"
"Deserto e nel " COLOR(YELLOW) "Tempio dello Spirito" COLOR(DEFAULT) ",\n"
"devi viaggiare nel flusso del\n"
"tempo..."
BOX_BREAK
UNSKIPPABLE "Ascolta questo " COLOR(YELLOW) "Requiem dello Spirito" COLOR(DEFAULT) ",\n"
"la sua musica ti riportera'\n"
"qui da bambino...  "
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Io sono il miglior arciere\n"
"a cavallo Gerudo! E inoltre, \n"
"io sono il numero uno dei\n"
"cavalieri Gerudo!     "
BOX_BREAK
"Vuoi provare a sfidrami per \n"
"sole " COLOR(RED) "20 Rupié" COLOR(DEFAULT) "? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai fegato - Mi piaci.     \n"
"Seguimi.  "
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non se ne parla nemmeno se non \n"
"hai un cavallo!     "
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Non voglio avere niente a che fare\n"
"con un codardo! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, allora non sei in gamba come\n"
"credevo...            "
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non male...  "
BOX_BREAK
"Per oggi, ammetto di aver\n"
"perso. Ma ho molto spazio per     \n"
"migliorare... "
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo é il " COLOR(RED) "Centro Allenamento\n"
"Gerudo" COLOR(DEFAULT) "."
BOX_BREAK
"L'ingresso é consentito solo\n"
"ai soci muniti di carta. "
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei al " COLOR(RED) "Centro Di Allenamento \n"
"Gerudo" COLOR(DEFAULT) "."
BOX_BREAK
"La carta socio é valida. "
BOX_BREAK
"Prova, solo 10 Rupié! \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Prova\n"
"Lascia " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va bene, prendo le tue 10 Rupié.    \n"
"Fai del tuo meglio!    " EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non ti bastano i soldi!     \n"
QUICKTEXT_ENABLE "Ritorna ancora. " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, pivello!"
BOX_BREAK
UNSKIPPABLE "Stai andando nel deserto?    \n"
"Ti apriro' il cancello, ma...    "
BOX_BREAK
UNSKIPPABLE "Per avanzare nel deserto,\n"
"dovrai superare le " COLOR(RED) "Due Prove" COLOR(DEFAULT) ".      " TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La prima prova é...Il " COLOR(RED) "Fiume di Sabbia" COLOR(DEFAULT) "!  \n"
"Non riuscirai ad attraversarlo!\n"
"Ma se ci riuscissi, segui i nostri   \n"
"segnali...       "
BOX_BREAK
"La seconda prova é...\n"
"La" COLOR(RED) " Guida Fantasma" COLOR(DEFAULT) "!"
BOX_BREAK
"Coloro senza l'" COLOR(RED) "occhio che vede\n"
"la verita' " COLOR(DEFAULT) "si ritroverrano al punto \n"
"di partenza... "
BOX_BREAK
"Ci andrai lo stesso, ora?    \n"
"Non ti fermero'...     \n"
"Vai pure!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Perché sei venuto fino  \n"
"qui sotto? Cosa? Mi stavi  \n"
"per chiedere la stessa cosa?    \n"
"      " TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bene, visto che ormai sei qui,\n"
"cerca, almeno di fare la cosa giusta!\n"
"      "
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie! Bravo ragazzo!\n"
"Mi spiace che non posso darti\n"
"qualcosa in cambio ma, ad\n"
"ogni modo, tieni questo!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non ti ho mai visto in giro...   "
BOX_BREAK
"Che cosa vuoi?   \n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Vedere il tempio \n"
"Sto cercando i Saggi \n"
"Niente, davvero" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei un ragazzino! Questo non é\n"
"posto da ragazzini! "
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Saggi? E chi sono? Mai   \n"
"sentiti..."
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Non hai niente da fare?\n"
"Buona notizia!\n"
"Allora puoi farmi un favore?    "
BOX_BREAK
UNSKIPPABLE "Aspetta un attimo, prima vorrei \n"
"sapere...Una cosa. Non mi    \n"
"sembri uno dei seguaci..."
BOX_BREAK
"Di Ganondorf, o no?  \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "E se lo fossi?\n"
"Odio Ganondorf! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha!\n"
"Non provare a fare il duro.\n"
"Ho solo chiesto!  "
BOX_BREAK
UNSKIPPABLE "Un ragazzino come te, non puo'\n"
"essere amico di Ganondorf!  "
BOX_BREAK
UNSKIPPABLE "Bene, meglio tagliare corto... " TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uh-huh!"
BOX_BREAK
UNSKIPPABLE "Hai del fegato. \n"
"Cominci a piacermi." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Innanzitutto, mi voglio presentare \n"
"Sono " COLOR(RED) "Nabooru" COLOR(DEFAULT) " una ladra Gerudo.\n"
"Una ladra solitaria..."
BOX_BREAK
UNSKIPPABLE "Ma non giudicarmi male!"
BOX_BREAK
UNSKIPPABLE "Sebbene siamo entrambi ladri, \n"
"sono molto differente da  \n"
"Ganondorf."
BOX_BREAK
UNSKIPPABLE "Con i suoi seguaci, egli ruba\n"
"alle donne e ai bambini, e     \n"
"persino ai morti!  "
BOX_BREAK
UNSKIPPABLE "Un ragazzino come te, non lo sapra'\n"
"ma, la razza dei Gerudo consiste\n"
"in sole donne. Ogni cento anni,\n"
"pero', nasce un uomo..."
BOX_BREAK
UNSKIPPABLE "E sebbene la nostra legge\n"
"dica che il maschio debba divenire\n"
"Re dei Gerudos, io non mi\n"
"pieghero' mai a quel demonio!"
BOX_BREAK
UNSKIPPABLE "Comunque, qual'é il\n"
"tuo nome?   "
BOX_BREAK
UNSKIPPABLE  NAME "?!"
BOX_BREAK
UNSKIPPABLE "Ma che razza di nome é?\n"
"Bah...comunque...  " TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Volevo chiederti un favore..."
BOX_BREAK
UNSKIPPABLE "Potresti attraversare questo \n"
"cunicolo per riportarmi un tesoro?   "
BOX_BREAK
UNSKIPPABLE "Il tesoro sono i " COLOR(BLUE) "Guanti d'Argento" COLOR(DEFAULT) "!\n"
"Se li indossi, potrai spostare\n"
"facilmente oggetti molto,\n"
"molto pesanti!"
BOX_BREAK
UNSKIPPABLE "No, no, no! Non pensare nemmeno \n"
"di tenerti questo tesoro!      \n"
"         "
BOX_BREAK
UNSKIPPABLE "I Guanti d'Argento non andranno \n"
"mai bene ad un piccoletto come te!\n"
"Fai il bravo ragazzino e riportali       \n"
"a me!              "
BOX_BREAK
UNSKIPPABLE "Ganondorf e i suoi balordi\n"
"usano il Tempio come\n"
"nascondiglio...     "
BOX_BREAK
UNSKIPPABLE "Solo i Guanti d'Argento mi   \n"
"consentiranno di penetrare   \n"
"nel tempio."
BOX_BREAK
UNSKIPPABLE "Una volta dentro, rubero' tutti i \n"
"tesori che ci sono e rovinero'\n"
"i loro piani!"
BOX_BREAK
"Che ne pensi? Lo farai?      \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie!     "
BOX_BREAK
UNSKIPPABLE "Tu ed Io, faremo una bella\n"
"sorpresa a Ganondorf ed i\n"
"suoi sgherri!         " TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se riuscirai ad ottenere i      \n"
COLOR(BLUE) "Guanti d'Argento" COLOR(DEFAULT) "..."
BOX_BREAK
"Faro' qualcosa di utile" COLOR(RED) " " COLOR(DEFAULT) "per te! "
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa potevo aspettarmi?\n"
"Dopotutto, sei solo un bimbo! "
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi! Dove mi state portando?! "
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ho ho ho!\n"
"Sembra ci sia qualcuno qui, Koume."
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hee hee hee!\n"
"Proprio cosi', Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Che persona insolente é questa, \n"
"introdursi in questo modo nel \n"
"Tempio...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dobbiamo dare una bella lezione\n"
"a questo intruso!\n"
"He hee hee!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, mio servo...   "
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Distruggi questo intruso  \n"
"per me!   "
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "I Nemici...di Ganondorf..\n"
"Devono morire."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Unnnh...\n"
"Dove sono...? "
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bene, bene...\n"
"Sembra sia ritornata normale...   \n"
"Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"E' solo una ragazzina,    \n"
"ma si é conquistata molto \n"
"rispetto tra i Gerudo, Kotake...   "
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Forse potremmo farla collaborare\n"
"piu' a lungo per il grande\n"
"Ganondorf!          \n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Rifacciamogli il lavaggio\n"
"del cervello!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ragazzo, ti ringrazio.\n"
UNSKIPPABLE "Heheheh...Ma guarda quel     \n"
"ragazzino, é divenuto in questi\n"
"sette anni un grande guerriero!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
"A saperlo, che saresti divenuto\n"
"cosi' affascinante...  " BOX_BREAK_DELAYED("\x50") "Devo mantenere la promessa che\n"
"ti feci allora...  " FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ecco, ti daro' " COLOR(RED) "questo" COLOR(DEFAULT) "...   \n"
"E' molto importante per me...     \n"
"Ci scontreremo un altra volta! "
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...Ci si rivede! "
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Comunque...  "
BOX_BREAK
UNSKIPPABLE "Sono davvero confusa."
BOX_BREAK
UNSKIPPABLE "Sono stata ipnotizzata da\n"
"quelle megere e usata per i       \n"
"voleri di Ganondorf..."
BOX_BREAK
UNSKIPPABLE "Ma é strana la vita?! Una ladra  \n"
"come me che diviene il   \n"
COLOR(YELLOW) "Saggio dello Spirito" COLOR(DEFAULT) "! "
BOX_BREAK
UNSKIPPABLE "E adesso, combattero' il male\n"
"insieme agli altri Saggi!  \n"
"Heh heh..."
BOX_BREAK
UNSKIPPABLE "Mi vendichero' di tutto cio'  \n"
"che mi hanno fatto! "
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ragazzo."
BOX_BREAK
UNSKIPPABLE "No...\n"
NAME ", Eroe del Tempo!"
BOX_BREAK
UNSKIPPABLE "Al posto della promessa che ti  \n"
"feci, ti daro' questo       \n"
COLOR(YELLOW) "Medaglione" COLOR(DEFAULT) "! "
BOX_BREAK
UNSKIPPABLE "Prendilo!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x12") "Yeearggh!" QUICKTEXT_DISABLE " Lasciami!! "
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x33") "Voi, " QUICKTEXT_ENABLE "maledette!!" QUICKTEXT_DISABLE "\n"
SHIFT("\x29") "Serve di Ganondorf!!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x20") "Aiutami! Ti prego!!  "
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0C") "Streghe Malefiche! Stanno   \n"
SHIFT("\x1F") "usando magia nera!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, novellino! Questo é il\n"
COLOR(RED) "Campo arcieri a cavallo" COLOR(DEFAULT) "."
BOX_BREAK
"Dopo un bel po' di pratica e\n"
"allenamento, abbiamo acquisito\n"
"l'abilita' di centrare il bersaglio  \n"
"anche cavalcando!   "
BOX_BREAK
"Quando avrai imparato a cavalcare,\n"
"ritorna qui e prova a colpire\n"
"il centro! E' pericoloso, ma sara'\n"
"divertente!   "
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi novellino, hai un bel  \n"
"cavallo! "
BOX_BREAK
"Non so dove sei riuscito a \n"
"rubarlo, ma...   "
BOX_BREAK
"OK, che dici, vuoi provare a   \n"
COLOR(RED) "tirare cavalcando" COLOR(DEFAULT) "?"
BOX_BREAK
"Appena il cavallo inizia a correre,\n"
"mira ai bersagli con il\n"
"tuo arco."
BOX_BREAK
"Vediamo quanti punti riuscirai\n"
"a fare. Avrai solo 20 frecce."
BOX_BREAK
"Se farai almeno " COLOR(RED) "1.000 punti" COLOR(DEFAULT) ", ti \n"
"daro' qualcosa di utile!     " EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vuoi riprovare per sole     \n"
COLOR(RED) "20 Rupié" COLOR(DEFAULT) "? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, pivello!\n"
"Sembri in gamba!\n"
"Mostra ancora il tuo valore!"
BOX_BREAK
"Il tuo nuovo obiettivo é di \n"
COLOR(RED) "1,500 punti" COLOR(DEFAULT) ", prova ancora! " EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa? Vuoi riprovare ancora?   \n"
"Sembra tu abbia delle   \n"
"qualita'! " EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che io sia dannata! Sei un vero\n"
"maestro!"
BOX_BREAK
"Ti daro' un oggetto adatto ad\n"
"un fuoriclasse."
BOX_BREAK
"Questa faretra é molto importante\n"
"per me. Voglio l'abbia tu.\n"
"Tienila da conto, OK?    "
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " punti... Hmm...\n"
"Wha-ha-ha! Che prova! Puoi    \n"
"solo che migliorare! " EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantastico!\n"
"Sei il Signore dell'Arco!  "
BOX_BREAK
"Ti daro' questo oggetto.  \n"
"Con questo equipaggiamento, la  \n"
"sola cosa da migliorare sei  \n"
"tu stesso!"
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " punti... \n"
"Impressionante!  " EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Guarda quello stupido!  \n"
"E' venuto per conto suo per \n"
"offrirsi in sacrificio al\n"
"grande Ganondorf...   " FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x05") "Con le mie fiamme, gli brucero'  \n"
SHIFT("\x3F") "le ossa!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Con il mio ghiaccio, gelero' la  \n"
SHIFT("\x30") "sua anima!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x1C") "Cavolo, che ragazzino!  \n"
SHIFT("\x15") "Stavolta, si fa sul serio,  \n"
SHIFT("\x34") "giusto Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "Cosa?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x0A") "Ehi, Koume, cosa c'é sopra la \n"
SHIFT("\x38") "tua testa?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0B") "Non lo so, ma c'é qualcosa    \n"
SHIFT("\x14") "anche sulla tua, Kotake!   " FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "Ma io ho solo 400 anni!    " FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "E io appena 380 anni!      " FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Siamo gemelle! Non mentire   \n"
SHIFT("\x25") "sulla tua eta'!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x06") "Ti sei proprio rimbambita!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Chi hai chiamato rimbambita?\n"
SHIFT("\x2B") "Non trattare cosi' tua\n"
SHIFT("\x3D") "sorella maggiore!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x36") "Siamo GEMELLE!\n"
SHIFT("\x26") "  Ma quale maggiore! " QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Keeeyaaah!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x20") "   Sei senza cuore!   " QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x12") "Sei proprio un ingrata!      " QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x35") "Tu SENZA CUORE!!  " QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x33") "Tu INGRATA...    " QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "Tornero' a tormentarti!     " QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OK, facciamo sul serio, Kotake!   " QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x37")  QUICKTEXT_ENABLE "Oh, OK, Koume." QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x14")  SHIFT("\x30")  QUICKTEXT_ENABLE "Kotake" QUICKTEXT_DISABLE " e " QUICKTEXT_ENABLE "Koume    " QUICKTEXT_DISABLE "\n"
SHIFT("\x1C")  QUICKTEXT_ENABLE "Doppio" QUICKTEXT_DISABLE " Attacco " QUICKTEXT_ENABLE "Dinamite" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sei venuto qui a salvarmi?    \n"
"Oh, meno male!\n"
"Sono " COLOR(RED) "Ichiro il carpentiere" COLOR(DEFAULT) ".      "
BOX_BREAK
UNSKIPPABLE "Eravamo molto interessati ad\n"
"unirci ad un gruppo di sole-donne,\n"
"ma ci hanno messo in prigione solo\n"
"perché siamo uomini!"
BOX_BREAK
UNSKIPPABLE "Abbiamo chiuso con i Gerudo\n"
"per sempre! Sono dei rozzi! "
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Tre miei compagni" COLOR(DEFAULT) ", oltre a me,\n"
"sono stati catturati. Aiutali \n"
"a fuggire!       "
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sei un bravo ragazzo!\n"
"Grazie per avermi salvato!\n"
"Sono " COLOR(RED) "Jiro, il carpentiere" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Queste donne sono arpie!\n"
"Preferisco lavorare, piuttosto\n"
"che rimanere qui! "
BOX_BREAK
UNSKIPPABLE "Non vedo l'ora di andarmene da\n"
"questo posto!" COLOR(RED) " Due miei amici " COLOR(DEFAULT) "\n"
"sono ancora tenuti prigionieri. \n"
"Puoi aiutare anche loro? Ti prego!"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grazie, ragazzo! Sei grande!\n"
"Sono " COLOR(RED) "Sabooro, il carpentiere" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Hai visto il nostro capo?   \n"
"Sara' sicuramente arrabbiato!  \n"
"Devo raggiungerlo...   \n"
"Immediatamente!!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ancora uno dei miei compagni" COLOR(DEFAULT) " é\n"
"prigioniero. Ti prego salvalo!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Avevo paura che ti fossi dimen-\n"
"ticato di me! Sono libero! Grazie!\n"
"Sono " COLOR(RED) "Shiro il carpentiere" COLOR(DEFAULT) ".  "
BOX_BREAK
UNSKIPPABLE "Per avermi salvato, ti diro'\n"
"qualcosa di interessante sul   \n"
"deserto. L'ho origliato mentre\n"
"parlavano dei Gerudo."
BOX_BREAK
UNSKIPPABLE "Dicevano, \"Per attraversare le   \n"
"Terre Infestate, dovrai avere \n"
"l''" COLOR(RED) "occhio della verita'" COLOR(DEFAULT) "'. Il Colosso\n"
"si trova ai limiti delle terre...\"."
BOX_BREAK
UNSKIPPABLE "OK, ora ritornero' alla    \n"
COLOR(RED) "tenda alla Valle Gerudo" COLOR(DEFAULT) ", vieni\n"
"a trovarmi quando vuoi. Potrai\n"
"trovare qualcosa di utile! Ciao!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Il leader di questa banda di ladri\n"
"é " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Sta sperimentando il\n"
"lavaggio del cervello su molta\n"
"gente, giu' alle rovine.  "
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, era Ganondorf il Re del  \n"
"Male che stava dietro la banda di\n"
"ladri... "
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando" COLOR(RED) " Nabooru" COLOR(DEFAULT) " era una ladra\n"
"solitaria, non rubava mai ai \n"
"deboli, ma...   " TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ora, la banda di ladri di Nabooru\n"
"é crudele e senza pieta'.   \n"
"Sostiene di essere una ladra\n"
"d'onore, ma...non é cosi'!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Come sospettavo, Nabooru é stata\n"
"condizionata dai seguaci\n"
"di Ganondorf."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nella societa' Gerudo, chi é un  \n"
"bravo cavaliere e un buon arciere é\n"
"rispettato da tutti...     " TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Perché non provi il tiro con\n"
"l'arco alla Fortezza Gerudo?    "
BOX_BREAK
"Se hai un cavallo, un Gerudo \n"
"della fortezza ti seguira' per \n"
"la tua sfida.  "
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sei stato un grande! Bravo!!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ora che siamo tornati insieme,\n"
"ricostruire il ponte spezzato,\n"
"é stata una passeggiata..."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Senza le vecchie streghe la banda\n"
"di ladri non é cosi' spaventosa!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La " COLOR(RED) "Fortezza dei Gerudo" COLOR(DEFAULT) " si trova \n"
"al di la' del cancello.\n"
"Non é un luogo per ragazzini...  "
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Sono un" COLOR(RED) " Mastro Artigiano" COLOR(DEFAULT) ".\n"
"Quei ladri Gerudos...\n"
"Hanno rotto il ponte! "
BOX_BREAK
UNSKIPPABLE "Vorrei aggiustarlo, ma i miei\n"
"uomini sono spariti!"
BOX_BREAK
UNSKIPPABLE "Mi dissero che fare i carpentieri\n"
"era noioso, e se ne andarono alla\n"
COLOR(RED) "Fortezza Gerudo" COLOR(DEFAULT) " per fare\n"
"i ladri... " TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, tu! Se stai andando alla    \n"
"fortezza, perché non provi a\n"
"vedere cosa combinano i miei\n"
"uomini laggiu'? "
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, hai salvato i miei uomini!\n"
"Con il loro aiuto, ho riparato\n"
"il ponte."
BOX_BREAK
"Guarda laggiu'!\n"
"Non é un buon lavoro? "
BOX_BREAK
"Saranno anche degli ingenui,  \n"
"ma una volta  al lavoro, sono  \n"
"dei buoni carpentieri."
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Ehi, quella sega! E' mia!"
BOX_BREAK
UNSKIPPABLE "Ma....Pensavo di averla lasciata\n"
"alla mia vecchia...Va bene... " TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I miei attrezzi Biggoron sono rotti,\n"
"sto andando a Goron City\n"
"a ripararli."
BOX_BREAK
"Sei arrivato al momento giusto!\n"
"Mi ridai la mia sega?   \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x47")  QUICKTEXT_ENABLE "Cosa?!\n"
SHIFT("\x14") "Tu brutto, infame ladro!     " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo é un " COLOR(RED) "luogo d'allenamento\n"
COLOR(DEFAULT) " Gerudo. Ammesse solo persone  \n"
"qualificate."
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo é un " COLOR(RED) "luogo d'allenamento\n"
COLOR(DEFAULT) " Gerudo. Puoi entrare... \n"
"Vieni e testa le tue abilita'\n"
"quanto vuoi...      " EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Questo é un " COLOR(RED) "luogo d'allenamento\n"
COLOR(DEFAULT) " Gerudo. Anche se sei\n"
"autorizzato, non arraffare tutti i\n"
"tesori solo per te stesso! "
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, che peccato... "
BOX_BREAK
"Il segno che ti condurra' al Tempio\n"
"dello Spirito é la " COLOR(RED) "bandiera\n"
"a sinistra" COLOR(DEFAULT) " dopo il negozio."
BOX_BREAK
"Se cambi idea, vieni pure a\n"
"trovarmi di nuovo! "
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh, non hai le Rupié. \n"
"Non si fanno sconti qui.   "
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh.\n"
"Sei gia' impegnato in qualche   \n"
"cosa, non é vero?     "
BOX_BREAK
"Se vuoi scontrarti con me, devi \n"
"avere la mente sgombra...     \n"
"Nessuna distrazione!        "
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x41") "Ben Venuto!"
BOX_BREAK
"Vendo articoli, strani e molto \n"
"rari, provenienti dal mondo\n"
"e per tutti...\n"
"L'articolo di oggi é... "
BOX_BREAK
"Un oggetto veloce e letale!\n"
"Terrificante!\n"
"Non ti diro' cos'é fino a quando\n"
"non vedro' i soldi..."
BOX_BREAK
"Costa solo" COLOR(RED) " 200 Rupié" COLOR(DEFAULT) "!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Compra\n"
"Lascia" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grazie molte!       "
BOX_BREAK
"  Ti ho venduto una..." TEXT_SPEED("\x02")  COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" TEXT_SPEED("\x00")
BOX_BREAK
"Il segno che ti condurra' al\n"
"Tempio dello Spirito é la " COLOR(RED) "bandiera\n"
"a sinistra" COLOR(DEFAULT) " fuori al negozio.\n"
"Ci si vede! "
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ehi, cosa c'é, " NAME "? \n"
"Sorpreso di vedermi?"
BOX_BREAK
UNSKIPPABLE "Lunghi anni in questo mondo\n"
"sono quasi niente per te, eh? \n"
"Che strano!    "
BOX_BREAK
UNSKIPPABLE "Persino io credevo che la storia\n"
"di un ragazzo che poteva\n"
"viaggiare nel tempo, fosse solo\n"
"una leggenda!!"
BOX_BREAK
UNSKIPPABLE  NAME ", sei davvero maturato,\n"
"sei un adulto." TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"D'ora in poi, il futuro di tutta la\n"
"gente di Hyrule é sulle tue\n"
"spalle... "
BOX_BREAK
"Forse non ci rivedremo piu'...\n"
"E' il mio ultimo avviso. "
BOX_BREAK
"Due streghe vivono nel tempio.\n"
"Per sconfiggerle, " COLOR(RED) "dovrai usare la loro  \n"
"stessa magia" COLOR(DEFAULT) "!                \n"
"Hoo hoot!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vuoi risentire cio' che\n"
"ho detto?     \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Continuero' a controllarti...  \n"
"Hoo hoo hoo hoot!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Sono il corridore vagabondo!  \n"
"Ho corso lungo queste terre in\n"
"cerca di una vera competizione... "
BOX_BREAK
UNSKIPPABLE "Ho vinto tutte le mie gare,\n"
"sinora...    "
BOX_BREAK
UNSKIPPABLE "Mi sembri un tizio atletico e  \n"
"sembri possedere un vero      \n"
"istinto killer...     "
BOX_BREAK
UNSKIPPABLE "Ora che il ponte della Valle é \n"
"stato riparato, sono alla ricerca  \n"
"di un avversario per una\n"
"corsa commemorativa...    " TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Il tempo migliore, da qui sino al\n"
COLOR(ADJUSTABLE) "ponte dei Boschi Perduti" COLOR(DEFAULT) " é stato\n"
COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ".  E' il mio record."
BOX_BREAK
"Vuoi provare ad abbaterlo?   \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ottimo!\n"
"Allora... "
BOX_BREAK
"Vai prima tu.\n"
"Ti daro' un vantaggio. "
BOX_BREAK
"Ora! " TEXT_SPEED("\x02") "Vai avanti. " TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Non scoprirai mai il tuo\n"
"istinto di killer in questo\n"
"modo. Bah...     "
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Bene, non perfetto, ma sei\n"
"stato in gamba! Mi dispiace,\n"
"ma non mi batterai mai. Il\n"
"tuo record appartiene al passato."
BOX_BREAK
"Ci hai messo: " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ", giusto?   \n"
"Beh, non male, ma ho vinto io\n"
"per un secondo!" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Prego.  " TEXT_SPEED("\x02") "Vai pure." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Oh, sembra tu abbia mollato...   \n"
"Heh heh heh. scommeto che hai   \n"
"riscoperto il tuo istinto killer!   " FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh.\n"
"Non hai abbastanza istinto \n"
"killer ancora."
BOX_BREAK
"Allenati di piu'. \n"
QUICKTEXT_ENABLE "Ciao-Ciao!     " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Huff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "puff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "huff..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")
BOX_BREAK
"Huff...huff...phew!\n"
"Sei stato bravo!   "
BOX_BREAK
"Ma non vicerai mai!\n"
"Ci hai messo solo: " COLOR(RED)  MARATHON_TIME  COLOR(DEFAULT) ", ma Io\n"
"ho vinto per un solo secondo!"
BOX_BREAK
"Huff...huff... \n"
"Devi sfidarmi ancora,      \n"
"prima o poi!   "
BOX_BREAK
"Huff...huff...\n"
QUICKTEXT_ENABLE "Ciao-Ciao!     " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Sono il corridore vagabondo!  \n"
"Ho corso lungo queste terre alla\n"
"ricerca di un avversario con un\n"
"vero istinto killer! "
BOX_BREAK
"Sono venuto a correre nelle    \n"
"Terre Infestate, ma non sembra un\n"
"buon momento per correre adesso."
BOX_BREAK
"Vorrei ritornare nei Campi \n"
"Erbosi, ma il ponte é...beh, lo puoi\n"
"vedere da te li' fuori. Cosi' \n"
"sono bloccato in questa tenda."
BOX_BREAK
"Non penso che accettero' la tua\n"
"sfida per ora...    \n"
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
"Non riesco a prenderlo!  "
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huff huff! \n"
"Sono in ritardo!!  \n"
"L'appuntamento mi perdo!  "
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Benvenuto alla Citta' del Castello\n"
"Una pacifica, ridente citta'."
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"I ragazzini non devono\n"
"vagabondare a notte fonda!\n"
"Forza, tornatene a casa!!      "
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che barba, che noia...\n"
"Le cose andrebbero meglio\n"
"se ci fossero piu' guai nel mondo,\n"
"é tutto cosi' calmo..."
BOX_BREAK
"Ehi, che questo rimanga\n"
"tra te e me, OK?"
BOX_BREAK
"Comunque, ti puoi dar da fare\n"
"rompendo un po' di queste   \n"
"giare."
BOX_BREAK
"Mettiti di fronte e premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " le \n"
"alzerai. Premi " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e le lancerai!   "
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Grandioso!   "
BOX_BREAK
UNSKIPPABLE "Ah, dimenticavo...     " EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Sta succedendo qualcosa di grosso\n"
"al castello. Non posso far\n"
"entrare nemmeno un cane!!    \n"
"       " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Unnngh...Sei il ragazzo\n"
"della foresta...?    "
BOX_BREAK
UNSKIPPABLE "F-F-Finalmente ci incontriamo \n"
"D-D-Devo dirti u-u-una cosa...\n"
"     "
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", Il Re Gerudo dei\n"
"Ladri, ha tradito il nostro RE."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) " la governante di Zelda ha\n"
"fiutato il pericolo ed é scappata   \n"
"dal Castello..."
BOX_BREAK
UNSKIPPABLE "Ho provato a fermare gli uomini\n"
"di Ganondorf...Ma...      "
BOX_BREAK
UNSKIPPABLE "La Principessa...Aspettava un\n"
"ragazzo della foresta... cioe' te...  \n"
"Voleva dargli assolutamente\n"
COLOR(RED) "qualcosa" COLOR(DEFAULT) "...   "
BOX_BREAK
UNSKIPPABLE "Se l'hai ricevuta dalla Principessa,  \n"
TEXT_SPEED("\x03")  QUICKTEXT_ENABLE "presto..." QUICKTEXT_ENABLE "vai al" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tem" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "pio" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "del Tempo" COLOR(DEFAULT) "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Non si muovera' piu'...    "
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vedi quell'uomo dagli \n"
"occhi cattivi?   "
BOX_BREAK
UNSKIPPABLE "Lui e' " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", leader dei    \n"
"Gerudos. Viene dal lontano       \n"
"deserto dell'ovest... "
BOX_BREAK
UNSKIPPABLE "Sebbene desideri allearsi con mio\n"
"padre, sono sicura che non sia\n"
"sincero."
BOX_BREAK
UNSKIPPABLE "Le nuvole scure che coprirono\n"
"Hyrule nel mio sogno,\n"
"rappresentavano quell'uomo!  "
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0E") "Geh heh heh! Ottimo lavoro! " BOX_BREAK_DELAYED("\x3C")  SHIFT("\x14") "Come pensavo, avevi le chiavi\n"
SHIFT("\x26") "per la Porta del Tempo." BOX_BREAK_DELAYED("\x5A")  SHIFT("\x05") "Mi hai condotto alle porte del\n"
SHIFT("\x2D") "Sacro Reame...     " BOX_BREAK_DELAYED("\x50")  SHIFT("\x10") "Si, devo tutto a te, piccolo! " FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Per favore! Se non ti\n"
"sbrighi, va via!    " EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti prego..con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Pieta' vendimi il" COLOR(RED) " contenuto" COLOR(DEFAULT) "\n"
"della bottiglia. Ti prego usa " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". "
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che strano negozio!  \n"
"Mi chiedo quando sia aperto per\n"
"vendere. Ho letto il cartello, ma\n"
"resta comunque strano!   "
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sembra che potremmo attendere  \n"
"l'alba per sempre... "
BOX_BREAK
"La vista del Castello con il \n"
"sole del mattino e' fantastica! "
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Per salvare la ragazza, ti serve un\n"
COLOR(RED) "Item magico" COLOR(DEFAULT) "...\n"
"Vai al Villaggio Kakariko!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai l'Item che ti serviva...\n"
"La " COLOR(ADJUSTABLE) "ragazza della foresta" COLOR(DEFAULT) "\n"
"aspetta per il tuo aiuto...          "
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se vuoi delle pozioni,sara' meglio\n"
"che porti una bottiglia vuota,\n"
"Hai capito?   " PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Mi spiace, ma é solo per esposizione.\n"
"A causa della crisi a Goron    \n"
"City, non abbiamo ricevuto \n"
"nuovo materiale, tutto finito.    " PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se vuoi scalare la Montagna\n"
"della Morte uno  " COLOR(LIGHTBLUE) "Scudo Hylian" COLOR(DEFAULT) ", \n"
"ti sara' utile per difenderti  \n"
"dalla caduta dei massi.        "
BOX_BREAK
"Ma mi sembra grosso per te   \n"
"ragazzino...     " PERSISTENT
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"No, non sto danzando...\n"
"Mi fa male la schiena!\n"
"Ooh! Aah! Ooh!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dicono che noi " COLOR(LIGHTBLUE) "Hylians" COLOR(DEFAULT) " abbiamo\n"
"grandi orecchie per ascoltare\n"
"la voce degli Dei...\n"
"L'avessi mai sentita!"
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, sei mai stato al \n"
COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Il loro latte e' delizioso! \n"
"Ci sono molti cavalli, e\n"
"la giovane figlia del proprietario\n"
"é molto carina!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Per il " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) ", vai     \n"
"sempre a sud, dopo la citta', \n"
"attraversa i campi e vedrai sicu- \n"
"ramente il Ranch!       "
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Volevo vedere la" COLOR(RED) " Principessa" COLOR(DEFAULT) "!  "
BOX_BREAK
UNSKIPPABLE "Schivai le guardie...  "
BOX_BREAK
UNSKIPPABLE "Nuotai nel fossato...   "
BOX_BREAK
UNSKIPPABLE "Ce l'avevo quasi fatta\n"
"ma mi presero!  " TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Trovai un " COLOR(RED) "buco di scarico" COLOR(DEFAULT) " sulla  \n"
"destra del castello e pensai di\n"
"potermi infilare dentro, ma rimasi\n"
"bloccato li'..."
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE
BOX_BREAK
SHIFT("\x05") "Questa barba é il mio orgoglio!\n"
SHIFT("\x07") "Non ti sembra sia bella folta?! "
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SHIFT("\x05") "Questa barba é il mio orgoglio!\n"
SHIFT("\x07") "Non ti sembra sia bella folta?! "
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x51") "Cosa?!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Stai cercando il tizio\n"
"del Lon Lon Ranch?     "
BOX_BREAK
UNSKIPPABLE "Hmm, forse..." TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho visto" COLOR(RED) " un tizio con una barba\n"
"curata " COLOR(DEFAULT) "che consegnava scatole\n"
"al castello... "
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Conosci la storia del " COLOR(LIGHTBLUE) "Tempio\n"
"del Tempo" COLOR(DEFAULT) " che si trova nella \n"
"parte nord della citta?" TEXTID("\x70\x1E")
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La leggenda dice che il Tempio\n"
"sia l'entrata per il        \n"
"Sacro Reame... "
BOX_BREAK
"Lo sapevi questo? "
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha! Che pazzoide!    "
BOX_BREAK
UNSKIPPABLE "Ci crederesti che questo pazzo  \n"
"abbia provato a strisciare nel\n"
"castello della " COLOR(RED) "Principessa Zelda" COLOR(DEFAULT) "?" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' stato talmente idiota che l'hanno\n"
"preso e legato come un salame.  \n"
"Wha-ha-hah!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ho fatto molti soldi! "
BOX_BREAK
UNSKIPPABLE "Forse dovrei provare a \n"
"vendere piu' cose!!    " TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lo so! Dovrei andare a " COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) "!\n"
"Molte cose galleggiano sul fiume\n"
"e finiscono li'! \n"
"Hah hah!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ehi, boscaiolo! Sei nella " COLOR(LIGHTBLUE) "Citta' \n"
"di Hyrule" COLOR(DEFAULT) "! Non perdere tempo,\n"
"goditi la vista! " TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se sei venuto per andare al " COLOR(LIGHTBLUE) "\n"
"Castello" COLOR(DEFAULT) ", prendi la strada sulla\n"
"destra."
BOX_BREAK
"Se invece vuoi vedere i" COLOR(BLUE) "    \n"
"Vicoli" COLOR(DEFAULT) " della citta', prendi\n"
"la strada a sinistra."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..."
BOX_BREAK
"Sei cosi'...Bello...    "
BOX_BREAK
"Proprio come il Re di Hyrule..."
BOX_BREAK
"Hee hee..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..."
BOX_BREAK
"Tu sei... "
BOX_BREAK
"piu ' bella..."
BOX_BREAK
"della Principessa Zelda.."
BOX_BREAK
"Ohh..."
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hai mai sentito la leggenda del\n"
"\"Popolo Ombra\"?"
BOX_BREAK
UNSKIPPABLE "Sono detti " COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "...\n"
"Le ombre degli Hylians...   "
BOX_BREAK
UNSKIPPABLE "Si dice abbiano fatto un patto con\n"
"il Re di Hyrule e proteggano\n"
"la Famiglia Reale."
BOX_BREAK
UNSKIPPABLE "Ma con la pace che regna,\n"
"nessuno ha piu' visto\n"
"uno Sheikah da lungo tempo.     \n"
UNSKIPPABLE "Pero'...  " TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho sentito di una donna" COLOR(BLUE) " Sheikah\n"
COLOR(DEFAULT) "che vive nel castello...   "
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E cosi' vuoi vedere la \n"
COLOR(RED) "Principessa Zelda" COLOR(DEFAULT) ", eh?"
BOX_BREAK
"Probabilmente hai sentito di Lei\n"
"in citta' e hai deciso di\n"
"incontrarla...Bene. "
BOX_BREAK
QUICKTEXT_ENABLE "A CASA! " QUICKTEXT_DISABLE "V" QUICKTEXT_ENABLE "ai subito via!  " QUICKTEXT_DISABLE "\n"
"La Principessa non concedera'\n"
"mai udienza a uno come te!!      "
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z...."
BOX_BREAK
"Mumble mumble..."
BOX_BREAK
"Salve... Il ranch e' divertente."
BOX_BREAK
"Date pure un'occhiata..."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2D") "Ma che diavolo?   " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Non si puo' schiacciare un  \n"
"pisolino qui intorno?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ciao, e tu chi saresti?   "
BOX_BREAK
UNSKIPPABLE "Yep, sono " COLOR(RED) "Talon" COLOR(DEFAULT) ", il padrone del\n"
"Lon Lon Ranch."
BOX_BREAK
UNSKIPPABLE "Sono venuto al castello per con-\n"
"segnare del latte, ma una volta \n"
"seduto mi sono addormentato...    "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x4C")  SFX("\x68\x52") "COSA?!\n"
"Malon mi sta cercando?   \n"
"Devo subito andarla a prendere! "
BOX_BREAK
UNSKIPPABLE "Ho sbagliato a lasciarla da   \n"
"sola ad aspettarmi!!  "
BOX_BREAK
UNSKIPPABLE "Malon adesso ha bisogno di me!!   " EVENT
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Ehi tu! STOP!!\n"
SHIFT("\x28") "Tu, ragazzo, laggiu'!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x5F") "!" BOX_BREAK_DELAYED("\x0A")  UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Chi?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Chi sei tu??"
BOX_BREAK
UNSKIPPABLE "Come sei riuscito ad entrare?   " EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ce l'hai?       \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, e' strano... \n"
"Pensavo fossi proprio\n"
"quello del sogno...      \n"
"Sicuro di non averla?    "
BOX_BREAK
"Dimmi la verita'... " EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D") "Come pensavo!!    " EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ti prego tienilo segreto a    \n"
"chiunque...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"E dai...Non fare il pettegolo!   " EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Questa e' la leggenda...    " EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x12") "Le tre Divinita' celarono la\n"
SHIFT("\x0D")  COLOR(RED) "Triforza" COLOR(DEFAULT) ", contenente il potere\n"
SHIFT("\x0D") "degli Dei nel regno di Hyrule." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x38") "Il potere\n"
SHIFT("\x03") "di far divenire reali i desideri\n"
SHIFT("\x16") "di colui che la possiede.       " BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x03") "Se colui che esprime il desiderio\n"
SHIFT("\x10") "ha un cuore puro, allora, il   \n"
SHIFT("\x09") "futuro del regno sara' di pace...  " BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x06") "Ma se lo esprime colui che ha\n"
SHIFT("\x0A") "un cuore nero, allora, il male \n"
SHIFT("\x16") "consumera' il mondo...\n"
SHIFT("\x0A") "   Questo é stato scritto...     " BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x16") "   Gli Antichi costruirono \n"
SHIFT("\x02") "il " COLOR(LIGHTBLUE) "Tempio del Tempo " COLOR(DEFAULT) "per proteggere \n"
SHIFT("\x20") " la Triforza dal Male." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Si e' cosi'... Il Tempio del Tempo\n"
"e' l'entrata attraverso la quale \n"
"accedere al Sacro Reame dal\n"
"nostro mondo. "
BOX_BREAK
"Ma l'entrata é sigillata da\n"
"un muro di pietra, la... \n"
COLOR(LIGHTBLUE) "Porta del Tempo" COLOR(DEFAULT) "!"
BOX_BREAK
"E, per poterla aprire, fu stabi-\n"
"lito fosse necessario possedere\n"
"le tre " COLOR(RED) "Pietre Spirituali" COLOR(DEFAULT) ". "
BOX_BREAK
"E anche un altra cosa...\n"
"E' un tesoro che la Famiglia Reale \n"
"detiene dal tempo della leggenda...  " EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, spiacente.\n"
"Non sono brava a raccontare le storie" EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "Cos'é successo?" QUICKTEXT_DISABLE " Ti ha visto?  "
BOX_BREAK
UNSKIPPABLE "Non temere. "
BOX_BREAK
UNSKIPPABLE "Non ha nessuna idea dei   \n"
"nostri piani...         " EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Credimi\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Non, non ti credo.  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42") "Grazie!   " EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La mia governante ti guidera'\n"
"fuori dal castello.\n"
"Non aver paura di parlarle. "
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La Pietra Spirituale...\n"
"Alla fine l'hai trovata!"
BOX_BREAK
"E' stato detto che la razza che\n"
"detiene la Pietra Spirituale\n"
"si fidera' solo di colui che sa la\n"
COLOR(BLUE) "melodia della Famiglia Reale" COLOR(DEFAULT) "."
BOX_BREAK
"Ma questo gia' lo sapevi,    \n"
"vero?"
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, avete sentito delle\n"
"profetiche visioni avute nei\n"
"sogni dalla Principessa?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh? Cosa? Via, ragazzino! "
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ci sono tre piccole nicchie \n"
"ed una iscrizione...   "
BOX_BREAK
QUICKTEXT_ENABLE "Con le tre pietre dello Spirito" COLOR(BLUE) "\n"
COLOR(DEFAULT) "e la sacra " COLOR(LIGHTBLUE) "Ocarina del Tempo" COLOR(DEFAULT) ",\n"
COLOR(DEFAULT) "suona la " COLOR(LIGHTBLUE) "Canzone del Tempo" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
"Questo é cio' che c'é scritto... " EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E dai, almeno un\n"
"piccolo sconticino!?"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, lascia! E' mia!   \n"
"L'ho trovata io! "
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, chi spinge?!   "
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non ci sono mai molti Gerudos\n"
"da queste parti...\n"
"C'é qualcosa che non va!   "
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non era la Principessa Zelda\n"
"su quel cavallo bianco?! "
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quel cavallo nero mi ha    \n"
"scalciato!  "
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quel tizio in groppa al cavallo\n"
"nero doveva essere Ganondorf,\n"
"meglio conosciuto come\n"
"Re Gerudo dei ladri... "
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa succede?! "
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Guardalo come si é spaventato!   \n"
"Che fesso!  \n"
"Ha ha hah!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho la sensazione che stia\n"
"per succedere qualcosa di brutto.\n"
"Meglio lasciare la citta'... "
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' successo qualcosa al castello!\n"
"Ragazzo, stai molto attento! "
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Con la " COLOR(RED) "chiave" COLOR(DEFAULT) ", procedi nella\n"
"stanza piu' avanti!  "
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quello in groppa al cavallo bianco\n"
"che teneva la bambina... \n"
"Non era un leggendario Sheikah? "
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D")  NAME "..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x45") "Sveglia...\n"
SHIFT("\x1D")  NAME ", sei tu l'eletto.."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sono " COLOR(RED) "Rauru" COLOR(DEFAULT) ", uno degli antichi \n"
"Saggi..."
BOX_BREAK
UNSKIPPABLE "Ere fa, noi Antichi Saggi\n"
"costruimmo il Tempio del Tempo\n"
"per proteggere l'entrata\n"
"al Sacro Reame..."
BOX_BREAK
UNSKIPPABLE "Questa é la " COLOR(RED) "Camera dei Saggi" COLOR(DEFAULT) "," COLOR(RED) " \n"
COLOR(DEFAULT) "dentro il Tempio della Luce..."
BOX_BREAK
UNSKIPPABLE "Il Tempio della Luce, si trova \n"
"nel centro del Sacro Reame, ed \n"
"é l'ultima roccaforte contro \n"
"le forze del male di Ganondorf. "
BOX_BREAK
UNSKIPPABLE "La " COLOR(RED) "Spada Suprema" COLOR(DEFAULT) ", (la spada\n"
"ammazza-demoni che hai estratto \n"
"dal Piedistallo del Tempo), era\n"
"la chiave finale per il Sacro Reame."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Non ti allarmare...\n"
"Guardati bene...!   "
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x33")  COLOR(LIGHTBLUE) "Ehi " NAME "!!\n"
COLOR(DEFAULT)  SHIFT("\x32")  COLOR(LIGHTBLUE) "Sei grande ora!!\n"
COLOR(DEFAULT)  SHIFT("\x31")  COLOR(LIGHTBLUE) "Sei cresciuto!  " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La Spada Suprema ha una lama\n"
"sacra che i demoni non possono\n"
"toccare..."
BOX_BREAK
UNSKIPPABLE "Solo colui che diverra'  \n"
"l' \"Eroe del Tempo" COLOR(DEFAULT) "\"" COLOR(RED) " " COLOR(DEFAULT) "puo' estrarla dal  \n"
"Piedistallo del Tempo... "
BOX_BREAK
UNSKIPPABLE "Tu eri troppo giovane per essere  \n"
"l'Eroe del Tempo... "
BOX_BREAK
UNSKIPPABLE "Percio', il tuo spirito é\n"
"stato sigillato per sette anni."
BOX_BREAK
UNSKIPPABLE "E ora che sei cresciuto,       \n"
"é venuto il tempo di risve-\n"
"gliarti" COLOR(RED) " " COLOR(DEFAULT) "come Eroe del Tempo!"
BOX_BREAK
"Bene, hai compreso il tuo    \n"
"destino?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bene, sembri ancora un po'   \n"
"confuso... Ti rispieghero'  \n"
"tutto, dall'inizio.       " TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ma, ricorda... "
BOX_BREAK
UNSKIPPABLE "Anche se hai aperto la Porta\n"
"del Tempo in nome della pace..."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", il Re Gerudo dei  \n"
"Ladri, l'ha usata per accedere\n"
"al Sacro Reame proibito!"
BOX_BREAK
UNSKIPPABLE "Ha rubato la TriForza dal    \n"
"Tempio della Luce, e con il suo \n"
"potere, é divenuto il " COLOR(RED) "Re del Male" COLOR(DEFAULT) "...  "
BOX_BREAK
UNSKIPPABLE "Una Forza Oscura si é         \n"
"irradiata dal tempio di Hyrule, e\n"
"in soli 7 anni, ha trasformato\n"
"Hyrule in un mondo di mostri."
BOX_BREAK
UNSKIPPABLE "Il mio potere ha ben poca    \n"
"influenza, persino nel Sacro  \n"
"Reame..."
BOX_BREAK
UNSKIPPABLE "Ovvero nella Camera dei Saggi."
BOX_BREAK
UNSKIPPABLE "Ma c'é ancora una speranza..."
BOX_BREAK
UNSKIPPABLE "Rimane il potere dei Saggi. "
BOX_BREAK
UNSKIPPABLE "Quando il potere dei " COLOR(RED) "Saggi \n"
COLOR(DEFAULT) "sara' risvegliato,"
BOX_BREAK
UNSKIPPABLE "il " COLOR(RED) "Sigillo dei Saggi" COLOR(DEFAULT) " conterra'\n"
"tutta la forza del male al posto \n"
"del Reame..."
BOX_BREAK
UNSKIPPABLE "Io, Rauru, sono uno degli Antichi.\n"
"E..."
BOX_BREAK
UNSKIPPABLE "Combattendo con i Saggi al tuo    \n"
"fianco diverrai l'" COLOR(RED) "Eroe del Tempo" COLOR(DEFAULT) "!   "
BOX_BREAK
UNSKIPPABLE "L'Eroe del Tempo, scelto dalla \n"
"Sacra Lama!   "
BOX_BREAK
UNSKIPPABLE "Prendi il mio Spirito...  \n"
"E, trova il potere degli altri  \n"
"Saggi per divenire ancora\n"
"piu' forte!!"
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "...Siamo tornati nel\n"
COLOR(DEFAULT) "Tempio del Tempo" COLOR(LIGHTBLUE) ".\n"
"Ma sono passati davvero\n"
COLOR(DEFAULT) "sette anni" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sembra tu non sia in grado\n"
"di usare alcune delle " COLOR(DEFAULT) "armi" COLOR(LIGHTBLUE) "  \n"
"che hai trovato da ragazzino... "
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Dai usciamo fuori ora!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehiii, ma cosa? \n"
"Cosa c'e' di sbagliato nel \n"
"bighellonare?  "
BOX_BREAK
"Huh, ehi?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti stavo aspettando,    \n"
"Eroe del Tempo... "
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando il male e' ovunque, dal \n"
"Sacro Reame si leva una voce che  \n"
"risveglia gli antichi Saggi,\n"
"che dimorano nei " COLOR(RED) "Cinque Templi" COLOR(DEFAULT) ".   "
BOX_BREAK
UNSKIPPABLE "Uno in una " COLOR(ADJUSTABLE) "foresta" COLOR(DEFAULT) "...  "
BOX_BREAK
UNSKIPPABLE "Uno in una " COLOR(RED) "montagna" COLOR(DEFAULT) "...   "
BOX_BREAK
UNSKIPPABLE "Uno sotto un " COLOR(BLUE) "lago" COLOR(DEFAULT) "...    "
BOX_BREAK
UNSKIPPABLE "Uno nei " COLOR(PURPLE) "Monti della morte" COLOR(DEFAULT) "...       "
BOX_BREAK
UNSKIPPABLE "Uno dalla " COLOR(YELLOW) "Dea delle sabbie" COLOR(DEFAULT) "...      "
BOX_BREAK
UNSKIPPABLE "Insieme all'Eroe del Tempo, i   \n"
"risvegliati scacceranno il male\n"
"e ritornera' la luce della pace   \n"
"sul mondo...   "
BOX_BREAK
UNSKIPPABLE "Questa é la leggenda dei templi\n"
"ereditata dal mio popolo, gli  \n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, spiacente.\n"
"Non siamo ancora aperti.        \n"
"Ritorna presto!       " EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Usa la " COLOR(RED) "Spada Suprema" COLOR(DEFAULT) "!\n"
"Distruggi Ganon con la\n"
"spada sacra!!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ti stavo aspettando,        \n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", l'Eroe del Tempo..."
BOX_BREAK
UNSKIPPABLE "Hai superato molte avversita'\n"
"e hai svegliato i sei Saggi."
BOX_BREAK
UNSKIPPABLE "E ora ti aspetta lo scontro\n"
"finale, il duello con  \n"
"Ganondorf, il Re del Male....  "
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x10") "Se vuoi trovare il sacro\n"
SHIFT("\x10") "triangolo, ascoltami bene..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x09") "Il luogo ove si trova il sacro \n"
SHIFT("\x03") "triangolo, Il Sacro Reame, é uno\n"
SHIFT("\x14") "specchio in cui si riflette \n"
SHIFT("\x3B") "il cuore...    " BOX_BREAK_DELAYED("\x46")  UNSKIPPABLE  SHIFT("\x09") "Il cuore di colui che vi entra...\n"
SHIFT("\x04") "Se é malvagio, il Reame diverra'\n"
SHIFT("\x14") "un vero inferno. Se é puro,  \n"
SHIFT("\x04") "il Reame diverra' un paradiso.   " BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x02") "La Triforza...Il Sacro Triangolo...  \n"
SHIFT("\x0A") "é bilanciata dall'unione delle \n"
SHIFT("\x3F") "tre forze:\n"
SHIFT("\x0A") "Potere, Saggezza e Coraggio. " BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x0A") "Se il cuore di colui che detiene \n"
SHIFT("\x06") "il sacro triangolo possiede tutte\n"
SHIFT("\x12") "  e tre le forze bilanciate, \n"
SHIFT("\x03") "otterra' la Vera Forza per gestirle. " BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x06") "Ma, se quel cuore non é bilanciato\n"
SHIFT("\x07") "      la Triforza si separera'     \n"
SHIFT("\x3F") "in tre parti: \n"
SHIFT("\x13") "Potere, Saggezza e Coraggio. " BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x04") "Solo una parte rimarra' a colui  \n"
SHIFT("\x07") "che tocchera' la Triforza...La\n"
SHIFT("\x01") "parte che rappresenta la Forza in\n"
SHIFT("\x16") "cui noi tutti crediamo. " BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x04") "Colui che ricerca la Vera Forza, \n"
SHIFT("\x0F") "  dovra' ritrovare le due\n"
SHIFT("\x28") "parti mancanti." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x12") "Queste due parti le avranno \n"
SHIFT("\x07") "i prescelti dal destino, coloro \n"
SHIFT("\x0A") "che portano il marchio della \n"
SHIFT("\x11") "Triforza sulle loro mani...   " FADE("\x5A")
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sette anni fa, Ganondorf, il  \n"
"Re dei Ladri, passo' la porta\n"
"che tu apristi nel Tempio del Tempo \n"
"ed entro' nel Sacro Reame... "
BOX_BREAK
UNSKIPPABLE "Ma quando prese la Triforza, la \n"
"leggenda divenne una realta'.   "
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Colui che porta la " COLOR(RED) "Triforza del\n"
"Coraggio" COLOR(DEFAULT) "...\n"
"Sei Tu, " NAME "!  "
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E l'altro, che porta la \n"
COLOR(RED) "Triforza della Saggezza" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "E' il settimo Saggio, che é\n"
"destinato ad essere il capo \n"
"di tutti..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sono Io, \n"
"la Principessa " COLOR(RED) "Zelda" COLOR(DEFAULT) ".        "
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mi scuso per averti incontrato \n"
"camuffata, ma era necessario per\n"
"nascondersi dal Re del Male.\n"
"Ti prego perdonami..."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Ti vidi mentre scappavo dal \n"
"castello con la mia    \n"
"governante, Impa." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non appena prendesti l'Ocarina,\n"
"io credetti che Ganondorf non\n"
"sarebbe mai riuscito ad entrare\n"
"nel Sacro Reame, ma..."
BOX_BREAK
UNSKIPPABLE "Successe qualcosa di      \n"
"inaspettato..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x24") "Quel rumore...E' impossibile!"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Principessa Zelda!\n"
"...Tu Traditore!!  "
BOX_BREAK
UNSKIPPABLE "Te la sei cavata ad evitare le\n"
"mie ricerche per sette anni. "
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se vuoi salvare Zelda,\n"
"vieni al mio castello!! "
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...Mi puoi sentire?\n"
"Sono Rauru, il Saggio."
BOX_BREAK
UNSKIPPABLE "Noi sei Saggi ti daremo il \n"
"potere di creare un ponte sino\n"
"al castello di Ganondorf..."
BOX_BREAK
UNSKIPPABLE "Il castello, meglio conosciuto\n"
"come Torre di Ganon, é \n"
"protetto da " COLOR(RED) "Sei Barriere Maligne" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Abbattile tutte e sei e salva\n"
"la Principessa Zelda!! "
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
"Antichi Creatori di Hyrule!" BOX_BREAK_DELAYED("\x3C") "Ora, aprite il Passaggio \n"
"e mandate l'Incarnazione delle  \n"
"Tenebre nel vuoto del  \n"
"Regno del Male!!  " FADE("\x5A")
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "!\n"
"Finiscilo con la spada del     \n"
"tempo, la Spada Suprema!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh Passaggio aperto dai     \n"
"Saggi...Chiuditi per sempre \n"
"insieme all'Incarnazione delle\n"
"Tenebre!!  "
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Grazie, " NAME "...   "
BOX_BREAK
UNSKIPPABLE "Per merito tuo, Ganondorf é \n"
"stato sigillato nel Regno del Male!"
BOX_BREAK
UNSKIPPABLE "La pace ritornera' ancora\n"
"una volta, nel mondo...Per un po'."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x3C") "Grazie...   \n"
SHIFT("\x40")  NAME "..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  SHIFT("\x32") "Addio......." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Insomma vuoi proprio passare\n"
"oltre il cancello eh? Fammi pensare, \n"
"va bene...Ma in cambio...       " TEXTID("\x70\x72")
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dammi 10 Rupié.     \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ti prego credimi...  \n"
"Le mie profezie non\n"
"sbagliano mai!  " EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hai sconfitto le malvage\n"
"creature che infestavano il Tempio\n"
"e hai svegliato il Saggio..."
BOX_BREAK
UNSKIPPABLE "Ma ci sono altri Saggi che\n"
"hanno bisogno di te."
BOX_BREAK
UNSKIPPABLE "Per svegliare tutti gli altri  \n"
"Saggi, devi diventare ancora\n"
"piu' potente."
BOX_BREAK
UNSKIPPABLE "Devi viaggiare sulle\n"
"montagne... "
BOX_BREAK
"Sott'acqua... "
BOX_BREAK
"e persino nel tempo...  "
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sino a che avrai l'" COLOR(LIGHTBLUE) "Ocarina del\n"
"Tempo" COLOR(DEFAULT) " e la " COLOR(LIGHTBLUE) "Spada Suprema" COLOR(DEFAULT) ","
BOX_BREAK
UNSKIPPABLE "avrai il tempo stesso\n"
"nelle tue mani...   "
BOX_BREAK
UNSKIPPABLE  NAME ", ci rivedremo \n"
"ancora!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' un nuovo tipo di bomba! \n"
"E' disponibile solo in quantita'\n"
"limitata, e quando finira', \n"
"beh, ti saluto!" EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sono " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"Uno dei pochi Sheikahs...  "
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Appena ti ho visto brandire\n"
"la mitica " COLOR(RED) "Spada Suprema" COLOR(DEFAULT) ", ho\n"
"capito che eri il prescelto, il\n"
"leggendario Eroe del Tempo... "
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se credi alla leggenda, non hai\n"
"scelta. Devi cercare i cinque   \n"
"templi e risvegliare i      \n"
COLOR(RED) "Cinque Saggi" COLOR(DEFAULT) "...  "
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Un Saggio aspetta che tu lo     \n"
"risvegli nel" COLOR(ADJUSTABLE) " Tempio della Foresta" COLOR(DEFAULT) ".\n"
"Il Saggio é una ragazza e tu la\n"
"conosci."
BOX_BREAK
UNSKIPPABLE "A causa del potere maligno nel \n"
"tempio, non puo' udire il richiamo\n"
"che proviene dal Sacro Reame...\n"
" "
BOX_BREAK
UNSKIPPABLE "Sfortunatamente, non sei equipag-\n"
"giato bene, per poter entrare\n"
"nel tempio...     "
BOX_BREAK
UNSKIPPABLE "Ma, se hai creduto alle mie parole, \n"
"recati prima al " COLOR(RED) "Villaggio Kakariko" COLOR(DEFAULT) "...  "
BOX_BREAK
UNSKIPPABLE "Hai capito tutto,  \n"
NAME "?"
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Pensavo di potermi fidare a\n"
"lasciarti l'Ocarina...Pensavo, tu \n"
"fossi la nostra salvezza...  " FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prima di cio'...Devo dirti alcune\n"
"cose molto importanti.\n"
"Ascoltami ora."
BOX_BREAK
UNSKIPPABLE "Un altra leggenda poco conosciuta\n"
"sulla Triforza, narrata dal popolo\n"
"delle Ombre, dice..."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La Triforza fu separata in tre parti.\n"
"Solo la " COLOR(RED) "Triforza del Potere" COLOR(DEFAULT) " é ora\n"
"nelle mani di Ganondorf..."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "La potenza della Triforza del\n"
"Potere gli ha consentito di\n"
"divenire il Re del Male, ma non gli\n"
"basta per le sue ambizioni..."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Per ottenere il completo dominio\n"
"del mondo, Ganondorf sta cercando\n"
"i " COLOR(RED) "Prescelti dal Destino" COLOR(DEFAULT) " che hanno\n"
"le altre due parti di Triforza."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quel giorno di sette anni fa,\n"
"Ganondorf attacco' il Castello..."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dopo aver aperto la Porta del\n"
"Tempo, fosti sigillato nel Sacro\n"
"Reame dalla Spada Suprema..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il tuo Spirito rimase nel Sacro\n"
"Reame...E fu allora che la Triforza\n"
"fini' nelle mani di Ganondorf.\n"
"Pote' cosi' invadere il Sacro Reame."
BOX_BREAK
UNSKIPPABLE "E divenne il potente Re del\n"
"Male, riuscendo a trasformare  \n"
"il Sacro Reame in un inferno.\n"
"E' questo é quello che accadde..."
BOX_BREAK
UNSKIPPABLE "Mi feci passare per uno Sheikah \n"
"e sperai sempre nel tuo ritorno.\n"
"Ho aspettato sette anni... "
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E...Ora sei tornato.\n"
"L'era oscura del dominio di\n"
"Ganondorf, sta per finire!!    "
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I sei Saggi apriranno la porta\n"
"sigillata e attireranno Ganondorf    \n"
"nel Sacro Reame. "
BOX_BREAK
UNSKIPPABLE "A quel punto sigillero' la porta \n"
"di accesso a questo mondo.   "
BOX_BREAK
"Cosi, Ganondorf, il Re del Male,  \n"
"svanira' da Hyrule."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Ma per fare cio', ho bisogno ancora\n"
"del tuo coraggio. Proteggimi\n"
"e faro' la mia parte."
BOX_BREAK
UNSKIPPABLE "E qui c'é l'arma che potra'  \n"
"penetrare le difese del Re del Male...\n"
"Il potere concesso dal  \n"
"Prescelto... "
BOX_BREAK
UNSKIPPABLE  SHIFT("\x0F") "La sacra " COLOR(LIGHTBLUE) "Freccia della Luce" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ma hai abbassato la guardia...\n"
"Sapevo che saresti apparsa se lo\n"
"avessi lasciato girare!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il mio solo errore é stato quello\n"
"di sottovalutare il suo\n"
"potere...   "
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No...\n"
"Non il potere del ragazzino,\n"
"ma piuttosto, il potere della \n"
"Triforza del Coraggio!  "
BOX_BREAK
UNSKIPPABLE "Ma, con la Triforza della\n"
"Saggezza di Zelda...    \n"
"Ottenute queste due Triforze...     "
BOX_BREAK
UNSKIPPABLE "Diverro' l'unico e vero  \n"
"dominatore del mondo!! "
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "L'Ocarina del Tempo apri' la \n"
"porta. L'Eroe del Tempo, con la\n"
"Spada Suprema, discese da qui. " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non ti sembra strano che un \n"
"branco di cani giri per le strade, \n"
"durante la notte qui in citta'?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, piccolo, ti diro'\n"
"qualcosa di utile...   "
BOX_BREAK
"Ho sentito di una\n"
COLOR(RED) "misteriosa fontana" COLOR(DEFAULT) ", da qualche\n"
"parte al castello..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se vuoi tornare indietro nel \n"
"tempo, rimetti la Spada Suprema  \n"
"nel " COLOR(RED) "Piedistallo del Tempo" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE "Cosi' facendo, viaggierai indietro\n"
"nel tempo per sette anni..."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Verra' il momento in cui dovrai \n"
"tornare qui rapidamente... \n"
"Per \"volare\" sino a qui c'é una\n"
"particolare melodia...  "
BOX_BREAK
UNSKIPPABLE "La canzone per tornare al Tempio\n"
"del Tempo...é " COLOR(LIGHTBLUE) "Il Preludio alla Luce" COLOR(DEFAULT) "... "
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Io sono" COLOR(RED) " Impa" COLOR(DEFAULT) " una Sheikah. \n"
"Mio dovere e' proteggere la \n"
"Principessa Zelda. Tutto e' esat-\n"
"tamente come Lei ti ha detto...  "
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se le guardie del castello ti\n"
"trovano, sarai nei guai.\n"
"Lascia che ti guidi fuori di qui... "
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ehi tu! Non combinare dei guai!  " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sei molto coraggioso...    \n"
"Ti stai avventurando in\n"
"un difficile compito...      "
BOX_BREAK
UNSKIPPABLE "Il mio ruolo nel sogno di Zelda era\n"
"insegnare una melodia" COLOR(RED) " " COLOR(DEFAULT) "al ragazzo\n"
"della foresta.  "
BOX_BREAK
UNSKIPPABLE "Questa é un antica " COLOR(BLUE) "melodia\n"
"ereditata dalla Famiglia Reale" COLOR(DEFAULT) ". "
BOX_BREAK
UNSKIPPABLE "Ho suonato questa canzone per\n"
"la Principessa come ninnananna \n"
"sin da piccolina...    "
BOX_BREAK
UNSKIPPABLE "C'é un potere misterioso in\n"
"queste note.  "
BOX_BREAK
UNSKIPPABLE "Ascolta attentamente..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tutte le tragedie accadute ad  \n"
"Hyrule sono colpa mia..."
BOX_BREAK
UNSKIPPABLE "Ero cosi' giovane...Non potevo\n"
"capire le conseguenze del mio\n"
"tentativo di gestire il Sacro Reame."
BOX_BREAK
UNSKIPPABLE "E ho coinvolto anche te.\n"
UNSKIPPABLE "Ora é giunto il momento di pagare\n"
"per i miei errori..."
BOX_BREAK
UNSKIPPABLE "Riponi la Spada Suprema al suo\n"
"posto e chiuderai la Porta del Tempo."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E, cosi' facendo, chiuderai per\n"
"sempre la via del Tempo.        "
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ",\n"
"dammi l'Ocarina...       "
BOX_BREAK
UNSKIPPABLE "Come Saggio, ti restituiro'   \n"
"al tuo tempo...            "
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Quando tornera' la pace...     "
BOX_BREAK
UNSKIPPABLE "Sara' il momento per dirci    \n"
"addio...   "
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Torna a casa, " NAME ".\n"
"Torna al tuo tempo!   "
BOX_BREAK
UNSKIPPABLE "Casa... \n"
"La' dove dovresti essere ora...\n"
"La via che dovresti seguire...   "
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46")  QUICKTEXT_ENABLE "Tsk" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Tsk." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si vede che lo ritieni un\n"
"prezzo troppo alto." EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"OK, ti faro' passare, \n"
"veloce! " EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"TIENILO SEGRETO  \n"
"A CHIUNQUE!!  "
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gente, sono stanco!"
BOX_BREAK
"La veglia notturna é cosi'\n"
"noiosa! Vorrei vedere un fantasma\n"
"o qualcos'altro... "
BOX_BREAK
"Ehi, sono molto interessato ai\n"
"fantasmi!"
BOX_BREAK
"Studiarli é un mio hobby, e poi\n"
"non si sa mai...un domani    \n"
"questo tipo di conoscenza   \n"
"potrebbe rivelarsi utile!!"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il mio piccolino ha un pelo diverso\n"
"da tutti gli altri randagi che  \n"
"girano per le strade!   "
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il mio cucciolo corre piu' velo-\n"
"ce degli altri cagnacci che\n"
"girano qui! "
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Non trovo il mio piccolino!    \n"
"Aiutami a trovarlo! Per favore!   "
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0C")  QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"Non e' il mio cane! \n"
"Come hai potuto scambiare il\n"
"mio piccolo con questo?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x46")  QUICKTEXT_ENABLE "Richard!" QUICKTEXT_DISABLE
BOX_BREAK
"E' il mio piccolo Richard!\n"
"Grazie! Grazie!!   \n"
"Ti daro' questa cosa in \n"
"ricompensa!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Di notte e' pericoloso girare con\n"
"tutti questi cagnacci randagi...\n"
"No, non ti ho minacciato! \n"
"Sono preoccupata per Richie"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Salvee!\n"
"Benvenuti al " COLOR(RED) "Felici Maschele" COLOR(DEFAULT) "!  \n"
"Noi tlattiamo maschele che  \n"
"poltano felicita'!    "
BOX_BREAK
"Vollesti essele un piazzista\n"
"felice? Ti plestelo' una    \n"
"maschela. La vendelai e mi poltelai\n"
"i " COLOR(RED) "soldi" COLOR(DEFAULT) " fatti, indietlo. "
BOX_BREAK
"Se vuoi capile il meccanismo \n"
"basta, che ti leggi il " COLOR(RED) "Caltello\n"
COLOR(DEFAULT) "li' a destla.    "
BOX_BREAK
"Dopo avel venduto tutte le mas-\n"
"chele divellai felice" COLOR(RED) " " COLOR(DEFAULT) "tu stesso!"
BOX_BREAK
SHIFT("\x40") " Abbi fede..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Scegli le maschere spostandoti \n"
"con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parla al proprietario. \n"
"Lascia stare" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Una " COLOR(RED) "Maschela" COLOR(DEFAULT) " é un " COLOR(YELLOW) "[C] item" COLOR(DEFAULT) ".\n"
"Assegnala a " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", plemi " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e la indossi."
BOX_BREAK
"Pallando agli altli con la\n"
"maschela, ottellai divelse leazioni.  "
BOX_BREAK
"Se qualcuno é intelessato alla\n"
"maschela, ti chiedela' notizie\n"
"in ploposito."
BOX_BREAK
"Da qualche palte,   \n"
"in qualche modo, qualcuno...\n"
"Sta aspettando la sua maschela..."
BOX_BREAK
SHIFT("\x32") "Abbi fede...      " EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi sembrava di aver visto una\n"
"ragazzina qua vicino...\n"
"Che sia andata al castello?\n"
"Boh?      "
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Blavo!! L'hai venduta!\n"
"Plego lestituisci" COLOR(RED) " 10 Lupié " COLOR(DEFAULT) "per\n"
"la Maschela Keaton. " EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Non hai ancola venduto la\n"
"nuova maschela...Abbi fede...\n"
"Prova a gilale un altlo po'. " EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pagamento fatto! " EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Cosa?!" QUICKTEXT_DISABLE "\n"
"Non hai i miei soldi?!   "
BOX_BREAK
QUICKTEXT_ENABLE "Ma come osi! " QUICKTEXT_DISABLE
BOX_BREAK
"Sala' meglio che me li polti...\n"
"se no...! " EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh yeah!"
BOX_BREAK
"CONGLATULAZIONI!\n"
"Le hai vendute tutte!     "
BOX_BREAK
"Sapevo di potelmi fidale!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "In plemio...\n"
"Ti plesto questa maschela speciale. "
BOX_BREAK
UNSKIPPABLE "E' la " COLOR(RED) "Maschela della Velita'" COLOR(DEFAULT) ".\n"
"E' una maschela misteliosa\n"
"eleditata dagli Sheikah."
BOX_BREAK
UNSKIPPABLE "Con questa maschela leggelai le\n"
"menti degli altli... \n"
"E' utile, ma spaventosa!"
BOX_BREAK
UNSKIPPABLE "E pelché lo e'? "
BOX_BREAK
UNSKIPPABLE "Lo capilai quando salai piu'\n"
"glande e scoplilai il\n"
"significato della vita..."
BOX_BREAK
"Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Da ola in poi ti plestelo' la\n"
"maschela che vuoi.\n"
"Abbi fede...   " EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Benvenuto!\n"
"Che maschela vuoi oggi?    " EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Scegliela con sinistra o destla \n"
"con " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Maschera della Verita' \n"
"Non prendere niente" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"E' la " COLOR(RED) "Maschela della Velita'" COLOR(DEFAULT) ". E'\n"
"una maschela misteliosa eleditata\n"
"dagli Sheikah."
BOX_BREAK
"Con questa maschela leggelai le\n"
"menti degli altli...\n"
"E' utile, ma spaventosa!"
BOX_BREAK
"Pelché lo e'?  "
BOX_BREAK
"Lo capilai quando salai glande!   "
BOX_BREAK
"Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera della Verita'\n"
COLOR(DEFAULT) "Non in vendita\n"
"Ha speciali poteri.  " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Teschio    20 Rupié " COLOR(DEFAULT) "\n"
"Una maschera cornuta" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Demone      30 Rupié \n"
COLOR(DEFAULT) "Questa mette paura." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Keaton --   10 Rupié \n"
COLOR(DEFAULT) "Un articolo che va fortissimo!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bugs Bunny          50 Rupié \n"
COLOR(DEFAULT) "Con le orecchie luuunghee!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Teschio - Si presta" COLOR(DEFAULT) "\n"
"Una maschera cornuta" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Demone -- Si presta \n"
COLOR(DEFAULT) "Questa mette paura." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Keaton -- Si presta \n"
COLOR(DEFAULT) "Un articolo che va fortissimo!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bugs Bunny -- Si presta     \n"
COLOR(DEFAULT) "Con le orecchie luuuunghe!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Goron -- Si presta \n"
COLOR(DEFAULT) "Questo faccione rotondo ti\n"
"fa un po' felice!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Zora -- Si presta " COLOR(DEFAULT) "\n"
"Sei proprio forte se la metti\n"
"mentre stai nuotando!          " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera Gerudo -- Si presta \n"
COLOR(DEFAULT) "Con questi occhi affascinanti,\n"
"sembrerai una bella donna." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maschera della Verita' Si presta" COLOR(DEFAULT) "\n"
"Maschera misteriosa che ti fa\n"
"leggere la mente. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la\n"
COLOR(RED) "Maschera Teschio" COLOR(DEFAULT) "? " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la\n"
COLOR(RED) "Maschera Demone" COLOR(DEFAULT) "?   " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la\n"
COLOR(RED) "Maschera Keaton" COLOR(DEFAULT) "?   " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la       \n"
COLOR(RED) "Bugs Bunny" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la\n"
COLOR(RED) "Maschera Goron" COLOR(DEFAULT) "?   " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la \n"
COLOR(RED) "Maschera Zora" COLOR(DEFAULT) "?  " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi in prestito la \n"
COLOR(RED) "Maschera Gerudo" COLOR(DEFAULT) "?  " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vuoi prestata la\n"
COLOR(RED) "Maschera della Verita'" COLOR(DEFAULT) "? " QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Blavo!! L'hai venduta! \n"
"Plego lestituisci" COLOR(RED) " 20 Lupié\n"
COLOR(DEFAULT) "pel la Maschela Teschio.  " EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Blavo!! L'hai venduta! \n"
"Plego restituisci" COLOR(RED) " 30 Lupié\n"
COLOR(DEFAULT) "pel la Maschela Demone.    " EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Blavo!! L'hai venduta! \n"
"Plego lestituisci" COLOR(RED) " 50 Lupié\n"
COLOR(DEFAULT) "pel la Maschela Bugs Bunny" EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Non l'hai ancola venduta.\n"
"Abbi fede figliolo, ancola \n"
"per un po'.         "
BOX_BREAK
"O, la vuoi scambiale con un\n"
"altra maschela?  \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Si \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Le parti della Triforza vibrano...  \n"
"Cio' che era uno si sta riunendo... "
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Le due parti della Triforza che\n"
"non potei prendere quel giorno\n"
"di 7 anni fa... "
BOX_BREAK
UNSKIPPABLE "Non mi aspettavo si trovassero\n"
"nascoste in voi due!  "
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E ora, alla fine, tutte le parti  \n"
"della Triforza sono qui! "
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Non sono giocattoli per te!     "
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti ordino di restituirmeli\n"
"subito!  "
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"Non posso aiutarti!\n"
"A causa delle onde di\n"
"tenebra, non mi avvicinero'!"
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Mi spiace, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Il Grande Re del Male, sconfitto\n"
"da un ragazzino?!   "
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf...Uomo pietoso.."
BOX_BREAK
UNSKIPPABLE "Senza una mente giusta e forte,\n"
"non ha saputo controllare il potere\n"
"delle Dee...E... "
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", ascoltami! \n"
"Questa torre sta per cadere!    "
BOX_BREAK
UNSKIPPABLE "Con il suo ultimo respiro,\n"
"Ganondorf sta tentando di farci\n"
"rimanere sotto le macerie!\n"
"Dobbiamo scappare ora!!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ti prego seguimi!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E' finita...é finalmente finita."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... \n"
"Mi dispiace non averti potuto\n"
"aiutare in battaglia!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Cos'é questo suono?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "In nessun modo riuscira' a \n"
"riportarmi indietro!\n"
COLOR(DEFAULT)  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Stavolta, lotteremo insieme!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! Prendi la  \n"
"Spada Suprema! \n"
QUICKTEXT_ENABLE "Sbrigati!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sto usando il mio potere contro\n"
"il Re del Male! Usa la spada per\n"
"il colpo finale!       "
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x41") "Sei Saggi...\n"
QUICKTEXT_ENABLE  SHIFT("\x50") "ORA!!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "TU...." TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "MALEDETTA...ZELDA!\n"
TEXT_SPEED("\x02") "MALEDETTI...SAGGI!!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "MALEDETTO..." QUICKTEXT_ENABLE  NAME "!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Un giorno...\n"
"Il sigillo si rompera'... " BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Sara' allora che sterminero' i\n"
"vostri discendenti!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sino a che il Potere della Triforza\n"
"sara' mio...  " FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
TEXT_SPEED("\x02") "Tu... " TEXT_SPEED("\x00") "chi sei tu? " FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0A") "La " COLOR(ADJUSTABLE) "Barriera della Foresta" COLOR(DEFAULT) " é tolta!\n"
SHIFT("\x3C") "Presto, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "La " COLOR(RED) "Barriera di Fuoco" COLOR(DEFAULT) " é tolta! \n"
SHIFT("\x29") "Sbrigati fratello!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "La " COLOR(BLUE) "Barriera d'Acqua" COLOR(DEFAULT) " é spezzata!\n"
SHIFT("\x46") "Sbrigati!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "La " COLOR(PURPLE) "Barriera delle Ombre" COLOR(DEFAULT) " é tolta!\n"
SHIFT("\x24") "  Salva la Principessa!  " FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "La " COLOR(YELLOW) "Barriera dello Spirito" COLOR(DEFAULT) " é tolta! \n"
SHIFT("\x40") "Fai presto!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "La " COLOR(LIGHTBLUE) "Barriera di Luce" COLOR(DEFAULT) " é spezzata!\n"
SHIFT("\x4B") "Vai " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME ", ma, non é...?!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Si, é la lama leggendaria..." COLOR(DEFAULT)  FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "La Spada Suprema!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Trova tutti i Saggi " COLOR(RED) "\n"
COLOR(DEFAULT) "e salva Hyrule! " FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quell'uomo mostruoso ci ha \n"
"portato velocemente fuori!  "
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh che paura...\n"
"Che paura... "
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, ma cosa vuoi?    \n"
"Non ho tempo per parlare \n"
"con te!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ti prego..con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Pieta' vendimi qualcosa... \n"
"Pieta'...con " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "... "
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"No...\n"
"Non é questo che volevo. \n"
"Voglio " COLOR(RED) "qualcosa in una bottiglia" COLOR(DEFAULT) "...\n"
"Non intendevo quella cosa.."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"No...\n"
"Non posso prenderlo.\n"
"Non é cio' che volevo comprare. "
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, é il " COLOR(LIGHTBLUE) "Fuoco Blu" COLOR(DEFAULT) "!  \n"
"Lo compro per " COLOR(RED) "150 Rupié" COLOR(DEFAULT) "!   \n"
"Affare fatto, OK?   "
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, un" COLOR(PURPLE) " Pesce" COLOR(DEFAULT) "!\n"
"Lo compro per" COLOR(RED) " 100 Rupié" COLOR(DEFAULT) "! \n"
"Affare fatto, OK?   "
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, é un bell'" COLOR(ADJUSTABLE) "Insettone" COLOR(DEFAULT) "!   \n"
"Lo compro per " COLOR(RED) "50 Rupié" COLOR(DEFAULT) "!   \n"
"Affare fatto, OK?   "
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, la cara piccola " COLOR(LIGHTBLUE) "Fatina" COLOR(DEFAULT) "!\n"
"La compro per " COLOR(RED) "25 Rupié" COLOR(DEFAULT) "!   \n"
"Affare fatto, OK?   "
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...Sei un giovanotto pieno di\n"
"energia. E sei anche bello \n"
"e coraggioso. "
BOX_BREAK
UNSKIPPABLE "Heh heh heh...Ti chiami   \n"
NAME ", vero??   "
BOX_BREAK
UNSKIPPABLE "Heh heh he...Non sorprenderti.  \n"
"Posso leggerti la mente..."
BOX_BREAK
UNSKIPPABLE "Se fossi in gamba come te,   \n"
"farei un diverso genere di    \n"
"affari...heh he heh...  "
BOX_BREAK
UNSKIPPABLE "Questo é l'unico " COLOR(RED) "Negozio di Spettri\n"
COLOR(DEFAULT) "di Hyrule."
BOX_BREAK
UNSKIPPABLE "Grazie al grande Ganondorf,\n"
"si fanno ottimi affari di questi \n"
"tempi...heh heh heh...    "
BOX_BREAK
UNSKIPPABLE "Oh...Spero proprio che il mondo\n"
"peggiori ancora!"
BOX_BREAK
UNSKIPPABLE "Gli spettri, detti " COLOR(RED) "Poes" COLOR(DEFAULT) ", sono\n"
"veri e propri concentrati di odio\n"
"che appaiono nei campi e nei\n"
"cimiteri. Essi odiano il mondo!"
BOX_BREAK
UNSKIPPABLE "Giovanotto, se catturi un Poe,  \n"
"ti paghero' un sacco di soldi... \n"
"Heh heh hee!"
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, giovanotto. Cos'é successo  \n"
"oggi? Se hai preso un" COLOR(RED) " Poe" COLOR(DEFAULT) ", te lo \n"
"compro."
BOX_BREAK
"La tua carta ha " COLOR(PURPLE)  HIGHSCORE(HS_POE_POINTS) " " COLOR(DEFAULT) "punti ora.\n"
"Ritorna ancora!\n"
"Heh heh heh!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, hai portato un Poe oggi!"
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Hmmm..."
BOX_BREAK
UNSKIPPABLE "E' un " COLOR(RED) "Poe" COLOR(DEFAULT) " " COLOR(RED) "normale" COLOR(DEFAULT) ".   \n"
UNSKIPPABLE "Ecco sono ben " COLOR(RED) "10 Rupié" COLOR(DEFAULT) ". \n"
"Prendile. "
BOX_BREAK
UNSKIPPABLE "Heh heh."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, hai portato un Poe oggi!"
BOX_BREAK
UNSKIPPABLE "Hmmmm!"
BOX_BREAK
UNSKIPPABLE "Pero' mica male! \n"
"E' un " COLOR(RED) "Grosso Poe" COLOR(DEFAULT) "! "
BOX_BREAK
UNSKIPPABLE "Lo compro per " COLOR(RED) "50 Rupié   " COLOR(DEFAULT) "."
BOX_BREAK
"In piu', ti aggiungo ben " COLOR(RED) "100\n"
"punti " COLOR(DEFAULT) "sulla carta..."
BOX_BREAK
UNSKIPPABLE "Se guadagni " COLOR(RED) "1.000 punti" COLOR(DEFAULT) ", sarai  \n"
"un uomo felice! Heh heh."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma, un attimo! WOW!"
BOX_BREAK
UNSKIPPABLE "Hai guadagnato " COLOR(RED) "1.000 punti" COLOR(DEFAULT) "!! "
BOX_BREAK
UNSKIPPABLE "Giovanotto, sei un vero\n"
COLOR(RED) "Acchiappafantasmi" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Ti aspettavi che dicessi questo\n"
"vero? Heh heh heh"
BOX_BREAK
UNSKIPPABLE "Grazie a te, ho una bella   \n"
"scorta di " COLOR(RED) "Grossi Poes" COLOR(DEFAULT) ", percio' questa\n"
"é l'ultima volta che ne\n"
"compro uno"
BOX_BREAK
UNSKIPPABLE "Stai pensando a quello che ti\n"
"ho promesso una volta raggiunti\n"
"i 1.000 punti. Heh heh heh."
BOX_BREAK
UNSKIPPABLE "Non temere, non l'ho dimenticato,\n"
"Prendi pure."
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eh? Ma cosa...? "
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "E'" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "una...  " TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(DEFAULT) "Fatina" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!"
BOX_BREAK
UNSKIPPABLE "Allora, vieni... \n"
"...Vieni dalla foresta? " EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Allora...E' successo...Dovresti...\n"
"Avere...La..." COLOR(ADJUSTABLE) "Pietra Spirituale della\n"
"Foresta" COLOR(DEFAULT) ", vero?! \n"
"E' una pietra verde e luminosa...  " EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho avuto un sogno...\n"
"Nel sogno, scure nuvole minacciose\n"
"ricoprivano l'intera Hyrule..."
BOX_BREAK
UNSKIPPABLE "Ma d'improvviso, dalla foresta,\n"
"scaturi' un raggio di sole che\n"
"squarcio' le nuvole nel cielo...   "
BOX_BREAK
UNSKIPPABLE "La luce divenne una figura che\n"
"portava una " COLOR(ADJUSTABLE) "luminosa pietra verde" COLOR(DEFAULT) ",\n"
"seguita da una" COLOR(LIGHTBLUE) " Fata" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sentivo che, come predetto,  \n"
"qualcuno sarebbe venuto\n"
"dalla " COLOR(ADJUSTABLE) "foresta" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Si, penso che tu\n"
"sia l'ELETTO...      " EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Oh, spiacente!"
BOX_BREAK
UNSKIPPABLE "Mi sono fatta prendere dalla storia\n"
"e non mi sono nemmeno presentata!\n"
" " EVENT  UNSKIPPABLE  SHIFT("\x0C") "   "
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sono " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ", principessa di Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa? Ci siamo mai visti?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Awww... Che bella!     \n"
"Mi diresti dove l'hai trovata?       "
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeeeah!\n"
"Aiuto!! "
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh...ehi? E allora?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Odio le volpi"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che fastidio!! "
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, sembri forte! "
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "YEEEAH! Ma che ti é successo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ooh...é cosi' uno Zora?\n"
"Quegli occhi freddi sono\n"
"affascinanti..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh no! Fai paura! \n"
"Non ti avvicinare!!     "
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow...che nostalgia! Mi\n"
"ricorda di quando anch'io\n"
"ero piccolina."
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' proprio divertente...\n"
"mi fai ridere!! \n"
"Hee hee!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Uh-oh!" QUICKTEXT_DISABLE " Mi dispiace!!  \n"
"Oh...Ehi, sei tu!  \n"
"Non mi spaventare piu'!! "
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma che testona che hai!! "
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, non farlo!\n"
"Sono timido..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che c'é una gara di maschere\n"
"in corso?\n"
QUICKTEXT_ENABLE "Sicuramente ti votero'!!  " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un coniglio! \n"
"Parlando di conigli, ho visto\n"
"uno strano uomo cacciare \n"
"conigli...  "
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh, che bella donna!!  \n"
"Ma sei un po' piccolina, \n"
"pero'!?    "
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bah!...Non mi viene in mente \n"
"niente di divertente!        "
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Una maschera...Anch'io da piccolo,\n"
"giocavo con le maschere...  \n"
"Cosa? Non riesci a immaginartelo?!            "
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohhhh...Vedo... \n"
"E' un illusione... "
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, ragazzo non crescere    \n"
"come me..."
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AAAAAAAAAAAH!\n"
"UN GERUDO!!!" QUICKTEXT_DISABLE
BOX_BREAK
"Cosa? Una maschera?\n"
"Perché hai questa \n"
"maschera?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spiacente, sono occupato. "
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh wow! E' Keaton!\n"
"Ciao, Keaton!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spaventosa!\n"
"C'e' un ragazzo al Villag-\n"
"gio Kakariko che cerca una\n"
"maschera cosi'!! "
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm...Bella...Non hai    \n"
"altre maschere?   "
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che strana maschera!\n"
"Hee hah haa!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi tu! Non vedi che siamo\n"
"occupati? Vattene via!! "
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spiacente. Non voglio nemmeno \n"
"guardare un'altra donna! "
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee.\n"
"Non prestare attenzione a quel\n"
"ragazzo, caro... Ti chiedo solo di \n"
"tornare nel nostro piccolo mondo..."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, vai a disturbare\n"
"qualcun'altro! "
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si dice in giro che ci sia una\n"
"farmacia che sia riuscita a fare\n"
"la medicina definitiva!      "
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho sentito in giro di un mostro \n"
"che si mangia gli " COLOR(LIGHTBLUE) "Scudi Hylian  " COLOR(DEFAULT) "\n"
"da qualche parte fuori di qui.   \n"
"L'hai mai visto?      "
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono venuto a vendere bombe...\n"
"Comprane una! "
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho...Ho paura...  \n"
"Ho la sensazione che quell'uomo\n"
"distruggera' Hyrule. "
BOX_BREAK
UNSKIPPABLE "Ha un potere terrificante!   "
BOX_BREAK
UNSKIPPABLE "Ma fortunatamente\n"
"sei arrivato tu...     " EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa? Se vuoi qualcosa,     \n"
"spiegati per bene! "
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho da fare!\n"
"Levati davanti, subito!  "
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, e' proprio un legno\n"
"di ottima qualita'!     "
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm!\n"
"Levati davanti!   \n"
"Sei un buono a niente..."
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"EEEEEEAAAAH!\n"
"Whoops, non dovrei urlare cosi'\n"
"altrimenti il capo urlera' a me! "
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spiacente capo! \n"
"Non volevo perder tempo!   \n"
"Sono occupato!"
BOX_BREAK
"Oh, ma tu non se il capo?"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I Gerudos sono bravi e belli...   \n"
"Sono proprio affascinanti!   "
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un giorno, saro' anch'io cosi'\n"
"abile da incidere una maschera!   "
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, questa é la famosa mas-\n"
"chera di cui parlano tutti!\n"
"Che strana...  "
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wa-ha-hah!\n"
"Fai affari, eh, Mr. Eroe?\n"
"Hah hah hah!"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono di servizio\n"
"Capito?\n"
"SERVIZIO"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm, mah, non so proprio cosa \n"
"dirti di questa maschera...  "
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Carino!\n"
"Ma i Cuccos lo sono di piu!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eh, cosa?\n"
"Sei triste?\n"
"Felice?\n"
"Non lo so proprio...  "
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spiacente, non mi interessa\n"
"per niente.      "
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il bambino che gioca nel ci- \n"
"mitero dice spesso qualcosa\n"
"sulla sua faccia... "
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono davvero un brav'uomo\n"
"Non mi credi?      "
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHAAAA--!\n"
"Pensavo fossi quella stregaccia!\n"
"Non mi spaventare cosi'! "
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ricordo che mio padre parlava\n"
"di un fabbro...ma a me,     \n"
"non me ne importava proprio\n"
"niente."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non ho paura di nessun mostro\n"
"della foresta! Stai provando\n"
"a divertirmi? "
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma cos'hai li'? Non riesco a\n"
"vederlo bene da qui..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ciao di nuovo! Come va oggi?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oggi va tutto benissimo!"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stanco...sono stanco..."
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non mi interessano le \n"
"volpi!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che scocciatura!  \n"
"Mi infastidisce!   "
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sembra abbastanza bellino!"
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaaaah!\n"
"Cosa c'e' che non va? \n"
"Hai delle cattive abitudini?"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Idiota!!   \n"
"Quando parli a qualcuno, devi\n"
"guardarlo negli occhi!  "
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Idiota!!  \n"
"Quando parli a qualcuno, non\n"
"devi fissarlo!   "
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Idiota!!  \n"
"Quando parli a qualcuno, devi\n"
"toglierti la maschera!    "
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Idiota!! \n"
"Non so perché ti ho chiamato\n"
"cosi', ma...lo sei di sicuro!"
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dove l'hai presa?  \n"
"Cosa?\n"
"E' una maschera?"
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh, lasciami solo... \n"
"Non vedi che sto componendo  \n"
"adesso?   "
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Una maschera é come uno strumento\n"
"musicale...riflette il carattere\n"
"del proprietario...\n"
"Sei proprio originale!!  "
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che testone!!   \n"
"Come puoi passare per la porta?! "
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I ODIO le volpi!    "
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se questa non é la piu'\n"
"brutta faccia che ho visto in\n"
"tutta la mia vita, non so cosa lo\n"
"é!"
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, che bella faccia\n"
"che hai piccoletto!    "
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai avuto dei reclami?      \n"
"Parla, forza!  "
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Per favore basta giocare,\n"
"spezza la maledizione!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se indossassi una cosa simile...\n"
"sarei un vero Ragnaccio...\n"
"AAAAAAAAAAH!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Capiscimi, ti prego, se non \n"
"rido... E' difficile essere\n"
"felici in queste condizioni\n"
"Essere maledetti... "
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "Hyaaaaah!\n"
"E' spaventoso!\n"
"So che sono brutto ma...Gente!\n"
"Quello fa paura! "
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh?! Cos--!"
BOX_BREAK
"Oh, é solo un ragazzo.\n"
"Non mi spaventare piu'!\n"
"Potrebbe non sembrare, ma sono un\n"
"tipo sensibile!    "
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"bene, guarda che coppetta ha questo \n"
"bambino! E' ENORME! \n"
"Ma, anche la mia é enorme. "
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sai che tipo di maschera\n"
"stai indossando...?    \n"
"E continui ad indossarla?   "
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sono in servizio...\n"
"Se mi vuoi far scavare, non\n"
"scocciarmi."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma cos'é?...E' quello che   \n"
"saltella in giro nei campi... \n"
"Non mi ricordo come si      \n"
"chiama...  "
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi! E' una Maschera Keaton!\n"
"L'ho chiesta a mio padre!   \n"
"    "
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non e' molto differente da    \n"
"Mr. Dampé, vero? "
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Con quella non sembri altro che\n"
"Mr. Dampé, huh?"
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Ehi, e' bella...ma mette un po'\n"
"paura, non credi?    "
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi! Mi sembra familiare...\n"
"Mi sembra di averla gia' vista \n"
"nei Boschi Peruti, no?"
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Mi fa sentire...Felice...    "
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...Uh...Sniff...\n"
"Quella maschera...\n"
"Mi rende..infelice."
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah! Quella maschera non ti\n"
"servira mai!! Sei spaventato da me,\n"
"il grande Mido...e' vero?!   "
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaah! Cosa?\n"
"Ehi, non mi hai spaventato!\n"
"Solo non ti avvicinare, hai\n"
"capito?!    "
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, che maschera forte.\n"
"La voglio!\n"
"STAVO SCHERZANDO!!\n"
"Non voglio quella scemenza!   "
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah ha hah!\n"
"E' proprio adatta a te"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaah!\n"
"I-Io lo diro' a Mido e poi\n"
"vedrai!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeeeeah!\n"
"I-Io diro' a Mido di menarti \n"
"subito!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whooooah!\n"
"Sei una specie di fantasma \n"
"vero? "
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che mito!      \n"
"Uh...non dirlo a Mido, ti prego! "
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa?!\n"
"Sei tornato!  \n"
"So chi sei, anche se indossi\n"
"quella maschera!  "
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chissa' cosa direbbe Mido se la\n"
"vedesse?    \n"
"Mi piacerebbe osservare la sua\n"
"reazione!"
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vedo... \n"
"Vuoi spaventare Mido con quella\n"
"maschera, non e' vero?!"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah hah hah!\n"
"Che divertente sei!\n"
"Scommetto che anche Saria  \n"
"l'apprezzerebbe!  "
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee hee!\n"
"Una maschera di legno?\n"
"Sembra che indossi uno    \n"
"scudo in faccia!      "
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Che faccia strana!"
BOX_BREAK
"Parlando di strane facce, uno\n"
"dei ragazzi perduti si lamentava\n"
"della sua faccia. "
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma che capoccione che hai!     "
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee!\n"
"Dove lo hai preso?    \n"
"Fuori della foresta?\n"
"Bugiardo! Non ti credo!    "
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Si, é divertente, ma non é\n"
"il mio stile...    "
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Giusto!   \n"
"Indossaando questa maschera mi\n"
"sento un vero duro!     \n"
"Hee hee!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Ci sono cosi' tante facce diverse\n"
"nel mondo! Hee hee! "
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non mi serve una faccia nuova...\n"
"Mi piace quella che ho, grazie! "
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Wow, ti é venuto un testone\n"
"enorme! \n"
"Hee hee!"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "Ma che bel topolino!     \n"
"Cosa?\n"
"Oh, non é un topo?   "
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "Cosa sono quelle cose penzolanti\n"
"sulla testa?\n"
"Orecchie? Con quella maschera\n"
"sembra tu ne abbia 4! "
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "Deve essere eccitante schivare\n"
"le guardie indossando quella\n"
"maschera!"
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ciao, elfo!   \n"
"Cosa?\n"
"Pensavi che non ti riconoscessi?\n"
"Ma é cosi' evidente chi sei! "
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow!\n"
"Che occhi grandi che hai!\n"
"I Gorons sono cosi carini!    "
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, conosco quel personaggio!\n"
"E' Keaton!\n"
"E' davvero famoso alla \n"
"citta' di castello!  "
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, fratello!\n"
"I maschi siano mas"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"chi\n"
"Ma...aspetta\n"
"..io so chi sei...\n"
"Sei... Kin-ton!\n"
"Ho indovinato eh?!"
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fa davvero spavento, vero?  \n"
"Almeno quanto lo fa...Ingo!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, mi ricorda mia moglie...     \n"
"A pensarci bene, no, non era...\n"
"Non era proprio del tutto cosi'! "
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAWWN...\n"
"Sono un po' stanco adesso...\n"
"Lo vedro' piu' tardi.."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fila via!\n"
"Non vedi che ho da fare?! "
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Humph!\n"
"E' bello giocare fino a che si é \n"
"piccoli come te, ma una volta\n"
"cresciuti...Lavoro,Lavoro,Lavoro!!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YEOW!\n"
"Humph. E' una maschera... \n"
"Fila via ragazzino, subito! "
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh...\n"
"Bene, questo mi ha rallegrato un  \n"
"po'.\n"
"Grazie!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm... Vediamo...  \n"
"Si, sono piu' che sicuro... \n"
"E' stata ottenuta dal legno  \n"
"di una vecchia bara. Si, sicuro! "
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhh...si. Vediamo...   \n"
"Un ottimo lavoro a mano.\n"
"Ma non credo potrebbe essere un\n"
"buon ingrediente per la medicina. "
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Molto interessante! Un Goron!\n"
"Parlando di Gorons, mi chiedo\n"
"come stara' Biggoron alla\n"
"Montagna della Morte?     "
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' un manufatto inusuale... \n"
"Non credo sia solubile in acqua,\n"
"dunque non é un buon ingrediente \n"
"per la mia medicina...   "
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"OK, una maschera.\n"
"Vuoi comprare dei fagioli?  "
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"No, non voglio comprarli.    "
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"No, non é il mio stile. "
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Bene...non penso di        \n"
"volerlo."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cosa vuoi?       "
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non sembra tu sia in grado\n"
"di nuotare bene..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Capelli rossi... pelle scura...\n"
"Ho gia' visto gente cosi'.."
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si, giusto. \n"
"Sembri un po' piccolo come   \n"
"Zora..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho ho ho!\n"
"Sei un Hylians...che creatura \n"
"divertente!!"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quella faccia...mi da i brividi...   "
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parlando di nostalgia!      \n"
"Mi ricorda il mio amico della\n"
"infanzia, Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non é cosi' divertente dopotutto. \n"
"Ma stai scherzando?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sei proprio buffo! "
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai una testa enorme!    "
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non farlo...    \n"
"Mi stai imbarazzando!"
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va bene! Hai deciso di        \n"
"divenire uno Zora!\n"
"Sei pronto ora a sposarmi?     \n"
"       "
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHOA!\n"
"Il cuore...batte cosi'...\n"
"veloce!!  "
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' una maschera sgradevole..\n"
"Ciao.    "
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm...\n"
"Non so proprio che dirti."
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non dovresti essere cosi'   \n"
"schizzinoso! Hai mangiato tutte le\n"
"rocce verdi? Se non l'hai fatto,\n"
"non crescerai forte e grosso! "
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lasciami solo! "
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stai provando a farmi ridere?\n"
"Sappi che non mi diverto affatto."
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi farai impazzire!  "
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Odio i Gerudos!!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non mi scocciare! \n"
"Vattene!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah!\n"
"Pensi di essere in incognito?\n"
"Mi fai ridere"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Levati davanti!\n"
"Usciamo di qui!\n"
"Stavi chiedendo questo, vero?    "
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ehi, piccolo, hai avuto fegato a\n"
"venire qui indossandola! \n"
"Non ci prenderai in giro\n"
"facilmente!!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cos'é quella?\n"
"Che cosa ha a che fare con noi? "
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"Hai fegato da vendere, capito\n"
"ragazzino? \n"
"Mi piaci!  "
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Forza! Ora non si scherza piu'! "
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E' strano...la sua foggia mi ricorda\n"
"...\n"
"No...non proprio. No davvero,\n"
"se la guardo da vicino... "
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm. No, no, no!\n"
"Le orecchie non sono giuste! \n"
"Dovrebbero essere, piu' lunghe!  "
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma non sei un po' spaventato\n"
"a camminare in giro nel mezzo\n"
"della notte cosi' conciato?  "
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"Ma ti piacciono davvero\n"
"quelle cose?!    "
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mi sembra di aver visto una\n"
"pietra cosi' da qualche parte...\n"
"Ora dov'era?      \n"
"Hmmmm...."
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sbrigati, " NAME "!\n"
"Pochi secondi e la torre     \n"
"cadra' a pezzi!!   "
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Attento alle macerie!        "
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "!\n"
"Aiutami!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"L'uscita é proprio li sopra!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Grazie, " NAME ".  \n"
"Ora, sbrighiamoci!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Male!!  "
BOX_BREAK
"Allenati e pure parecchio!! " EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pero'!! "
BOX_BREAK
"Mica male...OK!  \n"
"Ti lascio provare un'altra volta.\n"
"Gratis! \n"
"Stavolta, ce la devi fare! " EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Complimenti!\n"
"Bravo!!!\n"
"Perfetto!!"
BOX_BREAK
"Eccoti lo splendido regalo!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh, no! " COLOR(RED) "Scaduto!  \n"
COLOR(LIGHTBLUE) "Le cose che volevi consegnare\n"
"si sono guastate!\n"
"Proviamo di nuovo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "BOINNG! BOINNG!\n"
"L'ora attuale é  " TIME "!" QUICKTEXT_DISABLE ":)    "
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hai sentito di noi dalla\n"
"guardia al cancello del Monte?  \n"
"Bene, ti faro' un bello sconto!           "
)

