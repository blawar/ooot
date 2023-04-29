DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x2D") QUICKTEXT_ENABLE "Você obteve um " COLOR(RED) "Ovo de Bolso" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Um Cucco de Bolso vai nascer\n"
"dele durante a noite. certifique-se de\n"
"devolvê-lo quando terminar de usar-lo."
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x2F") QUICKTEXT_ENABLE "Você devolveu o Cucco de Bolso\n"
"e ganhou o " COLOR(RED) "Cojiro" COLOR(DEFAULT) " em troca!" QUICKTEXT_DISABLE "\n"
"Diferente dos outros Cuccos, Cojiro\n"
"raramente cacareja."
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x30") QUICKTEXT_ENABLE "Você ganhou um " COLOR(RED) "Cogumelo Estranho" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Um cogumelo fresco como esse com\n"
"certeza vai estragar rapidamente! Leve-o para\n"
"a Loja de Poções Kakariko, rápido!"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x31") QUICKTEXT_ENABLE "Você ganhou uma " COLOR(RED) "Poção Estranha" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você não sabe o que está\n"
"entre esta senhora e aquele cara,\n"
"mas leve para o Bosque Perdido!"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x32") QUICKTEXT_ENABLE "Você devolveu a Poção Estranha \n"
"e ganhou uma " COLOR(RED) "Serra do Caçador" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"O jovem punk deve ter\n"
"deixado isso para trás."
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas 20 Peças 80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x48") QUICKTEXT_ENABLE "Você ganhou um \n"
COLOR(RED) "Saco de Balas de Sementes Deku" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Este saco pode guardar até " COLOR(YELLOW) "40" COLOR(DEFAULT) "\n"
"balas de estilingue."
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x33") QUICKTEXT_ENABLE "Você trocou a Serra do Caçador \n"
"pela " COLOR(RED) "Espada Goron Quebrada" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Visite o Biggoron para repará-la!"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x34") QUICKTEXT_ENABLE "Você deixou um Espada Goron \n"
"Quebrada e recebida uma \n"
COLOR(RED) "Prescrição" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Vá ver o Rei Zora!"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x37") QUICKTEXT_ENABLE "A Espada Biggoron..." QUICKTEXT_DISABLE "\n"
"Você recebeu um " COLOR(RED) "Comprovante " COLOR(DEFAULT) "por ela!\n"
"Você mal pode esperar para a espada\n"
"ficar completo!"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x3D") QUICKTEXT_ENABLE "Você trocou a Faca do Gigante \n"
"para a " COLOR(RED) "Espada de Biggoron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta lâmina foi forjada por um \n"
"mestre ferreiro e não vai quebrar!"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x3D") QUICKTEXT_ENABLE "Você entregou o Cheque de Reivindicação\n"
"e tenho a " COLOR(RED) "Biggoron's Sword" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta lâmina foi forjada por um \n"
"mestre ferreiro e não vai quebrar!"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x35") QUICKTEXT_ENABLE "Você usou a Prescrição e\n"
"recebeu um " COLOR(RED) "Eyeball Frog" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Seja rápido e entregue no Lago \n"
"Hylia enquanto está frio!"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x36") QUICKTEXT_ENABLE "Você trocou o Sapo do Olho \n"
"para o " COLOR(RED) "Os melhores colírios do mundo" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Depressa! Leve-os para Biggoron\n"
"antes que fiquem ruins!"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x41") COLOR(RED) "VENCEDOR!!" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x25") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Máscara de Caveira" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para exibi-lo!\n"
"Você se sente um monstro enquanto\n"
"Use esta máscara!"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x26") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Máscara Assustadora" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"desligado! Você pode assustar muitas pessoas\n"
"com esta máscara!"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x24") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Keaton Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"desligado! Você será um cara popular com\n"
"esta máscara!"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x27") QUICKTEXT_ENABLE "Você emprestou um " COLOR(RED) "Capuz de Coelho" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"desligado! As orelhas compridas do capuz são tão\n"
"fofa!"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x28") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Goron Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"desligado! Isso fará sua cabeça parecer\n"
"grande, no entanto."
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x29") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Zora Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"desativado! Com esta máscara, você pode\n"
"tornar-se um dos Zoras!"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2A") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Gerudo Mask" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para exibi-lo!\n"
"Esta máscara vai fazer você parecer\n"
"como uma menina?"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x2B") QUICKTEXT_ENABLE "Você emprestou uma " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) "." QUICKTEXT_DISABLE "\n"
"Use com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para mostrar\n"
"off! Mostre para muitas pessoas!"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem-vindo ao nosso \n de ponta"
"centro de diversões:" BOX_BREAK SHIFT("\x15") COLOR(RED) "Bombchu Bowling Alley!" COLOR(DEFAULT) BOX_BREAK "Você quer saber o que você \n"
"pode ganhar? Bem, é um " TEXT_SPEED("\x03") "segredo." TEXT_SPEED("\x00") "\n"
"Não posso contar até que você\n"
"pago para jogar". BOX_BREAK "É " COLOR(RED) "30 Rupees" COLOR(DEFAULT) " por jogo.\n"
"Você quer jogar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3C") "OK!!" QUICKTEXT_DISABLE BOX_BREAK "Mire no buraco no centro \n"
"e deixe " COLOR(RED) "Bombchu" COLOR(DEFAULT) "vá!\n"
"Você obtém " COLOR(RED) "dez tentativas" COLOR(DEFAULT) ". Pronto..." BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x42") COLOR(RED) "LET'S BOWL!" COLOR(DEFAULT) QUICKTEXT_DISABLE EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você quer jogar novamente?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, quase esqueci!\n"
"Aqui está o que você pode ganhar!" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombas (20 peças) 80 Rupees\n"
COLOR(DEFAULT) "Retire com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " novamente para jogá-lo. Você não pode\n"
"comprá-los sem um saco de bomba." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombas (30 peças) 120 Rupees\n"
COLOR(DEFAULT) "Retire com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " novamente para jogá-lo. Você não pode\n"
"comprá-los sem um saco de bomba." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas 30 peças 120 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou tão feliz que todos estejam \n"
"de volta ao normal!"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, salve meus outros irmãos\n"
"também! Tenho certeza que eles vão te dar\n"
"algo muito melhor!" BOX_BREAK "Você vai fazer isso?!"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "A maldição foi quebrada!\n"
"Obrigado!\n"
"Aqui está uma recompensa para você!" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yeaaargh! Eu sou amaldiçoado!!"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Teremos cuidado para não obter\n"
"amaldiçoado de novo!"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desde que você destruiu " COLOR(RED) TOKENS COLOR(DEFAULT) "\n"
"Aranhas da Maldição, a maldição\n"
"está começando a enfraquecer!" BOX_BREAK "As crianças que voltaram para\n"
"normal te dar alguma recompensa?" BOX_BREAK "Você deve saber que o único\n"
"maneira de se tornar " COLOR(RED) "muito rica" COLOR(DEFAULT) "é para\n"
"destrua o máximo de Aranhas do\n"
"Maldição possível!" BOX_BREAK "Existem alguns truques para encontrar\n"
"todos! Em primeiro lugar, você terá\n"
"caçar à noite. Em segundo lugar, fique em\n"
"lembre-se de que eles amam solo macio..." BOX_BREAK "Preste muita atenção ao seu\n"
"arredores!\n"
"Por favor, estamos contando com você!"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estamos assim por causa de \n"
"a maldição da aranha. Mas..." TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Todos nós estamos assim por causa de\n"
"a maldição da aranha." BOX_BREAK "Se cada " COLOR(RED) "Aranha da Maldição " COLOR(DEFAULT) "em\n"
"o mundo inteiro foi destruído,\n"
"a maldição seria quebrada." BOX_BREAK "Quando você destrói uma Aranha do \n"
"Maldição, um token aparecerá. Colete\n"
"como prova de sua conquista." BOX_BREAK ITEM_ICON("\x71") "O número ao lado deste ícone " COLOR(YELLOW) "" COLOR(DEFAULT) " ativado\n"
"a " COLOR(LIGHTBLUE) "Subtela de Status da Missão" COLOR(BLUE) " \n"
COLOR(DEFAULT) "indica quantas Aranhas do \n"
"Maldição você destruiu até agora." BOX_BREAK ITEM_ICON("\x71") "Quando este ícone " COLOR(YELLOW) "" COLOR(DEFAULT) " é exibido \n"
"ao lado do nome da área em\n"
"a " COLOR(RED) "Mapa Subtela" COLOR(DEFAULT) ", não há\n"
"mais Aranhas nessa área." TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quebrar a maldição no meu\n"
"família, nós vamos fazer você" COLOR(RED) "muito\n"
"rich" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Desde que você destruiu " COLOR(RED) TOKENS COLOR(DEFAULT) " Spiders\n"
"da Maldição, a maldição sobre mim \n"
"foi quebrado." BOX_BREAK UNSKIPPABLE "Obrigado! Aqui está um token do meu\n"
"apreciação! Por favor, aceite." EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado por salvar meus filhos." BOX_BREAK "O quê? Eu? Ah, tudo bem..." BOX_BREAK "Você já destruiu " COLOR(RED) TOKENS COLOR(DEFAULT) "\n"
"Aranhas da Maldição até agora, então...\n"
"Tudo bem... não se preocupe comigo..."
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu 20 peças 180 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer jogar um jogo?\n"
"É " COLOR(RED) "20 Rupees " COLOR(DEFAULT) "por jogada.\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você não pode! Você precisa de um arco!" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tudo bem. Você não precisa jogar\n"
"se você não quiser." EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OK!!" QUICKTEXT_DISABLE "\n"
"Este é um jogo para adultos!\n"
"A famosa " COLOR(RED) "Galeria de Tiro de Hyrule" COLOR(DEFAULT) "!" BOX_BREAK "Mire nos alvos desse \n"
"plataforma ali! Você pode clicar\n"
COLOR(RED) "dez alvos" COLOR(DEFAULT) "? Você recebe " COLOR(RED) "quinze \n"
COLOR(DEFAULT) "tiros!" BOX_BREAK "Desenhe sua arma com " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". \n"
"Você está pronto?\n"
"Vá para uma pontuação perfeita!\n"
"Boa sorte!" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você vê um pequeno monte de soft\n"
"solo aqui."
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x06") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Fairy Slingshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x06") "Pressione " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para tirá-lo e segurar\n"
"Ao segurar " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "você pode mirar \n"
"com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Solte " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para liberar \n"
"a " COLOR(RED) "Deku Seed" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x06") "Se você quiser atirar direito \n"
"fora, quando você pressiona " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", \n"
"mantenha pressionado " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "um pouco mais para \n"
"prepare uma semente."
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x03") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Fairy Bow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x03") "Pressione " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para tirá-lo\n"
"e segure. Enquanto pressiona\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " você pode mirar com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "." COLOR(YELLOW) " " COLOR(DEFAULT) "Liberar\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para deixar voar com uma " COLOR(RED) "seta" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x02") QUICKTEXT_ENABLE "Você tem " COLOR(RED) "Bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x02") "Use " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para levantar e colocar\n"
"it. Pressione " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " enquanto corre para\n"
"jogue. Se você vir algo\n"
"suspeito, bombardeie!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x09") QUICKTEXT_ENABLE "Você tem " COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x09") " Carregue e coloque com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"Este é um novo tipo de bomba que\n"
"pode até subir pelas paredes.\n"
"Mire bem e solte-o!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x01") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Deku Nut" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x01") "Defina como " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e tente \n"
"jogando! Ele piscará e \n"
"atordoe o inimigo!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0E") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Boomerang" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0E") "Pressione " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para usá-lo para \n"
"atacar inimigos distantes!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0A") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Hookshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É uma corrente de mola que\n"
"você pode lançar para fisgar coisas." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0A") "Você pode usá-lo para arrastar\n"
"itens distantes em sua direção, ou\n"
"você pode usá-lo para se puxar\n"
"em direção a algo." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0A") "Enquanto segura " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", você pode\n"
"mirar com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Atire com\n"
"liberando " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x00") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Deku Stick" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x00") "Defina para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e balance-o\n"
"com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x00") "Quando você quiser guardá-lo, \n"
"fique parado e pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". \n"
"Você pode carregar até 10 bastões,\n"
"mas não os desperdice."
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x11") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Megaton Hammer" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pressione " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para esmagar e quebrar \n"
"lixo! É tão pesado, você precisa \n"
"use as duas mãos para balançar!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0F") QUICKTEXT_ENABLE "Você encontrou a " COLOR(RED) "Lens of Truth" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Defina como " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para \n"
"olhe bem! Misterioso \n"
"as coisas estão escondidas em todos os lugares!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0F") "Certifique-se de tentar usá-lo fora\n"
"do poço. Ver a verdade irá\n"
"custa poder mágico, então pressione " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "novamente para parar de usá-lo."
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x08") QUICKTEXT_ENABLE "Você encontrou a " COLOR(RED) "Ocarina of Time" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Este é o esconderijo da Família Real \n"
"tesouro que Zelda deixou para trás.\n"
"Ele brilha com uma luz mística..."
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você conjura Vento de Farore!\n"
THREE_CHOICE COLOR(ADJUSTABLE) "Retornar ao Warp Point\n"
"Dissipar o Ponto de Distorção\n"
"Sair" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x67") QUICKTEXT_ENABLE "Você recebeu o " COLOR(RED) "Fogo\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Darunia desperta como uma Sábia e\n"
"adiciona o poder dele ao seu!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x68") QUICKTEXT_ENABLE "Você recebeu a " COLOR(BLUE) "Água\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ruto desperta como um Sábio e\n"
"adiciona o poder dela ao seu!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x66") QUICKTEXT_ENABLE "Você recebeu a " COLOR(ADJUSTABLE) "Floresta\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Saria desperta como uma Sábia e\n"
"adiciona o poder dela ao seu!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x69") QUICKTEXT_ENABLE "Você recebeu o " COLOR(YELLOW) "Spirit\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nabooru desperta como um Sábio e\n"
"adiciona o poder dela ao seu!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6B") QUICKTEXT_ENABLE "Você recebeu o " COLOR(LIGHTBLUE) "Light\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru, o Sábio, adiciona seu poder\n"
"para o seu!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6A") QUICKTEXT_ENABLE "Você recebeu a " COLOR(PURPLE) "Sombra\n"
"Medalhão" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Impa desperta como um Sábio e\n"
"adiciona o poder dela ao seu!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x14") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Garrafa Vazia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Depois de colocar algo nisso\n"
"garrafa, defina para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " quando você\n"
"quer usar o item dentro."
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x15") QUICKTEXT_ENABLE "Você tem uma " COLOR(RED) "Red Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"defina para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right ]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x15") "Beba com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"sua energia vital.\n"
"Você carrega esta poção em uma\n"
"das suas garrafas."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x16") QUICKTEXT_ENABLE "Você tem uma " COLOR(ADJUSTABLE) "Green Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"defina para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right ]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x16") "Beba com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"seu poder mágico.\n"
"Você carrega esta poção em uma\n"
"das suas garrafas."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x17") QUICKTEXT_ENABLE "Você tem uma " COLOR(BLUE) "Blue Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Beba com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para recuperar\n"
"sua energia vital e poder mágico."
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x18") QUICKTEXT_ENABLE "Você pegou uma " COLOR(RED) "Fada" COLOR(DEFAULT) " em uma garrafa!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x18") "Esta pequena fada é confiável \n"
"parceiro que vai reviver você\n"
"no momento em que você fica sem vida \n"
"energia." BOX_BREAK ITEM_ICON("\x18") "Depois de definir como " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"embora, você pode pedir sua ajuda\n"
"a qualquer momento."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x19") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Peixe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use-o com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e algo \n"
"pode acontecer... Parece tão \n"
"fresco e delicioso!" BOX_BREAK ITEM_ICON("\x19") "Na " COLOR(YELLOW) "Selecionar Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então pressione que\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para usá-lo."
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x10") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Magic Bean" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Encontre um local adequado para um jardim\n"
"e plante com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Então, aguarde\n"
"para que algo divertido aconteça!" BOX_BREAK ITEM_ICON("\x10") "Na " COLOR(YELLOW) "Selecionar Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então use isso\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para plantar."
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe por isso...OK, bem..." BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x3D") COLOR(RED) "LET'S BOWL" COLOR(DEFAULT) "!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x07") QUICKTEXT_ENABLE "Você recebeu o " COLOR(RED) "Fairy Ocarina" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta é uma lembrança de Saria.\n"
"Defina para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"para começar a jogar!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x07") "Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", e então use isso\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para começar a jogar." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x07") "Você pode tocar notas diferentes\n"
"com " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e os quatro botões " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". \n"
"Pressione " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para parar de jogar, ou \n"
"para começar sua música de novo."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3D") QUICKTEXT_ENABLE "Você tem a " COLOR(ADJUSTABLE) "Faca do Gigante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Segure com as duas mãos e use \n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "para atacar! É tão longo, você\n"
"não pode usá-lo com um escudo " COLOR(LIGHTBLUE)" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3E") QUICKTEXT_ENABLE "Você tem um " COLOR(LIGHTBLUE) "Deku Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Mudar para o " COLOR(BLUE) "Equipamento \n"
"Subtela" COLOR(RED) " " COLOR(DEFAULT) "e selecione o\n"
"escudo. Pressione " COLOR(BLUE) "[A] " COLOR(DEFAULT) "para equipá-lo." BOX_BREAK ITEM_ICON("\x3E") "Pressione " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para agachar e\n"
"defender. Se você pressionar " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " enquanto \n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", você pode mover\n"
"durante a defesa."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x3F") QUICKTEXT_ENABLE "Você tem um " COLOR(LIGHTBLUE) "Hylian Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Mudar para o " COLOR(BLUE) "Equipamento \n"
"Subtela" COLOR(DEFAULT) " e selecione isso\n"
"escudo, então equipe-o com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x40") QUICKTEXT_ENABLE "Você encontrou o " COLOR(LIGHTBLUE) "Mirror Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"A superfície polida do escudo pode\n"
"refletem luz ou energia. Pressione " COLOR(LIGHTBLUE) "[R]\n"
COLOR(DEFAULT) "para usá-lo."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0B") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Longshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"É um Hookshot atualizado.\n"
"Ele estende " COLOR(RED) "duas vezes" COLOR(DEFAULT) " até agora!"
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x42") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Túnica Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta túnica resistente ao calor é\n"
"tamanho adulto, então não cabe em uma criança...\n"
"Indo para um lugar quente? Não se preocupe!"
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x43") QUICKTEXT_ENABLE "Você tem um " COLOR(BLUE) "Túnica Zora" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Este traje de mergulho é tamanho adulto,\n"
"para que não caiba em uma criança. Use-o,\n"
"e você não vai se afogar debaixo d'água."
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem um " COLOR(ADJUSTABLE) "Magic Jar" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Seu medidor de magia está cheio!"
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x45") QUICKTEXT_ENABLE "Você tem o " COLOR(RED) "Iron Boots" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Tão pesado, você não pode correr.\n"
"Tão pesado, você não pode flutuar."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x46") QUICKTEXT_ENABLE "Você tem o " COLOR(RED) "Hover Boots" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Com essas botas misteriosas\n"
"você pode passar o mouse acima do solo.\n"
"A desvantagem? Sem tração!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x46") "Você pode até usá-los para\n"
"caminhar por curtos períodos onde \n"
"não há terra firme. Seja corajoso\n"
"e confie nas botas!"
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem um " COLOR(PURPLE) "Recovery Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua energia vital está recuperada!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x4B") QUICKTEXT_ENABLE "Você atualizou seu quiver para\n"
COLOR(RED) "Grande Aljava" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode carregar mais flechas-\n"
COLOR(YELLOW) "40" COLOR(DEFAULT) "no total!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x4B") QUICKTEXT_ENABLE "Você atualizou seu quiver para\n"
"a " COLOR(RED) "Maior Aljava" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode carregar ainda mais \n"
"setas, até um máximo de " COLOR(YELLOW) "50" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x4D") QUICKTEXT_ENABLE "Você encontrou um " COLOR(RED) "Bomb Bag" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta bolsa para bombas é feita \n"
"do estômago de um Dodongo!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x02") QUICKTEXT_ENABLE "Você encontrou " COLOR(RED) "20 Bombs" COLOR(DEFAULT) " dentro!" QUICKTEXT_DISABLE "\n"
"Agora você pode definir Bombas para " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "e explodir tudo! Que sorte \n"
"cara!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x4E") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Big Bomb Bag" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode carregar mais \n"
"Bombas, até um máximo de " COLOR(YELLOW) "30" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x4F") QUICKTEXT_ENABLE "Você tem o \n"
COLOR(RED) "Maior saco de bombas" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora, você pode carregar até \n"
COLOR(YELLOW) "40" COLOR(DEFAULT) "Bombas!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x51") QUICKTEXT_ENABLE "Você encontrou as " COLOR(BLUE) "Silver Gauntlets" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Se você os usasse, você\n"
"sinta poder em seus braços, o \n"
"poder para levantar grandes coisas com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x51") "Mas essas luvas não cabem\n"
"uma criança... Além disso, você prometeu dar\n"
"eles para " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Você deve manter\n"
"sua palavra..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x52") QUICKTEXT_ENABLE "Você encontrou o " COLOR(BLUE) "Golden Gauntlets" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você pode sentir ainda mais poder \n"
"correndo pelos seus braços!\n"
"Pegue com " COLOR(BLUE) "[A] " COLOR(DEFAULT) "e levante coisas!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1C") QUICKTEXT_ENABLE "Você coloca um " COLOR(LIGHTBLUE) "Blue Fire" COLOR(DEFAULT) "\n"
"na garrafa!" QUICKTEXT_DISABLE "\n"
"Esta é uma chama legal que você pode\n"
"use com " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " ou" COLOR(YELLOW) " [C-Right] " COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x56") QUICKTEXT_ENABLE "Você tem uma " COLOR(BLUE) "Carteira de adulto" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Adultos podem carregar um \n"
"muito dinheiro. Agora você pode segurar \n"
"até " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rúpias" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x57") QUICKTEXT_ENABLE "Você tem uma " COLOR(BLUE) "Carteira do Gigante" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Que carteira enorme! Agora \n"
"você pode carregar até " COLOR(YELLOW) "500" COLOR(DEFAULT) " " COLOR(YELLOW) "Rúpias" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77") QUICKTEXT_ENABLE "Você encontrou uma " COLOR(RED) "Small Key" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta chave abrirá um \n bloqueado"
"porta. Você só pode usá-la\n"
"nessa masmorra."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombchu (20 peças) 180 Rupees\n"
COLOR(DEFAULT) "Isso parece um mouse de brinquedo, mas\n"
"na verdade é um tempo autopropulsado\n"
"bombear!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Red Potion 40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Vermelha 50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Red Potion 40 Rupees\n"
COLOR(DEFAULT) "Se você beber isso, você vai\n"
"recupere sua energia vital.\n"
"Esta é uma dose única." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Red Potion 50 Rupees\n"
COLOR(DEFAULT) "Se você beber isso, você vai\n"
"recupere sua energia vital.\n"
"Esta é uma dose única." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x76") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Mapa da Masmorra" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pressione " COLOR(RED) "START" COLOR(DEFAULT) "para entrar no \n"
"Subtelas e olhe para o\n"
COLOR(RED) "Mapa Subtela" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x76") COLOR(BLUE) "Câmaras azuis" COLOR(DEFAULT) " são lugares \n"
"você já visitou. \n"
"Sua localização atual é \n"
"a " COLOR(LIGHTBLUE) "sala piscando" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x76") "Mover " COLOR(LIGHTBLUE) "[Control-Pad] para cima e para baixo" COLOR(DEFAULT) " para \n"
"escolha um andar para ver."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x75") QUICKTEXT_ENABLE "Você encontrou o " COLOR(RED) "Compass" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode ver os locais\n"
"de muitas coisas escondidas no\n"
"masmorra!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6F") QUICKTEXT_ENABLE "Você obteve a " COLOR(RED) "Pedra da Agonia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Se você equipar um " COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", ele\n"
"vai reagir a segredos próximos... segredos."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x23") QUICKTEXT_ENABLE "Você recebeu " COLOR(RED) "Carta de Zelda" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Uau! Esta carta tem Princesa\n"
"Autógrafo de Zelda! Configure para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"e mostre com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x23") "Na " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e então use aquela " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para mostrá-la\n"
"Para pessoas."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bem-vindo! Posso ajudá-lo?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Quero comprar\n"
"Apenas olhando" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você gostaria de comprar algo\n"
"senão?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x49") QUICKTEXT_ENABLE "Seu " COLOR(RED) "Bolsa de Sementes Deku \n"
COLOR(DEFAULT) "tornou-se maior!" QUICKTEXT_DISABLE "\n"
"Agora você pode carregar mais balas!\n"
"Esta bolsa pode conter " COLOR(YELLOW) "50" COLOR(RED) " " COLOR(DEFAULT) "balas!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Abra o baú e...Surpresa!\n"
"Se você encontrar uma chave dentro, você \n"
"poder avançar. Esquerda ou\n"
"certo - tente sua sorte!" BOX_BREAK COLOR(RED) "10 Rupees " COLOR(DEFAULT) "para jogar. Você quer \n"
"experimentar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ótimo! Você é um jogador de verdade!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem uma " COLOR(ADJUSTABLE) "Rúpia Verde" COLOR(DEFAULT) "!\n"
"Isso é " COLOR(ADJUSTABLE) "uma rupia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x04") QUICKTEXT_ENABLE "Você tem a " COLOR(RED) "Fire Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Defina como " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e suas setas irão\n"
"seja ligado! Se você pressionar\n"
"seu alvo, ele vai pegar fogo."
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0C") QUICKTEXT_ENABLE "Você tem a " COLOR(BLUE) "Ice Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Defina como " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e suas setas irão\n"
"seja ligado! Se você acertar seu \n"
"alvo, ele vai congelar." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0C") "Esta magia de seta é concedida\n"
"somente para quem completa o \n"
"treinamento difícil dos Gerudos,\n"
"então use-o com orgulho!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x12") QUICKTEXT_ENABLE "Você tem o " COLOR(LIGHTBLUE) "Light Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Defina como " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e suas setas irão\n"
"seja ligado! A luz de\n"
"a justiça ferirá o mal!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o\n"
SHIFT("\x2F") COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o\n"
SHIFT("\x37") COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o \n"
SHIFT("\x29") COLOR(BLUE) "Serenata de Água" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o \n"
SHIFT("\x2D") COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o \n"
SHIFT("\x28") COLOR(RED) "Noturno das Sombras" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x28") "Você aprendeu o \n"
SHIFT("\x32") COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x50") QUICKTEXT_ENABLE "Você tem a " COLOR(RED) "Pulseira do Goron" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode puxar a Bomba \n"
"Flores. Fique ao lado de uma e\n"
"use " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para puxá-lo para cima!"
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1D") QUICKTEXT_ENABLE "Você colocou um " COLOR(RED) "Bug " COLOR(DEFAULT) "na garrafa!" QUICKTEXT_DISABLE "\n"
"Você pode soltá-lo pressionando\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Este tipo de bug prefere\n"
"viver em pequenos buracos no chão."
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x70") QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Gerudo's \n"
"Cartão de Sócio" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você pode entrar no Gerudo's\n"
"campo de treinamento em seu esconderijo."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas 10 peças 50 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Setas 50 peças 90 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Peixe 200 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku Nuts 5 peças 15 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6C") QUICKTEXT_ENABLE "Você tem a " COLOR(ADJUSTABLE) "Kokiri's Emerald" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta é a Pedra Espiritual de \n"
"a Floresta, agora confiada a \n"
"você pela Grande Árvore Deku."
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6D") QUICKTEXT_ENABLE "Você obteve o " COLOR(RED) "Goron's Ruby" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta é a Pedra Espiritual de \n"
"Fogo transmitido pelos Gorons!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x6E") QUICKTEXT_ENABLE "Você obteve " COLOR(BLUE) "Zora's Sapphire" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta é a Pedra Espiritual de\n"
"Água passada pelo\n"
"Zoras!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Compre movendo o \n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "esquerda ou direita.\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Fale com o proprietário\n"
"Sair" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Muito obrigado!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você não tem Rúpias suficientes!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você não pode obter isso agora." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku Nuts 10 unidades 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku Stick 1 peça 10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku Shield 40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Seta 10 peças 20 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bomba 5 peças 25 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombchu 10 peças 100 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você não pode usar um Big Poe aqui!\n"
"Venda para o homem em Hyrule\n"
"Portão da Cidade do Castelo!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Vermelha 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Poção Verde 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x00") QUICKTEXT_ENABLE "Agora você pode pegar \n"
"muitos" COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"Você pode carregar até " COLOR(YELLOW) "20" COLOR(DEFAULT) " deles!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x00") QUICKTEXT_ENABLE "Agora você pode pegar \n"
"ainda mais" COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"Você pode carregar até " COLOR(YELLOW) "30" COLOR(DEFAULT) " deles!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Hylian Shield 80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Túnica Goron 200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Túnica Zora 300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Recovery Heart 10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Desculpe... não posso vender isso para\n"
"você, a menos que tenha uma garrafa para \n"
"coloque dentro." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x20") QUICKTEXT_ENABLE "Você pegou um " COLOR(RED) "Poe " COLOR(DEFAULT) "em uma garrafa!" QUICKTEXT_DISABLE "\n"
"Alguma coisa boa pode acontecer!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1A") QUICKTEXT_ENABLE "Você tem " COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Este leite é muito nutritivo!\n"
"Use-o com " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para recuperar seu \n"
"energia da vida!" BOX_BREAK ITEM_ICON("\x1A") "Você recuperará " COLOR(RED) "cinco corações" COLOR(DEFAULT) "\n"
"por bebida. Há dois\n"
"bebidas por garrafa." BOX_BREAK ITEM_ICON("\x1A") "Na " COLOR(YELLOW) "Selecionar Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e então use aquele " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para pegar \n"
"uma bebida."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x1B") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Garrafa Vazia" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Coloque algo dentro e \n"
"pressione " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para usar... O quê?\n"
"Alguma coisa já está dentro!?"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x21") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Weird Egg" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Parece que há algo\n"
"movendo-se para dentro! Configure para " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e \n"
"veja o que acontece!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x21") "Na opção " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) ",\n"
"você pode configurá-lo para " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "ou " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"e então pressione " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "para usá-lo."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Setas 30 peças 60 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu vendedor atual é o \n"
COLOR(LIGHTBLUE) "Hylian Shield" COLOR(DEFAULT) ", mas pode ser muito \n"
"grande para você, garoto." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nós nos mudamos do castelo para cá \n"
"cidade. Eu sei que os tempos estão difíceis, mas\n"
"Espero que você seja uma pessoa estável \n"
"cliente para nós!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x47") "Bem-vindo!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Deku Shield 40 Rupees\n"
COLOR(DEFAULT) "Uma vez equipado, você pode defender \n"
"com " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". Se for incendiado, irá\n"
"queimar!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Seta (10 peças) 20 Rupees\n"
COLOR(DEFAULT) "Você precisa de um arco para atirar neles.\n"
"Você não pode comprá-los a menos que\n"
"tenha um arco." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Deku Stick (1 peça) 10 Rupees\n"
COLOR(DEFAULT) "Um longo galho recolhido do\n"
"Grande Árvore Deku. Você pode usá-la\n"
"como uma arma, mas vai quebrar." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Deku Nuts (10 peças) 30 Rupees\n"
COLOR(DEFAULT) "Jogue-os para atordoar seus inimigos.\n"
"Você pode comprar apenas a quantidade que\n"
"pode realmente carregar." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombas (5 peças) 25 Rupees\n"
COLOR(DEFAULT) "Retire com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para jogá-lo. Você pode comprá-los\n"
"só se você tiver um saco de bomba." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x3B") QUICKTEXT_ENABLE "Você tem a " COLOR(ADJUSTABLE) "Kokiri Sword" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Na " COLOR(BLUE) "Equipamento Subtela" COLOR(DEFAULT) ",\n"
"selecione-o com o cursor e\n"
"equipá-lo com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x3B") "Este é um tesouro escondido de\n"
"o Kokiri, mas você pode pegar emprestado\n"
"por um tempo. Certifique-se de praticar \n"
"com ele antes de você realmente lutar!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Red Potion 30 Rupees\n"
COLOR(DEFAULT) "Beba para recuperar sua energia vital.\n"
"Esta é apenas uma dose única." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Green Potion 30 Rupees\n"
COLOR(DEFAULT) "Beba para recuperar seu poder mágico.\n"
"Esta é apenas uma dose única." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x01") QUICKTEXT_ENABLE "Agora você pode carregar\n"
"muitos" COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "!\n"
"Você pode armazenar até " COLOR(YELLOW) "30" COLOR(DEFAULT) " nozes!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x01") QUICKTEXT_ENABLE "Agora você pode carregar mesmo\n"
"mais " COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "! Você pode carregar\n"
"até " COLOR(YELLOW) "40" COLOR(RED) " " COLOR(DEFAULT) "nozes!" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Hylian Shield 80 Rupees\n"
COLOR(DEFAULT) "Este é um escudo grande e pesado apenas \n"
"como os que os Cavaleiros Hylians usam.\n"
"Ele pode resistir a ataques de chamas!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Túnica Goron 200 Rupees\n"
COLOR(DEFAULT) "Uma túnica feita por Gorons. Adulto\n"
"tamanho. Protege você do calor\n"
"dano." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Túnica Zora 300 Rupees\n"
COLOR(DEFAULT) "Uma túnica feita por Zoras. Tamanho adulto.\n"
"Evita que você se afogue\n"
"embaixo da agua." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Recovery Heart 10 Rupees\n"
COLOR(DEFAULT) "Isto irá recarregar instantaneamente um\n"
"Recipiente de coração." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x05") QUICKTEXT_ENABLE "Você tem " COLOR(RED) "Din's Fire" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua bola de fogo engole tudo!\n"
"É magia de ataque que você pode usar\n"
"com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x0D") QUICKTEXT_ENABLE "Você tem " COLOR(ADJUSTABLE) "Vento de Farore" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Esta é uma magia de distorção que você pode usar \n"
"com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Distorcer quando estiver em \n"
"perigo!" BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0D") "Você se teletransportará para a " COLOR(ADJUSTABLE) "Warp\n"
"Point" COLOR(DEFAULT) ". Quando você usa o magia\n"
"pela primeira vez, você criará um Warp\n"
"Apontar." BOX_BREAK UNSKIPPABLE ITEM_ICON("\x0D") "Quando você usa a mágica \n"
"novamente, você pode dissipar\n"
"o Warp Point que você criou por último\n"
"tempo ou dobra a esse ponto."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x13") QUICKTEXT_ENABLE "Você tem " COLOR(BLUE) "Nayru's Love" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Transmita isto para criar um poderoso\n"
"barreira protetora. É defensiva \n"
"magia que você pode usar com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Setas (50 peças) 90 Rupees\n"
COLOR(DEFAULT) "Atire neles com um arco. Você não pode\n"
"compre-os a menos que você tenha um arco." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombas (10 peças) 50 Rupees\n"
COLOR(DEFAULT) "Retire com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " novamente para jogá-lo. Você não pode\n"
"comprá-los sem um saco de bomba." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Deku Nuts (5 peças) 15 Rupees\n"
COLOR(DEFAULT) "Jogue-os para atordoar seus inimigos.\n"
"Você pode carregar apenas um \n limitado"
"quantidade deles". QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Peixe 200 Rupees\n"
COLOR(DEFAULT) "Acabado de pegar e tão fresco!\n"
"Você pode mantê-lo em uma garrafa." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você destruiu uma " COLOR(RED) "Gold Skulltula" COLOR(DEFAULT) ".\n"
"Você tem um token provando que você \n"
"destruiu!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você destruiu uma " COLOR(RED) "Gold Skulltula" COLOR(DEFAULT) ".\n"
"Você tem um token provando que você \n"
"destruiu!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Espírito de Fada 50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Espírito de Fada 50 Rupees\n"
COLOR(DEFAULT) "Você precisa de uma garrafa vazia para colocar\n"
"entrou. Não vá para a batalha \n"
"sem isso!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Fogo Azul 300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Blue Fire 300 Rupees\n"
COLOR(DEFAULT) "Você precisa de uma garrafa vazia para colocar\n"
"this in. Use-o para sentir \n"
"frescura refrescante." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bottle Bug 50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bottle Bug 50 Rupees\n"
COLOR(DEFAULT) "Você precisa de uma garrafa vazia para colocar\n"
"está dentro. Parece apenas um\n"
"bug normal..." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombchu (10 peças) 100 Rupees\n"
COLOR(DEFAULT) "Isso parece um mouse de brinquedo, mas\n"
"na verdade é um tempo autopropulsado\n"
"bombear!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Estamos temporariamente sem\n"
"estoque sobre esse item." COLOR(DEFAULT) QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vamos, cara! Você está velho demais para \n"
"este jogo!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x40") "Hein? O que--!" BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x50") "Uh-oh!" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x3E") "Um cliente!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x39") "zzzzz...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Setas (30 peças) 60 Rupees\n"
COLOR(DEFAULT) "Você precisa de um arco para atirar neles.\n"
"Use-os, e você vai acabar." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Colete quatro peças no total para obter\n"
"outro recipiente de coração. Mais\n"
"recipientes significam mais energia vital!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Até agora, você coletou dois \n"
"peças. Com mais duas peças, \n"
"você vai ganhar mais energia vital!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você coletou três \n"
"peças! Com outra peça, seu \n"
"energia vital será energizada!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você completou outro Coração\n"
"Contêiner! Sua vida máxima\n"
"energia é aumentada!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x72") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Heart Container" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Sua energia vital máxima é \n"
"aumentado por um coração. Sua vida\n"
"a energia será totalmente preenchida."
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x74") QUICKTEXT_ENABLE "Você tem a " COLOR(RED) "Chave do Chefe" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Agora você pode entrar no \n"
"câmara onde o chefe se esconde."
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não, você não tem o suficiente\n"
"Rúpias!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x24") "Tudo bem, pronto!" QUICKTEXT_DISABLE "\n"
"Por favor, espere do lado de fora enquanto eu ajusto \n"
"até o seu próximo desafio!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Bombas 5 peças 35 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Bombas (5 peças) 35 Rupees\n"
COLOR(DEFAULT) "Retire com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e pressione \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " novamente para jogá-lo. Você não pode\n"
"comprá-los sem um saco de bomba." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem um " COLOR(BLUE) "Blue Rupee" COLOR(DEFAULT) "!\n"
"Isso é " COLOR(BLUE) "cinco rúpias" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x53") QUICKTEXT_ENABLE "Você tem o " COLOR(BLUE) "Silver Scale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pule na água e pressione \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Você pode mergulhar mais fundo do que você\n"
"poderia antes."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE ITEM_ICON("\x54") QUICKTEXT_ENABLE "Você tem a " COLOR(BLUE) "Golden Scale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Pule na água e pressione \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Agora você pode mergulhar muito\n"
"mais profundo do que você poderia antes!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Parece que este item não \n"
"trabalhe aqui..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Não abre!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x14") "Você aprendeu " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x11") "Você aprendeu " COLOR(RED) "Epona's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x0B") "Você aprendeu a " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x15") "Você aprendeu " COLOR(BLUE) "Zelda's Lullaby" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x05") "Você aprendeu a " COLOR(LIGHTBLUE) "Song of Time" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você aprendeu a " COLOR(PURPLE) "Song of Storms" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Eu sou a Grande Fada do Poder!" BOX_BREAK UNSKIPPABLE "Vou conceder a você uma " COLOR(ADJUSTABLE) "espada\n"
"técnica" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receba agora!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Eu sou a Grande Fada da Sabedoria!" BOX_BREAK UNSKIPPABLE "Vou aprimorar sua mágica " COLOR(ADJUSTABLE) "\n"
"power" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receba agora!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Eu sou a Grande Fada da Coragem!" BOX_BREAK UNSKIPPABLE "Vou aprimorar seu \n"
COLOR(LIGHTBLUE) "poder defensivo" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receba agora!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando você estiver cansado da batalha,\n"
"Por favor, volte para me visitar!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem-vindo " NAME "!\n"
"Eu vou aliviar suas feridas." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x58") QUICKTEXT_ENABLE "Você tem " COLOR(RED) "Deku Seeds" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Estas são sementes pequenas e duras\n"
"que você pode usar como marcadores\n"
"para o seu estilingue."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE UNSKIPPABLE "Você dominou a espada secreta\n"
"técnica do " COLOR(RED) "Spin Attack" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Segure " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para carregar sua arma!\n"
"Libere " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " para desencadear uma onda\n"
"de energia com seu giro!" BOX_BREAK UNSKIPPABLE "Se você quiser liberar energia\n"
"sem carregar sua arma, apenas \n"
COLOR(LIGHTBLUE) "gire [Control-Pad] uma vez" COLOR(DEFAULT) "e pressione" COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "para" COLOR(ADJUSTABLE) "\n"
COLOR(DEFAULT) "um giro rápido muito eficaz!"
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Deku Seeds 30 peças 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Deku Seed (30 peças) 30 Rupees\n"
COLOR(DEFAULT) "Você pode usá-los como marcadores para\n"
"seu estilingue. Você não pode comprar \n"
"a menos que você tenha um estilingue." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você quer falar com Saria, certo?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Fale com Saria\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Sério? Então você quer falar \n"
"para homens"
COLOR(DEFAULT) TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x3C") NAME "...?\n"
SHIFT("\x0D") "Este é " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Você pode me ouvir?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você quer falar com Saria\n"
"novamente?" COLOR(DEFAULT) "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Seu " COLOR(ADJUSTABLE) "Magic Meter" COLOR(DEFAULT) " foi aprimorado!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Seu " COLOR(LIGHTBLUE) "poder defensivo" COLOR(DEFAULT) " foi aprimorado!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Você tem um pacote de flechas " COLOR(YELLOW) "" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando você carrega energia para um Spin\n"
"Ataque, poder mágico será\n"
"consumido. Preste atenção ao seu\n"
"verde" COLOR(ADJUSTABLE) "Medidor Mágico" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ei, garoto! Você é um mensageiro de\n"
"A Família Real, não é?" BOX_BREAK UNSKIPPABLE "Na próxima vez que você estiver no local\n"
"bairro, você deveria aparecer\n"
"em um amigo meu que mora de\n"
"Castelo de Hyrule." BOX_BREAK UNSKIPPABLE "Ela certamente lhe concederá outro\n"
"novo poder!"
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu poder mágico foi \n"
"aprimorado! Agora você tem duas vezes\n"
"tanto" COLOR(RED) "Poder Mágico" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu poder defensivo foi \n"
"aprimorado! Danos infligidos por \n"
"os inimigos serão " COLOR(RED) "reduzido pela metade" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Bem-vindo " NAME "!\n"
"Eu sou a Grande Fada da Magia!" BOX_BREAK UNSKIPPABLE "Vou te dar um "feitiço mágico" COLOR(RED) "COLOR(DEFAULT) ".\n"
"Por favor, pegue."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Desculpe, mas você não pode emprestar\n"
"esta máscara ainda." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você pode usar " COLOR(RED) "Din's Fire" COLOR(DEFAULT) " não apenas para\n"
"atacar, mas também para queimar coisas!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Lembre-se, você pode usar " COLOR(ADJUSTABLE) "Farore's\n"
"Vento" COLOR(DEFAULT) " apenas em masmorras que tenham\n"
"um mapa de masmorra escondido dentro, OK?"
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(BLUE) "Amor de Nayru" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "está em vigor apenas\n"
"um tempo limitado, então use-o com cuidado."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando a batalha o cansou,\n"
"Por favor, volte para me ver."
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você recebeu um " COLOR(RED) "Rupia Vermelha" COLOR(DEFAULT) "!\n"
"Isso é " COLOR(RED) "vinte rúpias" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Rúpia Roxa" COLOR(DEFAULT) "!\n"
"Isso é " COLOR(RED) "cinquenta rúpias" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você tem um " COLOR(YELLOW) "Huge Rupee" COLOR(DEFAULT) "!\n"
"Esta rúpia vale muito\n"
COLOR(YELLOW) "duzentas rúpias" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x77") QUICKTEXT_ENABLE "Você tem uma " COLOR(RED) "Chave da porta" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use esta chave para continuar para o\n"
"próxima sala. Selecione um tesouro \n"
"peito e veja como você é sortudo!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT) BOX_BREAK QUICKTEXT_ENABLE "Você encontrou apenas " COLOR(ADJUSTABLE) "uma rupia" COLOR(DEFAULT) ".\n"
"Você não tem muita sorte." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT) BOX_BREAK QUICKTEXT_ENABLE "Você encontrou " COLOR(BLUE) "cinco rúpias" COLOR(DEFAULT) ".\n"
"Mesmo assim, você não tem muita sorte." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Perdedor!" COLOR(DEFAULT) BOX_BREAK QUICKTEXT_ENABLE "Você encontrou " COLOR(RED) "vinte rúpias" COLOR(DEFAULT) ".\n"
"Sua última seleção foi um erro,\n"
"não foi! Que frustrante!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Vencedor!" COLOR(DEFAULT) BOX_BREAK QUICKTEXT_ENABLE "Você encontrou " COLOR(YELLOW) "cinquenta rúpias" COLOR(DEFAULT) ".\n"
"Você é um cara genuinamente sortudo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
ITEM_ICON("\x1E") QUICKTEXT_ENABLE "Você coloca um " COLOR(RED) "Big Poe " COLOR(DEFAULT) "em uma garrafa!" QUICKTEXT_DISABLE "\n"
"Vamos vendê-lo na " COLOR(RED) "Ghost Shop" COLOR(DEFAULT) "!\n"
"Alguma coisa boa pode acontecer!"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49") COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Colete quatro peças no total para obter\n"
"outro recipiente de coração. Mais\n"
"recipientes significam mais energia vital!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49") COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Até agora, você coletou dois \n"
"peças. Com mais duas peças, \n"
"você vai ganhar mais energia vital!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49") COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você coletou três peças!\n"
"Com outro pedaço, sua vida \n"
"energia será energizada!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
SHIFT("\x49") COLOR(RED) "VENCEDOR" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73") QUICKTEXT_ENABLE "Você tem um " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Você completou outro Coração\n"
"Contêiner! Sua vida máxima\n"
"energia é aumentada!"
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Procure-os não apenas no\n"
"aberto, mas também dentro das masmorras." BOX_BREAK "Claro, este é apenas o nosso sonho...\n"
"Você não precisa fazer isso se\n"
"não quero..." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "O que é isso?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Olha, olha, " NAME "!\n"
"Você pode ver abaixo desta " COLOR(DEFAULT) "web" COLOR(LIGHTBLUE) "\n"
"usando " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Olhe para esta parede! As vinhas\n"
"crescendo nele dá um tom áspero\n"
"superfície... Talvez você possa escalar \n"
"ele", "NAME"!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você pode abrir uma porta " COLOR(DEFAULT)" COLOR(LIGHTBLUE) " ficando de pé\n"
"na frente dele e pressionando " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Preste atenção no que\n"
COLOR(BLUE) "Ação" COLOR(LIGHTBLUE) " " COLOR(BLUE) "Ícone" COLOR(LIGHTBLUE) " diz.\n"
"Esse é o ícone azul " COLOR(BLUE)" COLOR(LIGHTBLUE) " na parte superior de\n"
"a tela!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Olha! Algo está desligando\n"
"lá! Parece uma antiga " COLOR(DEFAULT) "escada" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Ei...\n"
"Não é o mesmo design que é\n"
"na " COLOR(DEFAULT) "Porta do Tempo" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que aquela tocha foi\n"
"queimando não muito tempo atrás..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Daqui em diante, vamos\n"
"através de algumas passagens estreitas!\n"
"Se você for devagar, talvez você\n"
"pode se aproximar de alguns inimigos." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] Segmentação " COLOR(LIGHTBLUE) "para sempre olhar\n"
"na direção correta. Defina seu\n"
"ver para que você possa ver o próximo\n"
"corredor antes de virar uma esquina." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Depois de definir a visualização, mantenha pressionado\n"
COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "para " COLOR(DEFAULT) "desviar" COLOR(LIGHTBLUE) "ao virar da esquina.\n"
"Dessa forma você não ficará surpreso\n"
"por um inimigo esperando em emboscada." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Fique próximo a este " COLOR(DEFAULT) "bloco" COLOR(LIGHTBLUE) " e pegue\n"
"segure com " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". Enquanto segura\n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", você pode empurrar ou puxar." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Se você estiver ao lado do bloco " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "\n"
"e pressione " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) " enquanto pressiona " COLOR(DEFAULT) "[Control-Pad]" COLOR(LIGHTBLUE) "\n"
"em direção ao " COLOR(DEFAULT) "bloco" COLOR(LIGHTBLUE) ", você pode subir\n"
"no topo disso." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Preste atenção na ação" COLOR(BLUE)"\n"
"Ícone " COLOR(LIGHTBLUE) "diz!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Depois de entrar na água, se\n"
"você segura" COLOR(BLUE) " [A]" COLOR(LIGHTBLUE) ", você pode mergulhar!\n"
"Aposto que há alguns interessantes\n"
"coisas debaixo d'água!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Uau! Olhe para todos aqueles \n"
COLOR(DEFAULT) "Flores Bomba" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE COLOR(LIGHTBLUE) "Existe alguma maneira de definir\n"
"todos eles de uma vez?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que há muitas " COLOR(DEFAULT) "lava\n"
"pits " COLOR(LIGHTBLUE) "por aqui, então cuidado com o seu\n"
"Passo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Com esse interruptor ligado, o movimento\n"
COLOR(DEFAULT) "plataforma " COLOR(LIGHTBLUE) "vai mais alto. Agora você pode\n"
"chegar rápido ao segundo andar!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você nunca sabe o que será \n"
"ao virar da esquina nestes estreitos\n"
"caminhos...." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] Segmentação " COLOR(LIGHTBLUE) "para sempre procurar\n"
"na direção correta. Este é um\n"
"técnica útil, não é?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) NAME ", o que você é \n"
"olhando para?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "O rosto do Colosso do Deserto... ele \n"
"certamente parece mal!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Eu posso ouvir os espíritos sussurrando \n"
"neste quarto..." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE "\"Procure o olho da verdade...\"\n"
COLOR(LIGHTBLUE) "Isso é o que eles estão dizendo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Aqui... posso ouvir os espíritos\n"
"sussurrando nesta sala..." COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE "\"Aqueles que têm " COLOR(RED) "pés sagrados" COLOR(DEFAULT) "\n"
"devem deixar o vento guiá-los.\n"
"Então, eles serão levados para o \n"
"caminho oculto.\"" BOX_BREAK COLOR(LIGHTBLUE) "Isso é o que eles estão dizendo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta parede... diz algo aqui...\n"
COLOR(DEFAULT) "\"Perigo acima...\"" COLOR(LIGHTBLUE) "\n"
"É o que diz." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta parede... diz algo aqui...\n"
COLOR(DEFAULT) "\"Perigo abaixo...\"\n"
COLOR(LIGHTBLUE) "É o que diz." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "A água que sai deste \n"
"estátua está inundando o andar inteiro." COLOR(DEFAULT)
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
"A eletricidade está passando\n"
"esta " COLOR(ADJUSTABLE) "coisa verde viscosa" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado com " NAME "!\n"
"A eletricidade está passando\n"
"este " COLOR(RED) "coisa viscosa vermelha" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado com " NAME "!\n"
"A eletricidade está passando\n"
"este " COLOR(BLUE) "coisa azul viscosa" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta" COLOR(DEFAULT) "troca" COLOR(LIGHTBLUE) "...\n"
"Parece que você não pode pressionar\n"
"abaixe apenas com o seu peso,\n"
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "A coisa vermelha e viscosa " COLOR(RED)" COLOR(LIGHTBLUE) "desapareceu! \n"
"Isso deve ser porque você cortou o\n"
COLOR(RED) "red tail" COLOR(LIGHTBLUE) "! Isso funcionará com \n"
"os outros também?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há um interruptor além deste \n"
"muro!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Parece que há algo\n"
"lá em cima da plataforma!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x42") COLOR(LIGHTBLUE) "O QUE!?" BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Olhe para todas aquelas bandeiras " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "!\n"
"Você consegue descobrir quais são\n"
"real?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A " COLOR(DEFAULT) "Great Deku Tree" COLOR(RED) " " COLOR(LIGHTBLUE) "tem \n"
"convoquei você!\n"
"Por favor, venha comigo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos! Seja corajoso!\n"
"Vamos para o \n"
"Grande Árvore Deku!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A Grande Árvore Deku nos queria\n"
"ir visitar a princesa às\n"
COLOR(DEFAULT) "Hyrule Castle" COLOR(LIGHTBLUE) ".... Não deveríamos\n"
"ir indo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "A garota do rancho nos pediu\n"
"para encontrá-la" COLOR(DEFAULT) "pai" COLOR(LIGHTBLUE) "...Eu me pergunto onde\n"
"ele é?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Gostaria de saber onde encontraremos o \n"
COLOR(DEFAULT) "princesa" COLOR(LIGHTBLUE) "neste grande e velho castelo?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "O que diria " COLOR(DEFAULT) "Saria" COLOR(RED) " " COLOR(LIGHTBLUE) "se disséssemos\n"
"ela vamos salvar Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Impa " COLOR(LIGHTBLUE) "disse que a Pedra Espiritual\n"
"of Fire está em algum lugar em " COLOR(DEFAULT) "Morte\n"
"Montanha" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos entrar no Dodongo's\n"
"Cavern usando um " COLOR(DEFAULT) "Bomb Flower" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Darunia disse que uma fada " COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "vive no topo da Montanha da Morte,\n"
"não foi?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Gostaria de saber se " COLOR(DEFAULT) "Saria " COLOR(LIGHTBLUE) "sabe alguma coisa\n"
"sobre a outra Pedra Espiritual?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Parece " COLOR(DEFAULT) "Princesa Ruto" COLOR(LIGHTBLUE) "de alguma forma " COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "entrou na barriga do Jabu-Jabu..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você coletou três Espirituais\n"
"Pedras! Vamos voltar para " COLOR(DEFAULT) "Hyrule\n"
"Castelo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquelas pessoas no cavalo branco...\n"
"eles eram Zelda e Impa, não eram\n"
"eles? Parecia que eles jogaram \n"
"algo no " COLOR(DEFAULT) "fosso" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos verificar dentro do \n"
COLOR(DEFAULT) "Templo do Tempo" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Devemos acreditar no que Sheik disse \n"
"e vá para " COLOR(DEFAULT) "Vila Kakariko" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Eu me pergunto o que está acontecendo no\n"
"floresta agora... estou preocupado\n"
"sobre " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) ", também!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquela nuvem sobre" COLOR(DEFAULT) "Death Mountain" COLOR(LIGHTBLUE) "...\n"
"há algo estranho sobre \n"
"isso..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Um vento ártico está soprando\n"
COLOR(DEFAULT) "Rio de Zora" COLOR(LIGHTBLUE) "...você sente isso?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquelas" COLOR(DEFAULT) "Iron Boots" COLOR(LIGHTBLUE) "parece\n"
"eles pesam uma tonelada! Se você usar\n"
"essas botas, você pode\n"
"andar no fundo de um lago." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Vamos procurar alguém que possa\n"
"saber algo sobre o outro\n"
COLOR(DEFAULT) "Sábios" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquele monstro! Saiu do \n"
COLOR(DEFAULT) "bem na vila" COLOR(LIGHTBLUE) "! Vamos \n"
"confira o poço!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Eu me pergunto quem construiu o " COLOR(DEFAULT) "Spirit" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "Templo" COLOR(LIGHTBLUE) ", e para que finalidade?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Você já jogou o \n"
COLOR(RED) "Noturno das Sombras" COLOR(LIGHTBLUE) " aquele Sheik\n"
"ensinei você?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "deserto" COLOR(LIGHTBLUE) "...que é onde\n"
"Ganondorf, o Rei Maligno, nasceu.\n"
"Se formos lá, podemos encontrar\n"
"algo..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Equipe as " COLOR(DEFAULT) "Manoplas de Prata \n"
COLOR(LIGHTBLUE) "e tente mover as coisas que você \n"
"não podia ceder antes!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Aquele que está esperando por nós em\n"
"o Templo do Tempo... pode ser..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Temos que salvar a Princesa Zelda\n"
"de sua prisão na casa de Ganon\n"
"Castelo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) NAME "...\n"
"Tente se manter em movimento!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Não me importo de falar com você \n"
"usando a magia da Ocarina, mas\n"
"Gostaria muito de falar com você\n"
"cara a cara!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"A floresta está conectada a muitos \n"
"lugares! Se você puder ouvir minha música,\n"
"você deve estar em algum lugar que seja\n"
"conectado à floresta!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Fiquei muito feliz em saber disso\n"
"O Sr. Darunia adorou minha música, então\n"
"Muito de!" BOX_BREAK "Fiquei ainda mais feliz em descobrir\n"
"que o ajudou em sua missão,\n"
NAME "!\n"
"Tee-hee-hee!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está coletando Espiritual\n"
"Pedras? Você tem mais uma para\n"
"encontrar? Você quer dizer a " COLOR(BLUE) "Espiritual \n"
"Pedra da Água" COLOR(DEFAULT) ", não é?" BOX_BREAK "A Grande Árvore Deku me disse uma vez\n"
"aquele" COLOR(BLUE) "Rei Zora, governante de Zora\n"
"Domínio," COLOR(DEFAULT) "tem..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está coletando Espiritual\n"
"Pedras? Você tem mais uma para\n"
"encontrar? Você quer dizer a " COLOR(RED) "Espiritual \n"
"Pedra de Fogo" COLOR(DEFAULT) ", não é?" BOX_BREAK "A Grande Árvore Deku me disse uma vez\n"
"aquele " COLOR(RED) "Sr. Darunia dos Gorons\n"
COLOR(DEFAULT) "tem..." EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"Não sei o que é...\n"
"Tenho uma sensação de pavor..." BOX_BREAK "O Castelo...\n"
"Sim, algo ruim está acontecendo\n"
"no Castelo!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"O quê? Sua ocarina soa...\n"
"diferente de alguma forma... \n"
"Você tem praticado muito,\n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você está procurando um templo?\n"
"Um pássaro misterioso uma vez me disse..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Olhos que podem ver através \n"
"A escuridão se abrirá em uma tempestade." COLOR(DEFAULT) "\"\n"
"Você tem ideia do que ele \n"
"quer dizer com isso?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Onde você está, " NAME "?\n"
"Você está procurando um templo?\n"
"Uma vez ouvi um pássaro misterioso \n"
"diga..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Vá, rapaz. Vá para o\n"
"Deusa do Deserto com uma ocarina." COLOR(DEFAULT) "\"\n"
"Você tem alguma ideia do que ele\n"
"pode ter querido dizer com isso?" EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Você já encontrou todos os templos?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Ótimo! Você está seguro!\n"
"Eu sabia que teria notícias\n"
"você novamente!" BOX_BREAK "Estou na " COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) "!\n"
"Os espíritos da floresta estavam chamando\n"
"para obter ajuda, então fui verificar\n"
"fora..." BOX_BREAK "Mas está cheio de monstros do mal!\n"
"Ajude-me, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME "...\n"
"No começo, eu não queria me tornar \n"
"a " COLOR(ADJUSTABLE) "Sábio da Floresta" COLOR(DEFAULT) "...." BOX_BREAK "Mas estou feliz agora." BOX_BREAK "Porque estou ajudando você a economizar\n"
"Hyrule, " NAME "!\n"
"Sim eu estou!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Se todos os seis " COLOR(RED) "Sages" COLOR(DEFAULT) " se juntarem, \n"
"podemos prender Ganondorf, o \n"
"Rei do Mal, no Reino Sagrado." BOX_BREAK "Mas, para fazer um perfeito\n"
"selo, precisamos do " COLOR(RED) "sétimo \n"
"Sage" COLOR(DEFAULT) "." BOX_BREAK "Alguém que você conhece deve ser isso\n"
"Sage, " NAME "..." BOX_BREAK "De agora em diante, você deve viajar \n"
"entre passado e futuro para\n"
"desperte os Sábios restantes!" BOX_BREAK "Continue com o bom trabalho,\n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Nós, os Seis Sábios, estamos canalizando\n"
"nosso poder para você!" BOX_BREAK "O destino de Hyrule depende \n"
"sobre você!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Posso ouvir uma voz de\n"
"em algum lugar..." COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE COLOR(LIGHTBLUE) "Está dizendo:\n"
COLOR(DEFAULT) SHIFT("\x11") "\"Colete cinco Rupees de prata...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta parede... está dizendo alguma coisa!" COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Diz:\n"
COLOR(DEFAULT) "Se você quiser ver uma balsa para o\n"
SHIFT("\x1E") "outro mundo, venha aqui..."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE COLOR(LIGHTBLUE) "Se você quiser andar naquele " COLOR(DEFAULT) "barco" COLOR(LIGHTBLUE) ", seja \n"
"cuidado! Parece muito antigo... Quem\n"
"sabe quando pode afundar?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há uma " COLOR(DEFAULT) "porta" COLOR(LIGHTBLUE) "aqui... É \n"
"há alguma maneira de atravessar?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Aquela " COLOR(DEFAULT) "gelo vermelho" COLOR(LIGHTBLUE) "...é tão estranho!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta " COLOR(DEFAULT) "fogo azul" COLOR(LIGHTBLUE) "...não parece\n"
"natural. Talvez você possa usá-lo para\n"
"alguma coisa?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "O " COLOR(DEFAULT) "dispara nas tochas " COLOR(LIGHTBLUE) "sumiram.\n"
"Parece que os fantasmas os levaram \n"
"longe!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Olha, " NAME "! A " COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) "\n"
"está aceso! Isso porque\n"
"você venceu um fantasma, não é?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há setas " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "pintadas no \n"
"andar!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este corredor " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "está todo torcido!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Cuidado com as sombras de " COLOR(DEFAULT)" de\n"
"monstros " COLOR(LIGHTBLUE) "que ficam pendurados no\n"
"teto." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Há uma " COLOR(DEFAULT) "baú do tesouro" COLOR(LIGHTBLUE) " aqui." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta...esta é a mesma " COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) " nós\n"
"viu na entrada do templo,\n"
"não é?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta" COLOR(DEFAULT) "tocha" COLOR(LIGHTBLUE) "está acesa... isso significa..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta opção " COLOR(DEFAULT)" COLOR(LIGHTBLUE) " está congelada!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) NAME ", cuidado!\n"
"O teto está caindo!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) NAME ", ouço " COLOR(DEFAULT) "Goron \n"
"vozes " COLOR(LIGHTBLUE) "abaixo." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você pode ver daqui...\n"
"Não é esse o quarto onde vimos\n"
COLOR(DEFAULT) "Darúnia" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Esta" COLOR(DEFAULT) "estátua" COLOR(LIGHTBLUE) "...não vimos isso\n"
"em algum lugar antes?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Este interruptor " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "parece enferrujado." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"01a"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) NAME "! Tenha cuidado!\n"
"Não seja engolido pelo \n"
"vórtices!" COLOR(DEFAULT)
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
SHIFT("\x0F") "Oi! Eu sou uma porta falante!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x06") COLOR(LIGHTBLUE) "Estranho... esta porta não abre..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x04") COLOR(LIGHTBLUE) "Forte " COLOR(DEFAULT) "barras de ferro " COLOR(LIGHTBLUE) "estão bloqueando o\n"
COLOR(DEFAULT) SHIFT("\x0B") COLOR(LIGHTBLUE) "porta. Você não pode abri-las com\n"
COLOR(DEFAULT) SHIFT("\x40") COLOR(LIGHTBLUE) "suas mãos!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x09") COLOR(LIGHTBLUE) "Você precisa de uma " COLOR(DEFAULT) "Key" COLOR(LIGHTBLUE) " para abrir uma porta\n"
COLOR(DEFAULT) SHIFT("\x14") COLOR(LIGHTBLUE) "que está bloqueado e encadeado." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x21") COLOR(LIGHTBLUE) "Você precisa de uma chave especial " COLOR(DEFAULT)"\n"
SHIFT("\x28") COLOR(LIGHTBLUE) "para abrir esta porta." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Fique quieto!" QUICKTEXT_DISABLE BOX_BREAK "É apenas " HORA "!\n"
"I, " COLOR(RED) "Dampé " COLOR(DEFAULT) "o coveiro, am\n"
"na cama agora!" BOX_BREAK "Vá embora e jogue! Talvez você possa\n"
"encontrar um fantasma durante o dia?"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"É " HORA " agora.\n"
"O " COLOR(RED) "Tour de covinha" COLOR(DEFAULT) " terminou \n"
"agora!" BOX_BREAK "Eu, " COLOR(RED) "Dampé" COLOR(DEFAULT) " o coveiro, am\n"
"na cama!" BOX_BREAK "Vá embora e jogue! Talvez você\n"
"encontre um fantasma!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Happy Mask Shop\n"
COLOR(DEFAULT) "Por favor, leia este sinal antes de\n"
"usar esta loja." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE COLOR(RED) "Como esta loja funciona\n"
COLOR(DEFAULT) "Não vendemos máscaras nesta loja.\n"
"Nós apenas " COLOR(RED) "emprestamos" COLOR(DEFAULT) " para você." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Você vende as máscaras emprestadas no seu\n"
"ter." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Você devolve o dinheiro " COLOR(RED)" COLOR(DEFAULT) " pelo\n"
"máscara, e nós lhe emprestaremos uma \n"
"modelo mais novo." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Você pode emprestar as máscaras que você tem\n"
"já foi vendido novamente; no entanto, você \n"
"pode vender apenas cada modelo de máscara\n"
"uma vez." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Experimente nossa loja!\n"
SHIFT("\x14") "--Happy Mask Shop Owner" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Templo das Sombras...\n"
"Aqui estão reunidos os \n sangrentos de Hyrule"
"história de ganância e ódio..." EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"O que está escondido na escuridão...\n"
"Truques cheios de má vontade...\n"
"Você não pode ver o caminho a seguir..." EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Aquele que ganha o olho da verdade " COLOR(RED) "\n"
COLOR(DEFAULT) "poderá ver o que está oculto\n"
"na escuridão." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Algo estranho está cobrindo o\n"
"entrada. Você deve resolver a\n"
COLOR(DEFAULT) "quebra-cabeça" COLOR(LIGHTBLUE) " nesta sala para fazer o\n"
"entrada aberta." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo gigante morto...\n"
"quando vê vermelho,\n"
"um novo caminho a percorrer \n"
"estará aberto." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x1E") COLOR(LIGHTBLUE) "Concurso do Baú do Tesouro\n"
COLOR(DEFAULT) SHIFT("\x2D") "Temporariamente Fechado\n"
SHIFT("\x38") "Aberto hoje à noite!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Loja de Medicamentos\n"
COLOR(DEFAULT) "Fechado até de manhã"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Galeria de fotos\n"
COLOR(DEFAULT) "Aberto apenas durante o dia"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Feliz Loja de Máscaras\n"
COLOR(DEFAULT) "Agora contratando meio período\n"
"Aplicar durante o dia"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Bazar\n"
COLOR(DEFAULT) "Aberto apenas durante o dia"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Mostre-me a luz!"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Um com o " COLOR(RED) "olho da verdade " COLOR(DEFAULT) "deverá\n"
"ser guiado ao Templo dos Espíritos por\n"
"um fantasma convidativo." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Aqueles que desejam abrir o caminho\n"
"dormindo no fundo do lago\n"
"deve tocar a música " COLOR(RED) "transmitida\n"
"pela Família Real" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Aqueles que desejam abrir o portão\n"
"nas alturas distantes, toque a música " COLOR(RED) "\n"
"transmitido pela Família Real" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Aqueles que encontrarem uma " COLOR(RED) "Small Key" COLOR(DEFAULT) " podem\n"
"avançar para a próxima sala. Aqueles\n"
"quem não pode ir para casa!"
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se quiser falar comigo,\n"
"faça-o a partir da plataforma." EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x68\x6D") QUICKTEXT_ENABLE "Olá, " NAME "!" QUICKTEXT_DISABLE "\n"
"Olhe para cá!" BOX_BREAK "Olhe aqui com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", e fale \n"
"para mim com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A hora atual é: " COLOR(RED) TIME COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Iluminar os mortos-vivos..."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Aqueles que invadem o Royal \n"
"O túmulo será obstruído pelo\n"
COLOR(RED) "espreita no escuro" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ei, você! Jovem, ali!\n"
"Olhe aqui, dentro da cela!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu garotinho não está aqui certo \n"
"agora...\n"
"Acho que ele foi jogar no \n"
"cemitério..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, meu filho está dormindo agora.\n"
"Por favor, volte outra hora\n"
"para brincar com ele!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Quando a água enche o lago, \n"
"atirar para a luz da manhã." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se você quiser viajar para o \n"
"futuro, você deve voltar aqui \n"
"com o poder " COLOR(BLUE)" da prata " COLOR(DEFAULT) "do \n"
"passado." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Se você quiser prosseguir para o \n"
"passado, você deve retornar aqui\n"
"com o coração puro de uma criança." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Esta porta está sendo\n"
"reformado". QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Parece algo usado para\n"
"ser colocado neste estande..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x20") "Faça meu bico ficar de frente para o\n"
SHIFT("\x3A") COLOR(RED) "caveira da verdade" COLOR(DEFAULT) "." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x0C") "A alternativa é descer para\n"
SHIFT("\x2D") "a escuridão profunda." EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "Esta não é a tecla " COLOR(DEFAULT) "correta" COLOR(LIGHTBLUE) "...\n"
"A porta não abre!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x27") COLOR(LIGHTBLUE) "Loja de Poções da Vovó\n"
COLOR(DEFAULT) SHIFT("\x4F") "Fechado" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x28") "Ido para estudo de campo\n"
SHIFT("\x28") "Por favor, volte!\n"
SHIFT("\x4A") "--Vovó" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Quem está aí? Que garoto mau,\n"
"tentando entrar por trás\n"
"porta!" QUICKTEXT_DISABLE BOX_BREAK TEXT_SPEED("\x02") "Que garoto malvado..." TEXT_SPEED("\x00") "\n"
"Tenho que te contar umas suculentas\n"
"fofoca!" BOX_BREAK "O chefe carpinteiro tem um filho...\n"
"Ele é o cara que fica embaixo do\n"
"árvore todas as noites..." BOX_BREAK "Não conte ao chefe que eu te disse \n"
"que!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Olha isso!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Malon foi dormir!\n"
"Eu também vou dormir agora.\n"
"Volte novamente quando for\n"
"luz apagada!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE COLOR(RED) NAME "'s Records!\n"
COLOR(DEFAULT) "Aranhas esmagadas: " TOKENS "\n"
"Maior peixe capturado: " HIGHSCORE(HS_LARGEST_FISH) " libras" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Tempo da maratona: " HIGHSCORE(HS_MARATHON) "\n"
"Tempo de corrida de cavalos: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Tiro com arco a cavalo: " HIGHSCORE(HS_HORSE_ARCHERY) " pontos" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x06") "O brasão da Família Real de\n"
SHIFT("\x1E") "Hyrule está inscrito aqui." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE SHIFT("\x54") "RIP\n"
SHIFT("\x08") "Aqui jazem as almas daqueles que\n"
SHIFT("\x2A") "jurou fidelidade ao\n"
SHIFT("\x23") "Família Real de Hyrule" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x0F") "O Sheikah, guardiões do\n"
SHIFT("\x11") "Família Real e fundadores de\n"
SHIFT("\x02") "Kakariko, cuide desses espíritos\n"
SHIFT("\x1E") "em seu sono eterno." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE SHIFT("\x28") COLOR(BLUE) "Cachoeira sem dormir\n"
COLOR(DEFAULT) SHIFT("\x05") "O fluxo desta cascata serve\n"
SHIFT("\x02") "o Rei de Hyrule. Quando o Rei\n"
SHIFT("\x09") "adormece, assim como essas quedas." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Alguns sapos estão olhando para você\n"
"de debaixo d'água..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você está em um tapete macio\n"
"para convidados...\n"
"É tão macio sob seus pés!"
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se você conseguir superar as provas " COLOR(RED) "" COLOR(DEFAULT) "em\n"
"as câmaras à frente, então e somente\n"
"então você estará qualificado para manter\n"
"nosso tesouro secreto!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Se você deseja adquirir nosso\n"
"tesouro escondido, você deve se esforçar\n"
"para obter as chaves " COLOR(RED)" " COLOR(DEFAULT) "escondidas em cada\n"
"câmara!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Derrote todos os inimigos em um " COLOR(RED) "limitado\n"
"tempo" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Colecione as gemas subaquáticas " COLOR(RED)" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Atravesse o mar de fogo!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Encontre uma passagem secreta neste\n"
"sala!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Cego os olhos" COLOR(RED) "da estátua" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Um com " COLOR(RED) "mãos prateadas" COLOR(DEFAULT) " deve se mover\n"
"um bloco gigante!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Sem os itens necessários, um\n"
"será confundido pelo impossível\n"
"mistérios".
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Reúna as joias de " COLOR(RED)" de branco" COLOR(DEFAULT) ", enquanto\n"
"evitando armadilhas e perigo!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3F") COLOR(LIGHTBLUE) "Lagoa de Pesca" COLOR(DEFAULT) "\n"
SHIFT("\x07") "Os peixes estão realmente mordendo hoje!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4E") COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x05") "A sombra renderá apenas um\n"
SHIFT("\x0E") "com o " COLOR(RED) "olho da verdade" COLOR(DEFAULT) ", entregue\n"
SHIFT("\x1C") "na Vila Kakariko." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
FUNDO("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x41") COLOR(LIGHTBLUE) "Campo Hyrule" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2C") COLOR(LIGHTBLUE) "Hyrule Castle Town" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2D") COLOR(LIGHTBLUE) "O Templo do Tempo" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x47") COLOR(RED) "Beco sem saída" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x37") COLOR(RED) "Vila Kakariko\n"
COLOR(DEFAULT) SHIFT("\x28") "Trilha da Montanha da Morte\n"
SHIFT("\x3C") "Ponto inicial" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x17") COLOR(RED) "Cemitério Vila Kakariko" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x23") "Escuro! Estreito! Assustador!\n"
COLOR(PURPLE) SHIFT("\x1E") "Poço de três recursos" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x36") COLOR(RED) "Monte da Morte\n"
COLOR(DEFAULT) SHIFT("\x25") "Nenhuma passagem sem um\n"
SHIFT("\x3A") "Decreto Real!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x28") COLOR(RED) "Trilha da Montanha da Morte" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x36") COLOR(YELLOW) "Caverna do Dodongo\n"
COLOR(DEFAULT) SHIFT("\x0A") "Não entre sem permissão!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x28") "Terra dos Gorons\n"
SHIFT("\x41") COLOR(RED) "Goron City" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x48") COLOR(BLUE) "Rio de Zora\n"
COLOR(DEFAULT) SHIFT("\x0F") "Cuidado com a corrente rápida \n"
SHIFT("\x23") "e forte ressaca." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x05") "A sombra renderá apenas um\n"
SHIFT("\x0E") "com o olho da verdade, entregue\n"
SHIFT("\x1C") "na Vila Kakariko." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x37") COLOR(BLUE) "Domínio de Zora" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x37") COLOR(BLUE) "Fonte de Zora\n"
COLOR(DEFAULT) SHIFT("\x08") "Não perturbe Lord Jabu-Jabu! \n"
SHIFT("\x32") "--Rei Zora XVI" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x23") COLOR(PURPLE) "Centro de Treinamento Florestal\n"
COLOR(DEFAULT) SHIFT("\x15") "Não corte sinais de forma imprudente--\n"
SHIFT("\x28") "leia com atenção!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x12") "Todos aqueles imprudentes o suficiente para\n"
SHIFT("\x0B") "aventure-se no deserto--por favor\n"
SHIFT("\x2F") "passe em nossa loja." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x33") COLOR(YELLOW) "Carpet Merchant" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x41") "À frente:\n"
SHIFT("\x17") COLOR(AJUSTABLE) "Grande Deku Tree's Meadow" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x39") COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x35") COLOR(ADJUSTABLE) "O Bosque Perdido" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2E") "Talon e Malon's\n"
SHIFT("\x3C") COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x33") "O Grande Ingo\n"
SHIFT("\x46") COLOR(YELLOW) "Ingo Ranch" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x41") COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1E") COLOR(BLUE) "Lagoside Laboratory\n"
COLOR(DEFAULT) SHIFT("\x04") "Diariamente tentando chegar ao final\n"
SHIFT("\x09") "dos mistérios do Lago Hylia!\n"
SHIFT("\x36") "--Lake Scientist" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x37") COLOR(YELLOW) "Vale Gerudo" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x19") COLOR(YELLOW) "Cavalo Archery Range" COLOR(DEFAULT) "\n"
SHIFT("\x12") "Jogadores habilidosos são bem-vindos!\n"
SHIFT("\x12") "Registro atual: " COLOR(RED) HIGHSCORE(HS_HORSE_ARCHERY) COLOR(DEFAULT) " Pontos" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x21") COLOR(YELLOW) "Campo de Treinamento Gerudo\n"
COLOR(DEFAULT) SHIFT("\x11") "Apenas membros registrados são\n"
SHIFT("\x4B") "permitido!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2D") COLOR(YELLOW) "Terra Assombrada" COLOR(DEFAULT) "\n"
SHIFT("\x17") "Se você perseguir uma miragem, o\n"
SHIFT("\x1F") "o deserto vai engolir você.\n"
SHIFT("\x21") "Apenas um caminho é verdadeiro!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3C") COLOR(YELLOW) "Templo do Espírito" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x42") COLOR(ADJUSTABLE) "Loja Kokiri\n"
COLOR(DEFAULT) SHIFT("\x0B") "Temos produtos florestais originais!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1E") NAME "casa de" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x28") COLOR(ADJUSTABLE) "O povo da floresta não deve\n"
COLOR(DEFAULT) SHIFT("\x2D") COLOR(ADJUSTABLE) "deixe estas madeiras." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x03") "Seguir a trilha ao longo da borda de\n"
SHIFT("\x15") "o penhasco e você chegará\n"
SHIFT("\x06") COLOR(RED) "Goron City" COLOR(DEFAULT) ", lar dos Gorons." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x36") "Maravilha Natural\n"
SHIFT("\x3F") COLOR(RED) "Flor Bomba" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Perigo! Não desenraize!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x26") COLOR(RED) "Cúpula da Montanha da Morte\n"
COLOR(DEFAULT) SHIFT("\x10") "Entrada para a cratera à frente\n"
SHIFT("\x1E") "Cuidado com o calor intenso!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1D") COLOR(BLUE) "Sala do Trono do Rei Zora\n"
COLOR(DEFAULT) SHIFT("\x1E") "Para ouvir a realeza do Rei\n"
SHIFT("\x15") "proclamações, fique na\n"
SHIFT("\x17") "plataforma e fale com ele." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0A") "Se você puder parar minha rolagem selvagem,\n"
SHIFT("\x0B") "você pode obter algo ótimo.\n"
SHIFT("\x29") "--" COLOR(RED) "Hot Rodder Goron" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0A") "Apenas um com o olho da verdade\n"
SHIFT("\x15") "encontrará o guarda-chuva de pedra\n"
SHIFT("\x1A") "que protege contra o\n"
SHIFT("\x39") "chuva de lâminas." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0A") "Somente aquele que tem " COLOR(RED) "pés sagrados" COLOR(DEFAULT) "\n"
SHIFT("\x04") "pode cruzar o vale dos mortos." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O tempo de gravação desses\n"
"quem correu contra mim foi:\n"
COLOR(LIGHTBLUE) HIGHSCORE(HS_DAMPE_RACE) COLOR(DEFAULT) "\n"
"--Dampé the Gravekeeper" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Galeria de fotos \n"
"20 rúpias por uma peça\n"
COLOR(DEFAULT) "Existem " COLOR(RED) "10 alvos" COLOR(DEFAULT) ". Você tem " COLOR(RED) "15\n"
"chances" COLOR(DEFAULT) ". Acerte todos os 10 alvos!" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Acerte 10 alvos -- Prêmio Perfeito\n"
"Acerte 8 ou mais -- Tentativa Gratuita\n"
"Acertar menos de 8 -- Fim de jogo" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Regras nesta Galeria de Tiros\n"
COLOR(DEFAULT) "Não se apoie no balcão.\n"
"Não perturbe outros clientes." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x28") COLOR(LIGHTBLUE) "Loja do Baú do Tesouro" COLOR(DEFAULT) "\n"
SHIFT("\x06") "Nós não necessariamente os vendemos..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1F") COLOR(LIGHTBLUE) "Local de prática de mergulho alto\n"
COLOR(DEFAULT) SHIFT("\x2F") "Você está confiante\n"
SHIFT("\x2A") "em sua habilidade de mergulho?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x33") COLOR(RED) "Mountain Summit" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Perigo à frente - Mantenha-se afastado" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2E") COLOR(LIGHTBLUE) "Happy Mask Shop!" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Agora contratando felicidade\n"
SHIFT("\x3C") "entregadores!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x23") COLOR(LIGHTBLUE) "Bombchu Bowling Alley" COLOR(DEFAULT) "\n"
SHIFT("\x20") "Você pode experimentar o\n"
SHIFT("\x17") "mais recente em tecnologia Bomb!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x50") COLOR(LIGHTBLUE) "Bazaar" COLOR(DEFAULT) "\n"
SHIFT("\x0A") "Temos um pouco de tudo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x41") COLOR(LIGHTBLUE) "Loja de Poções\n"
COLOR(DEFAULT) SHIFT("\x1B") "Temos a melhor qualidade\n"
SHIFT("\x4A") "poções!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x41") COLOR(RED) "Goron Shop\n"
COLOR(DEFAULT) SHIFT("\x1E") "Suprimentos de montanhismo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x45") COLOR(BLUE) "Zora Shop" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Temos peixe fresco!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x03") COLOR(LIGHTBLUE) "Tour de escavação emocionante!\n"
COLOR(DEFAULT) SHIFT("\x08") "Das 18:00 às 21:00 Horário Hyrule\n"
SHIFT("\x1C") "--Dampé the Gravekeeper" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x03") COLOR(LIGHTBLUE) "Tour de escavação emocionante!\n"
COLOR(DEFAULT) SHIFT("\x0A") "Os passeios são " COLOR(RED) "cancelados" COLOR(DEFAULT) " até um novo\n"
SHIFT("\x1B") "o coveiro foi encontrado. Nós\n"
SHIFT("\x09") "peça desculpas por qualquer inconveniente." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(RED) "Sinais de ataque de propulsão!\n"
COLOR(DEFAULT) "Para empurrar com sua espada, pressione\n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " em direção ao seu alvo enquanto \n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", depois pressione " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(RED) "Buraco de \"Z\"\n"
COLOR(DEFAULT) "Vamos passar por este pequeno\n"
"buraco!" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Fique na frente do buraco e\n"
"empurre " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "para ele. Quando o \n"
COLOR(BLUE) "Ícone de ação " COLOR(DEFAULT) "mostra \"Enter\", pressione\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "para rastejar para dentro do buraco." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Preste atenção na ação " COLOR(BLUE) "\n"
"Ícone " COLOR(DEFAULT) "diz!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(RED) "Cortar grama com sua espada\n"
COLOR(DEFAULT) "Se você apenas balançar com " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", você \n"
"cortar horizontalmente. Se você segurar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " como" COLOR(LIGHTBLUE) " \n"
COLOR(DEFAULT) "você balança, corta verticalmente." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3C") COLOR(LIGHTBLUE) "Hyrule Castle" COLOR(DEFAULT) "\n"
SHIFT("\x37") COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x13") "Você está aqui: " COLOR(LIGHTBLUE) "Hyrule Castle" COLOR(DEFAULT) "\n"
SHIFT("\x16") "Desta forma para " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x42") "Apenas adiante\n"
SHIFT("\x29") COLOR(BLUE) "Câmara do Rei Zora\n"
COLOR(DEFAULT) SHIFT("\x19") "Mostre o devido respeito!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x19") "Casa do Grande " COLOR(RED) "Mido" COLOR(DEFAULT) "\n"
SHIFT("\x2D") "Chefe do Kokiri" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x04") "Casa dos Irmãos Sabe-Tudo" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x37") "Casa dos Gêmeos" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3D") COLOR(RED) "Saria" COLOR(DEFAULT) "'s House" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(PURPLE) "Ponto de visualização com segmentação [Z]\n"
COLOR(DEFAULT) "Quando você não tem nenhum objeto para olhar\n"
"at, você pode apenas olhar para frente\n"
"com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Pare de se mover e altere o\n"
"direção que você está enfrentando, ou " COLOR(LIGHTBLUE) "hold\n"
"abaixo [Z] " COLOR(DEFAULT) "por um tempo." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Isso pode ajudar você a se orientar\n"
"a direção que você quer enfrentar.\n"
"É bastante conveniente!" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Se " COLOR(LIGHTBLUE) "você mantiver pressionado [Z]" COLOR(DEFAULT) ", você pode\n"
COLOR(RED) "andar de lado" COLOR(DEFAULT) " de frente para \n"
"direto em frente." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE COLOR(RED) "Andar de lado" COLOR(DEFAULT) " pode ser muito\n"
"técnica importante na masmorra\n"
"corredores. Vire-se e tente\n"
"fazendo isso agora." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(RED) "Stepping Stones in the Pond\n"
COLOR(DEFAULT) "Se você for corajosamente na direção\n"
"você quer pular, você vai pular\n"
"automaticamente". QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Se você pular nas pedras,\n"
"você vai se tornar mais feliz!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2F") COLOR(RED) "Nenhum mergulho permitido\n"
COLOR(DEFAULT) SHIFT("\x15") "--Não vai adiantar nada!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(PURPLE) "Alternar segmentação\n"
COLOR(DEFAULT) "Se você vir um ícone " COLOR(ADJUSTABLE) " ▼ " COLOR(DEFAULT) " acima de um \n"
"objeto, você pode segmentá-lo com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Em outras palavras, se você pressionar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"quando você vê " COLOR(ADJUSTABLE) " ▼ " COLOR(YELLOW) " " COLOR(DEFAULT) "acima de um objeto,\n"
"você pode segurá-lo." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Se você pressionar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " novamente, o bloqueio\n"
"vai " COLOR(RED) "liberar" COLOR(DEFAULT) " ou vai\n"
"transferir para o próximo objeto com\n"
"a " COLOR(ADJUSTABLE) " ▼ " COLOR(DEFAULT) " acima dela." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Quando você tem muitos inimigos\n"
"seu campo de visão e você quer\n"
"para escapar, pressione " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "enquanto segura\n"
"voltar em " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para cancelar a segmentação." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Você pode segmentar as pedras " COLOR(RED)" COLOR(DEFAULT) " ao lado de\n"
"este sinal para a prática!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3D") COLOR(ADJUSTABLE) "Estágio da Floresta" COLOR(DEFAULT) QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x14") "Estamos esperando para ver seu\n"
SHIFT("\x38") "rosto lindo!\n"
SHIFT("\x28") "Ganhe prêmios fabulosos!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x48") "Visite o\n"
SHIFT("\x04") COLOR(RED) "Casa dos Irmãos Sabe-Tudo\n"
COLOR(DEFAULT) SHIFT("\x17") "para obter respostas para todos os seus\n"
SHIFT("\x22") "perguntas relacionadas ao item!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Esta é uma " COLOR(RED) "Pedra de Fofocas" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que você pode nadar mais rápido\n"
"pressionando continuamente " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que existe um segredo \n"
"perto da árvore solitária que não está\n"
"longe do rio no \n"
"parte noroeste de Hyrule Field."
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo\n"
"na estrada que leva ao Lago\n"
"Hília."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a Espada de Biggoron é \n"
"super afiada e nunca vai quebrar."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Medigoron não \n"
"realmente pensa no próprio tamanho dele, \n"
"então a loja dele é muito apertada."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Malon definiu o\n"
"registro original no obstáculo\n"
"curso de Lon Lon Ranch."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Malon de Lon Lon \n"
"Ranch espera um cavaleiro brilhante \n"
"armadura virá e varrerá ela \n"
"os pés dela algum dia."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Ruto, a Zora \n"
"Princesa que é conhecida por ela \n"
"natureza egoísta, gosta de um certo \n"
"Garoto..."
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os jogadores que selecionam\n"
"a opção \"HOLD\" para \"Z \n"
"TARGETING\" são as verdadeiras \"Zelda\n"
"jogadoras!\""
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que há um segredo\n"
"perto de uma árvore na Vila Kakariko."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem isso, ao contrário dela \n"
"imagem elegante, princesa Zelda de \n"
"Hyrule Castle é, na verdade, um \n"
"moleque!"
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a princesa Zelda \n"
"babá é na verdade uma das \n"
"Sheikah, que muitos achavam que tinha \n"
"morreu."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que existe um homem que\n"
"pode sempre ser encontrado em execução\n"
"em torno de Hyrule Field."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que é contra a\n"
"regras para usar óculos no \n"
"Loja do Baú do Tesouro em Hyrule\n"
"Mercado da Cidade do Castelo."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a Mulher Galinha \n"
"vai para o Laboratório Lakeside \n"
"para estudar como criar bolso-\n"
"Cucos de tamanho médio."
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Gerudos às vezes\n"
"venha para Hyrule Castle Town para\n"
"procure namorados."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que o ladrão chamado \n"
"Nabooru, que assombra esta área, é\n"
"um Gerudo."
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que se você chegar perto de um\n"
"borboleta enquanto segura um Deku\n"
"Fique em suas mãos, algo\n"
"o bem vai acontecer."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Eles dizem que você pode encontrar\n"
"algo novo nas masmorras que\n"
"você já terminou."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Gerudos adora \n"
"Ganondorf quase como um deus."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que existe um segredo \n"
"em volta da entrada de Gerudo \n"
"Vale."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que a coruja se chama\n"
"Kaepora Gaebora é a\n"
"reencarnação de um antigo sábio."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem aquela coruja estranha,\n"
"Kaepora Gaebora, pode parecer grande e\n"
"pesado, mas seu caráter é bastante \n"
"leve".
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que o cavalo\n"
"As corridas de Ganondorf são pretas sólidas\n"
"Gerudo garanhão."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que Ganondorf não é \n"
"satisfeito em governar apenas o\n"
"Gerudo e visa conquistar todos\n"
"de Hyrule!"
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que o tesouro que você\n"
"pode ganhar no Treinamento do Gerudo\n"
"O solo não é tão bom quanto você\n"
"esperaria, dada a sua dificuldade!"
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que existe um interruptor \n"
"que você pode ativar apenas por\n"
"usando o Spin Attack."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que é possível encontrar\n"
"um total de 100 Caveiras de Ouro\n"
"em toda Hyrule."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Eles dizem isso quando não são fada\n"
"as pessoas entram no Bosque Perdido, elas\n"
"tornam-se monstros!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os pequenos buracos em\n"
"o chão que você pode encontrar todos\n"
"sobre Hyrule faz a criação perfeita\n"
"terreno para insetos."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que os Kokiri são \n"
"sempre seguido por pequenas fadas."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Dizem que um Kokiri deixou\n"
"a floresta, mas ele ainda está\n"
"vivo!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(RED) "O que é isso?" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "É um dos monstros parasitas\n"
"dentro da Árvore Deku! Seu " COLOR(DEFAULT) "olho" COLOR(LIGHTBLUE) " é\n"
"vulnerável quando está vermelho!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ovo Gohma\n"
COLOR(LIGHTBLUE) "Quando este ovo chocar, um Gohma\n"
"A larva vai nascer." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larva Gohma\n"
COLOR(LIGHTBLUE) "Cuidado quando estiver pronto para\n"
"ataque!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Crânula\n"
COLOR(LIGHTBLUE) "É suave" COLOR(DEFAULT) "barriga" COLOR(LIGHTBLUE) "é seu ponto fraco!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grande Skulltula\n"
COLOR(LIGHTBLUE) "É suave" COLOR(DEFAULT) "barriga" COLOR(LIGHTBLUE) "é seu ponto fraco!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tailpasaran\n"
COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT)" cauda " COLOR(LIGHTBLUE) "é seu ponto fraco!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Acerte quando ele atacar você e \n"
"ficará de pé. Corte-o\n"
"rapidamente para obter um " COLOR(DEFAULT) "Deku Stick" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Big Deku Baba\n"
COLOR(LIGHTBLUE) "Acerte quando ele atacar você e \n"
"ficará de pé. Corte-o\n"
"rapidamente para obter um " COLOR(DEFAULT) "Deku Stick" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Embora pareça murcho, vai\n"
"ferir você se você tocá-lo!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Scrub\n"
COLOR(LIGHTBLUE) "Ele vai se esconder na grama se você conseguir\n"
"perto dele. Jogue as nozes nele \n"
"cospe de volta para ele!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Rei Dodongo\n"
COLOR(LIGHTBLUE) "Este é um Dodongo enorme que come\n"
"qualquer coisa! Dê um choque e \n"
"termine com sua " COLOR(DEFAULT) "sword" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Cuidado com o hálito de fogo!\n"
"Use " COLOR(DEFAULT) "[Z] Direcionamento " COLOR(LIGHTBLUE) "técnicas!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bebê Dodongo\n"
COLOR(LIGHTBLUE) "Cuidado com o ataque saltitante!\n"
"Ele vai explodir depois de ser derrotado!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos \n"
COLOR(LIGHTBLUE) "Use bem seu escudo e lute \n"
"com " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "técnicas!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos \n"
COLOR(LIGHTBLUE) "Use bem seu escudo e lute \n"
"com " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "técnicas!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Disparar Keese\n"
COLOR(LIGHTBLUE) "Destrua-o antes que ele voe para dentro\n"
"você! Se você não fizer isso, suas chamas irão\n"
"queime seu " COLOR(DEFAULT) "Deku Shield" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese\n"
COLOR(LIGHTBLUE) "Quando chegar perto, use \n"
COLOR(DEFAULT) "[Z] Segmentação" COLOR(LIGHTBLUE) ". Mesmo que voe\n"
"longe, você ainda pode segmentá-lo." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armas\n"
COLOR(LIGHTBLUE) "Parar o movimento e então\n"
"destrua-o!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinada\n"
COLOR(LIGHTBLUE) "Muitos enxames de medusas parasitas\n"
"em torno deste monstro. Mire nele\n"
"corpo, protegido por água-viva!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tentáculo Parasita?\n"
COLOR(LIGHTBLUE) "Parece que a parte estreita é \n"
"seu ponto fraco... Você precisa de um \n"
"item específico para destruí-lo!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shabom\n"
COLOR(LIGHTBLUE) "Se você tentar cortar, vai saltar\n"
"fora de sua lâmina!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "Se você tocá-lo, você será\n"
"eletrocutado!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "Se você tocá-lo, você será \n"
"eletrocutado!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ferrão\n"
COLOR(LIGHTBLUE) "Destrua-o antes que ele voe para você!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon Fantasma\n"
COLOR(LIGHTBLUE) "É um fantasma maligno da Floresta\n"
"Templo! Ele sai de um dos\n"
"as fotos". BOX_BREAK COLOR(LIGHTBLUE) "Responda ao ataque mágico dele com um\n"
"ataque de sua preferência!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Atraia-o para perto de você e observe-o\n"
"mova-se com cuidado! Ataque-o quando \n"
"ele baixa a guarda!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha azul\n"
COLOR(LIGHTBLUE) "Proteja-se contra sua chama azul com \n"
"seu " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha branca\n"
COLOR(LIGHTBLUE) "Apontar para ele quando ele parar!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha verde\n"
COLOR(LIGHTBLUE) "Use sua espada quando estiver verde\n"
"fogo desaparece!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skullwalltula\n"
COLOR(LIGHTBLUE) "Cuidado para não tocá-lo!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gold Skulltula\n"
COLOR(LIGHTBLUE) "Isso também é conhecido como Aranha de\n"
"a Maldição. Se você a derrotar, você\n"
"obter um " COLOR(DEFAULT) "token" COLOR(LIGHTBLUE) " como prova!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volvagia\n"
COLOR(LIGHTBLUE) "É o Chefe do Templo do Fogo,\n"
"revivido pelo Rei Maligno. Eu não\n"
"conheça seu ponto fraco..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dançarina do Flare\n"
COLOR(LIGHTBLUE) "Apague sua " COLOR(DEFAULT) "roupas flamejantes \n"
COLOR(LIGHTBLUE) "primeiro..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Slug da tocha\n"
COLOR(LIGHTBLUE) "Quando o fogo nas costas é\n"
"extinto, ele fugirá.\n"
"Destrua antes que reacenda!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bolha vermelha\n"
COLOR(LIGHTBLUE) "Proteja-se contra seu ataque com \n"
"seu " COLOR(DEFAULT) "escudo" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morfa\n"
COLOR(LIGHTBLUE) "Mestre do Templo da Água. É \n"
"tem controle absoluto da água. Puxe\n"
"fora seu " COLOR(DEFAULT) "núcleo " COLOR(LIGHTBLUE) "e ataque-o!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Escuro " NAME "\n"
COLOR(LIGHTBLUE) "Conquiste a si mesmo!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lâmina de Shell\n"
COLOR(LIGHTBLUE) "É" COLOR(DEFAULT) "músculo interno" COLOR(LIGHTBLUE) "é seu" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "ponto fraco!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spike\n"
COLOR(LIGHTBLUE) "Mire nele quando ele retrair\n"
"espigões!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Chefe do Templo das Sombras, \n"
"revivido do poço. Olhe para ele\n"
"com o " COLOR(DEFAULT) "olho da verdade" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "ReDead\n"
COLOR(LIGHTBLUE) "Seu olhar vai te paralisar. Se ele\n"
"morde você," COLOR(DEFAULT) "toque em qualquer botão" COLOR(LIGHTBLUE) " para \n"
"escapar!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Ganon Fantasma\n"
COLOR(LIGHTBLUE) "Ataque-o" COLOR(RED) " " COLOR(DEFAULT) "quando ele sair de\n"
"uma das fotos" COLOR(LIGHTBLUE) "!\n"
"Cuidado com o falso!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Seu olhar vai te paralisar. Se ele\n"
"morde você," COLOR(DEFAULT) "toque em qualquer botão" COLOR(LIGHTBLUE) " para\n"
"escapar!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mãos da Mão Morta\n"
COLOR(LIGHTBLUE) "Se pegar você, " COLOR(DEFAULT) "toque em qualquer botão \n"
COLOR(LIGHTBLUE) "para escapar!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mão morta\n"
COLOR(LIGHTBLUE) "Cuidado com as mãos infinitas dele!\n"
"Mire na cabeça dele!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mestre de parede\n"
COLOR(LIGHTBLUE) "Cuidado com a " COLOR(DEFAULT) "sombra" COLOR(LIGHTBLUE) " no\n"
"piso. Destrua-o antes que acabe\n"
"de volta ao teto!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Floormaster\n"
COLOR(LIGHTBLUE) "Quando se dividir, destrua todos os\n"
"peças antes de se reunirem!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Koume\n"
COLOR(LIGHTBLUE) "Mãe substituta de Ganondorf.\n"
"Feiticeira das Chamas. Ela parece\n"
"vulnerável a " COLOR(DEFAULT) "baixa temperatura" COLOR(LIGHTBLUE) "." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Kotake\n"
COLOR(LIGHTBLUE) "Mãe substituta de Ganondorf.\n"
"Feiticeira do Gelo. Ela parece\n"
"vulnerável a " COLOR(DEFAULT) "alta temperatura" COLOR(LIGHTBLUE) "." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Junta de Ferro\n"
COLOR(LIGHTBLUE) "Algo está estranho...\n"
"Este não é um inimigo comum!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Junta de Ferro\n"
COLOR(LIGHTBLUE) "Cuidado com o ataque do machado! \n"
"Dói muito! Golpeie quando\n"
"baixa a guarda!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Menino Caveira\n"
COLOR(LIGHTBLUE) "É isso que acontece com as crianças que\n"
"vaguear na floresta? Parece\n"
"como se ele não gostasse de adultos." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Curtir Curtir\n"
COLOR(LIGHTBLUE) "Um inimigo que come " COLOR(DEFAULT)" protege " COLOR(LIGHTBLUE) "e\n"
"certain " COLOR(DEFAULT) "roupas" COLOR(LIGHTBLUE) ". Vença rapidamente\n"
"para pegar seu equipamento de volta!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beamos\n"
COLOR(LIGHTBLUE) "Cuidado com o feixe de busca!\n"
"Aposto que não gosta de " COLOR(DEFAULT) "smoke" COLOR(LIGHTBLUE) " para\n"
"entra no olho dele!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anúbis\n"
COLOR(LIGHTBLUE) "É vulnerável a " COLOR(RED) "fire" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Congelar\n"
COLOR(LIGHTBLUE) "Cuidado com o congelamento\n"
"respiração! Destrua-o completamente\n"
"antes de reviver." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf, o Rei Maligno\n"
COLOR(LIGHTBLUE) "Não faço ideia do que ele é fraco\n"
"o ponto é!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "Eu realmente não tenho ideia do que é dele\n"
"ponto fraco é!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Menino Caveira\n"
COLOR(LIGHTBLUE) "É isso que acontece com as crianças que\n"
"se perder na floresta? Ele pode\n"
"seja nosso amigo se fizermos algo..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Menino Caveira\n"
COLOR(LIGHTBLUE) "É isso que acontece com as crianças que\n"
"se perder nessa floresta? Ele parece\n"
"infeliz por não ter rosto..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Menino Caveira\n"
COLOR(LIGHTBLUE) "É isso que acontece com as crianças que\n"
"se perder nessa floresta? Ele parece\n"
"satisfeito com sua cara de caveira." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Rebatem as pedras que eles cospem\n"
"em você!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe do cemitério?\n"
COLOR(LIGHTBLUE) "Se você olhar para ele com " COLOR(DEFAULT) "[Z] \n"
"Targeting" COLOR(LIGHTBLUE) ", irá desaparecer..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poes\n"
COLOR(LIGHTBLUE) "Se você olhar para ele com " COLOR(DEFAULT) "[Z] \n"
"Targeting" COLOR(LIGHTBLUE) ", irá desaparecer..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Teclado Vermelho\n"
COLOR(LIGHTBLUE) "Bloqueie nele enquanto ele pula com " COLOR(DEFAULT) "[Z]\n"
"Segmentação" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tektite Azul\n"
COLOR(LIGHTBLUE) "É difícil vencer na água.\n"
"Atraia-o para a terra!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Observe seus movimentos de perto e\n"
"deixe passar!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "Seu ponto fraco é sua " COLOR(DEFAULT) "roots" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Larva Peahat\n"
COLOR(LIGHTBLUE) "Defenda com seu escudo" COLOR(DEFAULT)" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobos\n"
COLOR(LIGHTBLUE) "Desenhe perto de você e assista \n"
"seu movimento com cuidado! Ataque-o \n"
"quando ele baixa a guarda!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Esfoliação louca\n"
COLOR(LIGHTBLUE) "Se você chegar perto dele, ele vai esconder \n"
"na grama..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Depuração de negócios\n"
COLOR(LIGHTBLUE) "Se você chegar perto dele, ele vai esconder \n"
"na grama..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fantasma de Dampé\n"
COLOR(LIGHTBLUE) "Esse é o fantasma dos mortos\n"
"gravekeeper! Se você persegui-lo,\n"
"ele pode te dar sua " COLOR(DEFAULT) "lembrança" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg - uma das irmãs Poe\n"
COLOR(LIGHTBLUE) "Se ela dividir em várias imagens,\n"
"você precisa descobrir qual \n"
"é o " COLOR(DEFAULT) "real" COLOR(LIGHTBLUE) ". É este?" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle - uma das irmãs Poe\n"
COLOR(LIGHTBLUE) "Mire nela quando ela aparecer!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beth - uma das irmãs Poe\n"
COLOR(LIGHTBLUE) "Mire nela quando ela aparecer!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy - uma das irmãs Poe\n"
COLOR(LIGHTBLUE) "Mire nela quando ela aparecer!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gerudo Ladrão\n"
COLOR(LIGHTBLUE) "Quando ela baixa a guarda,\n"
"ataque! Se você não a derrotar,\n"
"você será capturado!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Filhote\n"
COLOR(LIGHTBLUE) "Não tenha medo do Stalchild!\n"
"Apenas ataque-o repetidamente!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ice Keese\n"
COLOR(LIGHTBLUE) "Destrua-o antes que ele voe para dentro\n"
"tu!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lobos Brancos\n"
COLOR(LIGHTBLUE) "Atraia-o para perto de você e assista \n"
"seu movimento com cuidado! Ataque-o \n"
"quando ele baixa a guarda!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guay\n"
COLOR(LIGHTBLUE) "Destrua-o antes que ele voe para dentro\n"
"tu!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bigocto\n"
COLOR(LIGHTBLUE) "Ataque por trás!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Grande Poema\n"
COLOR(LIGHTBLUE) "Este Poe não vai desaparecer mesmo\n"
"se você olhar para ele. Ele se move\n"
"rápido apesar do tamanho!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova\n"
COLOR(LIGHTBLUE) "Esta é a forma combinada de\n"
"Kotake e Koume. Vire seus\n"
COLOR(DEFAULT) "ataque mágico" COLOR(LIGHTBLUE) "de volta para eles!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poes\n"
COLOR(LIGHTBLUE) "Este Poe não desaparece mesmo que\n"
"você fica olhando. Não assusta\n"
"facilmente, faz..." COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3C") "Jogar usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." COLOR(YELLOW) "\n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Jogar usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "Parar.\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x086F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
"\n"
"\n"
OCARINA
)

DEFINE_MESSAGE(0x0870, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x16") "Toque o " COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) "!" COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT) QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1F") "Toca o " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x11") "Toque a " COLOR(BLUE) "Serenade of Water" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x15") "Toque o " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0D") "Toque a " COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x19") "Toque o " COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0B") "Siga junto com " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x20") "OK? Esta é " COLOR(RED) "a Música" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x27") "Memorize " COLOR(BLUE) "esta música" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mantenha a " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) "em seu coração.\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Esta música" COLOR(DEFAULT) " abre a Porta do Tempo...\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x17") "Nunca esquecerei " COLOR(PURPLE) "esta música" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Jogar usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "Parar.\n"
"\n"
"\n"
QUICKTEXT_DISABLE OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
FUNDO("\x00", "\x20", "\x00") PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x23") COLOR(RED) "Você não pode deformar aqui!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(ADJUSTABLE) "Warp to the Bosque Perdido?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Transportar para a Montanha da Morte \n"
"Cratera?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(BLUE) "Transportar para o Lago Hylia?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(YELLOW) "Transportar para o Colosso do Deserto?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(PURPLE) "Transportar para o cemitério?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Warp to the Temple of Time?" COLOR(DEFAULT) QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x05") "Você jogou o " COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0E") "Você jogou o " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Você tocou a " COLOR(BLUE) "Serenade of Water" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x04") "Você tocou o " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x09") "Jogou o " COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x08") "Você tocou o " COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1E") "Você tocou " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x1C") "Você tocou " COLOR(RED) "Epona's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x18") "Você tocou " COLOR(BLUE) "Zelda's Lullaby" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x16") "Você tocou a " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x10") "Você tocou a " COLOR(LIGHTBLUE) "Song of Time" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x09") "Você tocou a " COLOR(PURPLE) "Song of Storms" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x04") "Você tocou a " COLOR(YELLOW) "Scarecrow's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Você finalmente acordou!\n"
"Eu sou " COLOR(RED) "Navi " COLOR(LIGHTBLUE) "a fada!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "A Grande Árvore Deku perguntou\n"
"eu para ser seu parceiro " COLOR(RED) "COLOR(LIGHTBLUE) "de\n"
"agora! Prazer em conhecê-lo!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x12") "Yahoo! Olá, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uau! Uma fada!!" BOX_BREAK UNSKIPPABLE "Finalmente, uma fada veio até você,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vou esperar por você aqui.\n"
"Vá em frente! Vá ver o Grande \n"
"Árvore Deku!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(BLUE) "[A] " COLOR(DEFAULT) "pela pedra, pegue-a!\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "pela pedra, pegue-a!" BOX_BREAK "Mean old" COLOR(RED) "Mido" COLOR(DEFAULT) "...ele me fez escolher \n"
"nas rochas na frente de sua casa."
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, você tem uma " COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) " agora?!\n"
"Isso é ótimo, " NAME "!" BOX_BREAK UNSKIPPABLE "O quê?" BOX_BREAK UNSKIPPABLE "Você foi chamado pelo\n"
COLOR(RED) "Grande Árvore Deku" COLOR(DEFAULT) "? Que honra!" BOX_BREAK UNSKIPPABLE "Ele pode te dar um presente especial!\n"
"Tê-te!" BOX_BREAK UNSKIPPABLE "Isso é porque o Grande Deku \n"
"Árvore é nosso pai, a floresta\n"
"guardião, e deu vida a todos \n"
"de nós Kokiri!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gostaria de saber se a " COLOR(RED) "Great Deku Tree" COLOR(DEFAULT) "\n"
"deu vida a tudo no\n"
"floresta, quero dizer, além de nós \n"
"Kokiri?"
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, vamos trabalhar em alguns movimentos!" BOX_BREAK "Para " COLOR(RED) "saltar para o lado " COLOR(DEFAULT) "enquanto " COLOR(LIGHTBLUE) "[Z] \n"
"Segmentando" COLOR(DEFAULT) ", pressione " COLOR(BLUE) "[A] " COLOR(DEFAULT) "enquanto você se move\n"
"direita ou esquerda." BOX_BREAK "Para fazer um " COLOR(RED) "backflip" COLOR(DEFAULT) " enquanto " COLOR(LIGHTBLUE) "[Z] \n"
"Segmentando" COLOR(DEFAULT) ", pressione " COLOR(BLUE) "[A] " COLOR(DEFAULT) "enquanto você se move\n"
"para trás." BOX_BREAK "Para fazer um ataque de rolo " COLOR(RED) "" COLOR(DEFAULT) " enquanto " COLOR(LIGHTBLUE) "[Z] \n"
"Segmentando" COLOR(DEFAULT) ", pressione " COLOR(BLUE) "[A] " COLOR(DEFAULT) "enquanto você se move\n"
"avançar. Enquanto você rola, você pode\n"
"evitar danos". BOX_BREAK "Se você tiver sua espada pronta enquanto\n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", você pode fazer um salto " COLOR(RED) "\n"
"ataque" COLOR(DEFAULT) " pressionando " COLOR(BLUE) "[A]" COLOR(DEFAULT) "! Um salto \n"
"ataque faz o dobro de dano!" BOX_BREAK "Você pode usar " COLOR(LIGHTBLUE) "[Z] Segmentação " COLOR(DEFAULT) "no\n"
COLOR(RED) "pedra" COLOR(DEFAULT) " ao meu lado, então vamos \n"
"prática!"
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você não tem permissão para sair do \n"
"floresta!" TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A Grande Árvore Deku disse isso se\n"
"um Kokiri sai da floresta, ele ou \n"
"Ela vai morrer!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aquele malvado," COLOR(RED) "Mido" COLOR(DEFAULT) ", me fez cortar \n"
"a grama na casa de Saria." BOX_BREAK UNSKIPPABLE "Mido disse a Saria que faria isso\n"
"ela gostaria dele, mas sou eu\n"
"fazendo todo o trabalho!" TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você e " COLOR(RED) "Saria" COLOR(DEFAULT) " são amigos íntimos,\n"
"então você vai me ajudar a cortar o \n"
"Relva?" BOX_BREAK "Vou deixar você ficar com qualquer coisa que \n"
"você encontra ao cortá-lo."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sim, sim! É assim que você usa um\n"
COLOR(LIGHTBLUE) "Fada" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "É tão bom que você finalmente tenha\n"
"uma fada" COLOR(RED) " " COLOR(DEFAULT) "parceiro!" BOX_BREAK UNSKIPPABLE "Vou te ensinar a falar com \n"
"pessoas usando sua fada!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando uma fada voa perto de uma pessoa \n"
"ou coisa, pressione " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " para " COLOR(RED) "olhar " COLOR(DEFAULT) "naquele\n"
"direção." BOX_BREAK "Se você usar " COLOR(LIGHTBLUE) "[Z] Segmentação" COLOR(DEFAULT) ", você pode \n"
"falar com as pessoas à distância, \n"
"como estamos fazendo agora." BOX_BREAK "Quando você não tem nada que você\n"
"pode segmentar, você pode pressionar " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " apenas\n"
"para " COLOR(RED) "aguarde" COLOR(DEFAULT) ".\n"
"Tente!"
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, uma fada " COLOR(BLUE)" COLOR(DEFAULT) "finalmente chegou até você!" BOX_BREAK UNSKIPPABLE "Agora você tem muito a aprender!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x68\x63") "Uau!" QUICKTEXT_ENABLE "Que ótima notícia!" QUICKTEXT_DISABLE "\n"
"Eu estou tão feliz por você!" BOX_BREAK UNSKIPPABLE "Agora você é um verdadeiro Kokiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "É mesmo? \n"
"A Grande Árvore Deku tem \n"
"convocou você?" BOX_BREAK UNSKIPPABLE "É uma grande honra falar com o\n"
"Grande Árvore Deku!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah, você vai embora..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas tudo bem, porque estaremos\n"
"amigos para sempre...\n"
"não vamos?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quero que você fique com esta Ocarina...\n"
"Por favor, cuide bem disso."
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Quando você tocar minha Ocarina, espero\n"
"você vai pensar em mim e vir\n"
"voltar à floresta para visitar."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah... Navegar...\n"
"Você retornou..." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Bem-vindo..." BOX_BREAK UNSKIPPABLE "Ouça com atenção o que eu, o\n"
COLOR(RED) "Deku Tree" COLOR(DEFAULT) ", estou prestes a te dizer..." BOX_BREAK UNSKIPPABLE "Teu sono nestas luas passadas \n"
"deve ter estado inquieto, e\n"
"cheio de pesadelos..." BOX_BREAK UNSKIPPABLE "Como os servos do mal ganham\n"
"força, um clima vil permeia\n"
"a terra e causa pesadelos\n"
"para aqueles que são sensíveis a isso..." BOX_BREAK UNSKIPPABLE "Verdadeiramente, tu o sentiste..." BOX_BREAK UNSKIPPABLE  NAME "... \n"
"Chegou a hora de testar seu\n"
"coragem..." TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu fui " COLOR(RED) "amaldiçoado" COLOR(DEFAULT) "...\n"
"Preciso que você quebre a maldição\n"
"com sua sabedoria e coragem." BOX_BREAK "Você tem coragem suficiente\n"
"para realizar esta tarefa?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então entre, bravo \n"
NAME ", e você também, \n"
"Navi..." BOX_BREAK UNSKIPPABLE "Navegar a fada... \n"
"Você deve ajudar " NAME "..." BOX_BREAK UNSKIPPABLE "E " NAME "...Quando " COLOR(LIGHTBLUE) "Navi \n"
COLOR(DEFAULT) "fala, use " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "para ouvir bem \n"
"às suas palavras de sabedoria..."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Talvez você ainda não tenha \n"
"confiança em suas habilidades...\n"
"Retorne à Floresta Kokiri para\n"
"aprenda as habilidades de combate..." BOX_BREAK "Quando estiver pronto, volte aqui \n"
"e fale comigo usando " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O melhor lugar para aprender\n"
"algumas novas habilidades estão na " COLOR(ADJUSTABLE) "Forest \n"
"Centro de Treinamento" COLOR(DEFAULT) "." COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "Está na colina\n"
"logo acima aqui."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x38\x82") QUICKTEXT_ENABLE "Ow-ow-ow!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Perdoe-me, mestre!" QUICKTEXT_DISABLE "\n"
"Se eu te der uma pista, você deixa \n"
"eu vou?" BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Quando você pula de um penhasco alto,\n"
"se você segurar " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " para frente, você\n"
"role no chão ao pousar \n"
"e não vai se machucar com a queda." BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Não posso garantir que irá\n"
"funcionar, porém, se o penhasco for mesmo,\n"
"muito alto, heh heh!" BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Bem, experimente se estiver sentindo\n"
"negrito!\n"
QUICKTEXT_ENABLE "Wah ha ha!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ei!\n"
"Sob essa máscara... você não é assim\n"
"Kokiri garoto?"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem uma máscara bem incomum\n"
"lá. Hee hee! Eu gosto! Pode\n"
"Faça-me parecer um pouco mais forte." BOX_BREAK "Ei, por que você não me dá?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"De jeito nenhum" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dó! Isso é muito ruim para mim..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yowza! Vou usar isso \n"
"o tempo todo!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x48\x07") "Ele acabou de te dar " COLOR(RED) "10 Rupees" COLOR(DEFAULT) " para \n"
"esta máscara de 20 rúpias! Você perdeu \n"
"dinheiro nesse negócio!" BOX_BREAK UNSKIPPABLE "Voltar para a loja de máscaras \n"
"e pague " COLOR(RED) "20 Rupees" COLOR(DEFAULT) " pelo \n"
"máscara. A diferença terá que \n"
"saia do seu próprio bolso."
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus amigos querem muito essa máscara!\n"
"Ei, ei, ei!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, você está bem? Você não saiu \n"
"a floresta, afinal, não é?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você sabia que se você segurar " COLOR(LIGHTBLUE) " ▼ \n"
COLOR(DEFAULT) "para a frente quando você pular de um penhasco,\n"
"você vai rolar quando pousar. Isso vai\n"
"absorva o choque de sua aterrissagem." BOX_BREAK "Se você cair muito longe, você\n"
"ainda se machucou..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria disse que está esperando no\n"
"local habitual."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Muito bem, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem um estilingue legal, hein?" BOX_BREAK "Sabe o que é legal nisso?\n"
"Você pode mirar enquanto mantém pressionado\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " e dispare soltando o\n"
"botão! Que legal!" BOX_BREAK "Se você tiver o estilingue pronto,\n"
"você pode usar " COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) " para \n"
COLOR(RED) "atirar enquanto se move" COLOR(DEFAULT) ".... Você \n"
"sabe disso?"
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não, " NAME "...\n"
"Você deve saber que meu tempo é curto..."
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Agora... ouça com atenção...\n"
"Um " COLOR(RED) "homem mau do deserto" COLOR(DEFAULT) " \n"
"lance esta terrível maldição sobre mim..."
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você está procurando por Saria, ela está\n"
"na " COLOR(ADJUSTABLE) "Bosque Perdido" COLOR(DEFAULT), como de costume." BOX_BREAK "Não me diga que você não sabe \n"
"onde fica! A entrada está em cima\n"
"no penhasco com vista para o \n"
"Vila!" BOX_BREAK "Eu sei que você vai se perder! Não \n"
"preocupe-se, você vai acabar voltando às\n"
"a entrada!" BOX_BREAK SHIFT("\x51") QUICKTEXT_ENABLE "Harumph!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você nunca deve permitir o deserto \n"
"homem de armadura preta para colocar seu \n"
"mãos na sagrada Triforce..." BOX_BREAK UNSKIPPABLE "Você nunca deve sofrer esse homem,\n"
"com seu coração mau, para entrar no \n"
"Reino Sagrado" COLOR(RED) " " COLOR(DEFAULT) "da lenda..." BOX_BREAK UNSKIPPABLE "Aquele homem malvado que lançou a morte \n"
"me amaldiçoe e minou meu \n"
"poder..." BOX_BREAK UNSKIPPABLE "Por causa dessa maldição, meu fim é\n"
"próximo..." BOX_BREAK UNSKIPPABLE "Embora seus valentes esforços para \n"
"quebrar a maldição foi bem sucedido, \n"
"Eu estava condenado antes de você começar..." BOX_BREAK UNSKIPPABLE "Sim, morrerei em breve...\n"
UNSKIPPABLE "Mas não sofra por mim..." BOX_BREAK UNSKIPPABLE "Eu pude falar com você sobre \n"
"estes assuntos importantes..." BOX_BREAK UNSKIPPABLE "Esta é a última esperança de Hyrule..."
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O futuro depende de ti,\n"
NAME "...\n"
"Tu és corajoso..." BOX_BREAK UNSKIPPABLE "Navegue a fada...\n"
"Ajude " NAME " a realizar \n"
"minha vontade..." BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x02") "Eu imploro... Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "Adeus..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Vamos para o Castelo de Hyrule,\n"
NAME "!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE TEXT_SPEED("\x01") COLOR(LIGHTBLUE) "Adeus..." COLOR(DEFAULT) TEXT_SPEED("\x00") COLOR(LIGHTBLUE) "Grande Deku Tree..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que pena... Heh heh!"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer jogar mais um pouco?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei você! \"" COLOR(LIGHTBLUE) "Sr. Sem Fada" COLOR(DEFAULT) "!\"\n"
"Qual é o seu negócio com o\n"
"Grande Árvore Deku?" BOX_BREAK UNSKIPPABLE "Sem uma fada, você não é\n"
"mesmo um homem de verdade!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quiser passar por aqui,\n"
"você deve pelo menos " COLOR(BLUE) "equipar" COLOR(DEFAULT) " a " COLOR(ADJUSTABLE) "espada" COLOR(RED) "\n"
COLOR(DEFAULT) "e" COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) "!" BOX_BREAK SHIFT("\x51") QUICKTEXT_ENABLE "Caramba!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x57") QUICKTEXT_ENABLE "O quê?!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE COLOR(RED) "Mido " COLOR(DEFAULT) "não vai deixar você ver \n"
"a Grande Árvore Deku?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode comprar um escudo " COLOR(LIGHTBLUE)" COLOR(DEFAULT) " na loja,\n"
"mas existe apenas uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) "\n"
"escondido em algum lugar na floresta."
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se você quiser ver o \n"
"Grande Árvore Deku, você deveria em \n"
"equipe pelo menos uma " COLOR(ADJUSTABLE) "espada" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) "!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu, o grande Mido," COLOR(RED) " " COLOR(DEFAULT) "nunca irei \n"
"aceito você como um de nós!" BOX_BREAK "Atire! Como você se tornou o\n"
"favorito de Saria e o Grande\n"
"Árvore Deku? Hein?!\n"
"Resmungar... resmungar..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu posso te ensinar sobre os ícones " COLOR(RED) "\n"
COLOR(DEFAULT) "na parte superior da tela.\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sobre os ícones amarelos\n"
"Sobre o ícone azul" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Os três ícones amarelos no \n"
"canto superior direito são chamados de " COLOR(YELLOW) "[C] ícones" COLOR(DEFAULT) "." BOX_BREAK "Eles exibem as coisas que você pode\n"
"use com o " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "e" COLOR(YELLOW) " \n"
"[C-Right]" COLOR(DEFAULT) "botões." BOX_BREAK "Depois de obter um item de botão " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", \n"
"vá para o " COLOR(YELLOW) "Selecione Item Subtela" COLOR(DEFAULT) " \n"
"e defina-o para um dos três\n"
COLOR(YELLOW) "Botões [C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O ícone azul na parte superior do\n"
"tela é chamada de " COLOR(BLUE) "Ícone de Ação" COLOR(DEFAULT) "." BOX_BREAK "Este ícone de ação mostra para você \n"
"qual ação você realizará\n"
"quando você pressiona " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Pare em muitos pontos para ver o\n"
"coisas diferentes que você pode fazer."
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você quiser saber mais sobre o\n"
COLOR(RED) "mapa " COLOR(DEFAULT) "e " COLOR(RED) "itens" COLOR(DEFAULT) ", é só me perguntar.\n"
"Mas não pergunte a menos que você queira\n"
"ouvir uma longa explicação." BOX_BREAK "O que você quer saber?\n"
THREE_CHOICE COLOR(ADJUSTABLE) "Sobre o mapa \n"
"Sobre os itens\n"
"Não pergunte" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Há um mapa " COLOR(RED)" COLOR(DEFAULT) " exibido no \n"
"canto inferior direito da tela." BOX_BREAK "A " COLOR(YELLOW) "seta amarela " COLOR(DEFAULT) "mostra seu \n"
"posição atual e direção que você\n"
"estão voltadas. A marca vermelha " COLOR(RED) "" COLOR(DEFAULT) "aparece\n"
"de onde você entrou na área." BOX_BREAK "Você pode ativar a exibição do mapa\n"
"e desligue com o " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) "." BOX_BREAK "Se você quiser ver o nome de um\n"
"coloque, pressione " COLOR(RED) "START" COLOR(DEFAULT) "." BOX_BREAK "Você entrará no Subtelas.\n"
"Selecione a " COLOR(RED) "Mapa Subtela" COLOR(DEFAULT) "." BOX_BREAK "No Mapa Subtela, você pode \n"
"veja um mapa de Hyrule.\n"
"Você conseguiu tudo isso?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Existem três tipos de itens:\n"
COLOR(BLUE) "Itens de equipamento" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C] Itens de botão" COLOR(DEFAULT) "\n"
"e " COLOR(LIGHTBLUE) "Itens da missão" COLOR(DEFAULT) "." BOX_BREAK COLOR(BLUE) "Itens de equipamento" COLOR(DEFAULT) " são coisas como \n"
"a espada, escudo e roupas \n"
"que são eficazes quando você equipa\n"
"eles." BOX_BREAK COLOR(YELLOW) "[C] Itens de botão" COLOR(DEFAULT) " pode ser definido como \n"
COLOR(YELLOW) "[C-Esquerda]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Baixo]" COLOR(DEFAULT) ", e " COLOR(YELLOW) "[C-Direito]" COLOR(DEFAULT) ", e\n"
"usado pressionando esses botões." BOX_BREAK COLOR(LIGHTBLUE) "Itens de missão " COLOR(DEFAULT) "são coisas que você \n"
"coletar durante sua aventura. Você\n"
"basta levá-los ao redor." BOX_BREAK "Se você quiser trocar de equipamento\n"
"ou apenas verifique seu inventário,\n"
"pressione " COLOR(RED) "INICIAR" COLOR(DEFAULT) ". \n"
"Você vai entrar no Subtelas." BOX_BREAK "Mudar para um dos quatro \n"
"diferentes Subtelas com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou\n"
COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "e altere ou verifique os itens como\n"
"você, por favor. Dê uma olhada ao redor!" BOX_BREAK "Quando você decide equipar um \n"
COLOR(BLUE) "Item de equipamento" COLOR(DEFAULT) ", pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Para\n"
COLOR(YELLOW) "[C] Itens do botão" COLOR(DEFAULT) ", pressione " COLOR(YELLOW) "[C-Esquerda]" COLOR(DEFAULT) ",\n"
COLOR(YELLOW) "[C-Baixo] " COLOR(DEFAULT) "ou " COLOR(YELLOW) "[C-Direito]" COLOR(DEFAULT) "." BOX_BREAK "Essa foi uma explicação bem longa.\n"
"Você entendeu tudo?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, lembre-se disso. Se você\n"
"quer " COLOR(ADJUSTABLE) "salvar" COLOR(DEFAULT) ", pressione " COLOR(RED) "START" COLOR(DEFAULT) "para obter\n"
"no Subtelas, então pressione\n"
COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Minha irmã pegou algumas rúpias e \n"
"foi fazer compras na loja\n"
"que tem um telhado vermelho.\n"
"Tê-te!" BOX_BREAK "Falando em " COLOR(RED) "Rupees" COLOR(DEFAULT) ", um " COLOR(AJUSTABLE) "verde" COLOR(DEFAULT) "um\n"
"vale um, um " COLOR(BLUE) "azul" COLOR(DEFAULT) " um vale\n"
"cinco e um " COLOR(RED) "red" COLOR(DEFAULT) " um vale \n"
"vinte. Hee hee!"
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta loja...Ela vende coisas que você\n"
"pode entrar na floresta de graça!\n"
"Tê-te!" BOX_BREAK "Você sabe como usar o \n"
COLOR(RED) "Deku Shield" COLOR(DEFAULT) "? Tee hee!" BOX_BREAK "Quando você pegar o escudo, pressione\n"
COLOR(RED) "START" COLOR(DEFAULT) "para entrar nas Subtelas.\n"
"Selecione a " COLOR(BLUE) "Subtela do Equipamento\n"
COLOR(DEFAULT) "com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "." BOX_BREAK "Na " COLOR(BLUE) "Equipamento Subtela" COLOR(DEFAULT) ", \n"
"escolha o item que deseja equipar\n"
"e pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para equipar esse item." BOX_BREAK "Depois de equipá-lo, segure-o\n"
"com " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " e altere seu ângulo\n"
"com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Tee hee!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer saber como usar\n"
"o botão " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você pressionar " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", você pode\n"
"mudar sua visão." BOX_BREAK "Em um lugar como este, ele mudará\n"
"para uma visualização de cima para baixo. Ao ar livre, em\n"
"um campo por exemplo, ele mudará\n"
"para uma perspectiva de primeira pessoa." BOX_BREAK "Além disso, quando \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\" é exibido em\n"
"no canto superior direito da tela, \n"
"Navi, a fada, quer falar com\n"
"você. Use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " para ouvi-la!"
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, se você brincar com isso, \n"
"você vai descobrir."
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso não é bem a Canção da Saria..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "está muito chateado!\n"
"Aconteceu alguma coisa com ele?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê? Aonde você vai?!" BOX_BREAK "Para o castelo?\n"
"Onde está o castelo?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós Kokiri morreremos se deixarmos o\n"
"floresta!" BOX_BREAK "Você não vai tentar sair\n"
"a floresta, é você?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, " NAME "!\n"
"O que você fez?!" BOX_BREAK UNSKIPPABLE "A Grande Árvore Deku... ele...\n"
"morrer?" BOX_BREAK UNSKIPPABLE "Como você pode fazer uma coisa como \n"
"isso?! É tudo culpa sua!!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ei!!" QUICKTEXT_DISABLE "\n"
"O que você está fazendo na minha casa?!"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME UNSKIPPABLE ", você está seguro!" TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria e " NAME " serão\n"
"amigos para sempre."
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aconteceu algo com o \n"
"Grande Árvore Deku?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De alguma forma, parece que o ar entra\n"
"a floresta mudou."
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", você vai\n"
"ir embora?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você perder seu escudo, vai\n"
"Você volta?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x80") "Todos os jovens Deku Scrub\n"
"os irmãos concordam...você parece exatamente \n"
"como nosso totem da floresta sagrada!" BOX_BREAK SFX("\x38\x80") "Como uma oferta nossa, por favor\n"
"aceite estes " COLOR(RED) "Deku Sticks" COLOR(DEFAULT) ".\n"
"Também melhoraremos seu\n"
"habilidades de transporte!" BOX_BREAK "Abracadabra!" BOX_BREAK SFX("\x38\x80") "Alakazaaaam!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desde a Grande Árvore Deku\n"
"murchou...mais malvados têm \n"
"estão aparecendo na floresta...\n"
"Eu estou assustado!"
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Um vento maligno está soprando do \n"
"direção do Templo da Floresta." BOX_BREAK UNSKIPPABLE COLOR(RED) "Saria" COLOR(DEFAULT) " esquerda, dizendo,\n"
"\"Tenho que fazer algo\n"
"sobre isso!"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O " COLOR(ADJUSTABLE)"Templo da Floresta" COLOR(DEFAULT) "está localizado \n"
"no Prado da Floresta Sagrada em\n"
"o outro lado do Bosque Perdido."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria foi ao templo e \n"
"não voltou..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oi, senhor! Você não pode usar um\n"
"Escudo Deku! É apenas para\n"
"crianças!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde está Saria? \n"
"Você conhece Saria, senhor?\n"
"Isso é estranho..." TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde " COLOR(RED) "Mido" COLOR(DEFAULT) " foi durante tal\n"
"uma emergência?"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Entendo. Você não tinha nenhum \n"
"problemas ao entrar na floresta, \n"
"senhor..." BOX_BREAK "Os malvados incomodaram\n"
"você muito? Antes do Grande Deku \n"
"A árvore morreu, você não veria as coisas\n"
"assim por aqui...." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Já que é perigoso lá fora, eu \n"
"fica sempre dentro da minha casa. \n"
"Mas eu estou morrendo de tédio aqui!"
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode comprar " COLOR(RED) "setas " COLOR(DEFAULT) "em uma loja \n"
"somente se você tiver um arco " COLOR(RED)" COLOR(DEFAULT) ". Você tem \n"
"tem um, senhor?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você tem viajado por aí\n"
"muito, senhor?\n"
"Você já conheceu um garoto chamado \n"
NAME "?" BOX_BREAK UNSKIPPABLE "Mido disse que o Grande Deku \n"
"A árvore murchou porque aquele menino\n"
"fez algo errado com isso..." BOX_BREAK UNSKIPPABLE "Só a Saria defendeu \n"
NAME "--até ela sair." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Talvez tenhamos entendido errado..."
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não te vi em algum lugar\n"
"antes, senhor?"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Senhor, você conhece um menino \n"
"chamado " NAME "?" BOX_BREAK UNSKIPPABLE "Ele saiu da floresta e nunca\n"
"voltou..." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gostaria de saber se " NAME " vai \n"
"voltar sempre?"
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Seria incrível ser grande \n"
"como você, senhor! Eu realmente quero\n"
"seja grande como você!" BOX_BREAK UNSKIPPABLE "Quero ser grande e forte e \n"
"derrubar os Deku Scrubs, mas..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós Kokiri nunca vamos ficar maiores \n"
"pelo resto de nossas vidas...\n"
"Que chato!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por que aquela fada está seguindo você \n"
"por perto? Você não é um de nós!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O que você é? Embora você use \n"
"Roupas Kokirish, você não pode\n"
"me engana!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Prometi a Saria que nunca faria\n"
"deixe qualquer um passar por aqui."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olá! Eu sou a " COLOR(RED) "Deku Tree \n"
"brotar" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Porque você e Saria" COLOR(RED) " " COLOR(DEFAULT) "quebraram a\n"
"maldição no Templo da Floresta, eu \n"
"pode crescer e florescer!" BOX_BREAK UNSKIPPABLE "Muito obrigado!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, você viu seu antigo\n"
"amigos? Nenhum deles reconheceu\n"
"você com seu corpo adulto, fez\n"
"elas?" BOX_BREAK UNSKIPPABLE "Isso porque " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) " nunca\n"
"cresça! Mesmo depois de sete anos,\n"
"eles ainda são crianças!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você deve estar se perguntando por que apenas\n"
"você cresceu!" BOX_BREAK UNSKIPPABLE "Bem, como você já deve ter feito \n"
"adivinhou, você não é um Kokiri!\n"
"Você é na verdade um " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Estou feliz em finalmente revelar isso\n"
"segredo para você!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Há algum tempo, antes do Rei de\n"
"Hyrule unificou este país, lá\n"
"foi uma guerra feroz em nosso mundo." BOX_BREAK_DELAYED("\x5A") "Um dia, para escapar dos incêndios\n"
"da guerra, uma " COLOR(RED) "Mãe Hyliana " COLOR(DEFAULT) "e \n"
"ela " COLOR(RED) "menino" COLOR(DEFAULT) " entrou nisso \n"
"floresta proibida". BOX_BREAK_DELAYED("\x5A") "A mãe ficou gravemente ferida...\n"
"Sua única opção foi confiar\n"
"a criança para o " COLOR(RED) "Deku Tree" COLOR(DEFAULT) ", o \n"
"espírito guardião da floresta". BOX_BREAK_DELAYED("\x5A") "A Árvore Deku pode sentir isso\n"
"este era um filho do destino, cujo\n"
"o destino afetaria o mundo inteiro,\n"
"então ele o levou para a floresta." BOX_BREAK_DELAYED("\x5A") "Depois que a mãe faleceu, \n"
"o bebê foi criado como " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) ".\n"
"E agora, finalmente, o dia de \n"
"o destino chegou!" FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você é um " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) ", e era\n"
"sempre obrigado a deixar esta floresta." BOX_BREAK UNSKIPPABLE "E agora...\n"
"Você aprendeu o seu próprio \n"
"destino...\n"
"Então você sabe o que deve fazer..." BOX_BREAK UNSKIPPABLE "Isso mesmo...\n"
"Você deve salvar a terra de \n"
"Hyrule!" BOX_BREAK UNSKIPPABLE "Agora, " NAME ", quebre o \n"
"maldições em todos os Templos,\n"
"e devolva a paz a Hyrule!!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SHIFT("\x37") "Aquela melodia?!" BOX_BREAK UNSKIPPABLE "Saria toca essa música o tempo todo \n"
"hora!\n"
"Você... você conhece Saria?" BOX_BREAK UNSKIPPABLE "Essa música..." BOX_BREAK UNSKIPPABLE "Saria ensinou apenas essa música \n"
"para os amigos dela..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando eu te vejo... \n"
"Não sei porque, mas lembro...\n"
"ele..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu tenho você agora!\n"
"Nessa lacuna entre sonhos e \n"
"realidade, em breve tudo o que restará\n"
"de você será o seu cadáver!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigado...\n"
"Por sua causa, eu poderia acordar como\n"
"a Sage..." BOX_BREAK UNSKIPPABLE "Eu sou " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"O Sábio do Templo da Floresta..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE SHIFT("\x28") "Saria sempre será...\n"
SHIFT("\x3C") "seu amigo..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O fluxo do tempo é sempre cruel...\n"
"Sua velocidade parece diferente para\n"
"cada pessoa, mas ninguém pode \n"
"change it..." BOX_BREAK UNSKIPPABLE "Uma coisa que não muda com\n"
"o tempo é uma lembrança dos dias de juventude..." BOX_BREAK UNSKIPPABLE "Para voltar aqui novamente,\n"
"toque a " COLOR(ADJUSTABLE) "Minueto da Floresta" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "...\n"
"Te vejo de novo..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria ainda não voltou...\n"
"Mas eu sei que ela vai voltar um dia..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "OK...\n"
"Eu confio em você." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah...Entendo..." BOX_BREAK UNSKIPPABLE "Saria nunca mais voltará..." BOX_BREAK UNSKIPPABLE "Mas...eu...eu prometi \n"
"Saria..." BOX_BREAK UNSKIPPABLE "Se " NAME " voltou, eu \n"
"certifique-se de dizer a ele que \n"
"Saria estava esperando por ele..." BOX_BREAK UNSKIPPABLE "Porque " TEXT_SPEED("\x03") "Saria... realmente...\n"
"gostei..." TEXT_SPEED("\x00") TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Ei, você." BOX_BREAK "Se você o vir em algum lugar, por favor\n"
"deixe ele saber..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ensine-me uma esgrima sofisticada!\n"
"Tudo o que eu fiz foi tocar em " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "todos\n"
"Minha vida!"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ainda acho que você realmente se parece\n"
"alguém que eu já vi antes, senhor."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é um cara tão grande e forte!\n"
"Eu realmente quero ser como você \n"
"algum dia mesmo que eu sempre estarei\n"
"pequeno."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... gostaria de saber se ele \n"
"Voltará..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sinto que te conheço há\n"
"muito tempo, senhor!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Agora que o " COLOR(RED) "broto da árvore Deku" COLOR(DEFAULT) "\n"
"está crescendo no Grande Deku \n"
"Prado de árvore, a floresta tem\n"
"voltou ao normal!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Todos trabalharemos juntos para proteger\n"
"a floresta!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"De alguma forma, um vento favorável começou\n"
"explodir recentemente."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Desde que um bom vento começou a \n"
"golpe, tenho certeza que " NAME " \n"
"Voltará!"
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu me pergunto se Saria vai voltar..."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Tenho certeza de que " NAME " será \n"
"voltar um dia!"
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x2E") COLOR(LIGHTBLUE) "Grande Deku Tree...\n"
COLOR(DEFAULT) SHIFT("\x48") COLOR(LIGHTBLUE) "Estou de volta!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Este homem mau usa incessantemente\n"
"seus poderes vis e feiticeiros em seu\n"
"procure pelo Reino Sagrado que\n"
"está conectado a Hyrule..." BOX_BREAK UNSKIPPABLE "Pois está naquele Reino Sagrado \n"
"aquele vai encontrar o divino\n"
"relíquia, a " COLOR(LIGHTBLUE) "Triforce" COLOR(DEFAULT) ", que contém \n"
"a essência dos deuses..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x06") "Antes do início dos tempos, antes dos espíritos\n"
SHIFT("\x31") "e a vida existia..." QUICKTEXT_DISABLE FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x02") "Três deusas douradas desceram\n"
SHIFT("\x04") "sobre o caos que era Hyrule..." QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x13") "Din, a deusa do poder..." QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x09") "Nayru, a deusa da sabedoria..." QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x06") "Farore, a deusa da coragem..." QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x53") "Din..." QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x02") "Com seus fortes braços flamejantes, ela\n"
SHIFT("\x0A") "cultivou a terra e criou\n"
SHIFT("\x3A") "a terra vermelha." QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x03") "Derramou sua sabedoria na terra\n"
SHIFT("\x0F") "e deu o espírito da lei para\n"
SHIFT("\x45") "o mundo." QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x09") "Com sua alma rica, produziu tudo\n"
SHIFT("\x14") "formas de vida que defenderiam\n"
SHIFT("\x4B") "a lei." QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x16") "As três grandes deusas,\n"
SHIFT("\x22") "trabalhos concluídos,\n"
SHIFT("\x19") "partiu para os céus." QUICKTEXT_DISABLE FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x14") "E triângulos sagrados dourados\n"
SHIFT("\x07") "permaneceu no ponto onde o\n"
SHIFT("\x1B") "deusas deixaram o mundo." QUICKTEXT_DISABLE FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x08") "Desde então, os triângulos sagrados\n"
SHIFT("\x0E") "tornaram-se a base do nosso\n"
SHIFT("\x2E") "providência do mundo." QUICKTEXT_DISABLE FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x0F") "E, o local de descanso do\n"
SHIFT("\x1C") "triângulos se tornaram os\n"
SHIFT("\x3B") "Reino Sagrado." QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei garoto, você foi muito bem...\n"
"Parece que você está ganhando\n"
"alguma pequena habilidade..." BOX_BREAK_DELAYED("\x3C") "Mas você derrotou apenas o meu\n"
"fantasma...\n"
"Quando você luta contra o verdadeiro eu, é \n"
"não vai ser tão fácil!" BOX_BREAK_DELAYED("\x3C") "Que criação inútil essa \n"
"fantasma era! Vou bani-lo para\n"
"a diferença entre as dimensões!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sempre acreditei que você \n"
"venha. Porque eu conheço você..." BOX_BREAK UNSKIPPABLE "Não..." BOX_BREAK_DELAYED("\x1E") UNSKIPPABLE "Você não precisa explicar\n"
"isso para mim..." BOX_BREAK UNSKIPPABLE "Porque é o destino que você \n"
"e eu não posso viver no mesmo mundo."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vou ficar aqui como a Floresta\n"
"Sage and help you..." BOX_BREAK UNSKIPPABLE "Agora, por favor, pegue isso \n"
COLOR(ADJUSTABLE) "Medalhão" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tu demonstraste verdadeiramente \n"
"tua coragem..." BOX_BREAK UNSKIPPABLE "Eu sabia que você seria capaz\n"
"realizar meus desejos..."
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Agora, ainda tenho mais para lhe contar,\n"
"você ouviria...\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
NAME UNSKIPPABLE "...\n"
"Vá agora para o Castelo de Hyrule..." BOX_BREAK UNSKIPPABLE "Lá, você certamente conhecerá\n"
"a " COLOR(RED) "Princesa do Destino" COLOR(DEFAULT) "..." BOX_BREAK IMPRESCINDÍVEL "Leve " COLOR(RED) "esta pedra " COLOR(DEFAULT) "com você.\n"
"A pedra que o homem tanto queria\n"
"muito, que ele lançou a maldição sobre\n"
"mim..."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu" COLOR(RED) " " COLOR(DEFAULT) "sabia...\n"
"que você deixaria a floresta...\n"
"algum dia, " NAME "..." BOX_BREAK UNSKIPPABLE "Porque você é diferente de\n"
"mim" COLOR(RED) " " COLOR(DEFAULT) "e meus amigos...."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE SFX("\x68\x44") COLOR(LIGHTBLUE) "Olá, " QUICKTEXT_ENABLE NAME QUICKTEXT_DISABLE "!\n"
"Acordar!" COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "A" COLOR(RED) "Grande Árvore Deku" COLOR(LIGHTBLUE) "quer\n"
"falar com você!\n"
QUICKTEXT_ENABLE NAME ", levante-se!" QUICKTEXT_DISABLE COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE SFX("\x68\x5F") COLOR(LIGHTBLUE) "Ei!" QUICKTEXT_ENABLE "Vamos!" QUICKTEXT_DISABLE COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE COLOR(LIGHTBLUE) "O destino de Hyrule pode realmente depender\n"
"em um menino tão preguiçoso?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pular está saindo de moda agora.\n"
"Estou louco para fazer " COLOR(RED) "backflips" COLOR(DEFAULT) "!\n"
SHIFT("\x32") "Você pode fazer um?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "A " COLOR(RED) "Grande Árvore Deku \n"
COLOR(LIGHTBLUE) "convocou você!\n"
"Então vamos indo, agora!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT UNSKIPPABLE("\x4B") "Navegação...\n"
SHIFT("\x23") "Navi, onde você está?\n"
SHIFT("\x39") "Venha aqui..."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, " COLOR(LIGHTBLUE) "Navegue a fada" COLOR(DEFAULT) "...\n"
"Ouça minhas palavras, as palavras de \n"
"a " COLOR(RED) "Árvore Deku" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Você sente isso?\n"
"O clima do mal descendo \n"
"sobre este reino..." BOX_BREAK UNSKIPPABLE "Forças malévolas até agora são\n"
"reunindo-se para atacar nossa terra\n"
"of Hyrule..." BOX_BREAK UNSKIPPABLE "Por tanto tempo, a " COLOR(RED) "Kokiri Forest" COLOR(DEFAULT) ", a\n"
"fonte de vida, tem se mantido como \n"
"barreira, desencorajando estranhos e \n"
"mantendo a ordem do mundo..." BOX_BREAK UNSKIPPABLE "Mas... diante desse tremendo mal\n"
"poder, até o meu poder é tão \n"
"nada..." BOX_BREAK UNSKIPPABLE "Parece que chegou a hora de \n"
"o menino " COLOR(RED) "sem fada " COLOR(DEFAULT) "para começar \n"
"sua jornada..." BOX_BREAK UNSKIPPABLE "A juventude cujo destino é\n"
"levar Hyrule ao caminho de \n"
"justiça e verdade..." BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "...vá agora! Encontre nossos jovens\n"
"amigo e guie-o até mim..." BOX_BREAK UNSKIPPABLE "Não me resta muito tempo." BOX_BREAK UNSKIPPABLE "Voe, Navi, voe! O destino dos\n"
"floresta, não, o mundo, depende\n"
"sobre ti!"
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x38\x82") "Por favor, me perdoe, mestre! Eu vou \n"
"nunca faça isso de novo! Se você poupar \n"
"eu, eu vou te ensinar uma coisa legal." BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Você nunca vencerá meus irmãos \n"
"à frente, a menos que você os puna \n"
"na ordem correta". BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "O pedido é..." TEXT_SPEED("\x05") COLOR(LIGHTBLUE) "2 3 1" COLOR(DEFAULT) TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Vinte e três é o número um!" COLOR(DEFAULT) QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Você acha que eu sou um traidor?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x38\x82") "Como você conheceu nosso segredo?!\n"
"Como " QUICKTEXT_ENABLE "irritante!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "É tão chato que vou\n"
"revelar o segredo da Rainha Gohma\n"
"para você!" BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Para administrar o golpe de\n"
"graça à Rainha Gohma, ataque\n"
"com sua espada " COLOR(RED) "enquanto ela está \n"
"atordoado" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Oh, Queenie..." BOX_BREAK SFX("\x38\x80") QUICKTEXT_ENABLE "Desculpe por isso!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"Na vasta e profunda floresta de Hyrule..." BOX_BREAK_DELAYED("\x28") SHIFT("\x16") "Por muito tempo servi como\n"
SHIFT("\x33") "espírito guardião...\n"
SHIFT("\x0C") "Sou conhecido como a Árvore Deku..." FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "Os filhos da floresta, os\n"
SHIFT("\x19") "Kokiri, viva aqui comigo." BOX_BREAK_DELAYED("\x3C") SHIFT("\x0B") "Cada Kokiri tem o seu\n"
SHIFT("\x38") "fada guardiã." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "No entanto, há um menino" COLOR(RED) " " COLOR(DEFAULT) "quem\n"
SHIFT("\x20") "não tem fada..." FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo! Em troca, vou vender \n"
"seu Deku Nuts!\n"
COLOR(RED) "5 peças 20 rúpias" COLOR(DEFAULT) "são!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tudo bem! Você ganhou! Em troca,\n"
"Vou te vender Deku Sticks!\n"
COLOR(RED) "1 peça 15 rúpias" COLOR(DEFAULT) "eles são!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tudo bem! Você ganhou! Em troca de\n"
"me poupando, eu vou te vender um \n"
"Pedaço de coração!\n"
COLOR(RED) "1 peça 10 rúpias" COLOR(DEFAULT) "é!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80") QUICKTEXT_ENABLE "Vamos fazer um acordo!\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"De jeito nenhum" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") QUICKTEXT_ENABLE "YIKES!!" QUICKTEXT_DISABLE "\n"
"Eu vou para casa então!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Rúpias insuficientes! \n"
"Volte novamente!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Você não pode ter isso agora!\n"
"Volte novamente!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80") QUICKTEXT_ENABLE SHIFT("\x2D") "Muito obrigado!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Estive esperando por você,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Esta é a " COLOR(RED) "Prado da Floresta Sagrada" COLOR(DEFAULT) ".\n"
"É" COLOR(RED) " " COLOR(DEFAULT) "meu lugar secreto!\n"
"Sinto..." BOX_BREAK UNSKIPPABLE "Este lugar será muito \n"
"importante para nós dois algum dia.\n"
"Isso é o que eu sinto." BOX_BREAK UNSKIPPABLE "Se você jogar a Ocarina aqui, você \n"
"pode falar com os espíritos no \n"
"floresta." TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você gostaria de jogar o \n"
"Ocarina comigo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não faça isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, tente acompanhar o\n"
"melodia eu vou tocar.\n"
"Você está pronto?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Huh?!\n"
"Que chato!\n"
"Vamos! Jogue junto!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x68\x63") SHIFT("\x36") "Ótimo! Ótimo!" BOX_BREAK UNSKIPPABLE "Por favor, não esqueça esta música!\n"
"Você promete?" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando você quiser ouvir minha voz,\n"
"reproduzir " COLOR(ADJUSTABLE) "Canção da Saria" COLOR(DEFAULT) ". Você pode falar \n"
"comigo a qualquer hora..."
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está cuidando bem de \n"
"minha Ocarina?"
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX UNSKIPPABLE("\x38\x80") "Legal!\n"
"Você é ótimo! Você marcou\n"
"três alvos perfeitos!" BOX_BREAK UNSKIPPABLE SFX("\x38\x80") "Tenho que dar um presente legal\n"
"para uma pessoa tão maravilhosa!\n"
"Por favor, pegue!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido pode saber algo sobre\n"
"O paradeiro de Saria." BOX_BREAK "Acho que Mido está de mau humor em um dos \n"
"as casas por aqui."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A") COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT) SHIFT("\x15") COLOR(LIGHTBLUE) "Sem resposta. Ele está dormindo." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cojiro? Por quê?\n"
"Normalmente só um cara legal como eu \n"
"pode domar você..." BOX_BREAK UNSKIPPABLE "O que significa..." BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x01") "Você... " TEXT_SPEED("\x00") "Você deve ser um cara legal!\n"
QUICKTEXT_ENABLE "Deve ser!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Você deve ser!!" QUICKTEXT_DISABLE "\n"
"Por favor, Sr. Cara Bonzinho! Por favor!" BOX_BREAK UNSKIPPABLE "Entregue este material para o " COLOR(RED) "antigo\n"
"bruxa na loja de poções " COLOR(DEFAULT) "em Kakariko\n"
"Vila!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso desaparecerá se você pegar\n"
"muito tempo, então você precisa se apressar!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não consigo" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, sim." QUICKTEXT_ENABLE "É isso!" QUICKTEXT_DISABLE "\n"
"Afinal, você não é um cara legal!!\n"
QUICKTEXT_ENABLE "Afaste-se de mim!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria queria ver você...\n"
"Ela já te encontrou?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Depressa, cara legal!\n"
"Antes que desapareça, entregue-o\n"
"para aquela velha vadia..."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Esse cara não está mais aqui." BOX_BREAK UNSKIPPABLE "Qualquer pessoa que entrar no \n"
"a floresta será perdida." BOX_BREAK UNSKIPPABLE "Todo mundo se tornará um Stalfos.\n"
"Todo mundo, Stalfos.\n"
"Então, ele não está mais aqui.\n"
"Só resta a serra dele. Hee hee." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse remédio é feito de \n"
"cogumelos da floresta. Devolva!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh.\n"
"Você vai ser... também?\n"
"Heh heh!"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nós vendemos escudos, mas não espadas!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você sabe" COLOR(ADJUSTABLE) "Canção da Saria" COLOR(DEFAULT) "! Devemos\n"
"sejam amigos! Aqui, tome isso!"
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oi! Você acha que meu rosto é gentil\n"
"de planície?\n"
"Não é muito incomum..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vamos jogar de novo algum dia!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Acompanhe nossa música em \n"
"sua Ocarina. Nós o guiaremos \n"
"afim disso."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Foi uma boa sessão.\n"
"Como prova de nossa amizade, \n"
"por favor, pegue isso."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, aqui!\n"
"Hoo-hoo!" BOX_BREAK_DELAYED("\x28") NAME UNSKIPPABLE "...Bom ver você\n"
"de novo! Ouça isso!\n"
"Hoot hoot...." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Depois de passar pelo Lost \n"
"Woods, você vai encontrar o \n"
COLOR(ADJUSTABLE) "Prado da Floresta Sagrada" COLOR(DEFAULT) "." BOX_BREAK "Esse é um lugar sagrado onde poucos\n"
"as pessoas já andaram." BOX_BREAK "Shhhh... O que é isso?\n"
"Eu posso ouvir uma música misteriosa..." BOX_BREAK "Você deveria ouvir essa música\n"
"também...\n"
"Hoo-ho-ho!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer ouvir o que eu disse\n"
"de novo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você é corajoso, você\n"
"vai passar pela floresta\n"
"muito bem..." BOX_BREAK UNSKIPPABLE "Apenas siga seus ouvidos e ouça\n"
"aos sons vindos do\n"
"floresta! \n"
"Hot hoo!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo!" BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "Você aprendeu uma música de Ocarina\n"
"de Sária?" BOX_BREAK UNSKIPPABLE "Essa melodia parece ter alguma\n"
"poder misterioso". BOX_BREAK UNSKIPPABLE "Pode haver algum outro \n"
"músicas misteriosas como essa que\n"
"você pode aprender em Hyrule." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você segurar a Ocarina com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"onde uma melodia é necessária, um \n"
COLOR(RED) "pauta musical " COLOR(DEFAULT) "aparecerá." BOX_BREAK "Recomendo que você toque uma música\n"
"você sabe." BOX_BREAK "Também sugiro que você jogue mesmo\n"
"quando uma pontuação não é exibida. \n"
"Assim como isto:\n"
"Hoo hoo hoo hoo hoo hoo!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer ouvir o que eu\n"
"disse de novo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Melodias que você aprendeu \n"
"será gravado na " COLOR(LIGHTBLUE) "Quest \n"
"Status Subtela" COLOR(DEFAULT) ". Você deve \n"
"memorize essas melodias."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah... Aquele vagabundo! Não sei porque \n"
"ele é sempre tão mau com todos!" BOX_BREAK UNSKIPPABLE "Mas o que ele disse é verdade." TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "A floresta... coisas estranhas têm\n"
"está acontecendo aqui ultimamente..." BOX_BREAK UNSKIPPABLE "Você precisa estar pronto para qualquer coisa.\n"
"É melhor você encontrar uma arma!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tudo bem! Você ganhou! Em troca,\n"
"Vou vender para você" COLOR(RED) "Deku Seeds" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 peças 40 Rupees" COLOR(DEFAULT) "são!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu desisto! Se você me deixar ir,\n"
"Vou te vender um " COLOR(RED) "Deku Shield" COLOR(DEFAULT) "! É\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Desisto! Se você me deixar ir, vou vender \n"
"você alguns " COLOR(RED) "Bombas" COLOR(DEFAULT) "!\n"
COLOR(RED) "5 peças 40 rúpias" COLOR(DEFAULT) "são!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Pare com isso! Deixe-me em paz e \n"
"Vou vender para você" COLOR(RED) "Setas" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 peças 70 rúpias" COLOR(DEFAULT) "são!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tudo bem! Você ganha! Se você poupar \n"
"eu, eu vou te vender um " COLOR(RED) "Red Potion" COLOR(DEFAULT) " \n"
"for " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Tudo bem! Você venceu! Me poupe e\n"
"Vou vender-lhe uma " COLOR(ADJUSTABLE) "Poção Verde" COLOR(DEFAULT) " por \n"
COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O quê?! Você tem uma fada?!\n"
"Dizer o quê? A Grande Árvore Deku\n"
"realmente convocou você?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O quê?!" BOX_BREAK UNSKIPPABLE "Por que ele chamaria você e não \n"
"o grande " COLOR(RED) "Mido" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Isso não é engraçado..." BOX_BREAK UNSKIPPABLE "Não acredito!\n"
"Você nem está totalmente equipado\n"
"ainda!" BOX_BREAK UNSKIPPABLE "Como você acha que vai \n"
"ajudar a Grande Árvore Deku sem\n"
"ambos uma " COLOR(ADJUSTABLE) "espada" COLOR(RED) " " COLOR(DEFAULT) "e " COLOR(LIGHTBLUE) "escudo" COLOR(RED) " " COLOR(DEFAULT) "pronto?" BOX_BREAK "O quê? Você está certo, eu não tenho\n"
"meu equipamento pronto, mas..." TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SHIFT("\x2D") "Eh, o que é isso?!" BOX_BREAK UNSKIPPABLE "Ah, você tem um " COLOR(LIGHTBLUE) "Deku Shield" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "E o que é ISSO?!" BOX_BREAK UNSKIPPABLE "Essa é a " COLOR(ADJUSTABLE) "Kokiri Sword" COLOR(DEFAULT) "?!" BOX_BREAK UNSKIPPABLE "BOA TRISTEZA!!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Bem, mesmo com todas essas coisas, \n"
"um covarde ainda é um covarde, hein?" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Perdi! Agora vou te vender um " COLOR(RED) "Deku \n"
"Coloque " COLOR(DEFAULT) "para " COLOR(RED) "15 Rupees" COLOR(DEFAULT) "." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Perdi! Agora vou te vender " COLOR(RED) "Deku \n"
"Nuts " COLOR(DEFAULT) "se você me deixar em paz.\n"
COLOR(RED) "5 peças 20 rúpias" COLOR(DEFAULT) "eles são." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"E também..." BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x0D") "Desculpe por ter sido má com ele." QUICKTEXT_DISABLE BOX_BREAK SHIFT("\x45") "Diga isso a ele também."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee!\n"
"Você veio até aqui?\n"
"Você é um homem de verdade!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olha! Essa vista não é linda?\n"
"Mude seu ponto de vista com " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ",\n"
"para que você possa olhar ao redor da floresta\n"
"com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você fez com o Grande\n"
"Árvore Deku?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quiser ir para o Lost \n"
"Woods, é melhor você equipar o\n"
"engrenagem certa!\n"
"Ei, ei!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\x82") "Todos os meus jovens irmãos Deku Scrub\n"
"diga...\n"
"Você tem um rosto horrível!" BOX_BREAK SFX("\x38\x82") "Mas não se preocupe! Nós recompensaremos\n"
"você com muitos " COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "." BOX_BREAK SFX("\x38\x82") "Claro que também habilitaremos \n"
"você para carregar mais deles!" BOX_BREAK "Abracadabra..." BOX_BREAK SFX("\x38\x80") "Alakazaaaam!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo!" BOX_BREAK SFX("\x38\x80") "Para facilitar sua missão,\n"
"Posso permitir que você pegue mais\n"
COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"Mas, vai te custar " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Eu me rendo!" BOX_BREAK SFX("\x38\x80") "Para facilitar sua missão, posso\n"
"permite que você pegue mais " COLOR(RED) "Deku\n"
"Nozes" COLOR(DEFAULT) "!\n"
"Mas, vai te custar " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Desculpe!\n"
"Você não pode comprar isso agora!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse cara não está mais aqui." BOX_BREAK "Qualquer pessoa que entrar no \n"
"a floresta será perdida." BOX_BREAK "Todo mundo se tornará um Stalfos.\n"
"Todo mundo, Stalfos.\n"
"Então, ele não está mais aqui."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Muito obrigado pelo \n"
"outro dia... eu nem perguntei\n"
"já seu nome..." BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00") BOX_BREAK UNSKIPPABLE "Sério?\n"
NAME "!" BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "Foi o que pensei!" QUICKTEXT_DISABLE "\n"
"Você é o menino fada do\n"
"floresta! Isso foi há anos!\n"
"Você se lembra de mim?" BOX_BREAK UNSKIPPABLE "Você quer? Eu tinha certeza que era você\n"
"porque Epona se lembrou de você!" BOX_BREAK UNSKIPPABLE "Ah, preciso falar sobre\n"
COLOR(RED) "Sr. Ingo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Ele estava com medo do Rei Maligno\n"
"pode descobrir que Epona tinha\n"
"foi levado... Ficou muito chateado\n"
"ele!" BOX_BREAK UNSKIPPABLE "Mas um dia, de repente, ele\n"
"voltou a ser normal," COLOR(RED) "legal\n"
"pessoa" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Agora meu pai está voltando...I\n"
"não acredito, mas a paz é\n"
"voltando a este rancho!" BOX_BREAK UNSKIPPABLE "É tudo por sua causa! I\n"
"Devo-lhe muito!" BOX_BREAK UNSKIPPABLE "Obrigado! Obrigado,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como " COLOR(RED) "Epona" COLOR(DEFAULT) "está indo?" BOX_BREAK "Se você tocar " COLOR(RED) "Música da Epona " COLOR(DEFAULT) "com\n"
"sua Ocarina, ela com certeza vai\n"
"ir até você." BOX_BREAK "Por favor, volte para o rancho\n"
"sempre que você quiser " COLOR(RED) "treinar \n"
COLOR(DEFAULT) "Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "está ótimo!\n"
"Parece que você conseguiu\n"
"para domá-la, também!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que tal testar sua habilidade com\n"
"Epona em uma " COLOR(RED) "curso de obstáculos" COLOR(DEFAULT) "?" BOX_BREAK "Vou cronometrar você para " COLOR(RED) "duas voltas" COLOR(DEFAULT) ".\n"
"É bastante desafiador. Se você\n"
"falta de pular uma cerca no \n"
"ordem adequada, você vai falhar." BOX_BREAK "Que tal?\n"
"Você quer tentar? \n"
TWO_CHOICE COLOR(ADJUSTABLE) "Vamos\n"
"Não faça isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, seu tempo era " COLOR(RED) RACE_TIME COLOR(DEFAULT) ".\n"
"Você tem que treinar mais!" BOX_BREAK "Lembre-se, você não precisa \n"
"acelerar para saltar mais baixo \n"
"cercas, mas você precisa ir\n"
"rápido para pular as cercas altas!"
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME "...você pode me ouvir?\n"
"Sou eu, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Moooooooooo!" BOX_BREAK "Que música legal...\n"
"Isso me lembra o pasto..." BOX_BREAK "Essa música me faz sentir tão bem,\n"
"Eu posso produzir muito leite!" EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tome um pouco do meu refrescante e \n"
"leite nutritivo!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
NAME ", quando você segura\n"
"esta Ocarina na sua mão..." BOX_BREAK_DELAYED("\x3C") "Eu não estarei mais por aqui..." BOX_BREAK_DELAYED("\x3C") "Eu queria esperar por você, mas eu\n"
"não poderia demorar mais..." BOX_BREAK_DELAYED("\x3C") "Pelo menos eu poderia deixar o \n"
"Ocarina e " COLOR(LIGHTBLUE) "esta melodia" COLOR(DEFAULT) "..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Agora, " NAME ".\n"
"Toque esta melodia na frente do\n"
"altar no Templo do Tempo.\n"
"Você deve proteger a Triforce!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha-hah! Você acha que \n"
"você está disfarçado, Sr. Herói?" BOX_BREAK SHIFT UNSKIPPABLE("\x57") "Oh?" BOX_BREAK UNSKIPPABLE "Isso é um \"Kee...alguma coisa...\"\n"
"máscara de personagem? Ouvi dizer que ele é \n"
"muito popular recentemente?" BOX_BREAK UNSKIPPABLE "Ele é o favorito do meu garoto. Isso\n"
"\"Kee...alguma coisa...\" máscara...\n"
"Se você não se importa..." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você vai vender para mim?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"De jeito nenhum" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não vou desistir! Tenho bastante\n"
"paciência. Eu tenho que para isso \n"
"trabalho! Hah hah hah!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mmmm...murmúrio...murmúrio...\n"
"Huh? Sim, eu estou acordado!" BOX_BREAK UNSKIPPABLE "O quê?" BOX_BREAK UNSKIPPABLE "Ei, é você! Bem-vindo!" BOX_BREAK UNSKIPPABLE "Awww... Isso foi difícil!\n"
"Malon gritou comigo por muito tempo\n"
"Tempo!" BOX_BREAK UNSKIPPABLE "Você cuidou de nós, então estou orgulhoso \n"
"para lhe dar este " COLOR(RED) "leite" COLOR(DEFAULT) "! Você pode \n"
"guarde a garrafa para você."
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A estrada " COLOR(RED) "está fechada " COLOR(DEFAULT) "além disso\n"
"ponto!\n"
"Você não consegue ler a placa \n"
"lá?" BOX_BREAK "Eh? Ah, entendi. Você é apenas uma criança,\n"
"e você ainda não sabe ler. \n"
"Ha ha ha!"
)

DEFINE_MESSAGE(0x200F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu não quero isso!"
)

DEFINE_MESSAGE(0x2010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, isso é...\n"
"Este é certamente o \n da Princesa Zelda"
"caligrafia! Bem, vamos ver...\n"
"Hmmm... OK..." BOX_BREAK UNSKIPPABLE SHIFT("\x06") "\"" COLOR(RED) "Este é " NAME "...\n"
COLOR(DEFAULT) SHIFT("\x06") COLOR(PURPLE) "Ele está sob minhas ordens para salvar\n"
COLOR(DEFAULT) SHIFT("\x06") COLOR(RED) "Hyrule." COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "Wah ha ha ha hah!\n"
"Que tipo de jogo engraçado tem nosso\n"
"Princesa veio com agora?!" BOX_BREAK UNSKIPPABLE "OK, OK, tudo bem. Você pode ir \n"
"agora... Só tome cuidado, Sr. Herói!\n"
TEXT_SPEED("\x01") QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah!" QUICKTEXT_DISABLE TEXT_SPEED("\x00") EVENT
)

DEFINE_MESSAGE(0x2011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, Sr. Herói!\n"
"Obrigado por todo o seu trabalho duro!\n"
TEXT_SPEED("\x01") QUICKTEXT_ENABLE "Wah" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ha" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "hah" QUICKTEXT_DISABLE TEXT_SPEED("\x00") "!!"
)

DEFINE_MESSAGE(0x2012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau! Ótimo!\n"
"Seu tempo era " COLOR(RED) RACE_TIME COLOR(DEFAULT) "!\n"
"Você e Epona são ótimos\n"
"equipe!"
)

DEFINE_MESSAGE(0x2013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, que pena.\n"
"Se você tivesse algo para colocar,\n"
"Eu poderia dar um pouco para você..." EVENT
)

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu sou " COLOR(RED) "Ingo" COLOR(DEFAULT) "--Sr. Ingo para você.\n"
"Eu cuido desses cavalos.\n"
"Você está no meu caminho, então saia correndo,\n"
"miúdo!"
)

DEFINE_MESSAGE(0x2015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "A propósito, Sr. Herói..." BOX_BREAK UNSKIPPABLE "Se você for escalar \n"
"Monte da Morte, você deve equipar\n"
"a " COLOR(LIGHTBLUE) "escudo adequado" COLOR(DEFAULT) "! É um ativo\n"
"vulcão, afinal!" BOX_BREAK UNSKIPPABLE "Se você voltar para o Castelo de Hyrule\n"
"Mercado Municipal, você deve verificar\n"
"fora do Bazar. Eles vendem o\n"
"escudo que você precisa lá." BOX_BREAK UNSKIPPABLE "Diga a eles que eu enviei você e eles\n"
"deve dar-lhe um especial \n"
"desconto!" BOX_BREAK UNSKIPPABLE "Se você acha que está pronto para ir\n"
"já, não se preocupe com isso." BOX_BREAK UNSKIPPABLE "Agora, gostaria de pedir um favor a \n"
"você. Não, eu não espero que você faça\n"
"só por causa da ótima dica que eu\n"
"só te dei! Só estou pedindo!" BOX_BREAK UNSKIPPABLE "Você já esteve no " COLOR(RED) "Feliz\n"
"Oficina de Máscaras" COLOR(DEFAULT) " que acabou de abrir em\n"
"o Mercado da Cidade do Castelo de Hyrule?\n"
"Todo mundo está falando sobre isso!" BOX_BREAK UNSKIPPABLE "Meu garotinho me incomoda por um \n"
"máscara popular, mas não tenho\n"
"hora de ir lá..." BOX_BREAK UNSKIPPABLE "Então, você poderia ir buscar o\n"
"mascare para mim na próxima vez que estiver em\n"
"o Mercado? Se você não quiser\n"
"tudo bem, mas..." BOX_BREAK UNSKIPPABLE "Bem, não tenho escolha, este é meu \n"
"trabalho..." BOX_BREAK UNSKIPPABLE  SHIFT("\x4B") "...suspiro..." EVENT
)

DEFINE_MESSAGE(0x2016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gostaria de poder ir para a máscara " COLOR(RED) "\n"
"loja " COLOR(DEFAULT) "na cidade para comprar um presente para\n"
"meu filho..." BOX_BREAK SHIFT("\x4B") "...suspiro..."
)

DEFINE_MESSAGE(0x2017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ah, não... Ele não está respirando..."
)

DEFINE_MESSAGE(0x2018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!?"
)

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x29") "Arrrrgh!" QUICKTEXT_DISABLE "Eu a perdi!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x32") "Você, aí! \n"
SHIFT("\x3C") QUICKTEXT_ENABLE "Criança!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x3A") TEXT_SPEED("\x0A") QUICKTEXT_ENABLE "Heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1C") "Você quer um pedaço de mim?!\n"
SHIFT("\x3E") "Muito engraçado!\n"
SHIFT("\x2A") "Gosto da sua atitude!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x2B") "Tolo patético!" QUICKTEXT_DISABLE "\n"
SHIFT("\x14") "Você percebe quem você é\n"
SHIFT("\x39") "lidando com?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x34") "Eu sou " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE SHIFT("\x0A") "E em breve, governarei o mundo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x0D") "Você deve ter visto o branco\n"
SHIFT("\x12") "cavalo a galope passado agora...\n"
SHIFT("\x23") "Para que lado foi?!\n"
SHIFT("\x3D") QUICKTEXT_ENABLE "Responda-me!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tsk tsk...Quando chegar a sua hora\n"
"Levante-se, eu vou te expulsar daqui."
)

DEFINE_MESSAGE(0x2020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu menino vai ficar muito feliz com \n"
"isso! Você realmente é o Sr. Herói!\n"
"O que ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x48\x07") "Você vendeu a máscara de 10 rúpias por \n"
COLOR(RED) "15 Rupees" COLOR(DEFAULT) ". Você ganhou um pouco\n"
"lucro." BOX_BREAK UNSKIPPABLE "Vamos à Loja de Máscaras e\n"
"pagar o preço da máscara de \n"
COLOR(RED) "10 rúpias" COLOR(DEFAULT) "." EVENT
)

DEFINE_MESSAGE(0x2022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Crianças não podem ir no \n"
"\"" COLOR(RED) "Covardia de tirar o fôlego\n"
"Tour" COLOR(DEFAULT) "\" descrito na placa." BOX_BREAK "Já que não posso fazer isso, estou apenas \n"
"imitando Dampé o coveiro \n"
"dia todo." BOX_BREAK "Mas com meu rostinho fofo, não sou\n"
"coração batendo em tudo, estou?"
)

DEFINE_MESSAGE(0x2023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gyaah!" QUICKTEXT_DISABLE "É Dampé o \n"
"coveiro!" BOX_BREAK SHIFT("\x57") "???" BOX_BREAK "Ah, é apenas uma máscara. Eu recebo um \n"
"tipo diferente de susto desse\n"
"máscara do que recebo de Dampé..." BOX_BREAK "Você me dá essa máscara?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"De jeito nenhum" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu realmente tenho algum dinheiro, você\n"
"conhecer."
)

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei! O tempo acabou, rapaz!\n"
"Você só pagou 10 rúpias!\n"
"Você já brincou o suficiente!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Com esta máscara, serei como \n"
"Dampe! \n"
"Aqui está o meu dinheiro!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x48\x07") "Você vendeu a máscara de 30 rúpias para um\n"
"garoto pelo preço cheio?! \n"
"E ele não se importou de pagar nada!" BOX_BREAK UNSKIPPABLE "Vamos voltar para a loja de máscaras para\n"
"pague " COLOR(RED) "30 Rupees " COLOR(DEFAULT) "pela máscara. \n"
"Você pode obter a nova máscara \n"
"modelo também."
)

DEFINE_MESSAGE(0x2028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vou cavar e cavar! \n"
"Assim como Dampé!!"
)

DEFINE_MESSAGE(0x2029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nos velhos tempos, ouvi dizer que havia \n"
"muitos coelhos selvagens na terra \n"
"de Hyrule. Mas não mais, \n"
"por causa da caça excessiva." BOX_BREAK "Quero me tornar um coelho...\n"
"Ouça o vento com \n"
"essas orelhas, saltam pelo chão\n"
"com essas pernas..." BOX_BREAK "Mesmo que eu possa apenas fingir."
)

DEFINE_MESSAGE(0x202A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aposto com essas orelhas compridas que você \n"
"pode ouvir as vozes... \n"
"Ah, estes são coelhos genuínos\n"
"orelhas do animal da lenda!" TEXTID("\x20\x2B")
)

DEFINE_MESSAGE(0x202B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não importa o quão caro seja!\n"
"Por favor, venda para mim!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"De jeito nenhum" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x202C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa não é a resposta que eu queria \n"
"ouvir!"
)

DEFINE_MESSAGE(0x202D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu sonho de longa data! Voltando para\n"
"a vida selvagem! Finalmente, o ator, \n"
"palco e suporte foram unidos!" EVENT
)

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x48\x07") "É uma máscara de 50 rúpias, mas ele pagou\n"
"você tem uma quantia louca de dinheiro para\n"
"it--mais dinheiro do que você pode \n"
"contar!" BOX_BREAK UNSKIPPABLE "Volte para a Loja de Máscaras e \n"
"pague apenas " COLOR(RED) "50 Rupees " COLOR(DEFAULT) "deste\n"
"dinheiro."
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x0E") "Então, você acha que pode proteger\n"
SHIFT("\x36") "eles de mim...\n"
SHIFT("\x28") "Você tem coragem, garoto."
)

DEFINE_MESSAGE(0x2030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Existem algumas pessoas em Kakariko\n"
"espalhar boatos de que eu trapaceei\n"
"Talon fora do rancho, mas..." BOX_BREAK UNSKIPPABLE SHIFT("\x2D") "Não seja " QUICKTEXT_ENABLE "ridículo!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Aquele tal do Talon era fraco!\n"
"Eu, o trabalhador " COLOR(RED) "Ingo" COLOR(DEFAULT) ", derramado \n"
"muita energia para este lugar!" BOX_BREAK UNSKIPPABLE "Não quero estranhos como\n"
"você está dizendo alguma coisa ruim sobre mim!" BOX_BREAK UNSKIPPABLE "Ouça. O " COLOR(RED) "grande Ganondorf\n"
COLOR(DEFAULT) "reconheci meus talentos óbvios e\n"
"deu o rancho para mim!" BOX_BREAK UNSKIPPABLE "Vou criar um belo cavalo e\n"
"ganhar o reconhecimento do grande \n"
"Ganondorf!" BOX_BREAK UNSKIPPABLE "Diga, rapaz, você quer\n"
"montar um dos meus belos cavalos?" TEXTID("\x20\x31")
)

DEFINE_MESSAGE(0x2031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pague-me " COLOR(RED) "10 Rupees " COLOR(DEFAULT) "e você pode \n"
"passeio.\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Passeio\n"
"Não ande" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem então, scram \n"
"seu pequeno punk!"
)

DEFINE_MESSAGE(0x2033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem o suficiente!\n"
"Salve sua alteração e \n"
"volte novamente!"
)

DEFINE_MESSAGE(0x2034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você quer saber como andar de bicicleta?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Ouvir\n"
"Não escute" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aproxime-se do cavalo silenciosamente e \n"
"fique ao seu lado. Pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para \n"
"montar". BOX_BREAK "Use o " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "para executá-lo. \n"
"Assim que começar a rodar, pressione\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " para bater com o chicote. \n"
"Vai acelerar!" BOX_BREAK "Quando você quiser pular um\n"
"cercar, acelerar e acertar\n"
"de cabeça erguida!" BOX_BREAK "Se você tentar pular uma cerca \n"
"em um ângulo, o cavalo não vai gostar\n"
"ele, e ele não vai pular." BOX_BREAK "Depois que o cavalo chega a um \n"
"parada completa, pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para \n"
"desmontar. Agora, divirta-se!" EVENT
)

DEFINE_MESSAGE(0x2036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você usar " COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", você pode \n"
"fale comigo a cavalo." BOX_BREAK "Você está pronto para ir para casa então \n"
"em breve?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Não, eu quero viajar.\n"
"Sim, eu terminei." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando quiser desmontar, pare \n"
"e pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Ei, jovem!\n"
"Eu te conheço? Eu me senti como \n"
"embora eu tenha visto você\n"
"em algum lugar antes..." TEXTID("\x20\x36")
)

DEFINE_MESSAGE(0x2038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está melhorando!\n"
"Que tal uma corrida comigo?\n"
"Uma volta no curral com\n"
"aquele cavalo." BOX_BREAK "Vamos fazer uma pequena aposta, digamos\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Faça\n"
"Não faça isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ei... Qual é o problema?\n"
"Você não tem nem 50 rúpias?!\n"
"Não quero correr com alguém\n"
"muito pobre!"
)

DEFINE_MESSAGE(0x203A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SHIFT("\x39") "Sh-" QUICKTEXT_ENABLE "shoooot!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Se o grande Ganondorf descobrisse\n"
"sobre essa humilhação...\n"
"Ei, você! Que tal outro\n"
"corrida! Se você vencer..." BOX_BREAK UNSKIPPABLE "Você pode ficar com... o cavalo!!" EVENT
)

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que há com esse cavalo?!\n"
"Isso é " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Como você domou aquele cavalo selvagem\n"
"bem debaixo do meu nariz?!" BOX_BREAK UNSKIPPABLE "Eu ia apresentar aquele cavalo\n"
"para o grande Ganondorf... Mas eu aposto\n"
"lo na corrida e perdeu! Shooot!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x36") "Hah ha hah!" BOX_BREAK UNSKIPPABLE "Como prometi, darei o \n"
"cavalo para você..." BOX_BREAK UNSKIPPABLE SHIFT("\x0A") "No entanto..." BOX_BREAK UNSKIPPABLE "Eu nunca vou deixar você sair deste rancho!" EVENT
)

DEFINE_MESSAGE(0x203D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee... Que pena para você!\n"
"Eu recebo suas 50 rúpias." EVENT
)

DEFINE_MESSAGE(0x203E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau ha ha!\n"
"Afinal, você é apenas uma criança!\n"
"Bem, volte a qualquer momento e nós\n"
"divirta-se mais..."
)

DEFINE_MESSAGE(0x203F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O quê? O que você está fazendo \n"
"andando por aqui?\n"
"Seu pequeno esquisito!" BOX_BREAK UNSKIPPABLE "Sou " COLOR(RED) "Ingo " COLOR(DEFAULT) "e me importo com o rancho." BOX_BREAK UNSKIPPABLE "Tenho trabalhado neste rancho \n"
"por muito tempo para aquele preguiçoso\n"
"vagabundo, Talon." BOX_BREAK UNSKIPPABLE "Hoje, por exemplo, ele se foi\n"
"em algum lugar para uma entrega e ele \n"
"ainda não voltou!" BOX_BREAK UNSKIPPABLE "Então, estou fazendo todo o trabalho\n"
"aqui." TEXTID("\x20\x40")
)

DEFINE_MESSAGE(0x2040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, bem... é difícil ser um\n"
"homem trabalhador."
)

DEFINE_MESSAGE(0x2041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, suas roupas! Elas são...\n"
"diferente...\n"
"Você não é daqui, \n"
"és tu?" BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x02") "........." TEXT_SPEED("\x00") "........" BOX_BREAK UNSKIPPABLE "Ah... Você é um menino fada de \n"
"a floresta! Meu nome é " COLOR(RED) "Malon" COLOR(DEFAULT) "!\n"
"Meu pai é dono do Rancho Lon Lon!" TEXTID("\x20\x42")
)

DEFINE_MESSAGE(0x2042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Papai foi ao castelo para entregar\n"
"um pouco de leite, e ele não veio\n"
"de volta ainda..."
)

DEFINE_MESSAGE(0x2043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você vai ao castelo,\n"
"menino fada?\n"
"Você se importaria de encontrar meu " COLOR(RED) "pai" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE SFX("\x68\x6D") "Ele deve ter adormecido \n"
"em algum lugar ao redor do castelo. \n"
"Que coisa para um adulto fazer!\n"
"Tê-te!" BOX_BREAK UNSKIPPABLE "Ah, sim, se você procurar por ele, eu \n"
"dar isso para você." BOX_BREAK UNSKIPPABLE "Estive incubando isso\n"
"ovo com muito cuidado...\n"
"Tê-te!" EVENT
)

DEFINE_MESSAGE(0x2044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Defina o ovo para " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " para incubar.\n"
"Ei, ei!" BOX_BREAK "Meu pai é muito problemático,\n"
"para um adulto, não é?!\n"
"Ei, ei!"
)

DEFINE_MESSAGE(0x2045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não acredito que eu, o grande\n"
COLOR(RED) "Ingo" COLOR(DEFAULT) ", estou trabalhando neste dump de\n"
"um rancho!" BOX_BREAK UNSKIPPABLE "Como o dono é muito preguiçoso, eu\n"
"sempre tem que fazer todo o trabalho \n"
"por aqui!" TEXTID("\x20\x46")
)

DEFINE_MESSAGE(0x2046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu, o trabalhador " COLOR(RED) "Ingo" COLOR(DEFAULT) ", deveria ser \n"
"no comando, não aquele vagabundo preguiçoso, \n"
"Talão!"
)

DEFINE_MESSAGE(0x2047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, é o menino fada de novo!" BOX_BREAK UNSKIPPABLE "Ouvi dizer que você encontrou meu pai!\n"
"Gostou do castelo? Gostou\n"
"você vê a princesa? Hee hee!" BOX_BREAK UNSKIPPABLE SFX("\x68\x6D") "Papai chegou em casa com pressa depois\n"
"você o encontrou. Hee hee!" BOX_BREAK UNSKIPPABLE "Ah, sim, tenho que te apresentar\n"
"para meu amigo, menino fada!" BOX_BREAK UNSKIPPABLE "Ela é este cavalo. O nome dela é\n"
COLOR(RED) "Epona" COLOR(DEFAULT) ". Ela não é fofa?"
)

DEFINE_MESSAGE(0x2048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que Epona tem medo de \n"
"você, menino fada..."
)

DEFINE_MESSAGE(0x2049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Minha mãe compôs essa música. \n"
"Não é legal? Vamos cantar juntos."
)

DEFINE_MESSAGE(0x204A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, Epona! Ela se afeiçoou a\n"
"você, menino fada."
)

DEFINE_MESSAGE(0x204B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "ZZZZZZZZZZZZZZZ" TEXT_SPEED("\x00") "..."
)

DEFINE_MESSAGE(0x204C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah... um visitante!\n"
"Faz muito tempo desde que nós\n"
"teve uma visita aqui...\n"
"De onde você veio?" BOX_BREAK "Desde que Ganondorf chegou, as pessoas entraram\n"
"a Cidade do Castelo se foi, lugares\n"
"foram arruinados, e monstros\n"
"estão vagando por toda parte." BOX_BREAK "O Sr. Ingo está apenas usando o rancho\n"
"para ganhar o favor de Ganondorf..." BOX_BREAK "Todo mundo parece estar se tornando mau..." BOX_BREAK "Mas papai...\n"
"Ele foi expulso do rancho\n"
"pelo Sr. Ingo..." BOX_BREAK "Se eu desobedecer ao Sr. Ingo, ele irá tratar\n"
"os cavalos tão mal..." BOX_BREAK "Então...\n"
"Não há nada que eu possa fazer..."
)

DEFINE_MESSAGE(0x204D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aposto que ninguém é mais rápido que eu \n"
"agora! Mas não sei se \n"
"deveria estar feliz ou triste..."
)

DEFINE_MESSAGE(0x204E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
TEXT_SPEED("\x02") "ZZZZZZZZZZZZZ" TEXT_SPEED("\x00") "...\n"
"P-pare essa música... eu... eu...\n"
"Resmungar... resmungar..."
)

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Dê uma boa olhada nisso \n"
"montanha. Isso é " COLOR(RED) "Death Mountain" COLOR(DEFAULT) ",\n"
"casa dos Gorons. Eles mantêm\n"
"a Pedra Espiritual do Fogo".
)

DEFINE_MESSAGE(0x2050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, mantenha isso em segredo de \n"
"Sr. Ingo que eu canto essa música..."
)

DEFINE_MESSAGE(0x2051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você...\n"
"Você conhece minha " COLOR(RED) "música da mãe" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Todo mundo gostou muito dessa música...\n"
"Meu pai... Até o Sr. Ingo..." BOX_BREAK UNSKIPPABLE "Mas... desde que Ganondorf apareceu,\n"
"O Sr. Ingo mudou completamente." BOX_BREAK UNSKIPPABLE "Eu me lembro dos bons velhos tempos\n"
"apenas enquanto eu canto a música. Também..." TEXTID("\x20\x52")
)

DEFINE_MESSAGE(0x2052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(RED) "Epona" COLOR(DEFAULT) " gostei muito dessa música...\n"
"Só eu poderia domar aquele cavalo...\n"
"Até o Sr. Ingo teve dificuldade..." BOX_BREAK "Hee hee hee!"
)

DEFINE_MESSAGE(0x2053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"O olhar caolho desta estátua \n"
"penetra em sua mente..."
)

DEFINE_MESSAGE(0x2054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Respondendo à sua máscara, isso \n"
"estátua de pedra estranha fala com \n"
"você..." BOX_BREAK "Eu ouvi isso..."
)

DEFINE_MESSAGE(0x2055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vou virar a página \n"
"e trabalhar muito duro a partir de agora."
)

DEFINE_MESSAGE(0x2056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sr. Ingo... Ele deve ter sido \n"
"tentado por poderes malignos.\n"
"Ele não é realmente uma pessoa ruim \n"
"de forma alguma..."
)

DEFINE_MESSAGE(0x2057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"ZZZZZZZZ...\n"
"Resmungar... Não é fácil\n"
"seja um trabalhador..."
)

DEFINE_MESSAGE(0x2058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Faz um tempo...\n"
"Você quer correr?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você mudar de ideia,\n"
"volte quando quiser!"
)

DEFINE_MESSAGE(0x205A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem então! Scram,\n"
"seu pequeno punk!" EVENT
)

DEFINE_MESSAGE(0x205B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh... Você está bravo porque \n"
"você perdeu? Se você está chateado assim,\n"
"que tal outra corrida?" BOX_BREAK "Apostar " COLOR(RED) "50 Rupees " COLOR(DEFAULT) "e correr de novo?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Corrida\n"
"Não corra" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito obrigado. Heh heh!" EVENT
)

DEFINE_MESSAGE(0x205D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu te der mais gratuitamente,\n"
"Ingo vai ficar bravo comigo. Então eu\n"
"melhor vendê-lo para você por\n"
"preço normal."
)

DEFINE_MESSAGE(0x205E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer comprar leite por " COLOR(RED) "30 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x205F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá, tudo bem?\n"
"Eu sou Ingo. Me sinto muito honrado\n"
"ter permissão para trabalhar aqui."
)

DEFINE_MESSAGE(0x2060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Seu bravo rapaz...\n"
"Devemos proteger esta linda\n"
"terra de Hyrule!"
)

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah, ocarina fofa!\n"
"Você vai tocar esta música\n"
"com aquela ocarina?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No sopé da Montanha da Morte\n"
"você encontrará minha vila," COLOR(RED) "Kakariko" COLOR(DEFAULT) ".\n"
"Foi onde nasci e \n"
"criado." BOX_BREAK UNSKIPPABLE "Você deveria falar com alguns dos\n"
"aldeões lá antes de você subir\n"
"Montanha da Morte."
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A música que acabei de ensinar a você tem\n"
"algum poder misterioso. Apenas \n"
"Membros da família real são permitidos\n"
"aprender esta canção." BOX_BREAK UNSKIPPABLE "Lembre-se, isso ajudará a provar\n"
"sua conexão com o Royal \n"
"Família." BOX_BREAK UNSKIPPABLE "A princesa está esperando por você para \n"
"retorne ao castelo com o\n"
"pedras. Tudo bem. Estamos contando\n"
"em você!"
)

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Hoo hoot!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Olhe para cima aqui!" BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "Parece que chegou a hora \n"
"finalmente vim para você começar seu \n"
"aventura!" BOX_BREAK UNSKIPPABLE "Você encontrará muitas dificuldades\n"
"à frente... Esse é o seu destino. Não \n"
"sentir-se desanimado, mesmo durante o\n"
"tempos mais difíceis!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vá direto por aqui e você vai\n"
"veja " COLOR(RED) "Hyrule Castle" COLOR(DEFAULT) "." BOX_BREAK "Você conhecerá uma princesa " COLOR(RED) "" COLOR(DEFAULT) "lá..." BOX_BREAK "Se você está perdido e não sabe \n"
"que caminho seguir, olhe para o \n"
COLOR(RED) "Mapa" COLOR(DEFAULT) "." BOX_BREAK "As áreas que você explorou serão \n"
"ser mostrado no Mapa. Pressione \n"
COLOR(RED) "INICIAR " COLOR(DEFAULT) "para entrar nas Subtelas\n"
"e " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para encontrar o Mapa." BOX_BREAK "Na " COLOR(RED) "Map Subtela" COLOR(DEFAULT) ", você irá\n"
"veja também um " COLOR(RED) "ponto piscando" COLOR(DEFAULT) " mostrando\n"
"você que caminho você deve ir em seguida." TEXTID("\x20\x66")
)

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você conseguiu tudo isso?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Não\n"
"Sim" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tudo bem então, vejo você por aí!\n"
"Hot hoot hoo!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, " NAME "! Por aqui!" BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "A princesa está dentro do castelo \n"
"à frente. Tenha cuidado para não obter \n"
"pego pelos guardas!\n"
"Ho ho ho hoo!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Neste terreno, o tempo flui \n"
"normalmente." BOX_BREAK "Mas o tempo pára enquanto você\n"
"estão em Lon Lon Ranch ou em uma cidade." BOX_BREAK "Se você quiser que o tempo passe normalmente,\n"
"você vai precisar sair da cidade." BOX_BREAK "Bem, bem, para que lado você está \n"
"vai ir agora?\n"
"Hoo hoo hoo!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer ouvir o que eu disse \n"
"de novo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoooo. Você é uma criança esperta.\n"
"Boa sorte, então. Hoo hoo."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, " NAME "! \n"
"Espere um segundo, amigo!" BOX_BREAK "Além deste ponto você encontrará \n"
COLOR(RED) "Vila Kakariko" COLOR(DEFAULT) ". Você viu \n"
"a Princesa de Hyrule? Se não, \n"
"Eu sugiro que você vá ao castelo." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, " NAME "! \n"
"Olhe aqui!" BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "Além deste ponto você encontrará\n"
COLOR(RED) "Vila Kakariko" COLOR(DEFAULT) ". Cuidado!\n"
"Hot hoo!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE ", você é o único\n"
"alguém que pode completar a missão\n"
"à frente!\n"
"Você deve fazer o seu melhor! Hoo!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "! Espere, amigo!\n"
"Hoo-hoo!" BOX_BREAK_DELAYED("\x28") "Vá para o sul daqui para chegar\n"
COLOR(RED) "Águas cheias e ricas" do "Lago Hylia" COLOR(DEFAULT) ". BOX_BREAK "Se você for para o oeste, encontrará \n"
COLOR(RED) "Vale do Gerudo" COLOR(DEFAULT) ". Há um esconderijo\n"
"de um bando de ladrões do outro\n"
"lado do vale". BOX_BREAK "Bem, você pode ir a qualquer lugar\n"
"você quer!\n"
"Ho ho ho...hoo!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não importa o quão difícil seja, apenas\n"
"não desanime. Ho Ho Hoo!"
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Além deste ponto fica o Lago Hylia.\n"
"Está cheio de águas profundas e puras." BOX_BREAK_DELAYED("\x28") "Os " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", que vivem todos os \n"
"a montante, guarde o afundado\n"
"templo no fundo do lago, como \n"
"bem como a Fonte de Zora." BOX_BREAK "Se você deseja confirmar sua localização \n"
"no mapa, pressione " COLOR(RED) "START" COLOR(DEFAULT) "para \n"
"mudar para as Subtelas e " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"ou " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " para encontrar o Mapa." BOX_BREAK "Todos os lugares que você visitou \n"
"será mostrado no mapa. \n"
"Ho hoo hoo!" EVENT
)

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK, tome cuidado e vá!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Qual é o seu nome?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") BOX_BREAK UNSKIPPABLE COLOR(ADJUSTABLE) NAME COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Estranho... . \n"
"familiar." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "OK então, " NAME "..." BOX_BREAK UNSKIPPABLE "Vou contar o segredo de\n"
"o Reino Sagrado que foi\n"
"transmitido pela Família Real\n"
"de Hyrule." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x26") "A Ocarina do Tempo!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você entendeu bem a história\n"
"Acabei de te contar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eu estava espiando por esta janela\n"
"agora..." BOX_BREAK UNSKIPPABLE "O outro elemento do meu\n"
"sonho... a " COLOR(BLUE) "nuvens escuras" COLOR(DEFAULT) "...\n"
"Acredito que eles simbolizam...\n"
"aquele homem aí!" BOX_BREAK "Você vai olhar pela janela\n"
"para ele?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Sim." BOX_BREAK UNSKIPPABLE "Contei ao meu pai sobre meu sonho..." BOX_BREAK UNSKIPPABLE "No entanto, ele não acreditou que era\n"
"uma profecia..." BOX_BREAK UNSKIPPABLE "Mas...eu posso sentir a maldade daquele homem\n"
"intenções!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que Ganondorf procura deve ser \n"
"nada menos que a " COLOR(RED) "Triforce \n"
COLOR(DEFAULT) "do Reino Sagrado." BOX_BREAK UNSKIPPABLE "Ele deve ter vindo para Hyrule para\n"
"obtenha-o!" BOX_BREAK UNSKIPPABLE "E ele quer conquistar Hyrule...\n"
"não, o mundo inteiro!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "...agora, nós somos o \n"
"apenas aqueles que podem proteger Hyrule!" EVENT
)

DEFINE_MESSAGE(0x207C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Não devemos deixar Ganondorf ficar\n"
"a Triforce!" BOX_BREAK UNSKIPPABLE "Eu protegerei a " COLOR(LIGHTBLUE) "Ocarina of Time\n"
COLOR(DEFAULT) "com todo o meu poder! \n"
"Ele não deve tê-lo!" BOX_BREAK UNSKIPPABLE "Você vai encontrar os outros " COLOR(RED) "dois\n"
"Pedras Espirituais" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Vamos pegar a Triforce antes\n"
"Ganondorf faz, e depois derrota \n"
"ele!" EVENT
)

DEFINE_MESSAGE(0x207D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Mais uma coisa...\n"
"Pegue esta " COLOR(RED) "carta" COLOR(DEFAULT) "...\n"
"Tenho certeza de que será útil para você." EVENT
)

DEFINE_MESSAGE(0x207E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Resmungar... resmungar...\n"
"Huh? Eu já estou acordado!" BOX_BREAK UNSKIPPABLE "O quê?" BOX_BREAK UNSKIPPABLE "Bem, eu vou! Se não for a floresta\n"
"garoto do outro dia!\n"
"A propósito, muito obrigado por\n"
"me acordando!" BOX_BREAK UNSKIPPABLE "Demorou um pouco, mas finalmente \n"
"Colocou Malon de bom humor de volta." BOX_BREAK UNSKIPPABLE "Então, o que você vai fazer hoje?\n"
"Tem algum tempo livre em suas mãos\n"
"você diz?\n"
"Bem, que tal um joguinho?" BOX_BREAK UNSKIPPABLE "Esses três Cuccos eu tenho aqui\n"
"são especiais" COLOR(RED) "Super Cuccos" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Vou jogar esses Cuccos\n"
"naquele bando de normal\n"
"Cucos." BOX_BREAK UNSKIPPABLE "Se você puder escolher esses três \n"
"pássaros especiais dentre os\n"
"Cuccos normais dentro do tempo \n"
"limite, eu vou te dar " COLOR(RED) "algo bom" COLOR(DEFAULT) "." BOX_BREAK "Se você não conseguir encontrá-los, eu ganho.\n"
"São 10 rúpias... Quer jogar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x207F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Resmungar... resmungar...\n"
"Estou de pé! Estou de pé!" BOX_BREAK "O quê?" BOX_BREAK "Ei, garoto da floresta!\n"
"Tem algum tempo livre?\n"
"Então vamos jogar!" BOX_BREAK "Vou jogar esses três\n"
COLOR(RED) "Super Cuccos " COLOR(DEFAULT) "nesse grupo de\n"
"Cucos normais." BOX_BREAK "Se você puder escolher esses três \n"
"pássaros especiais dentre os\n"
"Cuccos normais dentro do tempo \n"
"limite, eu vou te dar " COLOR(RED) "algo bom" COLOR(DEFAULT) "." BOX_BREAK "Se você não conseguir encontrá-los, eu ganho.\n"
"São 10 rúpias... Quer jogar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem 30 segundos!\n"
"Tudo bem então, prepare-se.\n"
"Aqui vão os Super Cuccos!" BOX_BREAK SHIFT("\x30") "COMECE A PROCURAR!!" EVENT
)

DEFINE_MESSAGE(0x2081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Acabou o tempo!\n"
"Muito ruim!!" BOX_BREAK "Estes são ótimos Cuccos\n"
"não são!\n"
"Eles estão juntando dinheiro para mim!" BOX_BREAK "Voltem para mim, meus bebês!" EVENT
)

DEFINE_MESSAGE(0x2082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse é um deles!\n"
"Continue! Continue!\n"
COLOR(RED) "Mais dois" COLOR(DEFAULT) "para encontrar!" EVENT
)

DEFINE_MESSAGE(0x2083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem outro!\n"
"Tudo bem, agora, o momento de\n"
"verdade!" COLOR(RED) "Mais uma" COLOR(DEFAULT) " para encontrar!" EVENT
)

DEFINE_MESSAGE(0x2084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puxa! Que droga!\n"
"É ameixa incrível!" BOX_BREAK "Esse é o último!\n"
"Você encontrou todos eles!\n"
"Venha aqui!" EVENT
)

DEFINE_MESSAGE(0x2085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quer tentar de novo?" BOX_BREAK "Um jovem como você deve ter\n"
"um verdadeiro fogo na sua barriga!\n"
"Encontre três deles dentro de\n"
"30 segundos." BOX_BREAK "Tente novamente por 5 rúpias?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você!\n"
"Você tem talento para ser um dos\n"
"os melhores cowboys do mundo!" BOX_BREAK "Você gostaria de se casar com Malon?\n"
"Hein?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Haw haw! Eu estava apenas brincando! \n"
"Brincadeira! Acho que você é um pouco\n"
"jovem para isso, não é?\n"
"Ah, ah, ah!" BOX_BREAK UNSKIPPABLE "Ah...! Tenho orgulho de apresentar a\n"
"você é uma amostra do nosso" COLOR(RED) "Lon\n"
"Lon Milk" COLOR(DEFAULT) ". Você ficará energizado\n"
"no momento em que você bebe!" BOX_BREAK UNSKIPPABLE "Depois de beber, você pode \n"
"traga de volta a garrafa " COLOR(RED)" COLOR(DEFAULT) "e compre uma\n"
"recarregue, quando quiser!" EVENT
)

DEFINE_MESSAGE(0x2088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, parceiro, você tem um \n honesto"
"Rosto!" BOX_BREAK "Quando você crescer, por que não\n"
"venha trabalhar aqui, neste \n"
"rancho? Essa é uma oferta permanente!\n"
"Eu vou estar esperando por você." EVENT
)

DEFINE_MESSAGE(0x2089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aqui está! Pegue este super\n"
"fresco" COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "!" EVENT
)

DEFINE_MESSAGE(0x208A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aqui está! Tome um super\n"
"leite fresco..." BOX_BREAK "Ah? Que pena!!\n"
"Você não tem uma garrafa vazia,\n"
"você?"
)

DEFINE_MESSAGE(0x208B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Resmungar... resmungar...\n"
"Estou acordado!" BOX_BREAK "O quê?" BOX_BREAK "Ei, " NAME "!\n"
"Se você está procurando por Malon,\n"
"ela está lá fora. Você \n"
"vem aqui para jogar?" BOX_BREAK "Bem, então, que tal jogar o\n"
COLOR(RED) "Jogo de encontrar o Super Cucco" COLOR(DEFAULT) "comigo?\n"
"Ou você quer comprar alguns\n"
COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "?" BOX_BREAK "O que vai ser?\n"
THREE_CHOICE COLOR(ADJUSTABLE) "Lon Lon Milk - 30 Rupees\n"
"Jogo de encontrar cuco - 10 Rupees\n"
"Sair" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x208C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE COLOR(RED) "Você falhou!" COLOR(DEFAULT) "\n"
"Você tem que pular todos os\n"
"cercas!" QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x208D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE COLOR(RED) "Mais uma volta!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x14")
)

DEFINE_MESSAGE(0x208E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está se certificando de se aproximar\n"
"as cercas de frente? Se você \n"
"abordagem em ângulo, o cavalo\n"
"não vai pular!" BOX_BREAK "Se quiser tentar novamente, monte\n"
"Epona e prepare-se!"
)

DEFINE_MESSAGE(0x208F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você conseguiu!\n"
COLOR(RED) RACE_TIME COLOR(DEFAULT) "é o novo recorde do curso!" BOX_BREAK UNSKIPPABLE "Tenho que te dar um presente para\n"
"comemore seu novo recorde!" BOX_BREAK UNSKIPPABLE "O presente é um pouco pesado demais\n"
"para dar a você aqui, então eu vou ter\n"
"entregue em sua casa. Aposto que\n"
"Mal posso esperar para ver! Hee hee!"
)

DEFINE_MESSAGE(0x2090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O registro até agora é " COLOR(RED) "50 segundos" COLOR(DEFAULT) ".\n"
"Seu melhor tempo é " COLOR(RED) HIGHSCORE(HS_HORSE_RACE) COLOR(DEFAULT) "." BOX_BREAK "Se você conseguir bater o recorde, eu vou\n"
"te dar um presente.\n"
"Dê o seu melhor, ok?" BOX_BREAK "Vamos em frente!" EVENT
)

DEFINE_MESSAGE(0x2091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu melhor tempo é " COLOR(RED) HIGHSCORE(HS_HORSE_RACE) COLOR(DEFAULT) "!\n"
"Quão rápido você consegue ir?!\n"
"Vamos, vamos começar!" EVENT
)

DEFINE_MESSAGE(0x2092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O registro atual é " COLOR(RED) "50 segundos" COLOR(DEFAULT) ".\n"
"Primeiro, tente bater este recorde!" BOX_BREAK "Se você conseguir bater o recorde, eu vou\n"
"te dar um presente!\n"
"Dê o seu melhor, ok?" BOX_BREAK "Tudo bem, vamos começar!" EVENT
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
UNSKIPPABLE "Você não sabe o que ele quer dizer com\n"
"\"Irmãos juramentados,\" mas você \n"
"coletou duas Pedras Espirituais!\n"
"Você tem mais um para encontrar!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você não sabe o que ele quer dizer com\n"
"\"Irmãos juramentados,\" mas você \n"
"finalmente coletei as três Pedras!\n"
"Volte para ver a princesa Zelda!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu faço isso...\n"
"Trrrrade for " COLOR(RED) "claimmm checkkk" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu dou isso pra vcsss porrrr\n"
"uma lembrançarrrr."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto, eu gosto de você!" BOX_BREAK UNSKIPPABLE "Que tal você e eu nos tornamos\n"
"Irmãos juramentados?!" BOX_BREAK UNSKIPPABLE "Não, não há grande cerimônia\n"
"envolvido! Apenas tome isso como\n"
"símbolo da nossa amizade!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x30") "Você foi muito bem!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que tal um grande abraço Goron, \n"
"Irmão?!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x50") "Ah!" BOX_BREAK_DELAYED("\x1E") SHIFT("\x4B") "Oh-oh!" BOX_BREAK_DELAYED("\x28") SHIFT("\x4B") QUICKTEXT_ENABLE "Vamos!" QUICKTEXT_DISABLE BOX_BREAK_DELAYED("\x1E") SHIFT("\x14") "Vamos! Vamos!" QUICKTEXT_ENABLE "Vamos!" QUICKTEXT_DISABLE BOX_BREAK_DELAYED("\x28") SHIFT("\x50") QUICKTEXT_ENABLE "HOT!!" QUICKTEXT_DISABLE BOX_BREAK_DELAYED("\x1E") SHIFT("\x28") "Que batida gostosa!" BOX_BREAK_DELAYED("\x28") SHIFT("\x32") "WHOOOAH!" BOX_BREAK_DELAYED("\x28") SHIFT("\x3C") QUICKTEXT_ENABLE "YEEEEEEH!" QUICKTEXT_DISABLE BOX_BREAK_DELAYED("\x28") SHIFT("\x3C") QUICKTEXT_ENABLE "YAHOOO!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x3008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Sou um dos " COLOR(RED) "Gorons" COLOR(DEFAULT) ",\n"
"as pessoas comedoras de pedras que vivem\n"
"na Montanha da Morte." BOX_BREAK UNSKIPPABLE "Olhe para aquele pedregulho enorme\n"
"lá!" BOX_BREAK UNSKIPPABLE "Bloqueia a entrada do\n"
COLOR(RED) "Caverna do Dodongo" COLOR(DEFAULT) ", que já foi\n"
"um lugar muito importante para nós\n"
"Gorons..." BOX_BREAK UNSKIPPABLE "Mas um dia, muitos Dodongos\n"
"apareceu de repente dentro do \n"
"caverna. Tornou-se muito \n"
"lugar perigoso!" BOX_BREAK UNSKIPPABLE "Além disso, um " COLOR(RED) "Gerudo em preto\n"
"armadura " COLOR(DEFAULT) "usou sua magia para selar a\n"
"entrada com aquela pedra!" TEXTID("\x30\x2A")
)

DEFINE_MESSAGE(0x3009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gostaria de poder rolar para baixo o \n"
"montanha como uma rocha, com um\n"
COLOR(RED) "Flor bomba " COLOR(DEFAULT) "e..." BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x3C") COLOR(RED) "BOOOOOOM!" COLOR(DEFAULT) QUICKTEXT_DISABLE BOX_BREAK "Se eu pudesse fazer isso com uma bomba \n"
"Flor, eu poderia me tornar um homem de verdade."
)

DEFINE_MESSAGE(0x300A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou aqui para sombrear o\n"
COLOR(RED) "Flores Bomba" COLOR(DEFAULT) "do sol." BOX_BREAK "Você tem uma pergunta para mim?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Pergunte sobre Flores Bomba\n"
"Pergunte sobre a Caverna do Dodongo" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x300B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquelas plantas crescendo ali \n"
"são " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ". Eles são\n"
"\"plantas mineiras\" que crescem apenas em\n"
"esta montanha." BOX_BREAK "O fruto da flor é o cru \n"
"material para bombas". BOX_BREAK "Mas um amador não Goron deve \n"
"nunca colha as Flores Bomb' \n"
"fruta!" BOX_BREAK "Eles geralmente crescem apenas no escuro \n"
"lugares, então Bomb Flores que crescem\n"
"em um lugar como este são extremamente\n"
"cru."
)

DEFINE_MESSAGE(0x300C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquelas plantas crescendo ali \n"
"são " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ". Eles são\n"
"\"plantas mineiras\" que crescem apenas em\n"
"esta montanha." BOX_BREAK "Eles geralmente crescem apenas no escuro \n"
"lugares, como cavernas, então Bomb \n"
"Flores que crescem em um lugar como\n"
"isso são extremamente raros." BOX_BREAK "Se você tiver a " COLOR(RED) "Pulseira do Goron" COLOR(DEFAULT) ",\n"
"até uma criança como você poderia\n"
"escolha-o facilmente com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x300D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu a caverna no seu \n"
"Aqui? Essa é a " COLOR(RED) "Dodongo's \n"
"Caverna" COLOR(DEFAULT) "." BOX_BREAK "Porque a luz interna é muito \n"
"dim, o " COLOR(RED) "Bomb Flowers" COLOR(DEFAULT) ", uma planta \n"
"único nesta montanha, cresça como\n"
"louco aí!"
)

DEFINE_MESSAGE(0x300E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah?" BOX_BREAK UNSKIPPABLE "Não recebemos muitos visitantes\n"
"Aqui em cima. De onde você é?" BOX_BREAK UNSKIPPABLE "A floresta?" BOX_BREAK UNSKIPPABLE "O que é uma \"floresta\"?" BOX_BREAK UNSKIPPABLE "Eh?" BOX_BREAK UNSKIPPABLE "É onde muitas \"árvores\" e \n"
"\"plantas crescem?" BOX_BREAK UNSKIPPABLE "Agora estou ainda mais confuso! \n"
"Nada cresce por aqui além de\n"
"a " COLOR(RED) "Flores da Bomba" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Não temos \"sementes\" ou \"nozes\"\n"
"por aqui também." BOX_BREAK UNSKIPPABLE "Até os Deku Sticks são muito escassos\n"
"por aqui!" TEXTID("\x30\x22")
)

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu fechei a entrada porque eu\n"
"não tem muita mercadoria para\n"
"vender. Mas você é bastante persistente\n"
"cliente, não é você." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Desculpe...\n"
"Essa bomba é apenas para exibição. \n"
"Estou " COLOR(RED) "esgotado" COLOR(DEFAULT) "dos reais." EVENT
)

DEFINE_MESSAGE(0x3011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por que você me parou?\n"
"Não me pare aqui!" BOX_BREAK "Você não pode parar minha corrida selvagem!" BOX_BREAK "Este rolamento selvagem é a única maneira\n"
"para aliviar o meu stress!" BOX_BREAK "Agora fique maravilhado com meu selvagem, selvagem\n"
"rolando!!"
)

DEFINE_MESSAGE(0x3012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Tudo bem! Vou te dar isso\n"
"em louvor de sua coragem!" EVENT
)

DEFINE_MESSAGE(0x3013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado! Deixe-me expressar minha alegria\n"
"com mais rolamento selvagem!"
)

DEFINE_MESSAGE(0x3014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SHIFT("\x21") "Ah... estou com tanta fome..." BOX_BREAK UNSKIPPABLE "Todo mundo se sente fraco de fome\n"
"por causa da escassez de alimentos em \n"
"esta cidade. Estamos em perigo de \n"
"extinção!" BOX_BREAK UNSKIPPABLE "É tudo porque não podemos entrar\n"
"nossa pedreira, a " COLOR(RED) "Dodongo's Cavern" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Nós Gorons vivemos com uma dieta de \n"
"pedras..." BOX_BREAK UNSKIPPABLE "E o mais delicioso e \n"
"rochas nutritivas ao redor são encontradas \n"
"na Caverna do Dodongo! Mas isso \n"
"parece história antiga agora..." BOX_BREAK UNSKIPPABLE "Nós nos tornamos tão gourmets que \n"
"não aguentamos comer pedras de\n"
"qualquer outro lugar!" TEXTID("\x30\x15")
)

DEFINE_MESSAGE(0x3015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Suspiro... quero comer o topo\n"
"pedras do lombo do " COLOR(RED) "Dodongo's \n"
"Caverna" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei!" BOX_BREAK UNSKIPPABLE "É perigoso para uma criança como\n"
"você venha aqui. Você pode \n"
"cair!" BOX_BREAK UNSKIPPABLE "Se não me engano, você se assumiu\n"
"aqui para comer a " COLOR(RED) "pedra vermelha" COLOR(DEFAULT) "!\n"
"Bem, que pena! Não está aqui!" BOX_BREAK UNSKIPPABLE "O quê? Não é por isso que você está\n"
"aqui?" BOX_BREAK UNSKIPPABLE "Você está procurando um \"Espiritual\n"
"Pedra?\" Você deve estar querendo dizer que \n"
"pedra vermelha deliciosa\n"
"que já foi exibido aqui!" BOX_BREAK UNSKIPPABLE "Estava com tanta fome que pensei\n"
"não há problema em dar apenas um\n"
"pequena lambida... então eu fugi\n"
"aqui. Mas, já tinha sumido!" BOX_BREAK UNSKIPPABLE "Acho que o Big Brother o tirou." BOX_BREAK UNSKIPPABLE "Ele sempre diz que todo mundo\n"
"está atrás daquela pedra vermelha!" TEXTID("\x30\x17")
)

DEFINE_MESSAGE(0x3017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Big Brother se trancou em\n"
"seu quarto dizendo,\n"
"\"" COLOR(RED) "Vou esperar aqui pelo \n"
"Mensageiro da Família Real!" COLOR(DEFAULT) "\""
)

DEFINE_MESSAGE(0x3018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estou com tanta fome que não consigo pensar\n"
"sobre tudo menos comida!" BOX_BREAK UNSKIPPABLE "Pergunte ao Big Brother sobre complicado\n"
"coisas." BOX_BREAK UNSKIPPABLE "Se ele estiver de mau humor, ele \n"
"provavelmente ficar bravo com você...ele\n"
"pode ser bem assustador. Mas..." BOX_BREAK UNSKIPPABLE "Eu conheço o SEGREDO dele." BOX_BREAK UNSKIPPABLE "Ele pode não se parecer com o tipo,\n"
"mas o Big Brother adora dançar!\n"
"Se ele entrar no ritmo, com certeza..." TEXTID("\x30\x19")
)

DEFINE_MESSAGE(0x3019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lembro que o Big Brother costumava\n"
"sempre ouça a música " COLOR(ADJUSTABLE) "que\n"
"vem da floresta" COLOR(DEFAULT) "..." BOX_BREAK "Ah sim, os bons velhos tempos...\n"
"Essa música me faz sentir\n"
"nostálgico também..." TEXTID("\x30\x2C")
)

DEFINE_MESSAGE(0x301A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Que diabos! Quem é você?!" BOX_BREAK UNSKIPPABLE "Quando ouvi a música " COLOR(BLUE) "do\n"
"Família Real" COLOR(DEFAULT) ", eu esperava que eles \n"
"mensageiro chegou, mas...\n"
"você é apenas uma criança!" BOX_BREAK UNSKIPPABLE "Tem " COLOR(RED) "Darunia" COLOR(DEFAULT) ", o chefão de\n"
"os Gorons, realmente perderam tanto\n"
"status a ser tratado assim\n"
"por seu Irmão Juramentado, o Rei?" BOX_BREAK UNSKIPPABLE "Agora, estou REALMENTE com raiva!\n"
"Saia da minha frente, agora!" BOX_BREAK UNSKIPPABLE "Você está perguntando por que estou em tal\n"
"mau humor agora?" BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "Criaturas antigas têm \n"
"infestou a Caverna do Dodongo!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "Tivemos uma colheita ruim\n"
"colheita especial, Bomb Flowers!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "Fome e fome porque\n"
"da escassez de rocha!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE SHIFT("\x48") "Mas..." TEXTID("\x30\x1B")
)

DEFINE_MESSAGE(0x301B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x19") "Este é um problema do Goron!" QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE SHIFT("\x11") "Não precisamos de ajuda de\n"
SHIFT("\x46") "estranhos!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x15") "Heeey!! Que música legal!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Assim, minha depressão é\n"
"tudo se foi! Algo acabou de chegar \n"
"sobre mim! De repente eu queria\n"
"dançar como um louco!" BOX_BREAK UNSKIPPABLE SHIFT("\x3C") "Eu sou " COLOR(RED) "Darunia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Sou o chefão dos Gorons!\n"
"Havia algo que você queria \n"
"para me perguntar sobre?" BOX_BREAK SHIFT UNSKIPPABLE("\x50") "O quê?" BOX_BREAK UNSKIPPABLE "Você quer a " COLOR(RED) "Pedra Espiritual de\n"
"Fogo" COLOR(DEFAULT) "também?" BOX_BREAK UNSKIPPABLE "A Pedra Espiritual do Fogo, também\n"
"conhecido como o Rubi do Goron, é o nosso\n"
"tesouro escondido da corrida..." BOX_BREAK UNSKIPPABLE "Mas espere, não vou dar\n"
"para você com tanta facilidade.\n"
"Se você quer tanto..." BOX_BREAK UNSKIPPABLE "Por que você não vai destruir o \n"
"monstros dentro do Dodongo's \n"
"Cavern e provar que você é um homem de verdade?" BOX_BREAK UNSKIPPABLE "Dessa forma, todos estarão \n"
"feliz de novo! Se você fizer isso, eu \n"
"vai dar a você o que você quiser,\n"
"até mesmo a Pedra Espiritual!" BOX_BREAK UNSKIPPABLE "Tenho algo para você. Não estou\n"
"realmente dando a você isso\n"
"devolva para qualquer coisa, mas pegue\n"
"qualquer maneira." BOX_BREAK UNSKIPPABLE "Se você usar isso, até um pouco \n"
"cara como se você pudesse escolher uma " COLOR(RED) "Bomba \n"
"Flor " COLOR(DEFAULT) "usando " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x301D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Destrua os monstros no\n"
COLOR(RED) "Caverna do Dodongo" COLOR(DEFAULT) "e se tornar um \n"
"homem de verdade! Então, podemos falar sobre\n"
"a Pedra Espiritual!"
)

DEFINE_MESSAGE(0x301E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, irmão, toque essa música\n"
"novamente em breve!"
)

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não importa quantas vezes eu ouça \n"
"essa música, não envelhece!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, não é bem isso que eu \n"
"estava procurando..." BOX_BREAK "Queria ouvir... uma música...\n"
"algo... hum... de fora \n"
"as montanhas...algo...\n"
"green...natural..." BOX_BREAK "Esse é o tipo de música que eu quero \n"
"ouvir..."
)

DEFINE_MESSAGE(0x3021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, agora podemos entrar na caverna.\n"
"Você é tão esperto!"
)

DEFINE_MESSAGE(0x3022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Conheço um truque para economizar gravetos!\n"
"Se você colocar fogo em um graveto, ele vai \n"
"queimar em cinzas. Pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para colocá-lo\n"
"fora antes que queime completamente!" BOX_BREAK "A propósito, escondi um graveto\n"
"em algum lugar...\n"
"Hehehe..."
)

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou eu," COLOR(RED) "Darúnia" COLOR(DEFAULT) "!\n"
"Bom trabalho!" BOX_BREAK UNSKIPPABLE "Graças a você, podemos mais uma vez\n"
"coma as deliciosas pedras do\n"
"Caverna do Dodongo até o nosso \n"
"estômagos estouraram!"
)

DEFINE_MESSAGE(0x3024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Estou com tanta fome que não consigo pensar\n"
"sobre tudo menos comida!" BOX_BREAK UNSKIPPABLE "\"Pedra Espiritual?\"\n"
"Aquela " COLOR(RED) "pedra vermelha" COLOR(DEFAULT) " que estava iluminando\n"
"até nossa cidade?" BOX_BREAK UNSKIPPABLE "Big Brother" COLOR(RED) "Darunia" COLOR(DEFAULT) " pegou\n"
"fora. Então, ele se trancou em\n"
"seu quarto e não vai sair." BOX_BREAK UNSKIPPABLE "Desde então, parece que tudo\n"
"as luzes da cidade se apagaram \n"
"fora... Todo mundo parece tão...\n"
"deprimido..." TEXTID("\x30\x25")
)

DEFINE_MESSAGE(0x3025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quero que você traga " COLOR(RED) "fire" COLOR(DEFAULT) " do Grande\n"
"O quarto do irmão aqui atrás."
)

DEFINE_MESSAGE(0x3026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, entendi...\n"
"Deveríamos ter jogado o \n"
"Bomba do penhasco..."
)

DEFINE_MESSAGE(0x3027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é incrível, destruindo \n"
"os Dodongos! Você se importa se eu \n"
"chamar você de Grande Irmão?"
)

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Graças a você, estamos todos bem!\n"
"Por que você não compra algumas bombas \n"
"agora?" EVENT
)

DEFINE_MESSAGE(0x3029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sabe, sou muito grato a você.\n"
"Quando eu tiver um filho, vou nomeá-lo\n"
"Depois de você!"
)

DEFINE_MESSAGE(0x302A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quiser ouvir mais Goron\n"
"fofoca, vá até nossa cidade!" BOX_BREAK COLOR(RED) "Goron City" COLOR(DEFAULT) " é um pouco\n"
"caminho pela trilha. Não vai demorar\n"
"muito mais tempo para chegar lá, mesmo\n"
"a pé."
)

DEFINE_MESSAGE(0x302B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você escolhe as Flores Bomba com \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Pressione " COLOR(BLUE) "[A] " COLOR(DEFAULT) "novamente para definir."
)

DEFINE_MESSAGE(0x302C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando todas as " COLOR(RED)" acenderem" COLOR(DEFAULT) " neste andar\n"
"estão acesos, Goron City é muito animada!"
)

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você vai limpar o \n"
"Dodongos? É um problema de Goron,\n"
"embora. Você é uma criança intrometida,\n"
"não é você?!" BOX_BREAK "Bem, é claro que ficaremos felizes se \n"
"você conserta para que possamos obter todos os\n"
"Bombas que queremos, como costumávamos fazer..." BOX_BREAK "Apenas deixe-me avisá-lo...\n"
"Dodongos são criaturas assustadoras! \n"
"Eles vão comer QUALQUER COISA!!" BOX_BREAK "Então tome cuidado e não \n"
"seja comido!" EVENT
)

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu já te disse!\n"
"Estamos sem bombas!\n"
"Ohhh... estou com tanta fome!" PERSISTENT
)

DEFINE_MESSAGE(0x302F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como foi o Grande Irmão?\n"
"Entendo..." BOX_BREAK "A propósito, você conhece o\n"
"música vindo de dentro de\n"
"este túnel? Todos nós gostamos desta música!"
)

DEFINE_MESSAGE(0x3030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu não vou deixar você me pegar! \n"
"Você provavelmente trabalha para Ganondorf!"
)

DEFINE_MESSAGE(0x3031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Como você pôde fazer isso comigo?\n"
"Você, você é o servo de Ganondorf!" BOX_BREAK UNSKIPPABLE "Ouça meu nome e trema!" BOX_BREAK UNSKIPPABLE "Eu sou " COLOR(RED) NAME COLOR(DEFAULT) "! \n"
"Herói dos Gorons!"
)

DEFINE_MESSAGE(0x3032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "O quê?" BOX_BREAK UNSKIPPABLE "Seu nome também é\n"
NAME "?" BOX_BREAK UNSKIPPABLE "Então você deve ser o lendário\n"
"Dodongo Buster e Herói, \n"
NAME "!" BOX_BREAK UNSKIPPABLE "Meu pai é " COLOR(RED) "Darunia" COLOR(DEFAULT) "...\n"
"Lembras-te dele?" BOX_BREAK UNSKIPPABLE "Papai me nomeou " NAME "\n"
"depois de você, porque você é tão \n"
"corajoso!" BOX_BREAK UNSKIPPABLE "É um nome legal!\n"
"Eu realmente gosto!" BOX_BREAK NAME UNSKIPPABLE ", você é um herói para \n"
"nós Gorons! \n"
"Estou tão feliz em conhecê-lo!" BOX_BREAK UNSKIPPABLE "Por favor, dê-me seu autógrafo!\n"
"Assine:\n"
SHIFT("\x05") "\"Para meu amigo, \n"
SHIFT("\x05") NAME " dos Gorons\"" BOX_BREAK UNSKIPPABLE "Oh..." BOX_BREAK UNSKIPPABLE "Acho que não é uma boa hora\n"
"pedir isso a você...\n"
"Por favor, ajude a todos!" BOX_BREAK UNSKIPPABLE "Meu pai, Darunia, foi para o " COLOR(RED) "Fogo\n"
"Templo" COLOR(DEFAULT) ". Um dragão está dentro!" BOX_BREAK UNSKIPPABLE "Se não nos apressarmos, até meu pai\n"
"será comido pelo dragão!!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bbb-boooo hooo!" EVENT
)

DEFINE_MESSAGE(0x3034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"É melhor tentar acalmá-lo\n"
"se você puder...\n"
"Talvez ele se acalme se você \n"
"fale com ele?" BOX_BREAK "O que você quer perguntar a ele?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sobre o dragão\n"
"Sobre os Gorons" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Há muito tempo atrás havia um\n"
"dragão malvado chamado " COLOR(RED) "Volvagia " COLOR(DEFAULT) "vivendo \n"
"nesta montanha." BOX_BREAK UNSKIPPABLE "Aquele dragão era muito assustador!\n"
"Ele comeu Gorons!" BOX_BREAK UNSKIPPABLE "Usando um martelo enorme, o herói de\n"
"os Gorons... BOOOM!" BOX_BREAK UNSKIPPABLE "Destruiu assim mesmo. Isto é \n"
"um mito de muito tempo atrás, mas é \n"
"verdadeiro!" BOX_BREAK UNSKIPPABLE "Eu sei, porque meu pai é um\n"
"descendente do herói!" TEXTID("\x30\x33")
)

DEFINE_MESSAGE(0x3036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Todos foram levados para o \n"
COLOR(RED) "Templo do Fogo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Enquanto meu pai estava fora...\n"
"Os seguidores de Ganondorf" COLOR(RED) " " COLOR(DEFAULT) "viram e\n"
"levou todos embora!" BOX_BREAK UNSKIPPABLE "Todos eles serão comidos por\n"
COLOR(RED) "Volvagia" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Papai disse que Ganondorf tem\n"
"Revived Volvagia..." BOX_BREAK UNSKIPPABLE "Como um aviso para aqueles que podem\n"
"oponha-se a ele, Ganondorf vai\n"
"alimente todos eles para Volvagia!" BOX_BREAK UNSKIPPABLE "O papai foi ao Templo do Fogo todos\n"
"sozinho para tentar salvar \n"
"todos..." BOX_BREAK UNSKIPPABLE "Por favor, ajude, " NAME "!\n"
"Vou dar-lhe este " COLOR(RED) "resistente ao calor\n"
"túnica" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x3037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Papai me disse para não deixar ninguém \n"
"siga-o até o templo, mas..." BOX_BREAK UNSKIPPABLE "Só você, " NAME ", pode\n"
"salve a todos!" BOX_BREAK UNSKIPPABLE "Tenho certeza de que o dono da loja, quem\n"
"está escondido em algum lugar agora, will\n"
"também ajudá-lo!" BOX_BREAK UNSKIPPABLE "Agora, vou falar sobre o segredo\n"
"passagem para o Templo do Fogo!" TEXTID("\x30\x38")
)

DEFINE_MESSAGE(0x3038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tente mover a estátua " COLOR(RED) "" COLOR(DEFAULT) "para dentro\n"
"Quarto do papai!"
)

DEFINE_MESSAGE(0x3039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quem está aí? É você,\n"
NAME "...?" BOX_BREAK UNSKIPPABLE "Ah, realmente é " NAME "!" BOX_BREAK UNSKIPPABLE "Você cresceu tanto desde a última vez\n"
"vi você!" BOX_BREAK UNSKIPPABLE "Quero ter uma conversa de homem para homem\n"
"com você, mas agora não é a hora." BOX_BREAK UNSKIPPABLE "Ganondorf está causando problemas em\n"
"Monte da Morte de novo!\n"
"Ele reviveu o mal, antigo\n"
"dragão Volvagia!" BOX_BREAK UNSKIPPABLE "Além disso, ele vai\n"
"alimente meu povo para aquele dragão maligno\n"
"como um aviso para outras raças que\n"
"pode resistir a ele..." BOX_BREAK UNSKIPPABLE "Se aquele dragão cuspidor de fogo\n"
"escapa da montanha, todos de\n"
"Hyrule se tornará uma queima\n"
"terra baldio!" BOX_BREAK UNSKIPPABLE "Vou seguir em frente para tentar selar\n"
"up the evil dragon..." BOX_BREAK UNSKIPPABLE "Mas estou preocupado porque eu\n"
"não tem o martelo lendário...\n"
"Mas eu não tenho escolha." BOX_BREAK NAME UNSKIPPABLE "...Estou pedindo para você\n"
"faça isso como meu Irmão Juramentado..." BOX_BREAK UNSKIPPABLE "Enquanto estou tentando lidar com o\n"
"dragão, por favor salve meu povo!" BOX_BREAK UNSKIPPABLE "As celas dos prisioneiros estão no\n"
"direção oposta.\n"
"Estou contando com você, \n"
NAME "!"
)

DEFINE_MESSAGE(0x303A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou salvo!\n"
"Obrigado!\n"
"Aqui, pegue isso!"
)

DEFINE_MESSAGE(0x303B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME UNSKIPPABLE "...Não é possível segurar... \n"
"mais...não consigo segurar\n"
"não vai mais..." BOX_BREAK UNSKIPPABLE "Saia daqui!!"
)

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigado, irmão!\n"
"Eu realmente aprecio o que você\n"
"sim. Agradeço em nome de\n"
"toda a raça Goron!" BOX_BREAK UNSKIPPABLE "Você se tornou um homem de verdade,\n"
"exatamente como eu pensei que você faria!"
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT("\x36") "Não se esqueça...\n"
SHIFT("\x03") "Agora você e eu somos verdadeiros Irmãos!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "É algo que cresce mais\n"
"tempo... uma verdadeira amizade.\n"
"Um sentimento no coração que \n"
"torna-se ainda mais forte com o tempo..." BOX_BREAK UNSKIPPABLE "A paixão da amizade vai \n"
"em breve florescerá em um justo\n"
"poder e através dele, você\n"
"saiba qual caminho seguir..." BOX_BREAK UNSKIPPABLE "Esta música é dedicada ao \n"
"poder do coração...\n"
"Ouça o " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "...Vejo você de novo..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) NAME ", está tão quente em \n"
"aqui! Não podemos ficar aqui por\n"
"grandes!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x3041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"IRMÃO " NAME "" UNSKIPPABLE!\n"
"Todo mundo voltou!" BOX_BREAK UNSKIPPABLE "Papai e você destruíram o dragão\n"
"juntos, não é!" TEXTID("\x30\x42")
)

DEFINE_MESSAGE(0x3042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quando eu crescer, quero ser um\n"
"homem forte como você, \n"
NAME "!"
)

DEFINE_MESSAGE(0x3043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Obrigado, " NAME "!!"
)

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Muito obrigado por\n"
"nos salvando!" PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A propósito, eu, a selvagem Darunia,\n"
"acabou sendo o grande \n"
COLOR(RED) "Sage of Fire" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Isso não é engraçado, irmão?\n"
"Bem, deve ser assim que eles chamam\n"
"destino." BOX_BREAK UNSKIPPABLE "Nada me deixou mais feliz\n"
"do que ajudar você a selar o mal\n"
"aqui!"
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, irmão, pegue isso!\n"
"Este é um " COLOR(RED) "Medalhão " COLOR(DEFAULT) "que contém\n"
"o poder dos espíritos do fogo--e\n"
"minha amizade."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Grande problema!\n"
"Todos se foram!\n"
"Mas vou manter meu negócio aberto!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Que aventura louca! Vai\n"
"fazer uma história incrível..." BOX_BREAK UNSKIPPABLE "Não acredito que os Dodongos\n"
"de repente apareceu em tão grande \n"
"números!" BOX_BREAK UNSKIPPABLE "E aquela pedra grande bloqueando o \n"
"cave..." BOX_BREAK UNSKIPPABLE "Todo esse problema deve ter sido\n"
"causado por aquele ladrão Gerudo, \n"
COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Ele disse, \n"
"\"" COLOR(LIGHTBLUE) "Dê-me a Pedra Espiritual!\n"
"Só assim vou abrir a caverna \n"
"para você!" COLOR(DEFAULT) "\"" BOX_BREAK UNSKIPPABLE "Você, por outro lado, arriscou \n"
"sua vida por nós..."
)

DEFINE_MESSAGE(0x3049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Ajuste apertado..."
)

DEFINE_MESSAGE(0x304A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou trabalhando em algo realmente \n"
"legal agora! Mas acho que é\n"
"vai demorar um pouco..." TEXTID("\x30\x4B")
)

DEFINE_MESSAGE(0x304B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você puder esperar cinco ou seis anos,\n"
"deve estar pronto. OK?"
)

DEFINE_MESSAGE(0x304C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Acabei de completar uma arma pequena.\n"
"Que tal..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como você gosta da sensação disso?"
)

DEFINE_MESSAGE(0x304E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que há um problema \n"
"com sua durabilidade...\n"
"Mas ainda..." TEXTID("\x30\x4F")
)

DEFINE_MESSAGE(0x304F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que tal comprar esta faca por \n"
"200 rúpias?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem. Volte novamente."
)

DEFINE_MESSAGE(0x3051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor... não... me coma...\n"
"Se você comer algo como eu,\n"
"você vai ficar com dor de estômago!" BOX_BREAK "Você vai se arrepender!!"
)

DEFINE_MESSAGE(0x3052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, entendi. Grande Irmão Darunia\n"
"pediu para você me resgatar.\n"
"Eu devo muito a você!" BOX_BREAK "Por favor, ajude o Big Brother!"
)

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu irmãorrr...\n"
"Abriu um novo storrrre...\n"
"É a Lâmina de Medigoron\n"
"Storrrrrrrre..." BOX_BREAK "No entantorrrrr... \n"
"Eu sou melhorrrrrr em fazer\n"
"lâminasssss." BOX_BREAK "Hylian carpinteirorrrrrs elogios\n"
"eu porrrrrr minhas habilidadesssssss.\n"
"Eu não estou mentindo..."
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Essa faca quebrada com certeza é minha \n"
"worrrrrrrrrrk...\n"
"Quero muito repararrrrr, mas..." BOX_BREAK UNSKIPPABLE "Mas por causa do dia de ontem\n"
"errrrrupção, meus olhos estão \n"
"irrrrrrrritated..." BOX_BREAK UNSKIPPABLE "Existem colírios finos no Zora\n"
"Domínio... Você os encontrará se\n"
"vai ver " COLOR(RED) "Kinnnnnng Zorrrrrra" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, vá buscar os olhosrrrrrrops...\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Awww nãooooo... Terminei...\n"
"Meus olhos estão coçando tanto...\n"
"Owwwwww..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, não! Todo mundo se foi!\n"
"Só eu fiquei para trás!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu estava esperando por você rrrr,\n"
"com lágrimas nos olhos...\n"
"Por favor, diga olá para Kinnng Zorrra!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Rrrrrralmente? Você trouxe o olho\n"
"gotas? Estou tão rrrrrealiviado! Estou\n"
"vou usá-los rrrrr agora!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(RED) "Wowwwwwwwwwwwwww!!" COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE "Isso é estimulante! É\n"
"worrrrrking grrrrreat!" BOX_BREAK UNSKIPPABLE "Agora posso voltar ao meu blade\n"
"negócios! Minha preocupação não é \n"
"muito consistente, então vou dar isso \n"
"para você, então você não vai esquecer." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Todo mundo voltou!\n"
"É negócio como de costume!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Depois de alguns dias...\n"
"Por favor retornerrrrrn...\n"
"Espere, apenas espere pacientemente..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ainda não...\n"
"Ei você...\n"
"Você está impaciente..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esse sworrrrd é o meu melhor \n"
"trabalha!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "escudo " COLOR(LIGHTBLUE) "desapareceu!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "A túnica " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "que você estava vestindo é \n"
"se foi!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Seu " COLOR(DEFAULT) "escudo " COLOR(LIGHTBLUE) "se foi!\n"
"A túnica " COLOR(DEFAULT)" COLOR(LIGHTBLUE) "que você estava vestindo tem\n"
"também foi levado!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x3062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você fez bem em vir todos os\n"
"caminho aqui em cima, " NAME ". \n"
"Este é o cume do sagrado\n"
"Monte da Morte! Hoot!" BOX_BREAK UNSKIPPABLE "Dizem que as nuvens \n"
"ao redor deste pico refletem o\n"
"condição da Montanha da Morte. Quando\n"
"eles parecem normais, está em paz." BOX_BREAK UNSKIPPABLE "Subindo até aqui\n"
"só prova o quão inteligente você é!\n"
"Agora quero ver você fazer\n"
"outra jogada inteligente..." BOX_BREAK UNSKIPPABLE "A " COLOR(RED) "Grande Fada" COLOR(DEFAULT) " vive nisso\n"
"topo da montanha, e ela dará\n"
"você é uma nova habilidade! Ela é a líder\n"
"das fadas, você sabe. Hoo!" BOX_BREAK UNSKIPPABLE "Vou me empoleirar aqui e esperar por você.\n"
"Quando você estiver pronto para voltar\n"
"abaixo, posso te ajudar! \n"
"Agora, vá!"
)

DEFINE_MESSAGE(0x3063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Puxa!\n"
"Bem, parece que você cresceu\n"
"um pouco acima da Grande Fada\n"
"poder..." BOX_BREAK "Mas você ainda não se parece muito com\n"
"o herói que salvará Hyrule. At\n"
"pelo menos ainda não!" BOX_BREAK "Se você estiver voltando" COLOR(RED) "para baixo\n"
"montanha" COLOR(DEFAULT) ", posso te emprestar uma asa.\n"
"Venha aqui e pegue minhas garras!\n"
"E segure firme! Hoo hooooooot!"
)

DEFINE_MESSAGE(0x3064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que uma " COLOR(RED) "linda" COLOR(DEFAULT) " " COLOR(RED) "fada\n"
COLOR(DEFAULT) "vive no topo da Montanha da Morte!" BOX_BREAK "Você não quer vê-la?"
)

DEFINE_MESSAGE(0x3065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que uma fada " COLOR(RED) "" COLOR(DEFAULT) "vive no topo\n"
"da Montanha da Morte." BOX_BREAK "Se você quiser chegar ao topo,\n"
"é melhor você pegar um grande " COLOR(LIGHTBLUE) "escudo" COLOR(DEFAULT) "\n"
"com você..."
)

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Olha! Uma " COLOR(DEFAULT) "galinha" COLOR(LIGHTBLUE) "chocou de\n"
"o " COLOR(DEFAULT) "ovo " COLOR(LIGHTBLUE) "que você estava incubando!\n"
"É o milagre da vida!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pegou a pedra vermelha?\n"
"Deixe-me dar uma lambida!" BOX_BREAK "Não? Booooo!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Irmão! Você vai continuar se aprimorando\n"
"em suas habilidades enquanto viaja,\n"
"não vai?" BOX_BREAK UNSKIPPABLE "Você deveria ir ver a " COLOR(RED) "Grande Fada" COLOR(DEFAULT) "\n"
"no topo da Montanha da Morte! Ela\n"
"vai energizar você!" BOX_BREAK UNSKIPPABLE "Ei, pessoal! Vamos nos despedir\n"
"Irmão!"
)

DEFINE_MESSAGE(0x3069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou te contar um segredo para\n"
"me salvando!" BOX_BREAK UNSKIPPABLE "Neste templo, há " COLOR(RED) "portas\n"
"que cai " COLOR(DEFAULT) "quando você tenta \n"
"abra-os. Quando um destes\n"
"portas começam a cair, mexa-se!" BOX_BREAK UNSKIPPABLE "Se você usar uma amostra do\n"
"Goron \"corte especial\", você pode\n"
"quebrar..."
)

DEFINE_MESSAGE(0x306A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Deixe-me contar um segredo como\n"
"uma recompensa por me libertar!" BOX_BREAK UNSKIPPABLE "Quando você está pegando fogo, você pode colocar\n"
"sacuda balançando sua espada, ou\n"
"rolando para frente... Você sabia\n"
"que?"
)

DEFINE_MESSAGE(0x306B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aqui vai uma dica para me resgatar!" BOX_BREAK UNSKIPPABLE "Em algum lugar deste templo, você está\n"
"certeza de encontrar alguns \n"
"criaturas que dançam como eles\n"
"ataque. Flechas não vão machucá-los!" BOX_BREAK UNSKIPPABLE "Parece que você pode precisar de\n"
"o Goron \"colheita especial!\" Isso é\n"
"tudo que eu tenho que te dizer!"
)

DEFINE_MESSAGE(0x306C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou te contar um segredo para\n"
"me salvando!" BOX_BREAK UNSKIPPABLE "Há interruptores neste templo\n"
"que você precisa cortar para ativar.\n"
"Mas você também pode usar o Goron\n"
"\"colheita especial\" para fazer o trabalho."
)

DEFINE_MESSAGE(0x306D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou te contar um segredo para\n"
"me salvando!" BOX_BREAK UNSKIPPABLE "Se você encontrar um lugar que possa\n"
"vê no mapa, mas não alcança,\n"
"tente jogar sua Ocarina!"
)

DEFINE_MESSAGE(0x306E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou te contar um segredo para\n"
"me salvando!" BOX_BREAK UNSKIPPABLE "Para entrar na sala\n"
"onde Darunia foi, você tem que\n"
"faça algo sobre o pilar\n"
"preso no teto". BOX_BREAK UNSKIPPABLE "Encontre um caminho que leve a uma sala\n"
"acima do teto imediatamente!"
)

DEFINE_MESSAGE(0x306F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vou te contar um segredo para\n"
"me salvando!" BOX_BREAK UNSKIPPABLE "Uma porta está escondida dentro da estátua\n"
"na entrada deste templo." BOX_BREAK UNSKIPPABLE "Mas, o Goron \"colheita especial\" não\n"
"trabalhe nisso... Você não tem\n"
"algo mais forte?"
)

DEFINE_MESSAGE(0x3070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aqui está um segredo para me salvar!" BOX_BREAK UNSKIPPABLE "Uma parede com a qual você pode destruir\n"
"a \"colheita especial\" do Goron irá\n"
"som diferente de um normal\n"
"parede se você acertar com sua espada."
)

DEFINE_MESSAGE(0x3071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está me liberando?\n"
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
"Hoje à noite vou cozinhar globos oculares fritos \n"
"pela primeira vez em muito tempo!\n"
"Ei, ei, ei, ei, ei!" BOX_BREAK UNSKIPPABLE "Que coisa incrível! Por favor, diga \n"
"obrigado ao Rei Zora!\n"
"Eh? O quê?" EVENT
)

DEFINE_MESSAGE(0x4001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Estes são para fazer " COLOR(RED) "Biggoron's \n"
"Colírio" COLOR(DEFAULT) "? Ah, que decepção!\n"
"Você deveria ter dito isso no \n"
"primeiro lugar!" EVENT
)

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "!\n"
"Por aqui! Hoo hoo!" BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "Gostaria de saber o que " COLOR(RED) "Saria" COLOR(DEFAULT) " está fazendo agora?\n"
"Que tal voltar para o\n"
"floresta algum dia?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que você está fazendo? Você veio \n"
"um longo caminho para chegar aqui..." BOX_BREAK_DELAYED("\x28") UNSKIPPABLE "Você deve olhar para o " COLOR(RED) "Mapa \n"
"Subtela " COLOR(DEFAULT) "às vezes." BOX_BREAK NAME UNSKIPPABLE ", este é um lindo\n"
"lago cheio de água pura e límpida." BOX_BREAK UNSKIPPABLE "No fundo do lago há\n"
"a " COLOR(BLUE) "Templo da Água" COLOR(DEFAULT) "usado para adorar \n"
"os espíritos da água. As " COLOR(BLUE) "Zoras " COLOR(DEFAULT) "são\n"
"guardiões do templo. Hoo hoo." BOX_BREAK UNSKIPPABLE "Os Zoras vêm do Zora\n"
"Domínio no nordeste de Hyrule. An\n"
"raça aquática, eles são antigos\n"
"aliados da Família Real de Hyrule." BOX_BREAK UNSKIPPABLE "Ouvi dizer que apenas a Família Real\n"
"de Hyrule pode entrar no Domínio de Zora...\n"
"Hoo-hoo!" BOX_BREAK UNSKIPPABLE "Estou voltando para o castelo " COLOR(RED)" COLOR(DEFAULT) ".\n"
"Se você quiser vir comigo, segure\n"
"para minhas garras!"
)

DEFINE_MESSAGE(0x4004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou voltando para o " COLOR(RED) "castelo" COLOR(DEFAULT) ".\n"
"Se você quiser vir comigo, segure\n"
"para minhas garras!"
)

DEFINE_MESSAGE(0x4005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "...Hein?" BOX_BREAK UNSKIPPABLE "Parece que há algo\n"
"já dentro desta garrafa.\n"
"É uma " COLOR(RED) "letra" COLOR(DEFAULT) ":" BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x0C") "\"" COLOR(PURPLE) "Ajude-me.\n"
COLOR(DEFAULT) SHIFT("\x0C") COLOR(PURPLE) "Estou te esperando lá dentro\n"
COLOR(DEFAULT) SHIFT("\x0C") COLOR(YELLOW) "Barriga" de "Lord Jabu-Jabu"(ROXO).\n"
COLOR(DEFAULT) SHIFT("\x18") "--" COLOR(YELLOW) "Ruto" COLOR(DEFAULT) QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x0C") COLOR(PURPLE) "PS: Não conte ao meu pai !" COLOR(DEFAULT) "\"" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quem é você?" BOX_BREAK UNSKIPPABLE "Nós somos a " COLOR(BLUE) "Zoras" COLOR(DEFAULT) ", a orgulhosa\n"
"pessoas aquáticas!" BOX_BREAK UNSKIPPABLE "Então... você diz que tem alguns \n"
"conexão com o Royal de Hyrule\n"
"Família... \n"
"Bem, o que você quer de nós?"
)

DEFINE_MESSAGE(0x4007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Nós somos bons em mergulho!\n"
"E você?" BOX_BREAK "Se você quer ser um mergulhador mestre,\n"
"experimente o " COLOR(RED) "jogo de mergulho" COLOR(DEFAULT) " no topo \n"
"da cachoeira!\n"
"Você já tentou?"
)

DEFINE_MESSAGE(0x4008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Fonte de Zora é o \n"
"nascente do rio.\n"
COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) "vive no \n"
"fonte." TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lord Jabu-Jabu é a divindade patrona\n"
"dos Zoras." COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) " está em \n"
"encarregado de preparar suas refeições, \n"
"manhã e noite".
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Todos nós, Zoras, servimos ao grande \n"
COLOR(RED) "Rei Zora" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O grande Rei Zora deveria estar em\n"
"a " COLOR(RED) "Câmara Real" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu o Senhor Jabu-Jabu?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"De acordo com a \"Lenda de Zora,\"\n"
"o ato de oferecer um " COLOR(RED) "peixe" COLOR(DEFAULT) " ao Senhor \n"
"Jabu-Jabu vai te fazer feliz."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh isso não é bom." BOX_BREAK "Todo mundo que vem por aqui \n"
"deve ver " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) " em \n"
"ao menos uma vez!" BOX_BREAK "Fonte de Zora está logo além \n"
"O trono do Rei Zora. É onde\n"
"Lord Jabu-Jabu nada. Mas..." BOX_BREAK "a menos que você tenha King Zora\n"
"permissão, você não pode ir para \n"
"Fonte de Zora."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não encontramos " COLOR(RED) "Princesa Ruto\n"
COLOR(DEFAULT) "mesmo que alguns de nós tenham \n"
"pesquisou até " COLOR(BLUE) "Lake Hylia" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você encontrar alguma pista para\n"
COLOR(RED) "Paradeiro da Princesa Ruto" COLOR(DEFAULT),\n"
"você vai mostrá-los ao Rei Zora?"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Toda a água em Hyrule flui\n"
"from " COLOR(BLUE) "Fonte de Zora" COLOR(DEFAULT) "." BOX_BREAK "Essa água flui pelo Zora\n"
"Rio, que eventualmente chega\n"
COLOR(BLUE) "Lago Hylia" COLOR(DEFAULT) "ao sul."
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah, eu voltei à vida!" BOX_BREAK UNSKIPPABLE "Foi você quem me salvou?\n"
"Não fique nervoso!" BOX_BREAK UNSKIPPABLE "Parece que você está com dificuldades\n"
"respirar debaixo d'água". BOX_BREAK UNSKIPPABLE "Como expressão de minha gratidão,\n"
"Eu concedo a você esta " COLOR(RED) "túnica" COLOR(DEFAULT) ". Com isso,\n"
"você não vai engasgar debaixo d'água."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Princesa Ruto foi para o Lago \n"
"Hylia e não voltou...\n"
"Estou tão preocupado... de novo!"
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ooh...\n"
"Isso é... bem... hmmm...\n"
"Hmmm..." COLOR(RED) "Colírio" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Você pode dizer que temos,\n"
"você pode dizer que não...\n"
"Nós temos os ingredientes." BOX_BREAK UNSKIPPABLE "Se você levar os ingredientes " COLOR(RED) "" COLOR(DEFAULT) "para o\n"
"médico do laboratório do lago, ele\n"
"pode fazer as gotas para você." BOX_BREAK UNSKIPPABLE "Mas você precisa entregá-los\n"
"fresco..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você pode fazer " COLOR(RED) "antes que eles\n"
"estragar" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Então você acha que eles vão estragar \n"
"antes de chegar lá?\n"
"Não é tão longe se você fizer o \n"
"conexão a cavalo..."
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoot hoot!" BOX_BREAK_DELAYED("\x28") NAME UNSKIPPABLE ", você se parece com \n"
"você está ficando mais confortável\n"
"em seu papel de aventureiro." BOX_BREAK UNSKIPPABLE "Acho que a Princesa Zelda é \n"
"esperando por você para visitá-la novamente." BOX_BREAK UNSKIPPABLE "Você já tem o " COLOR(RED) "Goron's Ruby" COLOR(DEFAULT) "," COLOR(RED) "\n"
COLOR(DEFAULT) "não é?"
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá, filho. Estou pesquisando \n"
"o processo de fazer remédios por \n"
"misturando a água do Lago Hylia com \n"
"vários compostos incomuns." BOX_BREAK "Talvez você tenha conhecido aquela senhora \n"
"da loja de poções... ela é tipo \n"
"um aluno meu...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Ah, uau!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Não vi um " COLOR(RED) "Eyeball Frog" COLOR(DEFAULT) " \n"
"assim desde que o Domínio de Zora congelou\n"
"sobre!" EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh, meu querido, doce" COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) "...\n"
"Para onde ela foi?\n"
"Eu estou tão preocupado..."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ho, esta carta! \n"
"É de " COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) "!!" BOX_BREAK UNSKIPPABLE "Hmmm...Vamos ver...\n"
"Ela está dentro do Senhor Jabu-Jabu?\n"
"Isso não é possível!" BOX_BREAK UNSKIPPABLE "Nosso deus guardião, " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) ",\n"
"nunca comeria minha querida princesa\n"
"Ruto!" BOX_BREAK UNSKIPPABLE "Mas desde aquele estranho, " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ",\n"
"vem aqui, Senhor Jabu-Jabu tem \n"
"estive um pouco verde por aí\n"
"gills..." BOX_BREAK UNSKIPPABLE "A evidência parece clara.\n"
"Claro, você vai encontrar Ruto.\n"
"Você pode passar por aqui para o \n"
"altar do Senhor Jabu-Jabu." BOX_BREAK UNSKIPPABLE "Vou manter esta carta. Você fica com o \n"
COLOR(RED) "garrafa " COLOR(DEFAULT) "em que estava. Pegue \n"
"respeitosamente!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, encontre minha querida" COLOR(RED) "Princesa Ruto" COLOR(DEFAULT) "\n"
"imediatamente... Zora!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Você não pode respirar debaixo d'água!\n"
"Se você começar a engasgar, decole\n"
"aqueles " COLOR(DEFAULT) "botas" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x36") "Ooooh Nãooooooo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ohhh, estou revivido...\n"
"Foi você quem me salvou?\n"
"Não fique tão nervoso!" BOX_BREAK UNSKIPPABLE "Vou te dar uma " COLOR(BLUE) "Túnica Zora" COLOR(DEFAULT) "como\n"
"um símbolo dos meus agradecimentos. Se você tiver\n"
"isso, você pode... O quê?!" BOX_BREAK UNSKIPPABLE "Você já tem um? Você é \n"
"pronta para qualquer coisa, não é!" BOX_BREAK UNSKIPPABLE "Com meus sinceros agradecimentos... como \n"
"sobre um BEIJO?! O quê? Você não \n"
"quer?! Ah bem..." BOX_BREAK UNSKIPPABLE "Se você não quer minhas recompensas, você\n"
"pode ouvir meus problemas..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou um " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Você viu um \n"
"Linda garota Zora por aqui?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou um " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Você viu\n"
"alguma coisa estranha no lago?\n"
"O rio carrega muitas coisas \n"
"para este lago!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você..." QUICKTEXT_ENABLE "Você está atrasado!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Por que você demorou tanto?" QUICKTEXT_DISABLE "\n"
"Você é " QUICKTEXT_ENABLE "inútil!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Eu estava sozinho, só isso...\n"
"Só um pouco!!"
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE "Eu estava com medo..." QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Um pouco!" QUICKTEXT_DISABLE "Só um pouco!!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
NAME UNSKIPPABLE "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Você!" QUICKTEXT_DISABLE "\n"
"Você parecia legal... mais legal do que eu \n"
"pensei que você iria, de qualquer maneira... \n"
QUICKTEXT_ENABLE "Só um pouco!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Bem, de qualquer forma, você me salvou, então eu \n"
"acho que vou recompensá-lo." BOX_BREAK UNSKIPPABLE "O que você deseja? Apenas me diga...\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Eu quero aquela Pedra Espiritual.\n"
"Nada realmente..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você quer dizer a Pedra Espiritual de\n"
"Água," COLOR(BLUE) "Safira de Zora" COLOR(DEFAULT) ", não é?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Minha mãe me deu e disse \n"
"Eu deveria dar apenas para o homem \n"
"quem será meu marido. Você pode\n"
"chame-o de Anel de Noivado de Zora!" BOX_BREAK UNSKIPPABLE SHIFT("\x45") QUICKTEXT_ENABLE "Tudo bem!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Vou te dar o meu mais precioso\n"
"posse: \n"
"Safira de Zora!"
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Não diga ao meu pai..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Heeheehee... Não seja tímido." BOX_BREAK UNSKIPPABLE "Posso dizer o que você está pensando..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quero comprar um peixe, mas eles estão\n"
"um pouco caro demais..." BOX_BREAK "Não tenho escolha a não ser pegar um\n"
"dos peixes que estão nadando\n"
"por aí."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, " NAME "!\n"
"Então, você salvou a princesa, hein?\n"
"Eu realmente gostei disso!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fiz meu bem mais precioso\n"
"ajudá-lo em sua busca? Heehee!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, oi" NAME "!\n"
"Você é tudo que a Princesa Ruto vai falar\n"
"sobre ultimamente!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, é você, " NAME "!\n"
"Graças a você, Senhor Jabu-Jabu é\n"
"de volta ao normal!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Todos nós, Zoras, respeitamos os grandes\n"
"Rei Zora! Ele tem a dignidade de\n"
"um rei. Oh sim, ele faz." BOX_BREAK UNSKIPPABLE "O grande Rei Zora tem um \n"
"Princesa chamada " COLOR(RED) "Ruto" COLOR(DEFAULT) ". Ela é uma\n"
"filho único." BOX_BREAK UNSKIPPABLE "Ela também é uma moleca selvagem, e isso\n"
"parece que ela está sempre causando\n"
"o Rei um monte de problemas!" TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Aqui está." BOX_BREAK UNSKIPPABLE "Este medicamento não tem\n"
"conservantes nele. Portanto, " COLOR(RED) "não será \n"
"durar muito tempo" COLOR(DEFAULT) "a esta temperatura." BOX_BREAK UNSKIPPABLE "Corra o mais rápido que puder para \n"
"Monte da Morte. Você é jovem--\n"
"Você consegue!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hoo hoo! Parece que você conseguiu\n"
"já maior e mais forte,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Logo à frente está" COLOR(BLUE) "Domínio de Zora" COLOR(DEFAULT) ". \n"
"Os Zoras servem ao Royal de Hyrule \n"
"Família protegendo esta água \n"
"fonte." BOX_BREAK UNSKIPPABLE "Sua porta não abrirá para \n"
"qualquer um, exceto aqueles que têm\n"
"alguma conexão com o Royal \n"
"Família." BOX_BREAK UNSKIPPABLE "Deixe-os ouvir a melodia " COLOR(RED) "do \n"
"Família Real" COLOR(DEFAULT) "!\n"
"Hoo hoo hoo!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Na próxima vez que você voltar, \n"
"não se esqueça de me trazer um \n"
"lembrança!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você encontrou a Princesa Ruto!\n"
"Agora o Rei Zora vai te dar o \n"
COLOR(BLUE) "Pedra Espiritual da Água" COLOR(DEFAULT) "...\n"
"Bem, talvez." BOX_BREAK UNSKIPPABLE "Hein?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O bem mais precioso dela?\n"
"Você não sabe o que ela está falando\n"
"sobre, mas você coletou dois \n"
"Pedras Espirituais! Só falta uma!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O bem mais precioso dela?\n"
"Você não sabe o que ela está falando\n"
"sobre, mas você finalmente coletou\n"
"todas as três Pedras Espirituais!!" BOX_BREAK UNSKIPPABLE "Volte para ver a princesa Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nos encontramos novamente, " NAME "..."
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Este gelo foi criado por um mal\n"
"maldição... O monstro na " COLOR(BLUE) "Água\n"
"Templo " COLOR(DEFAULT) "é a fonte da maldição." BOX_BREAK UNSKIPPABLE "A menos que você desligue a fonte, \n"
"este gelo nunca vai derreter..." BOX_BREAK UNSKIPPABLE "Se você tiver coragem suficiente para \n"
"enfrente o perigo e salve \n"
"os Zoras, eu vou te ensinar o \n"
"melodia que leva ao templo".
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O tempo passa, as pessoas se movem...\n"
"Como o fluxo de um rio, nunca acaba..." BOX_BREAK UNSKIPPABLE "Uma mente infantil se voltará para\n"
"nobre ambição... O amor jovem\n"
"torna-se afeição profunda... A clara \n"
"a superfície da água reflete o crescimento..." BOX_BREAK UNSKIPPABLE "Agora ouça a " COLOR(BLUE) "Serenata de \n"
"Água" COLOR(DEFAULT) "para refletir sobre si mesmo..."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você veio aqui para conhecer o \n"
"Zoras, você perdeu seu tempo...\n"
"Isso é tudo que existe..." BOX_BREAK UNSKIPPABLE "Com uma exceção, os Zoras \n"
"agora estão selados sob esta espessura \n"
"manto de gelo..." BOX_BREAK UNSKIPPABLE "Consegui resgatar o Zora\n"
"princesa debaixo do gelo, mas... \n"
"ela saiu para ir para a " COLOR(BLUE) "Água \n"
"Templo" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você quer comprar peixe, você precisa\n"
"um recipiente para colocá-los." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você diz que quer comprar uma " COLOR(BLUE) "Zora\n"
"Túnica" COLOR(DEFAULT) "? Essa túnica é feita do\n"
"melhor material e, portanto,\n"
"extremamente caro!" BOX_BREAK "Na verdade, temo apenas que " COLOR(RED) "muito\n"
"família rica na Vila Kakariko " COLOR(DEFAULT) "pode\n"
"comprar esta roupa fina..." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah... você... Se eu estiver certo...\n"
NAME "?!" BOX_BREAK UNSKIPPABLE "Você é " NAME ", não é\n"
"tu?" BOX_BREAK UNSKIPPABLE "Sou eu, sua noiva," COLOR(BLUE) "Ruto" COLOR(DEFAULT) "!\n"
"Princesa dos Zoras!" BOX_BREAK UNSKIPPABLE "Nunca esqueci os votos que fizemos\n"
"feito um ao outro sete anos \n"
"atrás!" BOX_BREAK UNSKIPPABLE "Você é um homem terrível de se ter \n"
"me deixou esperando por esses sete\n"
"longos anos..." BOX_BREAK UNSKIPPABLE "Mas agora não é hora de falar \n"
"sobre o amor..." BOX_BREAK UNSKIPPABLE "Tenho certeza que você já viu!\n"
"Domínio de Zora - totalmente congelado!" BOX_BREAK UNSKIPPABLE "Um jovem chamado " COLOR(RED) "Sheik" COLOR(DEFAULT) " salvo \n"
"eu debaixo do gelo..." BOX_BREAK UNSKIPPABLE "Mas meu pai e o outro \n"
"Zoras não tem" TEXT_SPEED("\x02") "...ainda..." TEXT_SPEED("\x00") BOX_BREAK UNSKIPPABLE "Quero salvar todos eles!\n"
"Eu quero salvar o Domínio de Zora!" BOX_BREAK UNSKIPPABLE "Você! Você tem que me ajudar!\n"
"Este é um pedido meu, o\n"
"mulher que vai ser sua\n"
"esposa!" BOX_BREAK NAME UNSKIPPABLE ", você tem que \n"
"me ajude a destruir o monstro do mal\n"
"no Templo, OK?!" BOX_BREAK UNSKIPPABLE "Dentro do Templo da Água, existem \n"
COLOR(RED) "três lugares" COLOR(DEFAULT) " onde você pode \n"
"mudar o nível da água." BOX_BREAK UNSKIPPABLE "Eu vou mostrar o caminho.\n"
"Siga-me, rapidamente!!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME UNSKIPPABLE "! Cuidado!\n"
"Isso não é água normal sobre \n"
"lá!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "..." BOX_BREAK UNSKIPPABLE "Não esperava menos\n"
"do homem que escolhi para ser meu\n"
"esposo." BOX_BREAK UNSKIPPABLE "Domínio de Zora e seu povo\n"
"eventualmente retornará aos seus\n"
"Estado original."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Se você vir Sheik, \n"
"Por favor, dê a ele meus agradecimentos, OK?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O Ruto queria me agradecer?" BOX_BREAK UNSKIPPABLE "Entendo..." BOX_BREAK UNSKIPPABLE "Temos que devolver a paz a \n"
"Hyrule por causa dela também. \n"
"Não é?"
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, entendi...\n"
"Princesa Ruto foi para a Água\n"
"Têmpora..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Como recompensa...\n"
"Eu concedo meu amor eterno a você." BOX_BREAK UNSKIPPABLE "Bem, é isso que eu quero dizer, \n"
"mas acho que não posso oferecer isso\n"
"agora."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Princesa Zelda... Ela está viva. Eu posso\n"
"sente-o... então não desanime."
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE SHIFT("\x3F") "Keeeyaaaah!\n"
SHIFT("\x0F") "O que é isso?! Um polvo?!" QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Tenho que guardar a Água \n"
"Templo como o " COLOR(BLUE) "Sage of Water" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "E você... Você está procurando pelo\n"
"princesa," COLOR(RED) "Zelda" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Hah!\n"
"Você não pode esconder nada de mim!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Posso dizer que nada vai parar\n"
"você em sua busca por justiça e \n"
"paz... Você deve pegar isso \n"
COLOR(BLUE) "Medalhão" COLOR(DEFAULT) "... Leve-o respeitosamente!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você! Quem é você?!" BOX_BREAK UNSKIPPABLE "Eu sou " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Princesa dos Zoras." BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "O quê?!" QUICKTEXT_DISABLE "\n"
"Você está dizendo que meu pai perguntou \n"
"você vir aqui para me salvar?" BOX_BREAK UNSKIPPABLE "Eu " QUICKTEXT_ENABLE "nunca" QUICKTEXT_DISABLE " pediria a alguém para fazer isso\n"
"coisa!" BOX_BREAK UNSKIPPABLE "\"Carta em uma garrafa?\" Eu tenho\n"
QUICKTEXT_ENABLE "não faço ideia" QUICKTEXT_DISABLE " do que você está falando!" BOX_BREAK UNSKIPPABLE "Meu pai está preocupado comigo?" BOX_BREAK UNSKIPPABLE "Eu não " QUICKTEXT_ENABLE "me importo!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "De qualquer forma, não posso ir para casa agora.\n"
"E você..." QUICKTEXT_ENABLE "Saia daqui!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Entendeu?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você ainda está por aqui?\n"
"Eu disse para você ir embora!" BOX_BREAK UNSKIPPABLE "Estou bem. Estou entrando\n"
"Barriga do Senhor Jabu-Jabu desde que eu era\n"
"pouco, mas..." BOX_BREAK UNSKIPPABLE "Lord Jabu-Jabu é muito estranho \n"
"hoje..." BOX_BREAK UNSKIPPABLE "Há águas-vivas eletrificadas e\n"
"buracos estranhos ao redor..." BOX_BREAK UNSKIPPABLE "Além disso, minha pedra preciosa \n"
"era...mas...\n"
QUICKTEXT_ENABLE "Isso não é da sua conta!" QUICKTEXT_DISABLE "\n"
"De qualquer forma..." BOX_BREAK UNSKIPPABLE "Você!" QUICKTEXT_ENABLE "Vá para casa agora!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Entendeu?!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você está tão preocupado comigo?" BOX_BREAK UNSKIPPABLE "Então eu lhe darei a honra\n"
"de me carregar!" BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "No entanto" QUICKTEXT_DISABLE "...Não vou embora até \n"
"encontre o que estou procurando.\n"
"É melhor você acreditar em mim!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Que falta de consideração!" QUICKTEXT_DISABLE "\n"
"Como você pôde me deixar para trás?! \n"
"Se você é homem, aja como um! \n"
"Tomar responsabilidade!" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "É isso aí!" QUICKTEXT_DISABLE "\n"
"É isso que eu estava procurando!\n"
"Me jogue lá em cima! \n"
"Para a plataforma!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE "Princesa Ruto conseguiu o \n"
COLOR(BLUE) "Pedra Espiritual" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "Mas" TEXT_SPEED("\x00") " por que Princesa Ruto?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh meu Deus!\n"
"Finalmente encontrei... \n"
"A pedra da minha mãe..." BOX_BREAK UNSKIPPABLE "Fiquei muito chateado quando Lord Jabu-\n"
"Jabu engoliu..." BOX_BREAK UNSKIPPABLE "Enquanto eu o alimentava, ele\n"
"de repente me engoliu! Eu estava \n"
"tão surpreso que deixei cair dentro..." BOX_BREAK UNSKIPPABLE "Mas, agora que encontrei, \n"
"Eu não preciso estar aqui \n"
"não mais!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Então, me leve para casa, agora mesmo!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jogo de Mergulho 20 Rupias\n"
"Quer jogar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x3F") "OK!" QUICKTEXT_DISABLE BOX_BREAK "Pegue todas as rúpias que eu jogo \n"
"a partir daqui. Você tem apenas um número limitado\n"
"quantidade de tempo!" BOX_BREAK "Quando você pegar todos eles, \n"
"volta aqui! Eu te dou\n"
"algo muito bom!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE QUICKTEXT_ENABLE "Ei! Parabéns!" QUICKTEXT_DISABLE "\n"
"Tenho algo \n"
"muito bom para você!\n"
"Venha e pegue!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Que mergulho gracioso!\n"
"Agora, por favor, pegue isso!" BOX_BREAK UNSKIPPABLE "Esta é uma \"" COLOR(RED) "escala" COLOR(DEFAULT) "\" do nosso tipo.\n"
"Com isso, você pode mergulhar muito\n"
"mais profundo debaixo d'água." EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "À medida que a água sobe, o mal \n"
"está desaparecendo do lago...\n"
NAME ", você conseguiu!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu...acredito que você vai \n"
"salve este mundo..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olha isso, " NAME "..." BOX_BREAK UNSKIPPABLE "Juntos, você e a princesa Ruto \n"
"destruiu o monstro do mal!" BOX_BREAK UNSKIPPABLE "Mais uma vez, o lago está cheio de\n"
"água pura. Tudo é como era aqui."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x51") COLOR(RED) "START!" COLOR(DEFAULT) QUICKTEXT_DISABLE EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Passe pelas cataratas para pegar um atalho." EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pegue o quanto quiser por \n"
"20 rúpias. Quer jogar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ei! Parabéns!!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Que tal um pouco de " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"Eles não estão vendendo muito bem..." BOX_BREAK "Que tal...\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " para uma peça?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Que tal um pouco de " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"Bem, eles não são tão populares ainda." BOX_BREAK "Que tal...\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) " para uma peça?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Que tal um pouco de " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"Eles estão ficando bastante \n"
"popular..." BOX_BREAK COLOR(RED) "30 Rupees" COLOR(DEFAULT) " para uma peça.\n"
"Que tal?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Que tal um pouco de " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"Eles estão na moda!" BOX_BREAK COLOR(RED) "40 Rupees" COLOR(DEFAULT) " para uma peça.\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Nós temos o popular " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "!\n"
"Você vai se arrepender se Não comprar \n"
"Eles agora!" BOX_BREAK COLOR(RED) "50 Rupees" COLOR(DEFAULT) " para uma peça.\n"
"(Só por enquanto.)\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Estes são os superpopulares \n"
COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! Caso você seja \n"
"imaginando, eles logo estarão esgotados!" BOX_BREAK "Super preço!\n"
COLOR(RED) "60 rúpias" COLOR(DEFAULT) " para uma peça!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Temos o super-raro \n"
COLOR(RED) "Feijões mágicos" COLOR(DEFAULT) "! Este pode ser o seu\n"
"última chance!" BOX_BREAK "Preço especial!\n"
COLOR(RED) "70 rúpias" COLOR(DEFAULT) "para uma peça!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Temos o lendário \n"
COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! Vou vendê-los apenas \n"
"para você!" BOX_BREAK "Super preço!\n"
COLOR(RED) "80 Rupees" COLOR(DEFAULT) "para uma peça!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Você quer..." COLOR(RED) "Feijão Mágico" COLOR(DEFAULT) "?! \n"
"Eles não são baratos, mas...você\n"
"ainda quer eles?" BOX_BREAK "Não posso deixá-los ir por menos que\n"
COLOR(RED) "90 rúpias" COLOR(DEFAULT) " cada um!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Nós temos..." COLOR(RED) "Feijão Mágico" COLOR(DEFAULT) "! \n"
"Você quer eles... hein? Hein?" BOX_BREAK COLOR(RED) "100 Rupees" COLOR(DEFAULT) " para uma peça!\n"
"Keyahahah!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, bem...\n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem dinheiro suficiente.\n"
"Não posso vendê-los para você.\n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Defina um bean para " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "e use-o em\n"
"a sujeira aqui."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, que pena! Estamos esgotados!\n"
"Chomp chomp...O quê?\n"
"Ah, esses feijões não estão à venda!"
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você quer plantar feijão, vá\n"
"ao redor e procure por solo macio.\n"
"Chomp chomp chomp."
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "1 metro" COLOR(DEFAULT) " agora. Mas eu não \n"
"chame isso de mergulho de verdade."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "2 metros" COLOR(DEFAULT) " agora. Mas eu não \n"
"chame isso de mergulho de verdade."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "3 metros" COLOR(DEFAULT) " agora. Mas eu não \n"
"chame isso de mergulho de verdade."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "4 metros" COLOR(DEFAULT) "agora. Ainda não \n"
"profundo o suficiente!"
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "5 metros" COLOR(DEFAULT) "agora. Ainda não \n"
"profundo o suficiente!"
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "6 metros" COLOR(DEFAULT) " agora. Você deve estar\n"
"capaz de mergulhar mais fundo!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você pode não ter notado, mas eu\n"
"estive observando você. Você mergulhou \n"
COLOR(RED) "7 metros" COLOR(DEFAULT) " agora. Você deve estar\n"
"capaz de mergulhar mais fundo!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você pode não ter notado, mas eu\n"
"estive observando você. Você " COLOR(RED) "tocou em \n"
"a parte inferior " COLOR(DEFAULT) "agora. Fantástico!\n"
"Eu vou te dar isso!"
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu mergulho é o melhor do \n"
"mundo. Por que você não mergulha no \n"
"fundo do Lago Hylia?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Meu nome é " COLOR(RED) "Pierre" COLOR(DEFAULT) ", o errante\n"
"espantalho. Na verdade, eu gostaria de poder\n"
"vaguear em busca de algo que comove a alma\n"
"Parece, mas eu estou meio preso aqui."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Música fantástica! Toca meu \n"
"coração!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você inventar uma boa música,\n"
"Volte e deixe-me ouvi-lo!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquela música que você tocou para mim ainda\n"
"fica no meu coração. Vamos ouvir\n"
"novamente!" EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquela música que você tocou para mim \n"
"fica no meu coração!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, você quer ir pescar \n"
"for " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, não! Você não tem um " COLOR(RED) "Rumble \n"
"Pak" COLOR(DEFAULT) "! Com um Rumble Pak, você pode\n"
"sinta as vibrações de um peixe em\n"
"seu gancho." BOX_BREAK "Desta vez, sem barulho para você!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Você tem um " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Hoje, você pode sentir a vibração,\n"
"homem jovem!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Puxa! Você não tem \n" suficiente
"dinheiro."
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ok, escute!" BOX_BREAK "Caminhe até a beira da água e\n"
"pressione " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " para olhar para um peixe." BOX_BREAK "Enquanto olha para um peixe, você pode \n"
"lançar sua linha com " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". Pressione " COLOR(BLUE) "[A]\n"
COLOR(DEFAULT) "para frear a linha." BOX_BREAK "Quando a isca cai no \n"
"água, você pode mexer com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"Se você é iniciante, também pode\n"
"use " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." BOX_BREAK "Enrole sua isca com " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Segure \n"
"para baixo " COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "para enrolar \n"
"mais rápido." BOX_BREAK "Se você sentir um golpe, pressione " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "e\n"
COLOR(LIGHTBLUE) "[Control-Pad] para baixo " COLOR(DEFAULT) "para definir o gancho.\n"
"Depois disso, enrole com " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Você entendeu?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sou tão generoso, vou deixar você pescar\n"
"pelo tempo que você quiser. No entanto,\n"
"você pode manter apenas um peixe." BOX_BREAK "O maior peixe já pescado aqui\n"
"pesou " COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "." BOX_BREAK "Depois de transmitir, você pode alterar\n"
"sua visão com " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." BOX_BREAK SHIFT("\x41") "Vamos pescar!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Wah ha haah!\n"
"Você ajustou o gancho pressionando\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " e " COLOR(LIGHTBLUE) "[Control-Pad] para baixo" COLOR(DEFAULT) "?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, o que aconteceu?\n"
"Você perdeu!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, bem... trata-se de " COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) ". \n"
"Você deseja mantê-lo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que você quer?\n"
THREE_CHOICE COLOR(ADJUSTABLE) "Pesar meu peixe.\n"
"Vamos conversar sobre algo.\n"
"Eu quero sair." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A paixão sozinha não vai te pegar \n"
"muitos peixes. Estou falando sério!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "UAU!" BOX_BREAK "Este peixe é enorme! Parece um \n"
"novo recorde! Pesa pelo menos \n"
COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "! Sério! \n"
"OK, aqui está o seu prêmio!" EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O quê? \n"
"O que você esta fazendo comigo?!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, jovem! Você não tem \n"
"qualquer coisa importante que você deveria ser\n"
"fazendo?" BOX_BREAK "O quê? Você está dizendo que é mais \n"
"divertido jogar aqui?" BOX_BREAK "Já vi muitas pessoas arruinando seus\n"
"vive com esse tipo de atitude.\n"
"Estou falando sério!\n"
"Ah bem..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já capturado\n"
"este lago pesava " FISH_INFO " quilos.\n"
"O pescador: " NAME QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Deseja continuar pescando?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, pesa " COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "...\n"
"Não é ruim, mas existem maiores\n"
"peixe lá!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, vamos lá! Você não tem um peixe!\n"
"Bolas!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer tentar outra isca?\n"
"Do que você está falando? Está\n"
"você é tão egoísta?" BOX_BREAK "Você não conhece o velho ditado,\n"
"\"Um grande pescador nunca escolhe\n"
"sua própria isca?\""
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O quê? Você quer saber um pouco \n"
"segredos de pesca? Não posso te contar\n"
"qualquer um. São segredos da empresa.\n"
"Seriamente!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O quê? Você quer saber se eu sou um \n"
"bom pescador?" BOX_BREAK "Claro que sou! Sou um profissional antigo!\n"
"Você sabe o que é um profissional?\n"
"Eu estou te dizendo a verdade!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regras e Regulamentos" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Não use iscas que afundam.\n"
"2. Não jogue lixo no lixo.\n"
"3. Ande em silêncio." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "4. Não jogue em ninguém." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Este é um verdadeiro lunker!\n"
"Vamos ver... pesa\n"
COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "!" BOX_BREAK "Deseja mantê-lo?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Volte quando ficar mais velho!\n"
"O peixe também ficará maior...\n"
"Bem, talvez."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, senhor! Eu me lembro de você!\n"
"Faz muito tempo!" BOX_BREAK UNSKIPPABLE "Há quantos anos?\n"
"Sete anos?! O que você tem\n"
"estava fazendo todo esse tempo?!" BOX_BREAK UNSKIPPABLE "Você é meu único cliente. Eu sou \n"
"quase falindo! Sério!\n"
"Além disso, meu cabelo..." BOX_BREAK UNSKIPPABLE "Uh, quer dizer, não importa..." BOX_BREAK UNSKIPPABLE "Bem, você quer ir pescar?\n"
"Custa apenas " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "!\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?" BOX_BREAK "Você quer pescar em um \n"
"lago de pesca diferente?!\n"
"O que você está falando?" BOX_BREAK "Vou fechar o negócio se você sair\n"
"em outro lugar!\n"
"Estou falando sério!"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?" BOX_BREAK "Você quer saber por que estou \n"
"coçar o tempo todo?\n"
"O que você está falando?" BOX_BREAK "Na verdade, não faço ideia.\n"
"Estou falando sério!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O que?" BOX_BREAK "Você está tentando me dizer que você\n"
"não consigo ver o peixe porque o\n"
"água está turva?" BOX_BREAK "Do que você está falando?\n"
"Esta hora do dia contribui para \n"
"pesca no seu melhor!" BOX_BREAK "Você pode fisgar um peixe do\n"
"azul, quando você menos espera.\n"
"Agora isso é emocionante!" BOX_BREAK "Estou falando sério. Estou falando sério!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, o que você está fazendo?\n"
"Eu disse para você não fazer isso!\n"
"Você é terrível!\n"
"Seriamente!" BOX_BREAK "Devolva meu chapéu!\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"De jeito nenhum" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O quê? Hein? Ah?\n"
"Acho que o peixe você já\n"
"mantido era maior que este..." BOX_BREAK "Você ainda deseja mantê-lo?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Não, eu não quero isso\n"
"Sim, eu quero mantê-lo de qualquer maneira" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Nossa! Que peixe estranho você\n"
"pego lá! Além disso,\n"
"pesa " COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "!" BOX_BREAK "O que você quer fazer com isso?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Mantenha mesmo assim\n"
"Não quero" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau!" BOX_BREAK "É isso que eu acho que é?\n"
"Incrível!\n"
"Você pegou uma isca afundando " COLOR(RED)" COLOR(DEFAULT) "!" BOX_BREAK "O que você quer fazer com isso?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Use agora.\n"
"Livre-se disso." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, bem..." BOX_BREAK "UAU! Que peixe raro!\n"
"Esta é uma " COLOR(RED) "Hyrule Loach" COLOR(DEFAULT) "!" BOX_BREAK "Para este peixe, o tamanho não \n"
"importante. Vou te dar isso \n"
"prêmio!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Recentemente, o número destes\n"
"os peixes diminuíram muito,\n"
"então eu vou lançar este." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Regras e Regulamentos\n"
"1. Não use iscas que afundam.\n"
"2. Não jogue lixo no lixo.\n"
"3. Ande em silêncio." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! Ei!\n"
"Você não pode tirar a haste de\n"
"aqui!" BOX_BREAK "Quando você parar de pescar, retorne \n"
"a vara ao balcão.\n"
"Estou falando sério!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh meu Deus!\n"
"Este peixe é gigantesco!!" BOX_BREAK "Um peixe tão grande nem cabe\n"
"na tela e não consigo pesá-la\n"
"com precisão, mas parece que é\n"
"sobre " COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "!!" BOX_BREAK "Você vai querer manter este,\n"
"direito n"
TWO_CHOICE COLOR(ADJUSTABLE) "Mantenha-o\n"
"Não guarde" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, querida!\n"
"Eu sou " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", o espantalho!\n"
"Você provavelmente já ouviu falar sobre meu\n"
"memória fantástica!" BOX_BREAK "Se você tiver uma nova música para tocar,\n"
"exploda!" BOX_BREAK "Esta é a última música que você tocou \n"
"hora, querida!" BOX_BREAK "Acerte!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Eu sou " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", o espantalho\n"
"gênio da música!\n"
"Ouço uma música uma vez e nunca\n"
"Esqueça, querida!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Toque a música normal para ligar\n"
"Pierre!\n"
"Se ele estiver por perto, ele sairá para\n"
"ajudá-lo, bebê!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei! Você não é a amiga fada que eu\n"
"conhecemos há muito tempo?\n"
"Uau, você cresceu, cara!" BOX_BREAK "Bem, aqui está sua música..." BOX_BREAK "O quê?" BOX_BREAK "Não, nunca esqueço!\n"
"Você, você que esqueceu...\n"
"não é? Se você tiver um \n"
"Ocarina, toque essa música, baby!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau! Você tem uma ocarina!\n"
"Ei, por que você não coloca uma música\n"
"em mim com isso, baby?!" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem... nada mal!\n"
"Vou lembrar para você \n"
"qualquer maneira!" BOX_BREAK "Não quero dizer que só me lembro\n"
"oito notas, mas vamos cortar\n"
"Aqui por enquanto, baby!" EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Jogue assim e você\n"
"nunca mova o coração deste espantalho,\n"
"bebê!" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"AH SIM!!\n"
"É isso, essa é a música!!\n"
"Você é demais!! Estou encantada!" BOX_BREAK "Ah, não, não! Não esqueci o\n"
"música... nunca esqueço nada!\n"
"Mas eu só quero recompensar\n"
"seu bebé!" BOX_BREAK "........\n"
"Eu tenho uma boa ideia!" BOX_BREAK "Meu amigo Pierre está vagando\n"
"ao redor, então toque essa música quando\n"
"você quer ligar para ele!" BOX_BREAK "Vou dizer a ele para ajudá-lo se ele\n"
"perto e ouve essa música, baby!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, é a Ocarina!\n"
"Toque essa música com ela,\n"
"bebê!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Jovem, você toca a Ocarina\n"
"bem... Mmmmm...! Essa melodia é \n"
"tão bom... ribbit! Todos nós deveríamos\n"
"pratique, ribbit!" BOX_BREAK "Leve rúpias como lembrança!\n"
"Se você inventar outro bom \n"
"melody, por favor, apareça e toque\n"
"isso... Ribbit ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Uau, essa melodia é tão legal! \n"
"Coelho!" BOX_BREAK "Siiiindo na chuva,\n"
"Ah, que sensação! \n"
"Rrrrribbbit!!" BOX_BREAK "Por favor, tome isso como um símbolo de\n"
"nossa gratidão de sapo, ribbit!\n"
"Tudo bem. Até mais, ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Olhe para nós, somos todos sapos enormes!!\n"
"Nós somos o Fabuloso mundialmente famoso\n"
"Cinco Tenores Froggish!!\n"
"Rrrrrbit!!" BOX_BREAK "Faça-nos pular para comer o \n"
"insetos voando acima de nós, ribbit!" BOX_BREAK "OK? \n"
"Então, pronto, pronto, vá!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Jovem, você foi ótimo!\n"
"Perrrrr perfeito!\n"
"Estamos cheios, ribbit!" BOX_BREAK "Você aceitaria este token nosso\n"
"gratidão?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, não me lembro disso \n"
"música, querida.\n"
"Por quê? Isso é o que eu não posso te dizer!\n"
"Bom dia!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já capturado\n"
"este lago pesava " FISH_INFO " quilos.\n"
"O pescador: o dono do lago" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê?\n"
"Você quer pescar com um \n"
"isca diferente?\n"
"... Ei, o que é isso?" BOX_BREAK "O quê? Você acabou de pegá-lo?\n"
"Geralmente, as regras dizem que você não pode\n"
"use um desses. Quero dizer, normalmente. \n"
"Mas, que diabos..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAHOOOOOO!\n"
"Isso é ENORME!! Um novo recorde!!\n"
"Isso... isso pesa tanto quanto...\n"
COLOR(RED) FISH_INFO " libras" COLOR(DEFAULT) "!!" BOX_BREAK "Puuuuuu! Essa isca afundando é\n"
"violando as regras!\n"
"Então, nenhum prêmio para você.\n"
"Ha ha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "O maior peixe já capturado\n"
"este lago pesava " FISH_INFO " quilos.\n"
"O pescador: " NAME "\n"
"(NOTA: Com isca de afundamento ilegal.)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é uma criança de bom coração!\n"
"Mas não conte a ninguém sobre isso.\n"
"Seriamente!" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O QUE AAAA?!?" BOX_BREAK "Por que você está fazendo isso comigo?\n"
"O que você está pensando?" BOX_BREAK "Não vou deixar você sair\n"
"tão fácil! Você tem que me pagar um \n"
COLOR(RED) "50 Rúpias" COLOR(DEFAULT) "bem!\n"
"Seriamente!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "GYAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") QUICKTEXT_ENABLE "Você" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "matou" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "me!!" QUICKTEXT_DISABLE TEXT_SPEED("\x00") "\n"
"Huh? Ah, é você." BOX_BREAK "Você tentou jogar o \n"
COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) "?" BOX_BREAK "Como eu disse antes, com isso \n"
"música, você pode transformar o dia em noite \n"
"ou da noite para o dia sempre que você \n"
"querer." BOX_BREAK "Quando você está no escuro, isso \n"
"música deve trazer a luz do sol\n"
"para você. Você deveria tentar."
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Quando cavei um buraco, encontrei um \n"
"tesouro que se estende - BOING!\n"
"e encolhe--BOING! É tão divertido, \n"
"Eu nunca vou dar a ninguém!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"O diário do coveiro " COLOR(RED) "" COLOR(DEFAULT) "está aqui.\n"
"Você quer ler?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Quem lê isso, por favor digite\n"
"meu túmulo. Vou deixar você ter meu\n"
"esticando, encolhendo" COLOR(RED) "lembrança" COLOR(DEFAULT) "." QUICKTEXT_DISABLE BOX_BREAK QUICKTEXT_ENABLE "Estou esperando por você.\n"
"--Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Você decide não ler..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você derrotou Poe o fantasma!" BOX_BREAK "Você quer pegá-lo em \n"
"uma garrafa?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você quer pegá-lo, mas você \n"
"não tenha uma garrafa vazia."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você deixa pra lá por agora."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você pegou um Poe!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x04") "O sol nascente acabará por se pôr,\n"
SHIFT("\x19") "A vida de um recém-nascido vai desaparecer." QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x05") "De sol a lua, lua a sol..." QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x25") "Dê um descanso tranquilo a\n"
SHIFT("\x37") "os mortos-vivos." QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Este é um poema interessante...\n"
"Hã?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x24") "Almas inquietas vagam\n"
SHIFT("\x1E") "onde eles não pertencem,\n"
SHIFT("\x27") "acalme-os com\n"
SHIFT("\x36") "a " COLOR(YELLOW) "Canção do Sol" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Algo está inscrito no \n"
"tombstone..." BOX_BREAK UNSKIPPABLE "É a " COLOR(YELLOW) "melodia secreta" COLOR(DEFAULT) " do \n"
"Irmãos Compositores!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Poção definitiva! Que tal\n"
COLOR(RED) "100 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se mudar de ideia, venha \n"
"voltar e me visitar...\n"
"Ei, ei, ei!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem rúpias suficientes!\n"
"Ei, ei, ei!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "GYAAAAH!\n"
TEXT_SPEED("\x02") QUICKTEXT_ENABLE "VOCÊ" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MATADO" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ME..." QUICKTEXT_DISABLE TEXT_SPEED("\x00") QUICKTEXT_ENABLE "Inacreditável!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Ah, o quê?\n"
"Você não é um dos \n de Ganondorf"
"homens, é você?" BOX_BREAK UNSKIPPABLE "Por causa do meu papel como fantasma, eu\n"
"Tive que agir assim. Peço desculpas." BOX_BREAK UNSKIPPABLE "Agora, deixe-me apresentar-me.\n"
"Aham..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou um dos compositores fantasmagóricos \n"
"irmãos da Vila Kakariko." BOX_BREAK "Todas as pessoas desta vila são\n"
"nascido para servir a Família Real de\n"
"Hyrule." BOX_BREAK "Nós irmãos também servimos o Royal \n"
"Família, e foram atribuídos a \n"
"estude o místico hereditário \n"
"poderes da família". BOX_BREAK "Embora nunca pudéssemos descobrir \n"
"o poder da Triforce", BOX_BREAK "estávamos quase completando nosso \n"
COLOR(RED) "estudo de controle de tempo" COLOR(DEFAULT) " com o \n"
"tons de ocarinas." BOX_BREAK "Uh, quero dizer..." BOX_BREAK "Na verdade, concluímos isso \n"
"estudar!" BOX_BREAK "Teríamos sido famosos, se \n"
"aquele odioso Ganondorf não tinha\n"
"tentou roubar nossos resultados." BOX_BREAK "Nós nunca poderíamos deixá-lo colher o \n"
"frutos de nossa pesquisa!" BOX_BREAK "É por isso que demos nossas vidas para \n"
"proteger o segredo." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você quer ouvir o que eu \n"
"disse de novo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") QUICKTEXT_ENABLE "Estou" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORTO" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "A" QUICKTEXT_DISABLE QUICKTEXT_ENABLE "GAIN!" QUICKTEXT_DISABLE TEXT_SPEED("\x00") "\n"
"O quê? Você de novo?" BOX_BREAK UNSKIPPABLE "De alguma forma, você me lembra...\n"
"Princesa Zelda..." BOX_BREAK UNSKIPPABLE "Hmm... Já que você pode ter alguns\n"
"conexão com a Família Real, I\n"
"vai contar um pouco mais da nossa\n"
"conto." BOX_BREAK UNSKIPPABLE "Naquela época, as pessoas nos chamavam de ótimos\n"
"compositores por causa dos muitos \n"
"obras-primas musicais que escrevemos." BOX_BREAK UNSKIPPABLE "Mas nós irmãos não éramos apenas \n"
"compositores". BOX_BREAK UNSKIPPABLE "Tínhamos a missão de analisar o\n"
"poderes misteriosos de Hyrule\n"
"Família real." BOX_BREAK UNSKIPPABLE "Nossos nomes fariam parte de \n"
"A história de Hyrule se pudéssemos \n"
"completar nossa pesquisa!" BOX_BREAK UNSKIPPABLE "Mantivemos nosso estudo extremamente \n"
"segredo até terminarmos." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") QUICKTEXT_ENABLE "Estou" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "MORTO" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "A" QUICKTEXT_DISABLE QUICKTEXT_ENABLE "GAIN!" QUICKTEXT_DISABLE TEXT_SPEED("\x00") "\n"
"O quê? Você de novo?" BOX_BREAK UNSKIPPABLE "De alguma forma, você me lembra\n"
"Princesa Zelda." BOX_BREAK UNSKIPPABLE "Já que você parece ter algum\n"
"conexão com a Família Real, I\n"
"vai contar um pouco mais da nossa\n"
"história." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para falar a verdade, cada um de nós\n"
"estava estudando uma música diferente, uma\n"
"para " COLOR(RED) "convocar o sol" COLOR(DEFAULT) " e outro para\n"
COLOR(RED) "invocar a lua" COLOR(DEFAULT) "." BOX_BREAK "Se você foi realmente enviado por um \n"
"membro da Família Real, eu vou\n"
"falar sobre os resultados do nosso\n"
"estudar." BOX_BREAK "Nós o inscrevemos no " COLOR(RED) "royal\n"
"lápide" COLOR(DEFAULT) "." BOX_BREAK "Como mensageiro da Realeza \n"
"Família, você deve mostrar sua\n"
"Credenciais reais no topo do \n"
"Marca Triforce..." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"ZZ Z..." BOX_BREAK "Malon... indo bem...\n"
"Resmungar... resmungar...\n"
"Desculpe fazer você se preocupar..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo assumiu o Rancho Lon Lon e\n"
"eles chamam de " COLOR(RED) "Ingo Ranch" COLOR(DEFAULT) "hoje em dia." BOX_BREAK "Fui expulso de lá e\n"
"olhe para mim agora! Minha garota, Malon, \n"
"ainda trabalha no rancho..." BOX_BREAK "Estou preocupado com ela..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você salvou Malon? Obrigado!\n"
"Vou voltar para o rancho, então!\n"
"Yeeha!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE "Ei garoto!" QUICKTEXT_DISABLE "\n"
"Não brinque com o \n"
"sepulturas!" BOX_BREAK UNSKIPPABLE "Sou " COLOR(RED) "Dampé the Gravekeeper" COLOR(DEFAULT) "!\n"
"Meu rosto pode ser assustador, mas eu não sou\n"
"um cara mau..." BOX_BREAK UNSKIPPABLE "Deixe-me dar-lhe um anúncio\n"
"para o meu negócio paralelo..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Dampé the Gravekeeper's" COLOR(DEFAULT) "\n"
"Coração de tirar o fôlego" COLOR(LIGHTBLUE) "Tour de escavação de túmulos" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "O que vai sair?!\n"
"O que vai sair?!\n"
"Quando eu começar a cavar,\n"
"nós vamos descobrir!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você quer que eu cave aqui?\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " para um buraco.\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não faça isso" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(RED) "Não, nada aqui!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Volte, " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "....\n"
"Aconteceu uma coisa terrível!\n"
"O " COLOR(RED) "espírito das sombras do mal" COLOR(DEFAULT) " tem\n"
"foi liberado!" BOX_BREAK UNSKIPPABLE COLOR(RED) "Impa" COLOR(DEFAULT) ", o líder de Kakariko\n"
"Vila, selou a sombra maligna\n"
"espírito no fundo do poço..." BOX_BREAK UNSKIPPABLE "Mas a força do espírito maligno\n"
"ficou tão forte, o selo do\n"
"bem quebrou, e escapou para o\n"
"mundo!!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Deixe-me cuidar da vila!\n"
"Estou contando com você,\n"
NAME "!"
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x23") "Royal Composer Bros.\n"
SHIFT("\x37") "Afie o Velho\n"
SHIFT("\x50") "RIP" QUICKTEXT_DISABLE EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x23") "Royal Composer Bros.\n"
SHIFT("\x33") "Flat the Younger\n"
SHIFT("\x50") "RIP" QUICKTEXT_DISABLE EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x28") "Tumba da Família Real" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x1A") "Este poema é dedicado a\n"
"a memória dos falecidos\n"
SHIFT("\x10") "membros da Família Real." EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O menino com a nobre Zelda's \n"
"Ocarina...Como eu esperava, \n"
"você veio." BOX_BREAK UNSKIPPABLE "Eu sou " COLOR(RED) "Impa" COLOR(DEFAULT) ", um dos Sheikah.\n"
"Sou a zeladora da Princesa Zelda,\n"
"e eu também sou o Sábio que\n"
"guarda o Templo das Sombras."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Por favor, cuide da princesa!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME UNSKIPPABLE ", o herói!" BOX_BREAK UNSKIPPABLE "Finalmente, todos nós, os " COLOR(RED) "seis Sábios" COLOR(DEFAULT) ", \n"
"foram acordados!\n"
"A hora do confronto final\n"
"com o Rei do Mal chegou!" BOX_BREAK UNSKIPPABLE "Antes disso, porém, você deve\n"
"encontrar quem está esperando\n"
"você..." BOX_BREAK UNSKIPPABLE "Aquele que está esperando por você às\n"
"a " COLOR(LIGHTBLUE) "Templo do Tempo" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Nós Sheikah servimos o \n"
"realeza de Hyrule de geração\n"
"para geração como atendentes.\n"
"No entanto..." BOX_BREAK UNSKIPPABLE "Naquele dia, sete anos atrás,\n"
"Ganondorf atacou de repente...\n"
"e o Castelo de Hyrule se rendeu\n"
"depois de pouco tempo." BOX_BREAK UNSKIPPABLE "O alvo de Ganondorf era um dos\n"
"as chaves para o Reino Sagrado... o\n"
"tesouro escondido da Realeza\n"
"Família... A Ocarina do Tempo!" BOX_BREAK UNSKIPPABLE "Meu dever me obrigava a levar Zelda \n"
"fora do alcance de Ganondorf." BOX_BREAK UNSKIPPABLE "Quando eu te vi pela última vez, como fizemos\n"
"nossa fuga do castelo, você\n"
"era apenas um rapaz..." BOX_BREAK UNSKIPPABLE "Agora vejo que você se tornou \n"
"um bom herói..."
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu tenho que ficar aqui... Você vai para \n"
"Ao lado da princesa Zelda e proteja \n"
"ela em meu nome." BOX_BREAK UNSKIPPABLE "Agora eu coloco meu poder, que deve \n"
"ser útil para você, para isso\n"
COLOR(BLUE) "Medalhão" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Como está seu Cucco? Ele está feliz?\n"
"Devo dar uma olhada nele para você?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x68\x55") "Eu sou o " COLOR(RED) "chefe dos carpinteiros\n"
COLOR(DEFAULT) "que a Impa contratou para melhorar isso\n"
"aldeia e transformá-la em uma verdadeira\n"
"cidade!" BOX_BREAK UNSKIPPABLE "Mas os jovens de hoje em dia não\n"
"tem alguma ambição...\n"
"Você sabe o que quero dizer, garoto?" BOX_BREAK UNSKIPPABLE "Meus workers estão apenas em execução\n"
"sem rumo ao redor da vila, e\n"
"eles não estão fazendo nenhum progresso\n"
"de todo..." BOX_BREAK UNSKIPPABLE "Até meu próprio filho não tem \n"
"emprego, e ele fica perambulando\n"
"dia todo!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eles são todos inúteis, eu te digo!!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olhe para aquela pobre garota ali.\n"
"Ela trabalha tanto cuidando de \n"
"suas galinhas, mesmo tocando\n"
"eles dão arrepios nela..." BOX_BREAK "Que soldado! Eu realmente \n"
"gostaria de ajudá-la! Acabei de ser\n"
"me sentindo tão caridoso hoje em dia!\n"
"Você não se sente assim também?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não há nada para se preocupar...\n"
"A princesa está segura agora."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Em breve, você conhecerá a Princesa Zelda\n"
"cara a cara, e ela explicará\n"
"tudo..." BOX_BREAK UNSKIPPABLE "Foi quando nós, os seis sábios \n"
"Uns, vão selar o Rei Maligno\n"
"e devolva a paz a Hyrule."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe, jovem...\n"
"Você foi muito rápido para conseguir\n"
"para me acompanhar! Hehehe!" BOX_BREAK UNSKIPPABLE "Como recompensa, vou dar\n"
"você é meu tesouro. Chama-se o\n"
COLOR(RED) "Hookshot" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Sua corrente com mola puxará\n"
"você para qualquer lugar onde seu gancho\n"
"gruda. Isso não parece legal?\n"
"Tenho certeza que vai te ajudar!" BOX_BREAK UNSKIPPABLE "Eu moro aqui agora, então volte\n"
"de novo em algum momento. Eu lhe darei\n"
"algo legal!" BOX_BREAK UNSKIPPABLE "Mais uma coisa! Tenha cuidado ao\n"
"seu caminho de volta!\n"
"Heheheh..."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você voltou, jovem...\n"
"Foi o presente que te dei\n"
"divertido e útil?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "A hora desta corrida foi\n"
SHIFT("\x4B") RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Parece que você está vindo por aí..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Acredito que o Impa foi para o \n"
COLOR(RED) "Templo das Sombras " COLOR(DEFAULT) "para selá-lo novamente,\n"
"mas... ela estará em perigo sem \n"
"qualquer ajuda!" BOX_BREAK NAME UNSKIPPABLE "!\n"
"Impa é um dos seis Sábios.\n"
"Destrua o espírito maligno das sombras e\n"
"salve Impa!" BOX_BREAK UNSKIPPABLE "Há uma entrada para o \n"
"Templo das Sombras sob o \n"
"cemitério atrás desta aldeia." BOX_BREAK UNSKIPPABLE "A única coisa que posso fazer por você é\n"
"ensinar a melodia que vai\n"
"levar você ao Templo das Sombras..." BOX_BREAK UNSKIPPABLE "Esta é a melodia que irá desenhar\n"
"você na escuridão infinita \n"
"que absorve até o tempo... Ouça \n"
"este, o " COLOR(RED) "Noturno das Sombras" COLOR(DEFAULT) "!!"
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vá ao redor! Dê a volta e ao redor\n"
"e por aí! Que divertido! Eu sou tão \n"
"feliz!" BOX_BREAK "Sou um homem da música que adora\n"
"dar voltas e voltas!\n"
"Vá ao redor e ao redor!!!" BOX_BREAK "Estou tentando criar um\n"
"tema musical inspirado neste \n"
"moinho de vento... dando uma volta e\n"
"ao redor e ao redor!!!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dar uma volta, uma volta, uma volta...\n"
"O quê? Está indo rápido demais!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrr!" BOX_BREAK "Nunca esquecerei o que aconteceu em\n"
"naquele dia, sete anos atrás!\n"
"Grrrrrrrr!" BOX_BREAK "É tudo culpa daquela criança Ocarina!\n"
"Na próxima vez que ele vier aqui,\n"
"Eu vou estragar ele!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O quê?! Você tem uma ocarina!!" BOX_BREAK UNSKIPPABLE "Que diabos!" BOX_BREAK UNSKIPPABLE "Isso me lembra daquela época,\n"
"sete anos atrás!" BOX_BREAK UNSKIPPABLE "Naquela época, um garoto malvado veio aqui \n"
"e tocou uma " COLOR(PURPLE) "canção estranha" COLOR(DEFAULT) ". É \n"
"estraguei este moinho de vento!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que devo fazer!?\n"
"Meu " COLOR(RED) "Cuccos" COLOR(DEFAULT) " todos voaram para longe!" BOX_BREAK "Você, garotinho, por favor!\n"
"Por favor, ajude-me a trazê-los de volta para \n"
"esta caneta!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor, me ajude a trazer o outro \n"
"quatro de volta para esta caneta! Por favor!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor, me ajude a trazer o outro \n"
"três de volta para esta caneta! Por favor!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor, me ajude a trazer o outro \n"
"dois de volta para esta caneta! Por favor!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor, ajude-me a trazer o último\n"
"volta para esta caneta! Por favor!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado por encontrar meus Cuccos.\n"
"Eu tenho alergia, então fico com \n"
"arrepios quando eu os toco." BOX_BREAK UNSKIPPABLE "Por me ajudar, darei isto\n"
"para você. É vidro fino e deve\n"
"seja útil. Por favor, aceite\n"
"Cuide disso!" EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o que você está fazendo?!\n"
"Agora arredonde-os ou pague por \n"
"eles!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, não provoque meus Cuccos!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu criei um novo tipo de miniatura \n"
"Cucco! Eu chamo isso de " COLOR(RED) "Bolso \n"
"Cucco" COLOR(DEFAULT) "! Não fico arrepiado\n"
"deste bebê." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Cuccos " COLOR(DEFAULT) "são muito bons em \n"
"tirar da cama os preguiçosos e madrugadores.\n"
"Você não ouviu falar deles \n"
"antes?" BOX_BREAK UNSKIPPABLE "Eles ficam muito felizes em cantar:\n"
QUICKTEXT_ENABLE SHIFT("\x38") COLOR(RED) "CUCCKOOOO" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"especialmente quando acorda um \n"
"dormir muito pesado!" BOX_BREAK UNSKIPPABLE "No entanto, meu Cucco não é totalmente\n"
"feliz agora..." BOX_BREAK UNSKIPPABLE "Você..., \n"
"Você parece ser bom em \n"
"manuseando Cuccos." BOX_BREAK UNSKIPPABLE "Aqui, pegue este ovo.\n"
"Depois que o Cucco chocar, traga-o \n"
"volte para mim depois de um tempo, e eu vou \n"
"verifique seu humor." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você acha? \n"
"Você vai tentar?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, que pena... você foi bicado por\n"
"um Cucco quando você era pequeno?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh, jovem!\n"
"Você é rápido em seus pés?" BOX_BREAK "Posso não parecer, mas sou \n"
"confiante na minha velocidade!\n"
"Vamos fazer uma corrida! \n"
"Siga-me se você se atreve!"
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, faça meu Cucco feliz!\n"
"OK?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, seu Cucco está lindo \n"
"feliz! Ele deve ter acordado um\n"
"cara extremamente preguiçoso!" BOX_BREAK UNSKIPPABLE "Você é um bom Cucco Keeper!\n"
"Eu lhe darei um raro e valioso\n"
"Cucco, se você estiver interessado..." BOX_BREAK UNSKIPPABLE "Seu nome é " COLOR(RED) "Cojiro" COLOR(DEFAULT) "," COLOR(RED) " " COLOR(DEFAULT) "e costumava\n "
"seja o Cucco do meu irmão. É\n"
"corpo azul é muito charmoso.\n"
"É tão fofo!" BOX_BREAK UNSKIPPABLE "Desde que meu irmão se foi, \n"
"é estranho, mas Cojiro tem \n"
"parou de cantarolar." TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Deseja manter " COLOR(RED) "Cojiro" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que você realmente gosta disso\n"
"outro Cucco. OK, pode ficar com ele\n"
"por um tempo." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uma bruxa velha administra a Loja de Poções\n"
"atrás deste. Você pode chegar a \n"
"aquela loja na porta da\n"
"esquerda do balcão." EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu irmão deve ter sido muito \n"
"sozinho..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvi dizer que " COLOR(ADJUSTABLE) "Bosque Perdido" COLOR(DEFAULT) ", \n"
"onde as fadas vivem, é um estranho\n"
"lugar com muitos cheiros misteriosos." BOX_BREAK "Gostaria de poder fazer apenas uma vez \n"
"medicina com alguns dos estranhos\n"
"coisas que posso encontrar lá..." BOX_BREAK "Talvez eu não consiga ver muito \n"
"bem mais, mas meu nariz ainda \n"
"funciona bem! Hehehe!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cheirar cheirar cheirar..." BOX_BREAK "Que cheiro misterioso..." BOX_BREAK "Você deve ter alguma coisa!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele vagabundo! Ele teve que entrar no \n"
"floresta...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "Entendo." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, dê para mim agora!\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que triste... eu só preciso de um pouco..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Se você ver aquele idiota, dê isso para \n"
"ele. É o remédio mais forte\n"
"Eu já produzi." BOX_BREAK UNSKIPPABLE "No entanto, esta poção não irá\n"
"trabalhar em um monstro..." EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ei, garoto! Se você quiser carregar \n"
"medicina, você precisa de um recipiente para\n"
"coloque dentro!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dizem que não existe \n"
"remédio que pode curar um tolo...\n"
"Acho que é verdade..."
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não consigo descer, então tudo o que posso fazer\n"
"é olhe para " COLOR(RED) "Monte da Morte" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não consigo descer, então tudo o que posso fazer \n"
"é olhar para as estrelas."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você consegue ver de lá? \n"
"Algo está acontecendo em " COLOR(RED) "Morte \n"
"Montanha" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você consegue ver de lá?\n"
COLOR(RED) "Monte da Morte" COLOR(DEFAULT) "está de volta ao normal!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não estou com vontade de descer,\n"
"sempre! Aconteça o que acontecer, eu manterei\n"
"assistindo a Montanha da Morte de \n"
"aqui em cima."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei! Bom ver você de novo! Vou\n"
"dar-lhe isso como uma lembrança."
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para obter uma boa visualização, use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " e \n"
"olhe em volta com " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Garoto, você sempre entra\n"
"casas de outras pessoas sem \n"
"permissão? Seus pais não \n"
"ensinar-lhe boas maneiras?" BOX_BREAK UNSKIPPABLE SHIFT("\x42") "Ah, bem." BOX_BREAK UNSKIPPABLE "Você viu uma senhora por trás disso \n"
"casa? Ela está passando por dificuldades \n"
"vezes". BOX_BREAK UNSKIPPABLE SHIFT("\x42") "Ah, bem." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se aquela senhora lhe perguntar sobre \n"
"frangos, você deve ouvi-la."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Está visitando a casa de outras pessoas \n"
"a esta hora tardia sua ideia de \n"
"divertido? Você não deve ter tido um \n"
"boa educação". BOX_BREAK UNSKIPPABLE SHIFT("\x42") "Ah, bem." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquela senhora cuida das galinhas,\n"
"mas ela é, na verdade, alérgica a \n"
"eles." BOX_BREAK SHIFT("\x42") "Bem."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Jovem! Um menino adulto\n"
"como você entrando na casa de uma pessoa\n"
"sem permissão?! Eu quero\n"
"fale com seus pais!" BOX_BREAK UNSKIPPABLE SHIFT("\x42") "Ah, bem." BOX_BREAK UNSKIPPABLE "Esta não é minha casa mesmo.\n"
"Esta é a casa " COLOR(RED) "do grande Impa" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "O grande Impa foi para o\n"
COLOR(RED) "cemitério" COLOR(DEFAULT) "para selar o \n"
"criatura gigantesca lá." BOX_BREAK UNSKIPPABLE "Desde que Ganondorf apareceu, muitos \n"
"monstros foram avistados \n"
"por aqui." BOX_BREAK UNSKIPPABLE "Só o grande Impa manteve \n"
"paz em nossa aldeia. Você tem que\n"
"Lembre-se disso, jovem!" BOX_BREAK UNSKIPPABLE SHIFT("\x42") "Ah, bem." BOX_BREAK UNSKIPPABLE "Falando na grande Impa, ela\n"
"ainda não voltou. Será que \n"
"o que aconteceu com ela?" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ouvi dizer que o " COLOR(RED) "fantasma do\n"
"gravekeeper " COLOR(DEFAULT) "frequentemente aparece no \n"
"cemitério atrás desta vila..." BOX_BREAK SHIFT("\x34") "Mas, nada demais."
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olá, rapaz! É a primeira vez\n"
"você visitou esta aldeia?" BOX_BREAK UNSKIPPABLE "Uma grande mulher, " COLOR(RED) "Impa" COLOR(DEFAULT) ", abriu\n"
"esta aldeia para nós, pobres." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, sinta-se em casa.\n"
"A comida ainda não está pronta, no entanto."
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O grande Impa não está aqui. Será que\n"
"algo aconteceu com ela?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Todas as pessoas têm dificuldades em \n"
"seu passado que eles fariam\n"
"em vez disso, ninguém descobriu." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Olha o barbudo dormindo\n"
"lá. Aposto que até alguém\n"
"como ele teve sua parte de\n"
"problemas no passado..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquele barbudo voltou para \n"
"o rancho. Ele parecia tão feliz!"
)

DEFINE_MESSAGE(0x5063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ding dong, ding dong!\n"
"Sou um soldado relógio de Kakariko!\n"
"A hora atual é: " TIME "." BOX_BREAK UNSKIPPABLE "Olá, filho.\n"
"Atendente de Zelda, a grande " COLOR(RED) "Impa" COLOR(DEFAULT) ",\n"
"abriu esta aldeia ao comum\n"
"pessoas." BOX_BREAK UNSKIPPABLE "Temos apenas uma pequena população \n"
"agora, mas um dia esse lugar vai \n"
"ser tão animado quanto o Castelo de Hyrule \n"
"Cidade! Oh, sim! Vai!" BOX_BREAK UNSKIPPABLE "Suba as escadas " COLOR(RED) "ao norte\n"
COLOR(DEFAULT) "final da vila para encontrar a trilha\n"
"que leva até a Montanha da Morte." BOX_BREAK UNSKIPPABLE "Mas você precisa da permissão do Rei\n"
"realmente subir a montanha."
)

DEFINE_MESSAGE(0x5064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME "."
)

DEFINE_MESSAGE(0x5065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME ".\n"
"A propósito, você sabe o que \n"
"aconteceu no castelo?"
)

DEFINE_MESSAGE(0x5066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, filho, o que você está fazendo \n"
"vagando por aí tão tarde às \n"
"noite?" BOX_BREAK UNSKIPPABLE "Ah, entendi. Você está testando seu\n"
"coragem, não é? Você deve \n"
"quer ir para... um cemitério!" BOX_BREAK UNSKIPPABLE "Espere um minuto! O que estou fazendo\n"
"conversando com uma criança? Tenho trabalho para\n"
"faça! Trabalhe! Trabalhe!" TEXTID("\x50\x67")
)

DEFINE_MESSAGE(0x5067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ding dong, ding dong!\n"
"A hora atual é: " TIME "." BOX_BREAK "Vá para o leste e você encontrará um\n"
COLOR(RED) "cemitério" COLOR(DEFAULT) ". As lendas dizem que você pode \n"
"acalmar as almas dos mortos com\n"
"uma " COLOR(BLUE) "canção antiga da Família Real" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tem um cara estranho morando no \n"
"Moinho de vento. Você já conheceu\n"
"ele, Sr. Herói?"
)

DEFINE_MESSAGE(0x5069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As pessoas são nojentas. \n"
"Meu próprio pai e minha mãe são\n"
"nojento.\n"
"Você deve ser nojento também!"
)

DEFINE_MESSAGE(0x506A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Durante todo o dia, estamos trabalhando em \n"
"muitos projetos de construção no\n"
"aldeia. Vai demorar um pouco\n"
"antes de tudo estar feito." BOX_BREAK "Nosso chefe trabalha muito conosco!"
)

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Estou morrendo de fome!\n"
"Vamos jantar, agora!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esses caras fazem o trabalho de \n"
"meio homem, mas eles ainda querem um\n"
"porção de homem completo!\n"
"Eles são preguiçosos preguiçosos, eu te digo!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Poe 30 Rupees\n"
COLOR(DEFAULT) "Este é um espírito fantasma engarrafado. \n"
"Venda para um louco \n"
"sobre coisas estranhas como esta." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Pegue 30 rúpias" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x506F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"506f"
)

DEFINE_MESSAGE(0x5070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meus Cuccos fugiram!\n"
"Por favor, pegue mais seis!"
)

DEFINE_MESSAGE(0x5071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) NAME "!\n"
"Este navio está afundando!\n"
"Abandonar o navio!\n"
"Entre em uma plataforma segura!" COLOR(DEFAULT) QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x5072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ainda estou sentindo falta de alguns Cuccos!\n"
"Por favor, reúna mais cinco!"
)

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Não cause problemas!\n"
"Vou contar a Dampé!" QUICKTEXT_DISABLE FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Olhe para isso, garoto! Minha linda,\n"
"mãos lisas estão todas desgastadas \n"
"de trabalhar.
)

DEFINE_MESSAGE(0x5075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Um trabalho onde você pode ganhar muito\n"
"de dinheiro sem muito esforço...\n"
"A única coisa que consigo pensar é\n"
"Ladrão... Isso é uma má ideia?"
)

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ouvi dizer que a casa do nosso chefe é\n"
"atrás desta casa. Ele não\n"
"Quero que qualquer um de nós saiba, no entanto."
)

DEFINE_MESSAGE(0x5077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você viu " COLOR(RED) "Sr. Dampé" COLOR(DEFAULT) ", quem\n"
"vive no cemitério à frente?" BOX_BREAK "É " HORA " agora, então ele está\n"
"provavelmente dormindo em sua cabana." BOX_BREAK "Por que você não sai para o \n"
"campo e matar algum tempo?"
)

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Estou morrendo de fome!\n"
"O jantar ainda não está pronto?\n"
"Já é " HORA "!"
)

DEFINE_MESSAGE(0x5079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Esta costumava ser a " COLOR(RED) "ótima \n"
"Casa da Impa" COLOR(DEFAULT) ", mas ela não\n"
"viva mais aqui." BOX_BREAK UNSKIPPABLE "Agora está aberto a todos \n"
"aldeões. Você é livre para\n"
"entre." TEXTID("\x50\x7A")
)

DEFINE_MESSAGE(0x507A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta vila costumava ser uma \n"
COLOR(BLUE) "Shiekah" COLOR(DEFAULT) "aldeia, mas o \n"
"grande Impa abriu para \n"
"todos."
)

DEFINE_MESSAGE(0x507B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu lhe digo, eu o vi!" BOX_BREAK "Eu vi a figura fantasmagórica de Dampé\n"
"o coveiro afundando\n"
"seu túmulo. Parecia que ele era\n"
"segurando algum tipo de " COLOR(RED) "tesouro" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x507C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lá está ele! É ele!\n"
"Ele é aquele que caiu de\n"
"o céu cercado por um azul\n"
"leve!" BOX_BREAK "Agora você acredita em mim?"
)

DEFINE_MESSAGE(0x507D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ninguém acredita no que eu fui\n"
"contar a todos esses passados \n"
"sete anos!"
)

DEFINE_MESSAGE(0x507E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O fogo quase consumiu todos nós!\n"
"Mas juntos, todos nós conseguimos\n"
"apagar o fogo! Muito bom\n"
"trabalho, você não acha?"
)

DEFINE_MESSAGE(0x507F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, ah, ah, ah, ah, ah!" BOX_BREAK "Olhe para esse cara! Desde\n"
"ele escapou do Castelo de Hyrule\n"
"Cidade, ele se tornou ainda mais\n"
"tímido!"
)

DEFINE_MESSAGE(0x5080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, ah, ah, ah, ah, ah!" BOX_BREAK "Ele deve estar vendo coisas!\n"
"Ah, ah, ah, ah, ah, ah!"
)

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau há há há há há!\n"
"Esses são uns engraçados\n"
"roupas, cara!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Uau há há há há há!\n"
"Quando os tempos são difíceis, o riso é\n"
"o melhor remédio!\n"
"Isso é o que meu pai sempre disse!"
)

DEFINE_MESSAGE(0x5083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olhe para mim! Estou no topo do \n"
"mundo! Me incomoda muito ver\n"
"alguém em um nível mais alto que eu\n"
"Sou! Eu tenho que estar no topo!"
)

DEFINE_MESSAGE(0x5084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu dormir aqui em cima, vou\n"
"certamente cairá..."
)

DEFINE_MESSAGE(0x5085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O moinho de vento puxa água de \n"
"a profundidade do poço." BOX_BREAK "Agora o poço está seco.\n"
"Hrrrrm..."
)

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A senhora aqui é realmente\n"
"generosa. Ela até cuidou de\n"
"os carpinteiros quando eram\n"
"aqui!"
)

DEFINE_MESSAGE(0x5087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Há muito tempo...\n"
"Havia um homem nesta\n"
"aldeia que tinha um olho disseram\n"
"poderia ver a verdade!" BOX_BREAK "Agora, normalmente, você tem que treinar\n"
"o olho da sua mente mais vigorosamente\n"
"para realmente ver a verdade..." BOX_BREAK "Mas esse cara, não, eles dizem que ele\n"
"tinha um jeito diferente de fazer\n"
"coisas..." BOX_BREAK "A casa dele ficava onde fica o poço\n"
"agora..."
)

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"As pessoas por aqui falam de um\n"
COLOR(RED) "família fabulosamente rica" COLOR(DEFAULT) "que uma vez\n"
"morava em uma das casas desta\n"
"village..." BOX_BREAK "Mas eles dizem que todo\n"
"família foi amaldiçoada devido aos seus\n"
"ambição!" BOX_BREAK "Quem sabe o que pode acontecer com\n"
"aqueles que são consumidos por\n"
"ambição..."
)

DEFINE_MESSAGE(0x5089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh..." BOX_BREAK "Que pessoa chata,\n"
"nos interrompendo assim...\n"
"Você não concorda, meu amor?"
)

DEFINE_MESSAGE(0x508A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee..." BOX_BREAK "Violando nosso espaço pessoal!\n"
"Ele deve ter algo melhor\n"
"fazer...\n"
"Você não concorda, querida?"
)

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Olhe para ele... o homem com o\n"
"barba. Acho que ele foi demitido de\n"
"seu trabalho no rancho..." TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ele está sempre descansando, \n"
"manhã, tarde e noite. \n"
"Ele é um cara terrivelmente despreocupado \n"
"durante tempos tão difíceis."
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Aquele homem preguiçoso, ele meio que \n"
"me lembrou do meu pequeno Richard..." BOX_BREAK "O que é isso? Você diz que\n"
"nunca ouviu falar do meu pequeno Richard?\n"
"Ele era um cachorrinho tão famoso! Você \n"
"sério não ouviu falar dele?"
)

DEFINE_MESSAGE(0x508E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, não! Uma tempestade de novo!!\n"
"Você tocou a Ocarina novamente,\n"
"você não!!\n"
"Grrrrrrrrrrrrrrrrrrrrrrrrrrrrr!!"
)

DEFINE_MESSAGE(0x508F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Você pegou um Big Poe!\n"
"Venda na " COLOR(RED) "Ghost Shop" COLOR(DEFAULT) "por um\n"
"muito dinheiro!"
)

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Pare! Fique onde está!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, recém-chegado!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato! Espere um segundo \n"
"e eu vou abrir o portão para você."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Não nos leve tão a sério!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Vi seu bom trabalho. Para obter \n"
"passar pelos guardas aqui, você deve \n"
"ter boas habilidades de ladrão." BOX_BREAK UNSKIPPABLE "Eu costumava pensar que todos os homens, \n"
"além do grande Ganondorf, foram \n"
"inútil... mas agora que eu vi\n"
"você, eu não acho mais!" BOX_BREAK UNSKIPPABLE COLOR(RED) "O exaltado Nabooru" COLOR(DEFAULT) ", nosso líder, \n"
"coloque-me no comando desta fortaleza." BOX_BREAK UNSKIPPABLE "Nabooru é o segundo em comando\n"
"ao grande Ganondorf, Rei de \n"
"os Ladrões Gerudo." BOX_BREAK UNSKIPPABLE "Seu quartel-general está no " COLOR(YELLOW) "Espírito\n"
"Templo" COLOR(DEFAULT) ", que está no final do \n"
"deserto." BOX_BREAK UNSKIPPABLE "Diga, você deve querer se tornar \n"
"um de nós, hein?\n"
"Tudo bem, então!\n"
"Você está dentro de agora em diante!" BOX_BREAK UNSKIPPABLE "Pegue isso. Com isso, você\n"
"ter acesso gratuito a todas as áreas de\n"
"a Fortaleza!" EVENT
)

DEFINE_MESSAGE(0x6005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A partir de agora, você está livre para vir\n"
"e vá como quiser pelo \n"
"porta para o deserto". BOX_BREAK "Você encontrará o " COLOR(YELLOW) "Spirit Temple" COLOR(DEFAULT) "," COLOR(YELLOW) " \n"
COLOR(DEFAULT) "onde o exaltado Nabooru vive,\n"
"lá fora no deserto."
)

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Garoto estúpido!" QUICKTEXT_DISABLE "\n"
"Entra aí e fica quieto!"
)

DEFINE_MESSAGE(0x6007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Não faço ideia de onde você \n"
"vem de, mas você deve ter um\n"
"muita coragem para superar tudo\n"
"os guardas por aqui!" BOX_BREAK UNSKIPPABLE "Todos os meus colegas carpinteiros\n"
"estão presos em algum lugar aqui." BOX_BREAK UNSKIPPABLE "Se você puder nos tirar daqui,\n"
"vamos retribuir o favor de alguma forma!" BOX_BREAK UNSKIPPABLE "Mas tenha cuidado! Com certeza\n"
"ser " COLOR(RED) "Gerudo " COLOR(DEFAULT) "guarda em algum lugar \n"
TEXT_SPEED("\x02") QUICKTEXT_ENABLE "ao redor" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "aqui" QUICKTEXT_DISABLE "...." TEXT_SPEED("\x00") BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE "Uau!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Cuidado!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6008, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x2E") "A entrada para o passado" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6009, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x24") "A entrada para o presente" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE SHIFT("\x24") "A entrada para o futuro" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX("\x38\xEC") "Serei seu guia no seu caminho,\n"
"mas voltando, não vou jogar!\n"
"Vou mostrar a você o único caminho a seguir,\n"
"então siga-me e não seja lento!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Passado, presente, futuro..." BOX_BREAK UNSKIPPABLE "A Master Sword é uma nave com \n"
"que você pode navegar rio acima e\n"
"a jusante pelo rio do tempo..." BOX_BREAK UNSKIPPABLE "O porto desse navio está no\n"
"Templo do Tempo..." BOX_BREAK UNSKIPPABLE "Para restaurar o Colosso do Deserto\n"
"e digite a " COLOR(YELLOW) "Templo do Espírito" COLOR(DEFAULT) ", você\n"
"deve viajar de volta no tempo\n"
"flow..." BOX_BREAK UNSKIPPABLE "Ouça este " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "...\n"
"Esta melodia levará uma criança de volta\n"
"para o deserto".
)

DEFINE_MESSAGE(0x600D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sou o mestre Gerudo de \n"
"tiro com arco a cavalo! Em cima de \n"
"isso, eu sou o mestre Gerudo de\n"
"cavalgando!" BOX_BREAK "Quer experimentar tiro com arco a cavalo\n"
"for " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x600E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem coragem - eu gosto de você. \n"
"Me siga."
)

DEFINE_MESSAGE(0x600F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está fora de questão se você \n"
"não tem um cavalo!"
)

DEFINE_MESSAGE(0x6010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Não terei nada a ver com um\n"
"covarde como você!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, você não é tão bom quanto \n"
"Reivindicação. Talvez da próxima vez."
)

DEFINE_MESSAGE(0x6012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você fez bem." BOX_BREAK "Por hoje, admito que perdi. \n"
"Parece que tenho muito espaço para \n"
"melhoria."
)

DEFINE_MESSAGE(0x6013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta é o " COLOR(RED) "Treinamento do Gerudo" COLOR(DEFAULT) "\n"
COLOR(DEFAULT) "." BOX_BREAK "Ninguém tem permissão para entrar \n"
"sem cartão de sócio."
)

DEFINE_MESSAGE(0x6014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Este é o " COLOR(RED) "Treinamento do Gerudo" COLOR(DEFAULT) "\n"
COLOR(DEFAULT) "." BOX_BREAK "Cartão de membro verificado." BOX_BREAK "Uma tentativa por 10 rúpias!\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Experimentar\n"
"Não tente" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem, eu aceito suas 10 rúpias.\n"
"Dê o seu melhor!" EVENT
)

DEFINE_MESSAGE(0x6016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não tem dinheiro suficiente!\n"
QUICKTEXT_ENABLE "Volte novamente." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, novato!" BOX_BREAK UNSKIPPABLE "Você vai para o deserto?\n"
"Vou abrir este portão para você, mas..." BOX_BREAK UNSKIPPABLE "Você não pode atravessar o deserto \n"
"a menos que você passe nas " COLOR(RED) "duas tentativas" COLOR(DEFAULT) "." TEXTID("\x60\x18")
)

DEFINE_MESSAGE(0x6018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O primeiro teste é... o " COLOR(RED) "Rio de \n"
"Areia" COLOR(DEFAULT) "! Você não pode atravessar isso\n"
"rio! Depois de atravessá-lo, siga\n"
"as bandeiras que colocamos lá." BOX_BREAK "O segundo teste é... o " COLOR(RED) "Fantasma\n"
"Guia" COLOR(DEFAULT) "!" BOX_BREAK "Aqueles sem olhos " COLOR(RED) "que podem ver\n"
"a verdade " COLOR(DEFAULT) "só se encontrará\n"
"voltando aqui." BOX_BREAK "Você vai mesmo assim, não vai?\n"
"Eu não vou impedir você...\n"
"Vá em frente!" EVENT
)

DEFINE_MESSAGE(0x6019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Por que você veio todos os\n"
"caminho para cá? O quê? Você estava\n"
"está prestes a me perguntar o mesmo \n"
"coisa?" TEXTID("\x60\x1A")
)

DEFINE_MESSAGE(0x601A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, agora que você está aqui, \n"
"você também pode tirar o melhor proveito de \n"
"coisas!"
)

DEFINE_MESSAGE(0x601B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bom garoto! Obrigado!\n"
"Lamento não poder dar a você\n"
"algo tão bom em troca, mas...\n"
"tome isso de qualquer maneira!"
)

DEFINE_MESSAGE(0x601C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"601C"
)

DEFINE_MESSAGE(0x601D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu não vi você por aí, garoto..." BOX_BREAK "O que você quer?\n"
THREE_CHOICE COLOR(ADJUSTABLE) "Para ver o templo\n"
"Procurando os Sábios\n"
"Nada, realmente" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x601E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é apenas uma criança! O templo é\n"
"não há lugar para crianças!"
)

DEFINE_MESSAGE(0x601F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Um Sábio? Não conheço ninguém\n"
"Curtiu isso."
)

DEFINE_MESSAGE(0x6020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você não tem nada para fazer? O que \n"
"bom momento! Você pode me fazer um \n"
"favor, garoto?" BOX_BREAK UNSKIPPABLE "Espere um segundo, quero perguntar a você\n"
"primeiro--você não seria\n"
"um dos seguidores de Ganondorf..." BOX_BREAK "seguidores... você faria?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "E se eu for?\n"
"Eu odeio Ganondorf!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "U-ha-ha!\n"
"Não tente parecer legal, garoto.\n"
"Eu só estava perguntando!" BOX_BREAK UNSKIPPABLE "Uma criança como você nunca poderia ser\n"
"um dos seguidores de Ganondorf!" BOX_BREAK UNSKIPPABLE "Bem, vamos direto ao assunto..." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Uh-huh!" BOX_BREAK UNSKIPPABLE "Você tem coragem.\n"
"Eu acho que eu gosto de você." TEXTID("\x60\x23")
)

DEFINE_MESSAGE(0x6023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Antes de mais nada, deixe-me apresentar \n"
"eu mesmo. Eu sou " COLOR(RED) "Nabooru " COLOR(DEFAULT) "do Gerudo.\n"
"Eu sou um ladrão lobo solitário." BOX_BREAK UNSKIPPABLE "Mas não me entenda mal!" BOX_BREAK UNSKIPPABLE "Embora nós dois sejamos ladrões, eu sou \n"
"completamente diferente de\n"
"Ganondorf." BOX_BREAK UNSKIPPABLE "Com seus seguidores, ele roubou\n"
"de mulheres e crianças, e ele \n"
"até matou pessoas!" BOX_BREAK UNSKIPPABLE "Uma criança como você pode não saber disso, \n"
"mas a corrida Gerudo consiste apenas\n"
"de mulheres. Apenas um homem nasce\n"
"a cada cem anos..." BOX_BREAK UNSKIPPABLE "Mesmo que nossas leis digam isso\n"
"Gerudo macho solitário deve se tornar\n"
"Rei do Gerudo, eu nunca vou\n"
"curvar-se a um homem tão mau!" BOX_BREAK UNSKIPPABLE "A propósito, qual é o seu nome, \n"
"miúdo?" BOX_BREAK UNSKIPPABLE  NAME "?!" BOX_BREAK UNSKIPPABLE "Que tipo de nome é esse?\n"
"Bem... de qualquer forma..." TEXTID("\x60\x24")
)

DEFINE_MESSAGE(0x6024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Quero te pedir um favor..." BOX_BREAK UNSKIPPABLE "Você vai passar por este buraco minúsculo\n"
"e pegar um tesouro que está dentro?" BOX_BREAK UNSKIPPABLE "O tesouro é a " COLOR(BLUE) "Prata\n"
"Manoplas" COLOR(DEFAULT) ". Se você as equipar, você\n"
"pode facilmente empurrar e puxar muito \n"
"coisas pesadas!" BOX_BREAK UNSKIPPABLE "Não, não, não, garoto! Nem pense\n"
"sobre levar este tesouro para \n"
"você mesma!" BOX_BREAK UNSKIPPABLE "As Manoplas de Prata não cabem em\n"
"garotinho como você se você tentar \n"
"equipe-os! Quero que você seja um \n"
"bom menino e dá-los para mim!" BOX_BREAK UNSKIPPABLE "Ganondorf e seus lacaios são\n"
"usando o Templo Espiritual como \n"
"esconderijo." BOX_BREAK UNSKIPPABLE "Apenas as Manoplas de Prata \n"
"permita-me mergulhar fundo no\n"
"têmpora." BOX_BREAK UNSKIPPABLE "Uma vez lá, vou roubar tudo\n"
"o tesouro dentro e bagunça\n"
"seus planos!" BOX_BREAK "Que tal? Você vai fazer isso?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado, garoto!" BOX_BREAK UNSKIPPABLE "Você e eu, vamos dar a Ganondorf\n"
"e seus seguidores uma grande surpresa,\n"
"devemos?" TEXTID("\x60\x26")
)

DEFINE_MESSAGE(0x6026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você conseguir obter o \n"
COLOR(BLUE) "Manoplas Prateadas" COLOR(DEFAULT) "..." BOX_BREAK "Vou fazer algo grande" COLOR(RED) " " COLOR(DEFAULT) "para você!"
)

DEFINE_MESSAGE(0x6027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, o que eu esperava?\n"
"Afinal, você é apenas uma criança!"
)

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei! Aonde você está me levando?!"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ho ho ho!\n"
"Parece que alguém está aqui, Koume."
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Hee hee hee!\n"
"Parece que sim, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Que sujeito ultrajante ele é,\n"
"intrometer-se com tanta ousadia em nosso \n"
"Templo...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Devemos ensinar isso ultrajante\n"
"companheiro de aula!\n"
"Ei, ei, ei!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Oh, lacaio leal..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Destrua este intruso em \n"
"nosso nome!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Grande Ganondorf... Inimigo...\n"
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
"mas ela comanda muito \n"
"respeito entre os Gerudo, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Talvez devêssemos fazê-la trabalhar\n"
"pelo grande Ganondorf para\n"
"mais um pouco!\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então devemos fazer uma lavagem cerebral nela\n"
"de novo!\n"
"Ei, ei, ei!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto, deixe-me agradecer." BOX_BREAK UNSKIPPABLE "Heheheh... olha só que coisa\n"
"o garoto se tornou nos últimos sete\n"
"anos - um espadachim competente!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
"Se eu soubesse que você se tornaria \n"
"um homem tão bonito..." BOX_BREAK_DELAYED("\x50") "Eu deveria ter cumprido a promessa\n"
"Eu fiz naquela época..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Aqui, eu vou te dar " COLOR(RED) "esta" COLOR(DEFAULT) "...\n"
"É uma coisa muito importante para mim.\n"
"Vamos ter uma competição mais tarde!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "...até mais!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A propósito..." BOX_BREAK UNSKIPPABLE "Eu realmente estraguei tudo..." BOX_BREAK UNSKIPPABLE "Eu sofri lavagem cerebral por aqueles velhos\n"
"bruxas e usado por Ganondorf para\n"
"faça o mal dele..." BOX_BREAK UNSKIPPABLE "Mas não é engraçado? Isso é uma pessoa\n"
"como eu poderia vir a ser o\n"
COLOR(YELLOW) "Sábio do Espírito" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "E agora vou lutar\n"
"eles como um dos seis Sábios!\n"
"Heh heh..." BOX_BREAK UNSKIPPABLE "Vou pagá-los de volta por\n"
"o que eles fizeram comigo!"
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Garoto..." BOX_BREAK UNSKIPPABLE "Não...\n"
NAME ", o Herói do Tempo!" BOX_BREAK UNSKIPPABLE "Ao invés de manter a promessa eu\n"
"feito naquela época, eu te dou isso\n"
COLOR(YELLOW) "Medalhão" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Pegue!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x12") "Yeearggh!" QUICKTEXT_DISABLE "Deixe-me ir!!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE SHIFT("\x33") "Você, " QUICKTEXT_ENABLE "seus demônios!" QUICKTEXT_DISABLE "\n"
SHIFT("\x29") "Os lacaios de Ganondorf!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x1E") NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x20") "Saia daqui! Agora!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x0C") "Essas bruxas! Elas estão usando\n"
SHIFT("\x2B") "magia negra em mim!"
)

DEFINE_MESSAGE(0x603F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato! Este é o nosso \n"
COLOR(RED) "campo de tiro com arco a cavalo" COLOR(DEFAULT) "." BOX_BREAK "Depois de muita prática e\n"
"treinamento, finalmente temos a habilidade\n"
"acertar no alvo enquanto cavalga\n"
"como o vento!" BOX_BREAK "Quando você finalmente aprender a andar de bicicleta\n"
"um cavalo, você deveria voltar\n"
"e experimente. É um esporte perigoso,\n"
"Mas é divertido!"
)

DEFINE_MESSAGE(0x6040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato, você tem um bom \n"
"cavalo!" BOX_BREAK "Não sei onde você roubou \n"
"de, mas..." BOX_BREAK "OK, que tal desafiar isso \n"
COLOR(RED) "tiro com arco a cavalo" COLOR(DEFAULT) "?" BOX_BREAK "Assim que o cavalo começar a galopar,\n"
"atirar nos alvos com seu\n"
"setas." BOX_BREAK "Vamos ver quantos pontos você \n"
"pode marcar. Você ganha 20 flechas." BOX_BREAK "Se você conseguir marcar " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) ", I\n"
"vai dar-lhe algo bom!" EVENT
)

DEFINE_MESSAGE(0x6041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você quer tentar " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, novato!\n"
"Você está bem!\n"
"Mostre-me sua habilidade novamente!" BOX_BREAK "Você deve definir uma nova meta de\n"
COLOR(RED) "1.500 pontos" COLOR(DEFAULT) "e tente novamente!" EVENT
)

DEFINE_MESSAGE(0x6043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê? Você quer tentar novamente?\n"
"Parece que você tem algum\n"
"potencial!" EVENT
)

DEFINE_MESSAGE(0x6044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que droga! Você é o máximo\n"
"mestre!" BOX_BREAK "Eu lhe darei um item adequado\n"
"para o mestre." BOX_BREAK "Esta aljava é muito importante para \n"
"eu. Eu quero que você fique com ele.\n"
"Cuide bem disso, está bem?"
)

DEFINE_MESSAGE(0x6045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
PONTOS " pontos...Hmm...\n"
"Wha-ha-ha! Você tem muito \n"
"pode melhorar!" EVENT
)

DEFINE_MESSAGE(0x6046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fantástico!\n"
"Você é um verdadeiro mestre!" BOX_BREAK "Vou dar isso a você.\n"
"Continue melhorando a si mesmo!"
)

DEFINE_MESSAGE(0x6047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
PONTOS " pontos...\n"
"Bem impressionante!" EVENT
)

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Olhe para aquele garoto estúpido!\n"
"Ele veio sozinho para oferecer \n"
"se como um sacrifício para o\n"
"grande Ganondorf..." FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x05") "Com minha chama, vou queimá-lo até\n"
SHIFT("\x46") "o osso!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Com meu gelo, vou congelá-lo\n"
SHIFT("\x46") "sua alma!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x1C") "Caramba, que garoto novo!\n"
SHIFT("\x15") "Desta vez, vamos levar a sério,\n"
SHIFT("\x3C") "certo Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4B") "O que?" BOX_BREAK_DELAYED("\x14") SHIFT("\x0A") "Ei, Koume, o que é isso acima\n"
SHIFT("\x41") "sua cabeça?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0B") "Não sei, mas você tem um\n"
SHIFT("\x14") "sobre sua cabeça também, Kotake!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "Mas eu tenho apenas 400 anos!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x14") "E eu tenho apenas 380 anos!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x0C") "Somos gêmeos! Não tente mentir\n"
SHIFT("\x35") "mais ou menos a sua idade!" QUICKTEXT_DISABLE FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x06") "Você deve ter ficado senil!" QUICKTEXT_DISABLE FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x1E") "Quem você está chamando de senil?!\n"
SHIFT("\x16") "É assim que você trata seu\n"
SHIFT("\x3D") "irmã mais velha?" QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x36") "Somos gêmeos! \n"
SHIFT("\x26") "Como você pode ser mais velho?" QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x3F") "Keeeyaaah!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE SHIFT("\x20") "Como você é insensível!" QUICKTEXT_DISABLE FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x12") "Como você pode ser tão ingrato?" QUICKTEXT_DISABLE FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x35") "Você não tem coração!!" QUICKTEXT_DISABLE FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x33") "Seu ingrato..." QUICKTEXT_DISABLE FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE SHIFT("\x21") "Vou voltar para assombrá-lo!" QUICKTEXT_DISABLE FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "OK, vamos falar sério agora, Kotake!" QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x37") QUICKTEXT_ENABLE "Ah, tudo bem, Koume." QUICKTEXT_DISABLE BOX_BREAK_DELAYED("\x14") SHIFT("\x30") QUICKTEXT_ENABLE "Kotake" QUICKTEXT_DISABLE " e " QUICKTEXT_ENABLE "Koume's" QUICKTEXT_DISABLE "\n"
SHIFT("\x1C") QUICKTEXT_ENABLE "Duplo" QUICKTEXT_DISABLE " Dinamite " QUICKTEXT_ENABLE "Ataque!" QUICKTEXT_DISABLE FADE("\x28")
)

DEFINE_MESSAGE(0x605B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você veio aqui para me salvar? \n"
"Ah, isso é ótimo! Eu sou " COLOR(RED) "Ichiro\n"
"o carpinteiro" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Estávamos realmente interessados em \n"
"ingressando no grupo só de mulheres, mas \n"
"eles nos trancaram assim apenas\n"
"porque somos homens!" BOX_BREAK UNSKIPPABLE "Não nos importamos com o Gerudo \n"
"mais! Eles são tão rudes!" BOX_BREAK UNSKIPPABLE COLOR(RED) "Três dos meus companheiros" COLOR(DEFAULT) " também \n"
"foi capturado, então por favor ajude \n"
"eles escapam, também!"
)

DEFINE_MESSAGE(0x605C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você é uma criança fofa! Obrigado por\n"
"Vem me salvar! Eu sou " COLOR(RED) "Jiro, o \n"
"carpinteiro" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Essas mulheres são tão assustadoras! Eu\n"
"prefiro trabalhar como carpinteiro do que\n"
"Junte-se a eles!" BOX_BREAK UNSKIPPABLE "Mal posso esperar para dizer adeus a\n"
"este lugar!" COLOR(RED) "Dois dos meus amigos" COLOR(DEFAULT) "\n"
"ainda estão sendo mantidos prisioneiros. Will\n"
"você, por favor, tire-os também?"
)

DEFINE_MESSAGE(0x605D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Obrigado, rapaz! Você é fantástico!\n"
"Eu sou " COLOR(RED) "Sabooro, o carpinteiro" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Você viu nosso chefe, garoto?\n"
"Ele provavelmente está preocupado comigo!\n"
"Eu tenho que voltar para ele \n"
QUICKTEXT_ENABLE "imediatamente!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE COLOR(RED) "Mais um dos nossos trabalhadores " COLOR(DEFAULT) "ainda está\n"
"um prisioneiro. Por favor, salve-o!"
)

DEFINE_MESSAGE(0x605E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu estava com medo que você fosse \n"
"esqueça de mim! Agora estou livre!\n"
"Obrigado! Eu sou " COLOR(RED) "Shiro o carpinteiro" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Para me resgatar, eu vou te dizer\n"
"algo interessante sobre o\n"
"deserto que eu ouvi o\n"
"Gerudos falando." BOX_BREAK UNSKIPPABLE "Eles disseram, \"Para atravessar o\n"
"Haunted Wasteland, você vai precisar do\n"
"'" COLOR(RED) "olho da verdade" COLOR(DEFAULT) ".' O Colosso está ativo\n"
"o outro lado do terreno baldio...\"" BOX_BREAK UNSKIPPABLE "OK, agora vou voltar para o meu\n"
COLOR(RED) "tenda perto do Vale do Gerudo" COLOR(DEFAULT) ", então, \n"
"apareça em algum momento. Você pode encontrar \n"
"algo útil aí! Tchau!"
)

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"O líder da gangue de ladrões\n"
"é " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". Ela está experimentando \n"
"na lavagem cerebral de muitas pessoas em \n"
"as ruínas no deserto."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, foi Ganondorf, o Maligno\n"
"Rei que estava por trás da gangue de \n"
"ladrões..."
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando " COLOR(RED) "Nabooru" COLOR(DEFAULT) " era um lobo solitário \n"
"ladrão, ela nunca roubou de \n"
"o fraco, mas..." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Agora, a gangue de ladrões de Nabooru \n"
"significa crueldade e brutalidade.\n"
"Ela afirma ser uma cavalheiresca \n"
"ladrão, mas... de jeito nenhum!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Como eu suspeitava, Nabooru era \n"
"lavagem cerebral por Ganondorf's \n"
"seguidores..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Na sociedade Gerudo, quem tem\n"
"grande habilidade em cavalgadas e\n"
"o tiro com arco são bem respeitados." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Que tal experimentar a cavalo \n"
"arco com arco na Fortaleza de Gerudo?" BOX_BREAK "Se você tem um cavalo, um Gerudo \n"
"da fortaleza vai configurar \n"
"seu desafio."
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você fez tão bem, jovem!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Construindo uma ponte sobre o vale\n"
"é uma tarefa simples para quatro\n"
"carpinteiros."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Sem as bruxas velhas, a gangue\n"
"de ladrões não é tão assustador!"
)

DEFINE_MESSAGE(0x6069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A " COLOR(RED) "Fortaleza do Gerudo " COLOR(DEFAULT) "está localizada \n"
"além deste portão. Uma criança como você \n"
"não tem nenhum negócio lá."
)

DEFINE_MESSAGE(0x606A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x68\x55") "Sou um mestre artesão " COLOR(RED)" COLOR(DEFAULT) ". Aqueles\n"
"Gerudo ladrões... eles quebraram o\n"
"ponte." BOX_BREAK UNSKIPPABLE "Quero corrigi-lo, mas todos os meus \n"
"os trabalhadores se foram!" BOX_BREAK UNSKIPPABLE "Eles disseram trabalhar como carpinteiros\n"
"não é legal, e eles foram para o\n"
COLOR(RED) "Fortaleza de Gerudo" COLOR(DEFAULT) "para se tornar \n"
"ladrões..." TEXTID("\x60\x6B")
)

DEFINE_MESSAGE(0x606B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você! Se você estiver indo para o \n"
"fortaleza, você se importaria de encontrar\n"
"o que meus funcionários estão fazendo\n"
"bem ali?"
)

DEFINE_MESSAGE(0x606C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ouvi dizer que você salvou meus homens.\n"
"Quando eles voltaram, nós construímos isso\n"
"ponte." BOX_BREAK "Olha isso! \n"
"Não é uma bela ponte?" BOX_BREAK "Eles podem ser carpinteiros fracos, \n"
"mas uma vez que todos se juntaram,\n"
"eles fizeram o trabalho."
)

DEFINE_MESSAGE(0x606D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SFX("\x68\x55") "Ei, isso viu! É meu!" BOX_BREAK UNSKIPPABLE "Mas... pensei que tinha deixado aquela serra\n"
"com minha velhinha... Ah bem..." TEXTID("\x60\x6E")
)

DEFINE_MESSAGE(0x606E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Minha ferramenta Biggoron quebrou, então eu estava\n"
"indo para Goron City para pegá-lo\n"
"reparado". BOX_BREAK "Sua vinda aqui é um ótimo momento.\n"
"Você vai me dar minha serra?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x606F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x47") QUICKTEXT_ENABLE "O que?!\n"
SHIFT("\x14") "Você é um ladrão sujo e podre!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Este é o treinamento do Gerudo" COLOR(RED) "\n"
"Terra" COLOR(DEFAULT) ". Pessoas não qualificadas são \n"
"não permitido."
)

DEFINE_MESSAGE(0x6071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta é a" COLOR(RED) "Treinamento do Gerudo\n"
"Ground" COLOR(DEFAULT) ". Você está qualificado...\n"
"Venha e aprimore suas habilidades\n"
"tanto quanto você quiser." EVENT
)

DEFINE_MESSAGE(0x6072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esta é a" COLOR(RED) "Treinamento do Gerudo\n"
"Ground" COLOR(DEFAULT) ". Mesmo que você seja \n"
"qualificado, não monopolize todos os \n"
"tesouro aqui para você!"
)

DEFINE_MESSAGE(0x6073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"6073"
)

DEFINE_MESSAGE(0x6074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh isso é muito ruim." BOX_BREAK "A marca que o levará ao\n"
"Templo do Espírito é a bandeira " COLOR(RED) "ativada\n"
"à esquerda" COLOR(DEFAULT) "fora da loja." BOX_BREAK "Se mudar de ideia, por favor\n"
"volte novamente!"
)

DEFINE_MESSAGE(0x6075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, não há rúpias suficientes.\n"
"Sem descontos, nem mesmo uma rúpia."
)

DEFINE_MESSAGE(0x6076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ei, ei.\n"
"Você já está no meio de \n"
"alguma coisa, não é você." BOX_BREAK "Se você quiser me desafiar, você\n"
"tem que vir aqui com uma clara\n"
"mente. Sem outras distrações!"
)

DEFINE_MESSAGE(0x6077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x41") "Bem vindo!" BOX_BREAK "Estou vendendo coisas estranhas e \n"
"raro, de todo o mundo para \n"
"todos.\n"
"O especial de hoje é..." BOX_BREAK "Um objeto em execução perigoso! \n"
"Aterrorizante! \n"
"Eu não vou te dizer o que é até \n"
"Eu vejo o dinheiro..." BOX_BREAK "Que tal " COLOR(RED) "200 Rupees" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Comprar\n"
"Não comprar" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x6078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito obrigado!" BOX_BREAK "O que estou vendendo é..." TEXT_SPEED("\x02") COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" TEXT_SPEED("\x00") BOX_BREAK "A marca que o levará a\n"
"o Templo Espiritual é a bandeira " COLOR(RED) "em\n"
"à esquerda " COLOR(DEFAULT) "fora da loja.\n"
"Estarei vendo você!"
)

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ei, e aí, " NAME "?\n"
"Surpreso em me ver?" BOX_BREAK UNSKIPPABLE "Há muito tempo neste mundo é\n"
"quase nada para você, não é?\n"
"Que misterioso!" BOX_BREAK UNSKIPPABLE "Até eu pensei que os contos de um\n"
"garoto que poderia viajar de volta e\n"
"atravessar o tempo foi meramente um\n"
"lenda." BOX_BREAK NAME UNSKIPPABLE ", você tem totalmente \n"
"amadureceu como um adulto." TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"De agora em diante, o futuro de todos os\n"
"pessoas em Hyrule estão no seu \n"
"ombros". BOX_BREAK "Talvez não seja mais minha hora. \n"
"Aqui está meu último conselho." BOX_BREAK "Duas bruxas habitam este templo. Em \n"
"para destruí-los," COLOR(RED) "transformar seus \n"
"próprio poder mágico contra eles" COLOR(DEFAULT) ".\n"
"Hooi!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você quer ouvir o que eu disse\n"
"de novo?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Vou continuar te observando...\n"
"Hoo hoo hoo hoo!"
)

DEFINE_MESSAGE(0x607D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Eu sou o homem correndo errante!\n"
"Eu corri por toda esta terra em\n"
"busca do verdadeiro espírito competitivo." BOX_BREAK UNSKIPPABLE "Eu venci todos os meus adversários, cara e\n"
"fera." BOX_BREAK UNSKIPPABLE "Você é um cara atlético e\n"
"parece que você pode ter um verdadeiro\n"
"instinto assassino também." BOX_BREAK UNSKIPPABLE "Agora que a ponte sobre Gerudo\n"
"Vale está completo, estou procurando\n"
"um desafiante a ter um \n"
"corrida comemorativa contra". TEXTID("\x60\x7E")
)

DEFINE_MESSAGE(0x607E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"A melhor hora para ir daqui para \n"
"a ponte " COLOR(ADJUSTABLE)" no Bosque Perdido " COLOR(DEFAULT) "era\n"
COLOR(RED) HIGHSCORE(HS_MARATHON) COLOR(DEFAULT) ". Esse é o meu recorde." BOX_BREAK "Você vai desafiar meu recorde?\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Excelente!\n"
"Então..." BOX_BREAK "Você vai primeiro.\n"
"Eu vou te dar uma vantagem." BOX_BREAK "Agora!" TEXT_SPEED("\x02") "Vá em frente." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Você nunca descobrirá seu\n"
"instinto matador com isso\n"
"tipo de atitude".
)

DEFINE_MESSAGE(0x6081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Bem, não é perfeito, mas você\n"
"tenha coragem! Infelizmente,\n"
"você nunca pode me vencer. Seu\n"
"o disco é coisa do passado." BOX_BREAK "Seu tempo foi " COLOR(RED) HIGHSCORE(HS_MARATHON) COLOR(DEFAULT) ", não foi?\n"
"Foi por pouco, mas eu venci você\n"
"por um segundo!" EVENT
)

DEFINE_MESSAGE(0x6082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Heh heh heh.\n"
"Por favor." TEXT_SPEED("\x02") "Vá em frente." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x6083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ah, parece que você desistiu da corrida.\n"
"Heh heh heh. Aposto que você quase \n"
"redescobriu seu instinto assassino!" FADE("\x3C")
)

DEFINE_MESSAGE(0x6084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Ei, ei.\n"
"Você não tem assassino suficiente\n"
"instinto ainda." BOX_BREAK "Apenas treine mais forte.\n"
QUICKTEXT_ENABLE "Adeus, então!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
TEXT_SPEED("\x01") QUICKTEXT_ENABLE "Huff..." QUICKTEXT_DISABLE QUICKTEXT_ENABLE "puff..." QUICKTEXT_DISABLE QUICKTEXT_ENABLE "huff..." QUICKTEXT_DISABLE TEXT_SPEED("\x00") BOX_BREAK "Huff...huff...whew! \n"
"Você fez muito bem!" BOX_BREAK "Mas você não poderia me vencer!\n"
"Seu tempo era " COLOR(RED) MARATHON_TIME COLOR(DEFAULT) ", mas eu\n"
"apenas vencê-lo por um segundo!" BOX_BREAK "Huff...huff...\n"
"Você vai ter que me desafiar\n"
"de novo em algum momento!" BOX_BREAK "Huff...huff...\n"
QUICKTEXT_ENABLE "Adeus, então!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Eu sou o homem correndo errante!\n"
"Eu corri por toda esta terra em \n"
"busca de concorrentes que tenham um\n"
"verdadeiro instinto assassino!" BOX_BREAK "Vim aqui para percorrer o \n"
"Terra Assombrada, mas não\n"
"parece um bom momento para isso." BOX_BREAK "Embora eu queira voltar para \n"
"Hyrule Field, a ponte é... bem,\n"
"você pode ver daqui. Então estou\n"
"preso aqui, dentro desta tenda." BOX_BREAK "Acho que não posso aceitar o seu\n"
"desafie agora mesmo.\n"
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
"Eu não posso pegar aquele Cucco!"
)

DEFINE_MESSAGE(0x7001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huff huff! \n"
"Estou atrasado! Estou atrasado!\n"
"Para uma data muito importante!"
)

DEFINE_MESSAGE(0x7002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem-vindo à Cidade do Castelo de Hyrule.\n"
"É uma cidade pacífica e próspera."
)

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"As crianças não devem andar por aí\n"
"cidade à noite! Fique dentro de casa\n"
"até de manhã!"
)

DEFINE_MESSAGE(0x7004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cara, estou TÃO entediado...\n"
"As coisas com certeza seriam mais\n"
"interessante se houvesse mais...\n"
"problemas no mundo..." BOX_BREAK "Ei, isso é só entre você e\n"
"eu, tudo bem?" BOX_BREAK "De qualquer forma, talvez possamos relaxar \n"
"um pouco de vapor quebrando esses \n"
"jarras". BOX_BREAK "Fique perto de uma jarra e pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " para\n"
"levantá-lo. Pressione " COLOR(BLUE) "[A]" COLOR(DEFAULT) " novamente para lançá-lo!"
)

DEFINE_MESSAGE(0x7005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Isso é ótimo!" BOX_BREAK UNSKIPPABLE "Esqueci de te dizer..." EVENT
)

DEFINE_MESSAGE(0x7006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Há muita coisa acontecendo no \n"
"castelo agora. Não posso permitir\n"
"até um cachorro para entrar no \n"
"castelo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Unnngh... você é o garoto de \n"
"a floresta...?" BOX_BREAK UNSKIPPABLE "Eu finalmente conheci você...\n"
"Eu tenho algo para contar\n"
"você..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o Rei Gerudo de\n"
"Ladrões, traíram nosso Rei..." BOX_BREAK UNSKIPPABLE "A babá de Zelda, " COLOR(RED) "Impa" COLOR(DEFAULT) ", pressentiu perigo\n"
"e escapou do castelo com\n"
"nossa princesa..." BOX_BREAK UNSKIPPABLE "Tentei parar os homens de Ganondorf\n"
"de persegui-los... mas..." BOX_BREAK UNSKIPPABLE "A princesa estava... esperando por um\n"
"garoto da floresta...é você...\n"
"Ela queria dar " COLOR(RED) "algo " COLOR(DEFAULT) "para\n"
"o menino..." BOX_BREAK UNSKIPPABLE "Se você recebeu do \n"
"Princesa, " TEXT_SPEED("\x03") QUICKTEXT_ENABLE "pressa" QUICKTEXT_DISABLE "..." QUICKTEXT_ENABLE "para o" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Tem" QUICKTEXT_DISABLE QUICKTEXT_ENABLE "ple" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "de" QUICKTEXT_DISABLE "\n"
"Hora" COLOR(DEFAULT) "...." TEXT_SPEED("\x00") EVENT
)

DEFINE_MESSAGE(0x7008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Ele não está mais se movendo..."
)

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você consegue ver o homem com o \n"
"olhos maus?" BOX_BREAK UNSKIPPABLE "Isso é " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o líder de \n"
"os Gerudos. Eles vêm do \n"
"deserto distante a oeste." BOX_BREAK UNSKIPPABLE "Embora ele jure fidelidade ao meu \n"
"pai, tenho certeza que ele não é \n"
"sincero." BOX_BREAK UNSKIPPABLE "As nuvens escuras que cobriram \n"
"Hyrule no meu sonho...\n"
"Eles devem simbolizar aquele homem!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0E") "Geh heh heh! Excelente trabalho!" BOX_BREAK_DELAYED("\x3C") SHIFT("\x08") "Como pensei, você segurou as teclas\n"
SHIFT("\x26") "para a Porta do Tempo!" BOX_BREAK_DELAYED("\x5A") SHIFT("\x05") "Você me levou aos portões de\n"
SHIFT("\x2D") "o Reino Sagrado..." BOX_BREAK_DELAYED("\x50") SHIFT("\x10") "Sim, devo tudo a você, garoto!" FADE("\x32")
)

DEFINE_MESSAGE(0x700B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Por favor! Se você não se apressar,\n"
"ele vai embora!" EVENT
)

DEFINE_MESSAGE(0x700C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor... com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Por favor, venda-me o conteúdo " COLOR(RED)" COLOR(DEFAULT) " de um\n"
"garrafa...\n"
"Por favor... com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x700D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que loja estranha! \n"
"Gostaria de saber quando estará aberto para\n"
"negócios. Li a placa ali, \n"
"mas ainda parece estranho!"
)

DEFINE_MESSAGE(0x700E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que está demorando uma eternidade\n"
"para o amanhecer..." BOX_BREAK "A vista do Castelo de Hyrule em \n"
"o sol da manhã é tão fantástico!"
)

DEFINE_MESSAGE(0x700F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para salvar a garota da floresta, você precisa\n"
COLOR(RED) "outra habilidade" COLOR(DEFAULT) "...\n"
"Vá para a Vila Kakariko!"
)

DEFINE_MESSAGE(0x7010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que você tem o\n"
"habilidades que você precisa... \n"
"A " COLOR(ADJUSTABLE) "garota da floresta" COLOR(DEFAULT) " está esperando pelo seu\n"
"ajuda...."
)

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você quer poções, é melhor \n"
"traga uma garrafa vazia. Entenda,\n"
"homem jovem?" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Desculpe, mas este é apenas um modelo. \n"
"Por causa da crise em Goron \n"
"Cidade, não recebemos nenhum \n"
"envios ultimamente e estamos fora." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Se você planeja escalar a Morte\n"
"Montanha, compre uma " COLOR(LIGHTBLUE) "Escudo Hylian" COLOR(DEFAULT) ".\n"
"Você pode se defender contra\n"
"pedras caindo com esse escudo." BOX_BREAK "Mas pode ser um pouco \n"
"grande para uma criança..." PERSISTENT
)

DEFINE_MESSAGE(0x7014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu não estou dançando, você sabe...\n"
"Minhas costas coçam! \n"
"Ooh! Aaah! Ooh!"
)

DEFINE_MESSAGE(0x7015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eles dizem que nós " COLOR(LIGHTBLUE) "Hylians " COLOR(DEFAULT) "temos orelhas grandes\n"
"para ouvir as vozes do \n"
"deuses... mas eu nunca os ouvi!"
)

DEFINE_MESSAGE(0x7016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Garoto, você já esteve em \n"
COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "O leite deles é delicioso!\n"
"Há muitos cavalos lá, e\n"
"a jovem filha do rancho\n"
"o dono é fofo!" TEXTID("\x70\x17")
)

DEFINE_MESSAGE(0x7017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Para chegar a " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT) ", depois\n"
"você sai da cidade, segue para o sul\n"
"do outro lado do campo. Você deve visitar\n"
"o rancho pelo menos uma vez!"
)

DEFINE_MESSAGE(0x7018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Eu queria ver " COLOR(RED) "Princesa Zelda" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Eu evitei os guardas..." BOX_BREAK UNSKIPPABLE "Nadei pelo fosso..." BOX_BREAK UNSKIPPABLE "Eu estava quase lá quando eles\n"
"me pegou!" TEXTID("\x70\x19")
)

DEFINE_MESSAGE(0x7019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Encontrei um " COLOR(RED) "pequeno orifício de drenagem " COLOR(DEFAULT) "no\n"
"lado direito do castelo que eu\n"
"pensei que poderia entrar, mas\n"
"fiquei preso lá."
)

DEFINE_MESSAGE(0x701A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x37") "Aham!" QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE BOX_BREAK SHIFT("\x05") "Esta barba é meu orgulho e alegria!\n"
SHIFT("\x07") "Não parece exuberante, garoto?!"
)

DEFINE_MESSAGE(0x701B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE SHIFT("\x37") "Aham!" QUICKTEXT_ENABLE "Hrrrm!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE SHIFT("\x05") "Esta barba é meu orgulho e alegria!\n"
SHIFT("\x07") "Não parece exuberante, garoto?!" BOX_BREAK UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x51") "O quê?!" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Você está procurando o cara de\n"
"Ranch Lon Lon?" BOX_BREAK UNSKIPPABLE "Hmm, talvez..." TEXTID("\x70\x1C")
)

DEFINE_MESSAGE(0x701C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu vi um cara " COLOR(RED) "com uma aparência esfarrapada\n"
"barba " COLOR(DEFAULT) "entregando algumas caixas para \n"
"o castelo."
)

DEFINE_MESSAGE(0x701D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você conhece o " COLOR(LIGHTBLUE) "Templo \n"
"of Time" COLOR(DEFAULT) "que temos no \n"
"parte nordeste da cidade?" TEXTID("\x70\x1E")
)

DEFINE_MESSAGE(0x701E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"As lendas dizem que o Templo de\n"
"O tempo é a entrada para o \n"
"Reino Sagrado..." BOX_BREAK "Você sabia disso?"
)

DEFINE_MESSAGE(0x701F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha! Que cara louco!" BOX_BREAK UNSKIPPABLE "Você acredita que esse cara foi \n"
"louco o suficiente para tentar se infiltrar\n"
"o castelo para ver" COLOR(RED) "Princesa Zelda" COLOR(DEFAULT) "?" TEXTID("\x70\x20")
)

DEFINE_MESSAGE(0x7020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo por causa desse idiota, eles \n"
"segurança reforçada no castelo.\n"
"Wha-ha-ha!"
)

DEFINE_MESSAGE(0x7021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ganhei muito dinheiro!" BOX_BREAK UNSKIPPABLE "Talvez eu deva procurar\n"
"mais coisas para vender!" TEXTID("\x70\x22")
)

DEFINE_MESSAGE(0x7022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu sei! Eu deveria ir para " COLOR(BLUE) "Lake Hylia" COLOR(DEFAULT) "!\n"
"Muitas coisas flutuam rio abaixo\n"
"e acaba aí!\n"
"Ha ha!"
)

DEFINE_MESSAGE(0x7023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ei, garoto da floresta! Esta é a cidade " COLOR(LIGHTBLUE) "\n"
"of Hyrule" COLOR(DEFAULT) "! Não se apresse e\n"
"aproveite as vistas!" TEXTID("\x70\x24")
)

DEFINE_MESSAGE(0x7024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se você veio aqui para ver " COLOR(LIGHTBLUE) "Hyrule\n"
"Castelo" COLOR(DEFAULT) ", pegue a rua no seu\n"
"direita." BOX_BREAK "Se você quiser ver o " COLOR(BLUE) "voltar \n"
"alleys" COLOR(DEFAULT) " da cidade, pegue a\n"
"rua à esquerda."
)

DEFINE_MESSAGE(0x7025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..." BOX_BREAK "Você é... tão bonito..." BOX_BREAK "Assim como o Rei de Hyrule..." BOX_BREAK "Hee hee..."
)

DEFINE_MESSAGE(0x7026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ohh..." BOX_BREAK "Você é..." BOX_BREAK "mais linda..." BOX_BREAK "do que a princesa Zelda..." BOX_BREAK "Ohh..."
)

DEFINE_MESSAGE(0x7027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Você já ouviu a lenda do\n"
"\"Gente das Sombras\"?" BOX_BREAK UNSKIPPABLE "Eles são a " COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "...as sombras\n"
"dos Hylianos." BOX_BREAK UNSKIPPABLE "Dizem que juraram lealdade a\n"
"o Rei de Hyrule e guardado\n"
"a família real." BOX_BREAK UNSKIPPABLE "Mas com a longa paz, ninguém\n"
"viu um Sheikah por aqui \n"
"por muito tempo." BOX_BREAK UNSKIPPABLE "Porém..." TEXTID("\x70\x28")
)

DEFINE_MESSAGE(0x7028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvi dizer que existe uma " COLOR(BLUE) "Sheikah \n"
COLOR(DEFAULT) "mulher morando no castelo..."
)

DEFINE_MESSAGE(0x7029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Então você diz que quer ver\n"
COLOR(RED) "Princesa Zelda" COLOR(DEFAULT) ", hein?" BOX_BREAK "Você provavelmente já ouviu falar dela em\n"
"cidade e decidiu que você tinha que se encontrar\n"
"ela... Bem..." BOX_BREAK QUICKTEXT_ENABLE "Vá para casa!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Saia daqui!" QUICKTEXT_DISABLE "\n"
"A princesa nunca concederia um\n"
"audiência para os gostos de você!"
)

DEFINE_MESSAGE(0x702A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"ZZZZ Z..." BOX_BREAK "Resmungar resmungar..." BOX_BREAK "Bem-vindo... nosso rancho é tão divertido..." BOX_BREAK "Vamos dar uma olhada..."
)

DEFINE_MESSAGE(0x702B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE QUICKTEXT_ENABLE SHIFT("\x2D") "O que em tarnation?" QUICKTEXT_DISABLE BOX_BREAK UNSKIPPABLE "Uma pessoa não pode ficar um pouco calada-\n"
"olho por aqui?"
)

DEFINE_MESSAGE(0x702C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Olá, e quem você pode ser?" BOX_BREAK UNSKIPPABLE "Sim, eu sou " COLOR(RED) "Talon" COLOR(DEFAULT) ", o proprietário de Lon \n"
"Ranch Lon." BOX_BREAK UNSKIPPABLE "Fui ao castelo para entregar\n"
"um pouco de leite, mas eu sentei aqui para\n"
"descanso, e acho que adormeci..." BOX_BREAK UNSKIPPABLE SHIFT("\x4C") SFX("\x68\x52") "O quê?!\n"
"Malon estava me procurando?\n"
"Eu vou pegar com ela agora!" BOX_BREAK UNSKIPPABLE "Eu errei muito, deixando Malon\n"
"atrás de esperar por mim!" BOX_BREAK UNSKIPPABLE "Ela realmente vai me deixar ficar com ele!" EVENT
)

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE SHIFT("\x37") "Ei, você! Pare!\n"
SHIFT("\x28") "Você, garoto, ali!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x5F") "!" BOX_BREAK_DELAYED("\x0A") SHIFT UNSKIPPABLE("\x4E") QUICKTEXT_ENABLE "Quem?!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x3A") "Quem é você?" BOX_BREAK UNSKIPPABLE "Como você passou pelos guardas?" EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Você tem? \n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem, isso é estranho...\n"
"Achei que você poderia ser o único\n"
"do meu sonho...\n"
"Você realmente não tem isso?" BOX_BREAK "Diga-me a verdade..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x2D") "Assim como eu pensava!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, mantenha isso em segredo de\n"
"todos...\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Vamos... não seja um tagarela!" EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A lenda é assim..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x12") "As três deusas esconderam a\n"
SHIFT("\x07") COLOR(RED) "Triforce " COLOR(DEFAULT) "contendo o poder de\n"
SHIFT("\x0D") "os deuses em algum lugar em Hyrule." BOX_BREAK_DELAYED("\x50") SHIFT UNSKIPPABLE("\x45") "O poder\n"
SHIFT("\x03") "para realizar o desejo de quem\n"
SHIFT("\x0A") "segura a Triforce em suas mãos." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE SHIFT("\x03") "Se alguém com um coração justo\n"
SHIFT("\x07") "faça um desejo, ele levará Hyrule\n"
SHIFT("\x09") "para uma idade de ouro de prosperidade..." BOX_BREAK_DELAYED("\x3C") UNSKIPPABLE SHIFT("\x06") "Se alguém com uma mente maligna tiver\n"
SHIFT("\x0A") "seu desejo atendido, o mundo irá\n"
SHIFT("\x02") "ser consumido pelo mal...Isso é o que\n"
SHIFT("\x35") "foi informado..." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE SHIFT("\x16") "Então, os antigos Sábios construíram\n"
SHIFT("\x02") "a " COLOR(LIGHTBLUE) "Temple of Time" COLOR(DEFAULT) " para proteger a\n"
SHIFT("\x20") "Triforce dos malignos." FADE("\x5A")
)

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Isso mesmo... O Templo do Tempo\n"
"é a entrada pela qual você\n"
"pode entrar no Reino Sagrado de\n"
"nosso mundo." BOX_BREAK "Mas a entrada está selada com\n"
"um muro de pedra chamado \n"
COLOR(LIGHTBLUE) "Porta do Tempo" COLOR(DEFAULT) "." BOX_BREAK "E, para abrir a porta,\n"
"diz-se que você precisa coletar\n"
"três" COLOR(RED) "Pedras Espirituais" COLOR(DEFAULT) "." BOX_BREAK "E outra coisa que você precisa...é\n"
"o tesouro que a Família Real\n"
"mantém essa lenda..." EVENT
)

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, desculpe. \n"
"Não sou muito bom em contar histórias..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE QUICKTEXT_ENABLE "O que aconteceu?" QUICKTEXT_DISABLE "Ele viu você?" BOX_BREAK UNSKIPPABLE "Não se preocupe." BOX_BREAK UNSKIPPABLE "Ele não faz ideia do que\n"
"estamos planejando... ainda!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Por favor!\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "OK\n"
"Eu não acredito em você." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x42") "Obrigado!" EVENT
)

DEFINE_MESSAGE(0x703C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu atendente irá guiá-lo para fora\n"
"o castelo. Não tenha medo de falar\n"
"a ela."
)

DEFINE_MESSAGE(0x703D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A Pedra Espiritual...\n"
"Você finalmente encontrou!" BOX_BREAK "Diz-se que as corridas que detêm\n"
"as Pedras Espirituais abrem seus\n"
"mente apenas para quem conhece o\n"
COLOR(BLUE) "melodia da Família Real" COLOR(DEFAULT) "." BOX_BREAK "Mas você já sabe disso, não\n"
"tu?"
)

DEFINE_MESSAGE(0x703E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você já ouviu falar disso\n"
"Princesa Zelda vê profética \n"
"visões em seus sonhos?"
)

DEFINE_MESSAGE(0x703F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh? O quê? Shoo, garoto! Shoo!"
)

DEFINE_MESSAGE(0x7040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Existem três cavidades e \n"
"uma inscrição aqui...." BOX_BREAK QUICKTEXT_ENABLE "Você que possui 3 Pedras Espirituais " COLOR(BLUE) "\n"
COLOR(DEFAULT) "Fique com a " COLOR(LIGHTBLUE) "Ocarina of Time" COLOR(BLUE) "\n"
COLOR(DEFAULT) "E toque a " COLOR(LIGHTBLUE) "Canção do Tempo" COLOR(DEFAULT) QUICKTEXT_DISABLE BOX_BREAK "É assim que se lê a inscrição." EVENT
)

DEFINE_MESSAGE(0x7041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vamos lá, você não pode fazer isso\n"
"mais barato?"
)

DEFINE_MESSAGE(0x7042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, solte! É meu!\n"
"Eu encontrei primeiro!"
)

DEFINE_MESSAGE(0x7043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, quem me bateu?!"
)

DEFINE_MESSAGE(0x7044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não vemos muitos Gerudos em\n"
"estas peças...\n"
"Alguma coisa estranha está acontecendo!"
)

DEFINE_MESSAGE(0x7045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquela princesa Zelda não estava cavalgando\n"
"no cavalo branco?!"
)

DEFINE_MESSAGE(0x7046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quase fui chutado por isso\n"
"cavalo preto!"
)

DEFINE_MESSAGE(0x7047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele cara andando no cavalo preto\n"
"deve ter sido Ganondorf, que é\n"
"reconhecido como o Rei Gerudo de \n"
"Ladrões."
)

DEFINE_MESSAGE(0x7048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que aconteceu?!"
)

DEFINE_MESSAGE(0x7049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olhe para aquele cara, ele está com tanto medo!\n"
"Que covarde!\n"
"Ha ha ha!"
)

DEFINE_MESSAGE(0x704A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou sentindo algo\n"
"terrível vai acontecer...\n"
"Talvez eu devesse deixar a cidade em breve."
)

DEFINE_MESSAGE(0x704B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Algo aconteceu no castelo!\n"
"Garoto, é melhor você ter cuidado!"
)

DEFINE_MESSAGE(0x704C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Com essa tecla " COLOR(RED)" COLOR(DEFAULT) ", prossiga para \n"
"quarto à frente. Vá, vá!"
)

DEFINE_MESSAGE(0x704D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele montado no cavalo branco\n"
"segurando a garotinha...\n"
"Aquele não era um lendário Sheikah?"
)

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
SHIFT UNSKIPPABLE("\x2D") NAME "..." BOX_BREAK SHIFT UNSKIPPABLE("\x45") "Acordar...\n"
SHIFT("\x05") NAME ", o escolhido..."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sou " COLOR(RED) "Rauru" COLOR(DEFAULT) ", um dos antigos\n"
"Sábios..." BOX_BREAK UNSKIPPABLE "Eras atrás, nós antigos sábios\n"
"construiu o Templo do Tempo para \n"
"proteger a entrada do\n"
"Reino Sagrado..." BOX_BREAK UNSKIPPABLE "Esta é a " COLOR(RED) "Câmara dos Sábios" COLOR(DEFAULT) "," COLOR(RED) " \n"
COLOR(DEFAULT) "dentro do Templo da Luz..." BOX_BREAK UNSKIPPABLE "O Templo da Luz, situado em\n"
"o próprio centro do Sagrado \n"
"Reino, é a última fortaleza \n"
"contra as forças do mal de Ganondorf." BOX_BREAK UNSKIPPABLE "A " COLOR(RED) "Master Sword" COLOR(DEFAULT) "--the evil-\n"
"espada destruidora que você puxou\n"
"fora do Pedestal of Time - foi \n"
"a chave final para o Reino Sagrado." BOX_BREAK NAME UNSKIPPABLE "...\n"
"Não se assuste...\n"
"Olhe para você...!"
)

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x23") COLOR(LIGHTBLUE) "Olha " NAME "!\n"
COLOR(DEFAULT) SHIFT("\x32") COLOR(LIGHTBLUE) "Você está grande agora!!\n"
COLOR(DEFAULT) SHIFT("\x31") COLOR(LIGHTBLUE) "Você cresceu!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A Espada Mestra é sagrada\n"
"lâmina que os malignos nunca podem\n"
"touch...." BOX_BREAK UNSKIPPABLE "Apenas um digno do título de\n"
"\"" COLOR(RED) "Hero of Time" COLOR(DEFAULT) "\"" COLOR(RED) " " COLOR(DEFAULT) "pode puxar de \n"
"o Pedestal do Tempo..." BOX_BREAK UNSKIPPABLE "No entanto, você era muito jovem para \n"
"seja o Herói do Tempo...." BOX_BREAK UNSKIPPABLE "Portanto, seu espírito era \n"
"selado aqui por sete anos." BOX_BREAK UNSKIPPABLE "E agora que você tem idade suficiente,\n"
"chegou a hora de você\n"
"desperte" COLOR(RED) " " COLOR(DEFAULT) "como o Herói do Tempo!" BOX_BREAK "Bem, você entende seu \n"
"destino?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Certo, parece que você está \n"
"confuso... Deixe-me dizer-lhe \n"
"mais uma vez, desde o início." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas, lembre-se..." BOX_BREAK UNSKIPPABLE "Embora você tenha aberto a porta de \n"
"Tempo em nome da paz..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", o Rei Gerudo de\n"
"Ladrões, usaram para entrar neste \n"
"Reino Sagrado proibido!" BOX_BREAK UNSKIPPABLE "Ele obteve a Triforce de\n"
"o Templo da Luz, e com seu \n"
"poder, ele se tornou o " COLOR(RED) "King of Evil" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Seu poder maligno irradiava do\n"
"templos de Hyrule, e em sete\n"
"curtos anos, transformou Hyrule\n"
"em um mundo de monstros." BOX_BREAK UNSKIPPABLE "Meu poder agora tem pouco \n"
"influência, mesmo neste Sagrado\n"
"Reino..." BOX_BREAK UNSKIPPABLE "A saber, esta Câmara dos Sábios." BOX_BREAK UNSKIPPABLE "Mas ainda há esperança..." BOX_BREAK UNSKIPPABLE "O poder dos Sábios permanece." BOX_BREAK UNSKIPPABLE "Quando o poder de todos os " COLOR(RED) "Sábios\n"
COLOR(DEFAULT) "é despertado..." BOX_BREAK UNSKIPPABLE "O " COLOR(RED) "Sages' Seals" COLOR(DEFAULT) " conterá\n"
"todo o poder do mal no vazio de \n"
"the Realm..." BOX_BREAK UNSKIPPABLE "Eu, Rauru, sou um dos Sábios...\n"
"E..." BOX_BREAK UNSKIPPABLE "Seu poder de lutar junto com\n"
"os Sábios fazem de você o \n"
COLOR(RED) "Herói do Tempo" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "O Herói do Tempo, escolhido pelo\n"
"Espada Mestra!" BOX_BREAK UNSKIPPABLE "Mantenha meu espírito com você...\n"
"E encontre o poder do outro\n"
"Sábios e adicione o poder deles ao seu\n"
"ter!"
)

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "...estamos de volta ao\n"
COLOR(DEFAULT) "Templo do Tempo" COLOR(LIGHTBLUE) "...\n"
"Mas tem " COLOR(DEFAULT) "sete anos" COLOR(LIGHTBLUE) " realmente\n"
"passado?" COLOR(DEFAULT) BOX_BREAK UNSKIPPABLE COLOR(LIGHTBLUE) "Parece que você não será\n"
"capaz de usar algumas das " COLOR(DEFAULT) "armas" COLOR(LIGHTBLUE) "\n"
"você encontrou mais quando criança..." BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Vamos sair daqui!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o que...? \n"
"O que há de errado com vadiagem\n"
"em torno de todo o dia?" BOX_BREAK "Hein, garoto?"
)

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Estou esperando por você, \n"
"Herói do Tempo..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Quando o mal governa tudo, um despertar\n"
"voz do Reino Sagrado irá\n"
"chame aqueles destinados a serem Sábios,\n"
"que habitam no" COLOR(RED) "cinco templos" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Um em uma " COLOR(AJUSTABLE) "floresta profunda" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Um em uma " COLOR(RED) "montanha alta" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Um sob um " COLOR(BLUE) "vasto lago" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Um dentro da " COLOR(PURPLE) "casa dos mortos" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Um dentro de uma " COLOR(YELLOW) "deusa da areia" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Junto com o Herói do Tempo, \n"
"os despertos ligarão os\n"
"mal e devolver a luz da paz\n"
"para o mundo..." BOX_BREAK UNSKIPPABLE "Esta é a lenda dos templos\n"
"passado pelo meu povo, o\n"
COLOR(BLUE) "Sheikah" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, desculpe.\n"
"Ainda não estamos abertos para negócios.\n"
"Por favor, volte logo!" EVENT
)

DEFINE_MESSAGE(0x7059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Use a " COLOR(RED) "Master Sword" COLOR(DEFAULT) "!\n"
"Destrua Ganon com o sagrado\n"
"espada!"
)

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Estive esperando por você,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE ", o Herói do Tempo..." BOX_BREAK UNSKIPPABLE "Você superou muitos \n"
"dificuldades e despertou seis Sábios." BOX_BREAK UNSKIPPABLE "E agora você tem uma final\n"
"desafio, um confronto com \n"
"Ganondorf, o Rei do Mal..."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x10") "Se você buscasse o sagrado\n"
SHIFT("\x28") "triângulo, ouça bem..." BOX_BREAK_DELAYED("\x3C") UNSKIPPABLE SHIFT("\x09") "O local de descanso do sagrado\n"
SHIFT("\x09") "triângulo, o Reino Sagrado, é um\n"
SHIFT("\x14") "espelho que reflete o que é\n"
SHIFT("\x3B") "no coração..." BOX_BREAK_DELAYED("\x46") UNSKIPPABLE SHIFT("\x05") "no coração de quem nele entra...\n"
SHIFT("\x0C") "Se um coração maligno, o Reino irá\n"
SHIFT("\x14") "ficar cheio de maldade; se puro,\n"
SHIFT("\x04") "o Reino se tornará um paraíso." BOX_BREAK_DELAYED("\x5A") MUDANÇA UNSKIPPABLE("\x02") "A Triforce...o triângulo sagrado...\n"
SHIFT("\x0A") "é uma balança que pesa o\n"
SHIFT("\x3C") "três forças:\n"
SHIFT("\x13") "Poder, Sabedoria e Coragem." BOX_BREAK_DELAYED("\x5A") UNSKIPPABLE SHIFT("\x02") "Se o coração de quem segura\n"
SHIFT("\x06") "o triângulo sagrado tem todos os três\n"
SHIFT("\x0A") "forças em equilíbrio, essa vai\n"
SHIFT("\x03") "ganhar a Verdadeira Força para governar tudo." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE SHIFT("\x06") "Mas, se o coração dessa pessoa não estiver em\n"
SHIFT("\x02") "balance, a Triforce vai separar\n"
SHIFT("\x32") "em três partes:\n"
SHIFT("\x13") "Poder, Sabedoria e Coragem." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE SHIFT("\x04") "Somente uma parte permanecerá para o\n"
SHIFT("\x02") "aquele que tocou a Triforce...a\n"
SHIFT("\x07") "parte representando a força que\n"
SHIFT("\x27") "em quem mais acredita." BOX_BREAK_DELAYED("\x5A") UNSKIPPABLE SHIFT("\x04") "Se aquele busca a Força Verdadeira,\n"
SHIFT("\x0C") "que se deve adquirir os dois\n"
SHIFT("\x44") "peças perdidas." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE SHIFT("\x12") "Essas duas partes serão mantidas\n"
SHIFT("\x07") "dentro de outros escolhidos pelo destino,\n"
SHIFT("\x0A") "quem portará a marca Triforce\n"
SHIFT("\x11") "nas costas de suas mãos." FADE("\x5A")
)

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sete anos atrás, Ganondorf, o \n"
"Rei dos Ladrões, usou a porta \n"
"você abriu no Templo do Tempo\n"
"e entrou no Reino Sagrado." BOX_BREAK UNSKIPPABLE "Mas quando ele colocou as mãos no\n"
"Triforce, a lenda se tornou realidade."
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Aquele que detém a " COLOR(RED) "Triforce \n"
"de Coragem " COLOR(DEFAULT) "é...\n"
"Seu nome "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E o outro, que detém o \n"
COLOR(RED) "Triforce of Wisdom" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "é o sétimo Sábio, que é\n"
"destinado a ser o líder de\n"
"o Shopping..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sou eu, a Princesa de Hyrule,\n"
COLOR(RED) "Zelda" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Peço desculpas por conhecê-lo em \n"
"disfarçar, mas foi necessário\n"
"esconder-se do Rei do Mal. \n"
"Por favor me perdoe..."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Eu te vi quando estava fugindo \n"
"do castelo com meu \n"
"atendente, Impa." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Desde que você tenha a Ocarina \n"
"em sua posse, pensei \n"
"Ganondorf nunca poderia entrar no\n"
"Reino Sagrado, mas..." BOX_BREAK UNSKIPPABLE "algo que eu nunca poderia esperar\n"
"ocorrido..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x24") "Aquele estrondo... Não pode ser!?"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Princesa Zelda... sua tola \n"
"traidor!" BOX_BREAK UNSKIPPABLE "Parabenizo você por evitar meu \n"
"perseguição por sete longos anos."
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você quiser resgatar Zelda,\n"
"Venha para o meu castelo!"
)

DEFINE_MESSAGE(0x7067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
NAME UNSKIPPABLE "...você pode me ouvir?\n"
"É Rauru, o Sábio." BOX_BREAK UNSKIPPABLE "Nós seis reuniremos nosso poder para\n"
"criar uma ponte para o castelo\n"
"onde Ganondorf mora..." BOX_BREAK UNSKIPPABLE "A fortaleza do castelo, que é \n"
"conhecida como Torre de Ganon, é \n"
"protegido por " COLOR(RED) "seis barreiras do mal" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Derrube as seis barreiras e\n"
"salve a princesa Zelda!!"
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
"Criadores Antigos de Hyrule!" BOX_BREAK_DELAYED("\x3C") "Agora, abra a porta selada\n"
"e envie a Encarnação do Mal de\n"
"Escuridão no vazio do\n"
"Reino do Mal!!" FADE("\x5A")
)

DEFINE_MESSAGE(0x706D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME UNSKIPPABLE "!\n"
"Acabe com ele com a espada de\n"
"tempo, a Espada Mestra!"
)

DEFINE_MESSAGE(0x706E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh porta selada aberta pelo \n"
"Sábios... Feche para sempre com \n"
"a Encarnação do Mal da Escuridão\n"
"dentro de!!"
)

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Obrigado, " NAME "..." BOX_BREAK UNSKIPPABLE "Graças a você, Ganondorf tem\n"
"foi selado dentro do Reino do Mal!" BOX_BREAK UNSKIPPABLE "Assim, a paz voltará\n"
"reinar neste mundo... por um tempo."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT UNSKIPPABLE("\x3C") "Obrigado...\n"
SHIFT("\x32") NAME "..." BOX_BREAK_DELAYED("\x28") SHIFT UNSKIPPABLE("\x32") "Adeus...." FADE("\x3C")
)

DEFINE_MESSAGE(0x7071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você realmente quer passar\n"
"esse portão tanto? Deixe-me pensar\n"
"sobre isso... OK, mas em troca..." TEXTID("\x70\x72")
)

DEFINE_MESSAGE(0x7072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Dê-me 10 rúpias...\n"
"\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Por favor, acredite em mim...\n"
"Minhas profecias nunca foram\n"
"errado!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você destruiu os perversos\n"
"criaturas que assombravam o templo\n"
"e despertou o Sábio..." BOX_BREAK UNSKIPPABLE "Mas ainda existem outros Sábios\n"
"quem precisa de sua ajuda." BOX_BREAK UNSKIPPABLE "Para despertar todos os outros\n"
"Sábios, vocês devem se tornar iguais\n"
"mais poderoso." BOX_BREAK UNSKIPPABLE "Você deve viajar\n"
"montanhas..." BOX_BREAK UNSKIPPABLE "debaixo d'água..." BOX_BREAK UNSKIPPABLE "e mesmo através do tempo..."
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Contanto que você segure a " COLOR(LIGHTBLUE) "Ocarina\n"
"of Time" COLOR(DEFAULT) " e a " COLOR(LIGHTBLUE) "Master Sword" COLOR(DEFAULT) "," BOX_BREAK UNSKIPPABLE "você retém o próprio tempo em seu\n"
"mãos..." BOX_BREAK NAME UNSKIPPABLE ", nos encontraremos \n"
"novamente!"
)

DEFINE_MESSAGE(0x7076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Este é um novo tipo de bomba!\n"
"Está disponível apenas em quantidade limitada\n"
"quantidades, e quando eu for vendido \n"
"fora, é isso!" EVENT
)

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sou " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"Sobrevivente dos Sheikahs..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Como eu vejo você parado aí\n"
"segurando o mítico " COLOR(RED) "Mestre \n"
"Sword" COLOR(DEFAULT) ", você realmente se parece com o \n"
"Lendário Herói do Tempo..."
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você acredita na lenda, você\n"
"não tem escolha. Você deve procurar\n"
"os cinco templos e desperte os\n"
COLOR(RED) "cinco Sábios" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Um Sábio está esperando a hora\n"
"de despertar na " COLOR(ADJUSTABLE) "Templo da Floresta" COLOR(DEFAULT) ".\n"
"A Sábia é uma garota, tenho certeza que você\n"
"sabe..." BOX_BREAK UNSKIPPABLE "Por causa do poder maligno no\n"
"templo, ela não pode ouvir o\n"
"chamado de despertar do Sagrado\n"
"Reino..." BOX_BREAK UNSKIPPABLE "Infelizmente, equipado como você \n"
"atualmente está, você não pode nem\n"
"entre no templo..." BOX_BREAK UNSKIPPABLE "Mas, se você acredita no que estou dizendo,\n"
"você deve ir para " COLOR(RED) "Kakariko \n"
"Village" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Você entendeu, \n"
NAME "?"
)

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Achei que deveria confiar a\n"
"Ocarina para você... eu pensei que \n"
"seria nossa melhor chance..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Antes disso... tenho coisas que quero \n"
"para contar apenas para você. Por favor, ouça." BOX_BREAK UNSKIPPABLE "Outra lenda desconhecida do \n"
"Triforce transmitida pelo \n"
"povo das sombras, os Sheikahs..."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A Triforce se separou em três \n"
"peças. Apenas a " COLOR(RED) "Triforce of Power" COLOR(DEFAULT) "\n"
"permaneceu na mão de Ganondorf."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "A força da Triforce de\n"
"O poder permitiu que ele se tornasse um\n"
"poderoso e malvado rei, mas sua escuridão\n"
"ambições não foram satisfeitas."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Para obter o domínio completo do \n"
"mundo, Ganondorf começou a procurar\n"
"para " COLOR(RED) "os escolhidos pelo destino" COLOR(DEFAULT) " para \n"
"segure as outras duas partes da Triforce."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Naquele dia, sete anos atrás,\n"
"Ganondorf atacou o Castelo de Hyrule."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Depois que você abriu a porta de \n"
"tempo, a Espada Mestra selou você\n"
"longe no Reino Sagrado..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Seu espírito permaneceu no Sagrado\n"
"Reino... e então a Triforce caiu \n"
"nas mãos de Ganondorf. Ele foi\n"
"invadindo o Reino Sagrado..." BOX_BREAK UNSKIPPABLE "Ganondorf se tornou o Mal\n"
"Rei e o Reino Sagrado\n"
"tornou-se um mundo do mal. Todos\n"
"esta é uma infeliz coincidência." BOX_BREAK UNSKIPPABLE "Eu me fiz passar por Sheikah\n"
"e esperava que você voltasse.\n"
"Esperei sete anos..."
)

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E... agora você está de volta. O \n"
"idade das trevas governada por Ganondorf o\n"
"O Rei Maligno vai acabar!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Os seis Sábios abrirão o selado\n"
"porta e atrai Ganondorf de volta para\n"
"o Reino Sagrado". BOX_BREAK UNSKIPPABLE "Vou então selar a porta para o \n"
"Reino Sagrado deste mundo." BOX_BREAK UNSKIPPABLE "Assim, Ganondorf, o Rei Maligno, irá\n"
"desaparecer de Hyrule." BOX_BREAK NAME UNSKIPPABLE "...\n"
"Para fazer isso, preciso do seu \n"
"coragem novamente. Por favor, proteja-me\n"
"enquanto eu faço a minha parte." BOX_BREAK UNSKIPPABLE "E aqui está uma arma que pode \n"
"penetrar nas defesas do Rei Maligno...\n"
"O poder dado ao escolhido \n"
"uns..." BOX_BREAK UNSKIPPABLE SHIFT("\x0F") "O sagrado " COLOR(LIGHTBLUE) "Arrow of Light" COLOR(DEFAULT) "!!!"
)

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Mas você baixou a guarda...\n"
"Eu sabia que você apareceria se eu deixasse\n"
"esse garoto anda por aí!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Meu único erro foi um pouco\n"
"subestimar o poder disso\n"
"miúdo..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Não...\n"
"Não era o poder do garoto I\n"
"julgado mal, foi o poder de\n"
"a Triforce da Coragem!" BOX_BREAK UNSKIPPABLE "Mas, com a Triforce da Sabedoria\n"
"que Zelda tem...\n"
"Quando eu conseguir essas duas Triforces..." BOX_BREAK UNSKIPPABLE "Então, eu me tornarei o verdadeiro\n"
"governante do mundo!!"
)

DEFINE_MESSAGE(0x7088, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "A Ocarina of Time abriu o\n"
"porta. O Herói do Tempo, com a\n"
"Espada Mestra, desceu aqui." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece estranho que pacotes de\n"
"cachorros perambulam pelas nossas ruas à noite...\n"
"Isso não parece estranho para você?"
)

DEFINE_MESSAGE(0x708A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, filho, vou te dizer uma coisa\n"
"útil..." BOX_BREAK "Ouvi dizer que existe um " COLOR(RED) "misterioso \n"
"fonte" COLOR(DEFAULT) " em algum lugar perto do \n"
"castelo..."
)

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Se você quiser voltar para o seu\n"
"hora original, devolva o mestre \n"
"Espada para o " COLOR(RED) "Pedestal do Tempo" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Ao fazer isso, você viajará de volta\n"
"no tempo sete anos ...."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Chegará o momento em que você\n"
"tenho que voltar aqui rapidamente...\n"
"Vou te ensinar isso para quando \n"
"aquela hora chega..." BOX_BREAK UNSKIPPABLE "A música para retornar ao \n"
"Templo do Tempo...\n"
COLOR(LIGHTBLUE) "O Prelúdio da Luz" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu sou " COLOR(RED) "Impa " COLOR(DEFAULT) "dos Sheikahs.\n"
"Sou responsável por proteger\n"
"Princesa Zelda. Tudo é \n"
"exatamente como a princesa predisse."
)

DEFINE_MESSAGE(0x708E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se os soldados do castelo encontrarem você,\n"
"haverá problemas. Deixe-me \n"
"levá-lo para fora do castelo."
)

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Ei, você! Não cause nenhum problema!" EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Você é um menino corajoso...\n"
"Você está saindo em um grande e novo \n"
"aventura, não é?" BOX_BREAK UNSKIPPABLE "Meu papel no sonho da princesa\n"
"era ensinar uma melodia" COLOR(RED) " " COLOR(DEFAULT) "para o um\n"
"da floresta". BOX_BREAK UNSKIPPABLE "Esta é uma melodia antiga " COLOR(BLUE) "passada \n"
"abaixo da Família Real" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Toquei esta música por \n"
"Princesa Zelda como uma canção de ninar de todos os tempos\n"
"desde que ela era um bebê..." BOX_BREAK UNSKIPPABLE "Existe um poder misterioso em \n"
"estas notas." BOX_BREAK UNSKIPPABLE "Agora ouça com atenção..."
)

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Toda a tragédia que se abateu\n"
"Hyrule foi obra minha..." BOX_BREAK UNSKIPPABLE "Eu era tão jovem... não conseguia\n"
"compreender as consequências de \n"
"tentando controlar o Reino Sagrado." BOX_BREAK UNSKIPPABLE "Também te arrastei para isso." BOX_BREAK UNSKIPPABLE "Agora é hora de fazer as pazes \n"
"pelos meus erros..." BOX_BREAK UNSKIPPABLE "Você deve colocar a Espada Mestra para \n"
"descanse e feche a Porta do Tempo..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "No entanto, ao fazer isso, a estrada\n"
"entre os horários estará fechado..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE ",\n"
"dê a Ocarina para mim..." BOX_BREAK UNSKIPPABLE "Como um Sábio, posso devolver você\n"
"ao seu tempo original com ele."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Quando a paz retornar a Hyrule..." BOX_BREAK UNSKIPPABLE "Será a hora de dizermos \n"
"adeus..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Agora, vá para casa, " NAME ".\n"
"Recupere o tempo perdido!" BOX_BREAK UNSKIPPABLE "Início... \n"
"onde você deveria estar...\n"
"do jeito que você deveria ser..."
)

DEFINE_MESSAGE(0x7096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x46") QUICKTEXT_ENABLE "Tsk" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Tsk." EVENT QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, talvez seja demais\n"
"para uma criança pagar." EVENT
)

DEFINE_MESSAGE(0x7098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"OK, vou deixar você passar,\n"
"rapidamente!" EVENT
)

DEFINE_MESSAGE(0x7099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"MANTENHA EM SEGREDO \n"
"PARA TODOS."
)

DEFINE_MESSAGE(0x709A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cara, eu estou TÃO cansado!" BOX_BREAK "A vigília noturna é tão chata!\n"
"Gostaria que alguns fantasmas viessem \n"
"fora ou algo assim..." BOX_BREAK "Ei, estou realmente interessado em \n"
"fantasmas!" BOX_BREAK "Estudá-los é um hobby meu,\n"
"mas nunca se sabe... a hora\n"
"pode vir quando esse tipo de\n"
"o conhecimento pode ser útil!"
)

DEFINE_MESSAGE(0x709B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Casaco de pele do meu precioso cachorrinho\n"
"é muito especial comparado ao \n"
"outros vira-latas por aqui!"
)

DEFINE_MESSAGE(0x709C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Meu precioso cachorrinho pode correr mais rápido\n"
"do que qualquer um dos outros vira-latas\n"
"por aqui!"
)

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Não consigo encontrar meu filhote em lugar nenhum!\n"
"Eu preciso que você o procure! Por favor!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x4C") QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"Esse não é meu cachorro! \n"
"Como você pode misturar meu cachorrinho\n"
"com um vira-lata assim?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x46") QUICKTEXT_ENABLE "Richard!" QUICKTEXT_DISABLE BOX_BREAK "Este é meu pequeno Richard!\n"
"Obrigado! Obrigado!\n"
"Vou dar isso a você como um\n"
"recompensa!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"À noite é perigoso sair\n"
"com todos os cães selvagens por perto...\n"
"Não, eu não estava avisando! \n"
"Estou preocupado com o meu cachorro!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Olá!\n"
"Bem-vindo à " COLOR(RED) "Happy Mask Shop" COLOR(DEFAULT) "!\n"
"Lidamos com máscaras que trazem \n"
"felicidade a todos!" BOX_BREAK "Como você gostaria de ser um \n"
"vendedor da felicidade? Vou te emprestar\n"
"uma máscara. Você vende a máscara e \n"
"traga o " COLOR(RED) "dinheiro " COLOR(DEFAULT) "de volta aqui." BOX_BREAK "Se você quiser ler a multa \n"
"imprima, dê uma olhada no sinal " COLOR(RED) "\n"
COLOR(DEFAULT) "bem ali." BOX_BREAK "Depois de vender todas as máscaras,\n"
"você ficará feliz" COLOR(RED) " " COLOR(DEFAULT) "você mesmo!" BOX_BREAK SHIFT("\x40") "Tenha fé..." EVENT
)

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Selecione uma máscara com esquerda ou direita\n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Fale com o dono da loja.\n"
"Não emprestar" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A " COLOR(RED) "máscara " COLOR(DEFAULT) "é um item " COLOR(YELLOW) "[C] Botão " COLOR(DEFAULT) ". Definir\n"
"COLOR(YELLOW)"[C]"COLOR(DEFAULT)" e pressione "COLOR(YELLOW)"[C]"COLOR(DEFAULT)" para usá-lo." BOX_BREAK "Se você falar com alguém com um \n"
"Máscara, você pode obter uma reação." BOX_BREAK "Se alguém estiver interessado no\n"
"máscara, ele ou ela perguntará a você \n"
"sobre isso. Alguém pode querer o \n"
"mascarar." BOX_BREAK "Em algum lugar do mundo, alguém\n"
"está esperando por essas máscaras." BOX_BREAK SHIFT("\x32") "Apenas tenha fé..." EVENT
)

DEFINE_MESSAGE(0x70A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu posso ter visto um bonitinho\n"
"garota por aqui...\n"
"Talvez ela tenha ido ao castelo?\n"
"Quem sabe?"
)

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, ótimo! Você vendeu!\n"
"Por favor, devolva " COLOR(RED) "10 Rupees " COLOR(DEFAULT) "por\n"
"a Máscara Keaton agora." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah! Você não vendeu o mais novo\n"
"mascarar ainda. Apenas tenha fé... Mantenha\n"
"tentando um pouco mais." EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Pagamento recebido!" EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "O quê?!" QUICKTEXT_DISABLE "\n"
"Você não tem meu dinheiro?!" BOX_BREAK QUICKTEXT_ENABLE "Como você se atreve!" QUICKTEXT_DISABLE BOX_BREAK "É melhor você me trazer meu dinheiro...\n"
"se não!" EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Oh sim!" BOX_BREAK "Muito bem feito!\n"
"Todas as máscaras estão esgotadas." BOX_BREAK "Eu sabia que podia confiar em você!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Como recompensa...\n"
"Eu vou te emprestar esta máscara especial." BOX_BREAK UNSKIPPABLE "Esta é a " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". É uma\n"
"máscara misteriosa transmitida por \n"
"o Sheikah." BOX_BREAK UNSKIPPABLE "Com esta máscara você pode ver dentro de \n"
"mentes de outras pessoas...\n"
"É útil, mas assustador!" BOX_BREAK UNSKIPPABLE "Por que é assustador?" BOX_BREAK UNSKIPPABLE "Você pode descobrir à medida que cresce\n"
"mais velho e descubra o verdadeiro \n"
"sentido da vida..." BOX_BREAK UNSKIPPABLE "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"A partir de agora você pode pegar qualquer um\n"
"máscara que você quer.\n"
"Basta ter fé..." EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Bem-vindo!\n"
"Qual máscara posso emprestar para você?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Escolha uma máscara com esquerda ou direita \n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Pergunte sobre a Máscara da Verdade\n"
"Não empreste uma máscara" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Esta é a " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". É uma\n"
"máscara misteriosa transmitida por \n"
"o Sheikah." BOX_BREAK "Com esta máscara você pode ver dentro de \n"
"mentes de outras pessoas. É útil,\n"
"mas assustador!" BOX_BREAK "Por que é assustador?" BOX_BREAK "Você descobrirá à medida que envelhecer!" BOX_BREAK "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara da Verdade -- Não à Venda" COLOR(DEFAULT) "\n"
"Esta máscara tem poderes especiais." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara de Caveira -- Preço 20 Rupees" COLOR(DEFAULT) "\n"
"Uma máscara de caveira com chifres." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara assustadora -- Preço 30 rúpias\n"
COLOR(DEFAULT) "Uma máscara de madeira triste." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Keaton Mask -- Preço 10 Rupees\n"
COLOR(DEFAULT) "O material Keaton é quente, quente, quente!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Capuz de Coelho -- Preço 50 Rupees\n"
COLOR(DEFAULT) "Com orelhas de coelho balançando!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara de Caveira -- Livre para Empréstimo" COLOR(DEFAULT) "\n"
"Uma máscara de caveira com chifres." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara Assustadora -- Grátis para Empréstimo\n"
COLOR(DEFAULT) "Uma máscara de madeira triste." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Keaton Mask -- Gratuito para Empréstimo\n"
COLOR(DEFAULT) "O material Keaton é quente, quente, quente!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Capuz de Coelho -- Gratuito para Empréstimo\n"
COLOR(DEFAULT) "Com orelhas de coelho balançando!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara Goron -- Livre para Empréstimo\n"
COLOR(DEFAULT) "Este rosto redondo faz você \n"
"um pouco mais feliz!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Zora Mask -- Free to Borrow" COLOR(DEFAULT) "\n"
"Você vai ficar legal enquanto estiver\n"
"nadar se você usar esta máscara!" QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Máscara Gerudo -- Livre para Empréstimo\n"
COLOR(DEFAULT) "Com seus olhos encantadores, faz\n"
"disfarce de uma grande dama." QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(RED) "Mask of Truth -- Free to Borrow" COLOR(DEFAULT) "\n"
"Máscara misteriosa para ver nos outros\n"
"mente das pessoas". QUICKTEXT_DISABLE PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer pegar emprestado o " COLOR(RED) "Crânio \n"
"Máscara" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Máscara Assustadora" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Máscara Keaton" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Capuz de Coelho" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Máscara Goron" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Zora Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Máscara Gerudo" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Você quer emprestar o \n"
COLOR(RED) "Máscara da Verdade" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, ótimo! Você vendeu!\n"
"Por favor me pague de volta" COLOR(RED) "20 Rupees \n"
COLOR(DEFAULT) "para a Máscara de Caveira agora." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, ótimo! Você vendeu!\n"
"Por favor, me pague de volta" COLOR(RED) "30 Rupees \n"
COLOR(DEFAULT) "para a Máscara Assustadora agora." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah, ótimo! Você vendeu!\n"
"Por favor me pague de volta" COLOR(RED) "50 Rupees \n"
COLOR(DEFAULT) "para o Capuz de Coelho agora." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Ah! Você não vendeu a máscara\n"
"ainda. Apenas tenha fé para um \n"
"pouco mais." BOX_BREAK "Ou, você quer trocá-lo\n"
"para outra máscara?\n"
TWO_CHOICE COLOR(ADJUSTABLE) "Sim\n"
"Não" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As partes da Triforce estão ressoando...\n"
"Eles estão se combinando em um novamente..."
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "As duas partes Triforce que eu \n"
"não foi possível capturar naquele dia\n"
"há sete anos..." BOX_BREAK UNSKIPPABLE "Não esperava que fossem \n"
"escondido dentro de vocês dois!"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "E agora, finalmente, toda a Triforce\n"
"peças se juntaram aqui!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Esses brinquedos são demais para você!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu ordeno que você os devolva \n"
"para mim!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SFX UNSKIPPABLE("\x68\x5F") COLOR(LIGHTBLUE) NAME "!\n"
"Não posso ajudar você!\n"
"Por causa das ondas de\n"
"escuridão, não consigo chegar perto!" BOX_BREAK COLOR(DEFAULT) UNSKIPPABLE COLOR(LIGHTBLUE) "Desculpe, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O Grande Rei do Mal Ganondorf...\n"
"espancado por esse garoto?!"
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ganondorf... homem lamentável..." BOX_BREAK UNSKIPPABLE "Sem uma mente forte e justa,\n"
"ele não conseguiu controlar o poder de\n"
"os deuses... e..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE ", me escute!\n"
"Esta torre vai desmoronar em breve!" BOX_BREAK UNSKIPPABLE "Com seu último suspiro, Ganondorf é\n"
"tentando nos esmagar nas ruínas de\n"
"a torre! Precisamos nos apressar e\n"
"escapar!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Por favor, siga-me!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Acabou... finalmente acabou..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME DE UNSKIPPABLE  COLOR(LIGHTBLUE) "... \n"
"Lamento não poder ajudá-lo no\n"
"batalha antes!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "O que é esse som?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SFX("\x68\x5F") COLOR(LIGHTBLUE) "Não tem como ele segurar\n"
"eu de volta!\n"
COLOR(DEFAULT) QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Desta vez, lutamos juntos!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME UNSKIPPABLE "! O Mestre \n"
"A espada está aqui! \n"
QUICKTEXT_ENABLE "Apresse-se!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Estou usando meu poder para segurar o\n"
"Rei Maligno! Você usa sua espada e\n"
"dar o golpe final!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x41") "Seis Sábios...\n"
QUICKTEXT_ENABLE SHIFT("\x50") "Agora!!" QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE TEXT_SPEED("\x03") "VOCÊ..." TEXT_SPEED("\x00") FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE TEXT_SPEED("\x03") "Amaldiçoe você...ZELDA!\n"
TEXT_SPEED("\x02") "Amaldiçoe vocês... SÁBIOS!!" TEXT_SPEED("\x00") FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Amaldiçoe você..." QUICKTEXT_ENABLE NAME "!" QUICKTEXT_DISABLE FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Algum dia...\n"
"Quando este selo for quebrado..." BOX_BREAK_DELAYED("\x50") UNSKIPPABLE "É quando eu vou exterminar\n"
"seus descendentes!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Enquanto a Triforce do Poder\n"
"está na minha mão...." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
TEXT_SPEED("\x02") "Você..." TEXT_SPEED("\x00") "quem é você?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0A") "A " COLOR(ADJUSTABLE) "Barreira da Floresta " COLOR(DEFAULT) "é dissipada!\n"
SHIFT("\x14") "Apresse-se, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(RED) "Fire Barrier" COLOR(DEFAULT) " foi dissipada!\n"
SHIFT("\x14") "Apresse-se, irmão!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(BLUE) "Barreira de Água " COLOR(DEFAULT) "é dissipada!\n"
SHIFT("\x46") "Apresse-se!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(PURPLE) "Barreira de Sombra " COLOR(DEFAULT) "é dissipada!\n"
SHIFT("\x1E") "Por favor salve a princesa!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(YELLOW) "Barreira do Espírito " COLOR(DEFAULT) "é dissipada!\n"
SHIFT("\x37") "Apresse-se, garoto!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT("\x0F") "A " COLOR(LIGHTBLUE) "Barreira de Luz " COLOR(DEFAULT) "é dissipada!\n"
SHIFT("\x4B") "Depressa!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) NAME ", não é...?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
COLOR(LIGHTBLUE) "É aquela lâmina lendária..." COLOR(DEFAULT) FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE SHIFT("\x29") COLOR(LIGHTBLUE) "A Espada Mestra!!" COLOR(DEFAULT) QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Encontre os outros Sábios" COLOR(RED) "\n"
COLOR(DEFAULT) "e salve Hyrule!" FADE("\x50")
)

DEFINE_MESSAGE(0x70EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aquele homem de aparência assustadora levou\n"
"fora daqui muito rápido!"
)

DEFINE_MESSAGE(0x70EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, que assustador...\n"
"Ah, tão assustador..."
)

DEFINE_MESSAGE(0x70EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o que você quer?\n"
"Não tenho tempo para conversar\n"
"para você!"
)

DEFINE_MESSAGE(0x70ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor... com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "...\n"
"Por favor, me venda algo...\n"
"Por favor... com " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x70EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não"
"Não é isso que eu quero...\n"
"Eu quero " COLOR(RED) "algo dentro de uma garrafa" COLOR(DEFAULT) "...\n"
"Eu não quis dizer isso..."
)

DEFINE_MESSAGE(0x70EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não"
"Não aguento isso...\n"
"Não é isso que eu quero comprar..."
)

DEFINE_MESSAGE(0x70F0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, isso é " COLOR(LIGHTBLUE) "Blue Fire" COLOR(DEFAULT) "!\n"
"Vou comprar por " COLOR(RED) "150 Rupees" COLOR(DEFAULT) "!\n"
"Todas as vendas finais, ok?"
)

DEFINE_MESSAGE(0x70F1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, uma " COLOR(ROXA) "Peixe" COLOR(DEFAULT) "!\n"
"Vou comprar por " COLOR(RED) "100 Rupees" COLOR(DEFAULT) "!\n"
"Todas as vendas finais, ok?"
)

DEFINE_MESSAGE(0x70F2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, que bonitinho" COLOR(ADJUSTABLE) "Inseto" COLOR(DEFAULT) "!\n"
"Vou comprar por " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!\n"
"Todas as vendas finais, ok?"
)

DEFINE_MESSAGE(0x70F3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, queridinho" COLOR(LIGHTBLUE) "Fada" COLOR(DEFAULT) "!\n"
"Vou comprar por " COLOR(RED) "25 Rupees" COLOR(DEFAULT) "!\n"
"Todas as vendas finais, ok?"
)

DEFINE_MESSAGE(0x70F4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah... você é muito enérgico\n"
"jovem. Você é corajoso e\n"
"bonito também." BOX_BREAK UNSKIPPABLE "Heh heh heh...seu nome é\n"
NAME ", não é." BOX_BREAK UNSKIPPABLE "Heh heh he... não se surpreenda.\n"
"Eu posso ler a mente das pessoas." BOX_BREAK UNSKIPPABLE "Se eu parecesse tão bem quanto você, eu\n"
"poderia executar um tipo diferente de \n"
"negócio...heh he heh..." BOX_BREAK UNSKIPPABLE "Minha loja é a única " COLOR(RED) "Loja Fantasma" COLOR(DEFAULT) "\n"
"em Hyrule." BOX_BREAK UNSKIPPABLE "Por causa do grande Ganondorf, \n"
"é um bom momento para um negócio \n"
"assim... heh heh heh..." BOX_BREAK UNSKIPPABLE "Ah... só posso esperar o mundo \n"
"fica ainda pior!" BOX_BREAK UNSKIPPABLE "Os fantasmas, chamados " COLOR(RED) "Poes" COLOR(DEFAULT) ", são \n"
"espíritos de ódio concentrado \n"
"que aparecem nos campos e \n"
"cemitério. Eles odeiam o mundo!" BOX_BREAK UNSKIPPABLE "Jovem, se você pegar um Poe, eu\n"
"vai pagar muito caro por isso...\n"
"Heh he he he!"
)

DEFINE_MESSAGE(0x70F5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, jovem. O que está acontecendo \n"
"hoje? Se você tiver um " COLOR(RED) "Poe" COLOR(DEFAULT) ", eu vou \n"
"compre." BOX_BREAK "Seu cartão agora tem pontos " COLOR(PURPLE) HIGHSCORE(HS_POE_POINTS) " " COLOR(DEFAULT) ".\n"
"Volte novamente!\n"
"Heh he he he!"
)

DEFINE_MESSAGE(0x70F6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, você trouxe um Poe hoje!" BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00") BOX_BREAK UNSKIPPABLE "Hmmm..." BOX_BREAK UNSKIPPABLE "Esta é uma " COLOR(RED) "normal" COLOR(DEFAULT) " " COLOR(RED) "Poe" COLOR(DEFAULT) ".\n"
"Aqui estão seus " COLOR(RED) "10 Rupees" COLOR(DEFAULT) ".\n"
"Pegue eles." BOX_BREAK UNSKIPPABLE "Heh heh."
)

DEFINE_MESSAGE(0x70F7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ah, você trouxe um Poe hoje!" BOX_BREAK UNSKIPPABLE "Hmmmm!" BOX_BREAK UNSKIPPABLE "Muito interessante!\n"
"Esta é uma " COLOR(RED) "Big Poe" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Vou comprar por " COLOR(RED) "50 Rupees" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Além disso, vou colocar " COLOR(RED) "100\n"
"aponta " COLOR(DEFAULT) "no seu cartão." BOX_BREAK UNSKIPPABLE "Se você ganhar " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) ", você\n"
"seja um homem feliz! Heh heh."
)

DEFINE_MESSAGE(0x70F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Espere um minuto! UAU!" BOX_BREAK UNSKIPPABLE "Você ganhou " COLOR(RED) "1.000 pontos" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Jovem, você é um verdadeiro\n"
COLOR(RED) "Caçador de Fantasmas" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "É isso que você esperava que eu fizesse\n"
"dizer? Heh heh heh!" BOX_BREAK UNSKIPPABLE "Por sua causa, tenho extra\n"
"inventário de " COLOR(RED) "Big Poes" COLOR(DEFAULT) ", então isso vai\n"
"ser a última vez que posso comprar um \n"
"fantasma." BOX_BREAK UNSKIPPABLE "Você está pensando no que eu \n"
"prometido aconteceria quando você\n"
"ganhou 1.000 pontos. Heh heh." BOX_BREAK UNSKIPPABLE "Não se preocupe, eu não esqueci.\n"
"Apenas pegue isso."
)

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Ah? O que é isso?" BOX_BREAK UNSKIPPABLE TEXT_SPEED("\x02") QUICKTEXT_ENABLE "É" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "esse" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "uma fada" COLOR(DEFAULT) QUICKTEXT_DISABLE "?!" BOX_BREAK UNSKIPPABLE "Então, você está...\n"
"Você é da floresta?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Então...então...você não aconteceria com\n"
"tem... a " COLOR(ADJUSTABLE) "Pedra Espiritual do \n"
"Floresta" COLOR(DEFAULT) ", você faria?! Aquele verde \n"
"e pedra brilhante..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu tive um sonho...No sonho,\n"
"nuvens de tempestade escuras estavam ondulando\n"
"sobre a terra de Hyrule..." BOX_BREAK UNSKIPPABLE "Mas de repente, um raio de luz disparou\n"
"fora da floresta, partiu a\n"
"nuvens e iluminaram o chão..." BOX_BREAK UNSKIPPABLE "A luz virou uma figura\n"
"segurando uma " COLOR(ADJUSTABLE) "pedra verde e brilhante" COLOR(DEFAULT) ",\n"
"seguido por um " COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Sei que esta é uma profecia que\n"
"alguém viria do\n"
COLOR(ADJUSTABLE) "floresta" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Sim, pensei que você poderia\n"
"seja o único..." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
SHIFT UNSKIPPABLE("\x3A") "Oh, me desculpe!" BOX_BREAK UNSKIPPABLE "Me empolguei com minha história \n"
"e nem apresentou corretamente \n"
"Eu mesmo!" EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE SHIFT("\x0C") "Eu sou " COLOR(LIGHTBLUE) "Zelda" COLOR(DEFAULT) ", Princesa de Hyrule." EVENT
)

DEFINE_MESSAGE(0x7100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê? Já nos encontramos antes?"
)

DEFINE_MESSAGE(0x7101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Awww... Que fofo!\n"
"Você poderia me dizer onde você\n"
"encontrei?"
)

DEFINE_MESSAGE(0x7102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah!\n"
"Me ajude!"
)

DEFINE_MESSAGE(0x7103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh... sim? E daí?"
)

DEFINE_MESSAGE(0x7104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu odeio raposas!"
)

DEFINE_MESSAGE(0x7105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que irritante!"
)

DEFINE_MESSAGE(0x7106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você parece bem!"
)

DEFINE_MESSAGE(0x7107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "YEEEAH! Qual é o seu problema?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh... isso é uma Zora?\n"
"Esses olhos legais são mesmo\n"
"fascinante..."
)

DEFINE_MESSAGE(0x7109, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, não! Você é assustador!\n"
"Não se aproxime mais!"
)

DEFINE_MESSAGE(0x710A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau... que nostalgia! Isso\n"
"me lembra quando eu era um\n"
"menino".
)

DEFINE_MESSAGE(0x710B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso é meio engraçado...é\n"
"me faz rir!\n"
"Ei, ei!"
)

DEFINE_MESSAGE(0x710C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Uh-oh!" QUICKTEXT_DISABLE "Sinto muito, mãe!\n"
"Ah... ei, é você!\n"
"Não me assuste assim\n"
"que!"
)

DEFINE_MESSAGE(0x710D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeça grande você tem!"
)

DEFINE_MESSAGE(0x710E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, não faça isso!\n"
"Eu sou tímido..."
)

DEFINE_MESSAGE(0x710F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Existe uma competição de máscaras\n"
"continuando? \n"
QUICKTEXT_ENABLE "Vou votar em você!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x7110, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah! Um coelho!\n"
"Falando em coelhos, eu vi um \n"
"homem estranho perseguindo coelhos \n"
"por aí..."
)

DEFINE_MESSAGE(0x7111, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oooh, que mulher bonita!\n"
"Mas você é meio baixinho,\n"
"não é você?"
)

DEFINE_MESSAGE(0x7112, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem... não consigo pensar em nada\n"
"engraçado dizer... desculpe, garoto!"
)

DEFINE_MESSAGE(0x7113, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uma máscara... Quando eu era pequeno \n"
"garoto, eu também usava máscaras por aí...\n"
"O quê? Você diz que não pode imaginar\n"
"eu fazendo isso?"
)

DEFINE_MESSAGE(0x7114, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhhh... entendi...\n"
"É uma ilusão..."
)

DEFINE_MESSAGE(0x7115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, garoto, não cresça para ser\n"
"como eu..."
)

DEFINE_MESSAGE(0x7116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "AAAAAAAAAAAH!\n"
"UM GERUDO!!!!" QUICKTEXT_DISABLE BOX_BREAK "O quê? Uma máscara?\n"
"Por que você tem uma máscara \n"
"Curtiu isso?!"
)

DEFINE_MESSAGE(0x7117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe, estou ocupado agora."
)

DEFINE_MESSAGE(0x7118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh uau! É Keaton!\n"
"Oi, Keaton!"
)

DEFINE_MESSAGE(0x7119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que assustador!\n"
"Há um menino em Kakariko\n"
"Aldeia que estava procurando por um\n"
"máscara assim!"
)

DEFINE_MESSAGE(0x711A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm... bem... você não tem nenhum\n"
"outras máscaras?"
)

DEFINE_MESSAGE(0x711B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que máscara estranha!\n"
"Ei ha ha ha!"
)

DEFINE_MESSAGE(0x711C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei garoto! Você não vê que estamos\n"
"ocupado?! Deixe-nos em paz!"
)

DEFINE_MESSAGE(0x711D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe. Eu nem quero\n"
"olhe para qualquer outra mulher!"
)

DEFINE_MESSAGE(0x711E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee.\n"
"Não dê atenção a isso\n"
"garoto, meu querido... Apenas finja que estamos\n"
"no nosso mundinho privado..."
)

DEFINE_MESSAGE(0x711F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, por favor!\n"
"Vá incomodar alguém \n"
"senão!"
)

DEFINE_MESSAGE(0x7120, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Há um boato circulando sobre isso\n"
"há uma Loja de Poções que pode\n"
"faça o remédio definitivo!"
)

DEFINE_MESSAGE(0x7121, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ouvi um boato de que existe um \n"
"monstro que come" COLOR(LIGHTBLUE) "Hylian Shields" COLOR(DEFAULT) "\n"
"em algum lugar do mundo.\n"
"Você já viu isso?"
)

DEFINE_MESSAGE(0x7122, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vim aqui para vender bombas...\n"
"Por favor, compre alguns!"
)

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Eu... estou com medo...\n"
"Tenho a sensação de que o homem está indo\n"
"para destruir Hyrule." BOX_BREAK UNSKIPPABLE "Ele tem um poder tão terrível!" BOX_BREAK UNSKIPPABLE "Mas é uma sorte que você tenha \n"
"vem..." EVENT
)

DEFINE_MESSAGE(0x7124, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê? Se você quer alguma coisa,\n"
"apenas deixe claro!"
)

DEFINE_MESSAGE(0x7125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou ocupado! Saia do meu caminho,\n"
"seu vagabundo!"
)

DEFINE_MESSAGE(0x7126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, você tem algo bom,\n"
"madeira de qualidade aí, garoto!"
)

DEFINE_MESSAGE(0x7127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm!\n"
"Saia da minha frente!\n"
"Você não serve para nada..."
)

DEFINE_MESSAGE(0x7128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"EEEEEEEEEE!\n"
"Opa, eu não deveria gritar como\n"
"isso ou o chefe vai gritar comigo!"
)

DEFINE_MESSAGE(0x7129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, desculpe chefe! \n"
"Eu não queria relaxar!\n"
"Vou ficar ocupado!" BOX_BREAK "Ah, não é você, chefe?"
)

DEFINE_MESSAGE(0x712A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Gerudos são lindos e corajosos...\n"
"Eles são tão fascinantes!"
)

DEFINE_MESSAGE(0x712B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Algum dia, quando eu tiver mais habilidade,\n"
"Eu vou esculpir uma máscara como essa!"
)

DEFINE_MESSAGE(0x712C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, essa é a máscara\n"
"todo mundo está falando!\n"
"Parece meio estranho..."
)

DEFINE_MESSAGE(0x712D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A-ha-ha!\n"
"Como vão os negócios,\n"
"Sr. Herói?\n"
"Ha ha ha ha!"
)

DEFINE_MESSAGE(0x712E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou de plantão.\n"
"Entendeu?\n"
"EM SERVIÇO!"
)

DEFINE_MESSAGE(0x712F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm, bem, eu realmente não sei\n"
"o que dizer sobre isso..."
)

DEFINE_MESSAGE(0x7130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh uau! Fofo!\n"
"Mas Cuccos são muito mais fofos!"
)

DEFINE_MESSAGE(0x7131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, o quê?\n"
"Você está triste?\n"
"Feliz?\n"
"Eu realmente não posso dizer..."
)

DEFINE_MESSAGE(0x7132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Desculpe, não estou realmente\n"
"interessado nisso."
)

DEFINE_MESSAGE(0x7133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"A criança brincando no\n"
"cemitério estava dizendo algo\n"
"sobre o rosto dele..."
)

DEFINE_MESSAGE(0x7134, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu realmente sou um bom homem.\n"
"Você não acredita em mim?"
)

DEFINE_MESSAGE(0x7135, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHAAAA--!\n"
"Achei que você fosse aquela bruxa velha!\n"
"Não me assuste assim!"
)

DEFINE_MESSAGE(0x7136, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lembro-me do meu pai falando\n"
"sobre um ferreiro... mas isso\n"
"não importa muito para mim\n"
"qualquer maneira."
)

DEFINE_MESSAGE(0x7137, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não tenho medo de nenhuma floresta \n"
"monstros! Você está tentando\n"
"faça piadas sobre mim?"
)

DEFINE_MESSAGE(0x7138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso? Não consigo ver\n"
"muito bem daqui..."
)

DEFINE_MESSAGE(0x7139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oi de novo! Como você está hoje?"
)

DEFINE_MESSAGE(0x713A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Está tudo bem hoje!"
)

DEFINE_MESSAGE(0x713B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cansado... estou tão cansado..."
)

DEFINE_MESSAGE(0x713C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não me importo com nenhum\n"
"raposas!"
)

DEFINE_MESSAGE(0x713D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso é irritante!\n"
"Isso incomoda meus olhos!"
)

DEFINE_MESSAGE(0x713E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso parece muito bonito!"
)

DEFINE_MESSAGE(0x713F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaaaaah!\n"
"O que há de errado com você?\n"
"Você tem uma atitude ruim?"
)

DEFINE_MESSAGE(0x7140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota! \n"
"Quando você fala com alguém, você\n"
"deve fazer contato visual!"
)

DEFINE_MESSAGE(0x7141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Quando você fala com alguém, você\n"
"não deveria olhar!"
)

DEFINE_MESSAGE(0x7142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Quando você fala com alguém, você\n"
"deve tirar sua máscara!"
)

DEFINE_MESSAGE(0x7143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Seu idiota!\n"
"Não sei por que estou ligando\n"
"você isso, mas... você é um!"
)

DEFINE_MESSAGE(0x7144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Onde você conseguiu isso?\n"
"O quê?\n"
"É uma máscara?"
)

DEFINE_MESSAGE(0x7145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uh, me deixe em paz...\n"
"Você não vê que estou em um ritmo\n"
"agora mesmo?"
)

DEFINE_MESSAGE(0x7146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uma máscara é como um musical \n"
"instrumento--ele reflete o\n"
"personagem de seu dono. Gosto\n"
"sua originalidade, garoto!"
)

DEFINE_MESSAGE(0x7147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeça grande!\n"
"Como você passou por aquela porta?!"
)

DEFINE_MESSAGE(0x7148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"EU ODEIO raposas, filho!"
)

DEFINE_MESSAGE(0x7149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Agora, se isso não for o máximo\n"
"rosto irritante que vi em\n"
"todos os meus dias, não sei o que\n"
"é!"
)

DEFINE_MESSAGE(0x714A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, que cara legal\n"
"Você chegou lá, filho!"
)

DEFINE_MESSAGE(0x714B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você tem alguma reclamação?\n"
"Fala, então!"
)

DEFINE_MESSAGE(0x714C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, pare de brincar\n"
"e dissipar nossa maldição!"
)

DEFINE_MESSAGE(0x714D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Se eu usasse algo assim...\n"
"Eu seria uma verdadeira Skulltula...\n"
"AAAAAAAAAAA!"
)

DEFINE_MESSAGE(0x714E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Por favor, entenda se eu não\n"
"risos... É difícil ser feliz\n"
"nesta condição... \n"
"Ser amaldiçoado e tudo..."
)

DEFINE_MESSAGE(0x714F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x67") "Olá!\n"
"Isso é assustador!\n"
"Eu sei que sou assustador, mas... cara!\n"
"Isso é realmente assustador!"
)

DEFINE_MESSAGE(0x7150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Huh?! O que--!" BOX_BREAK "Ah, é só uma criança.\n"
"Não me assuste assim!\n"
"Posso não parecer, mas sou um\n"
"cara muito sensível!"
)

DEFINE_MESSAGE(0x7151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Bem, você vai olhar para a cabeça em \n"
"esse garoto! É ENORME!\n"
"A minha também é enorme, embora..."
)

DEFINE_MESSAGE(0x7152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você sabe que tipo de\n"
"máscara que você está usando...?\n"
"E você ainda está usando?"
)

DEFINE_MESSAGE(0x7153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Estou de plantão agora... \n"
"Se você quer que eu cave, não\n"
"me incomode."
)

DEFINE_MESSAGE(0x7154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso? É algo\n"
"que pula em um campo...\n"
"Esqueci o que são essas coisas\n"
"chamado..."
)

DEFINE_MESSAGE(0x7155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! É uma Máscara Keaton!!\n"
"Pedi ao meu pai para me dar um,\n"
"também!"
)

DEFINE_MESSAGE(0x7156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso não é muito diferente de\n"
"Sr. Dampé, não é?"
)

DEFINE_MESSAGE(0x7157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso não se parece com\n"
"Sr. Dampé, hein?"
)

DEFINE_MESSAGE(0x7158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Ei, máscara legal... mas um pouco\n"
"Assustador, você não acha?"
)

DEFINE_MESSAGE(0x7159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei! Isso parece familiar...\n"
"Acho que vi algo parecido\n"
"no Bosque Perdido, não?"
)

DEFINE_MESSAGE(0x715A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x63") "Isso me faz sentir... feliz..."
)

DEFINE_MESSAGE(0x715B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah... uh... cheirar...\n"
"Essa máscara...\n"
"Isso me faz sentir... triste..."
)

DEFINE_MESSAGE(0x715C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hah! Essa máscara não vai te fazer nada\n"
"bom! Você está com medo de mim,\n"
"o grande Mido... não é?!"
)

DEFINE_MESSAGE(0x715D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Waaaaah! O quê?\n"
"Ei, não tenho medo de você!\n"
"Só não se aproxime,\n"
"Compreendo?!"
)

DEFINE_MESSAGE(0x715E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, que máscara legal.\n"
"Eu quero!\n"
"SÓ BRINCANDO! Hah!\n"
"Eu não quero essa máscara estúpida!"
)

DEFINE_MESSAGE(0x715F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau ha ha ha!\n"
"Isso realmente combina com você!"
)

DEFINE_MESSAGE(0x7160, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah!\n"
"Vou contar ao Mido sobre \n"
"esta!"
)

DEFINE_MESSAGE(0x7161, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Aaaah!\n"
"Vou dizer ao Mido para bater\n"
"você acorda!"
)

DEFINE_MESSAGE(0x7162, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ooooh!\n"
"Você é algum tipo de floresta\n"
"fantasma?"
)

DEFINE_MESSAGE(0x7163, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que legal!\n"
"Uh... não diga a Mido que eu disse isso!"
)

DEFINE_MESSAGE(0x7164, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O quê?!\n"
"Você voltou!\n"
"Eu posso dizer quem você é, mesmo\n"
"com essa máscara!"
)

DEFINE_MESSAGE(0x7165, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu me pergunto o que Mido diria se\n"
"ele viu isso?\n"
"Eu realmente gostaria de ver o dele\n"
"reação!"
)

DEFINE_MESSAGE(0x7166, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu vi"
"Você vai assustar o Mido com\n"
"essa máscara, não é?!"
)

DEFINE_MESSAGE(0x7167, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha ha!\n"
"Que cara engraçada!\n"
"Aposto que Saria pensaria que é\n"
"muito engraçado, também!"
)

DEFINE_MESSAGE(0x7168, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee hee!\n"
"Uma máscara de madeira?\n"
"Parece que você está vestindo\n"
"um escudo em seu rosto!"
)

DEFINE_MESSAGE(0x7169, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cara estranha!" BOX_BREAK "Falando em rostos estranhos, um dos\n"
"as crianças da floresta estavam reclamando\n"
"sobre o rosto dele..."
)

DEFINE_MESSAGE(0x716A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que cabeça enorme você tem!"
)

DEFINE_MESSAGE(0x716B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tee hee!\n"
"Onde você conseguiu isso?\n"
"Fora da floresta?\n"
"De jeito nenhum! Eu não acredito!"
)

DEFINE_MESSAGE(0x716C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ei!\n"
"Meio engraçado, mas não é\n"
"realmente meu estilo..."
)

DEFINE_MESSAGE(0x716D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Certo! \n"
"Usar esta máscara me faz sentir\n"
"muito difícil e assustador!\n"
"Ei, ei!"
)

DEFINE_MESSAGE(0x716E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ei!\n"
"Com certeza há muitos diferentes\n"
"pessoas do mundo!"
)

DEFINE_MESSAGE(0x716F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, ei!\n"
"Não preciso de um novo...\n"
"Eu gosto do que eu tenho, obrigado!"
)

DEFINE_MESSAGE(0x7170, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6D") "Uau, isso faz sua cabeça\n"
"parece enorme!\n"
"Ei, ei!"
)

DEFINE_MESSAGE(0x7171, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6B") "Que ratinho fofo!\n"
"O quê?\n"
"Ah, não é um rato?"
)

DEFINE_MESSAGE(0x7172, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x6C") "O que são esses disquetes\n"
"na sua cabeça?\n"
"Orelhas? Essa máscara faz você parecer\n"
"como se você tivesse quatro orelhas!"
)

DEFINE_MESSAGE(0x7173, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x68\x69") "Deve ser emocionante se esgueirar\n"
"passar pelos guardas vestindo\n"
"essa máscara!"
)

DEFINE_MESSAGE(0x7174, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Olá, menino fada!\n"
"O quê?\n"
"Você acha que está disfarçado?\n"
"Mas é tão óbvio quem você é!"
)

DEFINE_MESSAGE(0x7175, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Uau!\n"
"Que olhos grandes você tem!\n"
"Gorons são tão fofos, não são!"
)

DEFINE_MESSAGE(0x7176, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, eu conheço esse personagem!\n"
"É Keaton!\n"
"Ele é muito gostoso no Castelo de Hyrule\n"
"Cidade agora!"
)

DEFINE_MESSAGE(0x7177, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah, irmão!\n"
"Rapazes serão rapazes!"
)

DEFINE_MESSAGE(0x7178, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Espere... espere...\n"
"Eu sei quem você é...\n"
"É... Kin-ton!\n"
"Não é mesmo?!"
)

DEFINE_MESSAGE(0x7179, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso é assustador, não é?\n"
"Quase tão assustador quanto... Ingo!"
)

DEFINE_MESSAGE(0x717A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, isso me lembra minha esposa...\n"
"Pensando bem, não...\n"
"Não parece nada com ela!"
)

DEFINE_MESSAGE(0x717B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAAAWWN...\n"
"Estou meio cansado agora...\n"
"Mostre-me depois..."
)

DEFINE_MESSAGE(0x717C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Calma, garoto!\n"
"Você não vê que estou ocupado?!"
)

DEFINE_MESSAGE(0x717D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Humph!\n"
"Não há problema em jogar assim quando \n"
"você é uma criança, mas espere até\n"
"você cresce! Trabalhe, trabalhe, trabalhe!"
)

DEFINE_MESSAGE(0x717E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YEOW!\n"
"Humph. É só uma máscara...\n"
"Scram, garoto! Saia daqui!"
)

DEFINE_MESSAGE(0x717F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh...\n"
"Bem, isso me animou um pouco,\n"
"garoto.\n"
"Obrigado!"
)

DEFINE_MESSAGE(0x7180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmmm... Vamos ver...\n"
"Sim, tenho certeza...\n"
"Isso foi fabricado a partir de um \n"
"tábua de um caixão. Sim, era!"
)

DEFINE_MESSAGE(0x7181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ahhh... sim. Vamos ver...\n"
"Artesanato muito bom.\n"
"Mas não acho que isso faria\n"
"um bom ingrediente para o meu remédio."
)

DEFINE_MESSAGE(0x7182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Muito interessante! Um Goron!\n"
"Falando em Gorons, eu me pergunto\n"
"como meu velho amigo, Biggoron de\n"
"Monte da Morte, está fazendo?"
)

DEFINE_MESSAGE(0x7183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Construção muito incomum...\n"
"Não acho que seja solúvel em água,\n"
"então não daria um bom \n"
"ingrediente para meus remédios..."
)

DEFINE_MESSAGE(0x7184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"OK, OK, uma máscara.\n"
"Você quer comprar alguns feijões?"
)

DEFINE_MESSAGE(0x7185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Não, eu não quero comprá-lo."
)

DEFINE_MESSAGE(0x7186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Não, não é meu estilo."
)

DEFINE_MESSAGE(0x7187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Chomp chomp chomp...\n"
"Bem... não, acho que não \n"
"eu quero isso."
)

DEFINE_MESSAGE(0x7188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que você quer?"
)

DEFINE_MESSAGE(0x7189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Parece que você não pode\n"
"nadar muito bem..."
)

DEFINE_MESSAGE(0x718A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cabelo ruivo... pele bronzeada...\n"
"Eu já vi pessoas assim antes..."
)

DEFINE_MESSAGE(0x718B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sim, certo.\n"
"Você parece um pouco pequeno para um\n"
"Zora..."
)

DEFINE_MESSAGE(0x718C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ho ho ho!\n"
"Vocês Hylians...vocês são tão bobos\n"
"criaturas!"
)

DEFINE_MESSAGE(0x718D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Esse rosto... me dá calafrios..."
)

DEFINE_MESSAGE(0x718E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Fale sobre uma viagem nostálgica!\n"
"Isso me lembra minha infância\n"
"amigo, Biggoron!"
)

DEFINE_MESSAGE(0x718F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não acho nada engraçado.\n"
"Você está zombando de mim?"
)

DEFINE_MESSAGE(0x7190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você é um cara engraçado!"
)

DEFINE_MESSAGE(0x7191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sua cabeça - é gigantesca!"
)

DEFINE_MESSAGE(0x7192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Não faça isso...\n"
"Está me envergonhando!"
)

DEFINE_MESSAGE(0x7193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Tudo bem! Você realmente decidiu\n"
"para se tornar um Zora!\n"
"Você está realmente pronto para se casar\n"
"eu, agora?"
)

DEFINE_MESSAGE(0x7194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"UAU!\n"
"Meu coração... começou a bater \n"
"tão rápido!"
)

DEFINE_MESSAGE(0x7195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Essa é uma máscara desagradável...\n"
"Adeus."
)

DEFINE_MESSAGE(0x7196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hrrrrm...\n"
"Eu não sei o que dizer."
)

DEFINE_MESSAGE(0x7197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não deveria ser tão exigente sobre\n"
"o que você come! Você come todos os seus\n"
"pedras verdes? Se não, você \n"
"não vai crescer grande e forte!"
)

DEFINE_MESSAGE(0x7198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Me deixe em paz!"
)

DEFINE_MESSAGE(0x7199, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está tentando me fazer rir?\n"
"Bem, isso não é tão engraçado..."
)

DEFINE_MESSAGE(0x719A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você está me deixando louco!"
)

DEFINE_MESSAGE(0x719B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Eu odeio Gerudos!!"
)

DEFINE_MESSAGE(0x719C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Pare de me incomodar!\n"
"Vá embora!"
)

DEFINE_MESSAGE(0x719D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ah ah ah!\n"
"Você acha que está disfarçado?\n"
"Que engraçado!"
)

DEFINE_MESSAGE(0x719E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saia do meu caminho!\n"
"Saia daqui!\n"
"Você está pedindo por isso, não é?"
)

DEFINE_MESSAGE(0x719F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ei, garoto, você tem coragem\n"
"por aqui vestindo isso!\n"
"Ainda assim, você não pode nos enganar assim\n"
"facilmente!"
)

DEFINE_MESSAGE(0x71A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"O que é isso?\n"
"O que isso tem a ver com\n"
"nós?"
)

DEFINE_MESSAGE(0x71A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha!\n"
"Você tem coragem de sobra, não\n"
"você garoto? \n"
"Gosto de você!"
)

DEFINE_MESSAGE(0x71A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Vamos! É hora de ficar sério!"
)

DEFINE_MESSAGE(0x71A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Isso é estranho... parece que\n"
"homens"
"Não... na verdade não. De jeito nenhum,\n"
"se você olhar para ele de perto."
)

DEFINE_MESSAGE(0x71A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hmm. Não, não, não!\n"
"As orelhas não estão certas!\n"
"Eles deveriam ser, você sabe, mais longos!"
)

DEFINE_MESSAGE(0x71A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você não está com medo, \n"
"andando no meio de\n"
"a noite parecendo assim?"
)

DEFINE_MESSAGE(0x71A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ha ha ha!\n"
"Você realmente gosta dessas coisas,\n"
"não é?!"
)

DEFINE_MESSAGE(0x71A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Acho que vi uma pedra que\n"
"parece isso em algum lugar...\n"
"Agora, onde foi isso?\n"
"Hummm..."
)

DEFINE_MESSAGE(0x71A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Apresse-se, " NAME "!\n"
"A qualquer segundo, a torre está \n"
"vai desmoronar!!"
)

DEFINE_MESSAGE(0x71A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Cuidado com os escombros caindo!"
)

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
NAME "!\n"
"Me ajude!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"A saída é logo ali!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Obrigado, " NAME ".\n"
"Agora, vamos nos apressar!"
)

DEFINE_MESSAGE(0x71AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Que pena!" BOX_BREAK "Pratique bastante e volte!" EVENT
)

DEFINE_MESSAGE(0x71AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quase!!" BOX_BREAK "Bem... tudo bem!\n"
"Vou deixar você tentar mais uma vez para\n"
"grátis...\n"
"Desta vez, você tem que fazer isso!" EVENT
)

DEFINE_MESSAGE(0x71AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Maravilhoso!!!\n"
"Bravo!!!\n"
"Perfeito!!!" BOX_BREAK "Aqui está um presente fantástico!" EVENT
)

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE COLOR(LIGHTBLUE) "Ah, não!" COLOR(RED) "Tempo acabou!\n"
COLOR(LIGHTBLUE) "A coisa que você ia \n"
"entrega estragou!\n"
"Vamos tentar de novo!" COLOR(DEFAULT) QUICKTEXT_DISABLE EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "BOIN! BOINNG!\n"
"A hora atual é: " TIME "!" QUICKTEXT_DISABLE FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Você ouviu falar de nós a partir do\n"
"guarda no portão da Montanha da Morte?\n"
"Bem, eu tenho que dar\n"
"você é um bom negócio então!"
)
