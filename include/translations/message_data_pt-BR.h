DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "Recebeu um " COLOR(RED) "Ovo de Bolso" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Um Cucco de Bolso chocará dele\n"
"durante a noite. Lembre-se de\n"
"devolvê-lo quando isto acontecer."
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "Você devolveu o Cucco de\n"
"Bolso e pegou " COLOR(RED) "Cojiro" COLOR(DEFAULT) " em\n"
"troca!" QUICKTEXT_DISABLE " Cojiro é um Cucco,\n"
"mas raramente canta."
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Conseguiu um " COLOR(RED) "Cogumelo\n"
"Estranho" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Esse cogumelo\n"
"fresco apodrece logo! Leve-o\n"
"à Loja de Poções de Kakariko!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "Rápido!"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "Você recebeu uma " COLOR(RED) "Poção\n"
"Estranha" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "Pode ser útil...\n"
"Rápido, vá para o Bosque\n"
"Perdido!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "Você devolveu a Poção Estranha\n"
"e pegou o " COLOR(RED) "Serrote de Invasor" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"O rapaz deve ter deixado para\n"
"trás."
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas  20 Peças   80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Deixar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "Conseguiu um\n"
COLOR(RED) "Saco para Nozes Deku" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Este saco suporta " COLOR(YELLOW) "40" COLOR(DEFAULT) " nozes\n"
"do estilingue."
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "Você trocou o Serrote de\n"
"Invasor por uma " COLOR(RED) "Espada Goron\n"
"Quebrada" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE "Biggoron pode\n"
"consertá-la!"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "Você deixou a Espada Goron\n"
"Quebrada e recebeu uma\n"
COLOR(RED) "Prescrição" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vá ver o Rei Zora!"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "A Espada Biggoron..." QUICKTEXT_DISABLE "\n"
"Você pegou um " COLOR(RED) "Comprovante" COLOR(DEFAULT) "\n"
"dela! Você não vê a hora da\n"
"espada ficar pronta!!"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Você trocou a Faca de Gigante\n"
"pela " COLOR(RED) "Espada Biggoron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua lâmina foi forjada por um\n"
"ferreiro mestre. Não quebra!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Você mostrou o Comprovante e\n"
"pegou a " COLOR(RED) "Espada Biggoron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua lâmina foi forjada por um\n"
"ferreiro mestre. Não quebra!"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "Você usou a Prescrição e\n"
"recebeu um " COLOR(RED) "Olho de Rã" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Seja\n"
"rápido e leve-o ao Lago Hylia\n"
"enquanto ainda está fresco!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "Você trocou o Olho de Rã\n"
"pelas " COLOR(RED) "Lágrimas mais Delicadas\n"
"do Mundo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Leve-as para\n"
"Biggoron antes que apodreçam!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x41")  COLOR(RED) "VENCEDOR" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara de\n"
"Caveira" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Você se sente como\n"
"um monstro com essa máscara!"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara de\n"
"Fantasma" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Você pode assustar\n"
"as pessoas com ela!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara Keaton" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para colocá-la!\n"
"Você será um cara popular com\n"
"esta máscara!"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "Você pegou um " COLOR(RED) "Capuz de\n"
"Coelho" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-lo! As orelhonas do\n"
"capuz são lindas!"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara de\n"
"Goron" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Isto fará você\n"
"ficar com um cabeção!"
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara de\n"
"Zora" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Com esta máscara,\n"
"você se tornará um dos Zoras!"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara de\n"
"Gerudo" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Esta máscara fará\n"
"você parecer uma garota!!"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Máscara da\n"
"Verdade" COLOR(DEFAULT) "." QUICKTEXT_DISABLE " Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"colocá-la! Mostre-a às\n"
"pessoas!"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem-vindo ao nosso melhor\n"
"centro de diversões:"
BOX_BREAK
SHIFT("\x15")  COLOR(RED) "O Campo de Boliche Bombchu!" COLOR(DEFAULT)
BOX_BREAK
"Você quer saber o que poderá\n"
"ganhar? Bem, é um " TEXT_SPEED("\x13") "segredo." TEXT_SPEED("\x00") "\n"
"Não posso dizer a você até que\n"
"pague para jogar."
BOX_BREAK
"São " COLOR(RED) "30 Rupees" COLOR(DEFAULT) " por jogo.\n"
"Quer jogar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "OK!!" QUICKTEXT_DISABLE
BOX_BREAK
"Mire no buraco do centro e\n"
"deixa " COLOR(RED) "Bombchu" COLOR(DEFAULT) " ir!\n"
"Você tem " COLOR(RED) "Dez Chances" COLOR(DEFAULT) ".\n"
"Preparado..."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "VAMOS LÁ!!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer jogar novamente?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, eu quase esqueci!\n"
"Você poderá ganhar isto!" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombas  (20 peças)   80 Rupees\n"
COLOR(DEFAULT) "Pegue-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " de\n"
"novo para jogá-la. Só poderá\n"
"comprar com um saco de bombas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombas  (30 peças)   120 Rupees\n"
COLOR(DEFAULT) "Prepare-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"de novo para jogá-la. Não é\n"
"vendida sem um saco de bombas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas  30 Peças   120 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Deixar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que bom que todos voltaram\n"
"ao normal!"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, salve meus outros\n"
"irmãos também! Eles lhe darão\n"
"uma coisa muito melhor!"
BOX_BREAK
"Você vai salvá-los?!"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "A maldição foi quebrada!\n"
"Obrigado!\n"
"Aqui está uma recompensa!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah! Estou amaldiçoado!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Teremos mais cuidado com essa\n"
"maldição!"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como você destruiu " COLOR(RED)  TOKENS  COLOR(DEFAULT) "\n"
"Aranhas da Maldição, a maldição\n"
"está enfraquecendo!"
BOX_BREAK
"Os garotos que voltaram ao normal\n"
"lhe deram alguma recompensa?"
BOX_BREAK
"Saiba que a única forma de se\n"
"tornar " COLOR(RED) "muito rico" COLOR(DEFAULT) " é destruindo\n"
"o máximo de Aranhas da\n"
"Maldição que for possível!"
BOX_BREAK
"Há algumas artimanhas para\n"
"encontrá-las! Primeiro, você tem\n"
"que caçar à noite. Segundo, tenha\n"
"em mente que elas adoram terra fofa."
BOX_BREAK
"Preste bem atenção ao seu redor!\n"
"Por favor, nós estamos contando\n"
"com você!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nós somos assim por causa da\n"
"maldição da aranha. Mas... " TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós somos assim por causa da\n"
"maldição da aranha."
BOX_BREAK
"Se cada " COLOR(RED) "Aranha da Maldição" COLOR(DEFAULT) " no\n"
"mundo inteiro fosse destruída,\n"
"a maldição seria quebrada."
BOX_BREAK
"Quando você destrói uma Aranha\n"
"da Maldição, um emblema aparecerá.\n"
"Colete-o como prova de sua façanha."
BOX_BREAK
ITEM_ICON("\x71") "O número próximo a este " COLOR(YELLOW) "ícone" COLOR(DEFAULT) "\n"
"na " COLOR(LIGHTBLUE) "Subtela de Status" COLOR(DEFAULT) " indica\n"
"quantas Aranhas da Maldição\n"
"você destruiu até então. "
BOX_BREAK
ITEM_ICON("\x71") "Quando este " COLOR(YELLOW) "ícone" COLOR(DEFAULT) " estiver\n"
"mostrado próximo do nome da\n"
"área na " COLOR(RED) "Subtela do Mapa" COLOR(DEFAULT) ", não\n"
"haverá mais Aranhas na área." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quebrar a maldição de minha\n"
"família, o faremos " COLOR(RED) "muito rico" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Como você destruiu " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Aranhas\n"
"da Maldição, a maldição sobre mim\n"
"foi quebrada."
BOX_BREAK
UNSKIPPABLE "Obrigado! Aqui está um símbolo\n"
"de gratidão! Por favor, pegue-o." EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado por salvar meus garotos."
BOX_BREAK
"O que? Eu? Oh, OK..."
BOX_BREAK
"Você já destruiu " COLOR(RED)  TOKENS  COLOR(DEFAULT) " Aranhas\n"
"da Maldição, então... isto é bom...\n"
"não se preocupe comigo...    "
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu   20 Peças   180 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Deixar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer jogar?\n"
"Custa " COLOR(RED) "20 Rupees" COLOR(DEFAULT) " por jogo.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você precisa de um arco!" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tudo bem. Você não tem que jogar\n"
"se não quiser." EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OKAY!!" QUICKTEXT_DISABLE "\n"
"Este é um jogo para aperfeiçoamento!\n"
"A famosa " COLOR(RED) "Galeria de Tiro" COLOR(DEFAULT) "!"
BOX_BREAK
"Mire nos alvos daquela plataforma\n"
"ali! Você pode acertar " COLOR(RED) "dez alvos" COLOR(DEFAULT) "?\n"
"Você dispõe de " COLOR(RED) "quinze" COLOR(DEFAULT) " projéteis!"
BOX_BREAK
"Arme sua arma com " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".\n"
"Está preparado?\n"
"Tente uma pontuação perfeita!\n"
"Boa Sorte!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você vê um punhado de terra\n"
"fofa aqui."
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Estilingue" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x06") "Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo.\n"
"Segurando " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " você poderá\n"
"mirar com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Solte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"lançar uma " COLOR(RED) "Semente Deku" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x06") "Se quiser atirar com mais\n"
"precisão, quando apertar " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"segure-o por um tempo para\n"
"a semente ficar preparada.                  "
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Arco" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Seleção de\n"
"Item" COLOR(DEFAULT) ", poderá selecioná-lo\n"
"com " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x03") "Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo.\n"
"Segurando " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " você poderá\n"
"mirar com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Solte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"para lançar a " COLOR(RED) "flecha" COLOR(DEFAULT) ".              "
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Você achou as " COLOR(RED) "Bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-as\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x02") "Use " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para levantar ou\n"
"soltá-las. Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " correndo\n"
"para jogá-las. Se achar algo\n"
"suspeito, exploda-o!!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "Você achou " COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Na\n"
COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x09") "Carregue e solte-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"Este é um novo tipo de bomba\n"
"que pode até subir em muros.\n"
"Mire bem e lance-o!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Você achou uma " COLOR(RED) "Noz Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-a\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x01") "Selecione-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e tente\n"
"jogá-la! Ela vai brilhar e\n"
"atordoar o inimigo!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Bumerangue" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0E") "Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo\n"
"e atacar inimigos distantes!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Gancho" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É uma corrente com mola que,\n"
"se lançada, engancha-se nas\n"
"coisas."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0A") "Use-o para arrastar coisas\n"
"distantes para você, ou para\n"
"levá-lo em direção a alguma\n"
"coisa."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0A") "Segurando " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", você pode\n"
"mirar com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Para atirar\n"
"basta soltar o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Você achou um " COLOR(RED) "Galho Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x00") "Selecione-o e gire-o usando o\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x00") "Quando quiser quardá-lo, pare e\n"
"aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Você pode carregar\n"
"até 10 galhos, mas não os\n"
"perca!     "
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Martelo Megaton" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para esmagar e\n"
"quebrar entulho! É tão pesado\n"
"que são necessárias duas mãos!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "Você achou a " COLOR(RED) "Lente da\n"
"Verdade" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Selecione-a e use-a\n"
"com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "! Coisas misteriosas\n"
"escondem-se por todo lado!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0F") "Tente usá-la fora do poço.\n"
"Para ver a verdade é\n"
"necessário poder de mágica,\n"
"então aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " novamente"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0F") "para parar de usá-la!"
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Você achou a " COLOR(RED) "Ocarina do\n"
"Tempo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Este é o tesouro\n"
"escondido da Família Real\n"
"que Zelda deixou cair."
BOX_BREAK
ITEM_ICON("\x08")  QUICKTEXT_ENABLE "Ela brilha com uma luz mística..."
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você usou o Vento de Farore!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Retorna ao Teleporte\n"
"Fecha o Teleporte\n"
"Sair" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "Você recebeu o " COLOR(RED) "Medalhão do\n"
"Fogo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Darúnia acorda como um Sábio\n"
"e adiciona poder ao seu!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "Você recebeu o " COLOR(BLUE) "Medalhão da\n"
"Água" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ruto acorda como uma Sábia\n"
"e adiciona poder ao seu!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "Você obteve o " COLOR(ADJUSTABLE) "Medalhão da\n"
"Floresta" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Saria acorda como uma Sábia\n"
"e aumenta o seu poder!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "Você recebeu o " COLOR(YELLOW) "Medalhão do\n"
"Espírito" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nabooru acorda como uma Sábia\n"
"e aumenta o seu poder!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "Você recebeu o " COLOR(LIGHTBLUE) "Medalhão da\n"
"Luz" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru, o Sábio, adiciona\n"
"poder ao seu!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "Você recebeu o " COLOR(PURPLE) "Medalhão da\n"
"Sombra" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Impa acorda como uma Sábia\n"
"e adiciona poder ao seu!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Frasco Vazio" COLOR(DEFAULT)  QUICKTEXT_DISABLE "!\n"
"Após colocar alguma coisa\n"
"dentro dele, use " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"selecioná-lo ou usar o item!"
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(RED) "Poção\n"
"Vermelha" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ",\n"
"selecione-a para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x15") "Beba-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"sua vida. Você pode levá-la em\n"
"um de seus frascos."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(ADJUSTABLE) "Poção Verde" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ",\n"
"selecione-a para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x16") "Beba-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"sua magia. Você pode\n"
"carregá-la em um de seus\n"
"frascos."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(BLUE) "Poção Azul" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Beba-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"sua vida e sua magia."
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Fada" COLOR(DEFAULT) " com um\n"
"frasco! " QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ",\n"
"selecione-a para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x18") "Esta fadinha é uma parceira\n"
"confiável que o reviverá no\n"
"momento que estiver morrendo."
BOX_BREAK
ITEM_ICON("\x18") "Mas se colocá-la em " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", então\n"
"poderá pedir sua ajuda a\n"
"qualquer momento."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Peixe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e algo\n"
"poderá acontecer... Parece tão\n"
"fresco e delicioso!"
BOX_BREAK
ITEM_ICON("\x19") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então\n"
"aperte o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo.   "
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Feijão Mágico" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ache um local apropriado e\n"
"plante-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". E espere\n"
"que algo engraçado acontecerá!"
BOX_BREAK
ITEM_ICON("\x10") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e então use " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para plantá-lo.      "
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lamento por isso...OK, bem..."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "VAMOS JOGAR" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "Você recebeu a " COLOR(RED) "Ocarina Mágica" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ela é um presente de Saria.\n"
"Selecione-a para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e aperte\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para tocá-la!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x07") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-a\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) " e então use\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para começar a tocar.\n"
"Você pode tocar diferentes"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x07") "notas com " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e os quatro\n"
COLOR(YELLOW) "Botões [C]" COLOR(DEFAULT) ". Aperte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para\n"
"parar de tocar, ou para\n"
"iniciar a música novamente."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "Você obteve a " COLOR(ADJUSTABLE) "Faca de\n"
"Gigante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Segure-a com as\n"
"duas mãos e use " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para\n"
"atacar! Não pode ser usada"
BOX_BREAK
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "com um " COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "Você obteve um " COLOR(LIGHTBLUE) "Escudo Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Selecione-o na " COLOR(BLUE) "Subtela de\n"
"Equipamentos" COLOR(DEFAULT) ". Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"equipá-lo."
BOX_BREAK
ITEM_ICON("\x3E") "Aperte " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para abaixar e\n"
"defender. Se apertar " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " mirando\n"
"com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", você poderá se mover\n"
"defendendo."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "Você obteve um " COLOR(LIGHTBLUE) "Escudo Hylian" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Selecione-o na " COLOR(BLUE) "Subtela de\n"
"Equipamentos" COLOR(DEFAULT) ", e equipe-o com\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ".       "
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "Você encontrou o " COLOR(LIGHTBLUE) "Escudo\n"
"Espelhado" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " A sua superfície\n"
"polida reflete luz e energia.\n"
"Aperte " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para usá-lo."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "Você achou o " COLOR(RED) "Gancho Longo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É um gancho que tem o dobro\n"
"do tamanho padrão."
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(RED) "Túnica Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta túnica resistente ao calor\n"
"é para adultos, não cabe em\n"
"garotos. Protege do calor..."
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(BLUE) "Túnica Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta roupa de banho é para\n"
"adultos, não cabe em garotos.\n"
"Vista-a e você não se afogará."
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você obteve um " COLOR(ADJUSTABLE) "Jarro Mágico" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Encheu sua Magia!"
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "Você obteve as " COLOR(RED) "Botas de Ferro" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Com elas você não pode correr\n"
"nem boiar."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "Você obteve as " COLOR(RED) "Botas\n"
"Flutuantes" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Com elas poderá\n"
"flutuar sobre o chão, mas seu\n"
"ponto fraco é a baixa tração."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x46") "Você poderá até mesmo andar\n"
"por curtos períodos de tempo\n"
"onde não haja chão. Seja\n"
"corajoso e creia nas botas!"
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você obteve um " COLOR(PURPLE) "Coração de Cura" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua vida será curada!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Sua aljava se tornou uma\n"
COLOR(RED) "Aljava Grande" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você poderá carregar\n"
"até " COLOR(YELLOW) "40" COLOR(DEFAULT) " flechas!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "Sua aljava se tornou uma\n"
COLOR(RED) "Aljava Enorme" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Agora você\n"
"poderá carregar muito\n"
"mais flechas, " COLOR(YELLOW) "50" COLOR(DEFAULT) " no total!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "Você achou um " COLOR(DEFAULT) "Saco de Bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Este saco é feito com\n"
"estômagos de Dodongos!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "Você achou " COLOR(RED) "20 Bombas" COLOR(DEFAULT) " dentro!" QUICKTEXT_DISABLE "\n"
"Agora você pode selecioná-las\n"
"para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e explodir as coisas!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Grande Saco\n"
"de Bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora poderá carregar\n"
"até " COLOR(YELLOW) "30" COLOR(DEFAULT) " bombas!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Maior Saco de\n"
"Bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Poderá carregar até\n"
COLOR(YELLOW) "40" COLOR(DEFAULT) " Bombas!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Você achou as " COLOR(BLUE) "Luvas\n"
"Prateadas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Se as vestir,\n"
"sentirá força em seus braços\n"
"para levantar coisas grandes."
BOX_BREAK
ITEM_ICON("\x51")  QUICKTEXT_ENABLE "Use-as com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x51") "Mas, estas luvas não cabem\n"
"num garoto... E você prometeu\n"
"dá-las a " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Você tem\n"
"que manter a sua palavra..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "Você achou as " COLOR(BLUE) "Luvas Douradas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você pode sentir muito mais\n"
"força fluindo pelos seus\n"
"braços! Use-as com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!     "
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE "Você pôs um " COLOR(LIGHTBLUE) "Fogo Azul" COLOR(DEFAULT) "\n"
"dentro do frasco! " QUICKTEXT_DISABLE "\n"
"Essa chama pode ser usada\n"
"com " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(BLUE) "Sacola de\n"
"Adulto" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Adultos podem carregar\n"
"muito dinheiro. Agora você\n"
"levará até " COLOR(YELLOW) "200 Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(BLUE) "Sacola de\n"
"Gigante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Agora você\n"
"poderá carregar até\n"
COLOR(YELLOW) "500 Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Você achou uma " COLOR(RED) "Chave Pequena" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ela só pode ser usada para abrir\n"
"portas fechadas em calabouços."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu   20 peças   180 Rupees\n"
COLOR(DEFAULT) "Ele parece um rato de brinquedo,\n"
"mas é uma bomba-relógio\n"
"autopropelida!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Vermelha 40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Vermelha 50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poção Vermelha 40 Rupees\n"
COLOR(DEFAULT) "Se bebê-la, você vai recuperar\n"
"sua vida. Esta é uma dose simples." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poção Vermelha 50 Rupees\n"
COLOR(DEFAULT) "Se bebê-la, você vai recuperar\n"
"sua vida. Esta é uma dose simples." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "Você achou o " COLOR(DEFAULT) "Mapa do\n"
"Calabouço" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Aperte " COLOR(RED) "START" COLOR(DEFAULT) " e\n"
"veja-o na " COLOR(RED) "Subtela do Mapa" COLOR(DEFAULT) "!\n"
"Ele é muito útil!"
BOX_BREAK
ITEM_ICON("\x76")  COLOR(BLUE) "Salas Azuis" COLOR(DEFAULT) " são locais que\n"
"você já visitou. Sua posição\n"
"atual é a " COLOR(LIGHTBLUE) "Sala Brilhando" COLOR(DEFAULT) "."
BOX_BREAK
ITEM_ICON("\x76") " Mova o " COLOR(LIGHTBLUE) "[Control-Pad] para cima ou baixo\n"
COLOR(DEFAULT) " para selecionar o andar que\n"
" quer ver."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "Você achou a " COLOR(RED) "Bússola" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode ver os locais\n"
"das coisas escondidas no\n"
"calabouço!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "Você obteve a " COLOR(RED) "Pedra da\n"
"Agonia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Se equipar um\n"
COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", ele reagirá\n"
"próximo...a segredos."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "Você recebeu a " COLOR(RED) "Carta de Zelda" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Uau! Ela tem o autógrafo da\n"
"Princesa Zelda! Selecione-a e\n"
"mostre-a usando o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x23") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-a\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então use\n"
"o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrá-la para as\n"
"pessoas."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bem-vindo! Posso ajudá-lo?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Quero comprar\n"
"Só olhando" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer comprar mais alguma\n"
"coisa?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "Seu " COLOR(RED) "Saco de Sementes Deku" COLOR(DEFAULT) "\n"
"ficou maior!" QUICKTEXT_DISABLE " Agora você pode\n"
"levar mais munição! Este\n"
"saco leva até " COLOR(YELLOW) "50" COLOR(RED) " sementes!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Abra o baú e...Surpresa!\n"
"Se encontrar uma chave dentro,\n"
"você poderá avançar. Esquerda ou\n"
"direita--Tente a sua sorte!"
BOX_BREAK
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " para jogar. Quer\n"
"tentar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau! Você é um grande jogador!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ganhou um " COLOR(ADJUSTABLE) "Rupee Verde" COLOR(DEFAULT) "!\n"
"Vale " COLOR(ADJUSTABLE) "um Rupee" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "Você obteve a " COLOR(RED) "Flecha de Fogo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Selecione-a para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Se você\n"
"acertar um alvo com ela, ele\n"
"vai ficar em chamas."
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "Você obteve a " COLOR(BLUE) "Flecha de Gelo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Selecione-a para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Se você\n"
"acertar um alvo com ela, ele\n"
"vai ficar congelado."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0C") "Esta flecha mágica é dada\n"
"apenas aos que completam o\n"
"difícil treinamento de\n"
"Gerudos, então use-a com"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0C") "muito orgulho!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "Você obteve a " COLOR(LIGHTBLUE) "Flecha de Luz" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Selecione-a para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". A luz da\n"
"justiça castigará todos os\n"
"servos do mal!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x35") "Você aprendeu o\n"
SHIFT("\x2A")  COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x36") "Você aprendeu o\n"
SHIFT("\x39")  COLOR(RED) "Bolero do Fogo" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x36") "Você aprendeu a\n"
SHIFT("\x32")  COLOR(BLUE) "Serenata da Água" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x32") "Você aprendeu o\n"
SHIFT("\x23")  COLOR(YELLOW) "Réquiem dos Espíritos" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x34") "Você aprendeu o\n"
SHIFT("\x2C")  COLOR(PURPLE) "Noturno da Sombra" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x39") "Você aprendeu o\n"
SHIFT("\x39")  COLOR(LIGHTBLUE) "Prelúdio da Luz" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Bracelete Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode levantar Flores\n"
"Bomba. Chegue perto de uma e\n"
"use o botão " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "Você pôs um " COLOR(RED) "Inseto" COLOR(DEFAULT) " no frasco! " QUICKTEXT_DISABLE "\n"
"Você pode soltá-lo apertando\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Esses insetos gostam de\n"
"viver em buraquinhos no chão."
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Cartão de\n"
"Membro Gerudo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Você pode\n"
"entrar no esconderijo, o\n"
"campo de treinamento Gerudo."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas  10 peças  50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Flechas 50 peças  90 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Peixe  200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Noz Deku  5 peças  15 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "Você obteve a " COLOR(ADJUSTABLE) "Esmeralda Kokiri" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É a Pedra Espiritual da\n"
"Floresta, agora confiada a\n"
"você pela Grande Árvore Deku."
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Rubi Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É a Pedra Espiritual do\n"
"Fogo, mantida por gerações\n"
"pelos Gorons!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "Você obteve a " COLOR(BLUE) "Safira Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É a Pedra Espiritual da\n"
"Água, mantida por gerações\n"
"pelos Zoras!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Olhe ao redor movendo o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "\n"
"para a esquerda ou direita.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Falar\n"
"Sair" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Obrigado!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Não tem Rupees suficientes!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Não pode tê-lo agora." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Noz Deku  10 peças  30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Galho Deku 1 peça  10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Escudo Deku  40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Flecha   10 peças  20 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomba  5 peças  25 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu  10 peças  100 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não pode usar aqui! Venda-o ao\n"
"homem do portão da Cidade do\n"
"Castelo de Hyrule!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Vermelha 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Verde  30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Agora você poderá pegar muitos\n"
COLOR(RED) "Galhos Deku" COLOR(DEFAULT) "! Poderá\n"
"carregar ate " COLOR(YELLOW) "20" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Agora você poderá pegar muito\n"
"mais " COLOR(RED) "Galhos Deku" COLOR(DEFAULT) "!\n"
"Pode carregar até " COLOR(YELLOW) "30" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Escudo Hylian  80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Túnica Goron  200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Túnica Zora  300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Coração de Cura  10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Lamento... não posso vendê-lo a\n"
"você, a menos que tenha um\n"
"frasco." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "Você pegou um " COLOR(RED) "Fantasma" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Alguma coisa boa pode\n"
"acontecer!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "Você obteve " COLOR(RED) "Leite Lon Lon" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Este leite é muito nutritivo!\n"
"Use-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e recupere\n"
"sua vida!"
BOX_BREAK
ITEM_ICON("\x1A") "Você recuperará " COLOR(RED) "cinco corações" COLOR(DEFAULT) "\n"
"por porção. Cada frasco\n"
"contém duas porções."
BOX_BREAK
ITEM_ICON("\x1A") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então use o\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para tomar uma porção."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Frasco Vazio" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ponha algo dentro e aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"para usá-lo... O quê? Já tem\n"
"algo dentro!?"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Ovo Estranho" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Parece que algo dentro está se\n"
"mexendo! Selecione-o para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"e use-o!"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x21") "Na " COLOR(YELLOW) "Subtela de Itens" COLOR(DEFAULT) ", selecione-o\n"
"para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então\n"
"aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Flechas  30 peças  60 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O meu item mais vendido é o\n"
COLOR(LIGHTBLUE) "Escudo Hylian" COLOR(DEFAULT) ", mas é\n"
"muito grande para você, garoto." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Viemos da cidade do castelo para\n"
"cá. Os tempos estão difíceis, mas\n"
"espero que você seja um consumidor\n"
"assíduo!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x58") "Olá!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Escudo Deku  40 Rupees\n"
COLOR(DEFAULT) "Uma vez equipado, defenda-se\n"
"com " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". Esse escudo\n"
"não resiste ao fogo! " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Flecha  10 peças  20 Rupees\n"
COLOR(DEFAULT) "Você precisa de um arco para\n"
"lançá-las. Você não pode comprar\n"
"sem um arco. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Galho Deku  1 peça  10 Rupees\n"
COLOR(DEFAULT) "Um longo galho da Grande\n"
"Árvore Deku. Você pode usá-lo\n"
"como arma, mas ele quebrará." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Nozes Deku  10 peças  30 Rupees\n"
COLOR(DEFAULT) "Jogue-as para atordoar seus\n"
"inimigos. Só poderá levar uma\n"
"porção limitada delas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombas  5 peças  25 Rupees\n"
COLOR(DEFAULT) "Solte-as com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e novamente " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"para jogá-las. Não poderá comprar\n"
"sem ter um saco de bombas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "Você obteve a " COLOR(ADJUSTABLE) "Espada Kokiri" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(BLUE) "Subtela de Equipamentos" COLOR(DEFAULT) ",\n"
"selecione-a com o cursor e\n"
"equipe-a com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x3B") "Este é um tesouro escondido\n"
"dos Kokiris, mas você pode tê-la\n"
"por enquanto. Mas lembre-se de\n"
"praticar antes de realmente lutar!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poção Vermelha  30 Rupees\n"
COLOR(DEFAULT) "Bêba-a para recuperar sua vida.\n"
"Esta é uma dose simples." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Poção Verde  30 Rupees\n"
COLOR(DEFAULT) "Bêba-a para recuperar sua\n"
"magia. Esta é apenas uma dose\n"
"simples." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Agora você pode levar muitas\n"
COLOR(RED) "Nozes Deku" COLOR(DEFAULT) "! Até um máximo\n"
"de " COLOR(YELLOW) "30" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Você pode levar muito mais\n"
COLOR(RED) "Nozes Deku" COLOR(DEFAULT) "! Até um\n"
"máximo de " COLOR(YELLOW) "40" COLOR(DEFAULT) " nozes!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Escudo Hylia  80 Rupees\n"
COLOR(DEFAULT) "É um escudo pesado como os que\n"
"os Cavaleiros Hylians usam. Ele\n"
"pode suportar ataques de chamas!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Túnica Goron 200 Rupees\n"
COLOR(DEFAULT) "Um túnica feita por Gorons.\n"
"Tamanho adulto. Protege contra\n"
"o calor." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Túnica Zora 300 Rupees\n"
COLOR(DEFAULT) "Um túnica feita por Zoras.\n"
"Tamanho adulto. Evita o\n"
"afogamento se submerso." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Coração de Cura 10 Rupees\n"
COLOR(DEFAULT) "Instantaneamente preencherá\n"
"seus Corações." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Fogo de Din" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua bola de fogo traga tudo!\n"
"É um ataque mágico usado\n"
"com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE "Você obteve o " COLOR(ADJUSTABLE) "Vento de\n"
"Farore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " É uma mágica de\n"
"teletransporte que você\n"
"pode usar com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0D") "Você será teletransportado\n"
"para o " COLOR(ADJUSTABLE) "Ponto de\n"
"Teletransporte" COLOR(DEFAULT) ". Primeiro,\n"
"crie esse ponto."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0D") "Quando usar a mágica de\n"
"novo, você pode tanto\n"
"desfazer o Ponto de\n"
"Teletransporte como"
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x0D") "também ser\n"
"teletransportado."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "Você obteve o " COLOR(BLUE) "Amor de Nayru" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use-o para criar uma forte\n"
"grade protetora. É uma\n"
"mágica de defesa."
BOX_BREAK
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "Use-a com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Flechas  50 peças  90 Rupees\n"
COLOR(DEFAULT) "Lance-as com um arco. Você\n"
"não poderá comprá-las sem ter\n"
"um arco." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombas  10 peças  50 Rupees\n"
COLOR(DEFAULT) "Solte-as com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e novamente\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para jogá-las. Não poderá\n"
"comprá-las sem um saco de bombas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Nozes Deku  5 peças  15 Rupees\n"
COLOR(DEFAULT) "Jogue-as para atordoar seus\n"
"inimigos. Só poderá levar uma\n"
"porção limitada delas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Peixe  200 Rupees\n"
COLOR(DEFAULT) "Pescado agora, fresquinho! Pode\n"
"mantê-lo num frasco." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você destruiu uma " COLOR(RED) "Skulltula de Ouro" COLOR(DEFAULT) ".\n"
"Obteve um emblema provando o\n"
"que fez!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você destruiu uma " COLOR(RED) "Skulltula de Ouro" COLOR(DEFAULT) ".\n"
"Obteve um emblema provando o\n"
"que fez!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Espírito de Fada  50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Espírito de Fada  50 Rupees\n"
COLOR(DEFAULT) "Vai precisar de um frasco\n"
"vazio. Não entre em batalha sem\n"
"ele!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fogo Azul  300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fogo Azul  300 Rupees\n"
COLOR(DEFAULT) "Você vai precisar de um\n"
"frasco vazio. Use-o para sentir\n"
"o frescor da frieza." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Inseto no Frasco  50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Leva\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Inseto de Frasco  50 Rupees\n"
COLOR(DEFAULT) "Vai precisar de um frasco\n"
"vazio. Parece um inseto comum..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  10 peças  100 Rupees\n"
COLOR(DEFAULT) "Parece com um rato de brinquedo,\n"
"mas é na verdade uma bomba-\n"
"relógio!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Estamos sem estoque desse item\n"
"no momento." COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Poxa! Você é velho demais para\n"
"este jogo! " EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x40") "Uh? Ah--!"
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x50") "Oh!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x3E") "Um comprador!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x39") "zzzzz...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Flechas  30 peças  60 Rupees\n"
COLOR(DEFAULT) "É preciso um arco para\n"
"lançá-las. Use-as e elas irão diminuir. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Pedaço de\n"
"Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Colete quatro pedaços\n"
"no total para obter outro\n"
"coração."
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Isso aumentará a sua vida!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Pedaço de\n"
"Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Você coletou dois\n"
"pedaços. Com mais dois, você\n"
"ganhará mais um coração"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "de vida!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Pedaço de\n"
"Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Você coletou três\n"
"pedaços! Com mais um,"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "seus corações de vida\n"
"aumentarão de um!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Pedaço de\n"
"Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE " Você completou um\n"
"outro coração! Sua vida\n"
"máxima será incrementada!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua vida máxima será\n"
"incrementada de um coração."
BOX_BREAK
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "Seus corações serão\n"
"totalmente preenchidos."
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "Você obteve a " COLOR(RED) "Chave do Chefe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você poderá entrar na\n"
"sala do Chefão!"
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você não tem Rupees suficientes!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x39") "Ok, muito bem!" QUICKTEXT_DISABLE "\n"
"Por favor espere lá fora que eu\n"
"prepararei seu próximo desafio!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas  5 peças  35 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Bombas  5 peças  35 Rupees\n"
COLOR(DEFAULT) "Solte-as com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e aperte-o de\n"
"novo para jogá-las. Você não pode\n"
"comprá-las sem um saco de bombas. " QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Obtido um " COLOR(BLUE) "Rupee Azul" COLOR(DEFAULT) "!\n"
"Vale " COLOR(BLUE) "Cinco Rupees" COLOR(DEFAULT) "! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "Você obteve a " COLOR(BLUE) "Escama Prateada" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pule na água e aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Você\n"
"pode mergulhar mais fundo que\n"
"antes."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "Você obteve a " COLOR(BLUE) "Escama Dourada" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pule na água e aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".\n"
"Agora você pode mergulhar\n"
"bem mais fundo que antes!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Parece que esse item não funciona\n"
"aqui... " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Não vai abrir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Aprendeu a " COLOR(ADJUSTABLE) "Canção de Saria" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Aprendeu a " COLOR(RED) "Canção de Epona" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x19") "Aprendeu a " COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Aprendeu a " COLOR(BLUE) "Canção de Zelda" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Aprendeu a " COLOR(LIGHTBLUE) "Canção do Tempo" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Aprendeu a " COLOR(PURPLE) "Canção da Tempestade" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Sou a Grande Fada do Poder!"
BOX_BREAK
UNSKIPPABLE "Eu vou lhe conceder uma\n"
COLOR(ADJUSTABLE) "técnica de espada" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Receba-a agora!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Sou a Grande Fada da Sabedoria!"
BOX_BREAK
UNSKIPPABLE "Eu vou elevar seu " COLOR(ADJUSTABLE) "poder\n"
"de mágica" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Receba-o agora!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Sou a Grande Fada da Bravura!"
BOX_BREAK
UNSKIPPABLE "Eu vou elevar o seu " COLOR(LIGHTBLUE) "poder\n"
"defensivo" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Receba-o agora!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando estiver cansado das\n"
"batalhas, volte para me visitar!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem-vindo " NAME "!\n"
"Vou suavizar seus danos." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE "Você obteve " COLOR(RED) "Sementes Deku" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Essas sementes pequenas e\n"
"duras são munição para o\n"
"seu estilingue."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  UNSKIPPABLE "Você dominou a técnica de espada\n"
"secreta " COLOR(RED) "Ataque Giratório" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Segure " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " e carregue sua arma!\n"
"Solte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para desferir uma onda\n"
"de energia com o giro!"
BOX_BREAK
UNSKIPPABLE "Se quiser lançar energia sem\n"
"carregar a arma, " COLOR(LIGHTBLUE) "gire o [Control-Pad] uma\n"
"vez" COLOR(DEFAULT) " e aperte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para dar um giro\n"
"rápido bastante efetivo!  "
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Sementes Deku 30 peças 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Sementes Deku 30 peças 30 Rupees\n"
COLOR(DEFAULT) "Podem ser usadas como munição\n"
"para o estilingue. Não pode ser\n"
"comprada sem ter um estilingue." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você quer falar com Saria, certo?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Falar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Sério? Então você quer falar\n"
"comigo?\n"
COLOR(DEFAULT)  TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x3C")  NAME "...?\n"
SHIFT("\x0D") "Esta é " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Pode me ouvir?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você quer falar com Saria de\n"
"novo?" COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Sua " COLOR(ADJUSTABLE) "Barra de Magia" COLOR(DEFAULT) " aumentou! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Seu " COLOR(LIGHTBLUE) "poder defensivo" COLOR(DEFAULT) " aumentou!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Obteve um " COLOR(YELLOW) "monte de flechas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando se energizar para um\n"
"Ataque Giratório, o poder de\n"
"magia será consumido. Preste\n"
"atenção na barra verde!"
BOX_BREAK
UNSKIPPABLE "Ei, garoto! Você é um mensageiro da\n"
"Família Real, não é?"
BOX_BREAK
UNSKIPPABLE "Da próxima vez que estiver ao redor\n"
"do Castelo de Hyrule, visite uma\n"
"amiga minha que mora por lá."
BOX_BREAK
UNSKIPPABLE "Ela certamente lhe concederá um\n"
"outro novo poder!  "
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu poder de mágica foi melhorado!\n"
"Agora você dobrou o seu " COLOR(RED) "Poder\n"
"de Mágica" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu poder defensivo foi melhorado!\n"
"Dano infligido por inimigos\n"
"serão " COLOR(RED) "reduzidos pela metade" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Sou a Grande Fada da Magia!"
BOX_BREAK
UNSKIPPABLE "Eu vou lhe dar uma " COLOR(RED) "mágica" COLOR(DEFAULT) ".\n"
"Por favor, receba-a."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Lamento, mas não poderá levar a\n"
"máscara ainda." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você pode usar o " COLOR(RED) "Fogo de Din" COLOR(DEFAULT) "\n"
"para atacar ou para queimar\n"
"coisas!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Lembre-se, o " COLOR(ADJUSTABLE) "Vento de Farore" COLOR(DEFAULT) " só\n"
"pode ser usado em calabouços que\n"
"têm um mapa escondido, OK?"
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O " COLOR(BLUE) "Amor de Nayru" COLOR(DEFAULT) " tem efeito por\n"
"um tempo limitado então use-o\n"
"com cuidado."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando as batalhas o deixarem\n"
"cansado, volte a me visitar."
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Obteve um " COLOR(RED) "Rupee Vermelho" COLOR(DEFAULT) "!\n"
"Vale vinte Rupees!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Obteve um " COLOR(PURPLE) "Rupee Roxo" COLOR(DEFAULT) "!\n"
"Vale " COLOR(PURPLE) "cinquenta Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Obteve um " COLOR(YELLOW) "Rupee Enorme" COLOR(DEFAULT) "!\n"
"Este Rupee vale incríveis\n"
COLOR(YELLOW) "duzentos Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "Você obteve uma " COLOR(RED) "Chave" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use-a para passar à próxima\n"
"sala. Selecione um baú de\n"
"tesouro e veja quão"
BOX_BREAK
ITEM_ICON("\x77") "sortudo você é!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT) "!"
BOX_BREAK
QUICKTEXT_ENABLE "Encontrou apenas " COLOR(ADJUSTABLE) "um Rupee" COLOR(DEFAULT) ".\n"
"Você é azarado." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Encontrou " COLOR(BLUE) "cinco Rupees" COLOR(DEFAULT) ".\n"
"Mesmo assim, você é azarado." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Encontrou " COLOR(RED) "vinte Rupees" COLOR(DEFAULT) ".\n"
"Sua última escolha foi um engano,\n"
"não foi! Muito frustrante!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Vencedor!" COLOR(DEFAULT)
BOX_BREAK
QUICKTEXT_ENABLE "Encontrou " COLOR(YELLOW) "cinquenta Rupees" COLOR(DEFAULT) ".\n"
"Você é mesmo um sortudo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "Você pôs um " COLOR(RED) "Fantasmão" COLOR(DEFAULT) " num\n"
"frasco! " QUICKTEXT_DISABLE "\n"
"Vamos vender na " COLOR(RED) "Loja de Fantasmas" COLOR(DEFAULT) "!\n"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Obteve um " COLOR(RED) "Pedaço de Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Colete quatro pedaços para ganhar\n"
"outro Coração. Mais corações\n"
"significam mais vida!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Obteve um " COLOR(RED) "Pedaço de Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você já coletou dois pedaços. Com\n"
"mais dois, você ganhará mais\n"
"corações de vida!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Obteve um " COLOR(RED) "Pedaço de Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você coletou três pedaços! Com\n"
"mais um, seus corações de vida\n"
"serão aumentados!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!"
BOX_BREAK
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "Obteve um " COLOR(RED) "Pedaço de Coração" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você completou um outro Coração!\n"
"Sua vida máxima será aumentada!\n"
""
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Procure por elas não apenas em\n"
"locais abertos, mas também dentro\n"
"de calabouços."
BOX_BREAK
"Claro, isso é apenas nosso sonho...\n"
"Não terá que fazer se não quiser..." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Que é isto? " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Veja, veja, " NAME "!\n"
"Você pode ver abaixo desta " COLOR(DEFAULT) "teia" COLOR(LIGHTBLUE) "\n"
"com " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Olhe para o muro! As vinhas\n"
"crescendo formam algo rugoso...\n"
"Talvez você possa escalá-las,\n"
NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você pode abrir uma " COLOR(DEFAULT) "porta" COLOR(LIGHTBLUE) "\n"
"ficando à frente dela e usando\n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Atenção para o que o " COLOR(BLUE) "Ícone\n"
"de Ação" COLOR(LIGHTBLUE) " diz. É o " COLOR(BLUE) "ícone azul" COLOR(LIGHTBLUE) " no\n"
"topo da sua tela!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Veja! Algo está pendurado ali!\n"
"Parece uma velha " COLOR(DEFAULT) "escada" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ei...\n"
"Não é o mesmo desenho que havia\n"
"no " COLOR(DEFAULT) "Portal do Tempo" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que essa tocha estava\n"
"queimando há pouco tempo..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Daqui, nós passaremos por algumas\n"
"passagens estreitas!\n"
"Se for devagar, talvez possa\n"
"desviar de alguns inimigos."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] Mirando" COLOR(LIGHTBLUE) " para sempre olhar\n"
"na direção apropriada. Com isso\n"
"você poderá ver claramente o\n"
"próximo corredor antes de se virar."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Uma vez que sua visão está correta,\n"
"segure " COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) " para " COLOR(DEFAULT) "andar de lado" COLOR(LIGHTBLUE) " em\n"
"torno das quinas. Assim você não\n"
"será surpreendido pelos inimigos." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Fique perto deste " COLOR(DEFAULT) "bloco" COLOR(LIGHTBLUE) " e\n"
"pegue-o com " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". Segurando " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ",\n"
"você pode empurrá-lo ou\n"
"arrastá-lo."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Se você ficar perto do " COLOR(DEFAULT) "bloco" COLOR(LIGHTBLUE) ",\n"
"apertar " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) " e pressionar " COLOR(DEFAULT) "[Control-Pad]" COLOR(LIGHTBLUE) "\n"
"em sua direção, você\n"
"poderá subir nele."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Preste atenção ao que o " COLOR(BLUE) "Ícone\n"
"de Ação" COLOR(LIGHTBLUE) " diz!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Após você entrar na água, se você\n"
"segurar " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", poderá mergulhar!\n"
"Eu aposto que há coisas submersas\n"
"interessantes!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Uau! Veja todas aquelas " COLOR(DEFAULT) "Flores\n"
"Bomba" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Existe alguma forma de\n"
"detonar todas de uma vez?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que há muitas " COLOR(DEFAULT) "fossas de\n"
"lava" COLOR(LIGHTBLUE) " por aqui, cuidado com\n"
"seus passos!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Com o interruptor ligado, a\n"
COLOR(DEFAULT) "plataforma" COLOR(LIGHTBLUE) " móvel sobe.\n"
"Agora poderá chegar rápido ao\n"
"segundo andar!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você nunca saberá o que haverá\n"
"pelas esquinas nestes caminhos\n"
"estreitos..."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] mirando" COLOR(LIGHTBLUE) " para sempre\n"
"olhar na direção apropriada. É\n"
"uma técnica muito útil, não é?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", para o que está\n"
"olhando?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "O semblante do Colosso do\n"
"Deserto... é demoníaco!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Posso ouvir os espíritos\n"
"sussurrando nesta sala..."
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE "\"Procure o olho da verdade...\"\n"
COLOR(LIGHTBLUE) "É o que eles estão dizendo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Aqui...posso ouvir os espíritos\n"
"sussurrando nesta sala..." COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE "\"Aqueles que têm " COLOR(RED) "pés sagrados" COLOR(DEFAULT) "\n"
"deveriam deixar o vento guiá-los.\n"
"Então, serão levados ao caminho\n"
"oculto.\""
BOX_BREAK
COLOR(LIGHTBLUE) "É o que eles estão dizendo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este muro...diz alguma coisa aqui...\n"
COLOR(DEFAULT) "\"Perigo acima...\"" COLOR(LIGHTBLUE) "\n"
"É o que ele diz." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este muro...diz alguma coisa aqui...\n"
COLOR(DEFAULT) "\"Perigo abaixo...\"\n"
COLOR(LIGHTBLUE) "É o que ele diz." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "A água fluindo dessa estátua está\n"
"inundando o andar inteiro." COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado, " NAME "!\n"
"Essa " COLOR(ADJUSTABLE) "coisa viscosa verde" COLOR(LIGHTBLUE) " tem\n"
"eletricidade por dentro!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado " NAME "!\n"
"Essa " COLOR(RED) "coisa viscosa vermelha" COLOR(LIGHTBLUE) "\n"
"pode eletrocutá-lo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado " NAME "!\n"
"Essa " COLOR(BLUE) "coisa viscosa azul" COLOR(LIGHTBLUE) " tem\n"
"eletricidade por dentro!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este " COLOR(DEFAULT) "interruptor" COLOR(LIGHTBLUE) "...\n"
"Parece que você não pode\n"
"acioná-lo com o seu peso apenas,\n"
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "A " COLOR(RED) "coisa viscosa vermelha" COLOR(LIGHTBLUE) " se foi!\n"
"A " COLOR(RED) "cauda vermelha" COLOR(LIGHTBLUE) " foi cortada,\n"
"pode ser a causa. Será que\n"
"funciona com os outros?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há um interruptor atrás deste\n"
"muro!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que há alguma coisa lá\n"
"em cima, no topo da plataforma!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x4C")  COLOR(LIGHTBLUE) "O QUÊÊ!?"
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Olhe todas aquelas " COLOR(DEFAULT) "bandeiras" COLOR(LIGHTBLUE) "!\n"
"Você pode saber qual a verdadeira?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A " COLOR(DEFAULT) "Grande Árvore Deku" COLOR(RED) " " COLOR(LIGHTBLUE) "chamou\n"
"você!\n"
"Por favor, venha comigo! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos! Seja bravo!\n"
"Vamos à Grande Árvore Deku!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A Grande Árvore Deku queria que\n"
"visitássemos a princesa do\n"
COLOR(DEFAULT) "Castelo de Hyrule" COLOR(LIGHTBLUE) "...\n"
"Não estamos atrasados?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A garota do rancho quer que\n"
"encontremos seu " COLOR(DEFAULT) "pai" COLOR(LIGHTBLUE) "...\n"
"Onde ele estaria?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Queria saber onde acharemos a\n"
COLOR(DEFAULT) "princesa" COLOR(LIGHTBLUE) " neste castelo\n"
"enorme?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "O que " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) " diria se\n"
"contássemos a ela que vamos\n"
"salvar Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Impa " COLOR(LIGHTBLUE) "disse que a Pedra Espiritual\n"
"do Fogo está na " COLOR(DEFAULT) "Montanha da\n"
"Morte" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Entraremos na Caverna dos\n"
"Dodongos usando uma " COLOR(DEFAULT) "Flor\n"
"Bomba" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Darúnia disse que uma " COLOR(DEFAULT) "fada" COLOR(LIGHTBLUE) "\n"
"mora no topo da Montanha da\n"
"Morte!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Queria saber se " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) " sabe\n"
"algo sobre a outra Pedra\n"
"Espiritual?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Parece que a " COLOR(DEFAULT) "Princesa Ruto" COLOR(LIGHTBLUE) "\n"
"foi parar na barriga de Jabu\n"
"Jabu..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você tem três Pedras Espirituais!\n"
"Vamos voltar ao " COLOR(DEFAULT) "Castelo\n"
"de Hyrule" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquelas que estavam no cavalo\n"
"branco...eram Zelda e Impa, não\n"
"eram? Parece que elas jogaram\n"
"alguma coisa no " COLOR(DEFAULT) "fosso" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos checar dentro do\n"
COLOR(DEFAULT) "Templo do Tempo" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Devemos acreditar no que Sheik\n"
"disse e irmos à " COLOR(DEFAULT) "Vila Kakariko" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Queria saber o que está havendo\n"
"na floresta agora...preocupo-me\n"
"com " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A nuvem sobre a " COLOR(DEFAULT) "Montanha da\n"
"Morte" COLOR(LIGHTBLUE) "... há alguma coisa de\n"
"estranho nela..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Um vento gelado está vindo do\n"
COLOR(DEFAULT) "Rio dos Zoras" COLOR(LIGHTBLUE) "...você sente?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquelas " COLOR(DEFAULT) "Botas de Ferro" COLOR(LIGHTBLUE) " parecem\n"
"que pesam uma tonelada! Se\n"
"calçá-las, você poderá andar no\n"
"fundo de um lago." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos procurar alguém que saiba\n"
"alguma coisa sobre os outros\n"
COLOR(DEFAULT) "Sábios" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquele monstro! Ele saiu de\n"
"dentro do " COLOR(DEFAULT) "poço na vila" COLOR(LIGHTBLUE) "!\n"
"Vamos lá checar poço!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Queria saber quem construiu o\n"
COLOR(DEFAULT) "Templo dos Espíritos" COLOR(LIGHTBLUE) ", e\n"
"para quê?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você já tocou o " COLOR(PURPLE) "Noturno da\n"
"Sombra" COLOR(LIGHTBLUE) " que Sheik lhe\n"
"ensinou?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "deserto" COLOR(LIGHTBLUE) "...é onde\n"
"Ganondorf o Rei da Maldade\n"
"nasceu. Se formos lá, poderemos\n"
"encontrar alguma coisa..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Equipe as " COLOR(DEFAULT) "Luvas Prateadas" COLOR(LIGHTBLUE) " e\n"
"tente mover coisas que você\n"
"não podia antes!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A pessoa que está nos esperando\n"
"no Templo do Tempo...poderia ser..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Temos que salvar a Princesa Zelda\n"
"de sua prisão no Castelo de\n"
"Ganon!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME "...\n"
"Tente se mover!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Não me importo de falar com você\n"
"usando a mágica da Ocarina, mas\n"
"eu gostaria era de falar\n"
"cara a cara!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"A floresta é conectada a muitos\n"
"lugares! Se puder ouvir minha\n"
"canção, é porque está em algum\n"
"lugar conectado à floresta!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Fiquei tão feliz de ouvir que\n"
"o Sr. Darúnia amou minha canção!"
BOX_BREAK
"Fiquei até mais feliz de saber\n"
"que ela o ajudou em sua aventura,\n"
NAME "!\n"
"Tee hee hee!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está coletando Pedras\n"
"Espirituais? Falta alguma ainda?\n"
"Você se refere à " COLOR(BLUE) "Pedra Espiritual\n"
"da Água" COLOR(DEFAULT) ", não é?"
BOX_BREAK
"A Grande Árvore Deku uma vez me\n"
"disse que o " COLOR(BLUE) "Rei Zora" COLOR(DEFAULT) " a possui\n"
"no Domínio dos Zoras..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está coletando Pedras\n"
"Espirituais? Ainda falta alguma?\n"
"Você se refere à " COLOR(RED) "Pedra Espiritual\n"
"do Fogo" COLOR(DEFAULT) ", não é?"
BOX_BREAK
"A Grande Árvore Deku uma vez\n"
"me disse que o " COLOR(RED) "Sr. Darúnia dos\n"
"Gorons" COLOR(DEFAULT) ", a tem... " EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Não sei o que é isso...\n"
"Eu tenho uma sensação de pavor..."
BOX_BREAK
"O Castelo...\n"
"Sim, algo ruim está acontecendo\n"
"no Castelo!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"O que? Sua ocarina tem som...\n"
"diferente...\n"
"Você andou praticando bastante,\n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está procurando por um\n"
"Templo? Um passarinho me disse..."
BOX_BREAK
"\"" COLOR(LIGHTBLUE) "Olhos que vêem no escuro\n"
"serão abertos numa tempestade." COLOR(DEFAULT) "\"\n"
"Você tem alguma idéia do que\n"
"ele quis dizer?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Onde você está, " NAME "?\n"
"Está procurando por um templo?\n"
"Uma vez um passarinho\n"
"disse..."
BOX_BREAK
"\"" COLOR(LIGHTBLUE) "Vá, jovem. Vá à Deusa do\n"
"Deserto com uma ocarina." COLOR(DEFAULT) "\"\n"
"Você tem alguma idéia do que ele\n"
"quis dizer com isso?" EVENT " "
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você já achou todos os templos?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Que bom que está bem!\n"
"Eu sabia que o encontraria\n"
"novamente!"
BOX_BREAK
"Estou no " COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) "!\n"
"Os espíritos da floresta pediram\n"
"ajuda, então fui lá checar..."
BOX_BREAK
"Mas está cheio de monstros do\n"
"mal! Ajude-me!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"De início, eu não queria me\n"
"tornar a " COLOR(ADJUSTABLE) "Sábia da Floresta" COLOR(DEFAULT) "..."
BOX_BREAK
"Mas estou contente agora."
BOX_BREAK
"Pois estou lhe ajudando a salvar\n"
"Hyrule, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Se todos os seis " COLOR(RED) "Sábios" COLOR(DEFAULT) " se\n"
"juntarem, poderão aprisionar\n"
"Ganondorf, o Rei do Mal, no Reino\n"
"Sagrado."
BOX_BREAK
"Mas, para que seja perfeito,\n"
"precisaremos do " COLOR(RED) "sétimo Sábio" COLOR(DEFAULT) "."
BOX_BREAK
"Alguém que você conhece deve\n"
"ser esse Sábio, " NAME "..."
BOX_BREAK
"De agora em diante, viaje entre\n"
"o passado e o futuro para\n"
"despertar os Sábios que restam!"
BOX_BREAK
"Vá em frente, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Nós, os Seis Sábios, estamos\n"
"canalizando nosso poder para você!"
BOX_BREAK
"Hyrule depende de você, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Posso ouvir uma voz de algum\n"
"lugar..." COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ela diz:\n"
COLOR(DEFAULT)  SHIFT("\x02") "\"Colete cinco Rupees de prata...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este muro...diz alguma coisa!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ele diz:\n"
COLOR(DEFAULT) "Se quiser ver uma passagem\n"
SHIFT("\x02") "para o outro mundo, venha aqui..."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Se quer uma carona naquele " COLOR(DEFAULT) "barco" COLOR(LIGHTBLUE) ",\n"
"cuidado! Parece muito velho...\n"
"Ninguém sabe quando afundará!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há uma " COLOR(DEFAULT) "porta" COLOR(LIGHTBLUE) "logo ali... Há\n"
"alguma forma de passar por ela?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Humm " COLOR(DEFAULT) "gelo vermelho" COLOR(LIGHTBLUE) ", estranho!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esse " COLOR(DEFAULT) "fogo azul" COLOR(LIGHTBLUE) "...não parece\n"
"natural. Será que pode ser usado\n"
"para algo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "fogo das tochas" COLOR(LIGHTBLUE) " se foi.\n"
"Parece que os fantasmas apagaram!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Veja, " NAME "! Uma " COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) " está\n"
"acesa! Foi porque você matou um\n"
"fantasma?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Existem " COLOR(DEFAULT) "setas" COLOR(LIGHTBLUE) " pintadas\n"
"no piso!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esse " COLOR(DEFAULT) "corredor" COLOR(LIGHTBLUE) " está torto!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Atenção nas " COLOR(DEFAULT) "sombras dos monstros" COLOR(LIGHTBLUE) "\n"
"que se penduram no teto." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há um " COLOR(DEFAULT) "baú do tesouro" COLOR(LIGHTBLUE) " aqui." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta...esta é a mesma " COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) "\n"
"que vimos na entrada do templo,\n"
"não é?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Essa " COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) " acendeu, quer\n"
"dizer..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "O interruptor congelou!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", cuidado!\n"
"O teto está vindo a baixo!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", ouço " COLOR(DEFAULT) "vozes Goron" COLOR(LIGHTBLUE) "\n"
"logo abaixo." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você pode ver lá embaixo daqui...\n"
"Não é a sala em que vimos\n"
COLOR(DEFAULT) "Darúnia" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta " COLOR(DEFAULT) "estátua" COLOR(LIGHTBLUE) "...já não a\n"
"vimos alguma vez antes?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "interruptor" COLOR(LIGHTBLUE) " enferrujou." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Cuidado!\n"
"Os vórtices podem engoli-lo!" COLOR(DEFAULT) "\n"
""
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
SHIFT("\x23") "Sou uma porta falante!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x02")  COLOR(LIGHTBLUE) "Estranho...esta porta não abre..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x13")  COLOR(LIGHTBLUE) "Fortes " COLOR(DEFAULT) "barras de ferro" COLOR(LIGHTBLUE) " estão\n"
COLOR(DEFAULT)  SHIFT("\x13")  COLOR(LIGHTBLUE) "bloqueando a porta. Não abre\n"
COLOR(DEFAULT)  SHIFT("\x3B")  COLOR(LIGHTBLUE) "com as mãos!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x09")  COLOR(LIGHTBLUE) "Você precisa de uma " COLOR(DEFAULT) "Chave" COLOR(LIGHTBLUE) " para\n"
COLOR(DEFAULT)  SHIFT("\x19")  COLOR(LIGHTBLUE) "abrir uma porta trancada." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x24")  COLOR(LIGHTBLUE) "Só uma " COLOR(DEFAULT) "chave especial\n"
SHIFT("\x39")  COLOR(LIGHTBLUE) "abre esta porta." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Silêncio!" QUICKTEXT_DISABLE
BOX_BREAK
"Ainda são " TIME "!\n"
"Eu, " COLOR(RED) "Dampé" COLOR(DEFAULT) " o coveiro, estou\n"
"na cama agora!"
BOX_BREAK
"Saia e vá jogar! Talvez você\n"
"encontre um fantasma de dia!"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"São " TIME " agora.\n"
"O " COLOR(RED) "Passeio Cava-Cova" COLOR(DEFAULT) " já acabou!"
BOX_BREAK
"Eu, " COLOR(RED) "Dampé" COLOR(DEFAULT) " o coveiro, estou\n"
"na cama!"
BOX_BREAK
"Saia e vá jogar! Talvez você\n"
"ache um fantasma!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Loja Máscara Feliz\n"
COLOR(DEFAULT) "Por favor leia as instruções\n"
"antes de comprar."
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(RED) "Como a Loja Funciona\n"
COLOR(DEFAULT) "Não vendemos máscaras aqui.\n"
"Apenas as " COLOR(RED) "emprestamos" COLOR(DEFAULT) " a você." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Você as vende da forma que\n"
"quiser." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Paga de volta o " COLOR(RED) "dinheiro" COLOR(DEFAULT) " pela\n"
"máscara, e nós lhe emprestaremos\n"
"outro modelo." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Você pode pegar máscaras que já\n"
"foram vendidas; porém, só poderá\n"
"vender uma de cada modelo." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Por favor tente nossa loja!\n"
SHIFT("\x14") "--Dono da Loja Máscara Feliz" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Templo Sombrio...\n"
"Aqui fica a história sangrenta\n"
"de ódio e ganância de Hyrule... " EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"O que há na escuridão...\n"
"Trapaças cheias de má vontade...\n"
"Não dá para ver o caminho a\n"
"frente!" EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Quem ganha o " COLOR(RED) "olho da verdade" COLOR(DEFAULT) "\n"
"é capaz de ver o que está\n"
"escondido na escuridão." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Algo estranho está cobrindo a\n"
"entrada. Você deve resolver o\n"
COLOR(DEFAULT) "enigma" COLOR(LIGHTBLUE) " nesta sala para\n"
"fazer a entrada abrir." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gigante Dodongo morto...\n"
"quando ele vê vermelho,\n"
"um caminho se abrirá." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x24")  COLOR(LIGHTBLUE) "Torneio Baú do Tesouro\n"
COLOR(DEFAULT)  SHIFT("\x50") "Fechado\n"
SHIFT("\x2A") "Abre Hoje à Noite!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Loja de Remédios\n"
COLOR(DEFAULT) "Abre pela manhã"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Galeria de Tiro\n"
COLOR(DEFAULT) "Abre só durante o dia"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Loja Máscara Feliz\n"
COLOR(DEFAULT) "Estamos contratando!\n"
"Só durante o dia"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Bazar\n"
COLOR(DEFAULT) "Abre apenas durante o dia"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Mostre-me a luz!"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Alguém com o " COLOR(RED) "olho da verdade" COLOR(DEFAULT) "\n"
"será guiado ao Templo dos\n"
"Espíritos por uma fantasma." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Aqueles que desejam abrir o\n"
"caminho no fundo do lago devem\n"
"tocar a " COLOR(RED) "canção passada por\n"
"gerações pela Família Real" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Aqueles que desejam abrir o\n"
"portal das alturas, devem tocar\n"
"a " COLOR(RED) "canção da Família Real" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Os que acharem uma " COLOR(RED) "pequena\n"
"chave" COLOR(DEFAULT) " podem avançar à próxima\n"
"sala.            "
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quiser falar comigo,\n"
"fale de cima da plataforma. " EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Oi, " NAME "!" QUICKTEXT_DISABLE "\n"
"Olhe para cá!"
BOX_BREAK
"Aqui em cima com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", e fale\n"
"comigo usando o " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A hora atual é: " COLOR(RED)  TIME  COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Luz brilhante aos mortos-vivos..."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Aquele que quebrar a Tumba Real\n"
"será pego pelas " COLOR(RED) "emboscadas\n"
"da escuridão das trevas" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ei, você! Jovem, logo aí!\n"
"Olhe para cá, dentro da cela!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu garotinho não está aqui\n"
"agora...\n"
"Acho que ele foi brincar no\n"
"cemitério..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, meu garoto está dormindo\n"
"agora. Volte uma outra hora\n"
"para brincar com ele!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Quando a água encher o lago,\n"
"atire na luz da manhã." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se você quer viajar para o\n"
"futuro, retorne aqui com o\n"
COLOR(BLUE) "poder de prata" COLOR(DEFAULT) " do passado." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se você quer proceder ao passado,\n"
"retorne aqui com o coração\n"
"puro de uma criança." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Essa porta está meio\n"
"enferrujada." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Parece que alguma coisa costumava\n"
"ficar neste lugar... " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Faça meu bico encarar o\n"
SHIFT("\x2E")  COLOR(ADJUSTABLE) "crânio da verdade" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x19") "A alternativa é descer na\n"
SHIFT("\x2C") "escuridão profunda." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Esta não é a " COLOR(DEFAULT) "chave" COLOR(LIGHTBLUE) " correta...\n"
"A porta não abrirá!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C")  COLOR(LIGHTBLUE) "Loja de Poções da Granny\n"
COLOR(DEFAULT)  SHIFT("\x4F") "Fechada" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x42") "Fui Estudar\n"
SHIFT("\x37") "Volte mais tarde!\n"
SHIFT("\x4A") "--Granny" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Quem está aí? Que garoto mau,\n"
"tentando entrar pelos fundos!\n"
QUICKTEXT_DISABLE
BOX_BREAK
TEXT_SPEED("\x02") "Que pestinha..." TEXT_SPEED("\x00") "\n"
"Tenho que lhe dar uns bons\n"
"conselhos!"
BOX_BREAK
"O carpinteiro chefe tem um filho...\n"
"Ele é o cara que senta sob a\n"
"Árvore toda noite..."
BOX_BREAK
"Não diga ao chefe nossa\n"
"conversa!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Veja só isso!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Malon foi dormir!\n"
"Eu vou dormir agora, também.\n"
"Volte novamente quando o dia\n"
"amanhecer!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Recorde de " NAME "!\n"
COLOR(DEFAULT) "Aranhas pegas: " TOKENS "\n"
"Maior peixe pego: " HIGHSCORE(HS_LARGEST_FISH) " libras" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Tempo da maratona: " HIGHSCORE(HS_MARATHON) "\n"
"Corrida de cavalos: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Arco no cavalo: " HIGHSCORE(HS_HORSE_ARCHERY) " pontos " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x14") "O escudo da Família Real de\n"
SHIFT("\x1D") "Hyrule está inscrito aqui." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x54") "R.I.P.\n"
SHIFT("\x1C") "Aqui estão as almas que\n"
SHIFT("\x2C") "juraram lealdade à\n"
SHIFT("\x24") "Família Real de Hyrule" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x19") "Os Sheikahs, guardiões da\n"
SHIFT("\x13") "Família Real e fundadores de\n"
SHIFT("\x04") "Kakariko, observam esses espíritos\n"
SHIFT("\x14") "nos seus descansos eternos." QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(BLUE) "Cachoeira Sem Sono\n"
COLOR(DEFAULT)  SHIFT("\x0F") "O fluxo dessa cachoeira serve o\n"
SHIFT("\x14") "Rei de Hyrule. Quando o Rei\n"
SHIFT("\x02") "dorme, as quedas também adormecem." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Algumas rãs submersas estão\n"
"olhando para você..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você está sobre um tapete fofo\n"
"para visitas...\n"
"É tão macio sob os seus pés!"
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se você superar o " COLOR(RED) "Treinamento" COLOR(DEFAULT) "\n"
"nas salas à frente, então você\n"
"estará qualificado para receber\n"
"nosso tesouro secreto!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se você deseja adquirir nosso\n"
"tesouro, empenhe-se para obter as\n"
COLOR(RED) "chaves" COLOR(DEFAULT) " escondidas em cada\n"
"sala!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Derrote os inimigos num\n"
COLOR(RED) "tempo limitado" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Colete as " COLOR(RED) "jóias submersas" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cruze o mar de fogo!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Ache uma passagem secreta na\n"
"sala!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cegue os " COLOR(RED) "olhos da estátua" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Com as " COLOR(RED) "mãos prateadas" COLOR(DEFAULT) " mova\n"
"o bloco gigante!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sem os itens necessários, você\n"
"ficará confuso com mistérios\n"
"impossíveis."
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Colete as " COLOR(RED) "jóias brancas" COLOR(DEFAULT) ",\n"
"e evite as armadilhas e perigos!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(LIGHTBLUE) "Tanque de Pescaria" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Os peixes estão agitados!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4E")  COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "As Sombras guiarão apenas quem\n"
SHIFT("\x1D") "tiver o " COLOR(RED) "olho da verdade" COLOR(DEFAULT) ",\n"
SHIFT("\x13") "deixado sob a Vila Kakariko." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x32")  COLOR(LIGHTBLUE) "Campo de Hyrule" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Cidade do Castelo " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(LIGHTBLUE) "O Templo do Tempo " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47")  COLOR(RED) "  Fim" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B")  COLOR(PURPLE) "Vila Kakariko\n"
COLOR(DEFAULT)  SHIFT("\x2C") "Trilha da Montanha\n"
SHIFT("\x3D") "Ponto Inicial" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(PURPLE) "Cemitério da Vila Kakariko" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Escuro! Amedrontador!\n"
COLOR(PURPLE)  SHIFT("\x28") "Poço de Três Feições" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(RED) "Montanha da Morte\n"
COLOR(DEFAULT)  SHIFT("\x33") "Só entra com um\n"
SHIFT("\x3C") "Decreto Real!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(RED) " Trilha da Montanha " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(YELLOW) "Caverna dos Dodongos\n"
COLOR(DEFAULT)  SHIFT("\x1C") "Não entre sem permissão!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "Terra dos Gorons\n"
SHIFT("\x3E")  COLOR(RED) "Cidade Goron" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B")  COLOR(BLUE) "Rio dos Zoras\n"
COLOR(DEFAULT)  SHIFT("\x1C") "Cuidado com a correnteza\n"
SHIFT("\x24") "e as fortes ressacas." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "As Sombras guiarão apenas quem\n"
SHIFT("\x1E") "tiver o olho da verdade,\n"
SHIFT("\x13") "deixado sob a Vila Kakariko." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B")  COLOR(BLUE) "Domínio Zora " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Fonte dos Zoras\n"
COLOR(DEFAULT)  SHIFT("\x08") "Não perturbe Senhor Jabu-Jabu!\n"
SHIFT("\x35") "--Rei Zora XVI" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(PURPLE) "Centro de Treinamento\n"
COLOR(DEFAULT)  SHIFT("\x21") "Não corte os sinais--\n"
SHIFT("\x21") "Leia-os cuidadosamente!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "A todos os descuidados que\n"
SHIFT("\x1E") "se aventuram no deserto,\n"
SHIFT("\x26") "entrem em nossa loja." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(YELLOW) "Mercante de Carpetes" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D") "Logo adiante:\n"
SHIFT("\x1E")  COLOR(ADJUSTABLE) "Campina da Árvore Deku" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(ADJUSTABLE) "Bosque Perdido" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3A") "Rancho Lon Lon\n"
SHIFT("\x39") "de Talon e Malon" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42") "Rancho Ingo\n"
SHIFT("\x3A") "do Grande Ingo" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(BLUE) "Laboratório do Lago\n"
COLOR(DEFAULT)  SHIFT("\x14") "Tentando saber os mistérios\n"
SHIFT("\x16") "do Lago Hylia diariamente!\n"
SHIFT("\x33") "--Cientista do Lago" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(YELLOW) " Vale Gerudo " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(YELLOW) "Arco e Flecha a Cavalo" COLOR(DEFAULT) "\n"
SHIFT("\x1A") "Arqueiros experientes são\n"
SHIFT("\x45") "bem-vindos\n"
SHIFT("\x35") "Recorde: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " pontos." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12")  COLOR(YELLOW) "Área de Treinamento Gerudo\n"
COLOR(DEFAULT)  SHIFT("\x24") "Apenas para membros\n"
SHIFT("\x42") "registrados!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20")  COLOR(YELLOW) "Terras Mal-Assombradas" COLOR(DEFAULT) "\n"
SHIFT("\x1C") "Se seguir uma miragem, o\n"
SHIFT("\x30") "deserto o engolirá.\n"
SHIFT("\x26") "Só um caminho é real!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(YELLOW) "Templo dos Espíritos" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(ADJUSTABLE) "Loja Kokiri\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Temos itens da floresta!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39") "Casa de " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24")  COLOR(ADJUSTABLE) "O povo daqui não deve\n"
COLOR(DEFAULT)  SHIFT("\x39")  COLOR(ADJUSTABLE) "deixar o bosque." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Siga a trilha ao redor do\n"
SHIFT("\x14") "penhasco e você alcançará a\n"
SHIFT("\x0B")  COLOR(RED) "Cidade Goron" COLOR(DEFAULT) ", casa dos Gorons." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x34") "Maravilha Natural\n"
SHIFT("\x45")  COLOR(RED) "Flor Bomba" COLOR(DEFAULT) "\n"
SHIFT("\x31") "Perigo! Não colha!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16")  COLOR(RED) "Topo da Montanha da Morte\n"
COLOR(DEFAULT)  SHIFT("\x26") "Cratera logo à frente\n"
SHIFT("\x20") "Cuidado, calor intenso!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16")  COLOR(BLUE) "Sala do Trono do Rei Zora\n"
COLOR(DEFAULT)  SHIFT("\x1C") "Suba na plataforma para\n"
SHIFT("\x0E") "falar e ouvir as proclamações\n"
SHIFT("\x3A") "reais do Rei." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Se puder parar meu rolamento,\n"
SHIFT("\x16") "conseguirá algo muito bom.\n"
SHIFT("\x29") "--" COLOR(RED) "Hot Rodder Goron  " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "Quem tiver o olho da verdade\n"
SHIFT("\x13") "achará o guarda-sol de pedra\n"
SHIFT("\x28") "que protege contra a\n"
SHIFT("\x32") "chuva de lâminas." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Quem tiver os " COLOR(RED) "pés sagrados" COLOR(DEFAULT) "\n"
SHIFT("\x04") "poderá cruzar o vale dos mortos." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O tempo recorde dos que\n"
"correram contra mim foi:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"--Dampé o Coveiro" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Galeria de Tiro\n"
"20 Rupees por jogo\n"
COLOR(DEFAULT) "São " COLOR(RED) "10 alvos" COLOR(DEFAULT) ". Você tem " COLOR(RED) "15\n"
"chances" COLOR(DEFAULT) ". Acerte todos os 10 alvos!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Acerte 10 alvos -- Prêmio Perfeito\n"
"Acerte 8 ou mais -- Chance Grátis\n"
"Acerte menos de 8 -- Fim de Jogo" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Regras desta Galeria de Tiro\n"
COLOR(DEFAULT) "Não suba no balcão.\n"
"Não perturbe outros clientes." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x22")  COLOR(LIGHTBLUE) "Loja de Baús do Tesouro" COLOR(DEFAULT) "\n"
SHIFT("\x0F") "Não vendemos necessariamente." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "Prática de Mergulho\n"
COLOR(DEFAULT)  SHIFT("\x22") "Está confiante no nível\n"
SHIFT("\x2A") "dos seus mergulhos?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2F")  COLOR(RED) "Topo da Montanha" COLOR(DEFAULT) "\n"
SHIFT("\x2B") "Perigo! Fique longe!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "Loja Máscara Feliz!" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Contratamos office boys!\n"
SHIFT("\x3C")  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(LIGHTBLUE) "Campo de Boliche Bombchu" COLOR(DEFAULT) "\n"
SHIFT("\x22") "Experimente a mais nova\n"
SHIFT("\x26") "Tecnologia em bombas! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x50")  COLOR(LIGHTBLUE) "Bazar" COLOR(DEFAULT) "\n"
SHIFT("\x13") "Nós temos um pouco de tudo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3A")  COLOR(LIGHTBLUE) "Loja de Poções\n"
COLOR(DEFAULT)  SHIFT("\x26") "Nós temos as melhores\n"
SHIFT("\x4A") "poções! " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(RED) "Loja Goron\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Material para Montanhas!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(BLUE) "Loja Zora" COLOR(DEFAULT) "\n"
SHIFT("\x29") "Temos peixe fresco!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Passeio Cava-Cova!\n"
COLOR(DEFAULT)  SHIFT("\x04") "Das 18:00 às 21:00 no horário de\n"
SHIFT("\x19") "Hyrule -- Dampé o Coveiro" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Passeio Cava-Cova!\n"
COLOR(DEFAULT)  SHIFT("\x07") "Os passeios estão " COLOR(RED) "cancelados" COLOR(DEFAULT) " até\n"
SHIFT("\x07") "que um novo coveiro apareça. Nós\n"
SHIFT("\x02") "pedimos desculpas pela inconveniência." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Ataque Impulsivo!\n"
COLOR(DEFAULT) "Para impelir sua espada, aperte\n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " na direção do alvo enquanto\n"
COLOR(LIGHTBLUE) "mirar o [Z]" COLOR(DEFAULT) ", e então aperte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Buraco de \"Z\"\n"
COLOR(DEFAULT) "Vamos entrar no buraquinho!\n"
QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Fique à frente do buraco e\n"
"aperte " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para frente. Quando o\n"
COLOR(BLUE) "Ícone de Ação" COLOR(DEFAULT) " mostrar \"Entrar\",\n"
"aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para entrar no buraco." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Preste atenção no que o\n"
COLOR(BLUE) "Ícone de Ação" COLOR(DEFAULT) " diz!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Cortar Grama Com a Espada\n"
COLOR(DEFAULT) "Apertando " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", você cortará\n"
"horizontalmente. Se segurar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "\n"
"antes do " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", cortará verticalmente." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(LIGHTBLUE) "Castelo de Hyrule\n"
SHIFT("\x45")  COLOR(YELLOW) "Rancho Lon Lon" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Você está aqui: Castelo de Hyrule\n"
SHIFT("\x02") "Por ali: Rancho Lon Lon" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B") "Logo à Frente\n"
SHIFT("\x35")  COLOR(BLUE) "Sala do Rei Zora\n"
COLOR(DEFAULT)  SHIFT("\x28") "Mostre seu respeito!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29") "Casa do Grande " COLOR(RED) "Mido" COLOR(DEFAULT) "\n"
SHIFT("\x36") "Chefe dos Kokiris" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Casa dos Irmãos Sabe-Tudo" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x30") "Casa das Gêmeas " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3B") "Casa de " COLOR(RED) "Saria" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Ponto de Vista com [Z]\n"
COLOR(DEFAULT) "Você pode simplesmente olhar\n"
"para frente com o " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Pare de se mover e mude a direção\n"
"que você está olhando, ou " COLOR(LIGHTBLUE) "aperte\n"
"[Z]" COLOR(DEFAULT) " por um tempinho." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Isto pode ajudá-lo a se orientar\n"
"na direção que você quiser se\n"
"alinhar. É algo bem conveniente!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Se " COLOR(LIGHTBLUE) "você apertar [Z]" COLOR(DEFAULT) ", poderá\n"
COLOR(RED) "andar lateralmente" COLOR(DEFAULT) " enquanto\n"
"estiver olhando na direção da\n"
"sua frente." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  COLOR(RED) "Andando lateralmente" COLOR(DEFAULT) " é importante\n"
"em corredores de calabouços. De\n"
"agora em diante tente fazer esta\n"
"técnica." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Pulando Pedras no Tanque\n"
COLOR(DEFAULT) "Se for corajoso na direção\n"
"que quer pular, você saltará\n"
"automaticamente." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Se você saltar pelas pedras,\n"
"vai ficar mais feliz!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(RED) "Proibido Mergulhar\n"
COLOR(DEFAULT)  SHIFT("\x1E") "--Isso não lhe fará bem!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Trocar Alvo\n"
COLOR(DEFAULT) "Se vir um ícone " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " acima\n"
"de um objeto, você pode mirá-lo\n"
"com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Em outras palavras, se apertar\n"
COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " quando vir " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " sobre um objeto,\n"
"você poderá fixar nele." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Se apertar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " de novo, a mira\n"
"será " COLOR(RED) "desfeita" COLOR(DEFAULT) " ou transferida\n"
"para o próximo objeto com o " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) "\n"
"sobre ele." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Quando você tiver muitos\n"
"inimigos no seu campo de visão e\n"
"quiser escapar, aperte " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "\n"
"enquanto segura o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para trás." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Isso cancelará a mira." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Você pode mirar nas " COLOR(RED) "pedras" COLOR(DEFAULT) "\n"
"próximas daqui para praticar!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(ADJUSTABLE) "Estágio da Floresta" COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x16") "Estamos esperando para ver\n"
SHIFT("\x3A") "sua bela cara!\n"
SHIFT("\x3A") "Ganhe prêmios!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Visite a\n"
SHIFT("\x19")  COLOR(RED) "Casa dos Irmãos Sabe-Tudo\n"
COLOR(DEFAULT)  SHIFT("\x0F") "para acabar com todas as suas\n"
SHIFT("\x28") "dúvidas sobre itens!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Esta é uma Pedra Tagarela!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que apertando " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " várias\n"
"vezes, nada-se mais rápido."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo próximo\n"
"à árvore solitária não muito\n"
"longe do rio na parte noroeste\n"
"do Campo de Hyrule. "
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo na\n"
"estrada que leva ao Lago Hylia."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a Espada Biggoron é\n"
"super afiada e nunca vai quebrar."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Medigoron não pensou\n"
"sobre seu próprio tamanho, por\n"
"isso sua loja fica tão\n"
"confinada."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Malon fez o recorde\n"
"original no percurso com\n"
"obstáculos do Rancho Lon Lon."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Malon do Rancho Lon Lon\n"
"aguarda que um cavaleiro em\n"
"armadura brilhante venha e\n"
"carregue-a algum dia."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Ruto, a Princesa Zora\n"
"que é conhecida por seu egoísmo\n"
"natural, gosta de um certo\n"
"garoto..."
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os que escolhem a\n"
"opção \"HOLD\" para o \"Z TARGETING\"\n"
"são de fato os \"jogadores de\n"
"Zelda!\""
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo próximo\n"
"a uma árvore na Vila Kakariko."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que, ao contrário de sua\n"
"imagem elegante, a Princesa\n"
"Zelda é, de fato, uma garota\n"
"muito levada!"
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a babá da Princesa\n"
"Zelda é de fato um dos Sheikah,\n"
"que muitos pensaram terem\n"
"morrido."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um homem que pode\n"
"sempre ser visto correndo pelo\n"
"Campo de Hyrule."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que é contra as regras usar\n"
"óculos na Loja de Baús do Tesouro\n"
"no Mercado da Cidade do Castelo\n"
"de Hyrule."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a Dama das Galinhas foi\n"
"ao Laboratório do Lago estudar\n"
"como alimentar os Cuccos de\n"
"bolso."
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que às vezes Gerudos vêm\n"
"à Cidade do Castelo de Hyrule\n"
"procurar namorados."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a ladra Nabooru, que\n"
"frequenta esta área, é uma\n"
"Gerudo."
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que se chegar perto de uma\n"
"borboleta segurando um Galho\n"
"Deku nas mãos, alguma coisa\n"
"de bom acontecerá."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que você pode encontrar\n"
"algo novo em calabouços que\n"
"você já terminou."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os Gerudos veneram\n"
"Ganondorf quase como um deus."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo perto\n"
"da entrada para o Vale Gerudo."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a coruja Kaepora\n"
"Gaebora é a reencarnação de um\n"
"antigo Sábio.  "
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a estranha coruja,\n"
"Kaepora Gaebora, pode parecer\n"
"grande e pesada, mas seu\n"
"temperamento é bem alegre."
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que o cavalo de Ganondorf\n"
"é um garanhão Gerudo preto e\n"
"puro."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Ganondorf não está\n"
"satisfeito em dominar apenas\n"
"Gerudo. Ele quer conquistar\n"
"Hyrule inteiro!"
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que o tesouro que se ganha\n"
"no Campo de Treinamento de Gerudo\n"
"não é tão bom quanto se pode\n"
"esperar devido à sua dificuldade!"
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um interruptor que\n"
"só é ativado quando você dá\n"
"um Ataque Giratório."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que é possível achar um\n"
"total de 100 Skulltulas de Ouro\n"
"em Hyrule.  "
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que quando um povo sem\n"
"fada entra no Bosque Perdido,\n"
"viram monstros!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os buraquinhos no\n"
"chão que você encontra em\n"
"Hyrule são solos perfeitos\n"
"para proliferação de insetos."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os Kokiris são sempre\n"
"seguidos por pequenas fadas."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que um Kokiri deixou a\n"
"floresta, mas ele ainda está\n"
"vivo!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Que é isso? " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "Um dos monstros parasitas dentro\n"
"da Árvore Deku! Seu " COLOR(DEFAULT) "olho" COLOR(LIGHTBLUE) " é\n"
"vulnerável quando fica vermelho!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ovo Gohma\n"
COLOR(LIGHTBLUE) "Quando este ovo chocar, uma\n"
"Larva Gohma nascerá." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larva Gohma\n"
COLOR(LIGHTBLUE) "Cuidado quando ele preparar\n"
"o ataque!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula\n"
COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "abdome" COLOR(LIGHTBLUE) " mole é o\n"
"ponto fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula Grande\n"
COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "abdome" COLOR(LIGHTBLUE) " mole é o ponto\n"
"fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tailpasaran\n"
COLOR(LIGHTBLUE) "A " COLOR(DEFAULT) "cauda" COLOR(LIGHTBLUE) " é seu ponto fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baba Deku\n"
COLOR(LIGHTBLUE) "Acerte-o quando ele der o bote,\n"
"e ficar reto. Ataque-o rápido\n"
"para ganhar um " COLOR(DEFAULT) "Galho Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grande Baba Deku\n"
COLOR(LIGHTBLUE) "Acerte-o quando ele der o bote,\n"
"e ficar reto. Ataque-o rápido\n"
"para ganhar um " COLOR(DEFAULT) "Galho Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baba Deku\n"
COLOR(LIGHTBLUE) "Pode parecer murcho, mas ele\n"
"o machucará se o tocar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Arbusto Deku\n"
COLOR(LIGHTBLUE) "Vai se esconder na grama se\n"
"você chegar perto. Rebata as\n"
"nozes que ele cuspir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Rei Dodongo\n"
COLOR(LIGHTBLUE) "É um enorme Dodongo que come\n"
"tudo! Dei-lhe um impacto, e acabe\n"
"com ele usando a sua " COLOR(DEFAULT) "espada" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Cuidado com a sua baforada!\n"
"Use técnicas do tipo " COLOR(DEFAULT) "Mirar [Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo Bebê\n"
COLOR(LIGHTBLUE) "Cuidado com seus saltos!\n"
"Ele vai explodir depois de ser\n"
"derrotado!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos\n"
COLOR(LIGHTBLUE) "Use seu escudo e lute com\n"
"técnicas do tipo " COLOR(DEFAULT) "Mirar [Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos\n"
COLOR(LIGHTBLUE) "Use seu escudo e lute com\n"
"técnicas do tipo " COLOR(DEFAULT) "Mirar [Z]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese de Fogo\n"
COLOR(LIGHTBLUE) "Destrua-o antes que voe até\n"
"você! Do contrário, suas chamas\n"
"queimarão seu " COLOR(DEFAULT) "Escudo Deku" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese\n"
COLOR(LIGHTBLUE) "Quando estiver perto, use " COLOR(DEFAULT) "[Z]\n"
"Mirando" COLOR(LIGHTBLUE) ". Mesmo voando você\n"
"ainda pode mirar nele." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armos\n"
COLOR(LIGHTBLUE) "Pare o movimento dele e\n"
"o destrua!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinade\n"
COLOR(LIGHTBLUE) "Muitas medusas parasitas\n"
"aglomeram-se nesse monstro. Ataque\n"
"seu corpo protegido por medusas!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tentáculo Parasita?\n"
COLOR(LIGHTBLUE) "Parece que sua parte fina é\n"
"seu ponto fraco... Você precisa\n"
"de um item para destruí-lo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shabom\n"
COLOR(LIGHTBLUE) "Se o atacar, ele vai revidar\n"
"com sua lâmina!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "Se o tocar, você será\n"
"eletrocutado!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "Se o tocar, você será\n"
"eletrocutado!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stinger\n"
COLOR(LIGHTBLUE) "Destrua-o antes que voe até você!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon Fantasma\n"
COLOR(LIGHTBLUE) "É um fantasma do Templo da\n"
"Floresta! Ele vem de um dos\n"
"quadros."
BOX_BREAK
COLOR(LIGHTBLUE) "Responda ao ataque mágico dele\n"
"com o seu próprio ataque!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Atraia-o e observe os seus\n"
"movimentos! Ataque-o quando\n"
"ele baixar a guarda!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha Azul\n"
COLOR(LIGHTBLUE) "Proteja-se de sua chama azul\n"
"com seu " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha Branca\n"
COLOR(LIGHTBLUE) "Ataque quando ele parar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha Verde\n"
COLOR(LIGHTBLUE) "Use sua espada quando o fogo\n"
"verde acabar!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skullwalltula\n"
COLOR(LIGHTBLUE) "Cuidado para não tocá-la!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula de Ouro\n"
COLOR(LIGHTBLUE) "É conhecida também por Aranha\n"
"da Maldição. Se a matar, você\n"
"receberá um " COLOR(DEFAULT) "emblema" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volvagia\n"
COLOR(LIGHTBLUE) "É o Chefe do Templo do Fogo,\n"
"revivido pelo Rei do Mal. Não\n"
"sei seu ponto fraco..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dançarina em Chamas\n"
COLOR(LIGHTBLUE) "Primeiro apague suas " COLOR(DEFAULT) "chamas" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lesma Tocha\n"
COLOR(LIGHTBLUE) "Quando o seu fogo apagar, ela\n"
"vai fugir. Mate-a antes que\n"
"acenda o fogo de novo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha Vermelha\n"
COLOR(LIGHTBLUE) "Proteja-se do seu ataque com\n"
"o " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morpha\n"
COLOR(LIGHTBLUE) "Mestre do Templo da Água. Tem\n"
"controle total da água. Tire o\n"
"seu " COLOR(DEFAULT) "núcleo" COLOR(LIGHTBLUE) " e ataque-o!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  NAME " Negro\n"
COLOR(LIGHTBLUE) "Derrote a si mesmo!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Concha Afiada\n"
COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "músculo interno" COLOR(LIGHTBLUE) " é seu\n"
"ponto fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Prego\n"
COLOR(LIGHTBLUE) "Ataque-o quando retrair seus\n"
"pregos!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Chefe do Templo da Sombra,\n"
"revivido do poço. Olhe para ele\n"
"com o " COLOR(DEFAULT) "olho da verdade" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "ReDead\n"
COLOR(LIGHTBLUE) "Seu olhar vai paralisá-lo. Se\n"
"ele morder, " COLOR(DEFAULT) "aperte qualquer\n"
"botão" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ganon Fantasma\n"
COLOR(LIGHTBLUE) "Ataque-o " COLOR(DEFAULT) "quando ele vier de\n"
"um dos quadros" COLOR(LIGHTBLUE) "! Atenção para\n"
"os que são falsos!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Seu olhar vai paralisá-lo. Se ele\n"
"morder, " COLOR(DEFAULT) "aperte qualquer\n"
"botão" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mãos do Mão Morta\n"
COLOR(LIGHTBLUE) "Se ele o agarrar, " COLOR(DEFAULT) "aperte\n"
"qualquer botão" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mão Morta\n"
COLOR(LIGHTBLUE) "Cuidado com suas infinitas mãos!\n"
"Acerte a cabeça!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mestre do Muro\n"
COLOR(LIGHTBLUE) "Cuidado com sua " COLOR(DEFAULT) "sombra" COLOR(LIGHTBLUE) " no\n"
"chão. Destrua-o antes que ele\n"
"volte para o teto!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mestre do Piso\n"
COLOR(LIGHTBLUE) "Quando ele se dividir, destrua-o\n"
"antes que se reúna!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Koume\n"
COLOR(LIGHTBLUE) "Mãe adotiva de Ganondorf.\n"
"Feiticeira do Fogo. Ela parece\n"
"vulnerável a " COLOR(DEFAULT) "baixa temperatura" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Kotake\n"
COLOR(LIGHTBLUE) "Mãe adotiva de Ganondorf.\n"
"Feiticeira do Gelo. Ela parece\n"
"vulnerável a " COLOR(DEFAULT) "alta temperatura" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Junta de Ferro\n"
COLOR(LIGHTBLUE) "Algo estranho...\n"
"Esse não é um inimigo comum!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Junta de Ferro\n"
COLOR(LIGHTBLUE) "Cuidado com seu ataque ax!\n"
"Machuca muito! Ataque-o quando\n"
"baixar a guarda!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Caveirinha\n"
COLOR(LIGHTBLUE) "É isso que acontece com\n"
"garotos que andam na floresta?\n"
"Ele parece não gostar de adultos." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tal Tal\n"
COLOR(LIGHTBLUE) "Um inimigo que come " COLOR(DEFAULT) "escudos" COLOR(LIGHTBLUE) "\n"
"e certas " COLOR(DEFAULT) "roupas" COLOR(LIGHTBLUE) ". Abata-o para\n"
"pegar de volta o equipamento!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beamos\n"
COLOR(LIGHTBLUE) "Cuidado com seu raio guiado!\n"
"Aposto que ele não gosta de\n"
COLOR(DEFAULT) "fumaça" COLOR(LIGHTBLUE) " em seu olho!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anubis\n"
COLOR(LIGHTBLUE) "É vulnerável a " COLOR(RED) "fogo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Freezzard\n"
COLOR(LIGHTBLUE) "Cuidado com seu bafo congelante!\n"
"Destrua-o completamente antes\n"
"que reviva." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf o Rei do Mal\n"
COLOR(LIGHTBLUE) "Não tenho idéia do seu ponto\n"
"fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "Realmente não tenho idéia do\n"
"seu ponto fraco!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Caveirinha\n"
COLOR(LIGHTBLUE) "Isso acontece com garotos que\n"
"se perdem na floresta? Ele pode\n"
"ser nosso amigo se fizermos..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Caveirinha\n"
COLOR(LIGHTBLUE) "Isso acontece com garotos que\n"
"se perdem na floresta? Ele parece\n"
"infeliz por não ter rosto!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Caveirinha\n"
COLOR(LIGHTBLUE) "Isso acontece com garotos que\n"
"se perdem na floresta? Ele parece\n"
"satisfeito com seu crânio." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Rebata as rochas que ele cospe\n"
"em você!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasma do cemitério?\n"
COLOR(LIGHTBLUE) "Fixe seu olhar nele " COLOR(DEFAULT) "Mirando\n"
"[Z]" COLOR(LIGHTBLUE) ", e ele desaparecerá..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasma\n"
COLOR(LIGHTBLUE) "Use o " COLOR(DEFAULT) "[Z] Mirando" COLOR(LIGHTBLUE) ", e ele\n"
"irá desaparecer..." COLOR(DEFAULT)  QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tektite Vermelho\n"
COLOR(LIGHTBLUE) "Use o " COLOR(DEFAULT) "[Z] Mirando" COLOR(LIGHTBLUE) " quando\n"
"ele pular!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tektite Azul\n"
COLOR(LIGHTBLUE) "Difícil matá-lo na água. Atraia-o\n"
"para a superfície!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Observe os seus movimentos e\n"
"deixe-o ir!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "O ponto fraco são as " COLOR(DEFAULT) "raízes" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larva Peahat\n"
COLOR(LIGHTBLUE) "Defenda-se com o " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobo\n"
COLOR(LIGHTBLUE) "Atraia-o e observe seus\n"
"movimentos! Ataque-o quando ele\n"
"baixar a sua guarda!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Arbusto Mau\n"
COLOR(LIGHTBLUE) "Se chegar perto dele, ele\n"
"se esconderá na grama..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Arbusto Comerciante\n"
COLOR(LIGHTBLUE) "Se chegar perto dele, ele\n"
"vai se esconder..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasma de Dampé\n"
COLOR(LIGHTBLUE) "É o fantasma do coveiro morto!\n"
"Se o seguir, ele poderá lhe\n"
"dar o seu " COLOR(DEFAULT) "segredo" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg - Uma das irmãs fantasmas\n"
COLOR(LIGHTBLUE) "Se ela se dividir em múltiplas\n"
"imagens, descubra qual é a\n"
COLOR(DEFAULT) "verdadeira" COLOR(LIGHTBLUE) ". Seria essa uma?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle - Uma das irmãs fantasmas\n"
COLOR(LIGHTBLUE) "Ataque-a quando aparecer!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bete - Uma das irmãs fantasmas\n"
COLOR(LIGHTBLUE) "Ataque-a quando aparecer!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy - Uma das irmãs fantasmas\n"
COLOR(LIGHTBLUE) "Ataque-a quando aparecer!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ladra Gerudo\n"
COLOR(LIGHTBLUE) "Quando baixar a guarda,\n"
"ataque-a! Se não a derrotar,\n"
"você será capturado!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalchild\n"
COLOR(LIGHTBLUE) "Não tenha medo dele! Apenas\n"
"ataque-o repetidamente!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese de Gelo\n"
COLOR(LIGHTBLUE) "Destrua-o antes que voe em você!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobo Branco\n"
COLOR(LIGHTBLUE) "Atraia-o e observe os seus\n"
"movimentos! Ataque-o quando ele\n"
"abaixar a sua guarda!" COLOR(DEFAULT)  QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guay\n"
COLOR(LIGHTBLUE) "Destrua-o antes que voe em\n"
"você!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bigocto\n"
COLOR(LIGHTBLUE) "Ataque-o por trás!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasmão\n"
COLOR(LIGHTBLUE) "Não desaparecerá mesmo mirando\n"
"nele. Ele se move rápido mesmo\n"
"com esse tamanho!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova\n"
COLOR(LIGHTBLUE) "Essa é a combinação de Kotake\n"
"e Koume. Jogue seus " COLOR(DEFAULT) "ataques\n"
"mágicos" COLOR(LIGHTBLUE) " de volta a elas!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasma\n"
COLOR(LIGHTBLUE) "Ele não desaparece se mirar\n"
"nele. Ele não assombra muito,\n"
"ou será que sim..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x29") "Toque usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." COLOR(YELLOW) "\n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Toque usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " Pára.\n"
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
QUICKTEXT_ENABLE  SHIFT("\x13") "Toque o " COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x22") "Toque o " COLOR(RED) "Bolero do Fogo" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Toque a " COLOR(BLUE) "Serenata da Água" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0B") "Toque o Réquiem dos Espíritos!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Toque o " COLOR(PURPLE) "Noturno da Sombra" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Toque o " COLOR(LIGHTBLUE) "Prelúdio da Luz" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Acompanhe a " COLOR(ADJUSTABLE) "Canção de Saria" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21") "OK? Esta é " COLOR(RED) "a Canção" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27") "Memorize " COLOR(BLUE) "esta canção" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deixe a " COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) " no coração.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Esta canção" COLOR(DEFAULT) " abre o Portal do Tempo!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17") "Não esquecerei " COLOR(PURPLE) "esta canção" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Toque usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " Pára.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(RED) "Não pode sumir aqui!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Vai ao Bosque Perdido?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Vai ao Cume da Montanha da\n"
"Morte?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(BLUE) "Vai ao Lago Hylia?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Vai ao Colosso do Deserto?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Vai ao cemitério?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Vai ao Templo do Tempo?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05")  NAME " tocou o " COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0E")  NAME " tocou o " COLOR(RED) "Bolero do Fogo" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  NAME " tocou a " COLOR(BLUE) "Serenata da Água" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04")  NAME " tocou o " COLOR(YELLOW) "Réquiem dos Espíritos" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09")  NAME " tocou o " COLOR(PURPLE) "Noturno da Sombra" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08")  NAME " tocou o " COLOR(LIGHTBLUE) "Prelúdio da Luz" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Tocou a " COLOR(ADJUSTABLE) "Canção de Saria" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Tocou a " COLOR(RED) "Canção de Epona" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x18")  NAME " tocou a " COLOR(BLUE) "Canção de Zelda" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16")  NAME " tocou a " COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10")  NAME " tocou a " COLOR(LIGHTBLUE) "Canção do Tempo" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Tocou a " COLOR(PURPLE) "Canção da Tempestade" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04")  NAME " tocou a " COLOR(YELLOW) "Canção do Espantalho" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Finalmente acordou!\n"
"Eu sou " COLOR(RED) "Navi " COLOR(LIGHTBLUE) "a fada! " COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "A Grande Árvore Deku me pediu\n"
"para ser sua " COLOR(RED) "parceira" COLOR(LIGHTBLUE) "!\n"
"Prazer em conhecê-lo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x12") "Yahoo! Oi, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uau! Uma fada!"
BOX_BREAK
UNSKIPPABLE "Finalmente uma fada com você,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esperarei por você aqui.\n"
"Continue! Vá ver a Grande\n"
"Árvore Deku!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aperte " COLOR(BLUE) "[A] " COLOR(DEFAULT) "na pedra, e erga-a!\n"
"Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) ", e erga-a!"
BOX_BREAK
COLOR(RED) "Aquele Mido idiota..." COLOR(DEFAULT) " ele me fez\n"
"remover as rochas da frente da\n"
"casa dele."
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, você tem uma " COLOR(LIGHTBLUE) "fada" COLOR(DEFAULT) " agora?!\n"
"Que ótimo, " NAME "!"
BOX_BREAK
UNSKIPPABLE "Como?"
BOX_BREAK
UNSKIPPABLE "Você foi chamado pela\n"
COLOR(RED) "Grande Árvore Deku" COLOR(DEFAULT) "?\n"
"Que honra!"
BOX_BREAK
UNSKIPPABLE "Ela lhe dará um presente especial!\n"
"Hihi!"
BOX_BREAK
UNSKIPPABLE "Isto porque a Grande Árvore Deku\n"
"é nossa mãe, a guardiã da floresta,\n"
"que deu vida para todos nós,\n"
"os Kokiris!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu queria saber se a " COLOR(RED) "Grande\n"
"Árvore Deku" COLOR(DEFAULT) " deu vida para todos\n"
"na floresta, assim como para nós,\n"
"os Kokiris?"
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, vamos treinar uns comandos!"
BOX_BREAK
COLOR(RED) "Pulo lateral " COLOR(DEFAULT) "enquanto" COLOR(LIGHTBLUE) " [Z] Mirando" COLOR(DEFAULT) ",\n"
"aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " quando\n"
"em movimento lateral."
BOX_BREAK
COLOR(RED) "Mortal" COLOR(DEFAULT) " enquanto " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) ",\n"
"aperte " COLOR(BLUE) "[A] " COLOR(DEFAULT) "quando se\n"
"deslocar para trás."
BOX_BREAK
COLOR(RED) "Rolar" COLOR(DEFAULT) " enquanto " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) ",\n"
"aperte " COLOR(BLUE) "[A] " COLOR(DEFAULT) "quando estiver se\n"
"movendo para frente. Rolando\n"
"você pode evitar danos."
BOX_BREAK
"Se estiver com a espada preparada\n"
"enquanto " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) ", aperte\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " para " COLOR(RED) "atacar pulando" COLOR(DEFAULT) "!\n"
"Ataque com pulo dobra o dano!"
BOX_BREAK
"Você pode usar " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) "\n"
"na " COLOR(RED) "pedra" COLOR(DEFAULT) " próxima a mim,\n"
"então pratique!   "
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você não tem permissão para sair!\n"
TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A Grande Árvore Deku disse que\n"
"se um Kokiri deixar a floresta, ele\n"
"morrerá!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(RED) "Mido ignóbil" COLOR(DEFAULT) ", me fez cortar\n"
"a grama da casa de Saria."
BOX_BREAK
UNSKIPPABLE "Mido disse a Saria que faria\n"
"isso para ela gostar dele, mas na\n"
"verdade eu que faço o trabalho! " TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você e " COLOR(RED) "Saria" COLOR(DEFAULT) " são muito\n"
"amigos, então vai me ajudar a\n"
"cortar a grama?"
BOX_BREAK
"Deixarei com você tudo que\n"
"encontrar na grama que cortar."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sim! É assim que se usa uma\n"
COLOR(LIGHTBLUE) "fada" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "É tão formidável você ter uma\n"
"fada parceira!"
BOX_BREAK
UNSKIPPABLE "Eu vou lhe ensinar como falar\n"
"com as pessoas usando a sua\n"
"fada!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando uma fada voar perto de\n"
"uma pessoa ou coisa, aperte " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "\n"
"para olhar para ela."
BOX_BREAK
"Se usar " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) ", poderá falar\n"
"com as pessoas à distância,\n"
"como agora."
BOX_BREAK
"Quando não houver nada para\n"
"mirar você pode apertar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "\n"
"apenas para " COLOR(RED) "olhar para frente" COLOR(DEFAULT) ".\n"
"Tente isto!"
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, finalmente uma " COLOR(LIGHTBLUE) "fada" COLOR(DEFAULT) " com você!"
BOX_BREAK
UNSKIPPABLE "Terá muito que aprender!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Uau! " QUICKTEXT_ENABLE "Grande notícia!" QUICKTEXT_DISABLE "\n"
"Estou tão feliz!"
BOX_BREAK
UNSKIPPABLE "Agora você é um autêntico Kokiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "É verdade?\n"
"A Grande Árvore Deku convocou\n"
"você?"
BOX_BREAK
UNSKIPPABLE "É uma honra e tanto conversar\n"
"com a Grande Árvore Deku!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, você está indo..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas tudo bem, pois seremos\n"
"amigos para sempre...\n"
"não é?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu quero que leve esta Ocarina...\n"
"Por favor, cuide bem dela."
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando tocar minha Ocarina, eu\n"
"espero que pense em mim e volte\n"
"para visitar a floresta."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh... Navi...\n"
"Tu retornaste..."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Bem-vindo..."
BOX_BREAK
UNSKIPPABLE "Ouve com cuidado o que eu, a\n"
COLOR(RED) "Árvore Deku" COLOR(DEFAULT) ", tenho para falar\n"
"a ti..."
BOX_BREAK
UNSKIPPABLE "Tuas noites em luas recentes\n"
"devem ter sido inquietas, e\n"
"cheias de pesadelos..."
BOX_BREAK
UNSKIPPABLE "À medida que os servos do mal\n"
"ganham força, um clima vil\n"
"penetra a terra e causa pesadelos\n"
"àqueles sensíveis a isto..."
BOX_BREAK
UNSKIPPABLE "Há pouco, tu sentiste isto..."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Chegou a hora de testar tua\n"
"coragem... " TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu fui " COLOR(RED) "amaldiçoada" COLOR(DEFAULT) "...\n"
"Preciso que quebres a maldição\n"
"com tua sabedoria e coragem."
BOX_BREAK
"Tu tens coragem para\n"
"incumbir-se desta tarefa?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então entra, bravo\n"
NAME ", e tu também,\n"
"Navi..."
BOX_BREAK
UNSKIPPABLE "Navi a fada...\n"
"Tu deves ajudar " NAME "..."
BOX_BREAK
UNSKIPPABLE "E " NAME "...quando " COLOR(LIGHTBLUE) "Navi\n"
COLOR(DEFAULT) "falar, usa " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "para ouvir\n"
"suas palavras de sabedoria..."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Talvez tu ainda não tenhas\n"
"confiança em tuas perícias...\n"
"Retorna à Floresta Kokiri para\n"
"aprender as práticas de combate..."
BOX_BREAK
"Quando estiveres pronto, retorna aqui\n"
"e fala comigo usando " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O melhor lugar para aprender\n"
"algumas habilidades é no\n"
COLOR(ADJUSTABLE) "Centro de Treinamento da Floresta" COLOR(DEFAULT) ".\n"
COLOR(DEFAULT) "No monte acima daqui."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Ou-ou-ou!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Perdoe-me, mestre! " QUICKTEXT_DISABLE "\n"
"Se eu lhe der uma dica, você me\n"
"deixa ir?"
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Quando você pular de um penhasco\n"
"alto, se você segurar " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para\n"
"frente, você rolará no chão e não\n"
"se machucará na queda.  "
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Não posso garantir que isto\n"
"funciona caso o penhasco seja\n"
"realmente muito alto, hehe!"
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Bem, tente isto se sentir\n"
"que é alto!\n"
QUICKTEXT_ENABLE "Uah ha hah!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Sob a máscara...você não é\n"
"o garoto Kokiri?"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que máscara incomum você tem\n"
"aí. He He! Gosto disso! Isto me\n"
"faz parecer um pouco mais fortão."
BOX_BREAK
"Ei, por que você não me dá isso?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Jamais" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh! Que maldade comigo..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Vou ficar o tempo todo usando\n"
"isto!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Ele lhe deu " COLOR(RED) "10 Rupees" COLOR(DEFAULT) " por\n"
"esta máscara de 20 Rupees! Você\n"
"perdeu dinheiro!"
BOX_BREAK
UNSKIPPABLE "Volte à Loja de Máscaras e pague\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) " pela máscara. A\n"
"diferença terá de sair do seu\n"
"próprio bolso.  "
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus amigos querem esta máscara!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, tudo OK? Você não deixou a\n"
"floresta depois de tudo, hein?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você sabia que se você segurar " COLOR(LIGHTBLUE) "▼" COLOR(DEFAULT) "\n"
"para frente quando pular de um\n"
"penhasco, você rolará no chão? O\n"
"choque da aterrissagem será absorvido."
BOX_BREAK
"Se cair de um lugar muito alto,\n"
"ainda se machucará..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria está esperando no lugar\n"
"de sempre."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Muito bom, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem um Estilingue massa, eh?"
BOX_BREAK
"Sabe o que tem de massa nisso?\n"
"Você pode mirar enquanto aperta\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e atira soltando o botão!\n"
"Que massa!"
BOX_BREAK
"Se você tiver o Estilingue armado,\n"
"poderá usar " COLOR(LIGHTBLUE) "[Z] Mirando" COLOR(DEFAULT) " para\n"
COLOR(RED) "atirar se movendo" COLOR(DEFAULT) "... Você\n"
"sabia disso?"
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não, " NAME "...\n"
"Meu tempo é curto...  "
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Agora... ouve cuidadosamente...\n"
"Um " COLOR(RED) "homem mau do deserto" COLOR(DEFAULT) "\n"
"lançou esta maldição sobre mim..."
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se estiver procurando Saria, ela\n"
"está no " COLOR(ADJUSTABLE) "Bosque Perdido" COLOR(DEFAULT) "."
BOX_BREAK
"Não me diga que você não sabe\n"
"onde é! A entrada é em cima do\n"
"monte que avista toda nossa\n"
"vila!"
BOX_BREAK
"Eu sei que você vai se perder! Não\n"
"se preocupe, você logo estará de\n"
"volta a entrada!"
BOX_BREAK
SHIFT("\x51")  QUICKTEXT_ENABLE "Grumf!!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tu nunca deverás permitir que o\n"
"homem de armadura negra ponha as\n"
"mãos na Triforce sagrada..."
BOX_BREAK
UNSKIPPABLE "Nunca permita que aquele homem,\n"
"com seu coração do mal, entre no\n"
"Reino Sagrado" COLOR(RED) " " COLOR(DEFAULT) "da lenda..."
BOX_BREAK
UNSKIPPABLE "Aquele homem do mal que lançou\n"
"a maldição mortal em mim e\n"
"consumiu meu poder..."
BOX_BREAK
UNSKIPPABLE "Por causa disto,\n"
"meu fim é inexorável..."
BOX_BREAK
UNSKIPPABLE "Apesar de teu empenho em quebrar\n"
"a maldição, eu já estava condenada\n"
"antes de tu teres iniciado..."
BOX_BREAK
UNSKIPPABLE "Sim, eu irei falecer logo...\n"
UNSKIPPABLE "Mas não te aflijas por mim..."
BOX_BREAK
UNSKIPPABLE "Eu pude dizer a ti essas\n"
"questões importantes..."
BOX_BREAK
UNSKIPPABLE "Esta é a última esperança de\n"
"Hyrule..."
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O futuro depende de ti,\n"
NAME "...\n"
"Tu és corajoso..."
BOX_BREAK
UNSKIPPABLE "Navi a fada...\n"
"Ajuda " NAME " a conduzir consigo\n"
"o meu legado..."
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "Eu te imploro...Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "A...deus..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vamos ao Castelo de Hyrule,\n"
NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Adeus..." COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "Árvore Deku... " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que triste...HeHe!"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer tocar mais?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei você! \"" COLOR(LIGHTBLUE) "Sr. Sem Fada" COLOR(DEFAULT) "!\"\n"
"Qual o seu interesse com a\n"
"Grande Árvore Deku?"
BOX_BREAK
UNSKIPPABLE "Sem uma fada, você nem mesmo\n"
"é um homem!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quer passar por aqui, deve\n"
"ter no mínimo uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) " e um\n"
COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) " " COLOR(BLUE) "equipados" COLOR(DEFAULT) "!"
BOX_BREAK
SHIFT("\x51")  QUICKTEXT_ENABLE "Hehehe!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4F")  QUICKTEXT_ENABLE "Quê?!!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "não vai deixar você ver\n"
"a Grande Árvore Deku?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode comprar um " COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) " na\n"
"loja, mas só existe uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) "\n"
"em algum lugar da floresta."
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se quer ver a Grande Árvore Deku,\n"
"tenha pelo menos uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) " e um\n"
COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) " equipados!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu, o grande Mido," COLOR(RED) " " COLOR(DEFAULT) "jamais o\n"
"aceitarei como um de nós!"
BOX_BREAK
"Bah! Como você conseguiu ser o\n"
"favorito de Saria e da Grande\n"
"Árvore Deku?! Hein?!\n"
"Humph...humph..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Posso ensinar a você sobre os\n"
COLOR(RED) "ícones " COLOR(DEFAULT) "do topo da tela.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sobre os ícones amarelos\n"
"Sobre o ícone azul" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Os três ícones amarelos são\n"
"chamados " COLOR(YELLOW) "ícones [C]" COLOR(DEFAULT) "."
BOX_BREAK
"Eles mostram as coisas que\n"
"você pode usar com os botões\n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
"Uma vez que você consiga um " COLOR(YELLOW) "Item\n"
"de Botão [C]" COLOR(DEFAULT) ", vá a tela " COLOR(YELLOW) "Subtela de\n"
"Seleção de Item" COLOR(DEFAULT) " e selecione-o\n"
"para um dos três " COLOR(YELLOW) "Botões [C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O ícone azul no topo da tela\n"
"é chamado " COLOR(BLUE) "Ícone de Ação" COLOR(DEFAULT) "."
BOX_BREAK
"Este Ícone de Ação mostra a você\n"
"que ação você fará quando pressionar\n"
"o " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
"Pare em muitos lugares para ver\n"
"as diferentes coisas que poderá\n"
"fazer."
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você quer aprender sobre o\n"
COLOR(RED) "mapa " COLOR(DEFAULT) "e os " COLOR(RED) "itens" COLOR(DEFAULT) ", pergunte-me.\n"
"Mas só pergunte se quiser\n"
"ouvir uma longa explicação."
BOX_BREAK
"Sobre o que você quer saber?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Sobre o mapa\n"
"Sobre os itens\n"
"Não perguntar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Há um " COLOR(RED) "mapa" COLOR(DEFAULT) " na parte inferior\n"
"direita da tela."
BOX_BREAK
"A " COLOR(YELLOW) "seta amarela" COLOR(DEFAULT) " mostra a sua\n"
"posição atual e para que lado está\n"
"olhando. A " COLOR(RED) "marca vermelha" COLOR(DEFAULT) " mostra\n"
"por onde você entrou na área."
BOX_BREAK
"Você pode tirar e recolocar o\n"
"mapa na tela com o botão " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) "."
BOX_BREAK
"Se você quiser ver o nome\n"
"de um lugar, pressione " COLOR(RED) "START" COLOR(DEFAULT) "."
BOX_BREAK
"Você irá às Subtelas.\n"
"Selecione a " COLOR(RED) "Subtela Mapa" COLOR(DEFAULT) "."
BOX_BREAK
"Na Subtela Mapa, você pode\n"
"ver um mapa de Hyrule.\n"
"Conseguiu entender tudo mesmo?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Há três tipos de itens:\n"
COLOR(BLUE) "Itens de Equipamento" COLOR(DEFAULT) ", " COLOR(YELLOW) "Itens\n"
"de Botões [C]" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "Itens de Aventura" COLOR(DEFAULT) "."
BOX_BREAK
COLOR(BLUE) "Itens de Equipamento" COLOR(DEFAULT) " são espada,\n"
"escudo e roupa, que são efetivos\n"
"quando você os equipa."
BOX_BREAK
COLOR(YELLOW) "Itens de Botões [C]" COLOR(DEFAULT) " podem ser\n"
"configurados com " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) ", e " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e\n"
"usados pressionando-os."
BOX_BREAK
COLOR(LIGHTBLUE) "Itens de Aventura" COLOR(DEFAULT) " são coisas que\n"
"você coleta durante a sua aventura.\n"
"Você apenas os carrega."
BOX_BREAK
"Se você quiser mudar de equipamento\n"
"ou checar seu inventário, pressione\n"
COLOR(RED) "START" COLOR(DEFAULT) ".\n"
"Você entrará nas Subtelas."
BOX_BREAK
"Mude para uma das quatro diferentes\n"
"Subtelas com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "e mude ou\n"
"cheque os itens como quiser.\n"
"Dê uma olhada nisso!"
BOX_BREAK
"Quando você decidir equipar um\n"
COLOR(BLUE) "Item de Equipamento" COLOR(DEFAULT) ", aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) ".\n"
"Para " COLOR(YELLOW) "Itens de Botões [C]" COLOR(DEFAULT) ", aperte\n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "."
BOX_BREAK
"E isto foi uma bonita e longa\n"
"explicação.\n"
"Você entendeu tudo?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, apenas lembre-se disto. Se\n"
"quiser " COLOR(ADJUSTABLE) "salvar" COLOR(DEFAULT) ", aperte " COLOR(RED) "START" COLOR(DEFAULT) "\n"
"e entre nas Subtelas, depois\n"
"aperte " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Minha irmã pegou uns Rupees e foi\n"
"comprar algo na loja que tem um\n"
"telhado vermelho. Hih!"
BOX_BREAK
"Falando em " COLOR(RED) "Rupees" COLOR(DEFAULT) ", um " COLOR(ADJUSTABLE) "verde" COLOR(DEFAULT) "\n"
"vale um, um " COLOR(BLUE) "azul" COLOR(DEFAULT) " vale cinco\n"
"e um " COLOR(RED) "vermelho" COLOR(DEFAULT) " vale vinte.\n"
"Hi Hi!            "
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta loja...ela vende coisas que\n"
"você consegue na floresta de graça!\n"
"Hi hi!"
BOX_BREAK
"Você sabe como se usa um " COLOR(RED) "Escudo\n"
"Deku" COLOR(DEFAULT) "? Hi hi!"
BOX_BREAK
"Quando conseguir o escudo, aperte\n"
COLOR(RED) "START" COLOR(DEFAULT) " para entrar nas Subtelas.\n"
"Escolha a " COLOR(BLUE) "Subtela Equipamento" COLOR(DEFAULT) "\n"
"com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "."
BOX_BREAK
"Na " COLOR(BLUE) "Subtela Equipamento" COLOR(DEFAULT) ", escolha\n"
"o item que quer equipar e\n"
"pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para equipá-lo."
BOX_BREAK
"Uma vez equipado, segure-o com\n"
COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " e mude o ângulo dele\n"
"com o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Hi hi hi hi!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer saber como usar o\n"
COLOR(YELLOW) "Botão [C-Up]" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você pressionar " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", você\n"
"pode mudar sua visão."
BOX_BREAK
"Num lugar como esse, mudará para\n"
"uma visão de cima. Em locais abertos,\n"
"mudará para uma perspectiva em\n"
"primeira pessoa."
BOX_BREAK
"Além disso, quando \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\"\n"
"aparecer na parte superior direita da\n"
"tela, a fada Navi quer falar com\n"
"você. Use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " para ouvi-la!     "
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, se você jogar por aí com ele,\n"
"você irá descobrir."
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isto não é a Canção de Saria..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "está muito perturbado!\n"
"O que há com ele?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê? Onde você está indo?!"
BOX_BREAK
"Ao castelo?\n"
"Onde fica o castelo?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós Kokiris morreremos se sairmos\n"
"da floresta!"
BOX_BREAK
"Você não vai tentar sair da floresta,\n"
"ou vai?"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, " NAME "!\n"
"O que você fez?!"
BOX_BREAK
UNSKIPPABLE "A Grande Árvore Deku...ela...\n"
"morreu?"
BOX_BREAK
UNSKIPPABLE "Como você pôde ter feito isso?!\n"
"É tudo culpa sua!!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ei!!" QUICKTEXT_DISABLE "\n"
"O que está fazendo em minha casa?"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", está salvo! " TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria e " NAME " serão amigos\n"
"para sempre."
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aconteceu algo com a Grande Árvore\n"
"Deku?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De alguma forma, parece que o ar na\n"
"floresta mudou."
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", você está indo\n"
"embora?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você perder o escudo, você\n"
"vai voltar?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x80") "Todos os irmãos Anões Deku acham\n"
"você igualzinho ao nosso totem\n"
"sagrado da floresta!"
BOX_BREAK
SFX("\x38\x80") "Esta é uma oferenda nossa,\n"
"por favor aceite estes " COLOR(RED) "Galhos\n"
"Deku" COLOR(DEFAULT) ". Também iremos aumentar\n"
"sua capacidade de carregar!"
BOX_BREAK
"Abracadabra!"
BOX_BREAK
SFX("\x38\x80") "Alakazaammm! " EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desde que a Grande Árvore Deku\n"
"murchou...mais pestinhas\n"
"apareceram na floresta...\n"
"estou com medo!"
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Um vento do mal está vindo da\n"
"direção do Templo da Floresta."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Saria" COLOR(DEFAULT) " saiu, dizendo,\n"
"\"Eu tenho que fazer alguma coisa!\"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O " COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) " é\n"
"localizado na Campina Sagrada,\n"
"no outro lado do Bosque Perdido."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria foi ao templo e ainda\n"
"não voltou..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oi! Você não pode usar um Escudo\n"
"Deku! É só para garotos!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde está Saria?\n"
"O senhor a conhece?\n"
"Isso é estranho..." TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde " COLOR(RED) "Mido" COLOR(DEFAULT) " foi durante\n"
"uma emergência dessas?"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Entendo. Você não teve problemas\n"
"para entrar na floresta, senhor..."
BOX_BREAK
"Aqueles pestinhas irritaram muito?\n"
"Antes da Árvore Deku ter morrido,\n"
"não se viam coisas como aquelas\n"
"pelas redondezas..." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como é perigoso lá fora, eu sempre\n"
"fico dentro de casa.\n"
"Mas eu não aguento mais ficar aqui!"
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode comprar " COLOR(RED) "flechas" COLOR(DEFAULT) " numa\n"
"loja se tiver um " COLOR(RED) "arco" COLOR(DEFAULT) ". Você\n"
"já tem um, senhor?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Faz tempo que você viaja,\n"
"senhor?\n"
"Você se encontrou com um garoto\n"
"chamado " NAME "?"
BOX_BREAK
UNSKIPPABLE "Mido disse que a Grande Árvore\n"
"Deku murchou por causa daquele\n"
"garoto..."
BOX_BREAK
UNSKIPPABLE "Apenas Saria defendia\n"
NAME "--até que ela saiu." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Talvez nos confundimos..."
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu já o vi em algum lugar antes,\n"
"senhor?"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Senhor, conhece um garoto chamado\n"
NAME "?"
BOX_BREAK
UNSKIPPABLE "Ele saiu da floresta e não voltou mais! " TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Queria saber se " NAME " ainda\n"
"voltará?"
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Seria incrível ficar grande\n"
"como você, senhor! Eu queria\n"
"ser grande como você!"
BOX_BREAK
UNSKIPPABLE "Eu quero ser grande e forte e\n"
"derrotar os Anões Deku, mas..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós Kokiris jamais cresceremos\n"
"até o resto de nossas vidas...\n"
"Que porcaria!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por que esta fada está seguindo\n"
"você? Você não é um de nós!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O que você é? Apesar das roupas\n"
"de Kokiris, você não me engana!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prometi a Saria que nunca deixaria\n"
"ninguém vir por aqui."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olá! Eu sou o " COLOR(RED) "broto da\n"
"Árvore Deku" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Devido a você e Saria terem\n"
"quebrado a maldição do Templo da\n"
"Floresta, eu posso crescer!"
BOX_BREAK
UNSKIPPABLE "Obrigado!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, você viu seus velhos amigos?\n"
"Nenhum deles reconheceu você com\n"
"esse corpo crescido, não foi?\n"

BOX_BREAK
UNSKIPPABLE "Isto porque os " COLOR(ADJUSTABLE) "Kokiris" COLOR(DEFAULT) " nunca\n"
"crescem! Mesmo após sete anos,\n"
"eles ainda são garotos!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você deve estar confuso, pois\n"
"só você cresceu!"
BOX_BREAK
UNSKIPPABLE "Bem, como você já deve ter\n"
"percebido, você não é um Kokiri!\n"
"Você é um " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Estou feliz de finalmente revelar\n"
"este segredinho para você!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Há algum tempo atrás, antes do\n"
"Rei de Hyrule unificar este país,\n"
"houve uma guerra ardente no mundo." BOX_BREAK_DELAYED("\x5A") "Um dia, para escapar das chamas\n"
"da guerra, a " COLOR(RED) "mãe de um Hylian" COLOR(DEFAULT) "\n"
"e seu " COLOR(RED) "bebê" COLOR(DEFAULT) " entraram nesta\n"
"floresta proibida." BOX_BREAK_DELAYED("\x5A") "A mãe ficou gravemente ferida...\n"
"sua única chance era confiar a\n"
"criança à " COLOR(RED) "Árvore Deku" COLOR(DEFAULT) ", o\n"
"espírito guardião da floresta. " BOX_BREAK_DELAYED("\x5A") "A Árvore Deku podia sentir que esta\n"
"era uma criança de sorte, cujo\n"
"destino afetaria o mundo inteiro,\n"
"e então a levou para a floresta." BOX_BREAK_DELAYED("\x5A") "Após a morte da mãe, o bebê\n"
"cresceu como um " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) ".\n"
"E agora, finalmente, o dia de seu\n"
"destino chegou!  " FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você é um " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) ", e sempre\n"
"esteve destinado a deixar esta\n"
"floresta."
BOX_BREAK
UNSKIPPABLE "E agora...\n"
"Você aprendeu seu próprio destino...\n"
"E saberá o que deve fazer."
BOX_BREAK
UNSKIPPABLE "E é isso...\n"
"Você deve salvar a terra de\n"
"Hyrule!"
BOX_BREAK
UNSKIPPABLE "Agora, " NAME ", quebre as maldições\n"
"em todos os Templos, e traga a paz\n"
"para Hyrule!!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Essa melodia!"
BOX_BREAK
UNSKIPPABLE "Saria toca aquela canção o\n"
"tempo todo!\n"
"Você...conhece Saria?"
BOX_BREAK
UNSKIPPABLE "Essa canção..."
BOX_BREAK
UNSKIPPABLE "Saria só a ensinava para os\n"
"seus amigos..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando vejo você...\n"
"Não sei porquê, mas me lembro...\n"
"dele..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu tenho você agora!\n"
"Nesta fenda entre sonhos e\n"
"realidade, logo tudo que ficará\n"
"de você será seu corpo falecido!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigada!\n"
"Por sua causa, eu acordei como\n"
"uma Sábia..."
BOX_BREAK
UNSKIPPABLE "Eu sou " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"A Sábia do Templo da Floresta..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "Saria será sempre...\n"
SHIFT("\x3C") "sua amiga..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O fluxo do tempo é sempre cruel...\n"
"Sua velocidade é distinta para\n"
"cada pessoa, mas ninguém pode\n"
"mudar isto..."
BOX_BREAK
UNSKIPPABLE "Algo que não muda com o tempo\n"
"é a memória dos dias de\n"
"juventude..."
BOX_BREAK
UNSKIPPABLE "Para voltar aqui novamente,\n"
"toque o " COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...\n"
"Eu o verei de novo..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria ainda não voltou...\n"
"Mas sei que ela retornará\n"
"algum dia..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "OK...\n"
"Eu acredito." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...entendo..."
BOX_BREAK
UNSKIPPABLE "Saria jamais voltará..."
BOX_BREAK
UNSKIPPABLE "Mas...Eu...Eu fiz uma promessa\n"
"a Saria..."
BOX_BREAK
UNSKIPPABLE "Se " NAME " voltasse, eu certamente\n"
"diria a ele que Saria estava\n"
"esperando por ele..."
BOX_BREAK
UNSKIPPABLE "Por que " TEXT_SPEED("\x03") "Saria...realmente...\n"
"gostava..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Ei, você."
BOX_BREAK
"Se você o vir por aí,\n"
"por favor deixe-o saber..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ensine-me algo de esgrima!\n"
"Só tenho apertado " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " em\n"
"toda minha vida!"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ainda acho que você parece com\n"
"alguém que eu já vi antes, senhor."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é tão grande e forte! Eu\n"
"queria ser como você algum dia,\n"
"mesmo sabendo que serei sempre\n"
"pequeno."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... eu queria saber se ele\n"
"voltará..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sinto como se já o conhecesse há\n"
"muito tempo, Sr.!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Agora que o " COLOR(RED) "broto da Árvore\n"
"Deku" COLOR(DEFAULT) " está crescendo na\n"
"campina da Grande Árvore Deku,\n"
"a floresta voltou ao normal!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Trabalharemos juntos para\n"
"proteger a floresta!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Recentemente um vento bom vem\n"
"passando por aqui."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Desde que começou este vento,\n"
"tenho certeza que " NAME " voltará!\n"
""
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Queria saber se Saria voltará..."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tenho certeza que " NAME " vai\n"
"voltar!"
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "Grande Árvore Deku!\n"
COLOR(DEFAULT)  SHIFT("\x4F")  COLOR(LIGHTBLUE) "Voltei! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Esse homem maligno usa poderes de\n"
"feitiçaria incessantemente em sua\n"
"busca pelo Reino Sagrado, que é\n"
"conectado a Hyrule..."
BOX_BREAK
UNSKIPPABLE "Quando estiver nesse Reino\n"
"Sagrado, ele encontrará a relíquia\n"
"divina, a " COLOR(LIGHTBLUE) "Triforce" COLOR(DEFAULT) ", que contém\n"
"a essência dos deuses..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Antes do início dos tempos, antes\n"
SHIFT("\x2F") "da vida existir... " QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Três deusas douradas desceram\n"
SHIFT("\x13") "sobre o caos que era Hyrule..." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "Din, a deusa do poder... " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "Nayru, a deusa da sabedoria... " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Farore, a deusa da bravura... " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Com seus fortes braços em chamas,\n"
SHIFT("\x1C") "cultivou a terra e criou\n"
SHIFT("\x36") "a terra vermelha. " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Despejou sua sabedoria na terra\n"
SHIFT("\x13") "e deu o espírito da lei para\n"
SHIFT("\x48") "o mundo. " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Com sua alma rica, fez todas as\n"
SHIFT("\x14") "formas de vida que manteriam\n"
SHIFT("\x53") "a lei." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "Após os trabalhos concluídos,\n"
SHIFT("\x24") "as três grandes deusas\n"
SHIFT("\x24") "partiram para os céus. " QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "E triângulos sagrados dourados\n"
SHIFT("\x16") "permaneceram no local onde\n"
SHIFT("\x14") "as deusas deixaram o mundo." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Desde então, os triângulos sagrados\n"
SHIFT("\x16") "tornaram-se a base de Deus\n"
SHIFT("\x38") "em nosso mundo." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "E, o local de descanso dos\n"
SHIFT("\x24") "triângulos tornou-se o\n"
SHIFT("\x3A") "Reino Sagrado. " QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei garoto, você foi muito bem...\n"
"Parece que está ganhando uma\n"
"leve habilidade..." BOX_BREAK_DELAYED("\x3C") "Mas você só derrotou meu\n"
"fantasma...\n"
"Quando lutar comigo, não será\n"
"tão fácil assim!" BOX_BREAK_DELAYED("\x3C") "Que criação inútil foi aquele\n"
"fantasma! Eu vou bani-lo para a\n"
"fenda entre dimensões!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sempre acreditei que você\n"
"viria. Porque eu conheço você..."
BOX_BREAK
UNSKIPPABLE "Não..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "Não precisa se explicar..."
BOX_BREAK
UNSKIPPABLE "Pois quis o destino que você\n"
"e eu não pudéssemos viver no\n"
"mesmo mundo."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu ficarei aqui como a Sábia da\n"
"Floresta para ajudá-lo..."
BOX_BREAK
UNSKIPPABLE "Agora, leve este " COLOR(ADJUSTABLE) "Medalhão" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu demonstraste perfeitamente a\n"
"tua coragem..."
BOX_BREAK
UNSKIPPABLE "Eu sabia que tu serias capaz\n"
"de realizar meus desejos..."
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Agora, ainda tenho mais para te\n"
"dizer, queres ouvir...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...\n"
"Vai agora ao Castelo de Hyrule..."
BOX_BREAK
UNSKIPPABLE "Lá, tu certamente encontrarás a\n"
COLOR(RED) "Princesa do Destino" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Leva " COLOR(RED) "esta pedra" COLOR(DEFAULT) " contigo.\n"
"A pedra que aquele homem queria\n"
"tanto, que me amaldiçoou..."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sabia...\n"
"que você deixaria a floresta...\n"
"algum dia, " NAME "..."
BOX_BREAK
UNSKIPPABLE "Porque você é diferente de\n"
"mim e de meus amigos..."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE)  QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "! Vamos!\n"
"Acorda! " COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "A " COLOR(RED) "Grande Árvore Deku" COLOR(LIGHTBLUE) " quer\n"
"falar com você!\n"
QUICKTEXT_ENABLE  NAME " levanta!" QUICKTEXT_DISABLE  COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Ei! " QUICKTEXT_ENABLE "Vamos! " QUICKTEXT_DISABLE  COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Pode Hyrule depender de um garoto\n"
"tão preguiçoso?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pular está fora de moda agora.\n"
"Loucura são esses " COLOR(RED) "saltos\n"
"mortais" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x39") "Você pode fazer?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "A " COLOR(RED) "Grande Árvore Deku\n"
COLOR(LIGHTBLUE) "convocou você!\n"
"Então vamos indo, agora! " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x4D") "Navi...\n"
SHIFT("\x25") "Navi, onde tu estás?\n"
SHIFT("\x37") "Vem até aqui..."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, " COLOR(LIGHTBLUE) "Navi a fada" COLOR(DEFAULT) "... Ouve\n"
"minhas palavras, as palavras da\n"
COLOR(RED) "Árvore Deku" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Tu estás sentindo?\n"
"A atmosfera do mal que está\n"
"cobrindo este reino..."
BOX_BREAK
UNSKIPPABLE "Forças malignas estão reunindo\n"
"tropas para atacar nossa terra,\n"
"Hyrule..."
BOX_BREAK
UNSKIPPABLE "Por muito tempo, a " COLOR(RED) "Floresta Kokiri" COLOR(DEFAULT) ",\n"
"a fonte de vida, resistiu como uma\n"
"barreira, impedindo intrusos e\n"
"mantendo a ordem do mundo..."
BOX_BREAK
UNSKIPPABLE "Mas... diante deste poder do mal,\n"
"até mesmo o meu poder não é\n"
"nada..."
BOX_BREAK
UNSKIPPABLE "Parece que chegou o momento do\n"
COLOR(RED) "garoto sem fada" COLOR(DEFAULT) " começar a\n"
"sua aventura..."
BOX_BREAK
UNSKIPPABLE "O jovem cujo destino é levar\n"
"Hyrule ao caminho da justiça\n"
"e verdade..."
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "...vai agora! Encontra nosso\n"
"amigo e o guia para mim..."
BOX_BREAK
UNSKIPPABLE "Eu não tenho muito tempo."
BOX_BREAK
UNSKIPPABLE "Voa, Navi, voa! O destino da\n"
"floresta e do mundo, depende\n"
"de ti!"
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Por favor perdoe-me, mestre!\n"
"Nunca mais farei de novo! Se\n"
"me poupar, ensinarei uma coisa\n"
"boa a você."
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Você nunca derrotará meus irmãos\n"
"a menos que os acerte na ordem\n"
"correta."
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "A ordem é..." TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) "2  3  1" COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Vinte-três é o número um!" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
UNSKIPPABLE  SFX("\x38\x80") "Você acha que sou traidor?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Como soube de nosso segredo?!\n"
"Que " QUICKTEXT_ENABLE "irritante! " QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "É tão aborrecedor revelar o\n"
"segredo da Rainha Gohma para\n"
"você!  "
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Para administrar os momentos de\n"
"fúria da Rainha Gohma, ataque com\n"
"sua espada " COLOR(RED) "enquanto ela estiver\n"
"atordoada" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Oh, Realeza..."
BOX_BREAK
SFX("\x38\x80")  QUICKTEXT_ENABLE "Foi mal!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"Na vasta, densa floresta de Hyrule..." BOX_BREAK_DELAYED("\x28")  SHIFT("\x13") "Por longo tempo servi como\n"
SHIFT("\x29") "o espírito guardião...\n"
SHIFT("\x1F") "Eu sou a Árvore Deku..." FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x05") "As crianças da floresta, os Kokiris,\n"
SHIFT("\x2D") "moram aqui comigo." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0B") "Cada Kokiri tem sua própria\n"
SHIFT("\x35") "fada guardiã." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x14") "Porém, há um garoto" COLOR(RED) " " COLOR(DEFAULT) "que\n"
SHIFT("\x25") "não tem uma fada..." FADE("\x25")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo! Em troca, venderei\n"
"a você Nozes Deku!\n"
COLOR(RED) "5 peças" COLOR(DEFAULT) " são " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ok! Você venceu! Em troca,\n"
"venderei a você Galhos Deku!\n"
COLOR(RED) "1 peça" COLOR(DEFAULT) " são " COLOR(RED) "15 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ok! Você venceu! Em troca, por me\n"
"poupar, venderei a você um\n"
"Pedaço de Coração!\n"
COLOR(RED) "1 pedaço custa 10 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Vamos negociar!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "OPS!!!!" QUICKTEXT_DISABLE "\n"
"Vou para casa então!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Rupees insuficientes!\n"
"Volte depois!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Você não pode tê-lo agora!\n"
"Volte depois!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x2D") "Muito obrigado!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Estava esperando por você,\n"
NAME "!"
BOX_BREAK
UNSKIPPABLE "Esta é a " COLOR(RED) "Campina Sagrada da\n"
"Floresta" COLOR(DEFAULT) ". Meu lugar secreto!\n"
"Eu acho..."
BOX_BREAK
UNSKIPPABLE "Este lugar será um dia muito\n"
"importante para nós dois. É o que\n"
"eu sinto."
BOX_BREAK
UNSKIPPABLE "Se você tocar a Ocarina aqui,\n"
"poderá falar com os espíritos da\n"
"floresta." TEXTID("\x10\xA9") " "
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você gostaria de tocar a Ocarina\n"
"comigo?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não quero!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, tente seguir a melodia que\n"
"eu vou tocar.\n"
"Você está preparado?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Huh?!\n"
"Seu chato!\n"
"Vamos! Vamos tocar!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x36") "Formidável!"
BOX_BREAK
UNSKIPPABLE "Por favor não esqueça esta\n"
"música! Você promete?" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando quiser ouvir minha voz,\n"
"toque a " COLOR(ADJUSTABLE) "Canção de Saria" COLOR(DEFAULT) ". E fale\n"
"comigo regularmente!"
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está cuidando bem da minha\n"
"Ocarina?"
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x38\x80") "Bom!\n"
"Formidável! Conseguiu três\n"
"perfeitas tentativas!"
BOX_BREAK
UNSKIPPABLE  SFX("\x38\x80") "Tenho que dar um presente\n"
"de bom gosto para tal pessoa\n"
"maravilhosa! Leve isto!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido pode saber algo sobre o\n"
"paradeiro de Saria."
BOX_BREAK
"Eu acho que Mido está de mau\n"
"humor em uma das casas ao redor."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT)  SHIFT("\x1E")  COLOR(LIGHTBLUE) "Nada. Ele está dormindo." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cojiro? Por que?\n"
"Só um cara gentil como eu pode\n"
"amansá-lo..."
BOX_BREAK
UNSKIPPABLE "Ou seja..."
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x01") "Você..." TEXT_SPEED("\x00") "Você deve ser um\n"
"cara gentil!" QUICKTEXT_ENABLE " Deve ser!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Isso mesmo! " QUICKTEXT_DISABLE "\n"
"Por favor Sr. Gentil! Por favor!"
BOX_BREAK
UNSKIPPABLE "Entregue isto à " COLOR(RED) "velha bruxa\n"
"na loja de poções" COLOR(DEFAULT) " na Vila\n"
"Kakariko!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isto desaparecerá se você\n"
"demorar muito, então se apresse!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não posso " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Beleza. " QUICKTEXT_ENABLE "É isso aí!" QUICKTEXT_DISABLE "\n"
"Você não é um cara gentil mesmo!!\n"
QUICKTEXT_ENABLE "Desapareça daqui!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria queria ver você...\n"
"Ela já o encontrou?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Apresse-se, rapaz gentil!\n"
"Antes que desapareça, entregue-o\n"
"àquela velha..."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aquele cara não está aqui."
BOX_BREAK
UNSKIPPABLE "Todo aquele que entra na\n"
"floresta, fica perdido."
BOX_BREAK
UNSKIPPABLE "Todos se tornarão Stalfos.\n"
"Todos, Stalfos.\n"
"Por isso, ele não está mais\n"
"aqui. Apenas o seu serrote ficou." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse remédio é feito de cogumelos\n"
"da floresta. Devolva!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi.\n"
"Você vai se tornar... também?\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vendemos escudos, e não espadas!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você sabe a " COLOR(ADJUSTABLE) "Canção de Saria" COLOR(DEFAULT) "!\n"
"Somos amigos então! Tome isto!"
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oi! Você acha que minha face é do\n"
"tipo boa fé?\n"
"Ela não é muito rara..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vamos jogar mais depois!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Siga nossa música com sua\n"
"Ocarina. Nós o guiaremos com o\n"
"som."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Foi uma bela sessão.\n"
"Como símbolo de nossa amizade,\n"
"por favor leve isto."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, aqui!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME "... Que bom vê-lo\n"
"novamente! Ouça isto!\n"
"Hoot hoot..." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Depois de atravessar o Bosque\n"
"Perdido, você chegará na " COLOR(ADJUSTABLE) "Campina\n"
"da Floresta Sagrada" COLOR(DEFAULT) "."
BOX_BREAK
"É um lugar sagrado onde poucas\n"
"pessoas já estiveram."
BOX_BREAK
"Shhhh... que foi aquilo?\n"
"Posso ouvir um tom misterioso..."
BOX_BREAK
"Você deveria ouvir aquele tom\n"
"também...\n"
"Hoo hoo!!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer ouvir o que eu disse\n"
"novamente?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você for corajoso, passará\n"
"pela floresta tranquilamente..."
BOX_BREAK
UNSKIPPABLE "Simplesmente siga seus ouvidos\n"
"e ouça os sons que vêm da\n"
"floresta!\n"
"Hoot hoot hoot!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Você aprendeu uma música de\n"
"Ocarina com Saria?"
BOX_BREAK
UNSKIPPABLE "Aquela melodia parece ter poderes\n"
"misteriosos."
BOX_BREAK
UNSKIPPABLE "Deve haver outras músicas como\n"
"esta que você poderá aprender em\n"
"Hyrule." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você segurar a Ocarina com\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " onde uma melodia é\n"
"necessária, uma " COLOR(RED) "partitura" COLOR(DEFAULT) " vai\n"
"aparecer."
BOX_BREAK
"Recomendo que toque uma música\n"
"que saiba."
BOX_BREAK
"Também sugiro que toque até\n"
"mesmo quando um registro não for\n"
"mostrado. Como este:\n"
"Hoo hoo hoo hoot hoot hoot!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer ouvir o que eu disse\n"
"novamente?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não " COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Melodias que você aprendeu serão\n"
"gravadas na " COLOR(LIGHTBLUE) "Subtela de Status\n"
"da Aventura" COLOR(DEFAULT) ". Você deveria\n"
"memorizá-las."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...que vagabundo! Não sei\n"
"por que ele é sempre tão vil\n"
"com todos!"
BOX_BREAK
UNSKIPPABLE "Porém, ele disse a verdade. " TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Na floresta...coisas estranhas\n"
"vêm acontecendo ultimamente..."
BOX_BREAK
UNSKIPPABLE "Esteja preparado para tudo.\n"
"Seria melhor você achar uma arma!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ok! Você venceu! Em troca,\n"
"venderei a você " COLOR(RED) "Sementes Deku" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 peças" COLOR(DEFAULT) " custam " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Desisto! Se me deixar ir,\n"
"venderei a você um " COLOR(RED) "Escudo Deku" COLOR(DEFAULT) "!\n"
"São\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Desisto! Se me deixar ir,\n"
"venderei algumas " COLOR(RED) "Bombas" COLOR(DEFAULT) "!\n"
COLOR(RED) "5 peças  40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Pare com isso! Deixe-me em paz, e\n"
"eu lhe venderei " COLOR(RED) "Flechas" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 peças  70 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ok! Você venceu! Se me poupar, eu\n"
"lhe venderei uma " COLOR(RED) "Poção\n"
"Vermelha" COLOR(DEFAULT) " por " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Ok! Você venceu! Poupe-me, e eu\n"
"lhe venderei uma " COLOR(ADJUSTABLE) "Poção Verde" COLOR(DEFAULT) "\n"
"por " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O quê? Conseguiu uma fada?!\n"
"O que disse? A Grande Árvore\n"
"Deku convocou você?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O queeeeee?!"
BOX_BREAK
UNSKIPPABLE "Por que ela o chamaria e não o\n"
"grande " COLOR(RED) "Mido" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Não tem nem graça..."
BOX_BREAK
UNSKIPPABLE "Não acredito nisso!\n"
"Você nem mesmo está todo\n"
"equipado!"
BOX_BREAK
UNSKIPPABLE "Como você acha que vai ajudar a\n"
"Grande Árvore Deku sem uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) "\n"
"e um " COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) " preparados?"
BOX_BREAK
"O quê? Você está certo, eu não\n"
"tenho meu equipamento preparado,\n"
"mas...\n"
TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x2D") "Ei, o que é isso?"
BOX_BREAK
UNSKIPPABLE "Oh, você tem um " COLOR(LIGHTBLUE) "Escudo Deku" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "E o que é ISSO?!"
BOX_BREAK
UNSKIPPABLE "É a " COLOR(ADJUSTABLE) "Espada Kokiri" COLOR(DEFAULT) "?!"
BOX_BREAK
UNSKIPPABLE "BOA OFENSIVA!!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bem, mesmo com tudo isso,\n"
"um fracote ainda é um fracote, huh?" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Perdi! Venderei a você um " COLOR(RED) "Galho\n"
"Deku" COLOR(DEFAULT) " por " COLOR(RED) "15 Rupees" COLOR(DEFAULT) "." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Perdi! Venderei a você " COLOR(RED) "Nozes\n"
"Deku" COLOR(DEFAULT) " se me deixar em paz.\n"
COLOR(RED) "5 peças  20 Rupees" COLOR(DEFAULT) "." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E também..."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x02") "Sinto muito ter sido vil para ele." QUICKTEXT_DISABLE
BOX_BREAK
SHIFT("\x45") "Diga isso a ele."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hii hii hii!\n"
"Você andou tudo isso até aqui?\n"
"É um homem mesmo!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Veja! A vista não é linda?\n"
"Mude sua visão com " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", assim\n"
"poderá olhar por toda a floresta\n"
"com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você fez à Grande Árvore\n"
"Deku?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quiser ir ao Bosque Perdido,\n"
"é melhor ter o equipamento\n"
"certo!\n"
"Hii hii hii!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x82") "Todos os meus irmãozinhos\n"
"dizem...\n"
"Que você tem um rosto horrível!"
BOX_BREAK
SFX("\x38\x82") "Mas não se aflija! Nós lhe\n"
"daremos muitas " COLOR(RED) "Nozes Deku" COLOR(DEFAULT) "."
BOX_BREAK
SFX("\x38\x82") "Claro, também o faremos carregar\n"
"um número maior delas!"
BOX_BREAK
"Abracadabra..."
BOX_BREAK
SFX("\x38\x80") "Alakazaaaaaam!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo!"
BOX_BREAK
SFX("\x38\x80") "Para facilitar sua vida, farei\n"
"você carregar mais " COLOR(RED) "Galhos Deku" COLOR(DEFAULT) "!\n"
"Mas, isso vai lhe custar " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo!"
BOX_BREAK
SFX("\x38\x80") "Para facilitar a sua vida, farei\n"
"você carregar mais " COLOR(RED) "Nozes Deku" COLOR(DEFAULT) "!\n"
"Mas, isso vai lhe custar " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Que pena!\n"
"Não pode comprar isso agora!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele cara não está mais aqui."
BOX_BREAK
"Quem entra na floresta sempre\n"
"se perde."
BOX_BREAK
"Todos vão se tornar Stalfos.\n"
"Todos, Stalfos.\n"
"Por isso ele não está mais aqui."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Muito obrigado por aquele outro\n"
"dia... Eu nem mesmo perguntei o\n"
"seu nome ainda..."
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Sério?\n"
NAME "!"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Foi o que eu pensei!" QUICKTEXT_DISABLE "\n"
"É o garoto mágico da floresta!\n"
"Isso foi há anos atrás!\n"
"Você lembra de mim?"
BOX_BREAK
UNSKIPPABLE "Lembra? Tinha certeza que era\n"
"você pois Epona lembrou de você!"
BOX_BREAK
UNSKIPPABLE "Oh, tenho que lhe falar sobre\n"
"o " COLOR(RED) "Sr. Ingo" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Ele ficou com medo do Rei do Mal\n"
"descobrir que Epona fugiu...\n"
"Isso realmente o irritou!"
BOX_BREAK
UNSKIPPABLE "Mas um dia, repentinamente, ele\n"
"voltou a ser uma " COLOR(RED) "pessoa boa" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Agora meu pai está voltando...\n"
"Não posso acreditar que a paz\n"
"está retornando a este rancho!"
BOX_BREAK
UNSKIPPABLE "Isso tudo por causa de você!\n"
"Eu devo muito a você!"
BOX_BREAK
UNSKIPPABLE "Muito obrigado! Muitos obrigado,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como vai " COLOR(RED) "Epona" COLOR(DEFAULT) "?"
BOX_BREAK
"Se você tocar a " COLOR(RED) "Canção de\n"
"Epona" COLOR(DEFAULT) " com sua Ocarina, ela\n"
"certamente virá até você."
BOX_BREAK
"Por favor volte ao rancho sempre\n"
"que quiser " COLOR(RED) "treinar" COLOR(DEFAULT) " Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "está muito bem!\n"
"Parece que você conseguiu\n"
"domesticá-la também!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que tal tentar com Epona uma\n"
COLOR(RED) "corrida de obstáculos" COLOR(DEFAULT) "?"
BOX_BREAK
"Vou cronometrar você por " COLOR(RED) "duas\n"
"voltas" COLOR(DEFAULT) ". É um bom desafio. Se\n"
"errar o pulo de uma cerca, você\n"
"falhará."
BOX_BREAK
"Que tal?\n"
"Vai querer tentar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Vamos lá\n"
"Não quero fazer isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, seu tempo foi " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ". Tem\n"
"que treinar mais!"
BOX_BREAK
"Lembre-se, não precisa acelerar\n"
"para pular cercas baixas, mas\n"
"tem que ir rápido para pular\n"
"as cercas altas!    "
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME "...pode me ouvir?\n"
"Sou eu, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Muuuuuuuuuu!"
BOX_BREAK
"Que música bonita...\n"
"Ela me lembra o pasto..."
BOX_BREAK
"Essa música me faz tão bem,\n"
"posso produzir muito leite!" EVENT " "
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tome um pouco do meu fresco e\n"
"nutritivo leite!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME ", quando você segurar a\n"
"Ocarina em suas mãos..." BOX_BREAK_DELAYED("\x3C") "Não estarei mais aqui..." BOX_BREAK_DELAYED("\x3C") "Eu queria esperar por você, mas\n"
"não podia mais..." BOX_BREAK_DELAYED("\x3C") "Pelo menos eu pude deixar a\n"
"Ocarina e " COLOR(LIGHTBLUE) "esta melodia" COLOR(DEFAULT) " para\n"
"você..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Agora, " NAME ".\n"
"Toque essa melodia em frente ao\n"
"altar no Templo do Tempo. Você\n"
"deve proteger a Triforce!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uah-ha-ha-hah! Acha que está\n"
"disfarçado, Sr. Herói?"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x57") "Uh?"
BOX_BREAK
UNSKIPPABLE "É a máscara do personagem\n"
"\"Kea...algo assim...\"? Ouvi que\n"
"ele anda muito popular!"
BOX_BREAK
UNSKIPPABLE "É o favorito do meu garoto. Essa\n"
"máscara \"Kea...sei lá o quê...\"\n"
"Diga-se de passagem..." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vai vender para mim?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não vou desistir! Tenho muita\n"
"paciência. Tenho que ter para\n"
"este trabalho! Ha ha!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mmmm...grunf...grunf...\n"
"Huh? Estou acordado!"
BOX_BREAK
UNSKIPPABLE "O que?"
BOX_BREAK
UNSKIPPABLE "Ei, é você! Bem-vindo!"
BOX_BREAK
UNSKIPPABLE "Auu... ela é muito severa!\n"
"Malon gritou comigo por muito\n"
"tempo!"
BOX_BREAK
UNSKIPPABLE "Você cuidou da gente, então\n"
"tenho orgulho de lhe dar este\n"
COLOR(RED) "leite" COLOR(DEFAULT) "! Pode ficar com o\n"
"frasco."
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A " COLOR(RED) "estrada está fechada" COLOR(DEFAULT) " além\n"
"deste ponto!\n"
"Não leu a placa ali não?"
BOX_BREAK
"Hein? Oh, entendo. Você é apenas\n"
"um garoto, e ainda não sabe ler.\n"
"Ha ha hah!"
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não quero isso!"
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, esta é...\n"
"Com certeza a letra da Princesa\n"
"Zelda! Bem, deixe-me ver...\n"
"Hmmm... OK..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x06") "\"" COLOR(PURPLE) "Este é " NAME "...\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "Ele está sob as minhas ordens para\n"
COLOR(DEFAULT)  SHIFT("\x06")  COLOR(PURPLE) "salvar Hyrule." COLOR(DEFAULT) "\""
BOX_BREAK
UNSKIPPABLE "Uah ha ha ha hah!\n"
"Que jogo engraçado a Princesa\n"
"está aprontando agora?!"
BOX_BREAK
UNSKIPPABLE "OK, tudo bem. Pode ir agora...\n"
"Mas seja cuidadoso, Sr. Herói!\n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Sr. Herói!\n"
"Obrigado pelo bom trabalho!\n"
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "!!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau! Bom!\n"
"Seu tempo foi " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) "!\n"
"Você e Epona são um grande\n"
"time!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, que pena.\n"
"Se você tivesse algo para\n"
"colocá-lo dentro, eu lhe daria\n"
"um pouco..." EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sou " COLOR(RED) "Ingo" COLOR(DEFAULT) "--Sr. Ingo para você.\n"
"Tomo conta desses cavalos.\n"
"Sai da minha frente, garoto!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Além disso, Sr. Herói..."
BOX_BREAK
UNSKIPPABLE "Se vai subir a Montanha da\n"
"Morte, você precisa de um\n"
COLOR(LIGHTBLUE) "escudo apropriado" COLOR(DEFAULT) "! Pois,\n"
"de fato, é um vulcão ativo!"
BOX_BREAK
UNSKIPPABLE "Se você voltar ao Mercado de\n"
"Hyrule, cheque o bazar de lá.\n"
"Eles vendem o escudo que você\n"
"precisa."
BOX_BREAK
UNSKIPPABLE "Diga a eles que eu mandei você\n"
"lá, pode ser que eles dêem um\n"
"desconto especial!"
BOX_BREAK
UNSKIPPABLE "Se acha que já é bom para\n"
"subir, não se preocupe com isso."
BOX_BREAK
UNSKIPPABLE "Agora, gostaria de lhe pedir um\n"
"favor. Não, não espero isso de\n"
"você só por causa dessa dica que\n"
"eu lhe dei. É apenas um pedido!"
BOX_BREAK
UNSKIPPABLE "Você foi à " COLOR(RED) "Loja Máscara\n"
"Feliz" COLOR(DEFAULT) " que abriu no Mercado da\n"
"Cidade do Castelo de Hyrule? Todo\n"
"mundo anda falando dela agora!"
BOX_BREAK
UNSKIPPABLE "Meu garotinho vive me aperreando\n"
"por uma máscara popular, mas eu\n"
"não tenho tempo para ir lá..."
BOX_BREAK
UNSKIPPABLE "Então, você poderia ir e\n"
"trazer a máscara para mim? Se não\n"
"se interessar, tudo bem, mas..."
BOX_BREAK
UNSKIPPABLE "Bem, não tenho escolha, é o\n"
"meu trabalho..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x39") "...(suspiros)..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu desejo poder ir à " COLOR(RED) "Loja de\n"
"Máscaras" COLOR(DEFAULT) " comprar um presente\n"
"para meu garoto..."
BOX_BREAK
SHIFT("\x4B") "  ..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Oh não... parou de respirar..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x29") "Arrrrgh!" QUICKTEXT_DISABLE " Eu a perdi!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x49") "Você, aí!\n"
SHIFT("\x46")  QUICKTEXT_ENABLE "Garotinho!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3C")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1C") "Quer um pedaço de mim?!\n"
SHIFT("\x45") "Engraçado!\n"
SHIFT("\x26") "Gosto de sua atitude!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x25") "Pequeno tolo patético!" QUICKTEXT_DISABLE "\n"
SHIFT("\x13") "Você percebe com quem está\n"
SHIFT("\x4B") "lidando?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x33") "Eu sou " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x0B") "E em breve, dominarei o mundo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x04") "Você viu o cavalo branco correndo\n"
SHIFT("\x36") "agora há pouco...\n"
SHIFT("\x20") "Em que direção ele foi?!\n"
SHIFT("\x3C")  QUICKTEXT_ENABLE "Responda-me!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tss Tss... Quando seu tempo\n"
"acabar, vou bani-lo daqui."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu garoto vai ficar muito feliz!\n"
"Você é realmente o Sr. Herói!\n"
"Uah ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Você vendeu a máscara de 10\n"
"Rupees por " COLOR(RED) "15 Rupees" COLOR(DEFAULT) ". Teve\n"
"um pequeno lucro."
BOX_BREAK
UNSKIPPABLE "Vamos à Loja de Máscaras e pagar\n"
"de volta o preço de " COLOR(RED) "10 Rupees" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Garotinhos não podem fazer o\n"
"\"" COLOR(RED) "Assustador Passeio Cava-Cova" COLOR(DEFAULT) "\"\n"
"descrito na placa."
BOX_BREAK
"Como eu não posso, simplesmente\n"
"fico imitando Dampé o Coveiro\n"
"todos os dias."
BOX_BREAK
"Mas com meu bonito rosto, não\n"
"sou assustador realmente, não é?"
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baaah!" QUICKTEXT_DISABLE " É Dampé o coveiro!"
BOX_BREAK
SHIFT("\x57") "???"
BOX_BREAK
"Oh, é só uma máscara. Tive um\n"
"tipo diferente de susto dessa\n"
"máscara em relação a Dampé..."
BOX_BREAK
"Você vai me dar essa máscara?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Sem chance" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu tenho algum dinheiro, você\n"
"sabe."
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei! Tempo esgotado, jovem!\n"
"Você só pagou 10 Rupees!\n"
"E já jogou o suficiente!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Com esta máscara, eu serei como\n"
"Dampé!\n"
"Tome meu dinheiro!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "Você vendeu uma máscara de 30\n"
"Rupees a um garoto pelo preço\n"
"inteiro?! E ele pagou tudo!"
BOX_BREAK
UNSKIPPABLE "Vamos voltar à loja de máscaras\n"
"e pagar " COLOR(RED) "30 Rupees" COLOR(DEFAULT) ". Você\n"
"pode pegar também o novo modelo\n"
"de máscara."
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vou cavar e cavar!\n"
"Assim como Dampé!!"
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Antigamente, eu ouvi que havia\n"
"muitos coelhos selvagens em\n"
"Hyrule. Mas acabaram, devido à\n"
"caça excessiva."
BOX_BREAK
"Eu quero me tornar um coelho...\n"
"Ouvir o vento com aquelas\n"
"orelhas, pular pelos campos com\n"
"aquelas pernas..."
BOX_BREAK
"Mesmo se eu apenas puder fingir.     "
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aposto que com essas longas\n"
"orelhas você possa ouvir vozes...\n"
"Oh, essas são orelhas de coelho\n"
"genuínas da lenda!" TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não me importa o custo! Por\n"
"favor me venda!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Sem chance" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não é a resposta que eu queria\n"
"ouvir!"
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu sonho de tanto tempo!\n"
"Voltando à vida selvagem! Enfim,\n"
"o ator, o palco e a platéia\n"
"unidos!" EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x48\x07") "É uma máscara de 50 Rupees, mas\n"
"ele pagou muito mais dinheiro do\n"
"que você possa contar!"
BOX_BREAK
UNSKIPPABLE "Volte à Loja de Máscaras e pague\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) " deste dinheiro.             "
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x09") "Então, acha que pode protegê-las\n"
SHIFT("\x49") "de mim...\n"
SHIFT("\x28") "Tem coragem, garoto."
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Algumas pessoas em Kakariko estão\n"
"espalhando rumores de que eu\n"
"enganei Talon, mas..."
BOX_BREAK
UNSKIPPABLE "-Não seja " QUICKTEXT_ENABLE "ridículo!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Aquele Talon é um fraco!\n"
"Eu, o esforçado " COLOR(RED) "Ingo" COLOR(DEFAULT) ", despejei\n"
"tanta energia neste lugar!"
BOX_BREAK
UNSKIPPABLE "Não quero estranhos como você\n"
"dizendo nada de ruim sobre mim!"
BOX_BREAK
UNSKIPPABLE "Ouça. O " COLOR(RED) "Grande Ganondorf" COLOR(DEFAULT) "\n"
"reconheceu meus óbvios talentos e\n"
"me deu o rancho!"
BOX_BREAK
UNSKIPPABLE "Eu vou criar um belo cavalo para\n"
"ganhar o reconhecimento do grande\n"
"Ganondorf!"
BOX_BREAK
UNSKIPPABLE "Diga, jovem, você quer montar\n"
"algum dos meus excelentes\n"
"cavalos?" TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pague-me " COLOR(RED) "10 Rupees" COLOR(DEFAULT) " e poderá\n"
"montar.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ok então, até mais\n"
"pequeno rebelde!"
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não tem o suficiente!\n"
"Economize mais e volte\n"
"outra hora!"
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer ouvir como montar?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ouvir\n"
"Não ouvir" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aproxime-se de um cavalo e fique\n"
"do seu lado. Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"montar."
BOX_BREAK
"Use o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para fazê-lo correr.\n"
"Quando começar a correr, aperte\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " para chicoteá-lo. Isso o fará\n"
"acelerar!"
BOX_BREAK
"Quando quiser pular sobre uma\n"
"cerca, acelere e vá de frente\n"
"para ela!"
BOX_BREAK
"Se tentar pular de forma inclinada,\n"
"o cavalo não vai gostar, e não\n"
"vai pular."
BOX_BREAK
"Depois que o cavalo parar\n"
"completamente, aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"desmontar. Agora, divirta-se!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se usar " COLOR(LIGHTBLUE) "[Z] mirando" COLOR(DEFAULT) ", poderá\n"
"falar comigo sobre o cavalo."
BOX_BREAK
"Está pronto para ir para\n"
"casa?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Não, eu quero montar.\n"
"Sim, quero ir." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando quiser desmontar, pare e\n"
"aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
"Ei jovem!\n"
"Eu conheço você? Achei que eu já\n"
"o tinha visto antes em algum\n"
"lugar..." TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está melhorando!\n"
"Que tal uma corridinha comigo?\n"
"Uma volta ao redor do curral com\n"
"esse cavalo."
BOX_BREAK
"Vamos fazer uma pequena aposta\n"
"de " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei ei...Qual o problema?\n"
"Você não tem nem 50 Rupees?!\n"
"Eu não quero uma corrida com\n"
"alguém tão pobre!"
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x39") "Dr-" QUICKTEXT_ENABLE "ooooga!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Se o grande Ganondorf souber\n"
"dessa humilhação...\n"
"Ei, você!! Que tal uma outra\n"
"corrida! Se vencer..."
BOX_BREAK
UNSKIPPABLE "Você pode ficar com...o cavalo!!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que há com esse cavalo?!\n"
"É " COLOR(RED) "Epona" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Como você a domesticou bem\n"
"embaixo do meu nariz?!"
BOX_BREAK
UNSKIPPABLE "Eu ia presentear esse cavalo ao\n"
"grande Ganondorf... Mas apostei\n"
"na corrida e perdi! Droooga!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x36") "Ha ha ha!"
BOX_BREAK
UNSKIPPABLE "Como prometi, vou lhe dar o\n"
"cavalo..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x0A") "Entretanto..."
BOX_BREAK
UNSKIPPABLE "Eu nunca deixarei você sair\n"
"deste rancho!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi... Que pena! Eu peguei\n"
"seus 50 Rupees." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uah ha ha!\n"
"Você é só um garoto mesmo!\n"
"Bem, volte outra hora e nós\n"
"teremos mais divertimentos..."
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O que? O que está fazendo\n"
"rondando por aqui? Seu idiota!"
BOX_BREAK
UNSKIPPABLE "Eu sou " COLOR(RED) "Ingo" COLOR(DEFAULT) " e comando o rancho."
BOX_BREAK
UNSKIPPABLE "Eu trabalhei neste rancho muito\n"
"tempo para aquele vagabundo\n"
"preguiçoso, Talon."
BOX_BREAK
UNSKIPPABLE "Hoje, por exemplo, ele foi para\n"
"uma entrega não sei onde e ainda\n"
"não voltou!"
BOX_BREAK
UNSKIPPABLE "Por isso estou fazendo todo o\n"
"trabalho por aqui." TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh bem...É duro ser um\n"
"trabalhador."
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, suas roupas! Elas são...\n"
"diferentes...\n"
"Você não é das redondezas,\n"
"não é?"
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........." TEXT_SPEED("\x00") "........"
BOX_BREAK
UNSKIPPABLE "Oh... Você é um garoto da\n"
"floresta! Meu nome é " COLOR(RED) "Malon" COLOR(DEFAULT) "!\n"
"Meu pai é dono do Rancho Lon Lon!" TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Papai foi ao castelo entregar\n"
"leite e ainda não voltou..."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você está indo ao castelo,\n"
"garoto?\n"
"Importaria-se de achar o meu\n"
COLOR(RED) "pai" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE  SFX("\x68\x6D") "Ele deve ter adormecido em\n"
"algum lugar do castelo.\n"
"Que \"coisa\" para um adulto fazer!\n"
"Hii hii!"
BOX_BREAK
UNSKIPPABLE "E, se for procurar por ele, eu lhe\n"
"darei isto."
BOX_BREAK
UNSKIPPABLE "Eu estava incubando este ovo\n"
"com muito cuidado...\n"
"Hi hi!" EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Coloque o ovo em " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para\n"
"chocá-lo. Hi hi!"
BOX_BREAK
"Meu pai é mesmo problemático para\n"
"um adulto, não é?!\n"
"Hi hi!"
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não posso acreditar que eu, o\n"
"grande " COLOR(RED) "Ingo" COLOR(DEFAULT) ", estou trabalhando\n"
"no lixão do rancho!"
BOX_BREAK
UNSKIPPABLE "Por causa da preguiça do dono, eu\n"
"sempre tenho que fazer tudo aqui!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu, o esforçado " COLOR(RED) "Ingo" COLOR(DEFAULT) ", deveria\n"
"estar no comando, e não aquele\n"
"vagabundo!"
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, é o garoto da floresta de\n"
"novo!"
BOX_BREAK
"Soube que achou o meu pai!\n"
"Gostou do castelo? Você viu a\n"
"Princesa? hi hi!"
BOX_BREAK
UNSKIPPABLE  SFX("\x68\x6D") "Papai veio para casa correndo\n"
"depois que você o encontrou.\n"
"Hi hi!"
BOX_BREAK
UNSKIPPABLE "Oh sim, tenho que apresentá-lo à\n"
"minha amiga!"
BOX_BREAK
UNSKIPPABLE "Ela é essa égua. Seu nome é\n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". Ela não é linda?      "
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que Epona tem medo de\n"
"você..."
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Minha mãe compôs essa canção.\n"
"Não é linda? Vamos cantar juntos."
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Epona! Ela se apaixonou por\n"
"você."
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "..."
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...um visitante!\n"
"Faz um bom tempo que tivemos um\n"
"visitante aqui...\n"
"De onde você vem?"
BOX_BREAK
"Desde que Ganondorf veio, as\n"
"pessoas da Cidade do Castelo se\n"
"foram, tudo foi arruinado, e\n"
"monstros estão por toda parte."
BOX_BREAK
"O Sr. Ingo está usando o rancho\n"
"para ganhar benefícios de\n"
"Ganondorf..."
BOX_BREAK
"Todos parecem estar se tornando\n"
"maus..."
BOX_BREAK
"E Papai...\n"
"Foi expulso do rancho pelo\n"
"Sr. Ingo..."
BOX_BREAK
"Se eu desobedecer ao Sr. Ingo,\n"
"ele tratará os cavalos muito\n"
"mal..."
BOX_BREAK
"Não há nada que eu possa fazer..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aposto que ninguém é mais rápido\n"
"que eu agora! Mas, não sei se\n"
"fico feliz ou triste..."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "Z Z Z Z Z Z Z Z Z Z Z Z Z" TEXT_SPEED("\x00") "...\n"
"P-aare essa música...eu...\n"
"Grunf... grunf..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dê uma boa olhada naquela\n"
"montanha. É a " COLOR(RED) "Montanha da Morte" COLOR(DEFAULT) ",\n"
"casa dos Gorons. Eles possuem\n"
"a Pedra Espiritual do Fogo."
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor mantenha segredo do\n"
"Sr. Ingo eu cantei essa canção!"
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você...\n"
"Conhece a " COLOR(RED) "canção da minha mãe" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Todo mundo gosta dessa canção...\n"
"Meu pai... Até o Sr. Ingo..."
BOX_BREAK
UNSKIPPABLE "Mas...desde que Ganondorf\n"
"apareceu, o Sr. Ingo mudou."
BOX_BREAK
UNSKIPPABLE "Posso lembrar dos bons e velhos\n"
"dias quando canto essa canção.\n"
"Mas..." TEXTID("\x20\x52")
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Epona" COLOR(DEFAULT) " realmente gostou da\n"
"música... Apenas eu domestiquei\n"
"aquela égua... Até o Sr. Ingo\n"
"teve dificuldades..."
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"O olhar fixo dessa estátua\n"
"penetra em sua mente..."
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Respondendo à sua máscara, essa\n"
"estranha estátua de pedra fala\n"
"com você..."
BOX_BREAK
"Vejamos..."
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu vou virar a página e trabalhar\n"
"muito duro daqui para frente."
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O Sr. Ingo... Deve ter sido\n"
"tentado por forças do mal. Na\n"
"verdade ele não é uma má\n"
"pessoa..."
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z Z Z Z...\n"
"Grunf... Não é fácil ser um\n"
"trabalhador..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Faz um bom tempo...\n"
"Quer correr?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se mudar de idéia, volte\n"
"a qualquer hora!"
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem então,\n"
"seu pequeno rebelde!" EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"He he... Você está bravo porque\n"
"perdeu? Se está tão chateado,\n"
"que tal uma outra corrida?"
BOX_BREAK
"Aposta " COLOR(RED) "50 Rupees" COLOR(DEFAULT) " de novo?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Sem chance" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito obrigado. He he he!" EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu der mais desconto a você,\n"
"Ingo ficará bravo comigo. Então\n"
"é melhor vender a você pelo\n"
"preço normal."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer comprar leite por\n"
COLOR(RED) "30 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá, como vai você?\n"
"Eu sou Ingo. Sinto-me honrado de\n"
"poder trabalhar aqui."
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Você é bravo...\n"
"Devemos proteger esta bela terra\n"
"de Hyrule!"
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, bela ocarina!\n"
"Você vai tocar essa canção com\n"
"a ocarina?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No pé da Montanha da Morte você\n"
"encontrará minha vila, " COLOR(RED) "Kakariko" COLOR(DEFAULT) ".\n"
"É onde eu nasci e cresci."
BOX_BREAK
UNSKIPPABLE "Fale com os moradores de lá\n"
"antes de subir a Montanha da\n"
"Morte.                  "
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A canção que eu acabei de lhe\n"
"ensinar tem poderes misteriosos.\n"
"Apenas os membros da Família\n"
"Real podem aprender essa canção."
BOX_BREAK
UNSKIPPABLE "Lembre-se, ela ajudará a provar\n"
"a sua conexão com a Família\n"
"Real."
BOX_BREAK
UNSKIPPABLE "A Princesa vai esperar o seu\n"
"retorno ao castelo com as pedras.\n"
"Tudo bem. Estamos contando com\n"
"você!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hoo hoot!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Aqui em cima!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Parece que finalmente chegou\n"
"a hora de você iniciar a sua\n"
"aventura!"
BOX_BREAK
UNSKIPPABLE "Você encontrará muito sofrimento\n"
"adiante... Esse é o seu destino.\n"
"Não desanime, mesmo durante os\n"
"momentos mais difíceis!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vá em frente neste caminho e você\n"
"verá o " COLOR(RED) "Castelo de Hyrule" COLOR(DEFAULT) "."
BOX_BREAK
"Lá irá encontrar uma " COLOR(RED) "princesa" COLOR(DEFAULT) "..."
BOX_BREAK
"Se ficar perdido e não souber\n"
"para onde ir, olhe no " COLOR(RED) "Mapa" COLOR(DEFAULT) "."
BOX_BREAK
"As áreas que você explorou serão\n"
"mostradas no Mapa. Aperte " COLOR(RED) "START" COLOR(DEFAULT) "\n"
"para entrar nas Subtelas e " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou\n"
COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para achar o Mapa."
BOX_BREAK
"Na " COLOR(RED) "Subtela do Mapa" COLOR(DEFAULT) ", você\n"
"também verá um " COLOR(RED) "ponto piscando" COLOR(DEFAULT) "\n"
"mostrando a você o próximo\n"
"caminho a seguir." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você entendeu tudo?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Não\n"
"Sim" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tudo bem então, vejo você por aí!\n"
"Hoot hoot hoot hoot!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, " NAME "! Por aqui!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "A princesa está dentro do\n"
"castelo em frente. Tome cuidado\n"
"para não ser pego pelos guardas!\n"
"Ho ho ho hoot!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Neste local o tempo passa\n"
"normalmente."
BOX_BREAK
"Mas o tempo pára enquanto você\n"
"está em alguma cidade."
BOX_BREAK
"Se quiser que o tempo passe\n"
"normalmente, você precisa sair\n"
"da cidade."
BOX_BREAK
"Bem, bem, para onde você está\n"
"indo agora?\n"
"Hoo hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer ouvir de novo o que eu\n"
"disse?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hooo. Você é um garoto esperto.\n"
"Boa sorte, então."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, " NAME "!\n"
"Espere um segundo, amigo!"
BOX_BREAK
"Além deste ponto você encontra\n"
"a " COLOR(RED) "Vila Kakariko" COLOR(DEFAULT) ". Você já\n"
"viu a Princesa de Hyrule? Se não,\n"
"eu sugiro-lhe ir para o castelo." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, " NAME "!\n"
"Olhe para cá!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Além deste ponto você encontra\n"
"a " COLOR(RED) "Vila Kakariko" COLOR(DEFAULT) ". Preste\n"
"Atenção!\n"
"Hoot hoo!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", você é o único\n"
"que pode completar esta\n"
"aventura!\n"
"Faça o melhor que puder! Hoo!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "! Espere, amigo!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28") "Vá daqui ao sul para chegar\n"
"às abundantes águas do " COLOR(RED) "Lago Hylia" COLOR(DEFAULT) "."
BOX_BREAK
"Se for a oeste, encontrará o\n"
COLOR(RED) "Vale Gerudo" COLOR(DEFAULT) ". Há um esconderijo\n"
"de uma gangue de ladras do outro\n"
"lado do vale."
BOX_BREAK
"Bem, você é livre para ir\n"
"para qualquer lugar que quiser!\n"
"Ho ho hoo!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não importa o quão difícil seja,\n"
"é só não desanimar. Ho Ho Hoo!"
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Além deste ponto fica o Lago Hylia.\n"
"É cheio de água pura." BOX_BREAK_DELAYED("\x28") "Os " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", que vivem todos rio acima,\n"
"guardam o templo submerso no fundo\n"
"do lago, conhecido como a\n"
"Fonte de Zora."
BOX_BREAK
"Se você quiser confirmar sua\n"
"localização no mapa, aperte " COLOR(RED) "START" COLOR(DEFAULT) "\n"
"para ir às Subtelas e " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou\n"
COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para encontrar o mapa."
BOX_BREAK
"Todos os locais já visitados serão\n"
"mostrados no mapa.\n"
"Hoo hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, fique atento e vá!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Qual é o seu nome?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Estranho...parece um tanto...\n"
"familiar." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK então, " NAME "."
BOX_BREAK
UNSKIPPABLE "Eu vou contar a você o segredo do\n"
"Reino Sagrado que foi passado por\n"
"gerações pela Família Real de\n"
"Hyrule." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x26") "A Ocarina do Tempo! " EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Entendeu bem a história que\n"
"acabei de contar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eu estava espiando por esta janela\n"
"agora..."
BOX_BREAK
UNSKIPPABLE "O outro elemento do meu sonho...\n"
"as " COLOR(BLUE) "nuvens negras" COLOR(DEFAULT) "... Acredito\n"
"que simbolizem... aquele homem lá\n"
"dentro!"
BOX_BREAK
"Você vai olhar para ele pela\n"
"janela?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Sim."
BOX_BREAK
UNSKIPPABLE "Eu disse a meu pai sobre o sonho..."
BOX_BREAK
UNSKIPPABLE "Porém, ele não acreditou que\n"
"era uma profecia..."
BOX_BREAK
UNSKIPPABLE "Mas sinto as más intenções\n"
"daquele homem!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que Ganondorf procura deve ser\n"
"nada menos que a " COLOR(RED) "Triforce" COLOR(DEFAULT) " do\n"
"Reino Sagrado."
BOX_BREAK
UNSKIPPABLE "Ele deve ter vindo a Hyrule\n"
"para obtê-la!"
BOX_BREAK
UNSKIPPABLE "E além disso, ele quer conquistar\n"
"Hyrule...\n"
"Não, o mundo inteiro!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...agora, somos os únicos\n"
"que podem proteger Hyrule! " EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Não podemos deixar Ganondorf pegar\n"
"a Triforce!"
BOX_BREAK
UNSKIPPABLE "Eu vou proteger a " COLOR(LIGHTBLUE) "Ocarina do Tempo" COLOR(DEFAULT) "\n"
"com todo o meu poder!\n"
"Ele não a terá!"
BOX_BREAK
UNSKIPPABLE "Vá encontrar as outras " COLOR(RED) "duas\n"
"Pedras Espirituais" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Pegaremos a Triforce antes de\n"
"Ganondorf, para então derrotá-lo! " EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Mais uma coisa...\n"
"Pegue esta " COLOR(RED) "carta" COLOR(DEFAULT) "...\n"
"Certamente será útil para você." EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Grunf...grunf...\n"
"Huh? Já estou acordado!"
BOX_BREAK
UNSKIPPABLE "Que?"
BOX_BREAK
UNSKIPPABLE "Bem, olha só! Se não é o garoto\n"
"da floresta do outro dia!\n"
"A propósito, muito obrigado por\n"
"me acordar!"
BOX_BREAK
UNSKIPPABLE "Deu-me trabalho, mas finalmente\n"
"consegui trazer o bom humor de volta\n"
"a Malon."
BOX_BREAK
UNSKIPPABLE "Então, o que vai fazer hoje?\n"
"Você tem um tempinho livre?\n"
"Bem, que tal um joguinho agora?"
BOX_BREAK
UNSKIPPABLE "Estes três Cuccos que tenho\n"
"aqui são " COLOR(RED) "Super Cuccos" COLOR(DEFAULT) " especiais!"
BOX_BREAK
UNSKIPPABLE "Eu vou jogá-los naquele monte\n"
"de Cuccos normais."
BOX_BREAK
UNSKIPPABLE "Se você conseguir pegar esses três\n"
"cuccos especiais no meio dos cuccos\n"
"normais dentro do limite de tempo,\n"
"eu darei a você uma " COLOR(RED) "coisa boa" COLOR(DEFAULT) "."
BOX_BREAK
"Se não encontrá-los, eu ganho.\n"
"Custa 10 Rupees... Quer jogar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grunf...grunf...\n"
"Estou de pé!"
BOX_BREAK
"O que?"
BOX_BREAK
"Ei, garoto da floresta!\n"
"Conseguiu um tempo livre?\n"
"Então venha e jogue!"
BOX_BREAK
"Eu jogarei estes três\n"
COLOR(RED) "Super Cuccos" COLOR(DEFAULT) " naquele monte de\n"
"cuccos normais."
BOX_BREAK
"Se você pegar os três cuccos\n"
"especiais no meio dos cuccos normais\n"
"dentro do tempo limite, vou lhe\n"
"dar " COLOR(RED) "algo bom" COLOR(DEFAULT) "."
BOX_BREAK
"Se não encontrá-los, eu ganho.\n"
"Custa 10 Rupees... Quer jogar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem 30 segundos!\n"
"Ok então, prepare-se.\n"
"Aí vão os Super Cuccos!"
BOX_BREAK
SHIFT("\x29") "COMECE A PROCURAR!!" EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"O tempo acabou!\n"
"Muito ruim!!"
BOX_BREAK
"Eles são grandes Cuccos, não\n"
"são! Estão juntando dinheiro para\n"
"mim!"
BOX_BREAK
"Voltem aqui, meus bebês!" EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"É um deles!\n"
"Continue assim! Ainda tem\n"
COLOR(RED) "mais dois" COLOR(DEFAULT) " para achar!" EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"É outro!\n"
"Tudo bem, agora, a hora da\n"
"verdade! " COLOR(RED) "Mais um " COLOR(DEFAULT) "para achar!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Deus! Que maldição!\n"
"Isto é incrível!"
BOX_BREAK
"É o último!\n"
"Você encontrou todos!\n"
"Agora venha até aqui!" EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer tentar novamente?"
BOX_BREAK
"Um jovem como você deve ter um\n"
"verdadeiro fogo em seu ventre!\n"
"Ache os três em 30 segundos."
BOX_BREAK
"Que tal por 5 Rupees?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você!\n"
"Você tem talento para ser um dos\n"
"melhores vaqueiros do mundo!"
BOX_BREAK
"Quer se casar com Malon?\n"
"Huh?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ha ha! Eu estava só brincando!\n"
"Só brincando! Acho que é um\n"
"pouco jovem para isso, não é?\n"
"Ha ha ha ha!"
BOX_BREAK
UNSKIPPABLE "Oh...! Estou orgulhoso de\n"
"presenteá-lo com uma amostra do\n"
"nosso " COLOR(RED) "Leite Lon Lon" COLOR(DEFAULT) ". Você ficará\n"
"energizado assim que o beber!"
BOX_BREAK
UNSKIPPABLE "Após bebê-lo, você pode trazer\n"
"o " COLOR(RED) "frasco " COLOR(DEFAULT) "e comprar mais\n"
"quando quiser!" EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, sócio, você tem uma cara\n"
"honesta!"
BOX_BREAK
"Quando crescer, porque você não\n"
"vem trabalhar aqui, neste rancho?\n"
"É uma oferta permanente!\n"
"Vou espera por você." EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aí vai! Tome este super " COLOR(RED) "Leite\n"
"Lon Lon" COLOR(DEFAULT) " puro!" EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aí vai! Tome este super leite\n"
"puro..."
BOX_BREAK
"Oh? É uma pena!!\n"
"Você não tem um frasco vazio,\n"
"não é?"
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grunf...grunf...\n"
"Estou acordado!"
BOX_BREAK
"O que?"
BOX_BREAK
"Ei, " NAME "!\n"
"Se está procurando por Malon,\n"
"ela está lá fora. Você veio aqui\n"
"para jogar?"
BOX_BREAK
"Bem então, que tal jogar o\n"
COLOR(RED) "Super Encontra-Cucco" COLOR(DEFAULT) " comigo?\n"
"Ou você quer comprar " COLOR(RED) "Leite\n"
"Lon Lon" COLOR(DEFAULT) "?"
BOX_BREAK
"O que vai ser?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Leite Lon Lon - 30 Rupees\n"
"Encontra-Cucco - 10 Rupees\n"
"Sair" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Você falhou!" COLOR(DEFAULT) "\n"
"Você tem que pular todas as\n"
"cercas! " QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE  COLOR(RED) "Mais uma vez!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem certeza que está chegando às\n"
"cercas de frente? Se chegar em\n"
"ângulo errado, o cavalo não pulará!"
BOX_BREAK
"Se quiser tentar novamente,\n"
"monte Epona e prepare-se!"
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você conseguiu!\n"
COLOR(RED)  RACE_TIME  COLOR(DEFAULT) " é o novo recorde da pista!"
BOX_BREAK
UNSKIPPABLE "Darei um presente a você para\n"
"comemorar seu recorde!"
BOX_BREAK
UNSKIPPABLE "O presente é um pouco pesado\n"
"para lhe dar aqui, então vou\n"
"entregá-lo em sua casa. Aposto que\n"
"não pode esperar para vê-lo! Hi hi hi!"
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O recorde é " COLOR(RED) "50 segundos" COLOR(DEFAULT) ".\n"
"Seu melhor tempo é " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "."
BOX_BREAK
"Se você bater o recorde, eu\n"
"lhe darei um presente.\n"
"Dê o melhor de si, OK?"
BOX_BREAK
"Vamos lá!" EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu melhor tempo é " COLOR(RED)  HIGHSCORE(HS_HORSE_RACE)  COLOR(DEFAULT) "!\n"
"Quão rápido pode ir?!\n"
"Venha, vamos começar!" EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O recorde atual é " COLOR(RED) "50 segundos" COLOR(DEFAULT) ".\n"
"Primeiro, tente bater este recorde!"
BOX_BREAK
"Se bater o recorde, eu lhe darei\n"
"um presente!\n"
"Dê o melhor de si, OK?"
BOX_BREAK
"Tudo bem, vamos começar!" EVENT
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
UNSKIPPABLE "Você não sabe o que ele quer\n"
"dizer com \"Irmãos de Juramento\",\n"
"mas você coletou duas Pedras\n"
"Espirituais! Falta uma ainda!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você não sabe o que ele quer\n"
"dizer com \"Irmãos de Juramento\",\n"
"mas finalmente coletou as três\n"
"Pedras! Volte para ver a Princesa!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu fiiiz isssto...\n"
"Trrroque pelo " COLOR(RED) "commmprovante" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu te dooou isssto commmo\n"
"um souveniiiiirrrrrrrr."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto, eu gosto de você!"
BOX_BREAK
UNSKIPPABLE "Que tal nos tornarmos Irmãos\n"
"de Juramento?!"
BOX_BREAK
UNSKIPPABLE "Não, não há nenhuma cerimônia!\n"
"Pegue isto como símbolo de\n"
"nossa amizade!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x30") "Espetacular!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que tal um abração Goron,\n"
"brother?" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "Oh!" BOX_BREAK_DELAYED("\x1E")  SHIFT("\x4B") "Oh-oh!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x4B")  QUICKTEXT_ENABLE "Venha!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x14") "Vamos! Vamos!\n"
"Vamos!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x50")  QUICKTEXT_ENABLE "BOM!!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x1E")  SHIFT("\x28") "Que batida boa! " BOX_BREAK_DELAYED("\x28")  SHIFT("\x32") "UUUUUUUH!" BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YEEEEAH!" QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x28")  SHIFT("\x3C")  QUICKTEXT_ENABLE "YAHOOO!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu sou um dos " COLOR(RED) "Gorons" COLOR(DEFAULT) ",\n"
"o povo come-pedra que vive na\n"
"Montanha da Morte."
BOX_BREAK
UNSKIPPABLE "Olhe para aquela grande pedra\n"
"ali!"
BOX_BREAK
UNSKIPPABLE "Ela bloqueia a entrada da\n"
COLOR(RED) "Caverna dos Dodongos" COLOR(DEFAULT) ", que\n"
"já foi um local muito importante\n"
"para nós, Gorons..."
BOX_BREAK
UNSKIPPABLE "Mas um dia, muitos Dodongos\n"
"apareceram repentinamente na\n"
"caverna. Ela se tornou um local\n"
"perigosíssimo!"
BOX_BREAK
UNSKIPPABLE "Nisso, um " COLOR(RED) "Gerudo em armadura\n"
"negra" COLOR(DEFAULT) " usou sua mágica para\n"
"selar a entrada com essa pedra!" TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu queria rolar montanha abaixo\n"
"como uma rocha, com uma " COLOR(RED) "Flor\n"
"Bomba" COLOR(DEFAULT) " e..."
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x41") "BOOOOM!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
"Se eu pudesse fazer isso com\n"
"uma Flor Bomba, eu seria um\n"
"homem de verdade."
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou aqui para cobrir as " COLOR(RED) "\n"
"Flores Bomba" COLOR(DEFAULT) " do sol."
BOX_BREAK
"Você tem alguma pergunta a fazer?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sobre as Flores Bomba\n"
"Sobre a caverna dos Dodongos" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essas plantas crescendo ali são\n"
COLOR(RED) "Flores Bomba" COLOR(DEFAULT) ". Elas são\n"
"\"plantas minadas\" que crescem só\n"
"nesta montanha."
BOX_BREAK
"A fruta da flor é o puro material\n"
"para bombas. Mas um novato\n"
"não-Goron nunca deve pegar a\n"
"fruta das Flores Bomba!"
BOX_BREAK
"Elas crescem apenas em lugares\n"
"escuros, e Flores Bomba que\n"
"crescem num local como este são\n"
"extremamente raras."
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essas plantas crescendo ali são\n"
COLOR(RED) "Flores Bomba" COLOR(DEFAULT) ". Elas são\n"
"\"plantas minadas\" que crescem só\n"
"nesta montanha."
BOX_BREAK
"Elas crescem apenas em lugares\n"
"escuros, como cavernas, então\n"
"Flores Bomba que crescem num\n"
"local como este são muito raras."
BOX_BREAK
"Em poder do " COLOR(RED) "Bracelete Goron" COLOR(DEFAULT) ",\n"
"até um garotinho como você pode\n"
"facilmente pegá-las com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu a caverna quando vinha\n"
"para cá? Ela é a " COLOR(RED) "Caverna dos\n"
"Dodongos" COLOR(DEFAULT) "."
BOX_BREAK
"Como a luz lá dentro é muito\n"
"fraca, as " COLOR(RED) "Flores Bomba" COLOR(DEFAULT) ", uma\n"
"planta única desta montanha,\n"
"crescem bastante lá dentro!"
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh?"
BOX_BREAK
UNSKIPPABLE "Não temos muitos visitantes aqui\n"
"em cima. De onde você é?"
BOX_BREAK
UNSKIPPABLE "Da floresta?"
BOX_BREAK
UNSKIPPABLE "O que é uma \"floresta\"?"
BOX_BREAK
UNSKIPPABLE "É? " UNSKIPPABLE "É onde muitas \"árvores\" e\n"
"\"plantas\" crescem?"
BOX_BREAK
UNSKIPPABLE "Agora estou ainda mais confuso!\n"
"Nada cresce por aqui além das\n"
COLOR(RED) "Flores Bomba" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Não temos \"sementes\" ou \"nozes\"\n"
"por aqui também."
BOX_BREAK
UNSKIPPABLE "Até Galhos Deku são muito\n"
"escassos por aqui!" TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu fechei a entrada porque não\n"
"tinha muitas coisas para vender.\n"
"Mas você é um consumidor bem\n"
"persistente, não é?" EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Lamento...\n"
"Essa bomba é só para exposição.\n"
"Eu " COLOR(RED) "vendi" COLOR(DEFAULT) " as verdadeiras." EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por que você me parou?\n"
"Não me pare aqui!"
BOX_BREAK
"Você não pode parar meu rolamento\n"
"selvagem!"
BOX_BREAK
"Este é o único jeito de aliviar\n"
"o meu estresse!"
BOX_BREAK
"Agora sai da frente do meu\n"
"rolamento!!"
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tudo bem! Eu lhe darei isto\n"
"pela sua coragem!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado! Deixe-me mostrar o meu\n"
"prazer nos rolamentos!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x21") "Oh...Estou faminto..."
BOX_BREAK
UNSKIPPABLE "Todos se sentem abatidos de\n"
"fome por causa da pouca comida\n"
"nesta cidade. Nós estamos em\n"
"perigo de extinção!"
BOX_BREAK
UNSKIPPABLE "Tudo porque não podemos entrar\n"
"em nossa mina, a " COLOR(RED) "Caverna dos\n"
"Dodongos" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Nós vivemos numa dieta\n"
"de pedras..."
BOX_BREAK
UNSKIPPABLE "E as mais deliciosas e\n"
"nutritivas pedras são encontradas\n"
"na Caverna dos Dodongos! Mas isso\n"
"parece uma antiga história..."
BOX_BREAK
UNSKIPPABLE "Nós nos tornamos gourmets que\n"
"não mais suportam comer rochas\n"
"de nenhum lugar além deste!" TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah! Quero comer umas boas\n"
"almôndegas de pedra da\n"
COLOR(RED) "Caverna dos Dodongos" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei!"
BOX_BREAK
UNSKIPPABLE "É perigoso para um garotinho como\n"
"você vir aqui. Você pode\n"
"cair!"
BOX_BREAK
UNSKIPPABLE "Se não me engano, você veio\n"
"aqui para comer a " COLOR(RED) "pedra\n"
"vermelha" COLOR(DEFAULT) "! Bem, é uma pena!\n"
"Ela não está aqui!"
BOX_BREAK
UNSKIPPABLE "Que? Não é por isso que\n"
"está aqui?"
BOX_BREAK
UNSKIPPABLE "Você está procurando por uma\n"
"\"Pedra Espiritual?\" Você diz\n"
"aquela aparentemente deliciosa\n"
"pedra vermelha que estava aqui!"
BOX_BREAK
UNSKIPPABLE "Eu estava tão faminto que pensei\n"
"que estaria OK em dar apenas\n"
"uma lambidinha... então eu vim\n"
"para cá. Mas, ela já havia sumido!"
BOX_BREAK
UNSKIPPABLE "Eu acho que o Big Brother a\n"
"levou."
BOX_BREAK
UNSKIPPABLE "Ele sempre diz que\n"
"todos estão atrás daquela pedra\n"
"vermelha!" TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Big Brother se trancou em seu\n"
"quarto dizendo, \"" COLOR(RED) "Eu vou\n"
"esperar aqui pelo mensageiro da\n"
"Família Real!" COLOR(DEFAULT) "\""
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estou tão faminto que não penso\n"
"em nada além de comida!"
BOX_BREAK
UNSKIPPABLE "Pergunte ao Big Brother sobre\n"
"coisas complicadas."
BOX_BREAK
UNSKIPPABLE "Se ele estiver mal humorado,\n"
"vai ficar bravo com você!\n"
"É assustador. Mas..."
BOX_BREAK
UNSKIPPABLE "Eu sei seu SEGREDO."
BOX_BREAK
UNSKIPPABLE "Ele pode não parecer do tipo,\n"
"mas o Big Brother adora dançar!\n"
"Se ele pegar um ritmo, então\n"
"certamente... " TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu me lembro que o Big Brother\n"
"sempre ouvia a " COLOR(ADJUSTABLE) "música que\n"
"vem da floresta" COLOR(DEFAULT) "..."
BOX_BREAK
"Ah sim, os bons e velhos\n"
"tempos... Aquela música faz eu\n"
"me sentir nostálgico..." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quem diabos é você?!"
BOX_BREAK
UNSKIPPABLE "Quando eu ouvi a " COLOR(BLUE) "Canção\n"
"da Família Real" COLOR(DEFAULT) ", eu esperava\n"
"que seu mensageiro havia chegado,\n"
"mas... você é apenas um garotinho!"
BOX_BREAK
UNSKIPPABLE "Será que " COLOR(RED) "Darúnia" COLOR(DEFAULT) ", o chefão\n"
"dos Gorons, perdeu tanto status\n"
"para ser tratado assim pelo seu\n"
"Irmão de Juramento, o Rei?"
BOX_BREAK
UNSKIPPABLE "Agora, estou MUITO bravo!\n"
"Suma da minha frente, agora!"
BOX_BREAK
UNSKIPPABLE "Está perguntando por que\n"
"estou de mal humor?"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Criaturas ancestrais invadiram\n"
"a Caverna dos Dodongos!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Tivemos uma safra pobre de\n"
"nossa plantação especial, Flores\n"
"Bomba!" QUICKTEXT_DISABLE  UNSKIPPABLE  QUICKTEXT_ENABLE " Inanição e fome por causa\n"
"da falta de rochas!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SHIFT("\x48") "Mas..." TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "É um problema Goron!" QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE  SHIFT("\x11") "Não precisamos da ajuda de\n"
SHIFT("\x46") "estranhos!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x15") "Eeeei! Que música legal!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "A minha depressão se foi!\n"
"Alguma coisa me tomou! Eu de\n"
"repente queria dançar como\n"
"louco!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x3C") "Eu sou " COLOR(RED) "Darúnia" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Eu sou o chefão dos Gorons!\n"
"Tem alguma coisa que você\n"
"gostaria de me perguntar?"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x50") "O que?"
BOX_BREAK
UNSKIPPABLE "Você também quer a " COLOR(RED) "Pedra\n"
"Espiritual do Fogo" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "A Pedra Espiritual do Fogo, também\n"
"conhecida como o Rubi Goron, é o\n"
"tesouro escondido de nossa raça...."
BOX_BREAK
UNSKIPPABLE "Mas espere. Eu não vou dá-la\n"
"para você assim tão fácil.\n"
"Se você a quer tanto..."
BOX_BREAK
UNSKIPPABLE "Por que não vai destruir os\n"
"monstros dentro da Caverna dos\n"
"Dodongos para provar que é um\n"
"verdadeiro homem?"
BOX_BREAK
UNSKIPPABLE "Dessa maneira, todos vão ficar\n"
"felizes novamente! Se o fizer, eu\n"
"vou lhe dar tudo o que você\n"
"quiser, até a Pedra Espiritual!"
BOX_BREAK
UNSKIPPABLE "Eu tenho algo para você. Não\n"
"estou lhe dando como retribuição\n"
"de nada, apenas tome de qualquer\n"
"forma."
BOX_BREAK
UNSKIPPABLE "Se usá-lo, mesmo um pequenino\n"
"como você poderá pegar uma\n"
COLOR(RED) "Flor Bomba" COLOR(DEFAULT) " usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Destrua os monstros na " COLOR(RED) "Caverna\n"
"dos Dodongos" COLOR(DEFAULT) " e torne-se um\n"
"herói! Então, poderemos falar\n"
"sobre a Pedra Espiritual!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, Irmão, toque aquela música\n"
"de novo algum dia!"
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não importa quantas vezes eu ouça\n"
"aquela canção, ela não enjoa!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, não era o que eu estava\n"
"procurando..."
BOX_BREAK
"Eu queria ouvir...uma música...\n"
"algo...de fora das montanhas...\n"
"algo...humm...verde...natural..."
BOX_BREAK
"Esse é o tipo de música que\n"
"eu quero ouvir...     "
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, agora podemos entrar na\n"
"caverna. Espertinho!"
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sei um truque para conservar\n"
"galhos! Se atear fogo em um galho,\n"
"ele vai virar cinzas. Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"guardá-lo antes que queime todo!"
BOX_BREAK
"Falando nisso, escondi um\n"
"galho em algum lugar..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou eu, " COLOR(RED) "Darúnia" COLOR(DEFAULT) "!\n"
"Muito bem!"
BOX_BREAK
UNSKIPPABLE "Graças a você, podemos comer\n"
"novamente as rochas deliciosas\n"
"da Caverna dos Dodongos até\n"
"estourar os estômagos!"
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estou tão faminto que não penso\n"
"em nada além de comida!"
BOX_BREAK
UNSKIPPABLE "\"Pedra Espiritual?\"\n"
"Aquela " COLOR(RED) "pedra vermelha" COLOR(DEFAULT) " que\n"
"iluminava a cidade?"
BOX_BREAK
UNSKIPPABLE "Big Brother " COLOR(RED) "Darúnia" COLOR(DEFAULT) " levou-a\n"
"embora. Então, trancou-se em seu\n"
"quarto e não quis mais sair."
BOX_BREAK
UNSKIPPABLE "Desde então, parece que todas\n"
"as luzes da cidade se apagaram...\n"
"Todos se sentem tão...\n"
"deprimidos..." TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quero que você traga " COLOR(RED) "fogo" COLOR(DEFAULT) "\n"
"do quarto do Big Brother para cá."
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, entendi...\n"
"Devíamos ter jogado a Bomba do\n"
"penhasco..."
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você foi incrível, destruindo os\n"
"Dodongos! Importa-se se eu o chamar\n"
"de Big Brother?"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Graças a você, estamos todos OK!\n"
"Quer comprar bombas agora?" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como sabe, sou grato a você,\n"
"Quando tiver um filho, vou dar\n"
"seu nome a ele!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quiser ouvir mais sobre Goron,\n"
"vá até nossa cidade!"
BOX_BREAK
COLOR(RED) "A Cidade dos Gorons" COLOR(DEFAULT) " fica\n"
"um pouco acima da trilha. Não\n"
"vai demorar para chegar, nem\n"
"mesmo a pé."
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pega as Flores Bomba com\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". E aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"soltá-las."
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando todas as " COLOR(RED) "tochas" COLOR(DEFAULT) " daqui\n"
"são acesas, a Cidade dos Gorons\n"
"revigora!"
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você está indo acabar com os\n"
"Dodongos? Mas, é um problema\n"
"Goron. Você é um garotinho\n"
"curioso, não é?!"
BOX_BREAK
"Bem, certamente ficaremos\n"
"felizes se resolvê-lo, pois\n"
"pegaremos todas as bombas que\n"
"quisermos, como fazíamos..."
BOX_BREAK
"Mas vou avisando logo... Dodongos\n"
"são criaturas assustadoras! Eles\n"
"comem QUALQUER COISA!"
BOX_BREAK
"Então se cuide, e não seja\n"
"comido!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu já lhe falei!\n"
"Estamos sem bombas!\n"
"Ohh... Estou tão faminto!" PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como está o Big Brother?\n"
"Sei..."
BOX_BREAK
"A propósito, você conhece a\n"
"música que vem desse túnel? Todos\n"
"nós adoramos esta música!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não vou deixá-lo me pegar!\n"
"Você trabalha para Ganondorf!"
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Como pôde fazer isto comigo?\n"
"Você é um servo de Ganondorf!"
BOX_BREAK
UNSKIPPABLE "Ouça meu nome e trema!"
BOX_BREAK
UNSKIPPABLE "Eu sou " COLOR(RED)  NAME  COLOR(DEFAULT) "!\n"
"Herói dos Gorons!"
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O que?"
BOX_BREAK
UNSKIPPABLE "Seu nome também é " NAME "?"
BOX_BREAK
UNSKIPPABLE "Então você deve ser o lendário\n"
"Herói Caçador de Dodongo, " NAME "!"
BOX_BREAK
UNSKIPPABLE "Meu pai é " COLOR(RED) "Darúnia" COLOR(DEFAULT) "...\n"
"Você lembra dele?"
BOX_BREAK
UNSKIPPABLE "Ele me nomeou " NAME " como\n"
"você, porque você é muito bravo!"
BOX_BREAK
UNSKIPPABLE "É um nome legal!\n"
"Eu gostei muito dele!"
BOX_BREAK
UNSKIPPABLE  NAME ", você é um herói para nós!\n"
"Fico feliz em conhecê-lo!"
BOX_BREAK
UNSKIPPABLE "Por favor me dê um autógrafo!\n"
"Assine:\n"
SHIFT("\x05") "\"Para meu amigo,\n"
SHIFT("\x05")  NAME " dos Gorons\""
BOX_BREAK
UNSKIPPABLE "Oh..."
BOX_BREAK
UNSKIPPABLE "Acho que não é uma boa hora\n"
"para pedir isso...\n"
"Por favor, ajude a todos!"
BOX_BREAK
UNSKIPPABLE "Meu pai, Darúnia, foi ao\n"
COLOR(RED) "Templo do Fogo" COLOR(DEFAULT) ". Tem um dragão\n"
"lá dentro!"
BOX_BREAK
UNSKIPPABLE "Se não corrermos,\n"
"até o meu pai será comido pelo\n"
"dragão!!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"B-b-b-buuuu huuuuu!" EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"É melhor você tentar acalmá-lo\n"
"se puder...\n"
"Será que se acalma se você falar\n"
"com ele?"
BOX_BREAK
"O que gostaria de perguntá-lo?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sobre o dragão\n"
"Sobre os Gorons" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Há muito tempo atrás havia um\n"
"malvado dragão chamado\n"
COLOR(RED) "Volvagia" COLOR(DEFAULT) " vivendo nesta\n"
"montanha."
BOX_BREAK
UNSKIPPABLE "Ele era assustador e comia\n"
"Gorons!"
BOX_BREAK
UNSKIPPABLE "Usando um grande martelo, o\n"
"herói dos Gorons... BOOM!"
BOX_BREAK
UNSKIPPABLE "Destruiu-o desse jeito.\n"
"Isto é uma fábula muito antiga,\n"
"mas é verdadeira!"
BOX_BREAK
UNSKIPPABLE "Eu sei, porque meu pai é\n"
"um descendente do herói!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Todos foram levados para o\n"
COLOR(RED) "Templo do Fogo" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Enquanto meu pai saiu...\n"
"Os Seguidores de Ganondorf vieram\n"
"e levaram todos!"
BOX_BREAK
UNSKIPPABLE "Todos eles serão comidos por\n"
COLOR(RED) "Volvagia" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Papai disse que Ganondorf\n"
"reviveu Volvagia..."
BOX_BREAK
UNSKIPPABLE "Como um aviso àqueles que\n"
"se opuserem a ele, Ganondorf vai\n"
"alimentar Volvagia com todos eles!"
BOX_BREAK
UNSKIPPABLE "Papai foi ao Templo do Fogo\n"
"sozinho para tentar salvar a\n"
"todos..."
BOX_BREAK
UNSKIPPABLE "Por favor, ajude " NAME "!\n"
"Vou lhe dar esta " COLOR(RED) "túnica\n"
"resistente ao calor!"
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Papai disse para não deixar\n"
"ninguém segui-lo, mas..."
BOX_BREAK
UNSKIPPABLE "Só você, " NAME ", pode salvar\n"
"a todos!"
BOX_BREAK
UNSKIPPABLE "Tenho certeza que o dono da\n"
"loja, que está escondido em algum\n"
"lugar agora, também vai ajudá-lo!"
BOX_BREAK
UNSKIPPABLE "Agora, vou lhe dizer sobre a\n"
"passagem secreta para o Templo!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tente mover a " COLOR(RED) "estátua" COLOR(DEFAULT) " do\n"
"quarto de papai!"
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quem está aí? É você, " NAME "...?"
BOX_BREAK
UNSKIPPABLE "Oh, realmente é " NAME "!"
BOX_BREAK
UNSKIPPABLE "Você cresceu tanto desde a\n"
"última vez que o vi!"
BOX_BREAK
UNSKIPPABLE "Quero ter uma longa conversa com\n"
"você, mas agora não é hora."
BOX_BREAK
UNSKIPPABLE "Ganondorf está causando problemas\n"
"na Montanha da Morte de novo!\n"
"Ele reviveu o maligno dragão\n"
"Volvagia!"
BOX_BREAK
UNSKIPPABLE "Além disso, ele vai dar meu\n"
"povo de comida àquele dragão\n"
"como um aviso às outras raças\n"
"que tentarem resistir a ele..."
BOX_BREAK
UNSKIPPABLE "Se aquele dragão cospe-fogo\n"
"escapar da montanha, toda\n"
"Hyrule se tornará uma terra\n"
"devastada pelo fogo!"
BOX_BREAK
UNSKIPPABLE "Eu vou na frente para tentar\n"
"selar o dragão maligno..."
BOX_BREAK
UNSKIPPABLE "Mas estou preocupado, porque\n"
"eu não tenho o martelo lendário...\n"
"Mas não tenho escolha."
BOX_BREAK
UNSKIPPABLE  NAME "...quero que faça isso\n"
"como meu Irmão de Juramento..."
BOX_BREAK
UNSKIPPABLE "Enquanto eu estiver lidando\n"
"com o dragão, por favor, salve\n"
"o meu povo!"
BOX_BREAK
UNSKIPPABLE "As celas dos prisioneiros estão\n"
"na direção oposta.\n"
"Estou contando com você,\n"
NAME "!"
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou salvo!\n"
"Obrigado!\n"
"Leve isto aqui!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "...não posso...\n"
"aguentar mais...\n"
"não consigo..."
BOX_BREAK
UNSKIPPABLE "Dê o fora daqui agora!!"
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigado, Brother!\n"
"Eu realmente aprecio o que\n"
"você fez. Agradeço em nome de\n"
"toda a raça dos Gorons!"
BOX_BREAK
UNSKIPPABLE "Você se tornou um verdadeiro\n"
"herói, como eu pensava que\n"
"seria!"
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT("\x36") "Não se esqueça...\n"
SHIFT("\x03") "Agora somos Irmãos de verdade!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "É algo que cresce com o tempo...\n"
"uma verdadeira amizade.\n"
"Um sentimento no coração que\n"
"se torna mais forte com o tempo..."
BOX_BREAK
UNSKIPPABLE "A afeição da amizade vai logo\n"
"florescer num virtuoso poder, e\n"
"com ele, você saberá por qual\n"
"caminho seguir..."
BOX_BREAK
UNSKIPPABLE "Esta canção é dedicada ao\n"
"poder do coração...\n"
"Ouça o " COLOR(RED) "Bolero do Fogo" COLOR(DEFAULT) "...\n"
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "...até a próxima..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME ", é tão quente aqui!\n"
"Não podemos ficar muito\n"
"tempo! " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Brother " NAME "!\n"
"Todos retornaram!"
BOX_BREAK
UNSKIPPABLE "Papai e você destruíram o\n"
"dragão juntos, não foi!?" TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando crescer, quero ser um\n"
"homem forte como você, " NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado, " NAME "!!!"
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Muito obrigado por nos\n"
"salvar! " PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A propósito, eu, o bravo Darúnia,\n"
"tornei-me o grande " COLOR(RED) "Sábio do\n"
"Fogo" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Não é engraçado, Brother?\n"
"Bem, isso deve ser o que chamam\n"
"de destino."
BOX_BREAK
UNSKIPPABLE "Nada me deixou mais feliz do\n"
"que ajudá-lo a selar o mal aqui!"
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, Brother, pegue isto!\n"
"Este é um " COLOR(RED) "Medalhão" COLOR(DEFAULT) " que\n"
"contém o poder dos espíritos do\n"
"fogo, e minha amizade."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Problemão!\n"
"Todos sumiram!\n"
"Mas eu vou manter minha loja\n"
"aberta!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Que aventura fantástica! Vai dar\n"
"uma história incrível..."
BOX_BREAK
UNSKIPPABLE "Não posso acreditar que os\n"
"Dodongos apareceram de repente\n"
"em grande número!"
BOX_BREAK
UNSKIPPABLE "E aquela rocha bloqueando a\n"
"caverna..."
BOX_BREAK
UNSKIPPABLE "Tudo isso deve ter sido\n"
"causado por aquele ladrão Gerudo,\n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Ele disse,\n"
"\"" COLOR(LIGHTBLUE) "Entreguem-me a Pedra\n"
"Espiritual! Só então eu abrirei\n"
"a caverna para vocês!" COLOR(DEFAULT) "\""
BOX_BREAK
UNSKIPPABLE "Você, por outro lado,\n"
"arriscou sua vida por nós..."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Firme..."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou trabalhando em algo bem\n"
"legal agora! Mas eu acho que isso\n"
"vai demorar um pouco..." TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se puder esperar 5 ou 6 anos,\n"
"isso deve estar pronto. OK?"
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Completei uma pequena arma.\n"
"O que acha..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Qual a sensação que ela passa?"
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que há um problema com\n"
"a durabilidade...\n"
"Entretanto..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que acha de comprar essa faca\n"
"por 200 Rupees?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem. Volte sempre."
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor...Não...me coma...\n"
"Se comer algo como eu, você terá\n"
"uma dor de barriga!"
BOX_BREAK
"Vai se arrepender!!"
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, sim. Big Brother Darúnia\n"
"pediu-lhe para me salvar.\n"
"Te devo uma!"
BOX_BREAK
"Por favor, ajude o Big Brother!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu Brotherrr...\n"
"Abriu uma nova lojjja...\n"
"É a lojjjja Lâmina de Medigoron..."
BOX_BREAK
"Porrrém...\n"
"Eu sou melhorrrr em fazerrr\n"
"lâminasssss."
BOX_BREAK
"Carrrrrrrpinteiros Hylianssss\n"
"elogiam-me porrrrr minhassssss\n"
"habilidadesssssssssss..."
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Essa faca quebrada é certamente\n"
"trrrrrrabalho meu..."
BOX_BREAK
UNSKIPPABLE "Quero muito conserrrtá-la, mas..."
BOX_BREAK
UNSKIPPABLE "Por causa da errrrupção de\n"
"onnnnntem, meus olhos estão\n"
"irrrrrrritados..."
BOX_BREAK
UNSKIPPABLE "Existem bons colírios no\n"
"Domínio dos Zoras... Você vai\n"
"encontrá-los se for ver o\n"
COLOR(RED) "RRRRReeei Zorrrrra" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, vá pegar o colírrio...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Auuu nãão... Estou acabado...\n"
"Meus olhos arrrrrdem...\n"
"Auuuuuuuuu..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, não! Sumiram todos!\n"
"Só eu fui deixado aqui!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Estava esperando porrr você,\n"
"com lágrrrimas nos olhos...\n"
"Por favor, dê um alô ao\n"
"RRRei Zorrrra!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ssssério? Você trrrouxe o\n"
"colírio? Estou tão alivvviado!\n"
"Vou usá-lo agorrrra messssssmo!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(RED) "Uauuuuuuuuu!!" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE "Isso é estimulante! Está\n"
"funcionannnnnndo muito bemm!"
BOX_BREAK
UNSKIPPABLE "Agora posso voltar a fazer lâminas!\n"
"Meu trrrrabalho não é muito\n"
"consisssstente, então vou lhe dar\n"
"isto para que não se esssssqueça." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Todos voltaram!\n"
"O comércio é o mesmo de sempre! " EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Depoisss de alguns dias...\n"
"Por favor retorrrne...\n"
"Espere pacientemente..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ainda não...\n"
"Ei você...\n"
"Você é impaciente..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Essa espada é meu perfeito\n"
"trabalho!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) " se foi!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "A " COLOR(DEFAULT) "túnica" COLOR(LIGHTBLUE) " que estava\n"
"vestindo sumiu! " COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) " sumiu!\n"
"A " COLOR(DEFAULT) "túnica" COLOR(LIGHTBLUE) " que estava\n"
"vestindo também foi levada!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você fez bem em subir todo esse\n"
"caminho até aqui, " NAME ".\n"
"Este é o topo da sagrada\n"
"Montanha da Morte! Hoot!"
BOX_BREAK
UNSKIPPABLE "Dizem que as nuvens em volta\n"
"deste pico refletem o estado da\n"
"Montanha da Morte. Quando parecem\n"
"normais, a montanha está em paz."
BOX_BREAK
UNSKIPPABLE "Escalando tudo até aqui só\n"
"prova o quanto você é esperto!\n"
"Agora quero ver você fazer\n"
"outro movimento especial..."
BOX_BREAK
UNSKIPPABLE "A " COLOR(RED) "Grande Fada" COLOR(DEFAULT) " vive neste\n"
"topo da montanha, e ela lhe dará\n"
"uma nova habilidade! Ela é a\n"
"líder das fadas, como sabe. Hoo!"
BOX_BREAK
UNSKIPPABLE "Vou ficar aqui e esperar por\n"
"você. Quando estiver pronto para\n"
"descer, poderei ajudá-lo!\n"
"Agora, suba!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hoo!\n"
"Bem, parece que você cresceu\n"
"um pouco com o poder da Grande\n"
"Fada..."
BOX_BREAK
"Mas realmente ainda\n"
"não parece com o herói que vai\n"
"salvar Hyrule. Por enquanto\n"
"ainda não!"
BOX_BREAK
"Se você for " COLOR(RED) "descer a montanha" COLOR(DEFAULT) ",\n"
"eu posso lhe dar uma carona.\n"
"Venha cá e segure em minhas\n"
"garras! E segure-se firme!"
BOX_BREAK
"Hooot hoooooooooot!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que uma " COLOR(RED) "bela fada" COLOR(DEFAULT) "\n"
"vive no topo da Montanha da\n"
"Morte!"
BOX_BREAK
"Você não quer vê-la?\n"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que uma " COLOR(RED) "fada" COLOR(DEFAULT) " vive\n"
"no topo da Montanha da Morte."
BOX_BREAK
"Se quiser chegar ao topo,\n"
"é melhor levar consigo um grande\n"
COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Veja! Uma " COLOR(DEFAULT) "galinha" COLOR(LIGHTBLUE) " nasceu\n"
"do " COLOR(DEFAULT) "ovo" COLOR(LIGHTBLUE) " que você estava\n"
"chocando! É o milagre da vida!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pegou a pedra vermelha?\n"
"Deixa eu dar uma lambidinha!"
BOX_BREAK
"Não? Ah!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Brother! Você continua melhorando\n"
"suas habilidades conforme viaja,\n"
"não é?"
BOX_BREAK
UNSKIPPABLE "Você deveria ver a " COLOR(RED) "Grande\n"
"Fada" COLOR(DEFAULT) " no topo da Montanha da\n"
"Morte! Ela vai fortificá-lo!"
BOX_BREAK
UNSKIPPABLE "Ei, todos! Vamos ver o nosso\n"
"Brother!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou lhe contar um segredo por me\n"
"salvar!"
BOX_BREAK
UNSKIPPABLE "Neste templo, existem " COLOR(RED) "portas\n"
"que caem" COLOR(DEFAULT) " quando você tenta\n"
"abri-las. Quando uma destas\n"
"portas começar a cair, mova-se!"
BOX_BREAK
UNSKIPPABLE "Se usar uma amostra da\n"
"\"plantação especial\" Goron,\n"
"poderá quebrá-la..."
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Deixe-me contar-lhe um segredo\n"
"como recompensa por me soltar!"
BOX_BREAK
UNSKIPPABLE "Quando estiver em chamas,\n"
"afaste-as girando sua espada, ou\n"
"rolando para frente... Você\n"
"sabia disso?"
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aqui vai uma dica por me salvar!"
BOX_BREAK
UNSKIPPABLE "Em algum lugar neste templo,\n"
"você encontrará criaturas que\n"
"dançam enquanto atacam. Flechas\n"
"não vão machucá-las!"
BOX_BREAK
UNSKIPPABLE "Parece que você precisará de\n"
"um pouco da \"plantação especial\"\n"
"Goron! É tudo que posso lhe falar!"
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou lhe contar um segredo por\n"
"me salvar!"
BOX_BREAK
UNSKIPPABLE "Existem interruptores neste templo\n"
"que ativam com um ataque.\n"
"Mas pode-se usar a \"bomba especial\"\n"
"Goron para fazer o trabalho."
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou lhe contar um segredo por\n"
"me salvar!"
BOX_BREAK
UNSKIPPABLE "Se encontrar um local que você\n"
"pode ver no mapa, mas não\n"
"alcança, tente tocar a Ocarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou lhe contar um segredo por\n"
"me salvar!"
BOX_BREAK
UNSKIPPABLE "Para chegar no lugar em que\n"
"Darúnia entrou, você tem que\n"
"fazer alguma coisa com o pilar\n"
"preso no teto."
BOX_BREAK
UNSKIPPABLE "Ache um caminho que leve a uma\n"
"sala acima do teto imediatamente!\n"
""
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou lhe contar um segredo por\n"
"me salvar!"
BOX_BREAK
UNSKIPPABLE "Uma porta está escondida dentro\n"
"da estátua na entrada deste\n"
"templo."
BOX_BREAK
UNSKIPPABLE "Mas, a \"bomba especial\" não\n"
"vai funcionar... Você não tem\n"
"algo mais poderoso?"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aqui vai um segredo por me\n"
"salvar!"
BOX_BREAK
UNSKIPPABLE "Muros que você pode destruir com\n"
"a \"bomba especial\" Goron farão um\n"
"som diferente de um muro normal\n"
"se acertá-lo com sua espada."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está me soltando?\n"
"Estou livre para ir?" EVENT
)

DEFINE_MESSAGE(0x3072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3072"
)

DEFINE_MESSAGE(0x3073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"3073"
)

DEFINE_MESSAGE(0x4000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Esses olhos são tão deliciosos!\n"
"Hoje à noite vou fazer olhos\n"
"fritos como há tanto tempo não\n"
"fazia! Ho ho ho ho ho!!"
BOX_BREAK
UNSKIPPABLE "Que coisa maravilhosa! Por\n"
"favor agradeça ao Rei Zora!\n"
"Eh? O que?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Estes aqui são para fazer o\n"
COLOR(RED) "Colírio do Biggoron" COLOR(DEFAULT) "? Oh,\n"
"que decepção! Você devia ter me\n"
"dito isso logo no início! " EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
"Por aqui! Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Queria saber o que " COLOR(RED) "Saria" COLOR(DEFAULT) "\n"
"estaria fazendo?\n"
"Que acha de voltar para a\n"
"floresta?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que está fazendo? Andou um\n"
"longo caminho até chegar aqui..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Você devia olha a " COLOR(RED) "Subtela do\n"
"Mapa" COLOR(DEFAULT) " regularmente."
BOX_BREAK
UNSKIPPABLE  NAME ", este é um belo lago\n"
"cheio de água, limpa e pura."
BOX_BREAK
UNSKIPPABLE "No fundo do lago há um " COLOR(BLUE) "Templo\n"
"da Água" COLOR(DEFAULT) " usado para adoração\n"
"dos espíritos da água. Os " COLOR(BLUE) "Zoras" COLOR(DEFAULT) "\n"
"são os guardiões do templo. Hoo."
BOX_BREAK
UNSKIPPABLE "Os Zoras vêm do Domínio dos\n"
"Zoras à nordeste de Hyrule. Essa\n"
"raça aquática é há muito tempo\n"
"aliada da Família Real de Hyrule."
BOX_BREAK
UNSKIPPABLE "Ouvi falar que só a Família\n"
"Real de Hyrule pode entrar no\n"
"Domínio dos Zoras. Hoo hoo ho!"
BOX_BREAK
UNSKIPPABLE "Estou voltando para o " COLOR(RED) "castelo" COLOR(DEFAULT) ".\n"
"Se quiser vir comigo, segure nas\n"
"minhas garras!"
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou voltando para o " COLOR(RED) "castelo" COLOR(DEFAULT) ".\n"
"Se quiser vir comigo, segure nas\n"
"minhas garras!"
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "...Huh?"
BOX_BREAK
UNSKIPPABLE "Parece que tem alguma coisa\n"
"dentro deste frasco.\n"
"É uma " COLOR(RED) "carta" COLOR(DEFAULT) ":"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x0C") "\"" COLOR(PURPLE) "Ajude-me." COLOR(DEFAULT) "\n"
SHIFT("\x0C")  COLOR(PURPLE) "Estou esperando por você dentro\n"
COLOR(DEFAULT)  SHIFT("\x0C") "da barriga do " COLOR(YELLOW) "Senhor Jabu-Jabu" COLOR(PURPLE) ".\n"
COLOR(PURPLE)  SHIFT("\x18") "--" COLOR(YELLOW) "Ruto" COLOR(DEFAULT)  QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x16")  COLOR(PURPLE) "ps: Não conte ao meu pai!" COLOR(DEFAULT) "\"" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quem é você?"
BOX_BREAK
UNSKIPPABLE "Nós somos os " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", o\n"
"orgulhoso povo aquático!"
BOX_BREAK
UNSKIPPABLE "Então você diz que tem alguma\n"
"conexão com a Família Real de\n"
"Hyrule... Bem, o que quer de\n"
"nós?"
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós somos bons em mergulho!\n"
"E você?"
BOX_BREAK
"Se quiser ser um mergulhador\n"
"mestre, tente o " COLOR(RED) "jogo do\n"
"mergulho" COLOR(DEFAULT) " no topo da cachoeira!\n"
"Por acaso você já tentou?"
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Fonte dos Zoras é a\n"
"nascente do rio.\n"
"O " COLOR(RED) "Senhor Jabu-Jabu" COLOR(DEFAULT) " vive\n"
"nessa fonte." TEXTID("\x40\x09") " "
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O Senhor Jabu-Jabu é o patrono\n"
"divino dos Zoras. A " COLOR(RED) "Princesa\n"
"Ruto" COLOR(DEFAULT) " é a responsável pela\n"
"refeição dele, da manhã e noite."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós Zoras todos servimos ao\n"
COLOR(RED) "Rei Zora" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O grande Rei Zora deveria estar\n"
"no " COLOR(RED) "Salão Real" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu o Senhor Jabu-Jabu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De acordo com a \"Lenda de Zora,\"\n"
"o ato de oferecer um " COLOR(RED) "peixe" COLOR(DEFAULT) " ao\n"
"Senhor Jabu-Jabu fará você feliz."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, isto não é bom."
BOX_BREAK
"Todo mundo que vem por aqui\n"
"deveria ver o " COLOR(RED) "Senhor Jabu-Jabu" COLOR(DEFAULT) "\n"
"no mínimo uma vez!"
BOX_BREAK
"A fonte dos Zoras está logo atrás\n"
"do trono do Rei Zora. É lá onde o\n"
"Senhor Jabu-Jabu nada. Mas..."
BOX_BREAK
"a menos que tenha a permissão\n"
"do Rei Zora, não poderá ir à\n"
"Fonte."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não encontramos a " COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) "\n"
"apesar de termos ido procurar\n"
"tão longe quanto o " COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você achar alguma pista do\n"
"paradeiro da " COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) ",\n"
"você vai contar ao Rei Zora?"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Toda a água em Hyrule flui da\n"
COLOR(BLUE) "Fonte dos Zoras" COLOR(DEFAULT) "."
BOX_BREAK
"Esta água corre pelo Rio dos\n"
"Zoras, que eventualmente alcança\n"
"o " COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) " ao sul.   "
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh--Eu voltei à vida!"
BOX_BREAK
UNSKIPPABLE "Foi você quem me salvou?\n"
"Não fique nervoso!"
BOX_BREAK
UNSKIPPABLE "Parece que você sentiu dificuldade\n"
"em respirar debaixo d'água."
BOX_BREAK
UNSKIPPABLE "Para mostrar minha gratidão,\n"
"Eu lhe darei esta " COLOR(RED) "túnica" COLOR(DEFAULT) ". Com\n"
"isto, você não se afogará na água."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A Princesa Ruto foi ao templo do\n"
"Lago Hylia e não voltou... estou\n"
"tão preocupado... de novo!"
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ooh...\n"
"Isto é... bem... hmm...\n"
"Hmm... " COLOR(RED) "Colírio" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Você pode dizer que os temos,\n"
"pode dizer que não os temos...\n"
"Nós temos os ingredientes."
BOX_BREAK
UNSKIPPABLE "Se você levar os " COLOR(RED) "ingredientes" COLOR(DEFAULT) "\n"
"ao doutor no laboratório do lago,\n"
"ele poderá fazer o colírio para\n"
"você."
BOX_BREAK
UNSKIPPABLE "Mas tem que entregá-los frescos!" TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pode levar " COLOR(RED) "antes que\n"
"estraguem" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Então acha que vão estragar antes\n"
"que chegue lá? Não é tão longe\n"
"se você fizer a conexão montado\n"
"em um cavalo..."
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoot hoot!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", parece que você está mais\n"
"confortável em seu papel de\n"
"aventureiro."
BOX_BREAK
UNSKIPPABLE "Eu acho que a Princesa Zelda está\n"
"esperando sua visita de novo."
BOX_BREAK
UNSKIPPABLE "Você já tem o " COLOR(RED) "Rubi Goron" COLOR(DEFAULT) ",\n"
"não tem?           "
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá garoto. Estou pesquisando o\n"
"processo de fazer remédio\n"
"misturando a água do Lago Hylia\n"
"com vários compostos raros."
BOX_BREAK
"Talvez você encontre aquela\n"
"velha senhora da loja de poções...\n"
"ela é como uma aprendiz minha...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Oh, uau!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Não vejo um " COLOR(RED) "Olho de Rã" COLOR(DEFAULT) " como\n"
"esse desde que o Domínio dos Zoras\n"
"congelou! " EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, minha querida, doce " COLOR(RED) "Princesa\n"
"Ruto" COLOR(DEFAULT) "... Onde estaria?\n"
"Estou preocupado!"
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, esta carta!\n"
"É da " COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) "!!"
BOX_BREAK
UNSKIPPABLE "Hmmm...Vamos ver...\n"
"Ela está dentro do Senhor\n"
"Jabu-Jabu? Não é possível!"
BOX_BREAK
UNSKIPPABLE "Nosso deus guardião, " COLOR(RED) "Senhor\n"
"Jabu-Jabu" COLOR(DEFAULT) ", nunca comeria minha\n"
"querida Princesa Ruto!"
BOX_BREAK
UNSKIPPABLE "Mas desde que aquele estranho,\n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", veio aqui, Senhor\n"
"Jabu-Jabu ficou com as brânquias\n"
"verdes..."
BOX_BREAK
UNSKIPPABLE "A evidência parece clara.\n"
"É claro, vá encontrar Ruto.\n"
"Você pode passar por aqui até o\n"
"altar do Senhor Jabu-Jabu."
BOX_BREAK
UNSKIPPABLE "Eu ficarei com esta carta. Fique\n"
"com o " COLOR(RED) "frasco" COLOR(DEFAULT) ". Tome-o\n"
"respeitosamente!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor ache minha querida\n"
COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) " rápido!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Você não pode respirar sob a\n"
"água! Se começar a se afogar,\n"
"tire as " COLOR(DEFAULT) "botas" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x36") "Ooooh Noooooo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ohh, eu revivi...\n"
"Foi você quem me salvou?\n"
"Não fique nervoso!"
BOX_BREAK
UNSKIPPABLE "Darei a você uma " COLOR(BLUE) "Túnica\n"
"Zora" COLOR(DEFAULT) " como um agradecimento.\n"
"Com isto, você pode... O quê?!"
BOX_BREAK
UNSKIPPABLE "Você já tem uma? Está preparado\n"
"para tudo, não é!?"
BOX_BREAK
UNSKIPPABLE "Com os meus sinceros\n"
"agradecimentos... que tal um\n"
"BEIJO? O quê? Não quer? Tudo bem..."
BOX_BREAK
UNSKIPPABLE "Já que não quer meu agradecimento,\n"
"você pode ouvir meus problemas..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou um " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Você viu\n"
"uma bonita garota Zora por aqui?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou um " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Você viu algo\n"
"estranho no lago? O rio traz\n"
"muitas coisas para dentro deste\n"
"lago!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você..." QUICKTEXT_ENABLE "Está atrasado!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Por que demorou tanto?" QUICKTEXT_DISABLE "\n"
"Você é " QUICKTEXT_ENABLE "inútil!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Eu estava sozinha indefesa,\n"
"isso é tudo..."
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Eu estava..." QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "assustada!" QUICKTEXT_DISABLE " Só um pouquinho!!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Você!" QUICKTEXT_DISABLE "\n"
"Parece legal... mais do que eu\n"
"pensava que fosse...\n"
QUICKTEXT_ENABLE "Eu achava só um pouco!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Bem, você me salvou, então\n"
"acho que quero recompensá-lo."
BOX_BREAK
UNSKIPPABLE "O que você deseja? Diga-me...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Eu quero aquela Pedra Espiritual\n"
"Na verdade, nada..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você diz a Pedra Espiritual da\n"
"Água, " COLOR(BLUE) "Safira de Zora" COLOR(DEFAULT) ", não é?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Minha mãe me deu e disse que eu\n"
"deveria dá-la ao homem que será\n"
"meu marido. Pode chamá-la de\n"
"Anel de Noivado Zora!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x45")  QUICKTEXT_ENABLE "Tudo bem!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Eu vou dar a você minha mais\n"
"preciosa propriedade: A Safira\n"
"de Zora!     "
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Não diga ao meu pai..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe... não se assuste."
BOX_BREAK
UNSKIPPABLE "Posso dizer o que está\n"
"pensando..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu quero comprar um peixe, mas\n"
"está muito caro..."
BOX_BREAK
"Não tenho escolha a não ser\n"
"pescar um desses peixes que vivem\n"
"nadando por aí afora."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, " NAME "!\n"
"Então, você salvou a Princesa, eh?\n"
"Gostei de ver!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A minha preciosa propriedade o\n"
"ajudou em sua aventura? Heehee!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, oi " NAME "!\n"
"Você é tudo o que a Princesa\n"
"Ruto andou falando!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, é você, " NAME "!\n"
"Graças a você, Senhor Jabu-Jabu\n"
"voltou ao normal!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nós Zoras respeitamos o grande\n"
"Rei Zora! Ele tem a dignidade de\n"
"um rei."
BOX_BREAK
UNSKIPPABLE "O grande Rei Zora tem uma Princesa\n"
"chamada " COLOR(RED) "Ruto" COLOR(DEFAULT) ". Ela é filha\n"
"única."
BOX_BREAK
UNSKIPPABLE "Ela também é uma garota muito\n"
"levada, e parece que ela sempre\n"
"está causando muitos problemas\n"
"ao Rei!" TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Aqui está."
BOX_BREAK
UNSKIPPABLE "Este remédio não contém nenhum\n"
"conservante. Então " COLOR(RED) "não durará\n"
"muito" COLOR(DEFAULT) " nesta temperatura."
BOX_BREAK
UNSKIPPABLE "Corra o quanto puder à Montanha\n"
"da Morte. Você é jovem, você\n"
"consegue!    "
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo! Parece que já ficou\n"
"mais alto e mais forte, " NAME "!"
BOX_BREAK
UNSKIPPABLE "Logo a frente é o " COLOR(BLUE) "Domínio\n"
"dos Zoras" COLOR(DEFAULT) ". Os Zoras servem à\n"
"Família Real de Hyrule protegendo\n"
"esta fonte de água."
BOX_BREAK
UNSKIPPABLE "A entrada não abrirá para\n"
"ninguém, exceto àqueles que têm\n"
"alguma conexão com a Família Real."
BOX_BREAK
UNSKIPPABLE "Deixe-os ouvirem a " COLOR(RED) "melodia\n"
"da Família Real" COLOR(DEFAULT) "!\n"
"Hooo hoo hooooot!   "
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na próxima vez que voltar,\n"
"não esqueça de me trazer um\n"
"presentinho!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você achou a Princesa Ruto!\n"
"Agora o Rei Zora lhe dará a\n"
COLOR(BLUE) "Pedra Espiritual da Água" COLOR(DEFAULT) "...\n"
"Bem, talvez."
BOX_BREAK
UNSKIPPABLE "Huh?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sua mais preciosa propriedade?\n"
"Você não sabe do que ela está\n"
"falando, mas você coletou duas\n"
"Pedras Espirituais! Só falta uma!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sua mais preciosa propriedade?\n"
"Você não sabe do que ela está\n"
"falando, mas você finalmente\n"
"coletou as três Pedras Espirituais!"
BOX_BREAK
UNSKIPPABLE "Volte para ver a Princesa Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Juntos de novo, " NAME "!"
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Este gelo é criado por uma\n"
"terrível maldição... O monstro no\n"
COLOR(BLUE) "Templo da Água" COLOR(DEFAULT) " é a origem\n"
"da maldição."
BOX_BREAK
UNSKIPPABLE "A menos que acabe com a fonte,\n"
"este gelo jamais derreterá..."
BOX_BREAK
UNSKIPPABLE "Se tiver coragem suficiente para\n"
"confrontar o perigo e salvar os\n"
"Zoras, eu lhe ensinarei a melodia\n"
"que leva ao templo."
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O tempo passa, as pessoas se\n"
"movem... Como um rio que flui sem\n"
"fim..."
BOX_BREAK
UNSKIPPABLE "Uma mente ingênua tornar-se-á\n"
"uma nobre ambição... E o amor\n"
"jovem, uma profunda afeição... A\n"
"límpida água reflete o crescimento."
BOX_BREAK
UNSKIPPABLE "Agora ouça a " COLOR(BLUE) "Serenata da Água" COLOR(DEFAULT) "\n"
"para que reflita sobre si mesmo..."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se veio aqui para ver os Zoras,\n"
"perdeu seu tempo...\n"
"Isto é tudo que sobrou..."
BOX_BREAK
UNSKIPPABLE "Com uma exceção, os Zoras agora\n"
"estão selados debaixo desta\n"
"superfície de gelo..."
BOX_BREAK
UNSKIPPABLE "Consegui resgatar a Princesa\n"
"Zora sob o gelo, mas... ela saiu\n"
"em direção ao " COLOR(BLUE) "Templo da Água" COLOR(DEFAULT) "...\n"
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se quer comprar um peixe, traga\n"
"um recipiente para levá-lo." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você disse que quer comprar uma\n"
COLOR(BLUE) "Túnica Zora" COLOR(DEFAULT) "? Ela é feita\n"
"do mais fino material, e portanto\n"
"extremamente cara!"
BOX_BREAK
"De fato, tenho medo que apenas\n"
"aquela " COLOR(RED) "família muito rica da\n"
"Vila Kakariko" COLOR(DEFAULT) " possa comprar\n"
"este fino artigo..." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh...você... se estou certa...\n"
NAME "?!"
BOX_BREAK
UNSKIPPABLE "Você é " NAME ", não é?"
BOX_BREAK
UNSKIPPABLE "Sou eu, sua noiva, " COLOR(BLUE) "Ruto" COLOR(DEFAULT) "!\n"
"Princesa dos Zoras!"
BOX_BREAK
UNSKIPPABLE "Nunca me esqueci dos votos que\n"
"fizemos um ao outro sete anos\n"
"atrás!"
BOX_BREAK
UNSKIPPABLE "Você é um terrível homem para\n"
"me deixar aguardando por esses\n"
"sete longos anos..."
BOX_BREAK
UNSKIPPABLE "Mas agora não é hora para falar\n"
"sobre amor..."
BOX_BREAK
UNSKIPPABLE "Estou certa de que já viu!\n"
"O Domínio dos Zoras todo\n"
"congelado!"
BOX_BREAK
UNSKIPPABLE "Um jovem chamado " COLOR(RED) "Sheik" COLOR(DEFAULT) " me\n"
"salvou de baixo do gelo..."
BOX_BREAK
UNSKIPPABLE "Mas meu pai e os outros\n"
"Zoras ainda " TEXT_SPEED("\x02") "...não...    " TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Quero salvar todos eles!\n"
"Quero salvar o Domínio dos Zoras!"
BOX_BREAK
UNSKIPPABLE "Você! Tem que me ajudar!\n"
"Este é um pedido meu, a mulher\n"
"que vai ser a sua esposa!"
BOX_BREAK
UNSKIPPABLE  NAME ", você tem que me ajudar a\n"
"destruir o monstro maligno no\n"
"Templo, OK?!"
BOX_BREAK
UNSKIPPABLE "Dentro do Templo da Água,\n"
"existem " COLOR(RED) "três locais" COLOR(DEFAULT) " em que\n"
"você pode mudar o nível da água."
BOX_BREAK
UNSKIPPABLE "Vou mostrar-lhe o caminho.\n"
"Siga-me, rápido!!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! Cuidado!\n"
"Aquela água lá não é\n"
"normal!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "..."
BOX_BREAK
UNSKIPPABLE "Eu não esperaria menos do homem\n"
"que escolhi para ser meu marido."
BOX_BREAK
UNSKIPPABLE "O Domínio dos Zoras e seu povo\n"
"finalmente voltará ao seu\n"
"estado original."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Se encontrar Sheik,\n"
"agradeça-o por mim, OK?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ruto queria me agradecer?"
BOX_BREAK
UNSKIPPABLE "Entendo..."
BOX_BREAK
UNSKIPPABLE "Temos que trazer a paz a Hyrule\n"
"por ela também. Não temos?"
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, entendo...\n"
"Princesa Ruto foi ao Templo\n"
"da Água..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Como recompensa...\n"
"Garanto meu eterno amor a você."
BOX_BREAK
UNSKIPPABLE "Bem, queria dizer isso, mas\n"
"acho que não posso lhe oferecer\n"
"agora."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Princesa Zelda... está viva.\n"
"Posso sentir... não perca as\n"
"esperanças."
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Aaaaaahhhh!\n"
SHIFT("\x0F") "O que é isso?! Um polvo?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tenho que proteger o Templo da\n"
"Água como a " COLOR(BLUE) "Sábia da Água" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "E você... está procurando pela\n"
"princesa, " COLOR(RED) "Zelda" COLOR(DEFAULT) "?"
BOX_BREAK
UNSKIPPABLE "Ah! Você não pode esconder\n"
"nada de mim!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Posso dizer que nada irá pará-lo\n"
"em sua busca por justiça e paz...\n"
"Você deve levar este " COLOR(BLUE) "Medalhão" COLOR(DEFAULT) "...\n"
"Pegue-o respeitosamente!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você! Quem é você?!"
BOX_BREAK
UNSKIPPABLE "Eu sou " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Princesa dos\n"
"Zoras."
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "O que?!" QUICKTEXT_DISABLE "\n"
"Está dizendo que meu pai disse\n"
"para vir aqui me salvar?"
BOX_BREAK
UNSKIPPABLE "Eu " QUICKTEXT_ENABLE "nunca" QUICKTEXT_DISABLE " pediria a ninguém\n"
"para fazer algo assim!"
BOX_BREAK
UNSKIPPABLE "\"Carta num Frasco?\" Não faço\n"
QUICKTEXT_ENABLE "idéia" QUICKTEXT_DISABLE " do que você está falando!"
BOX_BREAK
UNSKIPPABLE "Meu pai está preocupado?"
BOX_BREAK
UNSKIPPABLE "Eu não " QUICKTEXT_ENABLE "ligo!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Mesmo assim, não posso voltar\n"
"agora. E você... " QUICKTEXT_ENABLE "Dê o fora daqui!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Entendeu?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ainda perambulando por aqui?\n"
"Eu disse para ir embora!"
BOX_BREAK
UNSKIPPABLE "Estou bem. Tenho vindo dentro\n"
"da barriga do Senhor Jabu-Jabu\n"
"desde pequena, mas..."
BOX_BREAK
UNSKIPPABLE "Senhor Jabu-Jabu está muito\n"
"estranho hoje..."
BOX_BREAK
UNSKIPPABLE "Tem águas-vivas eletrificadas e\n"
"buracos em toda parte..."
BOX_BREAK
UNSKIPPABLE "Apesar disso, minha preciosa pedra\n"
"foi...mas...\n"
QUICKTEXT_ENABLE "Isso não é da sua conta!" QUICKTEXT_DISABLE "\n"
"Mesmo assim..."
BOX_BREAK
UNSKIPPABLE "Agora " QUICKTEXT_ENABLE "vá embora!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Entendeu?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Então está mesmo preocupado\n"
"comigo?"
BOX_BREAK
UNSKIPPABLE "Então vou lhe dar a honra de\n"
"me carregar!"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE "Porém" QUICKTEXT_DISABLE "...não vou sair até\n"
"encontrar o que estou procurando.\n"
"É melhor acreditar em mim!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Que desconsideração!" QUICKTEXT_DISABLE "\n"
"Como pôde me deixar para trás?!\n"
"Se é um homem, aja como um!\n"
"Tenha responsabilidade!" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "É isso!" QUICKTEXT_DISABLE "\n"
"É o que eu estava procurando!\n"
"Jogue-me lá em cima!\n"
"Sobre a plataforma!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Princesa Ruto pegou a\n"
COLOR(BLUE) "Pedra Espiritual" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Mas" TEXT_SPEED("\x00") " porque a Princesa?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh meu Deus!\n"
"Finalmente achei...\n"
"A pedra da minha mãe..."
BOX_BREAK
UNSKIPPABLE "Fiquei brava quando o Senhor\n"
"Jabu-Jabu a engoliu..."
BOX_BREAK
UNSKIPPABLE "Quando estava alimentando-o,\n"
"ele me engoliu de repente! Fiquei\n"
"tão surpresa que soltei a pedra..."
BOX_BREAK
UNSKIPPABLE "Mas, agora que a encontrei,\n"
"Não preciso mais estar aqui\n"
"dentro!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Leve-me para casa, agora!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mergulho-game  20 Rupees\n"
"Quer jogar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "OK!" QUICKTEXT_DISABLE
BOX_BREAK
"Pegue todos os Rupees que eu\n"
"jogar daqui. Você tem muito pouco\n"
"tempo, apenas!"
BOX_BREAK
"Quando pegar todos, volte para cá!\n"
"Eu lhe darei uma coisa muito\n"
"legal!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ei! Congratulações!" QUICKTEXT_DISABLE "\n"
"Eu tenho algo muito legal para\n"
"você! Venha receber!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Que mergulho gracioso!\n"
"Agora, fique com isto!"
BOX_BREAK
UNSKIPPABLE "Esta é uma \"" COLOR(RED) "escama" COLOR(DEFAULT) "\" de nossa\n"
"raça. Com ela, poderá mergulhar\n"
"muito mais fundo." EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Conforme a água sobe, o mal vai\n"
"sumindo do lago...\n"
NAME ", você conseguiu!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu...acredito que você conseguirá\n"
"salvar o mundo..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Veja isso, " NAME "..."
BOX_BREAK
UNSKIPPABLE "juntos, você e a Princesa Ruto\n"
"destruíram o monstro do mal!"
BOX_BREAK
UNSKIPPABLE "Novamente, o lago está cheio\n"
"de água pura. Tudo está como\n"
"era antes."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(RED) "AGORA!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pule da cachoeira para um atalho." EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pegue o quanto quiser por\n"
"20 Rupees. Quer jogar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ei!!  Congratulações!! " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Quer alguns " COLOR(BLUE) "Feijões Mágicos" COLOR(DEFAULT) "?\n"
"Não estão vendendo muito bem..."
BOX_BREAK
"Que tal...\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " por uma unidade?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Quer alguns " COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "?\n"
"Bem, ainda não são tão populares."
BOX_BREAK
"Que tal...\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) " por uma unidade?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Quer alguns " COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "?\n"
"Eles estão ficando populares..."
BOX_BREAK
COLOR(RED) "30 Rupees" COLOR(DEFAULT) " por uma unidade.\n"
"O que acha?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Quer alguns " COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "?\n"
"Eles estão na moda!"
BOX_BREAK
COLOR(RED) "40 Rupees" COLOR(DEFAULT) " por uma unidade.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Tenho os populares " COLOR(RED) "Feijões\n"
"Mágicos" COLOR(DEFAULT) "! Vai se arrepender se\n"
"não os comprar agora!"
BOX_BREAK
UNSKIPPABLE "A 50 Rupees " COLOR(DEFAULT) "por uma unidade.\n"
"(Promoção.)\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Estes são os superpopulares\n"
COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "! Caso não\n"
"saiba, eles logo vão acabar!"
BOX_BREAK
"Super preço!\n"
COLOR(RED) "60 Rupees" COLOR(DEFAULT) " por uma unidade!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Temos os super-raros\n"
COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) " Esta pode ser\n"
"sua última chance!"
BOX_BREAK
"Preço especial!\n"
COLOR(RED) "70 Rupees" COLOR(DEFAULT) " por unidade!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Temos os lendários\n"
COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "! Vou vendê-los\n"
"só para você!"
BOX_BREAK
"Super preço!\n"
COLOR(RED) "80 Rupees" COLOR(DEFAULT) " por unidade!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Você quer..." COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "?!\n"
"Eles não são baratos, mas...\n"
"você ainda quer?"
BOX_BREAK
"Não posso vendê-los por menos\n"
"de " COLOR(RED) "90 Rupees" COLOR(DEFAULT) " cada um!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Nhoc nhoc nhoc...\n"
"Temos..." COLOR(RED) "Feijões Mágicos" COLOR(DEFAULT) "!\n"
"Você quer...hein? Hein?"
BOX_BREAK
COLOR(RED) "100 Rupees" COLOR(DEFAULT) " por uma unidade!\n"
"Kiahahah!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh bem...\n"
"Nhoc nhoc..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não tem dinheiro suficiente.\n"
"Não posso vendê-los a você.\n"
"Nhoc nhoc..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Coloque um feijão em " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e\n"
"use-o aqui nessa areia."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, que pena! Vendi todos!\n"
"Nhoc nhoc...O que?\n"
"Ah, estes feijões não estão a\n"
"venda!"
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quiser plantar feijões, ande\n"
"por aí e procure terra macia.\n"
"Nhoc nhoc nhoc."
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"estava observando você. Você\n"
"mergulhou " COLOR(RED) "1 metro" COLOR(DEFAULT) " bem agora.\n"
"Mas eu não acho um bom mergulho."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter notado, mas eu\n"
"observei você. Você mergulhou " COLOR(RED) "2\n"
"metros" COLOR(DEFAULT) " bem agora. Mas eu não\n"
"acho que é um bom mergulho."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"observei você. Você mergulhou\n"
COLOR(RED) "3 metros" COLOR(DEFAULT) " bem agora. Mas\n"
"eu não acho isso um bom mergulho."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"observei você. Você mergulhou\n"
COLOR(RED) "4 metros" COLOR(DEFAULT) " bem agora. Ainda\n"
"não é o suficiente!"
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"observei você. Você mergulhou\n"
COLOR(RED) "5 metros" COLOR(DEFAULT) " bem agora. Ainda\n"
"não é o suficiente!"
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"observei você. Você mergulhou\n"
COLOR(RED) "6 metros" COLOR(DEFAULT) " bem agora. Você\n"
"é capaz de mergulhar mais fundo!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pode não ter reparado, mas eu\n"
"observei você. Você mergulhou\n"
COLOR(RED) "7 metros" COLOR(DEFAULT) " bem agora. Você\n"
"é capaz de mergulhar mais fundo!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Pode não ter reparado, mas eu\n"
"observei você. Você " COLOR(RED) "tocou o\n"
"fundo" COLOR(DEFAULT) " bem agora. Fantástico!\n"
"Eu vou dar isto a você! "
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu mergulho é o melhor do mundo.\n"
"Por que não mergulha até o fundo\n"
"do Lago Hylia?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu nome é " COLOR(RED) "Pierre" COLOR(DEFAULT) ", o\n"
"espantalho andarilho. De fato, eu\n"
"queria poder procurar por sons\n"
"dançantes, mas estou preso aqui.      "
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Melodia fantástica! Toca meu\n"
"coração!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se conseguir uma canção legal,\n"
"volte e deixe-me ouvi-la!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A canção que você tocou para mim\n"
"está em meu coração. Toque-a\n"
"novamente." EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A música que você tocou está\n"
"em meu cpração!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, você quer pescar\n"
"por " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, não! Você não tem um " COLOR(RED) "Rumble\n"
"Pak" COLOR(DEFAULT) "! Com um Rumble Pak, pode\n"
"sentir as vibrações de um peixe\n"
"no seu anzol."
BOX_BREAK
"Desta vez não vai tremer!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Você tem um " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Hoje, você pode sentir a\n"
"vibração, jovem!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah! Você não tem dinheiro\n"
"suficiente."
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OK, ouça!"
BOX_BREAK
"Vá para a beira da água e aperte\n"
COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " para olhar para um peixe."
BOX_BREAK
"Enquanto olhar um peixe, você\n"
"pode jogar a linha com " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ".\n"
"Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para brecar a linha."
BOX_BREAK
"Quando a isca cair na água, você\n"
"poderá mexê-la com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Se for\n"
"iniciante, use também o " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
BOX_BREAK
"Rebobine a isca com " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Segure " COLOR(BLUE) "[A]" COLOR(DEFAULT) "\n"
"e " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para rebobinar mais\n"
"rápido."
BOX_BREAK
"Se sentir uma fisgada, aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) "\n"
"e " COLOR(LIGHTBLUE) "[Control-Pad] para baixo" COLOR(DEFAULT) " para firmar\n"
"o anzol. Depois disso, rebobine-o\n"
"com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
BOX_BREAK
"Você entendeu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT) " "
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sou tão generoso, vou deixá-lo\n"
"pescar o tempo que quiser. Porém,\n"
"poderá ficar com um peixe apenas."
BOX_BREAK
"O maior peixe já pescado aqui\n"
"pesava " COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "."
BOX_BREAK
"Depois de lançar, você pode mudar\n"
"a visão com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "."
BOX_BREAK
SHIFT("\x41") "Vamos pescar!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ha ha hah!\n"
"Você lançou o anzol apertando " COLOR(BLUE) "[A]" COLOR(DEFAULT) "\n"
"e " COLOR(LIGHTBLUE) "[Control-Pad] para baixo" COLOR(DEFAULT) "?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, o que houve?\n"
"Você o perdeu!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, bem... ele pesa " COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) ".\n"
"Você quer manter este?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que você quer?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Pesar meu peixe.\n"
"Vamos falar de alguma coisa.\n"
"Quero sair." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Só vontade não lhe fará pescar\n"
"muitos peixes. É sério!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "UTZ!"
BOX_BREAK
"Que peixe enorme! Parece um novo\n"
"recorde! Pesa pelo menos " COLOR(RED)  FISH_INFO "\n"
"libras" COLOR(DEFAULT) "! Sério!\n"
"OK, aqui está o seu prêmio!" EVENT " "
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?\n"
"O que está fazendo comigo?" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, jovem! Você não tem nada\n"
"importante que deveria estar\n"
"fazendo?"
BOX_BREAK
"O que? Está dizendo que é mais\n"
"divertido jogar aqui?"
BOX_BREAK
"Já vi muitas pessoas acabarem com\n"
"suas vidas com esse tipo de\n"
"atitude. É serio!\n"
"Oh meu..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já pego nesse tanque\n"
"pesava " FISH_INFO " libras.\n"
"O pescador: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer continuar pescando?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, ele pesa " COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "...\n"
"Nada mal, mas existem peixes\n"
"maiores aqui!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, cara! Você nem peixe tem!\n"
"Tss tss!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer tentar uma outra isca?\n"
"Do que você está falando?\n"
"Não está sendo egoísta?"
BOX_BREAK
"Você não conhece o ditado,\n"
"\"Um grande pescador nunca escolhe\n"
"a própria isca?\""
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que? Você quer saber alguns\n"
"segredos de pesca? Não posso\n"
"dizer nenhum. São segredos\n"
"comerciais. Sério!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que? Quer saber se  sou um bom\n"
"pescador?"
BOX_BREAK
"É claro que sou! Sou um velho\n"
"profissional! Sabe o que é isso,\n"
"não é?\n"
"Isso tudo é verdade!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regras e Regulamentos" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Não use iscas que afundam.\n"
"2.Não os espante.\n"
"3. Silêncio." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "4. Não lance em ninguém." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Este é realmente grande!\n"
"Vejamos...ele pesa " COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "!"
BOX_BREAK
"Quer ficar com este?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Volte aqui quando crescer!\n"
"Os peixes serão maiores também...\n"
"Bem, talvez."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, senhor! Eu lembro de você!\n"
"Há quanto tempo!"
BOX_BREAK
UNSKIPPABLE "Quantos anos se passaram?\n"
"Sete anos?! O que esteve fazendo\n"
"durante todo este tempo?!"
BOX_BREAK
UNSKIPPABLE "Você é meu único cliente. Estou\n"
"quase fora dos negócios! Sério!\n"
UNSKIPPABLE "Além disso, meu cabelo..."
BOX_BREAK
UNSKIPPABLE "Hum, digo, deixa pra lá..."
BOX_BREAK
UNSKIPPABLE "Bem, você quer pescar?\n"
"Custa apenas " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?"
BOX_BREAK
"Você quer pescar em um outro\n"
"tanque de pesca?!\n"
"Do que você está falando?"
BOX_BREAK
"Eu irei à falência se você for\n"
"para outro lugar!\n"
"É sério!  "
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?"
BOX_BREAK
"Você quer saber porque eu fico\n"
"me coçando toda hora?\n"
"Do que está falando?"
BOX_BREAK
"Na verdade, eu não tenho idéia.\n"
"É sério!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?"
BOX_BREAK
"Quer dizer que você não consegue\n"
"enxergar os peixes porque a água\n"
"é turva?"
BOX_BREAK
"Do que está falando?\n"
"Esta hora do dia é a melhor\n"
"para pescar!"
BOX_BREAK
"Você pode pegar um peixe e\n"
"tirá-lo da água quando menos\n"
"espera. Isso é excitante!"
BOX_BREAK
"É sério. Verdade, eu fico\n"
"excitado!  "
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, o que está fazendo?\n"
"Eu lhe disse para não fazer isso!\n"
"Você é terrível!\n"
"Sério!"
BOX_BREAK
"Devolva o meu chapéu!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que? Hum? Oh?\n"
"Acho que outro peixe já pego é\n"
"maior que este..."
BOX_BREAK
"Ainda quer ficar com ele?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Não, eu não quero\n"
"Sim, quero ficar com esse" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Caramba! O peixe que você pegou\n"
"é estranho! Além disso, ele pesa\n"
COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "!"
BOX_BREAK
"O que quer fazer com ele?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ficar com ele\n"
"Eu não quero ele" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau!"
BOX_BREAK
"Isso é o que eu estou achando\n"
"que é? Surpreendente!\n"
"Você pegou uma " COLOR(RED) "isca que afunda" COLOR(DEFAULT) "!"
BOX_BREAK
"O que vai fazer?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Usá-la agora.\n"
"Jogar fora." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, bem..."
BOX_BREAK
"UAU! Que peixe raro!\n"
"É uma " COLOR(RED) "Carpa de Hyrule" COLOR(DEFAULT) "!"
BOX_BREAK
"Para este peixe, o tamanho não\n"
"importa. Vou lhe dar este prêmio!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ultimamente, o número desses\n"
"peixes caiu tremendamente, então\n"
"eu vou soltar este aqui." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regras e Regulamentos\n"
"1. Não use iscas que afundam.\n"
"2. Não os espante.\n"
"3. Silêncio." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! Ei!\n"
"Não pode levar a vara para fora\n"
"daqui!"
BOX_BREAK
"Quando não quiser mais pescar,\n"
"devolva a vara ao balcão.\n"
"É sério!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh meu Deus!\n"
"Este peixe é gigante!!"
BOX_BREAK
"Um peixe grande assim nem cabe\n"
"na tela, a eu não posso pesá-lo\n"
"corretamente, mas parece que ele\n"
"pesa umas " COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "!!"
BOX_BREAK
"Vai querer ficar com esse,\n"
"certo?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Certo\n"
"Não quero ficar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, cara!\n"
"Sou " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", o espantalho!\n"
"Provavelmente já ouviu sobre\n"
"minha incrível memória!"
BOX_BREAK
"Se tiver uma música nova,\n"
"toque-a!"
BOX_BREAK
"Esta é a canção que tocou da\n"
"última vez, cara!"
BOX_BREAK
"Toque-a!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sou " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", o espantalho\n"
"e gênio musical!\n"
"Ouço uma música uma vez e nunca\n"
"me esqueço, cara!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Toque a música de sempre para\n"
"chamar Pierre!\n"
"Se estiver por perto, ele virá\n"
"ajudá-lo!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei! Você não é o camarada que\n"
"eu conheci há muito tempo?\n"
"Uau, você cresceu, cara!"
BOX_BREAK
"Bem, esta é sua canção..."
BOX_BREAK
"O que?"
BOX_BREAK
"Não, nunca esqueço!\n"
"Foi você quem esqueceu...\n"
"Não foi? Se tiver uma Ocarina,\n"
"toque esta canção, cara!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Você tem uma ocarina!\n"
"Ei, por que não toca uma música\n"
"para mim com ela?!" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem...nada mal!\n"
"Vou lembrar dela para você\n"
"então!"
BOX_BREAK
"Não significa que eu possa\n"
"lembrar de apenas oito notas, mas\n"
"vamos parar com isso assim\n"
"mesmo!" EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Toque-a assim e você jamais vai\n"
"comover o meu coração, cara!" EVENT "\n"
""
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"OH YEAHH!!\n"
"É isso aí, é essa a música!\n"
"Arrasou!! Estou detonado!"
BOX_BREAK
"Oh, não, não! Não esqueci a\n"
"canção...Eu nunca esqueço nada!\n"
"Mas eu quero recompensar você,\n"
"cara!"
BOX_BREAK
"........\n"
"Tenho uma boa idéia!"
BOX_BREAK
"Meu amigo Pierre está zanzando\n"
"por aí, então toque essa música\n"
"quando quiser chamá-lo!"
BOX_BREAK
"Eu vou dizer a ele para lhe\n"
"ajudar caso ele ouça esta canção,\n"
"cara!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, é a Ocarina!\n"
"Toque aquela canção com ela,\n"
"cara!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Mocinho, você toca a Ocarina\n"
"muito bem... Mmmm...! Essa\n"
"melodia é tão boa...ribbit! Nós\n"
"todos devemos praticá-la!"
BOX_BREAK
"Pegue Rupees de lembrança!\n"
"Se tiver outra melodia legal, por\n"
"favor, venha aqui e toque-a...\n"
"Ribbit ribbit ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Uau, essa melodia é muito legal!\n"
"Ribbit!"
BOX_BREAK
"Cantaaaanndo na chuuuva,\n"
"Oh que emoção!\n"
"Rrrrribbbit!!"
BOX_BREAK
"Por favor, pegue isto como um\n"
"símbolo de nossa gratidão\n"
"saponiana, ribbit! Ok, tchau,\n"
"ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Olhe para nós, somos rãs enormes!\n"
"Somos os mundialmente famosos\n"
"Cinco Fabulosos Tenores Rãs!!\n"
"Rrribbit!!"
BOX_BREAK
"Faça-nos pular para podermos\n"
"comer os insetos, ribbit!"
BOX_BREAK
"OK?\n"
"Preparar, apontar, já!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Jovem, foi formidável!\n"
"Perrrrfeito!\n"
"Estamos cheios, ribbit!"
BOX_BREAK
"Ficaria com este símbolo de\n"
"nossa gratidão?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, eu não me lembro dessa\n"
"música, cara. Por que? Isso eu\n"
"não posso dizer!\n"
"Meu Deus!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já pego neste\n"
"tanque pesava " FISH_INFO " libras.\n"
"O pescador: o dono do tanque" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que?\n"
"Você quer pescar com uma isca\n"
"diferente?\n"
"...Ei, o que é isso?"
BOX_BREAK
"O que? Você pegou agora?\n"
"Geralmente, as regras dizem que\n"
"não pode usar um desses. Digo,\n"
"Geralmente. Mas, que diabos..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAHOOOOOO!\n"
"Este é ENORME!! Novo recorde!!\n"
"Ele...ele pesa cerca de...\n"
COLOR(RED)  FISH_INFO " libras" COLOR(DEFAULT) "!!"
BOX_BREAK
"Maaaaaaaas! Essa isca que afunda\n"
"viola as regras!\n"
"Então, vai ficar sem prêmio.\n"
"Uah ha ha ha ha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já pego neste\n"
"tanque pesava " FISH_INFO " libras.\n"
"O pescador: " NAME "\n"
"(NOTA: Com uma isca ilegal.)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem um bom coração, garoto!\n"
"Mas não conte isso a ninguém.\n"
"Sério!" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O QUEEEE?!?"
BOX_BREAK
"Por que está fazendo isso\n"
"comigo? O que está pensando?"
BOX_BREAK
"Não vai sair dessa tão fácil!\n"
"Você tem que me pagar uns bons\n"
COLOR(RED) "50-Rupees" COLOR(DEFAULT) "!\n"
"É sério!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "BAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Você" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "me" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "matou!!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Hum? Oh, é você."
BOX_BREAK
"Já tentou tocar a " COLOR(YELLOW) "Canção\n"
"do Sol" COLOR(DEFAULT) "?"
BOX_BREAK
"Como já lhe disse, com essa\n"
"canção, você pode transformar o\n"
"dia em noite ou a noite em dia\n"
"quando quiser."
BOX_BREAK
"Quando estiver no escuro, essa\n"
"canção pode lhe trazer a luz do\n"
"sol. Você deveria tentar."
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Quando cavei um buraco, eu achei\n"
"um tesouro que estica--BOING!\n"
"e encolhe--BOING! É tão engraçado,\n"
"Não vou dá-lo a ninguém!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"O " COLOR(RED) "diário do coveiro" COLOR(DEFAULT) " está aqui.\n"
"Você quer ler?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Quem ler isto, por favor entre\n"
"em meu túmulo. Eu lhe darei\n"
"minha " COLOR(RED) "dádiva" COLOR(DEFAULT) " que estica\n"
"e encolhe." QUICKTEXT_DISABLE
BOX_BREAK
QUICKTEXT_ENABLE "Espero por você.\n"
"--Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Você decidiu não ler isto..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você derrotou o Fantasma!"
BOX_BREAK
"Quer capturá-lo em um\n"
"frasco?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você quer capturá-lo mas não\n"
"tem um frasco vazio."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você o libertou agora."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você pegou um!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x16") "O sol nascente vai se pôr,\n"
SHIFT("\x0F") "Uma vida que nasce vai sumir." QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x05") "Do sol para a lua, da lua para o sol..." QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x28") "Dê o descanso eterno\n"
SHIFT("\x36") "aos mortos-vivos." QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "É um poema interessante...\n"
"Hum?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "Almas penadas vagam\n"
SHIFT("\x1D") "onde elas não pertencem,\n"
SHIFT("\x22") "Dê-lhes o sossego com a\n"
SHIFT("\x36")  COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Alguma coisa está inscrita na\n"
"lápide..."
BOX_BREAK
UNSKIPPABLE "É a " COLOR(YELLOW) "melodia secreta" COLOR(DEFAULT) " dos\n"
"Irmãos Compositores!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Poção definitiva! Que tal\n"
COLOR(RED) "100 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se mudar de idéia, volte para\n"
"me visitar...\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem Rupees suficientes!\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "BAAAAAH!\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "VOCÊ" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ME" QUICKTEXT_DISABLE " MATOU..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Incrível!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Oh, o que?\n"
"Você não seria um dos de\n"
"Ganondorf, não é?"
BOX_BREAK
UNSKIPPABLE "Por causa do meu papel como\n"
"fantasma, tenho que agir assim.\n"
"Desculpe-me."
BOX_BREAK
UNSKIPPABLE "Agora, deixe eu me apresentar.\n"
"Hamham..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sou um dos irmãos compositores\n"
"fantasmas da Vila Kakariko."
BOX_BREAK
"Todas as pessoas nesta vila\n"
"nascem para servir à Família\n"
"Real de Hyrule."
BOX_BREAK
"Nós irmãos também servimos à\n"
"Família Real, e fomos designados\n"
"para estudar os poderes místicos\n"
"hereditários da família."
BOX_BREAK
"Embora nunca pudéssemos descobrir\n"
"o poder da Triforce,"
BOX_BREAK
"nós quase completamos nosso\n"
COLOR(RED) "estudo do controle do tempo" COLOR(DEFAULT) "\n"
"com os sons das ocarinas."
BOX_BREAK
"Hum, digo..."
BOX_BREAK
"Na verdade, nós completamos\n"
"esse estudo!"
BOX_BREAK
"Nós teríamos ficado famosos, se\n"
"aquele odioso Ganondorf não\n"
"tivesse tentado roubar os\n"
"resultados."
BOX_BREAK
"Não podíamos deixá-lo colher os\n"
"frutos de nossa pesquisa!"
BOX_BREAK
"É por isso que demos nossas\n"
"vidas para manter o segredo." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer ouvir o que eu\n"
"disse novamente?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "BAAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "ESTOU" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORTO" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DE" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "NOVO!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"O que? Você de novo?"
BOX_BREAK
UNSKIPPABLE "De certo modo, você me lembra...\n"
"a Princesa Zelda..."
BOX_BREAK
UNSKIPPABLE "Hmm...Já que você tem alguma\n"
"conexão com a Família Real, vou\n"
"dizer um pouco mais do conto."
BOX_BREAK
UNSKIPPABLE "Então, chamaram-nos de grandes\n"
"compositores pelos vários\n"
"primores musicais que escrevemos."
BOX_BREAK
UNSKIPPABLE "Mas nós irmãos não éramos\n"
"apenas compositores."
BOX_BREAK
UNSKIPPABLE "Tínhamos a missão de analisar\n"
"os misteriosos poderes da Família\n"
"Real de Hyrule."
BOX_BREAK
UNSKIPPABLE "Nossos nomes seriam parte\n"
"da história de Hyrule caso\n"
"completássemos a pesquisa!"
BOX_BREAK
UNSKIPPABLE "Mantivemos nossos estudos bem\n"
"secretos até o completarmos." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "BAAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "ESTOU" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORTO" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DE" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "NOVO!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"O que? Você de novo?"
BOX_BREAK
UNSKIPPABLE "Você me lembra a Princesa\n"
"Zelda."
BOX_BREAK
UNSKIPPABLE "Já que você deve ter alguma\n"
"conexão com a Família Real, eu\n"
"vou lhe dizer um pouco mais de\n"
"nosso conto." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para dizer a verdade, nós\n"
"estudávamos canções diferentes,\n"
"uma para " COLOR(RED) "invocar o sol" COLOR(DEFAULT) " e\n"
"outra para " COLOR(RED) "invocar a lua" COLOR(DEFAULT) "."
BOX_BREAK
"Se você realmente foi enviado\n"
"por um membro da Família Real,\n"
"eu vou lhe dizer os resultados\n"
"dos nossos estudos."
BOX_BREAK
"Nós os inscrevemos no " COLOR(RED) "túmulo\n"
"real" COLOR(DEFAULT) "."
BOX_BREAK
"Como mensageiro da Família Real,\n"
"deve mostrar suas credenciais\n"
"Reais ao topo da marca da\n"
"Triforce..." TEXTID("\x50\x11") " "
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z..."
BOX_BREAK
"Malon...está tudo bem...\n"
"Grunf...Grunf...\n"
"Perdoe-me pela preocupação..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo tomou o Rancho Lon Lon e\n"
"o chama de " COLOR(RED) "Rancho Ingo" COLOR(DEFAULT) " agora."
BOX_BREAK
"Eu fui chutado de lá, e olhe\n"
"para mim agora! Minha garota,\n"
"Malon, ainda trabalha no rancho..."
BOX_BREAK
"Estou preocupado com ela..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você salvou Malon? Obrigado!\n"
"Vou voltar para o rancho, então!\n"
"Iiiahah!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Ei garoto!" QUICKTEXT_DISABLE "\n"
"Não bagunce nem suje os\n"
"túmulos!"
BOX_BREAK
UNSKIPPABLE "Sou " COLOR(RED) "Dampé o Coveiro" COLOR(DEFAULT) "!\n"
"Meu rosto pode ser assustador,\n"
"mas eu não sou mau..."
BOX_BREAK
UNSKIPPABLE "Deixe-me fazer uma propaganda\n"
"do meu trabalho alternativo..."
BOX_BREAK
UNSKIPPABLE "O Assustador " COLOR(LIGHTBLUE) "Passeio Cava-Cova" COLOR(DEFAULT) "\n"
"de " COLOR(RED) "Dampé, o Coveiro" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "O que vai sair?!\n"
"O que vai sair?!\n"
"Quando eu começar a cavar,\n"
"Nós vamos descobrir!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer que eu cave aqui?\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " por um buraco.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não faça isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Não, nada por aqui!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Afaste-se " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....\n"
"Uma coisa terrível aconteceu!\n"
"O " COLOR(RED) "Espírito das Sombras" COLOR(DEFAULT) " foi\n"
"libertado!"
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", a líder da Vila\n"
"Kakariko, lacrou o maligno\n"
"espírito das sombras no fundo\n"
"do poço...."
BOX_BREAK
UNSKIPPABLE "Mas a força do espírito maligno\n"
"ficou tão forte que o lacre do\n"
"poço se quebrou, e ele escapou\n"
"pelo mundo!!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Deixe-me tomar conta da vila!\n"
"Conto com você, " NAME "!"
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Irmãos Compositores Reais\n"
"" SHIFT("\x37") "Sharp o Velho\n"
"" SHIFT("\x50") "D.E.P" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Irmãos Compositores Reais\n"
" " SHIFT("\x33") "Flat o Jovem\n"
" " SHIFT("\x50") " D.E.P " QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") " Túmulo da Família Real " QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x09") "Este poema é dedicado à memória\n"
SHIFT("\x14") "dos membros queridos mortos\n"
SHIFT("\x39") "da Família Real." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O garoto com a nobre Ocarina de\n"
"Zelda...Como eu esperava,\n"
"você veio."
BOX_BREAK
UNSKIPPABLE "Eu sou " COLOR(RED) "Impa" COLOR(DEFAULT) ", um dos Sheikah.\n"
"Sou a tutora da Princesa Zelda,\n"
"e também sou a Sábia que guarda\n"
"o Templo da Sombra."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Por favor, cuide bem da Princesa!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", o herói!"
BOX_BREAK
UNSKIPPABLE "Finalmente, todos nós, os " COLOR(RED) "seis\n"
"Sábios" COLOR(DEFAULT) ", despertamos! A hora\n"
"da batalha final com o Rei do\n"
"Mal chegou!"
BOX_BREAK
UNSKIPPABLE "Antes disso, porém, você deve\n"
"se encontrar com alguém que está\n"
"esperando por você..."
BOX_BREAK
UNSKIPPABLE "Alguém que o está esperando no\n"
COLOR(LIGHTBLUE) "Templo do Tempo" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nós Sheikah servimos a realeza\n"
"de Hyrule de geração a geração\n"
"como criados.\n"
"Porém..."
BOX_BREAK
UNSKIPPABLE "Naquele dia, sete anos atrás,\n"
"Ganondorf de repente atacou...\n"
"e o Castelo de Hyrule se entregou\n"
"depois de pouco tempo."
BOX_BREAK
UNSKIPPABLE "O objetivo de Ganondorf era uma\n"
"das chaves para o Reino Sagrado...\n"
"o tesouro escondido da Família\n"
"Real...A Ocarina do Tempo!"
BOX_BREAK
UNSKIPPABLE "Meu dever me obrigou a levar\n"
"Zelda fora do alcance de\n"
"Ganondorf."
BOX_BREAK
UNSKIPPABLE "Na última vez que nos vimos,\n"
"quando escapamos do castelo, você\n"
"era apenas um garoto..."
BOX_BREAK
UNSKIPPABLE "Agora vejo que se tornou um\n"
"ótimo herói..."
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tenho que ficar aqui... Fique\n"
"perto da Princesa Zelda e a\n"
"proteja junto comigo."
BOX_BREAK
UNSKIPPABLE "Agora eu coloco meu poder,\n"
"que lhe deve ser muito útil,\n"
"neste " COLOR(BLUE) "Medalhão" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como está seu Cucco? Ele está\n"
"feliz? Devo checá-lo para você?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Sou o " COLOR(RED) "mestre dos carpinteiros" COLOR(DEFAULT) "\n"
"que Impa contratou para melhorar\n"
"esta vila e transformá-la numa\n"
"cidade!"
BOX_BREAK
UNSKIPPABLE "Mas, jovens, hoje em dia não têm\n"
"nenhuma ambição... Sabe do que eu\n"
"falo, garoto?"
BOX_BREAK
UNSKIPPABLE "Meus homens estão apenas correndo\n"
"pela vila sem objetivo, e não\n"
"estão progredindo..."
BOX_BREAK
UNSKIPPABLE "Até meu próprio filho não tem\n"
"trabalho, ele apenas vaga por aí\n"
"todos os dias!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Digo a você que são todos inúteis!!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olhe para aquela pobre garota.\n"
"Ela trabalha tão duro cuidando\n"
"de suas galinhas, mesmo que\n"
"tocá-las lhe cause um mal-estar..."
BOX_BREAK
"Que besteira! Eu realmente\n"
"gostaria de ajudá-la! Estou me\n"
"sentindo tão caridoso esses dias!\n"
"Também não se sente assim?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não há nada para se preocupar...\n"
"A Princesa está segura."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Breve, você vai se encontrar com\n"
"a Princesa Zelda cara a cara, e\n"
"ela explicará tudo..."
BOX_BREAK
UNSKIPPABLE "Será quando nós, os seis Sábios,\n"
"lacrarmos o Rei do Mal e\n"
"trouxermos a paz a Hyrule."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe, jovem...\n"
"Você foi muito rápido para\n"
"conseguir ficar junto comigo!"
BOX_BREAK
UNSKIPPABLE "Como prêmio, eu vou lhe dar\n"
"o meu tesouro. Ele se chama\n"
COLOR(RED) "Gancho" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Suas correntes enroladas em\n"
"molas vão levá-lo a qualquer\n"
"lugar onde o gancho pregar. Não\n"
"é legal? Certamente vai te ajudar!"
BOX_BREAK
UNSKIPPABLE "Eu moro aqui agora, então volte\n"
"novamente uma outra hora. Vou lhe\n"
"dar algo legal!"
BOX_BREAK
UNSKIPPABLE "Mais uma coisa! Tome cuidado\n"
"em seu caminho de volta!\n"
"Heheheh...."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você voltou, jovem...\n"
"O presente que eu lhe dei foi\n"
"divertido e útil?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "O tempo desta corrida foi\n"
SHIFT("\x4B")  RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você parece estar voltando a si..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Acredito que Impa foi lacrar o\n"
COLOR(PURPLE) "Templo da Sombra" COLOR(DEFAULT) " novamente,\n"
"mas...ela estará em perigo sem\n"
"nenhuma ajuda!"
BOX_BREAK
UNSKIPPABLE  NAME "!\n"
"Impa é um dos seis Sábios.\n"
"Destrua o espírito das sombras e\n"
"salve Impa!"
BOX_BREAK
UNSKIPPABLE "Existe uma entrada para o\n"
"Templo da Sombra abaixo do\n"
"cemitério por trás desta vila."
BOX_BREAK
UNSKIPPABLE "A única coisa que posso fazer\n"
"é ensiná-lo a melodia que irá\n"
"levá-lo ao Templo da Sombra..."
BOX_BREAK
UNSKIPPABLE "Esta é a melodia que irá jogá-lo\n"
"na escuridão infinita que absorve\n"
"até o tempo... Ouça isto,\n"
"você vai se arrepiar!!"
BOX_BREAK
UNSKIPPABLE "É o " COLOR(PURPLE) "Noturno das Sombras" COLOR(DEFAULT) "!! "
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dê voltas! Dê voltas e voltas\n"
"e voltas! Que legal! Estou tão\n"
"feliz!"
BOX_BREAK
"Eu sou um músico que ama\n"
"dar voltas e voltas! Dê voltas\n"
"e voltas!!!"
BOX_BREAK
"Estou tentando criar um tema\n"
"musical inspirado por este\n"
"moinho...dando voltas e voltas\n"
"e voltas e voltas!!!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dê voltas, dê voltas, dê voltas...\n"
"O que? Está indo muito rápido!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!"
BOX_BREAK
"Nunca me esquecerei do que\n"
"aconteceu naquele dia, sete anos\n"
"atrás!\n"
"Grrrrrrr!"
BOX_BREAK
"É tudo culpa do garoto da\n"
"Ocarina! Se ele aparecer de novo,\n"
"eu vou acabar com ele!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que?! Você tem uma Ocarina!"
BOX_BREAK
UNSKIPPABLE "Que droga!"
BOX_BREAK
UNSKIPPABLE "Isso me lembra daquele dia,\n"
"sete anos atrás!"
BOX_BREAK
UNSKIPPABLE "Um desprezível garoto veio aqui\n"
"e tocou uma " COLOR(PURPLE) "Canção Estranha" COLOR(DEFAULT) ".\n"
"Ela acabou com esse moinho!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que eu faço!?\n"
"Meus " COLOR(RED) "Cuccos" COLOR(DEFAULT) " foram todos\n"
"embora!"
BOX_BREAK
"Você, garotinho, por favor!\n"
"Ajude a trazê-los de volta ao\n"
"galinheiro!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Ajude-me a trazer os outros\n"
"quatro de volta a este galinheiro!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Ajude-me a trazer os outros três\n"
"de volta a este galinheiro!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Ajude-me a trazer os outros dois\n"
"de volta a este galinheiro!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Ajude-me a trazer o último de\n"
"volta a este galinheiro!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado por encontrar meus\n"
"Cuccos. Eu tenho alergias, então\n"
"eu passo mal quando os toco."
BOX_BREAK
UNSKIPPABLE "Por me ajudar, vou dar isto a\n"
"você. É um vidro bom, e deve ser\n"
"útil. Por favor, tome cuidado\n"
"com isso!" EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o que está fazendo?!\n"
"Agora vá procurá-los ou pague\n"
"por eles!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não incomode meus Cuccos!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu criei um novo tipo de Cucco\n"
"miniatura! Eu o chamo de " COLOR(RED) "Cucco\n"
"de Bolso" COLOR(DEFAULT) "! Eu não passei mal\n"
"com este bebê."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Cuccos" COLOR(DEFAULT) " são muito preguiçosos,\n"
"acordam muito tarde. Você já não\n"
"ouviu sobre eles antes?"
BOX_BREAK
UNSKIPPABLE "Ficam muito felizes ao cantar:\n"
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(RED) "CUCCKOOOO" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Especialmente quando acordam um\n"
"dorminhoco com sono pesado!"
BOX_BREAK
UNSKIPPABLE "Porém, meu Cucco não está\n"
"totalmente feliz agora..."
BOX_BREAK
UNSKIPPABLE "Você...,\n"
"Você parece que é bom em cuidar\n"
"de Cuccos."
BOX_BREAK
UNSKIPPABLE "Aqui, pegue este ovo.\n"
"Depois que o Cucco chocar,\n"
"traga-o de volta para que eu\n"
"cheque a disposição dele." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você acha?\n"
"Vai tentar?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, que pena...foi picado por um\n"
"Cucco quando era pequeno?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"He he he, jovem!\n"
"Você é rápido com os pés?"
BOX_BREAK
"Posso não parecer, mas eu\n"
"confio em minha velocidade!\n"
"Vamos ter uma corrida!\n"
"Siga-me se puder! "
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Faça meu Cucco feliz!\n"
"OK?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, seu Cucco parece muito feliz!\n"
"Ele deve ter acordado um cara\n"
"muito preguiçoso!"
BOX_BREAK
UNSKIPPABLE "Você é um bom criador de Cuccos!\n"
"Vou lhe dar um raro e valioso\n"
"Cucco, se interessar..."
BOX_BREAK
UNSKIPPABLE "Seu nome é " COLOR(RED) "Cojiro" COLOR(DEFAULT) ", e ele era\n"
"o Cucco do meu irmão. Seu corpo\n"
"azul é um tanto atraente. Ele\n"
"é tão lindo!"
BOX_BREAK
UNSKIPPABLE "Desde que meu irmão se foi,\n"
"é estranho, mas Cojiro parou\n"
"de cantar." TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer cuidar de " COLOR(RED) "Cojiro" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Realmente parece que você gosta\n"
"desse outro Cucco. OK, pode ficar\n"
"com ele." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uma velha bruxa tem uma Loja de\n"
"Poções abaixo desta. Você pode\n"
"chegar lá passando pela porta à\n"
"esquerda do balcão." EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu irmão devia estar muito\n"
"solitário..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu ouvi que o " COLOR(ADJUSTABLE) "Bosque Perdido" COLOR(DEFAULT) ",\n"
"onde as fadas vivem, é um lugar\n"
"estranho com muitos aromas\n"
"misteriosos."
BOX_BREAK
"Eu gostaria de fazer remédios com\n"
"algumas das coisas estranhas que\n"
"eu achasse por lá..."
BOX_BREAK
"Posso não ser capaz de enxergar\n"
"muito bem, mas meu nariz ainda\n"
"funciona bem! He he he!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sniff sniff sniff..."
BOX_BREAK
"Que aroma misterioso..."
BOX_BREAK
"Você deve ter alguma coisa!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele vagabundo! Entrou na\n"
"floresta...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "Entendo." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, dê-me isso agora!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chato... Preciso de um pouco..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se vir aquele imbecil, dê isto a\n"
"ele. É o medicamento mais forte\n"
"que eu já produzi."
BOX_BREAK
UNSKIPPABLE "Todavia, essa poção não\n"
"funcionará em um monstro..." EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, garoto! Se quer carregar\n"
"medicamentos, precisa de algo\n"
"para colocar!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Disseram que não existe cura\n"
"para um cara imbecil...\n"
"Acho que é verdade..."
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não posso descer, tudo que faço\n"
"é olhar a " COLOR(RED) "Montanha da Morte" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não posso descer, tudo que faço\n"
"é olhar as estrelas."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Podes ver daqui?\n"
"Tem algo acontecendo na\n"
COLOR(RED) "Montanha da Morte" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Podes ver daqui?\n"
"A " COLOR(RED) "Montanha da Morte " COLOR(DEFAULT) "\n"
"voltou ao normal!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não sinto vontade de descer,\n"
"agora! Talvez aconteça, mas\n"
"prefiro ficar olhando a Montanha\n"
"da Morte aqui."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei! Que bom vê-lo de novo!\n"
"Vou lhe dar isto como\n"
"lembrança."
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para ver melhor, use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " e\n"
"movimente com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Garoto, você sempre entra\n"
"na casa dos outros sem permissão?\n"
"Seus pais não lhe ensinaram boas\n"
"maneiras?"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Ok então."
BOX_BREAK
UNSKIPPABLE "Você viu uma dama atrás desta\n"
"casa? Ela está passando maus\n"
"momentos."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Ok então." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se essa dama lhe perguntar sobre\n"
"galinhas, dê ouvidos a ela."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Visitar a casa alheia a esta\n"
"hora da noite é sua idéia de\n"
"diversão? Você não deve ter\n"
"nenhuma educação."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Oh meu Deus." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquela dama toma conta das\n"
"galinhas, mas ela é, de fato,\n"
"alérgica a elas."
BOX_BREAK
SHIFT("\x42") "Ok..."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Jovem! Um garoto forte\n"
"como você entrando na casa das\n"
"pessoas sem permissão? Quero\n"
"falar com seus pais!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Meu Deus."
BOX_BREAK
UNSKIPPABLE "Esta não é mais minha casa.\n"
"Agora é a casa de " COLOR(RED) "Impa" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Impa foi para o " COLOR(RED) "cemitério" COLOR(DEFAULT) "\n"
"selar a criatura estranha lá."
BOX_BREAK
UNSKIPPABLE "Desde que Ganondorf apareceu,\n"
"muitos monstros têm sido vistos\n"
"pelas redondezas."
BOX_BREAK
UNSKIPPABLE "Somente a grande Impa manteve a\n"
"paz em nosso povoado. Você tem\n"
"que lembrar disso, jovem!"
BOX_BREAK
UNSKIPPABLE  SHIFT("\x42") "Oh meu Deus."
BOX_BREAK
UNSKIPPABLE "Falando na formidável Impa, ela\n"
"ainda não retornou. Eu queria\n"
"saber o que aconteceu com ela!?" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ouvi sobre um " COLOR(RED) "fantasma do\n"
"coveiro " COLOR(DEFAULT) "que geralmente aparece\n"
"no cemitério atrás deste\n"
"povoado..."
BOX_BREAK
SHIFT("\x34") "Mas, nunca o vi."
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oi, Garoto! Essa é a primeira vez\n"
"que visita o povoado?"
BOX_BREAK
UNSKIPPABLE "Uma grande mulher, " COLOR(RED) "Impa" COLOR(DEFAULT) ", fundou\n"
"esta vila para nós." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, sinta-se em casa.\n"
"A comida ainda não está pronta,\n"
"certo!?"
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A Grande Impa não está aqui.\n"
"Aconteceu algo a ela?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Todas as pessoas têm coisas em\n"
"seus passados que não gostariam\n"
"que ninguém soubesse." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Veja o homem barbudo dormindo\n"
"bem ali. Aposto que até alguém\n"
"como ele tenha tido muitos\n"
"problemas no passado..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquele homem barbudo voltou ao\n"
"rancho. Ele parecia tão feliz!"
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ding dong, ding dong!\n"
"Sou um soldado-relógio de\n"
"Kakariko!\n"
"A hora atual é: " TIME "."
BOX_BREAK
UNSKIPPABLE "Olá, filho.\n"
"A babá de Zelda, a grande " COLOR(RED) "Impa" COLOR(DEFAULT) ",\n"
"fundou esta vila para pessoas comuns."
BOX_BREAK
UNSKIPPABLE "Temos uma pequena população\n"
"agora, mas um dia aqui será tão\n"
"movimentado quanto a Cidade do\n"
"Castelo de Hyrule! Oh sim! Vai!"
BOX_BREAK
UNSKIPPABLE "Suba as " COLOR(RED) "escadas no extremo\n"
"norte" COLOR(DEFAULT) " da vila para encontrar\n"
"a trilha que leva à Montanha da\n"
"Morte."
BOX_BREAK
UNSKIPPABLE "Mas você precisa da permissão\n"
"do Rei para realmente subir a\n"
"montanha."
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME "."
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME ".\n"
"Você sabe o que aconteceu no\n"
"castelo?"
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, filho, o que está fazendo\n"
"zanzando por aí a esta hora da\n"
"noite?"
BOX_BREAK
UNSKIPPABLE "Oh, entendi. Está testando sua\n"
"coragem, não é mesmo? Você devia\n"
"querer ir ao...cemitério!"
BOX_BREAK
UNSKIPPABLE "Espere aí! O que estou fazendo\n"
"falando com um garoto? Tenho um\n"
"trabalho a fazer!" TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME "."
BOX_BREAK
"Siga a leste para achar um\n"
COLOR(RED) "cemitério" COLOR(DEFAULT) "."
BOX_BREAK
"Diz a lenda que você\n"
"pode acalmar as almas dos mortos\n"
"com uma " COLOR(BLUE) "velha canção da\n"
"Família Real" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem um cara estranho vivendo no\n"
"Moinho. Já o conhece,\n"
"Sr. Herói?"
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As pessoas são repugnantes.\n"
"Meus próprios pais são também.\n"
"Você deve ser repugnante, também!"
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O dia todo, trabalhamos em vários\n"
"projetos de construção nesta vila.\n"
"Vai demorar bastante até que\n"
"tudo esteja terminado."
BOX_BREAK
"Nosso chefe nos faz trabalhar\n"
"muito!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Estou faminto!\n"
"Vamos jantar logo!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esses caras fazem o trabalho de\n"
"meio homem, mas querem uma porção\n"
"inteira! São preguiçosos, estou\n"
"te dizendo!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Fantasma  30 Rupees\n"
COLOR(DEFAULT) "É um espírito no frasco.\n"
"Venda a alguém que seja louco\n"
"por coisas estranhas como essas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fantasma 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Levar\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor pegue mais seis!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE)  NAME "!\n"
"Esse barco está afundando!\n"
"Abandonar navio!\n"
"Vamos sair!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ainda faltam alguns Cuccos!\n"
"Por favor, ache mais cinco!"
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Não cause problemas ou\n"
"conto a Dampé!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Veja isto, garoto! Minhas belas\n"
"e suaves mãos estão calejadas do\n"
"trabalho. Tsc tsc..."
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Trabalhar e ganhar muito dinheiro\n"
"sem se esforçar...A única coisa\n"
"que consigo pensar é o roubo...\n"
"Você acha uma má idéia?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ouvi dizer que a casa do chefe é\n"
"logo atrás dessa casa. Mas ele\n"
"não quer que nenhum de nós\n"
"saiba."
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu o " COLOR(RED) "Sr. Dampé" COLOR(DEFAULT) ", que\n"
"vive lá no cemitério?"
BOX_BREAK
"São " TIME " agora, então ele deve\n"
"estar dormindo em sua cabana."
BOX_BREAK
"Por que não vai lá fora no campo\n"
"para matar o tempo?"
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Estou faminto!\n"
"O jantar não está pronto?\n"
"Já são " TIME "!"
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Essa costumava ser a " COLOR(RED) "casa\n"
"da grande Impa" COLOR(DEFAULT) ", mas ela não\n"
"vive mais aí."
BOX_BREAK
UNSKIPPABLE "É agora aberta a todos\n"
"os habitantes. Você é livre para\n"
"visitá-la." TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse vilarejo costumava ser um\n"
"vilarejo " COLOR(BLUE) "Sheikah" COLOR(DEFAULT) ", mas a\n"
"grande Impa o abriu para\n"
"todos."
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou dizendo, eu o vi!"
BOX_BREAK
"Eu vi o fantasma de Dampé\n"
"o coveiro afundando na cova dele.\n"
"Parecia que ele estava segurando\n"
"algum tipo de " COLOR(RED) "tesouro" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Era ele! Era ele!\n"
"Foi ele que caiu do céu envolvido\n"
"por uma luz azul!"
BOX_BREAK
"Você acredita em mim agora?"
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ninguém acredita no que venho\n"
"dizendo a todos nesse últimos\n"
"sete anos!"
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O fogo quase consumiu todos nós!\n"
"Mas juntos, fomos capazes de\n"
"acabar com o fogo! Belo trabalho,\n"
"você não acha?"
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uah ha ha ha ha ha ha!!!"
BOX_BREAK
"Veja esse cara! Desde que\n"
"ele escapou do Castelo de Hyrule,\n"
"ele ficou mais medroso!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Wah hah hah hah hah hah!"
BOX_BREAK
"Ele deve estar vendo coisas!\n"
"Uah ha ha ha ha ha ha!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uah ha ha ha ha ha ha!\n"
"Essas roupas são muito\n"
"engraçadas, cara!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uah ha ha ha ha ha ha!\n"
"Quando os tempos estão ruins,\n"
"rir é o melhor remédio! É o que\n"
"o meu pai sempre dizia!"
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olhe para mim! Estou no topo do\n"
"mundo! Sempre me irrita ver\n"
"alguém em um nível mais alto que\n"
"eu! Tenho que estar no topo!"
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu cair no sono aqui,\n"
"certamente irei cair..."
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O moinho puxa a água lá do\n"
"fundo do poço."
BOX_BREAK
"Porém, agora o poço está seco.\n"
"Hrrrrm..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A dama daqui é realmente\n"
"generosa. Ela sempre cuida dos\n"
"carpinteiros quando eles vêm\n"
"aqui!"
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Há muito tempo atrás...\n"
"Havia um homem nesta vila que\n"
"tinha um olho que diziam poder\n"
"ver a verdade!"
BOX_BREAK
"Agora, você tem que treinar seu\n"
"olho mental e ativamente para\n"
"poder ver a verdade..."
BOX_BREAK
"Mas ele, não, dizem que ele\n"
"tinha uma forma diferente de\n"
"fazer as coisas..."
BOX_BREAK
"Sua casa ficava onde hoje é\n"
"o poço..."
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Os boatos daqui falam sobre uma\n"
COLOR(RED) "família fabulosamente rica" COLOR(DEFAULT) "\n"
"que vivia em uma das casas deste\n"
"vilarejo..."
BOX_BREAK
"Dizem também que esta tal família\n"
"foi amaldiçoada por causa da sua\n"
"ganância!"
BOX_BREAK
"É o que acontece aos que são\n"
"consumidos pela ganância..."
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh..."
BOX_BREAK
"Que pessoa chata,\n"
"interrompendo-nos neste\n"
"momento...\n"
"Não concorda, meu amor?"
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee..."
BOX_BREAK
"Violando nosso espaço pessoal!\n"
"Ele deve ter algo melhor para\n"
"fazer...\n"
"Não concorda, querido?"
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olhe só para ele... o cara\n"
"barbudo.\n"
"Acho que ele foi expulso do\n"
"trabalho lá no rancho" TEXTID("\x50\x9C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ele sempre fica vagabundando, de\n"
"manhã, de tarde e de noite.\n"
"Ele é de fato um cara folgado\n"
"nesses dias difíceis."
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esse preguiçoso, ele adora me\n"
"lembrar do meu Ricardinho..."
BOX_BREAK
"O que disse? Está dizendo que\n"
"nunca ouviu falar do meu\n"
"Ricardinho? Ele era um filhote\n"
"tão famoso!"
BOX_BREAK
UNSKIPPABLE "Sério, nunca ouviu falar dele?"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, não! Um raio de novo!!\n"
"Você tocou a Ocarina de novo,\n"
"não foi!!\n"
"Grrrrrrrrrrrrrrr!!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você pegou um Fantasmão!\n"
"Venda-o numa " COLOR(RED) "Loja de Fantasmas" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Parado! Fique onde está!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato! Espere aí que\n"
"abrirei o portão para você."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Não nos subestime!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu vi seu belo trabalho. Para\n"
"passar pelos guardas daqui, só\n"
"tendo técnicas de ladrão."
BOX_BREAK
UNSKIPPABLE "Eu costumava pensar que todos os\n"
"homens, além do grande Ganondorf,\n"
"eram inúteis...mas agora que o vi,\n"
"não penso mais assim!"
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "A louvada Nabooru" COLOR(DEFAULT) ", nossa\n"
"líder, encarregou-me da fortaleza."
BOX_BREAK
UNSKIPPABLE "Nabooru é a segunda no\n"
"comando do grande Ganondorf, Rei\n"
"dos Ladrões Gerudos."
BOX_BREAK
UNSKIPPABLE "O quartel general dela é no\n"
COLOR(YELLOW) "Templo dos Espíritos" COLOR(DEFAULT) ", que fica\n"
"no final do deserto."
BOX_BREAK
UNSKIPPABLE "Diga, você quer se tornar um\n"
"de nós, não é? Tudo bem então!\n"
"Você está dentro agora."
BOX_BREAK
UNSKIPPABLE "Pegue isto. Com ele, você terá\n"
"livre acesso a todas as áreas\n"
"da fortaleza!" EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De agora em diante, você é livre\n"
"para ir e vir como quiser pelo\n"
"portão do deserto."
BOX_BREAK
"Você encontrará o " COLOR(YELLOW) "Templo dos\n"
"Espíritos" COLOR(DEFAULT) ", onde a louvada Nabooru\n"
"vive, além do deserto."
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Estúpido!" QUICKTEXT_DISABLE "\n"
"Entre logo e fique quieto!"
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não faço idéia de onde você veio\n"
"mas deve ter muita habilidade\n"
"para conseguir passar por todos\n"
"esses guardas!"
BOX_BREAK
UNSKIPPABLE "Todos os meus colegas carpinteiros\n"
"foram aprisionados em algum lugar\n"
"daqui."
BOX_BREAK
UNSKIPPABLE "Se puder nos tirar dessa, eu\n"
"vou lhe retribuir!"
BOX_BREAK
UNSKIPPABLE "Mas tenha cuidado! Certamente\n"
"há guardas " COLOR(RED) "Gerudo" COLOR(DEFAULT) " ao redor\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "daqui" QUICKTEXT_DISABLE "...." TEXT_SPEED("\x00")  UNSKIPPABLE  QUICKTEXT_ENABLE "Uh!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Cuidado!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "A Entrada para o Passado" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "A Entrada para o Presente" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "A Entrada para o Futuro" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\xEC") "Serei seu guia, mas se retrucar,\n"
"eu vou parar! Eu lhe mostrarei\n"
"o único caminho a seguir, então\n"
"siga-me e não seja lento!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Passado, presente, futuro..."
BOX_BREAK
UNSKIPPABLE "A Espada Mestra é um navio com\n"
"o qual poderá navegar acima ou\n"
"abaixo no rio do tempo..."
BOX_BREAK
UNSKIPPABLE "O porto para esse navio é o\n"
"Templo do Tempo..."
BOX_BREAK
UNSKIPPABLE "Para restaurar o Colosso do\n"
"Deserto e entrar no " COLOR(YELLOW) "Templo dos\n"
"Espíritos" COLOR(DEFAULT) ", você deve viajar de\n"
"volta pelo fluxo do tempo!"
BOX_BREAK
UNSKIPPABLE "Ouça este " COLOR(YELLOW) "Réquiem dos Espíritos" COLOR(DEFAULT) "...\n"
"Esta melodia levará uma criança\n"
"ao deserto."
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou o mestre Gerudo de\n"
"arco-e-flecha sobre o cavalo!\n"
"Além disso, sou o mestre Gerudo\n"
"em montaria!"
BOX_BREAK
"Vai tentar arco-e-flecha a cavalo\n"
"por " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem talento--Gostei.\n"
"Siga-me."
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso não tem sentido se você\n"
"não tem um cavalo!"
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Eu não terei nada a fazer com um\n"
"covarde como você!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não é tão bom quanto\n"
"afirma. Talvez na próxima."
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você foi bem."
BOX_BREAK
"Por hoje, admito que perdi.\n"
"Parece que eu tenho muito a\n"
"melhorar."
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta é a " COLOR(RED) "Área de Treinamento" COLOR(DEFAULT) "\n"
"Gerudo."
BOX_BREAK
"Ninguém pode entrar aqui sem um\n"
"cartão de sócio."
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa é a " COLOR(RED) "Área de Treinamento" COLOR(DEFAULT) "\n"
"Gerudo."
BOX_BREAK
"Cartão de sócio checado."
BOX_BREAK
"Uma tentativa por 10 Rupees!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ok, vou aceitar seus 10 Rupees.\n"
"Dê o melhor de si!" EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não tem dinheiro suficiente!\n"
QUICKTEXT_DISABLE "Volte sempre." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, novato!"
BOX_BREAK
UNSKIPPABLE "Você está indo ao deserto?\n"
"Vou abrir o portão para você,\n"
"mas..."
BOX_BREAK
UNSKIPPABLE "Não poderá cruzar o deserto a\n"
"menos que passe nas " COLOR(RED) "duas provas" COLOR(DEFAULT) ". " TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A primeira prova é...o " COLOR(RED) "Rio de\n"
"Areia" COLOR(DEFAULT) "! Você pode andar por esse\n"
"rio! Após cruzá-lo, siga as\n"
"bandeiras que nós colocamos lá."
BOX_BREAK
"A segunda prova é...o " COLOR(RED) "Guia\n"
"Fantasma" COLOR(DEFAULT) "!"
BOX_BREAK
"Aqueles sem os " COLOR(RED) "olhos que podem\n"
"ver a verdade" COLOR(DEFAULT) " só conseguirão\n"
"retornar ao início."
BOX_BREAK
"Você irá de qualquer jeito, não\n"
"é? Eu não o impedirei...\n"
"Vá em frente!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Por que você andou todo esse\n"
"caminho até aqui? O quê? Veio\n"
"só para perguntar a mesma coisa?" TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, agora que você está aqui,\n"
"poderá também fazer as melhores\n"
"coisas!"
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bom garoto! Obrigado!\n"
"Sinto muito por não poder lhe\n"
"dar algo em troca, mas...\n"
"Leve isto mesmo assim!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu não tinha visto você por aqui,\n"
"garoto..."
BOX_BREAK
"O que quer?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Ver o templo\n"
"Procurar os Sábios\n"
"Nada mesmo" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é só um garoto! Lá não é\n"
"um lugar para você!"
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Um Sábio? Não conheço ninguém\n"
"assim."
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você não tem nada a fazer?\n"
"Que boa hora! Pode me fazer um\n"
"favor?"
BOX_BREAK
UNSKIPPABLE "Espere um segundo, quero lhe\n"
"perguntar primeiro--você não\n"
"seria um dos seguidores de..."
BOX_BREAK
"Ganondorf...seria?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "E se eu for?\n"
"Eu odeio Ganondorf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uah-ha-ha!\n"
"Não tente ser esperto, garoto.\n"
"Eu apenas perguntei!"
BOX_BREAK
UNSKIPPABLE "Um garoto como você nunca\n"
"seria um dos seguidores de\n"
"Ganondorf!"
BOX_BREAK
UNSKIPPABLE "Voltando ao assunto..." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uh-huh!"
BOX_BREAK
UNSKIPPABLE "Você é bom. Acho que gostei\n"
"de você." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou me apresentar antes de tudo.\n"
"Eu sou " COLOR(RED) "Nabooru" COLOR(DEFAULT) " dos Gerudos.\n"
"Eu sou uma grande ladra."
BOX_BREAK
UNSKIPPABLE "Mas não me leve a mal!"
BOX_BREAK
UNSKIPPABLE "Apesar de ambos serem ladrões,\n"
"eu sou completamente diferente de\n"
"Ganondorf."
BOX_BREAK
UNSKIPPABLE "Com seus seguidores, ele rouba\n"
"de mulheres e crianças, e até já\n"
"matou pessoas!"
BOX_BREAK
UNSKIPPABLE "Um garoto como você pode não\n"
"saber disso, mas a raça Gerudo\n"
"consiste apenas de mulheres. Só\n"
"um homem nasce a cada cem anos!"
BOX_BREAK
UNSKIPPABLE "Apesar de nossas leis dizerem\n"
"que esse Gerudo macho deva se\n"
"tornar Rei, eu nunca me curvarei\n"
"a esse homem maligno!"
BOX_BREAK
UNSKIPPABLE "A propósito, qual é o seu nome,\n"
"garoto?"
BOX_BREAK
UNSKIPPABLE  NAME "?!"
BOX_BREAK
UNSKIPPABLE "Que tipo de nome é esse?\n"
"Bem...assim..." TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu quero lhe pedir um favor..."
BOX_BREAK
UNSKIPPABLE "Você entraria neste buraquinho\n"
"e pegaria um tesouro lá dentro?"
BOX_BREAK
UNSKIPPABLE "O tesouro são as " COLOR(BLUE) "Luvas\n"
"Prateadas" COLOR(DEFAULT) ". Se as usar, poderá\n"
"empurrar e puxar facilmente coisas\n"
"pesadas!"
BOX_BREAK
UNSKIPPABLE "Não, não, garoto! Nem pense em\n"
"levar esse tesouro com você!"
BOX_BREAK
UNSKIPPABLE "As Luvas Prateadas não caberão\n"
"em um garotinho como você se\n"
"tentar usá-las! Eu quero que seja\n"
"um bom garoto e me entregue-as!"
BOX_BREAK
UNSKIPPABLE "Ganondorf e seus homens estão\n"
"usando o Templo dos Espíritos\n"
"como um esconderijo."
BOX_BREAK
UNSKIPPABLE "Somente as Luvas Prateadas me\n"
"permitirão entrar de fininho\n"
"no templo."
BOX_BREAK
UNSKIPPABLE "Uma vez lá, eu roubarei todo o\n"
"tesouro contido e acabarei com o\n"
"plano deles!"
BOX_BREAK
"O que acha disso? Vai entrar?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado, garoto!"
BOX_BREAK
UNSKIPPABLE "Você e eu, faremos uma grande\n"
"surpresa a Ganondorf e seus\n"
"seguidores!" TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você obtiver com sucesso as\n"
COLOR(BLUE) "Luvas Prateadas" COLOR(DEFAULT) "..."
BOX_BREAK
"Eu farei algo muito bom para\n"
"você!"
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu já devia esperar por isso!\n"
"Você é apenas um garoto!"
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Para onde está me levando?"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ho ho ho!\n"
"Parece que há alguém aqui, Koume."
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hi hi hi!\n"
"Parece que sim, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Que rapaz ultrajante você é,\n"
"para invadir com tanta audácia\n"
"nosso Templo...\n"
"Ho ho!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nós deveríamos lhe ensinar um\n"
"boa lição! Hi hi hi hi!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, leal colega..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Destrua esse intruso em nosso\n"
"nome!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Inimigo...de Ganondorf...\n"
"Deve morrer..."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Unnnh...\n"
"Onde estou...?"
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem, bem...\n"
"Parece que ela voltou ao normal...\n"
"Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ela é apenas uma garotinha,\n"
"mas ela detém muito respeito\n"
"entre os Gerudos, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Talvez devêssemos fazê-la\n"
"trabalhar para o grande Ganondorf\n"
"por mais um tempo!\n"
"ho ho ho!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então devemos fazer uma nova\n"
"lavagem cerebral!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto, deixe-me agradecê-lo.\n"
UNSKIPPABLE "Hehehe...veja no que o garotinho\n"
"se transformou nesses sete\n"
"anos--um ótimo esgrimista!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
"Se eu soubesse que se tornaria\n"
"um homem tão elegante..." BOX_BREAK_DELAYED("\x50") "Eu manteria a promessa que\n"
"eu fiz antes..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, eu lhe darei " COLOR(RED) "isto" COLOR(DEFAULT) "...\n"
"É algo muito importante para\n"
"mim. Vamos ter uma competição\n"
"depois!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", te vejo depois!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A Propósito..."
BOX_BREAK
UNSKIPPABLE "Eu realmente esqueci..."
BOX_BREAK
UNSKIPPABLE "As bruxas fizeram uma lavagem\n"
"cerebral em mim e Ganondorf me\n"
"usou..."
BOX_BREAK
UNSKIPPABLE "Mas isso não é engraçado? Que\n"
"uma pessoa como eu poderia se\n"
"tornar um " COLOR(YELLOW) "Sábio do Espírito" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "E agora, eu lutarei contra eles\n"
"como um dos seis Sábios!\n"
"He he..."
BOX_BREAK
UNSKIPPABLE "Eles vão pagar pelo que fizeram\n"
"em mim!          "
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto..."
BOX_BREAK
UNSKIPPABLE "Não...\n"
NAME ", o Herói do Tempo!"
BOX_BREAK
UNSKIPPABLE "Ao invés de manter a promessa\n"
"que eu fiz, eu lhe darei este\n"
COLOR(YELLOW) "Medalhão" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Pegue-o!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x29") "Arrgh!" QUICKTEXT_DISABLE " Deixe-me ir!!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x29") "Seus, " QUICKTEXT_ENABLE "seus demônios" QUICKTEXT_DISABLE "\n"
SHIFT("\x3B") "de Ganondorf!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x4F")  NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x33") "Saia daqui! Agora!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x14") "Essas bruxas! Estão usando\n"
SHIFT("\x27") "magia negra em mim!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato! Este é nosso " COLOR(RED) "Campo\n"
"de Arco-e-Flecha a Cavalo" COLOR(DEFAULT) "."
BOX_BREAK
"Após muita prática e treino,\n"
"nós finalmente temos a técnica de\n"
"acertar na mosca enquanto\n"
"cavalgamos como o vento!"
BOX_BREAK
"Quando aprender a montar um\n"
"cavalo, seria bom voltar e tentar\n"
"isso. É um esporte perigoso,\n"
"mas é muito divertido!"
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei novato, você tem uma ótima\n"
"égua!"
BOX_BREAK
"Não sei de onde a roubou, mas..."
BOX_BREAK
"O que acha de entrar no desafio\n"
"da " COLOR(RED) "montaria com arco-e-flecha" COLOR(DEFAULT) "?"
BOX_BREAK
"Quando o cavalo começar a\n"
"galopar, atire nos alvos com suas\n"
"flechas."
BOX_BREAK
"Vamos ver quantos pontos pode\n"
"fazer. Você tem 20 flechas."
BOX_BREAK
"Se você fizer " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) ", eu\n"
"lhe darei algo muito bom!" EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer tentar de novo por\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato!\n"
"Você parece bom!\n"
"Mostre-me suas técnicas de novo!"
BOX_BREAK
"A nova meta agora será\n"
COLOR(RED) "1.500 pontos" COLOR(DEFAULT) "!" EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que? Você quer tentar de novo?\n"
"Parece que você tem potencial!" EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vou ser amaldiçoado! Você é um\n"
"verdadeiro mestre!"
BOX_BREAK
"Eu lhe darei um item digno de\n"
"um mestre."
BOX_BREAK
"Esta aljava é muito importante\n"
"para mim. Quero que a tenha.\n"
"Cuide bem dela, certo?"
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " pontos...Hmm...\n"
"Uah-ha-ha! Você tem muito que\n"
"aprender ainda!" EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantástico!\n"
"Você é o mestre definitivo!"
BOX_BREAK
"Eu lhe darei este item.\n"
"Agora que tem esse equipamento,\n"
"a única coisa para melhorar é\n"
"você mesmo!"
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
POINTS " pontos...\n"
"Impressionante!" EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Olhe aquele garoto bobo!\n"
"Ele veio sozinho para se oferecer\n"
"como sacrifício para o grande\n"
"Ganondorf... " FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Com minha chama, vou queimá-lo\n"
SHIFT("\x3B") "até os ossos! " FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Com meu gelo, eu congelarei até\n"
SHIFT("\x3E") "a sua alma!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x22") "Droga, garoto atrevido!\n"
SHIFT("\x1C") "Dessa vez, vai ser sério,\n"
SHIFT("\x39") "certo Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4D") "O que?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x17") "Ei Koume, o que é isso em\n"
SHIFT("\x40") "sua cabeça?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "Não sei, mas você também tem\n"
SHIFT("\x16") "uma em sua cabeça, Kotake!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x17") "Mas eu só tenho 400 anos!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x36") "E eu apenas 380!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x09") "Somos gêmeas! Não tente mentir\n"
SHIFT("\x3E") "a sua idade!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x20") "Você deve estar caduca!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x10") "Está me chamando de caduca?!\n"
SHIFT("\x25") "É assim que trata sua\n"
SHIFT("\x36") "irmã mais velha?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x39") "Somos gêmeas!\n"
SHIFT("\x22") "Você não é mais velha!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x49") "Aaaahhh!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x21") "Como você é insensível!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x14") "Como pode ser tão ingrata?" QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3A") "Você é cruel!!" QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3A") "Sua ingrata..." QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "Voltaremos para assombrá-lo!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OK, seremos sérias agora, Kotake!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x3A")  QUICKTEXT_ENABLE "Oh, ok, Koume." QUICKTEXT_DISABLE  BOX_BREAK_DELAYED("\x14")  SHIFT("\x26")  QUICKTEXT_ENABLE "Ataque" QUICKTEXT_DISABLE " Dinamite" QUICKTEXT_ENABLE " Duplo" QUICKTEXT_DISABLE "\n"
SHIFT("\x2C")  QUICKTEXT_ENABLE "de Kotake" QUICKTEXT_DISABLE " e " QUICKTEXT_ENABLE "Koume!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você veio aqui para me salvar?\n"
"Oh, formidável! Eu sou " COLOR(RED) "Ichiro\n"
"o carpinteiro" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Estávamos realmente interessados\n"
"em nos unir a todo o grupo\n"
"feminino delas, mas elas nos\n"
"trancaram porque somos homens!"
BOX_BREAK
UNSKIPPABLE "Não nos importamos mais com os\n"
"Gerudos! Elas são tão rudes!"
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Três dos meus parceiros" COLOR(DEFAULT) " também\n"
"foram capturados. Por favor,\n"
"ajude-os a escapar!"
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você é um bom garoto! Obrigado\n"
"por me salvar! Sou " COLOR(RED) "Jiro, o\n"
"carpinteiro" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Essas mulheres apavoram!\n"
"Prefiro ser carpinteiro do que\n"
"me juntar a elas!"
BOX_BREAK
UNSKIPPABLE "Mal posso esperar para dizer\n"
"adeus a este lugar! " COLOR(RED) "Dois dos meus\n"
"amigos" COLOR(DEFAULT) " ainda estão presos.\n"
"Você também vai libertá-los?"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado, garoto! Você é\n"
"fantástico! Sou " COLOR(RED) "Sabooro, o\n"
"carpinteiro" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Você viu nosso chefe, garoto?\n"
"Ele deve estar preocupado comigo!\n"
"Eu tenho que retornar " QUICKTEXT_ENABLE "logo!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ainda há um de nossos amigos" COLOR(DEFAULT) "\n"
"presos. Por favor, salve-o!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estava com medo de você se\n"
"esquecer de mim! Agora estou\n"
"livre! Obrigado!\n"
"Sou " COLOR(RED) "Shiro o carpinteiro" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Por me salvar, direi a você\n"
"algo interessante sobre o deserto\n"
"que eu ouvi de uns Gerudos\n"
"que conversavam."
BOX_BREAK
UNSKIPPABLE "Elas disseram, \"Para atravessar\n"
"as Terras Mal-Assombradas, é\n"
"necessário o " COLOR(RED) "olho da verdade" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "O Colosso é no outro extremo\n"
"do deserto...\""
BOX_BREAK
UNSKIPPABLE "OK, agora voltarei para a minha\n"
COLOR(RED) "tenda perto do Vale Gerudo" COLOR(DEFAULT) ",\n"
"dê um pulinho lá de vez em\n"
"quando. Poderá obter muita ajuda!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A líder da gangue de ladras é\n"
COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Ela está testando\n"
"lavagem cerebral em muitas\n"
"pessoas nas ruínas do deserto."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, era Ganondorf o Rei do Mal\n"
"quem estava por trás da gangue de\n"
"ladras!"
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando " COLOR(RED) "Nabooru" COLOR(DEFAULT) " era uma ladra\n"
"solitária, nunca roubava dos\n"
"fracos, mas..." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Agora, a gangue de ladras de\n"
"Nabooru faz crueldades e\n"
"brutalidades. Ela se diz uma\n"
"ladra nobre, mas...não é!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Como eu suspeitei, Ganondorf\n"
"fez lavagem cerebral em Nabooru..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Na sociedade Gerudo, os que forem\n"
"bons de montaria e arco-e-flecha\n"
"são bem respeitados." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que tal tentar arco-e-flecha\n"
"sobre o cavalo na Fortaleza\n"
"Gerudo?"
BOX_BREAK
"Se tiver um cavalo, um Gerudo\n"
"da fortaleza lhe fará um desafio."
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você foi tão bem, jovem!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Agora que estamos juntos de novo,\n"
"construir uma ponte sobre o vale\n"
"foi uma moleza."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sem as velhas bruxas, a gangue\n"
"de ladras não é tão assustadora!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A " COLOR(RED) "Fortaleza Gerudo" COLOR(DEFAULT) " fica após\n"
"este portão. Um garoto como você\n"
"não tem nada a fazer lá."
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Sou um " COLOR(RED) "mestre artesão" COLOR(DEFAULT) ". Aquelas\n"
"ladras Gerudos... quebraram a\n"
"ponte."
BOX_BREAK
UNSKIPPABLE "Eu quero consertá-la, mas meus\n"
"empregados se foram!"
BOX_BREAK
UNSKIPPABLE "Disseram que trabalhar como\n"
"carpinteiro não era legal, e\n"
"foram à " COLOR(RED) "Fortaleza Gerudo" COLOR(DEFAULT) " para\n"
"serem ladrões..." TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você! Se estiver indo à\n"
"fortaleza, poderia descobrir o\n"
"que meus empregados estão\n"
"fazendo por lá?"
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, soube que você salvou meus\n"
"homens. Quando retornaram, nós\n"
"construímos esta ponte."
BOX_BREAK
"Olhe isso!\n"
"Não é uma ótima ponte?"
BOX_BREAK
"Eles podem ser carpinteiros\n"
"fracos, mas quando se unem,\n"
"fazem bons trabalhos."
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "Ei, esse serrote! É meu!"
BOX_BREAK
UNSKIPPABLE "Mas... Pensei tê-lo deixado com\n"
"minha velha dama... Oh cara..." TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Minha ferramenta Biggoron\n"
"quebrou, eu estava indo à Cidade\n"
"dos Gorons para reparar."
BOX_BREAK
"Você chegou em boa hora.\n"
"Vai me dar o serrote?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x47")  QUICKTEXT_ENABLE "O que?!\n"
SHIFT("\x14") "Você é uma ladrãozinho sujo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa é a " COLOR(RED) "Área de Treinamento" COLOR(DEFAULT) "\n"
"Gerudo. Permitido apenas pessoas\n"
"qualificadas."
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa é a " COLOR(RED) "Área de Treinamento" COLOR(DEFAULT) "\n"
"Gerudo. Você é qualificado...\n"
"Entre e teste suas habilidades\n"
"o quanto quiser." EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta é a " COLOR(RED) "Área de Treinamento" COLOR(DEFAULT) "\n"
"Gerudo. Mesmo sendo qualificado,\n"
"não pegue todo o tesouro daqui\n"
"para você!"
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, que pena."
BOX_BREAK
"A marca que o guiará ao\n"
"Templo dos Espíritos é a " COLOR(RED) "bandeira\n"
"à esquerda" COLOR(DEFAULT) " da parte externa\n"
"da loja."
BOX_BREAK
"Se mudar de idéia, por favor\n"
"volte aqui novamente!"
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, Rupees insuficientes.\n"
"Nem um Rupee de desconto."
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"He he.\n"
"Você já está no meio de alguma\n"
"coisa, não é?"
BOX_BREAK
"Se você quiser me desafiar, terá\n"
"de vir aqui com uma mente limpa.\n"
"Sem outra distrações!"
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x41") "Bem-Vindo!"
BOX_BREAK
"Estou vendendo coisas, estranhas e\n"
"raras, do mundo inteiro e para\n"
"todos.\n"
"O especial de hoje é..."
BOX_BREAK
"Um objeto perigoso!\n"
"Terrível!\n"
"Não te direi o que é até que\n"
"eu veja o dinheiro...."
BOX_BREAK
"Que tal " COLOR(RED) "200 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito obrigado!"
BOX_BREAK
"Eu estou vendendo... " TEXT_SPEED("\x02")  COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" TEXT_SPEED("\x00")
BOX_BREAK
"O marco que te levará ao\n"
"Templo do Espírito é a " COLOR(RED) "bandeira\n"
"à esquerda" COLOR(DEFAULT) " da loja.\n"
"Até logo!"
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, como vai, " NAME "?\n"
"Surpreso em me ver?"
BOX_BREAK
UNSKIPPABLE "Um longo tempo neste mundo não\n"
"representa nada para ti, não é?\n"
"Mistério!"
BOX_BREAK
UNSKIPPABLE "Até eu pensei que as histórias de\n"
"um garoto que podia viajar\n"
"no tempo fossem só lendas."
BOX_BREAK
UNSKIPPABLE  NAME ", você tem a maturidade de\n"
"um adulto." TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"De agora em diante o futuro de\n"
"todo o povo de Hyrule está em\n"
"suas mãos."
BOX_BREAK
"Talvez meu tempo já\n"
"tenha passado. Eis meu último\n"
"conselho:"
BOX_BREAK
"Duas bruxas habitam este templo.\n"
"Para destruí-las, " COLOR(RED) "use a\n"
"própria magia delas contra elas" COLOR(DEFAULT) ".\n"
"Hoo hoot!Hoo hoot!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quer ouvir o que eu disse\n"
"de novo?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu continuarei a te vigiar...\n"
"Hoo hoo hoo hoot!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eu sou o corredor andarilho!\n"
"Percorro toda esta terra em\n"
"busca do verdadeiro espírito\n"
"esportivo."
BOX_BREAK
UNSKIPPABLE "Venci todos os desafiantes, homem\n"
"e fera."
BOX_BREAK
UNSKIPPABLE "Você é um cara atlético, parece\n"
"ter também um verdadeiro instinto\n"
"matador."
BOX_BREAK
UNSKIPPABLE "Agora que a ponte sobre o Vale\n"
"Gerudo está pronta, estou\n"
"procurando um desafiante para uma\n"
"corrida comemorativa." TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"O melhor tempo daqui até a\n"
COLOR(ADJUSTABLE) "ponte do Bosque Perdido " COLOR(DEFAULT) "\n"
"foi " COLOR(RED)  HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ". É meu recorde."
BOX_BREAK
"Quer desafiar meu recorde?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Excelente!\n"
"Então..."
BOX_BREAK
"Você primeiro.\n"
"Darei uma vantagem."
BOX_BREAK
"Agora!" TEXT_SPEED("\x02") " Vá logo!" TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Nunca descobrirá o seu\n"
"instinto matador com esse\n"
"tipo de atitude."
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Bem, nada mau, você tem muita\n"
"garra! Infelizmente você nunca\n"
"me vencerá. Seu recorde é coisa\n"
"do passado."
BOX_BREAK
"Seu tempo foi " COLOR(RED) "\n"
HIGHSCORE(HS_MARATHON)  COLOR(DEFAULT) ", não foi?\n"
"Você chegou perto, eu ganhei\n"
"por pouco!" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh he.\n"
"Por favor. " TEXT_SPEED("\x20") " Vai." TEXT_SPEED("\x2F")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Oh, parece que você desistiu.\n"
"Heh heh heh. Creio que você deva\n"
"redescobrir o seu instinto\n"
"matador!" FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh.\n"
"Você não tem instinto matador\n"
"ainda."
BOX_BREAK
"É só treinar mais um pouco.\n"
QUICKTEXT_ENABLE "Até mais!" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01")  QUICKTEXT_ENABLE "Huff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "puff..." QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "\n"
"huff..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")
BOX_BREAK
"Huff...huff...\n"
"Nossa! Você foi bem!"
BOX_BREAK
"Mas não\n"
"pôde me vencer!\n"
"Seu tempo foi " COLOR(RED)  MARATHON_TIME  COLOR(DEFAULT) ", mas eu\n"
"venci você por pouco!"
BOX_BREAK
"\n"
"Huff...huff... Você tem que me\n"
"desafiar mais vezes!"
BOX_BREAK
"Huff...\n"
QUICKTEXT_ENABLE "Adeus então!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Eu sou o corredor andarilho!\n"
"Percorro toda esta terra em\n"
"busca de desafiantes com o\n"
"verdadeiro espírito esportivo!"
BOX_BREAK
"Eu vim até aqui para correr na\n"
"Terra Mal-Assombrada, mas acho\n"
"que não é uma boa hora para isso.\n"

BOX_BREAK
"Agora eu quero voltar para o\n"
"Campo de Hyrule, mas a ponte...\n"
"bem, você pode ver daqui. E eu,\n"
"ficarei aqui, dentro desta barraca."
BOX_BREAK
"Não estou em condições de aceitar\n"
"o seu desafio agora.\n"
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
"Não posso pegar o Cucco!"
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huff!\n"
"Estou atrasado para um encontro\n"
"muito importante!"
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem-vindo à cidade de Hyrule.\n"
"É uma cidade pacífica e próspera."
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Crianças não deveriam sair da\n"
"cidade à noite! Fique em casa\n"
"até que amanheça!"
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cara, estou TÃO entediado...\n"
"As coisas seriam melhores se\n"
"houvesse mais problemas no\n"
"mundo..."
BOX_BREAK
"Ei, isso é só entre eu e você,\n"
"OK?"
BOX_BREAK
"Hum... talvez nós possamos nos\n"
"aliviar quebrando alguns destes\n"
"jarros."
BOX_BREAK
"Pare perto de um jarro e aperte\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " para levantá-lo.\n"
"Aperte " COLOR(BLUE) "[A]" COLOR(DEFAULT) " de novo para\n"
"lançar!"
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Que ótimo!"
BOX_BREAK
UNSKIPPABLE "Esqueci de\n"
"te dizer..." EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tem alguma coisa acontecendo aí,\n"
"pois não posso deixar nem um cão\n"
"entrar no castelo!"
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Unnngh...você é o garoto da\n"
"floresta...?"
BOX_BREAK
UNSKIPPABLE "F-f-finalmente te achei...\n"
"T-t-tenho algo a lhe dizer...\n"

BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o Rei Gerudo\n"
"dos Ladrões, traiu nosso Rei..."
BOX_BREAK
UNSKIPPABLE "A servente de Zelda, " COLOR(RED) "Impa" COLOR(DEFAULT) "\n"
"pressentiu o perigo e fugiu com\n"
"nossa Princesa..."
BOX_BREAK
UNSKIPPABLE "Eu tentei impedir que os homens\n"
"de Ganondorf fossem atrás delas\n"
"...mas..."
BOX_BREAK
UNSKIPPABLE "A princesa estava...esperando\n"
"por um garoto da floresta...\n"
"você... Ela queria dar " COLOR(RED) "algo" COLOR(DEFAULT) "\n"
"ao garoto..."
BOX_BREAK
UNSKIPPABLE "Se você já recebeu isso da\n"
"Princesa, " TEXT_SPEED("\x03")  QUICKTEXT_ENABLE "depressa..." QUICKTEXT_DISABLE "..." QUICKTEXT_ENABLE "vá ao " QUICKTEXT_DISABLE  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Tem" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "plo\n"
QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "do " QUICKTEXT_DISABLE "Tempo" COLOR(DEFAULT) "...." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ele parou de se mexer...."
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vê aquele homem de olhos\n"
"malignos?"
BOX_BREAK
UNSKIPPABLE "Esse é " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o líder dos\n"
"Gerudos. Ele vem do longínquo\n"
"deserto do oeste."
BOX_BREAK
UNSKIPPABLE "Mesmo que ele tenha jurado ser\n"
"leal ao meu pai, eu tenho certeza\n"
"de que ele não é sincero."
BOX_BREAK
UNSKIPPABLE "As nuvens negras que cobriram\n"
"Hyrule em meu sonho... Devem\n"
"simbolizar esse homem!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x16") "Heh heh heh! Bom trabalho!" BOX_BREAK_DELAYED("\x3C")  SHIFT("\x21") "Como pensei, você tinha\n"
SHIFT("\x0F") "as chaves do Portal do Tempo!" BOX_BREAK_DELAYED("\x5A")  SHIFT("\x17") "Você me levou aos portões\n"
SHIFT("\x2C") "do Reino Sagrado..." BOX_BREAK_DELAYED("\x50")  SHIFT("\x09") "Sim, devo tudo a você, garoto!" FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Por favor se apresse, ele irá\n"
"embora!" EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor...com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Por favor, venda-me o\n"
COLOR(RED) "conteúdo" COLOR(DEFAULT) " dos frascos...\n"
"use o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que loja estranha!\n"
"Gostaria de saber quando abrirão.\n"
"Eu já li a placa, mas ainda me\n"
"parece estranho!"
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O amanhecer está demorando uma\n"
"eternidade para vir..."
BOX_BREAK
"A vista do Castelo de Hyrule no\n"
"sol da manhã é fantástica!"
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para salvar a garota da floresta,\n"
"precisará de " COLOR(RED) "uma habilidade" COLOR(DEFAULT) ".\n"
"Vá a Kakariko!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que você tem a habilidade\n"
"necessária... A " COLOR(ADJUSTABLE) "garota da\n"
"floresta" COLOR(DEFAULT) " espera a sua\n"
"ajuda...."
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você quiser poções, melhor me\n"
"trazer um frasco vazio. Entendeu,\n"
"jovem?" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Desculpe, isso são só amostras.\n"
"Devido à crise da Cidade Goron,\n"
"não estamos recebendo produtos\n"
"ultimamente."
BOX_BREAK
"E estamos falindo." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se planeja escalar a Montanha da\n"
"Morte, compre um " COLOR(LIGHTBLUE) "Escudo\n"
"Hylian" COLOR(DEFAULT) ". Com ele, poderá se\n"
"defender das rochas que caem."
BOX_BREAK
"Mas ele pode ser um pouco grande\n"
"para um garoto..."
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não estou dançando, sabia...\n"
"Minhas costas coçam!\n"
"Oh! Ah! Oh!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que nós " COLOR(LIGHTBLUE) "Hylians" COLOR(DEFAULT) "\n"
"temos orelhas grandes para\n"
"ouvir as vozes dos Deuses...\n"
"Mas eu nunca ouvi nada!"
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Garoto, você já esteve lá no " COLOR(YELLOW) "\n"
"Rancho Lon Lon" COLOR(DEFAULT) "?"
BOX_BREAK
"O leite deles\n"
"é delicioso! Há muitos cavalos lá\n"
"e a filha do dono do Rancho é\n"
"muito bonita!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para ir ao " COLOR(YELLOW) "Rancho Lon Lon" COLOR(DEFAULT) ",\n"
"depois que sair da cidade, vá ao\n"
"sul pelo campo. Você deve visitar\n"
"o Rancho de vez em quando!"
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu queria ver a " COLOR(RED) "Princesa\n"
"Zelda" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Evitei os guardas...\n"
"Nadei através do fosso...\n"
"Eu estava quase lá quando me\n"
"pegaram!" TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu achei um " COLOR(RED) "pequeno buraco" COLOR(DEFAULT) "\n"
"no lado direito do castelo por\n"
"onde eu podia entrar, mas eu\n"
"fiquei entalado lá."
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE
BOX_BREAK
SHIFT("\x05") "Essa barba\n"
"é meu orgulho! Ela não é\n"
"exuberante, garoto!?"
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "Ahem! " QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE  SHIFT("\x05") "Essa barba é meu orgulho!\n"
SHIFT("\x07") "Ela não é exuberante, garoto?!"
BOX_BREAK
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x51") "Quê?!" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Você está procurando o cara do\n"
"Rancho Lon Lon?"
BOX_BREAK
UNSKIPPABLE "Hmm talvez...\n"
TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu vi um " COLOR(RED) "cara com uma barba\n"
"rala " COLOR(DEFAULT) "entregando umas caixas\n"
"no castelo."
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você sabe sobre o " COLOR(LIGHTBLUE) "Templo\n"
"do Tempo" COLOR(DEFAULT) " que fica na parte\n"
"nordeste da cidade?" TEXTID("\x70\x1E") "\n"
""
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lendas contam que o Templo do\n"
"Tempo é a entrada para o Reino\n"
"Sagrado..."
BOX_BREAK
"Você sabia disso?"
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ua-ha-ha! Que cara maluco!"
BOX_BREAK
UNSKIPPABLE "Acredita que ele foi maluco o\n"
"suficiente para tentar entrar no\n"
"castelo para ver a " COLOR(RED) "Princesa\n"
"Zelda" COLOR(DEFAULT) "?" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por causa desse idiota, eles\n"
"reforçaram a guarda do castelo.\n"
"Uha-ha-hah!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu ganhei muito dinheiro!"
BOX_BREAK
UNSKIPPABLE "Talvez seja melhor vender mais\n"
"coisas!" TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Já sei! Vou até o " COLOR(RED) "Lago Hylia" COLOR(DEFAULT) "!\n"
"Várias coisas vão boiando no\n"
"rio e acabam por lá!\n"
"Hah hah hah!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, garoto da floresta! Esta é a\n"
COLOR(LIGHTBLUE) "cidade de Hyrule" COLOR(DEFAULT) "! Fique\n"
"para dar uma olhada!" TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você veio para ver o " COLOR(LIGHTBLUE) "Castelo\n"
"de Hyrule" COLOR(DEFAULT) ", pegue a rua à\n"
"direita."
BOX_BREAK
"Se veio para ver os " COLOR(BLUE) "becos\n"
"dos fundos" COLOR(DEFAULT) " da cidade, vá\n"
"pela rua da esquerda."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..."
BOX_BREAK
"Você é tão elegante..."
BOX_BREAK
"Assim como o Rei de Hyrule..."
BOX_BREAK
"Hi hi hi..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..."
BOX_BREAK
"Você é..."
BOX_BREAK
"mais bonita..."
BOX_BREAK
"que a Princesa Zelda..."
BOX_BREAK
"Ohh..."
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você já ouviu a lenda do \"Povo\n"
"das Sombras\"?"
BOX_BREAK
UNSKIPPABLE "Eles são os\n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "...as sombras dos\n"
"Hylians."
BOX_BREAK
UNSKIPPABLE "Eles juraram\n"
"fidelidade ao Rei de Hyrule e\n"
"protegiam a Família Real."
BOX_BREAK
UNSKIPPABLE "Mas com esses tempos de paz,\n"
"ninguém tem visto Sheikahs por\n"
"aqui faz tempo."
BOX_BREAK
UNSKIPPABLE "Entretanto..." TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvi dizer que tem uma mulher\n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) " vivendo no\n"
"castelo..."
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Então você quer ver a " COLOR(RED) "Princesa\n"
"Zelda" COLOR(DEFAULT) ", não é?"
BOX_BREAK
"Provavelmente você ouviu sobre\n"
"ela na cidade e veio conhecê-la!\n"
"Bem..."
BOX_BREAK
QUICKTEXT_ENABLE "Vá para casa!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Fora daqui!" QUICKTEXT_DISABLE "\n"
"A princesa nunca teria uma\n"
"audiência com um tipinho como\n"
"você! "
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z Z Z..."
BOX_BREAK
"Mumble..."
BOX_BREAK
"Bem vindo...nosso rancho é tão\n"
"divertido..."
BOX_BREAK
"Venha passear..."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2D") "Que diabos?" QUICKTEXT_DISABLE
BOX_BREAK
UNSKIPPABLE "Será que não se pode dormir um\n"
"pouco por aqui?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Olá, e quem é você?"
BOX_BREAK
UNSKIPPABLE "É, sou " COLOR(RED) "Talon" COLOR(DEFAULT) ", dono do Rancho\n"
"Lon Lon."
BOX_BREAK
UNSKIPPABLE "Eu vim até o castelo entregar\n"
"leite, mas eu sentei aqui para\n"
"descansar e acabei dormindo..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x4C")  SFX("\x68\x52") "Que?!\n"
"Malon está me procurando?\n"
"Vou escutar umas poucas e boas\n"
"dela agora!"
BOX_BREAK
UNSKIPPABLE "Fiz muito mal em deixar Malon\n"
"esperando por mim!"
BOX_BREAK
UNSKIPPABLE "Ela realmente vai me\n"
"esculhambar!" EVENT
BOX_BREAK
"tenho certeza disso!"
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "Ei você, pare!\n"
SHIFT("\x28") "Você garoto, pare aí!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x5F") "!" BOX_BREAK_DELAYED("\x0A")  UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Quem?" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Quem é você?"
BOX_BREAK
UNSKIPPABLE "Como você passou pelos guardas? " EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Está com ela?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, é estranho...\n"
"Pensei ser você a pessoa\n"
"do meu sonho...\n"
"Você não está mesmo com ela?"
BOX_BREAK
"Diga-me a verdade..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D") "Como eu pensei!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, não conte isto a\n"
"ninguém...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah vai...não seja\n"
"fofoqueiro!" EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A lenda começa assim..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0C") "As três deusas esconderam a\n"
SHIFT("\x0C")  COLOR(RED) "Triforce " COLOR(DEFAULT) "contendo o poder dos\n"
SHIFT("\x04") "deuses em algum lugar de Hyrule." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x48") "O poder\n"
SHIFT("\x04") "de garantir o desejo daquele que\n"
SHIFT("\x0A") "tiver a Triforce em suas mãos." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x08") "Se alguém de coração justo faz\n"
SHIFT("\x1D") "um pedido, levará Hyrule\n"
SHIFT("\x23") "a uma era dourada de\n"
SHIFT("\x39") "prosperidade..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x07") "Se alguém com uma mente cruel\n"
SHIFT("\x15") "faz o pedido, o mundo será\n"
SHIFT("\x0D") "consumido pelo mal... isso é o\n"
SHIFT("\x2E") "que diz a lenda..." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x1C") "Então, os antigos Sábios\n"
SHIFT("\x13") "fizeram o " COLOR(LIGHTBLUE) "Templo do Tempo" COLOR(DEFAULT) "\n"
SHIFT("\x1C") "para proteger a Triforce\n"
SHIFT("\x21") "dos homens perversos." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"É isso mesmo... O Templo do Tempo\n"
"é a entrada que leva ao Reino\n"
"Sagrado a partir do nosso mundo."
BOX_BREAK
"Mas a entrada está selada com\n"
"uma parede chamada de\n"
COLOR(LIGHTBLUE) "Portal do Tempo" COLOR(DEFAULT) "."
BOX_BREAK
"E para abrir o portal,\n"
"dizem que é preciso coletar as\n"
"três " COLOR(RED) "Pedras Espirituais" COLOR(DEFAULT) "."
BOX_BREAK
"E outra coisa é necessária... é\n"
"o tesouro que a Família Real tem\n"
"de acordo com essa lenda..." EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, desculpe-me.\n"
"Não sou boa em contos..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "O que aconteceu?" QUICKTEXT_DISABLE " Ele te viu?"
BOX_BREAK
UNSKIPPABLE "Não se preocupe."
BOX_BREAK
UNSKIPPABLE "Ele não tem idéia do que\n"
"planejamos...ainda!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Por favor!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"Não acredito." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x42") "Que bom!" EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Minha servente o guiará para fora\n"
"do castelo. Não tenha medo de\n"
"falar com ela."
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A Pedra Espiritual...\n"
"Você a encontrou!"
BOX_BREAK
"Dizem que as raças que detêm\n"
"as Pedras espirituais abrem suas\n"
"mentes apenas para os que sabem a\n"
COLOR(BLUE) "Melodia da Família Real" COLOR(DEFAULT) "."
BOX_BREAK
"Você já sabia disso, não sabia?       "
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você ouviu dizer que a\n"
"Princesa Zelda tem visões\n"
"proféticas nos sonhos?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh? Que? Sho, Garoto! Sho!"
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Há três buracos e uma inscrição\n"
"aqui...."
BOX_BREAK
QUICKTEXT_ENABLE "Aquele que tiver as três Pedras\n"
"Espirituais, segure a " COLOR(LIGHTBLUE) "Ocarina do\n"
"Tempo e toque a " COLOR(LIGHTBLUE) "Canção do Tempo" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
BOX_BREAK
"É isso o que a inscrição diz." EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vamos, não pode fazer mais\n"
"barato?"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, saia! Isso é meu!\n"
"Eu achei primeiro!"
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, quem me bateu?!"
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não vemos muitos Gerudos\n"
"por aqui...\n"
"Algo estranho está acontecendo!"
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não era a Princesa Zelda montada\n"
"em um cavalo branco?!"
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quase fui atropelado pelo\n"
"cavalo preto!"
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O cara montando o cavalo preto\n"
"deve ser Ganondorf, que é\n"
"conhecido como Rei Gerudo dos\n"
"Ladrões.  "
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que aconteceu?!"
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olha esse cara--está assustado!\n"
"Que covarde!\n"
"Ha ha ha ha!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou sentindo que algo\n"
"terrível vai acontecer...\n"
"Talvez eu devesse sair da cidade\n"
"logo."
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aconteceu algo no castelo!\n"
"Garoto, é melhor ter cuidado!"
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Com essa " COLOR(RED) "chave" COLOR(DEFAULT) ", entre no\n"
"quarto à frente. Vá, Vá!"
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquela montada no cavalo branco\n"
"levando a garotinha...\n"
"Não era a lendária Sheikah?"
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x50")  NAME "..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x4B") "Acorde...\n"
SHIFT("\x28")  NAME ", o escolhido..."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou " COLOR(RED) "Rauru" COLOR(DEFAULT) ", um dos antigos\n"
"Sábios..."
BOX_BREAK
UNSKIPPABLE "Eras atrás, nós, Antigos Sábios\n"
"construímos o Templo do Tempo\n"
"para proteger a entrada do\n"
"Reino Sagrado..."
BOX_BREAK
UNSKIPPABLE "Esta é a " COLOR(RED) "Câmara dos Sábios" COLOR(DEFAULT) ",\n"
"dentro do Templo da Luz..."
BOX_BREAK
UNSKIPPABLE "O Templo da Luz, situado no centro\n"
"do Reino Sagrado, é a última\n"
"fortaleza que ainda luta contra\n"
"o poderio de Ganondorf."
BOX_BREAK
UNSKIPPABLE "A " COLOR(RED) "Espada Mestra" COLOR(DEFAULT) "--A\n"
"destruidora do mal que você tirou\n"
"do Pedestal do Tempo--era a chave\n"
"final para o Reino Sagrado."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Não se assuste...\n"
"Olhe para você...!                              "
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x40")  COLOR(LIGHTBLUE) "Veja " NAME "!\n"
COLOR(DEFAULT)  SHIFT("\x3D")  COLOR(LIGHTBLUE) "Está grande!!\n"
COLOR(DEFAULT)  SHIFT("\x3B")  COLOR(LIGHTBLUE) "Você cresceu!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A Espada Mestra é a lâmina\n"
"sagrada que o mal nunca irá\n"
"tocar..."
BOX_BREAK
UNSKIPPABLE "Somente o digno do título de\n"
"\"" COLOR(RED) "Herói do Tempo" COLOR(DEFAULT) "\" pode retirá-la\n"
"do Pedestal do Tempo..."
BOX_BREAK
UNSKIPPABLE "Porém, você era muito jovem para\n"
"ser o Herói do Tempo..."
BOX_BREAK
UNSKIPPABLE "Então, seu espírito foi selado\n"
"aqui por sete anos."
BOX_BREAK
UNSKIPPABLE "Agora você é velho o bastante,\n"
"a hora de você despertar" COLOR(RED) " " COLOR(DEFAULT) "\n"
"como Herói do Tempo chegou!"
BOX_BREAK
"Bem, você entende o seu\n"
"destino?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Certo, você parece estar\n"
"confuso... Vou explicar de novo,\n"
"desde o princípio." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas, lembre-se..."
BOX_BREAK
UNSKIPPABLE "Mesmo abrindo a Porta do\n"
"Tempo em nome da paz..."
BOX_BREAK
UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o Rei Gerudo dos\n"
"Ladrões, usou-a para entrar no\n"
"proibido Reino Sagrado!"
BOX_BREAK
UNSKIPPABLE "Ele obteve a Triforce no\n"
"Templo da Luz, e com seu poder,\n"
"tornou-se o " COLOR(RED) "Rei do Mal" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Seu poder maligno irradiou dos\n"
"templos de Hyrule, e em sete\n"
"curtos anos, ele mudou Hyrule\n"
"em um mundo monstruoso."
BOX_BREAK
UNSKIPPABLE "Meu poder agora tem pouca\n"
"influência, mesmo neste Reino\n"
"Sagrado..."
BOX_BREAK
UNSKIPPABLE "Mas aqui na Câmara dos Sábios."
BOX_BREAK
UNSKIPPABLE "Ainda há esperança..."
BOX_BREAK
UNSKIPPABLE "O poder dos Sábios vive."
BOX_BREAK
UNSKIPPABLE "Quando o poder de todos os " COLOR(RED) "Sábios" COLOR(DEFAULT) "\n"
"for despertado..."
BOX_BREAK
UNSKIPPABLE "O " COLOR(RED) "Lacre dos Sábios" COLOR(DEFAULT) " conterá\n"
"todo o poder maligno no vazio do\n"
"Reino..."
BOX_BREAK
UNSKIPPABLE "Eu, Rauru, sou um dos Sábios...\n"
"E..."
BOX_BREAK
UNSKIPPABLE "Seu poder de lutar junto com\n"
"os Sábios faz de você o\n"
COLOR(RED) "Herói do Tempo" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "O Herói do Tempo, escolhido pela\n"
"Espada Mestra!"
BOX_BREAK
UNSKIPPABLE "Leve o meu espírito com você...\n"
"E, ache o poder dos outros Sábios\n"
"e some a coragem deles à sua\n"
"bravura!                                                       "
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "...voltamos ao\n"
COLOR(DEFAULT) "Templo do Tempo" COLOR(LIGHTBLUE) "...\n"
"Mas será que " COLOR(DEFAULT) "sete anos" COLOR(LIGHTBLUE) "\n"
"realmente passaram?" COLOR(DEFAULT)
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que você não poderá\n"
"usar algumas das " COLOR(DEFAULT) "armas" COLOR(LIGHTBLUE) "\n"
"que achou no passado..."
BOX_BREAK
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vamos sair daqui!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eiii, que...??\n"
"Qual o problema em vadiar\n"
"o dia todo?"
BOX_BREAK
"Hein, garoto?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Esperava por ti,\n"
"Herói do Tempo..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando o mal governar, uma voz\n"
"chamará do Reino Sagrado os\n"
"destinados a serem Sábios, que\n"
"vivem nos " COLOR(RED) "Cinco Templos" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Uma na " COLOR(ADJUSTABLE) "densa floresta" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Um nas " COLOR(RED) "altas montanhas" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Um dentro do " COLOR(BLUE) "vasto lago" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Um dentro da " COLOR(PURPLE) "casa da morte" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Um dentro da " COLOR(YELLOW) "deusa da areia" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "Junto com o Herói do Tempo,\n"
"os despertados lacrarão o mal e a\n"
"luz da paz voltará ao mundo..."
BOX_BREAK
UNSKIPPABLE "Esta é a lenda dos templos\n"
"contada pelo meu povo,\n"
"os " COLOR(BLUE) "Sheikah" COLOR(DEFAULT) ".                                               "
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, desculpe.\n"
"Não abrimos ainda.\n"
"Por favor, volte uma outra hora!" EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Use a " COLOR(RED) "Espada Mestra" COLOR(DEFAULT) "!\n"
"Destrua Ganon com a Espada\n"
"Sagrada!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Esperava por você,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", o Herói do Tempo..."
BOX_BREAK
UNSKIPPABLE "Você superou muitas dificuldades\n"
"e acordou os seis Sábios."
BOX_BREAK
UNSKIPPABLE "E agora lhe resta o desafio\n"
"final, o confronto com Ganondorf,\n"
"o Rei do Mal..."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x18") "Se você busca o triângulo\n"
SHIFT("\x24") "sagrado, escute bem..." BOX_BREAK_DELAYED("\x3C")  UNSKIPPABLE  SHIFT("\x09") "O lugar de repouso do sagrado\n"
SHIFT("\x17") "triângulo, o Reino Sagrado,\n"
SHIFT("\x15") "é um espelho que reflete o\n"
SHIFT("\x28") "que há no coração..." BOX_BREAK_DELAYED("\x46")  UNSKIPPABLE  SHIFT("\x0D") "O coração de quem adentra...\n"
SHIFT("\x0D") "Se for maligno, o Reino ficará\n"
SHIFT("\x15") "cheio de maldade; se puro,\n"
SHIFT("\x1A") "o Reino será um paraíso." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x0A") "A Triforce...triângulo sagrado...\n"
SHIFT("\x13") "é uma balança que pondera\n"
SHIFT("\x34") "as três forças:\n"
SHIFT("\x11") "Poder, Sabedoria e Coragem." BOX_BREAK_DELAYED("\x7A")  UNSKIPPABLE  SHIFT("\x02") "Se o coração daquele que possui o\n"
SHIFT("\x0D") "triângulo sagrado tiver as três\n"
SHIFT("\x0C") "forças em equilíbrio, ele terá a\n"
SHIFT("\x0A") "Verdadeira Força para governar." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x1C") "Mas, se seu coração não\n"
SHIFT("\x02") "estiver em equilíbrio, a triforce irá\n"
SHIFT("\x1B") "se partir em três partes:\n"
SHIFT("\x14") "Poder, Sabedoria e Coragem." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x1A") "Apenas uma parte restará\n"
SHIFT("\x14") "para quem tocou a Triforce...\n"
SHIFT("\x10") "a parte representando a força\n"
SHIFT("\x26") "que ele mais acredita." BOX_BREAK_DELAYED("\x5A")  UNSKIPPABLE  SHIFT("\x14") "Se este busca o Verdadeiro\n"
SHIFT("\x0E") "Poder, deverá adquirir as duas\n"
SHIFT("\x32") "partes perdidas." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE  SHIFT("\x02") "Essas duas partes estarão em poder\n"
SHIFT("\x0A") "de outros escolhidos pelo destino,\n"
SHIFT("\x08") "que terão a marca da Triforce nas\n"
SHIFT("\x27") "costas das suas mãos.                                             "
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sete anos atrás, Ganondorf, o Rei\n"
"dos Ladrões, usou a porta que\n"
"você abriu no Templo do Tempo\n"
"e entrou no Reino Sagrado."
BOX_BREAK
UNSKIPPABLE "Mas quando ele pôs as mãos na\n"
"Triforce, a lenda se concretizou."
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Aquele que detém a " COLOR(RED) "Triforce\n"
"da Coragem " COLOR(DEFAULT) "é...\n"
"Você, " NAME "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E o outro, que detém a\n"
COLOR(RED) "Triforce da Sabedoria" COLOR(DEFAULT) "..."
BOX_BREAK
UNSKIPPABLE "é o sétimo Sábio, que está\n"
"destinado a liderar todos\n"
"os outros."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou eu, a Princesa de Hyrule,\n"
COLOR(RED) "Zelda" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Minhas desculpas por falar-lhe em\n"
"um disfarce, mas foi necessário\n"
"para me esconder do Rei do Mal.\n"
"Perdoe-me..."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Vi você quando estava escapando\n"
"do castelo com a minha\n"
"serva, Impa." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Enquanto estivesse com a Ocarina,\n"
"pensei que Ganondorf nunca iria\n"
"entrar no Reino Sagrado, mas..."
BOX_BREAK
UNSKIPPABLE "Algo inesperado\n"
"aconteceu...                     "
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0F") "Esse barulho...não pode ser!?"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Princesa Zelda...sua tola\n"
"traidora!"
BOX_BREAK
UNSKIPPABLE "Condeno-te por evitar minha\n"
"busca por sete longos anos."
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se quiser resgatar Zelda,\n"
"venha ao meu castelo!"
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...pode me ouvir?\n"
"É Rauru, o Sábio."
BOX_BREAK
UNSKIPPABLE "Nós seis usaremos nosso poder\n"
"para criar uma ponte para o\n"
"castelo onde Ganondorf vive..."
BOX_BREAK
UNSKIPPABLE "O castelo que é conhecido por\n"
"Torre de Ganon, é protegido por\n"
COLOR(RED) "seis barreiras malignas" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Derrube as barreiras e salve\n"
"a Princesa Zelda!! "
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
"Antigos criadores de Hyrule" BOX_BREAK_DELAYED("\x3C") "Agora abram a porta selada\n"
"e mandem a Encarnação Maligna da\n"
"Escuridão para o vazio\n"
"Reino Maligno!!" FADE("\x5A") "!"
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME "!\n"
"Acabe com ele com a espada do\n"
"tempo, a Espada Mestra!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh porta selada aberta pelos\n"
"Sábios... Feche-se para sempre\n"
"com a Encarnação Maligna da\n"
"Escuridão!!"
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigada, " NAME "..."
BOX_BREAK
UNSKIPPABLE "Graças a você, Ganondorf foi\n"
"selado no Reino do Mal!"
BOX_BREAK
UNSKIPPABLE "Assim, a paz voltará a reinar\n"
"neste mundo... por enquanto.  "
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x42") "Obrigada...\n"
SHIFT("\x43")  NAME "..." BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  SHIFT("\x4C") "Adeus..." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você realmente quer passar pelo\n"
"portão? Deixe-me pensar um\n"
"pouco... OK, mas em troca..." TEXTID("\x70\x72") " "
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quero 10 Rupees...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Acredite em mim...\n"
"Minhas profecias nunca estão\n"
"erradas!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você destruiu as criaturas que\n"
"assolavam o templo e acordou\n"
"o Sábio..."
BOX_BREAK
UNSKIPPABLE "Mas ainda há outros Sábios\n"
"que precisam da sua ajuda."
BOX_BREAK
UNSKIPPABLE "Para acordar todos os outros\n"
"Sábios, é preciso tornar-se ainda\n"
"mais poderoso."
BOX_BREAK
UNSKIPPABLE "Você pode viajar pelas\n"
"montanhas..."
BOX_BREAK
"debaixo d'água..."
BOX_BREAK
"e pelo tempo...  "
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Enquanto você tiver a " COLOR(LIGHTBLUE) "Ocarina\n"
"do Tempo" COLOR(DEFAULT) " e a " COLOR(LIGHTBLUE) "Espada\n"
"Mestra" COLOR(DEFAULT) ","
BOX_BREAK
UNSKIPPABLE "você terá o tempo em suas\n"
"mãos..."
BOX_BREAK
UNSKIPPABLE  NAME ", nos veremos de\n"
"novo!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Este é um novo tipo de bomba!\n"
"tenho um estoque muito limitado,\n"
"quando acabar, acabou!" EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sou " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"Sobrevivente Sheikah..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vendo você assim\n"
"segurando a mística " COLOR(RED) "Espada\n"
"Mestra" COLOR(DEFAULT) ", realmente parece o\n"
"lendário Herói do Tempo...          "
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se acredita na lenda, você\n"
"não tem escolha. Você precisa\n"
"achar os cinco templos e acordar\n"
"os " COLOR(RED) "Cinco Sábios" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Um Sábio está esperando a hora de\n"
"despertar no " COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) ".\n"
"O Sábio é certamente conhecida\n"
"sua..."
BOX_BREAK
UNSKIPPABLE "Devido ao poder do mal no\n"
"templo, ela não pode ouvir o\n"
"chamado do Reino Sagrado..."
BOX_BREAK
UNSKIPPABLE "Infelizmente, equipado como você\n"
"está, não poderá sequer entrar no\n"
"templo..."
BOX_BREAK
UNSKIPPABLE "Mas, se acredita no que eu estou\n"
"dizendo, vá até a " COLOR(RED) "Vila\n"
"Kakariko..."
BOX_BREAK
UNSKIPPABLE "Você me entendeu, " NAME "?                              "
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Eu pensei que deveria confiar a\n"
"Ocarina a você... Achei que seria\n"
"nossa melhor chance..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Antes de tudo... Tenho coisas\n"
"que quero dizer apenas a você.\n"
"Por favor, ouça."
BOX_BREAK
UNSKIPPABLE "Outra lenda desconhecida da\n"
"Triforce passada pelo povo\n"
"oculto, os Sheikah..."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A Triforce separou-se em três\n"
"partes. Apenas a " COLOR(RED) "Triforce do\n"
"Poder" COLOR(DEFAULT) " permaneceu nas mãos de\n"
"Ganondorf."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A força da Triforce do Poder\n"
"transformou-o num rei mau, mas\n"
"suas ambições malignas não\n"
"foram satisfeitas.       "
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Para ganhar completo controle do\n"
"mundo, Ganondorf foi procurar por\n"
COLOR(RED) "aqueles escolhidos pelo destino" COLOR(DEFAULT) "\n"
"para guardar as outras partes."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Naquele dia, sete anos atrás,\n"
"Ganondorf atacou o Castelo."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Após você abrir a porta do tempo,\n"
"a Espada Mestra lançou você no\n"
"Reino Sagrado..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu espírito permaneceu no Reino\n"
"Sagrado...e então a Triforce caiu\n"
"nas mãos de Ganondorf. Ele foi\n"
"então invadir o Reino Sagrado..."
BOX_BREAK
UNSKIPPABLE "Ganondorf tornou-se o Rei do\n"
"Mal, e o Reino Sagrado tornou-se\n"
"um mundo maligno. Tudo isso é uma\n"
"infeliz coincidência."
BOX_BREAK
UNSKIPPABLE "Eu me fiz passar por uma Sheikah\n"
"e tinha esperanças que você\n"
"retornaria. Eu esperei por\n"
"sete anos..."
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E... agora está de volta. A era\n"
"negra dominada por Ganondorf\n"
"vai chegar ao fim!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Os seis Sábios abrirão a porta\n"
"lacrada e atrairão Ganondorf de\n"
"volta ao Reino Sagrado."
BOX_BREAK
UNSKIPPABLE "E eu selarei a porta para o Reino\n"
"Sagrado por este mundo."
BOX_BREAK
"Portanto, Ganondorf o Rei do Mal\n"
"será banido de Hyrule."
BOX_BREAK
UNSKIPPABLE  NAME "...\n"
"Para fazer isso, preciso de sua\n"
"coragem de novo. Proteja-me\n"
"enquanto faço a minha parte."
BOX_BREAK
UNSKIPPABLE "E aqui está uma arma que pode\n"
"penetrar as defesas do Rei do\n"
"Mal... O poder dado aos\n"
"escolhidos..."
BOX_BREAK
UNSKIPPABLE  SHIFT("\x0F") "A sagrada " COLOR(LIGHTBLUE) "Flecha de Luz" COLOR(DEFAULT) "!!!    "
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas deixou sua guarda baixa...\n"
"Sabia que você apareceria se eu\n"
"deixasse o garoto vivo!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Meu único engano foi subestimar\n"
"levemente o poder desse garoto..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não...\n"
"Não foi o poder do garoto que eu\n"
"julguei errado, foi o poder da\n"
"Triforce da Coragem!"
BOX_BREAK
UNSKIPPABLE "Mas, com a Triforce da Sabedoria\n"
"que Zelda tem...quando eu\n"
"obtiver as duas Triforces..."
BOX_BREAK
UNSKIPPABLE "Então, serei realmente o\n"
"dominador do mundo!!"
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "A Ocarina do Tempo abriu a porta.\n"
"O Herói do Tempo, com a Espada\n"
"Mestra, desceu aqui." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece estranho, bandos de cães\n"
"latem em nossas ruas à noite...\n"
"Não parece estranho para você?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, filho, direi a você algo\n"
"útil..."
BOX_BREAK
"Eu ouvi que há uma " COLOR(RED) "fonte\n"
"misteriosa" COLOR(DEFAULT) " em algum lugar\n"
"perto do castelo..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se quiser retornar ao seu tempo\n"
"de origem, ponha de volta a\n"
"Espada Mestra no " COLOR(RED) "Pedestal do\n"
"Tempo" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Fazendo isso, você voltará no\n"
"tempo sete anos..."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Chegará a hora em que você terá\n"
"de retornar aqui rapidamente...\n"
"Vou lhe ensinar isto para quando\n"
"a hora chegar..."
BOX_BREAK
UNSKIPPABLE "A canção para retorná-lo ao\n"
"Templo do Tempo...\n"
COLOR(LIGHTBLUE) "O Prelúdio da Luz" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou " COLOR(RED) "Impa" COLOR(DEFAULT) " dos Sheikahs.\n"
"Eu sou responsável pela proteção\n"
"da Princesa Zelda. Tudo está da\n"
"forma como a Princesa profetizou."
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se os soldados do castelo o\n"
"acharem, vai ter confusão.\n"
"Deixe-me tirá-lo do castelo."
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ei você! Não cause problemas!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "É um garoto corajoso...\n"
"Está destinado a uma grande e\n"
"nova aventura, não está?"
BOX_BREAK
UNSKIPPABLE "Meu papel no sonho da Princesa\n"
"era ensinar uma melodia àquele\n"
"que vem da floresta."
BOX_BREAK
UNSKIPPABLE "Esta é uma antiga " COLOR(BLUE) "melodia\n"
"passada pela Família Real" COLOR(DEFAULT) "."
BOX_BREAK
UNSKIPPABLE "Eu tocava esta canção para a\n"
"Princesa Zelda como uma canção\n"
"de ninar desde quando ela era\n"
"um bebê..."
BOX_BREAK
UNSKIPPABLE "Há um poder misterioso nestas\n"
"notas."
BOX_BREAK
UNSKIPPABLE "Agora ouça cuidadosamente..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Toda a tragédia que assolou\n"
"Hyrule foi culpa minha..."
BOX_BREAK
UNSKIPPABLE "Eu era tão jovem...não podia\n"
"compreender as consequências\n"
"de tentar controlar o Reino\n"
"Sagrado."
BOX_BREAK
UNSKIPPABLE "Eu coloquei você nisso, também.\n"
UNSKIPPABLE "Agora é hora de reparar meus\n"
"erros..."
BOX_BREAK
UNSKIPPABLE "Você deve pôr a Espada Mestra\n"
"para descansar e fechar o Portal\n"
"do Tempo..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Porém, fazendo isso, o elo entre\n"
"os tempos será fechado..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ",\n"
"dê-me a Ocarina..."
BOX_BREAK
UNSKIPPABLE "Como uma Sábia, posso com ela\n"
"retorná-lo ao seu tempo original."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Quando a paz retornar a Hyrule..."
BOX_BREAK
UNSKIPPABLE "Será o momento para dizermos\n"
"adeus..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Agora, vá, " NAME ".\n"
"Recupere seu tempo perdido!"
BOX_BREAK
UNSKIPPABLE "Sua casa... é onde você deveria\n"
"estar... é o lugar onde deveria\n"
"ficar..."
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46")  QUICKTEXT_ENABLE "Tsk" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Tsk." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, talvez seja muito para\n"
"um garoto pagar. " EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"OK, deixarei passar,\n"
"rápido!" EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"MANTENHA ISTO SEGREDO\n"
"DE TODOS."
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cara, estou TÃO cansado!"
BOX_BREAK
"A noite é tão chata!\n"
"Eu queria que alguns fantasmas\n"
"ou algo viessem aqui..."
BOX_BREAK
"Ei, estou muito interessado em\n"
"fantasmas!"
BOX_BREAK
"Estudá-los é o meu hobby, mas\n"
"nunca se sabe...o momento em que\n"
"esse conhecimento possa vir a\n"
"ser útil!"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu precioso filhotinho é muito\n"
"especial comparado aos outros\n"
"cães bobos que andam por aqui!"
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu precioso filhotinho é mais\n"
"rápido que qualquer um dos outros\n"
"cães!"
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não encontro meu filhotinho em\n"
"lugar algum! Por favor, ache-o!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C")  QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"Não é meu cachorro!\n"
"Como você pôde confundir o meu\n"
"com esses vira-latas?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x16")  QUICKTEXT_ENABLE "Ricardo!" QUICKTEXT_DISABLE " É meu Ricardinho!\n"
"Obrigada! Obrigada!\n"
"Eu lhe darei isto como uma\n"
"recompensa!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"À noite é perigoso lá fora com\n"
"todos aqueles cães ferozes\n"
"rondando... Não estou avisando a\n"
"você! Preocupo-me com meu cão!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hiihi!\n"
"Bem-vindo à " COLOR(RED) "Loja Máscara Feliz" COLOR(DEFAULT) "!\n"
"Lidamos com máscaras que trazem\n"
"felicidade a todos!"
BOX_BREAK
"Gostaria de ser um vendedor da\n"
"felicidade? Vou lhe emprestar\n"
"uma máscara. Venda a máscara e\n"
"traga o " COLOR(RED) "dinheiro" COLOR(DEFAULT) " de volta."
BOX_BREAK
"Se quiser ler o contrato, dê uma\n"
"olhada na " COLOR(RED) "placa" COLOR(DEFAULT) " à minha\n"
"direita."
BOX_BREAK
"Depois de vender todas as máscaras,\n"
"você se tornará muito feliz!"
BOX_BREAK
SHIFT("\x40") "Tenha fé nisso..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Escolha uma máscara com o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "\n"
"para um dos lados.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Falar com o dono.\n"
"Não pegar" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uma " COLOR(RED) "máscara" COLOR(DEFAULT) " é um item do\n"
COLOR(YELLOW) "Botão [C]" COLOR(DEFAULT) ". Coloque-a em " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"e aperte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para colocá-la."
BOX_BREAK
"Se falar com alguém usando-a,\n"
"poderá ter um reação."
BOX_BREAK
"Se alguém se interessar, ele ou\n"
"ela vai falar sobre isso.\n"
"Alguém pode querer a máscara."
BOX_BREAK
"Em algum lugar do mundo, alguém\n"
"está esperando por estas\n"
"máscaras."
BOX_BREAK
SHIFT("\x32") "Tenha fé..." EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Acho que vi uma bela garotinha\n"
"por aqui... Talvez ela tenha ido\n"
"ao castelo?\n"
"Quem vai saber?"
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, ótimo! Você vendeu!\n"
"Pague de volta " COLOR(RED) "10 Rupees" COLOR(DEFAULT) "\n"
"pela Máscara Keaton." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Ainda não vendeu a mais nova\n"
"máscara. Mantenha a fé... Tente\n"
"mais um pouco." EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pagamento feito! " EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "O que?!" QUICKTEXT_DISABLE "\n"
"Você não tem meu dinheiro?!"
BOX_BREAK
QUICKTEXT_ENABLE "Como ousa!" QUICKTEXT_DISABLE
BOX_BREAK
"É melhor trazer o meu\n"
"dinheiro...\n"
"Senão!" EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Beleza!"
BOX_BREAK
"Muito bem!\n"
"Todas as máscaras vendidas."
BOX_BREAK
"Sabia que você era confiável!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Como recompensa...\n"
"Vou lhe emprestar essa máscara\n"
"especial."
BOX_BREAK
UNSKIPPABLE "É a " COLOR(RED) "Máscara da Verdade" COLOR(DEFAULT) ". É\n"
"uma misteriosa máscara dos\n"
"antigos Sheikah."
BOX_BREAK
UNSKIPPABLE "Com esta máscara poderá ler a\n"
"mente das pessoas...\n"
"É útil, mas assustadora!"
BOX_BREAK
UNSKIPPABLE "Por que é assustadora?"
BOX_BREAK
UNSKIPPABLE "Vai saber quando crescer e\n"
"descobrir o verdadeiro sentido\n"
"da vida..."
BOX_BREAK
"Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"De agora em diante você pode\n"
"pegar emprestada qualquer\n"
"máscara!" EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem-vindo!\n"
"Vai querer que máscara?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Escolha uma máscara com o " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sobre a Máscara da Verdade\n"
"Não quero máscara" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esta é a " COLOR(RED) "Máscara da Verdade" COLOR(DEFAULT) ".\n"
"É uma máscara misteriosa passada\n"
"pelos Sheikahs."
BOX_BREAK
"Com ela você pode ler a mente\n"
"das pessoas. É útil, mas\n"
"assustadora!"
BOX_BREAK
"Por que é assustadora?"
BOX_BREAK
"Você saberá quando crescer!"
BOX_BREAK
"Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara da Verdade -- Não está\n"
"a venda" COLOR(DEFAULT) ". Ela tem poderes." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara de Caveira -- 20 Rupees" COLOR(DEFAULT) "\n"
"Possui chifres." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Fantasma -- 30 Rupees" COLOR(DEFAULT) "\n"
"Feita de madeira." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Keaton -- 10 Rupees" COLOR(DEFAULT) "\n"
"Ela é muito popular, quente!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Capuz de Coelho -- 50 Rupees\n"
COLOR(DEFAULT) "Com orelhas que balançam!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara de Caveira -- Grátis" COLOR(DEFAULT) "\n"
"Possui chifres." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara de Fantasma -- Grátis\n"
COLOR(DEFAULT) "Feita de madeira." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Keaton -- Grátis\n"
COLOR(DEFAULT) "Muito popular, sucesso!" QUICKTEXT_DISABLE  PERSISTENT " "
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Capuz de Coelho -- Grátis\n"
COLOR(DEFAULT) "Com orelhas que balançam!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Goron -- Grátis\n"
COLOR(DEFAULT) "Esta máscara redonda fará\n"
"você mais feliz!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Zora -- Grátis\n"
COLOR(DEFAULT) "Você vai ficar muito bem\n"
"nadando com esta máscara!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara Gerudo -- Grátis\n"
COLOR(DEFAULT) "Com seus olhos charmosos, é um\n"
"bom disfarce para mulheres." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED) "Máscara da Verdade -- Grátis" COLOR(DEFAULT) "\n"
"Máscara misteriosa para ler a\n"
"mente das pessoas." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara de\n"
"Caveira" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara de\n"
"Fantasma" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara\n"
"Keaton" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar o " COLOR(RED) "Capuz de\n"
"Coelho" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara\n"
"Goron" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara\n"
"Zora" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "quer levar a " COLOR(RED) "Máscara\n"
"Gerudo" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Quer levar a " COLOR(RED) "Máscara da\n"
"Verdade" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, ótimo! Você vendeu!\n"
"Pague-me de volta " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "\n"
"pela Máscara de Caveira." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, ótimo! Você vendeu!\n"
"Pague-me de volta " COLOR(RED) "30 Rupees" COLOR(DEFAULT) "\n"
"pela Máscara de Fantasma." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, ótimo! Você vendeu! Pague-me\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) " pelo Capuz de\n"
"Coelho agora." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh! Ainda não vendeu a máscara.\n"
"Tenha um pouquinho mais de fé\n"
"que vai dar certo."
BOX_BREAK
"Ou, quer trocá-la por outra\n"
"máscara?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As partes da Triforce estão em\n"
"ressonância...Estão se\n"
"combinando de novo!"
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As duas partes da Triforce que\n"
"eu ainda não capturei naquele\n"
"dia anos atrás..."
BOX_BREAK
UNSKIPPABLE "Não esperava que estivessem\n"
"escondidas com vocês dois!"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E agora, finalmente, as partes da\n"
"Triforce se juntaram aqui!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Elas são demais para vocês!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu ordeno que devolvam-nas\n"
"para mim!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"Não posso ajudá-lo!\n"
"As ondas das trevas não me\n"
"deixam chegar perto!"
BOX_BREAK
COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Sinto muito, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O Grande Rei Ganondorf derrotado\n"
"por este garoto?!"
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf...pobre homem..."
BOX_BREAK
UNSKIPPABLE "Sem uma mente forte e justa, ele\n"
"não podia controlar o poder dos\n"
"deuses...e..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME ", ouça-me!\n"
"Esta torre vai desmoronar logo!"
BOX_BREAK
UNSKIPPABLE "Com seu último suspiro, Ganondorf\n"
"está tentando nos esmagar nas\n"
"ruínas da torre! Rápido, nós\n"
"temos que escapar!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Venha e me siga!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Acabou...finalmente acabou..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "...\n"
"Desculpa por não tê-lo ajudado\n"
"na batalha anterior!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Que som é esse?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Não há como ele me impedir de\n"
"novo!\n"
COLOR(DEFAULT)  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Dessa vez, nós lutaremos juntos!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! A Espada Mestra\n"
"está aqui!\n"
QUICKTEXT_ENABLE "Rápido!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Estou usando meu poder para\n"
"conter o Rei do Mal! Use sua\n"
"espada e desfira o golpe final!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x41") "6 Sábios...\n"
QUICKTEXT_ENABLE  SHIFT("\x49") "Agora!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "VOCÊ! " TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  TEXT_SPEED("\x03") "MALDITA... ZELDA!\n"
TEXT_SPEED("\x02") "E VOCÊS...SÁBIOS!!!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "MALDITO... " QUICKTEXT_ENABLE  NAME "! " QUICKTEXT_DISABLE  FADE("\x1E")  UNSKIPPABLE "Um dia...\n"
"Quando este lacre for quebrado..." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Eu exterminarei os seus\n"
"descendentes!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Um dia...\n"
"Quando este lacre for quebrado..." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "Eu exterminarei os seus\n"
"descendentes!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tão logo a Triforce do Poder\n"
"esteja comigo..." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
TEXT_SPEED("\x02") "Você.." TEXT_SPEED("\x00") "quem é você?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0B") "A " COLOR(ADJUSTABLE) "Barreira da Floresta" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x39") "Rápido, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(RED) "Barreira de Fogo" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x39") "Rápido, brother!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(BLUE) "Barreira de Água" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x46") "Rápido!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(PURPLE) "Barreira de Sombras" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x1E")  NAME ", Salve a Princesa!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(YELLOW) "Barreira de Espíritos" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x37") "Rápido, garoto!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(LIGHTBLUE) "Barreira de Luz" COLOR(DEFAULT) " acabou!\n"
SHIFT("\x4B") "Rápido!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE)  NAME ", isso não é...?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquela lâmina lendária..." COLOR(DEFAULT) FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "A Espada Mestra!! " COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ache os outros Sábios e salve\n"
"Hyrule!" FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele homem mal-encarado saiu\n"
"daqui rapidamente!"
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, era tão assustador..."
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o que você quer?\n"
"Não tenho tempo de falar\n"
"com você!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor...com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Por favor venda-me algo...\n"
"Use o " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não...\n"
"Não é o que eu quero...\n"
"Eu quero " COLOR(RED) "algo dentro de um\n"
"frasco" COLOR(DEFAULT) "... Não é essa coisa..."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não...\n"
"Não posso pegar isso...\n"
"Não é o que quero comprar..."
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, é " COLOR(LIGHTBLUE) "Fogo Azul" COLOR(DEFAULT) "!\n"
"Vou comprá-lo por " COLOR(RED) "150 Rupees" COLOR(DEFAULT) "!\n"
"Negócio fechado, OK?"
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, um " COLOR(PURPLE) "Peixe" COLOR(DEFAULT) "!\n"
"Compro por " COLOR(RED) "100 Rupees" COLOR(DEFAULT) "!\n"
"Negócio fechado, OK?"
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, é uma belo e pequeno " COLOR(ADJUSTABLE) "Inseto" COLOR(DEFAULT) "!\n"
"Compro por " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!\n"
"Negócio fechado, OK?"
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, uma querida " COLOR(LIGHTBLUE) "Fadinha" COLOR(DEFAULT) "!\n"
"Eu compro por " COLOR(RED) "25 Rupees" COLOR(DEFAULT) "!\n"
"Negócio fechado, OK?"
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...você é um homem bem\n"
"enérgico. É bravo e elegante,\n"
"também."
BOX_BREAK
UNSKIPPABLE "He he he...seu nome é " NAME ",\n"
"não é."
BOX_BREAK
UNSKIPPABLE "He he he...não fique surpreso.\n"
"Eu posso ler a mente das pessoas."
BOX_BREAK
UNSKIPPABLE "Se eu fosse tão bom quanto\n"
"você, poderia fazer vários tipos\n"
"de negócios...he he he..."
BOX_BREAK
UNSKIPPABLE "Minha loja é a única " COLOR(RED) "Loja\n"
"Fantasma" COLOR(DEFAULT) " em Hyrule."
BOX_BREAK
UNSKIPPABLE "Por causa do grande Ganondorf,\n"
"é um momento ótimo para negócios\n"
"como esse...he he he..."
BOX_BREAK
UNSKIPPABLE "Oh...só espero que o mundo\n"
"fique cada vez pior!"
BOX_BREAK
UNSKIPPABLE "Os " COLOR(RED) "Fantasmas" COLOR(DEFAULT) ", são espíritos\n"
"de ódio concentrado que aparecem\n"
"nos campos e cemitérios. Eles\n"
"odeiam o mundo!"
BOX_BREAK
UNSKIPPABLE "Jovem, se você pegar um Fantasma,\n"
"Eu pagarei muito dinheiro por\n"
"ele... Procure em todos os\n"
"lugares... He he he he!"
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, jovem. O que está havendo\n"
"hoje? Se você tiver um " COLOR(RED) "Fantasma" COLOR(DEFAULT) ",\n"
"eu comprarei."
BOX_BREAK
"Seu cartão tem " COLOR(PURPLE)  HIGHSCORE(HS_POE_POINTS) " " COLOR(DEFAULT) "pontos.\n"
"Volte sempre!\n"
"He he he he he!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, trouxe um Fantasma hoje!"
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")
BOX_BREAK
UNSKIPPABLE "Hmmm..."
BOX_BREAK
UNSKIPPABLE "É um " COLOR(RED) "Fantasma Normal" COLOR(DEFAULT) ".\n"
UNSKIPPABLE "Aqui estão seus " COLOR(RED) "10 Rupees" COLOR(DEFAULT) ".\n"
"Pegue-os."
BOX_BREAK
UNSKIPPABLE "He he he."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, trouxe um Fantasma hoje!"
BOX_BREAK
UNSKIPPABLE "Hmmmm!"
BOX_BREAK
UNSKIPPABLE "Muito interessante!\n"
"É um " COLOR(RED) "Fantasmão" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Vou comprar por " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "."
BOX_BREAK
"Além disso, colocarei " COLOR(RED) "100 pontos" COLOR(DEFAULT) "\n"
"no seu cartão."
BOX_BREAK
UNSKIPPABLE "Se você ganhar " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) ",\n"
"será um homem feliz! He he he."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Espere um minuto! UAU!"
BOX_BREAK
UNSKIPPABLE "Você ganhou " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "Jovem, você é um genuíno\n"
COLOR(RED) "Caçador de Fantasmas" COLOR(DEFAULT) "!"
BOX_BREAK
UNSKIPPABLE "É o que você esperava que eu\n"
"\n"
"dissesse? He he!"
BOX_BREAK
UNSKIPPABLE "Por sua causa, eu tenho estoque\n"
"extra de " COLOR(RED) "Fantasmões" COLOR(DEFAULT) ", por isso\n"
"será a última vez que vou comprar\n"
"um fantasma."
BOX_BREAK
UNSKIPPABLE "Você está pensando sobre o que\n"
"eu prometi quando você ganhasse\n"
"1.000 pontos. He he."
BOX_BREAK
UNSKIPPABLE "Não se preocupe, não esqueci.\n"
"Tome isto."
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh? Que é isso?"
BOX_BREAK
UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "É" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "uma" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "fada" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!"
BOX_BREAK
UNSKIPPABLE "Então, você é...\n"
"Você é da floresta?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então...então...você não teria...\n"
"a " COLOR(ADJUSTABLE) "Pedra Espiritual da Floresta" COLOR(DEFAULT) ",\n"
"teria?! Aquela pedra verde e\n"
"brilhante..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu tive um sonho...No sonho,\n"
"nuvens de tempestades negras\n"
"cobriam a terra de Hyrule..."
BOX_BREAK
UNSKIPPABLE "Mas de repente, um raio de luz\n"
"surgiu da floresta, partiu as\n"
"nuvens e iluminou o chão..."
BOX_BREAK
UNSKIPPABLE "A luz se transformou em uma\n"
"imagem segurando uma " COLOR(ADJUSTABLE) "pedra\n"
"verde e brilhante" COLOR(DEFAULT) ", seguida\n"
"por uma " COLOR(LIGHTBLUE) "fada" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sei que alguém vindo da\n"
COLOR(ADJUSTABLE) "floresta" COLOR(DEFAULT) " é uma profecia..."
BOX_BREAK
UNSKIPPABLE "Sim, eu pensei que você pudesse\n"
"ser esse alguém..." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x3A") "Oh, sinto muito!"
BOX_BREAK
UNSKIPPABLE "Eu me deixei levar por essa\n"
"história e nem mesmo me apresentei\n"
"direito!" EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x0C") "Sou " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ", Princesa de Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hã? Já nos conhecemos?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahh... Que legal!\n"
"Você poderia me dizer onde você\n"
"achou isso?"
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eii!\n"
"Ajude-me!"
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh...hein? O que?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Odeio raposas"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que irritante!"
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, está bonito!"
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "UHUH! Qual o seu problema?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh...é um Zora?\n"
"Esse olhos são realmente\n"
"fascinantes..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh não! Você dá medo!\n"
"Não chegue perto!"
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau...que nostalgia! Isso me\n"
"lembra quando eu era uma gatotinha."
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que coisa engraçada...isso me\n"
"faz rir!\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Uh-oh!" QUICKTEXT_DISABLE " Desculpa, mamãe!\n"
"Oh...ei, é você!\n"
"Não me assuste assim!"
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeção você tem!"
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não faça isso!\n"
"Sou medroso..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está havendo alguma competição\n"
"de máscaras?\n"
QUICKTEXT_ENABLE "Vou votar em você!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh! Um coelho!\n"
"Falando em coelhos, eu vi um\n"
"estranho caçando coelhos por\n"
"aí..."
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh, que linda dama!\n"
"Mas você é muito baixinha, não é?"
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem...não consigo pensar em nada\n"
"engraçado para dizer!"
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uma máscara... Quando eu era\n"
"garoto, eu também usava\n"
"máscaras... O que? Está dizendo\n"
"que não acredita em mim?"
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohhh...Entendo...\n"
"É uma ilusão..."
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, garoto, não cresça para ser\n"
"como eu!"
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AAAAAHHH!\n"
"UMA GERUDO!!" QUICKTEXT_DISABLE
BOX_BREAK
"Que? Uma máscara?\n"
"Por que está usando essa\n"
"máscara?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe, estou ocupado."
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh uau! É o Keaton!\n"
"Oi, Keaton!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que susto!\n"
"Há um garoto na Vila Kakariko que\n"
"está procurando por uma máscara\n"
"dessa!"
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm...bem...não tem nenhuma\n"
"outra máscara?"
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que máscara estranha! Hi ha ha!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei garoto! Não vê que estamos\n"
"ocupados? Saia daqui!"
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sinto muito. Não quero olhar\n"
"para nenhuma outra mulher!"
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi.\n"
"Não dê atenção àquele garoto,\n"
"meu querido... Finja que estamos\n"
"em nosso próprio mundinho..."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, por favor!\n"
"Vá incomodar outro!"
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Há um rumor dizendo que existe\n"
"uma Loja de Poções que pode fazer\n"
"o medicamento definitivo!"
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvi um rumor de que há um\n"
"monstro que come " COLOR(LIGHTBLUE) "Escudos Hylians" COLOR(DEFAULT) "\n"
"em algum lugar do mundo. Você\n"
"já o viu em algum lugar?"
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vim aqui para vender bombas!\n"
"Compre algumas!"
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu estou com medo...\n"
"Tenho a sensação de que um homem\n"
"vai destruir Hyrule."
BOX_BREAK
UNSKIPPABLE "Ele tem poderes terríveis!"
BOX_BREAK
UNSKIPPABLE "Mas felizmente você veio..." EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que? Se quer alguma coisa,\n"
"seja mais claro!"
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou ocupado! Suma daqui,\n"
"vagabundo!"
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você tem madeira de boa\n"
"qualidade lá, garoto!"
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm!\n"
"Saia da minha frente!\n"
"Seu inútil..."
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"IIIIIAAAAA!\n"
"Oops, eu não devia gritar assim\n"
"senão o chefe grita comigo!"
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, desculpe-me chefe!\n"
"Não estou descansando!\n"
"Vou me ocupar!"
BOX_BREAK
"Oh, não é você, chefe?"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gerudos são belas e bravas...\n"
"Elas são tão fascinantes!"
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Algum dia, com mais habilidade,\n"
"vou fazer uma máscara como essa!"
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, essa é a máscara de que todos\n"
"falavam!\n"
"Ela é meio estranha..."
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha-ha-ha!\n"
"Como vão os negócios,\n"
"Sr. Herói?\n"
"Ha ha!"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou em serviço.\n"
"ENTENDEU?"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm, bem, eu realmente não sei o\n"
"que dizer sobre essa..."
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau! Lindo!\n"
"Mas Cuccos são mais lindos!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que?\n"
"Você está triste?\n"
"Feliz?\n"
"Não sei distinguir!"
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe-me, não estou\n"
"interessado nisso."
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O garoto que brinca no cemitério\n"
"estava falando algo sobre o\n"
"próprio rosto..."
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De fato sou um homem bom.\n"
"Você não acredita?"
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"AAAHH--!\n"
"Pensei que fosse aquela velha\n"
"bruxa!\n"
"Não me assuste assim!"
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lembro de meu pai falando sobre\n"
"um ferreiro...mas isso não me\n"
"interessa de forma alguma."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não tenho medo de monstros da\n"
"floresta! Quer tirar onda da\n"
"minha cara?"
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso? Não consigo ver\n"
"muito bem daqui..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá de novo! Como está hoje?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está tudo bem hoje!"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou tão cansado..."
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu não ligo para raposas!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso é irritante!\n"
"Incomoda meus olhos!"
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está bem elegante!"
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaaaahh!\n"
"O que há de errado com você?\n"
"Está de mau humor?"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Quando falar com alguém,\n"
"primeira encare-o no olho!"
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Quando falar com alguém,\n"
"não o encare!"
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Quando falar com alguém, primeiro\n"
"tire a sua máscara!"
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Não sei por que o chamo assim,\n"
"mas...você é mesmo!"
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde pegou isso?\n"
"O que?\n"
"É uma máscara?"
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh, deixe-me sozinho...\n"
"Não vê que eu estou ocupado\n"
"agora?"
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uma máscara é como um instrumento\n"
"musical--reflete a personalidade\n"
"do seu dono. Eu gosto da sua\n"
"originalidade!"
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeção!\n"
"Como você passou pela porta?!"
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu ODEIO raposas!"
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se essa não for a cara mais\n"
"irritante que eu já vi em toda\n"
"minha vida, não sei qual é!"
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você está com uma cara\n"
"ótima, filho!"
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem alguma reclamação a fazer?\n"
"Fale logo!"
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pare de brincar e acabe com\n"
"a nossa maldição!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu usasse algo assim...\n"
"Seria uma verdadeira Skulltula...\n"
"AAAAAAAAAH!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor entenda se eu não\n"
"rir... É difícil ser feliz\n"
"nessa condição...\n"
"Ser amaldiçoado e tal..."
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "Iaaaaaah!\n"
"Que susto!\n"
"Sei que sou assustador, mas...\n"
"cara! Isso apavora!"
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh?! Que--!"
BOX_BREAK
"Oh, é só um garoto.\n"
"Não me assuste assim!\n"
"Posso não parecer, mas sou um\n"
"cara muito sensível!"
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nossa, olha só a cabeça desse\n"
"garoto! É ENORME!\n"
"A minha é grande também..."
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"VocÊ sabe que tipo de máscara\n"
"está usando...?\n"
"E você ainda a está usando?"
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou em serviço...\n"
"Se quer que eu cave, não me\n"
"amole."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso? É aquilo que pula\n"
"nos campos...\n"
"Esqueci como essas coisas são\n"
"chamadas..."
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! É uma Máscara de Keaton!!\n"
"Pedi uma ao meu pai, também!"
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não é muito diferente do\n"
"Sr. Dampé, não é?"
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não se parece nada com o\n"
"Sr. Dampé, heim?"
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Ei, máscara legal, mas apavora,\n"
"você não acha?"
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! Parece-me familiar...\n"
"Acho que vi algo assim no\n"
"Bosque Perdido, não?"
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Isso me deixa...feliz..."
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh...uh...sniff...\n"
"Essa máscara...me deixa...\n"
"triste..."
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah! Essa máscara não serve para\n"
"nada! Você ficou com medo de mim,\n"
"o grande Mido...não foi?!"
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaaaah! O que?\n"
"Ei, não tenho medo de você!\n"
"Só não se aproxime,\n"
"entendeu?!"
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, que máscara legal.\n"
"Eu a quero!\n"
"BRINCADEIRA! Ah!\n"
"Não quero essa máscara estúpida!"
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha ha!\n"
"Parece bem com você!"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah!\n"
"E-eu vou falar disso para o\n"
"Mido!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Issoo!\n"
"V-vou falar para o Mido te\n"
"bater!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah!\n"
"É algum tipo de fantasma da\n"
"floresta?"
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que legal!\n"
"Uh...não diga ao Mido que eu\n"
"falei!"
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que?!\n"
"Você voltou!\n"
"Posso dizer quem você é, mesmo\n"
"com essa máscara!"
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que Mido diria se visse isso?\n"
"Eu realmente gostaria de ver a\n"
"reação dele!"
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Entendo...\n"
"Você vai assustar Mido com essa\n"
"máscara, não vai?!"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha!\n"
"Que cara engraçada!\n"
"Aposto que Saria acharia isso\n"
"engraçado, também!"
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi hi!\n"
"É feita de madeira?\n"
"Parece que você está usando um\n"
"escudo no rosto!"
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cara estranha!"
BOX_BREAK
"Falando nisso, um dos garotos\n"
"da floresta estava reclamando\n"
"da própria cara..."
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeça enorme você tem!"
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi!\n"
"Onde a conseguiu?\n"
"Fora da floresta?\n"
"Não pode ser! Não acredito nisso!"
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"hi hi!\n"
"É meio engraçado, mas não faz\n"
"meu estilo..."
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Legal!\n"
"Essa máscara faz eu me sentir\n"
"mau e assustador!\n"
"Hi hi hi!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi!\n"
"Há com certeza muitas pessoas\n"
"diferentes no mundo!"
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi hi!\n"
"Não preciso de uma nova...\n"
"Gosto da que eu tenho!"
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Uau, isso faz sua cabeça parecer\n"
"enorme!\n"
"He!"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "Que lindo ratinho!\n"
"O que?\n"
"Oh, isso não é um rato?"
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "O que são essas coisas moles na\n"
"sua cabeça?\n"
"Orelhas? Você fica parecendo que\n"
"tem quatro orelhas!"
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "Deve ser excitante passar pelos\n"
"guardas usando essa máscara!"
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oi, garoto da floresta!\n"
"O que?\n"
"Acha que está disfarçado?\n"
"É tão óbvio quem você é!"
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau!\n"
"Que grandes olhos você tem!\n"
"Gorons são fofos, não são?!"
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, conheço esse rosto!\n"
"É Keaton!\n"
"Ele é muito famoso na Cidade do\n"
"Castelo de Hyrule!"
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, cara!\n"
"Garotos são garotos!"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Espere...\n"
"Sei quem você é...\n"
"Err...Kin-ton!\n"
"Acertei?!"
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa assusta, não é?\n"
"Só não assusta mais que...Ingo!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, isso lembra a minha esposa...\n"
"Pensando bem, não...\n"
"Não parece nem um pouco com ela!"
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"IAAAUU...\n"
"Estou meio cansado agora...\n"
"Mostre-me isso depois..."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saia daqui!\n"
"Eu estou muito ocupado!!"
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Humf!\n"
"É bom brincar enquanto é um\n"
"garoto, mas espere até você\n"
"crescer! Trabalho, trabalho...!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"IAU!\n"
"Humf. É só uma máscara...\n"
"Dê o fora daqui garoto!"
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"He he he...\n"
"Bem, isso me animou um pouco,\n"
"garoto.\n"
"Obrigado!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm... Vamos ver...\n"
"Sim, tenho quase certeza...\n"
"Isso foi feito com uma tábua de\n"
"um caixão. Sim, é isso!"
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhh...sim. Vamos ver...\n"
"Muito bem trabalhado.\n"
"Mas não acho que seria um bom\n"
"ingrediente para meu remédio."
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito interessante! Um Goron!\n"
"Falando nisso, com está meu velho\n"
"amigo Biggoron da Montanha da\n"
"Morte? "
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Constituição muito incomum...\n"
"Não acho que seja solúvel em\n"
"água, por isso não é um bom\n"
"ingrediente para meus remédios..."
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nhoc nhoc nhoc...\n"
"OK, OK, uma máscara.\n"
"Quer comprar alguns feijões?"
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nhoc nhoc nhoc...\n"
"Não, não quero comprar isso."
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nhoc nhoc nhoc...\n"
"Não, não faz meu tipo."
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nhoc nhoc nhoc...\n"
"Bem...não, acho que não quero\n"
"ela."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você quer?"
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você parece que não nada muito\n"
"bem..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cabelo vermelho...pele morena...\n"
"Já vi pessoas assim antes!"
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sim, correto.\n"
"Você é muito baixo para um\n"
"Zora..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho ho ho!\n"
"Vocês Hylians...são criaturas\n"
"tão bobas!"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa cara... me dá calafrios..."
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso que é nostalgia!\n"
"Lembrou-me do meu amigo de\n"
"infância, Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não acho isso engraçado.\n"
"Você está zombando de mim?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é engraçado!"
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sua cabeça--é gigantesca!"
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não faça isso...\n"
"Fico envergonhado!"
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Certo! Você decidiu se tornar um\n"
"Zora! E agora você está preparado\n"
"para se casar comigo?"
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"UAU!\n"
"Meu coração...está acelerado!"
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"É uma máscara desagradável...\n"
"Adeus."
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm...\n"
"Eu não sei o que dizer."
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não deveria ter tanta\n"
"frescura para comer! Você comeu\n"
"todas as pedras verdes? Se não,\n"
"não vai ficar grande e forte!"
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Suma daqui!"
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está tentando me fazer rir?\n"
"Bem, isso não é muito\n"
"engraçado..."
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está me irritando!"
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Odeio Gerudos!!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pare de me amolar!\n"
"Saia!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uah ha ha!\n"
"Acha que está disfarçado?\n"
"Que engraçado!"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saia da minha frente!\n"
"Saia daqui!\n"
"Quer levar umas porradas?"
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, garoto, você tem coragem de\n"
"vir aqui usando isso! Mas não\n"
"pode nos enganar tão facilmente!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso?\n"
"O que isso tem a ver conosco?"
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha!\n"
"Você tem coragem de sobra, não é?\n"
"Eu gostei de você!"
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vamos! Agora é sério!"
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que estranho...parece comigo...\n"
"Não...nem tanto. Nem um pouco,\n"
"se você olhar de perto."
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm. Não, não!\n"
"As orelhas não estão de acordo!\n"
"Deveriam ser maiores, sabe!"
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem nenhum pouco de\n"
"medo? Andando por aí no meio da\n"
"noite desse jeito?"
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha!\n"
"Você gosta mesmo dessas coisas,\n"
"não é?"
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu acho que vi uma pedra como\n"
"essa em algum lugar...\n"
"Onde que foi?\n"
"Hmmmm...."
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Rápido, " NAME "!\n"
"A torre pode desmoronar a\n"
"qualquer segundo!!"
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cuidado com os destroços!"
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "!\n"
"Socorro!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"A saída é por aqui!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Obrigada, " NAME "\n"
"Vamos nos apressar!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que pena!"
BOX_BREAK
"Treine mais e volte!" EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quase!!"
BOX_BREAK
"Bem...certo!\n"
"Vou deixar você tentar mais uma\n"
"vez de graça...\n"
"Dessa vez, você consegue!" EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Maravilha!!!\n"
"Bravo!!!\n"
"Perfeito!!!"
BOX_BREAK
"Aqui está seu presente!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh, não! " COLOR(RED) "O tempo acabou!" COLOR(LIGHTBLUE) "\n"
"A coisa que você ia entregar,\n"
"estragou!\n"
"Tente novamente!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "BOINNG! BOINNG!\n"
"Agora são: " TIME "!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você ouviu de nós pelo guarda\n"
"do portão da Montanha da Morte?\n"
"Bem, vou te dar um desconto\n"
"então!"
)

