DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Oeuf de \n"
"Poche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Une Cocotte apparaîtra\n"
"demain matin. Allez la rendre\n"
"une fois utilisée."
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "Vous échangez la Cocotte de \n"
"Poche contre le " COLOR(RED) "P'tit Poulet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Contrairement aux Cocottes, \n"
"P'tit Poulet chante très rarement."
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Vous recevez un " COLOR(RED) "Champignon \n"
"suspect" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Apportez-le vite à \n"
"l'apothicaire de Cocorico!"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "Vous recevez une " COLOR(RED) " Mixture \n"
"suspecte" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Elle peut toujours\n"
"vous être utile... Rendez-vous\n"
"vite aux Bois Perdus!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "Vous échangez la Mixture \n"
"contre la " COLOR(RED) "Scie du chasseur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Le type bizarre l'a sûrement\n"
"laissée tomber."
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombes   20 Unités   80 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "Vous recevez le\n"
COLOR(RED) "Sac de graines Mojo" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Ce sac contient jusqu'à " COLOR(YELLOW) "40" COLOR(DEFAULT) "\n"
"munitions pour le lance-pierre."
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "Vous échangez la Scie \n"
"contre l'" COLOR(RED) "Epée brisée de Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rendez visite à Biggoron et il \n"
"vous la réparera!"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "Vous remettez l'Epée brisée \n"
"de Goron et vous recevez une\n"
COLOR(RED) "Ordonnance" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Allez vite voir le Roi Zora!"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "L'Epée de Biggoron..." QUICKTEXT_DISABLE "\n"
"Vous recevez un " COLOR(RED) "Certificat" COLOR(DEFAULT) "!\n"
"Une fois prête, sa lame tran-\n"
"chera du monstre en rondelles!"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Vous échangez la Lame \n"
"des Géants contre l'" COLOR(RED) "Epée de \n"
"Biggoron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " \n"
"Cette lame est indestructible!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Vous échangez le Certificat \n"
"contre l'" COLOR(RED) "Epée de Biggoron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette lame est indestructible!"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "Vous échangez l'ordonnance \n"
"contre le " COLOR(RED) "Crapaud-qui-louche" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Apportez-le vite au Lac Hylia\n"
"avant qu'il ne soit trop tard!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "Vous échangez le crapaud\n"
"contre les " COLOR(RED) "Super Gouttes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vite! Apportez-les à Biggoron \n"
"avant qu'elles ne tournent!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x47")  COLOR(RED) "GAGNE!!" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"de Mort" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"et vous serez beau comme un \n"
"monstre!"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"d'Effroi" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"pour terrifier certaines \n"
"personnes!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "Vous empruntez le " COLOR(RED) "Masque du \n"
"Renard" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et \n"
"devenez le type le plus cool \n"
"du moooonde!"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "Vous empruntez le " COLOR(RED) "Masque du \n"
"Lapin" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et \n"
"devenez aussi mignon qu'un \n"
"lapinou d'amour!"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"de Goron" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"pour avoir une grosse tête."
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"de Zora" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"pour devenir un vrai Zora!"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"de Gerudo" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"pour ressembler à... une fille?"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "Vous empruntez un " COLOR(RED) "Masque \n"
"de Vérité" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Portez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"et montrez-le à tout le monde!"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Découvrez l'attraction des \n"
"amateurs d'explosions:" BOX_BREAK SHIFT("\x11")  COLOR(RED) "Le célèbre Bowling Teigneux!" COLOR(DEFAULT)  BOX_BREAK "Tu veux savoir ce qu'on y gagne?\n"
"C'est un " TEXT_SPEED("\x03") "secret." TEXT_SPEED("\x00") "\n"
"Paie d'abord et je parlerai ensuite,\n"
"p'tite tête..." BOX_BREAK "C'est " COLOR(RED) "30 Rubis" COLOR(DEFAULT) " la partie.\n"
"Tu veux jouer?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "OKAY!!" QUICKTEXT_DISABLE  BOX_BREAK "Vise le trou du centre et laisse \n"
"partir le missile!\n"
"Tu as 10 essais. Prêt..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "C'EST PARTI!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu rejouer?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, j'ai failli oublier!\n"
"Voilà ce que tu peux gagner!" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombes   (20 unités)   80 Rubis\n"
COLOR(DEFAULT) "Allumez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et appuyez sur \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour la lancer. Un sac est \n"
"indispensable pour en acheter." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombes   (30 unités)   120 Rubis\n"
COLOR(DEFAULT) "Allumez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et appuyez sur \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour la lancer. Un sac est \n"
"indispensable pour en acheter." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombes   30 unités   120 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tout le monde est guéri!\n"
"C'est formidable!"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sauve mes frères, je t'en prie!"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La malédiction est brisée!\n"
"Merci infiniment!\n"
"Voici une récompense bien\n"
"méritée!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beuaaaaark! Je suis maudit!!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les araignées... Plus jamais!"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as détruit " COLOR(RED)  TOKENS " " COLOR(DEFAULT) "araignées de la \n"
"malédiction. Mes enfants sont \n"
"sains et saufs." BOX_BREAK "Mes enfants t'ont-ils tous donné\n"
"une récompense?" BOX_BREAK "Cherche bien les araignées surtout\n"
"de nuit... Extermine-les et \n"
"tu deviendras " COLOR(RED) "très riche!" COLOR(DEFAULT)  BOX_BREAK "Et souviens-toi: les araignées \n"
"adorent la terre fraîchement \n"
"retournée!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La malédiction des araignées nous\n"
"a tous transformés mais..." TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La malédiction des araignées nous\n"
"a tous transformés." BOX_BREAK "Si toutes les " COLOR(RED) "Araignées de la \n"
"Malédiction " COLOR(DEFAULT) "sont détruites,\n"
"nous serons sauvés!" BOX_BREAK "Pour chaque Araignée de la \n"
"Malédiction tuée un symbole \n"
"apparaîtra. Prouve ta valeur en\n"
"récupérant les symboles." BOX_BREAK ITEM_ICON("\x71") "Le nombre affiché près de cette\n"
COLOR(YELLOW) "icône" COLOR(DEFAULT) " sur l'écran du " COLOR(LIGHTBLUE) "Statut " COLOR(DEFAULT) "indique \n"
"combien d'Araignées de la \n"
"Malédiction furent détruites." BOX_BREAK ITEM_ICON("\x71") "Lorsque cette " COLOR(YELLOW) "icône" COLOR(DEFAULT) " est affichée\n"
"près du nom d'un lieu sur l'écran\n"
"de la " COLOR(RED) "Carte" COLOR(DEFAULT) ", toutes les araignées \n"
"ont été éliminées." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Brise la malédiction et tu seras \n"
"très riche!"
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "En détruisant " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Araignées de la\n"
"Malédiction tu as pu me sauver." BOX_BREAK UNSKIPPABLE "Merci mille fois! Reçois donc ceci\n"
"en gage de ma gratitude!" EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci d'avoir sauvé mes enfants." BOX_BREAK "Quoi? Moi? No Problemo.\n"
"Je suis en pleine forme!" BOX_BREAK "Tu as déjà détruit " COLOR(RED)  TOKENS " " COLOR(DEFAULT) "Araignées" COLOR(RED) "\n"
COLOR(DEFAULT) "de la Malédiction...\n"
"Ne t'inquiète surtout pas pour moi!"
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Missiles   20 Unités   180 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu tenter ta chance?\n"
"C'est " COLOR(RED) "20 Rubis " COLOR(DEFAULT) "la partie.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Pas question" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mais... Où est ton arc?" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Très bien. Personne ne t'oblige à \n"
"jouer, tu sais." EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "OKAY!!" QUICKTEXT_DISABLE "\n"
"Ce jeu n'est pas pour les gamins!\n"
"Le célèbre " COLOR(RED) "Jeu d'adresse " COLOR(DEFAULT) "d'Hyrule!" BOX_BREAK "Vise bien et dégomme ce qui \n"
"apparaît! Pourras-tu toucher\n"
COLOR(RED) "dix cibles" COLOR(DEFAULT) "? Tu as " COLOR(RED) "quinze " COLOR(DEFAULT) "essais!" BOX_BREAK "Utilise ton arme avec " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". \n"
"Es-tu prêt?\n"
"Fais-moi un sans faute!\n"
"Bonne chance!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On dirait de la terre fraîchement\n"
"retournée."
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(RED) "Lance-Pierre\n"
"des Fées" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-le à " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"ou" COLOR(YELLOW) " [C-Right] " COLOR(DEFAULT) "dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour le \n"
"brandir. Maintenez " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "et \n"
"visez avec le " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Relâchez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"pour tirer une " COLOR(RED) "Graine Mojo" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Si vous désirez tirer très \n"
"vite, après avoir appuyé sur \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", maintenez " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "plus longtemps\n"
"pour préparer une graine."
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "Vous trouvez l'" COLOR(RED) "Arc des Fées" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x03") "Appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour le \n"
"brandir. Maintenez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et \n"
"visez avec le " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "." COLOR(YELLOW) " " COLOR(DEFAULT) "Relâchez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"pour décocher une " COLOR(RED) "flèche" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Vous obtenez des " COLOR(RED) "Bombes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-les en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x02") "Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour brandir puis \n"
"poser une bombe. Appuyez sur\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "en vous déplaçant pour la \n"
"jeter. Faites tout sauter!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "Vous obtenez des " COLOR(RED) "Missiles" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-les en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x09") " Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour brandir puis \n"
"poser un missile. Ce nouveau \n"
"type de bombe peut même \n"
"grimper aux murs. A l'attaque!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(RED) "Noix Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-la en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x01") "Utilisez " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour en lancer \n"
"une! Vous pourrez ainsi \n"
"aveugler vos ennemis!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(RED) "Boomerang" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0E") "Appuyez sur " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour \n"
"attaquer vos ennemis à \n"
"distance!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(RED) "Grappin" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette chaîne montée sur \n"
"ressort peut s'accrocher à \n"
"certaines choses." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Vous pouvez l'utiliser pour \n"
"attirer un objet vers vous ou \n"
"pour vous tracter." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "Maintenez " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "puis visez à \n"
"l'aide du " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". \n"
"Faites feu en relâchant " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Bâton Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x00") "Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour donner de\n"
"grands coups!" BOX_BREAK ITEM_ICON("\x00") "Restez immobile et appuyez \n"
"sur " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pour ranger votre \n"
"bâton. Vous ne pouvez trans-\n"
"porter que 10 bâtons!"
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(RED) "Masse des \n"
"Titans" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Appuyez sur " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour \n"
"frapper comme un sourd ou \n"
"pour écraser quelque chose!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(RED) "Monocle de \n"
"Vérité" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour le \n"
"porter! Certains éléments sont\n"
"dissimulés un peu partout!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0F") "Assurez-vous de l'utiliser en\n"
"dehors du puits. Porter le \n"
"monocle gaspillera de la magie.\n"
"Appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour l'ôter."
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Vous trouvez l' " COLOR(RED) "Ocarina du \n"
"Temps" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ce trésor de la Famille\n"
"Royale vous est confié par la \n"
"Princesse Zelda..."
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Vous invoquez le Vent de Farore!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Retourner au téléporteur\n"
"Dissiper le téléporteur\n"
"Quitter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(RED) "Médaillon du \n"
"Feu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Darunia se révèle être un\n"
"des Sages et vous confie son \n"
"pouvoir!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(BLUE) "Médaillon de \n"
"l'Eau" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ruto se révèle être \n"
"une des Sages et vous confie \n"
"son pouvoir!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(ADJUSTABLE) "Médaillon de \n"
"la Forêt" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Saria se révèle être \n"
"une des Sages et vous confie \n"
"son pouvoir!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(YELLOW) "Médaillon de\n"
"l'Esprit" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Nabooru se révèle \n"
"être une des Sages et vous \n"
"confie son pouvoir!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "Vous recevez le" COLOR(LIGHTBLUE) " Médaillon de \n"
"la Lumière" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Rauru le Sage \n"
"vous confie son pouvoir!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(PURPLE) "Médaillon de \n"
"l'Ombre" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Impa se révèle être \n"
"une des Sages et vous confie \n"
"son pouvoir!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(RED) "Bouteille \n"
"Vide" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Après avoir rempli cette\n"
"bouteille, assignez-la à " COLOR(YELLOW) "[C] \n"
COLOR(DEFAULT) "pour utiliser son contenu."
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(RED) "Potion \n"
"Rouge" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " \n"
"ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x15") "Buvez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour \n"
"restaurer votre énergie. \n"
"Cette potion remplit l'une de \n"
"vos bouteilles."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(ADJUSTABLE) "Potion \n"
"Verte" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " \n"
"ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x16") "Buvez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour \n"
"restaurer votre magie. Cette \n"
"potion remplit l'une de vos \n"
"bouteilles."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "Vous recevez une " COLOR(BLUE) "Potion \n"
"Bleue" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Buvez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour \n"
"restaurer magie et énergie."
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "Vous attrapez une " COLOR(RED) "Fée" COLOR(DEFAULT) " dans \n"
"une bouteille!" QUICKTEXT_DISABLE " Assignez-la en \n"
"appuyant sur " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " \n"
"dans l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x18") "Cette petite fée est bien \n"
"utile! Elle peut automatique-\n"
"ment restaurer votre énergie \n"
"dans un moment critique." BOX_BREAK ITEM_ICON("\x18") "En revanche, après l'avoir \n"
"assignée à " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", vous pouvez \n"
"solliciter son aide à tout\n"
"moment."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Poisson" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Utilisez-le avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " au bon \n"
"endroit pour qu'il se passe \n"
"quelque chose." BOX_BREAK ITEM_ICON("\x19") "Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'Inventaire\n"
"et utilisez ce " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour vous en\n"
"servir."
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "Vous obtenez des " COLOR(RED) "Haricots \n"
"Magiques" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Plantez-les au bon \n"
"endroit en appuyant sur " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x10") "Assignez-les en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire\n"
COLOR(DEFAULT) "puis utilisez ce " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour en\n"
"planter."
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bon... Es-tu prêt cette fois-ci?" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "C'EST PARTI" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "Vous recevez l'" COLOR(RED) "Ocarina des \n"
"Fées" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez ce cadeau de\n"
"Saria aux boutons " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " puis\n"
"appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire\n"
COLOR(DEFAULT) "puis utilisez ce " COLOR(YELLOW) "[C]  " COLOR(DEFAULT) "pour en\n"
"jouer." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "Les boutons " COLOR(BLUE) "[A]" COLOR(DEFAULT) " et " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"correspondent à différentes \n"
"notes. Appuyez sur " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " pour \n"
"arrêter de jouer."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Vous obtenez la " COLOR(ADJUSTABLE) "Lame des \n"
"Géants" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Appuyez sur " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "pour \n"
"attaquer! Vous ne pouvez \n"
"plus porter de " COLOR(LIGHTBLUE) "bouclier" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(LIGHTBLUE) "Bouclier \n"
"Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Sélectionnez ce bouclier\n"
"à l'" COLOR(BLUE) "écran de l'Equipement" COLOR(DEFAULT) ".\n"
"Appuyez sur " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pour l'équiper." BOX_BREAK ITEM_ICON("\x3E") "Appuyez sur " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " pour vous \n"
"accroupir et vous protéger.\n"
"Appuyez sur " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " en maintenant\n"
COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "pour en plus vous déplacer."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(LIGHTBLUE) "Bouclier \n"
"Hylien" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Sélectionnez-le à \n"
"l'" COLOR(BLUE) "écran de l'Equipement" COLOR(DEFAULT) ", puis \n"
"appuyez sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour l'équiper."
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(LIGHTBLUE) "Bouclier \n"
"Miroir" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ce bouclier peut \n"
"réfléchir lumière et énergie. \n"
"Appuyez sur " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "pour l'utiliser."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "Vous trouvez le " COLOR(RED) "Super \n"
"Grappin" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ce nouveau modèle \n"
"de grappin peut s'étendre " COLOR(RED) "deux\n"
"fois " COLOR(DEFAULT) "plus loin!"
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(RED) "Tunique \n"
"Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " L'étoffe de cet habit \n"
"pour adulte est à l'épreuve du\n"
"feu. Chaud, moi? J'crois pas!"
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(BLUE) "Tunique\n"
"Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Cet habit pour adulte \n"
"vous permettra de respirer \n"
"sous l'eau."
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous trouvez une " COLOR(ADJUSTABLE) "Bouteille de \n"
"Magie" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Votre Magie est restaurée!"
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "Vous trouvez les \n"
COLOR(RED) "Bottes de plomb" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Si lourdes, nul ne court.\n"
"Si lourdes, nul ne flotte."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "Vous trouvez les " COLOR(RED) "Bottes des\n"
"airs" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ces bottes ailées vous \n"
"permettront de léviter au-\n"
"dessus du sol. " BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x46") "Vous pouvez même utiliser \n"
"ces bottes pour marcher dans \n"
"le vide pendant quelques \n"
"instants."
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous trouvez un " COLOR(PURPLE) "Coeur de Vie" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Votre énergie est restaurée!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Vous changez votre carquois \n"
"pour un " COLOR(RED) "Grand Carquois" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "40 " COLOR(DEFAULT) "flèches!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Vous changez votre carquois \n"
"pour un " COLOR(RED) "Enorme Carquois" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "50 " COLOR(DEFAULT) "flèches!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "Vous trouvez un " COLOR(RED) "Sac de \n"
"Bombes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Fait à base d'esto-\n"
"macs de Dodongos, ce sac \n"
"contient plusieurs bombes!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Vous trouvez " COLOR(RED) "20 Bombes" COLOR(DEFAULT) " à \n"
"l'intérieur!" QUICKTEXT_DISABLE " Posez des bombes \n"
"avec " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "et faites tout sauter!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Gros Sac de \n"
"Bombes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous pouvez \n"
"désormais transporter jusqu'à \n"
COLOR(YELLOW) "30" COLOR(DEFAULT) " bombes!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Enorme Sac \n"
"de Bombes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous pouvez \n"
"désormais transporter jusqu'à \n"
COLOR(YELLOW) "40" COLOR(DEFAULT) " bombes!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Vous trouvez les " COLOR(BLUE) "Gantelets \n"
"d'argent" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " En les portant vous \n"
"pourriez soulever d'énormes \n"
"objets avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x51") "Mais ces gantelets sont trop \n"
"grands pour vos petites \n"
"menottes et vous avez promis à\n"
COLOR(RED) "Nabooru" COLOR(DEFAULT) " de les lui rapporter..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "Vous trouvez les " COLOR(BLUE) "Gantelets \n"
"d'or" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Une puissance démesurée\n"
"vous envahit! Utilisez " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pour\n"
"soulever d'énormes objets!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE "Vous enfermez une " COLOR(LIGHTBLUE) "Flamme \n"
"Bleue " COLOR(DEFAULT) "dans une bouteille!" QUICKTEXT_DISABLE "\n"
"Utilisez cette flamme magique \n"
"avec " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "Vous recevez la " COLOR(BLUE) "Grande \n"
"Bourse" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Elle vous permet de\n"
"transporter jusqu'à " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rubis" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "Vous recevez la " COLOR(BLUE) "Bourse de \n"
"Géant" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Elle peut contenir\n"
"jusqu'à " COLOR(YELLOW) "500" COLOR(DEFAULT) " " COLOR(YELLOW) "Rubis" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Vous trouvez une " COLOR(RED) "Petite Clé" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette clé permet d'ouvrir une \n"
"des portes verrouillées de ce\n"
"donjon."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Missile  (20 unités)  180 Rubis\n"
COLOR(DEFAULT) "Profilée comme une souris\n"
"mécanique, cette arme est \n"
"destructrice!!!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Potion Rouge   40 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Potion Rouge  50 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Potion Rouge  40 Rubis\n"
COLOR(DEFAULT) "Utilisable qu'une seule fois, elle\n"
"restaurera votre énergie." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Potion Rouge   50 Rubis\n"
COLOR(DEFAULT) "Utilisable qu'une seule fois, elle\n"
"restaurera votre énergie." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(RED) "Carte du \n"
"Donjon" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Appuyez sur " COLOR(RED) "START \n"
COLOR(DEFAULT) "pour accéder à l'écran de la\n"
COLOR(RED) "Carte" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x76") "Les " COLOR(BLUE) "pièces en bleu " COLOR(DEFAULT) "sont \n"
"celles déjà visitées. Votre \n"
"position actuelle est une\n"
COLOR(LIGHTBLUE) "pièce clignotante" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x76") "Déplacez " COLOR(LIGHTBLUE) "[Control-Pad] en haut et en \n"
"bas " COLOR(DEFAULT) "pour passer en revue un \n"
"étage précis."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(RED) "Boussole" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vous pouvez désormais \n"
"découvrir l'emplacement de \n"
"nombreux objets cachés!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "Vous obtenez la " COLOR(RED) "Pierre de \n"
"Souffrance" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Avec un " COLOR(LIGHTBLUE) "Kit \n"
"Vibration" COLOR(DEFAULT) ", vous pourrez sentir \n"
"la présence d'objets cachés."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "Vous recevez la " COLOR(RED) "Lettre de \n"
"Zelda" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "et \n"
"montrez-la avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bienvenue! \n"
"Je peux vous renseigner?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "J'veux acheter!\n"
"Je jette un oeil..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Désirez-vous autre chose?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui! J'en veux encore!\n"
"Non! J'en veux plus!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "Votre " COLOR(RED) "Sac de graines" COLOR(DEFAULT) " devient\n"
"plus gros!" QUICKTEXT_DISABLE " Vous pouvez \n"
"désormais transporter jusqu'à\n"
COLOR(YELLOW) "50" COLOR(RED) " " COLOR(DEFAULT) "munitions!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvre un coffre et...Surprise!\n"
"Si tu trouves une clé à l'intérieur,\n"
"tu pourras continuer à avancer.\n"
"Fais ensuite le bon choix!" BOX_BREAK "C'est " COLOR(RED) "10 Rubis " COLOR(DEFAULT) "la partie.\n"
"Tu veux tenter ta chance?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ouais\n"
"Heu... Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Génial! T'es joueur, toi!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous obtenez un " COLOR(ADJUSTABLE) "Rubis vert" COLOR(DEFAULT) "!\n"
"Vous gagnez " COLOR(ADJUSTABLE) "un Rubis" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(RED) "Flèche de \n"
"Feu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour \n"
"enchanter vos flèches! Tirez \n"
"et embrasez votre cible!"
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(BLUE) "Flèche de \n"
"Glace" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour \n"
"enchanter vos flèches! Tirez \n"
"et gelez votre cible." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0C") "Ce sort enchantera les flèches\n"
"du valeureux archer ayant\n"
"triomphé de l'entraînement\n"
"des Gerudos."
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "Vous obtenez la " COLOR(LIGHTBLUE) "Flèche de \n"
"Lumière" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Assignez-la à " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "et la clarté de la Justice\n"
"dissipera le Malin!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x32")  COLOR(ADJUSTABLE) "Menuet des bois" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x38")  COLOR(RED) "Boléro du feu" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2E") "Vous apprenez la \n"
SHIFT("\x2D")  COLOR(BLUE) "Sérénade de l'eau" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x28")  COLOR(YELLOW) "Requiem des esprits" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x28")  COLOR(PURPLE) "Nocturne de l'ombre" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x24")  COLOR(LIGHTBLUE) "Prélude de la lumière" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(RED) "Bracelet \n"
"Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous pouvez désormais\n"
"soulever les Choux-Péteurs. \n"
"Appuyez sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "Vous enfermez un " COLOR(RED) "Insecte \n"
COLOR(DEFAULT) "dans la bouteille!" QUICKTEXT_DISABLE "\n"
"Gardez-le ou libérez-le en \n"
"appuyant sur " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK "Cette petite bestiole adore se\n"
"cacher dans la terre!"
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "Vous recevez la " COLOR(RED) "Carte Gerudo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vous pouvez désormais entrer\n"
"dans le Gymnase des Gerudos."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombes  10 unités  50 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Flèches  50 unités  90 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Poisson   200 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Noix Mojo   5 unités   15 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "Vous recevez l'" COLOR(ADJUSTABLE) "Emeraude Kokiri" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette Pierre Ancestrale de la\n"
"forêt vous est confiée par le\n"
"vénérable Arbre Mojo."
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(RED) "Rubis Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette Pierre Ancestrale du \n"
"feu vous est confiée par les \n"
"Gorons!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "Vous recevez le" COLOR(BLUE) " Saphir Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cette Pierre Ancestrale de \n"
"l'eau vous est confiée par les \n"
"Zoras!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Passez en revue les articles en \n"
"déplaçant " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "à gauche ou à droite.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parler au marchand\n"
"Quitter" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "Merci beaucoup!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous n'avez pas assez d'argent!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous ne pouvez acheter ceci\n"
"maintenant." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Noix Mojo   10 unités  30 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bâton Mojo  1 unité   10 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bouclier Mojo   40 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Flèches   10 unités   20 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombes   5 unités   25 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Missiles  10 unités   100 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Vous ne pouvez utiliser une Ame\n"
"ici! Vendez-la à l'homme près du\n"
"pont-levis!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Potion rouge   30 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Potion verte  30 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "20" COLOR(DEFAULT) " " COLOR(RED) "Bâtons Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "30" COLOR(DEFAULT) " " COLOR(RED) "Bâtons Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bouclier Hylien   80 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Tunique Goron   200 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Tunique Zora   300 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Coeur de vie   10 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Désolé... Il vous faut une bouteille\n"
"vide pour acheter ceci." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "Vous attrapez un " COLOR(RED) "Esprit " COLOR(DEFAULT) "dans \n"
"une bouteille!" QUICKTEXT_DISABLE "\n"
"Il doit bien servir à quelque \n"
"chose!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "Vous obtenez le " COLOR(RED) "Lait de \n"
"Lon Lon" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ce lait est très \n"
"nourrissant! Buvez-le avec " COLOR(YELLOW) "[C] \n"
COLOR(DEFAULT) "pour restaurer votre énergie!" BOX_BREAK ITEM_ICON("\x1A") "Chaque dose restaurera " COLOR(RED) "cinq\n"
"coeurs" COLOR(DEFAULT) ". Une bouteille contient\n"
"deux doses." BOX_BREAK ITEM_ICON("\x1A") "Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire\n"
COLOR(DEFAULT) "puis appuyez sur ce bouton " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "pour boire."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "Vous obtenez une " COLOR(RED) "Bouteille \n"
"vide" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Enfermez-y quelque chose\n"
"et appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour \n"
"l'utiliser. Heu? Elle est pleine?"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "Vous recevez un " COLOR(RED) "Oeuf \n"
"curieux" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " On dirait que ça \n"
"bouge à l'intérieur! Assignez-le\n"
"à " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "et... Patience!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x21") "Assignez-le en appuyant sur \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " dans l'" COLOR(YELLOW) "Inventaire\n"
COLOR(DEFAULT) "puis appuyez sur ce bouton " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "pour l'utiliser."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Flèches   30 unités   60 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ma meilleure vente est le " COLOR(LIGHTBLUE) "Bouclier \n"
"Hylien" COLOR(DEFAULT) " mais il risque d'être trop\n"
"grand pour toi, mon p'tit." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Les temps sont durs... Et nous\n"
"avons dû fuir du château. Mais \n"
"j'espère vous avoir comme \n"
"client fidèle!!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x43") "Bienvenue!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bouclier Mojo   40 Rubis\n"
COLOR(DEFAULT) "Une fois équipé, appuyez sur " COLOR(LIGHTBLUE) "[R]\n"
COLOR(DEFAULT) "pour vous protéger. Prenez garde\n"
"à ce qu'il ne brûle pas!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Flèches   10 unités   20 Rubis\n"
COLOR(DEFAULT) "Il vous faut un arc pour avoir\n"
"le droit d'acheter des flèches." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bâton Mojo  1 unité  10 Rubis\n"
COLOR(DEFAULT) "Bien que fragile, cette longue\n"
"branche provenant de l'Arbre Mojo\n"
"peut vous servir d'arme." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Noix Mojo  10 unités  30 Rubis\n"
COLOR(DEFAULT) "Utilisez ces projectiles pour\n"
"paralyser vos ennemis." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombes   5 unités   25 Rubis\n"
COLOR(DEFAULT) "Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour allumer et lancer\n"
"une bombe. Un sac de bombes est\n"
"indispensable pour en acheter." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "Vous trouvez l'" COLOR(ADJUSTABLE) "Epée Kokiri" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Activez l'" COLOR(BLUE) "Ecran de l'Equipement" COLOR(DEFAULT) ",\n"
"sélectionnez-la puis équipez-la\n"
"avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x3B") "Cette lame est le trésor \n"
"secret de la tribu Kokiri. \n"
"N'hésitez pas à vous entraîner\n"
"avant de croiser le fer!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Potion Rouge   30 Rubis\n"
COLOR(DEFAULT) "Cette dose unique restaurera \n"
"votre énergie." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Potion Verte   30 Rubis\n"
COLOR(DEFAULT) "Cette dose unique restaurera\n"
"votre magie." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "30 " COLOR(RED) "Noix Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Vous pouvez désormais trans-\n"
"porter jusqu'à " COLOR(YELLOW) "40" COLOR(DEFAULT) " " COLOR(RED) "Noix Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bouclier Hylien   80 Rubis\n"
COLOR(DEFAULT) "Ce bouclier pour chevalier est si\n"
"résistant qu'il vous protégera\n"
"des attaques de feu!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Tunique Goron   200 Rubis\n"
COLOR(DEFAULT) "Créé par les Gorons, cet habit\n"
"pour adulte vous rend insensible \n"
"au feu." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Tunique Zora    300 Rubis\n"
COLOR(DEFAULT) "Créé par les Zoras, cet habit\n"
"pour adulte vous permet de \n"
"respirer sous les flots." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Coeur de vie   10 Rubis\n"
COLOR(DEFAULT) "Il restaurera une petite partie\n"
"de votre énergie." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(RED) "Feu de Din" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Appuyez sur " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour invoquer\n"
"une puissante aura de feu \n"
"destructrice."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE "Vous recevez le " COLOR(ADJUSTABLE) "Vent de \n"
"Farore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ce sortilège vous \n"
"permettra de vous téléporter \n"
"en utilisant " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "En invoquant ce sort, vous\n"
"pourrez créer puis vous \n"
"rendre à un " COLOR(ADJUSTABLE) "téléporteur" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "En utilisant la magie une \n"
"seconde fois, vous aurez le \n"
"choix entre vous téléporter ou\n"
"annuler le téléporteur."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "Vous recevez l'" COLOR(BLUE) "Amour de \n"
"Nayru" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Lancez ce sort avec \n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "pour invoquer une \n"
"puissante barrière protectrice."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Flèches  50 unités  90 Rubis\n"
COLOR(DEFAULT) "Il vous faut un arc pour avoir\n"
"le droit d'acheter des flèches." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombes  10 unités  50 Rubis\n"
COLOR(DEFAULT) "Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour allumer et lancer\n"
"une bombe. Un sac de bombes est\n"
"indispensable pour en acheter." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Noix Mojo  5 unités  15 Rubis\n"
COLOR(DEFAULT) "Utilisez avec " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "ces projectiles\n"
"pour paralyser vos ennemis." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Poisson   200 Rubis\n"
COLOR(DEFAULT) "Une prise de ce matin!\n"
"A conserver dans une bouteille." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Vous venez de détruire une\n"
COLOR(RED) "Skulltula d'or" COLOR(DEFAULT) "! Ce symbole prouve\n"
"votre haut fait!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Vous venez de détruire une\n"
COLOR(RED) "Skulltula d'or" COLOR(DEFAULT) "! Ce symbole prouve\n"
"votre haut fait!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Esprit de fée    50 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Esprit de fée   50 Rubis\n"
COLOR(DEFAULT) "Il vous faut une bouteille vide \n"
"pour la conserver. \n"
"Ne sortez pas sans elle!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Flamme bleue    300 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Flamme bleue   300 Rubis\n"
COLOR(DEFAULT) "Il vous faut une bouteille vide\n"
"pour la conserver. A utiliser dans\n"
"les conditions extrêmes!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Insecte en bouteille   50 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Insecte en bouteille    50 Rubis\n"
COLOR(DEFAULT) "Il vous faut une bouteille vide\n"
"pour le conserver. On dirait un\n"
"insecte ordinaire..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Missile  10 unités  100 Rubis\n"
COLOR(DEFAULT) "Profilée comme une souris\n"
"mécanique, cette arme est \n"
"destructrice!!!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Cet article est actuellement \n"
"indisponible." COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Allez, vieux! T'as plus l'âge\n"
"pour ce jeu!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x34") "Mmmm? Gueu--!" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x2D") "Qu... Comm.. Hein?" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3C") "UN CLIENT!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x1B") "zzzzz...(ronfle)...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Flèches   30 unités   60 Rubis\n"
COLOR(DEFAULT) "A utiliser avec un arc.\n"
"A décocher avec modération!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de \n"
"Coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Trouvez quatre \n"
"fragments pour gagner plus \n"
"d'énergie!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de \n"
"Coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous disposez de deux\n"
"fragments. Encore deux et \n"
"vous gagnerez plus d'énergie!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de \n"
"Coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous disposez de trois\n"
"fragments! Plus qu'un et votre\n"
"énergie sera plus importante!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de \n"
"Coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Un nouveau coeur \n"
"d'énergie est créé!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Coeur \n"
"d'Energie" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Votre maximum \n"
"d'énergie augmente d'un coeur!\n"
"Votre énergie est restaurée!"
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "Vous trouvez la " COLOR(RED) "Clé d'or" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vous pouvez désormais \n"
"accéder au repaire du Maître \n"
"des lieux."
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Non p'tite tête... T'as pas assez\n"
"d'argent!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x2B") "Parfait, ça marche!" QUICKTEXT_DISABLE "\n"
"Attends dehors le temps que je\n"
"prépare la partie suivante!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombes   5 unités   35 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombes   5 unités   35 Rubis\n"
COLOR(DEFAULT) "Utilisez " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour allumer et lancer\n"
"une bombe. Un sac de bombes est\n"
"indispensable pour en acheter." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous obtenez un " COLOR(BLUE) "Rubis Bleu" COLOR(DEFAULT) "!\n"
"Vous gagnez" COLOR(BLUE) " cinq Rubis" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "Vous recevez l'" COLOR(BLUE) "Ecaille \n"
"d'argent" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Nagez et utilisez \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Vous pouvez désormais \n"
"plonger plus profondément."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "Vous recevez l'" COLOR(BLUE) "Ecaille d'or" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nagez et appuyez sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". \n"
"Vous pouvez désormais plonger \n"
"encore plus profondément!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Ceci n'a pas l'air de servir à \n"
"grand chose dans le coin..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Impossible de l'ouvrir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x02") "Vous apprenez le " COLOR(ADJUSTABLE) "Chant de Saria" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x05") "Vous apprenez le " COLOR(RED) "Chant d'Epona" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x01") "Vous apprenez le " COLOR(YELLOW) "Chant du Soleil" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2E") "Vous apprenez la \n"
SHIFT("\x2D")  COLOR(BLUE) "Berceuse de Zelda" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Vous apprenez le " COLOR(LIGHTBLUE) "Chant du Temps" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "Vous apprenez le\n"
SHIFT("\x26")  COLOR(PURPLE) "Chant des Tempêtes" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bienvenue " NAME "!\n"
"Je suis la divine Fée de la Force!" BOX_BREAK UNSKIPPABLE "Je vais t'enseigner une nouvelle\n"
COLOR(ADJUSTABLE) "technique d'attaque" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Qu'il en soit ainsi!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bienvenue " NAME "!\n"
"Je suis la divine Fée de la \n"
"Sagesse!" BOX_BREAK UNSKIPPABLE "Je vais accroître ta " COLOR(ADJUSTABLE) "puissance" COLOR(DEFAULT) " \n"
COLOR(ADJUSTABLE) "magique" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Qu'il en soit ainsi!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bienvenue " NAME "!\n"
"Je suis la divine Fée du Courage!" BOX_BREAK UNSKIPPABLE "Je vais renforcer ton " COLOR(LIGHTBLUE) "endurance" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Qu'il en soit ainsi!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Si les batailles un jour t'épuisent,\n"
"j'apaiserai tes blessures!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bienvenue " NAME "!\n"
"Je vais apaiser tes souffrances." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE "Vous obtenez des " COLOR(RED) "Graines \n"
"Mojo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Ces petites graines \n"
"vous serviront de munitions \n"
"pour votre lance-pierre."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  UNSKIPPABLE "Vous maîtrisez la technique\n"
"secrète de l'" COLOR(RED) "Attaque Cyclone" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Chargez votre épée avec " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " puis\n"
"relâcher " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " pour créer une vague\n"
"tourbillonnante d'énergie!" BOX_BREAK UNSKIPPABLE "Pour créer un cyclone d'énergie\n"
"sans charger votre épée, faites un\n"
"tour complet avec" COLOR(LIGHTBLUE) " [Control-Pad] " COLOR(DEFAULT) "puis appuyez\n"
"sur " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Graines Mojo 30 unités 30 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Graines Mojo  30 unités  30 Rubis\n"
COLOR(DEFAULT) "Elles servent de munitions pour\n"
"votre lance-pierre." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Tu veux parler à Saria, c'est ça?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parler à Saria\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Ah bon? Tu veux me parler alors?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x3C")  NAME "...?\n"
SHIFT("\x0D") "C'est " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Peux-tu m'entendre?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Veux-tu encore parler à Saria?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Votre " COLOR(ADJUSTABLE) "puissance magique" COLOR(DEFAULT) " \n"
"a augmenté!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Votre " COLOR(LIGHTBLUE) "endurance" COLOR(DEFAULT) " a augmenté!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Vous obtenez " COLOR(YELLOW) "plusieurs flèches" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mais prends garde: en concentrant\n"
"ton attaque, le " COLOR(ADJUSTABLE) "niveau de magie\n"
COLOR(DEFAULT) "diminuera!" BOX_BREAK UNSKIPPABLE "Hé, mon garçon! Tu es un \n"
"messager de la Famille Royale, \n"
"n'est-ce pas?" BOX_BREAK UNSKIPPABLE "Si tu retournes au château,\n"
"va rendre visite à l'une de mes\n"
"amies vivant dans le coin." BOX_BREAK UNSKIPPABLE "Elle se fera une joie de te\n"
"donner un petit quelque chose!"
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Votre puissance magique a\n"
"augmenté! Vous disposerez à \n"
"présent d'une puissance magique\n"
COLOR(RED) "deux fois plus importante" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tes blessures seront désormais\n"
"réduites de " COLOR(RED) "moitié" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bienvenue " NAME "!\n"
"Je suis la Divine Fée des \n"
"enchantements!" BOX_BREAK UNSKIPPABLE "Je t'offre un " COLOR(RED) "sortilège" COLOR(DEFAULT) ".\n"
"Utilise-le avec soin."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Désolé, ce masque n'est pas \n"
"disponible pour l'instant." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Le " COLOR(RED) "Feu de Din" COLOR(DEFAULT) " consumera tes \n"
"ennemis et certains obstacles!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Souviens-toi, le " COLOR(ADJUSTABLE) "Vent de Farore " COLOR(DEFAULT) "ne\n"
"fonctionne que dans les donjons\n"
"possédant une carte."
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "L'" COLOR(BLUE) "Amour de Nayru" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "ne fonctionne \n"
"que pendant un court instant, \n"
"alors prends-en soin!"
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Si les batailles un jour t'épuisent,\n"
"j'apaiserai tes blessures!"
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Rubis rouge" COLOR(DEFAULT) "!\n"
"Vous gagnez " COLOR(RED) "vingt Rubis" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous obtenez un " COLOR(PURPLE) "Rubis pourpre" COLOR(DEFAULT) "!\n"
"Vous gagnez " COLOR(PURPLE) "cinquante Rubis" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Vous obtenez un " COLOR(YELLOW) "énorme Rubis" COLOR(DEFAULT) "!\n"
"Cette pierre vous rapporte\n"
COLOR(YELLOW) "deux cents Rubis" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Vous obtenez une" COLOR(RED) " Clé" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Utilisez cette clé pour accéder\n"
"à la salle suivante. Ouvrez un \n"
"coffre et... Surprise!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4D")  COLOR(LIGHTBLUE) "Perdu!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Vous ne trouvez qu'" COLOR(ADJUSTABLE) "un Rubis" COLOR(DEFAULT) ".\n"
"Dommage." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4D")  COLOR(LIGHTBLUE) "Perdu!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Vous trouvez " COLOR(BLUE) "cinq Rubis" COLOR(DEFAULT) ".\n"
"C'est peu." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4D")  COLOR(LIGHTBLUE) "Perdu!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Vous trouvez " COLOR(RED) "vingt Rubis" COLOR(DEFAULT) ".\n"
"Votre dernier choix fut une\n"
"erreur... C'est frustrant, hein?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4D")  COLOR(RED) "Gagné!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "Vous trouvez " COLOR(YELLOW) "cinquante Rubis" COLOR(DEFAULT) ".\n"
"Vous êtes troooop chanceux!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "Vous enfermez une" COLOR(RED) " Ame " COLOR(DEFAULT) "dans \n"
"une bouteille!" QUICKTEXT_DISABLE " Allez vite la \n"
"vendre au " COLOR(RED) "Marchand d'Ames" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x49")  COLOR(RED) "GAGNE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de\n"
"coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Trouvez quatre \n"
"fragments pour créer un \n"
"nouveau coeur de vie!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B")  COLOR(RED) "GAGNE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de\n"
"coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous disposez de deux\n"
"fragments. Encore deux et\n"
"vous gagnerez plus d'énergie!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B")  COLOR(RED) "GAGNE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de\n"
"coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Vous disposez de trois\n"
"fragments! Plus qu'un et votre\n"
"énergie sera plus importante!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B")  COLOR(RED) "GAGNE" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Vous obtenez un " COLOR(RED) "Quart de\n"
"coeur" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Un nouveau coeur\n"
"d'énergie est créé!"
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cherche-les bien à l'extérieur mais\n"
"également dans tous les donjons." BOX_BREAK "Bien entendu, rien ne t'oblige à\n"
"nous aider, tu sais..." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "C'est quoi, ça?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hé! Regarde, " NAME "!\n"
"Tu peux voir à travers cette\n"
COLOR(DEFAULT) "toile d'araignée " COLOR(LIGHTBLUE) "en utilisant " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Regarde ce mur! Les racines qui\n"
"le recouvrent le rendent praticable.\n"
"Tu dois pouvoir l'escalader,\n"
NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Place-toi devant une " COLOR(DEFAULT) "porte " COLOR(LIGHTBLUE) "et\n"
"ouvre-la avec " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Observe bien l'" COLOR(BLUE) "icône d'action" COLOR(LIGHTBLUE) ".\n"
"C'est l'" COLOR(BLUE) "icône bleue" COLOR(LIGHTBLUE) " située en haut\n"
"de l'écran!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Là! Il y a quelque chose qui pend!\n"
"On dirait une vieille " COLOR(DEFAULT) "échelle" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Dis donc...\n"
"Ce symbole n'apparaît-il pas\n"
"sur la " COLOR(DEFAULT) "Porte du Temps" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cette torche semble être éteinte\n"
"depuis peu..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "A partir d'ici nous allons emprunter\n"
"d'étroits passages! Si tu procèdes\n"
"prudemment, tu surprendras certai-\n"
"nement quelques monstres." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Utilise la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "pour toujours\n"
"regarder dans la bonne direction.\n"
"Axe-toi pour voir le fond d'un \n"
"couloir avant de bifurquer." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Une fois bien placé, maintiens " COLOR(DEFAULT) "[Z]\n"
COLOR(LIGHTBLUE) "pour faire un " COLOR(DEFAULT) "pas de côté" COLOR(LIGHTBLUE) ".\n"
"Ainsi tu ne seras jamais pris dans\n"
"une embuscade." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Approche-toi de ce " COLOR(DEFAULT) "bloc de pierre" COLOR(LIGHTBLUE) "\n"
"et saisis-le avec " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". En maintenant\n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", tu peux le pousser ou le tirer." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Tu peux grimper sur un " COLOR(DEFAULT) "bloc de\n"
"pierre " COLOR(LIGHTBLUE) "en maintenant " COLOR(DEFAULT) "[Control-Pad] " COLOR(LIGHTBLUE) "vers le \n"
COLOR(DEFAULT) "bloc" COLOR(LIGHTBLUE) " et en appuyant sur " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Observe bien l'" COLOR(BLUE) "icône d'action" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0109"
)

DEFINE_MESSAGE(0x010A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"010a"
)

DEFINE_MESSAGE(0x010B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"010b"
)

DEFINE_MESSAGE(0x010C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Une fois dans l'eau, tu pourras\n"
"plonger en maintenant" COLOR(BLUE) " [A]" COLOR(LIGHTBLUE) "!\n"
"Je parie que tu y trouveras \n"
"quelque chose!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x010D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"010d"
)

DEFINE_MESSAGE(0x010E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"010e"
)

DEFINE_MESSAGE(0x010F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"010f"
)

DEFINE_MESSAGE(0x0110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0110"
)

DEFINE_MESSAGE(0x0111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0111"
)

DEFINE_MESSAGE(0x0112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0112"
)

DEFINE_MESSAGE(0x0113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0113"
)

DEFINE_MESSAGE(0x0114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Woah! Mate-moi tous ces \n"
COLOR(DEFAULT) "Choux-Péteurs" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Crois-tu pouvoir tous les faire\n"
"exploser en même temps?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Prends garde aux nombreux\n"
COLOR(DEFAULT) "puits de lave" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Une fois enfoncé, cet interrupteur\n"
"fait monter cette " COLOR(DEFAULT) "plate-forme \n"
COLOR(LIGHTBLUE) "jusqu'au deuxième étage!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "On ne sait jamais ce qu'il y a au\n"
"détour de ces étroits couloirs...." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Utilise la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "pour bien axer\n"
"ton angle de vue. Pratique, non?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x011A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"011a"
)

DEFINE_MESSAGE(0x011B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"011b"
)

DEFINE_MESSAGE(0x011C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"011c"
)

DEFINE_MESSAGE(0x011D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"011d"
)

DEFINE_MESSAGE(0x011E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"011e"
)

DEFINE_MESSAGE(0x011F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Dis donc, " NAME "...\n"
"On peut savoir ce que tu mates?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0120"
)

DEFINE_MESSAGE(0x0121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0121"
)

DEFINE_MESSAGE(0x0122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0122"
)

DEFINE_MESSAGE(0x0123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0123"
)

DEFINE_MESSAGE(0x0124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Le Mal se lit sur le visage de \n"
"cette statue...\n"
"J'ai un peu la trouille!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "J'entends les esprits murmurer \n"
"dans cette pièce:" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE "\"Cherche l'oeil de vérité...\""
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "J'entends les esprits murmurer \n"
"dans cette pièce:" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "\"Le héros aux " COLOR(RED) "pieds ailés " COLOR(DEFAULT) "se \n"
"laissera porter par le vent.\n"
"Puisse-t-il être guidé sur la voie\n"
"secrète.\""
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ce mur...Il me parle...\n"
COLOR(DEFAULT) "\"Danger au-dessus...\""
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ce mur...Il me parle...\n"
COLOR(DEFAULT) "\"Danger en dessous...\""
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "L'eau qui coule de cette statue\n"
"inonde le sol." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"012c"
)

DEFINE_MESSAGE(0x012D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"012d"
)

DEFINE_MESSAGE(0x012E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"012e"
)

DEFINE_MESSAGE(0x012F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Prends garde, " NAME "!\n"
"Cette chose" COLOR(ADJUSTABLE) " verte et gluante" COLOR(LIGHTBLUE) " est\n"
"électrifiée!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Prends garde, " NAME "!\n"
"Cette chose " COLOR(RED) "rouge et visqueuse \n"
COLOR(LIGHTBLUE) "est électrifiée!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Prends garde, " NAME "!\n"
"Cette chose " COLOR(BLUE) "bleue et visqueuse\n"
COLOR(LIGHTBLUE) "est électrifiée!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cet " COLOR(DEFAULT) "interrupteur" COLOR(LIGHTBLUE) "...\n"
"Ta carrure de poids plume ne sera\n"
"pas suffisante pour l'activer, \n"
NAME "..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0134"
)

DEFINE_MESSAGE(0x0135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0135"
)

DEFINE_MESSAGE(0x0136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0136"
)

DEFINE_MESSAGE(0x0137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Depuis que tu as tranché le \n"
COLOR(RED) "tentacule rouge" COLOR(LIGHTBLUE) ", la chose " COLOR(RED) "rouge et \n"
"visqueuse " COLOR(LIGHTBLUE) "n'est plus là! Cela\n"
"fonctionnera-t-il avec les autres?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il y a un interrupteur\n"
"derrière ce mur!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il y a quelque chose sur cette\n"
"plate-forme, là-haut!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2B")  COLOR(LIGHTBLUE) "Qu... Comm... Hein?" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Regarde cette flopée de " COLOR(DEFAULT) "drapeaux" COLOR(LIGHTBLUE) "!\n"
"Sauras-tu distinguer les vrais des\n"
"faux?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Le très vénérable " COLOR(DEFAULT) "Arbre Mojo\n"
COLOR(LIGHTBLUE) "veut te parler! Suis-moi vite!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Courage! \n"
"Entrons dans l'Arbre Mojo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Le très vénérable Arbre Mojo \n"
"nous a demandé de rendre visite à \n"
"la Princesse du " COLOR(DEFAULT) "Château d'Hyrule" COLOR(LIGHTBLUE) "....\n"
"On devrait y aller, non?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "La fille du Ranch nous a demandé\n"
"de retrouver son " COLOR(DEFAULT) "père" COLOR(LIGHTBLUE) "... \n"
"Sais-tu où il se trouve?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Je me demande où la " COLOR(DEFAULT) "Princesse " COLOR(LIGHTBLUE) "se\n"
"cache dans cet immense château." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Que dirait " COLOR(DEFAULT) "Saria" COLOR(RED) " " COLOR(LIGHTBLUE) "en apprenant que\n"
"nous devons sauver Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Impa " COLOR(LIGHTBLUE) "nous a dit que la Pierre \n"
"Ancestrale du Feu est dissimulée\n"
"dans le " COLOR(DEFAULT) "Mont du Péril" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Entrons dans la Caverne Dodongo \n"
"en utilisant un " COLOR(DEFAULT) "Chou-Péteur" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Darunia affirme qu'une " COLOR(DEFAULT) "fée " COLOR(LIGHTBLUE) "vit au\n"
"sommet du Mont du Péril." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Je me demande si " COLOR(DEFAULT) "Saria " COLOR(LIGHTBLUE) "sait\n"
"quelque chose sur l'autre Pierre\n"
"Ancestrale..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "La " COLOR(DEFAULT) "Princesse Ruto " COLOR(LIGHTBLUE) "est sans doute\n"
"dans le ventre de Jabu-Jabu..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Tu as trouvé les trois Pierres\n"
"Ancestrales! Retournons au \n"
COLOR(DEFAULT) "Château d'Hyrule" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "N'était-ce pas Impa et Zelda sur \n"
"le cheval blanc? Je crois qu'elles \n"
"ont jeté quelque chose dans les \n"
COLOR(DEFAULT) "douves" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Et si nous allions faire un tour\n"
"dans le " COLOR(DEFAULT) "Temple du Temps" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Devrions-nous croire ce que Sheik\n"
"raconte et aller au " COLOR(DEFAULT) "Village\n"
"Cocorico" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Je me demande ce qu'il se passe\n"
"dans la forêt en ce moment... \n"
"Et que devient " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Ce nuage au sommet du \n"
COLOR(DEFAULT) "Mont du Péril " COLOR(LIGHTBLUE) "ne m'inspire pas\n"
"confiance..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Un étrange souffle glacé nous \n"
"vient du " COLOR(DEFAULT) "Fleuve Zora" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Tes " COLOR(DEFAULT) "Bottes de plomb " COLOR(LIGHTBLUE) "ont l'air de \n"
"peser une tonne! En les portant, \n"
"tu pourras sûrement marcher " COLOR(DEFAULT) "au \n"
"fond d'un lac" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Quelqu'un peut-il nous renseigner\n"
"sur les autres " COLOR(DEFAULT) "Sages" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Ce monstre! Il est sorti du " COLOR(DEFAULT) "puits\n"
"du village" COLOR(LIGHTBLUE) "! Allons l'examiner!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Je me demande bien qui a pu\n"
"construire le " COLOR(DEFAULT) "Temple de l'Esprit" COLOR(LIGHTBLUE) "...\n"
"Et pourquoi?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "N'as-tu jamais joué le " COLOR(PURPLE) "Nocturne\n"
"de l'Ombre" COLOR(LIGHTBLUE) " que Sheik t'a enseigné?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Le " COLOR(DEFAULT) "désert" COLOR(LIGHTBLUE) "... C'est là que Ganondorf\n"
"a vu le jour. Je suis sûre que \n"
"nous y trouverons quelque chose..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Enfile tes " COLOR(DEFAULT) "Gantelets d'argent " COLOR(LIGHTBLUE) "et \n"
"tente de bouger quelque chose de\n"
"très lourd!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Celui qui nous attend au Temple \n"
"du Temps...ne serait-ce pas..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Allons vite dans le Château" COLOR(DEFAULT) " " COLOR(LIGHTBLUE) "libérer\n"
"la Princesse Zelda des griffes de\n"
"l'ignoble Ganondorf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE)  NAME "...\n"
"Continue ta quête!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Pourquoi utilises-tu ton ocarina?\n"
"Je ne suis qu'à deux pas!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"La forêt est reliée à bien des \n"
"lieux! Si tu entends ma chanson, \n"
"l'une des entrées n'est pas loin!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Je suis si contente d'apprendre \n"
"que Darunia aime ma chanson!" BOX_BREAK "Je suis d'autant plus ravie que \n"
"cela t'a aidé dans ta quête!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cherches-tu les " COLOR(BLUE) "Pierres \n"
"Ancestrales" COLOR(DEFAULT) "? Il doit te manquer \n"
"celle de l'" COLOR(BLUE) "eau" COLOR(DEFAULT) ", n'est-ce pas?" BOX_BREAK "Le très vénérable Arbre Mojo m'a\n"
"dit un jour que le " COLOR(BLUE) "Roi Zora" COLOR(DEFAULT) "," COLOR(BLUE) " \n"
"souverain du Domaine Zora" COLOR(DEFAULT) ", garde\n"
"cette pierre..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cherches-tu les " COLOR(RED) "Pierres \n"
"Ancestrales" COLOR(DEFAULT) "?" COLOR(RED) " " COLOR(DEFAULT) "Il doit te manquer \n"
"celle du " COLOR(RED) "feu" COLOR(DEFAULT) ", n'est-ce pas?" BOX_BREAK "Le très vénérable Arbre Mojo m'a\n"
"dit un jour que " COLOR(RED) "Darunia le Goron \n"
COLOR(DEFAULT) "garde cette pierre..." EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME "...\n"
"J'ai une étrange intuition...\n"
"Je suis terrifiée..." BOX_BREAK "Le Château...\n"
"Il se passe quelque chose au \n"
"Château!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Tiens... Ton ocarina sonne\n"
"différemment... \n"
"T'es-tu beaucoup entraîné, \n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cherches-tu un temple?\n"
"Un bien étrange oiseau m'a dit un \n"
"jour..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "L'oeil qui voit dans les ténèbres\n"
"s'ouvrira dans la tempête." COLOR(DEFAULT) "\"\n"
"Ca te dit quelque chose?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Où es-tu, " NAME "?\n"
"Cherches-tu un temple?\n"
"Un bien étrange oiseau m'a dit un \n"
"jour..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Va jusqu'à la Déesse du Désert,\n"
"un ocarina dans la main." COLOR(DEFAULT) "\"\n"
"Ca te dit quelque chose?" EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"As-tu déjà trouvé tous les\n"
"temples?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Incroyable! Tu es en vie!\n"
"J'étais sûre que tu donnerais signe\n"
"de vie!" BOX_BREAK "Je suis dans le " COLOR(ADJUSTABLE) "Temple de la Forêt" COLOR(DEFAULT) "!\n"
"Les esprits des bois ont appellé \n"
"au secours et je m'y suis rendue..." BOX_BREAK "Mais de terribles monstres \n"
"pervertissent cet endroit...\n"
"A l'aide, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME "...\n"
"Je n'ai jamais voulu devenir le\n"
COLOR(ADJUSTABLE) "Sage de la Forêt" COLOR(DEFAULT) "..." BOX_BREAK "Mais j'trouve ça pas mal,\n"
"finalement." BOX_BREAK "Ainsi je peux t'aider à sauver\n"
"Hyrule, " NAME "!\n"
"J'en suis très heureuse!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Si les six " COLOR(RED) "Sages" COLOR(DEFAULT) " s'allient, nous \n"
"pourrons emprisonner Ganondorf,  \n"
"le seigneur du Malin, dans le\n"
"Saint Royaume." BOX_BREAK "Mais pour sceller parfaitement\n"
"cette prison, il nous faudra l'aide\n"
"du " COLOR(RED) "Septième Sage" COLOR(DEFAULT) "." BOX_BREAK "C'est certainement quelqu'un que\n"
"tu as déjà rencontré,\n"
NAME "..." BOX_BREAK "Dès maintenant, parcours passé et\n"
"futur pour éveiller les derniers\n"
"Sages!" BOX_BREAK "Tu es sur le bon chemin,\n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Nous, les Six Sages, te confions\n"
"nos pouvoirs!" BOX_BREAK "La fragile destinée d'Hyrule repose\n"
"sur ton noble courage!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "J'entends une voix..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Elle me dit:\n"
"\n"
COLOR(DEFAULT)  SHIFT("\x0D") "\"Amasse cinq Rubis d'argent...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ce mur... Il me parle!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Il dit:\n"
COLOR(DEFAULT) "\n"
SHIFT("\x0A") "Si tu veux un aller simple pour\n"
SHIFT("\x15") "l'enfer, approche pour voir!"
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ce " COLOR(DEFAULT) "bâteau " COLOR(LIGHTBLUE) "m'a l'air vieux... \n"
"Es-tu certain qu'il ne va pas \n"
"sombrer?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il y a une " COLOR(DEFAULT) "porte " COLOR(LIGHTBLUE) "de ce côté...  \n"
"Sais-tu comment traverser?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cette " COLOR(DEFAULT) "glace rouge" COLOR(LIGHTBLUE) "...\n"
"Bizarre, non?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cette " COLOR(DEFAULT) "flamme bleue" COLOR(LIGHTBLUE) "... Elle n'a pas\n"
"l'air naturel. Elle doit sûrement \n"
"servir à quelque chose..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Le " COLOR(DEFAULT) "feu de ces torches " COLOR(LIGHTBLUE) "s'est éteint.\n"
"Comme si les spectres l'avaient \n"
"consumé!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Regarde, " NAME "! \n"
"Une " COLOR(DEFAULT) "torche " COLOR(LIGHTBLUE) "s'est allumée quand\n"
"tu as vaincu un spectre!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Regarde!\n"
"Il y a des " COLOR(DEFAULT) "flèches " COLOR(LIGHTBLUE) "peintes sur le \n"
"sol!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ce " COLOR(DEFAULT) "couloir " COLOR(LIGHTBLUE) "est tordu!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Prends garde à l'" COLOR(DEFAULT) "ombre des \n"
"monstres " COLOR(LIGHTBLUE) "qui apparaissent au\n"
"plafond." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Il y a un " COLOR(DEFAULT) "coffre" COLOR(LIGHTBLUE) " ici." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cette " COLOR(DEFAULT) "torche" COLOR(LIGHTBLUE) " est identique à celle\n"
"de l'entrée du temple!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Si cette " COLOR(DEFAULT) "torche" COLOR(LIGHTBLUE) " est allumée...\n"
"Cela veut dire que..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cet " COLOR(DEFAULT) "interrupteur " COLOR(LIGHTBLUE) "est pris dans la \n"
"glace!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", attention!\n"
"Le plafond nous tombe dessus!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0199"
)

DEFINE_MESSAGE(0x019A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019a"
)

DEFINE_MESSAGE(0x019B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019b"
)

DEFINE_MESSAGE(0x019C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019c"
)

DEFINE_MESSAGE(0x019D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019d"
)

DEFINE_MESSAGE(0x019E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019e"
)

DEFINE_MESSAGE(0x019F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"019f"
)

DEFINE_MESSAGE(0x01A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a0"
)

DEFINE_MESSAGE(0x01A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a1"
)

DEFINE_MESSAGE(0x01A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a2"
)

DEFINE_MESSAGE(0x01A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", \n"
"j'entends " COLOR(DEFAULT) "des Gorons " COLOR(LIGHTBLUE) "juste en bas." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "D'ici on peut voir ce qu'il se passe\n"
"en bas... N'était-ce pas la salle où\n"
COLOR(DEFAULT) "Darunia " COLOR(LIGHTBLUE) "est apparu?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cette " COLOR(DEFAULT) "statue" COLOR(LIGHTBLUE) "... Ne l'aurions-nous\n"
"pas croisée autre part?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cet " COLOR(DEFAULT) "interrupteur " COLOR(LIGHTBLUE) "m'a l'air rouillé." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Prends garde!\n"
"Ne te fais pas engloutir par le\n"
"tourbillon!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01ac"
)

DEFINE_MESSAGE(0x01AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01ad"
)

DEFINE_MESSAGE(0x01AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01ae"
)

DEFINE_MESSAGE(0x01AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01af"
)

DEFINE_MESSAGE(0x01B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"01b0"
)

DEFINE_MESSAGE(0x01B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"01B1"
)

DEFINE_MESSAGE(0x0200, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x0E") "Bonjour! Je suis une porte \n"
SHIFT("\x46") "qui parle!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x19")  COLOR(LIGHTBLUE) "Etrange... Cette porte ne \n"
COLOR(DEFAULT)  SHIFT("\x41")  COLOR(LIGHTBLUE) "s'ouvre pas" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x19")  COLOR(LIGHTBLUE) "De lourdes " COLOR(DEFAULT) "barres d'acier \n"
SHIFT("\x0C")  COLOR(LIGHTBLUE) "verrouillent cette porte. Tu ne\n"
COLOR(DEFAULT)  SHIFT("\x16")  COLOR(LIGHTBLUE) "peux l'ouvrir de tes mains!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Tu as besoin d'une " COLOR(DEFAULT) "Clé" COLOR(LIGHTBLUE) " pour ouvrir\n"
COLOR(DEFAULT)  SHIFT("\x0B")  COLOR(LIGHTBLUE) "cette porte. Elle est fortement\n"
COLOR(DEFAULT)  SHIFT("\x43")  COLOR(LIGHTBLUE) "verrouillée." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0A")  COLOR(LIGHTBLUE) "Tu as besoin d'une " COLOR(DEFAULT) "Clé spéciale\n"
SHIFT("\x1E")  COLOR(LIGHTBLUE) "pour ouvrir cette porte." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Silence!" QUICKTEXT_DISABLE  BOX_BREAK "Il n'est que " TIME "!\n"
"Moi, " COLOR(RED) "Igor " COLOR(DEFAULT) "le fossoyeur, \n"
"j'suis au pieu!" BOX_BREAK "Dégage et va jouer avec les \n"
"spectres du jour!"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Il est " TIME ".\n"
"L'" COLOR(RED) "Excursion du fossoyeur" COLOR(DEFAULT) " est finie!" BOX_BREAK "Moi, " COLOR(RED) "Igor" COLOR(DEFAULT) ", j'suis au pieu!" BOX_BREAK "Dégage et va jouer avec les \n"
"spectres!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Foire aux Masques\n"
COLOR(DEFAULT) "Veuillez lire cette affiche avant \n"
"de faire appel à nos services." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "Fonctionnement de la Foire\n"
COLOR(DEFAULT) "Ici les masques ne sont pas à \n"
"vendre mais sont " COLOR(RED) "confiés" COLOR(DEFAULT) " à un \n"
"coursier gratuitement." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Vous vendez le masque emprunté\n"
"à votre convenance." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Vous apportez l'" COLOR(RED) "argent" COLOR(DEFAULT) " et l'on vous\n"
"confiera un nouveau masque." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Vous pouvez emprunter un masque \n"
"déjà vendu sans pouvoir le vendre \n"
"de nouveau." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Pourquoi ne pas essayer?\n"
SHIFT("\x34") "--Le propriétaire" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Temple de l'Ombre...\n"
"Ici sommeillent les légendes\n"
"sanglantes d'Hyrule, faites de haine\n"
"et de cupidité..." EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Reposent au fond des ténèbres \n"
"pièges vicieux, trappes sournoises,\n"
"et l'ombre qui masque le chemin..." EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Seul le gardien de l'" COLOR(RED) "oeil de vérité \n"
COLOR(DEFAULT) "pourra scruter le tréfonds obscur." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Une étrange substance nous bloque\n"
"l'entrée. Tu dois résoudre l'" COLOR(DEFAULT) "énigme" COLOR(LIGHTBLUE) " \n"
"de cette pièce pour passer." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Crâne géant de Dodongo...\n"
"Quand il voit rouge, un nouveau\n"
"chemin se découvre." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x2A")  COLOR(LIGHTBLUE) "Chasse aux trésors\n"
COLOR(DEFAULT)  SHIFT("\x21") "Fermée pour le moment\n"
SHIFT("\x2A") "Ouverture: ce soir!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x41")  COLOR(LIGHTBLUE) "Apothicaire\n"
COLOR(DEFAULT)  SHIFT("\x28") "Fermé jusqu'au matin"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x3C")  COLOR(LIGHTBLUE) "Jeu d'adresse\n"
COLOR(DEFAULT)  SHIFT("\x1B") "Ouvert seulement le jour"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x2D")  COLOR(LIGHTBLUE) "Foire aux Masques\n"
COLOR(DEFAULT)  SHIFT("\x37") "Nous recrutons\n"
SHIFT("\x1E") "Se renseigner la journée"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x51")  COLOR(LIGHTBLUE) "Bazar\n"
COLOR(DEFAULT)  SHIFT("\x1B") "Ouvert seulement le jour"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Apporte-moi la lumière!"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Seul un " COLOR(RED) "regard juste " COLOR(DEFAULT) "discernera\n"
"le guide fantomatique jusqu'au\n"
"Temple de l'Esprit." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Toi qui désires ouvrir le sentier\n"
"enfoui au fond du lac, entonne le\n"
COLOR(RED) "Chant de la Famille Royale" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Toi qui désires ouvrir la porte\n"
"des hauteurs célestes, entonne le\n"
COLOR(RED) "Chant de la Famille Royale" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Qui a la " COLOR(RED) "petite clé" COLOR(DEFAULT) " passera.\n"
"Qui ne l'a pas, s'en va!"
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si tu veux Nous demander \n"
"audience, fais-le de la plate-forme." EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Salut, " NAME "!" QUICKTEXT_DISABLE "\n"
"Regarde par là!" BOX_BREAK "Regarde-moi avec " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", et parle-moi\n"
"avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Au quatrième top; il sera:\n"
COLOR(RED)  TIME  COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Inonde de lumière les morts."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Celui qui viole la Tombe Royale\n"
"réveillera les " COLOR(RED) "bêtes de l'ombre" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hé, toi! P'tit gars!\n"
"Regarde par là! Dans la cellule!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mon gamin n'est pas là pour\n"
"l'instant...\n"
"Je crois qu'il traîne du côté du\n"
"cimetière..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mon gamin dort pour le moment.\n"
"Reviens demain matin pour jouer\n"
"avec lui!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Quand les premières lueurs de \n"
"l'aube se reflèteront sur le lac, \n"
"décoche vers l'astre du matin." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pour t'aventurer dans le futur,\n"
"rapporte le " COLOR(BLUE) "pouvoir de l'argent " COLOR(DEFAULT) "du \n"
"passé." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pour errer dans le passé, présente\n"
"ici un coeur pur d'enfant." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Cette porte est en réparation." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Quelque chose devait être fixé \n"
"sur ce socle..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "Pointe mon bec vers le\n"
SHIFT("\x34")  COLOR(RED) "crâne de vérité" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x14") "Une erreur te plongera dans\n"
SHIFT("\x25") "les abîmes infernales." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Ce n'est pas la bonne " COLOR(DEFAULT) "clé" COLOR(LIGHTBLUE) "...\n"
"Cette porte ne s'ouvre pas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(LIGHTBLUE) "Apothicaire\n"
COLOR(DEFAULT)  SHIFT("\x50") "Fermé" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x1B") "Je suis partie faire des \n"
SHIFT("\x3C") "expériences...\n"
SHIFT("\x2C") "Revenez plus tard!\n"
SHIFT("\x4B") "--Granny" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Qui va là? Quel sale môme!\n"
"Essayer de passer par derrière!" QUICKTEXT_DISABLE  BOX_BREAK TEXT_SPEED("\x02") "Vilain petit..." TEXT_SPEED("\x00") "\n"
"Je m'en vais te raconter une \n"
"petite histoire!" BOX_BREAK "Le chef des ouvriers a un fils...\n"
"Il passe ses nuits assis sous \n"
"l'arbre..." BOX_BREAK "Ne va pas dire au chef que je \n"
"t'en ai parlé!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Regarde ça!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Malon est au lit!\n"
"Je vais me coucher, moi aussi.\n"
"Reviens demain lorsqu'il fera jour!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Records de " NAME "!\n"
COLOR(DEFAULT) "Araignées écrabouillées: " TOKENS "\n"
"Plus gros poisson: " HIGHSCORE(HS_LARGEST_FISH) " livres" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Marathon: " HIGHSCORE(HS_MARATHON) "\n"
"Course à cheval: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Archerie montée: " HIGHSCORE(HS_HORSE_ARCHERY) " points" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Le blason de la Famille Royale\n"
SHIFT("\x24") "d'Hyrule est gravé ici." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x32") "Paix à leur âme\n"
SHIFT("\x0C") "Ici reposent éternellement les \n"
SHIFT("\x09") "fidèles serviteurs de la Famille \n"
SHIFT("\x36") "Royale d'Hyrule." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x09") "Les Sheikahs, protecteurs de la\n"
SHIFT("\x0A") "Famille Royale et fondateurs de\n"
SHIFT("\x07") "Cocorico, veillent sur le sommeil\n"
SHIFT("\x32") "éternel des âmes." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(BLUE) "Cascade Insomniaque\n"
COLOR(DEFAULT)  SHIFT("\x02") "Le flux de cette cascade obéit au\n"
SHIFT("\x05") "Roi d'Hyrule. Lorsque le Roi dort,\n"
SHIFT("\x28") "la cascade se meure." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Des crapauds vous toisent depuis\n"
"le fond des eaux..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vous foulez du pied un tapis \n"
"d'apparat...\n"
"C'est tout doux entre les orteils!"
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Passe maître des " COLOR(RED) "épreuves \n"
COLOR(DEFAULT) "suivantes et notre trésor secret \n"
"récompensera ta valeur!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Ouvre la voie jusqu'au trésor\n"
"secret en méritant les " COLOR(RED) "clés \n"
COLOR(DEFAULT) "dissimulées dans chaque salle!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Ecrase tes ennemis en un \n"
COLOR(RED) "temps record" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Amasse les " COLOR(RED) "gemmes sous-marines" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Traverse les flots en feu!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Révèle le secret de cette pièce!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Aveugle " COLOR(RED) "cette statue" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Celui aux " COLOR(RED) "doigts d'argent " COLOR(DEFAULT) "pourra\n"
"déplacer un bloc de géant!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Sans les bons objets, \n"
"la compréhension sera obscurcie \n"
"par d'innombrables mystères."
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Amasse les " COLOR(RED) "joyaux de platine" COLOR(DEFAULT) " et \n"
"évite pièges et dangers!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(LIGHTBLUE) "Etang" COLOR(DEFAULT) "\n"
SHIFT("\x03") "Les poissons mordent aujourd'hui!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4E")  COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Seul le détenteur de l'" COLOR(RED) "oeil de" COLOR(DEFAULT) "\n"
SHIFT("\x0A")  COLOR(RED) "vérité" COLOR(DEFAULT) " du Village Cocorico sera\n"
SHIFT("\x23") "porté par les Ombres." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(LIGHTBLUE) "Plaine d'Hyrule" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(LIGHTBLUE) "Bourg d'Hyrule" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(LIGHTBLUE) "Temple du Temps" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B")  COLOR(RED) "Impasse" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(PURPLE) "Village Cocorico\n"
COLOR(DEFAULT)  SHIFT("\x1F") "Première étape vers le \n"
SHIFT("\x36") "Chemin du Péril" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24")  COLOR(PURPLE) "Cimetière de Cocorico" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Sombre! Etroit! Effrayant!\n"
SHIFT("\x29")  COLOR(PURPLE) "Le puits du mystère" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "Mont du Péril\n"
COLOR(DEFAULT)  SHIFT("\x23") "Passage interdit sans \n"
SHIFT("\x2A") "autorisation royale!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(RED) "Chemin du Péril" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(YELLOW) "Caverne Dodongo\n"
COLOR(DEFAULT)  SHIFT("\x05") "Ne pas entrer sans autorisation!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29") "Contrée des Gorons\n"
SHIFT("\x3C")  COLOR(RED) "Village Goron" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(BLUE) "Fleuve Zora\n"
COLOR(DEFAULT)  SHIFT("\x0B") "Prenez garde aux remous et \n"
SHIFT("\x47") "courants." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "L'oeil de la vérité, enfoui sous le\n"
SHIFT("\x14") "Village Cocorico, procurera \n"
SHIFT("\x1B") "l'alliance des ombres à son\n"
SHIFT("\x46") "détenteur." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(BLUE) "Domaine Zora" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(BLUE) "Fontaine Zora\n"
COLOR(DEFAULT)  SHIFT("\x12") "Ne pas déranger le Seigneur\n"
SHIFT("\x3C") "Jabu-Jabu! \n"
SHIFT("\x25") "--Zora le XVIème, Roi" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F")  COLOR(PURPLE) "Aire d'Entraînement Sylvestre" COLOR(RED) "\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Prière de ne pas trancher les\n"
SHIFT("\x0F") "pancartes comme un barbare..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "A ceux assez fous pour se \n"
SHIFT("\x1E") "risquer dans le désert: \n"
SHIFT("\x25") "Passez donc me voir!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(YELLOW) "Marchand de Tapis" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "Droit devant:\n"
SHIFT("\x1A") "La " COLOR(ADJUSTABLE) "Clairière du Vénérable\n"
COLOR(DEFAULT)  SHIFT("\x41")  COLOR(ADJUSTABLE) "Arbre Mojo" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(ADJUSTABLE) "Temple de la Forêt" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(ADJUSTABLE) "Les Bois Perdus" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(YELLOW) "Lon Lon Ranch\n"
COLOR(DEFAULT)  SHIFT("\x10") "Propriétaires: Talon et Malon." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x43")  COLOR(YELLOW) "Ranch Ingo\n"
COLOR(DEFAULT)  SHIFT("\x16") "Propriétaire: le Grand Ingo." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47")  COLOR(BLUE) "Lac Hylia" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(BLUE) "Laboratoire du Lac\n"
COLOR(DEFAULT)  SHIFT("\x14") "Nous tentons de percer les\n"
SHIFT("\x24") "secrets du Lac Hylia!\n"
SHIFT("\x34") "--Le Scientifique" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Vallée Gerudo" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(YELLOW) "Archerie Montée" COLOR(DEFAULT) "\n"
SHIFT("\x0C") "Bienvenue aux habiles archers!\n"
SHIFT("\x15") "Record actuel: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " Points" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(YELLOW) "Gymnase Gerudo\n"
COLOR(DEFAULT)  SHIFT("\x0D") "Seuls les membres actifs sont\n"
SHIFT("\x46") "autorisés!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Désert Hanté" COLOR(DEFAULT) "\n"
SHIFT("\x07") "Poursuis un mirage et les sables\n"
SHIFT("\x07") "t'engloutiront. Seul un chemin te\n"
SHIFT("\x32") "mènera au salut!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(YELLOW) "Temple de l'Esprit" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(ADJUSTABLE) "Boutique Kokiri\n"
COLOR(DEFAULT)  SHIFT("\x23") "Fournisseur officiel du\n"
SHIFT("\x32") "peuple sylvestre!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17") "Cabane de " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19")  COLOR(ADJUSTABLE) "Un Kokiri ne quitte jamais\n"
COLOR(DEFAULT)  SHIFT("\x49")  COLOR(ADJUSTABLE) "la Forêt." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Longez la falaise pour accéder au\n"
COLOR(RED) "Village Goron" COLOR(DEFAULT) ", demeure des Gorons." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Merveille de la nature:\n"
SHIFT("\x37") "Le " COLOR(RED) "Chou-Péteur" COLOR(DEFAULT) "\n"
SHIFT("\x16") "Danger! Ne pas déraciner!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x34")  COLOR(RED) "Sommet du Péril\n"
COLOR(DEFAULT)  SHIFT("\x2F") "Entrée du cratère\n"
SHIFT("\x04") "Attention aux vagues de chaleur!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12")  COLOR(BLUE) "Salle d'Audience du Roi Zora\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Pour entendre les proclamations\n"
SHIFT("\x19") "royales, tenez-vous sur la\n"
SHIFT("\x25") "plate-forme et parlez." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Arrête ma course folle et je\n"
"t'offrirai (peut-être) quelque chose.\n"
SHIFT("\x34") "-- " COLOR(RED) "Le Goron Fou" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Un oeil de vérité révèlera le\n"
SHIFT("\x06") "bouclier de pierre, seule défense\n"
SHIFT("\x1C") "contre la nuée de lames." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Seuls ceux au " COLOR(RED) "pied léger " COLOR(DEFAULT) "pourront\n"
SHIFT("\x0F") "traverser la vallée des morts." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Le plus rapide de mes adversaires\n"
"a fait:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"--Igor le fossoyeur" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Jeu d'adresse  \n"
"20 Rubis la partie\n"
COLOR(RED) "10 cibles" COLOR(DEFAULT) ", " COLOR(RED) "15 coups" COLOR(DEFAULT) ", facile!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "10 cibles touchées -- Premier Prix\n"
"8 cibles ou plus -- Partie gratuite\n"
"Moins de 8 cibles -- T'es nul" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Règles du Jeu d'adresse\n"
COLOR(DEFAULT) "Ne pas tirer sur le patron.\n"
"Ne pas jeter de bombes.\n"
"Ne JAMAIS tirer sur le patron." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2A")  COLOR(LIGHTBLUE) "Chasse aux trésors" COLOR(DEFAULT) "\n"
SHIFT("\x08") "T'auras du pot si t'es chanceux." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x34")  COLOR(LIGHTBLUE) "Jeu du plongeon\n"
COLOR(DEFAULT)  SHIFT("\x05") "Aurez-vous le courage de plonger\n"
SHIFT("\x23") "du haut de la falaise?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F")  COLOR(RED) "Sommet de la Montagne" COLOR(DEFAULT) "\n"
SHIFT("\x46") "Danger!!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2A")  COLOR(LIGHTBLUE) "Foire aux Masques!" COLOR(DEFAULT) "\n"
SHIFT("\x0C") "Nous recherchons un coursier!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(LIGHTBLUE) "Bowling Teigneux" COLOR(DEFAULT) "\n"
SHIFT("\x08") "Testez les dernières nouveautés\n"
SHIFT("\x1E") "en matière d'explosions!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(LIGHTBLUE) "Bazar" COLOR(DEFAULT) "\n"
SHIFT("\x20") "Ici l'on trouve de tout!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(LIGHTBLUE) "Apothicaire\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Potions, bandages et onguents!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(RED) "Boutique Goron\n"
COLOR(DEFAULT)  SHIFT("\x23") "Matériel de montagne!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(BLUE) "Boutique Zora" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Les produits de la mer!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  COLOR(LIGHTBLUE) "Excursion du Fossoyeur!\n"
COLOR(DEFAULT)  SHIFT("\x10") "De 18h à 21h (heure d'Hyrule)\n"
SHIFT("\x2D") "--Igor le fossoyeur" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Excursion du Fossoyeur!\n"
SHIFT("\x0A") "L'attraction est " COLOR(RED) "annulée" COLOR(DEFAULT) " jusqu'à\n"
SHIFT("\x3C") "nouvel ordre...\n"
SHIFT("\x20") "Recherchons fossoyeur." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Attaque en Fente!\n"
COLOR(DEFAULT) "Pour faire une fente avec votre \n"
"lame, maintenez " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "et" COLOR(LIGHTBLUE) " [Control-Pad] " COLOR(DEFAULT) "vers\n"
"votre cible puis appuyez sur " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(PURPLE) "Passage étroit\n"
COLOR(DEFAULT) "Faufilez-vous dans ce trou!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Placez-vous devant le trou et \n"
"maintenez " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "vers celui-ci. \n"
"Lorsque l'" COLOR(BLUE) "icône d'action " COLOR(DEFAULT) "indique\n"
"\"Entrer\", appuyez sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Observez bien ce qu'affiche\n"
COLOR(BLUE) "l'icône d'action" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Coupez l'herbe avec votre épée!\n"
COLOR(DEFAULT) "Attaquez avec " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " pour trancher\n"
"horizontalement. Maintenez " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"pour trancher verticalement." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(LIGHTBLUE) "Château d'Hyrule" COLOR(DEFAULT) "\n"
SHIFT("\x38")  COLOR(YELLOW) "Ranch Lon Lon" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Vous êtes ici: " COLOR(LIGHTBLUE) "Château d'Hyrule" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Tout droit: " COLOR(YELLOW) "Ranch Lon Lon" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x43") "Tout droit:\n"
SHIFT("\x13")  COLOR(BLUE) "Salle d'audience du Roi Zora\n"
COLOR(DEFAULT)  SHIFT("\x11") "Appliquez-vous au protocole!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Cabane du Grand " COLOR(RED) "Mido" COLOR(DEFAULT) "\n"
SHIFT("\x32") "Chef des Kokiris" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Cabane des Frères Je-Sais-Tout" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Cabane des Jumelles" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "Cabane de " COLOR(RED) "Saria" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Axer l'angle de vue avec [Z] \n"
COLOR(DEFAULT) "Appuyez sur " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "pour axer votre \n"
"angle de vue vers l'avant." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Restez immobile puis changez de\n"
"direction ou " COLOR(LIGHTBLUE) "maintenez [Z] " COLOR(DEFAULT) "pendant\n"
"un court instant." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Cette technique permet de vous\n"
"orienter toujours dans la bonne\n"
"direction. Pratique, non?" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "En " COLOR(LIGHTBLUE) "maintenant [Z]" COLOR(DEFAULT) ", vous pouvez \n"
"vous déplacez " COLOR(RED) "latéralement" COLOR(DEFAULT) " en \n"
"faisant face toujours au même \n"
"point." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "Les pas de côté" COLOR(DEFAULT) " sont très \n"
"importants dans les couloirs d'un\n"
"donjon ou pendant un combat.\n"
"Entraînez-vous dès maintenant!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Sauter sur les pierres\n"
COLOR(DEFAULT) "Marchez vers le bord d'une plate-\n"
"forme pour sauter automatiquement." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Sautez sur toutes les pierres et\n"
"vous passerez une bonne journée!\n"
SHIFT("\x32") "(proverbe Kokiri)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(RED) "Interdiction de plonger\n"
COLOR(DEFAULT)  SHIFT("\x32") "(L'eau ça mouille)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Visée\n"
COLOR(DEFAULT) "Si vous apercevez une icône " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " \n"
"au-dessus d'un élément, vous \n"
"pouvez cibler celui-ci avec " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "En d'autres termes, en appuyant \n"
"sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " lorsque vous voyez " COLOR(ADJUSTABLE) "▼" COLOR(YELLOW) " " COLOR(DEFAULT) "au-\n"
"dessus d'un objet, vous pouvez \n"
"vous axer vers celui-ci. Cool, non?" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "En appuyant de nouveau sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", \n"
"la cible " COLOR(RED) "disparaîtra" COLOR(DEFAULT) " ou se fixera\n"
"sur un nouvel élément possédant \n"
"une icône " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Lors d'un combat vous opposant à \n"
"de nombreux ennemis, appuyez sur\n"
COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "et " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " vers l'arrière pour\n"
"faire disparaître la cible." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Ciblez les " COLOR(RED) "pierres" COLOR(DEFAULT) " à côté de cette\n"
"pancarte pour vous entraîner!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x30")  COLOR(ADJUSTABLE) "Théâtre Sylvestre" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Venez nous montrer vos grimaces!\n"
SHIFT("\x0D") "De fabuleux prix à remporter!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F") "Venez voir les fabuleux\n"
SHIFT("\x2D")  COLOR(RED) "Frères Je-Sais-Tout\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Et vos questions ne resteront\n"
SHIFT("\x29") "plus sans réponse!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ceci est une " COLOR(RED) "Pierre à Potins" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que d'appuyer sur " COLOR(ADJUSTABLE) "[B]\n"
COLOR(DEFAULT) "vous fait nager plus vite."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte qu'il y a un passage \n"
"secret près de l'arbre au\n"
"Nord-Est de la Plaine d'Hyrule."
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte qu'il y a un passage\n"
"secret sur la route menant au Lac \n"
"Hylia."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que l'épée de Biggoron\n"
"est indestructible."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que Medigoron pue des\n"
"pieds."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que Malon est la\n"
"première à avoir inscrit un record\n"
"à la course d'obstacle du Ranch\n"
"Lon Lon."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que Malon du Ranch\n"
"Lon Lon rêve toutes les nuits \n"
"qu'un prince charmant la demande\n"
"en mariage."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que Ruto, la capricieuse\n"
"princesse Zora, est amoureuse\n"
"d'un garçon..."
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que choisir la visée \n"
"\"maintenue\" au début du jeu \n"
"est super cool!"
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte qu'il y a un passage\n"
"secret non loin d'un arbre sur la\n"
"route de Cocorico."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que, contrairement aux\n"
"apparences, la Princesse Zelda du\n"
"Château d'Hyrule est un vrai\n"
"garçon manqué!"
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que la nourrice de la\n"
"Princesse Zelda est une Sheikah, \n"
"une race souvent considérée comme\n"
"éteinte."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'un drôle de type\n"
"s'amuse à cavaler autour de la\n"
"Plaine d'Hyrule."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'il est interdit d'utiliser\n"
"des lunettes pendant la chasse\n"
"aux trésors.."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que cogner sur les poules,\n"
"c'est rigolo et ça défoule!"
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On raconte que les Gerudos \n"
"viennent souvent chercher des \n"
"petits amis au Château d'Hyrule."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que Zelda est le plus beau\n"
"jeu du monde... Ben, j'crois bien\n"
"qu'c'est vrai!"
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que tenir un bâton Mojo\n"
"près d'un papillon fait \n"
"apparaître quelque chose."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'un donjon une fois\n"
"terminé peut faire apparaître\n"
"de nouveaux monstres."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que les Gerudos vénèrent\n"
"Ganondorf comme un dieu."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'il y a un passage secret \n"
"près de l'entrée de la Vallée \n"
"Gerudo."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que la chouette du nom de\n"
"Kaepora Gaebora est la réincarna-\n"
"tion d'un ancien Sage."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que le traducteur de Zelda\n"
"est super beau et méga cool!"
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que le destrier de\n"
"Ganondorf est un étalon dressé \n"
"par les Gerudos."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que Ganondorf veut non\n"
"seulement dominer les Gerudos \n"
"mais aussi Hyrule!"
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que le Gymnase Gerudo est\n"
"super balèze...\n"
"Et que le trésor secret n'est pas \n"
"aussi cool qu'on le pense!"
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'il y a un interrupteur\n"
"à activer avec l'Attaque Cyclone."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'il y a en tout\n"
"100 Skulltulas d'or à trouver."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'un Hylien se transforme\n"
"en monstre s'il s'égare dans les\n"
"Bois Perdus!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que les insectes adorent\n"
"se cacher dans les trous du sol\n"
"d'Hyrule."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit que manger des cafards,\n"
"c'est dégueulasse."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"On dit qu'un Kokiri a quitté la \n"
"forêt et a survécu!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "C'est quoi ce truc?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "Ce monstre ronge les entrailles de\n"
"l'Arbre Mojo! Vise son " COLOR(DEFAULT) "oeil" COLOR(LIGHTBLUE) " lorsque\n"
"celui-ci est rouge!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Oeuf Gohma\n"
COLOR(LIGHTBLUE) "Si cet oeuf éclot, une Larve\n"
"Gohma apparaîtra." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larve Gohma\n"
COLOR(LIGHTBLUE) "Prends garde à ses sauts!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula\n"
COLOR(LIGHTBLUE) "Son " COLOR(DEFAULT) "ventre" COLOR(LIGHTBLUE) " est son point faible!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grosse Skulltula\n"
COLOR(LIGHTBLUE) "Son " COLOR(DEFAULT) "ventre" COLOR(LIGHTBLUE) " est son point faible!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tailpasaran\n"
COLOR(LIGHTBLUE) "Sa " COLOR(DEFAULT) "queue " COLOR(LIGHTBLUE) "est son point faible!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mojo Baba\n"
COLOR(LIGHTBLUE) "Frappe-la après son attaque et \n"
"elle se dressera. Tranche-la vite \n"
"pour obtenir un " COLOR(DEFAULT) "Bâton Mojo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grosse Mojo Baba\n"
COLOR(LIGHTBLUE) "Frappe-la après son attaque et \n"
"elle se dressera. Tranche-la vite \n"
"pour obtenir un " COLOR(DEFAULT) "Bâton Mojo" COLOR(LIGHTBLUE) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mojo Baba\n"
COLOR(LIGHTBLUE) "Son seul contact te fera souffrir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peste Mojo\n"
COLOR(LIGHTBLUE) "Approche-t'en et il se cachera \n"
"dans l'herbe. Fais rebondir ses\n"
"projectiles!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "King Dodongo\n"
COLOR(LIGHTBLUE) "Cet énorme Dodongo avalerait \n"
"n'importe quoi! Donne-lui une bonne\n"
"secousse et frappe avec ton " COLOR(DEFAULT) "épée" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Prends garde à son souffle!\n"
"Utilise bien la " COLOR(DEFAULT) "Visée [Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo Junior\n"
COLOR(LIGHTBLUE) "Prends garde à ses sauts!\n"
"Il explosera une fois vaincu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos \n"
COLOR(LIGHTBLUE) "Utilise souvent ton bouclier et \n"
"la " COLOR(DEFAULT) "Visée [Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos \n"
COLOR(LIGHTBLUE) "Utilise souvent ton bouclier et \n"
"la " COLOR(DEFAULT) "Visée [Z]" COLOR(LIGHTBLUE) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Saigneur ardent\n"
COLOR(LIGHTBLUE) "Détruis-le rapidement ou ses \n"
"flammes feront brûler ton \n"
COLOR(DEFAULT) "Bouclier Mojo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Saigneur\n"
COLOR(LIGHTBLUE) "Utilise la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "pour toujours\n"
"garder un oeil sur lui." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armos\n"
COLOR(LIGHTBLUE) "Immobilise-le pour ensuite le\n"
"détruire!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinade\n"
COLOR(LIGHTBLUE) "De dangereuses méduses lui \n"
"tournent autour. Vise la partie\n"
"protégée de son corps!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tentacule Parasite?\n"
COLOR(LIGHTBLUE) "La partie mince semble être son\n"
"point faible... Tu as besoin d'une\n"
"arme spéciale pour le couper!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bulld'O\n"
COLOR(LIGHTBLUE) "Ta lame la fera rebondir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "Touche-la et tu recevras une\n"
"décharge électrique!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "Touche-la et tu recevras une\n"
"décharge électrique!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Manta\n"
COLOR(LIGHTBLUE) "Détruis-la avant qu'elle ne \n"
"t'attaque!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon Spectral\n"
COLOR(LIGHTBLUE) "C'est un esprit maléfique du \n"
"Temple de la forêt! Il surgit\n"
"de l'un des tableaux." BOX_BREAK COLOR(LIGHTBLUE) "Réponds à son attaque magique \n"
"avec l'une des tiennes!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Attire-le et observe bien ses \n"
"mouvements! Attaque quand il\n"
"baisse sa garde!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tetdoss Bleue\n"
COLOR(LIGHTBLUE) "Protège-toi de sa flamme bleue \n"
"avec ton " COLOR(DEFAULT) "bouclier" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tetdoss Blanche\n"
COLOR(LIGHTBLUE) "Vise-la une fois à l'arrêt!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tetdoss Verte\n"
COLOR(LIGHTBLUE) "Vise-la lorsque sa flamme verte \n"
"disparaît!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skullwalltula\n"
COLOR(LIGHTBLUE) "Ne la touche surtout pas!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula d'or\n"
COLOR(LIGHTBLUE) "Cette Araignée de la Malédiction,\n"
"une fois vaincue, fera apparaître \n"
"un " COLOR(DEFAULT) "symbole" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volcania\n"
COLOR(LIGHTBLUE) "Il est le gardien du Temple du\n"
"feu, réveillé par le Roi Sombre.\n"
"Quel peut être son point faible?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Danse-Flamme\n"
COLOR(LIGHTBLUE) "Souffle d'abord son " COLOR(DEFAULT) "habit de \n"
"flammes" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Feu Visqueux\n"
COLOR(LIGHTBLUE) "Il fuira une fois sa flamme éteinte.\n"
"Détruis-le avant sa régénération!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tetdoss Rouge\n"
COLOR(LIGHTBLUE) "Protège-toi de son attaque \n"
"avec ton " COLOR(DEFAULT) "bouclier" COLOR(LIGHTBLUE) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morpha\n"
COLOR(LIGHTBLUE) "Gardien du Temple de l'eau, il\n"
"contrôle les fluides. Son point \n"
"faible semble être le " COLOR(DEFAULT) "noyau" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ombre de " NAME "\n"
COLOR(LIGHTBLUE) "Terrasse ton Frère Noir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Coquillos\n"
COLOR(LIGHTBLUE) "Son " COLOR(DEFAULT) "organe interne " COLOR(LIGHTBLUE) "est son point\n"
"faible!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spike\n"
COLOR(LIGHTBLUE) "Vise-le quand il rétracte ses \n"
"pointes!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Seigneur du Temple de l'Ombre, \n"
"échappé du puits de Cocorico.\n"
"Utilise le " COLOR(DEFAULT) "Monocle de Vérité" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Effroi\n"
COLOR(LIGHTBLUE) "Son regard te paralysera. S'il te \n"
"mord, appuie sur les " COLOR(DEFAULT) "boutons " COLOR(LIGHTBLUE) "pour\n"
"te dégager!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ganon Spectral\n"
COLOR(LIGHTBLUE) "Attaque-le " COLOR(DEFAULT) "lorsqu'il sort des \n"
"tableaux" COLOR(LIGHTBLUE) "! Fais attention aux \n"
"illusions!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Son regard te paralysera. S'il te \n"
"mord, appuie sur les " COLOR(DEFAULT) "boutons" COLOR(LIGHTBLUE) " pour\n"
"te dégager!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poigneur\n"
COLOR(LIGHTBLUE) "S'il t'empoigne, appuie sur les\n"
COLOR(DEFAULT) "boutons " COLOR(LIGHTBLUE) "pour te dégager!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poignant\n"
COLOR(LIGHTBLUE) "Prends garde aux mains infinies! \n"
"Vise la tête...ça l'arrêtera net!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Clapoir\n"
COLOR(LIGHTBLUE) "Fais bien attention à son " COLOR(DEFAULT) "ombre" COLOR(LIGHTBLUE) " \n"
"sur le sol. Détruis-la avant qu'elle\n"
"ne retourne au plafond!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grossbaffe\n"
COLOR(LIGHTBLUE) "Lorsqu'elle se divise, viens à bout\n"
"de toutes les mains avant qu'elles\n"
"ne fusionnent!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Koume\n"
COLOR(LIGHTBLUE) "Mère spirituelle de Ganondorf.\n"
"Maîtresse des flammes infinies. \n"
"Elle est vulnérable au " COLOR(DEFAULT) "froid" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Kotake\n"
COLOR(LIGHTBLUE) "Mère spirituelle de Ganondorf.\n"
"Maîtresse des glaces éternelles.\n"
"Elle est vulnérable au " COLOR(DEFAULT) "feu" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hache-Viande\n"
COLOR(LIGHTBLUE) "C'est étrange...\n"
"Cet ennemi n'est pas comme les \n"
"autres!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hache-Viande\n"
COLOR(LIGHTBLUE) "Sa hache est meurtrière! \n"
"Frappe-le quand il baisse sa garde!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Voilà ce qu'il advient des enfants\n"
"perdus dans la forêt... On dirait \n"
"qu'il n'aime pas les adultes." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Pudding\n"
COLOR(LIGHTBLUE) "Ce monstre avale " COLOR(DEFAULT) "tuniques" COLOR(LIGHTBLUE) " et \n"
COLOR(DEFAULT) "boucliers" COLOR(LIGHTBLUE) ". Détruis-le vite pour\n"
"récupérer ton équipement!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Sentinelle\n"
COLOR(LIGHTBLUE) "Evite son regard meurtrier!\n"
"A mon avis, son oeil craint la \n"
"fumée!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anubis\n"
COLOR(LIGHTBLUE) "Il est vulnérable au " COLOR(RED) "feu" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mr. Freezzard\n"
COLOR(LIGHTBLUE) "Attention à son souffle glacé! \n"
"Détruis-le entièrement avant qu'il\n"
"ne régénère." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf, Seigneur du Malin\n"
COLOR(LIGHTBLUE) "Son point faible? \n"
"Comment veux-tu qu'je le sache!!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "Quel est son point faible?\n"
"Mais j'en sais rien moi!!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Voici ce qu'il advient des enfants\n"
"perdus dans la forêt. \n"
"Comment devenir son ami?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Voilà ce qu'il advient des enfants\n"
"perdus dans la forêt? Il a l'air\n"
"triste de ne plus avoir de visage." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Voilà ce qu'il advient des enfants\n"
"perdus dans la forêt? Il a l'air\n"
"content avec sa tête de mort." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Fais rebondir ses rochers!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Esprit du cimetière?\n"
COLOR(LIGHTBLUE) "Fixe-le avec la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "et il\n"
"disparaîtra..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Esprit\n"
COLOR(LIGHTBLUE) "Fixe-le avec la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "et il\n"
"disparaîtra..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Araknon Rouge\n"
COLOR(LIGHTBLUE) "Fixe-le avec la " COLOR(DEFAULT) "Visée [Z] " COLOR(LIGHTBLUE) "pendant\n"
"ses sauts..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Araknon Bleu\n"
COLOR(LIGHTBLUE) "Attire-le de préférence vers le sol\n"
"pour le détruire!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Observe bien ses mouvements!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "Ses " COLOR(DEFAULT) "racines " COLOR(LIGHTBLUE) "sont sensibles!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larve Peahat\n"
COLOR(LIGHTBLUE) "Protège-toi avec ton " COLOR(DEFAULT) "bouclier" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobo\n"
COLOR(LIGHTBLUE) "Attire-le vers toi et observe ses\n"
"mouvements! Frappe quand il\n"
"baisse sa garde!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peste Dingo\n"
COLOR(LIGHTBLUE) "Approche-t'en et il se cachera\n"
"dans l'herbe..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peste Marchande\n"
COLOR(LIGHTBLUE) "Approche-t'en et il se cachera\n"
"dans l'herbe..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spectre d'Igor\n"
COLOR(LIGHTBLUE) "C'est le fantôme du fossoyeur!\n"
"Suis-le et il te remettra son \n"
COLOR(DEFAULT) "trésor" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg de la Confrérie des Esprits\n"
COLOR(LIGHTBLUE) "Ne te laisse pas avoir par ses\n"
"répliques illusoires! Cherche \n"
COLOR(DEFAULT) "la bonne" COLOR(LIGHTBLUE) " et vise bien!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle de la Confrérie des Esprits\n"
COLOR(LIGHTBLUE) "Vise-la quand elle apparaît!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beth de la Confrérie des Esprits\n"
COLOR(LIGHTBLUE) "Vise-la quand elle apparaît!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy de la Confrérie des Esprits\n"
COLOR(LIGHTBLUE) "Vise-la quand elle apparaît!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Voleuse Gerudo\n"
COLOR(LIGHTBLUE) "Quand elle baisse sa garde, cogne-\n"
"la comme une brute! Fais vite ou \n"
"tu seras capturé." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Sakdoss\n"
COLOR(LIGHTBLUE) "N'aie pas peur du Sakdoss!\n"
"Cogne comme un sourd en criant:\n"
"YAAAAAAAAAAH!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Saigneur givré\n"
COLOR(LIGHTBLUE) "Détruis-le avant qu'il ne t'attaque!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobo blanc\n"
COLOR(LIGHTBLUE) "Attire-le vers toi et observe ses\n"
"mouvements! Frappe quand il\n"
"baisse sa garde!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Toukor\n"
COLOR(LIGHTBLUE) "Détruis-le avant qu'il ne t'attaque!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bigocto\n"
COLOR(LIGHTBLUE) "Attaque-le par derrière!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ame\n"
COLOR(LIGHTBLUE) "Ce type d'Esprit, plus courageux, \n"
"ne fuira pas ton regard. \n"
"Attention: elle se déplace vite!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fusion maléfique\n"
COLOR(LIGHTBLUE) "Le feu et la glace réunis en un\n"
"corps parfait. Sers-toi de leur\n"
COLOR(DEFAULT) "propre attaque magique" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Esprit\n"
COLOR(LIGHTBLUE) "Cet Esprit ne disparaît pas si tu\n"
"le fixes. Rien ne lui fait peur,\n"
"apparemment..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D") "Jouez avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) " et " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." COLOR(YELLOW) "\n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "[A]" COLOR(DEFAULT) " et " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "- Jouer " COLOR(ADJUSTABLE) "   [B] " COLOR(DEFAULT) "- Annuler\n"
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
QUICKTEXT_ENABLE  SHIFT("\x19") "Jouez le " COLOR(ADJUSTABLE) "Menuet des bois" COLOR(DEFAULT) "." COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT)  QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "Jouez le " COLOR(RED) "Boléro du feu" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15") "Jouez la " COLOR(BLUE) "Sérénade de l'eau" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Jouez le " COLOR(YELLOW) "Requiem des esprits" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Jouez le " COLOR(PURPLE) "Nocturne de l'ombre" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Jouez le " COLOR(LIGHTBLUE) "Prélude de la lumière" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1A") "Jouez le " COLOR(ADJUSTABLE) "Chant de Saria" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "OK? Voici la" COLOR(RED) " mélodie" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "Retiens cette " COLOR(BLUE) "mélodie" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Retiens à jamais le " COLOR(YELLOW) "Chant du Soleil" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Ce chant" COLOR(DEFAULT) " ouvre la Porte du Temps.\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Je n'oublierai jamais cette " COLOR(PURPLE) "mélodie" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "[A]" COLOR(DEFAULT) " et " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "- Jouer " COLOR(ADJUSTABLE) "   [B] " COLOR(DEFAULT) "- Annuler\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x0A")  COLOR(RED) "Impossible de se téléporter ici!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Se téléporter aux Bois Perdus!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Se téléporter au Cratère du Péril!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "Se téléporter au Lac Hylia!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Se téléporter au Colosse du \n"
"Désert!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Se téléporter au Cimetière!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Se téléporter au Temple du Temps!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK!\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Vous jouez le " COLOR(ADJUSTABLE) "Menuet des bois" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Vous jouez le " COLOR(RED) "Boléro du feu" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "Vous jouez la " COLOR(BLUE) "Sérénade de l'eau" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vous jouez le " COLOR(YELLOW) "Requiem des esprits" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vous jouez le " COLOR(PURPLE) "Nocturne de l'ombre" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vous jouez le " COLOR(LIGHTBLUE) "Prélude de la lumière" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Vous jouez le " COLOR(ADJUSTABLE) "Chant de Saria" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Vous jouez le " COLOR(RED) "Chant d'Epona" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Vous jouez la " COLOR(BLUE) "Berceuse de Zelda" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0B") "Vous jouez le " COLOR(YELLOW) "Chant du Soleil" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Vous jouez le " COLOR(LIGHTBLUE) "Chant du Temps" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vous jouez le " COLOR(PURPLE) "Chant des Tempêtes" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Vous jouez le " COLOR(YELLOW) "Chant de l'Epouvantail" COLOR(DEFAULT) "\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Haa... Enfin debout!\n"
"Moi c'est " COLOR(RED) "Navi" COLOR(LIGHTBLUE) " la fée!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Le très vénérable Arbre Mojo m'a\n"
"désignée pour être ta " COLOR(RED) "partenaire " COLOR(LIGHTBLUE) "!\n"
"J'en suis très honorée!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x14") "Hé! Salut, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Whoaaa! Une fée!!" BOX_BREAK UNSKIPPABLE "Enfin tu as reçu une fée,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je vais t'attendre ici!\n"
"Va voir le vénérable Arbre Mojo!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(BLUE) "[A] " COLOR(DEFAULT) "devant une pierre, et han! \n"
"Je la soulève.\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "devant une pierre, et yaa!\n"
"Je la soulève." BOX_BREAK "Pfouuh, cette peste de " COLOR(RED) "Mido" COLOR(DEFAULT) "...Il \n"
"m'a obligé à ramasser toutes les \n"
"pierres devant chez lui."
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, tu as une " COLOR(LIGHTBLUE) "fée" COLOR(DEFAULT) " maintenant?!\n"
"C'est cool, " NAME "!" BOX_BREAK UNSKIPPABLE "Comment?" BOX_BREAK UNSKIPPABLE "Tu as été convoqué par le \n"
COLOR(RED) "vénérable Arbre Mojo" COLOR(DEFAULT) "?\n"
"Quel honneur!" BOX_BREAK UNSKIPPABLE "Il va peut-être te donner un joli \n"
"cadeau, hi hi!" BOX_BREAK UNSKIPPABLE "Il est notre père à tous, tu sais!\n"
"Il protège la forêt de sa toute\n"
"puissance! Il a donné vie à tous\n"
"les Kokiris!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je me demande bien si le \n"
COLOR(RED) "vénérable Arbre Mojo " COLOR(DEFAULT) "a créé\n"
"tous les êtres de la forêt."
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bon, répétons quelques \n"
"mouvements!" BOX_BREAK "Cible quelque chose avec la \n"
COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) " et appuie sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " \n"
"en allant à droite ou à gauche \n"
"pour " COLOR(RED) "bondir sur les côtés" COLOR(DEFAULT) "." BOX_BREAK "Cible avec la " COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) ", appuie\n"
"sur " COLOR(BLUE) "[A] " COLOR(DEFAULT) "tout en pointant vers\n"
"l'arrière pour faire un " COLOR(RED) "saut \n"
"périlleux arrière" COLOR(DEFAULT) "." BOX_BREAK "Pour faire une " COLOR(RED) "roulade" COLOR(DEFAULT) ", cible\n"
"avec la " COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) " et appuie \n"
"sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Dégaine ton épée et utilise la \n"
COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) " pour effectuer une \n"
COLOR(RED) "Attaque sautée" COLOR(DEFAULT) " avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!\n"
"Elle fait deux fois plus mal!" BOX_BREAK "Entraîne-toi à la " COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) " sur\n"
"ces pierres, et essaie tous ces \n"
"nouveaux mouvements!"
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu n'es pas autorisé à quitter la \n"
"forêt, petit Kokiri!" TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le très vénérable Arbre Mojo dit\n"
"qu'un Kokiri hors de la forêt est\n"
"un Kokiri mort!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cette peste de " COLOR(RED) "Mido" COLOR(DEFAULT) " m'a obligé à\n"
"tondre la pelouse devant la maison\n"
"de Saria." BOX_BREAK UNSKIPPABLE "Mido drague Saria en lui rendant \n"
"service! Mais au bout du compte \n"
"c'est moi qui me tape le sale \n"
"boulot à sa place!" TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Toi et " COLOR(RED) "Saria" COLOR(DEFAULT) ", vous êtes plutôt \n"
"copains, non? Alors pourquoi tu \n"
"m'aiderais pas un peu à couper \n"
"cette herbe!" BOX_BREAK "Tu n'as qu'à garder tout ce que tu \n"
"y trouveras."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bravo! \n"
"Voilà comment s'utilise une " COLOR(LIGHTBLUE) "fée" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "C'est vraiment chouette d'en avoir\n"
"une, hein?" BOX_BREAK UNSKIPPABLE "Je vais t'apprendre à parler aux \n"
"gens avec ta fée!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quand une fée vole autour de\n"
"quelqu'un, utilise " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " pour " COLOR(RED) "regarder" COLOR(DEFAULT) " \n"
"dans sa direction." BOX_BREAK "Utilise la " COLOR(LIGHTBLUE) "Visée [Z]" COLOR(DEFAULT) " pour parler \n"
"aux gens de loin, un peu comme\n"
"nous sommes en train de faire." BOX_BREAK "Et si tu n'as rien à cibler, appuie \n"
"sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " pour " COLOR(RED) "regarder" COLOR(DEFAULT) " devant toi."
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah! Enfin tu as eu ta " COLOR(LIGHTBLUE) "fée" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Mais tu as encore beaucoup à \n"
"apprendre!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Yipii! " QUICKTEXT_ENABLE "Quelle bonne nouvelle!" QUICKTEXT_DISABLE "\n"
"Je suis si heureuse!" BOX_BREAK UNSKIPPABLE "Tu es maintenant un vrai Kokiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Alors, c'est vrai? \n"
"Le très vénérable Arbre Mojo t'a \n"
"convoqué?" BOX_BREAK UNSKIPPABLE "C'est un véritable honneur d'être\n"
"convoqué par le vénérable Arbre\n"
"Mojo, tu sais!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x1C") "Oh...alors tu pars...déjà..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ce n'est pas grave...\n"
"Nous serons amis pour toujours...\n"
"N'est-ce pas?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je veux que tu gardes cet \n"
"ocarina...\n"
"Prends-en grand soin!"
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Pense à moi en jouant de l'ocarina.\n"
"Et un jour peut-être...\n"
"Tu reviendras me voir..."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh... Navi...\n"
"Enfin te voici..." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Sois le bienvenu..." BOX_BREAK UNSKIPPABLE "Ecoute, écoute bien, jeune enfant...\n"
"Moi, " COLOR(RED) "l'Arbre Mojo" COLOR(DEFAULT) ", de par mes \n"
"sages paroles, vais te révéler la\n"
"sombre réalité!" BOX_BREAK UNSKIPPABLE "Ton sommeil, depuis plusieurs\n"
"lunes, est tourmenté par\n"
"d'épuisants songes et de terribles \n"
"cauchemars..." BOX_BREAK UNSKIPPABLE "Alors que les forces obscures\n"
"grandissent, une aura maléfique\n"
"s'étend sur le monde, pervertissant\n"
"nos rêves de sombres présages!" BOX_BREAK UNSKIPPABLE "Et toi aussi, jeune enfant, tu as \n"
"ressenti cette infâmie..." BOX_BREAK UNSKIPPABLE  NAME "... \n"
"Le temps est venu pour toi de \n"
"mettre ton courage à l'épreuve..." TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je suis sous l'emprise d'une\n"
"odieuse " COLOR(RED) "malédiction" COLOR(DEFAULT) "...\n"
"Pour me libérer, j'ai besoin de \n"
"ta vaillance et de ta sagesse." BOX_BREAK "Auras-tu le courage d'entreprendre\n"
"cette noble quête?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Alors entre, brave " NAME ",\n"
"et toi aussi Navi..." BOX_BREAK UNSKIPPABLE "Navi la fée, tu aideras   \n"
NAME " de ton mieux..." BOX_BREAK UNSKIPPABLE "Et toi " NAME ", quand " COLOR(LIGHTBLUE) "Navi \n"
COLOR(DEFAULT) "désirera te parler, utilise " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "pour\n"
"écouter ses conseils avisés..."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Soit... Il est sans doute encore \n"
"trop tôt pour toi...\n"
"Alors retourne dans la forêt pour \n"
"terminer ton apprentissage..." BOX_BREAK "Une fois prêt, reviens te présenter\n"
"devant moi... Parle en appuyant \n"
"sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'" COLOR(ADJUSTABLE) "aire d'entraînement sylvestre " COLOR(DEFAULT) " \n"
"t'enseignera de nouvelles \n"
"techniques. Dirige-toi vers \n"
"cette colline..."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Aïe-ouille-aïe!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Pardon, seigneur!" QUICKTEXT_DISABLE "\n"
"Je te donne un indice et tu me \n"
"laisses partir, OK?" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Tu peux sauter d'une falaise\n"
"sans te faire mal. Maintiens " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " \n"
"vers l'avant pour faire une roulade\n"
"et ainsi amortir ta chute." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Bon d'accord, ça ne marche pas\n"
"à tous les coups... Surtout si la \n"
"falaise est super haute...\n"
"Gnark, gnark..." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Essaie quand même!\n"
QUICKTEXT_ENABLE "Warf.. arf.. arf!!!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tiens tiens!...\n"
"On dirait bien le p'tit Kokiri\n"
"derrière ce masque!"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pas mal ton masque. Il me plaît!\n"
"Avec ça sur ma face, j'aurai l'air\n"
"d'un dur, un vrai!" BOX_BREAK "Donne! Donne! Donne!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Jamais" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beuh! T'es nul..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouais!!! Je vais le porter toute\n"
"la journée!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "Il n'a donné que " COLOR(RED) "10 Rubis" COLOR(DEFAULT) "! Et ce \n"
"masque en vaut 20! Tu t'es fait \n"
"avoir, mec!" BOX_BREAK UNSKIPPABLE "Retournons à la Foire aux Masques\n"
"payer les " COLOR(RED) "20 Rubis" COLOR(DEFAULT) ". La différence, \n"
"c'est pour ta pomme!!!"
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tous mes copains veulent le même \n"
"masque, j'ai la super cote!!!\n"
"Nananèreuh..."
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tout va bien? \n"
"Tu n'as pas quitté la forêt?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sais-tu qu'en maintenant " COLOR(LIGHTBLUE) "▼ " COLOR(DEFAULT) "vers" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "l'avant pendant un saut tu peux \n"
"faire une roulade pour amortir ta \n"
"chute?" BOX_BREAK "Bien sûr, tomber de trop haut te\n"
"fera quand même bobo..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria t'attend à l'endroit habituel."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Félicitations, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa! Il est cool ton lance-pierre!" BOX_BREAK "Tu peux viser en maintenant " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " \n"
"et tirer en relâchant le bouton!\n"
"Pratique, non?" BOX_BREAK "Garde ton lance-pierre en main, \n"
"cible avec la " COLOR(LIGHTBLUE) "Visée [Z] " COLOR(DEFAULT) "et" COLOR(LIGHTBLUE) " " COLOR(RED) "tire en \n"
"te déplaçant!\n"
COLOR(DEFAULT) "Tu le savais pas ça, hein?"
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hélas non, " NAME "...\n"
"Sache que mon temps est compté..."
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Maintenant...écoute-moi bien... \n"
"Un" COLOR(RED) " vil cavalier du désert " COLOR(DEFAULT) "m'a \n"
"infligé cette terrible et odieuse \n"
"malédiction..."
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu cherches Saria? \n"
"Elle est dans les " COLOR(ADJUSTABLE) "Bois Perdus" COLOR(DEFAULT) ".\n"
"Comme d'habitude..." BOX_BREAK "Ne dis pas que tu ne sais plus \n"
"comment y aller! L'entrée est sur \n"
"la falaise au-dessus du village!" BOX_BREAK "Je parie que tu vas te perdre...\n"
"Minable!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Pfeuhh!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu ne dois surtout pas laisser \n"
"l'homme du désert en armure noire \n"
"s'approcher de la sainte Triforce..." BOX_BREAK UNSKIPPABLE "Et tu ne permettras jamais que \n"
"cet homme au coeur si mauvais \n"
"puisse s'immiscer dans le très \n"
"Saint Royaume des Légendes..." BOX_BREAK UNSKIPPABLE "Ce vil chacal m'a jeté cette \n"
"malédiction infecte et mortelle \n"
"pour saper mon pouvoir." BOX_BREAK UNSKIPPABLE "Ce sort si néfaste me promet un \n"
"trépas imminent..." BOX_BREAK UNSKIPPABLE "Même si tes vaillants efforts\n"
"ont eu raison de ce maléfice, mon\n"
"destin est scellé depuis le début..." BOX_BREAK UNSKIPPABLE "Hélas, je ne peux m'y soustraire:\n"
"le moment fatal est proche..." BOX_BREAK UNSKIPPABLE "Mais ne te lamente pas sur \n"
"mon sort..." BOX_BREAK UNSKIPPABLE "Je t'ai transmis mon savoir...\n"
"Tu connais la vérité maintenant...\n"
"Mon rôle s'achève ici..." BOX_BREAK UNSKIPPABLE "Tu es le dernier espoir d'Hyrule!"
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La destinée du monde dépend de \n"
"tes actes...\n"
NAME "...\n"
"Tu es courageux et vaillant..." BOX_BREAK UNSKIPPABLE "Navi, belle petite fée...\n"
"Aide " NAME " dans sa \n"
"quête..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "Je t'en prie... Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "...Adieuuuu..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Allons au Château d'Hyrule,\n"
NAME "!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Adieu..." COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "Vénérable Arbre Mojo..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Dommage...Hein? Hein?"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu veux encore tenter ta chance?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé, toi là! \n"
"\"" COLOR(LIGHTBLUE) "Monsieur J'ai-pas-d'fée" COLOR(DEFAULT) "!\"\n"
"Tu lui veux quoi au vénérable \n"
"Arbre Mojo?" BOX_BREAK UNSKIPPABLE "Sans fée t'es même pas un vrai \n"
"Kokiri, d'abord!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si tu veux passer, " COLOR(BLUE) "équipe-toi" COLOR(DEFAULT) " \n"
"d'abord d'une " COLOR(ADJUSTABLE) "épée" COLOR(DEFAULT) " et d'un " COLOR(LIGHTBLUE) "bouclier" COLOR(BLUE) "," COLOR(DEFAULT) "\n"
"minus!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Pfeuh!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4D")  QUICKTEXT_ENABLE "Quoi?!" QUICKTEXT_DISABLE "\n"
UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "ne veut pas te laisser voir\n"
"le vénérable Arbre Mojo?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Va t'acheter un " COLOR(LIGHTBLUE) "bouclier " COLOR(DEFAULT) "à la \n"
"boutique Kokiri. Mais pour l'" COLOR(ADJUSTABLE) "épée" COLOR(DEFAULT) "... \n"
"Cherche bien dans un coin du \n"
"village!"
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Si tu veux voir le Vénérable Arbre\n"
"Mojo, Il te faut d'abord une " COLOR(ADJUSTABLE) "épée" COLOR(DEFAULT) " \n"
"et un " COLOR(LIGHTBLUE) "bouclier" COLOR(DEFAULT) "!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Moââ, le grand Mido, je ne \n"
"t'accepterai jamais comme l'un\n"
"des nôtres!" BOX_BREAK "Et puis d'abord, comment t'as fait \n"
"pour être le chouchou de Saria et\n"
"du vénérable Arbre Mojo?!  \n"
".......Pfeuuh!......."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je peux te renseigner sur les \n"
COLOR(RED) "icônes " COLOR(DEFAULT) "en haut de l'écran. \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Les icônes jaunes\n"
"Les icônes bleues" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Les trois icônes jaunes dans le \n"
"coin en haut à droite s'appellent:\n"
COLOR(YELLOW) "Icônes" COLOR(DEFAULT) " " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK "Elles montrent ce que tu peux \n"
"utiliser avec les boutons " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] \n"
COLOR(DEFAULT) "et " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "." BOX_BREAK "Quand tu obtiens un nouvel " COLOR(YELLOW) "objet" COLOR(DEFAULT) ", \n"
"tu peux l'assigner à l'un des trois\n"
"boutons " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " en activant le menu \n"
"de l'" COLOR(YELLOW) "inventaire" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"L'icône bleue en haut de l'écran \n"
"est l'" COLOR(BLUE) "Icône d'Action" COLOR(DEFAULT) "." BOX_BREAK "Cette icône t'indique les actions\n"
"réalisables en appuyant sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Selon l'endroit et le moment, ce \n"
"bouton te permettra de faire\n"
"différentes actions.\n"
"Observe bien l'icône d'action!"
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je suis incollable sur la " COLOR(RED) "carte" COLOR(DEFAULT) " et \n"
"les " COLOR(RED) "objets" COLOR(DEFAULT) "... Pose-moi n'importe\n"
"quelle question mais prépare-toi à  \n"
"de longues explications!" BOX_BREAK "Bon alors, tu veux savoir quoi?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Ben...C'est quoi la carte?\n"
"Heu..Les objets... \n"
"Houlà! Me parle pas, toi!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il y a une " COLOR(RED) "carte" COLOR(DEFAULT) " affichée dans le \n"
"coin en bas à droite." BOX_BREAK "La " COLOR(YELLOW) "flèche jaune" COLOR(DEFAULT) " montre ta position \n"
"et ton orientation actuelles. La \n"
COLOR(RED) "marque rouge" COLOR(DEFAULT) " indique l'endroit par \n"
"lequel tu es entré sur cette carte." BOX_BREAK "Tu peux supprimer l'affichage de la \n"
"carte avec  " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) "." BOX_BREAK "Pour connaître le nom des divers\n"
"emplacements de la carte, appuie \n"
"sur " COLOR(RED) "START" COLOR(DEFAULT) "." BOX_BREAK "Tu feras alors apparaître le\n"
COLOR(RED) "Sous-Menu de la Carte" COLOR(DEFAULT) "." BOX_BREAK "Seront alors affichés la carte\n"
"générale d'Hyrule ainsi qu'une\n"
"multitude de renseignements!\n"
"Tu as bien tout compris?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Les objets appartiennent à trois\n"
"catégories différentes:\n"
"l'" COLOR(BLUE) "Equipement" COLOR(DEFAULT) ", l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) " et \n"
"le " COLOR(LIGHTBLUE) "Statut" COLOR(DEFAULT) "." BOX_BREAK "Les objets de" COLOR(BLUE) " " COLOR(DEFAULT) "l'" COLOR(BLUE) "Equipement" COLOR(DEFAULT) " sont  \n"
"les épées, les boucliers les \n"
"tuniques, etc... Equipe-les pour \n"
"les rendre actifs!" BOX_BREAK "Ceux de l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) " peuvent être \n"
"assignés aux boutons " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " et \n"
COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ". Pour les utiliser, appuie sur \n"
"le bouton correspondant!" BOX_BREAK "Ceux du " COLOR(LIGHTBLUE) "Statut" COLOR(DEFAULT) " sont des objets  \n"
"amassés au gré de l'aventure.\n"
"Tu ne peux que les porter!" BOX_BREAK "Si tu veux organiser ton\n"
"équipement ou juste vérifier ton \n"
"inventaire, appuie sur " COLOR(RED) "START" COLOR(DEFAULT) ". Des \n"
"sous-menus apparaîtront!" BOX_BREAK "Passe d'un sous-menu à l'autre \n"
"avec " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". Familiarise-toi \n"
"avec ce système!" BOX_BREAK "Utilise " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour activer un \n"
COLOR(BLUE) "Equipement" COLOR(DEFAULT) ", et  " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) " \n"
"pour l'" COLOR(YELLOW) "Inventaire" COLOR(DEFAULT) "." BOX_BREAK "Bwouff...C'était long!!!\n"
"J'espère que tu as bien tout \n"
"compris?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Souviens-toi bien: pour \n"
COLOR(ADJUSTABLE) "sauvegarder" COLOR(DEFAULT) ", appuie sur " COLOR(RED) "START" COLOR(DEFAULT) " \n"
"pour accéder aux sous-menus puis \n"
"sur " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ma soeur est partie faire des \n"
"emplettes à la Boutique au toit \n"
"rouge. Hi hi!" BOX_BREAK "Au fait, un " COLOR(RED) "Rubis" COLOR(DEFAULT) " " COLOR(ADJUSTABLE) "vert" COLOR(DEFAULT) " ne vaut \n"
"qu'un rubis, mais un " COLOR(BLUE) "bleu" COLOR(DEFAULT) " en vaut\n"
"cinq et un " COLOR(RED) "rouge" COLOR(DEFAULT) " en vaut vingt!\n"
"Hii hii hihi!"
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ce que propose cette boutique\n"
"se trouve dans la forêt!\n"
"Tii hii!" BOX_BREAK "Tu sais comment ça s'utilise un \n"
COLOR(RED) "Bouclier Mojo" COLOR(DEFAULT) ", hein, tu l'sais??" BOX_BREAK "Une fois acheté, appuie sur " COLOR(RED) "START\n"
COLOR(DEFAULT) "pour accéder aux sous-menus. \n"
"Sélectionne le " COLOR(BLUE) "sous-menu \n"
"Equipement " COLOR(DEFAULT) "avec " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "." BOX_BREAK "Dans le " COLOR(BLUE) "Sous-Menu Equipement" COLOR(DEFAULT) ", \n"
"choisis l'objet qui t'intéresse et \n"
"active-le avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Une fois ton bouclier prêt,\n"
"brandis-le avec " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " et change ton \n"
"angle de défense avec " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"Tii hii!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu savoir comment utiliser\n"
"le " COLOR(YELLOW) "bouton" COLOR(DEFAULT) " " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Appuie sur " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "pour changer de \n"
"vue." BOX_BREAK "Dans un endroit comme celui-ci, \n"
"tu activeras une vue du dessus. \n"
"Mais à l'extérieur tu activeras une\n"
"vue subjective." BOX_BREAK "Quand \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\" apparaît en haut de \n"
"l'écran, ta fée a quelque chose à\n"
"dire! Appuie alors sur " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "pour \n"
"l'écouter!"
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"C'est sûr, tu pourrais le découvrir\n"
"tout seul!"
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mouais...C'est pas exactement \n"
"comme ça, la chanson de Saria..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido est vraiment furieux!\n"
"Que lui est-il arrivé?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? Où tu vas?!" BOX_BREAK "Au château?\n"
"C'est quoi un château?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un Kokiri ne peut quitter la forêt!\n"
"On dit souvent: \n"
"\"Qui n'en sort, n'en meurt!\"" BOX_BREAK "...Comment ça?\n"
"Tu vas quitter la forêt?\n"
"Et notre proverbe?\n"
"T'en fais quoi?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé, " NAME "!\n"
"Qu'as-tu encore fait?!" BOX_BREAK UNSKIPPABLE "Le très vénérable Arbre Mojo...\n"
"Il est...mort...?" BOX_BREAK UNSKIPPABLE "Comment as-tu pu faire une chose \n"
"pareille?! Tout est de ta faute!!\n"
"Nous allons tous mourir à cause \n"
"de toi!!!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hé!!" QUICKTEXT_DISABLE "\n"
"Qu'est-ce que tu trafiques \n"
"chez moi?!"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", tu vas bien?" TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria et " NAME " seront \n"
"amis pour toujours."
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il est arrivé quelque chose au \n"
"très vénérable Arbre Mojo?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La forêt a changé... "
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", \n"
"vas-tu nous quitter?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si jamais tu perds ton bouclier, \n"
"reviens nous voir!"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\x80") "Mes frères sont tous d'accord...\n"
"Tu es le sosie de notre totem!" BOX_BREAK SFX("\x38\x80") "Accepte l'offrande de notre \n"
"communauté. Prends ces quelques \n"
COLOR(RED) "Bâtons" COLOR(DEFAULT) " " COLOR(RED) "Mojo" COLOR(DEFAULT) ". Tu pourras \n"
"aussi en transporter plus!" BOX_BREAK "Abracadabra!" BOX_BREAK SFX("\x38\x80") "Alakazaaaam!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Depuis la mort du très vénérable \n"
"Arbre Mojo de nombreux monstres\n"
"sont apparus dans la forêt...\n"
"J'ai très peur!"
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Un vent diabolique nous vient du \n"
"Temple de la forêt." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Saria" COLOR(DEFAULT) ", avant de partir, nous a dit:\n"
"\"Je dois aller voir ce qu'il se \n"
"passe là-bas!\"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le " COLOR(ADJUSTABLE) "Temple de la Forêt se trouve\n"
COLOR(DEFAULT) "près du Bosquet Sacré au fond \n"
"des Bois Perdus."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria est partie dans le temple, \n"
"mais elle n'en est jamais revenue..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé, m'sieur! Vous pouvez pas \n"
"utiliser un Bouclier Mojo!\n"
"C'est pour les gamins!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein? Où est Saria? \n"
"Vous la connaissez, Saria?\n"
"Heu...t'es un menteur, monsieur?" TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mais où est donc " COLOR(RED) "Mido" COLOR(DEFAULT) "... \n"
"On a besoin de lui par ces temps \n"
"difficiles!"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vous êtes entré dans la forêt \n"
"sans problème?" BOX_BREAK "Les monstres ne vous ont pas \n"
"attaqué? Du temps du Vénérable \n"
"Arbre Mojo, vous n'auriez pas vu \n"
"de pareilles nuisances dans le coin." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est super dangereux dehors!\n"
"Alors je reste cloîtré chez moi!\n"
"....j'm'ennuie..."
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les " COLOR(RED) "flèches" COLOR(DEFAULT) " ne sont que pour les\n"
"archers... Vous avez un " COLOR(RED) "arc" COLOR(DEFAULT) ", vous?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Avez-vous beaucoup voyagé, \n"
"monsieur?\n"
"Avez-vous déja rencontré un \n"
"garçon nommé " NAME "?" BOX_BREAK UNSKIPPABLE "Mido à raconté à tout le monde \n"
"que " NAME " a tué le\n"
"vénérable Arbre Mojo..." BOX_BREAK UNSKIPPABLE "Il n'y avait que Saria pour dire le \n"
"contraire!\n"
"Enfin...quand Saria était encore\n"
"parmi nous." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Qui peut savoir la vérité?"
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On s'connaît, monsieur?"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Monsieur, connaissez-vous un \n"
"garçon du nom de " NAME "?" BOX_BREAK UNSKIPPABLE "Il a quitté la forêt et n'est jamais\n"
"revenu..." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je me demande si " NAME "  \n"
"reviendra un jour..."
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Etre grand, c'est trop cool!\n"
"Je veux être une grosse brute \n"
"comme vous, m'sieur!" BOX_BREAK UNSKIPPABLE "I Je voudrais être très grand et \n"
"très fort pour me battre contre \n"
"les Pestes Mojo, mais...je ne suis\n"
"que petit et faible..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nous les Kokiris ne seront jamais \n"
"grands...\n"
"C'est vraiment pas drôle!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pourquoi une fée vous suit \n"
"partout? Vous n'êtes pourtant pas \n"
"un Kokiri!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mais qui êtes-vous? \n"
"Votre habit Kokiri ne marche pas!\n"
"Je ne suis pas né de la dernière\n"
"giboulée!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai promis à Saria de ne laisser \n"
"passer personne."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bonzour tout le monde! Ze suis le \n"
COLOR(RED) "Bourzeon de l'Arbre Mozo" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Comme tu as brizé la malédiction\n"
"du Temple de la Forêt, ze peux \n"
"croître et fleurir!" BOX_BREAK UNSKIPPABLE "Merzi beaucoup!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu as vu tes zanciens zamis?\n"
"Ze ne pense pas qu'ils te \n"
"reconnaissent avec ta grande \n"
"taille..." BOX_BREAK UNSKIPPABLE "C'est parze que les " COLOR(ADJUSTABLE) "Kokiris" COLOR(DEFAULT) " ne \n"
"grandissent zamais! Même après \n"
"sept ans, ils restent des zenfants!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu dois te demander alors \n"
"pourquoi tu as grandi!" BOX_BREAK UNSKIPPABLE "Bon, comme tu as dézà dû le \n"
"deviner, tu n'es pas vraiment un \n"
"Kokiri! Tu es zen fait " COLOR(LIGHTBLUE) "Hylien" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ze suis si content de te révéler\n"
"ce secret!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Il y a très longtemps, il y eut \n"
"une guerre terrible, avant même \n"
"que le roi Hyrule n'unifie ce pays." BOX_BREAK_DELAYED("\x5A") "Un zour, pour échapper à ce \n"
"conflit, une " COLOR(RED) "Maman Hylienne" COLOR(DEFAULT) " et son \n"
COLOR(RED) "Petit Bébé" COLOR(DEFAULT) " entrèrent dans cette \n"
"forêt interdite." BOX_BREAK_DELAYED("\x5A") "Cette pauvre maman était \n"
"gravement blessée. Son seul espoir\n"
"était de confier son bébé à l'Arbre\n"
"Mozo, l'esprit gardien de la forêt." BOX_BREAK_DELAYED("\x5A") "L'Arbre Mozo pouvait dézà sentir \n"
"le pouvoir de cet enfant dont la \n"
"destinée allait affecter le monde \n"
"entier. Ainsi fut-il adopté..." BOX_BREAK_DELAYED("\x5A") "Après la mort de sa pauvre \n"
"maman, il fut élevé comme un \n"
COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) ". Et désormais sa destinée\n"
"doit s'accomplir!" FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu es zun " COLOR(LIGHTBLUE) "Hylien" COLOR(DEFAULT) ", depuis \n"
"touzours ze savais que tu \n"
"devais quitter la forêt." BOX_BREAK UNSKIPPABLE "Tu connais ta propre destinée...\n"
"Tu sais ce qu'il te reste à \n"
"faire..." BOX_BREAK UNSKIPPABLE "Tu dois sauver Hyrule!" BOX_BREAK UNSKIPPABLE "Va, " NAME "... Dissipe la \n"
"malédiction zetée sur les temples\n"
"et rétablis paix et amour sur \n"
"Hyrule!!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x34") "Cette melodie?!" BOX_BREAK UNSKIPPABLE "Saria la jouait tout le temps!\n"
"Vous...connaissez Saria?" BOX_BREAK UNSKIPPABLE "Cette chanson..." BOX_BREAK UNSKIPPABLE "Saria ne l'a enseignée qu'à ses\n"
"amis..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je ne sais pas pourquoi, mais... \n"
"Vous me rappelez...l'autre..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Capturé dans l'enfer de ma \n"
"malédiction, assis sur le seuil de\n"
"la réalité et du rêve, il ne restera\n"
"de toi qu'un corps décharné!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Merci, merci beaucoup...\n"
"Grâce à toi, je m'éveille à la \n"
"conscience de Sage..." BOX_BREAK UNSKIPPABLE "Je suis " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"Sage du Temple de la Forêt..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x26") "Saria sera toujours...\n"
SHIFT("\x44") "Ton amie..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La course du temps est cruelle...\n"
"Sa vitesse est perçue différemment\n"
"par chacun, mais personne ne peut\n"
"la modifier..." BOX_BREAK UNSKIPPABLE "Seule la mémoire des jours \n"
"anciens n'est pas altérée..." BOX_BREAK UNSKIPPABLE "Pour revenir ici, joue le \n"
COLOR(ADJUSTABLE) "Menuet des bois" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...\n"
"A très bientôt..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria n'est pas encore revenue...\n"
"Mais je sais qu'elle reviendra \n"
"bientôt..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "OK...\n"
"Je te fais confiance." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...Je vois..." BOX_BREAK UNSKIPPABLE "Saria ne reviendra jamais..." BOX_BREAK UNSKIPPABLE "Mais...je...j'avais fait une promesse \n"
"à Saria..." BOX_BREAK UNSKIPPABLE "Si " NAME " revient un jour, \n"
"je voudrais lui dire que Saria \n"
"l'attend..." BOX_BREAK UNSKIPPABLE "Parce que " TEXT_SPEED("\x03") "Saria...aimait..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46") "Mais toi..." BOX_BREAK "Fais-lui le message...\n"
"S'il te plaît..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Apprends-moi à me battre comme\n"
"toi! Tout ce que je sais faire \n"
"c'est appuyer sur " COLOR(ADJUSTABLE) "[B]!\n"
COLOR(DEFAULT) "Haaa! Si j'avais lu les pancartes!"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vous ressemblez à quelqu'un que \n"
"je connais, monsieur."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vous êtes tellement fort! Un jour, \n"
"je serai comme vous! Même si je \n"
"reste un nabot toute ma vie."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... \n"
"Je me demande s'il reviendra\n"
"un jour..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai l'impression de vous connaître \n"
"depuis longtemps, monsieur!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le " COLOR(RED) "Bourgeon de l'Arbre Mojo \n"
COLOR(DEFAULT) "grandit paisiblement et la forêt\n"
"est de nouveau joyeuse!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nous assurerons tous ensemble la \n"
"protection de la forêt!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Un vent paisible commence à \n"
"souffler sur la forêt."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ce vent paisible fera sûrement\n"
"revenir " NAME " !"
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je me demande si Saria va revenir."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME " reviendra un jour!\n"
"C'est certain!"
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x1F")  COLOR(LIGHTBLUE) "Vénérable Arbre Mojo...\n"
COLOR(DEFAULT)  SHIFT("\x2D")  COLOR(LIGHTBLUE) "Je suis de retour!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "L'homme maléfique ne cesse de \n"
"faire appel à ses sombres et vils \n"
"pouvoirs pour trouver le Saint \n"
"Royaume relié à Hyrule..." BOX_BREAK UNSKIPPABLE "Car dans le Saint Royaume \n"
"sommeille la divine relique, la \n"
COLOR(LIGHTBLUE) "Triforce" COLOR(DEFAULT) ", renfermant des pouvoirs\n"
"comparables à ceux des dieux..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1A") "Avant le début du temps,\n"
SHIFT("\x2A") "avant que vie et \n"
SHIFT("\x2F") "esprit n'existent..." QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x07") "Trois déesses d'or et de lumière\n"
SHIFT("\x05") "descendirent sur l'amas chaotique\n"
SHIFT("\x1E") "qu'allait devenir Hyrule..." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1A") "Din, déesse de la Force..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Nayru, déesse de la Sagesse..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Farore, déesse du Courage..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F") "De ses bras enflammés,\n"
SHIFT("\x28") "elle sculpta le sol et\n"
SHIFT("\x29") "créa la terre rouge." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Elle inonda de sa sagesse la\n"
SHIFT("\x10") "terre et apporta ordre et loi\n"
SHIFT("\x3A") "sur ce monde." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0D") "De son âme infinie, elle donna\n"
SHIFT("\x0E") "vie aux êtres issus de l'ordre\n"
SHIFT("\x40") "et de la loi." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2B") "Les trois déesses, \n"
SHIFT("\x24") "leur oeuvre accomplie,\n"
SHIFT("\x06") "s'en retournèrent vers les cieux." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Leur départ fit alors apparaître\n"
SHIFT("\x2D") "trois triangles d'or,\n"
SHIFT("\x0C") "seuls vestiges de leur pouvoir." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Depuis, les triangles sacrés\n"
SHIFT("\x1B") "symbolisent l'essence de \n"
SHIFT("\x38") "notre création." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2F") "Et depuis ce jour,\n"
SHIFT("\x06") "Le Saint Royaume est le berceau\n"
SHIFT("\x1E") "des triangles de justice." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors moucheron... Tu as appris à\n"
"combattre! Tu revendiques le sang\n"
"des guerriers..." BOX_BREAK_DELAYED("\x3C") "Tu n'as vaincu que mon faible\n"
"spectre... Quand l'heure de \n"
"l'affrontement sonnera, l'ombre du\n"
"trépas sera sur toi." BOX_BREAK_DELAYED("\x3C") "Ce fantôme était une création \n"
"pitoyable, je vais le bannir par-delà\n"
"les seuils dimensionnels!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "J'ai toujours su que tu reviendrais.\n"
"Je le savais, je te connais bien..." BOX_BREAK UNSKIPPABLE "Non..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "Tu n'as pas besoin de te justifier\n"
"devant moi..." BOX_BREAK UNSKIPPABLE "Le destin n'a pas voulu que nous\n"
"vivions dans le même monde."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "En temps que Sage de la forêt, \n"
"ma place est ici..." BOX_BREAK UNSKIPPABLE "Tiens... Prends ce " COLOR(ADJUSTABLE) "Médaillon" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu as fait preuve de courage\n"
"et de sagesse..." BOX_BREAK UNSKIPPABLE "Tu te révèles digne de mon estime\n"
"et de ma confiance..."
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"J'ai encore bien des choses à te\n"
"dire veux-tu bien les écouter?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...\n"
"Va au Château d'Hyrule..." BOX_BREAK UNSKIPPABLE "Tu y rencontreras la \n"
COLOR(RED) "Princesse de la Destinée" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Prends cette " COLOR(RED) "Pierre" COLOR(DEFAULT) "...\n"
"Elle est la cause de la malédiction\n"
"jetée sur moi par l'homme sombre."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "J'ai toujours su qu'un jour...\n"
"Tu quitterais la forêt,\n"
NAME "..." BOX_BREAK UNSKIPPABLE "Car tu es différent de nous..."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE) "Hé, " QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "!\n"
"Debout! Maintenant!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Le très " COLOR(RED) "vénérable Arbre Mojo \n"
COLOR(LIGHTBLUE) "veut te parler!\n"
"Réveille-toi, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  QUICKTEXT_ENABLE "Ho!" QUICKTEXT_DISABLE " Tu vas te lever, oui?" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "La destinée d'Hyrule repose-t-elle \n"
"sur un garçon aussi paresseux?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sauter, c'est plus à la mode. \n"
"Moi j'fais des " COLOR(RED) "sauts périlleux" COLOR(DEFAULT) "!\n"
"Tu sais en faire un, toi?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Le très " COLOR(RED) "vénérable Arbre Mojo " COLOR(LIGHTBLUE) "\n"
"veut te parler!\n"
"Allons-y tout de suite!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x4B") "Navi...\n"
SHIFT("\x37") "Navi, où es-tu?\n"
SHIFT("\x3C") "Viens à moi..."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi la fée" COLOR(DEFAULT) "...\n"
"Ecoute mes paroles, les paroles du\n"
"très vénérable" COLOR(RED) " Arbre Mojo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Sens-tu le danger qui rôde?\n"
"Cette aura ténébreuse qui s'abat \n"
"sur le royaume..." BOX_BREAK UNSKIPPABLE "Des forces maléfiques s'activent\n"
"dans l'ombre et préparent l'invasion\n"
"d'Hyrule..." BOX_BREAK UNSKIPPABLE "Depuis toujours la " COLOR(RED) "Forêt Kokiri" COLOR(DEFAULT) "\n"
"s'élève comme un rempart contre \n"
"les forces chaotiques, assurant le\n"
"maintien de l'ordre et de la loi..." BOX_BREAK UNSKIPPABLE "Mais face à ce pouvoir terrifiant\n"
"et infernal, mes forces ne sont\n"
"que misère..." BOX_BREAK UNSKIPPABLE "Le temps est venu pour ce " COLOR(RED) "garçon \n"
"sans fée " COLOR(DEFAULT) "de commencer son \n"
"périple..." BOX_BREAK UNSKIPPABLE "Cet enfant dont la destinée est\n"
"de conduire Hyrule sur la voie de \n"
"la justice et de la vérité..." BOX_BREAK UNSKIPPABLE "Va... " COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "! Trouve notre jeune ami \n"
"et présente-le devant moi..." BOX_BREAK UNSKIPPABLE "Il ne me reste que peu de temps." BOX_BREAK UNSKIPPABLE "Vole, Navi, vole! Le destin de la \n"
"forêt, que dis-je, du monde dépend\n"
"de toi!!!"
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Pitié, Seigneur! Je ne le ferai \n"
"plus jamais! Epargne-moi et je te \n"
"donne un indice." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Tu ne pourras jamais battre mes \n"
"frères si tu ne respectes pas un\n"
"ordre précis!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Le bon ordre est..." TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) "2 - 3 - 1!" COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Vingt-trois est numéro un! Ha ha!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Tu crois que j'suis un traître?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Qui t'a donné notre secret?!\n"
"Hmmm... " QUICKTEXT_ENABLE "ça me rend dingue!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "J'suis tellement en pétard que je \n"
"vais te dire le point faible de \n"
COLOR(RED) "Gohma notre Reine" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Pour lui administrer le coup de \n"
"grâce, frappe son oeil avec ton \n"
"épée après l'avoir " COLOR(RED) "étourdie" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Oh ma Reine, ma p'tite Reine..." BOX_BREAK SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x1B") "Je ne suis qu'un traître!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"Dans l'immense forêt d'Hyrule..." BOX_BREAK_DELAYED("\x28")  SHIFT("\x0B") "Les siècles m'ont choisi comme\n"
SHIFT("\x0F") "le gardien spirituel des bois...\n"
SHIFT("\x1F") "Je suis... l'Arbre Mojo..." FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0F") "Les Kokiris sont mes enfants.\n"
SHIFT("\x0F") "Ils sont le peuple de la forêt." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0A") "Dès la naissance, chaque Kokiri\n"
SHIFT("\x3C") "reçoit sa fée." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "Mais seul un jeune garçon\n"
SHIFT("\x2A") "n'avait pas de fée..." FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Je me rends, c'est bon! En \n"
"échange je veux bien te vendre \n"
"des Noix Mojo!\n"
COLOR(RED) "5 unités   20 Rubis" COLOR(DEFAULT) ", c'est le prix!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "T'es le plus fort! Je vais\n"
"te vendre des Bâtons Mojo, tiens!\n"
COLOR(RED) "1 unité   15 Rubis, " COLOR(DEFAULT) "t'en veux?" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "J'abandonne! Tu veux bien \n"
"m'acheter des coeurs?\n"
COLOR(RED) "1 unité   10 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Alors...ça marche?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Non, jamais!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "GLOPS!!" QUICKTEXT_DISABLE "\n"
"J'me rentre, si c'est comme ça!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Pas assez de rubis!\n"
"Reviens plus tard!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "T'en as plein tes poches!\n"
"reviens plus tard!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x41") "Merci bien!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je t'attendais,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Nous sommes ici dans le " COLOR(RED) "Bosquet \n"
"Sacré" COLOR(DEFAULT) ". C'est mon jardin secret!\n"
"J'ai le sentiment que..." BOX_BREAK UNSKIPPABLE "Cet endroit sera très important \n"
"pour nous deux. J'en suis sûre!" BOX_BREAK UNSKIPPABLE "Joue de l'ocarina ici et tu pourras\n"
"parler avec les esprits de la forêt." TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu jouer de l'ocarina \n"
"avec moi?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Essaie de suivre cette mélodie.\n"
"Tu es prêt?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Heu?!\n"
"T'es pas drôle!\n"
"Allez! Jouons ensemble!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x3A") "Bravo! Bravo!" BOX_BREAK UNSKIPPABLE "N'oublie jamais cette mélodie!\n"
"Tu me le promets?" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Entonne le " COLOR(ADJUSTABLE) "Chant de Saria " COLOR(DEFAULT) "si tu \n"
"as besoin de me parler..."
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prends-tu bien soin de mon \n"
"ocarina?"
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x38\x80") "Whoaa!\n"
"Tu es très fort!\n"
"Trois fois dans le mille!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Je me sens obligé de t'offrir\n"
"un cadeau! Prends donc ceci!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"S'il y a quelqu'un pour savoir ce\n"
"que fait Saria, c'est bien Mido!" BOX_BREAK "Il est sûrement dans le coin."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT)  SHIFT("\x15")  COLOR(LIGHTBLUE) "Pas de réponse. Il doit dormir." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Un P'tit Poulet?  Comment ça?\n"
"Seul un chic type comme moi peut\n"
"s'en occuper..." BOX_BREAK UNSKIPPABLE "Ce qui veut dire que..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x01") "Toi... " TEXT_SPEED("\x00") "Toi aussi, tu es un chic type!\n"
QUICKTEXT_ENABLE "Incroyable!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Un chic type! Un vrai!" QUICKTEXT_DISABLE "\n"
"Oh, je t'en supplie..." BOX_BREAK UNSKIPPABLE "Apporte ceci à l'" COLOR(RED) "Apothicaire" COLOR(DEFAULT) " du\n"
"village Cocorico!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dépêche-toi sinon ceci va pourrir!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"J'peux pas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha bon. " QUICKTEXT_ENABLE "Tu l'prends comme ça?" QUICKTEXT_DISABLE "\n"
"T'es pas si chic que ça, alors!!\n"
QUICKTEXT_ENABLE "Dégage!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria te cherchait...\n"
"L'as-tu vue?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grouille-toi, mon nouveau copain!\n"
"Apporte-le à la vieille peau, avant \n"
"qu'il ne soit trop tard..."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Le garçon n'est plus ici." BOX_BREAK UNSKIPPABLE "Un Hylien perdu dans la forêt est\n"
"un Hylien de moins! (proverbe)" BOX_BREAK UNSKIPPABLE "Un Hylien perdu dans la forêt \n"
"devient un monstre......\n"
"Il ne reste que sa scie. Hii hii." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La mixture est à base de champi-\n"
"gnons. Voulez-vous la rendre?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi hi!\n"
"Vas-tu te transformer en monstre,\n"
"toi aussi?"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Nous vendons des boucliers, mais\n"
"pas d'épées!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu connais le " COLOR(ADJUSTABLE) "Chant de Saria" COLOR(DEFAULT) "! \n"
"Alors soyons amis! \n"
"Tiens, prends donc ceci!"
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Salut! Ne trouves-tu pas que mon\n"
"visage n'a rien d'extraordinaire?\n"
"J'aimerais avoir du style..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Reviens jouer quand tu veux!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Accompagne-nous avec ton ocarina. \n"
"Nous allons te donner le rythme."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quelle belle prestation!\n"
"En gage de notre amitié, \n"
"accepte donc ceci."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hé ho! Par ici!\n"
"Hou hou!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME "... \n"
"Quel plaisir de te voir! \n"
"Ecoute donc mes sages paroles!\n"
"Hou hou...." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Après avoir traversé les Bois \n"
"Perdus tu arriveras au " COLOR(ADJUSTABLE) "Bosquet\n"
"Sacré" COLOR(DEFAULT) "." BOX_BREAK "Ce saint domaine ne fut exploré\n"
"que par très peu d'aventuriers." BOX_BREAK "Chuuut... Ecoute...\n"
"J'entends un chant mystérieux..." BOX_BREAK "Tu devrais tendre l'oreille à\n"
"ton tour! Hou hou hou!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu que je répète tout ça?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Sois courageux et la forêt ne\n"
"te posera pas de problèmes..." BOX_BREAK UNSKIPPABLE "Fais confiance à tes oreilles,\n"
"dirige-toi grâce aux sons de \n"
"la forêt! Hou hou!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hou hou!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Saria t'a-t-elle appris une chanson?" BOX_BREAK UNSKIPPABLE "Cette mélodie semble avoir de \n"
"mystérieux pouvoirs." BOX_BREAK UNSKIPPABLE "Tu apprendras sûrement d'autres \n"
"chants au gré de ton périple..." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Utilise ton ocarina avec les \n"
"boutons " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " au bon endroit et une \n"
COLOR(RED) "portée " COLOR(DEFAULT) "apparaîtra." BOX_BREAK "Je te conseille alors de jouer un \n"
"chant que tu connais." BOX_BREAK "Je te conseille aussi de jouer\n"
"même si la portée n'apparaît pas.\n"
"Comme ça:\n"
"Hou hou hou hout hout hout!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu que je répète tout ça?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Les mélodies que tu apprendras\n"
"seront enregistrées dans le \n"
COLOR(LIGHTBLUE) "Sous-Menu du Statut" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ohh...Le vilain! Je ne sais \n"
"pas pourquoi il est si méchant\n"
"avec tout le monde!" BOX_BREAK UNSKIPPABLE "Même s'il a raison cette fois-ci!" TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Il se passe des choses étranges \n"
"dans la forêt..." BOX_BREAK UNSKIPPABLE "Sois prêt à tout!\n"
"Tu ferais mieux de te trouver une \n"
"arme!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Paix! Gentil! T'as gagné! \n"
"Veux-tu des " COLOR(RED) "Graines Mojo" COLOR(DEFAULT) "?\n"
COLOR(RED) "30 unités   40 Rubis, " COLOR(DEFAULT) "pas cher!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "J'me rends! Laisse-moi partir et \n"
"je te vends un Bouclier Mojo pour\n"
COLOR(RED) "50 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "J'abandonne! Veux-tu des " COLOR(RED) "bombes" COLOR(DEFAULT) "?\n"
COLOR(RED) "5 unités   40 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "C'est bon! Laisse-moi tranquille\n"
"et je te vends des " COLOR(RED) "flèches" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 unités   70 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "T'as gagné! Epargne-moi et je te\n"
"vends une " COLOR(RED) "potion rouge" COLOR(DEFAULT) " pour \n"
COLOR(RED) "40 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "T'as gagné! Epargne-moi et je te \n"
"vends une " COLOR(ADJUSTABLE) "potion verte" COLOR(DEFAULT) " pour \n"
COLOR(RED) "40 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quoi?!? Tu as une fée?!\n"
"Comment? Le Vénérable Arbre \n"
"Mojo t'a convoqué?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x33") "Heiiiiinnnnnnnn?!" BOX_BREAK UNSKIPPABLE "Et pourquoi j'suis pas \n"
"convoqué, moi le grand " COLOR(RED) "Mido" COLOR(DEFAULT) "? " BOX_BREAK UNSKIPPABLE "C'est pas juste..." BOX_BREAK UNSKIPPABLE "J'te crois pas!\n"
"Tu n'es même pas équipé!" BOX_BREAK UNSKIPPABLE "Comment pourrais-tu aider le \n"
"Vénérable Arbre Mojo sans " COLOR(ADJUSTABLE) "épée" COLOR(DEFAULT) " \n"
"ni " COLOR(LIGHTBLUE) "bouclier" COLOR(DEFAULT) ", hein!?" BOX_BREAK "Quoi? \n"
"Ok, mon équipement non plus n'est\n"
"pas prêt mais...\n"
"Et puis de quoi j'me mêle?" TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x24") "Heu... C'est quoi ça?!" BOX_BREAK UNSKIPPABLE "Oh! Tu as un " COLOR(LIGHTBLUE) "Bouclier" COLOR(DEFAULT) " " COLOR(LIGHTBLUE) "Mojo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Et pis ça c'est quoi?!" BOX_BREAK UNSKIPPABLE "Mais... C'est l'" COLOR(ADJUSTABLE) "Epée" COLOR(DEFAULT) " " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) "!?" BOX_BREAK UNSKIPPABLE  SHIFT("\x30") "BEN CA ALORS!!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Enfin... Même avec tout ça,\n"
"une mauviette est toujours une \n"
"mauviette, hein?" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Houlà! Doucement! J'ai perdu mais\n"
"je peux te vendre des \n"
COLOR(RED) "Bâtons" COLOR(DEFAULT) " " COLOR(RED) "Mojo " COLOR(DEFAULT) "pour " COLOR(RED) "15 Rubis" COLOR(DEFAULT) "." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Perdu! Dommage pour moi! \n"
"Veux-tu des " COLOR(RED) "Noix" COLOR(DEFAULT) " " COLOR(RED) "Mojo" COLOR(DEFAULT) "?\n"
COLOR(RED) "5 unités   20 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Et aussi..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3A") "Dis-lui aussi..." QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x32") "Que je m'excuse."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hii hii hii!\n"
"Tu es arrivé jusqu'ici tout seul? \n"
"Comme un grand?\n"
"T'es un homme, un vrai de vrai!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Regarde! Belle vue, non?\n"
"Tu peux changer ton angle de vue \n"
"avec " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " et ainsi admirer la forêt \n"
"avec " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Qu'as-tu fait au très vénérable \n"
"Arbre Mojo?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Avant d'aller dans les Bois Perdus, \n"
"il te faudra d'abord te trouver le \n"
"bon équipement!\n"
"Hii hii!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\x82") "Tous mes frères sont d'accord: \n"
"Ta face est trop moche..." BOX_BREAK SFX("\x38\x82") "Mais ne pleure pas! \n"
"On va te donner des " COLOR(RED) "Noix Mojo" COLOR(DEFAULT) "." BOX_BREAK SFX("\x38\x82") "Nous allons aussi te donner le \n"
"pouvoir d'en porter plus!" BOX_BREAK "Abracadabra..." BOX_BREAK SFX("\x38\x80") "Alakazaaaam!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "J'me rends!" BOX_BREAK SFX("\x38\x80") "Pour faciliter ta quête, je peux\n"
"te donner le pouvoir de porter \n"
"plus de " COLOR(RED) "Bâtons Mojo" COLOR(DEFAULT) "!\n"
"Cela te coûtera " COLOR(RED) "40 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "J'me rends!" BOX_BREAK SFX("\x38\x80") "Pour faciliter ta quête, je peux\n"
"te donner le pouvoir de porter \n"
"plus de " COLOR(RED) "Noix" COLOR(DEFAULT) " " COLOR(RED) "Mojo" COLOR(DEFAULT) "!\n"
"Cela te coûtera " COLOR(RED) "40 Rubis" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Yaaaa! Dommage! \n"
"Pas d'argent, pas d'amis!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le garçon n'est plus ici." BOX_BREAK "Un Hylien dans la forêt est un\n"
"Hylien de moins. (proverbe)" BOX_BREAK "Il est devenu un monstre.\n"
"Comme tous les autres."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Merci encore pour l'autre jour...\n"
"Au fait...\n"
"Je ne connais même pas ton nom!" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Vraiment?\n"
NAME "!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "J'en étais sûre!" QUICKTEXT_DISABLE "\n"
"Tu es le garçon de la forêt! \n"
"Cela fait si longtemps!\n"
"Tu te souviens de moi?" BOX_BREAK UNSKIPPABLE "Oui? J'étais certaine de t'avoir\n"
"déjà rencontré quand Epona est \n"
"venue vers toi!" BOX_BREAK UNSKIPPABLE "Oh, au fait... Je dois te parler de\n"
COLOR(RED) "Monsieur Ingo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Il craignait que le Roi Sombre\n"
"n'apprenne qu'Epona a disparu...\n"
"Il était si préoccupé!" BOX_BREAK UNSKIPPABLE "Mais un beau jour, sans crier gare,\n"
"il redevint un " COLOR(RED) "homme gentil" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Mon père est maintenant de \n"
"retour au Ranch...\n"
"C'est incroyable, la paix est \n"
"revenue!" BOX_BREAK UNSKIPPABLE "Et tout ça grâce à toi!\n"
"Je te suis si reconnaissante!" BOX_BREAK UNSKIPPABLE "Merci infiniment,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Comment se porte " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK "Si tu joues le " COLOR(RED) "Chant d'Epona" COLOR(DEFAULT) " avec \n"
"ton ocarina, elle viendra vers toi." BOX_BREAK "Reviens vite au Ranch si tu veux\n"
COLOR(RED) "entraîner " COLOR(DEFAULT) "Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "est en pleine forme!\n"
"On dirait que tu as réussi à la \n"
"dompter, toi aussi!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pourquoi ne pas mettre tes talents\n"
"de cavalier à l'épreuve avec une\n"
"petite " COLOR(RED) "course d'obstacle" COLOR(DEFAULT) "?" BOX_BREAK "Je relèverai ton temps pour \n"
COLOR(RED) "deux tours" COLOR(DEFAULT) ". Tu perdras si tu ne \n"
"sautes pas toutes les barrières\n"
"dans le bon ordre." BOX_BREAK "Qu'en dis-tu?\n"
"Tu veux tenter ta chance? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "C'est parti!\n"
"Pas question" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ton temps est de " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ".\n"
"Il te faut plus d'entraînement!" BOX_BREAK "Souviens-toi bien: tu n'as besoin\n"
"d'accélérer que pour sauter de\n"
"grandes barrières!"
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x09")  NAME "... M'entends-tu?\n"
SHIFT("\x30") "C'est moi...Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Meuuuuuuu!" BOX_BREAK "Quel chant mélooooodieux...\n"
"Il me rappelle les verts pâturages\n"
"de ma jeuuuuunesse..." BOX_BREAK "Je me sens si repooooosée!" EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prends donc un peu de mooooon \n"
"déliceuuuuux lait!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME ", quand tu trouveras\n"
"cet ocarina..." BOX_BREAK_DELAYED("\x3C") "Je serai déjà si loin..." BOX_BREAK_DELAYED("\x3C") "Malgré mes efforts, je n'ai pu \n"
"retarder ma fuite..." BOX_BREAK_DELAYED("\x3C") "Je ne peux t'offrir que cet\n"
"ocarina ainsi que " COLOR(LIGHTBLUE) "cette melodie" COLOR(DEFAULT) "..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Va, " NAME ".\n"
"Entonne ce chant devant l'autel du\n"
"Temple du Temps.\n"
"Tu dois protéger la Triforce!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha-hah! Alors comme ça \n"
"on s'déguise, p'tite tête?" BOX_BREAK UNSKIPPABLE  SHIFT("\x57") "Oh?" BOX_BREAK UNSKIPPABLE "N'est-ce pas un Masque du... \n"
"Comment déjà...putois? Non...\n"
"Du Renard?" BOX_BREAK UNSKIPPABLE "Mon gamin en est marteau!\n"
"Tu veux bien me le vendre alors \n"
"ce \"Masque du...truc...bidule...\"?\n"
"Allez, sois chic." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Marché conclu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je ne lâcherai pas le morceau!\n"
"J'ai de la patience, tu sais!\n"
"Il en faut pour faire un boulot \n"
"comme le mien!  Hah hah hah!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mmmm...(baille)...quoi?...\n"
"Hein? Ouais, ouais. J'suis réveillé!" BOX_BREAK UNSKIPPABLE "Comment?" BOX_BREAK UNSKIPPABLE "Hé, c'est toi? Bien le bonjour!" BOX_BREAK UNSKIPPABLE "Quelle histoire!\n"
"Malon n'a pas arrêté de me crier\n"
"dessus!" BOX_BREAK UNSKIPPABLE "Tu nous as bien aidés...\n"
"Je suis fier de t'offrir ce " COLOR(RED) "lait" COLOR(DEFAULT) "!\n"
"Tu peux garder la bouteille."
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Au-delà de cette limite, la " COLOR(RED) "route \n"
"est fermée" COLOR(DEFAULT) "!\n"
"N'as-tu pas lu la pancarte,\n"
"là-bas?" BOX_BREAK "Ah, je vois. Tu n'es qu'un gamin et\n"
"tu ne sais pas encore lire, hein?\n"
"Tu t'paies ma tête?"
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'en veux pas d'ce machin!"
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, n'est-ce pas...\n"
"Mais si! C'est l'écriture de la\n"
"Princesse Zelda! Voyons voir..." BOX_BREAK UNSKIPPABLE  SHIFT("\x06") "\"" COLOR(PURPLE) "Ce preux chevalier se nomme\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE)  NAME "...\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "Sa noble quête est de sauver \n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "Hyrule." COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "Wah ha ha ha ha!\n"
"C'est quoi cette histoire?\n"
"Encore un jeu de la Princesse!" BOX_BREAK UNSKIPPABLE "OK, OK, très bien. Je te laisse\n"
"passer... Sois quand même prudent,\n"
"Preux Chevalier! Wah hah ha ha!" EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, le Preux Chevalier!\n"
"Merci de sauver Hyrule!\n"
TEXT_SPEED("\x01") "Wah ha ha hah" TEXT_SPEED("\x00") "!!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Woah! Génial!\n"
"Ton temps est de " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) "!\n"
"Toi et Epona êtes faits l'un pour\n"
"l'autre!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ooooooh, quel doooommage.\n"
"Si tu avais une bouteille, j'aurais \n"
"pu t'offrir un peu de lait..." EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mon nom est " COLOR(RED) "Ingo" COLOR(DEFAULT) "--Monsieur Ingo.\n"
"Je prends soin des chevaux.\n"
"J'ai du boulot... Dégage!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Au fait, Preux Chevalier..." BOX_BREAK UNSKIPPABLE "Si tu comptes t'attaquer au\n"
"Sommet du Péril, équipe-toi du bon\n"
COLOR(LIGHTBLUE) "bouclier" COLOR(DEFAULT) "! \n"
"Ce volcan est en activité!" BOX_BREAK UNSKIPPABLE "Si tu retournes au marché,\n"
"va au Bazar. Ils auront un bouclier\n"
"pour toi!" BOX_BREAK UNSKIPPABLE "Dis bien que tu viens de ma part,\n"
"ils te feront un prix!" BOX_BREAK UNSKIPPABLE "En échange, j'aimerais que tu me\n"
"rendes un p'tit service...\n"
"Tu n'es pas obligé, mais...\n"
"On ne sait jamais!" BOX_BREAK UNSKIPPABLE "Es-tu déjà allé à la " COLOR(RED) "Foire aux \n"
"Masques" COLOR(DEFAULT) " sur la place du marché?\n"
"Tout le monde en parle!" BOX_BREAK UNSKIPPABLE "Mon gamin veut absolument un\n"
"masque à la mode mais je n'ai pas\n"
"le temps de m'y rendre..." BOX_BREAK UNSKIPPABLE "Pourrais-tu y aller pour moi?\n"
"Encore une fois, rien ne t'oblige\n"
"à me rendre ce service..." BOX_BREAK UNSKIPPABLE "Mon boulot est vraiment nul." BOX_BREAK UNSKIPPABLE  SHIFT("\x4B") "...pfff..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'aimerais tant pouvoir me rendre \n"
"à la " COLOR(RED) "Foire aux Masques " COLOR(DEFAULT) "..." BOX_BREAK SHIFT("\x4B") "...pfff..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Il est bel et bien mort..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x10") "Tssss...!" QUICKTEXT_DISABLE " Elle s'est échappée!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x41") "Toi, là-bas!\n"
SHIFT("\x41")  QUICKTEXT_ENABLE "Moucheron!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x43")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1A") "Tu cherches le contact?!\n"
SHIFT("\x3C") "Bonne blague!\n"
SHIFT("\x1C") "Tu es brave, mais sot!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x34") "Insecte ridicule!" QUICKTEXT_DISABLE "\n"
SHIFT("\x19") "Sais-tu bien qui je suis?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D") "Je suis " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x04") "Et sous peu, le monde sera mien!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x03") "Un destrier blanc vient de passer\n"
SHIFT("\x2E") "il y a un instant...\n"
SHIFT("\x26") "Par où s'est-il enfui?\n"
SHIFT("\x46")  QUICKTEXT_ENABLE "Réponds!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tsss... Bientôt je te ficherai\n"
"tout ça dehors."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon gamin sera fou de joie!\n"
"Tu es vraiment un Preux Chevalier!\n"
"Wha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "Vous vendez le masque pour\n"
COLOR(RED) "15 Rubis" COLOR(DEFAULT) ". Vous gardez les\n"
"bénéfices." BOX_BREAK UNSKIPPABLE "Retournons à la Foire aux Masques\n"
"pour rendre les " COLOR(RED) "10 Rubis" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"\"" COLOR(RED) "l'Excursion du fossoyeur" COLOR(DEFAULT) "\" est \n"
"interdite aux enfants." BOX_BREAK "Alors je me balade dans le\n"
"cimetière en imitant Igor le\n"
"fossoyeur." BOX_BREAK "Mais avec mon visage d'ange,\n"
"je ne suis pas aussi terrifiant que\n"
"ça, hein?"
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gyaah!" QUICKTEXT_DISABLE " C'est Igor le fossoyeur!" BOX_BREAK SHIFT("\x57") "???" BOX_BREAK "Oh, c'est juste un masque. \n"
"Il m'a fait une de ces frousses...\n"
"Mais je l'adore!" BOX_BREAK "Peux-tu me le donner?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai de l'argent tu sais..."
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hop là! C'est fini, mon ami!\n"
"Tu n'as payé que 10 Rubis!\n"
"Tu t'es suffisamment amusé!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je vais être une terreur avec ce \n"
"masque! Comme Igor, mon idole! \n"
"Voilà mes sous!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "Vous vendez le masque à l'enfant\n"
"au prix fort! Quel arnaqueur vous \n"
"faites!" BOX_BREAK UNSKIPPABLE "Retournons à la Foire aux Masques\n"
"rendre les " COLOR(RED) "30 Rubis" COLOR(DEFAULT) ". \n"
"Vous y trouverez aussi un nouveau\n"
"modèle!"
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je vais creuser et creuser!\n"
"Tout comme Igor!!"
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Du temps jadis, force lapins \n"
"gambadaient de-ci de-là sur la\n"
"noble Plaine d'Hyrule. \n"
"Enfin, avant qu'on les bouffe tous!" BOX_BREAK "Je veux être un lapin.\n"
"Un gentil lapinou.\n"
"Qui court, qui saute et tout ça..." BOX_BREAK "Je donnerais n'importe quoi pour \n"
"me mettre des oreilles de lapinou\n"
"sur la tête." BOX_BREAK "Un lapin tout mimi...\n"
"C'est le lapinou gentil!"
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh.... Quelle jolies oreilles de...\n"
QUICKTEXT_ENABLE "LAPIN???" QUICKTEXT_DISABLE "\n"
"Sont-ce de véritables oreilles de\n"
"lapinou tout mimi et tout poilu?" TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ton prix sera le mien!!!\n"
"Je les veux. MAINTENANT!!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mauvaise réponse.\n"
"Je les veux. Je les veux.\n"
"Je les veux. Je les veux.\n"
"Je les veux. Je les veux."
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Enfin... Mon rêve se réalise.\n"
"Je suis un petit lapin.\n"
"Tout mimi. Tout gentil.\n"
"Je cours et je saute. Youki!" EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "Ce masque à 50 rubis a été\n"
"vendu à un prix incroyable!" BOX_BREAK UNSKIPPABLE "Retournez à la Foire aux Masques\n"
"rendre les " COLOR(RED) "50 Rubis" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x10") "Tu crois que ton silence les \n"
SHIFT("\x12") "protègera? Jeune impudent..."
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "On dit à Cocorico que j'ai fichu\n"
"Talon à la porte du Ranch..." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E") "C'est du n'importe quoi!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ce vieux crétin était inutile!\n"
"Moi, " COLOR(RED) "Ingo " COLOR(DEFAULT) "le travailleur, me suis \n"
"dévoué entièrement à ce Ranch!" BOX_BREAK UNSKIPPABLE "Alors fais gaffe à tes paroles!\n"
"Je n'aime pas trop les rigolos \n"
"dans ton genre qui racontent \n"
"n'importe quoi sur moi!" BOX_BREAK UNSKIPPABLE "Le " COLOR(RED) "grand Ganondorf " COLOR(DEFAULT) "a reconnu mes\n"
"talents et m'a fait don de ce \n"
"Ranch! Ca te la coupe, hein?" BOX_BREAK UNSKIPPABLE "Je vais dresser un cheval \n"
"d'exception et le grand Ganondorf\n"
"sera ravi de mes services!" BOX_BREAK UNSKIPPABLE "Au fait, mon ami, que dirais-tu de\n"
"monter l'un de mes chevaux?" TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Donne-moi " COLOR(RED) "10 Rubis " COLOR(DEFAULT) "et tu pourras\n"
"monter un de mes chevaux.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors... Hors de ma vue, microbe!"
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu n'as pas assez d'argent!\n"
"Va bosser un peu et reviens me\n"
"voir!"
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu savoir comment monter?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Place-toi près du flanc du cheval \n"
"et appuie sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour le monter." BOX_BREAK "Utilise le " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "pour le faire galoper.\n"
"Pendant sa course, appuie sur\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour le cravacher. \n"
"Il ira beaucoup plus vite!" BOX_BREAK "Pour sauter par-dessus un \n"
"obstacle, fais galoper ta monture\n"
"le plus vite possible!" BOX_BREAK "Attention: un cheval est parfois\n"
"capricieux! Il ne sautera pas si\n"
"l'angle de saut ne lui plaît pas." BOX_BREAK "Fais arrêter le cheval puis appuie\n"
"sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour mettre pied à terre.\n"
"Et maintenant va t'amuser!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Utilise la " COLOR(LIGHTBLUE) "Visée [Z] " COLOR(DEFAULT) "pour parler \n"
"tout en montant ton cheval." BOX_BREAK "Veux-tu t'arrêter maintenant?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Non, je veux encore monter\n"
"Oui, j'en ai marre" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pour mettre pied à terre, \n"
"arrête-toi puis appuie sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Dis-moi jeune homme, on ne se\n"
"connaîtrait pas, par hasard?\n"
"J'ai l'impression de t'avoir déjà\n"
"vu quelque part..." TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu t'améliores!\n"
"Ca te dit une petite course\n"
"contre moi? Le premier à faire le\n"
"tour de l'enclos a gagné." BOX_BREAK "Paie-moi " COLOR(RED) "50 Rubis " COLOR(DEFAULT) "et c'est parti!\n"
"Tu es d'accord?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé...\n"
"Tu n'as même pas 50 Rubis?!\n"
"Je ne fais pas la course contre \n"
"un clochard!"
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x3C") "Nooooooooon!" BOX_BREAK UNSKIPPABLE "Si le grand Ganondorf apprend\n"
"cette infâmie...\n"
"Hé, toi!!  On refait la course!\n"
"Et si tu gagnes cette fois encore..." BOX_BREAK UNSKIPPABLE "Tu pourras garder...le cheval!!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Yaaaah!!! Quelle est cette jument?\n"
"Est-ce " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Comment as-tu pu dresser cet \n"
"animal sauvage???" BOX_BREAK UNSKIPPABLE "Cette jument était destinée au \n"
"grand Ganondorf... Mais je l'ai \n"
"pariée et perdue! Noooooooon!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x36") "Hah ha hah!" BOX_BREAK UNSKIPPABLE "Comme promis, \n"
"tu peux garder le cheval." BOX_BREAK UNSKIPPABLE  SHIFT("\x3C") "Cependant..." BOX_BREAK UNSKIPPABLE "Tu ne sortiras jamais de ce Ranch!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé hé hé... Dommage, petit!\n"
"Je garde tes 50 Rubis." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah ha hah!\n"
"Tu n'es qu'un débutant, après tout!\n"
"Reviens quand tu veux pour te \n"
"faire ridiculiser..."
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Huh? Que fais-tu là? \n"
"Sale môme, va!" BOX_BREAK UNSKIPPABLE "Mon nom est " COLOR(RED) "Ingo " COLOR(DEFAULT) "et je m'occupe\n"
"du ranch." BOX_BREAK UNSKIPPABLE "Je travaille pour ce crétin de\n"
"Talon depuis très longtemps. \n"
"Trop longtemps.\n"
"Il ne fait rien de toute la journée!" BOX_BREAK UNSKIPPABLE "Aujourd'hui, par exemple, il est \n"
"parti faire une livraison et...\n"
"Il n'est toujours pas rentré!" BOX_BREAK UNSKIPPABLE "Alors je me tape tout le boulot.\n"
"Cool, non?" TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pfff...ça craint d'bosser!"
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé! Tes vêtements! Ils sont...\n"
"Différents...\n"
"Tu n'es pas du coin, toi?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........." TEXT_SPEED("\x00") "........" BOX_BREAK UNSKIPPABLE "Ohh... \n"
"Tu es un garçon de la forêt!\n"
"Mon nom est " COLOR(RED) "Malon" COLOR(DEFAULT) "! Mon père \n"
"tient le Ranch Lon Lon." TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Papa est parti livrer du lait au\n"
"Château mais il n'est toujours\n"
"pas revenu..."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vas-tu au Château, garçon de la \n"
"forêt? Peux-tu trouver mon " COLOR(RED) "père" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "Il a dû s'endormir quelque part\n"
"autour du Château. \n"
"Il est si paresseux! Hi hi hi!" BOX_BREAK UNSKIPPABLE "Prends ceci... Tu en auras\n"
"probablement besoin." BOX_BREAK UNSKIPPABLE "J'en prends soin depuis longtemps...\n"
"Hi hi hi!" EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Assigne l'oeuf à " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour le \n"
"couver. Hi hi!" BOX_BREAK "Mon père est...spécial, hein?\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Et dire que moi, le grand " COLOR(RED) "Ingo" COLOR(DEFAULT) ", \n"
"travaille dans un ranch aussi nul!\n"
"C'est de la folie!" BOX_BREAK UNSKIPPABLE "Le propriétaire est si paresseux!\n"
"Alors je me tape toutes les \n"
"corvées! J'en ai ras la moustache!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Moi, le grand " COLOR(RED) "Ingo" COLOR(DEFAULT) ", devrait être le\n"
"patron de ce ranch. Pas l'autre\n"
"crétin de Talon!"
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, revoilà le garçon de la forêt!\n"
"Alors, tu as trouvé mon papa?\n"
"As-tu visité le Château? As-tu \n"
"rencontré la Princesse? Hi hi!" BOX_BREAK UNSKIPPABLE  SFX("\x68\x6D") "Papa est revenu à la maison\n"
"en courant comme un lapin après \n"
"votre rencontre. Hi hi hi!" BOX_BREAK UNSKIPPABLE "Au fait... Je ne t'ai pas encore\n"
"présenté mon amie!" BOX_BREAK UNSKIPPABLE "Cette petite jument s'appelle\n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". N'est-elle pas adorable?"
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On dirait qu'Epona a peur de toi,\n"
"M. le garçon de la forêt..."
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma mère me chantait cette \n"
"chanson. Elle est belle, non?\n"
"Chantons-la tous les deux."
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Epona! Elle semble vous\n"
"apprécier, M. le garçon de la forêt."
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "..."
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...de la visite!\n"
"Les visiteurs se font rares\n"
"en ce moment...\n"
"D'où viens-tu?" BOX_BREAK "Depuis la venue de Ganondorf, \n"
"les gens ont fui les villes, le pays\n"
"est en ruines, et des monstres \n"
"sont apparus un peu partout." BOX_BREAK "M. Ingo ne dirige le Ranch que \n"
"pour plaire à Ganondorf..." BOX_BREAK "Tout le monde semble devenir\n"
"méchant..." BOX_BREAK "Et puis il y a mon père...\n"
"M. Ingo l'a jeté dehors..." BOX_BREAK "Si jamais j'ose désobéir à M. Ingo,\n"
"il fera du mal aux chevaux..." BOX_BREAK "Alors...\n"
"On ne peut pas dire que ce soit \n"
"la fête dans le coin..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Personne n'est aussi rapide que \n"
"moi! Alors, résultat: j'm'ennuie."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "...\n"
"Arrête de chanter...\n"
"Mmmm....Idiote..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Regarde bien cette montagne.\n"
"C'est le " COLOR(RED) "Mont du Péril" COLOR(DEFAULT) ", la demeure\n"
"des Gorons. Ils détiennent la\n"
"Pierre Ancestrale du feu."
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ne dis surtout pas à M. Ingo que\n"
"je chante cette chanson..."
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu...\n"
"Tu connais la " COLOR(RED) "chanson de ma mère" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Tout le monde adorait cette\n"
"chanson...\n"
"Mon père... Même M. Ingo..." BOX_BREAK UNSKIPPABLE "Mais...depuis la venue de\n"
"Ganondorf, M. Ingo a changé." BOX_BREAK UNSKIPPABLE "Cette chanson me rappelle\n"
"les beaux jours..." TEXTID("\x20\x52")
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Epona" COLOR(DEFAULT) " était folle de cette chanson...\n"
"J'étais la seule à pouvoir la \n"
"monter... Même M. Ingo a des \n"
"problèmes avec elle..." BOX_BREAK "Hi hi hi!"
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"L'oeil de cette statue perce les\n"
"mystères de votre esprit..."
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Grâce à votre masque, cette \n"
"étrange statue vous parle..." BOX_BREAK "Voici ses paroles..."
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai pris de bonnes résolutions:\n"
"Désormais je vais me mettre à \n"
"bosser comme un méga-dingue."
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"M. Ingo... De sombres pouvoirs\n"
"ont dû l'ensorceler...\n"
"Il n'a jamais été un mauvais\n"
"homme..."
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z Z Z Z...\n"
"Mmmm... J'en ai marre de bosser..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bon alors...\n"
"Tu veux faire la course?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si tu changes d'avis,\n"
"reviens me voir!"
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors... Hors de ma vue, microbe!" EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé... Tu m'en veux d'avoir \n"
"gagné, hein? Dans ce cas je peux\n"
"t'accorder une revanche!\n"
"On refait la course?" BOX_BREAK "Aboule " COLOR(RED) "50 Rubis " COLOR(DEFAULT) "et c'est parti!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Pas question" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci beaucoup, Hé hé!" EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo va me hurler dessus si je te\n"
"donne ceci pour rien.\n"
"Alors je vais te faire un prix."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu du lait pour " COLOR(RED) "30 Rubis" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bien le bonjour mon bon monsieur!\n"
"Mon nom est Ingo. Travailler ici\n"
"est un honneur."
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Petit...tu es courageux!\n"
"Nous devons protéger cette belle\n"
"terre d'Hyrule!"
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh, le bel ocarina!\n"
"Vas-tu jouer ma chanson avec ton\n"
"instrument?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Au pied du Mont du Péril tu \n"
"trouveras mon village natal, \n"
COLOR(RED) "Cocorico" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Interroge les villageois avant\n"
"de t'aventurer dans la montagne."
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La mélodie que je t'ai enseignée\n"
"possède d'étranges pouvoirs. Elle \n"
"est le patrimoine de la Famille\n"
"Royale..." BOX_BREAK UNSKIPPABLE "Elle t'aidera à prouver ton alliance\n"
"avec la Famille Royale." BOX_BREAK UNSKIPPABLE "Maintenant va, jeune guerrier...\n"
"Tu dois rapporter les Pierres au \n"
"Château. Nous comptons tous sur \n"
"toi!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hou houuu!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Regarde un peu par là!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Prépare-toi car ta noble quête \n"
"débute enfin!" BOX_BREAK UNSKIPPABLE "Ton destin est tourmenté.\n"
"Obstacles et épreuves t'attendent. \n"
"Mais jamais le courage ne doit te\n"
"faire défaut!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Va tout droit pour aller au\n"
COLOR(RED) "Château d'Hyrule" COLOR(DEFAULT) "." BOX_BREAK "Une " COLOR(RED) "Princesse " COLOR(DEFAULT) "t'y attend..." BOX_BREAK "Si par malheur tu perds ton \n"
"chemin, n'hésite pas à consulter\n"
"la " COLOR(RED) "Carte" COLOR(DEFAULT) "." BOX_BREAK "Les contrées déjà explorées seront\n"
"affichées à l'écran. Appuie sur\n"
COLOR(RED) "START " COLOR(DEFAULT) "puis sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " pour \n"
"trouver la carte." BOX_BREAK "Sur l'" COLOR(RED) "écran de la carte" COLOR(DEFAULT) " apparaîtra\n"
"un " COLOR(RED) "point clignotant" COLOR(DEFAULT) " t'indiquant la \n"
"position de ta prochaine épreuve." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"M'as-tu bien compris?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Non\n"
"Oui" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bonne chance brave petit!\n"
"Et à la prochaine!\n"
"Hou hou houuu!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hé, " NAME "! Par ici!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "La Princesse est dans le Château.\n"
"Ne te fais surtout pas repérer \n"
"par les gardes!\n"
"Hou hou hou houuuu!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Par ici, le temps s'écoule\n"
"normalement." BOX_BREAK "Mais le temps reste comme figé\n"
"lorsque tu visites le Ranch \n"
"Lon Lon ou une ville." BOX_BREAK "Dans ces conditions, tu devras \n"
"quitter la ville pour faire avancer\n"
"le temps normalement." BOX_BREAK "Dis-moi... Par où vas-tu aller\n"
"maintenant?\n"
"Hou hou houuu!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu que je répète tout ça?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Houuu. T'es un malin, toi!\n"
"Bonne chance mon garçon...\n"
"Hou hou hou."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé, " NAME "! \n"
"Attends une minute, l'ami!" BOX_BREAK "Par là tu trouveras le" COLOR(RED) " village de \n"
"Cocorico" COLOR(DEFAULT) ". As-tu déjà rencontré la\n"
"Princesse d'Hyrule? Si la réponse \n"
"est non, dirige-toi vers le Château." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé, " NAME "! \n"
"Par ici, mon tout petit!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Par là tu trouveras le " COLOR(RED) "village de \n"
"Cocorico" COLOR(DEFAULT) ". Prends garde à toi!\n"
"Houu houuu!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", sur tes minces \n"
"épaules repose la destinée du\n"
"Royaume! Sois à la hauteur! \n"
"Houu houuu!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME "!\n"
"Ecoute donc mes sages paroles!\n"
"Hou houuuu!" BOX_BREAK_DELAYED("\x28") "Au sud s'étend le " COLOR(RED) "Lac Hylia" COLOR(DEFAULT) "." BOX_BREAK "A l'ouest tu trouveras la " COLOR(RED) "Vallée\n"
"Gerudo" COLOR(DEFAULT) ". Un repaire de voleuses\n"
"occupe l'autre versant de la\n"
"vallée." BOX_BREAK "Tu es libre d'aller n'importe où!\n"
"Hou hou hou...houuu!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Reste courageux devant l'adversité.\n"
"Hou Hou Houuu!"
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Dans cette direction s'étend les\n"
"eaux riches et pures du Lac Hylia." BOX_BREAK_DELAYED("\x28") "Les " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", un peuple vivant en \n"
"amont du fleuve, sont les gardiens \n"
"du Temple sous-marin et de la \n"
"Fontaine Zora." BOX_BREAK "Pour confirmer sa position sur la \n"
"carte, appuie sur " COLOR(RED) "START " COLOR(DEFAULT) "puis sur \n"
COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " pour trouver la carte." BOX_BREAK "Toutes les contrées visitées sont\n"
"indiquées sur la carte.\n"
"Houuu houuu heu...hou!" EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mène à bien ta quête, \n"
"petit homme!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quel est ton nom?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "C'est étrange...j'ai l'impression... \n"
"de te connaître." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ecoute-moi bien, " NAME "..." BOX_BREAK UNSKIPPABLE "Je vais te révéler la légende du\n"
"Saint Royaume, gardée depuis bien\n"
"des lunes par la noble Famille\n"
"d'Hyrule." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x28") "L'Ocarina du Temps!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"As-tu bien compris toute l'histoire?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Je regardais par cette fenêtre..." BOX_BREAK UNSKIPPABLE "Les " COLOR(BLUE) "nuages noirs " COLOR(DEFAULT) "de mon rêve...\n"
"Je crois qu'ils symbolisent...\n"
"Cet homme!" BOX_BREAK "Veux-tu jeter un coup d'oeil?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Bien sûr!" BOX_BREAK UNSKIPPABLE "J'ai parlé de mon rêve à Père..." BOX_BREAK UNSKIPPABLE "Mais il n'a rien voulu savoir..." BOX_BREAK UNSKIPPABLE "Quoi qu'il en soit...\n"
"Je suis certaine que cet homme \n"
"nourrit de noirs desseins!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ganondorf est à la recherche de\n"
"la " COLOR(RED) "Triforce " COLOR(DEFAULT) "du Saint Royaume.\n"
"J'en suis sûre!" BOX_BREAK UNSKIPPABLE "Sa venue jusqu'à Hyrule en est la\n"
"preuve!" BOX_BREAK UNSKIPPABLE "Cependant...\n"
"Ses plans de conquête ne se \n"
"bornent pas à Hyrule...\n"
"Mais au monde entier!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...\n"
"Nous sommes les seuls en mesure\n"
"de protéger le Royaume d'Hyrule!" EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Le vil Ganondorf ne doit JAMAIS\n"
"mettre la main sur la Triforce!" BOX_BREAK UNSKIPPABLE "Je vais garder précieusement\n"
"l'" COLOR(LIGHTBLUE) "Ocarina du Temps" COLOR(DEFAULT) ". \n"
"Jamais il ne le trouvera!" BOX_BREAK UNSKIPPABLE "De ton côté, va récupérer les \n"
"deux autres " COLOR(RED) "Pierres Ancestrales" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Il est de notre devoir de trouver\n"
"la Triforce avant Ganondorf et de\n"
"contrecarrer ses plans de \n"
"conquête!" EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Encore une chose...\n"
"Prends cette " COLOR(RED) "lettre" COLOR(DEFAULT) "...\n"
"Elle te sera d'une grande aide." EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mmm...zzz..mmm...hein?\n"
"OK, j'suis réveillé maintenant!" BOX_BREAK UNSKIPPABLE "Quoi?" BOX_BREAK UNSKIPPABLE "Sacré nom d'un pétard mouillé!\n"
"C'est le p'tit gars d'la forêt!\n"
"Au fait, merci de m'avoir réveillé\n"
"l'aut'jour!" BOX_BREAK UNSKIPPABLE "Tu as dû comprendre que mon truc\n"
"à moi, c'est d'pioncer." BOX_BREAK UNSKIPPABLE "Alors quels sont tes projets pour\n"
"la journée? Ca te dirait de jouer\n"
"avec ton pote Talon?\n"
"(Heu... Talon, c'est moi.)" BOX_BREAK UNSKIPPABLE "Les trois cocottes que j'ai ici \n"
"sont des " COLOR(RED) "Super Cocottes" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Je vais lancer ces trois Cocottes \n"
"au milieu de toutes les autres." BOX_BREAK UNSKIPPABLE "Si tu peux les retrouver avant\n"
"la fin du chrono, j'te donnerai\n"
COLOR(RED) "un truc cool" COLOR(DEFAULT) "." BOX_BREAK "Dans le cas contraire, c'est moi\n"
"le vainqueur. On parie 10 Rubis...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Jamais!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm...mmmm...quoi?\n"
"OK, OK, j'suis réveillé!" BOX_BREAK "Qu'y a-t-il?" BOX_BREAK "Salut, p'tit gars d'la forêt!\n"
"Tu as du temps devant toi?\n"
"Alors on va jouer!" BOX_BREAK "Je vais lancer ces trois \n"
COLOR(RED) "Super Cocottes " COLOR(DEFAULT) "au milieu de \n"
"toutes les autres." BOX_BREAK "Si tu peux les retrouver avant\n"
"la fin du chrono, j'te donnerai\n"
COLOR(RED) "un truc cool" COLOR(DEFAULT) "." BOX_BREAK "Dans le cas contraire, c'est moi\n"
"le vainqueur. On parie 10 Rubis... \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Jamais!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as 30 secondes!\n"
"Prépare-toi...car voici...les...\n"
"Super Cocottes!" BOX_BREAK SHIFT("\x37") "C'EST PARTI!!!" EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hop là! C'est fini!\n"
"Dommaaaaage mon poussin!!" BOX_BREAK "Il est cool mon jeu, hein?\n"
"Mes Cocottes si mignonnes!" BOX_BREAK "Super Cocottes... Au pied!" EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"En voilà une!\n"
"Bien joué mon poussin!\n"
"Encore " COLOR(RED) "deux" COLOR(DEFAULT) " à trouver!" EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"En voilà une autre!\n"
"Le moment de vérité! \n"
"Plus qu'" COLOR(RED) "une" COLOR(DEFAULT) " à trouver!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sacré nom d'une pipe en bois!\n"
"J'en reste baba!" BOX_BREAK "C'était la dernière!\n"
"Tu les as toutes trouvées!\n"
"Approche un peu mon poussin!" EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu jouer encore une fois?" BOX_BREAK "Un p'tit gars comme toi a de\n"
"l'énergie à revendre!\n"
"Trouve mes Super Cocottes en\n"
"30 secondes." BOX_BREAK "On parie 5 Rubis?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Jamais!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon p'tit gars...\n"
"Tu as l'étoffe d'un éleveur de\n"
"Cocottes!" BOX_BREAK "Ca te dirait d'épouser Malon?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oh oui! Oh oui!\n"
"Jamaiiiis!!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ha ha! Je blaguais! \n"
"T'es peut-être un peu jeune pour \n"
"ça, p'tite tête!\n"
"Ha ha ha!" BOX_BREAK UNSKIPPABLE "Voici un échantillon de notre\n"
"célèbre " COLOR(RED) "Lait de Lon Lon" COLOR(DEFAULT) ". \n"
"Il restaurera ton énergie en une\n"
"seconde!" BOX_BREAK UNSKIPPABLE "Après l'avoir bu, rapporte la \n"
COLOR(RED) "bouteille" COLOR(DEFAULT) " pour faire le plein!" EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé l'ami... tu m'as l'air honnête et \n"
"travailleur!" BOX_BREAK "Une fois plus grand tu pourras\n"
"travailler au Ranch!\n"
"L'offre tiendra toujours dans\n"
"quelques années." EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voilà pour toi! Un bon litre de\n"
COLOR(RED) "Lait de Lon Lon " COLOR(DEFAULT) "bien frais!" EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voilà pour toi! \n"
"Du lait bien frais...hein?..." BOX_BREAK "Dommaaaaaaaaage!!\n"
"Tu n'as pas de bouteille vide!"
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm...mmm...\n"
"OK, OK, j'suis réveillé!" BOX_BREAK "Quoi?" BOX_BREAK "Salut, " NAME "!\n"
"Si tu cherches Malon, elle est \n"
"dehors. Tu es peut-être venu pour\n"
"jouer?" BOX_BREAK "Alors que dirais-tu d'une partie de\n"
COLOR(RED) "Cherche-la-Super-Cocotte" COLOR(DEFAULT) "?\n"
"Ou veux-tu plutôt du \n"
COLOR(RED) "lait de Lon Lon" COLOR(DEFAULT) "?" BOX_BREAK "Dis-moi tout!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Lait de Lon Lon - 30 Rubis\n"
"Jeu de la Cocotte - 10 Rubis\n"
"Quitter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Perdu!" COLOR(DEFAULT) "\n"
"Tu dois sauter par-dessus tous les\n"
"obstacles!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Encore un tour!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Es-tu sûr de t'y prendre\n"
"correctement? Galope tout droit\n"
"vers les barrières ou ton cheval\n"
"ne sautera pas!" BOX_BREAK "Grimpe sur Epona pour retenter\n"
"ta chance!"
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Fantastique!\n"
COLOR(RED)  RACE_TIME  COLOR(DEFAULT) " est le nouveau record!" BOX_BREAK UNSKIPPABLE "Je dois te donner un petit\n"
"quelque chose pour te féliciter!" BOX_BREAK UNSKIPPABLE "Je viendrai te livrer mon cadeau\n"
"chez toi...... Tu dois te demander\n"
"ce que c'est, hein? Hi hi hi!"
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le record est de " COLOR(RED) "50 secondes" COLOR(DEFAULT) ".\n"
"Ton meilleur temps est de " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "." BOX_BREAK "Si tu bats le record, je t'offrirai \n"
"un petit cadeau.\n"
"Alors fais de ton mieux, OK?" BOX_BREAK "Et c'est parti!" EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ton meilleur temps est de " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "!\n"
"Peux-tu faire mieux que ça?\n"
"Allez, c'est parti!" EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le record actuel est " COLOR(RED) "50 secondes" COLOR(DEFAULT) ".\n"
"Tente d'abord de battre ce temps!" BOX_BREAK "Si tu bats le record, je t'offrirai\n"
"un petit cadeau!\n"
"Alors fais de ton mieux, OK?" BOX_BREAK "Et c'est parti!" EVENT
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

DEFINE_MESSAGE(0x3000, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Vous ne savez pas ce que\n"
"\"frères de sang\" veut dire mais \n"
"vous avez désormais deux Pierres\n"
"Ancestrales! Plus qu'une à trouver!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Vous ne savez pas ce que\n"
"\"frères de sang\" veut dire mais\n"
"vous avez les trois Pierres \n"
"Ancestrales! Allez vite voir Zelda!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"J'ai faaaiiiis çççççaaaaaa...\n"
"Je veux le " COLOR(RED) "certiffficaaat" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"J'ai fait ceeeeeeciiiiii...\n"
"Commmmmmme sssouvvvenirrrr..."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D") "Petit, j't'aime bien!" BOX_BREAK UNSKIPPABLE "Pourquoi qu'on deviendrait pas \n"
"des frères de sang?!" BOX_BREAK UNSKIPPABLE "Pas besoin de cérémonie! \n"
"Accepte ce cadeau en témoignage \n"
"de notre amitié!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x25") "Viens faire un bisou!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "Tu veux un gros cââlinouu?" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x50") "Hé!!!" BOX_BREAK_DELAYED("\x1E")  SHIFT("\x4B") "Oh-oh!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x26")  QUICKTEXT_ENABLE "Plus fort la musique!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x11") "Allez donne-toi..." QUICKTEXT_ENABLE "ça balance" QUICKTEXT_DISABLE "!!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x37")  QUICKTEXT_ENABLE "C'est CHAUD!!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x28") "Quel rythme!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x32") "WHOOOOAH!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YHAAAAA!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YAHBADAA!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nous les " COLOR(RED) "Gorons" COLOR(DEFAULT) " mangeons les\n"
"pierres du Mont du Péril." BOX_BREAK UNSKIPPABLE "Regarde cet énorme rocher!" BOX_BREAK UNSKIPPABLE "Il bloque l'entrée de la " COLOR(RED) "Caverne" COLOR(DEFAULT) "\n"
COLOR(RED) "Dodongo" COLOR(DEFAULT) "." COLOR(RED) " " COLOR(DEFAULT) "C'est un endroit très \n"
"important pour les Gorons!" BOX_BREAK UNSKIPPABLE "Mais un jour, de nombreux \n"
"Dodongos infestèrent la caverne\n"
"et y aller devint très dangereux!" BOX_BREAK UNSKIPPABLE "Et en plus, comme si ça suffisait \n"
"pas, un vilain " COLOR(RED) "Gerudo en armure \n"
"noire " COLOR(DEFAULT) "a jeté un sort pour bloquer\n"
"l'entrée avec ce rocher!" TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon boulot c'est de dévaler le \n"
"long de la montagne avec un \n"
COLOR(RED) "Chou-Péteur" COLOR(DEFAULT) " dans les dents. \n"
"Je dois foncer dans l'rocher et..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(RED) "BOOOUUUM!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK "Mais...j'suis un peu lent...\n"
"Mon Chou-Péteur explose trop tôt \n"
"et mes dents...bah...comment dire...\n"
"Elles sont nazes, quoi!"
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je reste ici pour faire de l'ombre\n"
"aux " COLOR(RED) "Choux-Péteurs" COLOR(DEFAULT) ". \n"
"Ouais...c'est mon boulot à moi!" BOX_BREAK "Tu veux m'poser une question?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Chou-Péteur?\n"
"Caverne Dodongo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les plantes du coin sont des \n"
COLOR(RED) "Choux-Péteurs" COLOR(DEFAULT) ". Elles peuvent \n"
"exploser et ne poussent que sur \n"
"cette montagne." BOX_BREAK "Leur fruit est l'essence même\n"
"des célèbres bombes." BOX_BREAK "Mais un non-Goron ne peut se\n"
"servir d'un tel engin!" BOX_BREAK "Ces plantes ne poussent que dans \n"
"les endroits sombres... Mais \n"
"celle-ci est une des rares\n"
"exceptions."
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les plantes du coin sont des \n"
COLOR(RED) "Choux-Péteurs" COLOR(DEFAULT) ".  Elles peuvent \n"
"exploser et ne poussent que sur \n"
"cette montagne." BOX_BREAK "Ces plantes ne poussent que dans\n"
"les endroits sombres, comme\n"
"les cavernes, mais celle-ci est une \n"
"des rares exceptions." BOX_BREAK "Grâce au célèbre Bracelet Goron,\n"
"même un petit gars comme toi \n"
"pourrait les soulever avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As-tu vu l'entrée d'une caverne\n"
"sur ton chemin? Hé ben, c'etait la\n"
COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) "." BOX_BREAK "Comme il n'y a que très peu de \n"
"lumière là-dedans, les " COLOR(RED) "Choux-\n"
"Péteurs " COLOR(DEFAULT) "poussent comme du \n"
"chiendent!"
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x55") "Oh?" BOX_BREAK UNSKIPPABLE "Les visiteurs se font rares! \n"
"D'où viens-tu?" BOX_BREAK UNSKIPPABLE "La forêt?" BOX_BREAK UNSKIPPABLE "C'est quoi une \"forêt\"?" BOX_BREAK UNSKIPPABLE "Hein?" BOX_BREAK UNSKIPPABLE "On y trouve des \"arbres\" et\n"
"des \"plantes\"?" BOX_BREAK UNSKIPPABLE "Heu... Tu me parles de quoi, là?\n"
"Ici il y a bien des " COLOR(RED) "Choux-Péteurs" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Mais les Bâtons Mojo c'est \n"
"super rare dans l'coin!" TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"J'ai pas grand chose à vendre \n"
"alors j'ai fermé l'entrée. \n"
"Mais je vois que tu es un client \n"
"acharné..." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je suis désolé...\n"
"Cette bombe est en exposition.\n"
"J'ai " COLOR(RED) "vendu" COLOR(DEFAULT) " tout mon stock." EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ben...pourquoi tu m'as arrêté?\n"
"Pas ici! Non pas ici!" BOX_BREAK "Tu peux pas faire ça!" BOX_BREAK "Les roulés-boulés sont ma seule \n"
"raison de vivre: ça me calme les\n"
"nerfs!" BOX_BREAK "Respecte mes roulés-boulés! \n"
"Ecarte-toi que j'roule un peu!!"
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bon... Prends ceci en récompense\n"
"de ton courage!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci, merci! Laisse-moi te \n"
"remercier en exécutant un de \n"
"mes plus beaux roulés-boulés!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x31") "Oh...J'ai si faim..." BOX_BREAK UNSKIPPABLE "Tout le monde crève la dalle ici. \n"
"Nous sommes devenus une race en \n"
"voie d'extinction... \n"
"Faut nous protéger!" BOX_BREAK UNSKIPPABLE "On ne peut plus entrer dans les \n"
"carrières de la " COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) ", \n"
"notre garde-manger!" BOX_BREAK UNSKIPPABLE "On doit alors se contenter de \n"
"graviers, et ça c'est dur..." BOX_BREAK UNSKIPPABLE "Les meilleurs rochers, à la fois\n"
"nutritifs et délicieux, sont dans la\n"
"Caverne Dodongo! Mais c'est de \n"
"l'histoire ancienne..." BOX_BREAK UNSKIPPABLE "Nous sommes tous devenus \n"
"de vrais gourmets! Il est alors\n"
"impossible d'avaler autre chose \n"
"que de la pierre Dodongo!" TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beuhh... Je me taperais bien\n"
"un gigot de caillasse de la\n"
COLOR(RED) "Caverne Dodongo" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé!" BOX_BREAK UNSKIPPABLE "C'est dangereux par ici! \n"
"Un petit gars comme toi pourrait \n"
"tomber n'importe où!" BOX_BREAK UNSKIPPABLE "Attends! Tu ne serais pas\n"
"venu pour manger notre \n"
COLOR(RED) "pierre rouge" COLOR(DEFAULT) ", par hasard?\n"
"Dommage! Elle n'est plus là!" BOX_BREAK UNSKIPPABLE "Quoi? Tu n'es pas ici pour ça?" BOX_BREAK UNSKIPPABLE "Tu cherches la Pierre Ancestrale? \n"
"Il doit s'agir de la pierre rouge" COLOR(RED) " " COLOR(DEFAULT) "si \n"
"appétissante qui était là!" BOX_BREAK UNSKIPPABLE "J'avais si faim alors je me suis\n"
"dit: \"une p'tite bouchée de cette \n"
"belle pierre, personne ne le saura!\"\n"
"Mais elle avait déjà disparu!" BOX_BREAK UNSKIPPABLE "Je crois que le Chef l'a cachée." BOX_BREAK UNSKIPPABLE "Il dit toujours que ça rend les \n"
"frères complètement dingues de \n"
"regarder cette pierre rouge par \n"
"ces temps de famine." TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le Chef s'est cloîtré dans son \n"
"antre après avoir dit:\n"
"\"" COLOR(RED) "J'attends le messager de la \n"
"Famille Royale!" COLOR(DEFAULT) "\""
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "J'ai si faim que je ne pense qu'à\n"
"manger!" BOX_BREAK UNSKIPPABLE "Adresse-toi au Chef pour les \n"
"histoires compliquées." BOX_BREAK UNSKIPPABLE "S'il est de mauvaise humeur, il \n"
"risque de se fâcher pour un rien.\n"
"Et là...tu seras mal." BOX_BREAK UNSKIPPABLE "Je connais son SECRET." BOX_BREAK UNSKIPPABLE "Il n'en a peut-être pas l'air,\n"
"mais il adore danser!\n"
"S'il entend une belle mélodie,\n"
"qui sait ce qu'il se passera!" TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je crois que le Chef adore\n"
"la " COLOR(ADJUSTABLE) "musique de la forêt" COLOR(DEFAULT) "..." BOX_BREAK "Ha! C'était le bon vieux temps...\n"
"Cette musique me rend nostalgique." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mmm? Quoi? Qui es-tu?!" BOX_BREAK UNSKIPPABLE "C'est toi qui a joué le " COLOR(BLUE) "chant de la \n"
"Famille Royale" COLOR(DEFAULT) "? Mais tu n'es pas \n"
"un messager! Tu n'es qu'un nabot \n"
"avec un chapeau vert!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Darunia" COLOR(DEFAULT) ", le Chef des Gorons,\n"
"mérite plus de considération de la \n"
"part de son frère de clan, le Roi \n"
"d'Hyrule!" BOX_BREAK UNSKIPPABLE "Alors là je suis furax!\n"
"Hors d'ici, le gnome!" BOX_BREAK UNSKIPPABLE "Tu me demandes pourquoi je suis\n"
"si furieux? Whoa! T'es mignon toi!\n"
"Ecoute..." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Des monstres infestent notre \n"
"Caverne Dodongo!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Notre récolte de Choux-Péteurs\n"
"est minable!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "On crève tous de faim par ici!\n"
"Y'a plus un rocher mangeable!!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x48") "Mais..." TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "C'est notre problème..." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x05") "Cela ne regarde que les Gorons!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x11") "Hé! Ca c'est de la chanson!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Ma déprime vient de s'envoler!\n"
"J'ai eu tout d'un coup envie de \n"
"danser! Comme un méga-dingue!" BOX_BREAK UNSKIPPABLE  SHIFT("\x32") "Mon nom est " COLOR(RED) "Darunia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Je suis le Chef des Gorons!\n"
"Je peux faire quelque chose pour\n"
"toi?" BOX_BREAK UNSKIPPABLE  SHIFT("\x4B") "Pardon?" BOX_BREAK UNSKIPPABLE "Tu veux la " COLOR(RED) "Pierre Ancestrale du \n"
"Feu" COLOR(DEFAULT) "? Ben voyons!" BOX_BREAK UNSKIPPABLE "La Pierre Ancestrale du Feu est \n"
"notre trésor secret! Nous \n"
"l'appelons le Rubis Goron..." BOX_BREAK UNSKIPPABLE "Mais si tu la veux vraiment,\n"
"tu pourrais peut-être nous rendre\n"
"un service..." BOX_BREAK UNSKIPPABLE "Peux-tu détruire les monstres de\n"
"la Caverne Dodongo?" BOX_BREAK UNSKIPPABLE "Ainsi nous aurions de quoi manger!\n"
"Je suis prêt à donner n'importe \n"
"quoi à notre sauveur...\n"
"Même la Pierre Ancestrale!" BOX_BREAK UNSKIPPABLE "Tiens, prends déjà cet objet!\n"
"Il te sera certainement utile!" BOX_BREAK UNSKIPPABLE "En l'utilisant, même un petit\n"
"gars comme toi pourra déraciner \n"
"des " COLOR(RED) "Choux-Péteurs" COLOR(DEFAULT) " avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Allez, nettoie-moi la " COLOR(RED) "Caverne\n"
"Dodongo" COLOR(DEFAULT) "! Nous reparlerons de \n"
"cette pierre plus tard!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Mon Frère! Rejoue-moi cette \n"
"chanson quand tu veux!"
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je ne me lasserai jamais de cette \n"
"chanson! Elle est si funky!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hmmm... Ce n'est pas vraiment mon\n"
"style de musique..." BOX_BREAK "Mais plutôt un truc...rigolo...\n"
"...champêtre...genre nature, quoi!" BOX_BREAK "Mon style à moi c'est le rock\n"
"des arbres et tout ça..."
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors on peut entrer dans la \n"
"caverne maintenant? \n"
"T'es un génie! Je me demande bien\n"
"comment tu as fait!"
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je connais un truc pour conserver \n"
"un bâton: quand il brûle, range-le\n"
"avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) " avant qu'il ne soit trop\n"
"tard!" BOX_BREAK "Au fait, j'ai planqué un bâton \n"
"quelque part...\n"
"Hé hé hé..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "C'est moi! " COLOR(RED) "Darunia" COLOR(DEFAULT) "!\n"
"Bien joué! Chapeau, petit!" BOX_BREAK UNSKIPPABLE "Grâce à toi, nous pouvons manger \n"
"les délicieuses pierres de la \n"
"Caverne Dodongo jusqu'à explosion \n"
"ventrale!"
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "J'ai si faim! Je ne pense qu'à\n"
"manger!" BOX_BREAK UNSKIPPABLE "\"Pierre Ancestrale?\"\n"
"Cette " COLOR(RED) "pierre rouge" COLOR(DEFAULT) " qui éclairait\n"
"notre village?" BOX_BREAK UNSKIPPABLE "Le chef " COLOR(RED) "Darunia" COLOR(DEFAULT) " a dû la cacher\n"
"avant de s'enfermer dans son \n"
"antre." BOX_BREAK UNSKIPPABLE "Depuis j'ai l'impression que toutes\n"
"les lumières du village sont ternes!\n"
"Tout le monde déprime à mort..." TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'aimerais que tu apportes le " COLOR(RED) "feu\n"
COLOR(DEFAULT) "de l'antre du chef jusqu'ici!"
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je comprends maintenant!\n"
"Il fallait lancer la bombe du haut\n"
"de la falaise...D'accooooord! \n"
"On aurait dû y penser plus tôt!"
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est dingue! \n"
"T'as détruit les Dodongos? \n"
"Je peux t'appeller Grand Frère?"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Merci! Nous sommes sauvés!!!\n"
"Tu peux acheter des bombes \n"
"maintenant!" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je te remercie à mort! Tu es mon \n"
"héros! Mon fils portera ton nom!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si tu veux en savoir plus sur les\n"
"Gorons, va dans notre village!" BOX_BREAK "Le" COLOR(RED) " Village Goron " COLOR(DEFAULT) "est au bout du\n"
"chemin. C'est à deux pas!"
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ramasse un Chou-Péteur avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". \n"
"Appuie sur " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pour" COLOR(BLUE) " " COLOR(DEFAULT) "le poser\n"
"ou le lancer."
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si toutes les " COLOR(RED) "torches" COLOR(DEFAULT) " étaient \n"
"allumées, le Village Goron serait \n"
"un peu plus vivant!"
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Alors tu veux nous débarrasser \n"
"des Dodongos? C'est le problème \n"
"des Gorons, tu sais!" BOX_BREAK "Mais ton aide est quand même la\n"
"bienvenue! Sauve-nous et nous \n"
"pourrons récupérer toutes les \n"
"bombes dont nous avons besoin..." BOX_BREAK "Laisse-moi te prévenir...\n"
"Les Dodongos, c'est pas de la \n"
"rigolade! Ils mangeraient\n"
"n'importe quoi!!!" BOX_BREAK "Alors fais gaffe à ne pas te faire \n"
"croquer!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je t'ai déjà dit!\n"
"J'ai plus de BOMBES!!!\n"
"Hooo...j'ai tellement faim!" PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Comment va le chef?\n"
"......\n"
"Je vois..." BOX_BREAK "Au fait, connais-tu la musique\n"
"qui vient de ce tunnel?\n"
"Nous l'adorons tous!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu ne m'auras jamais!\n"
"Tu es au service de Ganondorf!"
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Comment peux-tu me faire ça?\n"
"Tu es aux ordres de Ganondorf!" BOX_BREAK UNSKIPPABLE "Entends mon nom et tremble car \n"
"je suis..." BOX_BREAK UNSKIPPABLE  COLOR(RED)  NAME  COLOR(DEFAULT) "! \n"
"Héros des Gorons!"
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quoi?" BOX_BREAK UNSKIPPABLE "Ton nom c'est aussi \n"
NAME "?" BOX_BREAK UNSKIPPABLE "Alors tu dois être le légendaire\n"
"tueur de Dodongos, \n"
NAME "!" BOX_BREAK UNSKIPPABLE "Mon pôpa c'est " COLOR(RED) "Darunia" COLOR(DEFAULT) "...\n"
"Tu te souviens de lui?" BOX_BREAK UNSKIPPABLE "Pôpa m'a appellé " NAME "\n"
"en souvenir de ton courage!" BOX_BREAK UNSKIPPABLE "C'est un super nom!\n"
"Je l'aime trop!" BOX_BREAK UNSKIPPABLE  NAME ", \n"
"tu es le héros des Gorons! \n"
"Je suis très fier de te \n"
"rencontrer!" BOX_BREAK UNSKIPPABLE "Tu peux me signer un autographe?\n"
"Ecris juste...\n"
SHIFT("\x0C") "\"Pour mon ami...\n"
SHIFT("\x0C")  NAME ", le Goron\"" BOX_BREAK UNSKIPPABLE "Ho..." BOX_BREAK UNSKIPPABLE "Pardon...c'est peut-être pas le\n"
"moment de te demander ça..." BOX_BREAK UNSKIPPABLE "Mon pôpa est parti dans le \n"
COLOR(RED) "Temple du Feu" COLOR(DEFAULT) ". \n"
"Il y a un dragon là-bas!" BOX_BREAK UNSKIPPABLE "Si personne ne va l'aider,\n"
"il va se faire croquer!!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"B-b-b-bouuu hoouuuu!" EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Il a besoin d'être calmé...\n"
"Peut-être faut-il lui parler?" BOX_BREAK "Sur quoi allez-vous le questionner?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Le dragon\n"
"Les Gorons" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Il y a très longtemps de ça,\n"
"un gros dragon nommé " COLOR(RED) "Volcania" COLOR(DEFAULT) " \n"
"vivait dans cette montagne." BOX_BREAK UNSKIPPABLE "Ce dragon était très méchant!\n"
"Il mangeait les Gorons!" BOX_BREAK UNSKIPPABLE "Mais avec un marteau gigantesque,\n"
"le héros des Gorons...\n"
"Vlan! Paf! Boum!" BOX_BREAK UNSKIPPABLE "Il en a fait de la purée...\n"
"C'est peut-être une légende mais\n"
"c'est vrai!" BOX_BREAK UNSKIPPABLE "J'le sais parce que mon pôpa à moi\n"
"c'est un descendant de ce héros!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ils ont tous été emmenés dans le\n"
COLOR(RED) "Temple du Feu" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Pendant que pôpa était dehors...\n"
"Les soldats de Ganondorf sont \n"
"arrivés et ils ont enlevé tout le\n"
"monde!" BOX_BREAK UNSKIPPABLE "Ils vont tous se faire manger par\n"
COLOR(RED) "Volcania" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Pôpa dit que c'est Ganondorf qui a\n"
"réveillé le dragon..." BOX_BREAK UNSKIPPABLE "Pour faire peur aux autres races,\n"
"Ganondorf va donner les Gorons \n"
"en pâture à Volcania!!!" BOX_BREAK UNSKIPPABLE "Pôpa est allé au Temple du Feu\n"
"pour les sauver..." BOX_BREAK UNSKIPPABLE "Aide-nous, " NAME "!\n"
"En échange, je te donne cette \n"
COLOR(RED) "tunique résistante au feu" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pôpa m'a dit de ne laisser \n"
"personne le suivre, mais..." BOX_BREAK UNSKIPPABLE "Tu es le seul, " NAME ", à \n"
"pouvoir sauver tout le monde!" BOX_BREAK UNSKIPPABLE "Je suis sûr que le patron de la\n"
"boutique sera prêt à t'aider. \n"
"Il se cache quelque part!" BOX_BREAK UNSKIPPABLE "Maintenant je vais te dire où se \n"
"trouve le passage secret menant \n"
"au Temple du Feu!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essaie de bouger la " COLOR(RED) "statue" COLOR(DEFAULT) " dans \n"
"l'antre de mon Pôpa!"
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Qui est là? Est-ce toi,\n"
NAME "...?" BOX_BREAK UNSKIPPABLE "C'est vraiment toi?!?" BOX_BREAK UNSKIPPABLE "Tu es devenu si grand depuis la\n"
"dernière fois!" BOX_BREAK UNSKIPPABLE "Bon... Faut qu'on parle...\n"
"D'homme à homme... \n"
"Mais y'a pas le temps!" BOX_BREAK UNSKIPPABLE "Ganondorf sème la pagaille sur le \n"
"Mont du Péril encore une fois!\n"
"Il a réveillé l'ancien dragon \n"
"démoniaque Volcania!" BOX_BREAK UNSKIPPABLE "Et en plus il va donner tout mon\n"
"peuple en amuse-gueule à ce sale \n"
"dragon! Tout ça pour faire peur \n"
"aux autres races du royaume..." BOX_BREAK UNSKIPPABLE "Si ce cracheur de feu s'échappe \n"
"de la montagne, il y a des chances\n"
"pour qu'Hyrule devienne un vrai \n"
"feu de joie!!!" BOX_BREAK UNSKIPPABLE "Je vais aller voir s'il y a un\n"
"moyen d'enfermer ce gros reptile..." BOX_BREAK UNSKIPPABLE "Je n'ai pas la masse légendaire, \n"
"mais le temps presse!" BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Rends-moi un service, en tant que \n"
"Frère de sang..." BOX_BREAK UNSKIPPABLE "Va sauver mon peuple pendant que \n"
"je m'occupe du dragon!" BOX_BREAK UNSKIPPABLE "Les cellules sont de l'autre côté.\n"
"Je compte sur toi, " NAME "!"
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis libre!\n"
"Merci! Merci! Merci!\n"
"Voilà pour toi!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "...Vite...\n"
"Je ne peux plus tenir..." BOX_BREAK UNSKIPPABLE "Sors vite d'ici!!"
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Merci mon Frère. " COLOR(RED) "\n"
COLOR(DEFAULT) "Tu as fait du bon boulot.\n"
"Je te remercie au nom du peuple \n"
"Goron tout entier!" BOX_BREAK UNSKIPPABLE "Tu es un vrai brave.\n"
"Je l'ai toujours su!"
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
SHIFT("\x39") "N'oublie jamais...\n"
SHIFT("\x0D") "Nous sommes Frères de sang!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Il est un fait que le temps ne \n"
"peut altérer...Une amitié partagée...\n"
"Un sentiment profond du coeur qui\n"
"devient plus fort au fil des jours..." BOX_BREAK UNSKIPPABLE "La confiance réciproque cèdera \n"
"bientôt sa place au pouvoir de \n"
"justice, te révélant le sentier de \n"
"la victoire et de la paix..." BOX_BREAK UNSKIPPABLE "Cette chanson est dédiée au\n"
"pouvoir de l'amitié...\n"
"Ecoute bien le " COLOR(RED) "Boléro du Feu" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...à bientôt..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME ", \n"
"il fait beaucoup trop chaud! \n"
"Nous ne tiendrons pas longtemps!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Frère " NAME "!\n"
"Pôpa est revenu!\n"
"Tout le monde est revenu!" BOX_BREAK UNSKIPPABLE "Pôpa et toi avez vaincu le\n"
"dragon! Tous les deux!" TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quand j'serai grand, je s'rai fort\n"
"comme toi, " NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci, " NAME "!!"
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Merci de nous avoir sauvés!" PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Moi, Darunia l'indomptable,\n"
"m'éveille à la conscience de \n"
COLOR(RED) "Sage du Feu" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Moi! Un Sage! \n"
"C'est marrant, non? Enfin...\n"
"C'est ce qu'on appelle le destin." BOX_BREAK UNSKIPPABLE "Si ma présence ici peut faire\n"
"reculer les forces du mal...\n"
"Tu peux compter sur moi!"
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tiens mon Frère! Prends ceci!\n"
"Ce " COLOR(RED) "médaillon" COLOR(DEFAULT) " renferme le pouvoir \n"
"du feu...et mon amitié."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Alors là, gros problème!\n"
"Tout le monde est parti!\n"
"Mais ma boutique est toujours\n"
"ouverte!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ben dis donc! Quelle histoire!" BOX_BREAK UNSKIPPABLE "Et dire que l'on croyait les \n"
"Dodongos disparus depuis bien des \n"
"lunes! Toute cette affaire est \n"
"étrange..." BOX_BREAK UNSKIPPABLE "Et puis ce rocher à l'entrée de la \n"
"caverne..." BOX_BREAK UNSKIPPABLE "A mon avis " COLOR(RED) "Ganondorf" COLOR(DEFAULT) " est le \n"
"responsable de tout ce tintouin!" BOX_BREAK UNSKIPPABLE "\"" COLOR(LIGHTBLUE) "Donne-moi la Pierre Ancestrale et" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "j'ouvrirai la caverne" COLOR(DEFAULT) "\", qu'il a dit..." BOX_BREAK UNSKIPPABLE "Quel sale type...\n"
"Par contre toi, tu n'as pas hésité \n"
"à risquer ta vie pour nous... Merci."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x3D") "Un peu serré..."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je travaille sur un truc vraiment\n"
"costaud! Mais ça va me prendre \n"
"du temps..." TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Reviens disons dans...\n"
"Cinq ou six ans, OK?"
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je viens de finir ce cure-dent. \n"
"Qu'en dis-tu?" TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors qu'en penses-tu?"
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je n'ai pas encore résolu son \n"
"problème de résistance...\n"
"Mais enfin..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Me le prends-tu pour 200 Rubis?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "J'achète!\n"
"Trop cher" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ok, reviens quand tu veux."
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ne me mange pas! \n"
"Ne me mange pas!\n"
"Ne me mange pas!\n"
"Ne me mange pas!" BOX_BREAK "J'ai un goût atroce!"
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le Chef Darunia t'a demandé de \n"
"me sauver? Je te dois une fière\n"
"chandelle!" BOX_BREAK "Va vite aider Grand Frère!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mon frèèèère...\n"
"A ouveeeert un nouveau maaagasin...\n"
"C'est la boutique de laaaaames de\n"
"Medigoooooron..." BOX_BREAK "Mais mooooiiiiiii... \n"
"Je fooooorge les meilleures \n"
"épées du mooooonde!" BOX_BREAK "Les ouvriers Hyliens admiiiirent\n"
"mes taaaaalents...\n"
"J'te jure!"
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Cette lame est briiiiisée...\n"
"J'aimeraiiiis te la répaaaarer mais..." BOX_BREAK UNSKIPPABLE "L'éruuuuuption d'hier a irriiité\n"
"mes yeux..." BOX_BREAK UNSKIPPABLE "Le " COLOR(RED) "Roi Zoooora " COLOR(DEFAULT) "a" COLOR(RED) " " COLOR(DEFAULT) "des gouttes \n"
"pour mes yeeeuuuuuux..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Peuuuuux-tu aller les chercher?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Nooooon... \n"
"Mes yeuuuuux....\n"
"Ouuiiillle...Booooboooo!"
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tout le monde est parti!\n"
"Je suis le seul survivant!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je t'ai attendu les yeux pleeiiins\n"
"de laaarrrrmmmmmes..."
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oooooh? Tu as rapportééé les\n"
"gouuutttes?! Je vais les utiliiiser\n"
"tout de suuiiitte!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(RED) "Wowwwwwwwwwwwwww!!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "Caaaaa faaaiiiittt duuuu bieeennn!\n"
"J'y voooiiiis pluus claiiir!" BOX_BREAK UNSKIPPABLE "Je vais pouvoir me remettre au\n"
"boulot! Tiens prends çaaaa, pour\n"
"te faaaiiire patienter." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tout le monde est revenu!\n"
"Je fais des affaires monstres!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Revieeeens...\n"
"Daaanns quelques jours...\n"
"Paaatience..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Paaaaas encoooore...\n"
"Tu vas patienter, ouais?"
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Voilàààààà c'est finiiiii!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Votre " COLOR(DEFAULT) "bouclier" COLOR(LIGHTBLUE) " a disparu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Votre " COLOR(DEFAULT) "tunique " COLOR(LIGHTBLUE) "a disparu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Votre " COLOR(DEFAULT) "bouclier" COLOR(LIGHTBLUE) " et votre " COLOR(DEFAULT) "tunique" COLOR(LIGHTBLUE) " \n"
"ont disparu!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bravo! \n"
"Tu es parvenu jusqu'ici sans\n"
"trop de problèmes, " NAME ". \n"
"Te voici au Sommet du Péril!" BOX_BREAK UNSKIPPABLE "On raconte que les nuages autour\n"
"du pic reflètent la santé de la\n"
"Montagne. S'ils sont blancs, le\n"
"Mont est en paix..." BOX_BREAK UNSKIPPABLE "Escalader cette montagne est bien\n"
"la preuve de ton courage! Mais \n"
"sauras-tu faire une sage décision?" BOX_BREAK UNSKIPPABLE "La " COLOR(RED) "Grande Fée" COLOR(DEFAULT) " demeure au sommet.\n"
"Va donc la voir et elle te remettra\n"
"un nouveau pouvoir! Hou Hou Hou!" BOX_BREAK UNSKIPPABLE "Je vais attendre ton retour. \n"
"N'hésite à me demander de te\n"
"faire descendre de la montagne.\n"
"A plus tard! Hou hou hou!!!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hoouu hou!\n"
"Le nouveau pouvoir de la Grande \n"
"Fée a augmenté tes capacités..." BOX_BREAK "Mais long est le chemin qui te \n"
"mènera jusqu'au salut d'Hyrule!" BOX_BREAK "Accroche-toi à mes griffes pour \n"
COLOR(RED) "descendre la montagne" COLOR(DEFAULT) "! \n"
"Je peux au moins te rendre ce\n"
"service!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On dit qu'il y a une très " COLOR(RED) "belle" COLOR(DEFAULT) " \n"
COLOR(RED) "fée" COLOR(DEFAULT) " au Sommet du Péril!\n"
"Tu y crois, toi?"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il paraît qu'une " COLOR(RED) "fée" COLOR(DEFAULT) " vit en haut de \n"
"la montagne." BOX_BREAK "Il te faut le bon " COLOR(LIGHTBLUE) "bouclier " COLOR(DEFAULT) "pour \n"
"arriver jusqu'au sommet en un seul \n"
"morceau..."
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Un " COLOR(DEFAULT) "poulet" COLOR(LIGHTBLUE) " est sorti de ton " COLOR(DEFAULT) "oeuf" COLOR(LIGHTBLUE) "! \n"
"C'est-y pas mimi la nature? Hein?" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors? Tu l'as ta pierre rouge?\n"
"Fais-moi goûter! Fais-moi goûter!" BOX_BREAK "Non? Beeeuuuuhhhh!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Frère! Tu vas vite devenir une\n"
"montagne de muscles si tu \n"
"continues comme ça!" BOX_BREAK UNSKIPPABLE "Je te conseille d'aller voir\n"
"la " COLOR(RED) "Grande Fée" COLOR(DEFAULT) " au sommet du \n"
"Mont du Péril! Elle a un cadeau \n"
"pour toi!" BOX_BREAK UNSKIPPABLE "Hé les gars! Venez tous faire un\n"
"gros câlinou à notre Frère!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Dans ce temple tu trouveras des \n"
COLOR(RED) "portes" COLOR(DEFAULT) "...agressives. \n"
"Evite de te faire écraser!" BOX_BREAK UNSKIPPABLE "Tu pourras les détruire avec la\n"
"\"spécialité locale\" des Gorons."
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Si ta tunique se met à brûler, \n"
"agite ton épée dans tous les sens\n"
"ou fait une roulade pour l'éteindre...\n"
"Tu le savais déjà? Ah bon."
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Certaines créatures vont bientôt\n"
"t'attaquer en dansant... \n"
"Elles sont insensibles aux flèches!" BOX_BREAK UNSKIPPABLE "Je crois que tu auras besoin\n"
"d'une bonne moisson de notre \n"
"\"spécialité locale\"."
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Tu devras trancher certains \n"
"interrupteurs pour les activer. \n"
"Mais notre \"spécialité locale\" est\n"
"aussi très efficace!"
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "La carte t'indiquera certains \n"
"endroits inaccessibles. \n"
"Utilise ton ocarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Pour accéder à la pièce de \n"
"Darunia, tu devras faire quelque\n"
"chose avec le pilier coincé au\n"
"plafond." BOX_BREAK UNSKIPPABLE "Trouve un moyen d'aller au-dessus\n"
"du plafond!"
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Une porte est cachée dans la \n"
"statue à l'entrée du temple." BOX_BREAK UNSKIPPABLE "Mais la \"specialité locale\" ne sera\n"
"pas suffisante...Trouve quelque \n"
"chose de plus costaud!"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pour te remercier, voici un petit\n"
"conseil..." BOX_BREAK UNSKIPPABLE "Les parois sensibles à notre\n"
"\"spécialité locale\" sonnent \n"
"différemment lorsqu'elles sont \n"
"frappées avec une épée."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh? Tu es venu me sauver?\n"
"Je peux partir?" EVENT
)

DEFINE_MESSAGE(0x3072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3072"
)

DEFINE_MESSAGE(0x3073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3073"
)

DEFINE_MESSAGE(0x4000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ces yeux sont délicieux!\n"
"Je vais m'en faire un bon ragoût!\n"
"Nyaha ha ha ha!" BOX_BREAK UNSKIPPABLE "Dis bien merci au Roi Zora!\n"
"Hein? Quoi?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Je dois en faire des " COLOR(RED) "Gouttes pour\n"
"Biggoron" COLOR(DEFAULT) "? Oh! Quel dommage!\n"
"Tu m'as donné faim!" EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
"Par ici!  Hou hou!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Je me demande ce que devient \n"
COLOR(RED) "Saria" COLOR(DEFAULT) "! Pourquoi ne pas aller dans \n"
"la forêt de temps en temps?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Que fais-tu là? Tu as parcouru\n"
"un bien long chemin pour arriver\n"
"jusqu'ici..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "N'hésite pas à consulter le \n"
COLOR(RED) "Sous-menu de la Carte" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  NAME "... \n"
"Regarde autour de toi...\n"
"Ce lac est d'une pureté cristalline." BOX_BREAK UNSKIPPABLE "Au fond des eaux se trouve le \n"
COLOR(BLUE) "Temple de l'Eau " COLOR(DEFAULT) "dédié aux " COLOR(BLUE) "Esprits \n"
"de l'Eau" COLOR(DEFAULT) ". Les Zoras en sont\n"
"les gardiens. Hou, hou!" BOX_BREAK UNSKIPPABLE "Les Zoras sont originaires du \n"
"Domaine Zora au Nord Est d'Hyrule.\n"
"Cette race aquatique est fidèle à\n"
"la Famille Royale." BOX_BREAK UNSKIPPABLE "Seuls les membres de la Famille \n"
"Royale peuvent entrer dans le \n"
"Domaine Zora...\n"
"Hou hou!" BOX_BREAK UNSKIPPABLE "Bon, je retourne au " COLOR(RED) "château" COLOR(DEFAULT) ".\n"
"Pour venir avec moi, accroche-toi \n"
"à mes serres!"
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bon, je retourne au " COLOR(RED) "château" COLOR(DEFAULT) ".\n"
"Pour venir avec moi, accroche-toi \n"
"à mes serres!"
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "...Hein?" BOX_BREAK UNSKIPPABLE "Il y a quelque chose dans\n"
"cette bouteille. C'est une " COLOR(RED) "lettre" COLOR(DEFAULT) ":" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C") "\"" COLOR(PURPLE) "A l'aide!\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(PURPLE) "Je suis enfermée dans le\n"
COLOR(DEFAULT)  SHIFT("\x0C")  COLOR(PURPLE) "ventre du" COLOR(DEFAULT) " " COLOR(YELLOW) "Grand Jabu-Jabu!" COLOR(PURPLE) "\n"
COLOR(DEFAULT)  SHIFT("\x18") "-" COLOR(YELLOW) "Ruto" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C")  COLOR(PURPLE) "PS: N'en parlez pas à Père." COLOR(DEFAULT) "\"" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Qui es-tu?" BOX_BREAK UNSKIPPABLE "Nous sommes les " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", fier \n"
"peuple aquatique!" BOX_BREAK UNSKIPPABLE "Tu dis avoir quelques liens avec\n"
"la Famille Royale d'Hyrule...\n"
"Que pouvons nous faire pour toi?"
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nous sommes d'excellents \n"
"plongeurs! Et toi?" BOX_BREAK "Pour devenir un bon plongeur, \n"
"essaie le " COLOR(RED) "jeu du plongeon " COLOR(DEFAULT) "en haut \n"
"de la cascade! Va piquer une tête!"
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La Fontaine Zora est la source\n"
"du fleuve.\n"
COLOR(RED) "Le Grand Jabu-Jabu " COLOR(DEFAULT) "vit dans cette" COLOR(RED) " \n"
COLOR(DEFAULT) "fontaine." TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le Grand Jabu-Jabu est notre dieu.\n"
"La " COLOR(RED) "Princesse Ruto" COLOR(DEFAULT) "  a pour mission \n"
"de lui préparer ses repas matin et\n"
"soir."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nous sommes tous les sujets du\n"
"grand " COLOR(RED) "Roi Zora" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le grand Roi Zora est dans la\n"
COLOR(RED) "salle du trône" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As-tu vu le Grand Jabu-Jabu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Selon la \"Légende Zora\", faire\n"
"présent d'un poisson au Grand\n"
"Jabu-Jabu te rendra heureux pour\n"
"la journée."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non? Quel dommage!" BOX_BREAK "Tous les nouveaux visiteurs se \n"
"doivent de présenter leurs \n"
"respects au " COLOR(RED) "Grand Jabu-Jabu" COLOR(DEFAULT) "!" BOX_BREAK "La Fontaine Zora est juste \n"
"derrière la salle du trône du Roi \n"
"Zora. Le Grand Jabu-Jabu y prend\n"
"son bain. Mais..." BOX_BREAK "Sans la permission du Roi Zora\n"
"tu ne pourras y accéder."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "La " COLOR(RED) "Princesse Ruto " COLOR(DEFAULT) "est introuvable.\n"
"Nous l'avons cherchée partout, \n"
"même dans le " COLOR(BLUE) "Lac Hylia" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Si tu trouves des indices sur la\n"
"disparition de la " COLOR(RED) "Princesse Ruto" COLOR(DEFAULT) ", \n"
"va vite en informer notre Roi!"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Toute l'eau d'Hyrule provient de la\n"
COLOR(BLUE) "Fontaine Zora" COLOR(DEFAULT) "." BOX_BREAK "Cette eau parcourt le Fleuve Zora\n"
"et aboutit dans le " COLOR(BLUE) "Lac Hylia " COLOR(DEFAULT) "\n"
"au sud."
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh--Nous revenons à la vie!" BOX_BREAK UNSKIPPABLE "Est-ce toi qui Nous a sauvé?\n"
"Ne sois pas timide devant Nous!" BOX_BREAK UNSKIPPABLE "Il Nous semble que tu ne puisses \n"
"respirer sous l'eau comme les \n"
"nobles Zoras..." BOX_BREAK UNSKIPPABLE "En reconnaissance de tes services,\n"
"Nous t'offrons cette " COLOR(RED) "tunique" COLOR(DEFAULT) ". \n"
"Elle te permettra de respirer sous\n"
"l'eau. Comme Nous, quoi."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La Princesse Ruto est partie au \n"
"Lac Hylia et n'est jamais revenue.\n"
"Nous sommes inquiet..."
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hoo...\n"
"Il veut donc....hmmm...\n"
"Hmmm... " COLOR(RED) "Des Gouttes" COLOR(DEFAULT) "...?" BOX_BREAK UNSKIPPABLE "Peut-être en avons-Nous,\n"
"peut-être n'en avons-Nous pas...\n"
"Nous en avons les " COLOR(RED) "ingrédients" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Apporte les ingrédients au docteur\n"
"du " COLOR(RED) "laboratoire" COLOR(DEFAULT) ", il en fera des\n"
"Gouttes!" BOX_BREAK UNSKIPPABLE "Mais garde-les au frais..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Peux-tu t'en occuper avant qu'" COLOR(RED) "ils \n"
"ne se dessèchent" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors ne penses-tu pas être aussi\n"
"rapide que Nous?\n"
"Ce n'est qu'à une minute à cheval!"
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hou hou!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", \n"
"Ton aventure te plait-elle?" BOX_BREAK UNSKIPPABLE "La Princesse Zelda t'attend." BOX_BREAK UNSKIPPABLE "Tu as déjà le " COLOR(RED) "Rubis Goron" COLOR(DEFAULT) ",\n"
"n'est-ce pas?"
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salut à toi, mon garçon! \n"
"En mélangeant l'eau du Lac Hylia à\n"
"des trucs baveux je fais des \n"
"potions dégueulasses!!!" BOX_BREAK "As-tu déjà rencontré la p'tite \n"
"vieille de l'apothicaire?" BOX_BREAK "Elle est comme mon élève et \n"
"teste toutes mes potions...\n"
"Nyarf nyarf nyarf!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Oh! Woah!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Superbe " COLOR(RED) "Crapaud-qui-louche" COLOR(DEFAULT) ".\n"
"Un spécimen comme celui-ci se\n"
"fait rare depuis un bon moment!" EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Notre chère et douce Princesse\n"
"Ruto... Mais où est-elle?\n"
"Nous sommes si inquiet..."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ho! Cette lettre! \n"
"Elle est de la " COLOR(RED) "Princesse Ruto" COLOR(DEFAULT) "!!" BOX_BREAK UNSKIPPABLE "Hmmm...voyons voir...\n"
"Elle est dans le ventre du Grand\n"
"Jabu-Jabu?\n"
"C'est incroyable!" BOX_BREAK UNSKIPPABLE "Notre dieu protecteur, le " COLOR(RED) "Grand" COLOR(DEFAULT) "\n"
COLOR(RED) "Jabu-Jabu" COLOR(DEFAULT) ", ne ferait jamais une\n"
"chose pareille à la Princesse Ruto!" BOX_BREAK UNSKIPPABLE "Mais depuis la venue de cet \n"
"étranger, " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", le Grand \n"
"Jabu-Jabu est un peu pâlot..." BOX_BREAK UNSKIPPABLE "Les faits sont clairs...\n"
"Tu dois délivrer Notre Ruto!\n"
"Passe derrière Nous et dirige-toi \n"
"vers l'autel du Grand Jabu-Jabu." BOX_BREAK UNSKIPPABLE "Nous gardons cette lettre.\n"
"Tu peux conserver cette " COLOR(RED) "bouteille" COLOR(DEFAULT) "!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Nous t'en prions...\n"
"Sauve la " COLOR(RED) "Princesse Ruto" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Vous ne pouvez respirer sous l'eau!\n"
"Retirez ves " COLOR(DEFAULT) "bottes " COLOR(LIGHTBLUE) "avant qu'il ne\n"
"soit trop tard!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x36") "Hoooo! Noooooonnnn!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh--Nous revenons à la vie!" BOX_BREAK UNSKIPPABLE "Nous as-tu sauvé?\n"
"Ne sois pas timide et parle-Nous!" BOX_BREAK UNSKIPPABLE "Nous allons te donner cette \n"
"tunique Zora en gage de Notre \n"
"immense gratitude!\n"
"Tu pourras...Quoi?!" BOX_BREAK UNSKIPPABLE "Tu en as déjà une? \n"
"Tu es à la mode, toi!" BOX_BREAK UNSKIPPABLE "Bon alors...\n"
"Que dirais-tu d'un de Nos bisous?\n"
"Quoi? Tu n'en veux pas?\n"
"Ha! Bon..." BOX_BREAK UNSKIPPABLE "Si tu ne veux pas de Nos cadeaux,\n"
"écoute au moins Nos petits\n"
"malheurs..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis un " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". As-tu vu une\n"
"jolie fille zora dans le coin?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis un " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". As-tu vu quelque\n"
"chose d'étrange dans le Lac? \n"
"Le fleuve véhicule souvent bien\n"
"des curiosités!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Toi..." QUICKTEXT_ENABLE "t'es en retard!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Je t'attends depuis une heure!" QUICKTEXT_DISABLE "\n"
"Tu es " QUICKTEXT_ENABLE "NUL!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Je me sentais seule, c'est tout...\n"
"Juste un peu!!"
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "J'avais peur..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "un peu!" QUICKTEXT_DISABLE " \n"
"Enfin juste un peu!!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Toi!" QUICKTEXT_DISABLE "\n"
"T'es cool... Plus cool que je ne le\n"
"pensais... " QUICKTEXT_ENABLE "Enfin juste un peu!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Tu m'as sauvée... Je dois donc te \n"
"récompenser!" BOX_BREAK UNSKIPPABLE "Que veux-tu de moi? Je t'écoute...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "La Pierre Ancestrale\n"
"Rien du tout" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu veux le " COLOR(BLUE) "Saphir Zora" COLOR(DEFAULT) "?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ma mère me l'a transmis et je ne\n"
"le donnerai qu'à mon futur mari.\n"
"C'est une bague de fiançailles \n"
"Zora!" BOX_BREAK UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Bon OK!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Je te donne mon bien le plus\n"
"précieux:\n"
"Le Saphir Zora!"
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ne le dis pas à Père..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hihihihi... Ne sois pas timide." BOX_BREAK UNSKIPPABLE "Je sais à quoi tu penses..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je veux acheter un poisson mais \n"
"je n'ai pas assez d'argent..." BOX_BREAK "Il ne me reste qu'à en pêcher un.\n"
"Il y en a dans ce coin..."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, " NAME "!\n"
"Alors tu as sauvé la Princesse?\n"
"Nous en sommes ravi!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prends-tu soin de mon bien le plus \n"
"précieux?\n"
"Hihihihihihi!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Salut " NAME "!\n"
"La Princesse Ruto ne parle que de\n"
"toi!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! C'est toi, " NAME "!\n"
"Merci pour tout! Le Grand \n"
"Jabu-Jabu est en pleine forme!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tous les Zoras respectent le Roi\n"
"Zora! Il a la dignité et la noblesse\n"
"d'un grand souverain! \n"
"Il a une classe...dingue!" BOX_BREAK UNSKIPPABLE "Le grand Roi Zora a une fille \n"
"unique: la Princesse " COLOR(RED) "Ruto" COLOR(DEFAULT) ". " BOX_BREAK UNSKIPPABLE "C'est un vrai garçon manqué!\n"
"Notre Roi en est très inquiet." TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Voilà!" BOX_BREAK UNSKIPPABLE "Garanties sans colorants ni \n"
"conservateurs! Mais elles risquent\n"
"de tourner dans " COLOR(RED) "peu de temps" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Va vite à la montagne Goron! \n"
"Tu es jeune et rapide, non?\n"
"Tu peux y arriver!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hou hou! \n"
"Tu es devenu très fort, \n"
NAME "!" BOX_BREAK UNSKIPPABLE "Plus loin se trouve le " COLOR(BLUE) "Domaine\n"
"Zora" COLOR(DEFAULT) ". Les Zoras protègent cette \n"
"source d'eau et servent la Famille \n"
"Royale d'Hyrule." BOX_BREAK UNSKIPPABLE "Leur porte ne s'ouvrira que pour\n"
"un ami de la Famille Royale." BOX_BREAK UNSKIPPABLE "Chante haut et fort la " COLOR(RED) "Mélodie de \n"
"la Famille Royale" COLOR(DEFAULT) "!\n"
"Houu hou hoouu!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Apporte-moi un p'tit cadeau la\n"
"prochaine fois!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vous avez trouvé la Princesse \n"
"Ruto! Le Roi Zora vous donnera \n"
"sûrement la " COLOR(BLUE) "Pierre Ancestrale de \n"
"l'Eau" COLOR(DEFAULT) "! Enfin...peut-être." BOX_BREAK UNSKIPPABLE "Hummm?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Son \"bien le plus précieux\"?\n"
"Vous ne savez pas de quoi elle\n"
"parlait mais vous avez deux\n"
"Pierres! Plus qu'une à trouver!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Son \"bien le plus précieux\"?\n"
"Vous ne savez pas de quoi elle\n"
"parlait mais vous avez les trois\n"
"Pierres Ancestrales!!" BOX_BREAK UNSKIPPABLE "Allez voir Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "A nouveau nos routes se croisent,\n"
NAME "..."
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Cette glace est le fruit d'une \n"
"malédiction... Le monstre du " COLOR(BLUE) "Temple \n"
"de l'Eau" COLOR(DEFAULT) " en est la source." BOX_BREAK UNSKIPPABLE "Vivant, la glace ne pourra jamais\n"
"fondre...." BOX_BREAK UNSKIPPABLE "Ton courage puisse-t-il sauver tous\n"
"les Zoras. Je vais t'enseigner la\n"
"mélodie du Temple de l'Eau."
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Le temps file et emporte les\n"
"hommes...\n"
"Ainsi coule le fleuve et jamais ne\n"
"s'arrête..." BOX_BREAK UNSKIPPABLE "Un jeune esprit renferme un coeur\n"
"ambitieux... Des amours légères \n"
"cèdent à une passion profonde...  \n"
"Un miroir d'eau pure reflète la vie." BOX_BREAK UNSKIPPABLE "Ecoute la " COLOR(BLUE) "Sérénade de l'Eau " COLOR(DEFAULT) "et \n"
"contemple ton reflet..."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu arrives trop tard, les Zoras \n"
"ne sont pas ici...\n"
"Voici ce qu'il en reste..." BOX_BREAK UNSKIPPABLE "Les Zoras sont prisonniers de\n"
"cette vague de glace! \n"
"Tous...sauf une......" BOX_BREAK UNSKIPPABLE "J'ai pu sauver la Princesse du gel\n"
"éternel, mais elle s'est rendue \n"
"au " COLOR(BLUE) "Temple de l'Eau" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il te faut un récipient pour \n"
"acheter un poisson." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu veux acheter une " COLOR(BLUE) "tunique Zora" COLOR(DEFAULT) "?\n"
"Cet habit est cousu d'un tissu\n"
"précieux. Il est honteusement cher!" BOX_BREAK COLOR(RED) "Les familles fortunées" COLOR(DEFAULT) " de Cocorico \n"
"sont les seules à pouvoir se \n"
"l'offrir!" EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ho!...Toi?...Tu es?...\n"
NAME "?!" BOX_BREAK UNSKIPPABLE  NAME ", c'est bien toi?" BOX_BREAK UNSKIPPABLE "C'est moi, " COLOR(BLUE) "Ruto" COLOR(DEFAULT) "!" COLOR(BLUE) " " COLOR(DEFAULT) "Ta fiancée!\n"
"Princesse des Zoras!" BOX_BREAK UNSKIPPABLE "Je n'ai pas oublié notre promesse!" BOX_BREAK UNSKIPPABLE "Tu ne manques pas d'air!\n"
"Me faire attendre pendant sept \n"
"longues années..." BOX_BREAK UNSKIPPABLE "Mais l'heure n'est pas vraiment \n"
"aux histoires de coeur..." BOX_BREAK UNSKIPPABLE "As-tu vu le Domaine Zora?\n"
"Tout est gelé!" BOX_BREAK UNSKIPPABLE "Un jeune homme nommé " COLOR(RED) "Sheik" COLOR(DEFAULT) " m'a \n"
"sauvée des glaces..." BOX_BREAK UNSKIPPABLE "Mais mon père et les autres Zoras\n"
"sont" TEXT_SPEED("\x02") "...encore..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Je veux tous les sauver!\n"
"Je veux sauver le Domaine Zora!" BOX_BREAK UNSKIPPABLE "Tu dois m'aider!\n"
"C'est une faveur que je te \n"
"demande, moi...ta future femme!" BOX_BREAK UNSKIPPABLE  NAME ", \n"
"tu dois m'aider à détruire l'infect\n"
"monstre du temple, d'accord?!" BOX_BREAK UNSKIPPABLE "Tu trouveras " COLOR(RED) "trois endroits" COLOR(DEFAULT) " te \n"
"permettant de changer le niveau \n"
"de l'eau." BOX_BREAK UNSKIPPABLE "Je passe devant...\n"
"Suis-moi! Vite!!!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! Attention!\n"
"Cette eau n'est pas normale!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "..." BOX_BREAK UNSKIPPABLE "Tu es bien digne d'être mon futur\n"
"époux." BOX_BREAK UNSKIPPABLE "Le Domaine Zora et son peuple \n"
"vont enfin se libérer des glaces."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dis bien merci à Sheik de ma part." FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ruto veut me remercier?" BOX_BREAK UNSKIPPABLE "Je vois...." BOX_BREAK UNSKIPPABLE "C'est aussi pour elle que nous \n"
"devons ramener paix et joie \n"
"en Hyrule."
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Nous voyons...\n"
"La Princesse Ruto est dans le \n"
"Temple de l'Eau..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Comme récompense...\n"
"Je t'offre mon amour éternel." BOX_BREAK UNSKIPPABLE "Même si pour l'instant je ne peux\n"
"t'en offrir davantage."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La Princesse Zelda...Elle est en vie.\n"
"Je le sens. Ne te décourage pas."
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x42") "Beuâââârk!\n"
SHIFT("\x17") "C'est quoi? Une pieuvre?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "En tant que " COLOR(BLUE) "Sage de l'Eau" COLOR(DEFAULT) "," COLOR(BLUE) " \n"
COLOR(DEFAULT) "mon devoir est d'assurer la garde \n"
"du Temple de l'Eau..." BOX_BREAK UNSKIPPABLE "Le tien est de chercher la \n"
"Princesse...comment...?\n"
COLOR(RED) "Zelda" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Ha!\n"
"Tu ne peux rien me cacher!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ta quête de justice et de paix \n"
"sera victorieuse...j'en suis sûre.\n"
"Prends ce " COLOR(BLUE) "Médaillon " COLOR(DEFAULT) "et garde-le\n"
"précieusement!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Toi! Qui es-tu?!" BOX_BREAK UNSKIPPABLE "Je suis " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Princesse des Zoras." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Quoi?!" QUICKTEXT_DISABLE "\n"
"Mon père t'a demandé de me \n"
"sauver?" BOX_BREAK UNSKIPPABLE "Je n'ai " QUICKTEXT_ENABLE "rien" QUICKTEXT_DISABLE " demandé à personne!" BOX_BREAK UNSKIPPABLE "\"Un message dans une bouteille?\" \n"
"Je ne " QUICKTEXT_ENABLE "vois pas" QUICKTEXT_DISABLE " de quoi tu parles!" BOX_BREAK UNSKIPPABLE "Mon père est très inquiet?" BOX_BREAK UNSKIPPABLE "J'm'en " QUICKTEXT_ENABLE "fiche!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "De toute façon, je ne peux pas \n"
"partir maintenant.\n"
"Quant à toi..." QUICKTEXT_ENABLE "Va-t'en d'ici!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Compris?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu es encore là, toi?\n"
"Je t'ai dit de partir!" BOX_BREAK UNSKIPPABLE "Je vais dans le ventre de \n"
"Jabu-Jabu depuis que je suis toute \n"
"petite! Alors j't'ai pas attendu!" BOX_BREAK UNSKIPPABLE "Le Grand Jabu-Jabu n'est pas \n"
"dans son assiette aujourd'hui..." BOX_BREAK UNSKIPPABLE "Il y a d'étranges méduses \n"
"électriques et des trous partout..." BOX_BREAK UNSKIPPABLE "Et en plus, ma chère pierre a été...\n"
QUICKTEXT_ENABLE "Mais c'est pas tes oignons!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Toi! " QUICKTEXT_ENABLE "Tu rentres chez toi!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Compris?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu t'inquiètes tant que ça pour \n"
"moi?" BOX_BREAK UNSKIPPABLE "Alors je t'accorde l'honneur de me\n"
"porter!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Toutefois" QUICKTEXT_DISABLE "...Je ne partirai pas \n"
"sans avoir trouvé ce que je \n"
"cherche. Tu peux en être sûr!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ho! Vilain!" QUICKTEXT_DISABLE "\n"
"Tu m'as abandonnée?!\n"
"Comment oses-tu faire une chose\n"
"pareille à une Princesse?" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Voilà!" QUICKTEXT_DISABLE "\n"
"C'est ça que je cherche!\n"
"Lance-moi sur cette plate-forme!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "La Princesse Ruto trouve la \n"
COLOR(BLUE) "Pierre Ancestrale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Mais" TEXT_SPEED("\x00") " pourquoi la Princesse Ruto?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Enfin!\n"
"J'ai trouvé... \n"
"La Pierre de ma maman..." BOX_BREAK UNSKIPPABLE "J'étais tellement triste quand le\n"
"Grand Jabu-Jabu l'a avalée..." BOX_BREAK UNSKIPPABLE "Tout ça s'est passé pendant son\n"
"repas... Il s'est agité et m'a avalée\n"
"d'un seul coup!" BOX_BREAK UNSKIPPABLE "Bon...on peut partir maintenant!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ramène-moi à la maison!\n"
"Tout de suite!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jeu du plongeon: 20 Rubis.\n"
"Tu veux essayer?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47") "PARFAIT!" QUICKTEXT_DISABLE  BOX_BREAK "Ramasse tous les rubis avant la \n"
"fin du chrono!" BOX_BREAK "Passe cette épreuve et reviens me \n"
"voir pour gagner un prix!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hé! Félicitations!" QUICKTEXT_DISABLE "\n"
"J'ai un beau cadeau pour toi! \n"
"Viens vite le chercher!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quel magnifique plongeon!\n"
"Prends donc ceci!" BOX_BREAK UNSKIPPABLE "Cette \"" COLOR(RED) "écaille" COLOR(DEFAULT) "\" de Zora te\n"
"permettra de plonger plus \n"
"profondément." EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Les flots s'élèvent... \n"
"Et le mal se dissout...\n"
"Tu as triomphé " NAME "!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je te crois capable de sauver ce \n"
"monde..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Regarde, " NAME "..." BOX_BREAK UNSKIPPABLE "La bête maléfique a péri. \n"
"Toi et la Princesse Ruto avez\n"
"accompli cet acte héroïque!" BOX_BREAK UNSKIPPABLE "Les eaux pures et claires \n"
"emplissent à nouveau ce paisible \n"
"lac..."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(RED) "Et c'est parti!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Passe les cascades pour un \n"
"raccourci!" EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Attrape un maximum pour 20 Rubis.\n"
"Ca te tente?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hé! Bravo!!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Les ventes sont faibles..." BOX_BREAK "Je t'en propose...\n"
COLOR(RED) "10 Rubis" COLOR(DEFAULT) " pièce?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Leur succès est médiocre." BOX_BREAK "Je t'en propose...\n"
COLOR(RED) "20 Rubis" COLOR(DEFAULT) " pièce?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Ils sont assez populaires..." BOX_BREAK COLOR(RED) "30 Rubis" COLOR(DEFAULT) " pièce.\n"
"T'en veux?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Ils sont à la mode!" BOX_BREAK COLOR(RED) "40 Rubis" COLOR(DEFAULT) " pièce.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Il ne m'en reste que très peu!" BOX_BREAK COLOR(RED) "50 Rubis" COLOR(DEFAULT) " pièce.\n"
"(Offre spéciale)\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Ils sont siiiii bons!" BOX_BREAK "Super promo!\n"
COLOR(RED) "60 Rubis " COLOR(DEFAULT) "pièce!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Ca marche du tonnerre!" BOX_BREAK "Promo de la mort!\n"
COLOR(RED) "70 Rubis" COLOR(DEFAULT) " pièce!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Ils sont introuvables!" BOX_BREAK "Offre de folie!\n"
COLOR(RED) "80 Rubis" COLOR(DEFAULT) " pièce!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui \n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"C'est cher mais...c'est cool!" BOX_BREAK "Je ne peux les lâcher à moins de\n"
COLOR(RED) "90 Rubis" COLOR(DEFAULT) " pièce!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Miam miam miam...\n"
"Veux-tu des " COLOR(RED) "haricots magiques" COLOR(DEFAULT) "?\n"
"Combien??? Devine!!!! \n"
"Hé hé hé..." BOX_BREAK COLOR(RED) "100 Rubis pièce" COLOR(DEFAULT) "!\n"
"Wouahahahahaha!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha! Bon...\n"
"Miam miam..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pas assez d'argent! \n"
"J'vais pas te les donner pour \n"
"rien! Miam miam..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Assigne un haricot à " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "et \n"
"plante-le dans la terre à côté."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dommage! Je suis en rupture de\n"
"de stock! Miam miam...Comment?\n"
"Non! Ces haricots ne sont pas à \n"
"vendre! C'est mon goûter..."
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu trouveras de nombreux trous\n"
"pour planter tes haricots...\n"
"Cherche bien!!!\n"
"Miam miam miam."
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "un mètre" COLOR(DEFAULT) ". \n"
"C'est pas terrible."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "2 mètres" COLOR(DEFAULT) ". \n"
"C'est pas terrible."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "3 mètres" COLOR(DEFAULT) ". \n"
"C'est pas terrible."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "4 mètres" COLOR(DEFAULT) ". \n"
"Ce n'est pas assez."
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "5 mètres" COLOR(DEFAULT) ". \n"
"Ce n'est pas assez."
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "6 mètres" COLOR(DEFAULT) ". \n"
"Tu peux faire mieux."
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sans que tu le saches, je \n"
"t'observais... \n"
"Tu viens de plonger à " COLOR(RED) "7 mètres" COLOR(DEFAULT) ". \n"
"Tu peux faire mieux."
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sans que tu le saches, je\n"
"t'observais...\n"
"Tu as " COLOR(RED) "touché le fond" COLOR(DEFAULT) ". Tu es fort!\n"
"Prends ceci en récompense!"
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es le meilleur plongeur du \n"
"monde... Peut-être devrais-tu \n"
"plonger dans le Lac Hylia?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mon nom est " COLOR(RED) "Pierre" COLOR(DEFAULT) " l'épouvantail! \n"
"J'adore les rythmes entraînants! \n"
"Mais je suis planté ici..."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Superbe mélodie! \n"
"Elle fait bouger mon p'tit corps!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"N'hésite pas à revenir me chanter\n"
"quelque chose!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Cette mélodie est gravée au fond\n"
"de mon coeur...\n"
"Joue-la encore une fois!" EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je garde cette mélodie au fond \n"
"de mon coeur!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La partie de pêche te coûtera...\n"
COLOR(RED) "20 Rubis" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ha! Tu n'as pas de " COLOR(RED) "Kit Vibration" COLOR(DEFAULT) "! \n"
"Tu ne pourras malheureusement \n"
"pas sentir les poissons taquiner \n"
"ton hameçon." BOX_BREAK "Pas de vibrations pour toi!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Whoa! Tu as un " COLOR(RED) "Kit Vibration" COLOR(DEFAULT) "!\n"
"Tu pourras sentir les poissons\n"
"taquiner ton hameçon!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Dommage! Tu n'as pas assez\n"
"d'argent!"
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bon! Je t'explique!" BOX_BREAK "Approche-toi du bord de l'eau et \n"
"appuie sur " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " pour repérer un\n"
"poisson." BOX_BREAK "Envoie ta ligne vers ce poisson \n"
"avec " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "  puis appuie sur " COLOR(BLUE) "[A] " COLOR(DEFAULT) "pour\n"
"arrêter le déroulement de la ligne." BOX_BREAK "Remue l'appât avec " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " ou utilise\n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "si tu es un débutant!" BOX_BREAK "Remonte ta ligne avec " COLOR(BLUE) "[A] " COLOR(DEFAULT) "et \n"
"appuie sur " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "pour l'enrouler \n"
"plus vite." BOX_BREAK "Si tu sens une touche, accroche-la\n"
"avec " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "et " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "vers le bas. \n"
"Remonte ensuite la ligne avec " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Tu as bien tout compris?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je suis très généreux aujourd'hui!\n"
"Tu peux pêcher aussi longtemps \n"
"que tu le désires... Mais tu ne \n"
"pourras conserver qu'un poisson." BOX_BREAK "Le poisson le plus gros jamais \n"
"attrapé pèse " COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "." BOX_BREAK "Au fait! Change ton angle de vue\n"
"avec " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "après avoir jeté ta ligne." BOX_BREAK SHIFT("\x20") "Allez hop! A la pêche!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wah ha ha ha ha!\n"
"As-tu accroché ce poisson en \n"
"appuyant sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " et " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "en bas?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Que s'est-il passé?\n"
"Tu as perdu ta prise!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mouais... Il pèse " COLOR(RED)  FISH_INFO " livres." COLOR(DEFAULT) "\n"
"Veux-tu le garder?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Que veux-tu?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Peser mon bô poisson!\n"
"Discuter un peu\n"
"Partir" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La passion seule ne fait pas le \n"
"bon pêcheur!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B") "WHOAAAA!" BOX_BREAK "Ce poisson est é-norme! C'est un \n"
"nouveau record! Il pèse au bas\n"
"mot " COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "! Vraiment! \n"
"Tiens voilà ton prix!" EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Héééé! \n"
"J'suis pas un poisson moi!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé! P'tite tête! T'as pas un truc\n"
"plus important à faire?" BOX_BREAK "Quoi? Tu trouves que c'est plus\n"
"drôle de jouer ici?" BOX_BREAK "Y'en a beaucoup qui sont morts\n"
"en faisant ça! C'est mauvais pour\n"
"la santé! Sérieux!\n"
"Enfin bon..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Plus gros poisson jamais pêché.\n"
"Poids:  " FISH_INFO " livres.\n"
"Pêcheur: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu continuer à pêcher?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il ne pèse que:  " COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "...\n"
"Y'a plus gros, c'est sûr!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ben alors! C'est pas la forme?" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu veux essayer un autre appât?\n"
"N'as-tu pas confiance en moi?\n"
"N'aimes-tu pas mon matériel?" BOX_BREAK "On dit souvent:\n"
"\"Le bon pêcheur ne décide jamais\n"
"de ses appâts!\""
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi? Tu veux connaître ma \n"
"technique secrète de pêche?\n"
"Ben justement, ma technique...\n"
"Elle est secrète..."
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi? Tu veux savoir si je suis \n"
"un bon pêcheur!" BOX_BREAK "T'étais pas né que le grand \n"
"Jabu-Jabu se balançait au bout de\n"
"ma ligne! \n"
"J'suis un pro! Une pointure!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Règlement:" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Ne pas utiliser d'appâts coulants.\n"
"2. Ne pas cracher dans l'étang.\n"
"3. Rester calme." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "4. Ne pas jeter sa ligne sur \n"
"le patron.\n"
"5. Ne pas utiliser de bombes." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wooaa! Quel gros morceau!\n"
"Voyons voir... Il pèse...\n"
COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "!" BOX_BREAK "Veux-tu le garder?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Reviens une fois plus grand!\n"
"Les poissons auront grandi aussi!\n"
"Wha ha ha ha...hmm...hmm."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hé, jeune homme! Je me souviens \n"
"de toi! Cela fait un bail!" BOX_BREAK UNSKIPPABLE "Combien d'années? Sept?! \n"
"Alors...quelles nouvelles?!" BOX_BREAK UNSKIPPABLE "Moi? Bof....\n"
"Tu es mon seul client. \n"
"Je n'ai plus de boulot.\n"
"Les temps sont durs!" BOX_BREAK UNSKIPPABLE "En plus mes cheveux..." BOX_BREAK UNSKIPPABLE "Enfin...\n"
"C'est un charme dont j'me passe." BOX_BREAK UNSKIPPABLE "Bon...tu veux pêcher?\n"
COLOR(RED) "20 Rubis" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi?" BOX_BREAK "Tu veux pêcher ailleurs? \n"
"T'es fou!?" BOX_BREAK "Qu'est-ce que je vais devenir?"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi?" BOX_BREAK "Pourquoi j'me gratte tout l'temps?\n"
"Mais...j'me gratte pas!\n"
"T'es un p'tit marrant, toi!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi?" BOX_BREAK "L'eau est trop sombre?\n"
"Les poissons ne mordent pas?" BOX_BREAK "Mais.... N'importe quoi!\n"
"C'est le meilleur moment pour\n"
"pêcher!" BOX_BREAK "Un énorme poisson peut mordre à\n"
"n'importe quel moment!\n"
"C'est ça la grande aventure de la\n"
"pêche, mon p'tit bonhomme!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé! Ho non! C'est interdit, ça!\n"
"Rends-moi mon chapeau ou \n"
"j't'accroche à mon hameçon!" BOX_BREAK "Tu m'cherches ou quoi?\n"
"Rends-le moi!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Jamais!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quoi? Humm? Oh?\n"
"Je crois que ce poisson est plus\n"
"petit que ta précédente prise..." BOX_BREAK "Tu veux vraiment le garder?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Non\n"
"Oui" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Peuchère! Il est bizarre ce \n"
"poisson! En plus il pèse\n"
COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "!" BOX_BREAK "Veux-tu le garder?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "Mmmm? C'est quoi ce truc?" BOX_BREAK "C'est pas un...? Incroyable!\n"
"Vous trouvez un " COLOR(RED) "appât coulant" COLOR(DEFAULT) "!" BOX_BREAK "Voulez-vous l'utiliser maintenant?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Jamais!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Voyons, voyons..." BOX_BREAK "WOW! C'est pas commun!\n"
"C'est un " COLOR(RED) "brochet Hylien" COLOR(DEFAULT) "!" BOX_BREAK "Ce poisson est si rare, son poids \n"
"n'est pas important... \n"
"Voilà ton prix!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ce type de poisson se fait rare.\n"
"Je vais le relâcher." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Règlement:\n"
"1. Ne pas utiliser d'appâts coulants.\n"
"2. Ne pas utiliser de bombes.\n"
"3. Rester calme." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Holà! Holà!\n"
"Les cannes ne sortent pas d'ici!" BOX_BREAK "Ta journée de pêche finie, \n"
"rapporte ta canne au patron!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohhhh mon Dieuuuuu!!!\n"
"Ce poisson est énooooorme!!" BOX_BREAK "Il ne tient même pas à l'écran! \n"
"J'peux pas l'peser... Il va faire \n"
"imploser ma balance!!! \n"
"Il doit faire " COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "!" BOX_BREAK "Tu veux garder ce monstre, hein?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Le garder" COLOR(DEFAULT) "\n"
COLOR(ADJUSTABLE) "Ne pas le garder" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé! P'tit mec!\n"
"Moi c'est " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", l'épouvantail!\n"
"j'ai une mémoire fabuleuse!" BOX_BREAK "N'hésite pas à me jouer une\n"
"super mélodie!" BOX_BREAK "Voilà la mélodie que tu m'as jouée\n"
"la dernière fois, mec!" BOX_BREAK "Chauffe, petit!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je suis " COLOR(RED) "Bonooru" COLOR(DEFAULT) " l'épouvan-tail \n"
"musi-cal et gé-nial!\n"
"Moi...J'n'oublie jamais une mélodie!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Entonne ta mélodie pour appeler \n"
"mon copain Pierre! \n"
"Il apparaîtra s'il se trouve dans \n"
"l'coin, mec!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé! N'es-tu pas le p'tit mec à la\n"
"fée d'il y a sept ans?\n"
"Wow! T'as bien grandi!" BOX_BREAK "Tiens voilà ta mélodie..." BOX_BREAK "Quoi?" BOX_BREAK "Non, moi j'oublie rien!\n"
"Alors joue ta mélodie pour voir...\n"
"Tu l'as peut-être oubliée, qui sait?\n"
"Joue, mec! Joue!!!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Whaouuu! Tu as un ocarina!\n"
"Pourquoi ne pas en pousser une \n"
"petite?" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Mmmmm.... Pas mal!\n"
"Je vais l'enregistrer pour toi!" BOX_BREAK "A la différence de Pierre, je peux\n"
"mémoriser n'importe quelle chanson,\n"
"même très longue! Mais ne \n"
"retenons que cette partie, OK?" EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"C'est mal! \n"
"Jouer de cette façon ne fera \n"
"jamais bouger mon p'tit corps!!!" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"HO YEAHHH!!\n"
"C'est ça! C'est la mélodie!!\n"
"Ca balance!! Je suis soufflé!" BOX_BREAK "Je n'ai pas oublié cette mélodie...\n"
"Je n'oublie jamais rien! \n"
"Je vais te récompenser, mec!" BOX_BREAK "........\n"
"J'ai une idée!" BOX_BREAK "Mon pote Pierre se balade dans le\n"
"coin! Joue cette mélodie et il\n"
"apparaîtra...peut-être!" BOX_BREAK "Je vais lui dire de t'aider au \n"
"son de ton ocarina!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hé! C'est un ocarina!\n"
"Joue ta chanson, mec!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Quel chant délicieux!\n"
"Cette mélodie est très belle...\n"
"Crooâââââ! Nous allons l'apprendre\n"
"par coeur...Croooââââ !" BOX_BREAK "Prends donc ces Rubis!\n"
"N'hésite pas à revenir nous\n"
"chanter quelque chose...\n"
"Croooâââ croooâââ!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Crooooââââââ!\n"
"Cette mélodie est divine! \n"
"Croooâââââ!" BOX_BREAK "Je chaaaaannnte sous la pluie!\n"
"Croooââââ!!" BOX_BREAK "La communauté grenouille te dit:\n"
"Merci!!! A bientôt!!\n"
"Crooooâââââ!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Nous sommes les célèbres ténors \n"
"grenouillesques!!! Les stars de \n"
"l'étang! Croooââââ!!" BOX_BREAK "Fais-nous sauter pour avaler les\n"
"insectes! Croooââââ!!!" BOX_BREAK "D'accord? \n"
"Trois, deux, un, PARTEZ!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Fantastique! Délicieux!\n"
"Un repas bien équilibré!\n"
"Crooooââââââ!" BOX_BREAK "Gros crapauds et belles grenouilles\n"
"te disent: Merci! Burp." EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je ne me souviens pas de cette \n"
"chanson, mec! \n"
"Pourquoi? J'sais pas moi!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Le plus gros poisson pêché dans \n"
"cet étang pèse: " FISH_INFO " livres.\n"
"Pêcheur: le patron " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? Tu veux pêcher avec un \n"
"autre appât?\n"
"...Hé! C'est quoi ça?" BOX_BREAK "Quoi? Tu l'as trouvé? Mon oeil!\n"
"Tu n'as pas le droit d'utiliser ça! \n"
"C'est le règlement!\n"
"Enfin...je passe l'éponge..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHOOOOOAAAAAAOOOO!\n"
"Il est E-N-O-R-M-E!!! \n"
"Tu as pulvérisé le record!!! \n"
"Il pèse " COLOR(RED)  FISH_INFO " livres" COLOR(DEFAULT) "!!" BOX_BREAK "Maaaaaaais...tu n'as pas utilisé un\n"
"appât réglementaire!\n"
"Donc...pas de prix pour toi!\n"
"Hé hé hé hé!!! P'tit tricheur!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Le plus gros poisson pêché dans\n"
"cet étang pèse: " FISH_INFO " livres.\n"
"Pêcheur: " NAME "\n"
"(NOTE: appât non-réglementaire!)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"T'es un bon p'tit gars!\n"
"Mais ne dis pas à tout le monde \n"
"que j'ai plus un poil sur l'caillou!" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"QUOIIIIII?!?" BOX_BREAK "Pourquoi tant de haine?\n"
"T'es un punk, toi?" BOX_BREAK "Mais j'vais pas m'laisser faire!\n"
"Paie-moi " COLOR(RED) "50 Rubis" COLOR(DEFAULT) "!\n"
"Non mais des fois!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "GYAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Tu" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "m'as" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "tué!!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Hein? Oh! C'est toi." BOX_BREAK "As-tu déjà utilisé le\n"
COLOR(YELLOW) "Chant du soleil" COLOR(DEFAULT) "?" BOX_BREAK "Comme je te l'ai déjà dit, ce chant\n"
"te permet de passer de la nuit au \n"
"jour et inversement. Et ceci à\n"
"n'importe quel moment." BOX_BREAK "Même plongé dans les ténèbres, ce \n"
"chant te viendra en aide.\n"
"N'hésite pas à souvent l'utiliser!"
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "En creusant un trou, j'ai trouvé un\n"
"truc qui fait BOING! BOING!\n"
"On dirait un ressort...\n"
"Je ne le donnerai à personne!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Vous trouvez le " COLOR(RED) "journal du \n"
"fossoyeur" COLOR(DEFAULT) "." BOX_BREAK "Désirez-vous le lire?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Toi le petit curieux qui lit ce\n"
"journal, viens dans ma tombe.\n"
"Et peut-être auras-tu droit à mon\n"
"précieux " COLOR(RED) "trésor" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Je t'attends...\n"
"--Igor" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Etre curieux, c'est pas bien..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vous avez vaincu un Esprit!" BOX_BREAK "Voulez-vous le garder dans une\n"
"bouteille?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vous n'avez malheureusement pas \n"
"de bouteille vide."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"L'Esprit peut alors s'enfuir."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vous obtenez un Esprit!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x14") "La course du soleil s'achève\n"
SHIFT("\x3B") "le soir venu...\n"
SHIFT("\x18") "Les nouvelles vies un jour\n"
SHIFT("\x3D") "se meurent..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2D") "Un soleil, une lune.\n"
SHIFT("\x30") "Un jour, une nuit." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x05") "Respecte les morts jadis vivants." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Purée... Que c'est beau!"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Entonne le " COLOR(YELLOW) "Chant du Soleil" COLOR(DEFAULT) " et \n"
SHIFT("\x11") "apaise le long tourment des \n"
SHIFT("\x3A") "âmes damnées" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Il y a quelque chose d'écrit\n"
"sur cette pierre tombale..." BOX_BREAK UNSKIPPABLE "C'est la " COLOR(YELLOW) "mélodie secrète" COLOR(DEFAULT) " des \n"
"Frères Musiciens!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Potion ultime! Que dis-tu de\n"
COLOR(RED) "100 Rubis" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Reviens me voir si tu changes\n"
"d'avis... Hé hé hé hé!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu n'as pas assez d'argent!\n"
"Hé hé hé hé!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "GYAAAAH!\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Tu" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "m'as" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "tué..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  QUICKTEXT_ENABLE "INCROYABLE!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Oh! Hein?\n"
"Tu n'es pas un soldat de \n"
"Ganondorf! Qui es-tu?" BOX_BREAK UNSKIPPABLE "Désolé de m'être comporté de la \n"
"sorte, mais... Je ne suis qu'un\n"
"fantôme, après tout!" BOX_BREAK UNSKIPPABLE "Sais-tu qui je suis? Non?\n"
"Ah bon... Alors écoute-moi bien.\n"
"Hum hum..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis un fantôme de l'un des \n"
"frères musiciens du Village \n"
"Cocorico." BOX_BREAK "Tous les habitants de ce village \n"
"sont les loyaux sujets de la Famille\n"
"Royale d'Hyrule." BOX_BREAK "Mon frère et moi-même avions\n"
"pour mission d'étudier les pouvoirs\n"
"mystiques héréditaires de la Famille\n"
"Royale." BOX_BREAK "Tout en ignorant à quoi pouvait \n"
"bien servir la célèbre Triforce," BOX_BREAK "nous fûmes sur le point d'achever\n"
"nos expériences sur le " COLOR(RED) "contrôle du" COLOR(DEFAULT) "\n"
COLOR(RED) "temps" COLOR(DEFAULT) " grâce aux ocarinas." BOX_BREAK "Plus précisément..." BOX_BREAK "Nous avons percé le mystère du \n"
"temps!" BOX_BREAK "La gloire nous tendait les bras\n"
"mais cet odieux Ganondorf tenta \n"
"de dérober le résultat d'années \n"
"d'études!" BOX_BREAK "Et c'est donc au prix de nos vies\n"
"que nous pûmes protéger le secret." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu que je répète tout ça?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "JE SUIS" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORT!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Heu..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "ENCORE?" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Gueuh?? C'est toi?" BOX_BREAK UNSKIPPABLE "Tu me fais vraiment penser à la\n"
"Princesse Zelda." BOX_BREAK UNSKIPPABLE "Tu es en si bons termes avec la\n"
"Famille Royale que je vais de ce \n"
"pas te conter la suite de notre\n"
"tragique histoire." BOX_BREAK UNSKIPPABLE "En raison de nos nombreuses\n"
"symphonies, les sujets d'Hyrule \n"
"nous élevèrent au rang de Grands\n"
"Compositeurs." BOX_BREAK UNSKIPPABLE "Mais notre rôle sur cette terre ne \n"
"se bornait pas à la composition." BOX_BREAK UNSKIPPABLE "Notre mission était d'analyser les\n"
"mystérieux pouvoirs de la Famille\n"
"Royale d'Hyrule." BOX_BREAK UNSKIPPABLE "Mais les évènements ont voulu\n"
"que le résultat de nos recherches \n"
"ne soit jamais révélé...\n"
"Pourtant la gloire nous souriait!" BOX_BREAK UNSKIPPABLE "Nos études furent gardées \n"
"secrètes jusqu'à terme...." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "JE SUIS" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORT!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Heu?" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "ENCORE?" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Quoi?? Encore toi?" BOX_BREAK UNSKIPPABLE "Tu me fais vraiment penser à la\n"
"Princesse Zelda." BOX_BREAK UNSKIPPABLE "Tu es en si bons termes avec la\n"
"Famille Royale que je vais de ce \n"
"pas te conter la suite de notre\n"
"tragique histoire." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pour être franc, chaque frère \n"
"étudiait un chant différent.\n"
"L'un pour " COLOR(RED) "invoquer le soleil " COLOR(DEFAULT) "et \n"
"l'autre pour " COLOR(RED) "invoquer la lune" COLOR(DEFAULT) "." BOX_BREAK "Si un membre de la Famille Royale\n"
"t'a envoyé jusqu'ici, je pense \n"
"pouvoir te faire confiance et te\n"
"faire partager notre secret." BOX_BREAK "Va donc examiner les inscriptions\n"
"sur la " COLOR(RED) "pierre tombale royale" COLOR(DEFAULT) "." BOX_BREAK "Toi, jeune messager de la Famille\n"
"Royale, chante haut et fort ta\n"
"loyauté sur la Sainte Triforce." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z..." BOX_BREAK "Malon...tout va bien...\n"
"Mmm...(ronfle)...Mmm...\n"
"Tout va bien..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo s'occupe du Ranch Lon Lon à\n"
"présent. On l'appelle le " COLOR(RED) "Ranch Ingo" COLOR(DEFAULT) "." BOX_BREAK "On m'a fichu dehors et...\n"
"Regarde dans quel état j'suis!\n"
"Ma fille Malon y travaille toujours." BOX_BREAK "Je me fais tant de souci..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Malon est de nouveau heureuse?\n"
"Je vais retourner au Ranch!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hé! Petit!" QUICKTEXT_DISABLE "\n"
"Laisse les tombes à leur place!" BOX_BREAK UNSKIPPABLE "Moi c'est " COLOR(RED) "Igor le fossoyeur" COLOR(DEFAULT) "!\n"
"Ma face fait peur aux mouches \n"
"mais je suis un chic type..." BOX_BREAK UNSKIPPABLE "Connais-tu l'attraction du\n"
"cimetière?\n"
"Elle s'appelle..." BOX_BREAK UNSKIPPABLE  SHIFT("\x1A")  COLOR(RED) "L'excursion du fossoyeur" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Je creuse, je creuse...\n"
"J'trouve un truc ou que dalle...\n"
"Fais-moi creuser et...\n"
"Garde tout pour ta pomme!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu veux que j'creuse ici?\n"
"C'est " COLOR(RED) "10 Rubis" COLOR(DEFAULT) " le trou.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(RED) "Y'a rien ici!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Arrière, " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "....\n"
"Un grand malheur vient de se \n"
"produire! Le " COLOR(RED) "monstre de l'ombre" COLOR(DEFAULT) " \n"
"s'est échappé!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", chef du Village Cocorico, \n"
"a jadis combattu puis enfermé le \n"
"Monstre de l'Ombre au fond du \n"
"puits...." BOX_BREAK UNSKIPPABLE "Mais depuis longtemps cette bête,\n"
"grâce à l'influence de Ganondorf, \n"
"rassemble ses forces pour enfin\n"
"recouvrer sa liberté!!!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je vais m'occuper du village!\n"
"Je compte sur toi " NAME "."
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Frère Musicien Royal\n"
SHIFT("\x3C") "Bémol l'aîné\n"
SHIFT("\x37") "Repose En Paix" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Frère Musicien Royal\n"
SHIFT("\x38") "Dièse le cadet\n"
SHIFT("\x37") "Repose En Paix" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Tombe Royale" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Cette ode est dédiée à la mémoire\n"
SHIFT("\x03") "des disparus de la Famille Royale." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Jeune garçon à l'ocarina...\n"
"Enfin tu es venu." BOX_BREAK UNSKIPPABLE "Mon nom est " COLOR(RED) "Impa" COLOR(DEFAULT) " des Sheikahs.\n"
"Je suis la nourrice de la Princesse\n"
"et le Sage du Temple de l'Ombre."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Prends bien soin de la Princesse!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", le héros!" BOX_BREAK UNSKIPPABLE "Enfin les " COLOR(RED) "six Sages " COLOR(DEFAULT) "sont éveillés!\n"
"L'heure est venue pour toi de \n"
"défier le Seigneur du Malin!" BOX_BREAK UNSKIPPABLE "Mais avant de croiser le fer avec\n"
"le vil Ganondorf, il te reste une \n"
"personne à rencontrer..." BOX_BREAK UNSKIPPABLE "Cette personne t'attend au\n"
COLOR(LIGHTBLUE) "Temple du Temps" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Depuis des siècles, les Sheikahs \n"
"furent les serviteurs secrets de \n"
"la Famille Royale d'Hyrule.\n"
"Toutefois..." BOX_BREAK UNSKIPPABLE "Il y a sept ans, Ganondorf lança\n"
"son attaque et le Château d'Hyrule \n"
"dut se rendre après une très \n"
"courte bataille." BOX_BREAK UNSKIPPABLE "Ganondorf était à la recherche\n"
"de l'une des clés du Saint \n"
"Royaume...le trésor secret de la \n"
"Famille Royale...l'Ocarina du Temps!" BOX_BREAK UNSKIPPABLE "Mon devoir était de mettre\n"
"la Princesse Zelda à l'abri." BOX_BREAK UNSKIPPABLE "Je me souviens t'avoir vu lors\n"
"de notre fuite..." BOX_BREAK UNSKIPPABLE "Tu es devenu un valeureux\n"
"guerrier..."
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mon devoir est de rester ici... \n"
"Trouve la Princesse Zelda et \n"
"protège-la à ma place." BOX_BREAK UNSKIPPABLE "Je vais maintenant te transmettre\n"
"mon pouvoir grâce à ce " COLOR(BLUE) "Médaillon" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Comment se porte ta Cocotte?\n"
"Veux-tu me la remettre?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Je suis le " COLOR(RED) "chef des ouvriers \n"
COLOR(DEFAULT) "engagé par Impa pour transformer\n"
"le village en grande ville!" BOX_BREAK UNSKIPPABLE "Mais les jeunes gens d'aujourd'hui\n"
"n'ont aucune ambition..." BOX_BREAK UNSKIPPABLE "Mes ouvriers se baladent toute\n"
"la sainte journée! Alors le travail \n"
"prend du retard et ça me rend \n"
"dingue..." BOX_BREAK UNSKIPPABLE "Même mon propre fils ne travaille\n"
"pas. Il fiche sa vie en l'air!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Inutiles et paresseux! TOUS!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Regarde-moi cette pauvre fille.\n"
"Elle s'occupe des cocottes même \n"
"en étant allergique aux plumes!\n"
"Quel courage...je l'aime..." BOX_BREAK "J'aimerais bien l'aider mais...\n"
"Les cocottes, moi ça m'énerve!\n"
"Pas toi?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La Princesse est à l'abri \n"
"maintenant..."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Très bientôt, Zelda viendra tout \n"
"t'expliquer..." BOX_BREAK UNSKIPPABLE "Une fois les six Sages réunis et\n"
"le Roi Sombre détruit, la vérité te \n"
"sera révélée."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Héhéhé, mon p'tit bouchon...\n"
"Alors t'es un rapide, hein?" BOX_BREAK UNSKIPPABLE "En récompense je te donne mon\n"
"trésor... un " COLOR(RED) "Grappin" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Cette chaîne montée sur ressort\n"
"te hissera là où sa pointe s'est\n"
"plantée. Pratique, hein?" BOX_BREAK UNSKIPPABLE "Reviens me voir et tu gagneras \n"
"peut-être un autre p'tit cadeau. \n"
"Alors à bientôt!" BOX_BREAK UNSKIPPABLE "Au fait... Bonne chance pour sortir \n"
"d'ici! Yark yark yark!"
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Te revoilà, mon bouchon...\n"
"As-tu toujours sur toi mon\n"
"p'tit cadeau?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x05") "Le temps de cette course est de\n"
SHIFT("\x4B")  RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bien... Tu reviens à toi..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Impa est partie sceller le\n"
COLOR(PURPLE) "Temple de l'Ombre" COLOR(DEFAULT) "," COLOR(BLUE) " " COLOR(DEFAULT) "mais...\n"
"Elle sera en danger si personne ne \n"
"vient lui prêter main-forte!" BOX_BREAK UNSKIPPABLE  NAME "!\n"
"Impa est l'une des six Sages.\n"
"Va détruire le Monstre de l'Ombre\n"
"et sauve Impa!" BOX_BREAK UNSKIPPABLE "L'entrée du Temple se trouve sous \n"
"le cimetière de ce village." BOX_BREAK UNSKIPPABLE "La seule chose en mon pouvoir est\n"
"de t'apprendre la mélodie t'ouvrant \n"
"le passage vers le Temple de \n"
"l'Ombre..." BOX_BREAK UNSKIPPABLE "Cet air te plongera dans les \n"
"ténèbres abyssales... \n"
"Hors du temps et de l'espace...\n"
"Entends le " COLOR(PURPLE) "Nocturne de l'Ombre" COLOR(DEFAULT) "!!"
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tourne et tourne! \n"
"Encore et encore!\n"
"Quelle fête!!!" BOX_BREAK "Je suis un joyeux musicien\n"
"qui tourne et tourne et tourne!\n"
"Danse et tourne avec moi!!!" BOX_BREAK "J'aimerais que ma chanson du \n"
"moulin fasse le tour du monde!\n"
"Tourne et tourne et tourne!!!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tourne et tourne et...hein?\n"
"Holà! Ca tourne trop vite!\n"
"Stooooooooooooooop!!!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!" BOX_BREAK "Si jamais je retrouve ce môme...\n"
"Je lui écrase la tête!\n"
"Grrrrrrrrr!" BOX_BREAK "Il y a sept ans, il a tout détraqué \n"
"mon beau moulin avec son ocarina!\n"
"Si jamais je le retrouve...\n"
"Ping! Vlan! Dans les dents!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quoi?! Tu as un ocarina!!\n"
"Nom d'un chou-péteur!\n"
"Comme ce môme, il y a sept ans..." BOX_BREAK UNSKIPPABLE "Il est arrivé ici comme une fleur\n"
"et il a joué une " COLOR(PURPLE) "curieuse mélodie" COLOR(DEFAULT) ". \n"
"Mon moulin est ensuite devenu \n"
"complètement dingue!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que dois-je faire!?\n"
"Mes " COLOR(RED) "Cocottes" COLOR(DEFAULT) " sont perdues!" BOX_BREAK "Aide-moi, mon petit!\n"
"Dépose toutes les cocottes dans\n"
"cet enclos!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mes Cocottes sont perdues!\n"
"Dépose encore quatre cocottes \n"
"dans l'enclos!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mes Cocottes sont perdues!\n"
"Dépose encore trois cocottes \n"
"dans l'enclos!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mes Cocottes sont perdues!\n"
"Dépose encore deux cocottes \n"
"dans l'enclos!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mes Cocottes sont perdues!\n"
"Dépose encore une cocotte dans \n"
"l'enclos!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Merci d'avoir retrouvé mes\n"
"cocottes. Mon allergie aux plumes\n"
"est vraiment pénible!" BOX_BREAK UNSKIPPABLE "Voici un petit quelque chose\n"
"pour te remercier..." EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mais que fais-tu?!\n"
"Rassemble-les dans l'enclos ou \n"
"paie le prix fort!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sois gentil avec les cocottes!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "J'élève une nouvelle espèce de\n"
"Cocotte: les " COLOR(RED) "Cocottes de Poche" COLOR(DEFAULT) "! \n"
"Je n'y suis plus allergique!" BOX_BREAK UNSKIPPABLE "Les " COLOR(RED) "Cocottes " COLOR(DEFAULT) "font d'excellents \n"
"réveils! Fais donc l'essai avec\n"
"quelqu'un de paresseux!" BOX_BREAK UNSKIPPABLE "Leur chant est si mélodieux...\n"
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(RED) "COCOOOOOOTTE" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Surtout lorsqu'un gros dormeur\n"
"se trouve à proximité! Hi hi hi!" BOX_BREAK UNSKIPPABLE "Toutefois... Mes cocottes ne sont\n"
"pas toutes heureuses..." BOX_BREAK UNSKIPPABLE "Dis-moi... \n"
"Tu m'as l'air d'aimer les cocottes!\n"
"Je me trompe?" BOX_BREAK UNSKIPPABLE "Tiens, prends cet oeuf.\n"
"Après l'apparition d'une cocotte,\n"
"reviens me voir et nous \n"
"examinerons son humeur." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Qu'en penses-tu? \n"
"L'idée t'intéresse?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Mouais\n"
"Bof" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dommage... \n"
"Les cocottes te font-elles peur?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé hé! Mon p'tit bouchon...\n"
"Tu t'crois rapide?" BOX_BREAK "J'ai peut-être la trogne de\n"
"travers mais... Je fonce comme \n"
"une flèche! On fait la course?"
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sois gentil avec ma cocotte!\n"
"D'accord?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh! Ta cocotte est en pleine \n"
"forme! Tu as sûrement réveillé\n"
"quelqu'un de très paresseux!" BOX_BREAK UNSKIPPABLE "Tu aimes les cocottes à la folie!\n"
"Je vais te donner une cocotte \n"
"très rare..." BOX_BREAK UNSKIPPABLE "Son nom est " COLOR(RED) "P'tit Poulet" COLOR(DEFAULT) "!\n"
"Mon frère s'en occupait...\n"
"Ses plumes bleues sont si douces!" BOX_BREAK UNSKIPPABLE "Depuis le départ de mon frère,\n"
"P'tit Poulet n'a pas chanté une \n"
"seule fois...." TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu garder " COLOR(RED) "P'tit Poulet" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es amoureux de ta cocotte!\n"
"C'est génial! Garde-la encore un \n"
"peu et reviens me voir quand le\n"
"P'tit Poulet t'intéresse..." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Une vieille bique a ouvert une\n"
"boutique derrière celle-ci.\n"
"Va à gauche du comptoir pour y\n"
"accéder." EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon frère devait se sentir bien\n"
"seul..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'on dit souvent que de par les\n"
COLOR(ADJUSTABLE) "Bois Perdus" COLOR(DEFAULT) ", d'étranges senteurs \n"
"vous titillent les naseaux...\n"
"Gniii gniii gniii..." BOX_BREAK "Il me plairait tant de cueillir \n"
"maintes et diverses choses en un \n"
"tel lieu... Gniii gniii gniiii!" BOX_BREAK "Mes yeux ne sont plus que l'ombre\n"
"d'eux-mêmes mais mes saintes \n"
"narines sont si fines...C'est fou! \n"
"Gniii gniii gniii!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sniff sniff sniff..." BOX_BREAK "Dieu! Quelle étrange senteur..." BOX_BREAK "Qu'as-tu dans ta besace?"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jeune fou! Perdu dans la forêt...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "Je vois." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Remets-le moi prestement!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dommage...Gniiii..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Va donc tendre à ce jeune insensé\n"
"cette mixture. Gniii niiii!\n"
"Elle est puissante! C'est dingue!" BOX_BREAK UNSKIPPABLE "Allez...dehors maintenant! Gnii!" EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Jeune homme! Il te faut un \n"
"récipient pour transporter une\n"
"potion!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'on dit de par les villes qu'un\n"
"jeune sot dans les bois se perd,\n"
"sa vie n'est plus que poussière.\n"
"C'est complètement fou!"
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'suis coincé ici...ça craint.\n"
"Alors je regarde le " COLOR(RED) "Mont du Péril" COLOR(DEFAULT) ".\n"
"Et alors ça...ça craint à mort."
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'suis coincé ici...ça craint.\n"
"Alors je regarde les étoiles.\n"
"Et alors ça...ça craint à mort."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"T'as vu? Là-haut! \n"
"Il se passe quelque chose sur le\n"
COLOR(RED) "Mont du Péril" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as remarqué?\n"
"Le " COLOR(RED) "Mont du Péril " COLOR(DEFAULT) "est devenu normal!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je n'ai plus envie de descendre!\n"
"Je ne me lasserai jamais d'admirer\n"
"le Mont du Péril."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé! Comment vas-tu?\n"
"C'est mon jour de bonté...\n"
"Prends donc ceci!"
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Admire les environs avec " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " et \n"
"utilise ensuite le " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Dis donc petit! Cela t'arrive \n"
"souvent d'entrer chez les gens \n"
"comme ça? Tu te crois où?\n"
"Chez ta p'tite soeur?" BOX_BREAK UNSKIPPABLE  SHIFT("\x1E") "Enfin...je passe l'éponge." BOX_BREAK UNSKIPPABLE "As-tu rencontré une gentille\n"
"fille derrière cette maison?\n"
"Elle a de gros ennuis." BOX_BREAK UNSKIPPABLE  SHIFT("\x2D") "Tu m'écoutes, oui?" TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Si cette fille te parle de ses\n"
"cocottes, écoute-la attentivement."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Non mais tu rentres chez les gens\n"
"comme ça, toi? Et en pleine nuit?\n"
"Tu serais pas un p'tit peu malade?\n"
"Tu t'crois où? Au zoo?" BOX_BREAK UNSKIPPABLE  SHIFT("\x1E") "Enfin...je passe l'éponge." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La fille derrière chez moi s'occupe\n"
"de cocottes mais elle est allergique\n"
"aux plumes...\n"
"Pfff... J'te jure..." BOX_BREAK SHIFT("\x0D") "Enfin...après tout...j'm'en fiche."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Dites donc jeune homme! \n"
"Cela vous prend souvent d'entrer\n"
"chez les autres comme ça?\n"
"Vous vous croyez dans une gare?" BOX_BREAK UNSKIPPABLE  SHIFT("\x1E") "Enfin...je passe l'éponge." BOX_BREAK UNSKIPPABLE "Ce n'est même pas chez moi ici.\n"
"C'est la maison de la " COLOR(RED) "noble Impa" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Impa est allée au " COLOR(RED) "cimetière" COLOR(DEFAULT) " pour y\n"
"enfermer une sale bête." BOX_BREAK UNSKIPPABLE "Depuis la venue de Ganondorf, de\n"
"nombreux monstres sont apparus \n"
"dans les environs." BOX_BREAK UNSKIPPABLE "Seule la grande Impa a su \n"
"préserver la paix dans notre \n"
"village. Ne l'oubliez jamais!" BOX_BREAK UNSKIPPABLE  SHIFT("\x2D") "Enfin...après tout..." BOX_BREAK UNSKIPPABLE "Au fait! Impa n'est toujours pas\n"
"revenue du cimetière! Lui est-il\n"
"arrivé malheur?" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il paraît que le " COLOR(RED) "spectre du \n"
"fossoyeur " COLOR(DEFAULT) "se balade souvent dans\n"
"le cimetière, la nuit tombée..." BOX_BREAK SHIFT("\x1F") "Enfin...moi j'y crois pas."
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hé! Petit! C'est la première fois\n"
"que tu visites ce village?" BOX_BREAK UNSKIPPABLE "Une noble dame, " COLOR(RED) "Impa" COLOR(DEFAULT) ", a créé ce\n"
"village pour nous, pauvres paysans." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Fais comme chez toi..."
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La noble Impa n'est pas ici. \n"
"Lui est-il arrivé quelque chose?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Les habitants ont tous de \n"
"douloureux souvenirs...\n"
"Enfouis dans leur mémoire." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Regarde ce gros moustachu...\n"
"Même lui a souffert par le passé..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Le gros moustachu est parti au \n"
"Ranch. Il était si joyeux!"
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ding dong, ding dong!\n"
"Je suis le soldat-pendule!\n"
"Au quatrième top il sera: " TIME "." BOX_BREAK UNSKIPPABLE "Bonjour mon ami!\n"
"La nourrice de Zelda, " COLOR(RED) "Impa" COLOR(DEFAULT) ", a  \n"
"fondé ce village." BOX_BREAK UNSKIPPABLE "Nous ne sommes que très peu\n"
"d'habitants pour l'instant mais\n"
"un jour ce village sera aussi\n"
"important que le bourg d'Hyrule!" BOX_BREAK UNSKIPPABLE "Les " COLOR(RED) "escaliers au nord" COLOR(DEFAULT) " du village\n"
"mènent au Mont du Péril." BOX_BREAK UNSKIPPABLE "Mais ce chemin n'est ouvert que \n"
"sur présentation d'un écrit royal."
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"Au quatrième top il sera: " TIME "."
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"Au quatrième top il sera: " TIME ".\n"
"Au fait... \n"
"Que s'est-il passé au château?"
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé! L'ami... Que fais-tu dehors\n"
"à une heure pareille?" BOX_BREAK UNSKIPPABLE "Oh! Je vois! Tu mets ton courage\n"
"à l'épreuve, hein? Alors pourquoi \n"
"ne pas aller au...cimetière?" BOX_BREAK UNSKIPPABLE "Allez, circule!\n"
"J'ai du travail!" TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"Au quatrième top il sera: " TIME "." BOX_BREAK "A l'Est du village tu trouveras le\n"
COLOR(RED) "cimetière" COLOR(DEFAULT) ". On dit souvent qu'une\n"
COLOR(BLUE) "mélodie de la Famille Royale " COLOR(DEFAULT) "a le\n"
"pouvoir d'apaiser les âmes..."
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un type louche vit dans le moulin.\n"
"Il chante toute la sainte journée \n"
"et sa voix me tape sur les nerfs..."
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les gens me dégoûtent.\n"
"Mes parents me dégoûtent.\n"
"Ta p'tite tête me dégoûte."
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Toute la journée, nous travaillons\n"
"sur les chantiers... Cela va \n"
"prendre du temps avant que tout \n"
"soit terminé." BOX_BREAK "Notre chef nous fait travailler \n"
"dur!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"J'ai faim! On passe à table tout \n"
"de suite? Et après ça une bonne \n"
"sieste et...hop! Au lit!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Vous n'êtes tous que de gros\n"
"flemmards! Le travail n'avance pas\n"
"et vous ne pensez qu'à bouffer!\n"
"JE VOUS HAIS!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Esprit   30 Rubis\n"
COLOR(DEFAULT) "Spectre en bouteille. \n"
"A vendre à un passionné." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Esprit  30 Rubis" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mes cocottes sont perdues!\n"
"Dépose six cocottes dans l'enclos!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME "!\n"
"Ce navire sombre!\n"
"Vite! Mets-toi à l'abri!!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il me manque encore des cocottes!\n"
"Dépose encore 5 cocottes!"
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Sois sage ou j'le dirai à Igor!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Regarde-moi ça! Je me suis cassé\n"
"un ongle en travaillant.\n"
"C'est super moche!\n"
"Pffff...."
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Travailler...moi j'aime pas.\n"
"Je veux devenir un voleur. \n"
"Un grand voleur! Avec des bottes\n"
"rouges et une cape! Cool, non?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il paraît que la maison du chef \n"
"est derrière celle-ci...\n"
"Et si on la brûlait? Hein?"
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As-tu déjà rencontré " COLOR(RED) "Igor" COLOR(DEFAULT) "?\n"
"Il vit dans le cimetière du village." BOX_BREAK "Il est " TIME "... Il doit dormir dans \n"
"sa cabane à cette heure-ci." BOX_BREAK "Pourquoi ne pas te balader sur\n"
"la Plaine d'Hyrule en attendant?"
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"J'ai faiiiim !!  !\n"
"On va manger?\n"
"Il est déjà " TIME "!"
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ici vivait autrefois la " COLOR(RED) "noble Impa" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Cette maison est ouverte à tous \n"
"les villageois. \n"
"L'entrée est gratuite." TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ce village fut jadis un repaire\n"
COLOR(BLUE) "Sheikah " COLOR(DEFAULT) "mais la noble Impa en fit\n"
"une terre d'accueil."
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mais j'en suis sûr! J'l'ai vu!" BOX_BREAK "J'ai vu le fantôme d'Igor entrer \n"
"dans sa tombe! Il portait même un\n"
COLOR(RED) "trésor" COLOR(DEFAULT) "... J'te l'jure!"
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est lui! C'est lui!\n"
"Il est tombé du ciel entouré d'une\n"
"lumière bleue! J'ai tout vu!" BOX_BREAK "Tu me crois, hein?"
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Depuis bientôt sept ans, personne \n"
"ne veut croire à mes histoires.\n"
"C'est agaçant à la fin!"
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le village fut ravagé mais nous \n"
"avons pu maîtriser le feu!\n"
"Beau boulot, hein?"
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!" BOX_BREAK "Mate-moi ce type! Depuis son \n"
"évasion du Bourg d'Hyrule, il est\n"
"devenu un méga-froussard!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!" BOX_BREAK "Ce type a des visions!\n"
"Wah hah hah hah hah hah!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wah hah hah hah hah hah!\n"
"Elles sont chouettes tes fringues!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wah hah hah hah hah hah!\n"
"Mon truc à moi c'est rigoler!\n"
"Wah hah hah hah hah hah!"
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ya-ha-ha! Je suis le roi du monde!\n"
"J'adore regarder les gens d'ici!\n"
"Ils sont si petits!"
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai peur de m'endormir...\n"
"Je risquerais de tomber!"
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le moulin draine l'eau du puits..." BOX_BREAK "Mais le puits est à sec depuis un \n"
"bon moment..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La fille du coin est vraiment\n"
"gentille... Elle s'est même occupée\n"
"des ouvriers."
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Il y a bien longtemps...\n"
"Le regard perçant d'un habitant de \n"
"ce village permettait à celui-ci de \n"
"voir la vérité!" BOX_BREAK "La vérité est une notion plus \n"
"philosophique que visuelle.\n"
"La percevoir est le fruit d'un long\n"
"travail intellectuel..." BOX_BREAK "Mais cet homme avait une autre \n"
"façon de procéder..." BOX_BREAK "Le puits fut construit là où\n"
"se trouvait sa maison..."
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"On raconte dans le coin qu'une\n"
COLOR(RED) "riche famille" COLOR(DEFAULT) " possédait une maison\n"
"dans ce village..." BOX_BREAK "Mais les membres de cette famille\n"
"étaient avares... Ainsi ils furent \n"
"maudits." BOX_BREAK "Bien heureux le pauvre... \n"
"Crois-moi!"
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...." BOX_BREAK "Quel malotru...\n"
"Nous déranger en plein câlin!\n"
"Où en étions-nous, amour?"
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi..." BOX_BREAK "Nous déranger en plein câlinou!\n"
"Le crois-tu jaloux, mon gnougnou?"
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Regarde celui-là...\n"
"Le gros moustachu...\n"
"On l'a mis à la porte du Ranch." TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il ne fait rien de la journée. \n"
"Et la crise actuelle...\n"
"Il s'en contre-fiche!"
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ce gros flemmard me rappelle kiki." BOX_BREAK "Comment? Tu n'as jamais entendu \n"
"parler de mon cher petit kiki\n"
"d'amour et d'amitié trop mignon?\n"
"C'est mon chien!"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh NoOoOoOoOoOoN!!!!\n"
"Encore un orage? \n"
QUICKTEXT_ENABLE "C'est de ta faute ! ! !" QUICKTEXT_DISABLE "\n"
"Grrrrrrrrrrrrrrr!!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Vous attrapez une Ame!\n"
"Allez la vendre chez le\n"
COLOR(RED) "Marchand d'Ames " COLOR(DEFAULT) "au prix fort!"
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x19") "Halte! On ne bouge plus!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Salut le nouveau!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Une minute, le nouveau...\n"
"Je vais t'ouvrir la porte."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Ne jamais défier une Gerudo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "J'ai vu comment tu as évité les\n"
"gardes. Tu es fort et rapide." BOX_BREAK UNSKIPPABLE "J'ai toujours pensé que les mâles\n"
"n'étaient que des larves! Tous \n"
"sauf le Grand Ganondorf, bien sûr!\n"
"Mais tu m'as prouvé le contraire..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Nabooru l'exaltée" COLOR(DEFAULT) ", notre chef, \n"
"m'a confié la garde de cette \n"
"forteresse." BOX_BREAK UNSKIPPABLE "Nabooru est le bras droit du \n"
"grand Ganondorf, Roi des Voleurs\n"
"Gerudo." BOX_BREAK UNSKIPPABLE "Son quartier général se trouve \n"
"dans le " COLOR(YELLOW) "Temple de l'Esprit" COLOR(DEFAULT) ", au-delà \n"
"du désert..." BOX_BREAK UNSKIPPABLE "A mon avis...tu aimerais devenir un\n"
"Gerudo! J'me trompe?\n"
"Alors c'est chose faite!" BOX_BREAK UNSKIPPABLE "Prends donc ceci. C'est une carte \n"
"de membre Gerudo. Toutes les \n"
"pièces de la forteresse te seront\n"
"désormais accessibles!" EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es désormais libre d'emprunter\n"
"la porte du désert." BOX_BREAK "Tu trouveras dans le désert le \n"
COLOR(YELLOW) "Temple de l'Esprit" COLOR(DEFAULT) ". \n"
"Nabooru l'exaltée y a élu domicile."
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pauvre idiot!" QUICKTEXT_DISABLE "\n"
"Entre là-dedans et reste \n"
"tranquille!"
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu as évité tous les gardes?\n"
"Je ne sais pas d'où tu viens, mais\n"
"tu dois être très fort!" BOX_BREAK UNSKIPPABLE "Tous les autres ouvriers sont\n"
"enfermés dans la forteresse." BOX_BREAK UNSKIPPABLE "Fais-nous tous sortir de ce\n"
"traquenard et nous te rendrons un\n"
"grand service!" BOX_BREAK UNSKIPPABLE "Sois prudent! Des gardes " COLOR(RED) "Gerudos" COLOR(DEFAULT) " \n"
"rôdent dans les couloirs..." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "Woah!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Attention!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Le Seuil ouvert sur le Passé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Le Seuil ouvert sur le Présent" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Le Seuil ouvert sur le Futur" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\xEC") "Le sentier laisse-moi te révéler\n"
"ou du désert tu seras prisonnier.\n"
"Poursuis bien mon halo spectral\n"
"qui te mènera jusqu'au lieu du mal!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Passé, présent, futur..." BOX_BREAK UNSKIPPABLE "L'épée de Légende est un esquif\n"
"voguant sur les flots tumultueux \n"
"du temps..." BOX_BREAK UNSKIPPABLE "Son voyage fait halte dans le\n"
"Temple du Temps..." BOX_BREAK UNSKIPPABLE "Pour entrer dans ce " COLOR(YELLOW) "Temple" COLOR(DEFAULT) ", \n"
"remonte le cours des âges..." BOX_BREAK UNSKIPPABLE "Entends le " COLOR(YELLOW) "Requiem des Esprits" COLOR(DEFAULT) "...\n"
"Cette mélodie conduira un enfant\n"
"aux portes du désert."
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis la meilleure archère \n"
"montée des Gerudos! Je suis \n"
"aussi la meilleure cavalière!" BOX_BREAK "L'archerie montée te tente?\n"
"Alors paie " COLOR(RED) "20 Rubis" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as du cran...j'aime ça.\n"
"Suis-moi!!!"
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mais t'es un crétin!\n"
"L'archerie montée se fait à cheval!\n"
"Si t'en a pas...t'en fais pas!\n"
"C'est logique!!!"
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lâche! Fuis mon regard! \n"
"Tu n'es que l'ombre d'un rat!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es faible... \n"
"Comme tous les hommes!\n"
"Peut-être la prochaine fois."
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es fort. J'en conviens." BOX_BREAK "Aujourd'hui je perds, demain à moi\n"
"la victoire!!!"
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voici l'entrée du " COLOR(RED) "Gymnase Gerudo" COLOR(DEFAULT) "." BOX_BREAK "Ne sont autorisés que les \n"
"membres actifs."
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voici l'entrée du " COLOR(RED) "Gymnase Gerudo" COLOR(DEFAULT) "." BOX_BREAK "Carte de membre acceptée." BOX_BREAK "Une session pour 10 Rubis!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est parti...\n"
"Bonne chance, le nouveau!\n"
"Ha ha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu n'as pas assez d'argent!\n"
QUICKTEXT_ENABLE "Reviens les poches pleines." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé! Le nouveau!" BOX_BREAK UNSKIPPABLE "Vas-tu dans le désert?\n"
"Je t'ouvre la porte, mais..." BOX_BREAK UNSKIPPABLE "Prends garde: tu ne pourras \n"
"traverser le désert sans passer \n"
"les " COLOR(RED) "deux épreuves" COLOR(DEFAULT) "." TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La première épreuve est le " COLOR(RED) "Fleuve\n"
"de Sable" COLOR(DEFAULT) "! Franchis-le et suis le\n"
"chemin bordé de drapeaux." BOX_BREAK "La deuxième épreuve est... \n"
COLOR(RED) "Le Guide Spectral" COLOR(DEFAULT) "!" BOX_BREAK "Ceux qui ne peuvent" COLOR(RED) " distinguer la \n"
"vérité de leurs yeux " COLOR(DEFAULT) "s'en \n"
"reviendront ici." BOX_BREAK "Enfin...si ton choix est fait, je ne\n"
"peux te retarder davantage...\n"
"Fonce, beau gosse!!!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Que fais-tu là? Quoi?\n"
"Tu allais me poser la même \n"
"question?" TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Te voilà bien avancé!\n"
"Comment vas-tu remonter à \n"
"présent?"
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci mon garçon!\n"
"Désolé, je n'ai pas grand chose à \n"
"te donner, mais...\n"
"Prends ceci...pour le geste!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu es nouveau dans le coin, \n"
"gamin..." BOX_BREAK "Que veux-tu?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Voir le Temple\n"
"Je cherche les Sages\n"
"Heu...j'me balade" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu n'es qu'un gamin! \n"
"Et les temples... C'est pas pour \n"
"les gamins!"
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? Les Sages? \n"
"C'est quoi donc?\n"
"Ici il n'y a que des voleurs!"
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu te balades? Tu n'as donc rien \n"
"à faire? Ca tombe très bien! \n"
"J'ai un petit service à te \n"
"demander..." BOX_BREAK UNSKIPPABLE "Au fait...juste une question...\n"
"Tu ne serais pas un des sbires \n"
"de..." BOX_BREAK "Ganondorf...par hasard?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Peut-être...j'hésite encore.\n"
"Ganondorf? Je le HAIS!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha-ha!\n"
"Tu veux jouer au dur! \n"
"C'est trooooop mignon!" BOX_BREAK UNSKIPPABLE "Crois-tu que Ganondorf recruterait\n"
"un gamin comme toi?" BOX_BREAK UNSKIPPABLE "Bon...allons droit au but..." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ho-hoh!" BOX_BREAK UNSKIPPABLE "Tu n'as pas froid au yeux!\n"
"Hmm...J'aime ça." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Je me présente: mon nom est \n"
COLOR(RED) "Nabooru " COLOR(DEFAULT) "la Gerudo! Je suis une \n"
"voleuse solitaire." BOX_BREAK UNSKIPPABLE "Mais...attention!" BOX_BREAK UNSKIPPABLE "Ganondorf et moi-même sommes\n"
"des voleurs, soit! Mais je suis \n"
"très différente de ce chacal!" BOX_BREAK UNSKIPPABLE "Ganondorf et ses infâmes\n"
"serviteurs volent les femmes et\n"
"les enfants. Ils commettent parfois \n"
"des meurtres!!!" BOX_BREAK UNSKIPPABLE "Sais-tu que la race des Gerudos\n"
"ne comporte que des femmes? \n"
"Un homme Gerudo n'apparaît qu'une\n"
"fois tous les cent ans." BOX_BREAK UNSKIPPABLE "Nos lois sont claires: cet homme\n"
"est né pour être roi des Gerudos.\n"
"Mais je refuse de jurer allégeance\n"
"à un homme aussi vil!" BOX_BREAK UNSKIPPABLE "Je parle, je parle et...au fait...\n"
"Quel est ton nom?" BOX_BREAK UNSKIPPABLE  NAME "?!" BOX_BREAK UNSKIPPABLE "Whoa! Tes parents ont le sens de\n"
"l'humour! Quel drôle de nom!\n"
"Enfin...peu importe..." TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Rends-moi service, veux-tu?" BOX_BREAK UNSKIPPABLE "De l'autre côté de ce passage se\n"
"trouve un trésor. Peux-tu me le \n"
"rapporter?" BOX_BREAK UNSKIPPABLE "Ce trésor renferme les " COLOR(BLUE) "Gantelets \n"
"d'argent" COLOR(DEFAULT) ". En les portant, n'importe\n"
"qui peut déplacer d'immenses \n"
"objets!" BOX_BREAK UNSKIPPABLE "Non, non, non, gamin! \n"
"Ne pense même pas à les garder \n"
"pour ta pomme!" BOX_BREAK UNSKIPPABLE "Les Gantelets d'argent sont trop\n"
"grands pour tes petites mains!\n"
"Sois un gentil petit et rapporte\n"
"à tata Nabooru!" BOX_BREAK UNSKIPPABLE "Ganondorf et ses sbires ont élu \n"
"domicile dans ce temple." BOX_BREAK UNSKIPPABLE "Grâce aux Gantelets d'argent, je\n"
"pourrai m'y glisser discrètement..." BOX_BREAK UNSKIPPABLE "Une fois sur place, je déroberai \n"
"leurs trésors et saccagerai leurs \n"
"plans de conquête!" BOX_BREAK "Alors? Veux-tu m'aider?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Nan, j'veux pas!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Merci bien, gamin!" BOX_BREAK UNSKIPPABLE "Nous allons mettre une de ces\n"
"pagailles dans les affaires de \n"
"Ganondorf! On va bien rire!" TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"En échange, si tu me rapportes \n"
"les " COLOR(BLUE) "Gantelets d'argent" COLOR(DEFAULT) "..." BOX_BREAK "Je te donnerai un petit bisou!"
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pfff... Après tout, tu n'es qu'un\n"
"gamin! Allez, ouste! Du balai!"
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hé! Lâchez-moi! Nooon!"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Gni...gni...gniii!\n"
"Tiens, tiens, tiens!!!\n"
"Voici de la visite, Koume!"
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Gnan...gnan...gnan!\n"
"De la visite en effet, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Qui es-tu, jeune impudent, pour\n"
"t'introduire dans notre temple?\n"
"Gni...gni...gni!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Une bonne correction!\n"
"Oh oui! Une bonne correction!\n"
"Gnan...gnan...gnan!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Esclave! Entends-moi..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mon verbe est ton ordre...\n"
"Tue ce jeune sot! Tue!!!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Grand Ganondorf... Intrus...\n"
"Mise à mort..."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hein? Quoi?...\n"
"Où suis-je...?"
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tiens, tiens...\n"
"Le charme est brisé...\n"
"Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ce n'est qu'une jeune fille\n"
"mais grande est son influence au \n"
"sein des Gerudos, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Elle se doit de servir la noble \n"
"cause du Seigneur Ganondorf!\n"
"Gni...gni...gni!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Utilisons le charme une fois\n"
"encore....\n"
"Gnan...gnan...gnan!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Merci, gamin...du fond du coeur.\n"
UNSKIPPABLE "Regardez-moi ça! \n"
"Le gamin est devenu un grand\n"
"guerrier!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
"Tu es devenu beau et fort..." BOX_BREAK_DELAYED("\x50") "J'aurais dû tenir ma promesse..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tiens! Je te donne " COLOR(RED) "ceci" COLOR(DEFAULT) "...\n"
"J'y tiens beaucoup. \n"
"Mais tu as mérité ma confiance!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...A bientôt!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Au fait..." BOX_BREAK UNSKIPPABLE "Excuse-moi de t'avoir attaqué." BOX_BREAK UNSKIPPABLE "J'étais sous le contrôle des\n"
"sorcières et sous les ordres de\n"
"Ganondorf... Pouah!" BOX_BREAK UNSKIPPABLE "Toute cette histoire est \n"
"incroyable, non? \n"
"Moi! Le " COLOR(YELLOW) "Sage de l'Esprit" COLOR(DEFAULT) "! \n"
"C'est à mourir de rire!" BOX_BREAK UNSKIPPABLE "Mais en tant que Sage, mon devoir \n"
"est désormais de combattre!\n"
"Hé hé hé..." BOX_BREAK UNSKIPPABLE "Ma vengeance sera terrible!\n"
"Yaaaaaaaaah!!! "
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Gamin...heu..." BOX_BREAK UNSKIPPABLE "Non...\n"
NAME ", Héros du Temps!" BOX_BREAK UNSKIPPABLE "Je te remets ce " COLOR(YELLOW) "Médaillon" COLOR(DEFAULT) "!\n"
"Le p'tit bisou sera pour plus tard." BOX_BREAK UNSKIPPABLE "Prends-en soin!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0B") "Yaaaaaah!" QUICKTEXT_DISABLE " Laissez-moi partir!!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x1F")  QUICKTEXT_ENABLE "Créatures démoniaques!" QUICKTEXT_DISABLE "\n"
SHIFT("\x23") "Larbins de Ganondorf!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x25") "Fuis cet enfer! Vite!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x10") "Ces sorcières! Elles utilisent\n"
SHIFT("\x19") "leur magie noire sur moi!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé, l'nouveau! Voici notre " COLOR(RED) "terrain\n"
"d'archerie montée" COLOR(DEFAULT) "." BOX_BREAK "Tout en faisant galoper nos \n"
"chevaux, nos flèches se plantent\n"
"dans le mille à tous les coups!" BOX_BREAK "Apprends à monter à cheval et\n"
"reviens nous voir pour tester tes\n"
"capacités... On va bien rire!"
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé, l'nouveau!\n"
"Ton cheval a fière allure!" BOX_BREAK "Je ne sais où tu l'as volé, mais..." BOX_BREAK "Pourquoi ne pas participer au\n"
"concours d'archers montés?" BOX_BREAK "Fais galoper ton destrier et\n"
"décoche tes flèches vers les \n"
"cibles. " BOX_BREAK "Tu as 20 flèches. Voyons un peu \n"
"quel sera ton score après un\n"
"aller-retour." BOX_BREAK "Totalise plus de " COLOR(RED) "1,000 points" COLOR(DEFAULT) ",\n"
"et tu gagneras un prix!" EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veux-tu tenter ta chance pour \n"
COLOR(RED) "20 Rubis" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé, l'nouveau!\n"
"T'es plutôt doué!\n"
"Augmentons un peu la difficulté..." BOX_BREAK "Totalise " COLOR(RED) "1,500 points " COLOR(DEFAULT) "ou plus \n"
"pour voir!" EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? Tu veux recommencer?\n"
"Tu as un certain potentiel!" EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fabuleux! Un vrai maître!" BOX_BREAK "Prends cet objet, il conviendra\n"
"mieux à un expert comme toi." BOX_BREAK "Ce carquois m'est très cher.\n"
"Mais je tiens à te le donner.\n"
"Prends-en soin, OK?"
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " points?!?\n"
"Wha-ha-ha! La gloire n'est pas \n"
"pour tout de suite!" EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantastique! De toute beauté!\n"
"Tu es un archer d'exception!" BOX_BREAK "Ceci te sera d'une grande aide..."
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " points...\n"
"Pas mal...enfin...bof." EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Quel jeune insensé!\n"
"Venir de son propre chef s'offrir \n"
"en sacrifice au Grand Ganondorf..." FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "Le souffle de mes flammes \n"
SHIFT("\x28") "consumera son âme!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x1B") "La morsure de ma glace \n"
SHIFT("\x2F") "pétrifiera ses os!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x28") "Quelle petite peste!\n"
SHIFT("\x12") "Cette fois, c'est du serieux,\n"
SHIFT("\x26") "n'est-ce pas Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x51") "Hein?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x17") "Hé! Koume! Tu as un truc\n"
SHIFT("\x24") "au-dessus de la tête!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x19") "Heu? Regarde! Toi aussi!\n"
SHIFT("\x15") "C'est quoi ce machin rond?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x18") "Mais je n'ai que 400 ans!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "Et moi je n'ai que 380 ans!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Nous sommes jumelles! Tu ne \n"
SHIFT("\x19") "peux pas avoir 380 ans! \n"
SHIFT("\x34") "Arrête de mentir!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "T'es devenue sénile!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "Quoi? C'est moi la sénile?\n"
SHIFT("\x01") "Cause meilleur à ta grande soeur!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "ON...EST...JUMELLES! JU-MELLES!\n"
SHIFT("\x05") "Tu ne peux pas être plus vieille \n"
SHIFT("\x43") "que moi!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x35") "Gnyyaaaarghh!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x0D") "C'que tu peux être sournoise!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Comment fais-tu pour être  \n"
SHIFT("\x34") "aussi mesquine?" QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x39") "T'es sournoise!!" QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "T'es mesquine..." QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x10") "En tout cas...moi j'suis sexy!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bon... Cette fois y'en a marre!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x32")  QUICKTEXT_ENABLE "En avant, Koume!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x14")  SHIFT("\x2D")  QUICKTEXT_ENABLE "Kotake" QUICKTEXT_DISABLE " et " QUICKTEXT_ENABLE "Koume" QUICKTEXT_DISABLE "...\n"
SHIFT("\x1C")  QUICKTEXT_ENABLE "Double" QUICKTEXT_DISABLE " Fusion " QUICKTEXT_ENABLE "Maléfique!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu es venu pour me sauver?\n"
"Alors ça, c'est trop chou! \n"
"Je suis " COLOR(RED) "Hiro l'ouvrier" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Nous voulions tous joindre leur\n"
"club de filles mais elles nous ont\n"
"enfermés! Tout ça parce que nous\n"
"sommes des...mâles!" BOX_BREAK UNSKIPPABLE "Au diable ces jolies filles Gerudos!\n"
"Elles sont trop dures!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Trois de mes compagnons" COLOR(DEFAULT) " sont \n"
"aussi enfermés. Peux-tu les sauver?"
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Gentil petit bouchon! \n"
"Je suis " COLOR(RED) "Julio l'ouvrier" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Ces femmes me font peur! \n"
"Je préfère travailler que d'en \n"
"épouser une!" BOX_BREAK UNSKIPPABLE "J'ai hâte de quitter cet endroit!\n"
"Mais encore " COLOR(RED) "deux petits camarades\n"
COLOR(DEFAULT) "sont enfermés! Peux-tu les sauver?"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Merci p'tite tête, t'es un amour! \n"
"Je suis " COLOR(RED) "Jibo l'ouvrier" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "T'as pas vu notre chef? Y doit\n"
"se faire du mouron! Je dois le \n"
"voir maintenant! Je suis déjà à la\n"
QUICKTEXT_ENABLE "bourre!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Mais un " COLOR(RED) "autre ouvrier " COLOR(DEFAULT) "est \n"
"encore enfermé... Sauve-le!\n"
"Je l'aime tant!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Youki! Je suis Liiiiibre!\n"
"Mon nom est " COLOR(RED) "Nico l'ouvrier" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Pour te remercier, voici ce que\n"
"mes petites oreilles d'amour ont \n"
"entendu il n'y a pas si longtemps..." BOX_BREAK UNSKIPPABLE "\"Seul l'oeil de vérité peut faire\n"
"traverser le désert... La déesse \n"
"est au-delà des sables...\"" BOX_BREAK UNSKIPPABLE "Bon...je retourne dans ma\n"
COLOR(RED) "tente près de la Vallée Gerudo" COLOR(DEFAULT) "!\n"
"Viens donc y faire un tour!\n"
"Saluuuut!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Le chef du clan des voleurs est \n"
COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Elle efface la mémoire \n"
"des voyageurs près des ruines\n"
"dans le désert."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ganondorf, le seigneur du malin, \n"
"est derrière toute cette histoire\n"
"de voleuses..."
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quand " COLOR(RED) "Nabooru" COLOR(DEFAULT) " n'était qu'une \n"
"voleuse solitaire, elle ne dérobait\n"
"jamais les faibles, mais..." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Aujourd'hui le clan de Nabooru est \n"
"violent et cruel! Elle se prétend \n"
"noble et chevaleresque...\n"
"Ben voyons!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Comme je l'ai toujours dit, \n"
"Nabooru était manipulée par les \n"
"sbires de Ganondorf..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Chez les Gerudos, un bon archer\n"
"et un fier cavalier est toujours \n"
"respecté." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu devrais te risquer au concours \n"
"d'archerie montée près de la \n"
"forteresse Gerudo!" BOX_BREAK "Si tu as un cheval, une Gerudo\n"
"te lancera un défi."
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu as été brillant, jeune homme!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Construire un pont est une simple \n"
"tâche si nous travaillons en équipe."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Sans ces sales vieilles sorcières, \n"
"le clan des voleuses est moins\n"
"terrifiant!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La " COLOR(RED) "forteresse Gerudo" COLOR(DEFAULT) " est de \n"
"l'autre côté...mais un gamin comme \n"
"toi n'a rien à y faire."
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Je suis le " COLOR(RED) "chef des ouvriers" COLOR(DEFAULT) ". \n"
"Les voleuses Gerudos ont cassé \n"
"mon joli pont." BOX_BREAK UNSKIPPABLE "J'aimerais le réparer mais mes \n"
"hommes ont disparu!\n"
"Alors...je suis coincé ici." BOX_BREAK UNSKIPPABLE "Leur condition d'ouvrier ne leur \n"
"plaisait pas...des mauviettes, oui! \n"
"Alors ils sont tous partis à \n"
"la " COLOR(RED) "forteresse Gerudo" COLOR(DEFAULT) "..." TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Toi! Tu vas à la forteresse?\n"
"Pourrais-tu voir ce que fabriquent\n"
"mes ouvriers?"
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! C'est toi qui as sauvé mes \n"
"hommes! Pour te remercier on t'a \n"
"construit ce pont! Pas mal, hein!\n"
"C'est pas du boulot d'Goron!!!" BOX_BREAK "Il est droit, il est soigné...\n"
"Mon pont à moi c'est le plus beau\n"
"de tous les ponts du mooooonde!" BOX_BREAK "Mes ouvriers sont, soit, un peu\n"
"paresseux...mais en travaillant en\n"
"équipe, ils font du bon travail!"
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Hé! Mais c'est ma scie!" BOX_BREAK UNSKIPPABLE "Je l'avais égarée chez ma vieille \n"
"femme...C'est fou!" TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon outil Biggoron est brisé. \n"
"Je m'apprêtais à le faire réparer \n"
"au village Goron." BOX_BREAK "Ta venue est providentielle.\n"
"Peux-tu me rendre la scie?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4D")  QUICKTEXT_ENABLE "Quoi?!\n"
SHIFT("\x30") "Sale petit voleur!\n"
SHIFT("\x38") "JE TE HAIS!!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voici l'entrée du " COLOR(RED) "Gymnase " COLOR(DEFAULT) "Gerudo.\n"
"Les personnes non autorisées sont\n"
"interdites d'accès!"
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voici l'entrée du " COLOR(RED) "Gymnase " COLOR(DEFAULT) "Gerudo.\n"
"Carte de membre valide...\n"
"Entre et donne-toi à fond!" EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Voici l'entrée du " COLOR(RED) "Gymnase " COLOR(DEFAULT) "Gerudo. \n"
"Même si ta carte est valide, ne \n"
"garde pas tous les trésors pour\n"
"ta pomme!"
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Comme c'i dommage" BOX_BREAK "Li marque qui ti mènera au Temple\n"
"di Isprits c'i li " COLOR(RED) "drapeau à gauche \n"
COLOR(DEFAULT) "en sortant d'ici." BOX_BREAK "N'hisite pas à rivinir mi voir!"
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Ti as pas assez di Rubis!\n"
"Ji fi pas cridit ici!!!"
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hé! Hé!\n"
"Tu m'as l'air préoccupé." BOX_BREAK "Pour me défier, il faut avoir\n"
"l'esprit clair... Une course est\n"
"un travail mental et physique!"
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bienvinue chez Sabib al Mamoud!" BOX_BREAK "Ji vends di choses...mirvilleuses.\n"
"Li curiositi, li objits magiques...\n"
"Ti trove tout chi Sabib al Mamoud!\n"
"Aujourd'hui, ji ti propose..." BOX_BREAK "Une arme qu'elle est tirrible!\n"
"Mais montre à Sabib tes Rubis..." BOX_BREAK "Donne " COLOR(RED) "200 Rubis " COLOR(DEFAULT) "et ji ti li donne.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Acheter\n"
"Ne pas acheter" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Merci di li beaucoup!\n"
"Ti es beau! Que ti es beau!" BOX_BREAK "Ci qui ji li vends c'est di...\n"
TEXT_SPEED("\x02")  COLOR(RED) "Missiles Teigneux" COLOR(DEFAULT) "!" TEXT_SPEED("\x00")  BOX_BREAK "Si ti veux aller au Temple di \n"
"l'Isprit va vers li " COLOR(RED) "drapeau à\n"
"gauche " COLOR(DEFAULT) "en sortant d'ici!"
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Bonjour " NAME "!\n"
"Content de me voir?" BOX_BREAK UNSKIPPABLE "Le temps n'a aucune prise sur toi! \n"
"Comme c'est étrange!" BOX_BREAK UNSKIPPABLE "J'ai toujours cru qu'un voyageur \n"
"du temps n'était qu'une légende..." BOX_BREAK UNSKIPPABLE  NAME ", \n"
"tu es devenu un adulte!" TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Le destin d'Hyrule est désormais\n"
"entre tes mains." BOX_BREAK "Le moment est mal choisi mais \n"
"voici un dernier conseil..." BOX_BREAK "Deux puissantes sorcières habitent\n"
"dans ce temple. Pour les vaincre, \n"
"il te faudra " COLOR(RED) "utiliser contre elles \n"
"leur propre magie" COLOR(DEFAULT) ". Hou hou!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Veux-tu que je répète tout ça?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je garde un oeil sur toi...\n"
"Hou hou hou hou!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Je suis le marathonien errant!\n"
"J'ai parcouru ce monde à la \n"
"recherche du véritable esprit\n"
"de compétition." BOX_BREAK UNSKIPPABLE "J'ai triomphé de tous mes \n"
"adversaires...\n"
"Car je suis...(tadaaaaa!).....\n"
QUICKTEXT_ENABLE "Le marathonien errant" QUICKTEXT_DISABLE "!" BOX_BREAK UNSKIPPABLE "Tu m'as l'air costaud. \n"
"L'instinct du furieux guerrier \n"
"sanguinaire brille dans ton regard." BOX_BREAK UNSKIPPABLE "Le pont de la vallée Gerudo est \n"
"à nouveau en état. Je cherche des\n"
"adversaires de valeur." TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Le meilleur temps d'ici jusqu'au \n"
COLOR(ADJUSTABLE) "pont des bois perdus" COLOR(DEFAULT) " est " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ".  \n"
"C'est mon record perso..." BOX_BREAK "Relèves-tu le défi?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Parfait!\n"
"Alors..." BOX_BREAK "Tu pars le premier.\n"
"Tu prendras la tête de la course.\n"
"Enfin...au début!" BOX_BREAK "Prêt? " TEXT_SPEED("\x02") "Partez!" TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Pfffff.....\n"
"Tu ne découvriras jamais ton \n"
"instinct de furieux guerrier \n"
"sanguinaire de cette façon!!!"
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Pas mal. Pas super-super, mais tu \n"
"t'es bien défendu! \n"
"Enfin...ne rêve pas trop!\n"
"Tu ne pourras JAMAIS me battre." BOX_BREAK "Ton temps est de " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ", non?\n"
"Malheureusement pour ta pomme,\n"
"je suis arrivé une seconde avant \n"
"toi! C'est bête, hein?" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hé hé hé hé hé...\n"
"Ne sois pas timide! " TEXT_SPEED("\x02") "Passe devant!" TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"C'est mal! \n"
"Tu as abandonné la course! \n"
"Tu ne seras donc jamais un \n"
"furieux guerrier sanguinaire!!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Hé hé hé hé...\n"
"Ton instinct de furieux guerrier \n"
"sanguinaire est faible." BOX_BREAK "Entraîne-toi encore et encore!\n"
"A la prochaine... " QUICKTEXT_ENABLE "Limace!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Heuff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "peuff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "heuff..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  BOX_BREAK "Woah! Tu as fait très fort!" BOX_BREAK "Maaaaaiiiis...je suis le vainqueur! \n"
"Ton temps est de " COLOR(RED)  MARATHON_TIME  COLOR(DEFAULT) ".\n"
"Je t'ai battu d'une seconde!" BOX_BREAK "Heuff...heuff... \n"
"N'hésite pas à me défier une \n"
"nouvelle fois! Quand tu veux!" BOX_BREAK "Heuff...heuff...\n"
"A la prochaine, " QUICKTEXT_ENABLE "limace!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Je suis le marathonien errant!\n"
"Je cherche un adversaire à\n"
"l'instinct du furieux guerrier\n"
"sanguinaire!" BOX_BREAK "J'aimerais rejoindre la plaine\n"
"d'Hyrule, mais le pont est...\n"
"Enfin ça se voit d'ici! \n"
"Alors je suis coincé ici." BOX_BREAK "Je suis désolé mais je ne peux\n"
"te défier aujourd'hui. Hé hé hé!"
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
"Je n'arrive pas à attraper cette \n"
"cocotte!"
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huff huff! \n"
"Je suis en retard!\n"
"J'ai un rencard!"
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gloire et longue vie à la noble\n"
"Famille Royale d'Hyrule!"
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Les gamins ne se promènent pas \n"
"près du château la nuit! \n"
"Reste dans la ville en attendant \n"
"le lever du soleil!"
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bwooarff! Je m'ennuie...\n"
"Ha! S'il y avait un peu plus \n"
"d'action, je pourrais m'amuser..." BOX_BREAK "Mais tu gardes ça pour toi, OK?" BOX_BREAK "Enfin...on peut toujours faire un \n"
"peu de bruit en brisant ces jarres." BOX_BREAK "Appuie sur " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour en soulever\n"
"une. Utilise ensuite " COLOR(BLUE) "[A]" COLOR(DEFAULT) " pour\n"
"la lancer!"
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "C'est fantastique!" BOX_BREAK UNSKIPPABLE "Ha! J'ai oublié de te dire..." EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Le château est en alerte! Je ne \n"
"laisserai même pas une souris\n"
"entrer!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Arrrrgh...es-tu le garçon de la\n"
"forêt...?" BOX_BREAK UNSKIPPABLE "Enfin te voici...\n"
"E-éc-écoute..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", le prince des voleurs,\n"
"a trahi notre Roi..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) " la nourrice a senti le danger\n"
"et s'est enfuie du château avec la\n"
"Princesse Zelda..." BOX_BREAK UNSKIPPABLE "J'ai essayé d'arrêter les hommes \n"
"de Ganondorf...mais..." BOX_BREAK UNSKIPPABLE "La Princesse attendait...un garçon\n"
"de la forêt...toi... Elle voulait\n"
"te donner " COLOR(RED) "quelque chose" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Si la Princesse te l'a remis, \n"
TEXT_SPEED("\x03")  QUICKTEXT_ENABLE "Vite" QUICKTEXT_DISABLE "..." QUICKTEXT_ENABLE "va au" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tem" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "ple" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "du" QUICKTEXT_DISABLE " Temps" COLOR(DEFAULT) "...." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Il ne bouge plus...."
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu vois cet homme aux yeux \n"
"noirs de haine?" BOX_BREAK UNSKIPPABLE "C'est " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", il est le chef \n"
"des Gerudos, une tribu du désert." BOX_BREAK UNSKIPPABLE "Même s'il jure fidélité à Père, \n"
"je suis sûre qu'il est un traître." BOX_BREAK UNSKIPPABLE "Mes rêves me font voir de \n"
"sombres nuages sur Hyrule...\n"
"Ils doivent représenter cet homme!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x05") "Ha hah hah! Félicitations, gamin!" BOX_BREAK_DELAYED("\x3C")  SHIFT("\x02") "Comme je le pensais, tu avais en \n"
SHIFT("\x06") "ta possession la clé des portes \n"
SHIFT("\x44") "du temps!" BOX_BREAK_DELAYED("\x5A")  SHIFT("\x0B") "Tu m'as ouvert la voie jusqu'au\n"
SHIFT("\x34") "Saint Royaume..." BOX_BREAK_DELAYED("\x50")  SHIFT("\x0F") "Je te dois ma victoire, petit!" FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vite! Il va s'en aller!" EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pitié...avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Pitié vends-moi le " COLOR(RED) "contenu" COLOR(DEFAULT) " d'une\n"
"bouteille...\n"
"Pitié...avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle étrange boutique!\n"
"Quand va-t-elle ouvrir?\n"
"J'ai lu le panneau mais... \n"
"J'y comprends rien!"
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'aube se fait attendre..." BOX_BREAK "La vue du château sous le soleil \n"
"du matin est superbe!"
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pour sauver la fille de la forêt il\n"
"te faudra un " COLOR(RED) "nouveau pouvoir" COLOR(DEFAULT) "... \n"
"Va au village Cocorico!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as le pouvoir qu'il te faut...\n"
"La " COLOR(ADJUSTABLE) "fille de la forêt " COLOR(DEFAULT) "t'attend..."
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Il te faut une bouteille vide\n"
"pour transporter une potion!" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Désolé...ce n'est qu'une maquette. \n"
"La crise du village Goron nous\n"
"a mis en rupture de stock." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Avant d'aller sur le Mont du Péril, \n"
"procure-toi un " COLOR(LIGHTBLUE) "bouclier Hylien" COLOR(DEFAULT) ". \n"
"Les chutes de pierres sont \n"
"terribles, tu verras!" BOX_BREAK "Mais il risque d'être un peu grand \n"
"pour toi..." PERSISTENT
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"T'es fou! Je ne danse pas...\n"
"J'ai le dos qui me gratte...\n"
"Haaaa! Hooooo! Rhaaaaa!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On dit que les grandes oreilles \n"
"des " COLOR(LIGHTBLUE) "Hyliens" COLOR(DEFAULT) " servent à entendre la \n"
"voix des dieux...faut croire que les \n"
"miennes sont en panne."
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Es-tu déjà allé au " COLOR(YELLOW) "Ranch Lon Lon" COLOR(DEFAULT) ",\n"
"Gamin?" BOX_BREAK UNSKIPPABLE "Leur lait est délicieux!\n"
"Ils ont beaucoup de chevaux et la\n"
"fille du patron est très mignonne!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pour te rendre au " COLOR(YELLOW) "Ranch" COLOR(DEFAULT) ", c'est \n"
"simple: traverse la plaine vers \n"
"le Sud en sortant du château!\n"
"Tu m'en diras des nouvelles!"
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Je voulais voir la " COLOR(RED) "Princesse Zelda" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "J'ai évité tous les gardes..." BOX_BREAK UNSKIPPABLE "J'ai nagé dans les douves..." BOX_BREAK UNSKIPPABLE "J'y étais presque mais...ils m'ont\n"
"attrapé!" TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai trouvé un petit " COLOR(RED) "trou\n"
"d'évacuation" COLOR(DEFAULT) " sur la droite du \n"
"château. J'ai voulu m'y glisser \n"
"mais je suis resté coincé!"
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x15") "Cette barbe est ma fierté!\n"
SHIFT("\x17") "Elle est belle, hein? Hein?"
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SHIFT("\x16") "Cette barbe est ma fierté.\n"
SHIFT("\x0E") "Elle est belle et bien fournie!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x4D") "Quoi?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Tu cherches le gars du Ranch \n"
"Lon Lon?" BOX_BREAK UNSKIPPABLE "Hmm, Peut-être..." TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai vu un " COLOR(RED) "type avec une horrible\n"
"moustache noire " COLOR(DEFAULT) "apporter du lait\n"
"au château."
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sais-tu que le " COLOR(LIGHTBLUE) "Temple du Temps" COLOR(DEFAULT) "\n"
"se trouve au Nord Est du Bourg?" TEXTID("\x70\x1E")
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les légendes racontent que le \n"
"Temple du Temps est l'entrée du\n"
"Saint Royaume..." BOX_BREAK "C'est trop terrible ça!"
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha! Il est dingue ce type!" BOX_BREAK UNSKIPPABLE "Il a essayé d'entrer dans le \n"
"château pour voir la " COLOR(RED) "Princesse \n"
"Zelda" COLOR(DEFAULT) "! Il est dingue, lui!" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A cause de ce crétin ils ont \n"
"doublé la garde! C'est malin!\n"
"Wha-ha-hah!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "J'ai gagné beaucoup d'argent!" BOX_BREAK UNSKIPPABLE "Moi j'aime vendre des trucs \n"
"et des machins!" TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je vais me faire des sous près du\n"
COLOR(BLUE) "Lac Hylia" COLOR(DEFAULT) "! On trouve plein d'objets\n"
"au fond de l'eau! Hah hah!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hé! P'tit gars de la forêt! \n"
"Voici le " COLOR(LIGHTBLUE) "Bourg d'Hyrule" COLOR(DEFAULT) "! \n"
"Prends ton temps et admire!" TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pour aller au " COLOR(LIGHTBLUE) "Château d'Hyrule" COLOR(DEFAULT) ",\n"
"prends la rue à droite." BOX_BREAK "Pour examiner la " COLOR(BLUE) "ruelle" COLOR(DEFAULT) ", emprunte\n"
"la rue de gauche."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Amour..." BOX_BREAK "Tu es si...beau..." BOX_BREAK "Comme le Roi d'Hyrule..." BOX_BREAK "Amour..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Comme tu es belle..." BOX_BREAK "Tu es..." BOX_BREAK "Encore plus belle que..." BOX_BREAK "La Princesse Zelda..." BOX_BREAK "Mon p'tit chat... Je t'aime tant!"
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Connais-tu le \"peuple de l'ombre\"?" BOX_BREAK UNSKIPPABLE "Les " COLOR(BLUE) "Sheikahs " COLOR(DEFAULT) "sont l'ombre des \n"
"Hyliens." BOX_BREAK UNSKIPPABLE "On dit qu'ils ont juré fidélité au\n"
"Roi d'Hyrule! Leur tâche est de \n"
"protéger la Famille Royale." BOX_BREAK UNSKIPPABLE "Mais ils se font très rares par \n"
"ces temps de paix ..." BOX_BREAK UNSKIPPABLE "Enfin..." TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai entendu dire qu'un " COLOR(BLUE) "Sheikah \n"
COLOR(DEFAULT) "vivait au château..."
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? Tu veux voir la " COLOR(RED) "Princesse\n"
"Zelda" COLOR(DEFAULT) "?\n"
"Haaaa... Encore un!" BOX_BREAK "Bon! Ce que tu veux, on s'en \n"
"contre-fiche!\n"
"Alors..." BOX_BREAK QUICKTEXT_ENABLE "Du balai!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Ouste!!" QUICKTEXT_DISABLE "\n"
"Jamais la Princesse n'accordera\n"
"une audience à un bouseux comme \n"
"toi! Hah ah ah ha ha!"
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z...." BOX_BREAK "Ronnnff...Zzzzzz...Hmmmpfff! " BOX_BREAK "Bienvenue...au Ranch..." BOX_BREAK "Il est beau mon Ranch...\n"
"Roooooonnnfle...."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x32") "Nom d'un pétard!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "On peut pas piquer un p'tit\n"
"roupillon en paix ici?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bonjour mon ami! Qui es-tu?" BOX_BREAK UNSKIPPABLE "Ouaip! Moi c'est " COLOR(RED) "Talon" COLOR(DEFAULT) ", patron du\n"
"Ranch Lon Lon." BOX_BREAK UNSKIPPABLE "Je suis venu au château livrer du\n"
"lait et...j'ai dû m'endormir..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4C")  SFX("\x68\x52") "Quoi?!\n"
SHIFT("\x2D") "Malon me cherche?\n"
"Houlà je vais m'faire crier dessus!" BOX_BREAK UNSKIPPABLE "Malon n'aime pas mes p'tites\n"
"pauses!" BOX_BREAK UNSKIPPABLE "Je ne vais pas y couper!" EVENT
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Hé! Le mioche! Viens par là!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x5F") "!" BOX_BREAK_DELAYED("\x0A")  UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Qui?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x42") "Qui es-tu?" BOX_BREAK UNSKIPPABLE "Comment as-tu évité les gardes?" EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Alors...tu as la Pierre?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Etrange...\n"
"Tu ressembles pourtant au garçon \n"
"de mon rêve...\n"
"Vraiment? Tu ne l'as pas?" BOX_BREAK "Allez... Dis-moi la vérité..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x34") "J'en étais sûre!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bon...ne répète ça à personne...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu vas cafarder? \n"
"Sois gentil..." EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Voici ce que dit la légende..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x0A") "Les trois déesses dissimulèrent\n"
"la " COLOR(RED) "Triforce" COLOR(DEFAULT) " renfermant la puissance\n"
SHIFT("\x04") "des dieux quelque part en Hyrule." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x1F") "Cette puissance permet\n"
SHIFT("\x0A") "d'exaucer un voeu au détenteur\n"
SHIFT("\x39") "de la Triforce." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x11") "Si ce voeu est prononcé par\n"
SHIFT("\x08") "un homme au coeur pur, Hyrule \n"
SHIFT("\x26") "connaîtra l'âge d'or...." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x08") "Mais si le voeu est formulé par\n"
SHIFT("\x04") "un homme mauvais, le monde sera\n"
SHIFT("\x15") "englouti dans les flammes..." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x08") "Les Sages anciens ont construit\n"
SHIFT("\x05") "le " COLOR(LIGHTBLUE) "Temple du Temps " COLOR(DEFAULT) "pour tenir la\n"
SHIFT("\x22") "Triforce à l'écart des \n"
SHIFT("\x33") "forces obscures." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"En effet... Le Temple du Temps est\n"
"la porte vers le Saint Royaume \n"
"légendaire." BOX_BREAK "Mais la " COLOR(LIGHTBLUE) "Porte du Temps" COLOR(DEFAULT) " en interdit\n"
"l'accès..." BOX_BREAK "Pour ouvrir cette porte les trois\n"
COLOR(RED) "Pierres Ancestrales" COLOR(DEFAULT) " sont\n"
"indispensables." BOX_BREAK "Ainsi que le trésor de la Famille\n"
"Royale......" EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Excuse-moi...\n"
"Je ne suis pas douée pour conter \n"
"les légendes..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "Que s'est-il passé?" QUICKTEXT_DISABLE " Il t'a vu?" BOX_BREAK UNSKIPPABLE "Ce n'est pas grave..." BOX_BREAK UNSKIPPABLE "Il ignore nos plans... \n"
"Enfin pour l'instant!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je t'en prie!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Je ne te crois pas" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x4E") "Merci!" EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ma nourrice te guidera hors du\n"
"château. N'aie pas peur et va lui \n"
"parler."
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"La Pierre Ancestrale...\n"
"Tu l'as enfin trouvée!" BOX_BREAK "Il est dit que les races possédant \n"
"une Pierre Ancestrale ouvrent leur \n"
"esprit au son de la " COLOR(BLUE) "Mélodie de la \n"
"Famille Royale" COLOR(DEFAULT) "." BOX_BREAK "Mais tu connais déjà cette \n"
"mélodie, n'est-ce pas?"
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Sais-tu que la Princesse \n"
"Zelda fait souvent des rêves \n"
"prémonitoires?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gné? Quoué? Comment? \n"
"Va-t'en, petit..."
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Il y a trois socles et une \n"
"inscription...." BOX_BREAK QUICKTEXT_ENABLE "Toi qui portes les trois Pierres\n"
"Ancestrales, entonne le " COLOR(LIGHTBLUE) "chant du \n"
"temps " COLOR(DEFAULT) "avec l'" COLOR(LIGHTBLUE) "Ocarina du Temps" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Allez, fais-moi un prix! \n"
"Une réduc' quoi! \n"
"C'est trop cher!"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Va-t'en! C'est à môa!\n"
"Je l'ai vu la première!"
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Qui c'est qui m'a poussée? \n"
"QUI?!"
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Etrange...Un groupe de Gerudos \n"
"dans la ville...Il se passe quelque\n"
"chose de pas très correct dans \n"
"le coin! Ouais, ça c'est sûr!"
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'était pas la Princesse Zelda sur\n"
"ce cheval blanc?!"
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"j'ai failli me faire écraser par \n"
"cet énorme cheval noir!\n"
"L'est fou l'aut' grand type!"
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"L'homme sur le cheval noir \n"
"s'appelle Ganondorf. Il est connu \n"
"comme étant le Roi des Voleurs \n"
"Gerudo."
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein?! Que s'est-il passé?!"
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Regarde ce type! Il est mort de\n"
"trouille! Quelle mauviette!\n"
"Ha ha hah!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmmm...ça craint dans l'coin...\n"
"Je vais prendre des vacances!"
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un drame est arrivé au château!\n"
"Sois prudent, gamin!"
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cette " COLOR(RED) "clé" COLOR(DEFAULT) " te permet d'ouvrir la\n"
"salle suivante!"
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sur le cheval blanc...\n"
"C'était pas cette...Sheikah?"
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D")  NAME "..." BOX_BREAK UNSKIPPABLE  SHIFT("\x37") "Reviens à toi...\n"
SHIFT("\x4B") "...L'élu..."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je suis " COLOR(RED) "Rauru" COLOR(DEFAULT) "...\n"
"L'un des anciens Sages." BOX_BREAK UNSKIPPABLE "Jadis, les Sages bâtirent le Temple \n"
"du Temps pour protéger l'entrée \n"
"du Saint Royaume Légendaire..." BOX_BREAK UNSKIPPABLE "Voici le " COLOR(RED) "Sanctuaire des Sages" COLOR(DEFAULT) " au\n"
"sein même du Temple de la \n"
"Lumière!" BOX_BREAK UNSKIPPABLE "Le Temple de la Lumière se trouve\n"
"au centre du Saint Royaume. Il est\n"
"le dernier rempart contre \n"
"l'influence maléfique de Ganondorf." BOX_BREAK UNSKIPPABLE "L'" COLOR(RED) "Epée de Légende" COLOR(DEFAULT) ", la lame \n"
"purificatrice jadis prisonnière \n"
"du piédestal du Temps, est la\n"
"clé ultime du Saint Royaume." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"N'aie pas peur...\n"
"Regarde-toi...!"
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x1B")  COLOR(LIGHTBLUE) "Regarde " NAME "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  SHIFT("\x38")  COLOR(LIGHTBLUE) "Tu as grandi!!\n"
COLOR(DEFAULT)  SHIFT("\x32")  COLOR(LIGHTBLUE) "Tu es un adulte!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "L'Epée de Légende est une lame \n"
"sacrée interdite aux forces \n"
"obscures...." BOX_BREAK UNSKIPPABLE "Seul le \"" COLOR(RED) "Héros du Temps" COLOR(DEFAULT) "\" peut la \n"
"retirer de son socle de granit...." BOX_BREAK UNSKIPPABLE "Mais tu étais trop jeune pour être\n"
"ce Héros du Temps...." BOX_BREAK UNSKIPPABLE "Ton esprit fut scellé en ce lieu\n"
"pendant sept ans." BOX_BREAK UNSKIPPABLE "Mais il est enfin temps de \n"
"t'éveiller et de laisser la \n"
"destinée du Héros du Temps \n"
"s'accomplir par tes actes!" BOX_BREAK "As-tu conscience de la tâche à \n"
"accomplir?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oui, je comprends, ton esprit est \n"
"encore embrumé par les voiles d'un\n"
"repos de sept ans...Je vais tout\n"
"te répéter." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mais souviens-toi..." BOX_BREAK UNSKIPPABLE "Même si tu as ouvert les Portes \n"
"du Temps au nom de la paix et \n"
"de la justice..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", le Roi des voleurs\n"
"Gerudo, en a profité pour violer\n"
"le Saint Royaume interdit!" BOX_BREAK UNSKIPPABLE "Il a dérobé la Triforce dans le \n"
"Temple de la Lumière, et grâce à\n"
"ses nouveaux pouvoirs il s'est \n"
"sacré " COLOR(RED) "Seigneur du Malin" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Son pouvoir maléfique a perverti\n"
"les Temples d'Hyrule et a transfor-\n"
"mé en sept ans notre monde en \n"
"un chaos innommable." BOX_BREAK UNSKIPPABLE "Mon pouvoir est bien faible, mon\n"
"influence mineure, dans le \n"
"Saint Royaume...et..." BOX_BREAK UNSKIPPABLE "...dans ce Sanctuaire des Sages." BOX_BREAK UNSKIPPABLE "Mais il reste un espoir." BOX_BREAK UNSKIPPABLE "La puissance des Sages." BOX_BREAK UNSKIPPABLE "Quand la puissance des " COLOR(RED) "sept\n"
"Sages " COLOR(DEFAULT) "se manifestera......" BOX_BREAK UNSKIPPABLE "...les influences maléfiques seront \n"
"endiguées par le " COLOR(RED) "Sceau des Sages" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Moi, Rauru, je suis l'un des Sages.\n"
"Et..." BOX_BREAK UNSKIPPABLE "...ta puissance combinée à celle\n"
"des Sages te proclame...\n"
COLOR(RED) "Héros du Temps" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Elu par l'Epée de Légende,\n"
"ta destinée sera de guider Hyrule\n"
"vers la lumière." BOX_BREAK UNSKIPPABLE "Garde mon esprit avec toi...\n"
"Trouve les autres Sages et reviens\n"
"ici consacré de leurs pouvoirs!"
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Nous sommes de retour dans le \n"
COLOR(DEFAULT) "Temple du Temps" COLOR(LIGHTBLUE) "...\n"
COLOR(DEFAULT) "Sept ans" COLOR(LIGHTBLUE) " se sont-ils vraiment\n"
"écoulés?" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Je pense que tu ne pourras plus\n"
"utiliser ton équipement d'enfant \n"
"ainsi que certaines " COLOR(DEFAULT) "armes" COLOR(LIGHTBLUE) "..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Bon...partons d'ici!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hééé! Quoi...? \n"
"Qu'y a-t-il de mal à ne rien\n"
"faire de la journée?" BOX_BREAK "Hein? hein? hein?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je t'attendais,\n"
"Héros du Temps..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quand le mal est sur le monde, \n"
"ceux sensibles à l'appel du Saint\n"
"Royaume Légendaire se réfugient \n"
"dans les " COLOR(RED) "cinq Temples" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Dans une " COLOR(ADJUSTABLE) "profonde forêt" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Sur une " COLOR(RED) "haute montagne" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Dans un " COLOR(BLUE) "vaste lac" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Dans la " COLOR(PURPLE) "maison des morts" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Dans la " COLOR(YELLOW) "déesse de sable" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Grâce au Héros du Temps les \n"
"éveillés chasseront les forces \n"
"maléfiques du monde et apporteront \n"
"paix et justice en Hyrule!" BOX_BREAK UNSKIPPABLE "Telle est la légende des temples,\n"
"transmise de génération en \n"
"génération par mon peuple, les\n"
COLOR(BLUE) "Sheikahs" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Je suis désolée.\n"
"Nous ne sommes pas ouverts pour \n"
"l'instant. Revenez plus tard!" EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Frappe-le avec " COLOR(RED) "l'Epée de Légende" COLOR(DEFAULT) "!\n"
"Seule la sainte lame peut terrasser\n"
"Ganon!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Je t'attendais,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", Héros du Temps..." BOX_BREAK UNSKIPPABLE "Tu as traversé bien des épreuves\n"
"pour éveiller les six Sages." BOX_BREAK UNSKIPPABLE "Il ne te reste plus que la dernière\n"
"épreuve, la plus terrible! La \n"
"confrontation finale avec \n"
"Ganondorf, le Seigneur du Malin..."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x21") "Toi, quêteur des saints\n"
SHIFT("\x21") "triangles, écoute bien..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x0E") "Les triangles sacrés reposent\n"
SHIFT("\x29") "en un lieu mystique,\n"
SHIFT("\x11") "un miroir reflétant l'intérieur\n"
SHIFT("\x46") "de l'âme..." BOX_BREAK_DELAYED("\x46")  UNSKIPPABLE  SHIFT("\x14") "Si une âme noire y pénètre,\n"
SHIFT("\x0C") "le royaume deviendra chaos et\n"
SHIFT("\x0B") "flammes. Si elle est pure, il se\n"
SHIFT("\x23") "changera en paradis...." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x06") "La Triforce, les triangles sacrés,\n"
SHIFT("\x11") "est une balance qui équilibre\n"
SHIFT("\x28") "les trois puissances:\n"
SHIFT("\x15") "Force, Sagesse et Courage." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x20") "Si l'âme du porteur des\n"
SHIFT("\x1B") "Saints Triangles préserve\n"
SHIFT("\x0F") "cet équilibre, alors le porteur\n"
SHIFT("\x20") "aura l'ultime puissance!" BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x07") "Mais si son âme est tourmentée\n"
SHIFT("\x25") "la Triforce se brisera\n"
SHIFT("\x18") "en trois parties: la Force,\n"
SHIFT("\x19") "la Sagesse et le Courage." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x11") "A celui qui a brisé l'équilibre\n"
SHIFT("\x15") "il ne restera qu'une pièce...\n"
SHIFT("\x13") "Celle qui correspond le plus\n"
SHIFT("\x34") "à ses ambitions." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x0C") "Et s'il cherche l'Ultime Pouvoir,\n"
SHIFT("\x19") "il devra acquérir les deux\n"
SHIFT("\x3A") "autres pièces." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Ces deux pièces seront transmises\n"
SHIFT("\x2B") "aux élus du Destin.\n"
SHIFT("\x10") "Ils porteront la marque de la\n"
SHIFT("\x10") "Triforce au dos de leur main." FADE("\x5A")
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Il y a sept ans, Ganondorf, \n"
"utilisa la porte que tu as ouverte \n"
"dans le temple du temps pour \n"
"violer le Saint Royaume." BOX_BREAK UNSKIPPABLE "Mais en posant la main sur la \n"
"Triforce la légende devint réalité."
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Le porteur de la " COLOR(RED) "Triforce du \n"
"courage" COLOR(DEFAULT) ", c'est...\n"
"Toi, " NAME "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Le détenteur de la " COLOR(RED) "Triforce\n"
"de la sagesse" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "...est le septième Sage, dont\n"
"le destin est de conduire les \n"
"autres éveillés..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "C'est moi," COLOR(RED) " Zelda" COLOR(DEFAULT) ", Princesse\n"
"d'Hyrule."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Pardonne-moi de t'avoir caché ma\n"
"véritable identité, mais je devais \n"
"me dérober aux yeux de Ganondorf."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Je t'ai vu en m'enfuyant du \n"
"château d'Hyrule." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "En te confiant l'ocarina, je pensais\n"
"pouvoir empêcher Ganondorf de \n"
"violer le Saint Royaume, mais..." BOX_BREAK UNSKIPPABLE "Quelque chose d'inattendu\n"
"est arrivé..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x19") "Cette secousse...c'est...!?"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Princesse Zelda...\n"
"Petite cachottière!" BOX_BREAK UNSKIPPABLE "Je te félicite d'avoir échappé à\n"
"mes recherches pendant sept ans."
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Si tu veux sauver la Princesse,\n"
"viens la chercher au château!"
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "... C'est moi, Rauru!\n"
"Peux-tu m'entendre?" BOX_BREAK UNSKIPPABLE "Nous, les six Sages, allons \n"
"concentrer nos pouvoirs pour \n"
"créer une passerelle vers le \n"
"château de Ganondorf..." BOX_BREAK UNSKIPPABLE "Le donjon, la Tour de Ganon, \n"
"est protégé par " COLOR(RED) "six barrières \n"
"maléfiques" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Abats ces barrières et sauve la\n"
"Princesse Zelda!!"
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

DEFINE_MESSAGE(0x706C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Anciens créateurs d'Hyrule!" BOX_BREAK_DELAYED("\x3C") "Ouvrez le sceau dimensionnel et\n"
"renvoyez l'incarnation du Malin\n"
"dans le vide infernal!!" FADE("\x5A")
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "!\n"
"Achève-le avec la lame sacrée, \n"
"l'Epée de Légende!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ô, sceau dimensionnel ouvert par \n"
"les Sages... Referme-toi sur \n"
"l'Incarnation du Malin!!"
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Merci, " NAME "..." BOX_BREAK UNSKIPPABLE "Grâce à toi, Ganondorf est \n"
"prisonnier du royaume infernal!" BOX_BREAK UNSKIPPABLE "La paix et la justice vont à \n"
"nouveau régner sur ce monde...\n"
"Et pour longtemps."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x1E") "Merci, " NAME "..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  SHIFT("\x4B") "Adieu...." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu veux vraiment passer? \n"
"Bon...laisse-moi réfléchir...\n"
"C'est d'accord, mais en échange..." TEXTID("\x70\x72")
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Donne-moi 10 Rubis...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Crois-moi....\n"
"Mes visions prophétiques sont\n"
"toujours exactes!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu as détruit l'odieux fantôme\n"
"de ce temple et éveillé le Sage..." BOX_BREAK UNSKIPPABLE "Mais d'autres Sages ont besoin de\n"
"ton aide." BOX_BREAK UNSKIPPABLE "Pour éveiller les autres Sages, tu \n"
"devras devenir encore plus \n"
"puissant..." BOX_BREAK UNSKIPPABLE "Va par les montagnes..." BOX_BREAK UNSKIPPABLE "Sous les flots..." BOX_BREAK UNSKIPPABLE "Et deviens voyageur du Temps..."
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Aussi longtemps que tu garderas\n"
COLOR(LIGHTBLUE) "l'ocarina " COLOR(DEFAULT) "et " COLOR(LIGHTBLUE) "l'Epée de Légende" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "...le temps sera avec toi..." BOX_BREAK UNSKIPPABLE  NAME "... A bientôt!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est un nouveau type de bombes!\n"
"Disponible uniquement en quantité\n"
"limitée! Quand y'en a pus, ben... \n"
"Y'en a pus!" EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mon nom est " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"L'un des derniers Sheikahs..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Armé de L'" COLOR(RED) "Epée de Légende" COLOR(DEFAULT) ", \n"
"le titre de Héros du Temps te\n"
"revient de droit..."
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Si j'en crois les légendes, ta quête\n"
"est claire... Tu dois éveiller " COLOR(RED) "les \n"
"cinq Sages " COLOR(DEFAULT) "dans les cinq temples..."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "L'un des Sages attend dans le \n"
COLOR(ADJUSTABLE) "Temple de la forêt " COLOR(DEFAULT) "l'heure de son \n"
"éveil. C'est une jeune fille que tu \n"
"connais..." BOX_BREAK UNSKIPPABLE "L'influence maléfique qui pervertit \n"
"les temples l'empêche de répondre \n"
"aux appels du Saint Royaume..." BOX_BREAK UNSKIPPABLE "Equipé comme tu l'es, tu ne\n"
"pourras entrer dans le Temple..." BOX_BREAK UNSKIPPABLE "Alors crois-moi, rends-toi au\n"
COLOR(RED) "Village Cocorico" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "M'as-tu compris, \n"
NAME "?"
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Je pensais que te confier l'ocarina\n"
"était notre seule chance..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "J'ai certaines choses à te dire... \n"
"Ecoute-moi bien." BOX_BREAK UNSKIPPABLE "Voici une autre légende sur la\n"
"Triforce connue des Sheikahs, \n"
"le peuple de l'ombre...."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "La Triforce s'est brisée en \n"
"trois parties. Ganondorf possède \n"
"la " COLOR(RED) "Triforce de la Force" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Grâce à sa Triforce il put devenir\n"
"le Seigneur du Malin. Mais ses \n"
"ambitions maléfiques n'ont pas de\n"
"limites."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Pour devenir le maître du monde\n"
"Ganondorf cherche les " COLOR(RED) "élus du \n"
"destin" COLOR(DEFAULT) " pour s'approprier les deux \n"
"pièces restantes de la Triforce."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "En ce jour maudit, il y a sept ans,\n"
"Ganondorf prit d'assaut le Château \n"
"d'Hyrule..."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Après avoir ouvert les portes du\n"
"Temps, l'Epée de Légende t'a \n"
"envoyé dans le Saint Royaume..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ton esprit s'est endormi dans le \n"
"Saint Royaume et Ganondorf viola\n"
"ce lieu sacré pour se saisir de la\n"
"Triforce..." BOX_BREAK UNSKIPPABLE "Ganondorf est devenu le Roi du \n"
"Mal, et sous son règne de haine, \n"
"Hyrule s'est transformée en une \n"
"terre hostile." BOX_BREAK UNSKIPPABLE "Je pris l'apparence d'un Sheikah en \n"
"attendant l'éveil de ton esprit. \n"
"Pendant sept longues années..."
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Désormais...et grâce à toi....\n"
"Le règne maléfique de Ganondorf \n"
"va prendre fin!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Les six Sages ouvriront le sceau\n"
"pour attirer Ganondorf dans le \n"
"Saint Royaume." BOX_BREAK UNSKIPPABLE "Je fermerai ensuite la porte.\n"
"Pour toujours..." BOX_BREAK UNSKIPPABLE "Ainsi Ganondorf, le Seigneur du \n"
"Malin, disparaîtra d'Hyrule." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Ton devoir est de me protéger\n"
"pendant l'exécution de ce plan." BOX_BREAK UNSKIPPABLE "Voici une arme qui pourra \n"
"pénétrer les défenses du Seigneur\n"
"du Malin...\n"
"L'arme sacrée de l'élu..." BOX_BREAK UNSKIPPABLE  SHIFT("\x0F") "La sainte " COLOR(LIGHTBLUE) "flèche de lumière" COLOR(DEFAULT) "!!!"
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mais tu as baissé ta garde...\n"
"Et grâce à ce gamin, encore une \n"
"fois, j'ai pu te retrouver!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ma seule erreur fut de sous-\n"
"estimer sa puissance..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mais sa puissance n'est que\n"
"misère...\n"
"Sa seule force est la Triforce du\n"
"Courage!" BOX_BREAK UNSKIPPABLE "Grâce à la Triforce de la Sagesse, \n"
"celle de Zelda...\n"
"Deux parties seront en ma \n"
"possession!" BOX_BREAK UNSKIPPABLE "Et bientôt tu me remettras ton\n"
"fragment... \n"
"Je serai alors le maître du monde!"
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ouverte par l'Ocarina du Temps, \n"
"la porte laissa apparaître l'élu, \n"
"porteur de l'Epée de Légende." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je ne sais pas pourquoi, mais les \n"
"chiens aiment sortir le soir.\n"
"C'est curieux, hein?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Mon petit, écoute ceci..." BOX_BREAK "On dit qu'il y a une " COLOR(RED) "étrange \n"
"fontaine" COLOR(DEFAULT) " près du château..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Pour voyager vers le passé, \n"
"pose l'Epée de Légende dans le \n"
COLOR(RED) "piédestal" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "A nouveau tu seras un jeune\n"
"garçon...."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Un jour viendra où tu voudras\n"
"revenir ici au plus vite...\n"
"Ecoute-moi et ton esprit volera,\n"
"défiant le temps et l'espace..." BOX_BREAK UNSKIPPABLE "Entends et apprends car voici...\n"
COLOR(LIGHTBLUE) "Le Prélude de la lumière" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mon nom est " COLOR(RED) "Impa " COLOR(DEFAULT) "des Sheikahs.\n"
"Je suis chargée de la protection\n"
"de la Princesse Zelda."
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les gardes du Roi ne doivent \n"
"pas te trouver en ces lieux. \n"
"Laisse-moi te guider hors du \n"
"château."
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Hé! Toi! Ne fais pas l'imbécile!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Tu es un garçon courageux...\n"
"Une grande et périlleuse aventure\n"
"t'attend!" BOX_BREAK UNSKIPPABLE "D'après les prédictions de la \n"
"Princesse, mon rôle est d'enseigner\n"
"une mélodie au garçon de la forêt." BOX_BREAK UNSKIPPABLE "Cette mélodie est transmise de" COLOR(BLUE) "\n"
COLOR(DEFAULT) "génération en génération" COLOR(BLUE) " au sein\n"
"de la Famille Royale" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Elle fut pendant longtemps la \n"
"berceuse de la Princesse Zelda..." BOX_BREAK UNSKIPPABLE "Ces notes renferment un pouvoir\n"
"mystérieux." BOX_BREAK UNSKIPPABLE "Ecoute bien..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je suis responsable de tous les \n"
"maux d'Hyrule..." BOX_BREAK UNSKIPPABLE "J'étais si jeune... \n"
"J'ignorais que le contrôle du Saint \n"
"Royaume pouvait entraîner tant de \n"
"troubles..." BOX_BREAK UNSKIPPABLE "Je t'ai fait prendre beaucoup de\n"
"risques." BOX_BREAK UNSKIPPABLE "Il est temps pour moi de réparer\n"
"mes erreurs..." BOX_BREAK UNSKIPPABLE "Laisse derrière toi l'Epée de \n"
"Légende et scelle les portes du \n"
"Temps..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mais en faisant cela les chemins\n"
"du temps seront à jamais fermés..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ",\n"
"rends-moi l'Ocarina..." BOX_BREAK UNSKIPPABLE "En tant que Sage, je peux te\n"
"renvoyer dans ton temps."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Quand la paix reviendra en Hyrule...\n"
UNSKIPPABLE "Il sera temps de nous dire adieu..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Rentre chez toi, " NAME ".\n"
"Retourne à ton époque!" BOX_BREAK UNSKIPPABLE "Ta maison... \n"
"Là est ta place...\n"
"Là est ton temps..."
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x42")  QUICKTEXT_ENABLE "Tss..." QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Tss..." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm...Tu as perdu ton argent de\n"
"poche?" EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bon...j'te laisse passer!" EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"GARDE CA POUR TOI!\n"
"NE LE REPETE A PERSONNE!"
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Haaa! Je suis siiiii fatigué!" BOX_BREAK "Les tours de garde nocturnes sont\n"
"super-méga-lourds!\n"
"Y'a même pas de fantômes..." BOX_BREAK "Hein? J'adore les fantômes!" BOX_BREAK "C'est ma passion! En savoir \n"
"beaucoup sur les Esprits et les\n"
"Ames peut être utile, non?"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon petit Kiki est le plus beau!\n"
"Il est le plus beau du moooonde!\n"
"C'est un gentil Kiki d'amour et\n"
"d'amitié qui me fait des bisous!"
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon p'tit Kiki, il est le Kiki le \n"
"plus rapide du moooonde!\n"
"Il court et saute et fait des \n"
"bisous à sa mémère."
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Je ne trouve plus mon petit KIKI!\n"
"Il est où le Kiki? Il est où?\n"
"Kiki! Kiki! Mon p'tit Kiki!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4C")  QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"C'est pas mon chien ça!\n"
"Celui-là il bave et il est moche!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x53")  QUICKTEXT_ENABLE "KIKI!" QUICKTEXT_DISABLE  BOX_BREAK "Mon p'tit Kiki! C'est bien lui!\n"
"Merci! Merci!\n"
"Tiens! Voilà pour toi!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"La nuit des chiens errants sèment \n"
"la terreur, j'ai peur!\n"
"Pas pour toi...pour mon chien.\n"
"Mon Kiki à moi....mon p'tit Kiki!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"B'jour!\n"
"Bienvenue à la " COLOR(RED) "Foire aux Masques" COLOR(DEFAULT) "!\n"
"Notre devise:\n"
"Un masque, un sourire,...la joie!" BOX_BREAK "Veux-tu devenir un coursier \n"
"officiel distributeur de bonheur? \n"
"Je te prête un masque, tu le \n"
"vends et tu me rapportes " COLOR(RED) "l'argent" COLOR(DEFAULT) "." BOX_BREAK "Pour jeter un oeil aux clauses du\n"
"contrat, va lire la " COLOR(RED) "pancarte" COLOR(DEFAULT) "." BOX_BREAK "Après avoir vendu tous les \n"
"masques, ta joie sera aussi grande\n"
"que le Mont du Péril!" BOX_BREAK SHIFT("\x32") "Aie la foi, petit..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Choisis un masque avec le " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Parler au vendeur\n"
"Quitter" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Un " COLOR(RED) "masque" COLOR(DEFAULT) " est un objet \n"
"d'" COLOR(YELLOW) "inventaire [C]" COLOR(DEFAULT) ".\n"
"Assigne-le à " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " et active-le avec\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " pour le porter." BOX_BREAK "Tes interlocuteurs réagiront\n"
"différemment en fonction de ton\n"
"masque." BOX_BREAK "Si quelqu'un s'intéresse à ton \n"
"masque, n'hésite pas à lui vendre." BOX_BREAK "Quelque part, perdu dans ce \n"
"monde de haine, une voix s'élève \n"
"par-delà les montagnes:\n"
QUICKTEXT_ENABLE "\"J'VEUX UN MASQUE\"!" QUICKTEXT_DISABLE  BOX_BREAK "C'est une image, bien sûr..." EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai vu une jolie fille passer...\n"
"Elle allait vers le château?\n"
"J'en sais rien moi!"
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Haaaa, bien! Tu l'as vendu!\n"
"Donne-moi " COLOR(RED) "10 Rubis " COLOR(DEFAULT) "pour le Masque\n"
"du Renard." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ho! Tu n'as pas vendu le masque?\n"
"Pas grave...ça viendra...\n"
"Cherche encore! Encore! Encore!" EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Merci mon joli!" EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Quoi?!" QUICKTEXT_DISABLE "\n"
"Tu n'as pas mon argent?!" BOX_BREAK QUICKTEXT_ENABLE "C'EST MAL!" QUICKTEXT_DISABLE  BOX_BREAK "Donne-moi mon pognon...sinon...\n"
"Plus de masques!" EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Fantastique!" BOX_BREAK "Tous les masques ont été vendus." BOX_BREAK "Tu es un excellent vendeur.\n"
"Je l'ai toujours su!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "En récompense...\n"
"Je te laisse ce masque spécial." BOX_BREAK UNSKIPPABLE "C'est le " COLOR(RED) "Masque de Vérité" COLOR(DEFAULT) ". \n"
"ses pouvoirs sont mystérieux...\n"
"Il me vient des Sheikahs." BOX_BREAK UNSKIPPABLE "Ce masque te permet de lire dans\n"
"l'esprit des gens...\n"
"Pratique mais effrayant!" BOX_BREAK UNSKIPPABLE "Pourquoi effrayant?" BOX_BREAK UNSKIPPABLE "Ha! Tu as encore bien des choses\n"
"à apprendre! Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Tu peux désormais emprunter \n"
"n'importe quel masque.\n"
"Amuse-toi bien..." EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bienvenue!\n"
"Quel masque te ferait plaisir?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Choisis un masque avec le " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Le Masque de Vérité?\n"
"Quitter" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Voici le " COLOR(RED) "Masque de Vérité" COLOR(DEFAULT) ". \n"
"Cet objet Sheikah est très \n"
"mystérieux." BOX_BREAK "Il permet de lire dans les esprits.\n"
"Pratique mais effrayant!" BOX_BREAK "Pourquoi effrayant?" BOX_BREAK "Tu comprendras quand tu seras \n"
"grand!" BOX_BREAK "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Vérité -- En exposition\n"
COLOR(DEFAULT) "Ce masque détient d'étranges \n"
"pouvoirs." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Mort -- 20 Rubis" COLOR(DEFAULT) "\n"
"Une tête de mort avec des cornes." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque d'Effroi -- 30 Rubis\n"
COLOR(DEFAULT) "Un masque de bois bien triste." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque du Renard -- 10 Rubis\n"
COLOR(DEFAULT) "Le Renard est à la mode!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque du Lapin -- 50 Rubis\n"
COLOR(DEFAULT) "Ses oreilles sont à croquer!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque  de Mort -- Gratuit" COLOR(DEFAULT) "\n"
"Une tête d'os avec des cornes." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque d'Effroi -- Gratuit\n"
COLOR(DEFAULT) "Un  masque en bois bien triste." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque du Renard -- Gratuit\n"
COLOR(DEFAULT) "Le Renard est à la mode!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque du Lapin -- Gratuit\n"
COLOR(DEFAULT) "Ses oreilles sont à croquer!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Goron -- Gratuit\n"
COLOR(DEFAULT) "Une grosse tête, c'est rigolo!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Zora -- Gratuit" COLOR(DEFAULT) "\n"
"A la mode pour une baignade!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Gerudo -- Gratuit\n"
COLOR(DEFAULT) "Un parfait déguisement de femme." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Masque de Vérité -- Gratuit" COLOR(DEFAULT) "\n"
"Un mystérieux masque permettant \n"
"de lire dans l'esprit des hommes." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque de Mort" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque d'Effroi" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux- tu le " COLOR(RED) "Masque du Renard" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque du Lapin" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque de Goron" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque de Zora" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque de Gerudo" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Veux-tu le " COLOR(RED) "Masque de Vérité" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bravo! Tu as vendu ton masque!\n"
"Donne-moi " COLOR(RED) "20 Rubis " COLOR(DEFAULT) "pour le\n"
"Masque de Mort." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bravo! Tu as vendu ton masque!\n"
"Donne-moi " COLOR(RED) "30 Rubis " COLOR(DEFAULT) "pour le \n"
"Masque d'Effroi." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Bravo! Tu as vendu ton masque!\n"
"Donne-moi " COLOR(RED) "50 Rubis " COLOR(DEFAULT) "pour le \n"
"Masque du Lapin." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh! Tu n'as pas encore vendu le\n"
"masque. Continue et garde espoir." BOX_BREAK "Tu veux peut-être essayer avec\n"
"un autre masque?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Oui\n"
"Non" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Les fragments de la Triforce \n"
"se réveillent...\n"
"Ils fusionnent une fois de plus..."
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Il y a sept ans...\n"
"Deux fragments ont échappé à \n"
"mon contrôle..." BOX_BREAK UNSKIPPABLE "Comment ont-ils pu arriver entre\n"
"vos mains?"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quoi qu'il en soit, les fragments \n"
"vont enfin s'unir en ce lieu!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Pauvres insectes....\n"
"Cette puissance n'est pas \n"
"pour vous!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je vous ordonne de me les rendre!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"Je ne peux pas t'aider!\n"
"L'énergie noire m'empêche \n"
"d'approcher!" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Pardonne-moi, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quoi? Le Grand Ganondorf vaincu \n"
"par ce gamin?!"
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Misérable Ganondorf......" BOX_BREAK UNSKIPPABLE "Sans un esprit sain et fort il ne\n"
"put maîtriser la puissance \n"
"des dieux...et..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", Ecoute-moi!\n"
"La tour va s'effondrer!" BOX_BREAK UNSKIPPABLE "De son dernier souffle de haine, \n"
"Ganon tente de nous écraser sous \n"
"les ruines de cette tour!\n"
"Dépêchons-nous!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Suis-moi vite!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "C'est terminé...enfin..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... \n"
"Pardonne-moi...je n'ai pas pu t'aider." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Quel est ce bruit?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Cette fois-ci je ne fuirai pas!\n"
COLOR(DEFAULT)  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Nous combattrons ensemble!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! \n"
"L'Epée de Légende est ici! \n"
QUICKTEXT_ENABLE "Vite!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mes pouvoirs paralysent Ganon!\n"
"Utilise l'Epée et porte-lui le coup\n"
"de grâce!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x41") "Six Sages...\n"
QUICKTEXT_ENABLE  SHIFT("\x3D") "Maintenant!!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x03") "TOI..." TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x03") "SOIS MAUDITE...ZELDA!\n"
TEXT_SPEED("\x02") "PESTE SOIT DES...SAGES!!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "JE TE MAUDIS..." QUICKTEXT_ENABLE  NAME "!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Un jour...\n"
"Ce sceau se brisera et...." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Je tuerai de mes mains tes \n"
"descendants!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "N'oublie pas...\n"
"Le fragment de la Force est \n"
"toujours en ma possession!...." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
TEXT_SPEED("\x02") "Toi..." TEXT_SPEED("\x00") "Qui es-tu?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x15") "La " COLOR(ADJUSTABLE) "Barrière de la Forêt " COLOR(DEFAULT) "est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x23") "Vite, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x21") "La " COLOR(RED) "Barrière du Feu " COLOR(DEFAULT) "est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x3F") "Vite, Frère!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x1F") "La " COLOR(BLUE) "Barrière de l'Eau " COLOR(DEFAULT) "est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x3E") "Depèche-toi!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x17") "La " COLOR(PURPLE) "Barrière de l'Ombre " COLOR(DEFAULT) "est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x18") "Va et sauve la Princesse!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x18") "La " COLOR(YELLOW) "Barrière de l'Esprit " COLOR(DEFAULT) "est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x40") "Vite, gamin!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "La " COLOR(LIGHTBLUE) "Barrière de la Lumière" COLOR(DEFAULT) " est\n"
SHIFT("\x48") "dissipée!\n"
SHIFT("\x52") "Vite!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE)  NAME ", mais c'est...?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "C'est la Lame purificatrice..." COLOR(DEFAULT)  FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "L'Epée de Légende!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Trouve les Sages et sauve Hyrule!" FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cet homme effrayant a semé une\n"
"sacrée pagaille ici!"
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! J'ai si peur...\n"
"Je suis terrifié..."
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Que veux-tu?\n"
"Je n'ai pas le temps de parler!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pitié avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Pitié vends-moi un truc...\n"
"Pitié avec " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non...\n"
"C'est pas ça que je veux...\n"
"Je veux un truc " COLOR(RED) "dans une bouteille" COLOR(DEFAULT) ".\n"
"Pas ce drôle de truc..."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non...\n"
"Je peux pas prendre ça...\n"
"J'veux pas acheter ça..."
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! C'est une " COLOR(LIGHTBLUE) "Flamme Bleue" COLOR(DEFAULT) "!\n"
"Je t'en donne " COLOR(RED) "150 Rubis" COLOR(DEFAULT) "!\n"
"Vends-la moi! Vends-la moi!"
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Un p'tit " COLOR(PURPLE) "poisson" COLOR(DEFAULT) "!\n"
"Je t'en donne " COLOR(RED) "100 Rubis" COLOR(DEFAULT) "!\n"
"Dis-moi oui...chéri."
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mais...c'est un superbe..." COLOR(ADJUSTABLE) "insecte" COLOR(DEFAULT) "!\n"
"Je t'en donne " COLOR(RED) "50 Rubis" COLOR(DEFAULT) "!\n"
"Donne! Donne!"
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle jolie " COLOR(LIGHTBLUE) "fée" COLOR(DEFAULT) "!\n"
"Je t'en offre " COLOR(RED) "25 Rubis" COLOR(DEFAULT) ", OK?"
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quel garçon plein d'entrain et \n"
"de vie...j'adore ça..." BOX_BREAK UNSKIPPABLE "Hé hé hé...ton nom est bien\n"
NAME "?" BOX_BREAK UNSKIPPABLE "Hé hé hé...ne sois pas surpris!\n"
"Je lis dans les esprits comme \n"
"dans un livre ouvert." BOX_BREAK UNSKIPPABLE "Si j'avais autant d'énergie que toi, \n"
"je pourrais changer de métier!\n"
"Hé hé hé..." BOX_BREAK UNSKIPPABLE "Je suis l'unique " COLOR(RED) "marchand d'âmes \n"
COLOR(DEFAULT) "de tout le Royaume d'Hyrule." BOX_BREAK UNSKIPPABLE "Depuis la venue de Ganondorf, les\n"
"affaires marchent plutôt bien...\n"
"Hé hé hé..." BOX_BREAK UNSKIPPABLE "Oh...Je ne peux qu'espérer une\n"
"nouvelle guerre!" BOX_BREAK UNSKIPPABLE "Les fantômes du nom d'" COLOR(RED) "Esprits" COLOR(DEFAULT) "\n"
"sont l'essence même de la haine. \n"
"Ils apparaissent dans les \n"
"cimetières ou dans les plaines." BOX_BREAK UNSKIPPABLE "Jeune homme plein de vie, si par \n"
"chance tu en captures un, viens \n"
"donc me le vendre...\n"
"Tu gagneras beaucoup d'argent!"
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Jeune homme plein de vie!\n"
"Quoi de neuf? \n"
"As-tu un Esprit ou une Ame à me \n"
"vendre?" BOX_BREAK "Ta carte a " COLOR(PURPLE)  HIGHSCORE(HS_POE_POINTS) " " COLOR(DEFAULT) "points.\n"
"Reviens vite me voir!\n"
"Hé hé hé!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh! Tu as apporté un fantôme!" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Hmmm..." BOX_BREAK UNSKIPPABLE "Ce n'est qu'un " COLOR(RED) "Esprit" COLOR(DEFAULT) ".\n"
"Je t'en donne " COLOR(RED) "10 Rubis" COLOR(DEFAULT) ". \n"
"C'est tout!" BOX_BREAK UNSKIPPABLE "Hé hé hé."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh! Tu as apporté un fantôme!" BOX_BREAK UNSKIPPABLE "Hmmmm!" BOX_BREAK UNSKIPPABLE "Magnifique!\n"
"C'est une " COLOR(RED) "Ame" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Je t'en donne " COLOR(RED) "50 Rubis" COLOR(DEFAULT) "." BOX_BREAK "Et en plus, j'inscris " COLOR(RED) "100 points\n"
COLOR(DEFAULT) "sur ta carte." BOX_BREAK UNSKIPPABLE "Obtiens " COLOR(RED) "1,000 points" COLOR(DEFAULT) " et tu ne\n"
"seras pas déçu...\n"
"Hé hé hé."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ooooh! WHOA!" BOX_BREAK UNSKIPPABLE "Tu as obtenu " COLOR(RED) "1,000 points" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Tu es un véritable " COLOR(RED) "chasseur de\n"
"fantômes" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Il est content? Hein? \n"
"Il est content le monsieur?\n"
"Hé hé hé!" BOX_BREAK UNSKIPPABLE "Grâce à toi, mon stock d'" COLOR(RED) "Ames" COLOR(DEFAULT) " est\n"
"plein! C'est donc la dernière fois \n"
"que nous faisons affaire." BOX_BREAK UNSKIPPABLE "Je sais, je sais...\n"
"Nous avions passé un pacte...\n"
"Tu as eu tes 1000 points et je \n"
"t'en félicite... Hé hé hé!" BOX_BREAK UNSKIPPABLE "Alors prends donc ceci, \n"
"mon bon ami!"
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh? C'est quoi ça?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Est-ce" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "une" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B") "..." QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Fée" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!" BOX_BREAK UNSKIPPABLE "Alors tu es un garçon...\n"
"de la forêt?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Alors...mais alors...tu dois avoir\n"
"la...la " COLOR(ADJUSTABLE) "Pierre Ancestrale de la \n"
"forêt" COLOR(DEFAULT) "?! Hein? Cette belle pierre \n"
"verte et brillante..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "J'ai fait un rêve...Dans ce rêve,\n"
"des nuages noirs et épais \n"
"recouvraient la terre d'Hyrule..." BOX_BREAK UNSKIPPABLE "Quand soudain, un rayon de \n"
"lumière surgit de la forêt, \n"
"dispersant les ténèbres et \n"
"illuminant la terre..." BOX_BREAK UNSKIPPABLE "Cette lumière se matérialisa sous \n"
"la forme d'un garçon tenant une \n"
COLOR(ADJUSTABLE) "pierre verte " COLOR(DEFAULT) "dans la main. \n"
"Une " COLOR(LIGHTBLUE) "fée " COLOR(DEFAULT) "volait à ses côtés..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Je sais qu'une prophétie annonce\n"
"la venue d'un enfant de la " COLOR(ADJUSTABLE) "forêt" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Cet enfant...ne peut être que toi." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D") "Oh! Pardonne-moi!" BOX_BREAK UNSKIPPABLE "Je parle, je parle et je ne me\n"
"suis toujours pas présentée..." EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2A") "Mon nom est " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ",\n"
SHIFT("\x2E") "Princesse d'Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quoi? On se connaît?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh... C'est trop mignon!\n"
"Où l'as-tu trouvé?"
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wouaaaaaah!\n"
"Au secours!"
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein?...ouais? Et alors?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"JE HAIS LES RENARDS!"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est agaçant ton truc!"
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa! La classe!"
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beuark! C'est quoi ton problème?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh...c'est un Zora?\n"
"Ses yeux sont fascinants..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yaaah! J'ai peur!!\n"
"Ne me mange pas! \n"
"Ne me mange pas!"
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est-y pas mignon...\n"
"La jeunesse, les masques...\n"
"Tout ça est si loin à présent."
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est rigolo ton truc!\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Oh-oh!" QUICKTEXT_DISABLE " Bonjour maman!\n"
"...Hein? C'est toi!\n"
"T'es malade ou quoi?"
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Woah! T'as une de ces têtes!"
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Enlève-le tout d'suite!\n"
"J'ai peur..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Y a-t-il un concours de masques \n"
"en ce moment?\n"
QUICKTEXT_ENABLE "Je vais voter pour toi!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Un lapin! Un petit lapinou!\n"
"Tout mimi. Tout gentil.\n"
"Il est à qui le lapin? Hein?\n"
"Il est à qui? C'est mignoooon."
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh! Quelle belle fille!\n"
"Un peu petite mais...jolie."
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm? Oui? C'est pour quoi?\n"
"Tu veux ma photo?"
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Un masque... Cela me rappelle\n"
"mon enfance. Je gambadais dans\n"
"la forêt avec un masque...\n"
"Et puis un jour...? Tu m'écoutes?"
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohhhh...Je vois...\n"
"C'est une illusion d'optique..."
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé petit! Ne deviens pas comme\n"
"moi...ça craint."
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "YAAAAAAAAAAAH!\n"
"UNE GERUDO!!!!" QUICKTEXT_DISABLE  BOX_BREAK "Quoi? Un masque?\n"
"Mais pourquoi tu portes un truc\n"
"comme ça? T'es tapé ou quoi?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laisse-moi tranquille...ouste!"
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cool! C'est le Renard!\n"
"Bonjour monsieur le Renard!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle horreur!\n"
"Un petit garçon à Cocorico \n"
"cherchait un masque comme\n"
"celui-ci..."
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm...super...tu n'as pas un autre\n"
"masque?"
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Woah! Il est louche ton masque!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu vois pas qu'on discute?\n"
"Laisse-nous tranquilles!"
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Désolé. Je ne pourrai plus jamais\n"
"regarder une autre femme!"
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi...\n"
"Ne prête pas attention à ce petit.\n"
"Embrasse-moi plutôt, amour."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heu....\n"
"Tu veux pas aller aut'part?"
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On dit qu'un apothicaire fabrique\n"
"un médicament surpuissant!"
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On raconte qu'un monstre avale\n"
"les " COLOR(LIGHTBLUE) "boucliers" COLOR(DEFAULT) ". \n"
"En as-tu déjà vu un?"
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis venu vendre des bombes...\n"
"En veux-tu?"
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "J'ai...J'ai peur...\n"
"J'ai le sentiment que cet homme\n"
"va anéantir Hyrule." BOX_BREAK UNSKIPPABLE "Ses pouvoirs sont terrifiants!" BOX_BREAK UNSKIPPABLE "Mais ta venue est providentielle." EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein? Mais tu veux quoi?\n"
"Tu vas me lâcher, ouais?"
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'suis occupé! Dégage!\n"
"JE TE HAIS!"
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm... Du bois de qualité!"
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrr!\n"
"Tu m'oublies, oui?\n"
"Mauviette..."
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAAAAAAAAAAH!\n"
"Oups. Désolé.\n"
"Je ne devrais pas crier comme ça."
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Désolé, chef!\n"
"Ma pause est terminée!\n"
"Je vais travailler...promis!" BOX_BREAK "Heu...chef? C'est vous?"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les Gerudos sont si belles...\n"
"Je les aime! Toutes!"
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un jour j'aurai du talent.\n"
"Et alors je pourrai sculpter un \n"
"masque comme le tien!"
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est ça le masque à la mode?\n"
"Il est méga-moche!"
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wa-ha-hah!\n"
"Tout se passe comme vous le \n"
"voulez, M. Le Preux Chevalier?\n"
"Hah hah hah!"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis de service.\n"
"T'as compris?\n"
"DE SERVICE!"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmmm... Pas mal...enfin...\n"
"J'm'en fiche, quoi!"
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh! C'est trop mimi!\n"
"Mais mes cocottes sont encore \n"
"plus mignonnes!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein? Quoi?\n"
"Tu es joyeux ou triste?\n"
"Difficile à dire..."
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm... Ce n'est pas vraiment mon \n"
"style..."
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Le petit garçon du cimetière nous\n"
"parle toute la journée de son \n"
"visage..."
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je suis un type bien.\n"
"Tu ne me crois pas?"
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAA--! Hein?\n"
"J'ai cru que c'était encore l'autre\n"
"vieille bique! J'ai eu une de ces\n"
"frousses!"
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon père me parlait souvent\n"
"d'un forgeron...mais tout ça ne\n"
"m'intéresse plus...."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les monstres de la forêt ne me\n"
"font pas peur! Tu me prends pour\n"
"qui, toi?"
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmm? C'est quoi ça?\n"
"Je ne vois rien d'ici..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bonjour! Quelles nouvelles?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Belle journée, n'est-ce pas?"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fatigué...dormir..."
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les renards m'agacent!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu es assez agaçant toi, non?\n"
"Allez! Du balai!"
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmmm...joli!"
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaaaah!\n"
"C'est quoi ton problème, petit?"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Crétin! Enlève ton masque avant \n"
"de parler à quelqu'un!"
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Crétin! Ne parle pas aux gens en\n"
"les fixant!"
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Crétinus!\n"
"Regarde-moi quand j'te parle!"
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bouffon!\n"
"Je ne sais pas pourquoi mais...\n"
"Bouffon!"
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mon dieu! Ton visage!\n"
"Il est tout...\n"
"Quoi? C'est un masque?\n"
QUICKTEXT_ENABLE "Sors de chez moi!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Laisse-moi tranquille...\n"
"J'suis occupé."
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un masque est un instrument: \n"
"il reflète la personnalité... \n"
"J'aime ton style, petit!"
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle tête ENORME!\n"
"Comment as-tu pu entrer ici?!"
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"JE HAIS LES RENARDS!\n"
"Je les..... " QUICKTEXT_ENABLE "HAIS" QUICKTEXT_DISABLE "!"
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Alors ça...c'est bien la tête la\n"
"plus énervante de tous les temps!\n"
"Félicitations, petit!"
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa! Joli visage, petit!"
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu veux me parler?\n"
"Alors enlève ce truc!"
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heu...comment dire...\n"
"On n'a pas vraiment le temps de \n"
"jouer avec toi, petit!\n"
"SAUVE-NOUS!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"J'ai beau être un demi-monstre \n"
"mais... ton masque...comment dire...\n"
"YAAAAAAAAAAH!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Excuse-moi si je n'explose pas de\n"
"rire mais...comment dire...\n"
"SAUVE-NOUS ! ! ! !"
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "WOUAAAAAAA!\n"
"Il est monstrueux ton masque!\n"
"Hein? Oui, je sais...merci...\n"
"Moi aussi j'suis un monstre!"
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gheu?! Quoi?!?" BOX_BREAK "Oh...c'est juste un gamin...\n"
"J'ai eu une de ces trouilles!\n"
"Ma face fait peur aux cafards\n"
"mais je suis super sensible!"
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nom d'un ver pourri...\n"
"Regardez-moi cette tête!\n"
"Hein? Quoi ma tête?"
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! Tu sais c'que tu portes, là?\n"
"Vraiment? Mais t'es tapé!"
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je bosse, là... \n"
"Si tu veux qu'je creuse,\n"
"laisse-moi tranquille."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est quoi ça? C'est pas un p'tit\n"
"truc tout mignon qui saute un peu\n"
"partout? Comment ça s'appelle?"
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé! C'est un masque du Renard!!\n"
"J'ai demandé à mon papa de m'en\n"
"acheter un!"
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est Igor tout craché, hein?"
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Rien à voir avec Igor, hein?"
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Cool comme masque mais...\n"
"Il est un p'tit peu trop effrayant!"
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ce masque me dit quelque chose...\n"
"Je l'ai déjà vu dans la forêt, non?"
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Ce masque me rend...heureuse..."
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh.....sniff...\n"
"Ce masque...me rend...\n"
"Si triiiiste! Bouhouuuuuu!"
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha! Tu portes un masque, hein?\n"
"Tu as donc peur de moi!Ha ha!"
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yaaaaaaaaah! C'est quoi ça?\n"
"J'ai pas peur! J'ai pas peur!\n"
"Mais...ne t'approche pas de moi!\n"
"Compris?"
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa! Il est génial ton masque!\n"
"Tu veux bien être mon copain?\n"
"....Ha ha! Tu m'as cru, hein?\n"
"Pauv'nul, va! Ha ha ha ha ha!"
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah ha hah!\n"
"C'est ton portrait tout craché!"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yaaaaaah Waaaah! \n"
"J-Je vais le dire à Mido!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bwaaaaaaaahh!\n"
"J-Je vais dire à Mido de te \n"
"casser la figure!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whooooah!\n"
"Es-tu un fantôme de la forêt?"
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gé-nial! Super ton masque!\n"
"Heu...ne répète pas à Mido que j'ai \n"
"dit ça, OK?"
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hein?!\n"
"Tu es revenu!\n"
"Pas la peine de se cacher derrière\n"
"ce masque! Je t'ai reconnu!"
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je me demande quelle serait la \n"
"réaction de Mido en voyant ça..."
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Je vois...\n"
"Tu veux faire peur à Mido avec ce\n"
"masque, hein?"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah hah hah!\n"
"C'est trop drôle!\n"
"Saria va adorer ce masque!"
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi hi!!!\n"
"Un masque de bois?\n"
"C'est comme si tu portais un\n"
"bouclier sur la tête!"
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle drôle de tête!" BOX_BREAK "Au fait... Un enfant de la forêt\n"
"se plaint de son visage toute la\n"
"journée..."
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quelle ENORME tête!"
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi!\n"
"Où l'as-tu trouvé?\n"
"En dehors de la forêt?\n"
"Impossible! Je ne te crois pas!"
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha!\n"
"C'est rigolo mais...ce n'est pas\n"
"vraiment mon style..."
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cool! \n"
"Porter ce masque me donne\n"
"l'impression d'être un vrai dur!\n"
"Hé hé!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé! \n"
"Cool ton masque mais...bon."
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé!\n"
"J'ai mon masque maintenant...\n"
"Les autres ne m'intéressent pas..."
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Woah! Tu as une ENORME tête!"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "Oh! Le mignon petit rat!\n"
"Quoi?\n"
"C'est pas un rat? Tu rigoles?"
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "C'est quoi ces trucs mous\n"
"au-dessus de ta p'tite tête?\n"
"Des oreilles? T'en as quatre?"
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "Tu as réussi à éviter les gardes\n"
"avec ça sur la tête?"
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bonjour gentil garçon à la fée!\n"
"...Pardon?\n"
"Mais bien sûr que je t'ai reconnu!"
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa!\n"
"Quels énormes yeux!\n"
"Les Gorons sont siiiii mignons!"
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Je te reconnais! tu es le\n"
"Renard! Bonjour le Renard!\n"
"Tu es très à la mode, tu sais!"
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Les garçons...tous les mêmes!"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Attends...attends...\n"
"Je sais qui tu es...\n"
"Tu es...le Renard, non?\n"
"Woah! J'suis trop fort!"
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Whoa!... Il est moche ton masque!\n"
"Presque aussi moche que...Ingo!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu me rappelles ma femme...\n"
"Attends...finalement non.\n"
"Tu ne lui ressembles pas du tout!"
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"(Baille)...\n"
"J'suis un peu naze...\n"
"Tu me le montreras plus tard..."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hors de ma vue!\n"
"Tu vois pas que j'travaille?!"
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Très drôle... Tu verras plus tard!\n"
"La vie active n'est pas aussi \n"
"marrante que ça!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAAAAAH!\n"
"Heu? C'est juste un masque...\n"
"OK. Bonne blague. Super. Dégage."
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé hé...\n"
"Un petit rayon de soleil dans ma\n"
"journée... Merci mon garçon!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmmm... Voyons un peu ceci...\n"
"Du bel ouvrage! Du bois de\n"
"premier choix! Gni gni...."
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhh...oui! En effet...\n"
"Un travail impeccable...\n"
"L'auteur de ce masque est un \n"
"véritable chef."
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Un joli Goron!\n"
"A propos...Je me demande comment \n"
"se porte mon vieil ami Biggoron du\n"
"Mont du Péril."
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Etrange...\n"
"Il ne doit pas être soluble."
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Miam miam miam...\n"
"Cool. Un masque. Youpi.\n"
"Tu veux m'acheter des haricots?"
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Miam miam miam...\n"
"J'en veux pas de ton masque."
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Miam miam miam...\n"
"Ce n'est pas vraiment mon style..."
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Miam miam miam...\n"
"Heu...non. J'en veux pas."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que veux-tu?"
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu n'as pas l'air d'être un bon\n"
"nageur..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cheveux rouges...peau mate...\n"
"Cela me rappelle quelque chose..."
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hé hé hé!\n"
"Tu es trop petit pour être un\n"
"Zora..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho ho ho!\n"
"Tu Nous fais bien rire!"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ce visage...il Nous fait peur!"
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cela Nous rappelle notre vieil ami\n"
"d'enfance: le joyeux Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Te paies-tu Notre tête?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"T'es rigolo, toi!"
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ta tête... Elle est ENORME!"
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Arrête ça tout de suite...\n"
"Tu me perturbes..."
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Génial! Tu as enfin décidé de\n"
"devenir un Zora et de m'épouser?"
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHOA!\n"
"Mon coeur s'est mis à battre \n"
"très vite!"
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ce masque me dérange...\n"
"Au revoir."
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mmmmmmm...\n"
"Je ne sais pas quoi te dire."
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mange bien tous tes cailloux et\n"
"tu deviendras gros et fort \n"
"comme moi!"
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu vas m'lâcher les bottes, ouais?"
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu cherches à me faire rire?\n"
"Bah c'est raté!"
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu m'énerves. \n"
"File avant que j'te brise!"
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"JE HAIS LES GERUDOS!!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouste. Du balai!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah!\n"
"Alors comme ça on s'déguise?\n"
"T'es un marrant, toi!"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu vas m'laisser tranquille, oui?\n"
"Tu m'cherches?"
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu as du courage de porter ça...\n"
"Mais ton p'tit jeu ne prend pas!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"C'est quoi ça?\n"
"Quel rapport avec notre histoire?"
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"Tu as du courage, toi!\n"
"J't'aime bien, petit!"
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"On arrête de jouer une seconde?"
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Etrange...ça me ressemble...\n"
"En fait...pas du tout!\n"
"Je suis plus belle que ça!"
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Non! Ces oreilles sont nulles!\n"
"Je veux des oreilles un peu plus...\n"
"Enfin un peu moins...\n"
"Tu vois, quoi!"
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu te balades avec ça sur la\n"
"tête en pleine nuit? \n"
"T'as peur de rien, toi!"
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha hah!\n"
"Tu t'amuses bien?!"
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Un rocher ressemble à ça quelque\n"
"part...mais où?"
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vite, " NAME "!\n"
"La tour va s'effondrer!!"
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Attention aux chutes de pierres!"
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME "!\n"
"Au secours!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"La sortie est par là!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Merci, " NAME ".\n"
"Ne perdons pas de temps!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dommage!" BOX_BREAK "Entraîne-toi et reviens vite!" EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Presque!!" BOX_BREAK "Bon...je suis sympa!\n"
"La prochaine partie est gratuite. \n"
"Donne-toi à fond!" EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantastique!!!\n"
"Bravo!!!\n"
"Génial!!!" BOX_BREAK "Voici ton magnifique prix!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh, non! " COLOR(RED) "Le" COLOR(LIGHTBLUE) " " COLOR(RED) "temps est écoulé!\n"
COLOR(LIGHTBLUE) "L'objet à apporter est perdu!\n"
"Essayez à nouveau!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "DING! DONG!\n"
"Au quatrième top il sera: " TIME "!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tu connais le garde de Cocorico?\n"
"On va te faire un bon prix!"
)

