DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Ei " COLOR(DEFAULT) "ausgeliehen!" QUICKTEXT_DISABLE "\n"
"Bald wird Kiki ausschlüpfen.\n"
"Gib es zurück, wenn Du\n"
"es nicht mehr benötigst!"
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "Du hast Kiki zurückgegeben\n"
"und dafür " COLOR(RED) "Henni" COLOR(DEFAULT) " bekommen." QUICKTEXT_DISABLE "\n"
"Im Gegensatz zu anderen\n"
"Hühnern kräht Henni selten!"
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Schimmelpilz" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  COLOR(RED) "\n"
COLOR(DEFAULT) "So ein frischer Pilz fault sehr\n"
"schnell. Also bringe ihn rasch\n"
"zum Hexenladen in Kakariko!"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Modertrank" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  COLOR(RED) "\n"
COLOR(DEFAULT) "Der Modertrank ist bestimmt\n"
"nützlich... Geh doch mal \n"
"in die Verlorenen Wälder!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "Du hast den Modertrank\n"
"gegen die " COLOR(RED) "Säge" COLOR(DEFAULT) " eingetauscht!" QUICKTEXT_DISABLE "\n"
"Der komische Kerl hat das\n"
"wohl hier liegen gelassen."
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomben   20 Stück   80 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen\n"
"Nicht kaufen" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "Du hast eine " COLOR(RED) "Munitionstasche\n"
"für Deku-Kerne" COLOR(DEFAULT) " erhalten." QUICKTEXT_DISABLE "\n"
"In der Tasche kannst Du \n"
COLOR(YELLOW) "40 " COLOR(DEFAULT) "Deku-Kerne aufbewahren!"
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "Du hast die Säge gegen ein\n"
COLOR(RED) "zerbrochenes Goronen-Schwert\n"
COLOR(DEFAULT) "eingetauscht!" QUICKTEXT_DISABLE "\n"
"Besuche damit Biggoron!"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "Du hast Biggoron das\n"
"zerbrochene Goronen-Schwert\n"
"gegeben und dafür ein " COLOR(RED) "Rezept\n"
COLOR(DEFAULT) "erhalten!" QUICKTEXT_DISABLE " Geh zu König Zora!"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "Biggorons Schwert!" QUICKTEXT_DISABLE "\n"
"Du hast ein " COLOR(RED) "Zertifikat" COLOR(DEFAULT) " erhalten.\n"
"Hoffentlich ist das Schwert\n"
"bald wieder repariert!"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Du hast das Langschwert\n"
"gegen das " COLOR(RED) "Biggoron-Schwert\n"
COLOR(DEFAULT) "getauscht!" QUICKTEXT_DISABLE " Diese Klinge ist\n"
"unzerbrechlich!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Du hast das Zertifikat gegen\n"
"das " COLOR(RED) "Biggoron-Schwert\n"
COLOR(DEFAULT) "getauscht!" QUICKTEXT_DISABLE " Diese Klinge\n"
"ist unzerbrechlich!"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "Du hast für das Rezept\n"
"einen " COLOR(RED) "Glotzfrosch" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE "\n"
"Schnell! Bringe ihn zum Hylia-\n"
"See, bevor ihm warm wird!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "Du hast für den Glotzfrosch\n"
"die " COLOR(RED) "Augentropfen" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE "\n"
"Bringe sie zu Biggoron, bevor\n"
"sie die Wirkung verlieren!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x24") "Herzlichen Glückwunsch!\n"
SHIFT("\x32")  COLOR(RED) "Du hast gewonnen!" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Schädel-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um andere\n"
"zu erschrecken! Du fühlst\n"
"Dich wie ein böses Monster!"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Geister-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Eine Menge Leute\n"
"kannst Du damit erschrecken!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Fuchs-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Wetten, Du machst\n"
"Dich damit beliebt?"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Hasenohren" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Die langen Ohren\n"
"sehen doch putzig aus!"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Goronen-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Du siehst selbst\n"
"fast aus wie ein Gorone..."
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Zora-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Mit dieser Maske\n"
"bist Du einer von ihnen!"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Gerudo-Maske" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu\n"
"zeigen! Du siehst damit aus\n"
"wie - ein Mädchen?!"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Maske des Wissens" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  COLOR(RED) "\n"
COLOR(DEFAULT) "Trage sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie\n"
"möglichst vielen Leuten\n"
"zu zeigen!"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willkommen auf der bombigen..." BOX_BREAK SHIFT("\x2F")  COLOR(RED) "Minenbowlingbahn!!!" COLOR(DEFAULT)  BOX_BREAK "Was man hier gewinnt? Das bleibt\n"
"zunächst mein " TEXT_SPEED("\x03") "Geheimnis." TEXT_SPEED("\x00") "\n"
"Ich verrate es erst, wenn Du für\n"
"ein Spiel bezahlt hast." BOX_BREAK "Ein Spiel kostet " COLOR(RED) "30 Rubine" COLOR(DEFAULT) ".\n"
"Willst Du?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x55") "OKAY!" QUICKTEXT_DISABLE  BOX_BREAK "Ziele auf das Loch in der Mitte\n"
"und schicke eine " COLOR(RED) "Krabbelmine" COLOR(DEFAULT) " los!\n"
"Du hast " COLOR(RED) "zehn" COLOR(DEFAULT) " " COLOR(RED) "Versuche" COLOR(DEFAULT) ". Fertig?" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "LOS GEHT'S!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du nochmal spielen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, das hätte ich fast vergessen!\n"
"Das hier kannst Du gewinnen!" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomben   20 Stück   80 Rubine\n"
COLOR(DEFAULT) "Halte die Bombe mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", drücke\n"
"zum Ablegen nochmal " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomben   30 Stück   120 Rubine\n"
COLOR(DEFAULT) "Halte die Bombe mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", drücke\n"
"zum Ablegen nochmal " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomben   30 Stück   120 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Fluch ist etwas Schreckliches!\n"
"Doch nun ist er von uns genommen!"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hilfst doch auch meinen\n"
"Brüdern, oder?" BOX_BREAK "Ich bin sicher, sie geben Dir\n"
"noch etwas viel Besseres!"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Der Fluch ist von mir genommen!\n"
"Tausend Dank! Hier ist eine\n"
"wertvolle Belohnung für Dich!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aarrrgh! Ich bin verflucht!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir werden künftig aufpassen, daß\n"
"uns nicht wieder jemand verflucht!"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast " COLOR(RED)  TOKENS " " COLOR(DEFAULT) "Skulltulas zerstört,\n"
"daher läßt nun langsam die \n"
"Wirkung des Fluchs nach." BOX_BREAK "Haben Dir meine Kinder, die Du\n"
"erlöst hast, etwas zur Belohnung\n"
"gegeben?" BOX_BREAK "Man wird übrigens nur dann\n"
COLOR(RED) "sehr reich" COLOR(DEFAULT) ", wenn man so viele\n"
"goldene Skulltulas wie möglich\n"
"vernichtet." BOX_BREAK "Du findest sie nur, wenn Du\n"
"Deine Umgebung stets\n"
"aufmerksam erkundest!" BOX_BREAK "Bitte hilf uns!\n"
"Wir zählen auf Dich!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wir sehen so aus, weil auf uns\n"
"der Fluch der Skulltulas lastet.\n"
"Aber..." TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir sehen so aus, weil auf uns\n"
"der " COLOR(RED) "Fluch der Skulltulas" COLOR(DEFAULT) " lastet." BOX_BREAK "Werden jedoch alle Skulltulas\n"
"dieser Welt zerstört, verliert\n"
"der Fluch seine Wirkung." BOX_BREAK "Tötest Du eine Skulltula, erscheint\n"
"ein Symbol. Sammle es ein!" BOX_BREAK ITEM_ICON("\x71") "Die Zahl neben dem " COLOR(YELLOW) "Spinnensymbol" COLOR(DEFAULT) "\n"
"auf dem " COLOR(LIGHTBLUE) "Status-Bildschirm" COLOR(DEFAULT) " gibt an,\n"
"wieviele Skulltulas Du bis zu\n"
"diesem Zeitpunkt zerstört hast." BOX_BREAK ITEM_ICON("\x71") "Erscheint das " COLOR(YELLOW) "Spinnensymbol" COLOR(DEFAULT) " neben\n"
"einem Namen auf dem " COLOR(RED) "Karten-\n"
"Bildschirm" COLOR(DEFAULT) ", findest Du in diesem\n"
"Gebiet keine Skulltulas mehr." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Brichst Du den Fluch, werden\n"
"wir Dich " COLOR(RED) "reich" COLOR(DEFAULT) " belohnen."
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Da Du " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Skulltulas zerstört\n"
"hast, wurde nun endlich der Fluch\n"
"von mir genommen." BOX_BREAK UNSKIPPABLE "Vielen Dank! Hier ist ein Zeichen\n"
"meiner Dankbarkeit!\n"
"Bitte nimm es an!" EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Danke, daß Du meine\n"
"Kinder befreit hast." BOX_BREAK "Was mit mir ist? Oh, das ist\n"
"schon in Ordnung." BOX_BREAK "Du hast jetzt bereits\n"
COLOR(RED)  TOKENS  COLOR(DEFAULT) " Skulltulas zerstört! Mach Dir\n"
"um mich mal keine Sorgen..."
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Krabbelminen 20 Stück 180 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Willst Du ein Spielchen wagen?\n"
"Es kostet Dich nur " COLOR(RED) "20 Rubine" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pech gehabt! Dafür brauchst Du\n"
"einen Bogen!" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Na gut. Dann eben nicht!" EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OKAY!" QUICKTEXT_DISABLE "\n"
"Das hier ist nur was für echte\n"
"Kerle! Die berühmteste\n"
COLOR(RED) "Schießbude" COLOR(DEFAULT) " des Landes!" BOX_BREAK "Stell Dich auf die Plattform und\n"
"ziele genau! Du hast " COLOR(RED) "fünfzehn" COLOR(DEFAULT) "\n"
"Schüsse und mußt alle " COLOR(RED) "zehn\n"
COLOR(DEFAULT) "Steine treffen!" BOX_BREAK "Schieße mit " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". \n"
"Fertig? Dann los und viel Glück!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hier ist ein Loch in der Erde. Ob\n"
"man wohl etwas einpflanzen kann?"
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Feen-Schleuder" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü " COLOR(DEFAULT) "kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder" COLOR(YELLOW) " [C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um die Schleuder\n"
"zu benutzen. Halte " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "und\n"
"ziele mit " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Laß " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " los,\n"
"um " COLOR(RED) "Deku-Kerne " COLOR(DEFAULT) "abzuschießen!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Wenn Du sofort schießen\n"
"willst, halte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " etwas länger\n"
"gedrückt und laß dann los."
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Feen-Bogen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x03") "Drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um den Bogen\n"
"zu benutzen. Halte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " und\n"
"ziele mit " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Laß " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " los,\n"
"um " COLOR(RED) "Pfeile" COLOR(DEFAULT) " abzuschießen!"
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Bomben" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im Gegenstands-Menü kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x02") "Mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " kannst Du sie halten\n"
"und ablegen. Drückst Du " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "während Du rennst, kannst\n"
"Du die Bomben auch werfen!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Krabbelminen" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x09") "Lege sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " ab.\n"
"Diese neuartige Bombe kann\n"
"an Wänden hinaufkrabbeln -\n"
"also ziele gut!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Deku-Nuß" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x01") "Wirf die Deku-Nuß. Sie wird\n"
"zerplatzen und Deine\n"
"Gegner betäuben!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Bumerang" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0E") "Drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um Gegner\n"
"zu treffen, die weiter\n"
"entfernt sind!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Fanghaken!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Benutze ihn, um entfernte\n"
"Objekte zu Dir zu holen oder\n"
"um Dich an ein Objekt\n"
"heranzuziehen." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Halte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " gedrückt und ziele\n"
"mit " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Läßt Du " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "los,\n"
"schießt Du den Fanghaken ab."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Deku-Stab" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x00") "Benutze ihn mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Wenn Du\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " drückst, kannst Du ihn\n"
"wieder wegpacken." BOX_BREAK ITEM_ICON("\x00") " Du kannst höchstens\n"
"10 Deku-Stäbe tragen, also\n"
"setze sie mit Bedacht ein!"
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Stahlhammer" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um mit ihm\n"
"Objekte zu zerschlagen!\n"
"Du brauchst beide Hände!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "Das " COLOR(RED) "Auge der Wahrheit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Plaziere es auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " und sieh\n"
"mit " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "hindurch! Du wirst\n"
"viele Geheimnisse lüften!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0F") "Setzt Du es ein,\n"
"kostet es magische Energie.\n"
"Mit " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "kannst Du es auch\n"
"wieder deaktivieren."
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Okarina der Zeit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Die Okarina ist ein Artefakt\n"
"aus dem Besitz des Königs.\n"
"Sie hat geheimnisvolle Kräfte!"
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du hast Farores Kräfte beschworen!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Zum Teleporter zurück\n"
"Teleporter entfernen\n"
"Zurück" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "Das " COLOR(RED) "Amulett des Feuers" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Darunia gibt sich als einer\n"
"der Weisen zu erkennen und\n"
"überträgt Dir seine Kraft!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "Das " COLOR(BLUE) "Amulett des Wassers" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ruto gibt sich als eine der\n"
"Weisen zu erkennen und\n"
"überträgt Dir ihre Kraft!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "Das " COLOR(ADJUSTABLE) "Amulett des Waldes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Salia gibt sich als eine der\n"
"Weisen zu erkennen und\n"
"überträgt Dir ihre Kraft!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "Das " COLOR(YELLOW) "Amulett der Geister" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Naboru gibt sich als eine der\n"
"Weisen zu erkennen und\n"
"überträgt Dir ihre Kraft!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "Das " COLOR(LIGHTBLUE) "Amulett des Lichts" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru, der Weise, gibt\n"
"Dir seine Kraft!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "Das " COLOR(PURPLE) "Amulett des Schattens" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Impa gibt sich als eine der\n"
"Weisen zu erkennen und\n"
"überträgt Dir ihre Kraft!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "Eine leere" COLOR(RED) " Flasche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Plaziere die Flasche auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"um sie einzusetzen."
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "Das " COLOR(RED) "Rote Elixier" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du es auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x15") "Benutze es mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um Deine \n"
"Energieleiste aufzufüllen.\n"
"Das Elixier befindet sich in\n"
"einer Deiner Flaschen."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "Das " COLOR(ADJUSTABLE) "Grüne Elixier" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im Gegenstands-Menü kannst\n"
"Du es auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x16") "Benutze es mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um Deine \n"
"Magieleiste aufzufüllen.\n"
"Das Elixier befindet sich in\n"
"einer Deiner Flaschen."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "Das " COLOR(BLUE) "Blaue Elixier" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Benutze es mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um\n"
"Magie- und Energieleiste\n"
"komplett aufzufüllen!"
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "Du besitzt jetzt eine " COLOR(RED) "Fee" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK ITEM_ICON("\x18") "Diese kleine Fee wird Dich\n"
"wiederbeleben, wenn Du keine\n"
"Energie mehr hast." BOX_BREAK ITEM_ICON("\x18") "Hast Du sie auf " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "plaziert, \n"
"kannst Du ihre Hilfe jederzeit\n"
"in Anspruch nehmen."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "Du besitzt jetzt einen " COLOR(RED) "Fisch" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Lasse ihn mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " frei. Er sieht\n"
"richtig frisch aus!" BOX_BREAK ITEM_ICON("\x19") "Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren.\n"
"Mit " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "läßt Du ihn frei."
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Wundererbse" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Suche nach einer Stelle,\n"
"um sie mit " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "einzupflanzen.\n"
"Warte ab, was passiert!" BOX_BREAK ITEM_ICON("\x10") "Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren und\n"
"mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " einpflanzen."
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tut mir leid... Na gut, also..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(RED) "LOS GEHT'S!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Feen-Okarina" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sie ist ein Andenken an Salia!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "Mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " und den " COLOR(YELLOW) "[C]-Knöpfen " COLOR(DEFAULT) "spielst\n"
"Du eine Melodie. Mit " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " kannst\n"
"Du aufhören oder neu beginnen."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Das " COLOR(ADJUSTABLE) "Langschwert" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Schwinge es mit " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "!\n"
"Benutzt Du es, kannst Du\n"
"Deinen " COLOR(LIGHTBLUE) "Schild" COLOR(DEFAULT) " nicht einsetzen!"
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "Der " COLOR(LIGHTBLUE) "Deku-Schild" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Gehe ins " COLOR(BLUE) "Ausrüstungs-Menü" COLOR(DEFAULT) ",\n"
"um ihn mit " COLOR(BLUE) "[A] " COLOR(DEFAULT) "auszuwählen." BOX_BREAK ITEM_ICON("\x3E") "Drücke " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ", um Angriffe\n"
"abzuwehren. Drückst Du " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " und\n"
"bewegst " COLOR(BLUE) "[Control-Pad]" COLOR(DEFAULT) ", schwenkst Du\n"
"den Schild."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "Der " COLOR(LIGHTBLUE) "Hylia-Schild" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Gehe ins " COLOR(BLUE) "Ausrüstungs-Menü" COLOR(DEFAULT) ",\n"
"um ihn mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " auszuwählen."
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "Der " COLOR(LIGHTBLUE) "Spiegel-Schild" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Der Spiegel-Schild reflektiert\n"
"Licht oder Energie. Mit " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "\n"
"setzt Du ihn ein."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Enterhaken" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Dies ist ein viel besserer\n"
"Fanghaken - er reicht\n"
COLOR(RED) "doppelt so weit" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Goronen-Rüstung" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Diese feuerfeste Rüstung\n"
"paßt nur Erwachsenen. Sie\n"
"schützt vor extremer Hitze!"
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Zora-Rüstung" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Diese Unterwasser-Rüstung\n"
"paßt nur Erwachsenen. Du\n"
"kannst unter Wasser atmen!"
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ein " COLOR(ADJUSTABLE) "Magie-Krug" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Deine Magieleiste\n"
"wird aufgefüllt."
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Eisenstiefel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Zu schwer, um zu rennen.\n"
"Zu schwer, um zu schwimmen."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Gleitstiefel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Mit diesen seltsamen Schuhen\n"
"schwebst Du über den Boden." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x46") "Du kannst damit für\n"
"kurze Zeit sogar Abgründe\n"
"überqueren. Habe Mut und\n"
"vertraue den Stiefeln!"
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ein " COLOR(PURPLE) "Herz" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Es füllt eines Deiner \n"
"Energieherzen auf!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Große Köcher" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du insgesamt\n"
COLOR(YELLOW) "40 " COLOR(DEFAULT) "Pfeile tragen!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Riesenköcher" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du insgesamt\n"
COLOR(YELLOW) "50" COLOR(DEFAULT) " Pfeile tragen!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Bombentasche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Diese Bombentasche ist aus\n"
"Dodongo-Leder hergestellt." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Darin findest Du " COLOR(RED) "20 Bomben" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du kannst die Bomben auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"plazieren und Hindernisse\n"
"wegsprengen! Das ist bombig!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Große Bombentasche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du insgesamt " COLOR(YELLOW) "30" COLOR(DEFAULT) "\n"
"Bomben tragen!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Riesen-Bombentasche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du insgesamt " COLOR(YELLOW) "40\n"
COLOR(DEFAULT) "Bomben tragen!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Krafthandschuhe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Trägst Du sie, hast Du\n"
"die Kraft, mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " auch sehr\n"
"schwere Dinge anzuheben!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x51") "Aber einem kleinen Jungen\n"
"sind sie zu groß... Zudem hast\n"
"Du versprochen, sie " COLOR(RED) "Naboru" COLOR(DEFAULT) " zu\n"
"geben! Halte also Wort!"
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Titanhandschuhe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Du fühlst noch größere Kraft\n"
"in den Armen! Du packst\n"
"schwerste Dinge mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Blaues Feuer" COLOR(DEFAULT) " eingefangen!" QUICKTEXT_DISABLE "\n"
"Es ist eine kalte Flamme.\n"
"Benutze sie mit\n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " oder" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Große Börse" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt hast Du eine größere\n"
"Geldbörse erhalten und kannst\n"
"insgesamt " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rubine" COLOR(DEFAULT) " tragen!"
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Riesenbörse" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Welch eine riesige Geldbörse!\n"
"Jetzt kannst Du sogar \n"
COLOR(YELLOW) "500 Rubine" COLOR(DEFAULT) " tragen!"
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "kleiner Schlüssel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Er öffnet eine verschlossene\n"
"Tür. Du kannst ihn nur in\n"
"diesem Labyrinth einsetzen."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Krabbelmine  20 Stück  180 Rubine\n"
COLOR(DEFAULT) "Das ist eine praktische Zeitbombe,\n"
"die Du als Distanzwaffe\n"
"einsetzen kannst!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Rotes Elixier   40 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Rotes Elixier   50 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Rotes Elixier   40 Rubine\n"
COLOR(DEFAULT) "Damit füllst Du Deine Energieleiste\n"
"wieder vollständig auf.\n"
"Zur einmaligen Anwendung." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Rotes Elixier   50 Rubine\n"
COLOR(DEFAULT) "Damit füllst Du Deine Energieleiste\n"
"wieder vollständig auf.\n"
"Zur einmaligen Anwendung." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Labyrinth-Karte" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Drücke " COLOR(RED) "START" COLOR(DEFAULT) ", um sie im\n"
COLOR(RED) "Karten-Bildschirm " COLOR(DEFAULT) "anzusehen!" BOX_BREAK ITEM_ICON("\x76")  COLOR(BLUE) "Blaue Räume" COLOR(DEFAULT) " hast Du bereits\n"
"aufgesucht.\n"
"Der " COLOR(LIGHTBLUE) "blinkende Raum " COLOR(DEFAULT) "zeigt\n"
"Deine derzeitige Position." BOX_BREAK ITEM_ICON("\x76") "Bewege " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "," COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "um ein\n"
"Stockwerk auszuwählen."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Kompaß" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt siehst Du auf Deiner\n"
"Karte alle Schatztruhen\n"
"dieses Labyrinths!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Stein des Wissens" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Benutzt Du ab jetzt Dein\n"
COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", reagiert es... auf\n"
"naheliegende Geheimnisse!"
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "Das ist " COLOR(RED) "Zeldas Brief" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Er trägt Prinzessin Zeldas\n"
"Unterschrift!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x23") "Im " COLOR(YELLOW) "Gegenstands-Menü " COLOR(DEFAULT) "kannst\n"
"Du ihn auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren. Benutze " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um ihn\n"
"jemandem zu zeigen."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hi! Was soll's denn sein?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ich will einkaufen!\n"
"Ich schau nur mal..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du noch etwas kaufen?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "Deine " COLOR(RED) "Munitionstasche\n"
COLOR(DEFAULT) "ist größer geworden!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du insgesamt\n"
COLOR(YELLOW) "50" COLOR(RED) " Deku-Kerne " COLOR(DEFAULT) "tragen!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Öffne eine Truhe und... Voilà!\n"
"Findest Du einen Schlüssel, darfst\n"
"Du den nächsten Raum betreten!\n"
"Links oder rechts? Probier's aus!" BOX_BREAK COLOR(RED) "10 Rubine " COLOR(DEFAULT) "pro Spiel.\n"
"Machst Du mit?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Klasse! Ein echter Zocker!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du hast einen " COLOR(ADJUSTABLE) "Rubin" COLOR(DEFAULT) "\n"
"erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "Die " COLOR(RED) "Feuer-Pfeile" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Plaziere sie auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "," COLOR(YELLOW) " " COLOR(DEFAULT) "um sie\n"
"abzuschießen! Triffst Du,\n"
"wird Dein Ziel entflammen!"
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Eis-Pfeile" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Plaziere sie auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie\n"
"zu verschießen! Triffst Du,\n"
"wird Dein Ziel einfrieren!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0C") "Diese magischen Pfeile darf\n"
"nur der verschießen, der das\n"
"Kampftraining der Gerudo-\n"
"Kriegerinnen bestanden hat!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "Die " COLOR(LIGHTBLUE) "Licht-Pfeile" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Plaziere sie auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie \n"
"zu verschießen - das Licht\n"
"des Guten zerstört Böses!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast das\n"
SHIFT("\x32")  COLOR(ADJUSTABLE) "Menuett des Waldes\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast den\n"
SHIFT("\x35")  COLOR(RED) "Bolero des Feuers\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast die\n"
SHIFT("\x29")  COLOR(BLUE) "Serenade des Wassers\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast das\n"
SHIFT("\x2F")  COLOR(YELLOW) "Requiem der Geister\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast die\n"
SHIFT("\x29")  COLOR(PURPLE) "Nocturne des Schattens\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x46") "Du hast die\n"
SHIFT("\x33")  COLOR(LIGHTBLUE) "Kantate des Lichts\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "Das " COLOR(RED) "Goronen-Armband" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nun kannst Du Donnerblumen\n"
"pflücken. Stelle Dich davor\n"
"und nimm sie mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " auf!"
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "Du hast einen " COLOR(RED) "Käfer " COLOR(DEFAULT) "gefangen!" QUICKTEXT_DISABLE "\n"
"Du kannst ihn mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " freilassen.\n"
"Du findest diese Käfer häufig in \n"
"dunklen Erdhöhlen."
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Gerudo-Paß" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt hast Du Zutritt zur\n"
"großen Trainingsarena der\n"
"Gerudo-Kriegerinnen."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomben  10 Stück  50 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pfeile  50 Stück  90 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fisch   200 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku-Nüsse   5 Stück   15 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "Der " COLOR(ADJUSTABLE) "Kokiri-Smaragd" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Der Deku-Baum hat Dir diesen\n"
"Heiligen Stein des Waldes\n"
"anvertraut!"
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Goronen-Opal" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Von den Goronen wurde Dir\n"
"dieser Heilige Stein\n"
"des Feuers übergeben!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "Der " COLOR(BLUE) "Zora-Saphir" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Von den Zoras wurde Dir\n"
"dieser Heilige Stein\n"
"des Wassers übergeben!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Wähle aus, indem Du " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "nach\n"
"links oder rechts bewegst.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Mit dem Verkäufer sprechen\n"
"Zurück" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Vielen Dank!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deine Rubine reichen nicht aus!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Das kannst Du jetzt nicht kaufen." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku-Nüsse   10 Stück  30 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku-Stab  1 Stück   10 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku-Schild   40 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pfeile   10 Stück   20 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomben   5 Stück   25 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Krabbelmine  10 Stück  100 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mit dem Nachtschwärmer bist Du\n"
"hier falsch! Verkaufe ihn dem\n"
"Mann im Haus rechts vom Burgtor!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Rotes Elixier   30 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Grünes Elixier   30 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Jetzt kannst Du insgesamt\n"
COLOR(YELLOW) "20" COLOR(DEFAULT) " " COLOR(RED) "Deku-Stäbe " COLOR(DEFAULT) "tragen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Jetzt kannst Du insgesamt\n"
COLOR(YELLOW) "30" COLOR(DEFAULT) " " COLOR(RED) "Deku-Stäbe" COLOR(DEFAULT) " tragen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hylia-Schild   80 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Goronen-Rüstung   200 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Zora-Rüstung   300 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Herz   10 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Tut mir leid... Du brauchst eine\n"
"leere Flasche, damit Du das hier\n"
"kaufen kannst." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Irrlicht" COLOR(DEFAULT) " in Deiner\n"
"Flasche gefangen!" QUICKTEXT_DISABLE "\n"
"Dir wird Gutes widerfahren!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "Du hast" COLOR(RED) " Milch " COLOR(DEFAULT) "erhalten!" QUICKTEXT_DISABLE "\n"
"Diese Milch ist sehr gesund!\n"
"Benutze sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um Deine\n"
"Energie aufzufrischen!" BOX_BREAK ITEM_ICON("\x1A") "Du erhältst " COLOR(RED) "fünf Herzen " COLOR(DEFAULT) "pro\n"
"Schluck. Du kannst zweimal\n"
"davon trinken." BOX_BREAK ITEM_ICON("\x1A") "Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du sie auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren. Mit " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "nimmst Du\n"
"einen Schluck."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "Eine " COLOR(RED) "Flasche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Fülle etwas hinein und nutze\n"
"sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "... Oh! Da ist ja\n"
"bereits etwas drin!"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "seltsames Ei" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Es scheint, als würde sich\n"
"darin etwas bewegen!\n"
"Warte ab, was passiert!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x21") "Im " COLOR(YELLOW) "Gegenstands-Menü" COLOR(DEFAULT) " kannst\n"
"Du es auf " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "plazieren.\n"
"Benutze es mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pfeile   30 Stück   60 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen\n"
"Nicht kaufen" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mein heißester Artikel ist zur Zeit\n"
"der " COLOR(LIGHTBLUE) "Hylia-Schild" COLOR(DEFAULT) ". Aber für Dich ist\n"
"er wohl eine Nummer zu groß,\n"
"Kleiner!" EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die Zeiten sind hart, deshalb sind\n"
"wir von Hyrule hierher gezogen.\n"
"Ich würde mich freuen, wenn Du\n"
"bei uns Stammkunde wirst!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x46") "Willkommen!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Deku-Schild   40 Rubine\n"
COLOR(DEFAULT) "Mit " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " kannst Du ihn einsetzen,\n"
"um Angriffe abzuwehren. Bei einer\n"
"Feuerattacke verbrennt er!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pfeile   10 Stück   20 Rubine\n"
COLOR(DEFAULT) "Du brauchst einen Bogen, um sie\n"
"abzuschießen. Du kannst sie nicht\n"
"kaufen, wenn Du noch keinen hast." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Deku-Stab  1 Stück  10 Rubine\n"
COLOR(DEFAULT) "Ein langer, starker Ast des\n"
"Deku-Baumes. Verwende ihn als\n"
"Waffe, bis er zerbricht!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Deku-Nüsse  10 Stück  30 Rubine\n"
COLOR(DEFAULT) "Betäube Deine Gegner damit! Du\n"
"kannst nur soviele kaufen, wie Du\n"
"zur Zeit tragen kannst." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomben   5 Stück   25 Rubine\n"
COLOR(DEFAULT) "Benutze sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Du kannst\n"
"sie nur kaufen, wenn Du eine\n"
"Bombentasche besitzt." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "Das " COLOR(ADJUSTABLE) "Kokiri-Schwert" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Wähle es mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " im\n"
COLOR(BLUE) "Ausrüstungs-Menü" COLOR(DEFAULT) " aus." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x3B") "Dies ist eine wertvolle Waffe\n"
"der Kokiri. Trainiere gut,\n"
"bevor Du Deine Mission\n"
"beginnst!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Rotes Elixier   30 Rubine\n"
COLOR(DEFAULT) "Damit füllst Du Deine Energieleiste\n"
"vollständig auf. Zur einmaligen\n"
"Anwendung!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Grünes Elixier   30 Rubine\n"
COLOR(DEFAULT) "Damit füllst Du Deine Magieleiste\n"
"vollständig auf. Zur einmaligen\n"
"Anwendung!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Jetzt kannst Du\n"
"insgesamt " COLOR(YELLOW) "30" COLOR(RED) " Deku-Nüsse\n"
COLOR(DEFAULT) "tragen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Jetzt kannst Du\n"
"insgesamt " COLOR(YELLOW) "40" COLOR(DEFAULT) " " COLOR(RED) "Deku-Nüsse\n"
COLOR(DEFAULT) "tragen!" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Hylia-Schild   80 Rubine\n"
COLOR(DEFAULT) "Ein großer, schwerer Schild der\n"
"hylianischen Ritter. Er hält sogar\n"
"Feuerattacken stand!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Goronen-Rüstung   200 Rubine\n"
COLOR(DEFAULT) "Eine starke Rüstung der Goronen,\n"
"die nur Erwachsenen paßt.\n"
"Schützt auch vor großer Hitze!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Zora-Rüstung   300 Rubine\n"
COLOR(DEFAULT) "Eine praktische Rüstung der Zoras,\n"
"die nur Erwachsenen paßt. Mit ihr\n"
"kann man unter Wasser atmen!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Herz   10 Rubine\n"
COLOR(DEFAULT) "Damit füllst Du ein Herz\n"
"Deiner Energieleiste auf." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE  COLOR(RED) "Dins Feuerinferno" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Dieser Feuerball entflammt die\n"
"Umgebung! Du setzt diese\n"
"Magie-Attacke mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " ein."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Farores Donnersturm" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ein magischer Teleporter, den\n"
"Du mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " einsetzt. Nutze\n"
"ihn, wenn Gefahr droht!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "Mit dieser Magie legst Du\n"
"einen " COLOR(ADJUSTABLE) "Teleporterpunkt" COLOR(DEFAULT) " an.\n"
"Rufst Du Farores Kraft erneut an,\n"
"gelangst Du dorthin zurück." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "Du kannst den Teleporter\n"
"aber auch wieder aufheben\n"
"und anderswo setzen, wenn\n"
"Du Farores Magie beschwörst."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE  COLOR(BLUE) "Nayrus Umarmung" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Setze diese kraftvolle,\n"
"magische Schutzaura\n"
"mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " ein."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pfeile  50 Stück  90 Rubine\n"
COLOR(DEFAULT) "Du brauchst einen Bogen, um sie\n"
"abzuschießen. Du kannst sie nicht\n"
"kaufen, wenn Du noch keinen hast." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomben  10 Stück  50 Rubine\n"
COLOR(DEFAULT) "Benutze sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Du kannst\n"
"sie nur kaufen, wenn Du eine\n"
"Bombentasche besitzt." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Deku-Nüsse  5 Stück  15 Rubine\n"
COLOR(DEFAULT) "Betäube Deine Gegner damit! Du\n"
"kannst nur soviele kaufen, wie Du\n"
"zur Zeit tragen kannst." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fisch   200 Rubine\n"
COLOR(DEFAULT) "Frisch gefangen! Du kannst ihn in\n"
"einer Flasche aufbewahren." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du hast eine " COLOR(RED) "Goldene Skulltula\n"
COLOR(DEFAULT) "zerstört. Du erhältst dafür ein\n"
"Skulltula-Symbol!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Du hast eine " COLOR(RED) "Goldene Skulltula" COLOR(DEFAULT) "\n"
"zerstört. Du erhältst dafür ein\n"
"Skulltula-Symbol als Beweis!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Feenflasche    50 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fee   50 Rubine\n"
COLOR(DEFAULT) "Dafür brauchst Du eine leere\n"
"Flasche. Begib Dich nie ohne\n"
"Fee in ein Labyrinth!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Blaues Feuer    300 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Blaues Feuer   300 Rubine\n"
COLOR(DEFAULT) "Dafür brauchst Du eine leere\n"
"Flasche. Benutze es, um Eis\n"
"zu schmelzen." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Käfer   50 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Käfer    50 Rubine\n"
COLOR(DEFAULT) "Dafür brauchst Du eine leere\n"
"Flasche. Sieht eigentlich wie\n"
"ein gewöhnlicher Käfer aus..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Krabbelmine  10 Stück  100 Rubine\n"
COLOR(DEFAULT) "Das ist eine praktische Zeitbombe,\n"
"die Du als Distanzwaffe\n"
"einsetzen kannst!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Das haben wir im Augenblick\n"
"nicht auf Lager." COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, Mann! Aus dem Alter\n"
"bist Du doch heraus!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x3D") "Uaah... Waas?!" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x5A") "Hey!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x46") "Ein Kunde!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zzzzzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Pfeile   30 Stück   60 Rubine\n"
COLOR(DEFAULT) "Du brauchst einen Bogen, um sie\n"
"abzuschießen. Du kannst sie nicht\n"
"kaufen, wenn Du noch keinen hast." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hast Du vier Teile gesammelt,\n"
"wird die Energieleiste um\n"
"einen Herzcontainer erhöht!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sammle noch zwei Herzteile,\n"
"und Du erhältst einen\n"
"neuen Herzcontainer!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Finde noch ein Herzteil, dann\n"
"erhöht sich die Energieleiste\n"
"um einen Herzcontainer!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt hast Du einen weiteren\n"
"Herzcontainer! Deine\n"
"Energieleiste erweitert sich!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Herzcontainer" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Die Energieleiste erweitert\n"
"sich um ein Herz. Deine\n"
"Energie wird aufgefüllt!"
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "Der " COLOR(RED) "Master-Schlüssel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jetzt kannst Du endlich jenen\n"
"Raum betreten, in dem der\n"
"Endgegner lauert."
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Verschwinde, Deine\n"
"Rubine reichen nicht aus!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x39") "Okay, das war's!" QUICKTEXT_DISABLE "\n"
"Bitte warte draußen, damit ich das\n"
"nächste Spiel vorbereiten kann!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomben   5 Stück   35 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bomben   5 Stück   35 Rubine\n"
COLOR(DEFAULT) "Benutze sie mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Du kannst\n"
"sie nur kaufen, wenn Du eine\n"
"Bombentasche besitzt." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du hast " COLOR(BLUE) "5 Rubine" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Silberne Schuppe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Begib Dich ins Wasser und\n"
"drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Jetzt kannst Du\n"
"tiefer tauchen als zuvor!"
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "Die " COLOR(BLUE) "Goldene Schuppe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Begib Dich ins Wasser und\n"
"drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Jetzt kannst Du\n"
"sehr tief tauchen!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Es sieht ganz so aus, als würde\n"
"dieser Gegenstand hier nicht\n"
"benötigt..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Geht nicht auf!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x51") "Du hast\n"
SHIFT("\x49")  COLOR(ADJUSTABLE) "Salias Lied\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x51") "Du hast\n"
SHIFT("\x46")  COLOR(RED) "Eponas Lied\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x47") "Du hast die\n"
SHIFT("\x38")  COLOR(YELLOW) "Hymne der Sonne\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x51") "Du hast\n"
SHIFT("\x37")  COLOR(BLUE) "Zeldas Wiegenlied\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x47") "Du hast die\n"
SHIFT("\x3D")  COLOR(LIGHTBLUE) "Hymne der Zeit\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x47") "Du hast die\n"
SHIFT("\x34")  COLOR(PURPLE) "Hymne des Sturms\n"
COLOR(DEFAULT)  SHIFT("\x50") "erlernt!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallo mein süßer " NAME "!\n"
"Ich bin die Fee der Fähigkeiten!" BOX_BREAK UNSKIPPABLE "Ich verleihe Dir mit meiner Macht\n"
"eine " COLOR(ADJUSTABLE) "neue Schwert-Technik" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Sei bereit!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallo mein süßer " NAME "!\n"
"Ich bin die Fee der Weisheit!" BOX_BREAK UNSKIPPABLE "Ich werde Deine " COLOR(ADJUSTABLE) "magische Kraft" COLOR(DEFAULT) "\n"
"erhöhen!" BOX_BREAK UNSKIPPABLE "Sei bereit!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallo mein süßer " NAME "!\n"
"Ich bin die Fee des Mutes!" BOX_BREAK UNSKIPPABLE "Ich verstärke Deine " COLOR(LIGHTBLUE) "Abwehrkraft" COLOR(DEFAULT) "\n"
"gegenüber feindlichen Attacken!" BOX_BREAK UNSKIPPABLE "Sei bereit!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du vom Kampf erschöpft\n"
"bist, kannst Du mich jederzeit\n"
"wieder besuchen!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallo mein süßer " NAME "!\n"
"Ich werde Deine Wunden heilen." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE  COLOR(RED) "Deku-Kerne" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Es sind kleine, harte Kerne.\n"
"Du kannst sie als Munition\n"
"für Deine Schleuder einsetzen."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  UNSKIPPABLE "Du beherrschst die kraftvolle\n"
COLOR(RED) "Wirbelattacke" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Halte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " gedrückt, um Dein\n"
"Schwert aufzuladen. Laß " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "\n"
"los, um einen energiegeladenen\n"
"Rundumschlag auszuführen!" BOX_BREAK UNSKIPPABLE "Bewegst Du " COLOR(LIGHTBLUE) "[Control-Pad] einmal im Kreis" COLOR(DEFAULT) "\n"
"und drückst dann " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", kannst Du\n"
"die Wirbelattacke sofort und ohne\n"
"Wartezeit ausführen."
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku-Kerne  30 Stück  30 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Deku-Kerne  30 Stück  30 Rubine\n"
COLOR(DEFAULT) "Du brauchst erst eine Schleuder,\n"
"um sie kaufen und als Munition\n"
"dafür einsetzen zu können." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Willst Du mit Salia sprechen?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Willst Du dann mit mir sprechen? \n"
"\n"
COLOR(DEFAULT)  TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x2A") "Hallo " NAME "!\n"
SHIFT("\x37") "Ich bin es, " COLOR(ADJUSTABLE) "Salia" COLOR(DEFAULT) ".\n"
SHIFT("\x3B") "Hörst Du mich?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Willst Du nochmal mit ihr reden?" COLOR(DEFAULT) "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Deine " COLOR(ADJUSTABLE) "magische Kraft" COLOR(DEFAULT) " wurde erhöht!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Deine " COLOR(LIGHTBLUE) "Abwehrkraft" COLOR(DEFAULT) " wurde verstärkt!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Du hast neue " COLOR(YELLOW) "Pfeile" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sammelst Du Kraft für eine\n"
"Wirbelattacke, verbrauchst Du\n"
"magische Energie. Achte also auf\n"
"Deine " COLOR(ADJUSTABLE) "grüne Magieleiste" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Sag mal, Du bist doch ein Bote\n"
"der königlichen Familie, oder?" BOX_BREAK UNSKIPPABLE "Wenn Du wieder dort bist, dann\n"
"schau in der Nähe des Schlosses\n"
"bei einer guten Freundin von mir\n"
"vorbei!" BOX_BREAK UNSKIPPABLE "Sie hat bestimmt auch etwas für\n"
"Dich, um Deine Fähigkeiten\n"
"zu verbessern!"
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Deine magischen Kräfte wurden\n"
"verstärkt! Du hast nun " COLOR(RED) "doppelt\n"
"soviel magische Energie" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Deine Abwehrkraft wurde\n"
"verstärkt! Gegnerische Angriffe\n"
"fügen Dir ab jetzt nur noch\n"
COLOR(RED) "halb soviel Schaden " COLOR(DEFAULT) "zu!"
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallo mein süßer " NAME "!\n"
"Ich bin die Fee der Magie!" BOX_BREAK UNSKIPPABLE "Ich habe einen " COLOR(RED) "mächtigen Zauber" COLOR(DEFAULT) "\n"
"für Dich. Bitte nimm ihn an."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Tut mir leid, aber Du kannst diese\n"
"Maske jetzt noch nicht ausleihen." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(RED) "Dins Feuerinferno" COLOR(DEFAULT) " kannst Du nicht\n"
"nur für Attacken nutzen.\n"
"Du kannst damit auch manches in\n"
"Brand setzen!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vergiß nicht: " COLOR(ADJUSTABLE) "Farores Donnersturm" COLOR(DEFAULT) "\n"
"kannst Du nur in einem Labyrinth\n"
"einsetzen, in dem auch eine Karte\n"
"versteckt ist. Alles klar?"
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(BLUE) "Nayrus Umarmung" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "kannst Du nur\n"
"für begrenzte Zeit nutzen. Wende\n"
"diesen Zauber also mit Bedacht an."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bist Du vom Kampf erschöpft,\n"
"besuche mich einfach wieder."
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du hast " COLOR(RED) "20 Rubine" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du hast " COLOR(PURPLE) "50 Rubine" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Du hast " COLOR(YELLOW) "200 Rubine" COLOR(DEFAULT) " erhalten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Ein " COLOR(RED) "Schlüssel" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Damit gelangst Du in den\n"
"nächsten Raum. Wähle dort\n"
"eine neue Schatzkiste aus!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dumm gelaufen!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hast " COLOR(ADJUSTABLE) "einen Rubin" COLOR(DEFAULT) " gefunden.\n"
"Vielleicht hättest Du doch besser\n"
"die andere Kiste geöffnet..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dumm gelaufen!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hast nur" COLOR(BLUE) " 5 Rubine" COLOR(DEFAULT) " gefunden.\n"
"Du hättest besser die Truhe\n"
"geöffnet, in der sich der\n"
"Schlüssel befindet..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dumm gelaufen!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hast nur " COLOR(RED) "20 Rubine\n"
COLOR(DEFAULT) "gefunden.\n"
"Das ist heute wohl nicht so ganz\n"
"Dein Tag, oder?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Gratuliere!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Du hast" COLOR(YELLOW) " 50 Rubine" COLOR(DEFAULT) " gefunden.\n"
"Du bist ja wirklich ein Glückspilz!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "Du hast den " COLOR(RED) "Nachtschwärmer\n"
COLOR(DEFAULT) "in Deiner Flasche gefangen!" QUICKTEXT_DISABLE "\n"
"Gehe in den " COLOR(RED) "Gespenstermarkt" COLOR(DEFAULT) "\n"
"und verkaufe ihn!"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x53")  COLOR(RED) "SUPER!" COLOR(DEFAULT)  BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) " gefunden!" QUICKTEXT_DISABLE "\n"
"Hast Du vier Herzteile gesammelt,\n"
"erhöht sich Deine Energieleiste\n"
"um einen Herzcontainer!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x53")  COLOR(RED) "SUPER!" COLOR(DEFAULT)  BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) " gefunden!" QUICKTEXT_DISABLE "\n"
"Du besitzt jetzt zwei Herzteile.\n"
"Mit zwei weiteren erhältst Du\n"
"einen neuen Herzcontainer."
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x53")  COLOR(RED) "SUPER!" COLOR(DEFAULT)  BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) " gefunden!" QUICKTEXT_DISABLE "\n"
"Du besitzt nun drei Herzteile!\n"
"Finde ein weiteres, und Deine\n"
"Energieleiste erhöht sich!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x53")  COLOR(RED) "SUPER!" COLOR(DEFAULT)  BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Du hast ein " COLOR(RED) "Herzteil" COLOR(DEFAULT) " gefunden!" QUICKTEXT_DISABLE "\n"
"Jetzt besitzt Du einen weiteren\n"
"Herzcontainer! Die Energieleiste\n"
"erhöht sich um ein Herz!"
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Suche nach den Skulltulas nicht\n"
"nur im Freien, sondern auch in\n"
"den Labyrinthen." BOX_BREAK "Aber natürlich ist es nur ein\n"
"Wunsch von uns... Wenn Du das\n"
"nicht tun willst, zwingen wir\n"
"Dich nicht." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Was mag das sein?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Schau doch, " NAME "!\n"
"Wenn Du " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) " drückst, dann\n"
"kannst Du durch das " COLOR(DEFAULT) "Netz\n"
COLOR(LIGHTBLUE) "nach unten sehen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sieh Dir diese Wand an!\n"
"Vielleicht kannst Du ja an\n"
"den Pflanzen hinaufklettern?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Um eine " COLOR(DEFAULT) "Tür" COLOR(LIGHTBLUE) " zu öffnen, stelle\n"
"Dich genau davor und drücke " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Achte auf das\n"
COLOR(BLUE) "blaue Aktions-Symbol" COLOR(LIGHTBLUE) ".\n"
"Es befindet sich am\n"
COLOR(BLUE) "oberen Bildrand" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Schau! Dort oben hängt etwas!\n"
"Sieht aus wie eine alte " COLOR(DEFAULT) "Leiter" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hey...\n"
"Sieht das hier nicht aus\n"
"wie das Symbol am " COLOR(DEFAULT) "Zeitportal" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sieht so aus, als habe diese\n"
"Fackel vor kurzem noch gebrannt..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ab hier wird es ziemlich eng!" COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "Sei vorsichtig, damit Dich\n"
"keine miesen Typen erwischen!" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Drücke " COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "und stelle Dich gleich" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "in die richtige Richtung.\n"
"So schaust Du sofort den Gang\n"
"hinab, wenn Du um die Ecke gehst." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Hast Du Dich richtig hingestellt,\n"
"halte " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) " gedrückt und laufe\n"
COLOR(DEFAULT) "seitwärts" COLOR(LIGHTBLUE) " um die Ecke. So kann\n"
"Dir niemand auflauern!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Stelle Dich vor den " COLOR(DEFAULT) "Steinblock\n"
COLOR(LIGHTBLUE) "und halte " COLOR(BLUE) "[A] " COLOR(LIGHTBLUE) "gedrückt.\n"
"So kannst Du ihn ziehen oder \n"
"schieben." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Auch zum Hinaufklettern mußt" COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "Du Dich vor den Block stellen." COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "Drücke erst" COLOR(DEFAULT) " [Control-Pad] " COLOR(LIGHTBLUE) "in Richtung des\n"
COLOR(DEFAULT) "Blocks" COLOR(LIGHTBLUE) " und dann" COLOR(DEFAULT) " " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Achte auf das\n"
COLOR(BLUE) "blaue Aktions-Symbol" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Befindest Du Dich im Wasser,\n"
"kannst Du tauchen, indem Du" COLOR(DEFAULT) "\n"
COLOR(BLUE) "[A] " COLOR(LIGHTBLUE) "gedrückt hältst! Wetten,\n"
"Du findest etwas Interessantes?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Wow! Schau Dir all die\n"
COLOR(DEFAULT) "Donnerblumen " COLOR(LIGHTBLUE) "an!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Meinst Du, Du kannst sie\n"
"alle auf einmal zünden?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sieht aus, als wären hier jede\n"
"Menge " COLOR(DEFAULT) "Lavagruben" COLOR(LIGHTBLUE) "! Paß auf, wo\n"
"Du hintrittst!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Betätige den Schalter, damit sich\n"
"die " COLOR(DEFAULT) "Plattform" COLOR(LIGHTBLUE) " hebt. So erreichst\n"
"Du leicht ein höheres Stockwerk!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "In diesen schmalen Gängen weiß\n"
"man nie, was sich hinter der \n"
"nächsten Ecke befindet..." BOX_BREAK COLOR(LIGHTBLUE)  UNSKIPPABLE "Drücke " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) ", um immer in die\n"
"richtige Richtung zu schauen.\n"
"Praktisch, nicht wahr?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", wohin schaust Du\n"
"eigentlich?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Der Wüstenkoloss! Das Gesicht\n"
"sieht wirklich bösartig aus!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ich höre in diesem Raum\n"
"geisterhafte Stimmen flüstern..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Sie flüstern mir zu: " COLOR(DEFAULT) "\"Suche\n"
"nach dem Auge der Wahrheit...\""
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ich höre die Geister in\n"
"diesem Raum flüstern..." BOX_BREAK COLOR(LIGHTBLUE) "Sie flüstern mir zu:" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE "\"Jener, dessen\n"
COLOR(RED) "Schritte heilig" COLOR(DEFAULT) " sind, möge sich vom\n"
"Wind treiben lassen. Er führt\n"
"ihn über den verborgenen Pfad.\""
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Diese Mauer...\n"
"Hier heißt es...\n"
COLOR(DEFAULT) "\"Gefahr von oben...\""
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Diese Mauer...\n"
"Hier heißt es...\n"
COLOR(DEFAULT) "\"Gefahr aus der Tiefe...\""
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Das Wasser dieser Statue\n"
"flutet das gesamte Stockwerk." COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vorsicht, " NAME "!\n"
"Dieses " COLOR(ADJUSTABLE) "grüne, schleimige Ding" COLOR(LIGHTBLUE) " ist\n"
"voller elektrischer Energie!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vorsicht, " NAME "!\n"
"Dieses " COLOR(RED) "rote, schleimige Ding" COLOR(LIGHTBLUE) " ist\n"
"voller elektrischer Energie!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vorsicht, " NAME "!\n"
"Dieses " COLOR(BLUE) "blaue, schleimige Ding" COLOR(LIGHTBLUE) " ist\n"
"voller elektrischer Energie!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Der " COLOR(DEFAULT) "Schalter" COLOR(LIGHTBLUE) "...\n"
"Sieht so aus, als könntest Du ihn\n"
"nicht betätigen, da Du allein zu \n"
"leicht bist..." COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Das " COLOR(RED) "rote, schleimige Ding " COLOR(LIGHTBLUE) "ist fort!\n"
"Es verschwand, als Du den\n"
"Tentakel zerstört hast! Ob das\n"
"bei den anderen auch funktioniert?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hinter dieser Wand befindet sich\n"
"ein Schalter!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sieht so aus, als befände sich auf\n"
"dieser Plattform etwas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x49")  COLOR(LIGHTBLUE) "WAAAAS!?" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Schau Dir all die " COLOR(DEFAULT) "Flaggen" COLOR(LIGHTBLUE) " an!\n"
"Finde heraus, welche davon\n"
"echt ist!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Der Weg zum " COLOR(DEFAULT) "Deku-Baum " COLOR(LIGHTBLUE) "befindet\n"
"sich im Osten des Dorfes!\n"
"Wir sollten uns beeilen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Also los! Sei mutig!\n"
"Laß uns den\n"
"Deku-Baum betreten!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Der Deku-Baum wollte, daß wir\n"
"die Prinzessin im " COLOR(DEFAULT) "Schloß von\n"
"Hyrule" COLOR(LIGHTBLUE) " besuchen... Sollten wir\n"
"uns nicht etwas beeilen?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Das Mädchen von der Farm wollte,\n"
"daß wir ihren " COLOR(DEFAULT) "Vater" COLOR(LIGHTBLUE) " suchen...\n"
"Wo er wohl sein mag?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Wie sollen wir in diesem großen\n"
"Schloß die " COLOR(DEFAULT) "Prinzessin" COLOR(LIGHTBLUE) " finden?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Was " COLOR(DEFAULT) "Salia" COLOR(RED) " " COLOR(LIGHTBLUE) "wohl sagen würde, wenn\n"
"sie wüßte, daß wir Hyrule retten?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Impa " COLOR(LIGHTBLUE) "sagte, daß sich der\n"
"Heilige Stein des Feuers\n"
"irgendwo im " COLOR(DEFAULT) "Todesberg" COLOR(LIGHTBLUE) " befindet." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Nimm eine " COLOR(DEFAULT) "Donnerblume" COLOR(LIGHTBLUE) ", um in\n"
"Dodongos Höhle zu gelangen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Wenn ich mich richtig erinnere,\n"
"sagte Darunia, daß auf dem Gipfel\n"
"des Todesbergs eine " COLOR(DEFAULT) "Fee" COLOR(LIGHTBLUE) " lebt!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ich frage mich, ob " COLOR(DEFAULT) "Salia" COLOR(LIGHTBLUE) " etwas\n"
"über den anderen Heiligen Stein\n"
"weiß..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Es scheint, als sei " COLOR(DEFAULT) "Prinzessin\n"
"Ruto " COLOR(LIGHTBLUE) "irgendwie im Bauch von\n"
"Lord Jabu-Jabu verschwunden!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Du besitzt nun die\n"
"drei Heiligen Steine!\n"
"Laß uns nach " COLOR(DEFAULT) "Hyrule " COLOR(LIGHTBLUE) "gehen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Die beiden auf dem weißen Pferd...\n"
"Das waren doch Zelda und Impa!\n"
"Sah aus, als hätten sie etwas in\n"
"den " COLOR(DEFAULT) "Wassergraben" COLOR(LIGHTBLUE) " geworfen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Laß uns in die\n"
COLOR(DEFAULT) "Zitadelle der Zeit" COLOR(LIGHTBLUE) " gehen." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Sollen wir Shiek glauben und \n"
"nach " COLOR(DEFAULT) "Kakariko " COLOR(LIGHTBLUE) "gehen?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ich frage mich, was in Kokiri\n"
"gerade passiert... Auch um " COLOR(DEFAULT) "Salia" COLOR(LIGHTBLUE) "\n"
"mache ich mir Sorgen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Diese Wolke über dem\n"
COLOR(DEFAULT) "Todesberg" COLOR(LIGHTBLUE) "... Sie bedeutet\n"
"nichts Gutes..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Spürst Du das? Ein eisiger Wind\n"
"weht vom " COLOR(DEFAULT) "Zora-Fluß " COLOR(LIGHTBLUE) "herüber!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Diese " COLOR(DEFAULT) "Eisenstiefel" COLOR(LIGHTBLUE) " sehen furchtbar\n"
"schwer aus! Wenn Du sie trägst,\n"
"kannst Du vielleicht am Grund des\n"
"Sees herumlaufen." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Laß uns jemanden suchen,\n"
"der uns etwas über die\n"
"anderen " COLOR(DEFAULT) "Weisen " COLOR(LIGHTBLUE) "erzählen\n"
"kann!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Dieser Dämon! Er kam\n"
"aus dem " COLOR(DEFAULT) "Brunnen im Dorf" COLOR(LIGHTBLUE) "!\n"
"Laß uns mal dorthin gehen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Ich frage mich, wer wohl\n"
"den " COLOR(DEFAULT) "Geistertempel" COLOR(LIGHTBLUE) " gebaut\n"
"hat? Und aus welchem Grund?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Du hast die " COLOR(PURPLE) "Nocturne des\n"
"Schattens" COLOR(LIGHTBLUE) " von Shiek erlernt.\n"
"Warum spielst Du sie nicht?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "In der " COLOR(DEFAULT) "Wüste" COLOR(LIGHTBLUE) " wurde Ganondorf,\n"
"der Großmeister des Bösen,\n"
"geboren.\n"
"Vielleicht finden wir dort etwas..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Verwende die " COLOR(DEFAULT) "Krafthandschuhe" COLOR(LIGHTBLUE) ",\n"
"um Dinge anzuheben, die Du\n"
"zuvor nicht bewegen konntest!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Jemand wartet in der Zitadelle\n"
"der Zeit auf uns... Ist es..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Los doch! Zu Ganons" COLOR(DEFAULT) " " COLOR(LIGHTBLUE) "Schloß! Wir\n"
"müssen Prinzessin Zelda befreien!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME "...\n"
"Los! Beeile Dich!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Ich unterhalte mich gern auf\n"
"telepathische Weise mit Dir.\n"
"Doch jetzt würde ich Dich lieber\n"
"persönlich sprechen!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Dieser Wald ist mit vielen Orten\n"
"verbunden. Wenn Du mein Lied\n"
"irgendwo hörst, muß es von dort\n"
"einen Weg hierher geben!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Ich habe mich sehr gefreut, daß\n"
"Darunia mein Lied gefallen hat!" BOX_BREAK "Noch schöner finde ich, daß es\n"
"Dir bei Deiner Mission geholfen\n"
"hat, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Sammelst Du die Heiligen Steine?\n"
"Du mußt noch einen finden? Den\n"
COLOR(BLUE) "Heiligen Stein des Wassers" COLOR(DEFAULT) ", oder?" BOX_BREAK "Der Deku-Baum erzählte mir einst,\n"
"daß ihn " COLOR(BLUE) "König Zora" COLOR(DEFAULT) " besitzt..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Sammelst Du die Heiligen Steine?\n"
"Du mußt noch einen finden? Den\n"
COLOR(RED) "Heiligen Stein des Feuers" COLOR(DEFAULT) ", oder?" BOX_BREAK "Der Deku-Baum erzählte mir einst,\n"
"daß ihn " COLOR(RED) "Darunia" COLOR(DEFAULT) ", der Gebieter über\n"
"Goronia, besitzt..." EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Ich weiß nicht, was geschieht...\n"
"Ich fühle eine Bedrohung..." BOX_BREAK "Das Schloß...\n"
"Dort geschieht Furchtbares!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Nanu? Deine Okarina klingt...\n"
"irgendwie anders...\n"
"Du hast wohl kräftig geübt,\n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Suchst Du nach einem Tempel?\n"
"Ein seltsamer Vogel erzählte\n"
"mir einst..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Augen, deren Blick die Dunkelheit\n"
"durchdringt, sehen weit mehr." COLOR(DEFAULT) "\"\n"
"Kannst Du Dir vorstellen, was er\n"
"damit wohl gemeint hat?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Wo bist Du, " NAME "?\n"
"Suchst Du einen Tempel?\n"
"Ich hörte einst einen\n"
"seltsamen Vogel sagen..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Geh, junger Held. Besuche die\n"
"Wüstengöttin mit Deiner Okarina." COLOR(DEFAULT) "\"\n"
"Kannst Du Dir vorstellen, was er\n"
"damit wohl gemeint hat?" EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Hast Du schon alle\n"
"Tempel besucht?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Großartig! Du hast es geschafft!\n"
"Ich wußte, daß ich wieder von Dir\n"
"hören würde!" BOX_BREAK "Ich bin im " COLOR(ADJUSTABLE) "Waldtempel" COLOR(DEFAULT) "!\n"
"Die Geister des Waldes haben um\n"
"Hilfe gerufen, also bin ich\n"
"dorthin geeilt..." BOX_BREAK "Aber hier lauern überall bösartige\n"
"Kreaturen!\n"
"Hilf mir, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Erst wollte ich nicht zur\n"
COLOR(ADJUSTABLE) "Weisen des Waldes" COLOR(DEFAULT) " werden..." BOX_BREAK "Doch nun bin ich glücklich!" BOX_BREAK "Jetzt kann ich Dir helfen,\n"
"Hyrule zu retten, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Sind alle sechs " COLOR(RED) "Weisen" COLOR(DEFAULT) " vereint,\n"
"können wir Ganondorf, den\n"
"Großmeister des Bösen,\n"
"ins Höllenreich verbannen." BOX_BREAK "Doch um ein machtvolles Siegel zu\n"
"erschaffen, benötigen wir die\n"
"Kraft des " COLOR(RED) "Siebten Weisen" COLOR(DEFAULT) "." BOX_BREAK "Dies ist jemand,\n"
"den Du kennst, " NAME "..." BOX_BREAK "Du mußt zwischen\n"
"Vergangenheit und Zukunft\n"
"hin- und herreisen, um die\n"
"anderen Weisen zu erwecken!" BOX_BREAK "Sei weiterhin so mutig,\n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Wir, die Sechs Weisen, übertragen\n"
"Dir all unsere Kraft!" BOX_BREAK "Das Schicksal Hyrules liegt nun\n"
"in Deinen Händen!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ich höre eine Stimme von\n"
"irgendwo..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Sie flüstert mir zu:\n"
"\n"
COLOR(DEFAULT)  SHIFT("\x11") "\"Sammle fünf silberne Steine...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Diese Mauer... Sie teilt mir\n"
"etwas mit!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Sie flüstert mir zu:\n"
COLOR(DEFAULT)  SHIFT("\x1A") "Willst Du mit einer Fähre\n"
SHIFT("\x1E") "in fremde Gefilde reisen,\n"
SHIFT("\x35") "so tritt näher..."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sei vorsichtig, wenn Du " COLOR(DEFAULT) "an Bord" COLOR(LIGHTBLUE) "\n"
"gehst! Es sieht ganz schön alt\n"
"aus... Wer weiß, wann es sinkt?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hier drüben befindet sich eine " COLOR(DEFAULT) "Tür" COLOR(LIGHTBLUE) "...\n"
"Gibt es irgendeinen Weg herüber?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Rotes Eis" COLOR(LIGHTBLUE) "... Das ist\n"
"seltsam..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Das ist " COLOR(DEFAULT) "blaues Feuer" COLOR(LIGHTBLUE) "... Es\n"
"wirkt übernatürlich. Aber vielleicht\n"
"kannst Du es ja für irgendetwas\n"
"gebrauchen?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Das " COLOR(DEFAULT) "Feuer der Fackeln" COLOR(LIGHTBLUE) " ist\n"
"erloschen. Es scheint, als wäre es\n"
"von Geistern genommen worden!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Sieh doch, " NAME "! Eine\n"
COLOR(DEFAULT) "Fackel" COLOR(LIGHTBLUE) " brennt wieder! Es liegt\n"
"daran, daß Du einen Geist\n"
"erlöst hast, oder?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Auf diesem Boden sind\n"
COLOR(DEFAULT) "Pfeile" COLOR(LIGHTBLUE) " aufgemalt!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Dieser " COLOR(DEFAULT) "Korridor " COLOR(LIGHTBLUE) "ist\n"
"völlig verdreht!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Achte auf die\n"
COLOR(DEFAULT) "Schatten der Kreaturen" COLOR(LIGHTBLUE) ",\n"
"die an der Decke hängen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hier befindet sich\n"
"eine " COLOR(DEFAULT) "Schatzkiste!"
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Das ist die gleiche " COLOR(DEFAULT) "Fackel" COLOR(LIGHTBLUE) ",\n"
"die wir auch am Eingang dieses\n"
"Tempels gesehen haben, oder?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Die" COLOR(DEFAULT) " Fackel" COLOR(LIGHTBLUE) " brennt... Das bedeutet..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Dieser " COLOR(DEFAULT) "Schalter" COLOR(LIGHTBLUE) " ist eingefroren!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", paß auf!\n"
"Die Decke fällt herab!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", ich kann unter\n"
"uns " COLOR(DEFAULT) "Stimmen von\n"
"Goronen" COLOR(LIGHTBLUE) " hören." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Schau hier herunter...\n"
"Ist das nicht der Raum, in dem\n"
"wir " COLOR(DEFAULT) "Darunia" COLOR(LIGHTBLUE) " getroffen haben?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Diese " COLOR(DEFAULT) "Statue" COLOR(LIGHTBLUE) "... Haben wir sie\n"
"nicht schon an anderem Orte \n"
"gesehen?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Der" COLOR(DEFAULT) " Schalter" COLOR(LIGHTBLUE) " sieht verrostet aus." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Sei vorsichtig!\n"
"Laß Dich nicht von\n"
"den Strudeln erfassen!" COLOR(DEFAULT)
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
SHIFT("\x0F") "Hi! Ich bin die sprechende Tür!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x19")  COLOR(LIGHTBLUE) "Komisch... Diese Tür läßt sich\n"
COLOR(DEFAULT)  SHIFT("\x41")  COLOR(LIGHTBLUE) "nicht öffnen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x04")  COLOR(LIGHTBLUE) "Dicke " COLOR(DEFAULT) "Eisenstangen " COLOR(LIGHTBLUE) "blockieren die\n"
COLOR(DEFAULT)  SHIFT("\x21")  COLOR(LIGHTBLUE) "Tür. Finde einen Weg, sie\n"
COLOR(DEFAULT)  SHIFT("\x31")  COLOR(LIGHTBLUE) "dennoch zu öffnen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x03")  COLOR(LIGHTBLUE) "Du benötigst einen " COLOR(DEFAULT) "Schlüssel," COLOR(LIGHTBLUE) " um \n"
COLOR(DEFAULT)  SHIFT("\x01")  COLOR(LIGHTBLUE) "eine solche Tür öffnen zu können!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x27")  COLOR(LIGHTBLUE) "Hier fehlt Dir wohl ein" COLOR(DEFAULT) "\n"
SHIFT("\x2E")  COLOR(LIGHTBLUE) "spezieller" COLOR(DEFAULT) " Schlüssel!"
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "RUHE!" QUICKTEXT_DISABLE  BOX_BREAK "Es ist erst " TIME " Uhr!\n"
COLOR(RED) "Boris" COLOR(DEFAULT) ", der Totengräber,\n"
"schläft noch!" BOX_BREAK "Genieße einen Spaziergang auf \n"
"dem Friedhof und komm \n"
"später wieder!"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Es ist jetzt " TIME " Uhr!\n"
"Die " COLOR(RED) "Grabgrusel-Tour" COLOR(DEFAULT) "\n"
"ist vorüber!" BOX_BREAK COLOR(RED) "Boris" COLOR(DEFAULT) ", der Totengräber,\n"
"schläft jetzt!" BOX_BREAK "Unterhalte Dich mit den Geistern \n"
"der Toten und komm \n"
"später wieder!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Maskenhändler\n"
COLOR(DEFAULT) "Bitte das Schild lesen!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "So funktioniert dieser Handel:\n"
COLOR(DEFAULT) "Die Masken werden nicht verkauft.\n"
"Wir " COLOR(RED) "leihen" COLOR(DEFAULT) " sie Dir nur." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du verkaufst die Masken." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Das so verdiente " COLOR(RED) "Geld " COLOR(DEFAULT) "gibst Du uns\n"
"und wir leihen Dir ein aktuelleres\n"
"Modell." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Du kannst auch eine bereits\n"
"verkaufte Maske nochmals leihen,\n"
"aber Du kannst sie nur einmal\n"
"verkaufen." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Probiere es einfach mal aus!\n"
SHIFT("\x63") "Der Maskenhändler"
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Der Schattentempel...\n"
"Hier ruhen Hyrules blutige Zeugnisse\n"
"von großer Gier und\n"
"blindem Hass..." EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"In der Dunkelheit verborgen...\n"
"Das bloße Auge listig täuschend...\n"
"Bleibt der rechte Weg verhüllt..." EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Jenem mit dem " COLOR(RED) "Auge der Wahrheit\n"
COLOR(DEFAULT) "wird sich manches offenbaren, was\n"
"noch von Dunkelheit umgeben..." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Eine seltsame Magie versperrt Dir\n"
"den Zugang. Löse das " COLOR(DEFAULT) "Rätsel" COLOR(LIGHTBLUE) "\n"
"dieses Raumes und Du erhältst\n"
"Zutritt!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der riesige Schädel...\n"
"Leuchten seine Augen rot,\n"
"öffnet sich ein neuer Weg!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x34")  COLOR(LIGHTBLUE) "Schatzkisten-Poker\n"
COLOR(DEFAULT)  SHIFT("\x17") "Vorübergehend geschlossen! \n"
SHIFT("\x29") "Erst abends geöffnet!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x47")  COLOR(LIGHTBLUE) "Magie-Laden\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Bis morgen früh geschlossen!"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x43")  COLOR(LIGHTBLUE) "Schießbude\n"
COLOR(DEFAULT)  SHIFT("\x23") "Nur tagsüber geöffnet!"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x3E")  COLOR(LIGHTBLUE) "Maskenhändler\n"
COLOR(DEFAULT)  SHIFT("\x15") "Reisender Händler gesucht!\n"
SHIFT("\x12") "Bewerbungen bitte tagsüber!"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x51")  COLOR(LIGHTBLUE) "Basar\n"
COLOR(DEFAULT)  SHIFT("\x20") "Nur tagsüber geöffnet!"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Hast Du Feuer?"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Jenen mit dem " COLOR(RED) "Auge der Wahrheit" COLOR(DEFAULT) "\n"
"wird ein hilfsbereites Phantom\n"
"zum Geistertempel führen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Jener, der den Zugang auf dem\n"
"Grund des Sees öffnen will, möge\n"
"ein " COLOR(RED) "Schlaflied aus königlicher\n"
"Überlieferung " COLOR(DEFAULT) "spielen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Jener, der das Tor in großer\n"
"Höhe öffnen will, möge\n"
"ein " COLOR(RED) "Schlaflied aus königlicher\n"
"Überlieferung " COLOR(DEFAULT) "spielen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Wer den " COLOR(RED) "Schlüssel" COLOR(DEFAULT) " findet, der\n"
"darf den nächsten Raum betreten.\n"
"Wer versagt, kann gehen!"
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wer Audienz wünscht, der möge\n"
"von der Plattform aus\n"
"zu mir sprechen." EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Hi " NAME "!" QUICKTEXT_DISABLE "\n"
"Schau zu mir herauf!" BOX_BREAK "Mit " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "schaust Du mich an, und\n"
"mit " COLOR(BLUE) "[A] " COLOR(DEFAULT) "kannst Du mit mir reden."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schau mir in die Augen und wisse, \n"
"es ist " COLOR(RED)  TIME " " COLOR(DEFAULT) "Uhr."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Erleuchte die lebenden Toten..."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Flatternde Schatten " COLOR(DEFAULT) "lauern im\n"
"Dunkel! Solange sie existieren,\n"
"versperren sie den Weg."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, Kleiner! Dich meine ich!\n"
"Schau hierher, in die Zelle!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mein Sohn ist gerade nicht\n"
"zuhause...\n"
"Vielleicht spielt er ja auf dem\n"
"Friedhof..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, mein Sohn schläft gerade.\n"
"Bitte komm doch später wieder,\n"
"wenn Du mit ihm spielen willst!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wenn das Wasser den See ausfüllt,\n"
"ziele auf die Morgensonne." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wer in die Zukunft reist, der\n"
"möge aus der Vergangenheit\n"
"kommen und die " COLOR(BLUE) "Kraft des Silbers" COLOR(DEFAULT) "\n"
"tragen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Komme in der Vergangenheit hierher\n"
"mit dem reinen Herzen eines Kindes." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Diese Tür wird zur Zeit\n"
"verschönert." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Sieht aus, als hätte hier jemand\n"
"etwas weggenommen..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1B") "Drehe meinen Schnabel zum\n"
SHIFT("\x2C")  COLOR(RED) "Schädel der Wahrheit" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x24") "Andernfalls stürzt Du in\n"
SHIFT("\x29") "unendliche Dunkelheit!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Das ist nicht der rechte " COLOR(DEFAULT) "Schlüssel!" COLOR(LIGHTBLUE) "\n"
"Die Tür bleibt Dir verschlossen..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3A")  COLOR(LIGHTBLUE) "Asas Hexenladen\n"
COLOR(DEFAULT)  SHIFT("\x46") "Geschlossen" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x28") "Bin auf Kräutersuche!\n"
SHIFT("\x2B") "Komm später wieder...\n"
SHIFT("\x26") "...wenn Du es wagst!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Wer ist da? Schon wieder so ein\n"
"Rattengesicht, das durch die\n"
"Hintertür kommen will!" QUICKTEXT_DISABLE  BOX_BREAK TEXT_SPEED("\x02") "Rattengesicht..." TEXT_SPEED("\x00") "\n"
"Ich muß Dir ein paar interessante\n"
"Neuigkeiten erzählen!" BOX_BREAK "Der Chef der Zimmerleute hat\n"
"einen Sohn...\n"
"Es ist der Typ, der jeden Abend\n"
"beim Baum herumlungert..." BOX_BREAK "Erzähl dem Chef bloß nicht, daß\n"
"ich Dir das gesagt habe!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Schau Dir das an!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Malon ist zu Bett gegangen!\n"
"Ich geh jetzt auch schlafen.\n"
"Komm wieder, wenn es hell ist!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bestleistungen von " NAME "!\n"
COLOR(DEFAULT) "Skulltula-Symbole: " TOKENS "\n"
"Größter Fang: " HIGHSCORE(HS_LARGEST_FISH) " Pfund" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Bestzeit beim Marathon: " HIGHSCORE(HS_MARATHON) "\n"
"Bestzeit beim Pferderennen: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Bogenschießen: " HIGHSCORE(HS_HORSE_ARCHERY) " Punkte" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x25") "Hier steht die Inschrift\n"
SHIFT("\x39") "aus dem Wappen\n"
SHIFT("\x17") "der Königsfamilie von Hyrule." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "R.I.P.\n"
SHIFT("\x0D") "Hier ruhen die Seelen derer, die\n"
SHIFT("\x19") "der Königsfamilie von Hyrule\n"
SHIFT("\x12") "ewige Treue geschworen haben." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x23") "Über ihre Seelen wachen\n"
SHIFT("\x24") "in Ewigkeit die Shiekah,\n"
SHIFT("\x18") "Beschützer der Königsfamilie\n"
SHIFT("\x28") "und Erbauer Kakarikos." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(BLUE) "Rastloser Wasserfall\n"
COLOR(DEFAULT)  SHIFT("\x04") "Diese rastlosen Wasser dienen dem\n"
SHIFT("\x1D") "König von Hyrule. Schläft er, so\n"
SHIFT("\x36") "rasten auch sie..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Unter Wasser gibt es Frösche, die\n"
"Dich neugierig beobachten..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du stehst auf einem weichen\n"
"Teppich, den nur Darunias\n"
"Gäste betreten dürfen..."
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Nur wenn Du die " COLOR(RED) "Prüfungen" COLOR(DEFAULT) " in den\n"
"verschiedenen Räumen bestehst,\n"
"wirst Du unseren streng gehüteten\n"
"Schatz erhalten!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Bemühe Dich mit ganzer Kraft, \n"
"alle " COLOR(RED) "Schlüssel" COLOR(DEFAULT) " zu erhalten, \n"
"damit Du Dir unseren streng\n"
"gehüteten Schatz verdienst!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Du hast nur " COLOR(RED) "begrenzt Zeit" COLOR(DEFAULT) ", um\n"
"alle Gegner zu beseitigen!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sammle " COLOR(RED) "alle silbernen Steine" COLOR(DEFAULT) " ein,\n"
"die Du im Wasser finden kannst!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Überquere den " COLOR(RED) "feurigen" COLOR(DEFAULT) " " COLOR(RED) "See" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Finde den " COLOR(RED) "geheimen Durchgang" COLOR(DEFAULT) "\n"
"in diesem Raum!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Blende die " COLOR(RED) "Augen der Statue" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Der mit den " COLOR(RED) "Händen aus Silber" COLOR(DEFAULT) "\n"
"wird den großen Block verschieben\n"
"können!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Ohne die rechten Hilfsmittel\n"
"wirst Du vor unlösbaren Aufgaben\n"
"stehen!"
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sammle die " COLOR(RED) "weißen Juwelen, " COLOR(DEFAULT) "jedoch\n"
"umgehe alle Fallen und Gefahren!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x46")  COLOR(LIGHTBLUE) "Fischweiher" COLOR(DEFAULT) "\n"
SHIFT("\x26") "Heute beißen die Fische\n"
SHIFT("\x3A") "wirklich gut!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4D")  COLOR(LIGHTBLUE) "???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Schatten werden sich nur dem\n"
"offenbaren, der die " COLOR(RED) "Augen der\n"
"Wahrheit" COLOR(DEFAULT) " besitzt. Es heißt, man\n"
"könne sie in Kakariko finden..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x34")  COLOR(LIGHTBLUE) "Hylianische Steppe" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Stadt Hyrule" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x31")  COLOR(LIGHTBLUE) "Zitadelle der Zeit" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x43")  COLOR(RED) "Sackgasse" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x31")  COLOR(PURPLE) "Pfad nach Kakariko" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x31")  COLOR(PURPLE) "Kakariko Friedhof" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE)  SHIFT("\x26") "Brunnen des Grauens\n"
COLOR(DEFAULT)  SHIFT("\x19") "Düster! Tief! Unheimlich!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x46")  COLOR(RED) "Todesberg\n"
COLOR(DEFAULT)  SHIFT("\x19") "Passieren ohne Erlaubnis \n"
SHIFT("\x19") "des Königs nicht möglich!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2A")  COLOR(RED) "Pfad zum Todesberg" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(YELLOW) "Dodongos Höhle\n"
COLOR(DEFAULT)  SHIFT("\x03") "Betreten ohne Erlaubnis verboten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C")  COLOR(RED) "Goronia\n"
COLOR(DEFAULT)  SHIFT("\x33") "Stadt der Goronen" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B")  COLOR(BLUE) "Zora-Fluß\n"
COLOR(DEFAULT)  SHIFT("\x0C") "Vorsicht vor reißenden Fluten \n"
SHIFT("\x18") "und gefährlichen Strudeln!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0E") "Die Schatten werden sich nur\n"
SHIFT("\x13") "dem offenbaren, der das Auge\n"
SHIFT("\x32") "der Wahrheit besitzt." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(BLUE) "Zoras Reich" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(BLUE) "Zoras Quelle\n"
COLOR(DEFAULT)  SHIFT("\x12") "Bitte nicht den Wal wecken! \n"
SHIFT("\x3B") "König Zora XVI." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24")  COLOR(PURPLE) "Kokiri Trainingslager" COLOR(RED) "\n"
COLOR(DEFAULT)  SHIFT("\x14") "Zerstöre die Schilder nicht!\n"
SHIFT("\x48") "Lies sie!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Oh, Ihr rastlosen Abenteurer,\n"
SHIFT("\x05") "die Ihr durch die Wüste wandert,\n"
SHIFT("\x41") "besucht mich." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x2F")  COLOR(YELLOW) "Fliegender Händler" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B") "Vor Dir liegt:\n"
SHIFT("\x1E") "Der " COLOR(ADJUSTABLE) "Hain des Deku-Baumes" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4E")  COLOR(ADJUSTABLE) "Waldtempel" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(ADJUSTABLE) "Verlorene Wälder" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32") "Talons und Malons\n"
SHIFT("\x3C")  COLOR(YELLOW) "Lon Lon-Farm" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Farm des tollen Basil! \n"
SHIFT("\x46")  COLOR(YELLOW) "Basil-Farm" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4E")  COLOR(BLUE) "Hylia-See" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B")  COLOR(BLUE) "Labor am See\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Erforschung der unbekannten \n"
SHIFT("\x1B") "Tiefen des Hylia-Sees!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x46")  COLOR(YELLOW) "Gerudotal" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  COLOR(YELLOW) "Bogenschießen zu Pferde" COLOR(DEFAULT) "\n"
"Begabte Schützen sind willkommen!\n"
SHIFT("\x19") "Bestleistung: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " Punkte" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(YELLOW) "Gerudo Trainingsarena\n"
COLOR(DEFAULT)  SHIFT("\x1F") "Betreten nur registrierten\n"
SHIFT("\x30") "Mitgliedern erlaubt!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(YELLOW) "Gespensterwüste\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Vertraust Du Deinem Instinkt,\n"
SHIFT("\x14") "verschlingt Dich die Wüste.\n"
SHIFT("\x24") "Suche den wahren Pfad!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Geistertempel" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(ADJUSTABLE) "Kokiri-Laden\n"
COLOR(DEFAULT)  SHIFT("\x17") "Wir handeln mit offiziellen\n"
SHIFT("\x1E") "Deku-Baum Artikeln!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1B") "Hier wohnt " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1B")  COLOR(ADJUSTABLE) "Die Waldbewohner sollten\n"
SHIFT("\x23") "Kokiri nicht verlassen." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Der Pfad führt zum Gipfel des\n"
SHIFT("\x0C") "Berges. Dort liegt " COLOR(RED) "Goronia" COLOR(DEFAULT) ", die\n"
SHIFT("\x2D") "Stadt der Goronen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Ein Wunder der Natur:\n"
SHIFT("\x36") "Die " COLOR(RED) "Donnerblume" COLOR(DEFAULT) "!\n"
SHIFT("\x19") "Vorsicht! Nicht pflücken!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x26")  COLOR(RED) "Gipfel des Todesberges\n"
COLOR(DEFAULT)  SHIFT("\x0D") "Nur noch wenige Schritte zum\n"
SHIFT("\x19") "Krater! Achtung, extreme\n"
SHIFT("\x50") "Hitze!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2A")  COLOR(BLUE) "König Zoras Thronsaal\n"
COLOR(DEFAULT)  SHIFT("\x23") "Betritt die Plattform, um\n"
SHIFT("\x1A") "mit dem König zu sprechen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15") "Gelingt es Dir, mich mit einer\n"
SHIFT("\x0D") "Donnerblume zu stoppen, belohne\n"
SHIFT("\x0A") "ich Dich. Versuche es mehrmals!\n"
SHIFT("\x36")  COLOR(RED) "Hot Rodder Goron" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Nur der, der die Augen der \n"
SHIFT("\x0E") "Wahrheit besitzt, wird Schutz\n"
SHIFT("\x03") "vor den tödlichen Stacheln finden." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Nur der, dessen " COLOR(RED) "Schritte heilig \n"
COLOR(DEFAULT)  SHIFT("\x0E") "sind, wird das Tal des Todes" COLOR(RED) " \n"
COLOR(DEFAULT)  SHIFT("\x3E") "durchqueren." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Viele haben sich schon mit mir\n"
"gemessen. Die beste Zeit bisher:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"Boris, der Totengräber" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x43")  COLOR(LIGHTBLUE) "Schießbude\n"
"Ein Spiel kostet 20 Rubine.\n"
COLOR(DEFAULT) "Es gibt " COLOR(RED) "10 Ziele" COLOR(DEFAULT) ". Du hast " COLOR(RED) "15\n"
"Versuche" COLOR(DEFAULT) ". Nutze Deine Chance!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "10 Treffer: Überraschungspreis\n"
"8-9 Treffer: Zweite Chance\n"
"0-7 Treffer: Chance vertan" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Dies haßt der Betreiber:\n"
COLOR(DEFAULT) "Leute, die an der Theke lehnen.\n"
"Leute, die andere belästigen." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Truhenlotterie" COLOR(DEFAULT) "\n"
SHIFT("\x0F") "Den Glücklichen erwartet ein \n"
SHIFT("\x31") "wertvoller Preis..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Extrem-Klippenspringen\n"
COLOR(DEFAULT)  SHIFT("\x06") "Bist Du am Klippenspringen\n"
SHIFT("\x3C") "interessiert?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(RED) "Todeskrater" COLOR(DEFAULT) "\n"
SHIFT("\x29") "Achtung Steinhagel!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(LIGHTBLUE) "Maskenhändler!" COLOR(DEFAULT) "\n"
SHIFT("\x0F") "Wir suchen Leute, die unsere\n"
SHIFT("\x1C") "Masken weiterverkaufen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(LIGHTBLUE) "Krabbelminen-Bowling" COLOR(DEFAULT) "\n"
SHIFT("\x14") "Spaß und Heiterkeit mit den\n"
SHIFT("\x0F") "neuesten Bombentechnologien!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x50")  COLOR(LIGHTBLUE) "Basar" COLOR(DEFAULT) "\n"
SHIFT("\x03") "Unser Angebot ist bunt gemischt!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4E")  COLOR(LIGHTBLUE) "Apotheke\n"
COLOR(DEFAULT)  SHIFT("\x23") "Wir führen die besten\n"
SHIFT("\x23") "Heilmittel des Landes!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "Goronen-Laden\n"
COLOR(DEFAULT)  SHIFT("\x0D") "Ausrüstung für Bergwanderer!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x46")  COLOR(BLUE) "Zora-Laden" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Heute im Angebot: Fisch!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(LIGHTBLUE) "Grausige Grabgrusel-Tour!\n"
COLOR(DEFAULT)  SHIFT("\x07") "Von 18:00 bis 21:00 Uhr\n"
SHIFT("\x25") "Boris, der Totengräber" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(LIGHTBLUE) "Grausige Grabgrusel-Tour!\n"
COLOR(DEFAULT)  SHIFT("\x14") "Alle Touren sind " COLOR(RED) "gestrichen," COLOR(DEFAULT) "\n"
"bis ein neuer Totengräber gefunden\n"
SHIFT("\x0A") "ist. Wir bitten um Verständnis." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x40")  COLOR(PURPLE) "Stoßattacke\n"
COLOR(DEFAULT) "Um mit dem Schwert zuzustoßen,\n"
"drücke" COLOR(LIGHTBLUE) " [Control-Pad]" COLOR(DEFAULT) " in Zielrichtung und halte \n"
COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "gedrückt. Drücke dann " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F")  COLOR(PURPLE) "Enge Passagen\n"
COLOR(DEFAULT) "Versuche, durch den schmalen Spalt\n"
"zu kriechen!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Stelle Dich vor die Öffnung und\n"
"drücke den " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "in Richtung Eingang. \n"
"Zeigt das" COLOR(BLUE) " blaue Aktions-Symbol" COLOR(DEFAULT) "\n"
"\"Kriechen\" an, drücke" COLOR(BLUE) " [A]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Achte immer auf die Anzeige des" COLOR(BLUE) "\n"
"Aktions-Symbols!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13")  COLOR(PURPLE) "Trainiere Deine Schwertkunst!\n"
COLOR(DEFAULT) "Drücke " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", um Dein Schwert \n"
"horizontal" COLOR(RED) " " COLOR(DEFAULT) "zu schwingen. Hältst Du\n"
COLOR(LIGHTBLUE) "[Z], " COLOR(DEFAULT) "schwingst Du es" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "vertikal." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Schloß" COLOR(DEFAULT) " " COLOR(LIGHTBLUE) "Hyrule" COLOR(DEFAULT) "\n"
SHIFT("\x41")  COLOR(YELLOW) "Lon Lon-Farm" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Diese Richtung zur " COLOR(YELLOW) "Lon Lon-Farm" COLOR(DEFAULT) "!" COLOR(YELLOW) "\n"
COLOR(DEFAULT) "Zur Rechten liegt " COLOR(LIGHTBLUE) "Hyrule" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42") "Vor Dir liegt\n"
SHIFT("\x24")  COLOR(BLUE) "König Zoras Thronsaal\n"
COLOR(DEFAULT)  SHIFT("\x26") "Betritt ihn ehrfürchtig!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x38") "Haus von " COLOR(RED) "Mido" COLOR(DEFAULT) "\n"
SHIFT("\x2B") "Anführer der Kokiri" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Haus der Allwissenden Brüder" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D") "Haus der Zwillinge" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(RED) "Salias" COLOR(DEFAULT) " Haus" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10")  COLOR(PURPLE) "Verändern der Blickrichtung\n"
COLOR(DEFAULT) "Du hast jederzeit die Möglichkeit,\n"
"Deine Blickrichtung mit " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "zu\n"
"verändern." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Bleib stehen und verändere dann\n"
"die Richtung, in die Du schaust,\n"
"oder " COLOR(LIGHTBLUE) "halte [Z] " COLOR(DEFAULT) "während des\n"
"Laufens gedrückt." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Dies wird Dir helfen,\n"
"Dich zu orientieren!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Hältst Du [Z] gedrückt" COLOR(DEFAULT) ", kannst Du\n"
"Dich" COLOR(RED) " seitlich" COLOR(DEFAULT) " bewegen und dabei\n"
"nach vorn schauen." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Die " COLOR(RED) "seitliche Fortbewegung " COLOR(DEFAULT) "\n"
"macht sich besonders in Labyrinthen\n"
"bezahlt. Probier es aus! Du wirst \n"
"sehen, wie praktisch dies ist." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x14")  COLOR(RED) "Springe von Stein zu Stein \n"
COLOR(DEFAULT) "Du springst automatisch, sobald \n"
"Du auf einen Vorsprung oder einen\n"
"Abgrund zuläufst." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Probier es bei den Steinen aus.\n"
"Du wirst sehen, es macht Spaß!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19")  COLOR(RED) "Klippenspringen verboten!\n"
COLOR(DEFAULT)  SHIFT("\x14") "Es schadet der Gesundheit!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(PURPLE) "Zielerfassung\n"
COLOR(DEFAULT) "Siehst Du einen" COLOR(ADJUSTABLE) " ▼" COLOR(DEFAULT) " über einem \n"
"Objekt, kannst Du es mit " COLOR(LIGHTBLUE) "[Z]\n"
COLOR(DEFAULT) "anpeilen." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Vor dem Spiel kannst Du zwischen\n"
"zwei Optionen wählen:\n"
"Du mußt entweder " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " gedrückt\n"
"halten, um Dein Ziel anzupeilen..." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "...oder Du mußt kurz " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " drücken,\n"
"um Dein Ziel solange anzuvisieren,\n"
"bis Du erneut " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " betätigst. Danach\n"
"kannst Du ein neues Ziel erfassen!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Drückst Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " und dann " COLOR(BLUE) "[A]" COLOR(DEFAULT) ",\n"
"kannst Du übrigens auch mit\n"
"Personen reden, die sich außerhalb\n"
"Deiner Reichweite aufhalten." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Willst Du fliehen, bewege den " COLOR(LIGHTBLUE) "[Control-Pad]\n"
COLOR(DEFAULT) "einfach nach hinten.\n"
"Visiere zur Übung die " COLOR(RED) "Steine\n"
COLOR(DEFAULT) "hier an!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x44")  COLOR(ADJUSTABLE) "Waldbühne" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Wir warten darauf, daß Du uns\n"
"Deine häßlichste Fratze zeigst!\n"
"Einzigartige Preise zu gewinnen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Öffne jede Truhe! Du findest darin\n"
SHIFT("\x10") "wertvolle Schätze, praktische\n"
SHIFT("\x06") "Gegenstände, hilfreiche Schlüssel\n"
SHIFT("\x32") "und vieles mehr!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dies ist der " COLOR(RED) "Mythen-Stein" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Es heißt, man könne schneller\n"
"schwimmen, wenn man \n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "drückt..."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß nahe des \n"
"einsamen Baumes im Nordwesten\n"
"der Steppe ein Geheimnis\n"
"verborgen läge..."
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß der Weg\n"
"zum Hylia-See ein Geheimnis\n"
"verbärge..."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, Biggorons \n"
"Schwert wäre unzerbrechlich..."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß Medigoron \n"
"nie über seine Größe nachgedacht \n"
"habe und deshalb seinen eigenen\n"
"Laden in Schutt und Asche legte..."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß Malon den\n"
"Springparcours auf der Farm wie\n"
"keine Zweite beherrsche..."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß Malon von \n"
"einem Ritter in glänzender \n"
"Rüstung träume, der sie auf \n"
"einem Roß hinfortträgt..."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß sich\n"
"die Zora-Prinzessin Ruto in \n"
"einen blonden Jüngling verliebt \n"
"habe..."
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß die \n"
"Informationen des Mythen-\n"
"Steins nicht besonders\n"
"interessant wären..."
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß nahe des\n"
"Baumes vor Kakariko ein\n"
"Geheimnis verborgen wäre..."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß Prinzessin \n"
"Zelda trotz ihres eleganten \n"
"Äußeren ein echter Wildfang wäre... "
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß Zeldas\n"
"Kindermädchen eine Shiekah sei. \n"
"Viele dachten, dieses Geschlecht \n"
"wäre längst ausgestorben..."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß es in\n"
"Hyrule einen Mann gäbe, der\n"
"ständig am Rennen sei..."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß es verboten \n"
"wäre, die Truhen beim\n"
"Schatzkisten-Poker als Toiletten\n"
"zu mißbrauchen..."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß das Hühner- \n"
"mädchen oft zum Labor am See\n"
"ginge, um dort eine Methode zur\n"
"Zwerghuhnzucht zu erforschen..."
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß die \n"
"Gerudo-Kriegerinnen sich oft nach \n"
"Hyrule begäben, um dort nach \n"
"Männern Ausschau zu halten."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, die \n"
"Diebesprinzessin Naboru wäre\n"
"eine Gerudo-Kriegerin..."
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß einem\n"
"Gutes widerführe, wenn man in\n"
"der Nähe eines Schmetterlings\n"
"einen Deku-Stab in die Luft halte."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß man in\n"
"bereits bewältigten Labyrinthen\n"
"später neue Dinge fände..."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, die Gerudo-\n"
"Kriegerinnen würden Ganondorf \n"
"nahezu als Gott verehren..."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß sich am  \n"
"Eingang des Gerudotals ein \n"
"Geheimnis verbärge..."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß eine Eule\n"
"namens Methusa die Reinkarnation \n"
"eines Weisen wäre..."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß die Eule\n"
"zwar unheimlich aussähe, aber \n"
"einen sehr gutmütigen Charakter \n"
"habe."
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, Ganondorfs\n"
"schwarzer Hengst wäre ein Bote\n"
"aus der Hölle."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, Ganondorf \n"
"strebe die Herrschaft über\n"
"ganz Hyrule an..."
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß der Schatz,\n"
"den man in der Kampfarena der\n"
"Gerudos erringen könne, nicht\n"
"sehr wertvoll sei..."
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, es gäbe Schalter,\n"
"die man mit der Wirbelattacke\n"
"des Schwertes aktivieren könne..."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, es wären in \n"
"Hyrule genau 100 goldene\n"
"Skulltulas verborgen..."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, wer die\n"
"Verlorenen Wälder beträte, würde\n"
"zu einem Waldschrat - es sei \n"
"denn, er wäre ein Kokiri!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß die\n"
"unterirdischen Höhlen, die man an\n"
"verschiedenen Stellen findet, die\n"
"idealen Brutstätten für Käfer wären."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß ein Kokiri \n"
"stets von einer Fee begleitet \n"
"würde..."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Man erzählt sich, daß etwas\n"
"Wundersames geschähe, wenn\n"
"man während des Spiels den\n"
"Reset-Knopf drückt..."
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Was ist das denn?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das ist Gohma!\n"
COLOR(LIGHTBLUE) "Färbt sich das " COLOR(DEFAULT) "Auge" COLOR(LIGHTBLUE) " dieser\n"
"Parasiten-Kreatur rot, ist es\n"
"verletzbar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Gohma-Ei!\n"
COLOR(LIGHTBLUE) "Wenn es aufplatzt, schlüpfen\n"
"bissige Gohma-Babys aus." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Gohma-Baby!\n"
COLOR(LIGHTBLUE) "Paß auf, daß es Dich nicht\n"
"anspringt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine Skulltula!\n"
COLOR(LIGHTBLUE) "Die weiche " COLOR(DEFAULT) "Bauchseite" COLOR(LIGHTBLUE) " ist ihre\n"
"schwache Stelle!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Riesen-Skulltula!\n"
COLOR(LIGHTBLUE) "Die weiche " COLOR(DEFAULT) "Bauchseite" COLOR(LIGHTBLUE) " ist ihre\n"
"schwache Stelle!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Zangengeiferer!\n"
COLOR(LIGHTBLUE) "Triff sein verletzliches\n"
COLOR(DEFAULT) "Schwanzende" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Dekuranha!\n"
COLOR(LIGHTBLUE) "Zerschlage ihn, bevor er nach Dir\n"
"schnappt. Du erhältst eine\n"
COLOR(DEFAULT) "Deku-Nuß" COLOR(LIGHTBLUE) " oder einen " COLOR(DEFAULT) "Deku-Stab" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein großer Dekuranha!\n"
COLOR(LIGHTBLUE) "Schlage zu, bevor er nach Dir\n"
"schnappt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein verwelkter Dekuranha!\n"
COLOR(LIGHTBLUE) "Er sieht zwar ganz schön alt aus,\n"
"aber wenn Du ihm zu nahe\n"
"kommst, schnappt er zu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vorsicht, ein Laubkerl!\n"
COLOR(LIGHTBLUE) "Näherst Du Dich, verschwindet er.\n"
"Lenke die Nüsse, die er spuckt,\n"
"mit Deinem Schild auf ihn zurück!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das ist King Dodongo!\n"
COLOR(LIGHTBLUE) "Wirf dem Vielfraß etwas Explosives\n"
"in den Rachen und schlage ihn mit\n"
"Deinem " COLOR(DEFAULT) "Schwert" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Dodongo greift an!\n"
COLOR(LIGHTBLUE) "Achte auf seinen feurigen Atem!\n"
"Benutze im Kampf am besten\n"
"die Zielerfassung mit " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Baby-Dodongo!\n"
COLOR(LIGHTBLUE) "Vorsicht, er springt Dich an! Hast\n"
"Du ihn bezwungen, explodiert er!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Echsodorus! \n"
COLOR(LIGHTBLUE) "Setze Deinen Schild geschickt ein\n"
"und benutze " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) ", um Deine\n"
"Schwerthiebe exakt zu plazieren!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Dinodorus! \n"
COLOR(LIGHTBLUE) "Setze Deinen Schild geschickt ein\n"
"und benutze " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) ", um Deine\n"
"Schwerthiebe exakt zu plazieren!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Feuerflatterer!\n"
COLOR(LIGHTBLUE) "Beseitige ihn, bevor er Dich\n"
"erreicht! Wenn Du eine \n"
"Distanzwaffe hast, setze sie\n"
"ein!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Flederbeißer!\n"
COLOR(LIGHTBLUE) "Benutze " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) ", um ihn effektiv zu\n"
"treffen. Du kannst ihn auch noch\n"
"anvisieren, wenn er davonfliegt." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Armos-Ritter!\n"
COLOR(LIGHTBLUE) "Stoppe ihn und zerstöre ihn dann!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Riesenqualle Barinade!\n"
COLOR(LIGHTBLUE) "Benutze erst Deinen Bumerang, um\n"
"die Riesenqualle zu betäuben, und\n"
"schlage dann mit dem Schwert zu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Parasiten-Tentakel!\n"
COLOR(LIGHTBLUE) "Die dünne Stelle ist der schwache\n"
"Punkt. Benutze eine Distanzwaffe!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine Blubberblase greift Dich an!\n"
COLOR(LIGHTBLUE) "Diese Dinger zerplatzen wie\n"
"Seifenblasen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine Zappelqualle!\n"
COLOR(LIGHTBLUE) "Sie verteilt Stromschläge - willst\n"
"Du sie zerstören, benutze keinen\n"
"metallischen Gegenstand!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine große Zappelqualle!\n"
COLOR(LIGHTBLUE) "Sie verteilt Stromschläge - willst\n"
"Du sie zerstören, benutze keinen\n"
"metallischen Gegenstand!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Elektromanta!\n"
COLOR(LIGHTBLUE) "Zerstöre ihn, bevor er Dich\n"
"erreicht!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Phantom-Ganon greift Dich an!\n"
COLOR(LIGHTBLUE) "Das reitende Unheil des Waldtempels!\n"
"Ziele mit Pfeilen auf ihn, wenn er\n"
"aus dem Bild herauskommt!" BOX_BREAK COLOR(LIGHTBLUE) "Schlage seine magischen Feuerbälle\n"
"mit dem Schwert zurück und\n"
"attackiere ihn, wenn er am\n"
"Boden liegt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Stalfos-Ritter!\n"
COLOR(LIGHTBLUE) "Locke ihn an und schlage zu, wenn\n"
"sich eine gute Gelegenheit bietet!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine blaue Knochenfratze!\n"
COLOR(LIGHTBLUE) "Wehre ihren Angriff mit Deinem\n"
COLOR(DEFAULT) "Schild" COLOR(LIGHTBLUE) " ab!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine bleiche Knochenfratze!\n"
COLOR(LIGHTBLUE) "Greife sie an, wenn sie sich nicht\n"
"mehr bewegt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dort ist eine grüne Knochenfratze!\n"
COLOR(LIGHTBLUE) "Greife an, sowie das grüne Feuer\n"
"verschwunden ist!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vorsicht, hier sind Skullwandulas!\n"
COLOR(LIGHTBLUE) "Benutze eine Distanzwaffe, um\n"
"sie zu beseitigen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine goldene Skulltula!\n"
COLOR(LIGHTBLUE) "Diese Biester sind als \"Symbole\n"
"des Fluchs\" bekannt. Zerstöre sie,\n"
"und Du erhältst etwas!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Lavadrachoid Volvagia!\n"
COLOR(LIGHTBLUE) "Dies ist der gefürchtete Wächter\n"
"des Feuertempels. Erweckt vom \n"
"Großmeister des Bösen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Flammenderwisch!\n"
COLOR(LIGHTBLUE) "Lösche zunächst seine " COLOR(DEFAULT) "flammende\n"
"Rüstung" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Lavaschleim kriecht heran!\n"
COLOR(LIGHTBLUE) "Wenn Du das Feuer auf seinem\n"
"Rücken gelöscht hast, zerstöre ihn,\n"
"bevor er wieder entflammt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Roter Tod!\n"
COLOR(LIGHTBLUE) "Wehre seine Angriffe mit Deinem\n"
COLOR(DEFAULT) "Schild" COLOR(LIGHTBLUE) " ab!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das Wassertentakel Morpha!\n"
COLOR(LIGHTBLUE) "Dieses Monster ist Wächter des\n"
"Wassertempels. Sein eigentlicher\n"
"Körper ist der rot wabernde " COLOR(DEFAULT) "Kern" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der schwarze " NAME "\n"
COLOR(LIGHTBLUE) "Besiege Deine schwarze Seele!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vorsicht vor der Killermuschel!\n"
COLOR(LIGHTBLUE) "Ihr " COLOR(DEFAULT) "innenliegender Klappmuskel\n"
COLOR(LIGHTBLUE) "scheint der empfindliche Punkt zu\n"
"sein. Benutze eine Distanzwaffe!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Stachelstein!\n"
COLOR(LIGHTBLUE) "Ziele mit einer Distanzwaffe auf\n"
"ihn, wenn er wie ein harmloser\n"
"Stein aussieht!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das ist Bongo Bongo!\n"
COLOR(LIGHTBLUE) "Diese Schattenbestie ist aus den\n"
"Tiefen der Hölle auferstanden. \n"
"Nutze das " COLOR(DEFAULT) "Auge der Wahrheit" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Zombie!\n"
COLOR(LIGHTBLUE) "Sein Blick paralysiert Dich. Wenn\n"
"er Dich anspringt, versuche durch\n"
COLOR(DEFAULT) "einen Knopfdruck" COLOR(LIGHTBLUE) " zu flüchten!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Phantom-Ganon!\n"
COLOR(LIGHTBLUE) "Attackiere ihn, wenn er" COLOR(DEFAULT) " aus\n"
"dem Bild " COLOR(LIGHTBLUE) "reitet! Achte auf\n"
"sein Trugbild!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Wickel-Zombie!\n"
COLOR(LIGHTBLUE) "Sein Blick paralysiert Dich. Wenn\n"
"er Dich anspringt, versuche durch\n"
COLOR(DEFAULT) "einen Knopfdruck" COLOR(LIGHTBLUE) " zu flüchten!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Hirnsauger-Hände!\n"
COLOR(LIGHTBLUE) "Wenn sie Dich erwischen, versuche\n"
"mit " COLOR(DEFAULT) "einem Knopfdruck " COLOR(LIGHTBLUE) "zu flüchten!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der große Hirnsauger!\n"
COLOR(LIGHTBLUE) "Zerschlage alle seine\n"
"Diener, um ihn zu beseitigen!\n"
"Triff den Kopf!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Deckengrapscher!\n"
COLOR(LIGHTBLUE) "Du siehst seinen " COLOR(DEFAULT) "Schatten" COLOR(LIGHTBLUE) " auf dem\n"
"Boden, bevor er angreift! Zerstöre\n"
"ihn, bevor er wieder entschwindet!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein bösartiger Bodengrapscher!\n"
COLOR(LIGHTBLUE) "Sobald er sich aufteilt, zerstöre die\n"
"kleinen Grapscher, bevor sie sich\n"
"wieder vereinigen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Killaohma Koume!\n"
COLOR(LIGHTBLUE) "Ganondorfs höllische Ersatzmama,\n"
"Hexerin der Flammen! Sie scheint\n"
"durch " COLOR(DEFAULT) "Kälte" COLOR(LIGHTBLUE) " verletzbar zu sein!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die Killaohma Kotake!\n"
COLOR(LIGHTBLUE) "Ganondorfs eiskalte Ersatzmama,\n"
"Hexerin des Eises. Sie scheint\n"
"durch " COLOR(DEFAULT) "Hitze" COLOR(LIGHTBLUE) " verletzbar zu sein!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das ist ein Eisenprinz!\n"
COLOR(LIGHTBLUE) "Moment... Irgendwas stimmt nicht...\n"
"Das ist kein gewöhnlicher Gegner!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Eisenprinz!\n"
COLOR(LIGHTBLUE) "Nimm Dich vor seiner schweren\n"
"Axt in acht! Schlage zu, wenn er\n"
"seine Deckung vernachlässigt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Horror-Kid!\n"
COLOR(LIGHTBLUE) "So etwas passiert also Kids,\n"
"die nachts im Wald unterwegs \n"
"sind..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Raubschleim!\n"
COLOR(LIGHTBLUE) "Er frißt " COLOR(DEFAULT) "Rüstungen" COLOR(LIGHTBLUE) " und " COLOR(DEFAULT) "Schilde" COLOR(LIGHTBLUE) "!\n"
"Zerstöre ihn schnell, damit Du\n"
"Deine Sachen wiederbekommst!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vorsicht vor Strahlzyklopen!\n"
COLOR(LIGHTBLUE) "Achte auf den tödlichen Strahl\n"
"und benutze am besten eine\n"
COLOR(DEFAULT) "explosive Distanzwaffe" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der Feuerfuchs Anubis!\n"
COLOR(LIGHTBLUE) "Dieser Gegner ist besonders\n"
"anfällig für " COLOR(RED) "Feuer" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Eisatmer!\n"
COLOR(LIGHTBLUE) "Achte auf seinen eisigen Atem und\n"
"zerschlage seine eisige Hülle so\n"
"schnell wie möglich!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf, Großmeister des Bösen!\n"
COLOR(LIGHTBLUE) "Ich habe keine Ahnung, wo sein\n"
"schwacher Punkt liegt..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon!\n"
COLOR(LIGHTBLUE) "Ich habe keine Ahnung, wo sein\n"
"schwacher Punkt liegt..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Horror-Kid!\n"
COLOR(LIGHTBLUE) "Das passiert also Kids, die\n"
"sich im Wald verlaufen? Könnten\n"
"wir uns wohl mit ihm anfreunden?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Horror-Kid!\n"
COLOR(LIGHTBLUE) "Das passiert also Kids, die sich\n"
"im Wald verlaufen? Sieht\n"
"traurig aus ohne sein Gesicht..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Horror-Kid!\n"
COLOR(LIGHTBLUE) "Das passiert also Kids, die sich im\n"
"Wald verlaufen. Sieht mit dem\n"
"Totenschädel ganz zufrieden aus..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Oktorok!\n"
COLOR(LIGHTBLUE) "Schlage die Steine, die er spuckt,\n"
"mit Deinem Schild zurück!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Irrlicht auf dem Friedhof!\n"
COLOR(LIGHTBLUE) "Starre es lange genug mit " COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "an,\n"
"dann wird es wohl verschwinden..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Irrlicht!\n"
COLOR(LIGHTBLUE) "Starre es lange genug mit " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) " an,\n"
"dann wird es wohl verschwinden..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein roter Arachno!\n"
COLOR(LIGHTBLUE) "Erfasse ihn mit " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) ", wenn er\n"
"springt, und schlage mit dem\n"
"Schwert zu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein blauer Arachno!\n"
COLOR(LIGHTBLUE) "Im Wasser hast Du kaum eine\n"
"Chance, ihn zu erwischen. Locke\n"
"ihn an Land!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Widerliche Sandkiller!\n"
COLOR(LIGHTBLUE) "Achte darauf, wo sie auftauchen\n"
"und weiche ihnen geschickt aus!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine riesige Killeranas!\n"
COLOR(LIGHTBLUE) "Versuche, ihre " COLOR(DEFAULT) "Wurzel" COLOR(LIGHTBLUE) " zu\n"
"erwischen - das ist ihre\n"
"schwache Stelle!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine Larve der Killeranas!\n"
COLOR(LIGHTBLUE) "Verteidige Dich mit Deinem " COLOR(DEFAULT) "Schild" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein bissiger Wolfsheimer!\n"
COLOR(LIGHTBLUE) "Laß ihn herankommen, achte auf\n"
"seine Bewegungen und schlage\n"
"ihn, wenn er unvorsichtig wird..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein verrückter Laubkerl!\n"
COLOR(LIGHTBLUE) "Kommst Du zu nahe, verschwindet\n"
"er im Laub. Setze Deine\n"
"Ausrüstung sinnvoll ein!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein reicher Laubkerl!\n"
COLOR(LIGHTBLUE) "Kommst Du zu nahe, verschwindet\n"
"er im Laub. Aber bist Du geschickt,\n"
"hat er etwas für Dich..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Das ist der Geist von Boris!\n"
COLOR(LIGHTBLUE) "Der Geist des Totengräbers!\n"
"Gewinnst Du den Wettlauf mit ihm,\n"
"hat er vielleicht ein " COLOR(DEFAULT) "Andenken" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Betti - eine der Irrlicht-Schwestern!\n"
COLOR(LIGHTBLUE) "Wenn sie sich aufteilt, mußt Du\n"
"herausfinden, welche die " COLOR(DEFAULT) "Echte" COLOR(LIGHTBLUE) " ist!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hetti - eine der Irrlicht-Schwestern!\n"
COLOR(LIGHTBLUE) "Ziele auf sie, sobald sie erscheint!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Netti - eine der Irrlicht-Schwestern!\n"
COLOR(LIGHTBLUE) "Ziele auf sie, sobald sie erscheint!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Etti - eine der Irrlicht-Schwestern!\n"
COLOR(LIGHTBLUE) "Ziele auf sie, sobald sie erscheint!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine Gerudo-Kriegerin!\n"
COLOR(LIGHTBLUE) "Attackiere sie, sowie sie ihre\n"
"Deckung vernachlässigt und hüte\n"
"Dich vor ihrer Spezialattacke!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Knochengänger!\n"
COLOR(LIGHTBLUE) "Laß Dir von ihm keine Angst\n"
"einjagen, schwinge einfach Dein\n"
"Schwert!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Polarflatterer!\n"
COLOR(LIGHTBLUE) "Zerstöre diese eiskalten Widerlinge,\n"
"bevor sie Dich einfrieren können!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein weißer Wolfsheimer!\n"
COLOR(LIGHTBLUE) "Laß ihn herankommen, achte auf\n"
"seine Bewegungen und schlage\n"
"ihn, wenn er unvorsichtig wird..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eine schwarze Wüstenkrähe!\n"
COLOR(LIGHTBLUE) "Zerstöre diese krächzenden\n"
"Widerlinge, bevor sie auf Dich\n"
"einhacken können!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hier wartet ein Grozokto!\n"
COLOR(LIGHTBLUE) "Gib ihm mit dem Bumerang eins\n"
"auf die Nase und attackiere sein\n"
"Hinterteil!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Nachtschwärmer!\n"
COLOR(LIGHTBLUE) "Dieser Geist ist hartnäckig und\n"
"sehr schnell!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Die... Killaohma?!\n"
COLOR(LIGHTBLUE) "Die vereinigten und attraktiv\n"
"verjüngten Kotake und Koume!\n"
"Wirf die " COLOR(DEFAULT) "Magie-Attacken" COLOR(LIGHTBLUE) " zurück!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ein Irrlicht!\n"
COLOR(LIGHTBLUE) "Dieses Irrlicht flüchtet nicht,\n"
"wenn Du versuchst, es mit " COLOR(DEFAULT) "[Z]" COLOR(LIGHTBLUE) "\n"
"anzustarren. Ganz im Gegenteil..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x38") "Spiele die Melodien\n"
SHIFT("\x3B") "mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " und " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29") "Spiele mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " und " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
SHIFT("\x1B") "Drücke" COLOR(ADJUSTABLE) " [B]" COLOR(DEFAULT) ", um zu beenden.\n"
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
QUICKTEXT_ENABLE "Spiele das " COLOR(ADJUSTABLE) "Menuett des Waldes" COLOR(DEFAULT) "." COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT)  QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele den " COLOR(RED) "Bolero des Feuers" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele die " COLOR(BLUE) "Serenade des Wassers" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele das " COLOR(YELLOW) "Requiem der Geister" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele die " COLOR(PURPLE) "Nocturne des Schattens" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele die " COLOR(LIGHTBLUE) "Kantate des Lichts" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele geschwind " COLOR(ADJUSTABLE) "Salias Lied" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Okay? Hier ist " COLOR(RED) "Eponas Lied" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Präge Dir " COLOR(BLUE) "Zeldas Wiegenlied" COLOR(DEFAULT) " ein...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele die " COLOR(YELLOW) "Hymne der Sonne" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Dies Lied" COLOR(DEFAULT) " öffnet das Zeitportal...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Nie werde ich " COLOR(PURPLE) "dies Lied" COLOR(DEFAULT) " vergessen!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spiele mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " und " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ";\n"
COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " zum Beenden.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x13")  COLOR(RED) "Hier kannst Du nicht warpen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Zu den Verlorenen Wäldern!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Zum Todeskrater!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(BLUE) "Zum Hylia-See!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Zum Wüstenkoloss!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Zum Friedhof!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Zur Zitadelle der Zeit!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Menuett des Waldes " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bolero des Feuers " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "Serenade des Wassers " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Requiem der Geister " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Nocturne des Schattens " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Kantate des Lichts " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Salias Lied " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Eponas Lied " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "Zeldas Wiegenlied" COLOR(DEFAULT) " gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Hymne der Sonne" COLOR(DEFAULT) " gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Hymne der Zeit " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Hymne des" COLOR(DEFAULT) " " COLOR(PURPLE) "Sturms " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Vogelscheuchen-Polka " COLOR(DEFAULT) "gespielt!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Na endlich bist Du aufgewacht.\n"
"Ich bin " COLOR(RED) "Navi" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Der Deku-Baum bat mich, Dich\n"
"ab jetzt zu " COLOR(RED) "begleiten" COLOR(LIGHTBLUE) ".\n"
"Schön, Dich kennenzulernen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x10") "Guten Morgen, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey! Eine Fee!" BOX_BREAK UNSKIPPABLE "Endlich hast Du auch eine Fee,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich werde hier auf Dich warten.\n"
"Geh nun, denn der Deku-Baum\n"
"hat Dich gerufen!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mit" COLOR(BLUE) " [A] " COLOR(DEFAULT) "kannst Du Dinge heben!" BOX_BREAK "Dieser arrogante" COLOR(RED) " Mido" COLOR(DEFAULT) "... Er will,\n"
"daß die Steine hier verschwinden.\n"
"Und jetzt soll ich für ihn die\n"
"Arbeit machen!"
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, Du besitzt endlich eine " COLOR(LIGHTBLUE) "Fee" COLOR(DEFAULT) "?!\n"
"Das ist cool, " NAME "!" BOX_BREAK UNSKIPPABLE "Was?" BOX_BREAK UNSKIPPABLE "Der " COLOR(RED) "Deku-Baum" COLOR(DEFAULT) " hat Dich zu sich\n"
"gerufen? Das ist eine große Ehre!" BOX_BREAK UNSKIPPABLE "Es kommt selten vor, daß der\n"
"Deku-Baum jemanden zu sich ruft." BOX_BREAK UNSKIPPABLE "Er ist der Hüter der Wälder und\n"
"hat uns Kokiri erschaffen!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich frage mich, ob der " COLOR(RED) "Deku-Baum " COLOR(DEFAULT) "\n"
"der Schöpfer allen Lebens ist..."
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laß uns an Deinen Kampftechniken\n"
"arbeiten!" BOX_BREAK "Hältst Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " gedrückt und\n"
"läufst dabei nach rechts oder\n"
"links, kannst Du mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " " COLOR(RED) "Sprünge\n"
"zur Seite " COLOR(DEFAULT) "ausführen." BOX_BREAK "Hältst Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " gedrückt und läufst\n"
"rückwärts, kannst Du mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) "\n"
"einen " COLOR(RED) "Rückwärtssalto" COLOR(DEFAULT) " ausführen." BOX_BREAK "Eine " COLOR(RED) "Rollattacke" COLOR(DEFAULT) " führst Du aus,\n"
"indem Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " gedrückt hältst und\n"
"dann " COLOR(BLUE) "[A]" COLOR(DEFAULT) " betätigst. Während der\n"
"Attacke bist Du nicht verwundbar." BOX_BREAK "Hast Du Dein Schwert in der\n"
"Hand und hältst " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " gedrückt, \n"
"kannst Du mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " eine effektive\n"
COLOR(RED) "Sprungattacke" COLOR(DEFAULT) " ausführen." BOX_BREAK "Die" COLOR(LIGHTBLUE) " Zielerfassung mit [Z]" COLOR(DEFAULT) "\n"
"kannst Du an diesem " COLOR(RED) "Stein" COLOR(DEFAULT) " \n"
"ausprobieren!"
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast nicht die Erlaubnis, das\n"
"Dorf zu verlassen!" TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der Deku-Baum sprach, daß jeder\n"
"Kokiri, der das Dorf verläßt, \n"
"zum Sterben verdammt ist!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Dieser großmäulige" COLOR(RED) " Mido" COLOR(DEFAULT) "!\n"
"Ich muß für ihn das Unkraut vor\n"
"Salias Haus entfernen." BOX_BREAK UNSKIPPABLE "Er hat Salia erzählt, daß ER das\n"
"für sie erledigen würde. Und nun\n"
"muß ich es tun!" TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Salia" COLOR(DEFAULT) " und Du, Ihr seid doch gute\n"
"Freunde. Hilfst Du mir bei meiner \n"
"Arbeit?" BOX_BREAK "Du darfst auch alles behalten, was \n"
"Du findest."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Gut gemacht! Dies war mit Hilfe\n"
"Deiner " COLOR(LIGHTBLUE) "Fee" COLOR(DEFAULT) " möglich!" BOX_BREAK UNSKIPPABLE "Wie schön, daß auch Du endlich\n"
"eine ständige Begleiterin hast!" BOX_BREAK UNSKIPPABLE "Ich werde Dich lehren, ihre\n"
"Kräfte richtig zu nutzen!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Fliegt Deine Fee zu einem Objekt  \n"
"oder einer Person, drücke " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", um \n"
COLOR(RED) "dorthin zu schauen" COLOR(DEFAULT) "." BOX_BREAK "Drückst Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " und dann " COLOR(BLUE) "[A]" COLOR(DEFAULT) ",\n"
"kannst Du mit weiter entfernten\n"
"Personen sprechen." BOX_BREAK "Wenn Du kein Ziel erfaßt,\n"
"kannst Du " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " nutzen, um\n"
COLOR(RED) "geradeaus" COLOR(DEFAULT) " " COLOR(RED) "zu schauen" COLOR(DEFAULT) ".\n"
"Versuch es!"
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, Du besitzt endlich eine " COLOR(LIGHTBLUE) "Fee" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Nun gibt es viel zu lernen!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Wow! " QUICKTEXT_ENABLE "Das ist cool!" QUICKTEXT_DISABLE "\n"
"Ich freue mich für Dich!" BOX_BREAK UNSKIPPABLE "Nun bist Du ein wahrer Kokiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ist es wirklich wahr? \n"
"Der Deku-Baum möchte, daß Du\n"
"zu ihm kommst?" BOX_BREAK UNSKIPPABLE "Es ist eine große Ehre, vor den\n"
"Deku-Baum treten zu dürfen!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, Du verläßt uns?"
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sicher hast Du Deine Gründe.\n"
"Versprich mir, daß wir immer \n"
"Freunde bleiben, ja?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich möchte, daß Du meine\n"
"Okarina an Dich nimmst."
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sie bedeutet mir sehr viel...\n"
"Wann immer Du sie spielst, sollst\n"
"Du an mich denken..."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh... Navi...\n"
"Du hast Deinen Auftrag\n"
"also erfüllt!" BOX_BREAK UNSKIPPABLE "Sei willkommen, " NAME "!" BOX_BREAK UNSKIPPABLE "Höre nun die Worte, die ich,\n"
"der" COLOR(RED) " Deku-Baum" COLOR(DEFAULT) ", Dir zu sagen habe." BOX_BREAK UNSKIPPABLE "Die vergangenen Nächte müssen\n"
"für Dich ruhelos und von finsteren\n"
"Träumen geprägt gewesen sein." BOX_BREAK UNSKIPPABLE "In diesen Tagen, da die Diener\n"
"des Bösen zu neuer Stärke\n"
"gelangen, werden die Auserwählten\n"
"von Alpträumen geplagt." BOX_BREAK UNSKIPPABLE "Dies ist auch Dir widerfahren!" BOX_BREAK UNSKIPPABLE  NAME "... \n"
"Nun ist die Zeit gekommen, da es\n"
"gilt, Deinen Mut zu prüfen!" TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ein " COLOR(RED) "Fluch" COLOR(DEFAULT) " lastet auf mir!\n"
"Deine Jugend und Kraft sollen mir\n"
"helfen, den Fluch zu brechen." BOX_BREAK "Hast Du den Mut, diese Prüfung\n"
"auf Dich zu nehmen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "So sei es! Tritt ein, tapferer \n"
NAME ", und auch Du, \n"
"Navi." BOX_BREAK UNSKIPPABLE "Navi, holde Fee...  \n"
"Unterstütze " NAME "!" BOX_BREAK UNSKIPPABLE "Und Du " NAME ", höre mit\n"
COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " " COLOR(LIGHTBLUE) "Navis" COLOR(DEFAULT) " Worte, denn es\n"
"sind Worte der Weisheit."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Womöglich fehlt Dir das Vertrauen \n"
"in Deine eigenen Fähigkeiten.\n"
"Kehre in den Kokiri-Wald zurück\n"
"und übe Deine Kampfeskunst!" BOX_BREAK "Fühlst Du, daß Deine Zeit \n"
"gekommen ist, tritt mir erneut \n"
"gegenüber und drücke" COLOR(LIGHTBLUE) " [Z]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der beste Ort, um zu lernen,\n"
"Fähigkeiten richtig einzusetzen,\n"
"ist das " COLOR(ADJUSTABLE) "Kokiri Trainingslager\n"
COLOR(DEFAULT) "hier auf dem Hügel."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Vergebung, Herr!" QUICKTEXT_DISABLE "\n"
"Läßt Du mich gehen, wenn ich\n"
"Dir ein Geheimnis anvertraue?" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Springst Du aus großer\n"
"Höhe und drückst bei der Landung\n"
"den " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "nach vorn, rollst Du Dich\n"
"ab und linderst so den Aufprall." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Allerdings kann ich nicht\n"
"wirklich garantieren, daß dies\n"
"bei jeder Absprunghöhe klappt..." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Probier es einfach aus, wenn\n"
"Du Mut hast!\n"
QUICKTEXT_ENABLE "Ich verschwinde!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey!\n"
"Du da, unter der Maske. Bist Du\n"
"nicht der junge Kokiri?"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eine coole Maske hast Du da, echt\n"
"groovy! Mit dem Teil würde ich\n"
"sicher einige Leute schocken." BOX_BREAK "Hey, gibst Du mir die Maske?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Blöd, ich hätte sie gerne gehabt..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cool! Ich werde sie immer tragen!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Er hat Dir nur " COLOR(RED) "10 Rubine" COLOR(DEFAULT) " \n"
"für die 20 Rubine teure Maske\n"
"gegeben!\n"
"Ein schlechtes Geschäft!" BOX_BREAK UNSKIPPABLE "Geh zurück zum Maskenhändler \n"
"und gib ihm seine " COLOR(RED) "20 Rubine" COLOR(DEFAULT) ".\n"
"Den Verlust mußt Du aus Deiner \n"
"eigenen Tasche bezahlen."
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin ein Zombie! Du mußt\n"
"schreiend davonlaufen!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hier? Ich dachte, Du hättest \n"
"den Wald verlassen..."
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wußtest Du, daß Du Dich mit dem \n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "abrollen kannst, wenn Du aus\n"
"großer Höhe herabspringst?\n"
"Das lindert Deinen Aufprall." BOX_BREAK "Ist es allerdings zu hoch, wirst\n"
"Du dennoch Schaden nehmen..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salia sagte, sie erwarte Dich\n"
"am üblichen Ort."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hab Dank, " NAME "!"
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, eine prächtige Feen-Schleuder\n"
"hast Du da..." BOX_BREAK "Hältst Du " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "gedrückt, kannst Du\n"
"mit ihr zielen. Läßt Du den Knopf\n"
"los, schießt Du einen Deku-Kern." COLOR(YELLOW) "." COLOR(DEFAULT) "\n"
"Bist Du ein guter Schütze?" BOX_BREAK "Hältst Du die Schleuder in der\n"
"Hand und drückst " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", kannst Du" COLOR(LIGHTBLUE) " \n"
COLOR(DEFAULT) "sogar schießen, " COLOR(RED) "während Du Dich\n"
"bewegst" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du mußt, " NAME "!\n"
"Mir bleibt nur wenig Zeit!"
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Höre, was ich zu sagen habe.\n"
"Ein " COLOR(RED) "Diener des Bösen, der aus der \n"
"Wüste kam" COLOR(DEFAULT) ", hat mich verflucht!"
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Falls Du Salia suchst: Sie ist in \n"
"den " COLOR(ADJUSTABLE) "Verlorenen Wäldern" COLOR(DEFAULT) "." BOX_BREAK "Der Eingang? Der ist irgendwo\n"
"hier im Dorf!" BOX_BREAK "Sicher wird einer wie Du sich im\n"
"Wald verlaufen. Da nützt Dir auch\n"
"Deine Fee nichts!" BOX_BREAK SHIFT("\x24")  QUICKTEXT_ENABLE "Und jetzt verschwinde!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Niemals darf es dem Teufel \n"
"aus der Wüste gelingen, die\n"
"Macht des Triforce zu erringen." BOX_BREAK UNSKIPPABLE "Nie darf der, der Böses in\n"
"seinem Herzen trägt, das \n"
"Heilige Reich betreten!" BOX_BREAK UNSKIPPABLE "Der Dämon, der den Fluch auf \n"
"mich legte und mir die Kraft\n"
"raubte!" BOX_BREAK UNSKIPPABLE "Mein Ende naht, das Böse nagt\n"
"an meinen Wurzeln..." BOX_BREAK UNSKIPPABLE "Obwohl Du den Fluch gebrochen\n"
"hast, kommt Deine Hilfe zu spät...\n"
"Ich bin zum Sterben verdammt." BOX_BREAK UNSKIPPABLE "Meine Zeit ist vorüber...\n"
UNSKIPPABLE "Doch trauere nicht um mich!" BOX_BREAK UNSKIPPABLE "Mein Auftrag war, Dich einzuweihen \n"
"in die Geschehnisse um Hyrule..." BOX_BREAK UNSKIPPABLE "Du bist des Landes letzte \n"
"Hoffnung!"
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die Zukunft liegt in Deinen \n"
"Händen, " NAME "...\n"
"Ich weiß, Du hast die Kraft..." BOX_BREAK UNSKIPPABLE "Navi...\n"
"Hilf " NAME ", meinen letzten \n"
"Willen zu verwirklichen..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Ich ersuche Dich... Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "So... lebt... denn... wohl..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Du hast die Worte des \n"
"Deku-Baumes gehört! Nur Du kannst\n"
"Hyrule retten! Laß uns also zum\n"
"Schloß aufbrechen, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Leb wohl... " COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "weiser Deku-Baum..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wie schade..."
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Spielst Du mit uns?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey Du " COLOR(LIGHTBLUE) "feenloser Versager" COLOR(DEFAULT) "!\n"
"Was hast Du mit dem Deku-Baum\n"
"zu bereden?" BOX_BREAK UNSKIPPABLE "Ohne Fee bist Du nicht mal\n"
"ein richtiger Mann!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Du passieren willst, solltest\n"
"Du wenigstens mit einem " COLOR(ADJUSTABLE) "Schwert \n"
COLOR(DEFAULT) "und einem " COLOR(LIGHTBLUE) "Schild " COLOR(DEFAULT) "ausgerüstet sein!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Verschwinde!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x57")  QUICKTEXT_ENABLE "Was?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "läßt Dich nicht zum \n"
"Deku-Baum?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das " COLOR(ADJUSTABLE) "Schwert" COLOR(DEFAULT) " ist irgendwo\n"
"verborgen, sagt man. Es ist das\n"
"einzige Schwert in Kokiri! Den\n"
COLOR(LIGHTBLUE) "Schild" COLOR(DEFAULT) " kannst Du im Laden kaufen."
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bevor Du zum Deku-Baum darfst, \n"
"mußt Du Dich zunächst mit einem\n"
COLOR(ADJUSTABLE) "Schwert" COLOR(DEFAULT) " und einem " COLOR(LIGHTBLUE) "Schild" COLOR(DEFAULT) " \n"
"ausrüsten!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich werde Dich niemals als einen \n"
"der Unseren akzeptieren!" BOX_BREAK "Wie nur kann es sein, daß erst\n"
"Salia und nun auch der Deku-Baum\n"
"so viel Vertrauen zu Dir haben? \n"
"Grummel... Grummel..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich kann Dir erklären, was die\n"
"Bildschirm-Symbole bedeuten.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Die gelben Symbole\n"
"Das blaue Symbol" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die drei gelben Symbole am \n"
"rechten oberen Bildrand sind die \n"
COLOR(YELLOW) "Gegenstands-Symbole" COLOR(DEFAULT) "." BOX_BREAK "Sie zeigen Dir die Gegenstände an,\n"
"die Du mit " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "und" COLOR(YELLOW) " [C-Right] \n"
COLOR(DEFAULT) "einsetzen kannst." BOX_BREAK "Hast Du einen " COLOR(YELLOW) "[C]-Gegenstand" COLOR(DEFAULT) " \n"
"erhalten, begib Dich ins \n"
COLOR(YELLOW) "Gegenstands-Menü " COLOR(DEFAULT) "und plaziere \n"
"ihn auf einem der " COLOR(YELLOW) "[C]-Knöpfe" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das blaue Symbol ist das " COLOR(BLUE) "Aktions-\n"
"Symbol" COLOR(DEFAULT) "." BOX_BREAK "Dieses Symbol gibt an, welche \n"
"Aktion Du ausführst, wenn Du\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "betätigst." BOX_BREAK "An bestimmten Stellen hast Du die\n"
"Möglichkeit, verschiedene Aktionen\n"
"auszuführen."
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du etwas über die " COLOR(RED) "Karte" COLOR(DEFAULT) "\n"
"oder die" COLOR(RED) " Gegenstände " COLOR(DEFAULT) "erfahren\n"
"möchtest, kann ich Dir \n"
"weiterhelfen." BOX_BREAK "Was interessiert Dich?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Karte\n"
"Gegenstände\n"
"Zurück" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ein " COLOR(RED) "Kartenausschnitt" COLOR(DEFAULT) " wird am\n"
"rechten unteren Bildrand angezeigt." BOX_BREAK "Der " COLOR(YELLOW) "gelbe Pfeil" COLOR(DEFAULT) " zeigt Deine\n"
"derzeitige Position und\n"
"Deine Blickrichtung. Der " COLOR(RED) "rote\n"
"Pfeil" COLOR(DEFAULT) " symbolisiert den Eingang." BOX_BREAK "Mit " COLOR(LIGHTBLUE) "[L] " COLOR(DEFAULT) "kannst Du die Anzeige\n"
"ein- und ausblenden." BOX_BREAK "Drückst Du " COLOR(RED) "START, " COLOR(DEFAULT) "kannst Du\n"
"Deinen derzeitigen Aufenthaltsort\n"
"feststellen." BOX_BREAK "Neben anderen Menüs findest Du\n"
"hier den " COLOR(RED) "Karten-Bildschirm" COLOR(DEFAULT) "." BOX_BREAK "Dieser zeigt Dir eine Karte des\n"
"Landes Hyrule oder des Labyrinths,\n"
"in dem Du Dich gerade befindest."
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Es gibt drei Arten von Gegenständen:\n"
COLOR(BLUE) "Ausrüstungs-" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C]-Knopf- " COLOR(DEFAULT) "und" COLOR(YELLOW) " \n"
COLOR(LIGHTBLUE) "Missions-Gegenstände" COLOR(DEFAULT) "." BOX_BREAK COLOR(BLUE) "Ausrüstungs-Gegenstände" COLOR(DEFAULT) " sind \n"
"Dinge wie Schwert, Schild oder \n"
"Rüstung. Wähle sie mit dem Cursor\n"
"aus und bestätige mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK COLOR(YELLOW) "[C]-Knopf-Gegenstände " COLOR(DEFAULT) "kannst Du \n"
"auf die Knöpfe " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " oder " COLOR(YELLOW) "[C-Right]\n"
COLOR(DEFAULT) "legen und sie durch diese auch\n"
"einsetzen." BOX_BREAK COLOR(LIGHTBLUE) "Missions-Gegenstände " COLOR(DEFAULT) "sammelst Du \n"
"während Deines Abenteuers. Du\n"
"mußt sie nicht speziell auswählen,\n"
"damit Du sie nutzen kannst." BOX_BREAK "Willst Du Deine Ausrüstung\n"
"verändern oder auch nur Dein \n"
"Inventar begutachten, drücke\n"
COLOR(RED) "START" COLOR(DEFAULT) "." BOX_BREAK "Mit " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " oder " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "kannst Du" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "zwischen den verschiedenen\n"
"Menüs hin- und herwechseln." BOX_BREAK "Mit Cursor und " COLOR(BLUE) "[A] " COLOR(DEFAULT) "wählst Du einen \n"
COLOR(BLUE) "Ausrüstungs-Gegenstand" COLOR(DEFAULT) ", mit " COLOR(YELLOW) "[C-Left],\n"
"[C-Down] " COLOR(DEFAULT) "oder" COLOR(YELLOW) " [C-Right] " COLOR(DEFAULT) "wählst Du einen \n"
COLOR(YELLOW) "[C]-Knopf-Gegenstand" COLOR(DEFAULT) "." BOX_BREAK "Das waren eine Menge\n"
"Erklärungen, nicht wahr?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Willst Du Deinen Spielstand \n"
COLOR(ADJUSTABLE) "sichern" COLOR(DEFAULT) ", drücke " COLOR(RED) "START" COLOR(DEFAULT) ", um zu\n"
"den Menüs zu gelangen und dann\n"
COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", um zu sichern."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meine Schwester hat einige \n"
"Rubine genommen und ist zum\n"
"Kokiri-Laden gegangen, um\n"
"dort einzukaufen!" BOX_BREAK "Apropos " COLOR(RED) "Rubine" COLOR(DEFAULT) ": Je größer Deine\n"
"Börse ist, desto mehr Rubine\n"
"kannst Du tragen..."
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Manche Dinge in diesem Laden\n"
"findest Du auch im Wald. Den\n"
"Deku-Schild jedoch nicht! Ihn mußt\n"
"Du kaufen!" BOX_BREAK "Weißt Du, wie man den " COLOR(RED) "Deku-\n"
"Schild " COLOR(DEFAULT) "richtig einsetzt?" BOX_BREAK "Hast Du den Schild erhalten,\n"
"drücke" COLOR(RED) " START" COLOR(DEFAULT) ", um zu den Menüs\n"
"zu gelangen. Begib Dich nun \n"
"zum " COLOR(BLUE) "Ausrüstungs-Menü" COLOR(DEFAULT) "." BOX_BREAK "Hier wählst Du mit dem Cursor \n"
"den Schild, mit dem Du Dich\n"
"ausrüsten willst, und drückst" COLOR(BLUE) " [A]" COLOR(DEFAULT) "," COLOR(BLUE) "\n"
COLOR(DEFAULT) "um Deine Wahl zu bestätigen." BOX_BREAK "Ist der Schild gewählt, kannst Du\n"
"ihn mit " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "einsetzen und mit " COLOR(LIGHTBLUE) "[Control-Pad]\n"
COLOR(DEFAULT) "seinen Winkel verändern."
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Willst Du wissen, wie man " COLOR(YELLOW) "[C-Up] \n"
COLOR(DEFAULT) "verwendet?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Drückst Du " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", kannst Du die\n"
"Kameraperspektive verändern." BOX_BREAK "In geschlossenen Räumen wie \n"
"diesem wechselst Du zur Vogel-\n"
"perspektive, unter freiem Himmel\n"
"zur Ego-Perspektive." BOX_BREAK "Ist " COLOR(YELLOW) "Navi" COLOR(DEFAULT) " dort zu lesen, will Dir\n"
"Deine Fee etwas mitteilen.\n"
"Ihre Botschaft kannst Du \n"
"dann mit " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " abrufen."
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Na gut, dann finde es selbst \n"
"heraus!"
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das klingt nicht wie Salias Lied..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "ist sehr aufgebracht!\n"
"Ich frage mich, was er hat?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was?! Wo gehst Du hin?" BOX_BREAK "Zum Schloß?\n"
"Wo liegt das Schloß?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kokiri, die das Dorf verlassen,\n"
"sind zum Sterben verdammt!" BOX_BREAK "Du hast doch nicht etwa vor,\n"
"es auszuprobieren?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, " NAME "!\n"
"Was hast Du getan?!" BOX_BREAK UNSKIPPABLE "Der Deku-Baum...\n"
"Ist er... tot?" BOX_BREAK UNSKIPPABLE "Wie konntest Du das nur tun?! \n"
"Es ist alles Deine Schuld!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der Deku-Baum ist tot... Ist damit\n"
"auch unser Ende nah?"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hallo " NAME "!" TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir werden doch immer Freunde\n"
"bleiben, oder nicht?"
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ist etwas mit dem Deku-Baum \n"
"geschehen?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mir scheint, es ist kühler\n"
"geworden im Wald..."
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", hast Du vor, uns\n"
"zu verlassen?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kommst Du wieder, wenn Du einen\n"
"neuen Schild brauchst?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x80") "Meine Brüder und ich sind uns\n"
"einig... Du siehst genauso aus \n"
"wie unser Heiliger Totem!" BOX_BREAK SFX("\x38\x80") "Nimm diese " COLOR(RED) "Deku-Stäbe" COLOR(DEFAULT) " als\n"
"Zeichen unserer Ehrfurcht.\n"
"Zudem werden wir dafür sorgen,\n"
"daß Du nun mehr tragen kannst!" BOX_BREAK "Hobrobbel... Kadobbel..." BOX_BREAK SFX("\x38\x80") "Kazabbarobbel!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seit der Deku-Baum uns nicht \n"
"mehr beschützt, treiben sich\n"
"unheimliche Kreaturen in den\n"
"Wäldern herum! Ich habe Angst..."
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ein kalter, dämonischer Wind \n"
"weht aus der Richtung des \n"
"Waldtempels." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Salia" COLOR(DEFAULT) " ist fort. Sie sagte, sie \n"
"wolle etwas dagegen unternehmen!" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der " COLOR(ADJUSTABLE) "Waldtempel " COLOR(DEFAULT) "befindet sich bei \n"
"der Heiligen Lichtung, tief in\n"
"den Verlorenen Wäldern."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salia ging zum Waldtempel und\n"
"kam bisher nicht zurück..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sie können mit Sicherheit keinen\n"
"Deku-Schild mehr benutzen, dafür\n"
"sind Sie zu alt!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wo Salia ist? \n"
"Sie kennen Salia?\n"
"Das ist merkwürdig..." TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Mido" COLOR(DEFAULT) " ist seit einiger Zeit\n"
"verschwunden... Wo er wohl \n"
"steckt?"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sie haben mit Sicherheit keine \n"
"Probleme, den Tempel zu betreten,\n"
"mein Herr!" BOX_BREAK "Wurden Sie von den Kreaturen\n"
"belästigt? Als der Deku-Baum uns \n"
"noch beschützte, haben sich keine\n"
"Dämonen hier herumgetrieben..." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Weil es draußen so gefährlich \n"
"ist, habe ich das Haus nicht mehr \n"
"verlassen. Nun langweile ich mich\n"
"hier zu Tode..."
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Sie einen " COLOR(RED) "Bogen" COLOR(DEFAULT) " besitzen, \n"
"können Sie im Laden " COLOR(RED) "Pfeile" COLOR(DEFAULT) " kaufen. \n"
"Haben Sie einen Bogen?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sie scheinen viel in der Welt\n"
"herumgekommen zu sein...\n"
"Haben Sie jemals einen Jungen \n"
"namens " NAME " getroffen?" BOX_BREAK UNSKIPPABLE "Mido behauptete damals, daß \n"
"dieser Junge Schuld am Tod des\n"
"Deku-Baumes hatte..." BOX_BREAK UNSKIPPABLE "Nur Salia hat " NAME " \n"
"immer verteidigt..." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vielleicht hatte Mido Unrecht..."
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Irgendwie kommen Sie mir bekannt\n"
"vor, mein Herr!"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Kennen Sie einen Jungen namens \n"
NAME "?" BOX_BREAK UNSKIPPABLE "Er hat den Wald verlassen und \n"
"kehrte nie zurück..." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich frage mich, ob " NAME "  \n"
"jemals zurückkommen wird?"
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Es muß fantastisch sein, wenn \n"
"man so groß ist. Ich wäre auch \n"
"gerne so groß!" BOX_BREAK UNSKIPPABLE "Das wäre mein Traum. Dann \n"
"könnte ich das Unkraut mit bloßen \n"
"Händen beseitigen..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Doch dummerweise altern wir \n"
"Kokiri nicht...\n"
"Das ist schade!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Warum folgt Ihnen eine Fee?\n"
"Sie sind kein Kokiri!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wer sind Sie? Mich können Sie \n"
"nicht täuschen, auch wenn Sie  \n"
"Kokiri-Kleidung tragen!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe Salia versprochen, sie\n"
"vor allen Gefahren zu schützen."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sei gegrüßt! Ich bin der " COLOR(RED) "Sproß \n"
"des Deku-Baumes" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Weil Du und Salia den Fluch\n"
"vom Waldtempel genommen haben,\n"
"kann ich wachsen und sprießen!" BOX_BREAK UNSKIPPABLE "Hab Dank!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hast Du Deine alten Freunde\n"
"wiedergesehen? Wahrscheinlich \n"
"wird Dich von ihnen niemand \n"
"mehr wiedererkennen..." BOX_BREAK UNSKIPPABLE "Das liegt daran, daß " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) " niemals\n"
"altern. Die vergangenen Jahre \n"
"gingen an ihnen spurlos vorüber!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sicher fragst Du Dich, warum Du\n"
"gealtert bist!" BOX_BREAK UNSKIPPABLE "Nun, Du hast es sicher schon \n"
"geahnt, Du bist kein Kokiri!\n"
"Du bist ein" COLOR(LIGHTBLUE) " Hylianer" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ich bin froh, Dir dieses Geheimnis\n"
"endlich offenbart zu haben!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Vor langer Zeit fand in Hyrule\n"
"ein Krieg statt, der nahezu eine\n"
"halbe Dekade andauerte." BOX_BREAK_DELAYED("\x5A") "Um diesem Krieg zu entkommen,\n"
"gab eine " COLOR(RED) "junge hylianische Mutter\n"
COLOR(DEFAULT) "ihr" COLOR(RED) " Baby " COLOR(DEFAULT) "in die Obhut des Waldes." BOX_BREAK_DELAYED("\x5A") "Als sich das Leben der Mutter \n"
"dem Ende zuneigte, vertraute sie\n"
"es dem " COLOR(RED) "Deku-Baum " COLOR(DEFAULT) "an..." BOX_BREAK_DELAYED("\x5A") "Der Deku-Baum ahnte bereits, daß\n"
"es sich bei dem Baby um ein Kind\n"
"des Schicksals handelte!" BOX_BREAK_DELAYED("\x5A") "Die" COLOR(ADJUSTABLE) " Kokiri " COLOR(DEFAULT) "zogen das Kind auf, und\n"
"es lebte dort bis zu jenem Tag, da\n"
"sich die Prophezeiung erfüllte." FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du bist " COLOR(LIGHTBLUE) "Hylianer" COLOR(DEFAULT) ". Es war immer\n"
"Deine Bestimmung, den Wald zu \n"
"verlassen." BOX_BREAK UNSKIPPABLE "Dein Schicksal...\n"
"Nun hat es sich endlich erfüllt!\n"
"Du weißt, was Du zu tun hast..." BOX_BREAK UNSKIPPABLE "Du mußt Hyrule vor dem Untergang \n"
"bewahren!" BOX_BREAK UNSKIPPABLE "So sei es, " NAME "! Befreie\n"
"die Tempel von ihren Flüchen und\n"
"sorge für Frieden in Hyrule!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Diese Melodie?!" BOX_BREAK UNSKIPPABLE "Salia hat sie geschrieben! \n"
"Sie... Sie kennen Salia?" BOX_BREAK UNSKIPPABLE "Das Lied..." BOX_BREAK UNSKIPPABLE "Salia hat das Lied nur ihren \n"
"engsten Freunden beigebracht..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Komisch... \n"
"Irgendwie erinnert er mich an\n"
"jemanden..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Der, der von meinem Fluch gebannt,\n"
"im Reich zwischen Wirklichkeit und\n"
"Traum, kann sein leblos Gebein\n"
"schon jetzt begraben!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Danke!\n"
"Dank Deiner Hilfe wurde ich in \n"
"den Kreis der Weisen\n"
"aufgenommen." BOX_BREAK UNSKIPPABLE "Nun bin ich die\n"
"Weise des Waldtempels..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x38") "Ich werde immer\n"
SHIFT("\x2D") "Deine Freundin sein..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Der Fluß der Zeit ist grausam...\n"
"Seine Geschwindigkeit scheint für\n"
"jede Person vorbestimmt. Niemand \n"
"hat die Möglichkeit, sie zu ändern..." BOX_BREAK UNSKIPPABLE "Etwas, das sich nie verändern \n"
"wird, sind die Erinnerungen an \n"
"vergangene Tage. Genieße daher\n"
"jede Sekunde Deines Lebens..." BOX_BREAK UNSKIPPABLE "Mit dem " COLOR(ADJUSTABLE) "Menuett des Waldes\n"
COLOR(DEFAULT) "kehrst Du zum Waldtempel zurück."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...\n"
"Wir werden uns wiedersehen..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salia ist noch immer nicht zurück...\n"
"Doch ich weiß, eines Tages wird \n"
"sie wiederkommen..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nun gut...\n"
"Ich vertraue Dir." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh... Ich verstehe." BOX_BREAK UNSKIPPABLE "Salia wird nicht zurückkommen." BOX_BREAK UNSKIPPABLE "Ich gab Salia das Versprechen, \n"
"daß..." BOX_BREAK UNSKIPPABLE "...ich " NAME " etwas mitteile,\n"
"falls er zurückkehrt. Salia sagte,\n"
"sie würde auf ihn warten...\n"
"Für immer..." BOX_BREAK UNSKIPPABLE "Ich glaube " TEXT_SPEED("\x03") "Salia... mochte...\n"
"ihn..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Fremder..." BOX_BREAK "Falls Sie ihn irgendwo sehen,\n"
"lassen Sie es ihn wissen..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fremder, ich möchte von Ihnen \n"
"lernen. Können Sie mir ein paar\n"
"neue Kampftechniken beibringen?"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich glaube immer noch, daß ich\n"
"Sie irgendwoher kenne..."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"So groß und kräftig wie Sie wäre\n"
"ich auch gerne. Hmmm, größer\n"
"werde ich bestimmt nicht. Vielleicht \n"
"klappt's ja mit der Kraft..."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "...\n"
"Ich frage mich, ob er\n"
"jemals zurückkehrt..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es kommt mir so vor, als würde\n"
"ich Sie schon seit Jahren kennen!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun, da der " COLOR(RED) "Sproß des Deku-Baumes\n"
COLOR(DEFAULT) "wächst und gedeiht, herrschen im\n"
"Wald wieder Ruhe und Frieden!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich werde alles tun, um den Wald\n"
"zu beschützen!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das Klima hat sich wieder \n"
"verändert. Es ist nun angenehm\n"
"warm..."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Seit es im Wald wieder\n"
"sicher ist, glaube ich,\n"
"daß " NAME " zurückkehren \n"
"wird!"
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich frage mich, was aus Salia \n"
"geworden ist..."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sicher wird " NAME " eines \n"
"Tages zurückkommen..."
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Deku-Baum...\n"
COLOR(DEFAULT)  SHIFT("\x22")  COLOR(LIGHTBLUE) "Ich bin zurückgekehrt!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das Böse in Menschengestalt\n"
"setzt seine diabolischen Kräfte\n"
"rücksichtslos ein, um Zugang\n"
"zum Heiligen Reich zu erlangen..." BOX_BREAK UNSKIPPABLE "In diesem Heiligen Reich ruht \n"
"das " COLOR(LIGHTBLUE) "Triforce" COLOR(DEFAULT) ", ein mächtiges Relikt \n"
"der Götter, und wartet auf den,\n"
"der seine Kraft zu nutzen weiß..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vor Tausenden von Jahren..." QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "...stiegen drei Göttinnen aus dem\n"
"Chaos der Gezeiten empor..." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1A") "Din, die Göttin der Kraft..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Nayru, die Göttin der Weisheit..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Farore, die Göttin des Mutes..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Mit dem feurigen Odem ihres\n"
SHIFT("\x11") "Körpers schuf sie unsere Welt." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Sie schenkte der Welt\n"
SHIFT("\x26") "die Gabe der Weisheit." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Sie spendete Leben und schuf\n"
SHIFT("\x38") "sämtliche Formen\n"
SHIFT("\x44") "des Daseins." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Als ihr Tun vollendet war,\n"
SHIFT("\x30") "zogen die Göttinnen\n"
SHIFT("\x4C") "gen Eden." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "Triforce-Symbole künden\n"
SHIFT("\x18") "noch heute von den Stätten,\n"
SHIFT("\x33") "die sie besuchten." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x25") "Seither ist das Triforce\n"
SHIFT("\x46") "ein Zeichen\n"
SHIFT("\x24") "göttlicher Prophezeiung!" QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1D") "Das Relikt der Götter ruht\n"
SHIFT("\x2B") "nun im Heiligen Reich." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast Dich tapfer geschlagen...\n"
"Es scheint, daß Du viel gelernt\n"
"hast! Jedoch..." BOX_BREAK_DELAYED("\x3C") "Du hast nur mein Phantom besiegt!\n"
"Trittst Du meinem wahren Ich\n"
"gegenüber, wirst Du vernichtet!" BOX_BREAK_DELAYED("\x3C") "Ich werde die reitende Kreatur nun \n"
"in den Hades verbannen, denn sie\n"
"hat ihren Schöpfer enttäuscht!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich habe stets gewußt, daß Du\n"
"zu Höherem berufen bist..." BOX_BREAK UNSKIPPABLE "Ich hege große Gefühle für Dich..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "Doch es ist Bestimmung, daß\n"
"wir verschiedene Wege gehen..." BOX_BREAK UNSKIPPABLE "Du und ich... Wir können nicht \n"
"in derselben Welt leben."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich werde Dich als Weise des\n"
"Waldes stets unterstützen..." BOX_BREAK UNSKIPPABLE "Nimm dieses " COLOR(ADJUSTABLE) "Amulett " COLOR(DEFAULT) "an Dich..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast Deinen Mut eindrucksvoll \n"
"unter Beweis gestellt." BOX_BREAK UNSKIPPABLE "Ich wußte, daß Du mein Vertrauen\n"
"nicht enttäuschen würdest!"
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Doch Du stehst erst am Anfang \n"
"Deiner Mission. Höre mich an...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "!\n"
"Begib Dich nun zum Schloß!" BOX_BREAK UNSKIPPABLE "Suche dort die " COLOR(RED) "Prinzessin" COLOR(DEFAULT) " auf,\n"
"denn sie teilt Dein Schicksal." BOX_BREAK UNSKIPPABLE "Nimm " COLOR(RED) "diesen Stein" COLOR(DEFAULT) " an Dich. Er\n"
"war das Begehr des Mannes, der\n"
"mich mit dem Fluch belegte."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich wußte, daß Du den Wald\n"
"eines Tages verlassen\n"
"würdest, " NAME "." BOX_BREAK UNSKIPPABLE "Denn Du bist anders als meine\n"
"Freunde und ich..."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE) "Hallo " QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "!\n"
"Wach auf!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Der" COLOR(RED) " Deku-Baum " COLOR(LIGHTBLUE) "hat Dich zu" COLOR(RED) " " COLOR(LIGHTBLUE) "\n"
"sich gerufen!\n"
QUICKTEXT_ENABLE  NAME ", wach auf!" QUICKTEXT_DISABLE  COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Los! " QUICKTEXT_ENABLE "Komm schon!" QUICKTEXT_DISABLE  COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Sollte die Zukunft Hyrules\n"
"wirklich in den Händen dieser\n"
"Schlafmütze liegen?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Springen ist langweilig...\n"
"Ein" COLOR(RED) " Rückwärtssalto" COLOR(DEFAULT) " ist cooler!\n"
"Beherrschst Du diese Technik?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Der" COLOR(RED) " Deku-Baum " COLOR(LIGHTBLUE) "hat Dich\n"
"zu sich befohlen...\n"
"Steh also endlich auf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x4B") "Navi...\n"
SHIFT("\x2E") "Navi, wo bist Du?\n"
SHIFT("\x39") "Erscheine..."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi, holde Fee" COLOR(DEFAULT) "...\n"
"Höre die Worte des \n"
COLOR(RED) "Deku-Baumes" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Spürst Du es?\n"
"Diabolische Kräfte bedrohen \n"
"unser Land." BOX_BREAK UNSKIPPABLE "Die Kreaturen der Nacht sammeln \n"
"sich, um das Schicksal Hyrules \n"
"zu besiegeln." BOX_BREAK UNSKIPPABLE "Für lange Zeit war ich es, der\n"
"die Schatten des Unheils daran\n"
"hinderte, das Land zu erobern." BOX_BREAK UNSKIPPABLE "Doch nun ist die Konzentration\n"
"des Bösen so stark, daß meine  \n"
"Kräfte nicht ausreichen, die \n"
"dunklen Mächte zu bannen..." BOX_BREAK UNSKIPPABLE "Die Zeit scheint reif, da der \n"
COLOR(RED) "Junge ohne Fee " COLOR(DEFAULT) "seine Bestimmung \n"
"erfahren soll..." BOX_BREAK UNSKIPPABLE "Die Jugend und Reinheit des\n"
"Jungen sollen Hyrule wieder auf\n"
"den Pfad des Lichtes führen..." BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "... Geh nun! Finde unseren\n"
"Freund und geleite ihn zu mir..." BOX_BREAK UNSKIPPABLE "Meine Zeit ist fast vorüber...\n"
"Mir bleiben nur noch wenige\n"
"Stunden." BOX_BREAK UNSKIPPABLE "Flieg, Navi, flieg! Das Schicksal \n"
"des Dorfes, gar das der ganzen \n"
"Welt, liegt in den Händen dieses \n"
"Jungen..."
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Vergib mir, Herr! Ich werde \n"
"es nicht wieder tun! Laß mich frei,\n"
"und ich gebe ein Geheimnis preis." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Nie wirst Du meine Brüder \n"
"bezwingen, wenn Du sie nicht in \n"
"richtiger Reihenfolge besiegst!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Merke Dir... " TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) "2  3  1" COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
UNSKIPPABLE  SFX("\x38\x80")  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Rechts vor links, aber\n"
"die goldene Mitte geht vor!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"Bin ich jetzt ein Verräter?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Woher kanntest Du unser Geheimnis?!\n"
"Bist Du ein " QUICKTEXT_ENABLE "Hellseher?" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "So sei es denn. Ich werde\n"
"Dir das Geheimnis der Spinnenkönigin\n"
"verraten..." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Um sie zu vernichten, solltest Du\n"
"die Früchte des Baumes nutzen... \n"
"Ein Gegner, der sich " COLOR(RED) "nicht bewegt" COLOR(DEFAULT) ", \n"
"läßt sich leichter bezwingen..." BOX_BREAK UNSKIPPABLE "Vergebt mir, Königin..." BOX_BREAK SFX("\x38\x80")  QUICKTEXT_ENABLE "Schande über mich!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"Es war einst in einem fernen Land..." BOX_BREAK_DELAYED("\x28")  SHIFT("\x0A") "Seit Anbeginn der Zeit wacht der\n"
SHIFT("\x18") "mächtige Deku-Baum über die\n"
SHIFT("\x30") "Kinder des Waldes!" FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x21") "Jedem der Kokiri schenkt\n"
SHIFT("\x29") "der Wächter eine Fee." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0D") "Als seine Abgesandten schützen\n"
SHIFT("\x22") "sie jene reinen Herzens." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x11") "Das Schicksal hat jedoch einen\n"
SHIFT("\x08") "auserkoren, dessen Bestimmung es\n"
SHIFT("\x11") "ist, den Gesetzen vergangener\n"
SHIFT("\x2B") "Zeiten zu entfliehen..." FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Vergib mir... Darf ich Dir Deku-  \n"
"Nüsse anbieten?\n"
COLOR(RED) "5 Stück   " COLOR(DEFAULT) "kosten" COLOR(RED) "  20 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Du hast gesiegt. Laß mich Dir einen\n"
"Deku-Stab anbieten!\n"
COLOR(RED) "1 Stück   " COLOR(DEFAULT) "kostet" COLOR(RED) "  15 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ich bin bezwungen. Verschone mich,\n"
"und ich werde Dir ein Herzteil zum \n"
"Kauf anbieten!\n"
COLOR(RED) "1 Stück   " COLOR(DEFAULT) "kostet" COLOR(RED) "  10 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Laß uns ein Geschäft machen!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "Ups!" QUICKTEXT_DISABLE "\n"
"Dann verschwinde ich besser!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Du hast zu wenig Rubine! \n"
"Komm später wieder!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Du hast schon genug davon!\n"
"Komm später wieder!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x43") "Hab Dank!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich habe auf Dich gewartet,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Dies ist die " COLOR(RED) "Heilige Lichtung" COLOR(DEFAULT) ",\n"
"mein Lieblingsort!\n"
"Ich spüre etwas..." BOX_BREAK UNSKIPPABLE "Dieser Ort wird für uns beide \n"
"von schicksalhafter Bedeutung sein.\n"
"Das kann ich fühlen..." BOX_BREAK UNSKIPPABLE "Spielst Du hier die Okarina, \n"
"kannst Du zu den Geistern des \n"
"Waldes sprechen." TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Machst Du mir die Freude und \n"
"spielst mit mir?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Versuch, die Melodie, die ich\n"
"spiele, nachzuspielen...\n"
"Bist Du bereit?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Was?!\n"
"Du enttäuschst mich!\n"
"Komm schon, spiel mir nach!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x2F") "Wie wunderschön!" BOX_BREAK UNSKIPPABLE "Du darfst dieses Lied nie \n"
"vergessen. Versprich es!" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du meine Stimme hören, so \n"
"spiele " COLOR(ADJUSTABLE) "Salias Lied" COLOR(DEFAULT) ". Du kannst \n"
"Dich jederzeit mit mir \n"
"unterhalten..."
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Paß gut auf meine Okarina \n"
"auf..."
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x38\x80") "Fantastisch!\n"
"Du hast dreimal ins Schwarze\n"
"getroffen!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Dein Talent soll nicht ohne Lohn\n"
"bleiben! Hier, nimm dies an Dich!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vielleicht weiß Mido, wo sich Salia\n"
"aufhält..." BOX_BREAK "Er hat sich beleidigt in eines der \n"
"Häuser zurückgezogen."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "Hallo?\n"
COLOR(DEFAULT)  SHIFT("\x35")  COLOR(LIGHTBLUE) "Er reagiert nicht!\n"
COLOR(DEFAULT)  SHIFT("\x23")  COLOR(LIGHTBLUE) "Er scheint zu schlafen..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Henni?  Was?!\n"
"Ich dachte, nur ein netter Mensch\n"
"wie ich kann Dich zähmen..." BOX_BREAK UNSKIPPABLE "Das bedeutet..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x01") "Du... " TEXT_SPEED("\x00") "Du mußt in Ordnung sein!\n"
QUICKTEXT_ENABLE "Ja, ganz bestimmt!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Ich vertraue Dir!" QUICKTEXT_DISABLE "\n"
"Tust Du mir einen Gefallen?" BOX_BREAK UNSKIPPABLE "Bring dies hier zum " COLOR(RED) "Laden der \n"
"Hexe Asa" COLOR(DEFAULT) " in Kakariko!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Doch laß Dir nicht zuviel Zeit,\n"
"denn sonst löst es sich auf!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ach... " QUICKTEXT_ENABLE "Na sowas..." QUICKTEXT_DISABLE "\n"
"Du scheinst doch nicht so nett zu \n"
"sein, wie ich dachte!\n"
QUICKTEXT_ENABLE "Du enttäuschst mich!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salia hat nach Dir gesucht...\n"
"Hat sie Dich schon gefunden?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beeil Dich, mein Freund!\n"
"Bevor es sich auflöst, muß es bei\n"
"der Hexe sein..."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Er ist nicht mehr hier..." BOX_BREAK UNSKIPPABLE "Jedes Wesen, das kein Kokiri ist,\n"
"ist in diesen Wäldern verloren." BOX_BREAK UNSKIPPABLE "Sicher hat er sich inzwischen\n"
"auch in eine Pflanze verwandelt.\n"
"Alles, was von ihm übrig blieb,\n"
"ist diese Säge hier." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Medizin besteht aus \n"
"Waldpilzen! Gib sie mir! \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wirst auch Du Dich verwandeln?"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wir verkaufen Schilde, aber keine \n"
"Schwerter!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du kennst " COLOR(ADJUSTABLE) "Salias Lied" COLOR(DEFAULT) "! Wir sollten \n"
"Freunde werden! Hier, nimm das..."
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hi! Wie findest Du mein Outfit?\n"
"Ich gebe zu, es ist nicht \n"
"besonders aufregend..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Laß uns mal wieder spielen!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Stimme in unser Lied mit Deiner \n"
"Okarina ein. Wir fangen an..."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das hat Spaß gemacht. Nimm dies\n"
"als Beweis unserer Freundschaft."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Willkommen!\n"
"Ich habe Dich erwartet!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Schön, Dich wiederzusehen, \n"
NAME ". Hör mir gut zu!" TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hier in den Verlorenen Wäldern \n"
"wirst Du die " COLOR(ADJUSTABLE) "Heilige Lichtung" COLOR(DEFAULT) " \n"
"finden." BOX_BREAK "Dies ist ein Ort, den bisher nur\n"
"wenige Leute betreten haben." BOX_BREAK "Still... Ich höre etwas...\n"
"Ich höre eine fremde Melodie!" BOX_BREAK "Kannst Du sie auch hören?" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Muß ich mich noch einmal \n"
"wiederholen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Beweise Dein Geschick und finde\n"
"den Weg durch den Wald..." BOX_BREAK UNSKIPPABLE "Verlasse Dich auf Dein Gehör\n"
"und Du wirst schon bald Dein\n"
"Ziel erreichen!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Hat Salia Dir ihr Lied \n"
"beigebracht?" BOX_BREAK UNSKIPPABLE "Das Lied scheint geheimnisvolle\n"
"Kräfte zu haben." BOX_BREAK UNSKIPPABLE "Ich hörte, daß an anderen \n"
"Orten ebenfalls die Möglichkeit\n"
"besteht, Lieder zu lernen. Zum \n"
"Beispiel in Hyrule..." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Plazierst Du die Okarina auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"und wählst sie aus, werden\n"
COLOR(RED) "Notenlinien" COLOR(DEFAULT) " erscheinen." BOX_BREAK "Ich empfehle Dir, hier eines der\n"
"Lieder zu spielen, die Du erlernt \n"
"hast." BOX_BREAK "Du kannst natürlich auch ohne\n"
"Notenlinien spielen. Auch das \n"
"macht Spaß!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Muß ich alles nochmal sagen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Alle Lieder, die Du lernst, \n"
"werden Dir im " COLOR(LIGHTBLUE) "Status-Menü \n"
COLOR(DEFAULT) "angezeigt. Lerne sie, denn Du \n"
"wirst sie häufig brauchen."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Dieser Mido! Ich frage mich, was \n"
"er sich dabei denkt..." BOX_BREAK UNSKIPPABLE "Dennoch ist das, was er sagte, \n"
"wahr." TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Im Wald gehen in letzter Zeit\n"
"merkwürdige Dinge vor sich..." BOX_BREAK UNSKIPPABLE "Wir müssen auf alles vorbereitet \n"
"sein. Du solltest Dir eine Waffe \n"
"suchen!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Hab Gnade! Ich kann Dir \n"
COLOR(RED) "Deku-Kerne " COLOR(DEFAULT) "anbieten!\n"
COLOR(RED) "30 Stück   " COLOR(DEFAULT) "kosten" COLOR(RED) "   40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ich gebe auf! Wie wär's, wenn ich\n"
"Dir einen " COLOR(RED) "Deku-Schild" COLOR(DEFAULT) " verkaufen \n"
"würde! Er kostet " COLOR(RED) "50 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") " Hab Erbarmen! Ich kann Dir \n"
"einige" COLOR(RED) " Bomben " COLOR(DEFAULT) "verkaufen!\n"
COLOR(RED) "5 Stück   kosten    40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Halte ein! Laß mich gehen und \n"
"ich verkaufe Dir " COLOR(RED) "Pfeile" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 Stück   kosten   70 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Vergib mir! Laß mich laufen, und \n"
"ich verkaufe Dir " COLOR(RED) "Rotes Elixier" COLOR(DEFAULT) " für \n"
"nur " COLOR(RED) "40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Hab Gnade! Verschone mich und \n"
"ich verkaufe Dir " COLOR(ADJUSTABLE) "Grünes Elixier" COLOR(DEFAULT) " für \n"
"nur " COLOR(RED) "40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Was?! Du hast eine Fee?!\n"
"Und der Deku-Baum hat Dich zu \n"
"sich gerufen?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Was muß ich da hören?!" BOX_BREAK UNSKIPPABLE "Wieso sollte er DICH und nicht \n"
"den großen" COLOR(RED) " Mido " COLOR(DEFAULT) "zu sich rufen?" BOX_BREAK UNSKIPPABLE "Das kann nicht sein..." BOX_BREAK UNSKIPPABLE "Ich glaube es einfach nicht!\n"
"Du bist nicht einmal richtig\n"
"ausgerüstet!" BOX_BREAK UNSKIPPABLE "Wie willst Du dem Deku-Baum \n"
"denn ohne " COLOR(ADJUSTABLE) "Schwert" COLOR(DEFAULT) " und " COLOR(LIGHTBLUE) "Schild" COLOR(DEFAULT) "\n"
"gegenübertreten?" BOX_BREAK "Was? Das stimmt, ich bin auch \n"
"nicht ausgerüstet, aber das ist\n"
"etwas anderes..." TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x2B") "Hey, was ist das?!" BOX_BREAK UNSKIPPABLE "Du besitzt einen " COLOR(LIGHTBLUE) "Deku-Schild" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Und... Und auf Deinem Rücken\n"
"trägst Du ein Schwert!" BOX_BREAK UNSKIPPABLE "Unglaublich! Es ist in der\n"
"Tat das " COLOR(ADJUSTABLE) "Kokiri-Schwert" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "HEILIGER DEKU!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wie dem auch sei, ein Weichling \n"
"bleibt immer ein Weichling!" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Laß mich laufen und ich verkaufe \n"
"Dir einen " COLOR(RED) "Deku-Stab" COLOR(DEFAULT) " für nur \n"
COLOR(RED) "15 Rubine!" COLOR(DEFAULT)  TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Verzeih mir! Ich kann Dir " COLOR(RED) "Deku-\n"
"Nüsse" COLOR(DEFAULT) " zum Kauf anbieten!\n"
COLOR(RED) "5 Stück   kosten    20 Rubine!" COLOR(DEFAULT)  TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Noch etwas..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x08") "Es tut mir leid, daß ich gemein \n"
SHIFT("\x3C") "zu ihm war." QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x14") "Sagen Sie ihm das bitte auch!"
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast einen beschwerlichen Weg\n"
"hinter Dir...\n"
"Du scheinst ein wahrer Held zu \n"
"sein!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sieh doch nur, ist die Aussicht \n"
"nicht wunderschön? Wechsle den \n"
"Blickwinkel mit " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "und nutze" COLOR(YELLOW) " " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ",\n"
"um die Sicht zu genießen."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was hast Du mit dem Deku-Baum \n"
"gemacht?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bevor Du Dich in die Verlorenen \n"
"Wälder begibst, solltest Du Dich \n"
"besser ausrüsten!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x82") "Meine Brüder und ich sind uns\n"
"einig...\n"
"Du bist potthäßlich!" BOX_BREAK SFX("\x38\x82") "Zum Trost werden wir Dich mit \n"
"einigen " COLOR(RED) "Deku-Nüssen " COLOR(DEFAULT) "versorgen." BOX_BREAK SFX("\x38\x82") "Außerdem werden wir dafür \n"
"sorgen, daß Du von nun an mehr \n"
"Nüsse tragen kannst!" BOX_BREAK "Hobrobbel... Kadobbel..." BOX_BREAK SFX("\x38\x80") "Wazakamobbel!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Hab Gnade!" BOX_BREAK SFX("\x38\x80") "Verschone mich und ich sorge\n"
"dafür, daß Du von nun an mehr\n"
COLOR(RED) "Deku-Stäbe " COLOR(DEFAULT) "tragen kannst!\n"
"Es kostet Dich nur " COLOR(RED) "40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Verschone mich!" BOX_BREAK SFX("\x38\x80") "Gewähr mir Gnade und ich sorge\n"
"dafür, daß Du von nun an mehr\n"
COLOR(RED) "Deku-Nüsse " COLOR(DEFAULT) "tragen kannst!\n"
"Es kostet Dich nur " COLOR(RED) "40 Rubine" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tut mir leid, aber Du kannst das \n"
"jetzt nicht kaufen!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der, den Du suchst,\n"
"ist nicht mehr hier..." BOX_BREAK "Jeder, der diesen Wald betritt und \n"
"kein Kokiri ist, ist verdammt..." BOX_BREAK "Jeder...\n"
"Sicher hat er sich schon längst in \n"
"eine Pflanze verwandelt..."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vielen Dank nochmal für \n"
"die Hilfe... Ich weiß nicht\n"
"einmal Deinen Namen..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Sagst Du ihn mir?" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Wirklich?\n"
NAME "!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Hab ich's doch gewußt!" QUICKTEXT_DISABLE "\n"
"Du bist der Feen-Junge aus dem\n"
"Wald! Es war vor vielen Jahren.\n"
"Erinnerst Du Dich an mich?" BOX_BREAK UNSKIPPABLE "Tatsächlich? Ich dachte mir schon,\n"
"daß Du es bist. Epona hat Dich\n"
"gleich wiedererkannt!" BOX_BREAK UNSKIPPABLE "Oh, ich muß Dir etwas über " COLOR(RED) "Basil\n"
COLOR(DEFAULT) "erzählen..." BOX_BREAK UNSKIPPABLE "Er hatte Angst, daß Ganondorf\n"
"dahinterkommen würde, daß er Epona\n"
"gehen ließ. Diese Furcht hat aus\n"
"ihm einen anderen Menschen gemacht!" BOX_BREAK UNSKIPPABLE "Nun ist er wieder " COLOR(RED) "so wie früher" COLOR(DEFAULT) ".\n"
"Daher kehrte auch mein Vater auf" COLOR(RED) "\n"
COLOR(DEFAULT) "die Farm zurück!" BOX_BREAK UNSKIPPABLE "Endlich wird alles wieder, wie\n"
"es einmal war. Ist das nicht\n"
"schön?!" BOX_BREAK UNSKIPPABLE "Das alles haben wir Dir zu\n"
"verdanken! Wir stehen tief in\n"
"Deiner Schuld!" BOX_BREAK UNSKIPPABLE "Vielen Dank, " NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wie geht es " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK "Spielst Du " COLOR(RED) "Eponas Lied " COLOR(DEFAULT) "auf Deiner\n"
"Okarina, wird sie immer zu Dir\n"
"kommen." BOX_BREAK "Wann immer Du mit Epona \n"
COLOR(RED) "trainieren" COLOR(DEFAULT) " möchtest, kannst Du \n"
"gern zur Farm zurückkehren!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "sieht prächtig aus!\n"
"Es scheint Dir gelungen zu sein,\n"
"sie zu zähmen!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Warum versuchst Du Dich nicht mit\n"
"Epona an dem " COLOR(RED) "Hindernisparcours" COLOR(DEFAULT) "?" BOX_BREAK "Du mußt " COLOR(RED) "zwei Runden" COLOR(DEFAULT) " reiten und \n"
"darfst dabei kein Hindernis \n"
"auslassen. Das ist eine große\n"
"Herausforderung!" BOX_BREAK "Wie sieht's aus?\n"
"Möchtest Du es versuchen? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun, Deine Zeit war " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ".\n"
"Nicht besonders gut..." BOX_BREAK "Vergiß nicht, Du brauchst nur zu\n"
"beschleunigen, um über die hohen \n"
"Hindernisse zu springen. Die\n"
"niedrigen nimmt Epona auch so."
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME ", kannst Du mich\n"
"hören? Ich bin es, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Muuuuuuuuuuuuuuuuuuuuuuuuuuuuh!" BOX_BREAK "Welch ein schönes Lied...\n"
"Es erinnert mich ans Melken..." BOX_BREAK "Muh, nach diesem Lied könnte\n"
"ich literweise Milch geben..." EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hier, nimm etwas von der \n"
"erfrischenden und nahrhaften \n"
"Milch!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME ", nun, da Du die \n"
"Okarina in Händen hältst..." BOX_BREAK_DELAYED("\x3C") "...bin ich schon weit entfernt..." BOX_BREAK_DELAYED("\x3C") "Ich versuchte, auf Dich zu warten,\n"
"doch die Zeit drängte..." BOX_BREAK_DELAYED("\x3C") "Zumindest konnte ich Dir die \n"
"Okarina übergeben...\n"
"Und diese " COLOR(LIGHTBLUE) "Melodie" COLOR(DEFAULT) "..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Wohlan, " NAME ".\n"
"Spiele diese Melodie in der\n"
"Zitadelle der Zeit vor dem \n"
"Zeitaltar!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ha! Denkst Du wirklich, daß ich \n"
"Dich nicht erkenne?" BOX_BREAK UNSKIPPABLE  SHIFT("\x1E") "Hey?!" BOX_BREAK UNSKIPPABLE "Ist das nicht eine Fuchs-Maske?\n"
"So etwas ist doch zur Zeit sehr \n"
"angesagt!" BOX_BREAK UNSKIPPABLE "Mein Sohn ist ganz verrückt\n"
"danach! \n"
"Wie wäre es, wenn..." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Würdest Du sie mir verkaufen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schade, doch ich gebe nicht auf!\n"
"Ich habe sehr viel Geduld. Sonst\n"
"würde ich hier auch nicht den\n"
"ganzen Tag herumstehen!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Gähn...\n"
"Schon gut, ich bin wach..." BOX_BREAK UNSKIPPABLE "Was?" BOX_BREAK UNSKIPPABLE "Ach, Du bist es! Hallo!" BOX_BREAK UNSKIPPABLE "Ich erinnere mich an Dich...\n"
"Malon war damals ziemlich sauer\n"
"auf mich..." BOX_BREAK UNSKIPPABLE "Du hast uns sehr geholfen. \n"
"Deshalb möchte ich, daß Du diese \n"
COLOR(RED) "Milch" COLOR(DEFAULT) " an Dich nimmst. Du kannst\n"
"auch die Flasche behalten!"
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das Passieren ist " COLOR(RED) "nur mit \n"
"königlicher Erlaubnis" COLOR(DEFAULT) " möglich!" BOX_BREAK "Hast Du das Schild nicht gelesen?\n"
"Oh, Du bist ja noch ein Kind,\n"
"sicher kannst Du gar nicht lesen..."
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was soll ich damit?!"
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, das scheint...\n"
"In der Tat, es ist Zeldas \n"
"Handschrift! Laß mal sehen... \n"
UNSKIPPABLE "Hmmm... Na gut..." BOX_BREAK "\"" COLOR(PURPLE) "Dies ist " NAME ".\n"
" Er hat den Auftrag, Hyrule\n"
" vor dem Untergang zu bewahren." COLOR(DEFAULT) "\"\n"
SHIFT("\x5A") "Prinzessin Zelda" BOX_BREAK UNSKIPPABLE "Ha!\n"
"Was ist denn das für ein \n"
"seltsames Vorhaben..." BOX_BREAK UNSKIPPABLE "Wie dem auch sei, Du kannst \n"
"passieren, Zwergenheld!\n"
TEXT_SPEED("\x01") "Hahaha!" TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, unser Held!\n"
"Vielen Dank für Deine Bemühungen!\n"
TEXT_SPEED("\x01") "Hahaha!" TEXT_SPEED("\x00") "!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Nicht schlecht!\n"
"Deine Zeit war " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) "!\n"
"Epona und Du, Ihr seid ein\n"
"gutes Team!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, das ist schade...\n"
"Du hast keine leere Flasche, sonst \n"
"hätte ich Dir etwas von meiner \n"
"Milch gegeben..." EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich bin " COLOR(RED) "Basil" COLOR(DEFAULT) "... für Dich natürlich\n"
"\"Herr Basil\". Du bist mir im Weg,\n"
"Kleiner! Verschwinde!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ach, Herr Nachwuchsheld..." BOX_BREAK UNSKIPPABLE "Falls Du planst, den Todesberg zu \n"
"besteigen, solltest Du Dich mit\n"
"einem " COLOR(LIGHTBLUE) "starken Schild" COLOR(DEFAULT) " ausrüsten!\n"
"Der Vulkan ist noch immer aktiv!" BOX_BREAK UNSKIPPABLE "Auf dem Marktplatz in Hyrule\n"
"wirst Du sicher fündig, wenn Du\n"
"Ausrüstungsgegenstände kaufen\n"
"möchtest!" BOX_BREAK UNSKIPPABLE "Wenn Du ihnen sagst, daß ich \n"
"Dich geschickt habe, machen sie \n"
"Dir sicher einen Sonderpreis!" BOX_BREAK UNSKIPPABLE "Denkst Du aber, Deine\n"
"Ausrüstung würde genügen, dann\n"
"laufe ruhig weiter." BOX_BREAK UNSKIPPABLE "Übrigens: Kann ich Dich um\n"
"einen Gefallen bitten? Du mußt es\n"
"nicht tun, aber immerhin habe ich\n"
"Dir eben einen guten Tip gegeben." BOX_BREAK UNSKIPPABLE "Warst Du schon beim \n"
COLOR(RED) "Maskenhändler" COLOR(DEFAULT) " in Hyrule? Über \n"
"diesen Laden spricht zur Zeit \n"
"jeder!" BOX_BREAK UNSKIPPABLE "Mein Sohn drängt mich schon die \n"
"ganze Zeit, ihm eine Maske zu \n"
"kaufen. Doch leider fehlt mir die \n"
"Zeit..." BOX_BREAK UNSKIPPABLE "Könntest Du mir eine Maske aus\n"
"dem Laden besorgen? Ich meine, \n"
"nur wenn Du zufällig mal nach \n"
"Hyrule kommen solltest..." BOX_BREAK UNSKIPPABLE "Wie gesagt, ich kann hier nicht \n"
"weg. Mein Job..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4C") "Seufz..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wünschte, ich könnte zum \n"
COLOR(RED) "Maskenhändler" COLOR(DEFAULT) " gehen und meinem \n"
"Sohn eine Maske kaufen..." BOX_BREAK SHIFT("\x4C") "Seufz..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Oh nein... Er atmet nicht mehr..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E") "Verdammt!" QUICKTEXT_DISABLE " Sie ist fort!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x4A") "Du da! \n"
SHIFT("\x39")  QUICKTEXT_ENABLE "Kleiner Wicht!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x41")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Ha" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x3A") "Du hast Mut!\n"
SHIFT("\x17") "Doch Mut kann manchmal...\n"
SHIFT("\x39") "...tödlich sein!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x36") "Armseliger Tropf!" QUICKTEXT_DISABLE "\n"
SHIFT("\x32") "Weißt Du, wem Du \n"
SHIFT("\x33") "gegenüberstehst?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D") "Ich bin " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x1E") "Der König der Gerudos!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x22") "Du mußt das weiße Pferd\n"
SHIFT("\x20") "gesehen haben! In welche\n"
SHIFT("\x10") "Richtung sind sie entkommen?!\n"
SHIFT("\x39")  QUICKTEXT_ENABLE "Antworte mir!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn die Zeit abgelaufen ist,\n"
"sage ich Dir Bescheid..."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Sohn wird sich sehr über die\n"
"Maske freuen! Vielen Dank,\n"
"mein Freund!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Du hast die Maske, für die Du\n"
"10 Rubine bezahlen mußt, für " COLOR(RED) "15 \n"
"Rubine " COLOR(DEFAULT) "weiterverkauft. Du hast \n"
"einen Gewinn erwirtschaftet!" BOX_BREAK UNSKIPPABLE "Geh nun zum Maskenhändler\n"
"zurück und gib ihm seine\n"
COLOR(RED) "10 Rubine" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kleine Kinder dürfen an der \n"
COLOR(RED) "Grausigen Grabgrusel-Tour" COLOR(DEFAULT) "\n"
"leider nicht teilnehmen..." BOX_BREAK "Deshalb treibe ich mich hier herum\n"
"und spiele Grausige Grabgrusel-\n"
"Tour..." BOX_BREAK "Allerdings sehe ich nicht \n"
"besonders grausig aus, oder?"
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Oh Graus!" QUICKTEXT_DISABLE " Es ist Boris, der \n"
"Totengräber!" BOX_BREAK SHIFT("\x51") "Nanu...?" BOX_BREAK "Oh, es ist nur eine Maske! Wow, \n"
"ich bin ganz schön \n"
"erschrocken!" BOX_BREAK "Gibst Du mir die Maske?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe auch Geld, ich kann\n"
"sie bezahlen!"
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey! Runter vom Pferd!\n"
"Die Zeit ist abgelaufen!\n"
"Du hast nur 10 Rubine gezahlt!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mit dieser Maske sehe ich fast \n"
"wie Boris aus! Cool! \n"
"Hier ist das Geld!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Du hast die Maske, die Dich\n"
"30 Rubine gekostet hat, zum \n"
"gleichen Preis weiterverkauft!" BOX_BREAK UNSKIPPABLE "Geh nun zurück zum \n"
"Maskenhändler und zahl ihm seine\n"
COLOR(RED) "30 Rubine " COLOR(DEFAULT) "zurück. Dabei kannst \n"
"Du eine neue Maske leihen."
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich fange jetzt zu graben an! \n"
"Genau wie Boris!"
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Früher hoppelten noch viele Hasen\n"
"durch die hylianische Steppe. Nun\n"
"sind sie fort, denn sie waren \n"
"sehr schmackhaft... Hoppeldihö..." BOX_BREAK "Wie gern wäre ich ein Hase... Wie \n"
"gern hätte ich lange Ohren, die \n"
"bei jeder Bewegung mitwippen\n"
"würden... Hoppeldihö..." BOX_BREAK "Findest Du mich merkwürdig?"
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wette, mit diesen Ohren kannst \n"
"Du die Stimmen hören... Das sind\n"
"die Ohren, die der Große Kürbis\n"
"prophezeit hat... Hoppeldihö..." TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mir ist egal, wie teuer sie sind!\n"
"Ich muß sie haben! Verkauf sie mir!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist nicht das, was ich hören \n"
"wollte! Hoppeldinö!"
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Traum geht in Erfüllung! Ich\n"
"habe Hasenohren! Hoppeldihö!\n"
"Füttert mich mit Möhren!" EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Für die Maske hast Du 50\n"
"Rubine bezahlt. Der durchgeknallte \n"
"Kerl hat Dir jedoch mehr dafür \n"
"gegeben, als Du zählen kannst!" BOX_BREAK UNSKIPPABLE "Geh zurück zum Maskenhändler \n"
"und gib ihm seine " COLOR(RED) "50 Rubine" COLOR(DEFAULT) " \n"
"wieder."
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x11") "Glaubst Du im Ernst, daß Du\n"
SHIFT("\x0F") "sie vor mir schützen kannst?\n"
SHIFT("\x47") "Du Narr!"
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Einige Leute verbreiten das \n"
"Gerücht, ich hätte Talon um die\n"
"Farm betrogen, aber..." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2D") "Das ist lächerlich!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Talon hat alles herunter- \n"
"gewirtschaftet! Ich, der hart \n"
"arbeitende " COLOR(RED) "Basil" COLOR(DEFAULT) ", habe meine ganze\n"
"Kraft in die Farm gesteckt!" BOX_BREAK UNSKIPPABLE "Niemand darf deshalb schlecht\n"
"über mich sprechen!" BOX_BREAK UNSKIPPABLE "Im Vertrauen... Eigentlich war\n"
"es der " COLOR(RED) "mächtige Ganondorf" COLOR(DEFAULT) ", der \n"
"meine Talente erkannte und mir die\n"
"Farm überließ..." BOX_BREAK UNSKIPPABLE "Als Dank werde ich ihm das beste\n"
"Pferd meiner Züchtung als Präsent\n"
"überreichen!" BOX_BREAK UNSKIPPABLE "Sag mal, hättest Du nicht Lust, \n"
"eines meiner Pferde zu reiten?" TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Für nur " COLOR(RED) "10 Rubine " COLOR(DEFAULT) "lasse ich \n"
"Dich reiten.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Reiten!\n"
"Nicht reiten!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na gut, dann verschwinde von \n"
"meiner Farm!"
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast zu wenig Rubine!\n"
"Komm wieder, wenn Du ein bißchen \n"
"mehr in der Tasche hast!"
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Soll ich Dir erklären, wie man \n"
"reitet?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nähere Dich dem Pferd langsam \n"
"und stell Dich an seine Seite.\n"
"Mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " steigst Du auf." BOX_BREAK "Nutze den " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ", um mit Epona zu \n"
"traben. Galoppierst Du, kannst Du \n"
"mit" COLOR(BLUE) " [A]" COLOR(DEFAULT) " die Peitsche aktivieren, \n"
"um sie noch mehr anzutreiben!" BOX_BREAK "Willst Du über ein Hindernis \n"
"springen, galoppiere darauf zu\n"
"und setze vor der Hürde die\n"
"Peitsche ein!" BOX_BREAK "Ist der Winkel, in dem Du auf das\n"
"Hindernis zureitest, zu spitz,\n"
"verweigert das Pferd." BOX_BREAK "Um wieder abzusteigen, halte \n"
"das Pferd an und drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".\n"
"Viel Spaß beim Reiten!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Setzt Du die " COLOR(LIGHTBLUE) "Zielerfassung" COLOR(DEFAULT) " ein,\n"
"kannst Du mit mir sprechen,\n"
"während Du auf dem Pferd sitzt." BOX_BREAK "Willst Du jetzt schon gehen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Nein, ich will reiten!\n"
"Ja, es ist genug!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du absteigen, halte an und \n"
"drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Hab ich Dich nicht schon mal\n"
"irgendwo gesehen? Du kommst mir\n"
"so bekannt vor..." TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du reitest nicht schlecht!\n"
"Wie wäre es mit einem kleinen\n"
"Rennen? Eine Runde um die \n"
"Koppel!" BOX_BREAK "Der Gewinner erhält, sagen wir,\n"
COLOR(RED) "50 Rubine" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Übe lieber noch ein wenig!\n"
"Dann kannst Du auch gegen \n"
"mich antreten!"
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x39") "Ver" QUICKTEXT_ENABLE "maledeit!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ich hoffe nur, der mächtige\n"
"Ganondorf erfährt nicht von dieser\n"
"Demütigung... Hey, Du! Wie wäre es\n"
"mit einer Revanche? Gewinnst Du,..." BOX_BREAK UNSKIPPABLE "...gehört das Pferd Dir!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wie kann das sein?!\n"
"Ist das wirklich " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Wie ist es Dir gelungen, das Pferd\n"
"hinter meinem Rücken zu zähmen?!" BOX_BREAK UNSKIPPABLE "Ich wollte Epona dem mächtigen\n"
"Ganondorf zum Geschenk machen!\n"
"Nun habe ich sie beim Pferderennen \n"
"verloren! Vermaledeit!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x1A") "Nun gut, so sei es denn!" BOX_BREAK UNSKIPPABLE "Ich halte mein Versprechen, das \n"
"Pferd möge Dir gehören..." BOX_BREAK UNSKIPPABLE  SHIFT("\x52") "Nur..." BOX_BREAK UNSKIPPABLE "Die Farm darfst Du mit ihr nicht \n"
"verlassen!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha! Hattest Du wirklich gedacht,\n"
"mich bezwingen zu können? \n"
"Danke für die 50 Rubine." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha! Im ersten Rennen habe ich nur\n"
"geblufft. Wie könnte ich gegen Dich\n"
"verlieren? Komm wieder, wenn Du\n"
"es erneut versuchen willst..."
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Was?! Wer hat Dir erlaubt, Dich  \n"
"hier herumzutreiben?\n"
"Armseliger Wicht!" BOX_BREAK UNSKIPPABLE "Ich bin " COLOR(RED) "Basil" COLOR(DEFAULT) ". Diese Farm liegt \n"
"mir sehr am Herzen." BOX_BREAK UNSKIPPABLE "Ich arbeite schon verdammt lange \n"
"hier. Talon, der faule Sack, ist \n"
"mein Chef!" BOX_BREAK UNSKIPPABLE "Heute zum Beispiel wollte er nur\n"
"schnell Milch im Schloß abliefern,\n"
"doch er ist noch immer\n"
"nicht zurück!" BOX_BREAK UNSKIPPABLE "So ist es fast jeden Tag!\n"
"Ich habe die ganze Arbeit\n"
"am Hals!" TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seufz... Man hat es nicht leicht\n"
"als rechtschaffener Arbeiter."
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wow! Deine Kleidung...\n"
"Wo trägt man denn sowas...\n"
"Du scheinst nicht von hier zu \n"
"sein, oder?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Woher..." TEXT_SPEED("\x00") " kommst Du?" BOX_BREAK UNSKIPPABLE "Oh, Du bist ein Feen-Junge aus \n"
"dem Wald! Ich bin " COLOR(RED) "Malon" COLOR(DEFAULT) ".\n"
"Meinem Vater gehört die \n"
"Lon Lon-Farm!" TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vater ist zum Schloß gegangen,\n"
"um dort Milch abzuliefern, doch\n"
"bisher kam er nicht zurück..."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Gehst Du zufällig auch zum\n"
"Schloß? Wenn ja, tust Du mir einen \n"
"Gefallen? Würdest Du dort meinen\n"
COLOR(RED) "Vater" COLOR(DEFAULT) " für mich suchen?" BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "Sicher ist er eingeschlafen \n"
"und macht irgendwo ein Nickerchen! \n"
"Es ist immer das gleiche mit ihm!" BOX_BREAK UNSKIPPABLE "Ach, wenn Du ihn suchst, nimm \n"
"dies hier an Dich!" BOX_BREAK UNSKIPPABLE "Bewahre es warm und sorgsam auf,\n"
"Du wirst es gebrauchen können...\n"
"Hihihi..." EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lege das Ei auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um es \n"
"einzusetzen!" BOX_BREAK "Für einen Erwachsenen ist mein \n"
"Vater ganz schön anstrengend, \n"
"oder? Hihihi..."
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Manchmal glaube ich einfach nicht,\n"
"daß ich, " COLOR(RED) "der fantastische Basil" COLOR(DEFAULT) ", \n"
"auf einer dämlichen Farm wie \n"
"dieser arbeite!" BOX_BREAK UNSKIPPABLE "Weil der Farmbesitzer ein\n"
"Faulpelz ist, muß ich die \n"
"gesamte Arbeit erledigen!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich, " COLOR(RED) "der einzigartige Basil" COLOR(DEFAULT) ", sollte \n"
"diese Farm leiten und nicht der \n"
"faule Talon!"
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, der Junge aus dem Wald!" BOX_BREAK "Ich hörte, Du hast meinen Vater \n"
"gefunden! Wie hat Dir das Schloß \n"
"gefallen? Und die Prinzessin? Hast \n"
"Du sie gesehen? Hihihi..." BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "Daddy hatte es ganz schön eilig,\n"
"nachdem Du ihn geweckt hast..." BOX_BREAK UNSKIPPABLE "Oh, ich muß Dir jemanden \n"
"vorstellen, Feen-Junge!" BOX_BREAK UNSKIPPABLE "Das Pferd hier heißt\n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". Süß, nicht wahr?"
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wie es scheint, hat Epona Angst \n"
"vor Dir..."
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dieses Lied hat meine Mutter \n"
"geschrieben. Es ist wunderschön. \n"
"Laß es uns zusammen singen!"
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Epona! Sie hat an Dir Gefallen\n"
"gefunden, Feen-Junge."
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "S C H N A R C H..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh... Ein Besucher!\n"
"Es ist lange her, seit wir Besuch \n"
"hier hatten...\n"
"Wo kommst Du her?" BOX_BREAK "Seit Ganondorf hier sein Unwesen\n"
"treibt, sind die Menschen auf der\n"
"Flucht, die einstigen Städte Ruinen,\n"
"und überall lauern böse Kreaturen." BOX_BREAK "Basil hat die Farm im Namen von\n"
"Ganondorf übernommen..." BOX_BREAK "Jeder scheint vom Bösen besessen." BOX_BREAK "Und Vater...\n"
"Er wurde von Basil von der Farm\n"
"verbannt..." BOX_BREAK "Falls ich Basil nicht gehorche,\n"
"hat er gedroht, die Pferde zu\n"
"quälen..." BOX_BREAK "Du siehst...\n"
"Es gibt nichts, was ich tun kann..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wette, es gibt niemanden, der\n"
"schneller als ich laufen kann... \n"
"Das Problem dabei ist nur, daß\n"
"ich nicht aufhören kann, zu laufen."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Zzzzzzzz..." TEXT_SPEED("\x00") "\n"
"Ruhe... ich... muß...\n"
"Kühe... Hühner..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Richte Deine Augen gen Osten.\n"
"Dies ist der " COLOR(RED) "Todesberg" COLOR(DEFAULT) ", das\n"
"Reich der Goronen. Sie hüten \n"
"den Heiligen Stein des Feuers."
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bitte erzähl Basil nicht, daß \n"
"ich dieses Lied singe..."
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du...\n"
"Du kennst das Lied " COLOR(RED) "meiner Mutter" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Alle haben dieses Lied geliebt...\n"
"Mein Vater... Sogar Basil..." BOX_BREAK UNSKIPPABLE "Doch seit Ganondorf aufgetaucht \n"
"ist, hat sich Basil völlig verändert." BOX_BREAK UNSKIPPABLE "Wenn ich es singe und die Augen \n"
"dabei schließe, denke ich an\n"
"vergangene Zeiten..." TEXTID("\x20\x52")
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Auch" COLOR(RED) " Epona" COLOR(DEFAULT) " liebte dieses Lied.\n"
"Damit konnte ich sie zähmen.\n"
"Basil ist dies nie gelungen..." BOX_BREAK "Hihihi..."
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Die steinerne Statue scheint Dir \n"
"etwas sagen zu wollen..."
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Da Du nun die Maske trägst,\n"
"beginnt die Statue mit Dir zu  \n"
"sprechen..." BOX_BREAK "Höre ihre Worte..."
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Von nun an werde ich jeden Tag\n"
"hart arbeiten. Das habe ich Malon\n"
"versprochen!"
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Basil... Mir scheint, er war von\n"
"bösen Mächten besessen.\n"
"Im Grunde ist er ein gutmütiger \n"
"Mensch."
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"S C H N A R C H...\n"
"Grummel... Wie schön, daß mir\n"
"Talon vergeben hat..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist lange her...\n"
"Lust auf ein Rennen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Falls Du Deine Meinung änderst,\n"
"kannst Du jederzeit zurückkommen!"
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na gut, dann verschwinde hier,\n"
"Du grüner Wichtel!" EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du bist sauer, weil Du verloren\n"
"hast? Kein Problem, wie wäre\n"
"es mit einem weiteren Rennen?" BOX_BREAK "Setze " COLOR(RED) "50 Rubine " COLOR(DEFAULT) "und versuch's \n"
"nochmal!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Farm dankt, hehehe..." EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn ich Dir noch mehr umsonst\n"
"gebe, wird Basil ziemlich sauer\n"
"werden. Deshalb verkaufe ich sie\n"
"Dir zum regulären Preis."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Möchtest für " COLOR(RED) "30 Rubine " COLOR(DEFAULT) "Milch\n"
"kaufen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallo! Wie geht's Dir?\n"
"Sorry, wenn ich in letzter Zeit\n"
"etwas merkwürdig war. Fühl Dich\n"
"hier wie zu Hause!"
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Du tapferer Jüngling...\n"
"Wir müssen Hyrule vor der \n"
"drohenden Apokalypse bewahren!"
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, eine hübsche Okarina!\n"
"Wirst Du das Lied auf der \n"
"Okarina spielen?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Am Fuße des Todesberges wirst\n"
"Du" COLOR(RED) " Kakariko " COLOR(DEFAULT) "finden. Es ist die \n"
"Stadt, die ich gegründet habe, um\n"
"Verfolgten Obdach zu bieten." BOX_BREAK UNSKIPPABLE "Bevor Du zum Berg aufbrichst, \n"
"solltest Du Dich mit einigen\n"
"Bewohnern unterhalten."
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das Lied, das ich Dich gelehrt\n"
"habe, besitzt geheimnisvolle Kräfte.\n"
"Nur Angehörige der Königsfamilie\n"
"dürfen es erlernen und spielen." BOX_BREAK UNSKIPPABLE "Vergiß nicht: Du kannst damit\n"
"beweisen, daß Du in königlicher\n"
"Mission unterwegs bist." BOX_BREAK UNSKIPPABLE "Geh nun, die Prinzessin und ich \n"
"warten auf Dich und die Heiligen\n"
"Steine im Schloß! Enttäusche uns\n"
"nicht!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Sei willkommen!" QUICKTEXT_DISABLE "\n"
"Bist Du bereit, " NAME "?" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Es scheint, daß nun die Zeit \n"
"gekommen ist, da Dein Abenteuer \n"
"beginnen soll." BOX_BREAK UNSKIPPABLE "Das, was hinter Dir liegt, war\n"
"ein Spaziergang im Vergleich zu\n"
"dem, was Dich erwartet... Doch sei\n"
"tapfer und verliere nie den Mut!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Folgst Du diesem Weg, so \n"
"gelangst Du zum " COLOR(RED) "Schloß von Hyrule" COLOR(DEFAULT) ".\n"
"Dort sei es Dir bestimmt, die \n"
COLOR(RED) "Prinzessin" COLOR(DEFAULT) " zu treffen..." BOX_BREAK "Weichst Du ab von Deinen Pfaden, \n"
"und wandelst auf unbekannten \n"
"Wegen, so nutze Deine" COLOR(RED) " Karte" COLOR(DEFAULT) "." BOX_BREAK "Die Orte, die Du bereits erforscht\n"
"hast, mögen wie von Geisterhand\n"
"in Deine Karte gezeichnet werden." BOX_BREAK "Drücke " COLOR(RED) "START" COLOR(DEFAULT) ", um ins Menü zu \n"
"gelangen, und " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " oder " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ", um den \n"
COLOR(RED) "Karten-Bildschirm" COLOR(DEFAULT) " einsehen zu \n"
"können." BOX_BREAK "Auf dem " COLOR(RED) "Karten-Bildschirm" COLOR(DEFAULT) " findest\n"
"Du außerdem einen " COLOR(RED) "Hinweis" COLOR(DEFAULT) ", welchen\n"
"Ort Du als nächsten aufsuchen \n"
"solltest." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hast Du alles verstanden?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Nein!\n"
"Ja!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "So sei es! Setze Deinen Weg nun \n"
"fort! Wir sehen uns wieder..."
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! Hier entlang!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Die Prinzessin befindet sich \n"
"im Schloß! Doch hüte Dich vor den \n"
"Wachen. Sie dürfen Dich nicht\n"
"sehen..." EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wisse, hier auf diesem Grund, \n"
"nimmt die Zeit ihren gewohnten \n"
"Lauf..." BOX_BREAK "Besuchst Du jedoch eine Stadt \n"
"oder die Ranch, steht die Zeit still." BOX_BREAK "Wenn Du möchtest, daß die \n"
"Tageszeit sich ändert, mußt Du die \n"
"Stadt verlassen und zu späterer \n"
"Stunde wiederkehren..." BOX_BREAK "Geh nun und hüte Dich vor den \n"
"Wachen..." EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Muß ich meine Worte wiederholen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du scheinst die Gabe der\n"
"Weisheit zu besitzen...\n"
"Viel Glück..."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sei willkommen, " NAME "! \n"
"Halte ein, mein Freund!" BOX_BREAK "Du befindest Dich vor den Toren \n"
COLOR(RED) "Kakarikos" COLOR(DEFAULT) ". Hast Du die Prinzessin \n"
"bereits besucht? Wenn nicht, so \n"
"rate ich Dir, sie aufzusuchen." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sei gegrüßt, " NAME "! \n"
"Schau hierher!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Du befindest Dich vor den Toren \n"
COLOR(RED) "Kakarikos" COLOR(DEFAULT) ". Die Treppen führen\n"
"Dich in die Stadt!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! Nur Du hast die\n"
"Macht, den Lauf des Schicksals zu\n"
"ändern!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "! Ich habe Dich \n"
"erwartet! Wohin werden Dich Deine\n"
"Schritte als nächstes lenken?" BOX_BREAK_DELAYED("\x28") "Begibst Du Dich gen Süden, so \n"
"kannst Du dort die ruhigen \n"
"Wasser des " COLOR(RED) "Hylia-Sees" COLOR(DEFAULT) " erkunden." BOX_BREAK "Im Westen hingegen liegt das \n"
COLOR(RED) "Gerudotal" COLOR(DEFAULT) ". Auf der anderen Seite\n"
"dieses Tales befindet sich die \n"
"Gerudo-Festung." BOX_BREAK "Welchen Weg Du auch immer wählst,\n"
"die Macht des Triforce möge Dich\n"
"begleiten!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Was auch immer das Schicksal Dir \n"
"bescheren mag, laß Dich niemals \n"
"entmutigen..."
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vor Dir liegt der Hylia-See.\n"
"Sein Wasser ist rein und klar..." BOX_BREAK_DELAYED("\x28") "Die " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", die im Osten des Landes\n"
"leben, sind die Hüter des Tempels,\n"
"der sich auf dem Grund des Sees\n"
"befindet..." BOX_BREAK "Willst Du Dir den Ort auf Deiner\n"
"Karte betrachten, so drücke \n"
COLOR(RED) "START" COLOR(DEFAULT) " und begib Dich mit" COLOR(RED) " " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"oder " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " zum " COLOR(BLUE) "Karten-Bildschirm" COLOR(DEFAULT) "." BOX_BREAK "Alle Orte, an denen Du schon \n"
"einmal warst, werden Dir auf der\n"
"Karte angezeigt..." EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Geh nun!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wie lautet Dein Name?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "Ich fühle etwas..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Seltsam... Er kommt mir so... \n"
"vertraut vor." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "So sei es, " NAME "..." BOX_BREAK UNSKIPPABLE "Ich werde Dich nun in das\n"
"Geheimnis des Heiligen Reiches\n"
"einweihen, das seit Generationen\n"
"von meiner Familie gehütet wird." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x23") "Die Okarina der Zeit!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hast Du die Geschichte, die ich\n"
"Dir anvertraute, verstanden?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ich habe gerade durch dieses\n"
"Fenster hier geschaut..." BOX_BREAK UNSKIPPABLE "Eines der Elemente aus meinem\n"
"Traum... Die" COLOR(BLUE) " dunklen Wolken" COLOR(DEFAULT) "...\n"
"Ich glaube, sie symbolisieren...\n"
"...diesen Mann dort!" BOX_BREAK "Möchtest Du ihn Dir anschauen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "Ich weiß..." TEXT_SPEED("\x00") " Er ist es!" BOX_BREAK UNSKIPPABLE "Natürlich erzählte ich meinem Vater \n"
"von dem Traum." BOX_BREAK UNSKIPPABLE "Doch er glaubte mir nicht, daß der\n"
"Traum eine Prophezeiung sei!" BOX_BREAK UNSKIPPABLE "Doch glaube mir... Ich spüre die \n"
"böse Aura dieses Mannes!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf hat es auf nichts\n"
"anderes als das " COLOR(RED) "Triforce" COLOR(DEFAULT) " des \n"
"Heiligen Reiches abgesehen..." BOX_BREAK UNSKIPPABLE "Nur das scheint sein Begehr!" BOX_BREAK UNSKIPPABLE "Um sein Ziel zu erreichen, muß\n"
"er Hyrule, nein, die gesamte Welt\n"
"unterwerfen!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "... Wir sind die \n"
"einzigen, die Ganondorfs Pläne\n"
"durchkreuzen können!" EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Wir müssen verhindern, daß \n"
"Ganondorf in den Besitz des\n"
"Triforce gelangt!" BOX_BREAK UNSKIPPABLE "Ich werde die " COLOR(LIGHTBLUE) "Okarina der Zeit\n"
COLOR(DEFAULT) "mit all meiner Kraft schützen! \n"
"Niemals soll er sie erhalten!" BOX_BREAK UNSKIPPABLE "Deine Aufgabe sei es, die\n"
"verbliebenen Heiligen Steine zu\n"
"finden! Sie sind der Schlüssel zum\n"
"Heiligen Reich..." BOX_BREAK UNSKIPPABLE "Laß uns das Triforce suchen und\n"
"mit dessen Kraft Ganondorf \n"
"bezwingen!" EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eines noch...\n"
"Nimm diesen " COLOR(RED) "Brief " COLOR(DEFAULT) "an Dich.\n"
"Ich bin sicher, Du wirst ihn \n"
"brauchen können..." EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Gähn...\n"
"Was?! Bin ich schon wach?" BOX_BREAK UNSKIPPABLE "Es scheint so..." BOX_BREAK UNSKIPPABLE "Hey, wenn das nicht der Junge\n"
"aus den Wäldern ist!\n"
"Vielen Dank nochmal, daß Du\n"
"mich geweckt hast!" BOX_BREAK UNSKIPPABLE "Es hat ganz schön lange gedauert, \n"
"bis ich Malon beruhigt hatte." BOX_BREAK UNSKIPPABLE "Was hast Du denn heute so vor?\n"
"Nichts besonderes? Nun, wie wäre\n"
"es dann mit einem kleinen\n"
"Spielchen? Hast Du Lust?" BOX_BREAK UNSKIPPABLE "Die drei Hühner hier sind\n"
COLOR(RED) "Super-Hühner" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ich werde sie nun mit den\n"
"anderen, herkömmlichen Hühnern\n"
"vermischen..." BOX_BREAK UNSKIPPABLE "Gelingt es Dir, sie innerhalb einer\n"
"bestimmten Zeit aus allen anderen \n"
"herauszupicken, werde ich Dich\n"
"mit " COLOR(RED) "etwas Nützlichem " COLOR(DEFAULT) "belohnen!" BOX_BREAK "Ein Spiel kostet 10 Rubine!\n"
"Machst Du mit?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gähn...\n"
"Schon gut... Ich bin ja wach!" BOX_BREAK "Was?!" BOX_BREAK "Hey, der Kokiri-Junge!\n"
"Hast Du ein bißchen Zeit?\n"
"Dann laß uns spielen!" BOX_BREAK "Ich vermische diese drei " COLOR(RED) "Super-\n"
"Hühner" COLOR(DEFAULT) " mit den herkömmlichen \n"
"Hühnern..." BOX_BREAK "Gelingt es Dir, sie innnerhalb einer \n"
"bestimmten Zeit aus allen anderen\n"
"Hühnern herauszupicken, belohne \n"
"ich Dich mit " COLOR(RED) "etwas Nützlichem" COLOR(DEFAULT) "!" BOX_BREAK "Ein Spiel kostet 10 Rubine!\n"
"Willst Du es versuchen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast 30 Sekunden!\n"
"Jetzt geht's los!\n"
"Hier sind die Super-Hühner!" BOX_BREAK SHIFT("\x42") "FINDE SIE!" EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Die Zeit ist um!\n"
"Oh, wie schade!" BOX_BREAK "Die Super-Hühner sind genial!\n"
"Jetzt bringen sie mir sogar noch\n"
"Geld ein!" BOX_BREAK "Kommt zu Daddy, ihr Süßen!" EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist eins von ihnen!\n"
"Such weiter! Schnell!\n"
COLOR(RED) "Zwei" COLOR(DEFAULT) " mußt Du noch finden!" EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wieder eins!\n"
"Jetzt kommt's drauf an! " COLOR(RED) "Eins" COLOR(DEFAULT) "\n"
"fehlt noch!!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Unglaublich!\n"
"Du hast ein gutes Gespür!" BOX_BREAK "Du hast sie tatsächlich\n"
"alle gefunden!\n"
"Komm her zu mir!" EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du es nochmal versuchen?\n"
"Ein junger Kerl wie Du hat doch\n"
"sicher Hummeln im Hintern!" BOX_BREAK "Du mußt nur in 30 Sekunden \n"
"die richtigen drei Hühner finden." BOX_BREAK "Willst Du es für 5 Rubine\n"
"versuchen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Junge!\n"
"Du hast das Zeug dazu, ein \n"
"verdammt guter Farmer zu \n"
"werden!" BOX_BREAK "Ich würde mich freuen, wenn Du \n"
"Malon heiraten würdest! Na?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hahaha, war doch nur Spaß!" BOX_BREAK UNSKIPPABLE "Oh, hier, nimm diese Flasche\n"
COLOR(RED) "Lon Lon-Milch " COLOR(DEFAULT) "an Dich. Sie gibt \n"
"Dir neue Energie, sobald Du sie \n"
"trinkst!" BOX_BREAK UNSKIPPABLE "Hast Du die " COLOR(RED) "Flasche" COLOR(DEFAULT) " geleert,\n"
"kannst Du jederzeit zurückkommen\n"
"und sie Dir gegen ein geringes\n"
"Entgelt auffüllen lassen!" EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey Partner, Du bist echt in \n"
"Ordnung!" BOX_BREAK "Wenn Du einmal erwachsen bist, \n"
"könntest Du auf der Farm \n"
"arbeiten...\n"
"Wir warten auf Dich!" EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hier, nimm diese leckere\n"
COLOR(RED) "Lon Lon-Milch " COLOR(DEFAULT) "an Dich!" EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hier! Nimm etwas von der\n"
"frischen Milch..." BOX_BREAK "Oh? Schade...\n"
"Du hast leider keine leere\n"
"Flasche, oder?"
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gähn...\n"
"Ich bin wach!" BOX_BREAK "Was?" BOX_BREAK "Hey, " NAME "!\n"
"Wenn Du Malon suchst, die ist\n"
"draußen! Oder bist Du zum \n"
"Spielen hergekommen?" BOX_BREAK "Dann laß uns " COLOR(RED) "Super-Huhn-Suchen \n"
COLOR(DEFAULT) "spielen!" COLOR(RED) " " COLOR(DEFAULT) "Oder willst Du nur \n"
"frische " COLOR(RED) "Lon Lon-Milch" COLOR(DEFAULT) "?" BOX_BREAK "Was darf es sein?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Lon Lon-Milch - 30 Rubine\n"
"Super-Huhn-Suchen - 10 Rubine\n"
"Zurück" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Du hast verloren!" COLOR(DEFAULT) "\n"
"Du hättest über alle Hindernisse\n"
"springen müssen!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Eine Runde noch!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du mußt auf die Hindernisse \n"
"frontal zureiten. Ist der Winkel zu \n"
"spitz, verweigert das Pferd!" BOX_BREAK "Wenn Du es erneut versuchen \n"
"möchtest, steig auf und mach Dich \n"
"bereit!"
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast es geschafft!\n"
COLOR(RED)  RACE_TIME  COLOR(DEFAULT) " ist neuer Parcours-Rekord!" BOX_BREAK UNSKIPPABLE "Für diese herausragende Leistung \n"
"gebührt Dir eine Belohnung!" BOX_BREAK UNSKIPPABLE "Mein Präsent ist ein bißchen zu\n"
"unhandlich, um es Dir hier geben zu\n"
"können. Deshalb hab ich es direkt\n"
"in Dein Haus liefern lassen! Hihihi..."
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der bisherige Rekord beträgt \n"
COLOR(RED) "50 Sekunden" COLOR(DEFAULT) ".\n"
"Deine Bestzeit ist " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "." BOX_BREAK "Gelingt es Dir, den Rekord zu \n"
"brechen, bekommst Du ein \n"
"Geschenk von mir!\n"
"Also, gib Dein Bestes!" BOX_BREAK "Los geht's!" EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Deine Bestzeit beträgt " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "!\n"
"Kannst Du das noch unterbieten?\n"
"Komm schon, versuch es!" EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der bisherige Rekord beträgt\n"
COLOR(RED) "50 Sekunden" COLOR(DEFAULT) ". Brichst Du ihn, \n"
"erhältst Du mein Geschenk!" BOX_BREAK "Also, streng Dich an und gib\n"
"alles!" BOX_BREAK "Okay, es geht los!!" EVENT
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
UNSKIPPABLE "Eine große Ehre, Blutsbrüderschaft\n"
"mit einem Goronen zu schließen... \n"
"Du besitzt nun zwei Heilige Steine!\n"
"Suche nach dem Dritten!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eine große Ehre, Blutsbrüderschaft \n"
"mit einem Goronen zu schließen... \n"
"Du besitzt nun alle Heiligen Steine!\n"
"Suche Prinzessin Zelda auf!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallo... Das habe ich gegen das\n"
COLOR(RED) "Zertifikat" COLOR(DEFAULT) " eingetauscht..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich gebe es Dir als Geschenk..."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich mag Dich, Kleiner!" BOX_BREAK UNSKIPPABLE "Was hältst Du davon, wenn Du \n"
"und ich Blutsbrüder werden?!" BOX_BREAK UNSKIPPABLE "Keine Angst, keine große Feier!\n"
"Nimm dies als Zeichen meiner\n"
"Freundschaft an Dich!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x16") "Meine Hochachtung!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Laß mich Dich in die Arme \n"
"schließen, Bruder!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x51") "Oh..." BOX_BREAK_DELAYED("\x1E")  SHIFT("\x51") "Wow!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3F")  QUICKTEXT_ENABLE "Das groovt!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x2E") "Yeah! Yeah! " QUICKTEXT_ENABLE "Yeah!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x34")  QUICKTEXT_ENABLE "Ein heißer Beat!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x4B") "Groovy!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3E") "Let's dance!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x46")  QUICKTEXT_ENABLE "YEEEEAH!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x44")  QUICKTEXT_ENABLE "YAHOOO!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich bin ein " COLOR(RED) "Gorone" COLOR(DEFAULT) ", wir sind\n"
"Steinfresser und leben auf dem\n"
"Todesberg." BOX_BREAK UNSKIPPABLE "Siehst Du den riesigen Fels\n"
"dort drüben?" BOX_BREAK UNSKIPPABLE "Er versperrt den Eingang zu\n"
COLOR(RED) "Dodongos Höhle" COLOR(DEFAULT) ". Die Höhle ist für\n"
"uns Goronen sehr wichtig, denn\n"
"dort lagert unsere Nahrung..." BOX_BREAK UNSKIPPABLE "Vor kurzem sind einige Dodongos\n"
"in der Höhle aufgetaucht. Seither  \n"
"war die Höhle für uns ein äußerst\n"
"gefährlicher Ort!" BOX_BREAK UNSKIPPABLE "Über dem Eingang der Höhle\n"
"sah ich einen " COLOR(RED) "Gerudo in schwarzer\n"
"Rüstung" COLOR(DEFAULT) ", der den Fels mit magischer\n"
"Kraft vor dem Eingang plazierte!" TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wünschte, ich könnte den \n"
"Eingang zu Dodongos Höhle\n"
"rechtzeitig mit einer " COLOR(RED) "Donnerblume\n"
COLOR(DEFAULT) "erreichen! Und..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x44")  COLOR(RED) "...BUMMS..." COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK "...wäre der Höhleneingang wieder\n"
"frei und ich ein gefeierter Held!"
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich stehe hier, um den\n"
COLOR(RED) "Donnerblumen " COLOR(DEFAULT) "Schatten zu\n"
"spenden." BOX_BREAK "Möchtest Du mich etwas \n"
"fragen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Über die Donnerblumen\n"
"Über Dodongos Höhle" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Blumen, die dort wachsen, sind \n"
COLOR(RED) "Donnerblumen" COLOR(DEFAULT) ". Es sind explosive\n"
"Höhlenpflanzen, die nur auf diesem\n"
"Berg wachsen." BOX_BREAK "Die Blüte der Blume dient als \n"
"Material zur Bombenherstellung." BOX_BREAK "Jemand, der die Blumen nicht \n"
"kennt, sollte sich davor hüten, sie\n"
"zu pflücken!" BOX_BREAK "Normalerweise wachsen sie nur in \n"
"dunklen Höhlen. Daher ist \n"
"dieses Exemplar hier\n"
"sehr selten."
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Blumen, die dort wachsen, sind \n"
COLOR(RED) "Donnerblumen" COLOR(DEFAULT) ". Es sind explosive\n"
"Höhlenpflanzen, die nur auf diesem\n"
"Berg wachsen." BOX_BREAK "Normalerweise wachsen sie nur in \n"
"dunklen Höhlen. Daher ist \n"
"dieses Exemplar hier\n"
"sehr selten." BOX_BREAK "Mit einem " COLOR(RED) "Goronen-Armband " COLOR(DEFAULT) "könnte \n"
"selbst ein kleines Kind wie\n"
"Du die Blumen mit " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pflücken."
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ist Dir auf Deinem Weg hierher \n"
"die Höhle aufgefallen? Dies ist \n"
COLOR(RED) "Dodongos Höhle" COLOR(DEFAULT) "." BOX_BREAK "Weil es im Inneren nur wenig Licht \n"
"gibt, wachsen dort sehr viele\n"
COLOR(RED) "Donnerblumen" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nanu?" BOX_BREAK UNSKIPPABLE "Nur selten verirren sich Leute\n"
"hierher! Woher kommst Du?" BOX_BREAK UNSKIPPABLE "Aus dem Wald?" BOX_BREAK UNSKIPPABLE "Was ist das, \"Wald\"?" BOX_BREAK UNSKIPPABLE "Was?" BOX_BREAK UNSKIPPABLE "Dort wachsen \"Bäume\" und \n"
"\"Pflanzen\"?" BOX_BREAK UNSKIPPABLE "Das verwirrt mich... \n"
"Hier oben wächst außer den \n"
COLOR(RED) "Donnerblumen" COLOR(DEFAULT) " gar nichts..." BOX_BREAK UNSKIPPABLE "Wir haben hier auch weder\n"
"Deku-Kerne noch Deku-Nüsse." BOX_BREAK UNSKIPPABLE "Und selbst Deku-Stäbe findet man\n"
"hier höchst selten." TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich hatte den Eingang versiegelt,\n"
"da ich nicht sehr viel zu \n"
"verkaufen habe... Du aber scheinst\n"
"sehr hartnäckig zu sein. Nun gut." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tut mir leid... Die Bombe hier ist \n"
"nur eine Attrappe. Die echten \n"
"sind " COLOR(RED) "ausverkauft" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, warum hast Du mich \n"
"aufgehalten? Das mag ich gar \n"
"nicht!" BOX_BREAK "Ich war gerade so schön in Fahrt!" BOX_BREAK "Auf diese Weise kann man \n"
"wunderbar Streß abbauen!" BOX_BREAK "Laß mich jetzt weiterrollen!\n"
"Rock'n'Roll!"
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du bist mutig! Das soll belohnt \n"
"werden! Nimm dies als Zeichen \n"
"meiner Anerkennung!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hab Dank! An meinem Downhill-Roll \n"
"kannst Du erkennen, wie sehr ich \n"
"mich freue!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x21") "Oh... Ich bin so hungrig..." BOX_BREAK UNSKIPPABLE "Jeder hier muß Hunger leiden,\n"
"weil der Eingang zur Höhle \n"
"verschlossen ist. Wir sind vom  \n"
"Aussterben bedroht!" BOX_BREAK UNSKIPPABLE "Wenn es nur eine Möglichkeit\n"
"gäbe," COLOR(RED) " Dodongos Höhle " COLOR(DEFAULT) "zu öffnen." BOX_BREAK UNSKIPPABLE "Seit Wochen ist sie verschüttet.\n"
"Es ist so tragisch..." BOX_BREAK UNSKIPPABLE "In der Höhle lagern die besten \n"
"und köstlichsten Steinvorräte. \n"
"Doch wie es scheint, müssen wir \n"
"nun auf diesen Genuß verzichten." BOX_BREAK UNSKIPPABLE "Dabei sind wir Goronen \n"
"Feinschmecker, die sich nur\n"
"schwerlich an andere Nahrung\n"
"gewöhnen können!" TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seufz... Wie gern würde ich jetzt \n"
"ein Stück Steinfilet aus " COLOR(RED) "Dodongos\n"
"Höhle " COLOR(DEFAULT) "genießen..."
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey!" BOX_BREAK UNSKIPPABLE "Ein kleines Kind wie Du muß \n"
"einen guten Grund haben, um \n"
"diesen Ort aufzusuchen!" BOX_BREAK UNSKIPPABLE "Ich hatte also recht! Du bist\n"
"hier, um den " COLOR(RED) "Roten Stein" COLOR(DEFAULT) " zu \n"
"fressen! Nun, da kommst Du zu \n"
"spät! Er ist fort!" BOX_BREAK UNSKIPPABLE "Was? Das ist gar nicht der \n"
"Grund, der Dich herführte?" BOX_BREAK UNSKIPPABLE "Du suchst einen Heiligen\n"
"Stein? Damit mußt Du den \n"
"leckeren Roten Stein meinen, der\n"
"vor kurzem noch hier lag!" BOX_BREAK UNSKIPPABLE "Ich war so hungrig, daß ich \n"
"dachte, es wäre in Ordnung, nur \n"
"ein kleines Stückchen davon zu \n"
"essen. Als ich kam, war er fort!" BOX_BREAK UNSKIPPABLE "Vielleicht hat ihn Darunia\n"
"weggenommen..." BOX_BREAK UNSKIPPABLE "Er sagte, es gefällt ihm nicht, daß\n"
"alle immer so gierig schauen,\n"
"wenn sie den Roten Stein \n"
"betrachten." TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Darunia hat sich in seinem Raum\n"
"eingeschlossen. Er sprach:\n"
"\"" COLOR(RED) "Ich werde hier auf den Boten \n"
"der Königsfamilie warten!" COLOR(DEFAULT) "\""
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich bin so hungrig, ich kann an \n"
"nichts anderes mehr denken..." BOX_BREAK UNSKIPPABLE "Suche Darunia auf, um Antwort\n"
"auf Deine Fragen zu finden." BOX_BREAK UNSKIPPABLE "Zur Zeit ist er sehr schlecht \n"
"gelaunt... Dann kann er sehr \n"
"abweisend sein..." BOX_BREAK UNSKIPPABLE "Doch ich weiß, wie man ihn\n"
"aufheitern kann..." BOX_BREAK UNSKIPPABLE "Er mag zwar nicht so aussehen,\n"
"doch er liebt Musik! Wann immer \n"
"er ein Lied hört, muß er tanzen..." TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich kann mich erinnern, daß\n"
"Darunia besonders die " COLOR(ADJUSTABLE) "Musik\n"
"des Waldes " COLOR(DEFAULT) "mochte..." BOX_BREAK "Das waren noch Zeiten...\n"
"Die Musik weckt in mir \n"
"Erinnerungen an vergangene Tage..." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Was?! Wer bist Du?!" BOX_BREAK UNSKIPPABLE "Als ich " COLOR(BLUE) "das Lied der Königsfamilie\n"
COLOR(DEFAULT) "hörte, dachte ich, ein Abgesandter \n"
"sei eingetroffen...\n"
"Stattdessen sehe ich ein Kind!" BOX_BREAK UNSKIPPABLE "Hat " COLOR(RED) "Darunia" COLOR(DEFAULT) ", der Führer der \n"
"Goronen, es wirklich verdient,\n"
"so behandelt zu werden?" BOX_BREAK UNSKIPPABLE "Ich kann es nicht glauben!\n"
"Geh zurück ins Schloß und sag\n"
"dem König, er solle mir einen\n"
"richtigen Mann schicken!" BOX_BREAK UNSKIPPABLE "Du fragst, warum ich so schlecht\n"
"gelaunt bin?" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Dämonische Kreaturen sind in \n"
"Dodongos Höhle eingedrungen..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Die Donnerblumen-Ernte war\n"
"schlecht..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Und zudem leidet mein Volk\n"
"Hunger..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x1C") "Doch wie dem auch sei..." TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Dies ist Sache der Goronen!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0B") "Wir sind zu stolz, um die Hilfe\n"
SHIFT("\x06") "Fremder in Anspruch zu nehmen!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x27") "Wow! Cooler Sound!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Meine schlechte Laune ist \n"
"verflogen! Ich konnte mich nicht\n"
"mehr halten, ich mußte einfach \n"
"tanzen!" BOX_BREAK UNSKIPPABLE  SHIFT("\x3C") "Ich bin " COLOR(RED) "Darunia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ich bin der Anführer der Goronen!\n"
"Gibt es etwas, das ich für Dich\n"
"tun kann?" BOX_BREAK UNSKIPPABLE  SHIFT("\x50") "Wie?" BOX_BREAK UNSKIPPABLE "Du suchst den " COLOR(RED) "Heiligen Stein\n"
"des Feuers" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Der Heilige Stein des Feuers, auch \n"
"als Goronen-Opal bekannt, ist das \n"
"wertvollste Relikt meines Volkes..." BOX_BREAK UNSKIPPABLE "Ich kann ihn Dir erst geben, \n"
"wenn Du meinem Volk beweist, \n"
"daß Du seiner würdig bist..." BOX_BREAK UNSKIPPABLE "Beweise Dich, indem Du die \n"
"Kreaturen in Dodongos Höhle \n"
"vertreibst!" BOX_BREAK UNSKIPPABLE "Bestehst Du diese Prüfung, ist  \n"
"Dir der Dank meines Volkes gewiß.\n"
"Der Lohn für Deine Mühe soll der\n"
"Heilige Stein sein!" BOX_BREAK UNSKIPPABLE "Bevor Du gehst, nimm dies\n"
"an Dich. Es ist ein Gastgeschenk\n"
"der Goronen, ein Zeichen der\n"
"Freundschaft." BOX_BREAK UNSKIPPABLE "Trägst Du es, kannst sogar Du \n"
"schwere Dinge wie " COLOR(RED) "Donnerblumen" COLOR(DEFAULT) " \n"
"mit" COLOR(RED) " " COLOR(BLUE) "[A] " COLOR(DEFAULT) "heben."
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vernichte die Kreaturen in \n"
COLOR(RED) "Dodongos Höhle " COLOR(DEFAULT) "und beweise, daß \n"
"Du meiner Freundschaft würdig \n"
"bist! Denk an den Heiligen Stein!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Bruder! Komm mal wieder\n"
"vorbei und spiele ein paar Lieder!"
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Egal, wie oft ich dieses Lied höre, \n"
"es wird nie langweilig!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hmmm, ganz gut... Aber nicht\n"
"genau das, was ich hören wollte..." BOX_BREAK "Ich mag Melodien... Wie soll ich \n"
"sagen... Von außerhalb... etwas\n"
"Natürliches... Grünes... aus dem \n"
"Wald..." BOX_BREAK "Das ist meine Art von Musik!"
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dank Deiner Hilfe können wir \n"
"wieder in die Höhle. Du bist ein \n"
"wahrer Held!"
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich verrate Dir etwas! Willst Du\n"
"einen brennenden Stab löschen, \n"
"so drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) ", bevor er ganz\n"
"abgebrannt ist!" BOX_BREAK "Apropos... Ich habe hier irgendwo\n"
"einen Stab versteckt..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin es, " COLOR(RED) "Darunia" COLOR(DEFAULT) "!\n"
"Du hast Deine Prüfung bestanden!" BOX_BREAK UNSKIPPABLE "Dank Deiner Hilfe können wir\n"
"nun wieder die schmackhaften\n"
"Steine aus der Höhle verspeisen!"
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe solchen Hunger, daß \n"
"ich nur ans Essen denken kann!" BOX_BREAK UNSKIPPABLE "Heiliger Stein?\n"
"Du meinst sicher den " COLOR(RED) "Roten Stein" COLOR(DEFAULT) ", \n"
"der einst in unserer Stadt\n"
"erstrahlte?" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Darunia" COLOR(DEFAULT) " nahm ihn an sich...\n"
"Danach schloß er sich in seinem\n"
"Raum ein und hat ihn seitdem\n"
"nicht mehr verlassen." BOX_BREAK UNSKIPPABLE "Seit dieser Zeit ist es dunkel\n"
"in Goronia. Die Dunkelheit macht\n"
"uns depressiv. Alles erscheint so \n"
"sinnlos..." TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wünschte, jemand würde die \n"
"Fackeln bei der Goronenstatue \n"
"entzünden. Ich glaube, in Darunias\n"
"Kammer findet man " COLOR(RED) "Feuer" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, ich verstehe...\n"
"Wir hätten die Bombe von der \n"
"Klippe aus werfen sollen..."
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast alle Dodongos vernichtet! \n"
"Das ist unglaublich! Laß mich Dich \n"
"Bruder nennen!"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Dank Deiner Bemühungen ist alles \n"
"wieder wie früher! Nun kann ich \n"
"Dir auch Bomben anbieten!" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sollte ich jemals ein Kind haben, \n"
"werde ich es nach Dir benennen!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Du schon hier bist, solltest\n"
"Du auch " COLOR(RED) "Goronia" COLOR(DEFAULT) " besuchen!" BOX_BREAK "Die Stadt liegt weiter oben auf\n"
"dem Berg. Es ist gar nicht mehr\n"
"weit bis dorthin."
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " nimmst Du die \n"
"Donnerblumen auf. Drückst Du \n"
"erneut " COLOR(BLUE) "[A]" COLOR(DEFAULT) ", legst Du sie wieder ab."
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Fackeln sind ein Symbol des\n"
"Lebens in Goronia. Würden sie\n"
"alle brennen, wäre es hier\n"
"sicher wieder schöner!"
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du hast vor, die Dodongos zu \n"
"vertreiben? Das ist Sache der \n"
"Goronen und keine Angelegenheit\n"
"für kleine Kinder!" BOX_BREAK "Andererseits wären wir froh, wenn \n"
"unser Problem gelöst würde. Dann \n"
"könnten wir endlich wieder Bomben \n"
"produzieren..." BOX_BREAK "Dennoch solltest Du Dich vor den\n"
"Dodongos hüten! Diese Kreaturen \n"
"fressen alles, was sich ihnen in \n"
"den Weg stellt!" BOX_BREAK "Wenn Du nicht aufpaßt, endest Du \n"
"im Magen eines Dodongo!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich hatte es Dir doch schon \n"
"gesagt! Bomben sind ausverkauft!\n"
"Wenn ich nur nicht solchen Hunger\n"
"hätte!" PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wie fühlt sich Darunia?\n"
"Oh, ich verstehe..." BOX_BREAK "Übrigens... Kennst Du die\n"
"Melodie, die durch diesen Tunnel\n"
"in unser Reich dringt? Wir mögen\n"
"sie sehr!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mich wirst Du nicht kriegen! \n"
"Sicher bist Du einer von \n"
"Ganondorfs Schergen!"
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wie konnte Dir das gelingen?\n"
"Du bist einer von Ganondorfs \n"
"Leuten..." BOX_BREAK UNSKIPPABLE "Höre meinen Namen und neige \n"
"Dein Haupt in Ehrfurcht!" BOX_BREAK UNSKIPPABLE "Ich bin " COLOR(RED)  NAME  COLOR(DEFAULT) "! \n"
"Der größte Krieger der Goronen!"
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Was?" BOX_BREAK UNSKIPPABLE "Auch Dein Name ist\n"
NAME "?" BOX_BREAK UNSKIPPABLE "Dann mußt Du der legendäre\n"
"Dodongo-Jäger sein, der mächtige \n"
NAME "!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Darunia " COLOR(DEFAULT) "ist mein Vater...\n"
"Kennst Du ihn?" BOX_BREAK UNSKIPPABLE "Er" COLOR(RED) " " COLOR(DEFAULT) "benannte mich nach Dir," COLOR(RED) "\n"
COLOR(DEFAULT) "weil Du tapfer bist und viel für\n"
"uns getan hast!" BOX_BREAK UNSKIPPABLE "Mir gefällt der Name!\n"
"Ich könnte mir keinen besseren \n"
"vorstellen!" BOX_BREAK UNSKIPPABLE  NAME ", für uns bist Du \n"
"ein echter Volksheld! \n"
"Ich bin stolz, Dich kennengelernt \n"
"zu haben!" BOX_BREAK UNSKIPPABLE "Gib mir bitte ein Autogramm!\n"
"Schreib:\n"
SHIFT("\x05") "\"Für meinen Freund \n"
SHIFT("\x05")  NAME ", den Goronen!\"" BOX_BREAK UNSKIPPABLE "Oh..." BOX_BREAK UNSKIPPABLE "Es mag ein schlechter Zeitpunkt \n"
"sein, Dich erneut um Hilfe zu \n"
"bitten, doch hör mich an..." BOX_BREAK UNSKIPPABLE "Mein Vater Darunia begab sich \n"
"zum " COLOR(RED) "Feuertempel" COLOR(DEFAULT) "! Dort lebt ein \n"
"Höllendrache!" BOX_BREAK UNSKIPPABLE "Wenn wir uns nicht beeilen,\n"
"ist mein Vater verloren!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heul... Schnüff... Daddy..." EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du solltest ihn beruhigen, wenn\n"
"Du kannst...\n"
"Am besten Du fragst ihn einfach \n"
"etwas!" BOX_BREAK "Worüber willst Du ihn befragen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Über den Drachen\n"
"Über die Goronen" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vor langer Zeit lebte eine\n"
"diabolische Kreatur namens \n"
COLOR(RED) "Volvagia " COLOR(DEFAULT) "in den Höhlen dieses \n"
"Berges." BOX_BREAK UNSKIPPABLE "Diese Drachenkreatur wütete\n"
"auf grausamste Art. Sie fraß \n"
"Goronen bei lebendigem Leib..." BOX_BREAK UNSKIPPABLE "Mit Hilfe eines legendären\n"
"Hammers gelang es schließlich,\n"
"Volvagia zu vernichten!" BOX_BREAK UNSKIPPABLE "So erzählt die Legende aus \n"
"vergangenen Zeiten.\n"
"Ich weiß, daß sie wahr ist!" BOX_BREAK UNSKIPPABLE "Einer der Vorfahren meines\n"
"Vaters war nämlich derjenige,\n"
"der die Kreatur vernichtete!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vater war gerade nicht hier, \n"
"als alle von Ganondorf in den" COLOR(RED) " \n"
"Feuertempel " COLOR(DEFAULT) "verschleppt wurden." BOX_BREAK UNSKIPPABLE "Es war schrecklich!\n"
"Ganondorfs Leute fielen in unsere\n"
"Stadt ein und nahmen alle \n"
"gefangen..." BOX_BREAK UNSKIPPABLE "Jetzt sollen sie " COLOR(RED) "Volvagia " COLOR(DEFAULT) "geopfert \n"
"werden!" BOX_BREAK UNSKIPPABLE "Vater sagte, daß Ganondorf die\n"
"Drachenkreatur wiedererweckt hat." BOX_BREAK UNSKIPPABLE "Als Warnung an alle, die sich\n"
"ihm widersetzen, will der Tyrann\n"
"die Goronen dem Drachen Volvagia \n"
"zum Fraß vorwerfen!" BOX_BREAK UNSKIPPABLE "Also brach Vater ganz allein\n"
"zum Tempel auf, um sie \n"
"zu befreien..." BOX_BREAK UNSKIPPABLE "Bitte hilf ihm, " NAME "!\n"
"Möge diese " COLOR(RED) "Goronen-Rüstung " COLOR(DEFAULT) "zum\n"
"Gelingen Deiner Mission beitragen!"
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vater sagte mir, ich solle nicht\n"
"zulassen, daß ihm irgendjemand \n"
"folgt..." BOX_BREAK UNSKIPPABLE "Doch bei Dir, " NAME ", ist\n"
"das etwas anderes! Ich bin mir \n"
"sicher, daß nur Du uns helfen \n"
"kannst!" BOX_BREAK UNSKIPPABLE "Sicher hilft Dir auch der \n"
"Ladenbesitzer weiter. Er hat sich\n"
"irgendwo versteckt..." BOX_BREAK UNSKIPPABLE "Laß mich Dir nun den geheimen\n"
"Pfad zum Feuertempel zeigen!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Versuche, die " COLOR(RED) "Statue " COLOR(DEFAULT) "in Vaters \n"
"Raum zu verschieben!"
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wer ist da? Bist Du es,\n"
NAME "?" BOX_BREAK UNSKIPPABLE "Tatsächlich! " NAME "!" BOX_BREAK UNSKIPPABLE "Du bist erwachsen geworden, ein\n"
"richtiger Mann!" BOX_BREAK UNSKIPPABLE "Gerne würde ich mich länger mit\n"
"Dir unterhalten, doch die Zeit \n"
"drängt..." BOX_BREAK UNSKIPPABLE "Erneut hat Ganondorf Chaos\n"
"gesät! Er hat die infernalische\n"
"Drachenkreatur Volvagia aus dem \n"
"Reich der Toten zurückgeholt!" BOX_BREAK UNSKIPPABLE "Zudem will er die gefangenen\n"
"Goronen der Bestie zum Fraß\n"
"vorwerfen. Als Warnung an alle,\n"
"die ihm trotzen..." BOX_BREAK UNSKIPPABLE "Wenn das feuerspeiende Ungetüm\n"
"aus den Höhlen des Tempels \n"
"entkommt, wird Hyrule in einem \n"
"flammenden Inferno versinken!" BOX_BREAK UNSKIPPABLE "Ich werde vorgehen und \n"
"versuchen, die Kreatur zu \n"
"bezwingen..." BOX_BREAK UNSKIPPABLE "Das wird nicht leicht, denn\n"
"mir fehlt die Waffe, die in der\n"
"alten Sage Erwähnung findet.\n"
"Doch mir bleibt keine Wahl..." BOX_BREAK UNSKIPPABLE  NAME "... Als Dein Bruder \n"
"bitte ich Dich um diesen Gefallen..." BOX_BREAK UNSKIPPABLE "Während ich die Bestie fordere,\n"
"sollst Du meine Leute retten!" BOX_BREAK UNSKIPPABLE "Die Zellen, in die man sie \n"
"gesperrt hat, sind über den\n"
"gesamten Tempel verteilt!\n"
"Hilf mir, " NAME "!"
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin gerettet!\n"
"Hab Dank!\n"
"Bitte, nimm dies!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "... Schnell... \n"
"Ich kann die Last nicht\n"
"länger tragen..." BOX_BREAK UNSKIPPABLE "Raus hier!"
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dank sei Dir, mein Bruder!\n"
"Ich weiß das, was Du getan hast,\n"
"sehr zu schätzen. Hab Dank, auch\n"
"im Namen meines Volkes!" BOX_BREAK UNSKIPPABLE "Du hast Dich als würdiger Streiter\n"
"erwiesen! Ich habe nie an Dir \n"
"gezweifelt..."
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT("\x47") "Vergiß nie...\n"
SHIFT("\x0C") "Du und ich, wir sind nun Brüder!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wahre Freundschaft wächst, je\n"
"länger sie besteht. \n"
"Sie wächst im Herzen und wird \n"
"mit jeder Minute stärker..." BOX_BREAK UNSKIPPABLE "Die leidenschaftliche Blüte \n"
"der Freundschaft, die jetzt schon\n"
"in Dir reift, wird Dir weisen den\n"
"richtigen Weg..." BOX_BREAK UNSKIPPABLE "Diese Melodie sei der Kraft \n"
"der Freundschaft gewidmet!\n"
"Lausche nun dem " COLOR(RED) "Bolero des \n"
"Feuers" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "... Bis bald..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME ", in dieser Höhle \n"
"herrscht extreme Hitze! \n"
"Lange können wir hier nicht \n"
"bleiben!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bruder " NAME "!\n"
"Daddy ist zurück!\n"
"Und auch die anderen!" BOX_BREAK UNSKIPPABLE "Vater und Du, ihr habt den\n"
"Drachen gemeinsam bezwungen!" TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn ich groß bin, möchte\n"
"ich genauso werden wie Du, \n"
NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Danke, " NAME "!"
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Dank sei Dir, denn Du hast uns \n"
"gerettet!" PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich, Darunia, offenbare mich\n"
"Dir als einer der Sieben Weisen... \n"
"Der " COLOR(RED) "Weise des Feuers" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Hättest Du das erwartet?\n"
"Ich denke das ist es, was\n"
"man Schicksal nennt..." BOX_BREAK UNSKIPPABLE "Wenn ich Dir helfen kann, das\n"
"Böse in seine Schranken zu \n"
"weisen, laß es mich wissen."
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nimm dies an Dich, Bruder!\n"
"Dieses " COLOR(RED) "Amulett " COLOR(DEFAULT) "enthält die Kräfte\n"
"der Geister des Feuers... und der\n"
"Freundschaft."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Alle sind verschwunden!\n"
"Dennoch, der Shop bleibt \n"
"geöffnet!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Welch aufregendes Abenteuer...\n"
"Es liefert Stoff für eine \n"
"Legende..." BOX_BREAK UNSKIPPABLE "Noch immer kann ich nicht \n"
"glauben, daß die Dodongos, die wir \n"
"für ausgestorben hielten, in so\n"
"großer Anzahl zurückkehrten..." BOX_BREAK UNSKIPPABLE "Und der Fels, der den Eingang \n"
"der Höhle versperrte..." BOX_BREAK UNSKIPPABLE "Für all dies war " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "," COLOR(RED) "\n"
COLOR(DEFAULT) "der Gerudokönig, verantwortlich." BOX_BREAK UNSKIPPABLE "Er sprach: \n"
"\"" COLOR(LIGHTBLUE) "Gebt mir den Heiligen Stein und\n"
"ich werde eure Höhle wieder \n"
"öffnen!" COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "Du hast Dein Leben für uns \n"
"riskiert..."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Paßt genau..."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich arbeite gerade an etwas sehr \n"
"Interessantem! Doch ich denke, es\n"
"wird noch eine Weile dauern..." TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich schätze, in fünf oder sechs\n"
"Jahren dürfte es fertig sein!"
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe eine Waffe fertiggestellt.\n"
"Wie wär's damit?" TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das Schwert ist doch kunstvoll\n"
"geschmiedet, nicht wahr?"
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, es scheint da ein Problem mit \n"
"der Stabilität zu geben.\n"
"Aber warte mal..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Möchtest Du vielleicht DIESE\n"
"Waffe für 200 Rubine kaufen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun gut, komm später wieder."
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bitte... Bitte friß mich nicht!\n"
"Wenn Du mich frißt, wird Dir \n"
"ganz schlecht werden!" BOX_BREAK "Du würdest es bereuen!"
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, sicher hat Darunia Dich um\n"
"Hilfe gebeten! Du hast etwas bei\n"
"mir gut!" BOX_BREAK "Hilf Darunia!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mein Bruder...\n"
"Er hat einen neuen Laden...\n"
"Es ist Medigorons \n"
"Waffengeschäft..." BOX_BREAK "Er ist gut... \n"
"Aber ich schmiede bessere\n"
"Klingen." BOX_BREAK "Die hylianischen Zimmerleute\n"
"wissen meine Arbeit zu schätzen.\n"
"Glaub mir..."
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Zweifelsohne eine Waffe aus \n"
"meiner Schmiede!\n"
"Ich würde sie reparieren..." BOX_BREAK UNSKIPPABLE "Doch beim letzten Erdbeben ist mir \n"
"Lavastaub in die Augen geraten.\n"
"Seitdem sehe ich schlecht!" BOX_BREAK UNSKIPPABLE "In Zoras Reich gibt es wundersame\n"
"Augentropfen. Wende Dich an \n"
COLOR(RED) "König Zora" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bitte, bringe mir die Augentropfen!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich bitte Dich! Mir geht es gar \n"
"nicht gut... Meine Augen brennen!\n"
"Bitte..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh nein! Alle sind verschwunden!\n"
"Ich blieb als einziger zurück!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich warte hier auf Dich,\n"
"mit tränenden Augen...\n"
"Bitte grüße König Zora von mir!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du... Du bringst die Augentropfen!\n"
"Du bist meine Rettung! Ich werde\n"
"sie gleich ausprobieren!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x59")  COLOR(RED) "Wow!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "Unglaublich! Grandios!\n"
"Ich kann wieder sehen!" BOX_BREAK UNSKIPPABLE "Endlich kann ich wieder\n"
"schmieden! Hier, nimm dies und \n"
"schau in ein paar Tagen wieder \n"
"vorbei!" TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sie sind alle wieder da!\n"
"Es ist wieder wie früher!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Noch einige Tage...\n"
"Gut Ding will Weile haben...\n"
"Gedulde Dich noch..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nein, noch immer nicht...\n"
"Es ist noch nicht fertig...\n"
"Du bist sehr ungeduldig..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hier ist es... Endlich!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Du hast Deinen " COLOR(DEFAULT) "Schild " COLOR(LIGHTBLUE) "verloren!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Du hast Deine " COLOR(DEFAULT) "Rüstung " COLOR(LIGHTBLUE) "verloren!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Du hast Deinen " COLOR(DEFAULT) "Schild " COLOR(LIGHTBLUE) "verloren!" COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "Du hast Deine " COLOR(DEFAULT) "Rüstung " COLOR(LIGHTBLUE) "verloren!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast Dich bisher gut \n"
"geschlagen, " NAME ". \n"
"Dies ist der Gipfel des \n"
"Todesberges!" BOX_BREAK UNSKIPPABLE "Man sagt, die Wolken, die den \n"
"Gipfel umgeben, spiegeln den\n"
"Zustand des Berges wider. Sind\n"
"sie weiß, herrscht Friede." BOX_BREAK UNSKIPPABLE "Dein Aufstieg zum Gipfel hat\n"
"mir bewiesen, wie tapfer Du bist!\n"
"Diese Tapferkeit soll nun erneut\n"
"geprüft werden..." BOX_BREAK UNSKIPPABLE "Eine mächtige " COLOR(RED) "Fee" COLOR(DEFAULT) " lebt \n"
"hier oben. Sie ist die\n"
"Mutter aller Feen! Suche sie auf,\n"
"und sie wird Dich belohnen..." BOX_BREAK UNSKIPPABLE "Ich werde hier auf Dich warten.\n"
"Willst Du zurück zum Fuß des\n"
"Berges, so werde ich Dir helfen.\n"
"Geh nun!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du siehst erwachsener aus,\n"
"seit Du die Fee besucht hast..." BOX_BREAK "Doch noch wirkst Du nicht wie \n"
"der prophezeite Retter Hyrules!\n"
"Hierfür fehlt Dir noch einiges!" BOX_BREAK "Wenn Du " COLOR(RED) "zum Fuß des Berges" COLOR(DEFAULT) " \n"
"zurück möchtest, kann ich Dich \n"
"mitnehmen. Komm her und halte \n"
"Dich an meinen Krallen fest!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Man sagt, daß auf dem Gipfel des \n"
"Todesberges eine " COLOR(RED) "wunderschöne\n"
"Fee" COLOR(DEFAULT) " lebt!" BOX_BREAK "Wirst Du sie besuchen?"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich hörte, daß auf dem Gipfel des\n"
"Todesberges eine " COLOR(RED) "Fee" COLOR(DEFAULT) " lebt." BOX_BREAK "Wenn Du dorthin möchtest, \n"
"solltest Du Dich mit einem\n"
"großen " COLOR(LIGHTBLUE) "Schild" COLOR(DEFAULT) " ausrüsten..."
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Wow! Du hast ein" COLOR(DEFAULT) " Ei \n"
COLOR(LIGHTBLUE) "ausgebrütet!\n"
"Ein " COLOR(DEFAULT) "Küken " COLOR(LIGHTBLUE) "ist geschlüpft!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Besitzt Du den Roten Stein? Laß \n"
"mich ein Stückchen probieren!" BOX_BREAK "Nein? Buh!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bruder! Du solltest stets daran\n"
"denken, Deine Kräfte zu erhöhen!" BOX_BREAK UNSKIPPABLE "Die " COLOR(RED) "Fee" COLOR(DEFAULT) " auf dem Gipfel des\n"
"Todesberges hilft Dir dabei!" BOX_BREAK UNSKIPPABLE "Freunde, laßt uns unseren Bruder\n"
"verabschieden!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Da Du mich befreit hast, verrate\n"
"ich Dir ein Geheimnis!" BOX_BREAK UNSKIPPABLE "In diesem Tempel gibt es " COLOR(RED) "Türen" COLOR(DEFAULT) ",\n"
COLOR(RED) "die Dich" COLOR(DEFAULT) " beim Versuch, sie zu \n"
"öffnen, " COLOR(RED) "erschlagen" COLOR(DEFAULT) "! Sei gewarnt!" BOX_BREAK UNSKIPPABLE "Besitzt Du das Relikt der Goronen,\n"
"kannst Du sie zerschmettern!"
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast mich gerettet! Dafür\n"
"offenbare ich Dir ein Geheimnis!" BOX_BREAK UNSKIPPABLE "Hast Du Feuer gefangen, so \n"
"schwinge Dein Schwert oder rolle\n"
"Dich über den Boden. So löschst\n"
"Du es schneller..."
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hab Dank! Du bist mein Retter!\n"
"Höre meinen Ratschlag..." BOX_BREAK UNSKIPPABLE "In diesem Tempel wirst Du auf\n"
"Kreaturen treffen, die Dich \n"
"attackieren, während sie tanzen.\n"
"Gegen Pfeile sind sie immun..." BOX_BREAK UNSKIPPABLE "Finde das Relikt der Goronen,\n"
"und Du wirst auch diese Gegner\n"
"bezwingen!"
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Laß mich Dir als Dank\n"
"dafür etwas verraten!" BOX_BREAK UNSKIPPABLE "Einige Schalter dieses Tempels\n"
"lassen sich nur mit Gewalt \n"
"aktivieren. Das Relikt der Goronen\n"
"kann Dir dabei behilflich sein!"
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Als Dank für meine Befreiung \n"
"verrate ich Dir etwas!" BOX_BREAK UNSKIPPABLE "Findest Du auf der Karte einen\n"
"Ort, den Du nicht erreichen \n"
"kannst, versuche es mit der \n"
"Okarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Als Dank für meine Rettung\n"
"verrate ich Dir ein Geheimnis!" BOX_BREAK UNSKIPPABLE "Um zu der Tür zu gelangen, hinter\n"
"der Darunia verschwunden ist,\n"
"mußt Du den Pfeiler, der aus der \n"
"Decke ragt, nach unten befördern!" BOX_BREAK UNSKIPPABLE "Finde einen Weg, der Dich in\n"
"die oberen Stockwerke bringt!"
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast mich gerettet! Dafür\n"
"vertraue ich Dir etwas an!" BOX_BREAK UNSKIPPABLE "In der Eingangshalle des Tempels\n"
"befindet sich eine Statue.\n"
"Sie verbirgt eine Tür..." BOX_BREAK UNSKIPPABLE "Mit dem Relikt der Goronen\n"
"kannst Du auch dieses Problem\n"
"lösen!"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Danke! Laß mich Dir ein Geheimnis\n"
"anvertrauen..." BOX_BREAK UNSKIPPABLE "Wände, die Du mit dem Relikt\n"
"der Goronen zerstören kannst, \n"
"klingen hohl, wenn Du mit dem\n"
"Schwert dagegen schlägst."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Qualen haben ein Ende!\n"
"Ich bin frei!" EVENT
)

DEFINE_MESSAGE(0x3072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3072"
)

DEFINE_MESSAGE(0x3073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3073"
)

DEFINE_MESSAGE(0x4000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Diese Augen schmecken göttlich!\n"
"Endlich kann ich mal wieder\n"
"gebratene Augäpfel in Sahnesoße\n"
"essen! Mmmmh...!" BOX_BREAK UNSKIPPABLE "Großartig! Richte König Zora\n"
"meinen Dank aus!\n"
"Bitte? Was willst Du?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Du willst, daß ich " COLOR(RED) "Augentropfen" COLOR(DEFAULT) " \n"
COLOR(RED) "für Biggoron" COLOR(DEFAULT) " herstelle? Oh, wie\n"
"außerordentlich schade! Das\n"
"hättest Du gleich sagen sollen!" EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
"Hier entlang!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Ich frage mich, was " COLOR(RED) "Salia\n"
COLOR(DEFAULT) "gerade macht. Warum gehst Du\n"
"nicht mal wieder zu ihr?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Was machst Du denn? Du hast\n"
"ja ganz schön lange gebraucht..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Vielleicht solltest Du ab und zu\n"
"auf die " COLOR(RED) "Karte " COLOR(DEFAULT) "schauen." BOX_BREAK UNSKIPPABLE  NAME ", das hier ist ein \n"
"ruhiger See mit kristallklarem,\n"
"kühlem Wasser." BOX_BREAK UNSKIPPABLE "Auf seinem Grund befindet sich\n"
"der Zugang zum " COLOR(BLUE) "Wassertempel" COLOR(DEFAULT) ".\n"
"Die " COLOR(BLUE) "Zoras " COLOR(DEFAULT) "wachen über ihn." BOX_BREAK UNSKIPPABLE "Die Zoras sind Angehörige von\n"
"Zoras Reich im Nordosten Hyrules.\n"
"Sie sind stolze Amphibienwesen und\n"
"seit Urzeiten der Königsfamilie treu." BOX_BREAK UNSKIPPABLE "Ich hörte, nur einem Angehörigen\n"
"der königlichen Familie würde der\n"
"Zutritt zu Zoras Reich gestattet!" BOX_BREAK UNSKIPPABLE "Ich bin übrigens gerade auf dem\n"
"Weg zum " COLOR(RED) "Schloß" COLOR(DEFAULT) ". Wenn Du mit mir\n"
"kommen möchtest, halte Dich an\n"
"meinen Krallen fest!"
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin übrigens gerade auf dem\n"
"Weg zum " COLOR(RED) "Schloß" COLOR(DEFAULT) ". Wenn Du mit mir\n"
"kommen möchtest, halte Dich an\n"
"meinen Krallen fest!"
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x56") "Nanu?" BOX_BREAK UNSKIPPABLE "Sieht aus, als wäre da etwas in\n"
"der Flasche drin...\n"
"Oh, es ist ein " COLOR(RED) "Brief" COLOR(DEFAULT) ":" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(PURPLE) "Hilf mir!\n"
COLOR(DEFAULT)  SHIFT("\x2C")  COLOR(PURPLE) "Ich bin im Bauch von\n"
COLOR(DEFAULT)  SHIFT("\x20")  COLOR(YELLOW) "Lord Jabu-Jabu" COLOR(PURPLE) " gefangen!\n"
COLOR(DEFAULT)  SHIFT("\x5A")  COLOR(YELLOW) "Ruto" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x34")  COLOR(PURPLE) "PS: Verrate bitte \n"
COLOR(DEFAULT)  SHIFT("\x2D")  COLOR(PURPLE) "meinem Daddy nichts!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wer seid Ihr?" BOX_BREAK UNSKIPPABLE "Wir sind die " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", das stolze\n"
"hylianische Amphibiengeschlecht!" BOX_BREAK UNSKIPPABLE "So... Ihr behauptet, ein\n"
"Angehöriger von Hyrules\n"
"königlicher Familie zu sein... \n"
"Nun denn, was wollt Ihr von uns?"
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir sind gewandte Taucher!\n"
"Wie steht es mit Euch?" BOX_BREAK "Wollt Ihr ebenso meisterlich\n"
"tauchen, macht mit bei unserem\n"
COLOR(RED) "Tauchspiel" COLOR(DEFAULT) " am höchsten Punkt des\n"
"Wasserfalls! Schon ausprobiert?"
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aus Zoras Quelle entspringt\n"
"der Fluß.\n"
"Die Quelle ist auch die Residenz\n"
"von " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) "." TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lord Jabu-Jabu ist Schutzheiliger\n"
"der Zoras. " COLOR(RED) "Prinzessin Ruto" COLOR(DEFAULT) " sorgt\n"
"täglich für seine Nahrung."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir Zoras dienen dem mächtigen \n"
COLOR(RED) "König Zora" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der mächtige König Zora befindet\n"
"sich derzeit im " COLOR(RED) "Königsgemach" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Habt Ihr bereits Lord Jabu-Jabu\n"
"kennengelernt?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nach den Legenden unseres Volkes\n"
"wird dem Gutes zuteil, der Lord\n"
"Jabu-Jabu einen " COLOR(RED) "Fisch" COLOR(DEFAULT) " kredenzt."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie bedauerlich." BOX_BREAK "Jeder, der unser Reich besucht,\n"
"sollte wenigstens einmal\n"
"um eine Audienz bei\n"
COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) " ersuchen!" BOX_BREAK "Direkt hinter dem Thron des\n"
"mächtigen König Zora befindet sich\n"
"Zoras Quelle. Dort lebt\n"
"Lord Jabu-Jabu." BOX_BREAK "Fehlt Euch aber König Zoras\n"
"Erlaubnis, könnt Ihr die\n"
"Quelle nicht betreten."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wir haben " COLOR(RED) "Prinzessin Ruto\n"
COLOR(DEFAULT) "immer noch nicht gefunden, obwohl\n"
"wir sogar am " COLOR(BLUE) "Hylia-See" COLOR(DEFAULT) " suchten..."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Ihr einen Hinweis auf den\n"
"Verbleib von " COLOR(RED) "Prinzessin Ruto " COLOR(DEFAULT) "habt,\n"
"teilt es bitte König Zora mit!"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alles Wasser in Hyrule entspringt\n"
COLOR(BLUE) "Zoras Quelle" COLOR(DEFAULT) "." BOX_BREAK "Das Wasser fließt durch den\n"
"Zora-Fluß und schließlich in den\n"
COLOR(BLUE) "Hylia-See " COLOR(DEFAULT) "im Süden Hyrules."
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, ich fühle mich wie neugeboren!" BOX_BREAK UNSKIPPABLE "Seid Ihr es, der mich vom Eis\n"
"befreit hat? Ich danke Euch!" BOX_BREAK UNSKIPPABLE "Mir scheint, Ihr könnt Euch nicht\n"
"sehr lange unter Wasser aufhalten." BOX_BREAK UNSKIPPABLE "Als Zeichen meines Dankes nehmt\n"
"bitte diese " COLOR(RED) "Rüstung" COLOR(DEFAULT) ". Mit ihr könnt\n"
"Ihr nun auch unter Wasser atmen!"
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Prinzessin Ruto hat sich zum\n"
"Hylia-See begeben...\n"
"Ich mache mir erneut große Sorgen\n"
"um sie..."
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ooh...\n"
"Das ist eine... Nun... Hmmm...\n"
"Hmmm... " COLOR(RED) "Augentropfen" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Nun, wir haben in jedem Fall die\n"
"erforderlichen Zutaten dafür." BOX_BREAK UNSKIPPABLE "Bringt diese " COLOR(RED) "Zutaten " COLOR(DEFAULT) "zum\n"
"Labor am See. Dort werden die\n"
"Augentropfen für Euch zubereitet." BOX_BREAK UNSKIPPABLE "Doch eilt, denn die Zutaten\n"
"müssen frisch sein..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Werdet Ihr es schaffen,\n"
COLOR(RED) "bevor sie verderben" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ihr glaubt, nicht schnell genug zu\n"
"sein? Nun, auf dem Rücken eines\n"
"flinken Pferdes könnt Ihr die\n"
"Wegstrecke schneller zurücklegen..."
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sei gegrüßt!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", es sieht aus, als\n"
"würdest Du Dich langsam an Dein\n"
"Abenteuerleben gewöhnen!" BOX_BREAK UNSKIPPABLE "Ich glaube, Prinzessin Zelda wartet\n"
"darauf, daß Du sie wieder besuchst." BOX_BREAK UNSKIPPABLE "Du besitzt doch schon den\n"
COLOR(RED) "Goronen-Opal" COLOR(DEFAULT) ", oder nicht?"
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallo! Ich bin gerade dabei,\n"
"das Wasser aus dem Hylia-See\n"
"mit einigen seltsamen Substanzen\n"
"zu vermischen." BOX_BREAK "Vielleicht hast Du ja schon mal mit\n"
"Asa, der alten Frau in Kakarikos\n"
"Hexenladen gesprochen... Sie hat\n"
"viel von mir gelernt..."
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Oh, wow!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ich habe keinen " COLOR(RED) "Glotzfrosch" COLOR(DEFAULT) " \n"
"mehr gesehen, seit Zoras Reich\n"
"vom Eis überzogen wurde!" EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, meine liebste, teuerste\n"
COLOR(RED) "Prinzessin Ruto" COLOR(DEFAULT) "...\n"
"Wo mag sie sein?\n"
"Ich mache mir solche Sorgen..."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dieser Brief! \n"
"Er ist von " COLOR(RED) "Prinzessin Ruto" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Hmmm... Laßt mich lesen...\n"
"Sie ist im Bauch von\n"
"Lord Jabu-Jabu?\n"
"Das ist doch nicht möglich!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Lord Jabu-Jabu " COLOR(DEFAULT) "ist unser\n"
"Schutzheiliger und würde\n"
"Prinzessin Ruto niemals\n"
"verspeisen!" BOX_BREAK UNSKIPPABLE "Doch seit dieser seltsame\n"
"Fremdling namens " COLOR(RED) "Ganondorf" COLOR(DEFAULT) " unser\n"
"Reich besucht hat, benimmt sich\n"
"Lord Jabu-Jabu etwas sonderbar..." BOX_BREAK UNSKIPPABLE "Der Brief scheint echt zu sein. Ihr\n"
"dürft Prinzessin Ruto suchen, wenn\n"
"Ihr mögt. Passiert das Tor\n"
"hinter mir!" BOX_BREAK UNSKIPPABLE "Ich behalte diesen Brief. Nehmt Ihr\n"
"die " COLOR(RED) "Flasche" COLOR(DEFAULT) ", in der er sich befand.\n"
"Ihr werdet sie bestimmt gut\n"
"nutzen können!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bitte findet meine liebste\n"
COLOR(RED) "Prinzessin Ruto" COLOR(DEFAULT) "\n"
"so schnell Ihr könnt!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Du kannst unter Wasser nicht\n"
"atmen! Wird Dir die Luft knapp,\n"
"ziehe diese " COLOR(DEFAULT) "Stiefel " COLOR(LIGHTBLUE) "aus!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x42") "Ooooh neiiiin!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, ich bin wieder frei...\n"
"Seid Ihr es, der mich vom Eis\n"
"befreit hat? Ich danke Euch!" BOX_BREAK UNSKIPPABLE "Als Zeichen meines Dankes nehmt\n"
"bitte diese " COLOR(BLUE) "Zora-Rüstung" COLOR(DEFAULT) ". Damit\n"
"könnt Ihr... Wie bitte?!" BOX_BREAK UNSKIPPABLE "Ihr habt sie bereits? Mir scheint,\n"
"Ihr seid auf alles vorbereitet!" BOX_BREAK UNSKIPPABLE "Laßt mich Euch dennoch herzlich\n"
"danken... Wie wäre es mit einem \n"
"königlichen KUSS?! Ihr mögt das\n"
"nicht? Nun denn..." BOX_BREAK UNSKIPPABLE "Wenn Ihr meinen Dank nicht wollt,\n"
"dann lauscht wenigstens meinen\n"
"Sorgen..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin ein " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Habt Ihr nicht\n"
"irgendwo ein hübsches\n"
"Zora-Mädchen gesehen?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin ein " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Habt Ihr nicht\n"
"manch Seltsames in diesem See\n"
"gefunden?\n"
"Der Fluß trägt vieles hierher!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du... " QUICKTEXT_ENABLE "Du bist spät dran!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Warum hat es so lange gedauert?" QUICKTEXT_DISABLE "\n"
"Du " QUICKTEXT_ENABLE "bist eine ziemlich lahme Ente!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Na gut... Ich hab mich ein bißchen\n"
"einsam gefühlt, das ist alles...\n"
"Aber nur ein bißchen!"
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ich hatte Angst..." QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Aber nur ein wenig!" QUICKTEXT_DISABLE "\n"
"Nur ein wenig!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hey, Du!" QUICKTEXT_DISABLE "\n"
"Du bist cool...\n"
"Ein bißchen mehr als andere... \n"
QUICKTEXT_ENABLE "Aber nur ein bißchen!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Naja, egal, Du hast mich gerettet.\n"
"Ich denke, ich kann Dir eine\n"
"Belohnung dafür geben." BOX_BREAK UNSKIPPABLE "Was möchtest Du? Sag's mir...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ich möchte den Heiligen Stein!\n"
"Eigentlich nichts..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du sprichst vom Heiligen Stein des\n"
"Wassers, dem " COLOR(BLUE) "Zora-Saphir" COLOR(DEFAULT) "?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe ihn von meiner Mama\n"
"bekommen und darf ihn nur dem\n"
"geben, der mich heiratet. Es ist so\n"
"eine Art Verlobungsring der Zoras!" BOX_BREAK UNSKIPPABLE  SHIFT("\x54")  QUICKTEXT_ENABLE "Okay!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ich gebe Dir meinen wertvollsten\n"
"Schatz: Den Zora-Saphir!"
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Sag's bloß nicht meinem Daddy..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hihihi... Sei nicht so schüchtern!" BOX_BREAK UNSKIPPABLE "Ich weiß genau, was Du gerade\n"
"denkst..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich wollte eigentlich einen Fisch\n"
"kaufen, aber er ist ein bißchen zu\n"
"teuer..." BOX_BREAK "Da muß ich wohl einen der\n"
"Fische fangen, die hier\n"
"herumschwimmen."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, " NAME "!\n"
"Ihr habt also\n"
"Prinzessin Ruto gerettet?\n"
"Ich bin sehr froh darüber!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich hoffe, mein wertvollster\n"
"Schatz wird Dir bei Deiner Mission\n"
"helfen. Das wäre super!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, hallo " NAME "!\n"
"Prinzessin Ruto spricht in der\n"
"letzten Zeit nur noch über Euch!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Ihr seid es, " NAME "!\n"
"Dank Euch ist Lord Jabu-Jabu\n"
"endlich wieder der alte!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wir Zoras achten den mächtigen\n"
"König Zora sehr. Er hat wahrlich\n"
"königliche Würde!" BOX_BREAK UNSKIPPABLE "Der mächtige König Zora hat eine\n"
"Tochter, Prinzessin " COLOR(RED) "Ruto" COLOR(DEFAULT) ". Sie ist\n"
"sein einziges Kind." BOX_BREAK UNSKIPPABLE "Sie ist ziemlich wild und\n"
"sorgt für ordentlichen Wirbel\n"
"hier in Zoras Reich." TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Bitte sehr." BOX_BREAK UNSKIPPABLE "Diese Medizin ist " COLOR(RED) "nicht lange\n"
"haltbar" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Eile so schnell wie möglich zu\n"
"den Goronen. Du bist ja noch jung\n"
"und hast flinke Beine!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hallo! Es sieht aus, als wärest Du\n"
"erfahrener und kräftiger geworden,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Direkt vor Dir liegt " COLOR(BLUE) "Zoras Reich" COLOR(DEFAULT) ".\n"
"Die Zoras dienen der königlichen\n"
"Familie von Hyrule und bewachen\n"
"dieses Gewässer." BOX_BREAK UNSKIPPABLE "Das Tor zu ihrem Reich öffnet\n"
"sich nur einem Abgesandten der \n"
"königlichen Familie." BOX_BREAK UNSKIPPABLE "Spiele vor dem Portal ein\n"
COLOR(RED) "Schlaflied" COLOR(DEFAULT) " aus der Überlieferung\n"
"der königlichen Familie!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Du wieder mal vorbeikommst,\n"
"bring mir doch ein Souvenir mit!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast Prinzessin Ruto gefunden!\n"
"Jetzt wird Dir König Zora sicher\n"
"den " COLOR(BLUE) "Heiligen Stein des Wassers\n"
COLOR(DEFAULT) "geben..." BOX_BREAK UNSKIPPABLE "Oder etwa nicht?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prinzessin Ruto hat Dir ihren\n"
"wertvollsten Schatz gegeben!\n"
"Du besitzt nun zwei Heilige Steine!\n"
"Jetzt fehlt nur noch einer!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prinzessin Ruto hat Dir\n"
"ihren wertvollsten Schatz gegeben!\n"
"Nun besitzt Du die\n"
"drei Heiligen Steine!" BOX_BREAK UNSKIPPABLE "Jetzt schnell zu Prinzessin Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sei gegrüßt, " NAME "..."
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dieses Eis wurde von einer bösen\n"
"Macht erschaffen... Das Ungeheuer\n"
"im " COLOR(BLUE) "Wassertempel" COLOR(DEFAULT) " ist der Urheber\n"
"dieses Unheils." BOX_BREAK UNSKIPPABLE "Du mußt das Übel beseitigen,\n"
"sonst wird dieses Eis nie mehr\n"
"schmelzen..." BOX_BREAK UNSKIPPABLE "Hast Du Mut, den Gefahren im\n"
"Tempel zu trotzen und die Zoras\n"
"zu retten, dann erlerne nun die\n"
"Melodie, die Dich zum Tempel führt."
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Zeit entschwindet, Menschen\n"
"scheiden...\n"
"In ewig wie des Wassers Fluß..." BOX_BREAK UNSKIPPABLE "Zu königlichem Streben reift des\n"
"Kindes Mut... Junger Liebe Knospen\n"
"erblühen groß und stark... Des\n"
"Wassers Kraft allein dies schafft!" BOX_BREAK UNSKIPPABLE "Lausche der " COLOR(BLUE) "Serenade des Wassers\n"
COLOR(DEFAULT) "und trage sie in Deinem Herzen..."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wenn Du hierher kamst, um die\n"
"Zoras zu retten, hast Du den\n"
"ersten Schritt getan. Doch mehr\n"
"findest Du hier nicht..." BOX_BREAK UNSKIPPABLE "Mit einer Ausnahme sind alle\n"
"Zoras unter einer dicken \n"
"Eisschicht gefangen..." BOX_BREAK UNSKIPPABLE "Ich konnte nur ihre Prinzessin\n"
"retten, aber sie lief in Richtung \n"
"des" COLOR(BLUE) " Wassertempels " COLOR(DEFAULT) "davon!"
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du einen Fisch kaufen willst,\n"
"dann brauchst Du etwas, worin Du\n"
"ihn aufbewahren kannst." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du willst die " COLOR(BLUE) "Zora-Rüstung" COLOR(DEFAULT) " kaufen?\n"
"Sie ist aus edelstem Material und\n"
"daher enorm teuer!" BOX_BREAK "Ich schätze, nur " COLOR(RED) "diese sehr\n"
"reiche Familie in Kakariko" COLOR(DEFAULT) " kann\n"
"sie sich leisten." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh... Wenn ich mich recht\n"
"entsinne... " NAME "?!" BOX_BREAK UNSKIPPABLE "Du bist " NAME ", oder?" BOX_BREAK UNSKIPPABLE "Ich bin es! " COLOR(BLUE) "Ruto" COLOR(DEFAULT) ", Deine Braut!\n"
"Die Prinzessin der Zoras!" BOX_BREAK UNSKIPPABLE "Ich werde nie vergessen, was\n"
"wir uns vor Jahren\n"
"geschworen haben!" BOX_BREAK UNSKIPPABLE "Es war grauenvoll von Dir,\n"
"mich sieben lange Jahre\n"
"warten zu lassen!" BOX_BREAK UNSKIPPABLE "Doch jetzt ist nicht die Zeit,\n"
"über Liebe zu sprechen. Es ist\n"
"etwas Furchtbares geschehen!" BOX_BREAK UNSKIPPABLE "Zoras Reich ist eingefroren!\n"
"Alles ist über und über mit\n"
"Eis bedeckt!" BOX_BREAK UNSKIPPABLE "Ein junger Mann namens " COLOR(RED) "Shiek\n"
COLOR(DEFAULT) "hat mich aus dem Eis gerettet..." BOX_BREAK UNSKIPPABLE "Aber die anderen Zoras wurden\n"
TEXT_SPEED("\x02") "... noch nicht..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Ich will sie retten. Alle!\n"
"Ich will Zoras Reich retten!" BOX_BREAK UNSKIPPABLE "Du mußt mir helfen! Du mußt\n"
"es für mich tun - für die Frau, die\n"
"Du heiraten wirst!" BOX_BREAK UNSKIPPABLE  NAME ", hilf mir, das\n"
"bösartige Ungeheuer zu\n"
"vernichten, das in diesem Tempel\n"
"lauert. Wirst Du das tun?" BOX_BREAK UNSKIPPABLE "Im Wassertempel gibt es " COLOR(RED) "drei\n"
"Stellen" COLOR(DEFAULT) ", an denen Du den\n"
"Wasserstand verändern kannst." BOX_BREAK UNSKIPPABLE "Ich zeige Dir den Weg.\n"
"Folge mir! Und beeile Dich!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! Vorsicht!\n"
"Das hier sieht nicht aus wie\n"
"gewöhnliches Wasser...\n"
"Irgendetwas lauert hier!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "..." BOX_BREAK UNSKIPPABLE "Ich hätte nichts anderes von\n"
"jemandem erwartet, den ich zu\n"
"meinem Ehemann auserkoren habe!" BOX_BREAK UNSKIPPABLE "Zoras Reich und seine Bewohner\n"
"können dank Deiner Hilfe\n"
"wieder in Freiheit leben."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Wenn Du Shiek triffst, danke\n"
"ihm von mir, okay?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ruto wollte sich bei mir \n"
"bedanken?" BOX_BREAK UNSKIPPABLE "Ich verstehe..." BOX_BREAK UNSKIPPABLE "Auch in ihrem Namen müssen wir\n"
"Hyrule den Frieden wiederbringen!"
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, ich verstehe...\n"
"Prinzessin Ruto ist zum\n"
"Wassertempel gegangen..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als meinen Lohn... gewähre\n"
"ich Dir meine ewige Liebe!" BOX_BREAK UNSKIPPABLE "Äh, naja, das würde ich gern,\n"
"aber ich merke, daß Du an eine \n"
"andere denkst..."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prinzessin Zelda... Sie ist am\n"
"Leben! Ich spüre es. Also laß\n"
"Dich nicht entmutigen!"
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x48") "Iiiihhhh!!!\n"
SHIFT("\x31") "Was ist das denn?!\n"
SHIFT("\x3D") "Ein Oktopus?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als " COLOR(BLUE) "Weise des Wassers\n"
COLOR(DEFAULT) "ist es meine Aufgabe, den \n"
"Wassertempel zu bewachen..." BOX_BREAK UNSKIPPABLE "Und Du... Du suchst nach\n"
"Prinzessin " COLOR(RED) "Zelda" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Gib es zu! Du kannst nichts\n"
"vor mir verheimlichen!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich weiß, Dich wird nichts\n"
"aufhalten in Deinem Kampf für den\n"
"Frieden... Nimm daher dieses\n"
COLOR(BLUE) "Amulett" COLOR(DEFAULT) " und trage es mit Würde!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, Du! Wer bist Du?!" BOX_BREAK UNSKIPPABLE "Ich bin " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Prinzessin der Zoras." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Was?!" QUICKTEXT_DISABLE "\n"
"Mein Daddy hat Dich geschickt,\n"
"um mich zu retten?" BOX_BREAK UNSKIPPABLE "Ich würde " QUICKTEXT_ENABLE "niemals" QUICKTEXT_DISABLE " jemanden\n"
"um so etwas bitten!" BOX_BREAK UNSKIPPABLE "Flaschenpost? Ich weiß\n"
QUICKTEXT_ENABLE "überhaupt nicht" QUICKTEXT_DISABLE ", wovon Du redest!" BOX_BREAK UNSKIPPABLE "Mein Daddy hat Angst um mich?" BOX_BREAK UNSKIPPABLE "Ist mir " QUICKTEXT_ENABLE "total" QUICKTEXT_DISABLE " egal!" BOX_BREAK UNSKIPPABLE "Außerdem kann ich jetzt sowieso\n"
"nicht heim. Und Du... " QUICKTEXT_ENABLE "Verschwinde!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Kapiert?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bist Du immer noch hier? Du bist\n"
"ja schlimmer als eine Klette!" BOX_BREAK UNSKIPPABLE "Ich bin okay. Schon seit ich eine\n"
"kleine Zora-Prinzessin war, laufe\n"
"ich hin und wieder in Lord\n"
"Jabu-Jabus Bauch herum. Aber..." BOX_BREAK UNSKIPPABLE "Lord Jabu-Jabu ist heute ziemlich\n"
"seltsam..." BOX_BREAK UNSKIPPABLE "Hier sind auf einmal elektrisch \n"
"geladene Quallen und seltsame\n"
"Löcher..." BOX_BREAK UNSKIPPABLE "Obendrein habe ich meinen\n"
"wertvollsten Stein...\n"
QUICKTEXT_ENABLE "Aber das geht Dich gar nichts an!" QUICKTEXT_DISABLE "\n"
"Egal..." BOX_BREAK UNSKIPPABLE "Du! " QUICKTEXT_ENABLE "Verschwinde!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Kapiert?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du machst Dir echt solche Sorgen\n"
"um mich?" BOX_BREAK UNSKIPPABLE "Dann wird Dir eine besondere Ehre\n"
"zuteil: Du darfst mich tragen!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Und übrigens" QUICKTEXT_DISABLE "... Ich bleibe bei Dir,\n"
"bis ich gefunden habe, wonach ich\n"
"suche! Kein Witz! Ich mein's ernst!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wie unaufmerksam von Dir!" QUICKTEXT_DISABLE "\n"
"Warum läßt Du mich sitzen?!\n"
"Wenn Du ein Mann sein willst,\n"
"dann verhalte Dich auch so!" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Da ist er ja!" QUICKTEXT_DISABLE "\n"
"Danach habe ich gesucht!\n"
"Wirf mich auf die Plattform!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Prinzessin Ruto hat den \n"
COLOR(BLUE) "Heiligen Stein" COLOR(DEFAULT) " wieder!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Aber" TEXT_SPEED("\x00") " warum Prinzessin Ruto?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Gott sei Dank!\n"
"Endlich... \n"
"Der Stein von meiner Mama..." BOX_BREAK UNSKIPPABLE "Als ich Lord Jabu-Jabu gefüttert\n"
"habe, hat er wild um sich\n"
"geschlagen! Vor Schreck habe ich\n"
"den Stein fallen lassen!" BOX_BREAK UNSKIPPABLE "Und ganz plötzlich hat er mich\n"
"und den Stein verschluckt..." BOX_BREAK UNSKIPPABLE "Aber jetzt habe ich ihn wieder\n"
"und kann heimgehen!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bring mich jetzt schnell heim!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tauchspiel   20 Rubine\n"
"Macht Ihr mit?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Okay!" QUICKTEXT_DISABLE  BOX_BREAK "Sammelt alle Steine ein, die ich\n"
"nach unten werfe. Ihr habt dafür\n"
"nur begrenzt Zeit!" BOX_BREAK "Sind alle eingesammelt, kommt\n"
"hierher zurück. Dann bekommt\n"
"Ihr etwas sehr Schönes!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Gratuliere!" QUICKTEXT_DISABLE "\n"
"Ich habe etwas Tolles für Euch!\n"
"Holt es Euch ab!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wie elegant Ihr getaucht seid!\n"
"Hier, nehmt dies als Lohn!" BOX_BREAK UNSKIPPABLE "Dies ist eine " COLOR(RED) "silberne Schuppe" COLOR(DEFAULT) "\n"
"der Zoras. Mit ihr kann man viel\n"
"tiefer tauchen!" EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das Wasser steigt, und das Böse\n"
"verläßt den See...\n"
NAME ", Du hast\n"
"es geschafft!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich... bin nun überzeugt, daß Du\n"
"diese Welt retten wirst..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Schau, " NAME "..." BOX_BREAK UNSKIPPABLE "Du und Prinzessin Ruto, ihr habt\n"
"gemeinsam das bösartige Monster\n"
"besiegt!" BOX_BREAK UNSKIPPABLE "Der See füllt sich mit reinem\n"
"Wasser, und alles ist wie zuvor."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "START!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Spring den Wasserfall hinab,\n"
"um Zeit zu sparen." EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nehmt soviel Ihr wollt für\n"
"20 Rubine. Macht Ihr mit?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gratuliere!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ein paar " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) " gefällig?\n"
"Sie gehen nicht besonders gut..." BOX_BREAK "Wie wäre es mit...\n"
COLOR(RED) "10 Rubine" COLOR(DEFAULT) " das Stück?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ein paar " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) " gefällig?\n"
"Sie sind noch nicht so beliebt." BOX_BREAK "Wie wäre es mit...\n"
COLOR(RED) "20 Rubine" COLOR(DEFAULT) " das Stück?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ein paar " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) " gefällig?\n"
"Sie werden langsam beliebter..." BOX_BREAK COLOR(RED) "30 Rubine" COLOR(DEFAULT) " das Stück.\n"
"Wie wäre es?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ein paar " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) " gefällig?\n"
"Sie gehen weg wie warme Semmeln!" BOX_BREAK COLOR(RED) "40 Rubine" COLOR(DEFAULT) " das Stück.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hier gibt's die tollen " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "!\n"
"Wer sie nicht kauft, der wird es\n"
"wirklich bereuen!" BOX_BREAK COLOR(RED) "50 Rubine" COLOR(DEFAULT) " das Stück.\n"
"(Aber nur jetzt!)\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Die weltberühmten " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "!\n"
"Sie sind absolut beliebt und sicher\n"
"schon bald ausverkauft!" BOX_BREAK "Ein Superpreis!\n"
COLOR(RED) "60 Rubine" COLOR(DEFAULT) " das Stück!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hier gibt es die seltenen\n"
COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "! Dies könnte die\n"
"letzte Chance sein!" BOX_BREAK "Mein Spezial-Preis!\n"
COLOR(RED) "70 Rubine" COLOR(DEFAULT) " das Stück!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wir haben die legendären \n"
COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "! Ich verkaufe sie\n"
"normalerweise an niemanden!" BOX_BREAK "Mein Super-Preis!\n"
COLOR(RED) "80 Rubine" COLOR(DEFAULT) " das Stück!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "?! Die sind sehr\n"
"teuer, aber... ich verkaufe\n"
"sie gern!" BOX_BREAK "Aber ich muß mindestens\n"
COLOR(RED) "90 Rubine" COLOR(DEFAULT) " für eine haben!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wir verkaufen... " COLOR(RED) "Wundererbsen" COLOR(DEFAULT) "! \n"
"Du willst sie kaufen... Na gut!" BOX_BREAK COLOR(RED) "100 Rubine" COLOR(DEFAULT) " für eine!\n"
"Juhuuu!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na gut..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist zu wenig Geld.\n"
"Ich kann sie nicht verkaufen."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Plaziere eine Wundererbse auf " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "und pflanze sie hier in die Erde."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie schade! Die Wundererbsen\n"
"sind ausverkauft! Wie bitte?\n"
"Oh, diese hier sind unverkäuflich!"
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es gibt eine Menge Orte, an denen\n"
"man  Wundererbsen pflanzen kann.\n"
"Suche nach einem quadratischen\n"
"Fleckchen Erde!"
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist nur " COLOR(RED) "1 Meter" COLOR(DEFAULT) " tief getaucht. Das\n"
"würde ich nicht \"Tauchen\" nennen..."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist nur " COLOR(RED) "2 Meter" COLOR(DEFAULT) " tief getaucht. Das\n"
"würde ich nicht \"Tauchen\" nennen..."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist nur " COLOR(RED) "3 Meter" COLOR(DEFAULT) " tief getaucht. Das\n"
"würde ich nicht \"Tauchen\" nennen..."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist nur " COLOR(RED) "4 Meter" COLOR(DEFAULT) " tief getaucht. Das\n"
"würde ich nicht \"Tauchen\" nennen..."
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist jetzt " COLOR(RED) "5 Meter" COLOR(DEFAULT) " tief getaucht. Das\n"
"ist noch nicht tief genug..."
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist jetzt " COLOR(RED) "6 Meter" COLOR(DEFAULT) " tief getaucht. Du\n"
"solltest tiefer tauchen können!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"bist jetzt " COLOR(RED) "7 Meter" COLOR(DEFAULT) " tief getaucht. Du\n"
"solltest tiefer tauchen können!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast es vielleicht nicht bemerkt,\n"
"aber ich habe Dich beobachtet. Du\n"
"hast den " COLOR(RED) "Grund des Sees" COLOR(DEFAULT) " erreicht!\n"
"Super! Hier ist etwas für Dich!"
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du scheinst der beste Taucher \n"
"Hyrules zu sein! Warum tauchst\n"
"Du nicht mal auf den \n"
"Grund des Hylia-Sees?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich bin " COLOR(RED) "Balzac" COLOR(DEFAULT) ", die Vogelscheuche.\n"
"Ich wünschte, ich könnte reisen,\n"
"um herzergreifende Lieder zu\n"
"hören. Aber ich stecke hier fest..."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eine wunderschöne Melodie!\n"
"Sie geht richtig ans Herz!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Dir ein schönes Lied einfällt,\n"
"komm her und spiel es mir vor!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Es ist lange her, aber würdest Du\n"
"mir nochmal das schöne Lied von\n"
"damals vorspielen?" EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das Lied von damals werde ich\n"
"nie vergessen!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nun, willst Du für nur\n"
COLOR(RED) "20 Rubine" COLOR(DEFAULT) " angeln?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, nein! Dir fehlt ein " COLOR(RED) "Rumble \n"
"Pak" COLOR(DEFAULT) "! Damit würdest Du spüren,\n"
"wenn ein Fisch am Haken ist." BOX_BREAK "Pech für Dich!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow! Du hast ein " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Jetzt spürst Du, ob Du etwas an\n"
"der Angel hast, mein Junge!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Mist! Du hast nicht genug Geld."
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Geh zum Rand des Sees und drücke\n"
COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", um die Fische anzuschauen.\n"
"Wirf die Leine mit " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " aus und\n"
"stoppe sie mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Laß Deinen Köder mit " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " im\n"
"Wasser zappeln. Als Anfänger\n"
"kannst Du auch " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " benutzen." BOX_BREAK "Hole die Angelschnur mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " ein.\n"
"Wenn Du " COLOR(BLUE) "[A]" COLOR(DEFAULT) " und " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "gedrückt\n"
"hältst, kannst Du den Fang\n"
"schneller einholen!" BOX_BREAK "Spürst Du, daß etwas anbeißt,\n"
"drücke " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "und " COLOR(LIGHTBLUE) "[Control-Pad] nach unten" COLOR(DEFAULT) ",\n"
"um den Haken festzusetzen. Dann\n"
"hole die Leine mit " COLOR(BLUE) "[A]" COLOR(DEFAULT) " ein." BOX_BREAK "Möchtest Du Deine Ergebnisse\n"
"beim Angeln festhalten, mußt Du\n"
"Deinen Fang wiegen lassen!" BOX_BREAK "Angelst Du als Kind, wird Dein\n"
"Ergebnis auch in der Zukunft\n"
"festgehalten. Umgekehrt ist\n"
"dies nicht möglich." BOX_BREAK "Hast Du alles verstanden?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich bin sehr großzügig. Du kannst\n"
"angeln, solange Du möchtest." BOX_BREAK "Der größte Fang an diesem See\n"
"wog " COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "." BOX_BREAK "Wenn Du Deine Angel ausgeworfen \n"
"hast, kannst Du die Blickrichtung\n"
"mit " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ändern." BOX_BREAK SHIFT("\x4A") "Petri Heil!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hahaha!\n"
"Hast Du den Haken nicht mit " COLOR(BLUE) "[A]\n"
COLOR(DEFAULT) "und " COLOR(LIGHTBLUE) "[Control-Pad] nach unten" COLOR(DEFAULT) " angezogen?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, was ist passiert?\n"
"Du hast den Fisch verloren!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Naja... Der wiegt etwa " COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) ". \n"
"Willst Du ihn behalten?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was möchtest Du?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Wiege meinen Fisch!\n"
"Laß uns ein wenig reden...\n"
"Mir reicht's!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du mußt Dich schon etwas  \n"
"gedulden, wenn Du einen guten\n"
"Fang machen willst! Ehrlich!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x55") "WOW!!" BOX_BREAK "Das ist ja ein Prachtkerl! Sieht\n"
"ganz nach einem neuen Rekord aus!\n"
"Er wiegt mindestens " COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "!\n"
"Okay, hier ist Dein Preis!" EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was? \n"
"Was machst Du mit mir?!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, Junge! Hast Du nichts\n"
"Besseres zu tun?" BOX_BREAK "Was? Du willst weiter hier\n"
"rumlungern?" BOX_BREAK "Mit so einer Einstellung bringt man\n"
"es im Leben zu nichts, glaub mir!\n"
"Naja..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der größte Fang an diesem See\n"
"wog " FISH_INFO " Pfund.\n"
"Gefangen von: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Willst Du weiter angeln?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Naja, er wiegt " COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "...\n"
"Nicht schlecht, aber in diesem See\n"
"gibt es auch größere Brocken!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, Du hast doch gar keinen\n"
"Fisch gefangen! Weichei!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du willst einen anderen Köder?\n"
"Meinst Du, darauf kommt es an?\n"
"Man braucht Talent und Erfahrung!\n"
"Hör mir zu:" BOX_BREAK "Ich habe den Sachsen das Angeln\n"
"beigebracht. Seitdem sind es die\n"
"Angelsachsen! Alles klar?"
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was? Du möchtest ein paar Tricks\n"
"erfahren? Die kann ich Dir nicht\n"
"verraten. Die sind geheim.\n"
"Ehrlich!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was? Du willst wissen, ob ich ein\n"
"guter Angler bin?" BOX_BREAK "Klar doch! Ein echter Pro!\n"
"Weißt Du überhaupt, was das ist?\n"
"So wie du angelst, wohl kaum!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Verhaltensmaßregeln" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Benutzen Sie keine fremden\n"
"Köder.\n"
"2. Nicht ins Wasser..." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "3. Keine Hamster als Köder\n"
"verwenden!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow! Das ist ja ein echter\n"
"Brocken! Tatsächlich! Er wiegt\n"
COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "!" BOX_BREAK "Willst Du ihn behalten?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Komm wieder, wenn Du älter bist!\n"
"Dann sind auch die Fische größer...\n"
"Naja, oder auch nicht."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, Typ! Wir kennen uns doch!\n"
"Ist aber schon lange her!" BOX_BREAK UNSKIPPABLE "Wieviel Jahre waren das?\n"
"Sieben Jahre?! Was hast Du denn\n"
"die ganze Zeit getrieben?!" BOX_BREAK UNSKIPPABLE "Du bist mein einziger Kunde.\n"
"Ich mache fast kein Geschäft\n"
"mehr!\n"
"Obendrein werden meine Haare..." BOX_BREAK UNSKIPPABLE "Naja, äh, egal..." BOX_BREAK UNSKIPPABLE "Na gut, willst Du fischen gehen?\n"
"Es kostet nur " COLOR(RED) "20 Rubine" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was?" BOX_BREAK "Du willst woanders fischen\n"
"gehen?! Du bist wohl nicht\n"
"mehr ganz bei Trost?" BOX_BREAK "Wenn Du hier nicht angelst, geh\n"
"ich ja völlig Pleite!\n"
"Ganz im Ernst!"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was?" BOX_BREAK "Du willst mit Fliegen fischen?\n"
"Glaubst, dann läuft's besser?" BOX_BREAK "Bleib mal lieber bei den Würmern.\n"
"Ganz ehrlich!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was?" BOX_BREAK "Was meinst Du damit, daß Du\n"
"keine Fische siehst, weil das\n"
"Wasser zu trüb ist?" BOX_BREAK "So ein Schwachsinn!\n"
"An solchen Tagen macht Fischen\n"
"noch mehr Spaß!" BOX_BREAK "Du erwischst einen Fisch, wenn\n"
"Du es am wenigsten erwartest!\n"
"Das ist doch richtig genial!" BOX_BREAK "Ganz im Ernst!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, was soll das?\n"
"Paß doch auf!\n"
"Du bist ja total schusselig!\n"
"Dumpfbacke!" BOX_BREAK "Gib mir meine Mütze wieder!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okay!\n"
"Auf keinen Fall!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Was? Oh!\n"
"Du hast ja schon größere Viecher\n"
"an Land gezogen..." BOX_BREAK "Willst Du ihn trotzdem behalten?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ich wil ihn nicht! \n"
"Ich behalte ihn!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey! Was ist das denn für ein\n"
"komischer Fisch? Er wiegt auch\n"
COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "!" BOX_BREAK "Was willst Du damit machen?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Behalten!\n"
"Nicht behalten!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wow!" BOX_BREAK "Hast Du tatsächlich...\n"
"Unglaublich!\n"
"Du hast einen " COLOR(RED) "fremden Köder\n"
COLOR(DEFAULT) "erwischt!" BOX_BREAK "Was willst Du damit tun?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Damit angeln!\n"
"Wegwerfen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nun ja..." BOX_BREAK "Wow! Welch ein seltener Fisch!\n"
"Eine " COLOR(RED) "hylianische Forelle" COLOR(DEFAULT) "!" BOX_BREAK "Da kommt es nicht auf die Größe\n"
"an! Ich gebe Dir diesen Preis!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"In der letzten Zeit haben wir kaum\n"
"noch solche Fische gefangen. Ich \n"
"laß ihn lieber wieder schwimmen." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Verhaltensmaßregeln\n"
"1. Keine fremden Köder benutzen.\n"
"2. Keinen Dreck machen.\n"
"3. Ruhe!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! Hey!\n"
"Du kannst die Angel doch nicht\n"
"einfach mitnehmen!" BOX_BREAK "Wenn Du aufhören willst, dann\n"
"bringe sie zum Angelverleih\n"
"zurück! Ganz im Ernst!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Göttlich!!!\n"
"Dieser Fisch ist ja riesengroß!" BOX_BREAK "Der paßt in keine Pfanne!\n"
"Er ist sogar für meine Waage\n"
"zu groß. Er wiegt\n"
"bestimmt " COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "!" BOX_BREAK "Du willst ihn bestimmt behalten,\n"
"oder nicht?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Behalten!\n"
"Nicht behalten!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, Süßer!\n"
"Ich bin " COLOR(RED) "Byron" COLOR(DEFAULT) ", die Vogelscheuche!\n"
"Du hast bestimmt schon von meinem\n"
"tollen Gedächtnis gehört!" BOX_BREAK "Wenn Du ein neues Lied weißt -\n"
"raus damit!" BOX_BREAK "Dies ist das Lied, das Du beim\n"
"letzten Mal geflötet hast!" BOX_BREAK "Los dann!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich bin " COLOR(RED) "Byron" COLOR(DEFAULT) ", das musikalische\n"
"Vogelscheuchen-Genie! Wenn ich\n"
"ein Lied einmal gehört habe, \n"
"vergesse ich es nie mehr, Süßer!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Spiel das Lied, damit Du Balzac\n"
"rufen kannst!\n"
"Wenn er in der Nähe ist, dann\n"
"hilft er Dir, Süßer!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey! Bist Du nicht der Typ aus\n"
"dem Kokiri-Wald?\n"
"Mann, bist Du gewachsen!" BOX_BREAK "Okay, das ist Dein Lied..." BOX_BREAK "Was?" BOX_BREAK "Ich hab eben ein Elefantenhirn!\n"
"Du hast eher ein Hirn wie ein Sieb,\n"
"mein Guter! Nimm Deine Okarina\n"
"und flöte das Lied, Süßer!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Whoa! Du hast eine Okarina!\n"
"Hey, warum flötest Du mir nicht\n"
"was vor, Süßer?!" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Naja... Nicht so schlecht!\n"
"Ich werde die Melodie im Kopf\n"
"behalten!" BOX_BREAK "Ich kann mir jedoch höchstens\n"
"acht Noten merken.\n"
"Also für heute laß gut sein,\n"
"Süßer." EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du so einen Unsinn flötest,\n"
"gewinnst Du keinen Blumentopf,\n"
"Süßer!" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OH YEAHHH!!\n"
"Das ist es! Das geht ab!\n"
"Mir haut's den Vogel raus!" BOX_BREAK "Ich hab das nie vergessen!\n"
"Ich hab ja kein Stroh im Hirn!\n"
"Ich glaube, Du hast Dir eine\n"
"Belohnung verdient, Süßer!" BOX_BREAK "Ich hab eine prima Idee!" BOX_BREAK "Mein Bruder Balzac reist in ganz\n"
"Hyrule herum. Wenn Du ihn rufen\n"
"willst, dann spiele dieses Lied!" BOX_BREAK "Wenn er in der Nähe ist und es\n"
"hört, dann wird er Dir helfen!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, die Okarina!\n"
"Spiel ein Lied damit,\n"
"Süßer!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Mein Freund, Du spielst die\n"
"Okarina gut... Mmmh...!\n"
"Eine nette Melodie... Wir sollten\n"
"sie alle üben!" BOX_BREAK "Nimm dies hier als Lohn!\n"
"Wenn Dir mal wieder eine feine\n"
"Weise durch den Kopf schießt,\n"
"komm vorbei und spiel sie vor!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Wow, ein cooler Song,\n"
"Freund!" BOX_BREAK "\"Siiiiingin' in the raaaaaain...\"\n"
"Wirklich schön! " BOX_BREAK "Steck Dir das hier als Gage\n"
"für den abgefahrenen Gig ein!\n"
"Alles klar, wir sehen uns!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Hey, wir sind die Riesenfrösche!\n"
"Die berühmten, unerreichten\n"
"fünf fabulösen Froschtenöre!" BOX_BREAK "Bring uns zum Springen, damit wir\n"
"die Fliegen über uns erwischen!" BOX_BREAK "Okay?\n"
"Also los dann!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Junge, das war genial!\n"
"Perrrrrfekt!\n"
"Wir platzen gleich!" BOX_BREAK "Das hier ist doch genug als Dank,\n"
"oder nicht?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Naja, an dieses Lied kann ich mich\n"
"aber gar nicht erinnern, Süßer!\n"
"Warum? Weiß ich auch nicht!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Der größte Fang, der in diesem See \n"
"gemacht wurde, wog " FISH_INFO " Pfund.\n"
"Gefangen vom Besitzer des Sees!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was?\n"
"Du willst einen anderen\n"
"Köder benutzen?\n"
"Hey, was ist das denn?" BOX_BREAK "Das hast Du gerade erwischt?\n"
"Nach den Regeln darfst Du sowas\n"
"ja eigentlich nicht benutzen.\n"
"Aber, naja, was soll's..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WOW!\n"
"Der ist RIESIG! Ein neuer Rekord!\n"
"Der... Der wiegt ganze...\n"
COLOR(RED)  FISH_INFO " Pfund" COLOR(DEFAULT) "!" BOX_BREAK "Aaaaaaber! Der fremde Köder war\n"
"ein Verstoß gegen die Regeln!\n"
"Also gibt es auch keinen Preis!\n"
"Hehe!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Größter Fang: " FISH_INFO " Pfund.\n"
"Gefangen von: " NAME "\n"
"(HINWEIS: Disqualifiziert wegen\n"
"Benutzung eines fremden Köders!)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du bist ein netter Junge!\n"
"Aber erzähl es nicht weiter.\n"
"Ehrenwort?" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WAAAS!?" BOX_BREAK "Warum machst Du das mit mir?\n"
"Was denkst Du Dir eigentlich?" BOX_BREAK "So leicht kommst Du nicht davon!\n"
"Du zahlst Strafe, und zwar \n"
COLOR(RED) "50 Rubine" COLOR(DEFAULT) "!\n"
"Garantiert!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AARGH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Du" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hast mich" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "bezwungen!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Wie? Ach, Du bist es." BOX_BREAK "Hast Du mal die " COLOR(YELLOW) "Hymne der Sonne" COLOR(DEFAULT) "\n"
"gespielt?" BOX_BREAK "Ich habe Dir ja schon \n"
"erzählt, daß Du damit die Nacht \n"
"zum Tag und den Tag zur Nacht\n"
"machst - wann immer Du willst." BOX_BREAK "Wenn alles um Dich herum dunkel\n"
"ist, kannst Du damit wieder Licht\n"
"in die Welt bringen. Probier's!"
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Ich habe beim Graben einen Schatz\n"
"gefunden - der wird lang und kurz\n"
"und macht \"KLING\"!\n"
"Den behalt ich!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Des " COLOR(RED) "Totengräbers" COLOR(DEFAULT) " Tagebuch.\n"
"Willst Du es lesen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Wer immer dies liest, der möge\n"
"mein Grab betreten. Ihm gebe ich\n"
"meinen langen, kurzen " COLOR(RED) "Schatz" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Ich warte!\n"
"Boris" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Das ist auch besser so!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du hast einen Geist vernichtet!" BOX_BREAK "Willst Du ihn in einer\n"
"Flasche aufbewahren?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du willst ihn aufbewahren, besitzt\n"
"aber keine leere Flasche."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Für den Augenblick läßt Du\n"
"ihn gehen."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du hast ein Irrlicht gefangen!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Das Sonnenlicht, es schwindet\n"
"bei Nacht...\n"
"Erst am Tag ist wieder sein Feuer\n"
"entfacht." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Von Sonne zu Mond und zu Sonne\n"
"erneut..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Ewige Ruhe die lebenden Toten\n"
"erfreut." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ziemlich schöne Lyrik, nicht wahr?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ruhelose Seelen wandern ohne Wonne.\n"
"Gib Frieden mit der " COLOR(YELLOW) "Hymne der Sonne" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Da ist eine Inschrift auf diesem\n"
"Grabstein..." BOX_BREAK UNSKIPPABLE "Eine " COLOR(YELLOW) "geheime Weise" COLOR(DEFAULT) " der\n"
"Gebrüder Brahmstein!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das weltbeste Elixier! Sagen wir\n"
COLOR(RED) "100 Rubine" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du Deine Meinung änderst,\n"
"kannst Du ja wieder herkommen.\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast nicht genügend Rubine!\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "AARGH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "DU" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "HAST MICH" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "BEZWUNGEN!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE "Unglaublich!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Wie?\n"
"Du bist doch nicht einer von\n"
"Ganondorfs Schergen, oder?" BOX_BREAK UNSKIPPABLE "Als Gespenst muß ich mich so\n"
"komisch benehmen. Tut mir leid." BOX_BREAK UNSKIPPABLE "Alsdann, ich glaube, ich stelle\n"
"mich mal vor!\n"
"Ähem..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin einer der geisterhaften\n"
"Komponisten-Brüder von Kakariko." BOX_BREAK "Wie alle Hylianer, so dienten auch\n"
"wir dem König dieses Landes." BOX_BREAK "Wir, die Gebrüder Brahmstein,\n"
"waren beauftragt, die mystische\n"
"Macht der königlichen Familie zu\n"
"untersuchen." BOX_BREAK "Wir haben bis jetzt die Macht des\n"
"Triforce nicht erklären können." BOX_BREAK "Aber unsere \"" COLOR(RED) "Studien zur Macht\n"
"über die Zeit mittels Tönen\n"
"einer Okarina" COLOR(DEFAULT) "\" haben wir\n"
"fast abgeschlossen!" BOX_BREAK "Um ehrlich zu sein..." BOX_BREAK "Wir haben unsere Studien dazu\n"
"bereits beendet!" BOX_BREAK "Wir wären berühmt geworden, wenn\n"
"dieser widerliche Ganondorf nicht\n"
"versucht hätte, die Aufzeichnungen \n"
"zu stehlen." BOX_BREAK "Wir konnten es nicht zulassen, daß\n"
"er die Früchte unserer Arbeit an\n"
"sich reißt!" BOX_BREAK "Daher haben wir unser Leben\n"
"riskiert, um diese Geheimnisse zu\n"
"bewahren." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Möchtest Du unsere Geschichte\n"
"noch einmal hören?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "AARGH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "ICH BIN" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "WIEDER" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "BESIEGT!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Was? Du schon wieder?" BOX_BREAK UNSKIPPABLE "Wenn ich Dich so ansehe, muß ich\n"
"an Prinzessin Zelda denken." BOX_BREAK UNSKIPPABLE "Da Du offenbar mit der\n"
"Königsfamilie in Kontakt stehst,\n"
"kann ich Dir ein wenig mehr über\n"
"uns erzählen." BOX_BREAK UNSKIPPABLE "Damals nannten uns die Leute\n"
"überall \"Die tadellosen Tonsetzer\",\n"
"da wir viele Meisterwerke\n"
"komponiert haben." BOX_BREAK UNSKIPPABLE "Aber wir waren nicht nur\n"
"Komponisten!" BOX_BREAK UNSKIPPABLE "Wir hatten auch einen Auftrag!\n"
"Wir sollten die geheimnisvollen\n"
"Kräfte der hylianischen \n"
"Königsfamilie untersuchen." BOX_BREAK UNSKIPPABLE "Unsere Namen wären in die\n"
"Geschichte Hyrules eingegangen,\n"
"wenn wir unsere Studien beendet\n"
"hätten." BOX_BREAK UNSKIPPABLE "Wir haben diese Studien natürlich\n"
"stets streng geheim gehalten!" TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "AARGH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "ICH BIN" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "SCHON WIEDER" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "TOT!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Was? Du schon wieder?" BOX_BREAK UNSKIPPABLE "Wenn ich Dich so anschaue, muß\n"
"ich an Prinzessin Zelda denken..." BOX_BREAK UNSKIPPABLE "Wenn Du mit der Königsfamilie\n"
"näher bekannt bist, kann ich Dir\n"
"ja etwas mehr über uns erzählen." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Bruder und ich studierten\n"
"verschiedene Melodien: Eine, den\n"
COLOR(RED) "Mond zu beschwören" COLOR(DEFAULT) ", und eine\n"
"andere, die " COLOR(RED) "Sonne herbeizurufen" COLOR(DEFAULT) "!" BOX_BREAK "Da Du von einem Angehörigen des\n"
"Königshauses geschickt wurdest,\n"
"will ich Dir von den Ergebnissen\n"
"unserer Untersuchungen berichten." BOX_BREAK "Sie stehen geschrieben auf dem\n"
COLOR(RED) "königlichen Grabstein" COLOR(DEFAULT) "." BOX_BREAK "Zeige auf musikalische Weise, daß\n"
"Du in königlichem Auftrag\n"
"unterwegs bist, wenn Du auf dem\n"
"Triforce vor dem Grab stehst." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zzzzzzzz..." BOX_BREAK "Malon... geht es gut...\n"
"Grummel... Murmel...\n"
"Tut mir leid, wenn Du Dir Sorgen\n"
"machst..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Lon Lon-Farm wurde von Basil\n"
"übernommen und heißt jetzt\n"
COLOR(RED) "Basil-Farm" COLOR(DEFAULT) "." BOX_BREAK "Mich hat man hinausgeworfen -\n"
"schau mich nur an! Meine Tochter\n"
"Malon arbeitet noch immer dort." BOX_BREAK "Ich mache mir Sorgen..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast Malon gerettet? Danke!\n"
"Dann kann ich ja wieder\n"
"auf die Farm zurück."
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hey, Kleiner!" QUICKTEXT_DISABLE "\n"
"Was hast Du hier zu suchen?" BOX_BREAK UNSKIPPABLE "Ich bin " COLOR(RED) "Boris, der Totengräber" COLOR(DEFAULT) "!\n"
"Ich sehe vielleicht zum Fürchten\n"
"aus, aber ich bin ganz harmlos..." BOX_BREAK UNSKIPPABLE "Laß mich Dir ein bißchen von\n"
"meinem Nebenjob erzählen:" BOX_BREAK UNSKIPPABLE "Ich, der " COLOR(RED) "Totengräber Boris" COLOR(DEFAULT) ",\n"
"lade ein zur...\n"
COLOR(LIGHTBLUE) "Grausigen Grabgrusel-Tour" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Was kommt dabei raus?!\n"
"Was kommt dabei raus?!\n"
"Lasset uns graben und\n"
"wir finden's heraus!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du, daß ich hier grabe?\n"
COLOR(RED) "10 Rubine" COLOR(DEFAULT) " für ein Loch.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Laß mal bleiben!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Nein, hier ist nichts!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x23") "Zurück, " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...\n"
"Etwas Schreckliches ist passiert!\n"
"Der " COLOR(RED) "Schattendämon" COLOR(DEFAULT) " ist\n"
"aus seinem Gefängnis entkommen!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", die Gründerin Kakarikos,\n"
"hatte den Schattendämon einst auf\n"
"den Grund des Brunnens verbannt\n"
"und dort eingeschlossen..." BOX_BREAK UNSKIPPABLE "Doch die Kraft des Dämons wurde\n"
"in letzter Zeit immer stärker, so\n"
"daß das Siegel brach und er wieder\n"
"in die Oberwelt entkommen konnte!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich werde mich um das Dorf\n"
"kümmern!\n"
"Ich zähle auf Dich,\n"
NAME "!"
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x25") "Gebrüder Brahmstein,\n"
SHIFT("\x2E") "königliche Tonsetzer.\n"
SHIFT("\x33") "Johann, der Ältere\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x25") "Gebrüder Brahmstein,\n"
SHIFT("\x2E") "königliche Tonsetzer.\n"
SHIFT("\x30") "Ludwig, der Jüngere\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4A") "Königsgrab" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Dieses Gedicht wurde im Gedenken\n"
SHIFT("\x0A") "an die teuren Verstorbenen der\n"
SHIFT("\x14") "königlichen Familie verfasst." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du hast die Kreatur des Bösen\n"
"bezwungen und den Fluch vom\n"
"Schattentempel genommen!\n"
"Hab Dank dafür, " NAME "!" BOX_BREAK UNSKIPPABLE "Denn ich bin nicht allein\n"
"Prinzessin Zeldas Vertraute,\n"
"sondern auch jene Weise, die\n"
"über den Tempel wacht!"
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x1B") "Bitte suche die Prinzessin!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", der Auserwählte!\n"
"Endlich!" BOX_BREAK UNSKIPPABLE "Alle " COLOR(RED) "Sechs Weisen " COLOR(DEFAULT) "sind erweckt!\n"
"Es ist soweit: Der entscheidende\n"
"Kampf gegen den Großmeister des\n"
"Bösen soll nun beginnen!" BOX_BREAK UNSKIPPABLE "Zuvor jedoch sollst Du jene\n"
"treffen, die auf Dich wartet..." BOX_BREAK UNSKIPPABLE "Sie harrt Deiner in der\n"
COLOR(LIGHTBLUE) "Zitadelle der Zeit" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die Shiekahs waren seit\n"
"Generationen die getreuen Diener\n"
"des Königsgeschlechts von Hyrule.\n"
"Jedoch..." BOX_BREAK UNSKIPPABLE "...auf den Tag genau vor sieben\n"
"Jahren griff Ganondorf das Schloß\n"
"an... Nach kurzem Kampf\n"
"schon ergab sich Hyrules König." BOX_BREAK UNSKIPPABLE "Ganondorf wollte den Schlüssel\n"
"zum Heiligen Reich, den\n"
"bestgehüteten Schatz der\n"
"Königsfamilie: Die Okarina der Zeit!" BOX_BREAK UNSKIPPABLE "Meine Aufgabe war, Prinzessin \n"
"Zelda zu retten und sie vor dem\n"
"Zugriff Ganondorfs zu bewahren." BOX_BREAK UNSKIPPABLE "Als ich Dich damals bei unserer\n"
"Flucht aus dem Schloß sah, warst\n"
"Du nur ein kleiner Junge..." BOX_BREAK UNSKIPPABLE "Jetzt ist aus Dir ein stolzer\n"
"Held geworden!"
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Gehe nun! Stehe Prinzessin\n"
"Zelda an meiner Stelle zur Seite\n"
"und beschütze sie." BOX_BREAK UNSKIPPABLE "Meine Kraft soll Dich begleiten.\n"
"Ich lege sie in dieses " COLOR(BLUE) "Amulett" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun? Ist Kiki fröhlich und\n"
"zufrieden? Soll ich sie mir\n"
"einmal anschauen?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Ich bin der " COLOR(RED) "Chef der Zimmerleute" COLOR(DEFAULT) ".\n"
"Impa hat uns angestellt, diesen\n"
"Ort in eine eindrucksvolle Stadt \n"
"zu verwandeln!" BOX_BREAK UNSKIPPABLE "Aber die jungen Kerle von heute\n"
"haben keinen Ehrgeiz mehr!\n"
"Weißt Du, was ich meine, Junge?" BOX_BREAK UNSKIPPABLE "Meine Arbeiter rennen nur planlos\n"
"im Dorf herum und machen bei\n"
"ihrer Arbeit keinerlei Fortschritte!" BOX_BREAK UNSKIPPABLE "Sogar mein Sohn ist ein fauler\n"
"Sack und hängt den ganzen Tag\n"
"nur in der Gegend rum!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich sage Dir: Die jungen\n"
"Leute sind zu nichts mehr \n"
"zu gebrauchen!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schau Dir die Kleine da drüben an.\n"
"Sie kümmert sich aufopferungsvoll\n"
"um ihre Hühner, und das, obwohl sie \n"
"gegen Federn allergisch ist." BOX_BREAK "Was für ein Mädchen! Ich würde\n"
"ihr gern helfen, ich fühle mich zur\n"
"Zeit wie ein Wohltäter! Geht's Dir\n"
"nicht auch so?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wir müssen uns keine Sorgen\n"
"machen...\n"
"Die Prinzessin ist jetzt in\n"
"Sicherheit."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Schon bald wirst Du Prinzessin\n"
"Zelda von Angesicht zu Angesicht\n"
"gegenübertreten. Sie wird Dir\n"
"alles erklären..." BOX_BREAK UNSKIPPABLE "Dann, wenn die Sechs Weisen den\n"
"Großmeister des Bösen verbannt\n"
"haben und wieder Frieden in \n"
"Hyrule eingekehrt ist!"
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe, Junge...\n"
"Du bist gut zu Fuß, was?" BOX_BREAK UNSKIPPABLE "Zur Belohnung werde ich Dir\n"
"meinen " COLOR(RED) "Fanghaken" COLOR(DEFAULT) " anvertrauen." BOX_BREAK UNSKIPPABLE "Damit wirst Du nun an Orte\n"
"gelangen, die bisher außerhalb\n"
"Deiner Reichweite lagen." BOX_BREAK UNSKIPPABLE "Besuch mich doch mal wieder,\n"
"wenn Du in der Gegend bist. Dann\n"
"gebe ich Dir wieder etwas\n"
"Wertvolles!" BOX_BREAK UNSKIPPABLE "Noch etwas: Sei auf Deinem\n"
"Rückweg sehr vorsichtig..."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du bist ja wieder da, Junge...\n"
"Hat Dir mein Geschenk\n"
"etwas genützt?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x3A") "Die Zeit beträgt\n"
SHIFT("\x4B")  RACE_TIME "!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sieht aus, als würdest\n"
"Du es überstehen..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich glaube, Impa ging zum \n"
COLOR(PURPLE) "Schattentempel" COLOR(DEFAULT) ", um ihn wieder zu\n"
"versiegeln. Ohne Hilfe wird\n"
"sie dort in großer Gefahr sein!" BOX_BREAK UNSKIPPABLE  NAME "!\n"
"Impa ist eine der Sechs Weisen.\n"
"Vernichte den Schattendämon und\n"
"rette Impa!" BOX_BREAK UNSKIPPABLE "Es gibt einen Zugang zum\n"
"Schattentempel hinter dem\n"
"Friedhof von Kakariko." BOX_BREAK UNSKIPPABLE "Alles, was ich für Dich tun kann,\n"
"ist, Dich die Melodie zu lehren, die\n"
"Dich zum Schattentempel bringt..." BOX_BREAK UNSKIPPABLE "Diese Melodie führt Dich in die\n"
"unendliche Dunkelheit, die sogar die\n"
"Zeit absorbiert... Höre nun\n"
"die " COLOR(PURPLE) "Nocturne des Schattens" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich mag es, im Rhythmus dieser\n"
"Mühle Musik zu machen!\n"
"Das macht Riesenspaß!" BOX_BREAK "Ich liebe Musik!\n"
"Ich liebe diese Mühle!" BOX_BREAK "Ich will selbst einmal etwas\n"
"komponieren. Vielleicht eine\n"
"Melodie, die von der Mühle\n"
"oder vom Wind erzählt!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist eine sehr schöne Melodie...\n"
"Huch! Jetzt geht es aber\n"
"doch zu schnell!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!" BOX_BREAK "Ich werde nie vergessen, was vor\n"
"sieben Jahren geschehen ist!\n"
"Grrrrrrrrr!" BOX_BREAK "Daran ist nur dieser Typ\n"
"mit seiner Okarina schuld!\n"
"Wenn er sich nochmal sehen\n"
"läßt, kann er etwas erleben!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Was?! Du besitzt eine Okarina!" BOX_BREAK UNSKIPPABLE "Das darf doch nicht wahr sein!" BOX_BREAK UNSKIPPABLE "Das erinnert mich an diesen\n"
"Tag vor genau sieben Jahren!" BOX_BREAK UNSKIPPABLE "Damals kam so ein Rattengesicht\n"
"hier herein und hat ein " COLOR(PURPLE) "seltsames" COLOR(BLUE) "\n"
COLOR(PURPLE) "Lied" COLOR(DEFAULT) " gespielt. Das hat alles \n"
"durcheinander gebracht!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was soll ich nur tun!?\n"
"Meine " COLOR(RED) "Hühner" COLOR(DEFAULT) " sind alle\n"
"davongeflogen!" BOX_BREAK "Bitte!\n"
"Hilf mir, die Hühner wieder\n"
"einzusammeln!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das machst Du sehr gut!\n"
"Bring doch bitte noch die\n"
"anderen vier zurück!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prima! Du bist ein echter\n"
"Hühnerfänger!\n"
"Bring doch auch die anderen\n"
"drei zurück!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Klasse! Du bist richtig lieb!\n"
"Bring doch noch die anderen\n"
"zwei zurück! Bitte!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Super! Jetzt hast Du fast alle!\n"
"Bring doch bitte noch das letzte\n"
"Huhn zurück!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Danke, daß Du meine Hühner\n"
"eingesammelt hast. Ich bin nämlich\n"
"allergisch und bekomme einen\n"
"Ausschlag, wenn ich sie anfasse." BOX_BREAK UNSKIPPABLE "Dafür, daß Du mir geholfen\n"
"hast, gebe ich Dir etwas\n"
"sehr Wertvolles!" EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, was machst Du denn da?!\n"
"Sammle sie ein oder zahle dafür!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ärgere die Hühner bitte nicht!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe ein neues Huhn\n"
"gezüchtet! Ich nenne es " COLOR(RED) "Kiki" COLOR(DEFAULT) ", und \n"
"ich bekomme keine Allergie, wenn\n"
"ich es anfasse." BOX_BREAK UNSKIPPABLE "Es paßt auch in die Hosentasche\n"
"und ist praktisch, um faule\n"
"Langschläfer aufzuwecken! Schon\n"
"mal was davon gehört?" BOX_BREAK UNSKIPPABLE "Es hat Spaß dabei, richtig laut zu\n"
"gackern. Ganz besonders, wenn es\n"
"eine Schlafmütze aufwecken darf!" BOX_BREAK UNSKIPPABLE "Aber... so ganz zufrieden ist\n"
"Kiki im Augenblick noch nicht..." BOX_BREAK UNSKIPPABLE "Du... Du siehst aus, als\n"
"hättest Du ein glückliches\n"
"Händchen für Hühner!" BOX_BREAK UNSKIPPABLE "Hier, nimm dieses Ei mit.\n"
"Ist Kiki ausgeschlüpft, dann bring\n"
"es irgendwann zu mir zurück und\n"
"ich schaue, wie es sich fühlt." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was hältst Du davon? \n"
"Willst Du es ausprobieren?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie schade... Haben die Hühner\n"
"immer nach Dir gehackt, als Du\n"
"noch kleiner warst?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hehehe, Junge!\n"
"Bist Du gut zu Fuß?" BOX_BREAK "Ich seh vielleicht nicht so aus,\n"
"aber ich bin ganz schön schnell!\n"
"Laß uns um die Wette laufen! \n"
"Wenn Du es Dir zutraust..."
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bitte sorge gut für Kiki!\n"
"Okay?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, Kiki sieht ja sehr gesund und\n"
"fröhlich aus. Es muß eine arge\n"
"Schlafmütze geweckt haben!" BOX_BREAK UNSKIPPABLE "Das hast Du gut gemacht!\n"
"Ich werde Dir ein sehr seltenes\n"
"Hühnchen mitgeben, wenn Du willst." BOX_BREAK UNSKIPPABLE "Ich nenne es " COLOR(RED) "Henni" COLOR(DEFAULT) ", es hat einmal\n"
"meinem Bruder gehört. Die blauen \n"
"Federn sehen sehr schön aus,\n"
"nicht wahr? Es ist sooooo süß!" BOX_BREAK UNSKIPPABLE "Seit mein Bruder verschwunden ist,\n"
"gackert Henni gar nicht mehr!" TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Möchtest Du " COLOR(RED) "Henni" COLOR(DEFAULT) " behalten?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Also magst Du Kiki doch lieber.\n"
"Okay, dann behalte sie noch für\n"
"eine Weile!" EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eine alte Vettel betreibt den\n"
"Hexenladen hinter diesem Shop.\n"
"Nimm die Tür links neben der\n"
"Theke, wenn Du hinein willst!" EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Bruder muß sehr einsam\n"
"gewesen sein..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe gehört, daß die\n"
COLOR(ADJUSTABLE) "Verlorenen Wälder" COLOR(DEFAULT) " ein mysteriöser\n"
"Ort mit vielen, noch seltsameren\n"
"Gewächsen sind." BOX_BREAK "Ich würde gern mal eine Medizin\n"
"mit einem der seltsamen Gewächse\n"
"zusammenbrauen, die es dort gibt." BOX_BREAK "Ich sehe vielleicht nicht mehr so\n"
"gut, aber meine Nase ist noch\n"
"sehr fein! Hihihi!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schnüffel..." BOX_BREAK "Welch ein seltsamer Duft..." BOX_BREAK "Du mußt etwas gefunden haben!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dieser Taugenichts! \n"
"Er mußte unbedingt in den Wald\n"
"gehen...\n"
TEXT_SPEED("\x01") "Hmmm..." TEXT_SPEED("\x00") " Ich verstehe." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, gib das sofort her!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wie schade... Ich brauche nur\n"
"ein bißchen..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wenn Du den Dummkopf siehst,\n"
"dann gib ihm dies. Es ist die\n"
"stärkste Medizin, die ich je \n"
"gebraut habe." BOX_BREAK UNSKIPPABLE "Aber sie wirkt nicht bei jedem!" EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, Kleiner! Wenn Du die Medizin\n"
"mitnehmen möchtest, brauchst Du\n"
"etwas zum Aufbewahren!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es heißt, gegen Dummheit ist kein\n"
"Kraut gewachsen...\n"
"Ich glaube, das ist wahr..."
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich komme nicht mehr vom Dach\n"
"herunter. Aber dafür kann ich\n"
"Tag und Nacht den " COLOR(RED) "Todesberg\n"
COLOR(DEFAULT) "anschauen!"
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich komm hier nicht mehr runter.\n"
"Ich kann nur noch dauernd die\n"
"Sterne anschauen."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Siehst Du das von hier aus? \n"
"Irgendetwas passiert auf dem\n"
COLOR(RED) "Todesberg" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Siehst Du das von hier aus?\n"
"Auf dem " COLOR(RED) "Todesberg " COLOR(DEFAULT) "ist alles\n"
"wieder wie früher!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eigentlich will ich gar nicht mehr \n"
"von diesem Dach herunter!\n"
"Egal was passiert, ich schaue mir\n"
"lieber den Todesberg an."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey! Schön, Dich wiederzusehen!\n"
"Ich gebe Dir dieses\n"
"Erinnerungsstück."
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Für einen guten Überblick drückst\n"
"Du einfach " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " und schaust mit\n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " umher."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey! Betrittst Du fremde Häuser\n"
"immer unaufgefordert? Haben Dir \n"
"Deine Eltern keine Manieren\n"
"beigebracht?" BOX_BREAK UNSKIPPABLE  SHIFT("\x4E") "Na, egal..." BOX_BREAK UNSKIPPABLE "Hast Du die Frau hinter dem\n"
"Haus gesehen? Sie hat's zur Zeit\n"
"nicht leicht." BOX_BREAK UNSKIPPABLE  SHIFT("\x4E") "Na, egal..." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sollte die Frau mal etwas über\n"
"Hühner erzählen, hör ihr gut zu."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Macht es Dir Spaß, fremde Leute\n"
"zu so später Stunde noch zu\n"
"belästigen? Du hast wohl gar\n"
"keine Erziehung genossen." BOX_BREAK UNSKIPPABLE  SHIFT("\x4E") "Na, egal..." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die Frau kümmert sich um die\n"
"Hühner, reagiert aber allergisch\n"
"auf Federn." BOX_BREAK SHIFT("\x4E") "Na, egal..."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey! Junge! Du bist fast\n"
"erwachsen und betrittst ein\n"
"fremdes Haus ohne Erlaubnis?!\n"
"Ich will mit Deinen Eltern reden!" BOX_BREAK UNSKIPPABLE  SHIFT("\x4E") "Na, egal..." BOX_BREAK UNSKIPPABLE "Das hier ist sowieso nicht mein\n"
"Haus. Es ist das Haus\n"
"der " COLOR(RED) "mächtigen Impa" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Die mächtige Impa ging zum\n"
COLOR(RED) "Friedhof" COLOR(DEFAULT) ", um eine widerliche\n"
"Kreatur zu bezwingen." BOX_BREAK UNSKIPPABLE "Seit Ganondorf aufgetaucht ist,\n"
"wimmelt es nämlich von\n"
"ekligen Kreaturen!" BOX_BREAK UNSKIPPABLE "Nur die mächtige Impa hat für\n"
"Frieden in unserem Dorf sorgen\n"
"können. Merk Dir das gut, mein \n"
"Junge!" BOX_BREAK UNSKIPPABLE  SHIFT("\x50") "Nun gut." BOX_BREAK UNSKIPPABLE "Apropos Impa: Sie ist noch immer \n"
"nicht zurück. Ich frage mich, was\n"
"da passiert ist!" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich habe gehört, daß der " COLOR(RED) "Geist\n"
"des Totengräbers" COLOR(DEFAULT) " öfters noch\n"
"auf dem Friedhof hinter dem Dorf\n"
"herumspukt..." BOX_BREAK SHIFT("\x14") "Aber das ist nicht so wichtig."
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, Kleiner! Bist Du zum ersten\n"
"Mal in Kakariko?" BOX_BREAK UNSKIPPABLE "Die mächtige " COLOR(RED) "Impa" COLOR(DEFAULT) ", eine großartige\n"
"Frau, hat das Dorf für einfache\n"
"Leute wie uns erbauen lassen." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Fühle Dich ganz wie zu Hause.\n"
"Das Essen ist allerdings\n"
"noch nicht fertig!"
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die mächtige Impa ist nicht hier.\n"
"Ob etwas passiert ist?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wir alle haben Schweres\n"
"durchgemacht. Aber wir möchten\n"
"das lieber für uns behalten." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Schau Dir den Bärtigen auf dem\n"
"Bett an. Ich wette, sogar einer\n"
"wie er hat seine Probleme..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Der Bärtige ist wieder zur Farm\n"
"zurück.\n"
"Er sah richtig glücklich aus!"
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Es ist jetzt " TIME " Uhr!\n"
"Die richtige Zeit, um Dir etwas\n"
"über das Dorf zu erzählen!" BOX_BREAK UNSKIPPABLE "Zeldas Dienerin, die mächtige\n"
COLOR(RED) "Impa" COLOR(DEFAULT) ", erbaute dieses Dorf für\n"
"einfache Leute wie uns." BOX_BREAK UNSKIPPABLE "Noch wohnen hier wenige,\n"
"aber eines Tages wird es genau\n"
"so lebhaft sein wie in Hyrule!\n"
"Oh ja, das wird es!" BOX_BREAK UNSKIPPABLE "Steige die " COLOR(RED) "Stufen im Norden \n"
"des Dorfes" COLOR(DEFAULT) " hinauf.\n"
"Dort gelangst Du zu dem Paß,\n"
"der zum Todesberg führt." BOX_BREAK UNSKIPPABLE "Aber Du brauchst des Königs\n"
"Erlaubnis, um diesen Weg nehmen\n"
"zu können."
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist jetzt genau " TIME " Uhr."
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist jetzt " TIME " Uhr.\n"
"Ach, übrigens: Weißt Du, was im\n"
"Schloß passiert ist?"
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, Junge, was treibst Du Dich\n"
"hier mitten in der Nacht herum?" BOX_BREAK UNSKIPPABLE "Ah, ich verstehe. Du willst Deinen\n"
"Mut testen! Du willst bestimmt...\n"
"auf den Friedhof!" BOX_BREAK UNSKIPPABLE "Moment mal! Was rede ich\n"
"eigentlich mit so einem\n"
"Milchbubi? Ich muß Wache\n"
"stehen und meinen Mund halten!" TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist jetzt " TIME " Uhr.\n"
"Genau die richtige Zeit, um\n"
"Gräber zu besuchen!" BOX_BREAK "Geh nach Osten zum " COLOR(RED) "Friedhof" COLOR(DEFAULT) ".\n"
"Legenden besagen, man könne die\n"
"ruhelosen Seelen mit einem\n"
COLOR(BLUE) "königlichen Schlaflied" COLOR(DEFAULT) " besänftigen..."
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein komischer Typ lebt in der \n"
"Windmühle. Warst Du schon bei\n"
"ihm, großer Held?"
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Menschen sind widerlich. \n"
"Meine Eltern sind widerlich.\n"
"Du bist bestimmt auch widerlich!"
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wir arbeiten den ganzen Tag lang\n"
"auf verschiedenen Baustellen hier\n"
"im Dorf. Es dauert wohl noch eine\n"
"Weile, bis alles fertig ist." BOX_BREAK "Unser Chef ist ein ziemlicher\n"
"Sklaventreiber!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich komme um vor Hunger!\n"
"Laß uns sofort etwas essen!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jeder von ihnen arbeitet nur halb\n"
"so viel, wie er sollte. Aber sie\n"
"wollen immer eine\n"
"doppelte Portion essen!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Irrlicht   30 Rubine\n"
COLOR(DEFAULT) "Dies ist ein Geist in einer Flasche. \n"
"Verkaufe ihn an jemanden, der\n"
"solch verrückte Dinge mag." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Irrlicht  30 Rubine" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meine Hühner sind davongerannt!\n"
"Bitte fange noch sechs weitere!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME "!\n"
"Das Schiff sinkt!\n"
"Spring ab!\n"
"Rette Dich auf festen Boden!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe noch nicht alle Hühner!\n"
"Bitte fange noch fünf ein!"
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Mach bloß keinen Ärger!\n"
"Ich sag's Boris!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Schau Dir das an, Kleiner!\n"
"Meine schönen, zarten Hände sind\n"
"von der Arbeit ganz rissig!\n"
"Schnief..."
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Job, bei dem Du viel Geld für\n"
"wenig Arbeit bekommst... Da fällt\n"
"mir nur Diebstahl ein... Du findest,\n"
"das wäre keine gute Idee?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich habe gehört, das Haus\n"
"unseres Chefs liegt direkt hinter\n"
"diesem. Aber er will nicht, daß wir\n"
"es wissen."
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hast Du " COLOR(RED) "Boris" COLOR(DEFAULT) " gesehen, der auf\n"
"dem Friedhof lebt?" BOX_BREAK "Es ist jetzt " TIME " Uhr. Er schläft\n"
"wahrscheinlich in seiner Hütte." BOX_BREAK "Warum schlägst Du nicht ein\n"
"bißchen die Zeit tot, bis es\n"
"Abend wird?"
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich komme um vor Hunger!\n"
"Ist das Essen schon fertig?\n"
"Es ist schon " TIME " Uhr!"
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "In diesem Haus lebte einst\n"
"die " COLOR(RED) "mächtige Impa" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Es ist nun für alle Dorfbewohner\n"
"geöffnet. Du kannst auch hinein!" TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dieses Dorf gehörte einst den\n"
COLOR(BLUE) "Shiekah" COLOR(DEFAULT) ", aber jetzt kann jeder\n"
"hier leben."
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich schwöre,\n"
"ich habe ihn gesehen!" BOX_BREAK "Ich habe den Geist von Boris, dem\n"
"Totengräber, im Grab\n"
"verschwinden sehen! Man sagt, er\n"
"lagere viel " COLOR(RED) "Wertvolles" COLOR(DEFAULT) " dort!"
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Da ist er! Er ist es!\n"
"Er fiel vom Himmel, umgeben\n"
"von blauem Feuer!" BOX_BREAK "Glaubst Du mir?"
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Kein Mensch glaubt mir, was ich in\n"
"den letzten sieben Jahren erzählt\n"
"habe!"
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das Feuer hätte uns fast\n"
"vernichtet! Aber gemeinsam haben\n"
"wir es gelöscht! Gute Arbeit,\n"
"denkst Du nicht auch?"
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hahaha!" BOX_BREAK "Schau Dir den an! Seit er aus\n"
"dem Schloß entkommen konnte,\n"
"ist er noch ängstlicher!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hahaha!" BOX_BREAK "Er muß schlimme Sachen gesehen\n"
"haben!\n"
"Hahaha!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hahaha!\n"
"Das sind vielleicht komische\n"
"Klamotten, Mann!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hahaha!\n"
"Wenn die Zeiten hart sind, ist\n"
"Lachen die beste Medizin!\n"
"Das hat mein Alter immer gesagt!"
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schau her! Ich bin ganz oben!\n"
"Ich mag es gar nicht, wenn jemand\n"
"höher hinaus will! Ich muß immer\n"
"ganz oben sein!"
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn ich hier oben einschlafe,\n"
"falle ich bestimmt runter..."
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Windmühle pumpt das Wasser\n"
"aus dem Brunnen nach oben." BOX_BREAK "Doch jetzt ist er ausgetrocknet.\n"
"Hmmm..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die Frau hier ist wirklich\n"
"großzügig. Sie hat sich sogar um\n"
"die Zimmerleute gekümmert, als \n"
"sie noch hier waren!"
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist lange her...\n"
"Da gab es hier einen Mann, von\n"
"dem man sagte, er besäße das \n"
COLOR(PURPLE) "Auge der Wahrheit" COLOR(DEFAULT) "!" BOX_BREAK "Heutzutage muß man schon selbst\n"
"ein ganz besonderes Gespür\n"
"entwickeln, um die Wahrheit zu\n"
"erkennen..." BOX_BREAK "Aber der Typ hat das irgendwie\n"
"anders gemacht..." BOX_BREAK "Sein Haus stand da, wo jetzt der\n"
"Brunnen ist..."
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die Leute in der Gegend\n"
"erzählen von einer\n"
COLOR(RED) "sagenhaft reichen Familie" COLOR(DEFAULT) ",\n"
"die einst hier lebte." BOX_BREAK "Aber die ganze Familie war\n"
"verflucht, sagt man...\n"
"Wegen ihrer unermeßlichen\n"
"Habsucht!" BOX_BREAK "Wer weiß schon, was mit jenen\n"
"passiert, die von unstillbarer\n"
"Gier besessen sind!"
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey..." BOX_BREAK "Welch eine Nervensäge, die uns da \n"
"stört... Denkst Du das nicht\n"
"auch, meine Liebe?"
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey..." BOX_BREAK "Er verletzt unsere Privatsphäre...\n"
"Findest Du nicht auch, Liebling?"
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Schau ihn an, den Bärtigen.\n"
"Ich glaube, sie haben ihn von der\n"
"Farm gejagt..." TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Er hängt immer nur faul herum,\n"
"den ganzen Tag lang.\n"
"Das ist ziemlich gedankenlos in\n"
"derart schlimmen Zeiten!"
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Der Bärtige erinnert\n"
"mich irgendwie an meinen\n"
"kleinen Richard..." BOX_BREAK "Wie bitte? Du hast nie etwas von\n"
"meinem kleinen Richard gehört?\n"
"Er war so ein liebes Hundchen! Du\n"
"kennst ihn wirklich nicht?"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh nein! Deine verflixte Okarina\n"
"ist ein Instrument des Teufels!\n"
"Grrrrr!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Du hast einen Nachtschwärmer\n"
"gefangen! Verkaufe ihn im\n"
COLOR(RED) "Gespenstermarkt " COLOR(DEFAULT) "zu einem\n"
"ordentlichen Preis!"
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Halt! Bleib, wo Du bist!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun, Kleiner?"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Kleiner! Warte eine Sekunde,\n"
"dann öffne ich Dir das Tor."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Unterschätz uns nicht!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich bin beeindruckt. Um an unseren\n"
"Wachen vorbeizukommen, muß man\n"
"schon sehr geschickt sein." BOX_BREAK UNSKIPPABLE "Ich habe immer gedacht, alle Typen\n"
"außer Ganondorf wären ziemliche\n"
"Waschlappen... Aber ich muß\n"
"meine Meinung ändern!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Unsere Anführerin Naboru" COLOR(DEFAULT) "\n"
"hat mir die Verantwortung für\n"
"diese Festung übertragen." BOX_BREAK UNSKIPPABLE "Naboru ist die Stellvertreterin\n"
"des mächtigen Ganondorf,\n"
"des Herrn der Gerudo-Kriegerinnen." BOX_BREAK UNSKIPPABLE "Sie ist gerade auf dem Weg zum\n"
COLOR(YELLOW) "Geistertempel" COLOR(DEFAULT) ", der sich jenseits\n"
"der Wüste befindet. Sie vermutet\n"
"dort ein wertvolles Relikt." BOX_BREAK UNSKIPPABLE "Du willst also einer von uns\n"
"werden, was? Na gut, Du hast\n"
"Deine Fähigkeiten bewiesen! \n"
"Du bist nun ein Gerudo!" BOX_BREAK UNSKIPPABLE "Nimm dies. Damit kannst Du Dich\n"
"in der Festung frei bewegen!" EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ab jetzt kannst Du das Tor zur\n"
"Wüste durchschreiten,\n"
"wann immer Du willst." BOX_BREAK "Dort findest Du den " COLOR(YELLOW) "Geistertempel" COLOR(DEFAULT) "," COLOR(YELLOW) " \n"
COLOR(DEFAULT) "in dem sich die herrliche Naboru\n"
"zur Zeit aufhält."
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Weichei!" QUICKTEXT_DISABLE "\n"
"Hinein mit Dir!\n"
"Und halt die Klappe!"
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich weiß zwar nicht, woher Du \n"
"kommst, aber Du mußt ganz schön \n"
"mutig sein, wenn Du Dich an den\n"
"Wachen vorbeitraust!" BOX_BREAK UNSKIPPABLE "Meine anderen Kumpels sind\n"
"auch irgendwo eingesperrt." BOX_BREAK UNSKIPPABLE "Befreie uns bitte alle!" BOX_BREAK UNSKIPPABLE "Aber sei vorsichtig! Hier gibt's\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "jede" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Menge" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
COLOR(RED) "Gerudo-Wächterinnen" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Hey!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Paß auf!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Portal in die Vergangenheit" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x25") "Portal in die Gegenwart" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D") "Portal in die Zukunft" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\xEC") "Den rechten Weg, den zeig ich Dir,\n"
"denn Du hast dafür kein Gespür.\n"
"Nun flott und folge mir sehr dicht.\n"
"Alleine überlebst Du's nicht!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vergangenheit...\n"
"Gegenwart...\n"
"Zukunft..." BOX_BREAK UNSKIPPABLE "Das Master-Schwert sei Dir ein\n"
"Ruder auf Deinem Weg hin und\n"
"zurück durch die Ströme der Zeit..." BOX_BREAK UNSKIPPABLE "Der Hafen der Zeitwanderer liegt\n"
"in der Zitadelle der Zeit..." BOX_BREAK UNSKIPPABLE "Willst Du den Wüstenkoloss\n"
"betreten und in den " COLOR(YELLOW) "Geistertempel" COLOR(DEFAULT) "\n"
"eindringen, mußt Du wieder zurück\n"
"auf den Wellen der Zeiten..." BOX_BREAK UNSKIPPABLE "Höre nun das " COLOR(YELLOW) "Requiem der Geister" COLOR(DEFAULT) "!\n"
"Es wird Dich als Kind\n"
"in die Wüste zurückbringen!"
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin die Gerudo-Meisterin im\n"
"berittenen Bogenschießen! Ach ja,\n"
"und ich bin obendrein die beste\n"
"Reiterin der Gerudos!" BOX_BREAK "Willst Du gegen mich antreten?\n"
"Das kostet nur " COLOR(RED) "20 Rubine" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast Mut! Typen wie Dich\n"
"mag ich! \n"
"Folge mir."
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das kannst Du vergessen, wenn\n"
"Du kein Pferd hast!"
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mit so einem Weichei will ich\n"
"nichts zu tun haben!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na, so gut bist Du wohl doch\n"
"nicht! Vielleicht beim nächsten\n"
"Mal."
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist ja super gelaufen!" BOX_BREAK "Ich muß zugeben, Du hast mich\n"
"ganz schön abgezogen. \n"
"Ich muß wohl noch besser werden..."
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist die " COLOR(RED) "Trainingsarena" COLOR(DEFAULT) " der\n"
"Gerudo-Kriegerinnen." BOX_BREAK "Ohne Gerudo-Paß kommst Du hier\n"
"nicht hinein!"
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist die " COLOR(RED) "Trainingsarena" COLOR(DEFAULT) " der\n"
"Gerudo-Kriegerinnen." BOX_BREAK "Du hast den Gerudo-Paß?\n"
"Gut, dann darfst Du hinein." BOX_BREAK "Ein Versuch kostet 10 Rubine!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ich versuche es!\n"
"Ich lasse es bleiben!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Okay, her mit den 10 Rubinen.\n"
"Schieß ordentlich!" EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast nicht genug Geld!\n"
QUICKTEXT_ENABLE "Komm später wieder." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, Grünschnabel!" BOX_BREAK UNSKIPPABLE "Willst Du Dich wirklich in\n"
"die Wüste begeben?\n"
"Na gut, ich öffne das Tor, aber..." BOX_BREAK UNSKIPPABLE "Es ist nicht leicht, den" COLOR(RED) "\n"
"Geistertempel" COLOR(DEFAULT) " zu erreichen!" TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zunächst mußt Du den... " COLOR(RED) "Treibsand-\n"
"Graben" COLOR(DEFAULT) " überqueren! Dann folge\n"
"auf dem richtigen Weg den Flaggen,\n"
"sonst schluckt Dich der Sand." BOX_BREAK "Die zweite Prüfung: Folge dem\n"
COLOR(RED) "Wüstengeist" COLOR(DEFAULT) "!" BOX_BREAK "Ohne das " COLOR(RED) "Auge der Wahrheit " COLOR(DEFAULT) "aber\n"
"landest Du direkt wieder hier!" BOX_BREAK "Du willst immer noch dorthin?\n"
"Ich halte Dich nicht auf...\n"
"Mach's gut!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Warum bist Du schon wieder hier?\n"
"Was? Willst Du mich etwa noch\n"
"einmal dasselbe fragen?" TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Naja, wenn Du sowieso schon da\n"
"bist, dann mach das Beste draus!"
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Guter Junge! Vielen Dank!\n"
"Ich kann Dir zwar nichts derart \n"
"Wertvolles zum Tausch anbieten,\n"
"aber... vielleicht ist das ja okay!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe Dich noch nie gesehen,\n"
"Kleiner..." BOX_BREAK "Was willst Du hier?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Den Tempel anschauen!\n"
"Ich suche die Weisen!\n"
"Eigentlich nichts!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du bist noch zu klein! Der Tempel\n"
"ist nicht der richtige Ort für\n"
"Kinder. Geh woanders spielen!"
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Weiser? Keine Ahnung! Ist\n"
"das jemand, der Vater und Mutter\n"
"verloren hat?"
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Du hast nichts Besseres zu tun?\n"
"Du kommst wie gerufen! Kannst Du\n"
"mir einen Gefallen tun, Kleiner?" BOX_BREAK UNSKIPPABLE "Moment mal, Du bist doch nicht\n"
"etwa einer von Ganondorfs..." BOX_BREAK "Anhängern... Oder?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Und wenn es so wäre?\n"
"Ich hasse Ganondorf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hahaha!\n"
"Gib nicht so an, Kleiner!" BOX_BREAK UNSKIPPABLE "Jemand wie Du könnte nie einer\n"
"von Ganondorfs Anhängern sein!" BOX_BREAK UNSKIPPABLE "Diese Schurken sind aus\n"
"ganz anderem Holz geschnitzt..." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ach was!" BOX_BREAK UNSKIPPABLE "Du bist ganz schön mutig.\n"
"Ich glaube, ich mag Dich." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aber erst will ich mich vorstellen.\n"
"Ich bin die Gerudo-Kriegerin\n"
COLOR(RED) "Naboru" COLOR(DEFAULT) ". Ich gehe lieber allein\n"
"auf Beutetour." BOX_BREAK UNSKIPPABLE "Und noch etwas solltest\n"
"Du wissen!" BOX_BREAK UNSKIPPABLE "Ganondorf und ich gehören\n"
"zwar demselben Volk an, doch wir\n"
"sind grundverschieden." BOX_BREAK UNSKIPPABLE "Ganondorf und seine Anhänger\n"
"haben auch Frauen und Kinder\n"
"beraubt, ja sogar getötet!" BOX_BREAK UNSKIPPABLE "Wisse, das Gerudo-Geschlecht\n"
"besteht nur aus Frauen. Nur alle \n"
"100 Jahre wird ein Mann geboren..." BOX_BREAK UNSKIPPABLE "Auch wenn es unser Gesetz so\n"
"will, daß dieser Mann der König\n"
"der Gerudo wird, so schwöre ich\n"
"Ganondorf niemals im Leben Treue!" BOX_BREAK UNSKIPPABLE "Ach, wie war eigentlich Dein \n"
"Name, Kleiner?" BOX_BREAK UNSKIPPABLE  NAME "?!" BOX_BREAK UNSKIPPABLE "Was ist das denn für ein\n"
"komischer Name?\n"
"Naja, egal..." TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich möchte Dich um einen Gefallen\n"
"bitten..." BOX_BREAK UNSKIPPABLE "Schaffst Du es, durch diesen\n"
"engen Durchlaß zu kriechen und\n"
"einen Schatz zu bergen?" BOX_BREAK UNSKIPPABLE "Es handelt sich um ein uraltes\n"
"Diebesrelikt, die " COLOR(BLUE) "Krafthandschuhe" COLOR(DEFAULT) ".\n"
"Damit kann man sehr schwere\n"
"Dinge anheben!" BOX_BREAK UNSKIPPABLE "Hey, Kleiner! Denk nicht mal dran,\n"
"Dir die Handschuhe selbst unter\n"
"den Nagel zu reißen!" BOX_BREAK UNSKIPPABLE "Die Krafthandschuhe würden Dir\n"
"sowieso nicht passen!\n"
"Sei anständig und bring sie mir!" BOX_BREAK UNSKIPPABLE "Ganondorf und seine Vasallen\n"
"nutzen den Geistertempel als\n"
"eines ihrer Verstecke." BOX_BREAK UNSKIPPABLE "Nur mit den Krafthandschuhen\n"
"kann ich mich hier hineinstehlen!" BOX_BREAK UNSKIPPABLE "Dann kann ich nicht nur all ihr\n"
"Diebesgut an mich nehmen, sondern\n"
"auch ihre grauenvollen Pläne\n"
"durchkreuzen!" BOX_BREAK "Also, wie ist es? Machst Du's?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Danke, Kleiner!" BOX_BREAK UNSKIPPABLE "Wir beide werden Ganondorfs\n"
"Tyrannei beenden! Nicht wahr,\n"
"Kleiner?" TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Du die " COLOR(BLUE) "Krafthandschuhe\n"
COLOR(DEFAULT) "besorgst..." BOX_BREAK "Dann werde ich mich bei Dir\n"
"revanchieren!"
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Naja, was kann man von einem\n"
"Kind wie Dir schon erwarten?"
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey! Was macht Ihr miesen\n"
"alten Weiber mit mir?!"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Hihihihi!\n"
"Sieht so aus, als hätten wir einen \n"
"ordentlichen Fang gemacht, Koume!"
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hihihihi!\n"
"Sieht ganz so aus, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Wie außergewöhnlich, daß sich\n"
"jemand so tief in unseren Tempel\n"
"hineintraut...\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wir sollten ihm eine ordentliche \n"
"Lektion erteilen!\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, treuer Vasall..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Zerstöre diesen Eindringling!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ganondorfs... Feinde...\n"
"müssen sterben..."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Uuhh...\n"
"Wo bin ich...?"
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Grummel...\n"
"Sieht aus, als hätte sie sich\n"
"befreien können, Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sie ist noch jung, genießt aber\n"
"hohen Respekt unter den Gerudo-\n"
"Kriegerinnen, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vielleicht sollten wir sie etwas\n"
"länger zum Dienste des mächtigen\n"
"Ganondorf versklaven!\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wir sollten ihr Gehirn einer neuen\n"
"Behandlung unterziehen!\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kleiner, ich muß Dir danken." BOX_BREAK UNSKIPPABLE "Hey... Sieh mal an, was aus Dir\n"
"geworden ist - ein talentierter\n"
"Schwertkämpfer!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
"Du bist wirklich ein tapferer Held \n"
"geworden!" BOX_BREAK_DELAYED("\x50") "Dir gebührt eine ganz spezielle\n"
"Anerkennung..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hier, nimm " COLOR(RED) "dies" COLOR(DEFAULT) "...\n"
"Es ist ein wichtiges Dokument.\n"
"Unsere Kräfte im Bogenschießen\n"
"können wir auch später messen!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "... Wir sehen uns!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Au weia..." BOX_BREAK UNSKIPPABLE "Ich bin völlig durcheinander..." BOX_BREAK UNSKIPPABLE "Die beiden alten Weiber haben\n"
"mich verhext. Ich mußte für\n"
"Ganondorf tun, was er\n"
"verlangte..." BOX_BREAK UNSKIPPABLE "Aber bist Du nicht überrascht?\n"
"Jemand wie ich ist letztendlich die\n"
COLOR(YELLOW) "Weise der Geister" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ab jetzt kämpfe ich als eine der\n"
"Weisen gegen das Böse!" BOX_BREAK UNSKIPPABLE "Nun werden sie für das bezahlen,\n"
"was sie mir angetan haben!"
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Kleiner..." BOX_BREAK UNSKIPPABLE "Nein...\n"
NAME ", der strahlende\n"
"Wanderer durch die Zeiten!" BOX_BREAK UNSKIPPABLE "Als Dank dafür, daß Du den\n"
"Fluch vom Geistertempel genommen\n"
"hast, übergebe ich Dir\n"
"dieses " COLOR(YELLOW) "Amulett" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Nimm es!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2E") "Aaargh!" QUICKTEXT_DISABLE " Laßt mich!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x14") "Ihr " QUICKTEXT_ENABLE "widerlichen alten Hexen!" QUICKTEXT_DISABLE "\n"
SHIFT("\x03") "Ihr seid Ganondorfs eklige Sklaven!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x20") "Flüchte, " NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x51") "Schnell!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x15") "Verdammte Hexen! Sie setzen\n"
SHIFT("\x0D") "schwarze Magie gegen mich ein!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Kleiner! Das ist die " COLOR(RED) "Arena\n"
"für Bogenschießen zu Pferde" COLOR(DEFAULT) "." BOX_BREAK "Wir treffen genau den Mittelpunkt\n"
"der Zielscheibe. Egal, wie wild wir\n"
"reiten!" BOX_BREAK "Wenn Du reiten kannst, dann\n"
"komm zu uns und probier es auch\n"
"aus. Es ist gefährlich - aber ein\n"
"Riesenspaß!"
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Junge, Du hast da aber ein\n"
"tolles Pferd!" BOX_BREAK "Keine Ahnung, wo Du das geklaut\n"
"hast, aber..." BOX_BREAK "...wie wäre es mit einer Runde\n"
COLOR(RED) "Bogenschießen" COLOR(DEFAULT) " " COLOR(RED) "zu Pferde" COLOR(DEFAULT) "!?" BOX_BREAK "Sowie Dein Pferd galoppiert,\n"
"schieße mit Deinen Pfeilen auf\n"
"die Zielscheiben." BOX_BREAK "Wir werden ja sehen, wie oft Du\n"
"triffst! Du bekommst 20 Pfeile." BOX_BREAK "Wenn Du " COLOR(RED) "1.000 Punkte" COLOR(DEFAULT) " erreichst,\n"
"erhältst Du einen genialen\n"
"Preis!" EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du es versuchen?\n"
"Es kostet nur " COLOR(RED) "20 Rubine" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Kleiner!\n"
"Das sieht gar nicht schlecht aus!\n"
"Zeig's mir nochmal!" BOX_BREAK "Versuche doch jetzt,\n"
COLOR(RED) "1.500 Punkte" COLOR(DEFAULT) " zu erreichen!" EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was? Du willst es nochmal\n"
"versuchen?\n"
"Du gibst wohl so schnell nicht\n"
"auf, was?" EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Donnerwetter! Du bist ja ein \n"
"wahrer Meister Deines Fachs!" BOX_BREAK "Ich gebe Dir etwas, dessen nur\n"
"ein echter Meister würdig ist." BOX_BREAK "Es ist ein wertvoller Köcher,\n"
"den ich Dir überreiche. Er gehört\n"
"nun Dir. Behandle ihn gut!"
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " Punkte... Hmmm...\n"
"Hahaha! Da mußt Du wohl noch\n"
"ein bißchen üben!" EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Großartig!\n"
"Du bist ja ein absoluter König\n"
"im Bogenschießen!" BOX_BREAK "Hier, nimm dies.\n"
"Du kannst es bestimmt\n"
"gut gebrauchen!"
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " Punkte...\n"
"Ganz ordentlich!" EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sieh Dir diesen Dummkopf an!\n"
"Er kam freiwillig als Opfer\n"
"für den mächtigen Ganondorf..." FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x2A") "Meine Flammen werden\n"
SHIFT("\x3C") "ihn bis auf die\n"
SHIFT("\x2E") "Knochen verbrennen!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x3F") "Mein Eiszauber\n"
SHIFT("\x39") "wird seine Seele\n"
SHIFT("\x3A") "gefriertrocknen!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x28") "Verhext und zugenäht!\n"
SHIFT("\x25") "So ein widerliches Balg!\n"
SHIFT("\x1C") "Ab jetzt machen wir Ernst!\n"
SHIFT("\x42") "Was, Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "Waaaas?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x15") "Hey, Koume! Was schwebt da\n"
SHIFT("\x32") "über Deinem Kopf?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x17") "Weiß ich nicht, aber über Dir\n"
SHIFT("\x15") "schwebt auch etwas, Kotake!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0B") "Aber ich bin erst 400 Jahre alt!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "Und ich bin erst 380 Jahre alt!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x33") "Wir sind Zwillinge!\n"
SHIFT("\x10") "Mach Dich nicht jünger,\n"
SHIFT("\x3E") "als Du bist!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x28") "Du bist ja völlig senil!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x1B") "Wen nennst Du hier senil?!\n"
SHIFT("\x26") "Behandelt man so seine\n"
SHIFT("\x32") "ältere Schwester?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x30") "Wir sind Zwillinge! \n"
SHIFT("\x14") "Wie kannst Du da älter sein?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x4F") "Iiihhhh!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x24") "Du herzloses Miststück!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x2A") "Du undankbares Weib!" QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3A") "Du bist herzlos!" QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x24") "Und Du bist undankbar..." QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x29") "Ich mach Dich fertig!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Okay, laß uns jetzt Ernst machen!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x41")  QUICKTEXT_ENABLE "Okay, Koume." QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x14")  SHIFT("\x2C")  QUICKTEXT_ENABLE "Kotakes" QUICKTEXT_DISABLE " und " QUICKTEXT_ENABLE "Koumes" QUICKTEXT_DISABLE "\n"
SHIFT("\x2D")  QUICKTEXT_ENABLE "Sexy" QUICKTEXT_DISABLE " Thermo " QUICKTEXT_ENABLE "Hexy!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bist Du hier, um mich zu retten? \n"
"Oh, das ist ja wirklich nett!\n"
"Ich bin " COLOR(RED) "John, der Zimmermann" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Wir wollten uns eigentlich den\n"
"Gerudo-Kriegerinnen anschließen...\n"
"Aber dann haben sie uns\n"
"eingesperrt, weil wir Männer sind!" BOX_BREAK UNSKIPPABLE "Jetzt wollen wir aber lieber\n"
"wieder heim! Diese Gerudos sind\n"
"schrecklich ungehobelt!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Drei meiner Kumpels" COLOR(DEFAULT) " sind hier\n"
"noch eingesperrt.\n"
"Befreie sie bitte!"
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Das ist wirklich nett von Dir,\n"
"Kleiner! Danke für die Rettung!\n"
"Ich bin " COLOR(RED) "Paul, der Zimmermann" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Diese Frauen hier machen mir\n"
"Angst! Ich bleibe lieber weiter\n"
"Zimmermann, als mich ihnen\n"
"anzuschließen!" BOX_BREAK UNSKIPPABLE "Ich kann es kaum erwarten, wieder\n"
"daheim zu sein! " COLOR(RED) "Zwei meiner\n"
"Kumpels " COLOR(DEFAULT) "sind noch eingesperrt.\n"
"Hilfst Du ihnen?"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Danke, Junge! Du bist super!\n"
"Ich bin " COLOR(RED) "George, der Zimmermann" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Hast Du unseren Chef gesehen?\n"
"Er hat vielleicht Angst um uns!\n"
"Ich muß " QUICKTEXT_ENABLE "sofort" QUICKTEXT_DISABLE " zu ihm!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Einer von uns " COLOR(DEFAULT) "ist noch gefangen.\n"
"Bitte hilf auch ihm!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe schon gedacht, Du hättest\n"
"mich vergessen! Vielen Dank!\n"
"Ich bin " COLOR(RED) "Ringo, der Zimmermann" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Dafür, daß Du mich befreit hast,\n"
"verrate ich Dir, was sich die\n"
"Gerudos über die Wüste erzählen:" BOX_BREAK UNSKIPPABLE "\"Wer die Gespensterwüste\n"
"durchqueren will, braucht das " COLOR(RED) "Auge\n"
"der Wahrheit" COLOR(DEFAULT) ". Den Wüstenkoloss\n"
"findet man jenseits der Wüste...\"" BOX_BREAK UNSKIPPABLE "Ich gehe jetzt zu meinem " COLOR(RED) "Zelt in\n"
"der Nähe des Gerudotals" COLOR(DEFAULT) ". Schau\n"
"doch mal vorbei, vielleicht gibt es\n"
"dort etwas für Dich! Leb wohl!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Naboru" COLOR(DEFAULT) ", die Anführerin der Gerudo-\n"
"Kriegerinnen, scheint Menschen\n"
"für ihre Zwecke zu versklaven..."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, es war Ganondorf, der\n"
"Großmeister des Bösen, der hinter\n"
"allem steckte...?"
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als " COLOR(RED) "Naboru" COLOR(DEFAULT) " noch zu den Diebinnen\n"
"gehörte, hat sie nie die Schwachen\n"
"und Armen bestohlen." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jetzt aber sind sie und ihre\n"
"Diebinnen brutal und rücksichtslos\n"
"geworden. Sie behauptet, sie sei\n"
"edel, aber... Von wegen!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wie ich mir dachte: Naboru wurde\n"
"mit Hexerei von Ganondorfs\n"
"Schergen zu einer willenlosen\n"
"Sklavin gemacht..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bei den Gerudo-Kriegerinnen\n"
"genießen besonders jene hohes\n"
"Ansehen, die gute Reiter und \n"
"Bogenschützen sind." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wie wär's mit etwas Bogenschießen\n"
"zu Pferde?" BOX_BREAK "Wenn Du ein Pferd besitzt, dann\n"
"findet sich in der Festung sicher\n"
"eine Gerudo, die Dich\n"
"herausfordert!"
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das hast Du großartig\n"
"gemacht, Junge!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn wir alle zusammen sind,\n"
"ist es ein Kinderspiel, eine\n"
"Brücke über den Abgrund\n"
"zu bauen!"
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ohne die widerlichen alten Hexen\n"
"machen mir die Gerudos nicht\n"
"mehr soviel Angst!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hinter diesem Tor befindet sich\n"
"die " COLOR(RED) "Gerudo-Festung" COLOR(DEFAULT) ". Kinder haben\n"
"hier nichts zu suchen."
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Ich bin " COLOR(RED) "Handwerkermeister" COLOR(DEFAULT) ".\n"
"Es waren Gerudos, die die Brücke\n"
"zerstört haben." BOX_BREAK UNSKIPPABLE "Ich will sie reparieren, aber meine\n"
"Leute sind verschwunden!" BOX_BREAK UNSKIPPABLE "Sie haben gesagt, ihr Job sei öde.\n"
"Sie wollten lieber in die " COLOR(RED) "Gerudo-\n"
"Festung " COLOR(DEFAULT) "gehen, um Diebe\n"
"zu werden..." TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Du! Wenn Du schon in die\n"
"Festung gehst... Kannst Du\n"
"herausfinden, was meine Jungs\n"
"dort tun?"
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, ich habe gehört, daß Du\n"
"meine Leute gerettet hast.\n"
"Als Gegenleistung haben wir die\n"
"Brücke repariert!" BOX_BREAK "Schau her! Ist sie nicht toll?" BOX_BREAK "Meine Arbeiter sind ziemliche\n"
"Weicheier. Aber wenn sie alle\n"
"gemeinsam zulangen, dann ist so \n"
"ein Job schnell erledigt."
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Oh, das ist ja meine Säge!" BOX_BREAK UNSKIPPABLE "Aber... Ich dachte, ich hätte sie\n"
"bei der alten Frau liegen gelassen..." TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich besitze übrigens ein\n"
"zerbrochenes Biggoron-Schwert.\n"
"Du müßtest es nur von einem\n"
"Goronen reparieren lassen..." BOX_BREAK "Ich würde es gegen die Säge\n"
"eintauschen! Gibst Du sie mir?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x53")  QUICKTEXT_ENABLE "Was?!\n"
SHIFT("\x03") "Du stinkender, widerlicher Dieb!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dies ist die " COLOR(RED) "Trainingsarena " COLOR(DEFAULT) "der\n"
"Gerudos. Wer sie betreten will,\n"
"braucht ein besonderes\n"
"Dokument!"
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dies ist die " COLOR(RED) "Trainingsarena " COLOR(DEFAULT) "der \n"
"Gerudos." COLOR(RED) " " COLOR(DEFAULT) "Du darfst eintreten...\n"
"Trainiere Deine Fähigkeiten, so\n"
"lange Du willst." EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dies ist die " COLOR(RED) "Trainingsarena " COLOR(DEFAULT) "der \n"
"Gerudos. Auch wenn Du sehr gut\n"
"bist: Sacke nicht alle Schätze\n"
"selbst ein!"
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie schade." BOX_BREAK "Das Zeichen, welches Euch zum\n"
"Geistertempel führt, ist die " COLOR(RED) "Flagge\n"
"zur Linken" COLOR(DEFAULT) " außerhalb des Ladens." BOX_BREAK "Solltet Ihr es Euch anders\n"
"überlegen, dann kommt doch\n"
"bitte wieder!"
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Ihr habt zu wenig Rubine.\n"
"Ich gebe keinen Nachlass,\n"
"nicht einen Rubin!"
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Keuch...\n"
"Du bist doch schon mit etwas\n"
"anderem beschäftigt, oder?" BOX_BREAK "Wenn Du mich herausfordern willst,\n"
"dann komm wieder, wenn Du den\n"
"Kopf dafür frei hast!"
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46") "Willkommen!" BOX_BREAK "Ich verkaufe hier seltsame, seltene\n"
"Sachen aus der ganzen Welt. Mein\n"
"heutiges Angebot ist..." BOX_BREAK "Ein bombiges, ferngesteuertes\n"
"Objekt! Furchterregend!\n"
"Ich erzähle Euch erst etwas davon,\n"
"wenn ich Geld sehe..." BOX_BREAK "Wie wär's mit " COLOR(RED) "200 Rubinen" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Kaufen!\n"
"Nicht kaufen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vielen herzlichen Dank!" BOX_BREAK "Ich verkaufe... " TEXT_SPEED("\x02")  COLOR(RED) "Krabbelminen" COLOR(DEFAULT) "!" TEXT_SPEED("\x00")  BOX_BREAK "Das Zeichen, welches Euch zum\n"
"Geistertempel führt, ist die " COLOR(RED) "Flagge\n"
"zur Linken" COLOR(DEFAULT) " außerhalb des Ladens.\n"
"Schaut mal wieder vorbei!"
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hey, was ist, " NAME "?\n"
"Überrascht, mich zu sehen?" BOX_BREAK UNSKIPPABLE "Lange Jahre in der Zukunft\n"
"bedeuten anscheinend gar\n"
"nichts. Hier sind nur wenige\n"
"Sekunden vergangen!" BOX_BREAK UNSKIPPABLE "Sogar ich hatte gedacht, daß\n"
"Reisen durch die Zeit eine reine\n"
"Legende seien." BOX_BREAK UNSKIPPABLE  NAME ", Du hast viel\n"
"Erfahrung gesammelt!" TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das Schicksal Hyrules liegt von\n"
"nun an in Deinen Händen." BOX_BREAK "Vielleicht ist meine Zeit jetzt\n"
"vorüber. Hier ist ein letzter Rat:" BOX_BREAK "In diesem Tempel hausen zwei alte\n"
"Hexen. Um sie zu vernichten,\n"
COLOR(RED) "schlage sie mit ihren eigenen\n"
"magischen Waffen" COLOR(DEFAULT) "!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Möchtest Du das, was ich gesagt\n"
"habe, noch einmal hören?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich werde Dich\n"
"weiterhin beobachten...\n"
"Viel Glück!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ich bin reisender Rennläufer!\n"
"Ich habe das ganze Land berannt...\n"
"ähh, bereist, um jemanden mit\n"
"echtem Sportsgeist zu finden!" BOX_BREAK UNSKIPPABLE "Ob Mensch oder Tier - ich habe\n"
"alle Herausforderer geschlagen." BOX_BREAK UNSKIPPABLE "Du siehst sportlich aus und hast\n"
"wohl auch den nötigen Biß!" BOX_BREAK UNSKIPPABLE "Da jetzt die Brücke über den\n"
"Abgrund repariert wurde,\n"
"suche ich einen Herausforderer\n"
"für einen Marathon!" TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Die Bestzeit von hier zur " COLOR(ADJUSTABLE) "Brücke\n"
"nach Kokiri " COLOR(DEFAULT) "war:\n"
COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ".\n"
"Das ist mein Rekord!" BOX_BREAK "Willst Du versuchen, diesen\n"
"Rekord zu brechen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ausgezeichnet!\n"
"Also..." BOX_BREAK "Du fängst an.\n"
"Ich gebe Dir sogar Vorsprung." BOX_BREAK TEXT_SPEED("\x02") "Los geht's." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Mit dieser Einstellung kommst Du\n"
"aber nicht sehr weit, mein Junge!"
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Nun ja, nicht perfekt, aber Du\n"
"traust Dich was! Nur dumm,\n"
"daß Du mich nie schlagen wirst.\n"
"Dein Rekord ist schon vergessen!" BOX_BREAK "Deine Zeit betrug " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ", oder?\n"
"Denkbar knapp, aber ich war um\n"
"eine Sekunde schneller!" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hihihi...\n"
"Bitte! " TEXT_SPEED("\x02") "Lauf weiter!" TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Oh, sieht aus, als würdest Du\n"
"aufgeben wollen. Hihihi...\n"
"Fast hättest Du Deine alte Form \n"
"wiedererlangt!" FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hihihi...\n"
"Du hast doch noch nicht den\n"
"rechten Biß, mein Lieber." BOX_BREAK "Du mußt härter trainieren.\n"
QUICKTEXT_ENABLE "Mach's mal gut!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Keuch..." QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Pust..." QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Hust..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  BOX_BREAK "Keuch... Pust... Wow!\n"
"Das war sehr gut!" BOX_BREAK "Doch Du hast mich noch nicht\n"
"geschlagen!\n"
"Deine Bestzeit war " COLOR(RED)  MARATHON_TIME  COLOR(DEFAULT) ", aber\n"
"ich war eine Sekunde schneller!" BOX_BREAK "Keuch... Hust... \n"
"Versuche es irgendwann noch\n"
"einmal!" BOX_BREAK "Keuch... Pust...\n"
QUICKTEXT_ENABLE "Mach's mal gut!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ich bin reisender Rennläufer!\n"
"Ich habe das ganze Land berannt...\n"
"ähh, bereist, um jemanden mit\n"
"echtem Sportsgeist zu finden!" BOX_BREAK "Ich bin hierher gekommen, um durch\n"
"die Gespensterwüste zu laufen...\n"
"Aber das war, glaube ich, kein\n"
"guter Zeitpunkt." BOX_BREAK "Ich wollte zur hylianischen Steppe\n"
"zurück, aber die Brücke ist...\n"
"Naja, das siehst Du ja selbst.\n"
"Jetzt sitze ich hier fest." BOX_BREAK "Ich kann daher auch Deine\n"
"Herausforderung leider noch\n"
"nicht annehmen. Hihihi!"
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
"Ich kann dieses Huhn\n"
"nicht einfangen!"
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Keuch! \n"
"Ich bin schwer\n"
"am Trainieren!"
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lang lebe Prinzessin Zelda!"
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"In Deinem Alter solltest Du um\n"
"diese Zeit im Bett liegen! Bleib\n"
"lieber im Haus bis morgen früh!"
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mann, ist mir langweilig...\n"
"Es wäre bestimmt spannender,\n"
"wenn hier mehr los wäre..." BOX_BREAK "Hey, das bleibt aber unter uns,\n"
"klar?" BOX_BREAK "Egal, vielleicht können wir ja\n"
"etwas Dampf ablassen, indem wir\n"
"ein paar Krüge zerschlagen." BOX_BREAK "Stelle Dich vor einen Krug und\n"
"drücke " COLOR(BLUE) "[A]" COLOR(DEFAULT) ", um ihn anzuheben.\n"
"Drückst Du nochmal " COLOR(BLUE) "[A]" COLOR(DEFAULT) ", wirfst\n"
"Du ihn!"
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Großartig!" BOX_BREAK UNSKIPPABLE "Das habe ich ganz vergessen..." EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Im Schloß ist es zur Zeit ziemlich\n"
"unruhig. Daher darf es\n"
"niemand betreten!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Arrgh... Bist Du der Junge aus\n"
"dem Wald...?" BOX_BREAK UNSKIPPABLE "Endlich treffe ich Dich...\n"
"Ich... Ich muß Dir etwas... mitteilen..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", der Herr der Gerudo,\n"
"hat unseren König verraten..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) " hat die Gefahr erkannt und\n"
"ist mit Prinzessin Zelda aus dem\n"
"Schloß geflüchtet..." BOX_BREAK UNSKIPPABLE "Ich habe versucht, Ganondorfs\n"
"Leute daran zu hindern, ihnen zu\n"
"folgen... aber... ohne Erfolg..." BOX_BREAK UNSKIPPABLE "Die Prinzessin hat... auf einen\n"
"Jungen aus dem Wald gewartet...\n"
"auf Dich... Sie wollte Dir " COLOR(RED) "etwas\n"
"geben" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Wenn Du es hast, dann " TEXT_SPEED("\x03")  QUICKTEXT_ENABLE "eile" QUICKTEXT_DISABLE "... " QUICKTEXT_ENABLE "zur" QUICKTEXT_DISABLE "\n"
COLOR(LIGHTBLUE)  QUICKTEXT_ENABLE "Zita" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "delle" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "der" QUICKTEXT_DISABLE " Zeit" COLOR(DEFAULT) "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Er rührt sich nicht mehr..."
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Siehst Du den Mann dort?\n"
"Den mit dem bösen Blick?" BOX_BREAK UNSKIPPABLE "Das ist " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", Anführer der \n"
"Gerudos, die in der Wüste fern im\n"
"Westen unseres Landes leben." BOX_BREAK UNSKIPPABLE "Er hat meinem Vater die Treue\n"
"geschworen, doch ich glaube nicht,\n"
"daß er aufrichtig ist." BOX_BREAK UNSKIPPABLE "Die dunklen Wolken, die Hyrule in\n"
"meinen Träumen einhüllten...\n"
"Sie müssen diesen Mann\n"
"symbolisiert haben!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x08") "Hahaha! Ausgezeichnet, Kleiner!" BOX_BREAK_DELAYED("\x3C") "Wie ich mir dachte, besitzt Du den\n"
SHIFT("\x1A") "Schlüssel zum Zeitportal!" BOX_BREAK_DELAYED("\x5A")  SHIFT("\x34") "Du hast mich zum\n"
SHIFT("\x20") "Heiligen Reich geführt..." BOX_BREAK_DELAYED("\x50")  SHIFT("\x12") "Ich muß Dir danken, Kleiner!" FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bitte! Wenn Du Dich nicht beeilst,\n"
"wird er fort sein!" EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bitte... Verkaufe mir etwas mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Verkaufe mir den " COLOR(RED) "Inhalt" COLOR(DEFAULT) " einer\n"
"Flasche...\n"
"Bitte... Drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Welch merkwürdiger Laden! \n"
"Ich frage mich, wann er öffnet.\n"
"Ich habe zwar das Schild gelesen,\n"
"aber es ist doch sehr seltsam!"
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es scheint ewig zu dauern,\n"
"bis die Sonne aufgeht..." BOX_BREAK "Der Blick auf Schloß Hyrule im\n"
"Licht der aufgehenden Sonne ist\n"
"einfach fantastisch!"
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Um das Mädchen aus dem Wald zu\n"
"retten, brauchst Du einen\n"
COLOR(RED) "weiteren Ausrüstungsgegenstand" COLOR(DEFAULT) "... \n"
"Geh zurück nach Kakariko!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es scheint, als hättest Du, was \n"
"Du benötigst... \n"
"Das" COLOR(ADJUSTABLE) " Mädchen aus dem Wald\n"
COLOR(DEFAULT) "wartet auf Deine Hilfe..."
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du Elixiere kaufen willst,\n"
"dann bringe eine leere Flasche mit.\n"
"Hast Du verstanden, Junge?" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Tut mir leid, das ist nur eine\n"
"Attrappe. Wegen der Probleme in\n"
"Goronia haben wir in der letzten\n"
"Zeit kein Material mehr bekommen." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wenn Du auf den Todesberg willst,\n"
"kaufe besser einen " COLOR(LIGHTBLUE) "Hylia-Schild" COLOR(DEFAULT) ".\n"
"Damit schützt Du Dich vor\n"
"herabfallenden Lavabrocken." BOX_BREAK "Aber für ein Kind ist der Schild\n"
"vielleicht eine Nummer zu groß..." PERSISTENT
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich tanze nicht, weißt Du...\n"
"Mir tut der Rücken weh!\n"
"Auu! Aaah!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es heißt, wir " COLOR(LIGHTBLUE) "Hylianer " COLOR(DEFAULT) "hätten so\n"
"große Ohren, um die Stimmen der\n"
"Götter hören zu können.\n"
"Aber ich habe sie nie gehört!"
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Warst Du schon einmal auf der\n"
COLOR(YELLOW) "Lon Lon-Farm" COLOR(DEFAULT) ", Kleiner?" BOX_BREAK UNSKIPPABLE "Die Milch dort ist köstlich!\n"
"Außerdem gibt es da viele Pferde,\n"
"und die junge Tochter des Farmers\n"
"ist richtig süß!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zur " COLOR(YELLOW) "Farm " COLOR(DEFAULT) "kommst Du, wenn Du\n"
"nach dem Ortsausgang durch die\n"
"Steppe nach Süden gehst.\n"
"Besuche sie unbedingt einmal!"
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich wollte zu " COLOR(RED) "Prinzessin Zelda" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Habe die Wachen umgangen..." BOX_BREAK UNSKIPPABLE "Bin durch den Burggraben\n"
"geschwommen..." BOX_BREAK UNSKIPPABLE "Ich war fast bei ihr, als sie\n"
"mich doch noch geschnappt haben!" TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe ein enges " COLOR(RED) "Abflußloch " COLOR(DEFAULT) "auf\n"
"der Ostseite des Schlosses\n"
"gefunden und dachte, ich käme\n"
"durch. Aber ich blieb hängen!"
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x53")  QUICKTEXT_ENABLE "Ähem!" QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x06") "Dieser Bart ist mein ganzer Stolz!\n"
SHIFT("\x01") "Ist er nicht eindrucksvoll, Kleiner?"
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Ähem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x06") "Dieser Bart ist mein ganzer Stolz!\n"
"Ist er nicht eindrucksvoll, Kleiner?" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x56") "Was?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Du suchst den Typen von der\n"
"Lon Lon-Farm?" BOX_BREAK UNSKIPPABLE "Hmmm, wart mal..." TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe gesehen, wie ein " COLOR(RED) "Typ mit\n"
"einem zerrupften Bart" COLOR(DEFAULT) " Kisten zum \n"
"Schloß gebracht hat."
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Kennst Du die " COLOR(LIGHTBLUE) "Zitadelle \n"
"der Zeit" COLOR(DEFAULT) ", die sich im Nordosten\n"
"der Stadt befindet?" TEXTID("\x70\x1E")
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Legenden besagen, daß sich in\n"
"der Zitadelle der Zeit der Zugang\n"
"zum Heiligen Reich befindet..." BOX_BREAK "Hast Du das schon gewußt?"
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hahaha! Welch dämlicher\n"
"Kerl!" BOX_BREAK UNSKIPPABLE "Kannst Du Dir vorstellen, daß er\n"
"sich tatsächlich ins Schloß \n"
"hineinschleichen wollte,\n"
"um " COLOR(RED) "Prinzessin Zelda" COLOR(DEFAULT) " zu sehen?" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wegen diesem Idioten haben sie\n"
"die Bewachung vor dem Schloß\n"
"noch verstärkt!\n"
"Hahaha!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ich habe tierisch viel verdient!" BOX_BREAK UNSKIPPABLE "Vielleicht sollte ich noch\n"
"mehr Sachen suchen, die ich\n"
"verkaufen kann!" TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich weiß schon! Ich sollte zum\n"
COLOR(BLUE) "Hylia-See" COLOR(DEFAULT) " gehen!\n"
"Da wird immer eine Menge\n"
"interessantes Zeug angeschwemmt!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, Waldschrat! Das ist " COLOR(LIGHTBLUE) "Hyrule" COLOR(DEFAULT) "!\n"
"Nimm Dir Zeit und schau Dich in\n"
"aller Ruhe um!" TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Du zum " COLOR(LIGHTBLUE) "Schloß von Hyrule" COLOR(DEFAULT) "\n"
"möchtest, nimm die Straße zu\n"
"Deiner Rechten." BOX_BREAK "Wenn Du die " COLOR(BLUE) "Seitenstraßen" COLOR(DEFAULT) "\n"
"erforschen willst, geh\n"
"nach links."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey!" BOX_BREAK "Du... siehst gut aus..." BOX_BREAK "Fast wie der König von Hyrule..." BOX_BREAK "Hihihi..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..." BOX_BREAK "Du bist ja..." BOX_BREAK "noch schöner..." BOX_BREAK "als Prinzessin Zelda..." BOX_BREAK "Ohh..."
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hast Du von der Legende des\n"
"\"Schattenvolks\" gehört?" BOX_BREAK UNSKIPPABLE "Es sind die " COLOR(BLUE) "Shiekah" COLOR(DEFAULT) "... Die Schatten\n"
"der Hylianer." BOX_BREAK UNSKIPPABLE "Es heißt, sie hätten dem König von\n"
"Hyrule ewige Treue geschworen,\n"
"um ihn und seine Familie\n"
"stets zu beschützen." BOX_BREAK UNSKIPPABLE "Aber nach solch einer langen Zeit\n"
"voller Frieden, haben wir schon\n"
"lange keinen der Shiekah mehr\n"
"gesehen." BOX_BREAK UNSKIPPABLE "Dennoch..." TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe gehört, daß es noch eine\n"
"Vertreterin der " COLOR(BLUE) "Shiekah" COLOR(DEFAULT) " geben soll.\n"
"Sie lebt im Schloß..."
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Also Du sagst, Du willst \n"
COLOR(RED) "Prinzessin Zelda" COLOR(DEFAULT) " sehen, wie?" BOX_BREAK "Du hast bestimmt im Ort von ihr\n"
"gehört und willst sie jetzt\n"
"unbedingt kennenlernen... Nun..." BOX_BREAK QUICKTEXT_ENABLE "Geh heim!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Verschwinde!" QUICKTEXT_DISABLE "\n"
"Einem wie Dir würde die Prinzessin\n"
"niemals Audienz gewähren!"
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zzzzzzzz..." BOX_BREAK "Murmel... Grummel..." BOX_BREAK "Milch... frisch abliefern..." BOX_BREAK "Muß... mich beeilen..."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x35") "Was zum Teufel...?" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Kann man denn nicht mal für eine\n"
"Sekunde die Augen zumachen?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hallo! Wer bist Du?" BOX_BREAK UNSKIPPABLE "Also ich bin " COLOR(RED) "Talon" COLOR(DEFAULT) ", Besitzer der\n"
"Lon Lon-Farm." BOX_BREAK UNSKIPPABLE "Ich war auf dem Weg zum Schloß,\n"
"um frische Milch zu liefern. Als\n"
"ich mich kurz ausruhen wollte, muß\n"
"ich wohl eingeschlafen sein..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4C")  SFX("\x68\x52") "Was?!\n"
"Malon sucht nach mir?\n"
"Da bekomme ich wieder gehörigen\n"
"Ärger!" BOX_BREAK UNSKIPPABLE "Ich hatte ihr doch versprochen..." BOX_BREAK UNSKIPPABLE "Au weia, das läuft nicht gut!" EVENT
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x35") "Hey, Kleiner! Halt!\n"
"Stehenbleiben! Im Namen des Königs!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x53")  QUICKTEXT_ENABLE "Nanu?" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Wer bist Du?" BOX_BREAK UNSKIPPABLE "Wie hast Du es geschafft,\n"
"an den Wachen vorbeizukommen?" EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nun, hast Du ihn dabei? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Das ist seltsam...\n"
"Ich glaubte eben, Du wärst der\n"
"Junge aus meinem Traum...\n"
"Du hast ihn wirklich nicht?" BOX_BREAK "Sag mir bitte die Wahrheit..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wie ich mir dachte!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du wirst das doch\n"
"nicht weitererzählen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Okay!\n"
"Doch!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Also das hätte ich von Dir\n"
"nicht gedacht!" EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dies ist die Legende..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x11") "Das " COLOR(RED) "Triforce" COLOR(DEFAULT) " vereinte die Kraft\n"
SHIFT("\x0A") "der drei Göttinnen. Sie verbargen\n"
SHIFT("\x1C") "es an einem Ort in Hyrule." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x0B") "Denn das Triforce hat die Macht,\n"
SHIFT("\x09") "die Wünsche dessen wahr werden\n"
SHIFT("\x09") "zu lassen, der es in Händen hält!" BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x0D") "Ein rechtschaffenes Herz würde\n"
SHIFT("\x13") "Hyrule in goldene Zeiten voller\n"
SHIFT("\x14") "Reichtum und Frieden führen..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x0D") "Würden Wünsche eines Menschen\n"
SHIFT("\x12") "mit niederer Gesinnung erfüllt,\n"
SHIFT("\x07") "so verschlänge das Böse die Welt!" BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x0F") "Daher errichteten die Weisen die\n"
SHIFT("\x06")  COLOR(LIGHTBLUE) "Zitadelle der Zeit" COLOR(DEFAULT) ", um das Triforce\n"
SHIFT("\x0C") "vor bösen Mächten zu bewahren." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Die Zitadelle der Zeit ist\n"
"in unserer Welt der Zugang zum\n"
"Heiligen Reich." BOX_BREAK "Doch dieser Zugang ist versiegelt\n"
"durch eine steinerne Mauer, die\n"
"man " COLOR(LIGHTBLUE) "Zeitportal" COLOR(DEFAULT) " nennt." BOX_BREAK "Es heißt, man brauche die drei\n"
COLOR(RED) "Heiligen Steine" COLOR(DEFAULT) ", um den Zugang\n"
"zu öffnen." BOX_BREAK "Und noch etwas... Nämlich ein\n"
"uraltes Relikt, das im Besitz der\n"
"Königsfamilie von Hyrule ist..." EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, tut mir leid...\n"
"Ich konnte noch nie gut\n"
"Geschichten erzählen..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "Was ist passiert?" QUICKTEXT_DISABLE " Hat er Dich\n"
"gesehen?" BOX_BREAK UNSKIPPABLE "Hab keine Angst." BOX_BREAK UNSKIPPABLE "Er hat keine Ahnung von unseren\n"
"Plänen... Noch nicht!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bitte!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Ich glaube kein Wort!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x38") "Ich danke Dir!" EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meine Vertraute wird Dich aus\n"
"dem Schloß geleiten. Unterhalte\n"
"Dich ruhig mit ihr."
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der Heilige Stein...\n"
"Du hast ihn gefunden!" BOX_BREAK "Wesen, deren Volk einen Heiligen\n"
"Stein besitzt, vertrauen sich nur\n"
"dem an, der eine" COLOR(BLUE) " Melodie aus dem\n"
"Erbe unserer Familie" COLOR(DEFAULT) " kennt." BOX_BREAK "Doch das wußtest Du bereits,\n"
"nicht wahr?"
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, hast Du schon gehört, daß\n"
"Prinzessin Zelda in ihren Träumen\n"
"die Zukunft voraussieht?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Häh? Was? Still, Kleiner! Still!"
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Hier sind drei Vertiefungen\n"
"und eine Inschrift..." BOX_BREAK QUICKTEXT_ENABLE "Jener mit den drei Heiligen Steinen" COLOR(BLUE) "\n"
COLOR(DEFAULT) "nehme seine " COLOR(LIGHTBLUE) "Okarina " COLOR(DEFAULT) "zur Hand" COLOR(BLUE) "\n"
COLOR(DEFAULT) "und spiele hier die " COLOR(LIGHTBLUE) "Hymne der Zeit" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK "Seltsam, aber so steht\n"
"es geschrieben..." EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, geht das nicht auch ein\n"
"bißchen billiger?"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, nimm Deine Finger weg!\n"
"Ich hab es zuerst gesehen!"
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, wer drängelt sich da vor?!"
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es ist komisch, daß Gerudos hier\n"
"eingedrungen sind... Das kommt mir\n"
"seltsam vor...!"
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"War das nicht Prinzessin Zelda\n"
"auf diesem Schimmel?"
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der schwarze Hengst dieses\n"
"Reiters hätte mich um ein Haar\n"
"zertrampelt!"
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Der Typ auf dem schwarzen Pferd\n"
"war bestimmt Ganondorf, der Herr\n"
"der Gerudo-Kriegerinnen!"
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was ist denn hier passiert?"
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Schau Dir den Weichling an!\n"
"Er hat sich vor Angst fast in die \n"
"Hosen gemacht!\n"
"Hahaha!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe das Gefühl, daß noch viel\n"
"Schrecklicheres passieren wird...\n"
"Vielleicht sollte ich abhauen!"
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Im Schloß ist etwas Schlimmes\n"
"passiert! Sei lieber vorsichtig,\n"
"Kleiner!"
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mit diesem " COLOR(RED) "Schlüssel" COLOR(DEFAULT) " kannst Du\n"
"den nächsten Raum betreten.\n"
"Los doch! Worauf wartest Du?"
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Person auf dem Schimmel, die\n"
"das Mädchen festhielt... War das\n"
"nicht eine der legendären Shiekah?"
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D")  NAME "..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4B") "Wach auf!\n"
SHIFT("\x21") "Du bist der Auserwählte!"
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin " COLOR(RED) "Rauru" COLOR(DEFAULT) ", einer der Weisen..." BOX_BREAK UNSKIPPABLE "Ich habe die Zitadelle der Zeit\n"
"erbaut, um den Zugang zum\n"
"Heiligen Reich zu schützen..." BOX_BREAK UNSKIPPABLE "Dies ist die " COLOR(RED) "Halle der Weisen \n"
COLOR(DEFAULT) "im Tempel des Lichts..." BOX_BREAK UNSKIPPABLE "Der Tempel des Lichts befindet\n"
"sich im Zentrum des Heiligen\n"
"Reiches. Er ist die letzte Festung\n"
"gegen die Macht Ganondorfs." BOX_BREAK UNSKIPPABLE "Das " COLOR(RED) "Master-Schwert" COLOR(DEFAULT) ", das alles\n"
"Böse vernichtet und das Du aus\n"
"dem Zeitenfels zogst, öffnete\n"
"das Tor zum Heiligen Reich!" BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Erschrick nicht...\n"
"Schau Dich an..."
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x1D")  COLOR(LIGHTBLUE) "Sieh nur, " NAME "!\n"
COLOR(DEFAULT)  SHIFT("\x31")  COLOR(LIGHTBLUE) "Du bist gewachsen!\n"
COLOR(DEFAULT)  SHIFT("\x25")  COLOR(LIGHTBLUE) "Du bist älter geworden!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das Master-Schwert hat eine\n"
"heilige Klinge, die nie in die \n"
"Hände des Bösen fallen darf..." BOX_BREAK UNSKIPPABLE "Nur jener, der zu Recht den\n"
"Namen " COLOR(RED) "Herr der Zeiten" COLOR(DEFAULT) " trägt, ist\n"
"in der Lage, es aus dem Zeitenfels\n"
"zu ziehen..." BOX_BREAK UNSKIPPABLE "Doch Du warst noch zu jung für\n"
"diese Aufgabe..." BOX_BREAK UNSKIPPABLE "Daher haben wir Deine Seele für\n"
"sieben Jahre hier gebannt." BOX_BREAK UNSKIPPABLE "Nun ist es Zeit, daß Du wieder in\n"
"die Welt zurückkehrst und Deine\n"
"Mission vollendest!" BOX_BREAK "Nun, hast Du verstanden, was\n"
"Deine Bestimmung ist?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nun, es sieht aus, als wärest Du\n"
"etwas verwirrt... Laß mich noch\n"
"einmal von vorn beginnen." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Doch vergiß niemals..." BOX_BREAK UNSKIPPABLE "Obwohl Du nur mit edelstem\n"
"Ansinnen das Zeitportal geöffnet\n"
"hast..." BOX_BREAK UNSKIPPABLE "...hat der niederträchtige\n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) " dadurch das Heilige\n"
"Reich betreten können!" BOX_BREAK UNSKIPPABLE "Er riß das Triforce-Fragment im\n"
"Tempel des Lichts an sich. Durch\n"
"dessen Kraft wurde er zum\n"
COLOR(RED) "Großmeister des Bösen" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Seine schwarze Macht überzog\n"
"ganz Hyrule, entweihte die Tempel\n"
"und verwandelte das einst blühende\n"
"Land in ein Refugium des Unheils!" BOX_BREAK UNSKIPPABLE "Meine Kraft ist nur noch\n"
"verschwindend gering, selbst in\n"
"diesem Heiligen Reich..." BOX_BREAK UNSKIPPABLE "Sie kann lediglich diese Halle\n"
"der Weisen noch schützen." BOX_BREAK UNSKIPPABLE "Doch noch ist Hoffnung..." BOX_BREAK UNSKIPPABLE "Die Kraft der Weisen blieb\n"
"erhalten." BOX_BREAK UNSKIPPABLE "Wenn die Kraft jedes der " COLOR(RED) "Sieben\n"
"Weisen " COLOR(DEFAULT) "wieder geweckt wird..." BOX_BREAK UNSKIPPABLE "...kann mit den " COLOR(RED) "Amuletten" COLOR(DEFAULT) " die\n"
"Macht des Bösen ins Höllenreich\n"
"verbannt werden!" BOX_BREAK UNSKIPPABLE "Ich, Rauru, bin einer dieser\n"
"Weisen..." BOX_BREAK UNSKIPPABLE "Der Auserwählte, die Kraft der\n"
"Weisen zu wecken, bist Du - der\n"
COLOR(RED) "Herr der Zeiten" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Du bist als Träger des \n"
"Master-Schwerts dazu auserwählt!" BOX_BREAK UNSKIPPABLE "Ich übertrage Dir meine Macht...\n"
"Geh nun, erwecke die Kraft der\n"
"anderen Weisen und vereine deren\n"
"Macht mit Deiner Stärke!"
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... Wir sind zurück\n"
"in der " COLOR(DEFAULT) "Zitadelle der Zeit" COLOR(LIGHTBLUE) "...\n"
"Aber sind wirklich " COLOR(DEFAULT) "sieben Jahre\n"
COLOR(LIGHTBLUE) "vergangen?" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Es sieht so aus, als könntest\n"
"Du einige " COLOR(DEFAULT) "Waffen" COLOR(LIGHTBLUE) ", die Du damals\n"
"gefunden hast, nicht mehr\n"
"benutzen..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Los, laß uns gehen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, was ist...? \n"
"Was ist schlimm daran, den Tag\n"
"über rumzuhängen, Kleiner?" BOX_BREAK "Was willst Du?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich habe auf Dich gewartet,\n"
"junger Held..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Beherrscht das Böse die Welt,\n"
"weilen jene Weisen, die von der\n"
"Stimme des Heiligen Reiches erweckt\n"
"werden, noch in den " COLOR(RED) "fünf Tempeln" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Einer in " COLOR(ADJUSTABLE) "dunklen Wäldern" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Einer auf " COLOR(RED) "hohem Berge" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Einer im " COLOR(BLUE) "tiefen See" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Einer an der " COLOR(PURPLE) "Stätte des Todes" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Einer innerhalb der\n"
COLOR(YELLOW) "Göttin des Sandes" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Zusammen mit dem Auserwählten\n"
"werden diese ihre Kräfte einsetzen,\n"
"um der Welt den Frieden\n"
"wiederzugeben..." BOX_BREAK UNSKIPPABLE "Dies ist die Legende der Tempel,\n"
"wie sie von meinem Volk, den\n"
COLOR(BLUE) "Shiekah" COLOR(DEFAULT) ", überliefert wurde."
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, tut mir leid.\n"
"Wir haben noch nicht geöffnet.\n"
"Komm bitte später wieder!" EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nimm das " COLOR(RED) "Master-Schwert" COLOR(DEFAULT) "!\n"
"Vernichte Ganon mit Deiner\n"
"heiligen Waffe!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ich habe auf Dich gewartet,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", der Auserwählte..." BOX_BREAK UNSKIPPABLE "Du hast unzählige Gefahren \n"
"überwunden und die sechs\n"
"Weisen erweckt." BOX_BREAK UNSKIPPABLE "Nun wartet Deine größte Aufgabe:\n"
"Ein letztes Zusammentreffen mit\n"
"Ganondorf, dem Großmeister\n"
"des Bösen..."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x24") "Suchst Du das Triforce,\n"
SHIFT("\x38") "so höre gut zu..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x08") "Es befindet sich im Heiligen Reich.\n"
SHIFT("\x16") "Dies ist ein Ort, der auf die\n"
SHIFT("\x08") "Wünsche Deines Herzens reagiert..." BOX_BREAK_DELAYED("\x46")  UNSKIPPABLE  SHIFT("\x07") "Ein schwarzes Herz macht es zum\n"
SHIFT("\x10") "Hort des Übels. Ein reines Herz\n"
SHIFT("\x04") "aber verwandelt es in ein Paradies!" BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x08") "Das Triforce... Symbol der Macht...\n"
SHIFT("\x12") "birgt das Gleichgewicht dreier\n"
SHIFT("\x0B") "Kräfte: Weisheit, Mut und Kraft!" BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x11") "Sind diese Kräfte ausgeglichen\n"
SHIFT("\x04") "im Herzen des Triforce-Trägers, hat\n"
SHIFT("\x02") "er die Macht, gerecht zu herrschen." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x1C") "Doch ist das Herz nicht im\n"
SHIFT("\x08") "Gleichgewicht, so spaltet sich das\n"
SHIFT("\x0A") "Triforce in seine drei Fragmente!" BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x07") "Nur ein Fragment bleibt ihm: Jenes\n"
SHIFT("\x01") "nämlich, das zu der Kraft gehört, an\n"
SHIFT("\x0C") "die er selbst am meisten glaubt." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x29") "Will er nun alle Macht\n"
SHIFT("\x17") "erhalten, muß er die anderen\n"
SHIFT("\x10") "Fragmente des Triforce finden!" BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x09") "Noch zwei vom Schicksal Erwählte\n"
SHIFT("\x09") "tragen je ein Triforce-Element als\n"
SHIFT("\x14") "Symbol auf ihrem Handrücken!" FADE("\x5A")
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sieben Jahre zuvor drang\n"
"Ganondorf in das Heilige Reich\n"
"ein, dessen Zugang Du in der\n"
"Zitadelle der Zeit geöffnet hast." BOX_BREAK UNSKIPPABLE "Als seine Hände das Triforce\n"
"berührten, wurde die Legende wahr!"
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Der Auserwählte mit dem " COLOR(RED) "Symbol \n"
"des Mutes " COLOR(DEFAULT) "bist...\n"
"Du, " NAME "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Das " COLOR(RED) "Symbol der Weisheit" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "...trägt der siebte Weise,\n"
"dessen Bestimmung es ist, zum\n"
"Meister aller zu werden..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin es - " COLOR(RED) "Zelda" COLOR(DEFAULT) ",\n"
"Prinzessin von Hyrule."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Verzeih, daß ich Dich stets in\n"
"dieser Verkleidung aufgesucht habe.\n"
"Doch es war nötig, da ich mich\n"
"vor Ganondorf verstecken mußte."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Ich habe Dich gesehen, als ich mit\n"
"Impa zusammen aus dem \n"
"Schloß floh." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Solange Du die Okarina in Deinen\n"
"Händen hältst, so dachte ich, wäre\n"
"es Ganondorf nicht möglich, das\n"
"Heilige Reich zu betreten. Aber..." BOX_BREAK UNSKIPPABLE "...etwas, das ich nie erwartet\n"
"hätte, ist geschehen..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3D") "Dieses Beben...\n"
SHIFT("\x30") "Was geschieht hier?\n"
SHIFT("\x2E") "Das darf nicht sein!"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prinzessin Zelda... Endlich\n"
"habe ich Dich!" BOX_BREAK UNSKIPPABLE "Ich bin beeindruckt, daß es Dir\n"
"gelungen ist, mir sieben Jahre lang\n"
"zu entkommen!"
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nie wirst Du Zelda retten!\n"
"Wagst Du es, mein Schloß zu\n"
"betreten, vernichte ich auch Dich!"
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "... Hörst Du mich?\n"
"Hier spricht Rauru." BOX_BREAK UNSKIPPABLE "Die sechs Weisen sammeln ihre\n"
"Kraft, um eine Brücke zum Portal\n"
"von Ganondorfs Schloß zu legen..." BOX_BREAK UNSKIPPABLE "Der Wachturm des Schlosses, auch\n"
"der " COLOR(RED) "Teufelsturm" COLOR(DEFAULT) " genannt, wird von\n"
"sechs " COLOR(RED) "Siegeln des Bösen" COLOR(DEFAULT) "\n"
"blockiert!" BOX_BREAK UNSKIPPABLE "Brich die Siegel,\n"
"dringe in den Turm ein und\n"
"rette Prinzessin Zelda!"
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
"Ihr Erschaffer Hyrules!" BOX_BREAK_DELAYED("\x3C") "Öffnet das versiegelte Portal und\n"
"schickt diese Kreatur des Bösen\n"
"in den Abgrund der Hölle!" FADE("\x5A")
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "!\n"
"Zerstöre ihn mit Deiner heiligen\n"
"Waffe - mit dem Master-Schwert!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, heiliges Portal, entriegelt von\n"
"den Weisen... Schließe Dich für\n"
"immer und schütze unsere Welt vor\n"
"dieser üblen Kreatur des Bösen!"
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Danke, " NAME "..." BOX_BREAK UNSKIPPABLE "Dank Deiner Hilfe ist es gelungen,\n"
"den Großmeister des Bösen in das\n"
"Reich der Hölle zu verbannen!" BOX_BREAK UNSKIPPABLE "Nun wird wieder Frieden herrschen\n"
"in unserer Welt... Hoffentlich für \n"
"alle Zeit."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x54") "Danke!\n"
SHIFT("\x5D")  NAME "..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  SHIFT("\x47") "Lebe wohl..." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Möchtest Du unbedingt durch\n"
"dieses Tor gehen? Nun, dann\n"
"verlange ich eine Gegenleistung...\n"
"Sagen wir..." TEXTID("\x70\x72")
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gib mir 10 Rubine!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bitte glaube mir...\n"
"Meine Prophezeiungen waren\n"
"niemals falsch!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du hast jene bösen Geister\n"
"vernichtet, die im Tempel hausten.\n"
"Und Du hast " COLOR(ADJUSTABLE) "Salia" COLOR(DEFAULT) " erweckt..." BOX_BREAK UNSKIPPABLE "Doch sie ist nicht die einzige, die\n"
"Deiner Hilfe bedarf." BOX_BREAK UNSKIPPABLE "Um alle Weisen zu erwecken, mußt\n"
"Du noch weit stärker werden!" BOX_BREAK UNSKIPPABLE "Reise zu den Bergen..." BOX_BREAK UNSKIPPABLE "...in die Tiefen des Wassers..." BOX_BREAK UNSKIPPABLE "...und sogar durch die Zeit..."
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Solange Du die " COLOR(LIGHTBLUE) "Okarina\n"
"der Zeit" COLOR(DEFAULT) " und das " COLOR(LIGHTBLUE) "Master-Schwert" COLOR(DEFAULT) "\n"
"in Deinen Händen hältst..." BOX_BREAK UNSKIPPABLE "...hast Du auch Macht\n"
"über die Zeit!" BOX_BREAK UNSKIPPABLE  NAME ", wir sehen\n"
"uns wieder!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eine neuartige Bombe! Ich kann Dir\n"
"nur eine begrenzte Stückzahl\n"
"anbieten. Ist das Lager leer,\n"
"gibt es keinen Nachschub mehr." EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin " COLOR(RED) "Shiek" COLOR(DEFAULT) ". Ich gehöre\n"
"den letzten Überlebenden\n"
"der Shiekah an..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Wahrlich, Du siehst aus wie der,\n"
"der uns prophezeit wurde. Tapfer " COLOR(RED) "\n"
COLOR(DEFAULT) "hältst Du das " COLOR(RED) "Master-Schwert " COLOR(DEFAULT) "in \n"
"der Hand..."
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Willst Du die Prophezeiung \n"
"erfüllen, so suche nach den fünf \n"
"Tempeln und befreie die dort \n"
"eingesperrten " COLOR(RED) "fünf Weisen" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Einer von ihnen wartet im \n"
COLOR(ADJUSTABLE) "Waldtempel" COLOR(DEFAULT) " darauf, sich Deiner zu \n"
"offenbaren. Es ist ein Mädchen, an  \n"
"das Du Dich sicher erinnern wirst..." BOX_BREAK UNSKIPPABLE "Aufgrund der bösen Aura, die den \n"
"Tempel umgibt, kann sie den \n"
"Ruf des Heiligen Reiches nicht \n"
"hören..." BOX_BREAK UNSKIPPABLE "Mit Deiner jetzigen Ausrüstung\n"
"kannst Du den Tempel nicht \n"
"betreten..." BOX_BREAK UNSKIPPABLE "So höre meine Worte und begib \n"
"Dich nach " COLOR(RED) "Kakariko" COLOR(DEFAULT) ", um dort das \n"
"zu suchen, das Dein Schlüssel zum \n"
"Tempel sein soll..." BOX_BREAK UNSKIPPABLE "Hast Du mich verstanden, \n"
NAME "?"
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Ich fühlte, daß Du derjenige bist,\n"
"der die Okarina haben soll...\n"
"Ich wußte, daß es unsere beste\n"
"und einzige Chance war..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bevor Du aufbrichst, solltest\n"
"Du meinen Worten lauschen..." BOX_BREAK UNSKIPPABLE "So höre denn die Legende, \n"
"die sich die Shiekah über das \n"
"Triforce erzählten..."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als das Triforce in drei Teile\n"
"zerbrach, gelang es Ganondorf \n"
"lediglich, das " COLOR(RED) "Triforce-Fragment\n"
"der Kraft " COLOR(DEFAULT) "zu erringen..."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Durch die Macht des Triforce-Teils\n"
"wurden seine teuflischen Kräfte \n"
"verstärkt. Doch sein Drang, Böses \n"
"zu tun, ist noch nicht befriedigt..."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Daher sucht er nun " COLOR(RED) "die, die \n"
"auserwählt wurden" COLOR(DEFAULT) ", Träger der \n"
"anderen Triforce-Elemente zu \n"
"sein..."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Heute vor genau sieben Jahren\n"
"suchte Ganondorf mit seiner Horde \n"
"wilder Kriegerinnen Hyrule heim..."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als Du das Tor zur Zeit betreten \n"
"hast, bannte Dich das Schwert \n"
"sieben Jahre im Heiligen Reich..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dein Geist ruhte im Vakuum der\n"
"Zeit... Das Triforce fiel in Ganondorfs\n"
"blutige Hände, die Unheil über \n"
"das Heilige Reich brachten..." BOX_BREAK UNSKIPPABLE "Ganondorf verlor mehr und mehr\n"
"sein menschliches Antlitz. Er\n"
"wurde zum Großmeister des Bösen,\n"
"dem Boten des Todes..." BOX_BREAK UNSKIPPABLE "In all den Jahren gelang es mir, \n"
"mich als Shiekah zu tarnen und \n"
"so meinem Schicksal zu entgehen...\n"
"Ich wartete sieben Jahre..."
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Doch nun endlich bist Du \n"
"zurückgekehrt! Die Herrschaft des \n"
"Terrors soll jetzt ihr Ende finden!\n"
"Die Tage des Bösen sind gezählt!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die sechs Weisen werden neue \n"
"Siegel schaffen und Ganondorf \n"
"für immer in die Tiefen der Hölle\n"
"verbannen..." BOX_BREAK UNSKIPPABLE "Ist dies vollbracht, werde ich das \n"
"Tor zum Heiligen Reich auf ewig \n"
"schließen!" BOX_BREAK UNSKIPPABLE "Auf diese Weise wird Ganondorf \n"
"und mit ihm alles Böse für alle \n"
"Zeit aus Hyrule verschwinden." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Um dieses Vorhaben mit Erfolg zu \n"
"krönen, mußt Du mich schützen, \n"
"bis der Plan vollbracht ist." BOX_BREAK UNSKIPPABLE "Nimm nun die Waffe an Dich, die\n"
"die Kraft des Bösen mitten ins\n"
"schwarze Herz trifft..." BOX_BREAK UNSKIPPABLE  SHIFT("\x0D") "Die heiligen " COLOR(LIGHTBLUE) "Pfeile des Lichts" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Endlich gibst Du Dich zu erkennen...\n"
"Ich wußte, daß ich nur dem Jungen\n"
"zu folgen brauchte, um Dich zu\n"
"finden..."
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mein einziger Fehler war, die\n"
"Kräfte des Jungen zu \n"
"unterschätzen..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nein... Es war nicht seine\n"
"Kraft, die ich unterschätzte.\n"
"Es waren die Kräfte des Triforce-\n"
"Symbols für Mut!" BOX_BREAK UNSKIPPABLE "Doch mit dem Element, das er \n"
"besitzt, und dem Triforce der \n"
"Weisheit, das in Deinen Händen \n"
"ruht, schließt sich der Kreis..." BOX_BREAK UNSKIPPABLE "Mit allen drei Elementen werde \n"
"ich zum Herrscher dieser Welt!"
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Als der Auserwählte die Okarina \n"
"spielte, öffnete sich das Portal \n"
"der Zeit. Das Master-Schwert \n"
"machte ihn zum Helden der Legende." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich weiß nicht, warum, aber \n"
"irgendwie scheinen die Hunde die\n"
"Nacht zu mögen...\n"
"Komisch, oder?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Kleiner! Ich verrate Dir\n"
"etwas..." BOX_BREAK "Ich hörte, daß sich in der Nähe des \n"
"Schlosses eine " COLOR(RED) "geheimnisvolle \n"
"Quelle " COLOR(DEFAULT) "befinden soll..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Willst Du in die Zeit, aus der Du\n"
"kamst, zurückkehren, so plaziere \n"
"das Master-Schwert wieder im \n"
COLOR(RED) "Zeitenfels" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Tust Du dies, so reist Du\n"
"sieben Jahre in der Zeit \n"
"zurück..."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Es wird die Zeit kommen, da\n"
"Du in Windeseile an diesen Ort \n"
"zurückkehren mußt... \n"
"Lausche daher meinen Worten..." BOX_BREAK UNSKIPPABLE "Das Lied, das Du spielen mußt, \n"
"um zur Zitadelle der Zeit \n"
"zurückzukehren ist...\n"
COLOR(LIGHTBLUE) "die Kantate des Lichts" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin " COLOR(RED) "Impa" COLOR(DEFAULT) ", Überlebende der \n"
"Shiekah. Meine Aufgabe ist, Zelda \n"
"zu schützen. Alles ist so geschehen, \n"
"wie es die Prinzessin prophezeite."
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wenn Dich die Soldaten hier \n"
"finden, bekommst Du Ärger. Laß \n"
"mich Dich aus dem Schloß führen!"
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hey, Du! Mach keinen Ärger!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du bist ein tapferer Junge!\n"
"Die Vorsehung hat Dich an diesen \n"
"Ort geführt..." BOX_BREAK UNSKIPPABLE "Mir wird nun die Aufgabe zuteil, \n"
"Dich eine Melodie zu lehren, die\n"
"Du nie vergessen darfst!" BOX_BREAK UNSKIPPABLE "Es ist ein Lied, " COLOR(BLUE) "das die \n"
"Königsfamilie von Generation zu \n"
"Generation weitergibt" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Ich habe dieses Lied für\n"
"Prinzessin Zelda gespielt, als sie\n"
"noch ein kleines Kind war." BOX_BREAK UNSKIPPABLE "In den Noten verbergen\n"
"sich mysteriöse Kräfte!" BOX_BREAK UNSKIPPABLE "Lausche nun der Melodie..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin schuld an all dem Unheil, \n"
"das über Hyrule kam..." BOX_BREAK UNSKIPPABLE "Ich war zu jung... Ich konnte noch\n"
"nicht wissen, welche Fährnisse\n"
"sich mir auftun würden..." BOX_BREAK UNSKIPPABLE "Ich habe Dich in all das \n"
"hineingezogen..." BOX_BREAK UNSKIPPABLE "Nun ist es an der Zeit, meinen\n"
"Fehler wiedergutzumachen..." BOX_BREAK UNSKIPPABLE "Leg nun das Master-Schwert aus \n"
"Deinen Händen und schließe so\n"
"das Zeitportal..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die Verbindung zwischen den\n"
"Zeiten sei für immer gelöst..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ",\n"
"gib mir die Okarina..." BOX_BREAK UNSKIPPABLE "Als eine der Weisen habe ich die \n"
"Gabe, Dich in Deine Zeit \n"
"zurückbringen zu können."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Nun herrscht wieder Friede\n"
"in Hyrule..." BOX_BREAK UNSKIPPABLE "Und nun ist es für uns an der\n"
"Zeit, Abschied zu nehmen..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Gehe nun, " NAME ".\n"
"Hole die verlorenen sieben Jahre\n"
"nach!" BOX_BREAK UNSKIPPABLE "Gehe nach Hause... \n"
"Dorthin, wo Dein Platz ist...\n"
"Als der, als der Du aufwuchst..."
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46")  QUICKTEXT_ENABLE "Tss..." QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "tss..." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das scheint für ein Kind\n"
"ein zu hoher Preis zu sein." EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nun gut, ich lasse Dich passieren!\n"
"Schnell!" EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"ERZÄHL DAS BLOSS \n"
"NIEMANDEM!"
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mann, ich bin soooo müde!" BOX_BREAK "Nachtwache ist total langweilig!\n"
"Wenn wenigstens ein paar Geister\n"
"rumspuken würden..." BOX_BREAK "Ich finde so etwas nämlich\n"
"wirklich interessant!" BOX_BREAK "Ich studiere Geister-Wissenschaften\n"
"schon seit Jahren. Man weiß\n"
"ja nie, ob das nicht einmal\n"
"nützlich sein kann!"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Verglichen mit den streunenden\n"
"Promenadenmischungen ist das Fell\n"
"meines Hundes prächtig und \n"
"glänzend!"
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Hund ist gut erzogen...\n"
"Aber manchmal läuft auch er \n"
"nachts in Hyrule herum - so wie\n"
"diese streunenden Stinkeköter!"
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hast Du meinen Richard gesehen?\n"
"Er ist sonst so ein braver Hund,\n"
"aber heute abend ist er\n"
"davongelaufen. Bitte suche ihn!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE " Das ist nicht mein Hundi!\n"
"Wie kannst Du meinen Liebling mit\n"
"so einer Zeckenmatte\n"
"verwechseln?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x46")  QUICKTEXT_ENABLE "Richard!" QUICKTEXT_DISABLE  BOX_BREAK "Da ist ja mein kleiner Richie\n"
"wieder! Vielen Dank!\n"
"Bitte, nimm dies als Belohnung an\n"
"Dich!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nachts, wenn die Köter draußen \n"
"herumstreunen, ist es gefährlich!\n"
"Nein, nicht für Dich, sondern für\n"
"meinen Liebling!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hallo und willkommen\n"
"beim lustigen " COLOR(RED) "Maskenhändler" COLOR(DEFAULT) "!\n"
"Wir handeln mit Masken, die\n"
"allen Leuten Freude bringen..." BOX_BREAK "Wärst nicht auch Du gern ein Bote\n"
"der Freude? Paß auf, ich leihe\n"
"Dir eine Maske, Du verkaufst sie\n"
"und gibst mir dann das " COLOR(RED) "Geld" COLOR(DEFAULT) "!" BOX_BREAK "Willst Du wissen, wie es \n"
"funktioniert, lies das " COLOR(RED) "Schild" COLOR(DEFAULT) "\n"
"zu Deiner Linken." BOX_BREAK "Übrigens: Wenn Du alle Masken \n"
"verkauft hast, wirst auch Du \n"
"glücklicher sein!" BOX_BREAK SHIFT("\x3C") "Vertrau mir..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Wähle eine Maske, indem Du den\n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "nach links oder rechts bewegst.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Mit dem Ladenbesitzer sprechen!\n"
"Nichts ausleihen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eine " COLOR(RED) "Maske " COLOR(DEFAULT) "ist ein " COLOR(YELLOW) "[C]-Knopf-\n"
"Gegenstand" COLOR(DEFAULT) ". Plaziere sie auf " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"und drücke " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", um sie zu tragen." BOX_BREAK "Sprichst Du jemanden an, während\n"
"Du die Maske trägst, erhältst Du\n"
"eine entsprechende Reaktion." BOX_BREAK "Wenn jemand an der Maske \n"
"interessiert ist, wird Dich \n"
"derjenige danach fragen." BOX_BREAK "Irgendwo in diesem Land findet\n"
"sich für jede Maske ein Käufer." BOX_BREAK SHIFT("\x26") "Vertrau mir einfach..." EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vor kurzem sah ich noch ein\n"
"goldiges, kleines Mädchen hier...\n"
"Vielleicht ist sie zum Schloß \n"
"gegangen... Wer weiß..."
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Du hast sie verkauft?! Fantastisch!\n"
"Dann zahl mir nun meine " COLOR(RED) "10 Rubine \n"
COLOR(DEFAULT) "für die Fuchs-Maske." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Du hast die Maske noch nicht\n"
"verkauft. Vertrau mir... Es  wird\n"
"sich schon ein Käufer finden." EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bezahlung erhalten!" EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Was?!" QUICKTEXT_DISABLE "\n"
"Du hast mein Geld verbraten?!" BOX_BREAK QUICKTEXT_ENABLE "Wie kannst Du es wagen!" QUICKTEXT_DISABLE  BOX_BREAK "Du besorgst besser ganz schnell \n"
"mein Geld, oder..." EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey!" BOX_BREAK "Gut gemacht!\n"
"Alle Masken sind verkauft." BOX_BREAK "Ich wußte, daß Du der richtige\n"
"Mann, ähh, Junge dafür bist!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Als Belohnung für Deine Mühe \n"
"sollst Du eine ganz besondere \n"
"Maske erhalten!" BOX_BREAK UNSKIPPABLE "Dies ist die " COLOR(RED) "Maske des Wissens." COLOR(DEFAULT) "\n"
"Es ist eine mysteriöse Maske aus\n"
"dem Erbe der Shiekah." BOX_BREAK UNSKIPPABLE "Suche, und Du wirst die \n"
"verborgenen Kräfte der Maske \n"
"entdecken... Sie ist nützlich und\n"
"unheimlich zugleich..." BOX_BREAK UNSKIPPABLE "Warum sie unheimlich ist?" BOX_BREAK UNSKIPPABLE "Das wirst Du herausfinden, wenn\n"
"Du älter wirst und irgendwann den\n"
"Sinn des Lebens erkennst..." BOX_BREAK UNSKIPPABLE "Vertrau mir, hahaha..." EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ich habe Nachschub bekommen! \n"
"Von nun an kannst Du jede \n"
"beliebige Maske ausleihen...\n"
"Vertrau mir..." EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Willkommen!\n"
"Welche Maske möchtest Du \n"
"leihen?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bewege den " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " nach rechts oder\n"
"links, um eine Maske zu wählen.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Frage nach der Maske des Wissens! \n"
"Nichts ausleihen!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Dies ist die " COLOR(RED) "Maske des Wissens" COLOR(DEFAULT) ".\n"
"Es ist eine mysteriöse Maske aus\n"
"dem Erbe der Shiekah." BOX_BREAK "Suche, und Du wirst die \n"
"verborgenen Kräfte der Maske \n"
"entdecken... Sie ist nützlich und\n"
"unheimlich zugleich..." BOX_BREAK "Warum sie unheimlich ist?" BOX_BREAK "Das wirst Du herausfinden, wenn\n"
"Du älter bist und irgendwann den\n"
"Sinn des Lebens erkennst..." BOX_BREAK "Vertrau mir, hahaha..." EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maske des Wissens -- Unverkäuflich" COLOR(DEFAULT) "\n"
"Eine Maske mit mysteriösen Kräften." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Schädel-Maske -- Preis 20 Rubine" COLOR(DEFAULT) "\n"
"Eine gehörnte Totenschädelmaske." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Geister-Maske -- Preis 30 Rubine\n"
COLOR(DEFAULT) "Eine traurig blickende Holzmaske." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fuchs-Maske -- Preis 10 Rubine\n"
COLOR(DEFAULT) "Der letzte Schrei! Sehr angesagt!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Hasenohren -- Preis 50 Rubine\n"
COLOR(DEFAULT) "Wippende Hasenohren! Supersüß!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Schädel-Maske -- Gebührenfrei!" COLOR(DEFAULT) "\n"
"Eine gehörnte Totenschädelmaske." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Geister-Maske -- Gebührenfrei!\n"
COLOR(DEFAULT) "Eine traurig blickende Holzmaske." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fuchs-Maske -- Gebührenfrei!\n"
COLOR(DEFAULT) "Der letzte Schrei! Sehr angesagt!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Hasenohren -- Gebührenfrei!\n"
COLOR(DEFAULT) "Wippende Hasenohren! Supersüß!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Goronen-Maske -- Gebührenfrei! \n"
COLOR(DEFAULT) "Trägst Du diese Maske,\n"
"lächelst Du immerzu!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Zora-Maske -- Gebührenfrei!" COLOR(DEFAULT) "\n"
"Sieht besonders cool beim\n"
"Schwimmen aus!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Gerudo-Maske -- Gebührenfrei!\n"
COLOR(DEFAULT) "Mit ihren verführerischen Augen \n"
"macht sie aus Dir ein \n"
"zauberhaftes Mädchen!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Maske des Wissens -- Gebührenfrei!" COLOR(DEFAULT) "\n"
"Eine Maske aus dem Erbe der \n"
"Shiekah! Man erzählt sich, sie\n"
"besäße mysteriöse Kräfte." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Schädel-Maske \n"
COLOR(DEFAULT) "leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Geister-Maske " COLOR(DEFAULT) "\n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Fuchs-Maske " COLOR(DEFAULT) "\n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Hasenohren" COLOR(DEFAULT) " \n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Goronen-Maske" COLOR(DEFAULT) " \n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Zora-Maske" COLOR(DEFAULT) "\n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Gerudo-Maske" COLOR(DEFAULT) "\n"
"leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Möchtest Du die " COLOR(RED) "Maske des\n"
"Wissens" COLOR(DEFAULT) " leihen?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, großartig! Du hast sie\n"
"verkauft! Bitte zahle mir \n"
"für die Schädel-Maske die\n"
COLOR(RED) "20 Rubine" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, großartig! Du hast sie\n"
"verkauft! Bitte zahle mir\n"
"für die Geister-Maske die\n"
COLOR(RED) "30 Rubine" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, großartig! Du hast sie\n"
"verkauft! Bitte zahle mir\n"
"für die Hasenohren die\n"
COLOR(RED) "50 Rubine" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Du hast die Maske noch\n"
"nicht verkauft? Dann biete sie\n"
"einfach weiterhin an." BOX_BREAK "Oder möchtest Du sie gegen eine\n"
"andere Maske tauschen?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ja!\n"
"Nein!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die Fragmente des Triforce...\n"
"Ich spüre... Ihre Macht scheint\n"
"sich wieder zu vereinigen... "
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Die fehlenden zwei Fragmente!\n"
"Ich warte seit\n"
"sieben Jahren darauf!" BOX_BREAK UNSKIPPABLE "Ich bin wirklich überrascht! Ich\n"
"hätte nicht erwartet, daß gerade\n"
"ihr zwei sie tragen würdet!"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Endlich! Endlich! Die drei\n"
"Fragmente sind wieder\n"
"vereint!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Diese Symbole der Macht sind\n"
"nichts für euch zwei! Ihr seid\n"
"dafür nicht geschaffen!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich allein bin der rechtmäßige\n"
"Träger des Triforce! Übergebt mir\n"
"die Fragmente!\n"
"Ich befehle es!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"Ich kann Dir nicht helfen!\n"
"Die Aura des Bösen ist\n"
"zu mächtig!" BOX_BREAK COLOR(LIGHTBLUE)  UNSKIPPABLE "Tut mir leid, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich, der Großmeister des Bösen... \n"
"Geschlagen von einem Kind?!\n"
"Das... darf... nicht... sein..."
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf... bemitleidenswerte\n"
"Kreatur..." BOX_BREAK UNSKIPPABLE "Da ihm der Sinn für\n"
"Gerechtigkeit fehlte, konnte er die\n"
"Macht der Götter nicht nutzen..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", hör zu!\n"
"Der Turm stürzt in sich zusammen!" BOX_BREAK UNSKIPPABLE "Das ist Ganondorfs letzte, böse\n"
"Tat! Die Trümmer sollen uns\n"
"zerschmettern! Schnell! Wir\n"
"müssen fliehen!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Schnell! Folge mir!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Es ist vorüber... Alles..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... \n"
"Tut mir leid, daß ich Dir im Kampf\n"
"nicht helfen konnte." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Was ist das für ein Geräusch?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Diesmal hat er keine Macht mehr\n"
"über mich!" COLOR(DEFAULT) "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Wir kämpfen gemeinsam!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
"Das Master-Schwert!\n"
"Es ist hier! \n"
QUICKTEXT_ENABLE "Schnell!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich versuche, Ganon mit meiner\n"
"Kraft zu bannen!\n"
"Nimm Du das Schwert und\n"
"versetze ihm den Todesstoß!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Oh, ihr Sechs Weisen...\n"
QUICKTEXT_ENABLE  SHIFT("\x3F") "Es ist soweit!\n"
SHIFT("\x32") "Sendet Eure Kraft!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "DUUUU... widerlicher..." TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "ICH VERFLUCHE DICH... ZELDA!\n"
TEXT_SPEED("\x02") "ICH VERFLUCHE EUCH... IHR WEISEN!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "ICH...\n"
"VERFLUCHE...\n"
"DICH... " QUICKTEXT_ENABLE  NAME "!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Arrgh! Eines Tages werde ich\n"
"dieses Siegel brechen..." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Dann werde ich eure\n"
"Nachfahren auslöschen!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Solange das Fragment der Kraft\n"
"in meiner Hand ist..." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
TEXT_SPEED("\x02") "Du... " TEXT_SPEED("\x00") "wer bist Du?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x11") "Das " COLOR(ADJUSTABLE) "Wald-Siegel " COLOR(DEFAULT) "ist gebrochen!\n"
SHIFT("\x1A") "Beeil Dich, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "Das " COLOR(RED) "Feuer-Siegel " COLOR(DEFAULT) "ist gebrochen!\n"
SHIFT("\x33") "Beeil Dich, Bruder!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0A") "Das " COLOR(BLUE) "Wasser-Siegel " COLOR(DEFAULT) "ist gebrochen!\n"
SHIFT("\x2E") "Beeil Dich, Liebster!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x06") "Das " COLOR(PURPLE) "Schatten-Siegel " COLOR(DEFAULT) "ist gebrochen!\n"
SHIFT("\x1C") "Bitte rette die Prinzessin!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0A") "Das " COLOR(YELLOW) "Geister-Siegel" COLOR(DEFAULT) " ist gebrochen!\n"
SHIFT("\x36") "Streng Dich an, Kleiner!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x11") "Das " COLOR(LIGHTBLUE) "Licht-Siegel" COLOR(DEFAULT) " ist gebrochen!\n"
SHIFT("\x41") "Schnell jetzt!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME ", ist das nicht...?!"
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Diese legendäre Klinge..." COLOR(DEFAULT)  FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(LIGHTBLUE) "Das Master-Schwert!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Finde die anderen\n"
"Weisen und rette Hyrule!" FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dieser schreckliche Typ ist wie\n"
"wild davongaloppiert!"
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie furchtbar...\n"
"Oh, wie schrecklich..."
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, was willst Du?\n"
"Ich habe keine Zeit, mit\n"
"Dir zu tratschen!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bitte... Verkaufe mir etwas mit " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Bitte verkaufe mir etwas...\n"
"Bitte... In einer Flasche..."
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nein...\n"
"Das ist nicht das, was ich will...\n"
"Ich möchte " COLOR(RED) "etwas in einer Flasche" COLOR(DEFAULT) "...\n"
"Nicht so etwas..."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nein...\n"
"Das kann ich nicht nehmen...\n"
"Es ist nicht das, was ich\n"
"haben will..."
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh," COLOR(BLUE) " " COLOR(LIGHTBLUE) "Blaues Feuer" COLOR(DEFAULT) "!\n"
"Ich kaufe es für " COLOR(RED) "150 Rubine" COLOR(DEFAULT) "!\n"
"Und nicht feilschen, okay?"
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, ein " COLOR(PURPLE) "Fisch" COLOR(DEFAULT) "!\n"
"Ich kaufe ihn für " COLOR(RED) "100 Rubine" COLOR(DEFAULT) "!\n"
"Und nicht feilschen, okay?"
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, ein niedlicher " COLOR(ADJUSTABLE) "Käfer" COLOR(DEFAULT) "!\n"
"Ich kaufe ihn für " COLOR(RED) "50 Rubine" COLOR(DEFAULT) "!\n"
"Und nicht feilschen, okay?"
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, eine hübsche, kleine " COLOR(LIGHTBLUE) "Fee" COLOR(DEFAULT) "!\n"
"Ich kaufe sie für " COLOR(RED) "25 Rubine" COLOR(DEFAULT) "!\n"
"Und nicht feilschen, okay?"
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh... Du bist ja ein agiler,\n"
"junger Mann. Und Du bist auch\n"
"ganz ansehnlich. Und mutig!" BOX_BREAK UNSKIPPABLE "Hehehe... Du heißt\n"
NAME ", nicht wahr?" BOX_BREAK UNSKIPPABLE "Hehehe... Schau nicht so.\n"
"Ich kann Gedanken lesen." BOX_BREAK UNSKIPPABLE "Wenn ich so gut aussähe wie Du,\n"
"dann könnte ich mein Geld auf\n"
"andere Weise verdienen...\n"
"Hehehe..." BOX_BREAK UNSKIPPABLE "Aber immerhin betreibe ich den\n"
"einzigen " COLOR(RED) "Gespenstermarkt" COLOR(DEFAULT) " von\n"
"Hyrule!" BOX_BREAK UNSKIPPABLE "Dank Ganondorf - gepriesen sei\n"
"sein Name - gehen die Geschäfte \n"
"zur Zeit blendend... Hehehe..." BOX_BREAK UNSKIPPABLE "Ich kann nur hoffen, daß das\n"
"auch so bleibt!" BOX_BREAK UNSKIPPABLE "Die Geister nennt man \n"
COLOR(RED) "Irrlichter " COLOR(DEFAULT) "oder" COLOR(RED) " Nachtschwärmer" COLOR(DEFAULT) "...\n"
"Sie tragen allen Haß der Welt...\n"
"Und sie hassen alle Welt..." BOX_BREAK UNSKIPPABLE "Wenn Du einen Geist fängst, dann\n"
"werde ich Dich reich belohnen,\n"
"mein Junge! Hehehe..."
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na, mein Junge! Hast Du ein Irrlicht\n"
"oder einen Nachtschwärmer dabei?\n"
"Ich gebe Dir 10 Rubine \n"
"für ein Irrlicht." BOX_BREAK "Für einen Nachtschwärmer erhältst\n"
"Du 50 Rubine sowie 100 Punkte!\n"
"Du hast bis jetzt " COLOR(PURPLE)  HIGHSCORE(HS_POE_POINTS) " Punkte" COLOR(DEFAULT) " auf\n"
"dem Nachtschwärmer-Konto gut!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, Du bringst mir etwas!" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Nun..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Laß sehen..." BOX_BREAK UNSKIPPABLE "Es ist ein " COLOR(RED) "Irrlicht" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Hier sind " COLOR(RED) "10 Rubine" COLOR(DEFAULT) ".\n"
"Vielen Dank!" BOX_BREAK UNSKIPPABLE "Hehehe..."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, Du bringst mir etwas!" BOX_BREAK UNSKIPPABLE "Nun..." BOX_BREAK UNSKIPPABLE "Erstaunlich!\n"
"Das ist ja ein " COLOR(RED) "Nachtschwärmer" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Dafür bekommst Du " COLOR(RED) "50 Rubine" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Obendrein hast Du nun " COLOR(RED) "100 Punkte\n"
COLOR(DEFAULT) "auf dem Nachtschwärmer-Konto gut." BOX_BREAK UNSKIPPABLE "Hast Du " COLOR(RED) "1.000 Punkte" COLOR(DEFAULT) " gesammelt,\n"
"dann wartet eine geniale \n"
"Belohnung! Hehehe..."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh! WOW!" BOX_BREAK UNSKIPPABLE "Du hast jetzt " COLOR(RED) "1.000 Punkte" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Du bist ja der geborene\n"
COLOR(RED) "Geisterjäger" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Du erwartest noch etwas von\n"
"mir? Was denn? Hehehe..." BOX_BREAK UNSKIPPABLE "Dank Dir ist mein Bestand an\n"
COLOR(RED) "Nachtschwärmern" COLOR(DEFAULT) " enorm gestiegen...\n"
"Dies ist der letzte Geist, den ich \n"
"Dir abnehme." BOX_BREAK UNSKIPPABLE "Ach, Du wartest auf das, was ich\n"
"Dir für ein 1.000 Punkte-Konto\n"
"versprochen habe? Hehehe..." BOX_BREAK UNSKIPPABLE "Na, da will ich mal nicht so sein...\n"
"Nimm das hier!"
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh? Was ist das?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Das" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ist" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Eine Fee" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!" BOX_BREAK UNSKIPPABLE "Dann... Dann kommst Du...\n"
"Kommst Du aus dem Wald?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Du... Du hast nicht auch\n"
"zufällig... den " COLOR(ADJUSTABLE) "Heiligen Stein des \n"
"Waldes" COLOR(DEFAULT) ", oder? Ich meine diesen\n"
"funkelnden, grünen Stein..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich hatte einen Traum...\n"
"Darin überzogen dunkle Wolken\n"
"unser Land Hyrule..." BOX_BREAK UNSKIPPABLE "Doch plötzlich... durchschnitt ein\n"
"Strahl hellen Lichts diese Wolken...\n"
"Er kam aus dem Wald, und ganz\n"
"Hyrule erstrahlte in seinem Glanz!" BOX_BREAK UNSKIPPABLE "Das Licht verwandelte sich in\n"
"einen Jungen, der einen " COLOR(ADJUSTABLE) "glitzernden,\n"
"grünen Stein" COLOR(DEFAULT) " in den Händen hielt.\n"
"Ihn begleitete eine " COLOR(LIGHTBLUE) "Fee" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich weiß, es war eine\n"
"Prophezeiung, daß jemand aus den\n"
COLOR(ADJUSTABLE) "Tiefen des Waldes" COLOR(DEFAULT) " kommen würde..." BOX_BREAK UNSKIPPABLE "Ich dachte, Du wärst es..." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x37") "Oh! Tut mir leid!" BOX_BREAK UNSKIPPABLE "Ich habe mich ein bißchen\n"
"mitreißen lassen von meiner\n"
"Geschichte und mich gar nicht\n"
"standesgemäß vorgestellt!" EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich bin " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ", Prinzessin von Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was? Kennen wir uns?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh... Das ist aber süß!\n"
"Sagst Du mir, woher Du sie\n"
"hast?"
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh mein Gott!\n"
"Hilfe!"
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ja? Was ist denn?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich hasse Füchse!"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du siehst bescheuert aus!"
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, das steht Dir wirklich gut!"
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bist Du so häßlich, daß Du das \n"
"Ding tragen mußt?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh... Bist Du ein Zora?\n"
"Diese Augen... Wirklich\n"
"faszinierend..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist ja schrecklich!\n"
"Komm bloß nicht näher!"
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow... Eine Maske! Das erinnert\n"
"mich an die Zeit, als ich noch\n"
"ein kleines Kind war."
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, das ist lustig... Es\n"
"bringt mich zum Lachen!\n"
"Hihihihi!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Oh-oh!" QUICKTEXT_DISABLE " Sorry, Mutter!\n"
"Oh... Ach, Du bist es!\n"
"Erschreck mich doch nicht \n"
"so!"
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du hast einen Riesenkürbis!"
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mach das nie wieder!\n"
"Ich bin so schreckhaft..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Findet hier ein Maskenwettbewerb \n"
"statt? \n"
QUICKTEXT_ENABLE "Wenn ja, dann wähle ich Dich!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Ein Hase!\n"
"Erst kürzlich sah ich einen \n"
"Mann, der auf dem Feld den \n"
"Hasen nachjagte."
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, welch gutaussehende Frau!\n"
"Aber Du bist ein wenig klein,\n"
"oder?"
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow, mit der Maske siehst Du \n"
"hübscher aus als vorher!"
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eine Maske... Das erinnert mich an\n"
"meine Jugendzeit. Damals hab ich\n"
"auch welche getragen. Heute würde \n"
"man mich als Spinner beschimpfen!"
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, hübsch... Ein wandelnder Fisch...\n"
"Ich könnte Dich zum Abendessen \n"
"einladen... Als Hauptgericht!"
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nicht schlecht. So einen \n"
"großen Hasen kriegt man selten in \n"
"die Pfanne!"
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AAAAAAAAAAAH!\n"
"EINE GERUDO-KRIEGERIN!!!!" QUICKTEXT_DISABLE  BOX_BREAK "Was? Nur eine Maske?!\n"
"Wie konntest Du mich so \n"
"erschrecken?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sorry, aber ich habe zu tun. Ich \n"
"muß etwas zum Essen einkaufen."
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Ein Fuchs! Hast Du auch\n"
"eine Gans gestohlen?!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist gespenstisch!\n"
"Ein Junge in Kakariko hat\n"
"nach einer Maske wie dieser\n"
"gesucht!"
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gähn... Hast Du keine andere\n"
"Maske?"
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Welch eine seltsame Maske!\n"
"Die ist klasse!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stör uns jetzt nicht! Wir haben \n"
"hier Wichtiges zu, äh, \n"
"besprechen!"
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich denke gar nicht daran,\n"
"irgendeine andere Frau \n"
"anzuschauen!"
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beachte ihn nicht, Darling...\n"
"Wir haben Besseres zu tun...\n"
"Küß mich..."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Hase! Sorry, aber ich hab \n"
"schon ein Häschen hier... und es \n"
"ist hübscher als Du!"
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Gerücht besagt, daß es einen \n"
"Laden gibt, der das ultimative\n"
"Elixier verkauft!"
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich hörte, daß es irgendwo eine \n"
"Kreatur geben soll, die " COLOR(LIGHTBLUE) "hylianische \n"
"Schilde" COLOR(DEFAULT) " frißt..."
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich kam her, um Bomben zu \n"
"verkaufen."
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ich... Ich habe Angst...\n"
"Große Angst, daß dieser Mann \n"
"Hyrule den Untergang bringt." BOX_BREAK UNSKIPPABLE "Er besitzt übermenschliche Kräfte!" BOX_BREAK UNSKIPPABLE "Doch nun, da Du hier bist, wird \n"
"alles gut..." EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das ist ja albern!"
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Würdest Du arbeiten,\n"
"kämst Du nicht auf solch\n"
"dämliche Ideen!"
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, Du trägst eine Holzmaske!\n"
"Die brennt sicher gut!"
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bist Du wirklich so häßlich,\n"
"daß Du dieses Ding tragen mußt?"
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ogottogottogott... Das darfst Du \n"
"aber nicht, mich so erschrecken!"
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du Böser! \n"
"Mich so auf den Arm zu \n"
"nehmen..." BOX_BREAK "Welch ein Schelm!"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huch, eine Frau...\n"
"Was will die denn hier...?"
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich werde auch versuchen, eine \n"
"Maske zu schnitzen... Vielleicht \n"
"eine Pinocchio-Maske. Wegen der \n"
"langen Nase... Hehe..."
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa! Kommst Du gerade aus dem \n"
"Fratzenwald?"
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, der Nachwuchsheld!\n"
"Wie läuft's denn so?\n"
"Alles klar?"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin im Dienst!\n"
"Ich darf nicht lachen!\n"
"VERSCHWINDE!"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, eine Maske... Schützt sie\n"
"Dich auch vor Faustschlägen?"
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, wie süß!\n"
"Aber nicht so süß wie meine \n"
"Hühner!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm, eine Maske...\n"
"Trägst Du sie, ist es ziemlich \n"
"schwer, festzustellen, ob Du \n"
"traurig oder fröhlich bist!"
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"So häßlich bist Du nun auch \n"
"wieder nicht, daß Du eine Maske\n"
"tragen müßtest."
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Auf dem Friedhof ist auch ein\n"
"Junge, dem so etwas gefallen \n"
"würde..."
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na, hübsche Frau?! Heute abend\n"
"schon etwas vor?"
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WÜRG!\n"
"Ich dachte gerade, Du wärst meine\n"
"Ex-Freundin! Erschreck mich bitte\n"
"nie wieder so..."
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mein Vater sprach mal von einem\n"
"Meisterschmied...\n"
"Wie dem auch sei, ich verkaufe\n"
"Hühner..."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, ein Monster! Ich werde es\n"
"einen Kopf kürzer machen und\n"
"seine Gebeine durch den\n"
"Fleischwolf drehen..."
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wer bist Du? Ich kann das von \n"
"hier aus schlecht erkennen..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, Du bist es! Trägst Du Deine \n"
"Haare heute anders?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, hast Du eine Beule am Kopf?"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huch, ein Außerirdischer!"
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Füchse finde ich nicht\n"
"besonders attraktiv!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mit dieser Maske wirst Du bei\n"
"Frauen nicht viel Erfolg haben..."
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich war schon immer gegen \n"
"Genversuche..."
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow, die Möglichkeiten der\n"
"plastischen Chirurgie sind\n"
"erstaunlich!"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ungezogener Bengel!\n"
"Wenn Du jemanden ansprichst,\n"
"solltest Du stets den \n"
"Augenkontakt suchen!"
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Jugend von heute!\n"
"Nun tragen sie schon Masken, um \n"
"wie Frauen auszusehen! Zu meiner\n"
"Zeit hätte es das nicht gegeben!"
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Unverschämtes Balg! Wie läufst Du \n"
"überhaupt herum?! Dein Hemd ist \n"
"nicht gebügelt, Deine Schuhe sind\n"
"schmutzig und Du bist vorlaut!"
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Äußerst interessant! Diese Maske\n"
"scheint eine Todesmaske des Zulu-\n"
"Kultes zu sein! Die Tiki-Priester\n"
"verwenden sie bei Ritualen..."
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eine Maske! Aber keine \n"
"besonders hübsche..."
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nette Maske, leider habe ich keine\n"
"Zeit, sie mir näher anzuschauen."
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eine Maske gleicht einem\n"
"Musikinstrument. Sie spiegelt den\n"
"Charakter ihres Besitzers wieder. \n"
"Ich mag das..."
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meine Güte, was für eine \n"
"Superrübe! Bleibst Du damit\n"
"nicht überall hängen?"
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ist das eine Rattenmaske?!"
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Welch bezaubernde Schönheit!\n"
"Niemals blickte ich in ein\n"
"Antlitz, das anmutiger war..."
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich will Dir ja nicht zu nahe\n"
"treten... Aber Du siehst aus wie\n"
"ein Vollidiot!"
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cooles Outfit! Sind Deine Eltern \n"
"Zoras?"
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hör auf mit den Spielchen\n"
"und erlöse uns von dem Fluch!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ein Schädel! Er erinnert mich an\n"
"den Fluch... Den Fluch der \n"
"Skulltulas!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Verzeih mir, daß ich nicht lache,\n"
"aber ich wurde verflucht, und das\n"
"ist nicht sehr lustig..."
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "Whoa!\n"
"Das macht mir Angst!\n"
"Ich weiß, daß ich schon \n"
"furchteinflößend bin... Aber das..."
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huch! Aaargh!" BOX_BREAK "Oh, es ist nur ein Kind! Du \n"
"darfst einen alten Mann doch \n"
"nicht so erschrecken!"
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow, ein riesiger Schwellkopf! \n"
"Ich habe auch einen! Sind wir \n"
"verwandt?"
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Weißt Du, was für eine Maske Du\n"
"trägst? Damit sollte man keine\n"
"Scherze treiben..."
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sorry, ich habe jetzt keine Zeit\n"
"für Dich, ich muß ein neues Grab\n"
"ausheben..."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was ist das denn? Das sieht\n"
"nicht besonders unheimlich aus...\n"
"Na ja, vielleicht unheimlich\n"
"bescheuert..."
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! Eine Fuchs-Maske! \n"
"Abgefahren! Mein Daddy wollte \n"
"mir so eine besorgen!"
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du siehst aus wie\n"
"der Totengräber...\n"
"Das macht mir keine Angst!"
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow, cool! Richtig unheimlich!\n"
"Unheimlicher als Boris..."
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Eine nette Maske... Aber wir \n"
"Kokiri sind hübscher, oder?"
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! Das kenne ich...\n"
"So etwas habe ich kürzlich in\n"
"den Verlorenen Wäldern gesehen..."
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Oh, wie goldig..."
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh... Schnief... Heul...\n"
"Diese Maske...\n"
"Sie macht mir Angst..."
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pah! Das beeindruckt mich nicht!\n"
"Sicher trägst Du sie nur, weil Du\n"
"vor mir, dem mächtigen Mido, \n"
"Angst hast..."
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaargh! Was? Ach so...\n"
"Nein, ich habe keine Angst!\n"
"Aber komm bloß nicht näher,\n"
"hörst Du?!"
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, coole Maske!\n"
"Ha! War nur Spaß!\n"
"Damit siehst Du noch dämlicher \n"
"aus als vorher!"
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ach, unser Süßer! Das steht\n"
"Dir, Du solltest sie aufbehalten!"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hilfeeeeeeeeee!\n"
"Das... Das erzähle ich Mido!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Iiiiihhhhhhhhh!\n"
"Wenn ich das Mido erzähle, \n"
"bekommst Du Ärger!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaaaaaarggghhh!\n"
"Mir ist ein Waldgeist erschienen!"
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Ist die süß!\n"
"Äh... Sag Mido nicht, daß mir die \n"
"Maske gefällt!"
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was?!\n"
"Du bist zurück!\n"
"Ich erkenne Dich, selbst wenn Du\n"
"diese Maske trägst!"
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich frage mich, wie Mido auf diese \n"
"Maske reagieren würde.\n"
"Das würde ich wirklich gerne \n"
"sehen!"
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, verstehe...\n"
"Du trägst diese Maske, um Mido\n"
"zu erschrecken, stimmt's?!"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hihi! Welch lustige Maske!\n"
"Obwohl, einem Mädchen würde sie\n"
"sicher besser stehen... Hehehe..."
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hihi!\n"
"Eine Holzmaske? Sieht aus, als\n"
"ob Du ein Brett vorm Kopf \n"
"hättest! Hihihi..."
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Welch häßliche Fratze!" BOX_BREAK "Und da beschweren sich manche \n"
"Kinder, daß sie nicht hübsch genug \n"
"seien..."
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallo Kartoffelkopf! Hihihi..."
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! Wo hast Du das denn her?\n"
"Von außerhalb des Waldes!\n"
"Wow! Das ist unglaublich!"
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Witzig, aber nicht ganz mein \n"
"Fall..."
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cool! Diese Maske sieht so \n"
"richtig unheimlich und diabolisch \n"
"aus! Groovy!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh Mann! Hier laufen manchmal\n"
"Spinner herum..."
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Danke, aber ich brauche nicht\n"
"noch eine... Meine gefällt mir ganz\n"
"gut..."
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Du machst mir Angst! Willst \n"
"Du das?"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "Was bist Du denn? Ach, Du bist \n"
"eines dieser goldigen kleinen \n"
"Taschenmonster, oder?"
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "Wie goldig, ein Häschen!\n"
"Hast Du denn auch ein \n"
"Stummelschwänzchen?"
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "Irgendwie erinnerst Du mich \n"
"an meine Großmutter..."
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi Feen-Junge! Ach so, Du bist \n"
"verkleidet, ich darf Dich nicht \n"
"erkennen! Na gut... Huch, wer bist\n"
"Du denn?!"
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wow! Du hast aber große Augen! \n"
"Aber... wo sind Deine Ohren?"
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, dieses Gesicht kenne ich\n"
"doch! Bist Du Fox McCloud?\n"
"Ich habe schon viel von Dir\n"
"gehört!"
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hallo Bruder!\n"
"Schönes Wetter heute, oder?!"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Moment... Ich kenne Dich...\n"
"Du bist... Kaputchi... Nein...\n"
"Aber so ähnlich klang doch\n"
"Dein Name, oder..."
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh... Wie häßlich! Genauso häßlich\n"
"wie Basil!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, sieht aus wie meine Frau...\n"
"Ähem, ich meine, nein, eigentlich...\n"
"Nein, niemals..."
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gähn...\n"
"Ich bin ziemlich müde...\n"
"Zeig mir das Ding später..."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Verschwinde!\n"
"Ich bin beschäftigt!"
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tja! Das macht Spaß! Genieße \n"
"Deine Jugend... Später, wenn Du \n"
"erwachsen bist, zählt nur noch die \n"
"Arbeit!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"HUCH!\n"
"Puh, nur eine Maske...\n"
"Verschwinde hier, Kleiner!"
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, wie lustig!\n"
"Das hat mich ein wenig \n"
"aufgeheitert! Danke, Kleiner!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm, laß mal schauen...\n"
"In der Tat... Die Maske wurde aus\n"
"einem alten Sargdeckel gefertigt...\n"
"Ein Relikt aus dem Totenreich!"
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, eine Schädelmaske...\n"
"Sehr interessant... Es ist ein\n"
"echter Schädel, es kleben noch\n"
"ein paar Würmer und Maden daran!"
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Zeig mal her... Ja, sehr gute\n"
"Handarbeit... Dies ändert jedoch\n"
"nichts an der Tatsache, daß Du \n"
"damit ziemlich dämlich aussiehst!"
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laß mal sehen... Aha... Sehr \n"
"interessant. So was hab ich schon \n"
"einmal gesehen... Ich glaube, es \n"
"war in einem Nachtclub..."
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mampf... Mampf...\n"
"Oh, eine Maske, cool...\n"
"Willst Du nicht ein paar Bohnen \n"
"kaufen?"
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mampf... Rülps...\n"
"Schön, aber ich habe keine\n"
"Verwendung dafür..."
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mampf... Börps...\n"
"Danke, aber die paßt nicht\n"
"zu meinem Wohnzimmerschrank."
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mampf... Börps...\n"
"Danke, aber Masken mag ich nicht\n"
"besonders..."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was ist Euer Begehr?"
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ihr scheint kein Wasserwesen zu \n"
"sein..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ihr wirkt sehr exotisch, woher\n"
"kommt Ihr?"
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ihr mögt das Antlitz der Zoras\n"
"besitzen, doch Eure Statur gleicht \n"
"der eines Gartenzwerges..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was?! Ersucht da ein niederes \n"
"Getier bei mir Audienz?"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Diese Fratze... Gar schrecklich!\n"
"Zu Hilfe!"
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Diese Maske... Sie erinnert mich\n"
"an einen alten Freund.\n"
"Sein werter Name ist Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wer wagt es, das edle hylianische \n"
"Zora-Geschlecht der Lächerlichkeit \n"
"preiszugeben?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hihi! Du bist süß... Zum Anbeißen!"
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das sieht lustig aus!"
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laß das, so etwas trägt kein \n"
"Mann!"
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wie ich sehe, hast Du Dich \n"
"entschloßen, ein Zora zu werden!\n"
"Nun steht unserer Heirat nichts\n"
"mehr im Wege!"
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHOA!\n"
"Mein Herz! Welch ein Schock!"
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das sieht nicht nett aus...\n"
"Tschüß..."
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hm...\n"
"Bist Du ein Travestie-Künstler?"
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du solltest mehr Steine fressen!\n"
"Wenn nicht, wirst Du immer so \n"
"mickrig bleiben!"
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laß mich allein!"
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Willst Du mich zum Lachen bringen?\n"
"Vergiß es! Das ist nicht lustig."
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich habe schon mehr gelacht..."
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich mag keine Gerudos!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Stör mich nicht!\n"
"Verschwinde!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Glaubst Du wirklich, daß Du\n"
"verkleidet bist?"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aus dem Weg!\n"
"Verschwinde! Dies ist kein\n"
"Kinderspielplatz!"
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du scheinst Mut zu haben, Dich\n"
"in diese Gegend zu wagen!\n"
"Glaub bloß nicht, daß Du uns \n"
"täuschen kannst!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Was soll das?\n"
"Willst Du mich zum Narren\n"
"halten?"
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du bist sehr mutig, Dich mit \n"
"dieser Maske in unsere Gegend\n"
"zu wagen! Du gefällst mir!"
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Das sind Spiele aus dem \n"
"Kindergarten! Werde erwachsen!"
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nanu? Du... Du siehst aus wie ich!\n"
"Nein, ich bin hübscher. Und vor \n"
"allem nicht so klein..."
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nein, nein!\n"
"Die Ohren sind etwas zu klein!\n"
"Sie sollten eher so aussehen!"
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hast Du denn keine Angst, des \n"
"Nachts hier herumzulaufen? Noch \n"
"dazu mit einer Maske wie dieser?"
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du scheinst ja ein richtiger \n"
"Maskensammler zu sein!"
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich erinnere mich, irgendwo einen\n"
"Stein gesehen zu haben, der \n"
"ähnlich aussah..."
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beeil Dich, " NAME "!\n"
"Der Teufelsturm kann jede \n"
"Sekunde einstürzen!"
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Achtung! Von überall her stürzen \n"
"Trümmer herab!"
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "!\n"
"Hilf mir!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"Der Ausgang ist hier drüben!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hab Dank, " NAME ".\n"
"Schnell! Laß uns fliehen!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du brauchst offenbar\n"
"noch etwas Training!" BOX_BREAK "Übe fleißig und komme wieder!" EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fast!" BOX_BREAK "Nun gut...\n"
"Du darfst es noch einmal \n"
"versuchen! Umsonst! \n"
"Diesmal mußt Du es schaffen!" EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ich bin begeistert!\n"
"Klasse!\n"
"Göttlich!" BOX_BREAK "Hier, nimm dieses einzigartige\n"
"Präsent an Dich!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh-oh, " COLOR(RED) "die Zeit" COLOR(LIGHTBLUE) " ist abgelaufen!" COLOR(RED) "\n"
COLOR(LIGHTBLUE) "Das Ding, das Du ausliefern \n"
"solltest, ist verdorben! \n"
"Versuch es erneut!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Man erzählt sich, es sei\n"
TIME " Uhr!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Die Wache in Kakariko schickt \n"
"Dich?! Nun, dann werde ich Dir \n"
"einen guten Preis machen!"
)

