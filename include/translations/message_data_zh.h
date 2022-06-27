DEFINE_MESSAGE(0x0001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x2D")  QUICKTEXT_ENABLE "你借到了一颗" COLOR(RED) "口袋鸡蛋" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"过夜后就会孵出一只口袋鸡，\n"
"你用完后别忘记把它还回去。"
)

DEFINE_MESSAGE(0x0002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x2F")  QUICKTEXT_ENABLE "你归还口袋鸡，得到" COLOR(RED) "克洛鸡" COLOR(DEFAULT) " ！" QUICKTEXT_DISABLE "\n"
"与口袋鸡不同，\n"
"克洛鸡很少啼叫。"
)

DEFINE_MESSAGE(0x0003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x30")  QUICKTEXT_ENABLE "你得到了一个" COLOR(RED) "奇异蘑菇" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"新鲜的蘑菇都很容易变质！\n"
"快拿到卡卡利科药店去吧！"
)

DEFINE_MESSAGE(0x0004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x31")  QUICKTEXT_ENABLE "你得到了一个" COLOR(RED) "奇异之药" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"你不知道这两人之间\n"
"发生了什么事，\n"
"但快把奇异之药带到\n"
"迷失的森林去吧！"
)

DEFINE_MESSAGE(0x0005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x32")  QUICKTEXT_ENABLE "奇异之药物归原主了，\n"
"你得到了" COLOR(RED) "偷猎者之锯" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"一定是那个年轻人留下的。"
)

DEFINE_MESSAGE(0x0006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "炸弹   20枚   80卢比" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "买\n"
"不买" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x48")  QUICKTEXT_ENABLE "你得到了一个"COLOR(RED) "德库子弹口袋" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"这个子弹口袋可以装下" COLOR(YELLOW) "40" COLOR(DEFAULT) "\n"
"发弹弓子弹。"
)

DEFINE_MESSAGE(0x0008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x33")  QUICKTEXT_ENABLE "你用偷猎者之锯换到了一把\n"
COLOR(RED) "破损的格雷之剑" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"到大格雷城可以修好它。"
)

DEFINE_MESSAGE(0x0009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x34")  QUICKTEXT_ENABLE "你交出了破损的格雷之剑，\n"
"得到了" COLOR(RED) "处方" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"去见卓拉王吧！"
)

DEFINE_MESSAGE(0x000A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x37")  QUICKTEXT_ENABLE "大格雷之剑…" QUICKTEXT_DISABLE "\n"
"你得到了大格雷之剑的" COLOR(RED) "兑换券" COLOR(DEFAULT) "！\n"
"你急切地希望快点\n"
"铸好这把剑！"
)

DEFINE_MESSAGE(0x000B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "你卖掉了巨人之刀，\n"
"换得了一把" COLOR(RED) "大格雷之剑" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"这把剑是铁匠大师所铸造，\n"
"坚不可摧！"
)

DEFINE_MESSAGE(0x000C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "你用兑换卷换得了\n"
COLOR(RED) "大格雷之剑" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"这把剑是铁匠大师所铸造，\n"
"坚不可摧！"
)

DEFINE_MESSAGE(0x000D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x35")  QUICKTEXT_ENABLE "你用处方换得了\n"
"一只 " COLOR(RED) "大眼青蛙" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"它还是凉的，快点把它\n"
"带到海拉鲁湖去！"
)

DEFINE_MESSAGE(0x000E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x36")  QUICKTEXT_ENABLE "你用大眼青蛙换到了\n"
COLOR(RED) "世上最好的眼药水" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE "\n"
"快！在它变质之前，\n"
"送到大格雷城去！"
)

DEFINE_MESSAGE(0x000F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x41")  COLOR(RED) "你赢啦！！" COLOR(DEFAULT)  EVENT
)

DEFINE_MESSAGE(0x0010, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x25")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "骷髅面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"你戴着它，真像个怪物！"
)

DEFINE_MESSAGE(0x0011, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x26")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "恐怖面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"你可以好好吓吓别人了！"
)

DEFINE_MESSAGE(0x0012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x24")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "基顿面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"戴着它，你会很受欢迎哦！"
)

DEFINE_MESSAGE(0x0013, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x27")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "兔子兜帽" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"那长耳朵真是太可爱了！"
)

DEFINE_MESSAGE(0x0014, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x28")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "格雷面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"它可以让你的头看起来很大！"
)

DEFINE_MESSAGE(0x0015, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x29")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "卓拉面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"戴上它，你就是卓拉人啦！"
)

DEFINE_MESSAGE(0x0016, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x2A")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "格鲁德面具" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！这个面\n"
"具让你看起来有点像…女孩？"
)

DEFINE_MESSAGE(0x0017, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x2B")  QUICKTEXT_ENABLE "你借到一个" COLOR(RED) "Mask of Truth" COLOR(DEFAULT) "。" QUICKTEXT_DISABLE "\n"
"按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 戴上它试试看吧！\n"
"让更多的人看看这个面具吧！"
)

DEFINE_MESSAGE(0x0018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"欢迎来到我们的娱乐中心：\n"
BOX_BREAK SHIFT("\x15")  COLOR(RED) "炸弹保龄球场！" COLOR(DEFAULT)  BOX_BREAK " \n"
"你想知道你可以赢到什么奖品吗？\n"
"好，这是" TEXT_SPEED("\x03") "秘密！" TEXT_SPEED("\x00") "\n"
"你付钱，我才告诉你。\n"
BOX_BREAK COLOR(RED) "30卢比" COLOR(DEFAULT) " 玩一次，要玩吗？\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "要\n"
"不要" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "好！！\n" 
QUICKTEXT_DISABLE  BOX_BREAK "瞄准中间的那个洞，\n"
"放下" COLOR(RED) "炸弹鼠" COLOR(DEFAULT) "！\n"
"你有" COLOR(RED) "十次机会" COLOR(DEFAULT) "！ 预备…" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(RED) "开始吧" COLOR(DEFAULT) "！" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x001A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"想再玩一次吗？\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "想\n"
"不想" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"哦！差点忘了，\n"
"这是你的奖品！" EVENT
)

DEFINE_MESSAGE(0x001C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "炸弹   （20枚）   80卢比\n"
COLOR(DEFAULT) "按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 把炸弹捡起来，再按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 扔出去。\n"
"没有炸弹口袋，你就不能买炸弹。" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "炸弹   （30枚）   120卢比\n"
COLOR(DEFAULT) "按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) "把炸弹捡起来，再按" COLOR(YELLOW) "[C]" COLOR(DEFAULT) " 扔出去。\n"
"没有炸弹口袋，你就不能买炸弹。" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x001E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "炸弹  30枚  120卢比" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "买\n"
"不买" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x001F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"太好了，所有的人都恢复正常了！"
)

DEFINE_MESSAGE(0x0020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"请再救救我的其他兄弟吧！\n"
"他们一定会给你更多更好的奖励。\n"
BOX_BREAK "你可以去救他们吗？！"
)

DEFINE_MESSAGE(0x0021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "诅咒解除了。\n"
"谢谢你！\n"
"这是给你的回报！" EVENT
)

DEFINE_MESSAGE(0x0022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"呀啊！我被诅咒了！！"
)

DEFINE_MESSAGE(0x0023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"我们要小心点，不要再被诅咒了！"
)

DEFINE_MESSAGE(0x0024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"你消灭了诅咒蜘蛛" COLOR(RED)  TOKENS "只" COLOR(DEFAULT) "\n"
"诅咒已经开始减弱了！\n"
BOX_BREAK "那个恢复正常的孩子给了\n"
"你什么奖励吗？" BOX_BREAK "\n"
"你要知道，变得" COLOR(RED) "很富有" COLOR(DEFAULT) "\n"
"只有一个办法，\n"
"那就是消灭更多的诅咒蜘蛛，\n"
"越多越好！" BOX_BREAK "我有一些经验可以帮助你\n"
"首先，你要在晚上行动。\n"
"第二，你要记住，\n"
"它们喜欢松柔的土壤…" BOX_BREAK "\n"
"一定要仔细观察你的周围！\n"
"好了，我们全靠你了！"
)

DEFINE_MESSAGE(0x0025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "我变成这样全都是 \n"
"因为蜘蛛的诅咒。但是…" TEXTID("\x00\x24")
)

DEFINE_MESSAGE(0x0026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"我们变成这种样子\n"
"全是因为蜘蛛的诅咒。" BOX_BREAK "只有世界上所有的" COLOR(RED) "诅咒蜘蛛" COLOR(DEFAULT) "都\n"
"被消灭了，诅咒才会解除。" BOX_BREAK "每消灭一个诅咒蜘蛛，就会出现\n"
"一个徽章。收集这些徽章作为你\n"
"战绩的证明。" BOX_BREAK ITEM_ICON("\x71") COLOR(LIGHTBLUE) "征途状态窗口" COLOR(DEFAULT) "中，此" COLOR(YELLOW) "图标" COLOR(DEFAULT) "\n"
"的旁边有个数字，显示了你" COLOR(BLUE) " \n"
COLOR(DEFAULT) "目前消灭的诅咒蜘蛛的数量。" BOX_BREAK ITEM_ICON("\x71") COLOR(RED) "地图窗口" COLOR(DEFAULT) "中，如果此" COLOR(YELLOW) "图标" COLOR(DEFAULT) " 显\n"
"示在地区名边上，说明那里\n"
"所有的诅咒蜘蛛都被消灭了" TEXTID("\x00\xFE")
)

DEFINE_MESSAGE(0x0027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"如果你帮我们家族解除诅咒，\n"
"我们会让你变得" COLOR(RED) "很富有" COLOR(DEFAULT) "…"
)

DEFINE_MESSAGE(0x0028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "你已经消灭了" COLOR(RED)  TOKENS  "只" COLOR(DEFAULT) " 诅咒蜘蛛，\n"
"我身上的诅咒解除了。\n"
BOX_BREAK UNSKIPPABLE "谢谢你！作为感谢，\n"
"拿着它吧！" EVENT
)

DEFINE_MESSAGE(0x0029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"谢谢你救了我的孩子" BOX_BREAK "什么？我？哦，我还好…" BOX_BREAK "到现在为止，你已经消灭了\n" 
COLOR(RED)  TOKENS  "只" COLOR(DEFAULT) "诅咒蜘蛛，所以…\n"
"很不错…不用担心我…"
)

DEFINE_MESSAGE(0x002A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "炸弹鼠  20枚  180卢比" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "买\n"
"不买" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"要玩吗？玩一次只要" COLOR(RED) "20卢比！" COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "要\n"
"不要" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x002C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"这样不行！你需要有一把弓箭！" EVENT
)

DEFINE_MESSAGE(0x002D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"没关系。如果你不想玩，\n"
"没有人强迫你。" EVENT
)

DEFINE_MESSAGE(0x002E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "好哦！！" QUICKTEXT_DISABLE "\n"
"这是大人玩的游戏！\n"
"海拉鲁著名的" COLOR(RED) "射击场" COLOR(DEFAULT) "！\n" BOX_BREAK 
"从那边的发射台瞄准目标！\n"
"你能够用" COLOR(RED) "十五" COLOR(DEFAULT) "支箭\n"
"射中" COLOR(RED) "十个目标" COLOR(DEFAULT) "吗？" BOX_BREAK "按" COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "准备好武器。 \n"
"准备好了吗？争取一个好成绩吧！\n"
"祝你好运！" EVENT
)

DEFINE_MESSAGE(0x002F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"你看到一堆松软的泥土。"
)

DEFINE_MESSAGE(0x0030, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x06")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Fairy Slingshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "Press " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to take it out and hold\n"
"it. As you hold " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "you can aim \n"
"with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Release " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to unleash \n"
"a " COLOR(RED) "Deku Seed" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x06") "If you want to shoot right \n"
"away, when you first press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", \n"
"hold down " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "a little longer to \n"
"get a seed ready."
)

DEFINE_MESSAGE(0x0031, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x03")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Fairy Bow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x03") "Press " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to take it out\n"
"and hold it. As you hold down\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " you can aim with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "." COLOR(YELLOW) " " COLOR(DEFAULT) "Release\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to let fly with an " COLOR(RED) "arrow" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0032, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x02")  QUICKTEXT_ENABLE "You got " COLOR(RED) "Bombs" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x02") "Use " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to lift and place\n"
"it. Press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " while running to\n"
"throw it. If you see something\n"
"suspicious, bomb it!"
)

DEFINE_MESSAGE(0x0033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x09")  QUICKTEXT_ENABLE "You got " COLOR(RED) "Bombchu" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x09") " Carry and place with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ".\n"
"This is a new type bomb that\n"
"can even crawl up walls.\n"
"Aim well and release it!"
)

DEFINE_MESSAGE(0x0034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x01")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Deku Nut" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x01") "Set it to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and try \n"
"throwing it! It will flash and \n"
"stun the enemy!"
)

DEFINE_MESSAGE(0x0035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0E")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Boomerang" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0E") "Press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to use it to \n"
"attack distant enemies!"
)

DEFINE_MESSAGE(0x0036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0A")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Hookshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"It's a spring-loaded chain that\n"
"you can cast out to hook things." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "You can use it to drag\n"
"distant items toward you, or\n"
"you can use it to pull yourself\n"
"toward something." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0A") "While holding " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ", you can\n"
"aim with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Shoot it by\n"
"releasing " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0037, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x00")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Deku Stick" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x00") "Set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and swing it\n"
"with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x00") "When you want to put it away, \n"
"stand still and press " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". \n"
"You can carry up to 10 sticks,\n"
"but don't waste them."
)

DEFINE_MESSAGE(0x0038, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x11")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Megaton Hammer" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to smash and break \n"
"junk! It's so heavy, you need to \n"
"use two hands to swing it!"
)

DEFINE_MESSAGE(0x0039, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0F")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Lens of Truth" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to \n"
"look through it! Mysterious \n"
"things are hidden everywhere!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0F") "Be sure to try to use it outside\n"
"of the well. Seeing the truth will\n"
"cost magic power, so press " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "again to stop using it."
)

DEFINE_MESSAGE(0x003A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x08")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Ocarina of Time" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is the Royal Family's hidden \n"
"treasure which Zelda left behind.\n"
"It glows with a mystical light..."
)

DEFINE_MESSAGE(0x003B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"You cast Farore's Wind!\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Return to the Warp Point\n"
"Dispel the Warp Point\n"
"Exit" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x003C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x67")  QUICKTEXT_ENABLE "You received the " COLOR(RED) "Fire\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Darunia awakens as a Sage and\n"
"adds his power to yours!"
)

DEFINE_MESSAGE(0x003D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x68")  QUICKTEXT_ENABLE "You received the " COLOR(BLUE) "Water\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Ruto awakens as a Sage and\n"
"adds her power to yours!"
)

DEFINE_MESSAGE(0x003E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x66")  QUICKTEXT_ENABLE "You received the " COLOR(ADJUSTABLE) "Forest\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Saria awakens as a Sage and\n"
"adds her power to yours!"
)

DEFINE_MESSAGE(0x003F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x69")  QUICKTEXT_ENABLE "You received the " COLOR(YELLOW) "Spirit\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Nabooru awakens as a Sage and\n"
"adds her power to yours!"
)

DEFINE_MESSAGE(0x0040, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6B")  QUICKTEXT_ENABLE "You received the " COLOR(LIGHTBLUE) "Light\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Rauru the Sage adds his power\n"
"to yours!"
)

DEFINE_MESSAGE(0x0041, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6A")  QUICKTEXT_ENABLE "You received the " COLOR(PURPLE) "Shadow\n"
"Medallion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Impa awakens as a Sage and\n"
"adds her power to yours!"
)

DEFINE_MESSAGE(0x0042, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x14")  QUICKTEXT_ENABLE "You got an " COLOR(RED) "Empty Bottle" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"After you put something in this\n"
"bottle, set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " when you\n"
"want to use the item inside."
)

DEFINE_MESSAGE(0x0043, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x15")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Red Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x15") "Drink it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to recover\n"
"your life energy.\n"
"You carry this potion in one\n"
"of your bottles."
)

DEFINE_MESSAGE(0x0044, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x16")  QUICKTEXT_ENABLE "You got a " COLOR(ADJUSTABLE) "Green Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x16") "Drink it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to recover\n"
"your magic power.\n"
"You carry this potion in one\n"
"of your bottles."
)

DEFINE_MESSAGE(0x0045, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x17")  QUICKTEXT_ENABLE "You got a " COLOR(BLUE) "Blue Potion" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Drink it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to recover\n"
"your life energy and magic power."
)

DEFINE_MESSAGE(0x0046, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x18")  QUICKTEXT_ENABLE "You caught a " COLOR(RED) "Fairy" COLOR(DEFAULT) " in a bottle!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x18") "This tiny fairy is a reliable \n"
"partner who will revive you\n"
"the moment you run out of life \n"
"energy." BOX_BREAK ITEM_ICON("\x18") "Once you set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ",\n"
"though, you can ask for its help\n"
"anytime."
)

DEFINE_MESSAGE(0x0047, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x19")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Fish" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and something \n"
"might happen... It looks so \n"
"fresh and delicious!" BOX_BREAK ITEM_ICON("\x19") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", and then press that\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to use it."
)

DEFINE_MESSAGE(0x0048, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x10")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Magic Bean" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Find a suitable spot for a garden\n"
"and plant it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Then, wait\n"
"for something fun to happen!" BOX_BREAK ITEM_ICON("\x10") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", and then use that\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to plant it."
)

DEFINE_MESSAGE(0x0049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sorry about that...OK, well..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "LET'S BOWL" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x004A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x07")  QUICKTEXT_ENABLE "You received the " COLOR(RED) "Fairy Ocarina" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is a memento from Saria.\n"
"Set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"to start playing it!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) "\n"
"or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", and then use that\n"
COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to start playing it." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x07") "You can play different notes\n"
"with " COLOR(BLUE) "[A]" COLOR(DEFAULT) " and the four " COLOR(YELLOW) "[C] Buttons" COLOR(DEFAULT) ". \n"
"Press " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " to quit playing, or \n"
"to start your song over again."
)

DEFINE_MESSAGE(0x004B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3D")  QUICKTEXT_ENABLE "You got the " COLOR(ADJUSTABLE) "Giant's Knife" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Hold it with both hands and use \n"
COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "to attack! It's so long, you\n"
"can't use it with a " COLOR(LIGHTBLUE) "shield" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3E")  QUICKTEXT_ENABLE "You got a " COLOR(LIGHTBLUE) "Deku Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Switch to the " COLOR(BLUE) "Equipment \n"
"Subscreen" COLOR(RED) " " COLOR(DEFAULT) "and select the\n"
"shield. Press " COLOR(BLUE) "[A] " COLOR(DEFAULT) "to equip it." BOX_BREAK ITEM_ICON("\x3E") "Press " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " to crouch and\n"
"defend. If you press " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " while \n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", you can move\n"
"while defending."
)

DEFINE_MESSAGE(0x004D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x3F")  QUICKTEXT_ENABLE "You got a " COLOR(LIGHTBLUE) "Hylian Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Switch to the " COLOR(BLUE) "Equipment \n"
"Subscreen" COLOR(DEFAULT) " and select this\n"
"shield, then equip it with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x004E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x40")  QUICKTEXT_ENABLE "You found the " COLOR(LIGHTBLUE) "Mirror Shield" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"The shield's polished surface can\n"
"reflect light or energy. Press " COLOR(LIGHTBLUE) "[R]\n"
COLOR(DEFAULT) "to use it."
)

DEFINE_MESSAGE(0x004F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0B")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Longshot" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"It's an upgraded Hookshot.\n"
"It extends " COLOR(RED) "twice" COLOR(DEFAULT) " as far!"
)

DEFINE_MESSAGE(0x0050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x42")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Goron Tunic" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This heat-resistant tunic is\n"
"adult size, so it won't fit a kid...\n"
"Going to a hot place? No worry!"
)

DEFINE_MESSAGE(0x0051, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x43")  QUICKTEXT_ENABLE "You got a " COLOR(BLUE) "Zora Tunic" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This diving suit is adult size,\n"
"so it won't fit a kid. Wear it,\n"
"and you won't drown underwater."
)

DEFINE_MESSAGE(0x0052, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(ADJUSTABLE) "Magic Jar" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Your Magic Meter is filled!"
)

DEFINE_MESSAGE(0x0053, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x45")  QUICKTEXT_ENABLE "You got the " COLOR(RED) "Iron Boots" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"So heavy, you can't run.\n"
"So heavy, you can't float."
)

DEFINE_MESSAGE(0x0054, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x46")  QUICKTEXT_ENABLE "You got the " COLOR(RED) "Hover Boots" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"With these mysterious boots\n"
"you can hover above the ground.\n"
"The downside? No traction!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x46") "You can even use these to\n"
"walk for short periods where \n"
"there is no solid ground. Be brave\n"
"and trust in the boots!"
)

DEFINE_MESSAGE(0x0055, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(PURPLE) "Recovery Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Your life energy is recovered!"
)

DEFINE_MESSAGE(0x0056, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "You upgraded your quiver to a\n"
COLOR(RED) "Big Quiver" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can carry more arrows-\n"
COLOR(YELLOW) "40 " COLOR(DEFAULT) "in total!"
)

DEFINE_MESSAGE(0x0057, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4B")  QUICKTEXT_ENABLE "You upgraded your quiver to\n"
"the " COLOR(RED) "Biggest Quiver" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can carry even more \n"
"arrows, to a maximum of " COLOR(YELLOW) "50" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0058, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4D")  QUICKTEXT_ENABLE "You found a " COLOR(RED) "Bomb Bag" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This bomb-holding bag is made \n"
"from a Dodongo's stomach!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x02")  QUICKTEXT_ENABLE "You found " COLOR(RED) "20 Bombs" COLOR(DEFAULT) " inside!" QUICKTEXT_DISABLE "\n"
"Now you can set Bombs to " COLOR(YELLOW) "[C]\n"
COLOR(DEFAULT) "and blow stuff up! What a lucky \n"
"guy!"
)

DEFINE_MESSAGE(0x0059, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4E")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Big Bomb Bag" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can carry more \n"
"Bombs, up to a maximum of " COLOR(YELLOW) "30" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x005A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x4F")  QUICKTEXT_ENABLE "You got the \n"
COLOR(RED) "Biggest Bomb Bag" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now, you can carry up to \n"
COLOR(YELLOW) "40" COLOR(DEFAULT) " Bombs!"
)

DEFINE_MESSAGE(0x005B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x51")  QUICKTEXT_ENABLE "You found the " COLOR(BLUE) "Silver Gauntlets" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"If you wore them, you would\n"
"feel power in your arms, the \n"
"power to lift big things with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x51") "But, these gauntlets won't fit\n"
"a kid... Plus, you promised to give\n"
"them to " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". You should keep\n"
"your word..."
)

DEFINE_MESSAGE(0x005C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x52")  QUICKTEXT_ENABLE "You found the " COLOR(BLUE) "Golden Gauntlets" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"You can feel even more power \n"
"coursing through your arms!\n"
"Grab with " COLOR(BLUE) "[A] " COLOR(DEFAULT) "and lift stuff up!"
)

DEFINE_MESSAGE(0x005D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1C")  QUICKTEXT_ENABLE "You put a " COLOR(LIGHTBLUE) "Blue Fire" COLOR(DEFAULT) "\n"
"into the bottle!" QUICKTEXT_DISABLE "\n"
"This is a cool flame you can\n"
"use with " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down]" COLOR(DEFAULT) " or" COLOR(YELLOW) " [C-Right]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x56")  QUICKTEXT_ENABLE "You got an " COLOR(BLUE) "Adult's Wallet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Adults are allowed to carry a \n"
"lot of money. Now you can hold \n"
"up to " COLOR(YELLOW) "200" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x005F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x57")  QUICKTEXT_ENABLE "You got a " COLOR(BLUE) "Giant's Wallet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"What a huge wallet! Now \n"
"you can carry up to " COLOR(YELLOW) "500" COLOR(DEFAULT) " " COLOR(YELLOW) "Rupees" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0060, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "You found a " COLOR(RED) "Small Key" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This key will open a locked \n"
"door. You can use it only\n"
"in this dungeon."
)

DEFINE_MESSAGE(0x0061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (20 pieces)  180 Rupees\n"
COLOR(DEFAULT) "This looks like a toy mouse, but\n"
"it's actually a self-propelled time\n"
"bomb!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Red Potion   40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Red Potion   50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Red Potion   40 Rupees\n"
COLOR(DEFAULT) "If you drink this, you will\n"
"recover your life energy.\n"
"This is a single dose." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Red Potion   50 Rupees\n"
COLOR(DEFAULT) "If you drink this, you will\n"
"recover your life energy.\n"
"This is a single dose." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x76")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Dungeon Map" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Press " COLOR(RED) "START " COLOR(DEFAULT) "to get into the \n"
"Subscreens and look at the\n"
COLOR(RED) "Map Subscreen" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x76")  COLOR(BLUE) "Blue chambers" COLOR(DEFAULT) " are places \n"
"you have already visited. \n"
"Your current location is \n"
"the " COLOR(LIGHTBLUE) "flashing room" COLOR(DEFAULT) "." BOX_BREAK ITEM_ICON("\x76") "Move " COLOR(LIGHTBLUE) "[Control-Pad] up and down" COLOR(DEFAULT) " to \n"
"select a floor to view."
)

DEFINE_MESSAGE(0x0067, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x75")  QUICKTEXT_ENABLE "You found the " COLOR(RED) "Compass" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can see the locations\n"
"of many hidden things in the\n"
"dungeon!"
)

DEFINE_MESSAGE(0x0068, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6F")  QUICKTEXT_ENABLE "You obtained the " COLOR(RED) "Stone of Agony" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"If you equip a " COLOR(LIGHTBLUE) "Rumble Pak" COLOR(DEFAULT) ", it\n"
"will react to nearby...secrets."
)

DEFINE_MESSAGE(0x0069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x23")  QUICKTEXT_ENABLE "You received " COLOR(RED) "Zelda's Letter" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Wow! This letter has Princess\n"
"Zelda's autograph! Set it to " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"and show it with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x23") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"and then use that " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to show it\n"
"to people."
)

DEFINE_MESSAGE(0x006A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Welcome! May I help you?" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "I want to shop\n"
"Just looking" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Would you like to buy something\n"
"else?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x49")  QUICKTEXT_ENABLE "Your " COLOR(RED) "Deku Seeds Bullet Bag \n"
COLOR(DEFAULT) "has become bigger!" QUICKTEXT_DISABLE "\n"
"Now you can carry more bullets!\n"
"This bag can hold " COLOR(YELLOW) "50" COLOR(RED) " " COLOR(DEFAULT) "bullets!"
)

DEFINE_MESSAGE(0x006D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Open the chest and...Surprise!\n"
"If you find a Key inside, you'll \n"
"be able to advance. Left or\n"
"right--try your luck!" BOX_BREAK COLOR(RED) "10 Rupees " COLOR(DEFAULT) "to play. Do you want \n"
"to try it?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x006E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Great! You are a real gambler!"
)

DEFINE_MESSAGE(0x006F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(ADJUSTABLE) "Green Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(ADJUSTABLE) "one Rupee" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x04")  QUICKTEXT_ENABLE "You got the " COLOR(RED) "Fire Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Set it to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and your arrows will\n"
"be powered up! If you hit\n"
"your target, it will catch fire."
)

DEFINE_MESSAGE(0x0071, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0C")  QUICKTEXT_ENABLE "You got the " COLOR(BLUE) "Ice Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Set it to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and your arrows will\n"
"be powered up! If you hit your \n"
"target, it will freeze." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0C") "This arrow magic is granted\n"
"only to those who complete the \n"
"difficult training of the Gerudos,\n"
"so use it with pride!"
)

DEFINE_MESSAGE(0x0072, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x12")  QUICKTEXT_ENABLE "You got the " COLOR(LIGHTBLUE) "Light Arrow" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Set it to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and your arrows will\n"
"be powered up! The light of\n"
"justice will smite evil!"
)

DEFINE_MESSAGE(0x0073, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the\n"
SHIFT("\x2F")  COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0074, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the\n"
SHIFT("\x37")  COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0075, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the \n"
SHIFT("\x29")  COLOR(BLUE) "Serenade of Water" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0076, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the \n"
SHIFT("\x2D")  COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0077, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the \n"
SHIFT("\x28")  COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0078, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x28") "You have learned the \n"
SHIFT("\x32")  COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0079, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x50")  QUICKTEXT_ENABLE "You got the " COLOR(RED) "Goron's Bracelet" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can pull up Bomb \n"
"Flowers. Stand next to one and\n"
"use " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to pull it up!"
)

DEFINE_MESSAGE(0x007A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1D")  QUICKTEXT_ENABLE "You put a " COLOR(RED) "Bug " COLOR(DEFAULT) "in the bottle!" QUICKTEXT_DISABLE "\n"
"You can release it by pressing\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". This kind of bug prefers to\n"
"live in small holes in the ground."
)

DEFINE_MESSAGE(0x007B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x70")  QUICKTEXT_ENABLE "You obtained the " COLOR(RED) "Gerudo's \n"
"Membership Card" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"You can get into the Gerudo's\n"
"training ground in their hideout."
)

DEFINE_MESSAGE(0x007C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombs  10 pieces  50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Arrows  50 pieces  90 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Fish   200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x007F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deku Nuts   5 Pieces   15 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0080, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6C")  QUICKTEXT_ENABLE "You got the " COLOR(ADJUSTABLE) "Kokiri's Emerald" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is the Spiritual Stone of \n"
"the Forest, now entrusted to \n"
"you by the Great Deku Tree."
)

DEFINE_MESSAGE(0x0081, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6D")  QUICKTEXT_ENABLE "You obtained the " COLOR(RED) "Goron's Ruby" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is the Spiritual Stone of \n"
"Fire passed down by the Gorons!"
)

DEFINE_MESSAGE(0x0082, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x6E")  QUICKTEXT_ENABLE "You obtained " COLOR(BLUE) "Zora's Sapphire" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is the Spiritual Stone of\n"
"Water passed down by the\n"
"Zoras!"
)

DEFINE_MESSAGE(0x0083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Shop around by moving the \n"
COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "left or right.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Talk to the owner\n"
"Quit" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Thanks a lot!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You don't have enough Rupees!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You can't get this now." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deku Nuts   10 pieces  30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deku Stick  1 piece   10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0089, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deku Shield   40 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Arrow   10 pieces   20 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bomb   5 pieces   25 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombchu  10 pieces   100 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"You can't use a Big Poe here!\n"
"Sell it to the man at the Hyrule\n"
"Castle Town gate!"
)

DEFINE_MESSAGE(0x008E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Red Potion   30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x008F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Green Potion   30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0090, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "Now you can pick up \n"
"many " COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"You can carry up to " COLOR(YELLOW) "20" COLOR(DEFAULT) " of them!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0091, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x00")  QUICKTEXT_ENABLE "You can now pick up \n"
"even more " COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"You can carry up to " COLOR(YELLOW) "30" COLOR(DEFAULT) " of them!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Hylian Shield   80 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Goron Tunic   200 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Zora Tunic   300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Recovery Heart   10 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "I'm sorry...I can't sell this to\n"
"you unless you have a bottle to \n"
"put it in." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x0097, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x20")  QUICKTEXT_ENABLE "You caught a " COLOR(RED) "Poe " COLOR(DEFAULT) "in a bottle!" QUICKTEXT_DISABLE "\n"
"Something good might happen!"
)

DEFINE_MESSAGE(0x0098, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1A")  QUICKTEXT_ENABLE "You got " COLOR(RED) "Lon Lon Milk" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This milk is very nutritious!\n"
"Use it with " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to recover your \n"
"life energy!" BOX_BREAK ITEM_ICON("\x1A") "You will recover " COLOR(RED) "five hearts" COLOR(DEFAULT) "\n"
"per drink. There are two\n"
"drinks per bottle." BOX_BREAK ITEM_ICON("\x1A") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"and then use that " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to take \n"
"a drink."
)

DEFINE_MESSAGE(0x0099, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x1B")  QUICKTEXT_ENABLE "You got an " COLOR(RED) "Empty Bottle" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Put something inside and \n"
"press " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to use it... What?\n"
"Something's already inside!?"
)

DEFINE_MESSAGE(0x009A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x21")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Weird Egg" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Feels like there's something\n"
"moving inside! Set it to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and \n"
"see what happens!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x21") "On the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) ",\n"
"you can set it to " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ",\n"
"and then press " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "to use it."
)

DEFINE_MESSAGE(0x009B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Arrows   30 pieces   60 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x009C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"My current hot seller is the \n"
COLOR(LIGHTBLUE) "Hylian Shield" COLOR(DEFAULT) ", but it might be too \n"
"big for you, kid." EVENT
)

DEFINE_MESSAGE(0x009D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"We moved here from the castle \n"
"town. I know times are tough, but\n"
"I hope you will be a steady \n"
"customer for us!" EVENT
)

DEFINE_MESSAGE(0x009E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x47") "Welcome!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x009F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Deku Shield   40 Rupees\n"
COLOR(DEFAULT) "Once equipped, you can defend \n"
"with " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) ". If set on fire, it will\n"
"burn!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Arrow   (10 pieces)   20 Rupees\n"
COLOR(DEFAULT) "You need a bow to shoot them.\n"
"You can't buy them unless you\n"
"have a bow." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Deku Stick  (1 piece)  10 Rupees\n"
COLOR(DEFAULT) "A long branch gathered from the\n"
"Great Deku Tree. You can use it\n"
"as a weapon, but it will break." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Deku Nuts  (10 pieces) 30 Rupees\n"
COLOR(DEFAULT) "Throw them to stun your enemies.\n"
"You can buy only the amount you\n"
"can actually carry." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombs   (5 pieces)   25 Rupees\n"
COLOR(DEFAULT) "Take it out with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " to throw it. You can buy them\n"
"only if you have a bomb bag." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x3B")  QUICKTEXT_ENABLE "You got the " COLOR(ADJUSTABLE) "Kokiri Sword" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"On the " COLOR(BLUE) "Equipment Subscreen" COLOR(DEFAULT) ",\n"
"select it with the cursor and\n"
"equip it with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x3B") "This is a hidden treasure of\n"
"the Kokiri, but you can borrow it\n"
"for a while. Be sure to practice \n"
"with it before you really fight!"
)

DEFINE_MESSAGE(0x00A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Red Potion   30 Rupees\n"
COLOR(DEFAULT) "Drink to recover your life energy.\n"
"This is just a single dose." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Green Potion   30 Rupees\n"
COLOR(DEFAULT) "Drink to recover your magic power.\n"
"This is just a single dose." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00A7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "Now you can carry\n"
"many " COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "!\n"
"You can hold up to " COLOR(YELLOW) "30" COLOR(DEFAULT) " nuts!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00A8, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x01")  QUICKTEXT_ENABLE "You can now carry even\n"
"more " COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "! You can carry\n"
"up to " COLOR(YELLOW) "40" COLOR(RED) " " COLOR(DEFAULT) "nuts!" QUICKTEXT_DISABLE " "
)

DEFINE_MESSAGE(0x00A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Hylian Shield   80 Rupees\n"
COLOR(DEFAULT) "This is a big, heavy shield just \n"
"like the ones Hylian Knights use.\n"
"It can stand up to flame attacks!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Goron Tunic   200 Rupees\n"
COLOR(DEFAULT) "A tunic made by Gorons. Adult\n"
"size. Protects you from heat\n"
"damage." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Zora Tunic   300 Rupees\n"
COLOR(DEFAULT) "A tunic made by Zoras. Adult size.\n"
"Prevents you from drowning\n"
"underwater." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Recovery Heart   10 Rupees\n"
COLOR(DEFAULT) "This will instantly refill one\n"
"Heart Container." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00AD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x05")  QUICKTEXT_ENABLE "You got " COLOR(RED) "Din's Fire" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Its fireball engulfs everything!\n"
"It's attack magic you can use\n"
"with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x0D")  QUICKTEXT_ENABLE "You got " COLOR(ADJUSTABLE) "Farore's Wind" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"This is warp magic you can use \n"
"with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) ". Warp when you are in \n"
"danger!" BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "You will teleport to the " COLOR(ADJUSTABLE) "Warp\n"
"Point" COLOR(DEFAULT) ". When you first use the\n"
"magic, you will create a Warp\n"
"Point." BOX_BREAK UNSKIPPABLE  ITEM_ICON("\x0D") "When you use the magic \n"
"again, you can either dispel\n"
"the Warp Point you created last\n"
"time or warp to that point."
)

DEFINE_MESSAGE(0x00AF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x13")  QUICKTEXT_ENABLE "You got " COLOR(BLUE) "Nayru's Love" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Cast this to create a powerful\n"
"protective barrier. It's defensive \n"
"magic you can use with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Arrows  (50 pieces)  90 Rupees\n"
COLOR(DEFAULT) "Shoot these with a bow. You can't\n"
"buy them unless you have a bow." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombs  (10 pieces)  50 Rupees\n"
COLOR(DEFAULT) "Take it out with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " again to throw it. You can't\n"
"buy them without a bomb bag." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Deku Nuts  (5 pieces)  15 Rupees\n"
COLOR(DEFAULT) "Throw them to stun your enemies.\n"
"You can carry only a limited \n"
"amount of them." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Fish   200 Rupees\n"
COLOR(DEFAULT) "Just caught and so fresh!\n"
"You can keep it in a bottle." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"You destroyed a " COLOR(RED) "Gold Skulltula" COLOR(DEFAULT) ".\n"
"You got a token proving you \n"
"destroyed it!"
)

DEFINE_MESSAGE(0x00B5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"You destroyed a " COLOR(RED) "Gold Skulltula" COLOR(DEFAULT) ".\n"
"You got a token proving you \n"
"destroyed it!"
)

DEFINE_MESSAGE(0x00B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Fairy's Spirit    50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Fairy's Spirit   50 Rupees\n"
COLOR(DEFAULT) "You need an empty bottle to put\n"
"it in. Don't go into battle \n"
"without it!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Blue Fire    300 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Blue Fire   300 Rupees\n"
COLOR(DEFAULT) "You need an empty bottle to put\n"
"this in. Use it to feel \n"
"refreshing coolness." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bottle Bug   50 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bottle Bug    50 Rupees\n"
COLOR(DEFAULT) "You need an empty bottle to put\n"
"it in. It looks like just an\n"
"ordinary bug..." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombchu  (10 pieces)  100 Rupees\n"
COLOR(DEFAULT) "This looks like a toy mouse, but\n"
"it's actually a self-propelled time\n"
"bomb!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "We're temporarily out of\n"
"stock on that item." COLOR(DEFAULT)  QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"C'mon, man! You're too old for \n"
"this game!" EVENT
)

DEFINE_MESSAGE(0x00BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x40") "Huh? Wha--!" BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x50") "Uh-oh!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x3E") "A customer!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x00C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x39") "zzzzz...zzzzz..." EVENT
)

DEFINE_MESSAGE(0x00C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Arrows   (30 pieces)   60 Rupees\n"
COLOR(DEFAULT) "You need a bow to shoot them.\n"
"Use them, and you'll run out." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00C2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Collect four pieces total to get\n"
"another Heart Container. More\n"
"containers mean more life energy!"
)

DEFINE_MESSAGE(0x00C3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"So far, you've collected two \n"
"pieces. With two more pieces, \n"
"you will gain more life energy!"
)

DEFINE_MESSAGE(0x00C4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you've collected three \n"
"pieces! With another piece, your \n"
"life energy will be powered up!"
)

DEFINE_MESSAGE(0x00C5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"You've completed another Heart\n"
"Container! Your maximum life\n"
"energy is increased!"
)

DEFINE_MESSAGE(0x00C6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x72")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Heart Container" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Your maximum life energy is \n"
"increased by one heart. Your life\n"
"energy will be totally filled."
)

DEFINE_MESSAGE(0x00C7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x74")  QUICKTEXT_ENABLE "You got the " COLOR(RED) "Boss Key" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Now you can get inside the \n"
"chamber where the Boss lurks."
)

DEFINE_MESSAGE(0x00C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Nope, you don't have enough\n"
"Rupees!" EVENT
)

DEFINE_MESSAGE(0x00C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "All right, you're done!" QUICKTEXT_DISABLE "\n"
"Please wait outside while I set \n"
"up your next challenge!" EVENT
)

DEFINE_MESSAGE(0x00CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Bombs   5 pieces   35 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bombs   (5 pieces)   35 Rupees\n"
COLOR(DEFAULT) "Take it out with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and press \n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " again to throw it. You can't\n"
"buy them without a bomb bag." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00CC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(BLUE) "Blue Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(BLUE) "five Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00CD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x53")  QUICKTEXT_ENABLE "You got the " COLOR(BLUE) "Silver Scale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jump into the water and press \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". You can dive deeper than you\n"
"could before."
)

DEFINE_MESSAGE(0x00CE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  ITEM_ICON("\x54")  QUICKTEXT_ENABLE "You got the " COLOR(BLUE) "Golden Scale" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Jump into the water and press \n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Now you can dive much\n"
"deeper than you could before!"
)

DEFINE_MESSAGE(0x00CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "It looks like this item doesn't \n"
"work here..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "It won't open!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00D1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x14") "You've learned " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x11") "You've learned " COLOR(RED) "Epona's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x0B") "You've learned the " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x15") "You've learned " COLOR(BLUE) "Zelda's Lullaby" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x05") "You've learned the " COLOR(LIGHTBLUE) "Song of Time" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You've learned the " COLOR(PURPLE) "Song of Storms" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Welcome " NAME "!\n"
"I am the Great Fairy of Power!" BOX_BREAK UNSKIPPABLE "I'm going to grant you a " COLOR(ADJUSTABLE) "sword\n"
"technique" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receive it now!"
)

DEFINE_MESSAGE(0x00D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Welcome " NAME "!\n"
"I am the Great Fairy of Wisdom!" BOX_BREAK UNSKIPPABLE "I'm going to enhance your " COLOR(ADJUSTABLE) "magic \n"
"power" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receive it now!"
)

DEFINE_MESSAGE(0x00D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Welcome " NAME "!\n"
"I am the Great Fairy of Courage!" BOX_BREAK UNSKIPPABLE "I'm going to enhance your \n"
COLOR(LIGHTBLUE) "defensive power" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Receive it now!"
)

DEFINE_MESSAGE(0x00DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"When you are weary of battle,\n"
"please come back to visit me!" EVENT
)

DEFINE_MESSAGE(0x00DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Welcome " NAME "!\n"
"I will soothe your wounds." EVENT
)

DEFINE_MESSAGE(0x00DC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x58")  QUICKTEXT_ENABLE "You got " COLOR(RED) "Deku Seeds" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"These are small, hard seeds\n"
"that you can use as bullets\n"
"for your Slingshot."
)

DEFINE_MESSAGE(0x00DD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  UNSKIPPABLE "You mastered the secret sword\n"
"technique of the " COLOR(RED) "Spin Attack" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Hold " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " to charge your weapon!\n"
"Release " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " to unleash a wave\n"
"of energy with your spin!" BOX_BREAK UNSKIPPABLE "If you want to release energy\n"
"without charging your weapon, just \n"
COLOR(LIGHTBLUE) "rotate [Control-Pad] once " COLOR(DEFAULT) "and press " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "for" COLOR(ADJUSTABLE) "\n"
COLOR(DEFAULT) "a very effective quick spin!"
)

DEFINE_MESSAGE(0x00DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Deku Seeds 30 pieces 30 Rupees" QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Deku Seed (30 pieces) 30 Rupees\n"
COLOR(DEFAULT) "You can use them as bullets for\n"
"your Slingshot. You can't buy \n"
"them unless you have a Slingshot." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "You want to talk to Saria, right?\n"
COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Talk to Saria\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Really? Then do you want to talk \n"
"to me?\n"
COLOR(DEFAULT)  TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x3C")  NAME "...?\n"
SHIFT("\x0D") "This is " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ". Can you hear me?" EVENT
)

DEFINE_MESSAGE(0x00E3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Do you want to talk to Saria\n"
"again?" COLOR(DEFAULT) "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x00E4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Your " COLOR(ADJUSTABLE) "Magic Meter" COLOR(DEFAULT) " is enhanced!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Your " COLOR(LIGHTBLUE) "defensive power" COLOR(DEFAULT) " is enhanced!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "You got a " COLOR(YELLOW) "bundle of arrows" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "When you charge power for a Spin\n"
"Attack, magic power will be\n"
"consumed. Pay attention to your\n"
"green " COLOR(ADJUSTABLE) "Magic Meter" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Hey, boy! You're a messenger of\n"
"the Royal Family, aren't you?" BOX_BREAK UNSKIPPABLE "Next time you're in their\n"
"neighborhood, you should drop in\n"
"on a friend of mine who lives by\n"
"Hyrule Castle." BOX_BREAK UNSKIPPABLE "She'll surely grant you another\n"
"new power!"
)

DEFINE_MESSAGE(0x00E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Your magic power has been \n"
"enhanced! Now you have twice\n"
"as much " COLOR(RED) "Magic Power" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x00E9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Your defensive power has been \n"
"enhanced! Damage inflicted by \n"
"enemies will be " COLOR(RED) "reduced by half" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x00EA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Welcome " NAME "!\n"
"I am the Great Fairy of Magic!" BOX_BREAK UNSKIPPABLE "I will give you a " COLOR(RED) "magic spell" COLOR(DEFAULT) ".\n"
"Please take it."
)

DEFINE_MESSAGE(0x00EB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "I'm sorry, but you can't borrow\n"
"this mask yet." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x00EC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You can use " COLOR(RED) "Din's Fire" COLOR(DEFAULT) " not only to\n"
"attack but also to burn things!"
)

DEFINE_MESSAGE(0x00ED, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Remember, you can use " COLOR(ADJUSTABLE) "Farore's\n"
"Wind" COLOR(DEFAULT) " only in dungeons that have\n"
"a dungeon map hidden inside, OK?"
)

DEFINE_MESSAGE(0x00EE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(BLUE) "Nayru's Love" COLOR(LIGHTBLUE) " " COLOR(DEFAULT) "is in effect for only\n"
"a limited time, so use it carefully."
)

DEFINE_MESSAGE(0x00EF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"When battle has made you weary,\n"
"please come back to see me."
)

DEFINE_MESSAGE(0x00F0, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(RED) "Red Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(RED) "twenty Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(PURPLE) "Purple Rupee" COLOR(DEFAULT) "!\n"
"That's " COLOR(PURPLE) "fifty Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F2, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "You got a " COLOR(YELLOW) "Huge Rupee" COLOR(DEFAULT) "!\n"
"This Rupee is worth a whopping\n"
COLOR(YELLOW) "two hundred Rupees" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F3, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x77")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Door Key" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Use this key to continue to the\n"
"next room. Select a treasure \n"
"chest and see how lucky you are!"
)

DEFINE_MESSAGE(0x00F4, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Loser!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "You found only " COLOR(ADJUSTABLE) "one Rupee" COLOR(DEFAULT) ".\n"
"You are not very lucky." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F5, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Loser!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "You found " COLOR(BLUE) "five Rupees" COLOR(DEFAULT) ".\n"
"Even so, you are not very lucky." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F6, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Loser!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "You found " COLOR(RED) "twenty Rupees" COLOR(DEFAULT) ".\n"
"Your last selection was a mistake,\n"
"wasn't it! How frustrating!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F7, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
COLOR(RED) "Winner!" COLOR(DEFAULT)  BOX_BREAK QUICKTEXT_ENABLE "You found " COLOR(YELLOW) "fifty Rupees" COLOR(DEFAULT) ".\n"
"You are a genuinely lucky guy!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x00F8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"00f8"
)

DEFINE_MESSAGE(0x00F9, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
ITEM_ICON("\x1E")  QUICKTEXT_ENABLE "You put a " COLOR(RED) "Big Poe " COLOR(DEFAULT) "in a bottle!" QUICKTEXT_DISABLE "\n"
"Let's sell it at the " COLOR(RED) "Ghost Shop" COLOR(DEFAULT) "!\n"
"Something good might happen!"
)

DEFINE_MESSAGE(0x00FA, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x49")  COLOR(RED) "WINNER" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"Collect four pieces total to get\n"
"another Heart Container. More\n"
"containers mean more life energy!"
)

DEFINE_MESSAGE(0x00FB, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x49")  COLOR(RED) "WINNER" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"So far, you've collected two \n"
"pieces. With two more pieces, \n"
"you will gain more life energy!"
)

DEFINE_MESSAGE(0x00FC, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x49")  COLOR(RED) "WINNER" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"You've collected three pieces!\n"
"With another piece, your life \n"
"energy will be powered up!"
)

DEFINE_MESSAGE(0x00FD, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
SHIFT("\x49")  COLOR(RED) "WINNER" COLOR(DEFAULT) "!" BOX_BREAK ITEM_ICON("\x73")  QUICKTEXT_ENABLE "You got a " COLOR(RED) "Piece of Heart" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"You've completed another Heart\n"
"Container! Your maximum life\n"
"energy is increased!"
)

DEFINE_MESSAGE(0x00FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Look for them not only out in the\n"
"open, but also inside the dungeons." BOX_BREAK "Of course, this is just our dream...\n"
"You don't have to do it if you\n"
"don't want to..." TEXTID("\x00\x27")
)

DEFINE_MESSAGE(0x0100, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "What's that?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0101, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Look, look, " NAME "!\n"
"You can see down below this " COLOR(DEFAULT) "web" COLOR(LIGHTBLUE) "\n"
"using " COLOR(YELLOW) "[C-Up]" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0102, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Look at this wall! The vines\n"
"growing on it give it a rough\n"
"surface... Maybe you can climb \n"
"it, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0103, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "You can open a " COLOR(DEFAULT) "door" COLOR(LIGHTBLUE) " by standing\n"
"in front of it and pressing " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Pay attention to what the\n"
COLOR(BLUE) "Action" COLOR(LIGHTBLUE) " " COLOR(BLUE) "Icon" COLOR(LIGHTBLUE) " says.\n"
"That's the " COLOR(BLUE) "blue icon" COLOR(LIGHTBLUE) " at the top of\n"
"the screen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0104, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Look! Something is hanging up\n"
"there! It looks like an old " COLOR(DEFAULT) "ladder" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0105, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Hey...\n"
"Isn't that the same design that's\n"
"on the " COLOR(DEFAULT) "Door of Time" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0106, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "It looks like that torch was\n"
"burning not too long ago..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0107, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "From here on, we'll be going\n"
"through some narrow passages!\n"
"If you take it slow, maybe you\n"
"can sneak up on some enemies." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "to always look\n"
"in the proper direction. Set your\n"
"view so you can see down the next\n"
"corridor before you turn a corner." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Once your view is set, hold down\n"
COLOR(DEFAULT) "[Z] " COLOR(LIGHTBLUE) "to " COLOR(DEFAULT) "sidestep " COLOR(LIGHTBLUE) "around the corner.\n"
"That way you won't be surprised\n"
"by an enemy waiting in ambush." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0108, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Stand next to this " COLOR(DEFAULT) "block" COLOR(LIGHTBLUE) " and grab\n"
"hold of it with " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ". While holding\n"
COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) ", you can push or pull it." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "If you stand next to the " COLOR(DEFAULT) "block" COLOR(LIGHTBLUE) "\n"
"and press " COLOR(BLUE) "[A]" COLOR(LIGHTBLUE) " while pressing " COLOR(DEFAULT) "[Control-Pad]" COLOR(LIGHTBLUE) "\n"
"towards the " COLOR(DEFAULT) "block" COLOR(LIGHTBLUE) ", you can climb\n"
"on top of it." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Pay attention to what the " COLOR(BLUE) "Action\n"
"Icon " COLOR(LIGHTBLUE) "says!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "After you get into the water, if\n"
"you hold down" COLOR(BLUE) " [A]" COLOR(LIGHTBLUE) ", you can dive!\n"
"I bet there are some interesting\n"
"things underwater!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Wow! Look at all those \n"
COLOR(DEFAULT) "Bomb Flowers" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Is there any way you can set\n"
"them all off at once?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0115, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "It looks like there are many " COLOR(DEFAULT) "lava\n"
"pits " COLOR(LIGHTBLUE) "around here, so watch your\n"
"step!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0116, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "With that switch on, the moving\n"
COLOR(DEFAULT) "platform " COLOR(LIGHTBLUE) "goes higher. Now you can\n"
"quickly reach the second floor!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0117, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0117"
)

DEFINE_MESSAGE(0x0118, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0118"
)

DEFINE_MESSAGE(0x0119, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "You never know what will be \n"
"around the corner in these narrow\n"
"paths...." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Use " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "to always look\n"
"in the proper direction. This is a\n"
"useful technique, isn't it?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", what are you \n"
"looking at?" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "The Desert Colossus's face...it \n"
"sure looks evil!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0125, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0125"
)

DEFINE_MESSAGE(0x0126, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "I can hear the spirits whispering \n"
"in this room..." BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE "\"Look for the eye of truth...\"\n"
COLOR(LIGHTBLUE) "That's what they are saying!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0127, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0127"
)

DEFINE_MESSAGE(0x0128, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Here...I can hear the spirits\n"
"whispering in this room..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "\"Those who have " COLOR(RED) "sacred feet " COLOR(DEFAULT) "\n"
"should let the wind guide them.\n"
"Then, they will be led to the \n"
"hidden path.\"" BOX_BREAK COLOR(LIGHTBLUE) "That's what they are saying!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0129, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This wall...it says something here...\n"
COLOR(DEFAULT) "\"Danger above...\"" COLOR(LIGHTBLUE) "\n"
"That's what it says." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This wall...it says something here...\n"
COLOR(DEFAULT) "\"Danger below...\"\n"
COLOR(LIGHTBLUE) "That's what it says." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x012B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "The water flowing out of this \n"
"statue is flooding the entire floor." COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "Watch out, " NAME "!\n"
"Electricity is running through\n"
"this " COLOR(ADJUSTABLE) "green slimy thing" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0130, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0130"
)

DEFINE_MESSAGE(0x0131, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Watch out " NAME "!\n"
"Electricity is running through\n"
"this " COLOR(RED) "red slimy thing" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0132, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Watch out " NAME "!\n"
"Electricity is running through\n"
"this " COLOR(BLUE) "blue slimy thing" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0133, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "switch" COLOR(LIGHTBLUE) "...\n"
"It doesn't look like you can press\n"
"it down with your weight alone,\n"
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
UNSKIPPABLE  COLOR(LIGHTBLUE) "The " COLOR(RED) "red slimy thing " COLOR(LIGHTBLUE) "is gone! \n"
"That must be because you cut the\n"
COLOR(RED) "red tail" COLOR(LIGHTBLUE) "! Will that work with \n"
"the other ones too?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0138, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0138"
)

DEFINE_MESSAGE(0x0139, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "There's a switch beyond this \n"
"wall!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "It looks like there is something\n"
"up there on top of the platform!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013b"
)

DEFINE_MESSAGE(0x013C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013c"
)

DEFINE_MESSAGE(0x013D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x42")  COLOR(LIGHTBLUE) "WHAAAT!?" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "Look at all those " COLOR(DEFAULT) "flags" COLOR(LIGHTBLUE) "!\n"
"Can you figure out which ones are\n"
"real?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x013E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013e"
)

DEFINE_MESSAGE(0x013F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"013f"
)

DEFINE_MESSAGE(0x0140, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "The " COLOR(DEFAULT) "Great Deku Tree" COLOR(RED) " " COLOR(LIGHTBLUE) "has \n"
"summoned you!\n"
"Please come with me!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0141, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "C'mon! Be brave!\n"
"Let's go into the \n"
"Great Deku Tree!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0142, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "The Great Deku Tree wanted us\n"
"to go to visit the princess at\n"
COLOR(DEFAULT) "Hyrule Castle" COLOR(LIGHTBLUE) ".... Shouldn't we\n"
"get going?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0143, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "The girl from the ranch asked us\n"
"to find her " COLOR(DEFAULT) "father" COLOR(LIGHTBLUE) "...I wonder where\n"
"he is?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0144, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "I wonder where we'll find the \n"
COLOR(DEFAULT) "princess " COLOR(LIGHTBLUE) "in this big old castle?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0145, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "What would " COLOR(DEFAULT) "Saria" COLOR(RED) " " COLOR(LIGHTBLUE) "say if we told\n"
"her we're going to save Hyrule?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0146, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Impa " COLOR(LIGHTBLUE) "said that the Spiritual Stone\n"
"of Fire is somewhere on " COLOR(DEFAULT) "Death\n"
"Mountain" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0147, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Let's go inside the Dodongo's\n"
"Cavern using a " COLOR(DEFAULT) "Bomb Flower" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0148, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Darunia said that a " COLOR(DEFAULT) "fairy\n"
COLOR(LIGHTBLUE) "lives on top of Death Mountain,\n"
"didn't he?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0149, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "I wonder if " COLOR(DEFAULT) "Saria " COLOR(LIGHTBLUE) "knows anything\n"
"about the other Spiritual Stone?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "It seems " COLOR(DEFAULT) "Princess Ruto " COLOR(LIGHTBLUE) "somehow " COLOR(DEFAULT) "\n"
COLOR(LIGHTBLUE) "got inside Jabu-Jabu's belly..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "You collected three Spiritual\n"
"Stones! Let's go back to " COLOR(DEFAULT) "Hyrule\n"
"Castle" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Those people on the white horse...\n"
"they were Zelda and Impa, weren't\n"
"they? It looked like they threw \n"
"something into the " COLOR(DEFAULT) "moat" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Let's go check inside the \n"
COLOR(DEFAULT) "Temple of Time" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Should we believe what Sheik said \n"
"and go to " COLOR(DEFAULT) "Kakariko Village" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x014F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"014f"
)

DEFINE_MESSAGE(0x0150, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "I wonder what's going on in the\n"
"forest right now... I'm worried\n"
"about " COLOR(DEFAULT) "Saria" COLOR(LIGHTBLUE) ", too!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0151, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "That cloud over " COLOR(DEFAULT) "Death Mountain" COLOR(LIGHTBLUE) "...\n"
"there is something strange about \n"
"it..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0152, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "An arctic wind is blowing from\n"
COLOR(DEFAULT) "Zora's River" COLOR(LIGHTBLUE) "...do you feel it?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0153, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Those " COLOR(DEFAULT) "Iron Boots " COLOR(LIGHTBLUE) "look like\n"
"they weigh a ton! If you wear\n"
"those boots, you may be able to\n"
"walk at the bottom of a lake." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0154, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Let's look for someone who might\n"
"know something about the other\n"
COLOR(DEFAULT) "Sages" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0155, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "That monster! It came out of the \n"
COLOR(DEFAULT) "well in the village" COLOR(LIGHTBLUE) "! Let's go \n"
"check out the well!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0156, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "I wonder who built the " COLOR(DEFAULT) "Spirit" COLOR(LIGHTBLUE) "\n"
COLOR(DEFAULT) "Temple" COLOR(LIGHTBLUE) ", and for what purpose?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0157, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Have you ever played the \n"
COLOR(PURPLE) "Nocturne of Shadow" COLOR(LIGHTBLUE) " that Sheik\n"
"taught you?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0158, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "The " COLOR(DEFAULT) "desert" COLOR(LIGHTBLUE) "...that is where\n"
"Ganondorf the Evil King was born.\n"
"If we go there, we might find\n"
"something..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0159, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0159"
)

DEFINE_MESSAGE(0x015A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Equip the " COLOR(DEFAULT) "Silver Gauntlets \n"
COLOR(LIGHTBLUE) "and try to move things you \n"
"couldn't budge before!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "The one who is waiting for us at\n"
"the Temple of Time...it could be..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "We have to save Princess Zelda\n"
"from her imprisonment in Ganon's\n"
"Castle!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x015D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"015D"
)

DEFINE_MESSAGE(0x015E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"015E"
)

DEFINE_MESSAGE(0x015F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE)  NAME "...\n"
"Try to keep moving!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0160, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"I don't mind talking to you \n"
"using the Ocarina's magic, but\n"
"I'd really like to talk to you\n"
"face-to-face!" EVENT
)

DEFINE_MESSAGE(0x0161, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"The forest is connected to many \n"
"places! If you can hear my song,\n"
"you must be somewhere that is\n"
"connected to the forest!" EVENT
)

DEFINE_MESSAGE(0x0162, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"I was so happy to hear that\n"
"Mr. Darunia loved my song so\n"
"much!" BOX_BREAK "I was even happier to find out\n"
"that it helped you on your quest,\n"
NAME "!\n"
"Tee hee hee!" EVENT
)

DEFINE_MESSAGE(0x0163, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Are you collecting Spiritual\n"
"Stones? You have one more to\n"
"find? You mean the " COLOR(BLUE) "Spiritual \n"
"Stone of Water" COLOR(DEFAULT) ", don't you?" BOX_BREAK "The Great Deku Tree once told me\n"
"that " COLOR(BLUE) "King Zora, ruler of Zora's \n"
"Domain, " COLOR(DEFAULT) "has it..." EVENT
)

DEFINE_MESSAGE(0x0164, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Are you collecting Spiritual\n"
"Stones? You have one more to\n"
"find? You mean the " COLOR(RED) "Spiritual \n"
"Stone of Fire" COLOR(DEFAULT) ", don't you?" BOX_BREAK "The Great Deku Tree once told me\n"
"that " COLOR(RED) "Mr. Darunia of the Gorons\n"
COLOR(DEFAULT) "has it..." EVENT
)

DEFINE_MESSAGE(0x0165, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME "...\n"
"I don't know what it is...\n"
"I have this feeling of dread..." BOX_BREAK "The Castle...\n"
"Yes, something bad is happening\n"
"at the Castle!" EVENT
)

DEFINE_MESSAGE(0x0166, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"What? Your ocarina sounds...\n"
"different somehow... \n"
"Have you been practicing a lot,\n"
NAME "?" EVENT
)

DEFINE_MESSAGE(0x0167, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Are you looking for a temple?\n"
"A mysterious bird once told me..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Eyes that can see through \n"
"darkness will open in a storm." COLOR(DEFAULT) "\"\n"
"Do you have any idea what he \n"
"meant by this?" EVENT
)

DEFINE_MESSAGE(0x0168, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Where are you, " NAME "?\n"
"Are you looking for a temple?\n"
"I once heard a mysterious bird \n"
"say..." BOX_BREAK "\"" COLOR(LIGHTBLUE) "Go, young man. Go to the\n"
"Desert Goddess with an ocarina." COLOR(DEFAULT) "\"\n"
"Do you have any idea what he\n"
"may have meant by this?" EVENT
)

DEFINE_MESSAGE(0x0169, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Did you find all the temples yet?" EVENT
)

DEFINE_MESSAGE(0x016A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"Great! You're safe!\n"
"I knew I would hear from\n"
"you again!" BOX_BREAK "I'm in the " COLOR(ADJUSTABLE) "Forest Temple" COLOR(DEFAULT) "!\n"
"The forest spirits were calling\n"
"for help, so I went to check it\n"
"out..." BOX_BREAK "But it's full of evil monsters!\n"
"Help me, " NAME "!" EVENT
)

DEFINE_MESSAGE(0x016B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME "...\n"
"At first, I didn't want to become \n"
"the " COLOR(ADJUSTABLE) "Sage of the Forest" COLOR(DEFAULT) "...." BOX_BREAK "But I'm glad now." BOX_BREAK "Because I am helping you to save\n"
"Hyrule, " NAME "!\n"
"Yes, I am!" EVENT
)

DEFINE_MESSAGE(0x016C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"If all six " COLOR(RED) "Sages" COLOR(DEFAULT) " come together, \n"
"we can imprison Ganondorf, the \n"
"King of Evil, in the Sacred Realm." BOX_BREAK "But, in order to make a perfect\n"
"seal, we need the " COLOR(RED) "seventh \n"
"Sage" COLOR(DEFAULT) "." BOX_BREAK "Someone you know must be that\n"
"Sage, " NAME "..." BOX_BREAK "From now on, you must travel \n"
"between past and future to\n"
"awaken the remaining Sages!" BOX_BREAK "Keep up the good work,\n"
NAME "!" EVENT
)

DEFINE_MESSAGE(0x016D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"We, the Six Sages, are channeling\n"
"our power to you!" BOX_BREAK "The destiny of Hyrule depends \n"
"upon you!" EVENT
)

DEFINE_MESSAGE(0x016E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016e"
)

DEFINE_MESSAGE(0x016F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"016f"
)

DEFINE_MESSAGE(0x0180, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "I can hear a voice from\n"
"somewhere..." COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "It's saying:\n"
COLOR(DEFAULT)  SHIFT("\x11") "\"Collect five silver Rupees...\""
)

DEFINE_MESSAGE(0x0181, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This wall...it's saying something!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "It says:\n"
COLOR(DEFAULT) "If you want to see a ferry to the\n"
SHIFT("\x1E") "other world, come here..."
)

DEFINE_MESSAGE(0x0182, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0182"
)

DEFINE_MESSAGE(0x0183, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "If you want to ride that " COLOR(DEFAULT) "boat" COLOR(LIGHTBLUE) ", be \n"
"careful! It looks very old... Who\n"
"knows when it might sink?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0184, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "There is a " COLOR(DEFAULT) "door " COLOR(LIGHTBLUE) "over here... Is \n"
"there any way to get across?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0185, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0185"
)

DEFINE_MESSAGE(0x0186, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "That " COLOR(DEFAULT) "red ice" COLOR(LIGHTBLUE) "...it's so weird!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0187, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0187"
)

DEFINE_MESSAGE(0x0188, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0188"
)

DEFINE_MESSAGE(0x0189, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "blue fire" COLOR(LIGHTBLUE) "...it doesn't seem\n"
"natural. Maybe you can use it for\n"
"something?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018a"
)

DEFINE_MESSAGE(0x018B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018b"
)

DEFINE_MESSAGE(0x018C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "The " COLOR(DEFAULT) "fires on the torches " COLOR(LIGHTBLUE) "are gone.\n"
"Seems like the ghosts took them \n"
"away!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Look, " NAME "! A " COLOR(DEFAULT) "torch" COLOR(LIGHTBLUE) "\n"
"is lit! That's because\n"
"you beat a ghost, isn't it?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x018E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"018e"
)

DEFINE_MESSAGE(0x018F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "There are " COLOR(DEFAULT) "arrows " COLOR(LIGHTBLUE) "painted on the \n"
"floor!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0190, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "corridor " COLOR(LIGHTBLUE) "is all twisted!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0191, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Watch for the " COLOR(DEFAULT) "shadows of\n"
"monsters " COLOR(LIGHTBLUE) "that hang from the\n"
"ceiling." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0192, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "There's a " COLOR(DEFAULT) "treasure chest" COLOR(LIGHTBLUE) " here." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0193, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0193"
)

DEFINE_MESSAGE(0x0194, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This...this is the same " COLOR(DEFAULT) "torch" COLOR(LIGHTBLUE) " we\n"
"saw at the entrance to the temple,\n"
"isn't it?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0195, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "torch" COLOR(LIGHTBLUE) " is lit...that means..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0196, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"0196"
)

DEFINE_MESSAGE(0x0197, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "switch" COLOR(LIGHTBLUE) " is frozen!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0198, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", watch out!\n"
"The ceiling is falling down!" COLOR(DEFAULT)
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
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME ", I hear " COLOR(DEFAULT) "Goron \n"
"voices " COLOR(LIGHTBLUE) "down below." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a4"
)

DEFINE_MESSAGE(0x01A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "You can see down from here...\n"
"Isn't that the room where we saw\n"
COLOR(DEFAULT) "Darunia" COLOR(LIGHTBLUE) "?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a6"
)

DEFINE_MESSAGE(0x01A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "statue" COLOR(LIGHTBLUE) "...haven't we seen it\n"
"somewhere before?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01a8"
)

DEFINE_MESSAGE(0x01A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "This " COLOR(DEFAULT) "switch " COLOR(LIGHTBLUE) "looks rusted." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x01AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"01aa"
)

DEFINE_MESSAGE(0x01AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "! Be careful!\n"
"Don't get swallowed by the \n"
"vortexes!" COLOR(DEFAULT)
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
SHIFT("\x0F") "Hi! I'm a talking door!"
)

DEFINE_MESSAGE(0x0201, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x06")  COLOR(LIGHTBLUE) "Strange...this door doesn't open..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0202, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x04")  COLOR(LIGHTBLUE) "Strong " COLOR(DEFAULT) "iron bars " COLOR(LIGHTBLUE) "are blocking the\n"
COLOR(DEFAULT)  SHIFT("\x0B")  COLOR(LIGHTBLUE) "door. You can't open them with\n"
COLOR(DEFAULT)  SHIFT("\x40")  COLOR(LIGHTBLUE) "your hands!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0203, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x09")  COLOR(LIGHTBLUE) "You need a " COLOR(DEFAULT) "Key" COLOR(LIGHTBLUE) " to open a door\n"
COLOR(DEFAULT)  SHIFT("\x14")  COLOR(LIGHTBLUE) "that is locked and chained." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0204, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x21")  COLOR(LIGHTBLUE) "You need a " COLOR(DEFAULT) "special key\n"
SHIFT("\x28")  COLOR(LIGHTBLUE) "to open this door." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0205, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Be quiet!" QUICKTEXT_DISABLE  BOX_BREAK "It's only " TIME "!\n"
"I, " COLOR(RED) "Dampé " COLOR(DEFAULT) "the gravekeeper, am\n"
"in bed now!" BOX_BREAK "Go away and play! Maybe you can\n"
"find a ghost in the daytime?"
)

DEFINE_MESSAGE(0x0206, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"It's " TIME " now.\n"
"The " COLOR(RED) "Gravedigging Tour" COLOR(DEFAULT) " is over \n"
"now!" BOX_BREAK "I, " COLOR(RED) "Dampé" COLOR(DEFAULT) " the gravekeeper, am\n"
"in bed!" BOX_BREAK "Go away and play! Maybe you'll\n"
"find a ghost!"
)

DEFINE_MESSAGE(0x0207, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Happy Mask Shop\n"
COLOR(DEFAULT) "Please read this sign before you\n"
"use this shop." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "How This Shop Works\n"
COLOR(DEFAULT) "We do not sell masks at this shop.\n"
"We just " COLOR(RED) "lend" COLOR(DEFAULT) " them to you." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "You sell the loaned masks on your\n"
"own." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "You pay back the " COLOR(RED) "money" COLOR(DEFAULT) " for the\n"
"mask, and we will lend you a \n"
"newer model." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "You can borrow masks you have\n"
"already sold again; however, you \n"
"can sell each model of mask only\n"
"once." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Please try our shop!\n"
SHIFT("\x14") "--Happy Mask Shop Owner" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0208, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Shadow Temple...\n"
"Here is gathered Hyrule's bloody \n"
"history of greed and hatred..." EVENT
)

DEFINE_MESSAGE(0x0209, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"What is hidden in the darkness...\n"
"Tricks full of ill will...\n"
"You can't see the way forward..." EVENT
)

DEFINE_MESSAGE(0x020A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"One who gains the " COLOR(RED) "eye of truth\n"
COLOR(DEFAULT) "will be able to see what is hidden\n"
"in the darkness." EVENT
)

DEFINE_MESSAGE(0x020B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "Something strange is covering the\n"
"entrance. You must solve the\n"
COLOR(DEFAULT) "puzzle" COLOR(LIGHTBLUE) " in this room to make the\n"
"entrance open." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x020C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Giant dead Dodongo...\n"
"when it sees red,\n"
"a new way to go \n"
"will be open." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x020D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
SHIFT("\x1E")  COLOR(LIGHTBLUE) "Treasure Chest Contest\n"
COLOR(DEFAULT)  SHIFT("\x2D") "Temporarily Closed\n"
SHIFT("\x38") "Open Tonight!"
)

DEFINE_MESSAGE(0x020E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Medicine Shop\n"
COLOR(DEFAULT) "Closed until morning"
)

DEFINE_MESSAGE(0x020F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Shooting Gallery\n"
COLOR(DEFAULT) "Open only during the day"
)

DEFINE_MESSAGE(0x0210, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Happy Mask Shop\n"
COLOR(DEFAULT) "Now hiring part-time\n"
"Apply during the day"
)

DEFINE_MESSAGE(0x0211, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Bazaar\n"
COLOR(DEFAULT) "Open only during the day"
)

DEFINE_MESSAGE(0x0212, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Show me the light!"
)

DEFINE_MESSAGE(0x0213, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "One with the " COLOR(RED) "eye of truth " COLOR(DEFAULT) "shall\n"
"be guided to the Spirit Temple by\n"
"an inviting ghost." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0214, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Those who wish to open the path\n"
"sleeping at the bottom of the lake\n"
"must play the " COLOR(RED) "song passed down\n"
"by the Royal Family" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0215, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Those who wish to open the gate\n"
"on the far heights, play the " COLOR(RED) "song\n"
"passed down by the Royal Family" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0216, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Those who find a " COLOR(RED) "Small Key" COLOR(DEFAULT) " can\n"
"advance to the next room. Those\n"
"who don't can go home!"
)

DEFINE_MESSAGE(0x0217, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you wish to speak to me,\n"
"do so from the platform." EVENT
)

DEFINE_MESSAGE(0x0218, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x6D")  QUICKTEXT_ENABLE "Hi, " NAME "!" QUICKTEXT_DISABLE "\n"
"Look this way!" BOX_BREAK "Look over here with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) ", and talk \n"
"to me with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0219, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The current time is: " COLOR(RED)  TIME  COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Shine light on the living dead..."
)

DEFINE_MESSAGE(0x021B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Those who break into the Royal \n"
"Tomb will be obstructed by the\n"
COLOR(RED) "lurkers in the dark" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x021C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Hey, you! Young man, over there!\n"
"Look over here, inside the cell!" EVENT
)

DEFINE_MESSAGE(0x021D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"My little boy isn't here right \n"
"now...\n"
"I think he went to play in the \n"
"graveyard..."
)

DEFINE_MESSAGE(0x021E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, my boy is asleep right now.\n"
"Please come back some other time\n"
"to play with him!"
)

DEFINE_MESSAGE(0x021F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "When water fills the lake, \n"
"shoot for the morning light." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0220, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "If you want to travel to the \n"
"future, you should return here \n"
"with the " COLOR(BLUE) "power of silver " COLOR(DEFAULT) "from the \n"
"past." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0221, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "If you want to proceed to the \n"
"past, you should return here\n"
"with the pure heart of a child." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0222, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "This door is currently being\n"
"refurbished." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0223, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "It looks like something used to\n"
"be set in this stand..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0224, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "Make my beak face the\n"
SHIFT("\x3A")  COLOR(RED) "skull of truth" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0C") "The alternative is descent into\n"
SHIFT("\x2D") "the deep darkness." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x0225, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "This is not the correct " COLOR(DEFAULT) "key" COLOR(LIGHTBLUE) "...\n"
"The door won't open!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0226, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27")  COLOR(LIGHTBLUE) "Granny's Potion Shop\n"
COLOR(DEFAULT)  SHIFT("\x4F") "Closed" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x28") "Gone for Field Study\n"
SHIFT("\x28") "Please come again!\n"
SHIFT("\x4A") "--Granny" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0227, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Who's there? What a bad kid,\n"
"trying to enter from the rear\n"
"door!" QUICKTEXT_DISABLE  BOX_BREAK TEXT_SPEED("\x02") "Such a bad kid..." TEXT_SPEED("\x00") "\n"
"I have to tell you some juicy\n"
"gossip!" BOX_BREAK "The boss carpenter has a son...\n"
"He's the guy who sits under the\n"
"tree every night..." BOX_BREAK "Don't tell the boss I told you \n"
"that!"
)

DEFINE_MESSAGE(0x0228, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(LIGHTBLUE) "Look at this!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0229, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Malon's gone to sleep!\n"
"I'm goin' to sleep now, too.\n"
"Come back again when it's\n"
"light out!"
)

DEFINE_MESSAGE(0x022A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(RED)  NAME "'s Records!\n"
COLOR(DEFAULT) "Spiders squished: " TOKENS "\n"
"Largest fish caught: " HIGHSCORE(HS_LARGEST_FISH) " pounds" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Marathon time: " HIGHSCORE(HS_MARATHON) "\n"
"Horse race time: " HIGHSCORE(HS_HORSE_RACE) "\n"
"Horseback archery: " HIGHSCORE(HS_HORSE_ARCHERY) " points" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "The crest of the Royal Family of\n"
SHIFT("\x1E") "Hyrule is inscribed here." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x54") "R.I.P.\n"
SHIFT("\x08") "Here lie the souls of those who\n"
SHIFT("\x2A") "swore fealty to the\n"
SHIFT("\x23") "Royal Family of Hyrule" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0F") "The Sheikah, guardians of the\n"
SHIFT("\x11") "Royal Family and founders of\n"
SHIFT("\x02") "Kakariko, watch over these spirits\n"
SHIFT("\x1E") "in their eternal slumber." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(BLUE) "Sleepless Waterfall\n"
COLOR(DEFAULT)  SHIFT("\x05") "The flow of this waterfall serves\n"
SHIFT("\x02") "the King of Hyrule. When the King\n"
SHIFT("\x09") "slumbers, so too do these falls." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x022E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"Some frogs are looking at you\n"
"from underwater..."
)

DEFINE_MESSAGE(0x022F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You're standing on a soft carpet\n"
"for guests...\n"
"It feels so plush under your feet!"
)

DEFINE_MESSAGE(0x0230, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"If you can overcome the " COLOR(RED) "trials " COLOR(DEFAULT) "in\n"
"the chambers ahead, then and only\n"
"then will you be qualified to hold\n"
"our secret treasure!"
)

DEFINE_MESSAGE(0x0231, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"If you desire to acquire our\n"
"hidden treasure, you must strive\n"
"to obtain the " COLOR(RED) "keys " COLOR(DEFAULT) "hidden in each\n"
"chamber!"
)

DEFINE_MESSAGE(0x0232, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Defeat all the enemies in a " COLOR(RED) "limited\n"
"time" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0233, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Collect the " COLOR(RED) "underwater gems" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0234, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Cross the sea of fire!"
)

DEFINE_MESSAGE(0x0235, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Find a secret passage in this\n"
"room!"
)

DEFINE_MESSAGE(0x0236, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Blind the " COLOR(RED) "eyes of the statue" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0237, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"One with " COLOR(RED) "silver hands" COLOR(DEFAULT) " shall move\n"
"a giant block!"
)

DEFINE_MESSAGE(0x0238, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Without the necessary items, one\n"
"will be confounded by impossible\n"
"mysteries."
)

DEFINE_MESSAGE(0x0239, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"Gather the " COLOR(RED) "jewels of white" COLOR(DEFAULT) ", while\n"
"avoiding traps and danger!"
)

DEFINE_MESSAGE(0x023A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F")  COLOR(LIGHTBLUE) "Fishing Pond" COLOR(DEFAULT) "\n"
SHIFT("\x07") "The fish are really biting today!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x023B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4E")  COLOR(LIGHTBLUE) "....???" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x023C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "The Shadow will yield only to one\n"
SHIFT("\x0E") "with the " COLOR(RED) "eye of truth" COLOR(DEFAULT) ", handed\n"
SHIFT("\x1C") "down in Kakariko Village." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0300, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x01", "\x10")
)

DEFINE_MESSAGE(0x0301, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Hyrule Field" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0302, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2C")  COLOR(LIGHTBLUE) "Hyrule Castle Town" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0303, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(LIGHTBLUE) "The Temple of Time" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0304, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x47")  COLOR(RED) "Dead End" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0305, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(PURPLE) "Kakariko Village\n"
COLOR(DEFAULT)  SHIFT("\x28") "Death Mountain Trail\n"
SHIFT("\x3C") "Starting Point" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0306, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17")  COLOR(PURPLE) "Kakariko Village Graveyard" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0307, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Dark! Narrow! Scary!\n"
COLOR(PURPLE)  SHIFT("\x1E") "Well of Three Features" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0308, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(RED) "Death Mountain\n"
COLOR(DEFAULT)  SHIFT("\x25") "No passage without a\n"
SHIFT("\x3A") "Royal Decree!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0309, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(RED) "Death Mountain Trail" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36")  COLOR(YELLOW) "Dodongo's Cavern\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Don't enter without permission!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Land of the Gorons\n"
SHIFT("\x41")  COLOR(RED) "Goron City" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x48")  COLOR(BLUE) "Zora's River\n"
COLOR(DEFAULT)  SHIFT("\x0F") "Watch out for swift current \n"
SHIFT("\x23") "and strong undertow." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "The Shadow will yield only to one\n"
SHIFT("\x0E") "with the eye of truth, handed\n"
SHIFT("\x1C") "down in Kakariko Village." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Zora's Domain" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x030F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(BLUE) "Zora's Fountain\n"
COLOR(DEFAULT)  SHIFT("\x08") "Don't disturb Lord Jabu-Jabu! \n"
SHIFT("\x32") "--King Zora XVI" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0310, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(PURPLE) "Forest Training Center\n"
COLOR(DEFAULT)  SHIFT("\x15") "Don't recklessly cut signs--\n"
SHIFT("\x28") "read them carefully!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0311, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "All those reckless enough to\n"
SHIFT("\x0B") "venture into the desert--please\n"
SHIFT("\x2F") "drop by our shop." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(YELLOW) "Carpet Merchant" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0312, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41") "Just ahead:\n"
SHIFT("\x17")  COLOR(ADJUSTABLE) "Great Deku Tree's Meadow" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0313, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x39")  COLOR(ADJUSTABLE) "Forest Temple" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0314, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x35")  COLOR(ADJUSTABLE) "The Lost Woods" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0315, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E") "Talon and Malon's\n"
SHIFT("\x3C")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0316, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "The Great Ingo's\n"
SHIFT("\x46")  COLOR(YELLOW) "Ingo Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0317, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(BLUE) "Lake Hylia" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0318, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  COLOR(BLUE) "Lakeside Laboratory\n"
COLOR(DEFAULT)  SHIFT("\x04") "Daily trying to get to the bottom\n"
SHIFT("\x09") "of the mysteries of Lake Hylia!\n"
SHIFT("\x36") "--Lake Scientist" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0319, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37")  COLOR(YELLOW) "Gerudo Valley" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19")  COLOR(YELLOW) "Horseback Archery Range" COLOR(DEFAULT) "\n"
SHIFT("\x12") "Skilled players are welcome!\n"
SHIFT("\x12") "Current record: " COLOR(RED)  HIGHSCORE(HS_HORSE_ARCHERY)  COLOR(DEFAULT) " Points" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x21")  COLOR(YELLOW) "Gerudo Training Ground\n"
COLOR(DEFAULT)  SHIFT("\x11") "Only registered members are\n"
SHIFT("\x4B") "allowed!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2D")  COLOR(YELLOW) "Haunted Wasteland" COLOR(DEFAULT) "\n"
SHIFT("\x17") "If you chase a mirage, the\n"
SHIFT("\x1F") "desert will swallow you.\n"
SHIFT("\x21") "Only one path is true!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(YELLOW) "Spirit Temple" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42")  COLOR(ADJUSTABLE) "Kokiri Shop\n"
COLOR(DEFAULT)  SHIFT("\x0B") "We have original forest goods!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x031F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "'s House" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0320, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(ADJUSTABLE) "Forest folk shall not\n"
COLOR(DEFAULT)  SHIFT("\x2D")  COLOR(ADJUSTABLE) "leave these woods." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0321, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Follow the trail along the edge of\n"
SHIFT("\x15") "the cliff and you will reach\n"
SHIFT("\x06")  COLOR(RED) "Goron City" COLOR(DEFAULT) ", home of the Gorons." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0322, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x36") "Natural Wonder\n"
SHIFT("\x3F")  COLOR(RED) "Bomb Flower" COLOR(DEFAULT) "\n"
SHIFT("\x1E") "Danger! Do not uproot!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0323, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x26")  COLOR(RED) "Death Mountain Summit\n"
COLOR(DEFAULT)  SHIFT("\x10") "Entrance to the crater ahead\n"
SHIFT("\x1E") "Beware of intense heat!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0324, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1D")  COLOR(BLUE) "King Zora's Throne Room\n"
COLOR(DEFAULT)  SHIFT("\x1E") "To hear the King's royal\n"
SHIFT("\x15") "proclamations, stand on the\n"
SHIFT("\x17") "platform and speak to him." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0325, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "If you can stop my wild rolling,\n"
SHIFT("\x0B") "you might get something great.\n"
SHIFT("\x29") "--" COLOR(RED) "Hot Rodder Goron" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0326, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Only one with the eye of truth\n"
SHIFT("\x15") "will find the stone umbrella\n"
SHIFT("\x1A") "that protects against the\n"
SHIFT("\x39") "rain of blades." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0327, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0A") "Only one who has " COLOR(RED) "sacred feet" COLOR(DEFAULT) "\n"
SHIFT("\x04") "can cross the valley of the dead." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0328, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "The record time of those\n"
"who raced against me was:\n"
COLOR(LIGHTBLUE)  HIGHSCORE(HS_DAMPE_RACE)  COLOR(DEFAULT) "\n"
"--Dampé the Gravekeeper" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0329, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Shooting Gallery  \n"
"20 Rupees for one play\n"
COLOR(DEFAULT) "There are " COLOR(RED) "10 targets" COLOR(DEFAULT) ". You have " COLOR(RED) "15\n"
"chances" COLOR(DEFAULT) ". Hit all 10 targets!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Hit 10 targets -- Perfect Prize\n"
"Hit 8 or more -- Free Retry\n"
"Hit less than 8 -- Game Over" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Rules at this Shooting Gallery\n"
COLOR(DEFAULT) "Don't lean on the counter.\n"
"Don't disturb other customers." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28")  COLOR(LIGHTBLUE) "Treasure Chest Shop" COLOR(DEFAULT) "\n"
SHIFT("\x06") "We don't necessarily sell them..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F")  COLOR(LIGHTBLUE) "High Dive Practice Spot\n"
COLOR(DEFAULT)  SHIFT("\x2F") "Are you confident\n"
SHIFT("\x2A") "in your diving skill?" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
"032c"
)

DEFINE_MESSAGE(0x032D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x33")  COLOR(RED) "Mountain Summit" COLOR(DEFAULT) "\n"
SHIFT("\x19") "Danger Ahead - Keep Out" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Happy Mask Shop!" COLOR(DEFAULT) "\n"
SHIFT("\x28") "Now hiring happiness\n"
SHIFT("\x3C") "delivery men!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x032F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Bombchu Bowling Alley" COLOR(DEFAULT) "\n"
SHIFT("\x20") "You can experience the\n"
SHIFT("\x17") "latest in Bomb technology!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0330, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x50")  COLOR(LIGHTBLUE) "Bazaar" COLOR(DEFAULT) "\n"
SHIFT("\x0A") "We have a little of everything!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0331, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(LIGHTBLUE) "Potion Shop\n"
COLOR(DEFAULT)  SHIFT("\x1B") "We have the best quality\n"
SHIFT("\x4A") "potions!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0332, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x41")  COLOR(RED) "Goron Shop\n"
COLOR(DEFAULT)  SHIFT("\x1E") "Mountaineering Supplies!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0333, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x45")  COLOR(BLUE) "Zora Shop" COLOR(DEFAULT) "\n"
SHIFT("\x28") "We have fresh fish!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0334, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Heart-Pounding Gravedigging Tour!\n"
COLOR(DEFAULT)  SHIFT("\x08") "From 18:00 to 21:00 Hyrule Time\n"
SHIFT("\x1C") "--Dampé the Gravekeeper" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0335, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03")  COLOR(LIGHTBLUE) "Heart-Pounding Gravedigging Tour!\n"
COLOR(DEFAULT)  SHIFT("\x0A") "Tours are " COLOR(RED) "cancelled" COLOR(DEFAULT) " until a new\n"
SHIFT("\x1B") "gravekeeper is found. We\n"
SHIFT("\x09") "apologize for any inconvenience." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0336, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Thrust Attack Signs!\n"
COLOR(DEFAULT) "To thrust with your sword, press\n"
COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " toward your target while \n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", then press " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0337, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Hole of \"Z\"\n"
COLOR(DEFAULT) "Let's go through this small\n"
"hole!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Stand in front of the hole and\n"
"push " COLOR(LIGHTBLUE) "[Control-Pad] " COLOR(DEFAULT) "towards it. When the \n"
COLOR(BLUE) "Action Icon " COLOR(DEFAULT) "shows \"Enter,\" press\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "to crawl into the hole." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Pay attention to what the " COLOR(BLUE) "Action\n"
"Icon " COLOR(DEFAULT) "says!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0338, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Cut Grass With Your Sword\n"
COLOR(DEFAULT) "If you just swing with " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ", you'll \n"
"cut horizontally. If you hold " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " as" COLOR(LIGHTBLUE) " \n"
COLOR(DEFAULT) "you swing, you'll cut vertically." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0339, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C")  COLOR(LIGHTBLUE) "Hyrule Castle" COLOR(DEFAULT) "\n"
SHIFT("\x37")  COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033A, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "You are here: " COLOR(LIGHTBLUE) "Hyrule Castle" COLOR(DEFAULT) "\n"
SHIFT("\x16") "This way to " COLOR(YELLOW) "Lon Lon Ranch" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033B, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x42") "Just Ahead\n"
SHIFT("\x29")  COLOR(BLUE) "King Zora's Chamber\n"
COLOR(DEFAULT)  SHIFT("\x19") "Show the proper respect!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033C, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "House of the Great " COLOR(RED) "Mido" COLOR(DEFAULT) "\n"
SHIFT("\x2D") "Boss of the Kokiri" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "House of the Know-it-All Brothers" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033E, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x37") "House of Twins" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x033F, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(RED) "Saria" COLOR(DEFAULT) "'s House" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0340, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "View Point with [Z] Targeting\n"
COLOR(DEFAULT) "When you have no object to look\n"
"at, you can just look forward\n"
"with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "Stop moving and then change the\n"
"direction you are facing, or " COLOR(LIGHTBLUE) "hold\n"
"down [Z] " COLOR(DEFAULT) "for a little while." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "This can help you get oriented in\n"
"the direction you want to face.\n"
"It's quite convenient!" QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "If " COLOR(LIGHTBLUE) "you hold down [Z]" COLOR(DEFAULT) ", you can\n"
COLOR(RED) "walk sideways" COLOR(DEFAULT) " while facing \n"
"straight ahead." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  COLOR(RED) "Walking sideways" COLOR(DEFAULT) " can be a very\n"
"important technique in dungeon\n"
"corridors. Turn around and try\n"
"doing this right now." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0341, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "Stepping Stones in the Pond\n"
COLOR(DEFAULT) "If you boldly go in the direction\n"
"you want to jump, you will leap\n"
"automatically." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "If you hop around on the stones,\n"
"you'll become happier!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0342, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x2F")  COLOR(RED) "No Diving Allowed\n"
COLOR(DEFAULT)  SHIFT("\x15") "--It won't do you any good!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0343, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Switch Targeting\n"
COLOR(DEFAULT) "If you see a " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " icon above an \n"
"object, you can target it with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "In other words, if you press " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " \n"
"when you see " COLOR(ADJUSTABLE) "▼" COLOR(YELLOW) " " COLOR(DEFAULT) "above an object,\n"
"you can lock on to it." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "If you press " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " again, the lock\n"
"will either " COLOR(RED) "release" COLOR(DEFAULT) " or it will\n"
"transfer to the next object with\n"
"the " COLOR(ADJUSTABLE) "▼" COLOR(DEFAULT) " above it." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "When you have many enemies in\n"
"your field of view and you want\n"
"to escape, press " COLOR(LIGHTBLUE) "[Z] " COLOR(DEFAULT) "while holding\n"
"back on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " to cancel targeting." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "You can target the " COLOR(RED) "stones" COLOR(DEFAULT) " next to\n"
"this sign for practice!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0344, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3D")  COLOR(ADJUSTABLE) "Forest Stage" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x14") "We are waiting to see your\n"
SHIFT("\x38") "beautiful face!\n"
SHIFT("\x28") "Win fabulous prizes!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0345, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x48") "Visit the\n"
SHIFT("\x04")  COLOR(RED) "House of the Know-it-All Brothers\n"
COLOR(DEFAULT)  SHIFT("\x17") "to get answers to all your\n"
SHIFT("\x22") "item-related questions!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0400, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"This is a " COLOR(RED) "Gossip Stone" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x0401, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that you can swim faster\n"
"by continuously pressing " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x0402, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a secret \n"
"near the lone tree which is not\n"
"far from the river in the \n"
"northwest part of Hyrule Field."
)

DEFINE_MESSAGE(0x0403, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a secret\n"
"on the road that leads to Lake\n"
"Hylia."
)

DEFINE_MESSAGE(0x0404, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Biggoron's Sword is \n"
"super sharp and will never break."
)

DEFINE_MESSAGE(0x0405, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Medigoron didn't \n"
"really think about his own size, \n"
"so his store is really cramped."
)

DEFINE_MESSAGE(0x0406, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Malon set the\n"
"original record in the obstacle\n"
"course of Lon Lon Ranch."
)

DEFINE_MESSAGE(0x0407, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Malon of Lon Lon \n"
"Ranch hopes a knight in shining \n"
"armor will come and sweep her off \n"
"her feet someday."
)

DEFINE_MESSAGE(0x0408, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Ruto, the Zora \n"
"Princess who is known for her \n"
"selfish nature, likes a certain \n"
"boy..."
)

DEFINE_MESSAGE(0x0409, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that players who select\n"
"the \"HOLD\" option for \"Z \n"
"TARGETING\" are the real \"Zelda\n"
"players!\""
)

DEFINE_MESSAGE(0x040A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a secret\n"
"near a tree in Kakariko Village."
)

DEFINE_MESSAGE(0x040B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that, contrary to her \n"
"elegant image, Princess Zelda of \n"
"Hyrule Castle is, in fact, a \n"
"tomboy!"
)

DEFINE_MESSAGE(0x040C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Princess Zelda's \n"
"nanny is actually one of the \n"
"Sheikah, who many thought had \n"
"died out."
)

DEFINE_MESSAGE(0x040D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a man who\n"
"can always be found running\n"
"around in Hyrule Field."
)

DEFINE_MESSAGE(0x040E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that it is against the\n"
"rules to use glasses at the \n"
"Treasure Chest Shop in Hyrule\n"
"Castle Town Market."
)

DEFINE_MESSAGE(0x040F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the Chicken Lady \n"
"goes to the Lakeside Laboratory \n"
"to study how to breed pocket-\n"
"sized Cuccos."
)

DEFINE_MESSAGE(0x0410, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Gerudos sometimes\n"
"come to Hyrule Castle Town to\n"
"look for boyfriends."
)

DEFINE_MESSAGE(0x0411, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the thief named \n"
"Nabooru, who haunts this area, is\n"
"a Gerudo."
)

DEFINE_MESSAGE(0x0412, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that if you get close to a\n"
"butterfly while holding a Deku\n"
"Stick in your hands, something\n"
"good will happen."
)

DEFINE_MESSAGE(0x0413, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that you may find\n"
"something new in dungeons that\n"
"you have already finished."
)

DEFINE_MESSAGE(0x0414, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Gerudos worship \n"
"Ganondorf almost like a god."
)

DEFINE_MESSAGE(0x0415, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a secret \n"
"around the entrance to Gerudo \n"
"Valley."
)

DEFINE_MESSAGE(0x0416, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the owl named\n"
"Kaepora Gaebora is the\n"
"reincarnation of an ancient Sage."
)

DEFINE_MESSAGE(0x0417, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that strange owl,\n"
"Kaepora Gaebora, may look big and\n"
"heavy, but its character is rather \n"
"lighthearted."
)

DEFINE_MESSAGE(0x0418, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the horse\n"
"Ganondorf rides is a solid black\n"
"Gerudo stallion."
)

DEFINE_MESSAGE(0x0419, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that Ganondorf is not \n"
"satisfied with ruling only the\n"
"Gerudo and aims to conquer all\n"
"of Hyrule!"
)

DEFINE_MESSAGE(0x041A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the treasure you\n"
"can earn in the Gerudo's Training\n"
"Ground is not as great as you\n"
"would expect, given its difficulty!"
)

DEFINE_MESSAGE(0x041B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that there is a switch \n"
"that you can activate only by\n"
"using the Spin Attack."
)

DEFINE_MESSAGE(0x041C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that it's possible to find\n"
"a total of 100 Gold Skulltulas\n"
"throughout Hyrule."
)

DEFINE_MESSAGE(0x041D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that when non-fairy\n"
"folk enter the Lost Woods, they\n"
"become monsters!"
)

DEFINE_MESSAGE(0x041E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the small holes in\n"
"the ground that you can find all\n"
"over Hyrule make perfect breeding\n"
"ground for bugs."
)

DEFINE_MESSAGE(0x041F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that the Kokiri are \n"
"always followed by small fairies."
)

DEFINE_MESSAGE(0x0420, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"They say that one Kokiri has left\n"
"the forest, but he is still\n"
"alive!"
)

DEFINE_MESSAGE(0x0421, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"0421"
)

DEFINE_MESSAGE(0x0600, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(RED) "What's that?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0601, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma\n"
COLOR(LIGHTBLUE) "It's one of the parasitic monsters\n"
"inside the Deku Tree! Its " COLOR(DEFAULT) "eye" COLOR(LIGHTBLUE) " is\n"
"vulnerable when it's red!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0602, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma Egg\n"
COLOR(LIGHTBLUE) "When this egg hatches, a Gohma\n"
"Larva will be born." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0603, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gohma Larva\n"
COLOR(LIGHTBLUE) "Look out when it gets ready to\n"
"pounce!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0604, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skulltula\n"
COLOR(LIGHTBLUE) "Its soft " COLOR(DEFAULT) "belly" COLOR(LIGHTBLUE) " is its weak point!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0605, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Big Skulltula\n"
COLOR(LIGHTBLUE) "Its soft " COLOR(DEFAULT) "belly" COLOR(LIGHTBLUE) " is its weak point!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0606, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Tailpasaran\n"
COLOR(LIGHTBLUE) "Its " COLOR(DEFAULT) "tail " COLOR(LIGHTBLUE) "is its weak point!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0607, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Hit it when it lunges at you, and \n"
"it will stand upright. Cut it\n"
"quickly to get a " COLOR(DEFAULT) "Deku Stick" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0608, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Big Deku Baba\n"
COLOR(LIGHTBLUE) "Hit it when it lunges at you, and \n"
"it will stand upright. Cut it\n"
"quickly to get a " COLOR(DEFAULT) "Deku Stick" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0609, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Baba\n"
COLOR(LIGHTBLUE) "Though it looks withered, it will\n"
"hurt you if you touch it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Deku Scrub\n"
COLOR(LIGHTBLUE) "It will hide in the grass if you get\n"
"close to it. Bounce the nuts it \n"
"spits back at it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"060b"
)

DEFINE_MESSAGE(0x060C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "King Dodongo\n"
COLOR(LIGHTBLUE) "This is a huge Dodongo that eats\n"
"anything! Give it a shock, and \n"
"finish it off with your " COLOR(DEFAULT) "sword" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dodongo\n"
COLOR(LIGHTBLUE) "Watch out for its fiery breath!\n"
"Use " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "techniques!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Baby Dodongo\n"
COLOR(LIGHTBLUE) "Watch out for its leaping attack!\n"
"It will explode after it's defeated!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x060F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Lizalfos \n"
COLOR(LIGHTBLUE) "Use your shield well and fight \n"
"with " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "techniques!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0610, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dinolfos \n"
COLOR(LIGHTBLUE) "Use your shield well and fight \n"
"with " COLOR(DEFAULT) "[Z] Targeting " COLOR(LIGHTBLUE) "techniques!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0611, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Fire Keese\n"
COLOR(LIGHTBLUE) "Destroy it before it flies into\n"
"you! If you don't, its flames will\n"
"burn up your " COLOR(DEFAULT) "Deku Shield" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0612, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keese\n"
COLOR(LIGHTBLUE) "When you get close to it, use \n"
COLOR(DEFAULT) "[Z] Targeting" COLOR(LIGHTBLUE) ". Even if it flies\n"
"away, you can still target it." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0613, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Armos\n"
COLOR(LIGHTBLUE) "Stop its movement and then\n"
"destroy it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0614, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Barinade\n"
COLOR(LIGHTBLUE) "Many parasitic jellyfish swarm\n"
"around this monster. Aim for its\n"
"body, protected by jellyfish!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0615, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Parasitic Tentacle?\n"
COLOR(LIGHTBLUE) "It seems that the narrow part is \n"
"its weak point... You need a \n"
"particular item to destroy it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0616, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shabom\n"
COLOR(LIGHTBLUE) "If you try to cut it, it will bounce\n"
"off your blade!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0617, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Biri\n"
COLOR(LIGHTBLUE) "If you touch it, you will be\n"
"electrocuted!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0618, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bari\n"
COLOR(LIGHTBLUE) "If you touch it, you will be \n"
"electrocuted!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0619, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stinger\n"
COLOR(LIGHTBLUE) "Destroy it before it flies into you!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Phantom Ganon\n"
COLOR(LIGHTBLUE) "It's an evil ghost of the Forest\n"
"Temple! He comes out of one of\n"
"the pictures." BOX_BREAK COLOR(LIGHTBLUE) "Answer his magic attack with an\n"
"attack of your own!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalfos\n"
COLOR(LIGHTBLUE) "Lure it close to you and watch its\n"
"movement carefully! Attack it when \n"
"it drops its guard!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Blue Bubble\n"
COLOR(LIGHTBLUE) "Guard against its blue flame with \n"
"your " COLOR(DEFAULT) "shield" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "White Bubble\n"
COLOR(LIGHTBLUE) "Aim for it when it stops!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Green Bubble\n"
COLOR(LIGHTBLUE) "Use your sword when its green\n"
"fire vanishes!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x061F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skullwalltula\n"
COLOR(LIGHTBLUE) "Be careful not to touch it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0620, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gold Skulltula\n"
COLOR(LIGHTBLUE) "This is also known as a Spider of\n"
"the Curse. If you defeat it, you'll\n"
"get a " COLOR(DEFAULT) "token" COLOR(LIGHTBLUE) " as proof!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0621, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Volvagia\n"
COLOR(LIGHTBLUE) "It's the Boss of the Fire Temple,\n"
"revived by the Evil King. I don't\n"
"know its weak point..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0622, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Flare Dancer\n"
COLOR(LIGHTBLUE) "Extinguish its " COLOR(DEFAULT) "flaming clothes \n"
COLOR(LIGHTBLUE) "first..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0623, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Torch Slug\n"
COLOR(LIGHTBLUE) "When the fire on its back is\n"
"extinguished, it will run away.\n"
"Destroy it before it relights!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0624, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Red Bubble\n"
COLOR(LIGHTBLUE) "Guard against its attack with \n"
"your " COLOR(DEFAULT) "shield" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0625, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Morpha\n"
COLOR(LIGHTBLUE) "Master of the Water Temple. It \n"
"has absolute control of water. Pull\n"
"out its " COLOR(DEFAULT) "nucleus " COLOR(LIGHTBLUE) "and attack it!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0626, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dark " NAME "\n"
COLOR(LIGHTBLUE) "Conquer yourself!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0627, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Shell Blade\n"
COLOR(LIGHTBLUE) "Its " COLOR(DEFAULT) "internal muscle " COLOR(LIGHTBLUE) "is its" COLOR(DEFAULT) " \n"
COLOR(LIGHTBLUE) "weak point!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0628, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Spike\n"
COLOR(LIGHTBLUE) "Aim for it when it retracts its\n"
"spikes!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0629, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bongo Bongo\n"
COLOR(LIGHTBLUE) "Boss of the Shadow Temple, \n"
"revived from the well. Look at it\n"
"with the " COLOR(DEFAULT) "eye of truth" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "ReDead\n"
COLOR(LIGHTBLUE) "Its gaze will paralyze you. If it\n"
"bites you, " COLOR(DEFAULT) "tap any button" COLOR(LIGHTBLUE) " to \n"
"escape!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Phantom Ganon\n"
COLOR(LIGHTBLUE) "Attack him" COLOR(RED) " " COLOR(DEFAULT) "when he comes out of\n"
"one of the pictures" COLOR(LIGHTBLUE) "!\n"
"Watch out for the fake one!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"062c"
)

DEFINE_MESSAGE(0x062D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gibdo\n"
COLOR(LIGHTBLUE) "Its gaze will paralyze you. If it\n"
"bites you, " COLOR(DEFAULT) "tap any button" COLOR(LIGHTBLUE) " to\n"
"escape!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dead Hand's Hands\n"
COLOR(LIGHTBLUE) "If it grabs you, " COLOR(DEFAULT) "tap any button \n"
COLOR(LIGHTBLUE) "to escape!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x062F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dead Hand\n"
COLOR(LIGHTBLUE) "Watch out for its infinite hands!\n"
"Aim for its head!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0630, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wallmaster\n"
COLOR(LIGHTBLUE) "Watch out for its " COLOR(DEFAULT) "shadow" COLOR(LIGHTBLUE) " on the\n"
"floor. Destroy it before it goes\n"
"back up to the ceiling!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0631, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Floormaster\n"
COLOR(LIGHTBLUE) "When it splits up, destroy all the\n"
"pieces before they reunite!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0632, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Koume\n"
COLOR(LIGHTBLUE) "Ganondorf's surrogate mother.\n"
"Sorceress of Flame. She seems\n"
"vulnerable to " COLOR(DEFAULT) "low temperature" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0633, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova Kotake\n"
COLOR(LIGHTBLUE) "Ganondorf's surrogate mother.\n"
"Sorceress of Ice. She seems\n"
"vulnerable to " COLOR(DEFAULT) "high temperature" COLOR(LIGHTBLUE) "." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0634, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Iron Knuckle\n"
COLOR(LIGHTBLUE) "Something's strange...\n"
"This is not an ordinary enemy!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0635, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Iron Knuckle\n"
COLOR(LIGHTBLUE) "Watch out for its ax attack! \n"
"It hurts a lot! Strike when it\n"
"drops its guard!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0636, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Is this what happens to kids who\n"
"wander into the forest? It looks\n"
"like he doesn't like grownups." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0637, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Like Like\n"
COLOR(LIGHTBLUE) "An enemy that eats " COLOR(DEFAULT) "shields " COLOR(LIGHTBLUE) "and\n"
"certain " COLOR(DEFAULT) "clothes" COLOR(LIGHTBLUE) ". Beat it quickly\n"
"to get your gear back!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0638, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"0638"
)

DEFINE_MESSAGE(0x0639, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beamos\n"
COLOR(LIGHTBLUE) "Watch out for its searching beam!\n"
"I bet it doesn't like " COLOR(DEFAULT) "smoke" COLOR(LIGHTBLUE) " to\n"
"get in its eye!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Anubis\n"
COLOR(LIGHTBLUE) "It's vulnerable to " COLOR(RED) "fire" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Freezzard\n"
COLOR(LIGHTBLUE) "Watch out for its freezing\n"
"breath! Destroy it completely\n"
"before it revives." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"063c"
)

DEFINE_MESSAGE(0x063D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganondorf the Evil King\n"
COLOR(LIGHTBLUE) "I have no idea what his weak\n"
"point is!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ganon\n"
COLOR(LIGHTBLUE) "I really have no idea what his\n"
"weak point is!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x063F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Is this what happens to kids who\n"
"get lost in the forest? He might\n"
"be our friend if we do something..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0640, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Is this what happens to kids who\n"
"get lost in this forest? He seems\n"
"unhappy to have no face..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0641, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Skull Kid\n"
COLOR(LIGHTBLUE) "Is this what happens to kids who\n"
"get lost in this forest? He looks\n"
"satisfied with his skull face." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0642, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Octorok\n"
COLOR(LIGHTBLUE) "Bounce back the rocks they spit\n"
"at you!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0643, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe of the graveyard?\n"
COLOR(LIGHTBLUE) "If you stare at it with " COLOR(DEFAULT) "[Z] \n"
"Targeting" COLOR(LIGHTBLUE) ", it will disappear..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0644, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "If you stare at it with " COLOR(DEFAULT) "[Z] \n"
"Targeting" COLOR(LIGHTBLUE) ", it will disappear..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0645, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Red Tektite\n"
COLOR(LIGHTBLUE) "Lock on to it as it jumps with " COLOR(DEFAULT) "[Z]\n"
"Targeting" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0646, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Blue Tektite\n"
COLOR(LIGHTBLUE) "It's hard to beat on the water.\n"
"Lure it onto the land!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0647, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Leever\n"
COLOR(LIGHTBLUE) "Watch its movements closely and\n"
"let it go by!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0648, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat\n"
COLOR(LIGHTBLUE) "Its weak point is its " COLOR(DEFAULT) "roots" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0649, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Peahat Larva\n"
COLOR(LIGHTBLUE) "Defend with your " COLOR(DEFAULT) "shield" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064a"
)

DEFINE_MESSAGE(0x064B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"064b"
)

DEFINE_MESSAGE(0x064C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Wolfos\n"
COLOR(LIGHTBLUE) "Draw it close to you and watch \n"
"its movement carefully! Attack it \n"
"when it drops its guard!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Mad Scrub\n"
COLOR(LIGHTBLUE) "If you get close to it, it will hide \n"
"in the grass..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Business Scrub\n"
COLOR(LIGHTBLUE) "If you get close to it, it will hide \n"
"in the grass..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x064F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Dampé's Ghost\n"
COLOR(LIGHTBLUE) "That's the ghost of the dead\n"
"gravekeeper! If you chase him,\n"
"he might give you his " COLOR(DEFAULT) "keepsake" COLOR(LIGHTBLUE) "..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0650, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Meg - one of the Poe sisters\n"
COLOR(LIGHTBLUE) "If she splits into multiple images,\n"
"you need to figure out which one \n"
"is the " COLOR(DEFAULT) "real one" COLOR(LIGHTBLUE) ". Is it this one?" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0651, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Joelle - one of the Poe sisters\n"
COLOR(LIGHTBLUE) "Aim for her when she appears!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0652, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Beth - one of the Poe sisters\n"
COLOR(LIGHTBLUE) "Aim for her when she appears!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0653, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Amy - one of the Poe sisters\n"
COLOR(LIGHTBLUE) "Aim for her when she appears!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0654, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Gerudo Thief\n"
COLOR(LIGHTBLUE) "When she drops her guard,\n"
"attack! If you don't defeat her,\n"
"you'll be captured!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0655, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Stalchild\n"
COLOR(LIGHTBLUE) "Don't be afraid of the Stalchild!\n"
"Just attack it repeatedly!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0656, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Ice Keese\n"
COLOR(LIGHTBLUE) "Destroy it before it flies into\n"
"you!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0657, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "White Wolfos\n"
COLOR(LIGHTBLUE) "Lure it close to you and watch \n"
"its movement carefully! Attack it \n"
"when it drops its guard!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0658, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Guay\n"
COLOR(LIGHTBLUE) "Destroy it before it flies into\n"
"you!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0659, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Bigocto\n"
COLOR(LIGHTBLUE) "Attack it from behind!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Big Poe\n"
COLOR(LIGHTBLUE) "This Poe won't disappear even\n"
"if you stare at it. It moves\n"
"fast despite its size!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Twinrova\n"
COLOR(LIGHTBLUE) "This is the combined form of\n"
"Kotake and Koume. Turn their\n"
COLOR(DEFAULT) "magic attack " COLOR(LIGHTBLUE) "back at them!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x065C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Poe\n"
COLOR(LIGHTBLUE) "This Poe doesn't disappear even if\n"
"you stare at it. It doesn't spook\n"
"easily, does it..." COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x086D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3C") "Play using " COLOR(BLUE) "[A]" COLOR(DEFAULT) " and " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "." COLOR(YELLOW) "\n"
COLOR(DEFAULT) "\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x086E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Play using " COLOR(BLUE) "[A]" COLOR(DEFAULT) " and " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " to Stop.\n"
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
QUICKTEXT_ENABLE  SHIFT("\x16") "Play the " COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) "!" COLOR(ADJUSTABLE) "\n"
"\n"
"\n"
COLOR(DEFAULT)  QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0871, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1F") "Play the " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0872, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x11") "Play the " COLOR(BLUE) "Serenade of Water" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0873, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x15") "Play the " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0874, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0D") "Play the " COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0875, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x19") "Play the " COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0876, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0B") "Follow along with " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0877, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x20") "OK? This is " COLOR(RED) "the Song" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0878, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x27") "Memorize " COLOR(BLUE) "this song" COLOR(DEFAULT) "...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x0879, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Keep the " COLOR(YELLOW) "Sun's Song " COLOR(DEFAULT) "in your heart.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "This song" COLOR(DEFAULT) " opens the Door of Time...\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x17") "I'll never forget " COLOR(PURPLE) "this song" COLOR(DEFAULT) "!\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x087C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Play using " COLOR(BLUE) "[A]" COLOR(DEFAULT) " and " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "; " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) " to Stop.\n"
"\n"
"\n"
QUICKTEXT_DISABLE  OCARINA
)

DEFINE_MESSAGE(0x088B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
BACKGROUND("\x00", "\x20", "\x00")  PERSISTENT
)

DEFINE_MESSAGE(0x088C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x23")  COLOR(RED) "You can't warp here!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x088D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(ADJUSTABLE) "Warp to the Lost Woods?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Warp to the Death Mountain \n"
"Crater?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x088F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(BLUE) "Warp to Lake Hylia?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0890, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(YELLOW) "Warp to the Desert Colossus?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0891, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(PURPLE) "Warp to the graveyard?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0892, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Warp to the Temple of Time?" COLOR(DEFAULT)  QUICKTEXT_DISABLE "\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x0893, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x05") "You played the " COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0894, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0E") "You played the " COLOR(RED) "Bolero of Fire" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0895, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "You played the " COLOR(BLUE) "Serenade of Water" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0896, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "You played the " COLOR(YELLOW) "Requiem of Spirit" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0897, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Played the " COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0898, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "You played the " COLOR(LIGHTBLUE) "Prelude of Light" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x0899, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "You played " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089A, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x1C") "You played " COLOR(RED) "Epona's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089B, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x18") "You played " COLOR(BLUE) "Zelda's Lullaby" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089C, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "You played the " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089D, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x10") "You played the " COLOR(LIGHTBLUE) "Song of Time" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089E, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "You played the " COLOR(PURPLE) "Song of Storms" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x089F, TEXTBOX_TYPE_OCARINA, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x04") "You played the " COLOR(YELLOW) "Scarecrow's Song" COLOR(DEFAULT) ".\n"
"\n"
"\n"
QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "You finally woke up!\n"
"I'm " COLOR(RED) "Navi " COLOR(LIGHTBLUE) "the fairy!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "The Great Deku Tree asked\n"
"me to be your " COLOR(RED) "partner " COLOR(LIGHTBLUE) "from\n"
"now on! Nice to meet you!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x12") "Yahoo! Hi, " NAME "!"
)

DEFINE_MESSAGE(0x1002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wow! A fairy!!" BOX_BREAK UNSKIPPABLE "Finally, a fairy came to you,\n"
NAME "!" TEXTID("\x10\x0F")
)

DEFINE_MESSAGE(0x1003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I'll wait for you here.\n"
"Get going! Go see the Great \n"
"Deku Tree!"
)

DEFINE_MESSAGE(0x1004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
COLOR(BLUE) "[A] " COLOR(DEFAULT) "by the stone, pick it up!\n"
COLOR(BLUE) "[A] " COLOR(DEFAULT) "by the stone, pick it up!" BOX_BREAK "Mean old" COLOR(RED) " Mido" COLOR(DEFAULT) "...he made me pick \n"
"up the rocks in front of his house."
)

DEFINE_MESSAGE(0x1005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, you have a " COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) " now?!\n"
"That's great, " NAME "!" BOX_BREAK UNSKIPPABLE "What?" BOX_BREAK UNSKIPPABLE "You've been called by the\n"
COLOR(RED) "Great Deku Tree" COLOR(DEFAULT) "? What an honor!" BOX_BREAK UNSKIPPABLE "He may give you a special gift!\n"
"Tee hee!" BOX_BREAK UNSKIPPABLE "That's because the Great Deku \n"
"Tree is our father, the forest\n"
"guardian, and he gave life to all \n"
"of us Kokiri!"
)

DEFINE_MESSAGE(0x1006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I wonder if the " COLOR(RED) "Great Deku Tree " COLOR(DEFAULT) "\n"
"gave life to everything in the\n"
"forest, I mean in addition to us \n"
"Kokiri?"
)

DEFINE_MESSAGE(0x1007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, let's work on some moves!" BOX_BREAK "To " COLOR(RED) "jump sideways " COLOR(DEFAULT) "while " COLOR(LIGHTBLUE) "[Z] \n"
"Targeting" COLOR(DEFAULT) ", press " COLOR(BLUE) "[A] " COLOR(DEFAULT) "as you move\n"
"right or left." BOX_BREAK "To do a " COLOR(RED) "backflip" COLOR(DEFAULT) " while " COLOR(LIGHTBLUE) "[Z] \n"
"Targeting" COLOR(DEFAULT) ", press " COLOR(BLUE) "[A] " COLOR(DEFAULT) "as you move\n"
"backwards." BOX_BREAK "To do a " COLOR(RED) "roll attack" COLOR(DEFAULT) " while " COLOR(LIGHTBLUE) "[Z] \n"
"Targeting" COLOR(DEFAULT) ", press " COLOR(BLUE) "[A] " COLOR(DEFAULT) "as you move\n"
"forward. While you roll, you can\n"
"avoid damage." BOX_BREAK "If you have your sword ready while\n"
COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", you can do a " COLOR(RED) "jump \n"
"attack" COLOR(DEFAULT) " by pressing " COLOR(BLUE) "[A]" COLOR(DEFAULT) "! A jump \n"
"attack does double damage!" BOX_BREAK "You can use " COLOR(LIGHTBLUE) "[Z] Targeting " COLOR(DEFAULT) "on the\n"
COLOR(RED) "stone" COLOR(DEFAULT) " next to me, so let's \n"
"practice!"
)

DEFINE_MESSAGE(0x1008, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You're not allowed to leave the \n"
"forest!" TEXTID("\x10\x09")
)

DEFINE_MESSAGE(0x1009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The Great Deku Tree said that if\n"
"a Kokiri leaves the woods, he or \n"
"she will die!"
)

DEFINE_MESSAGE(0x100A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "That meanie," COLOR(RED) " Mido" COLOR(DEFAULT) ", made me cut \n"
"the grass at Saria's house." BOX_BREAK UNSKIPPABLE "Mido told Saria he would do it so\n"
"she would like him, but I'm the one\n"
"doing all the work!" TEXTID("\x10\x0B")
)

DEFINE_MESSAGE(0x100B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You and " COLOR(RED) "Saria" COLOR(DEFAULT) " are close friends,\n"
"so will you help me cut the \n"
"grass?" BOX_BREAK "I'll let you keep anything that \n"
"you find while cutting it."
)

DEFINE_MESSAGE(0x100C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Yes, yes! That's how you use a\n"
COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "It's so great that you finally have\n"
"a fairy" COLOR(RED) " " COLOR(DEFAULT) "partner!" BOX_BREAK UNSKIPPABLE "I'll teach you how to talk to \n"
"people using your fairy!" TEXTID("\x10\x0D")
)

DEFINE_MESSAGE(0x100D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"When a fairy flies near a person \n"
"or thing, press " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " to " COLOR(RED) "look " COLOR(DEFAULT) "in that\n"
"direction." BOX_BREAK "If you use " COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) ", you can \n"
"talk to people from a distance, \n"
"like we're doing now." BOX_BREAK "When you have nothing that you\n"
"can target, you can press " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " just\n"
"to " COLOR(RED) "look forward" COLOR(DEFAULT) ".\n"
"Try it!"
)

DEFINE_MESSAGE(0x100E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, a " COLOR(LIGHTBLUE) "fairy " COLOR(DEFAULT) "finally came to you!" BOX_BREAK UNSKIPPABLE "Now you have a lot to learn!" TEXTID("\x10\x19")
)

DEFINE_MESSAGE(0x100F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x63") "Wow! " QUICKTEXT_ENABLE "That's great news!" QUICKTEXT_DISABLE "\n"
"I'm so happy for you!" BOX_BREAK UNSKIPPABLE "Now you're a true Kokiri,\n"
NAME "!" TEXTID("\x10\x10")
)

DEFINE_MESSAGE(0x1010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Is that right? \n"
"The Great Deku Tree has \n"
"summoned you?" BOX_BREAK UNSKIPPABLE "It's quite an honor to talk to the\n"
"Great Deku Tree!" TEXTID("\x10\x03")
)

DEFINE_MESSAGE(0x1011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh, you're leaving..."
)

DEFINE_MESSAGE(0x1012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "But that's OK, because we'll be\n"
"friends forever...\n"
"won't we?"
)

DEFINE_MESSAGE(0x1013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I want you to have this Ocarina...\n"
"Please take good care of it."
)

DEFINE_MESSAGE(0x1014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"When you play my Ocarina, I hope\n"
"you will think of me and come\n"
"back to the forest to visit."
)

DEFINE_MESSAGE(0x1015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh... Navi...\n"
"Thou hast returned..." BOX_BREAK UNSKIPPABLE  NAME "...\n"
"Welcome..." BOX_BREAK UNSKIPPABLE "Listen carefully to what I, the\n"
COLOR(RED) "Deku Tree" COLOR(DEFAULT) ", am about to tell thee..." BOX_BREAK UNSKIPPABLE "Thy slumber these past moons \n"
"must have been restless, and\n"
"full of nightmares..." BOX_BREAK UNSKIPPABLE "As the servants of evil gain\n"
"strength, a vile climate pervades\n"
"the land and causes nightmares\n"
"to those sensitive to it..." BOX_BREAK UNSKIPPABLE "Verily, thou hast felt it..." BOX_BREAK UNSKIPPABLE  NAME "... \n"
"The time has come to test thy\n"
"courage..." TEXTID("\x10\x16")
)

DEFINE_MESSAGE(0x1016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I have been " COLOR(RED) "cursed" COLOR(DEFAULT) "...\n"
"I need you to break the curse\n"
"with your wisdom and courage." BOX_BREAK "Dost thou have courage enough\n"
"to undertake this task?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Then enter, brave \n"
NAME ", and thou too, \n"
"Navi..." BOX_BREAK UNSKIPPABLE "Navi the fairy...  \n"
"Thou must aid " NAME "..." BOX_BREAK UNSKIPPABLE "And " NAME "...When " COLOR(LIGHTBLUE) "Navi \n"
COLOR(DEFAULT) "speaks, use " COLOR(YELLOW) "[C-Up] " COLOR(DEFAULT) "to listen well \n"
"to her words of wisdom..."
)

DEFINE_MESSAGE(0x1018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Perhaps you do not yet have \n"
"confidence in your abilities...\n"
"Return to the Kokiri Forest to\n"
"learn the skills of combat..." BOX_BREAK "When thou art ready, return here \n"
"and speak with me by using " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The best place to go to learn\n"
"some new skills is in the " COLOR(ADJUSTABLE) "Forest \n"
"Training Center" COLOR(DEFAULT) "." COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "It's on the hill\n"
"just above here."
)

DEFINE_MESSAGE(0x101A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82")  QUICKTEXT_ENABLE "Ow-ow-ow!" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "Forgive me, master!" QUICKTEXT_DISABLE "\n"
"If I give you a clue, will you let \n"
"me go?" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "When you jump off a high cliff,\n"
"if you hold " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) " forward, you will\n"
"roll on the ground when you land \n"
"and won't get hurt from the fall." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "I can't guarantee it will\n"
"work, though, if the cliff is really,\n"
"really high, heh heh!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Well, try it if you are feeling\n"
"bold!\n"
QUICKTEXT_ENABLE "Wah ha hah!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x101B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee!\n"
"Under that mask...aren't you that\n"
"Kokiri kid?"
)

DEFINE_MESSAGE(0x101C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Quite an unusual mask you have\n"
"there. Hee hee! I like it! It may\n"
"make me look a little bit tougher." BOX_BREAK "Hey, why don't you give it to me?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No way" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x101D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Doh! That's too bad for me..."
)

DEFINE_MESSAGE(0x101E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Yowza! I'm gonna wear this \n"
"all the time!"
)

DEFINE_MESSAGE(0x101F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "He just gave you " COLOR(RED) "10 Rupees" COLOR(DEFAULT) " for \n"
"this 20-Rupee mask! You lost \n"
"money on that deal!" BOX_BREAK UNSKIPPABLE "Go back to the Mask Shop \n"
"and pay " COLOR(RED) "20 Rupees" COLOR(DEFAULT) " for the \n"
"mask. The difference will have to \n"
"come out of your own pocket."
)

DEFINE_MESSAGE(0x1020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My buddies really want this mask!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x1021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, you're OK? You didn't leave \n"
"the forest after all, did you?"
)

DEFINE_MESSAGE(0x1022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did you know that if you hold " COLOR(LIGHTBLUE) "▼\n"
COLOR(DEFAULT) "forward when you jump off a cliff,\n"
"you'll roll when you land. This will\n"
"absorb the shock of your landing." BOX_BREAK "If you fall too far, though, you'll\n"
"still get hurt..."
)

DEFINE_MESSAGE(0x1023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria said she's waiting at the\n"
"usual spot."
)

DEFINE_MESSAGE(0x1024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Well done, " NAME "..."
)

DEFINE_MESSAGE(0x1025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You have a cool Slingshot, huh?" BOX_BREAK "You know what's cool about it?\n"
"You can aim while holding down\n"
COLOR(YELLOW) "[C]" COLOR(DEFAULT) " and shoot by releasing the\n"
"button! How cool!" BOX_BREAK "If you have the Slingshot ready,\n"
"you can use " COLOR(LIGHTBLUE) "[Z] Targeting" COLOR(DEFAULT) " to \n"
COLOR(RED) "shoot while moving" COLOR(DEFAULT) ".... Did you \n"
"know that?"
)

DEFINE_MESSAGE(0x1026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"No, " NAME "...\n"
"Thou must know my time is short..."
)

DEFINE_MESSAGE(0x1027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Now...listen carefully...\n"
"A " COLOR(RED) "wicked man of the desert" COLOR(DEFAULT) " \n"
"cast this dreadful curse upon me..."
)

DEFINE_MESSAGE(0x1028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you're looking for Saria, she's\n"
"in the " COLOR(ADJUSTABLE) "Lost Woods" COLOR(DEFAULT) ", as usual." BOX_BREAK "Don't tell me you don't know \n"
"where that is! The entrance is up\n"
"on the cliff overlooking the \n"
"village!" BOX_BREAK "I know you'll get lost! Don't \n"
"worry, you'll just end up back at\n"
"the entrance!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Harumph!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Thou must never allow the desert \n"
"man in black armor to lay his \n"
"hands on the sacred Triforce..." BOX_BREAK UNSKIPPABLE "Thou must never suffer that man,\n"
"with his evil heart, to enter the \n"
"Sacred Realm" COLOR(RED) " " COLOR(DEFAULT) "of legend..." BOX_BREAK UNSKIPPABLE "That evil man who cast the death \n"
"curse upon me and sapped my \n"
"power..." BOX_BREAK UNSKIPPABLE "Because of that curse, my end is\n"
"nigh..." BOX_BREAK UNSKIPPABLE "Though your valiant efforts to \n"
"break the curse were successful, \n"
"I was doomed before you started..." BOX_BREAK UNSKIPPABLE "Yes, I will pass away soon...\n"
UNSKIPPABLE "But do not grieve for me..." BOX_BREAK UNSKIPPABLE "I have been able to tell you of \n"
"these important matters..." BOX_BREAK UNSKIPPABLE "This is Hyrule's final hope..."
)

DEFINE_MESSAGE(0x102A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The future depends upon thee,\n"
NAME "...\n"
"Thou art courageous..." BOX_BREAK UNSKIPPABLE "Navi the fairy...\n"
"Help " NAME " to carry out \n"
"my will..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "I entreat ye... Navi..." TEXT_SPEED("\x00") "\n"
TEXT_SPEED("\x03") "Good...bye..." TEXT_SPEED("\x00")
)

DEFINE_MESSAGE(0x102B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "Let's go to Hyrule Castle,\n"
NAME "!!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01")  COLOR(LIGHTBLUE) "Good-bye..." COLOR(DEFAULT)  TEXT_SPEED("\x00")  COLOR(LIGHTBLUE) "Great Deku Tree..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Too bad...Heh heh!"
)

DEFINE_MESSAGE(0x102E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to play some more?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x102F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey you! \"" COLOR(LIGHTBLUE) "Mr. No Fairy" COLOR(DEFAULT) "!\"\n"
"What's your business with the\n"
"Great Deku Tree?" BOX_BREAK UNSKIPPABLE "Without a fairy, you're not\n"
"even a real man!" TEXTID("\x10\xD0")
)

DEFINE_MESSAGE(0x1030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you want to pass through here,\n"
"you should at least " COLOR(BLUE) "equip" COLOR(DEFAULT) " a " COLOR(ADJUSTABLE) "sword" COLOR(RED) "\n"
COLOR(DEFAULT) "and " COLOR(LIGHTBLUE) "shield" COLOR(DEFAULT) "!" BOX_BREAK SHIFT("\x51")  QUICKTEXT_ENABLE "Sheesh!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x1031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x57")  QUICKTEXT_ENABLE "What?!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  COLOR(RED) "Mido " COLOR(DEFAULT) "won't let you go to see \n"
"the Great Deku Tree?" TEXTID("\x10\xC8")
)

DEFINE_MESSAGE(0x1032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You can buy a " COLOR(LIGHTBLUE) "shield" COLOR(DEFAULT) " at the shop,\n"
"but there is only one " COLOR(ADJUSTABLE) "sword" COLOR(DEFAULT) "\n"
"hidden somewhere in the forest."
)

DEFINE_MESSAGE(0x1033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "If you want to see the \n"
"Great Deku Tree, you should at \n"
"least equip a " COLOR(ADJUSTABLE) "sword" COLOR(DEFAULT) " and " COLOR(LIGHTBLUE) "shield" COLOR(DEFAULT) "!" TEXTID("\x10\xD2")
)

DEFINE_MESSAGE(0x1034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I, the great Mido," COLOR(RED) " " COLOR(DEFAULT) "will never \n"
"accept you as one of us!" BOX_BREAK "Shoot! How did you get to be the\n"
"favorite of Saria and the Great\n"
"Deku Tree? Huh?!\n"
"Grumble...grumble..."
)

DEFINE_MESSAGE(0x1035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I can teach you about the " COLOR(RED) "icons\n"
COLOR(DEFAULT) "at the top of the screen.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "About the yellow icons\n"
"About the blue icon" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"The three yellow icons in the \n"
"upper right are called " COLOR(YELLOW) "[C] icons" COLOR(DEFAULT) "." BOX_BREAK "They display the things you can\n"
"use with the " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) "," COLOR(YELLOW) " [C-Down] " COLOR(DEFAULT) "and" COLOR(YELLOW) " \n"
"[C-Right] " COLOR(DEFAULT) "buttons." BOX_BREAK "Once you get a " COLOR(YELLOW) "[C] Button item" COLOR(DEFAULT) ", \n"
"go into the " COLOR(YELLOW) "Select Item Subscreen" COLOR(DEFAULT) " \n"
"and set it to one of the three\n"
COLOR(YELLOW) "[C] Buttons" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x1037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"The blue icon at the top of the\n"
"screen is called the " COLOR(BLUE) "Action Icon" COLOR(DEFAULT) "." BOX_BREAK "This Action Icon shows you \n"
"what action you will perform\n"
"when you press " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Stop in many spots to see the\n"
"different things you can do."
)

DEFINE_MESSAGE(0x1038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you want to learn about the\n"
COLOR(RED) "map " COLOR(DEFAULT) "and " COLOR(RED) "items" COLOR(DEFAULT) ", just ask me.\n"
"But don't ask unless you want\n"
"to hear a long explanation." BOX_BREAK "What do you want to know about?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "About the map \n"
"About items\n"
"Don't ask" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"There is a " COLOR(RED) "map" COLOR(DEFAULT) " displayed at the\n"
"bottom right of the screen." BOX_BREAK "The " COLOR(YELLOW) "yellow arrow " COLOR(DEFAULT) "shows your \n"
"current position and direction you\n"
"are facing. The " COLOR(RED) "red mark " COLOR(DEFAULT) "shows\n"
"where you entered the area from." BOX_BREAK "You can turn the map display on\n"
"and off with the " COLOR(LIGHTBLUE) "[L]" COLOR(DEFAULT) "." BOX_BREAK "If you want to see the name of a\n"
"place, press " COLOR(RED) "START" COLOR(DEFAULT) "." BOX_BREAK "You'll get into the Subscreens.\n"
"Select the " COLOR(RED) "Map Subscreen" COLOR(DEFAULT) "." BOX_BREAK "On the Map Subscreen, you can \n"
"see a map of Hyrule.\n"
"Did you get all that?"
)

DEFINE_MESSAGE(0x103A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"There are three kinds of items:\n"
COLOR(BLUE) "Equipment items" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C] Button items" COLOR(DEFAULT) "\n"
"and " COLOR(LIGHTBLUE) "Quest items" COLOR(DEFAULT) "." BOX_BREAK COLOR(BLUE) "Equipment items" COLOR(DEFAULT) " are things like \n"
"the sword, shield and clothes \n"
"that are effective when you equip\n"
"them." BOX_BREAK COLOR(YELLOW) "[C] Button items" COLOR(DEFAULT) " can be set to \n"
COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ", " COLOR(YELLOW) "[C-Down]" COLOR(DEFAULT) ", and " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) ", and\n"
"used by pressing those buttons." BOX_BREAK COLOR(LIGHTBLUE) "Quest items " COLOR(DEFAULT) "are things you \n"
"collect during your adventure. You\n"
"just carry them around." BOX_BREAK "If you want to change equipment\n"
"or just check on your inventory,\n"
"press " COLOR(RED) "START" COLOR(DEFAULT) ". \n"
"You will get into the Subscreens." BOX_BREAK "Switch to one of the four \n"
"different Subscreens with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " or\n"
COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "and change or check items as\n"
"you please. Take a look around!" BOX_BREAK "When you decide to equip an \n"
COLOR(BLUE) "Equipment item" COLOR(DEFAULT) ", press " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". For\n"
COLOR(YELLOW) "[C] Button items" COLOR(DEFAULT) ", press " COLOR(YELLOW) "[C-Left]" COLOR(DEFAULT) ",\n"
COLOR(YELLOW) "[C-Down] " COLOR(DEFAULT) "or " COLOR(YELLOW) "[C-Right]" COLOR(DEFAULT) "." BOX_BREAK "That was a pretty long explanation.\n"
"Did you understand everything?"
)

DEFINE_MESSAGE(0x103B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, just remember this. If you\n"
"want to " COLOR(ADJUSTABLE) "save" COLOR(DEFAULT) ", press " COLOR(RED) "START " COLOR(DEFAULT) "to get\n"
"into the Subscreens, then press\n"
COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x103C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"My sister took some Rupees and \n"
"went shopping at the store\n"
"that has a red roof.\n"
"Tee hee!" BOX_BREAK "Speaking of " COLOR(RED) "Rupees" COLOR(DEFAULT) ", a " COLOR(ADJUSTABLE) "green " COLOR(DEFAULT) "one\n"
"is worth one, a " COLOR(BLUE) "blue" COLOR(DEFAULT) " one is worth\n"
"five and a " COLOR(RED) "red" COLOR(DEFAULT) " one is worth \n"
"twenty. Hee hee!"
)

DEFINE_MESSAGE(0x103D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This shop...It sells things you\n"
"can get in the forest for free!\n"
"Tee hee!" BOX_BREAK "Do you know how to use the \n"
COLOR(RED) "Deku Shield" COLOR(DEFAULT) "? Tee hee!" BOX_BREAK "When you get the shield, press\n"
COLOR(RED) "START " COLOR(DEFAULT) "to get into the Subscreens.\n"
"Select the " COLOR(BLUE) "Equipment Subscreen\n"
COLOR(DEFAULT) "with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " or " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) "." BOX_BREAK "On the " COLOR(BLUE) "Equipment Subscreen" COLOR(DEFAULT) ", \n"
"choose the item you want to equip\n"
"and press " COLOR(BLUE) "[A]" COLOR(DEFAULT) " to equip that item." BOX_BREAK "Once you equip it, hold it up\n"
"with " COLOR(LIGHTBLUE) "[R]" COLOR(DEFAULT) " and change its angle\n"
"with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ". Tee hee!"
)

DEFINE_MESSAGE(0x103E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to know how to use\n"
"the " COLOR(YELLOW) "[C-Up] Button" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x103F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you press " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ", you can\n"
"change your view." BOX_BREAK "In a place like this, it will switch\n"
"to a top-down view. Outdoors, in\n"
"a field for example, it will switch\n"
"to a first-person perspective." BOX_BREAK "Also, when \"" COLOR(YELLOW) "Navi" COLOR(DEFAULT) "\" is displayed in\n"
"the upper right of your screen, \n"
"Navi the fairy wants to talk to\n"
"you. Use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " to listen to her!"
)

DEFINE_MESSAGE(0x1040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, if you play around with it, \n"
"you'll figure it out."
)

DEFINE_MESSAGE(0x1041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That's not quite Saria's Song..."
)

DEFINE_MESSAGE(0x1042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido" COLOR(RED) " " COLOR(DEFAULT) "is very upset!\n"
"Did something happen to him?"
)

DEFINE_MESSAGE(0x1043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What? Where are you going?!" BOX_BREAK "To the castle?\n"
"Where is the castle?"
)

DEFINE_MESSAGE(0x1044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We Kokiri will die if we leave the\n"
"forest!" BOX_BREAK "You're not going to try to leave\n"
"the forest, are you?!"
)

DEFINE_MESSAGE(0x1045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey, " NAME "!\n"
"What did you do?!" BOX_BREAK UNSKIPPABLE "The Great Deku Tree...did he...\n"
"die?" BOX_BREAK UNSKIPPABLE "How could you do a thing like \n"
"that?! It's all your fault!!" EVENT
)

DEFINE_MESSAGE(0x1046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hey!!" QUICKTEXT_DISABLE "\n"
"What are you doing in my house?!"
)

DEFINE_MESSAGE(0x1047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", you're safe!" TEXTID("\x10\x48")
)

DEFINE_MESSAGE(0x1048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria and " NAME " will be\n"
"friends forever."
)

DEFINE_MESSAGE(0x1049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did something happen to the \n"
"Great Deku Tree?"
)

DEFINE_MESSAGE(0x104A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Somehow, it seems that the air in\n"
"the forest has changed."
)

DEFINE_MESSAGE(0x104B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME ", are you going\n"
"to go away?"
)

DEFINE_MESSAGE(0x104C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you lose your shield, will\n"
"you come back?"
)

DEFINE_MESSAGE(0x104D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\x80") "All of the young Deku Scrub\n"
"brothers agree...you look exactly \n"
"like our sacred forest totem!" BOX_BREAK SFX("\x38\x80") "As an offering from us, please\n"
"accept these " COLOR(RED) "Deku Sticks" COLOR(DEFAULT) ".\n"
"We will also enhance your\n"
"carrying skills!" BOX_BREAK "Abracadabra!" BOX_BREAK SFX("\x38\x80") "Alakazaaaam!" EVENT
)

DEFINE_MESSAGE(0x104E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Since the Great Deku Tree\n"
"withered...more meanies have \n"
"been appearing in the forest...\n"
"I'm scared!"
)

DEFINE_MESSAGE(0x104F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "An evil wind is blowing from the \n"
"direction of the Forest Temple." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Saria" COLOR(DEFAULT) " left, saying,\n"
"\"I have to do something\n"
"about it!\"" TEXTID("\x10\x50")
)

DEFINE_MESSAGE(0x1050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The " COLOR(ADJUSTABLE) "Forest Temple " COLOR(DEFAULT) "is located \n"
"in the Sacred Forest Meadow in\n"
"the far side of the Lost Woods."
)

DEFINE_MESSAGE(0x1051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria went to the temple and \n"
"hasn't come back..."
)

DEFINE_MESSAGE(0x1052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hi, mister! You can't use a\n"
"Deku Shield! It's only for\n"
"kids!"
)

DEFINE_MESSAGE(0x1053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Where's Saria? \n"
"Do you know Saria, mister?\n"
"That's weird..." TEXTID("\x10\x54")
)

DEFINE_MESSAGE(0x1054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Where has " COLOR(RED) "Mido" COLOR(DEFAULT) " gone during such\n"
"an emergency?"
)

DEFINE_MESSAGE(0x1055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I see. You didn't have any \n"
"problems entering the forest, \n"
"mister..." BOX_BREAK "Did the meanies out there bother\n"
"you much? Before the Great Deku \n"
"Tree died, you wouldn't see things\n"
"like that around here...." TEXTID("\x10\x56")
)

DEFINE_MESSAGE(0x1056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Since it's dangerous outside, I \n"
"always stay inside my house. \n"
"But I'm bored to death in here!"
)

DEFINE_MESSAGE(0x1057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You can buy " COLOR(RED) "arrows " COLOR(DEFAULT) "at a shop \n"
"only if you have a " COLOR(RED) "bow" COLOR(DEFAULT) ". Have you \n"
"got one, mister?"
)

DEFINE_MESSAGE(0x1058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Have you been travelling around\n"
"much, mister?\n"
"Have you ever met a boy named \n"
NAME "?" BOX_BREAK UNSKIPPABLE "Mido said that the Great Deku \n"
"Tree withered because that boy\n"
"did something wrong to it..." BOX_BREAK UNSKIPPABLE "Only Saria defended \n"
NAME "--until she left." TEXTID("\x10\x59")
)

DEFINE_MESSAGE(0x1059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Maybe we misunderstood...."
)

DEFINE_MESSAGE(0x105A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Haven't I seen you somewhere\n"
"before, mister?"
)

DEFINE_MESSAGE(0x105B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Mister, do you know a boy \n"
"named " NAME "?" BOX_BREAK UNSKIPPABLE "He left the forest and never\n"
"came back..." TEXTID("\x10\x5C")
)

DEFINE_MESSAGE(0x105C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I wonder if " NAME " will \n"
"ever return?"
)

DEFINE_MESSAGE(0x105D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "It would be awesome to be big \n"
"like you, mister! I really want to\n"
"be big like you!" BOX_BREAK UNSKIPPABLE "I want to be big and strong and \n"
"beat up the Deku Scrubs, but..." TEXTID("\x10\x5E")
)

DEFINE_MESSAGE(0x105E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We Kokiri won't ever get bigger \n"
"for the rest of our lives...\n"
"What a bummer!"
)

DEFINE_MESSAGE(0x105F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Why is that fairy following you \n"
"around? You're not one of us!"
)

DEFINE_MESSAGE(0x1060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What are you? Though you wear \n"
"Kokirish clothing, you can't\n"
"fool me!" TEXTID("\x10\x61")
)

DEFINE_MESSAGE(0x1061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I promised Saria I would never\n"
"let anybody go through here."
)

DEFINE_MESSAGE(0x1062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hi there! I'm the " COLOR(RED) "Deku Tree \n"
"sprout" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Because you and Saria" COLOR(RED) " " COLOR(DEFAULT) "broke the\n"
"curse on the Forest Temple, I \n"
"can grow and flourish!" BOX_BREAK UNSKIPPABLE "Thanks a lot!"
)

DEFINE_MESSAGE(0x1063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, have you seen your old\n"
"friends? None of them recognized\n"
"you with your grown-up body, did\n"
"they?" BOX_BREAK UNSKIPPABLE "That's because the " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) " never\n"
"grow up! Even after seven years,\n"
"they're still kids!"
)

DEFINE_MESSAGE(0x1064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You must be wondering why only\n"
"you have grown up!" BOX_BREAK UNSKIPPABLE "Well, as you might have already \n"
"guessed, you are not a Kokiri!\n"
"You are actually a " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "I am happy to finally reveal this\n"
"secret to you!"
)

DEFINE_MESSAGE(0x1065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"Some time ago, before the King of\n"
"Hyrule unified this country, there\n"
"was a fierce war in our world." BOX_BREAK_DELAYED("\x5A") "One day, to escape from the fires\n"
"of the war, a " COLOR(RED) "Hylian mother " COLOR(DEFAULT) "and \n"
"her " COLOR(RED) "baby boy" COLOR(DEFAULT) " entered this \n"
"forbidden forest." BOX_BREAK_DELAYED("\x5A") "The mother was gravely injured...\n"
"Her only choice was to entrust\n"
"the child to the " COLOR(RED) "Deku Tree" COLOR(DEFAULT) ", the \n"
"guardian spirit of the forest." BOX_BREAK_DELAYED("\x5A") "The Deku Tree could sense that\n"
"this was a child of destiny, whose\n"
"fate would affect the entire world,\n"
"so he took him into the forest." BOX_BREAK_DELAYED("\x5A") "After the mother passed away, \n"
"the baby was raised as a " COLOR(ADJUSTABLE) "Kokiri" COLOR(DEFAULT) ".\n"
"And now, finally, the day of \n"
"destiny has come!" FADE("\x5A")
)

DEFINE_MESSAGE(0x1066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You are a " COLOR(LIGHTBLUE) "Hylian" COLOR(DEFAULT) ", and were\n"
"always bound to leave this forest." BOX_BREAK UNSKIPPABLE "And now...\n"
"You have learned your own \n"
"destiny...\n"
"So you know what you must do..." BOX_BREAK UNSKIPPABLE "That's right...\n"
"You must save the land of \n"
"Hyrule!" BOX_BREAK UNSKIPPABLE "Now, " NAME ", break the \n"
"curses on all of the Temples,\n"
"and return peace to Hyrule!!"
)

DEFINE_MESSAGE(0x1067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x37") "That melody?!" BOX_BREAK UNSKIPPABLE "Saria plays that song all the \n"
"time!\n"
"You...Do you know Saria?" BOX_BREAK UNSKIPPABLE "That song..." BOX_BREAK UNSKIPPABLE "Saria taught that song only \n"
"to her friends..." TEXTID("\x10\x6F")
)

DEFINE_MESSAGE(0x1068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When I see you... \n"
"I don't know why, but I remember...\n"
"him..."
)

DEFINE_MESSAGE(0x1069, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I have you now!\n"
"In this gap between dreams and \n"
"reality, soon all that will remain\n"
"of you will be your dead body!"
)

DEFINE_MESSAGE(0x106A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Thank you...\n"
"Because of you, I could awaken as\n"
"a Sage..." BOX_BREAK UNSKIPPABLE "I am " COLOR(ADJUSTABLE) "Saria" COLOR(DEFAULT) ".\n"
"The Sage of the Forest Temple..."
)

DEFINE_MESSAGE(0x106B, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x28") "Saria will always be...\n"
SHIFT("\x3C") "your friend..." FADE("\x50")
)

DEFINE_MESSAGE(0x106C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The flow of time is always cruel...\n"
"Its speed seems different for\n"
"each person, but no one can \n"
"change it..." BOX_BREAK UNSKIPPABLE "A thing that doesn't change with\n"
"time is a memory of younger days..." BOX_BREAK UNSKIPPABLE "In order to come back here again,\n"
"play the " COLOR(ADJUSTABLE) "Minuet of Forest" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x106D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...\n"
"I'll see you again..."
)

DEFINE_MESSAGE(0x106E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria hasn't come back yet...\n"
"But I know she'll return someday..."
)

DEFINE_MESSAGE(0x106F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "OK...\n"
"I trust you." TEXTID("\x10\x68")
)

DEFINE_MESSAGE(0x1070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh...I see..." BOX_BREAK UNSKIPPABLE "Saria won't ever come back..." BOX_BREAK UNSKIPPABLE "But...I...I made a promise to \n"
"Saria..." BOX_BREAK UNSKIPPABLE "If " NAME " came back, I \n"
"would be sure to tell him that \n"
"Saria had been waiting for him..." BOX_BREAK UNSKIPPABLE "Because " TEXT_SPEED("\x03") "Saria...really...\n"
"liked..." TEXT_SPEED("\x00")  TEXTID("\x10\x71")
)

DEFINE_MESSAGE(0x1071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x4B") "Hey, you." BOX_BREAK "If you see him somewhere, please\n"
"let him know..." TEXTID("\x10\xD6")
)

DEFINE_MESSAGE(0x1072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Teach me some fancy fencing!\n"
"All I've ever done is tap " COLOR(ADJUSTABLE) "[B] " COLOR(DEFAULT) "all\n"
"my life!"
)

DEFINE_MESSAGE(0x1073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I still think you really look like\n"
"somebody I've seen before, mister."
)

DEFINE_MESSAGE(0x1074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're such a big, strong guy!\n"
"I really want to be like you \n"
"someday even though I'll always be\n"
"small."
)

DEFINE_MESSAGE(0x1075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "... I wonder if he \n"
"will come back..."
)

DEFINE_MESSAGE(0x1076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I feel like I've known you for a\n"
"long time, mister!"
)

DEFINE_MESSAGE(0x1077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Now that the " COLOR(RED) "Deku Tree's sprout" COLOR(DEFAULT) "\n"
"is growing in the Great Deku \n"
"Tree's meadow, the forest has\n"
"returned to normal!"
)

DEFINE_MESSAGE(0x1078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We'll all work together to protect\n"
"the forest!"
)

DEFINE_MESSAGE(0x1079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Somehow, a fair wind has begun\n"
"to blow recently."
)

DEFINE_MESSAGE(0x107A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Since a fair wind started to \n"
"blow, I'm sure " NAME " \n"
"will come back!"
)

DEFINE_MESSAGE(0x107B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I wonder if Saria will come back..."
)

DEFINE_MESSAGE(0x107C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I'm sure " NAME " will \n"
"return someday!"
)

DEFINE_MESSAGE(0x107D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2E")  COLOR(LIGHTBLUE) "Great Deku Tree...\n"
COLOR(DEFAULT)  SHIFT("\x48")  COLOR(LIGHTBLUE) "I'm back!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x107E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "This evil man ceaselessly uses\n"
"his vile, sorcerous powers in his\n"
"search for the Sacred Realm that\n"
"is connected to Hyrule..." BOX_BREAK UNSKIPPABLE "For it is in that Sacred Realm \n"
"that one will find the divine\n"
"relic, the " COLOR(LIGHTBLUE) "Triforce" COLOR(DEFAULT) ", which contains \n"
"the essence of the gods..."
)

DEFINE_MESSAGE(0x107F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Before time began, before spirits\n"
SHIFT("\x31") "and life existed..." QUICKTEXT_DISABLE  FADE("\x50")
)

DEFINE_MESSAGE(0x1080, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "Three golden goddesses descended\n"
SHIFT("\x04") "upon the chaos that was Hyrule..." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1081, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x13") "Din, the goddess of power..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1082, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "Nayru, the goddess of wisdom..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1083, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "Farore, the goddess of courage..." QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x1084, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x53") "Din..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1085, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x02") "With her strong flaming arms, she\n"
SHIFT("\x0A") "cultivated the land and created\n"
SHIFT("\x3A") "the red earth." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1086, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4C") "Nayru..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1087, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x03") "Poured her wisdom onto the earth\n"
SHIFT("\x0F") "and gave the spirit of law to\n"
SHIFT("\x45") "the world." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x1088, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x4B") "Farore..." QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x1089, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x09") "With her rich soul, produced all\n"
SHIFT("\x14") "life forms who would uphold\n"
SHIFT("\x4B") "the law." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108A, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x16") "The three great goddesses,\n"
SHIFT("\x22") "their labors completed,\n"
SHIFT("\x19") "departed for the heavens." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108B, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x14") "And golden sacred triangles\n"
SHIFT("\x07") "remained at the point where the\n"
SHIFT("\x1B") "goddesses left the world." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108C, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x08") "Since then, the sacred triangles\n"
SHIFT("\x0E") "have become the basis of our\n"
SHIFT("\x2E") "world's providence." QUICKTEXT_DISABLE  FADE("\x5A")
)

DEFINE_MESSAGE(0x108D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x0F") "And, the resting place of the\n"
SHIFT("\x1C") "triangles has become the\n"
SHIFT("\x3B") "Sacred Realm." QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x108E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey kid, you did quite well...\n"
"It looks like you may be gaining\n"
"some slight skill..." BOX_BREAK_DELAYED("\x3C") "But you have defeated only my\n"
"phantom...\n"
"When you fight the real me, it \n"
"won't be so easy!" BOX_BREAK_DELAYED("\x3C") "What a worthless creation that \n"
"ghost was! I will banish it to\n"
"the gap between dimensions!!" FADE("\x3C")
)

DEFINE_MESSAGE(0x108F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I always believed that you would \n"
"come. Because I know you..." BOX_BREAK UNSKIPPABLE "No..." BOX_BREAK_DELAYED("\x1E")  UNSKIPPABLE "You don't have to explain\n"
"it to me..." BOX_BREAK UNSKIPPABLE "Because it is destiny that you \n"
"and I can't live in the same world."
)

DEFINE_MESSAGE(0x1090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I will stay here as the Forest\n"
"Sage and help you..." BOX_BREAK UNSKIPPABLE "Now, please take this \n"
COLOR(ADJUSTABLE) "Medallion" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x1091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Thou hast verily demonstrated \n"
"thy courage..." BOX_BREAK UNSKIPPABLE "I knew that thou wouldst be able\n"
"to carry out my wishes..."
)

DEFINE_MESSAGE(0x1092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
"Now, I have yet more to tell ye,\n"
"wouldst thou listen...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  NAME "...\n"
"Go now to Hyrule Castle..." BOX_BREAK UNSKIPPABLE "There, thou will surely meet\n"
"the " COLOR(RED) "Princess of Destiny" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Take " COLOR(RED) "this stone " COLOR(DEFAULT) "with you.\n"
"The stone that man wanted so\n"
"much, that he cast the curse on\n"
"me..."
)

DEFINE_MESSAGE(0x1094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I" COLOR(RED) " " COLOR(DEFAULT) "knew...\n"
"that you would leave the forest...\n"
"someday, " NAME "..." BOX_BREAK UNSKIPPABLE "Because you are different from\n"
"me" COLOR(RED) " " COLOR(DEFAULT) "and my friends...."
)

DEFINE_MESSAGE(0x1095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x44")  COLOR(LIGHTBLUE) "Hello, " QUICKTEXT_ENABLE  NAME  QUICKTEXT_DISABLE "!\n"
"Wake up!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "The" COLOR(RED) " Great Deku Tree " COLOR(LIGHTBLUE) "wants\n"
"to talk to you!\n"
QUICKTEXT_ENABLE  NAME ", get up!" QUICKTEXT_DISABLE  COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "Hey! " QUICKTEXT_ENABLE "C'mon!" QUICKTEXT_DISABLE  COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Can Hyrule's destiny really depend\n"
"on such a lazy boy?" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Jumping is going out of style now.\n"
"I'm crazy about doing " COLOR(RED) "backflips" COLOR(DEFAULT) "!\n"
SHIFT("\x32") "Can you do one?"
)

DEFINE_MESSAGE(0x1098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  COLOR(LIGHTBLUE) "The " COLOR(RED) "Great Deku Tree \n"
COLOR(LIGHTBLUE) "has summoned you!\n"
"So let's get going, right now!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x1099, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x4B") "Navi...\n"
SHIFT("\x23") "Navi, where art thou?\n"
SHIFT("\x39") "Come hither...."
)

DEFINE_MESSAGE(0x109A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh, " COLOR(LIGHTBLUE) "Navi the fairy" COLOR(DEFAULT) "...\n"
"Listen to my words, the words of \n"
"the " COLOR(RED) "Deku Tree" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Dost thou sense it?\n"
"The climate of evil descending \n"
"upon this realm..." BOX_BREAK UNSKIPPABLE "Malevolent forces even now are\n"
"mustering to attack our land\n"
"of Hyrule..." BOX_BREAK UNSKIPPABLE "For so long, the " COLOR(RED) "Kokiri Forest" COLOR(DEFAULT) ", the\n"
"source of life, has stood as a \n"
"barrier, deterring outsiders and \n"
"maintaining the order of the world..." BOX_BREAK UNSKIPPABLE "But...before this tremendous evil\n"
"power, even my power is as \n"
"nothing..." BOX_BREAK UNSKIPPABLE "It seems the time has come for \n"
"the " COLOR(RED) "boy without a fairy " COLOR(DEFAULT) "to begin \n"
"his journey..." BOX_BREAK UNSKIPPABLE "The youth whose destiny it is to\n"
"lead Hyrule to the path of \n"
"justice and truth..." BOX_BREAK UNSKIPPABLE  COLOR(LIGHTBLUE) "Navi" COLOR(DEFAULT) "...go now! Find our young\n"
"friend and guide him to me..." BOX_BREAK UNSKIPPABLE "I do not have much time left." BOX_BREAK UNSKIPPABLE "Fly, Navi, fly! The fate of the\n"
"forest, nay, the world, depends\n"
"upon thee!"
)

DEFINE_MESSAGE(0x109B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "Please forgive me, master! I'll \n"
"never do it again! If you spare \n"
"me, I'll teach you something cool." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "You will never beat my brothers \n"
"up ahead unless you punish them \n"
"in the proper order." BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "The order is..." TEXT_SPEED("\x05")  COLOR(LIGHTBLUE) "2  3  1" COLOR(DEFAULT)  TEXT_SPEED("\x00") "\n"
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Twenty-three is number one!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "Do you think I'm a traitor?" EVENT
)

DEFINE_MESSAGE(0x109C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x38\x82") "How did you know our secret?!\n"
"How " QUICKTEXT_ENABLE "irritating!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "It's so annoying that I'm going to\n"
"reveal the secret of Queen Gohma\n"
"to you!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "In order to administer the coup de\n"
"grace to Queen Gohma, strike\n"
"with your sword " COLOR(RED) "while she's \n"
"stunned" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "Oh, Queenie..." BOX_BREAK SFX("\x38\x80")  QUICKTEXT_ENABLE "Sorry about that!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x109D, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
"In the vast, deep forest of Hyrule..." BOX_BREAK_DELAYED("\x28")  SHIFT("\x16") "Long have I served as the\n"
SHIFT("\x33") "guardian spirit...\n"
SHIFT("\x0C") "I am known as the Deku Tree..." FADE("\x46")
)

DEFINE_MESSAGE(0x109E, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "The children of the forest, the\n"
SHIFT("\x19") "Kokiri, live here with me." BOX_BREAK_DELAYED("\x3C")  SHIFT("\x0B") "Each Kokiri has his or her own\n"
SHIFT("\x38") "guardian fairy." FADE("\x3C")
)

DEFINE_MESSAGE(0x109F, TEXTBOX_TYPE_NONE_BOTTOM, TEXTBOX_POS_VARIABLE,
SHIFT("\x0B") "However, there is one boy" COLOR(RED) " " COLOR(DEFAULT) "who\n"
SHIFT("\x20") "does not have a fairy..." FADE("\x3C")
)

DEFINE_MESSAGE(0x10A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I surrender! In return, I will sell \n"
"you Deku Nuts!\n"
COLOR(RED) "5 pieces   20 Rupees" COLOR(DEFAULT) " they are!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! In return,\n"
"I will sell you Deku Sticks!\n"
COLOR(RED) "1 piece   15 Rupees " COLOR(DEFAULT) "they are!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! In return for\n"
"sparing me, I will sell you a \n"
"Piece of Heart!\n"
COLOR(RED) "1 piece   10 Rupees " COLOR(DEFAULT) "it is!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE "Let's make a deal!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No way" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82")  QUICKTEXT_ENABLE "YIKES!!" QUICKTEXT_DISABLE "\n"
"I'm going home then!"
)

DEFINE_MESSAGE(0x10A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Not enough Rupees! \n"
"Come back again!"
)

DEFINE_MESSAGE(0x10A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "You can't have this now!\n"
"Come back again!"
)

DEFINE_MESSAGE(0x10A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x80")  QUICKTEXT_ENABLE  SHIFT("\x2D") "Thank you very much!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x10A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I've been waiting for you,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "This is the " COLOR(RED) "Sacred Forest Meadow" COLOR(DEFAULT) ".\n"
"It's" COLOR(RED) " " COLOR(DEFAULT) "my secret place!\n"
"I feel..." BOX_BREAK UNSKIPPABLE "This place will be very \n"
"important for both of us someday.\n"
"That's what I feel." BOX_BREAK UNSKIPPABLE "If you play the Ocarina here, you \n"
"can talk with the spirits in the \n"
"forest." TEXTID("\x10\xA9")
)

DEFINE_MESSAGE(0x10A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Would you like to play the \n"
"Ocarina with me?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"Don't do it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "OK, try to follow along with the\n"
"melody I will play.\n"
"Are you ready?"
)

DEFINE_MESSAGE(0x10AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Huh?!\n"
"How boring!\n"
"C'mon! Play along!"
)

DEFINE_MESSAGE(0x10AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x63")  SHIFT("\x36") "Great! Great!" BOX_BREAK UNSKIPPABLE "Please don't forget this song!\n"
"Do you promise?" TEXTID("\x10\xAD")
)

DEFINE_MESSAGE(0x10AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When you want to hear my voice,\n"
"play " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) ". You can talk \n"
"with me anytime..."
)

DEFINE_MESSAGE(0x10AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Are you taking good care of \n"
"my Ocarina?"
)

DEFINE_MESSAGE(0x10AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x38\x80") "Cool!\n"
"You're great!  You scored\n"
"three perfect bull's-eyes!" BOX_BREAK UNSKIPPABLE  SFX("\x38\x80") "I have to give a neat present\n"
"to such a wonderful person!\n"
"Please take it!" EVENT
)

DEFINE_MESSAGE(0x10B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Mido might know something about\n"
"Saria's whereabouts." BOX_BREAK "I think Mido is sulking in one of \n"
"the houses around here."
)

DEFINE_MESSAGE(0x10B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x5A")  COLOR(LIGHTBLUE) "??\n"
COLOR(DEFAULT)  SHIFT("\x15")  COLOR(LIGHTBLUE) "No response. He's sleeping." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Cojiro?  Why?\n"
"Normally only a nice guy like me \n"
"can tame you..." BOX_BREAK UNSKIPPABLE "Which means..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x01") "You... " TEXT_SPEED("\x00") "You must be a nice guy!\n"
QUICKTEXT_ENABLE "Must be!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "You must be!!" QUICKTEXT_DISABLE "\n"
"Please Mr. Nice Guy! Please!" BOX_BREAK UNSKIPPABLE "Deliver this stuff to the " COLOR(RED) "old\n"
"hag in the potion shop " COLOR(DEFAULT) "in Kakariko\n"
"Village!" EVENT
)

DEFINE_MESSAGE(0x10B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"This will disappear if you take\n"
"too long, so you gotta hurry!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"I can't" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, yeah. " QUICKTEXT_ENABLE "That's it!" QUICKTEXT_DISABLE "\n"
"You aren't a nice guy after all!!\n"
QUICKTEXT_ENABLE "Get away from me!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x10B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Saria wanted to see you...\n"
"Did she find you already?"
)

DEFINE_MESSAGE(0x10B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hurry up, nice guy!\n"
"Before it disappears, deliver it\n"
"to that old wench...."
)

DEFINE_MESSAGE(0x10B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "That guy isn't here anymore." BOX_BREAK UNSKIPPABLE "Anybody who comes into the \n"
"forest will be lost." BOX_BREAK UNSKIPPABLE "Everybody will become a Stalfos.\n"
"Everybody, Stalfos.\n"
"So, he's not here anymore.\n"
"Only his saw is left. Hee hee." TEXTID("\x10\xB8")
)

DEFINE_MESSAGE(0x10B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That medicine is made of \n"
"forest mushrooms. Give it back!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh.\n"
"Are you going to be... too?\n"
"Heh heh!"
)

DEFINE_MESSAGE(0x10BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"We sell shields, but not swords!" EVENT
)

DEFINE_MESSAGE(0x10BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You know " COLOR(ADJUSTABLE) "Saria's Song" COLOR(DEFAULT) "! We should\n"
"be friends! Here, take this!"
)

DEFINE_MESSAGE(0x10BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hi! Do you think my face is kind\n"
"of plain?\n"
"It's just not very unusual..."
)

DEFINE_MESSAGE(0x10BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Let's play again sometime!"
)

DEFINE_MESSAGE(0x10BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Follow along with our song on \n"
"your Ocarina. We'll lead you \n"
"into it."
)

DEFINE_MESSAGE(0x10BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "That was quite a nice session.\n"
"As a token of our friendship, \n"
"please take this."
)

DEFINE_MESSAGE(0x10C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, over here!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME "...Good to see you\n"
"again! Listen to this!\n"
"Hoot hoot...." TEXTID("\x10\xC1")
)

DEFINE_MESSAGE(0x10C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"After going through the Lost \n"
"Woods, you will come upon the \n"
COLOR(ADJUSTABLE) "Sacred Forest Meadow" COLOR(DEFAULT) "." BOX_BREAK "That is a sacred place where few\n"
"people have ever walked." BOX_BREAK "Shhhh...What's that?\n"
"I can hear a mysterious tune..." BOX_BREAK "You should listen for that tune\n"
"too...\n"
"Hoo hoo ho!" EVENT
)

DEFINE_MESSAGE(0x10C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to hear what I said\n"
"again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "If you are courageous, you\n"
"will make it through the forest\n"
"just fine..." BOX_BREAK UNSKIPPABLE "Just follow your ears and listen\n"
"to the sounds coming from the\n"
"forest! \n"
"Hoot hoot!"
)

DEFINE_MESSAGE(0x10C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Did you learn an Ocarina song\n"
"from Saria?" BOX_BREAK UNSKIPPABLE "That melody seems to have some\n"
"mysterious power." BOX_BREAK UNSKIPPABLE "There may be some other \n"
"mysterious songs like this that\n"
"you can learn in Hyrule." TEXTID("\x10\xC5")
)

DEFINE_MESSAGE(0x10C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you hold the Ocarina with " COLOR(YELLOW) "[C]" COLOR(DEFAULT) "\n"
"where a melody is necessary, a \n"
COLOR(RED) "musical staff " COLOR(DEFAULT) "will appear." BOX_BREAK "I recommend that you play a song\n"
"you know." BOX_BREAK "I also suggest that you play even\n"
"when a score is not displayed. \n"
"Just like this:\n"
"Hoo hoo hoo hoot hoot hoot!" EVENT
)

DEFINE_MESSAGE(0x10C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to hear what I\n"
"said again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x10C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Melodies you have learned \n"
"will be recorded on the " COLOR(LIGHTBLUE) "Quest \n"
"Status Subscreen" COLOR(DEFAULT) ". You should \n"
"memorize those melodies."
)

DEFINE_MESSAGE(0x10C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Ohh...That bum! I don't know why \n"
"he's always so mean to everyone!" BOX_BREAK UNSKIPPABLE "What he said is true, though." TEXTID("\x10\xC9")
)

DEFINE_MESSAGE(0x10C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "The forest...strange things have\n"
"been happening here lately..." BOX_BREAK UNSKIPPABLE "You need to be ready for anything.\n"
"You'd better find a weapon!" TEXTID("\x10\x32")
)

DEFINE_MESSAGE(0x10CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! In return,\n"
"I will sell you " COLOR(RED) "Deku Seeds" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 pieces   40 Rupees" COLOR(DEFAULT) " they are!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I give up! If you let me go,\n"
"I will sell you a " COLOR(RED) "Deku Shield" COLOR(DEFAULT) "! It's\n"
COLOR(RED) "50 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I quit! If you let me go, I'll sell \n"
"you some " COLOR(RED) "Bombs" COLOR(DEFAULT) "!\n"
COLOR(RED) "5 pieces   40 Rupees" COLOR(DEFAULT) " they are!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "Knock it off! Leave me alone, and \n"
"I will sell you " COLOR(RED) "Arrows" COLOR(DEFAULT) "!\n"
COLOR(RED) "30 pieces   70 Rupees" COLOR(DEFAULT) " they are!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! If you spare \n"
"me, I will sell you a " COLOR(RED) "Red Potion" COLOR(DEFAULT) " \n"
"for " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "All right! You win! Spare me, and\n"
"I will sell you a " COLOR(ADJUSTABLE) "Green Potion" COLOR(DEFAULT) " for \n"
COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What?! You've got a fairy?!\n"
"Say what? The Great Deku Tree\n"
"actually summoned you?" TEXTID("\x10\xD1")
)

DEFINE_MESSAGE(0x10D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Whaaaaaaat?!" BOX_BREAK UNSKIPPABLE "Why would he summon you and not \n"
"the great " COLOR(RED) "Mido" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "This isn't funny..." BOX_BREAK UNSKIPPABLE "I don't believe it!\n"
"You aren't even fully equipped\n"
"yet!" BOX_BREAK UNSKIPPABLE "How do you think you're going to \n"
"help the Great Deku Tree without\n"
"both a " COLOR(ADJUSTABLE) "sword" COLOR(RED) " " COLOR(DEFAULT) "and " COLOR(LIGHTBLUE) "shield" COLOR(RED) " " COLOR(DEFAULT) "ready?" BOX_BREAK "What? You're right, I don't have\n"
"my equipment ready, but..." TEXTID("\x10\x30")
)

DEFINE_MESSAGE(0x10D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SHIFT("\x2D") "Eh, what's that?!" BOX_BREAK UNSKIPPABLE "Oh, you have a " COLOR(LIGHTBLUE) "Deku Shield" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "And what's THAT?!" BOX_BREAK UNSKIPPABLE "Is that the " COLOR(ADJUSTABLE) "Kokiri Sword" COLOR(DEFAULT) "?!" BOX_BREAK UNSKIPPABLE "GOOD GRIEF!!" TEXTID("\x10\xD3")
)

DEFINE_MESSAGE(0x10D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Well, even with all that stuff, \n"
"a wimp is still a wimp, huh?" TEXTID("\x10\x34")
)

DEFINE_MESSAGE(0x10D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I lost! Now I'll sell you a " COLOR(RED) "Deku \n"
"Stick " COLOR(DEFAULT) "for " COLOR(RED) "15 Rupees" COLOR(DEFAULT) "." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I lost! Now I'll sell you " COLOR(RED) "Deku \n"
"Nuts " COLOR(DEFAULT) "if you leave me alone.\n"
COLOR(RED) "5 pieces   20 Rupees " COLOR(DEFAULT) "they are." TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"And also..." BOX_BREAK QUICKTEXT_ENABLE  SHIFT("\x0D") "I'm sorry for being mean to him." QUICKTEXT_DISABLE  BOX_BREAK SHIFT("\x45") "Tell him that, too."
)

DEFINE_MESSAGE(0x10D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hee hee hee!\n"
"You came all the way up here?\n"
"You're a real man!" TEXTID("\x10\xD8")
)

DEFINE_MESSAGE(0x10D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Look! Isn't this view pretty?\n"
"Change your viewpoint with " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) ",\n"
"so you can look around the forest\n"
"with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x10D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What did you do to the Great\n"
"Deku Tree?"
)

DEFINE_MESSAGE(0x10DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you want to go to the Lost \n"
"Woods, you'd better equip the\n"
"right gear!\n"
"Hee hee!"
)

DEFINE_MESSAGE(0x10DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\x82") "All my young Deku Scrub brothers\n"
"say...\n"
"You have a horrible face!" BOX_BREAK SFX("\x38\x82") "But don't worry! We will reward\n"
"you with many " COLOR(RED) "Deku Nuts" COLOR(DEFAULT) "." BOX_BREAK SFX("\x38\x82") "Of course, we will also enable \n"
"you to carry more of them!" BOX_BREAK "Abracadabra..." BOX_BREAK SFX("\x38\x80") "Alakazaaaam!!" EVENT
)

DEFINE_MESSAGE(0x10DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I surrender!" BOX_BREAK SFX("\x38\x80") "To make your quest easier,\n"
"I can enable you to pick up more\n"
COLOR(RED) "Deku Sticks" COLOR(DEFAULT) "!\n"
"But, it'll cost you " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "I surrender!" BOX_BREAK SFX("\x38\x80") "To make your quest easier, I can\n"
"enable you to pick up more " COLOR(RED) "Deku\n"
"Nuts" COLOR(DEFAULT) "!\n"
"But, it'll cost you " COLOR(RED) "40 Rupees" COLOR(DEFAULT) "!" TEXTID("\x10\xA3")
)

DEFINE_MESSAGE(0x10DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x38\x82") "So sorry!\n"
"You can't buy that right now!"
)

DEFINE_MESSAGE(0x10DF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That guy isn't here anymore." BOX_BREAK "Anybody who comes into the \n"
"forest will be lost." BOX_BREAK "Everybody will become a Stalfos.\n"
"Everybody, Stalfos.\n"
"So, he's not here anymore."
)

DEFINE_MESSAGE(0x2000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Thank you very much for the \n"
"other day... I haven't even asked\n"
"you your name yet..." BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02") "........" TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "Really?\n"
NAME "!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "That's what I thought!" QUICKTEXT_DISABLE "\n"
"You're the fairy boy from the\n"
"forest! That was years ago!\n"
"Do you remember me?" BOX_BREAK UNSKIPPABLE "You do? I was sure it was you\n"
"because Epona remembered you!" BOX_BREAK UNSKIPPABLE "Oh, I have to tell you about\n"
COLOR(RED) "Mr. Ingo" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "He was afraid that the Evil King\n"
"might find out that Epona had\n"
"been taken away...It really upset\n"
"him!" BOX_BREAK UNSKIPPABLE "But one day, all of a sudden, he\n"
"went back to being a normal, " COLOR(RED) "nice\n"
"person" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Now my dad is coming back...I\n"
"can't believe it, but peace is\n"
"returning to this ranch!" BOX_BREAK UNSKIPPABLE "It's all because of you! I\n"
"owe you so much!" BOX_BREAK UNSKIPPABLE "Thank you! Thank you,\n"
NAME "!"
)

DEFINE_MESSAGE(0x2001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How is " COLOR(RED) "Epona " COLOR(DEFAULT) "doing?" BOX_BREAK "If you play " COLOR(RED) "Epona's Song " COLOR(DEFAULT) "with\n"
"your Ocarina, she will surely\n"
"come to you." BOX_BREAK "Please come back to the ranch\n"
"whenever you want to " COLOR(RED) "train \n"
COLOR(DEFAULT) "Epona!"
)

DEFINE_MESSAGE(0x2002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Epona" COLOR(RED) " " COLOR(DEFAULT) "looks great!\n"
"It looks like you were able\n"
"to tame her, too!" TEXTID("\x20\x03")
)

DEFINE_MESSAGE(0x2003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How about trying your skill with\n"
"Epona on an " COLOR(RED) "obstacle course" COLOR(DEFAULT) "?" BOX_BREAK "I'll time you for " COLOR(RED) "two laps" COLOR(DEFAULT) ".\n"
"It's pretty challenging. If you\n"
"miss jumping a fence in the \n"
"proper order, you'll fail." BOX_BREAK "How about it?\n"
"Do you want to try? \n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Let's go\n"
"Don't do it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Well, your time was " COLOR(RED)  RACE_TIME  COLOR(DEFAULT) ".\n"
"You have to train harder!" BOX_BREAK "Remember, you don't need to \n"
"accelerate to jump over low \n"
"fences, but you do need to go\n"
"fast to jump the high fences!"
)

DEFINE_MESSAGE(0x2005, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
NAME "...can you hear me?\n"
"It's me, Zelda..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xDF") "Moooooooooo!" BOX_BREAK "What a nice song...\n"
"It reminds me of the pasture..." BOX_BREAK "That song makes me feel so good,\n"
"I can produce a lot of milk!" EVENT
)

DEFINE_MESSAGE(0x2007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Have some of my refreshing and \n"
"nutritious milk!" EVENT
)

DEFINE_MESSAGE(0x2008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
NAME ", when you hold\n"
"this Ocarina in your hand..." BOX_BREAK_DELAYED("\x3C") "I won't be around anymore..." BOX_BREAK_DELAYED("\x3C") "I wanted to wait for you, but I\n"
"couldn't delay any longer..." BOX_BREAK_DELAYED("\x3C") "At least I could leave you the \n"
"Ocarina and " COLOR(LIGHTBLUE) "this melody" COLOR(DEFAULT) "..." FADE("\x3C")
)

DEFINE_MESSAGE(0x2009, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Now, " NAME ".\n"
"Play this melody in front of the\n"
"altar in the Temple of Time.\n"
"You must protect the Triforce!"
)

DEFINE_MESSAGE(0x200A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Wha-ha-ha-hah! Do you think \n"
"you're in disguise, Mr. Hero?" BOX_BREAK UNSKIPPABLE  SHIFT("\x57") "Oh?" BOX_BREAK UNSKIPPABLE "Is that a \"Kee...something...\"\n"
"character mask? I heard he's \n"
"very popular recently?" BOX_BREAK UNSKIPPABLE "He's my boy's favorite. That\n"
"\"Kee...something...\" mask...\n"
"If you don't mind..." TEXTID("\x20\x0B")
)

DEFINE_MESSAGE(0x200B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Will you sell it to me?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No way" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x200C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I won't give up! I have plenty of\n"
"patience. I have to for this \n"
"job!  Hah hah hah!" EVENT
)

DEFINE_MESSAGE(0x200D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Mmmm...mumble...mumble...\n"
"Huh? Yeah, I'm awake!" BOX_BREAK UNSKIPPABLE "What?" BOX_BREAK UNSKIPPABLE "Hey, it's you! Welcome!" BOX_BREAK UNSKIPPABLE "Awww... That was rough!\n"
"Malon yelled at me for a long\n"
"time!" BOX_BREAK UNSKIPPABLE "You took care of us, so I'm proud \n"
"to give you this " COLOR(RED) "milk" COLOR(DEFAULT) "! You can \n"
"keep the bottle for yourself."
)

DEFINE_MESSAGE(0x200E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The " COLOR(RED) "road is closed " COLOR(DEFAULT) "beyond this\n"
"point!\n"
"Can't you read the sign over \n"
"there?" BOX_BREAK "Eh? Oh, I see. You're just a kid,\n"
"and you can't read yet. \n"
"Ha ha hah!"
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

DEFINE_MESSAGE(0x2014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x29") "Arrrrgh!" QUICKTEXT_DISABLE " I lost her!"
)

DEFINE_MESSAGE(0x201A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x32") "You, over there! \n"
SHIFT("\x3C")  QUICKTEXT_ENABLE "Little kid!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x3A")  TEXT_SPEED("\x0A")  QUICKTEXT_ENABLE "Heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "heh" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00") "\n"
SHIFT("\x1C") "You want a piece of me?!\n"
SHIFT("\x3E") "Very funny!\n"
SHIFT("\x2A") "I like your attitude!"
)

DEFINE_MESSAGE(0x201C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x2B") "Pathetic little fool!" QUICKTEXT_DISABLE "\n"
SHIFT("\x14") "Do you realize who you are\n"
SHIFT("\x39") "dealing with?!"
)

DEFINE_MESSAGE(0x201D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x34") "I am " COLOR(RED) "Ganondorf" COLOR(DEFAULT) "!\n"
QUICKTEXT_ENABLE  SHIFT("\x0A") "And soon, I will rule the world!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x201E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2021, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey! Time's up, young man!\n"
"You only paid 10 Rupees!\n"
"You've played around long enough!" EVENT
)

DEFINE_MESSAGE(0x2026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"With this mask, I'll be just like \n"
"Dampé! \n"
"Here's my money!"
)

DEFINE_MESSAGE(0x2027, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x202E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x48\x07") "It's a 50-Rupee mask, but he paid\n"
"you a crazy amount of money for\n"
"it--more money than you can \n"
"count!" BOX_BREAK UNSKIPPABLE "Go back to the Mask Shop and \n"
"pay back just " COLOR(RED) "50 Rupees " COLOR(DEFAULT) "of this\n"
"money."
)

DEFINE_MESSAGE(0x202F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x203B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "What's up with that horse?!\n"
"Is that " COLOR(RED) "Epona" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "How did you tame that wild horse\n"
"right under my nose?!" BOX_BREAK UNSKIPPABLE "I was going to present that horse\n"
"to the great Ganondorf... But I bet\n"
"it on the race and lost! Shooot!" EVENT
)

DEFINE_MESSAGE(0x203C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x204F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh, cute ocarina!\n"
"Are you going to play this song\n"
"with that ocarina?"
)

DEFINE_MESSAGE(0x2062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "At the foot of Death Mountain\n"
"you will find my village, " COLOR(RED) "Kakariko" COLOR(DEFAULT) ".\n"
"That is where I was born and \n"
"raised." BOX_BREAK UNSKIPPABLE "You should talk to some of the\n"
"villagers there before you go up\n"
"Death Mountain."
)

DEFINE_MESSAGE(0x2063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hoo hoot!" QUICKTEXT_DISABLE "\n"
NAME "...\n"
"Look up here!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "It appears that the time has \n"
"finally come for you to start your \n"
"adventure!" BOX_BREAK UNSKIPPABLE "You will encounter many hardships\n"
"ahead... That is your fate. Don't \n"
"feel discouraged, even during the\n"
"toughest times!" TEXTID("\x20\x65")
)

DEFINE_MESSAGE(0x2065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Did you get all that?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No\n"
"Yes" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x2067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "All right then, I'll see you around!\n"
"Hoot hoot hoot ho!"
)

DEFINE_MESSAGE(0x2068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, " NAME "! This way!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "The princess is inside the castle \n"
"just ahead. Be careful not to get \n"
"caught by the guards!\n"
"Ho ho ho hoot!" EVENT
)

DEFINE_MESSAGE(0x2069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"On this ground, time flows \n"
"normally." BOX_BREAK "But time stands still while you\n"
"are in Lon Lon Ranch or in a town." BOX_BREAK "If you want time to pass normally,\n"
"you'll need to leave town." BOX_BREAK "Well, well, which way are you \n"
"going to go now?\n"
"Hoo hoo hoot!" EVENT
)

DEFINE_MESSAGE(0x206A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to hear what I said \n"
"again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x206B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hoooo. You're a smart kid.\n"
"Good luck, then. Hoo hoo."
)

DEFINE_MESSAGE(0x206C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, " NAME "! \n"
"Wait a second, friend!" BOX_BREAK "Beyond this point you'll find \n"
COLOR(RED) "Kakariko Village" COLOR(DEFAULT) ". Have you seen \n"
"the Princess of Hyrule? If not, \n"
"I suggest you go to the castle." EVENT
)

DEFINE_MESSAGE(0x206D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, " NAME "! \n"
"Look over here!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "Beyond this point you'll find\n"
COLOR(RED) "Kakariko Village" COLOR(DEFAULT) ". Watch your step!\n"
"Hoot hoo!" EVENT
)

DEFINE_MESSAGE(0x206E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", you're the only\n"
"one who can complete the quest\n"
"ahead!\n"
"You must do your best! Hoo!"
)

DEFINE_MESSAGE(0x206F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME "! Wait up, buddy!\n"
"Hoo hoo!" BOX_BREAK_DELAYED("\x28") "Head south from here to reach\n"
COLOR(RED) "Lake Hylia's " COLOR(DEFAULT) "full, rich waters." BOX_BREAK "If you go west, you'll find \n"
COLOR(RED) "Gerudo Valley" COLOR(DEFAULT) ". There's a hideout\n"
"of a gang of thieves on the other\n"
"side of the valley." BOX_BREAK "Well, you're free to go anywhere\n"
"you want!\n"
"Ho ho ho...hooo!" EVENT
)

DEFINE_MESSAGE(0x2070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "No matter how hard it is, just\n"
"don't get discouraged. Ho Ho Hoo!"
)

DEFINE_MESSAGE(0x2071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "OK, be careful and go!"
)

DEFINE_MESSAGE(0x2073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "What is your name?" EVENT
)

DEFINE_MESSAGE(0x2074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE  COLOR(ADJUSTABLE)  NAME  COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Strange...it sounds somehow... \n"
"familiar." EVENT
)

DEFINE_MESSAGE(0x2075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "OK then, " NAME "..." BOX_BREAK UNSKIPPABLE "I'm going to tell you the secret of\n"
"the Sacred Realm that has been\n"
"passed down by the Royal Family\n"
"of Hyrule." EVENT
)

DEFINE_MESSAGE(0x2076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x26") "The Ocarina of Time!" EVENT
)

DEFINE_MESSAGE(0x2077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x2079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x01") "........" TEXT_SPEED("\x00") "Yes." BOX_BREAK UNSKIPPABLE "I told my father about my dream..." BOX_BREAK UNSKIPPABLE "However, he didn't believe it was\n"
"a prophecy..." BOX_BREAK UNSKIPPABLE "But...I can sense that man's evil\n"
"intentions!" EVENT
)

DEFINE_MESSAGE(0x207A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "What Ganondorf is after must be \n"
"nothing less than the " COLOR(RED) "Triforce \n"
COLOR(DEFAULT) "of the Sacred Realm." BOX_BREAK UNSKIPPABLE "He must have come to Hyrule to\n"
"obtain it!" BOX_BREAK UNSKIPPABLE "And, he wants to conquer Hyrule...\n"
"no, the entire world!" EVENT
)

DEFINE_MESSAGE(0x207B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3000, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You don't know what he means by\n"
"\"Sworn Brothers,\" but you've \n"
"collected two Spiritual Stones!\n"
"You have one more to find!"
)

DEFINE_MESSAGE(0x3001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You don't know what he means by\n"
"\"Sworn Brothers,\" but you've \n"
"finally collected all three Stones!\n"
"Go back to see Princess Zelda!"
)

DEFINE_MESSAGE(0x3002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I maaaade thissss...\n"
"Trrrrade for " COLOR(RED) "claimmm checkkk" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x3003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I giiiive thissss to yoooou forrr\n"
"a souvenirrrrr."
)

DEFINE_MESSAGE(0x3004, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Kid, I like you!" BOX_BREAK UNSKIPPABLE "How's about you and I become\n"
"Sworn Brothers?!" BOX_BREAK UNSKIPPABLE "No, there's no big ceremony\n"
"involved! Just take this as a\n"
"token of our friendship!"
)

DEFINE_MESSAGE(0x3005, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x30") "You did great!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"How 'bout a big Goron hug, \n"
"Brother?!" FADE("\x1E")
)

DEFINE_MESSAGE(0x3007, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x300F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I sealed the entrance because I\n"
"don't have much merchandise to\n"
"sell. But you're quite a persistent\n"
"customer, aren't you." EVENT
)

DEFINE_MESSAGE(0x3010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x301C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x301F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"No matter how many times I hear \n"
"that song, it doesn't get old!"
)

DEFINE_MESSAGE(0x3020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x302D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x302E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x303C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Thank you, Brother!\n"
"I really appreciate what you\n"
"did. I thank you on behalf of\n"
"the entire Goron race!" BOX_BREAK UNSKIPPABLE "You turned out to be a real man,\n"
"just as I thought you would!"
)

DEFINE_MESSAGE(0x303D, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
SHIFT("\x36") "Don't forget...\n"
SHIFT("\x03") "Now you and I are true Brothers!" FADE("\x50")
)

DEFINE_MESSAGE(0x303E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x303F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...See you again..."
)

DEFINE_MESSAGE(0x3040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Thank you very much for\n"
"saving us!" PERSISTENT
)

DEFINE_MESSAGE(0x3045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "By the way, I, the wild Darunia,\n"
"turned out to be the great \n"
COLOR(RED) "Sage of Fire" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Isn't that funny, Brother?\n"
"Well, this must be what they call\n"
"destiny." BOX_BREAK UNSKIPPABLE "Nothing has made me happier\n"
"than helping you seal the evil\n"
"here!"
)

DEFINE_MESSAGE(0x3046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, Brother, take this!\n"
"This is a " COLOR(RED) "Medallion " COLOR(DEFAULT) "that contains\n"
"the power of the fire spirits--and\n"
"my friendship."
)

DEFINE_MESSAGE(0x3047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Big problem!\n"
"Everybody is gone!\n"
"But I'll keep my business open!" PERSISTENT
)

DEFINE_MESSAGE(0x3048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"My Brotherrrr...\n"
"Opened a new storrrre...\n"
"It's Medigoron's Blade\n"
"Storrrrrrrre..." BOX_BREAK "Howeverrrrr... \n"
"I am betterrrrrr at making\n"
"bladessssss." BOX_BREAK "Hylian carpenterrrrrs praise\n"
"me forrrrrr my skillssssss.\n"
"I'm not lyinnnnng..."
)

DEFINE_MESSAGE(0x3054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "That broken knife is surely my \n"
"worrrrrrrrrrk...\n"
"I really want to repairrrrr it, but..." BOX_BREAK UNSKIPPABLE "But because of yesterrrrrday's\n"
"errrrruption, my eyes are \n"
"irrrrrrrritated..." BOX_BREAK UNSKIPPABLE "There are fine eyedrops in Zora's\n"
"Domain... You will find them if you\n"
"go to see " COLOR(RED) "Kinnnnnng Zorrrrrra" COLOR(DEFAULT) "..." TEXTID("\x30\x55")
)

DEFINE_MESSAGE(0x3055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Please go get the eyedrrrrrrops...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x3056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Awww nooooo... I'm finished...\n"
"My eyes arrrrrre so itchy...\n"
"Owwwwww..."
)

DEFINE_MESSAGE(0x3057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, no! Everybody's gone!\n"
"Only I was left behind!" EVENT
)

DEFINE_MESSAGE(0x3058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I've been waiting forrrrr you,\n"
"with tearrrrrrs in my eyes...\n"
"Please say hello to Kinnng Zorrra!"
)

DEFINE_MESSAGE(0x3059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Rrrrreally? You brrrrought the eye\n"
"drops? I'm so rrrrrelieved!  I'm\n"
"going to use them rrrrrright now!" EVENT
)

DEFINE_MESSAGE(0x305A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(RED) "Wowwwwwwwwwwwwww!!" COLOR(DEFAULT)  BOX_BREAK UNSKIPPABLE "This is stimulating! It's\n"
"worrrrrking grrrrreat!" BOX_BREAK UNSKIPPABLE "Now I can get back to my blade\n"
"business! My worrrrrk is not \n"
"verrrry consistent, so I'll give this \n"
"to you so you won't forrrrrget." TEXTID("\x30\x5C")
)

DEFINE_MESSAGE(0x305B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Everybody has come back!\n"
"It's business as usual!" EVENT
)

DEFINE_MESSAGE(0x305C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Afterrrr a few days...\n"
"Please returrrrrrn...\n"
"Wait, just wait patiently..."
)

DEFINE_MESSAGE(0x305D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Not yet...\n"
"Hey you...\n"
"You arrrre impatient..."
)

DEFINE_MESSAGE(0x305E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"That sworrrrd is my finest \n"
"worrrrk!"
)

DEFINE_MESSAGE(0x305F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Your " COLOR(DEFAULT) "shield " COLOR(LIGHTBLUE) "is gone!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "The " COLOR(DEFAULT) "tunic " COLOR(LIGHTBLUE) "you were wearing is \n"
"gone!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x3061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x3066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Look! A " COLOR(DEFAULT) "chicken " COLOR(LIGHTBLUE) "hatched from\n"
"the " COLOR(DEFAULT) "egg " COLOR(LIGHTBLUE) "you were incubating!\n"
"It's the miracle of life!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x63")
)

DEFINE_MESSAGE(0x3067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did you get the red stone?\n"
"Let me get one little lick!" BOX_BREAK "No? Booooo!"
)

DEFINE_MESSAGE(0x3068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x4002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "!\n"
"This way!  Hoo hoo!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE "I wonder what " COLOR(RED) "Saria" COLOR(DEFAULT) " is doing now?\n"
"How about going back to the\n"
"forest sometime?"
)

DEFINE_MESSAGE(0x4003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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
UNSKIPPABLE "Zora's Fountain is the \n"
"source of the river.\n"
COLOR(RED) "Lord Jabu-Jabu " COLOR(DEFAULT) "lives in the \n"
"fountain." TEXTID("\x40\x09")
)

DEFINE_MESSAGE(0x4009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Lord Jabu-Jabu is the patron deity\n"
"of the Zoras. " COLOR(RED) "Princess Ruto" COLOR(DEFAULT) " is in \n"
"charge of preparing his meals, \n"
"morning and night."
)

DEFINE_MESSAGE(0x400A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"We Zoras all serve the great \n"
COLOR(RED) "King Zora" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"The great King Zora should be in\n"
"the " COLOR(RED) "Royal Chamber" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x400C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Have you seen Lord Jabu-Jabu?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x400D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"According to the \"Legend of Zora,\"\n"
"the act of offering a " COLOR(RED) "fish" COLOR(DEFAULT) " to Lord \n"
"Jabu-Jabu will make you happy."
)

DEFINE_MESSAGE(0x400E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, that's not good." BOX_BREAK "Everybody who comes around here \n"
"should see " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) " at \n"
"least once!" BOX_BREAK "Zora's Fountain is just beyond \n"
"King Zora's throne. That is where\n"
"Lord Jabu-Jabu swims. But..." BOX_BREAK "unless you have King Zora's\n"
"permission, you can't go to \n"
"Zora's Fountain."
)

DEFINE_MESSAGE(0x400F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "We haven't found " COLOR(RED) "Princess Ruto\n"
COLOR(DEFAULT) "even though some of us have \n"
"searched as far as " COLOR(BLUE) "Lake Hylia" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x4010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you find any clues to\n"
COLOR(RED) "Princess Ruto's " COLOR(DEFAULT) "whereabouts,\n"
"will you show them to King Zora?"
)

DEFINE_MESSAGE(0x4011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"All of the water in Hyrule flows\n"
"from " COLOR(BLUE) "Zora's Fountain" COLOR(DEFAULT) "." BOX_BREAK "That water flows through Zora's\n"
"River, which eventually reaches\n"
COLOR(BLUE) "Lake Hylia " COLOR(DEFAULT) "to the south."
)

DEFINE_MESSAGE(0x4012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh--I've come back to life!" BOX_BREAK UNSKIPPABLE "Was it you who saved me?\n"
"Don't be nervous!" BOX_BREAK UNSKIPPABLE "It looks like you have a hard time\n"
"breathing underwater." BOX_BREAK UNSKIPPABLE "As an expression of my gratitude,\n"
"I grant you this " COLOR(RED) "tunic" COLOR(DEFAULT) ". With this,\n"
"you won't choke underwater."
)

DEFINE_MESSAGE(0x4013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Princess Ruto has gone to Lake \n"
"Hylia and has not come back...\n"
"I'm so worried...again!"
)

DEFINE_MESSAGE(0x4014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ooh...\n"
"This is... well... hmmm...\n"
"Hmmm... " COLOR(RED) "Eye drops" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "You might say we have them,\n"
"you might say we don't...\n"
"We do have the ingredients." BOX_BREAK UNSKIPPABLE "If you take the " COLOR(RED) "ingredients " COLOR(DEFAULT) "to the\n"
"doctor at the lake laboratory, he\n"
"can make the drops for you." BOX_BREAK UNSKIPPABLE "But you need to deliver them\n"
"fresh..." TEXTID("\x40\x15")
)

DEFINE_MESSAGE(0x4015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Can you make it " COLOR(RED) "before they\n"
"spoil" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Then you think they'll spoil \n"
"before you can get there?\n"
"It's not that far if you make the \n"
"connection on horseback..."
)

DEFINE_MESSAGE(0x4017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hoot hoot!" BOX_BREAK_DELAYED("\x28")  UNSKIPPABLE  NAME ", you look like \n"
"you're getting more comfortable\n"
"in your role as adventurer." BOX_BREAK UNSKIPPABLE "I think Princess Zelda is \n"
"waiting for you to visit her again." BOX_BREAK UNSKIPPABLE "You already have the " COLOR(RED) "Goron's Ruby" COLOR(DEFAULT) "," COLOR(RED) "\n"
COLOR(DEFAULT) "don't you?"
)

DEFINE_MESSAGE(0x4018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hello there, son. I'm researching \n"
"the process of making medicine by \n"
"mixing Lake Hylia's water with \n"
"various unusual compounds." BOX_BREAK "Perhaps you've met that old lady \n"
"from the potion shop...she is like \n"
"a student of mine...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x4019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Oh, wow!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "I haven't seen an " COLOR(RED) "Eyeball Frog" COLOR(DEFAULT) " \n"
"like this since Zora's Domain froze\n"
"over!" EVENT
)

DEFINE_MESSAGE(0x401A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, my dear, sweet " COLOR(RED) "Princess Ruto" COLOR(DEFAULT) "...\n"
"Where has she gone?\n"
"I'm so worried..."
)

DEFINE_MESSAGE(0x401B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ho, this letter! \n"
"It's from " COLOR(RED) "Princess Ruto" COLOR(DEFAULT) "!!" BOX_BREAK UNSKIPPABLE "Hmmm...Let's see...\n"
"She's inside Lord Jabu-Jabu?\n"
"That's not possible!" BOX_BREAK UNSKIPPABLE "Our guardian god, " COLOR(RED) "Lord Jabu-Jabu" COLOR(DEFAULT) ",\n"
"would never eat my dear Princess\n"
"Ruto!" BOX_BREAK UNSKIPPABLE "But since that stranger, " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ",\n"
"came here, Lord Jabu-Jabu has \n"
"been a little green around the\n"
"gills..." BOX_BREAK UNSKIPPABLE "The evidence seems clear.\n"
"Of course, you'll go find Ruto.\n"
"You can pass through here to the \n"
"altar of Lord Jabu-Jabu." BOX_BREAK UNSKIPPABLE "I'll keep this letter. You keep the \n"
COLOR(RED) "bottle " COLOR(DEFAULT) "it was in. Take it \n"
"respectfully!" TEXTID("\x40\x1C")
)

DEFINE_MESSAGE(0x401C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Please find my dear " COLOR(RED) "Princess Ruto" COLOR(DEFAULT) "\n"
"immediately... Zora!"
)

DEFINE_MESSAGE(0x401D, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "You can't breathe underwater!\n"
"If you start choking, take off\n"
"those " COLOR(DEFAULT) "boots" COLOR(LIGHTBLUE) "!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x401E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x36") "Ooooh Noooooo!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x401F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ohhh, I'm revived...\n"
"Was it you who saved me?\n"
"Don't be so nervous!" BOX_BREAK UNSKIPPABLE "I will give you a " COLOR(BLUE) "Zora Tunic " COLOR(DEFAULT) "as\n"
"a token of my thanks. If you have\n"
"this, you can... What?!" BOX_BREAK UNSKIPPABLE "You already have one? You're \n"
"ready for anything, aren't you!" BOX_BREAK UNSKIPPABLE "With my heartfelt thanks...how \n"
"about a KISS?! What? You don't \n"
"want it?! Oh well..." BOX_BREAK UNSKIPPABLE "If you don't want my rewards, you\n"
"can listen to my troubles..." TEXTID("\x40\x13")
)

DEFINE_MESSAGE(0x4020, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I am a " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Have you seen a \n"
"pretty Zora girl around here?"
)

DEFINE_MESSAGE(0x4021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I am a " COLOR(BLUE) "Zora" COLOR(DEFAULT) ". Have you seen\n"
"anything strange in the lake?\n"
"The river carries many things \n"
"into this lake!"
)

DEFINE_MESSAGE(0x4022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You..." QUICKTEXT_ENABLE "You're late!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "What took you so long?" QUICKTEXT_DISABLE "\n"
"You're " QUICKTEXT_ENABLE "useless!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "I was just lonely, that's all...\n"
"Just a little!!"
)

DEFINE_MESSAGE(0x4023, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "I was scared..." QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "A little!" QUICKTEXT_DISABLE " Just a little!!"
)

DEFINE_MESSAGE(0x4024, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "!\n"
NAME "!"
)

DEFINE_MESSAGE(0x4025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "You!" QUICKTEXT_DISABLE "\n"
"You looked cool...cooler than I \n"
"thought you would, anyway... \n"
QUICKTEXT_ENABLE "Just a little!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Well, anyway, you saved me, so I \n"
"guess I'll reward you." BOX_BREAK UNSKIPPABLE "What do you wish? Just tell me...\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "I want that Spiritual Stone.\n"
"Nothing really..." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You mean the Spiritual Stone of\n"
"Water, " COLOR(BLUE) "Zora's Sapphire" COLOR(DEFAULT) ", don't you?" TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x4027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "My mother gave it to me and said \n"
"I should give it only to the man \n"
"who will be my husband. You might\n"
"call it the Zora's Engagement Ring!" BOX_BREAK UNSKIPPABLE  SHIFT("\x45")  QUICKTEXT_ENABLE "All right!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "I'll give you my most precious\n"
"possession: \n"
"Zora's Sapphire!"
)

DEFINE_MESSAGE(0x4028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
"Don't tell my father..."
)

DEFINE_MESSAGE(0x4029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Heeheehee... Don't be shy." BOX_BREAK UNSKIPPABLE "I can tell what you're thinking..." TEXTID("\x40\x27")
)

DEFINE_MESSAGE(0x402A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I want to buy a fish, but they are\n"
"a little too expensive..." BOX_BREAK "I have no choice but to catch one\n"
"of the fishes that's swimming\n"
"around out there."
)

DEFINE_MESSAGE(0x402B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, " NAME "!\n"
"So, you saved the Princess, eh?\n"
"I really appreciate it!"
)

DEFINE_MESSAGE(0x402C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did my most precious possession\n"
"help you in your quest? Heehee!"
)

DEFINE_MESSAGE(0x402D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, hi " NAME "!\n"
"You're all Princess Ruto will talk\n"
"about lately!"
)

DEFINE_MESSAGE(0x402E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, it's you, " NAME "!\n"
"Thanks to you, Lord Jabu-Jabu is\n"
"back to normal!"
)

DEFINE_MESSAGE(0x402F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "We Zoras all respect the great\n"
"King Zora! He has the dignity of\n"
"a king. Oh yeah, he does." BOX_BREAK UNSKIPPABLE "The grand King Zora has a \n"
"Princess named " COLOR(RED) "Ruto" COLOR(DEFAULT) ". She's an\n"
"only child." BOX_BREAK UNSKIPPABLE "She's also a wild tomboy, and it\n"
"seems like she's always causing\n"
"the King a lot of trouble!" TEXTID("\x40\x0B")
)

DEFINE_MESSAGE(0x4030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Here it is." BOX_BREAK UNSKIPPABLE "This medicine doesn't have any\n"
"preservatives in it. So it " COLOR(RED) "won't \n"
"last long " COLOR(DEFAULT) "at this temperature." BOX_BREAK UNSKIPPABLE "Run as fast as you can to \n"
"Death Mountain. You're young--\n"
"you can do it!"
)

DEFINE_MESSAGE(0x4031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hoo hoo! Looks like you've gotten\n"
"bigger and stronger already,\n"
NAME "!" BOX_BREAK UNSKIPPABLE "Just ahead lies " COLOR(BLUE) "Zora's Domain" COLOR(DEFAULT) ". \n"
"The Zoras serve Hyrule's Royal \n"
"Family by protecting this water \n"
"source." BOX_BREAK UNSKIPPABLE "Their door will not open for \n"
"anyone except those who have\n"
"some connection with the Royal \n"
"Family." BOX_BREAK UNSKIPPABLE "Let them hear the " COLOR(RED) "melody of the \n"
"Royal Family" COLOR(DEFAULT) "!\n"
"Hooo hoo hoooot!"
)

DEFINE_MESSAGE(0x4032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"When you come back next time, \n"
"don't forget to bring me a \n"
"souvenir!"
)

DEFINE_MESSAGE(0x4033, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You found Princess Ruto!\n"
"Now King Zora will give you the \n"
COLOR(BLUE) "Spiritual Stone of Water" COLOR(DEFAULT) "...\n"
"Well, maybe." BOX_BREAK UNSKIPPABLE "Huh?"
)

DEFINE_MESSAGE(0x4034, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Her most precious possession?\n"
"You don't know what she's talking\n"
"about, but you've collected two \n"
"Spiritual Stones! Only one to go!"
)

DEFINE_MESSAGE(0x4035, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Her most precious possession?\n"
"You don't know what she's talking\n"
"about, but you've finally collected\n"
"all three Spiritual Stones!!" BOX_BREAK UNSKIPPABLE "Go back to see Princess Zelda!"
)

DEFINE_MESSAGE(0x4036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "We meet again, " NAME "..."
)

DEFINE_MESSAGE(0x4037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "This ice is created by an evil\n"
"curse... The monster in the " COLOR(BLUE) "Water\n"
"Temple " COLOR(DEFAULT) "is the source of the curse." BOX_BREAK UNSKIPPABLE "Unless you shut off the source, \n"
"this ice will never melt...." BOX_BREAK UNSKIPPABLE "If you have courage enough to \n"
"confront the danger and save \n"
"the Zoras, I will teach you the \n"
"melody that leads to the temple."
)

DEFINE_MESSAGE(0x4038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Time passes, people move....\n"
"Like a river's flow, it never ends..." BOX_BREAK UNSKIPPABLE "A childish mind will turn to\n"
"noble ambition... Young love will\n"
"become deep affection... The clear \n"
"water's surface reflects growth..." BOX_BREAK UNSKIPPABLE "Now listen to the " COLOR(BLUE) "Serenade of \n"
"Water" COLOR(DEFAULT) " to reflect upon yourself...."
)

DEFINE_MESSAGE(0x4039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "If you came here to meet the \n"
"Zoras, you wasted your time...\n"
"This is all there is..." BOX_BREAK UNSKIPPABLE "With one exception, the Zoras \n"
"are now sealed under this thick \n"
"ice sheet..." BOX_BREAK UNSKIPPABLE "I managed to rescue the Zora\n"
"princess from under the ice, but... \n"
"she left to head for the " COLOR(BLUE) "Water \n"
"Temple" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x403A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you want to buy fish, you need\n"
"a container to put them in." EVENT
)

DEFINE_MESSAGE(0x403B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"You say you want to buy a " COLOR(BLUE) "Zora\n"
"Tunic" COLOR(DEFAULT) "? That tunic is made of the\n"
"finest material, and is therefore\n"
"exceedingly expensive!" BOX_BREAK "In fact, I'm afraid only that " COLOR(RED) "very\n"
"rich family in Kakariko Village " COLOR(DEFAULT) "can\n"
"afford this fine garment..." EVENT
)

DEFINE_MESSAGE(0x403C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403C"
)

DEFINE_MESSAGE(0x403D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"403D"
)

DEFINE_MESSAGE(0x403E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh...you... If I'm right...\n"
NAME "?!" BOX_BREAK UNSKIPPABLE "You're " NAME ", aren't\n"
"you?" BOX_BREAK UNSKIPPABLE "It's me, your fiancée, " COLOR(BLUE) "Ruto" COLOR(DEFAULT) "!\n"
"Princess of the Zoras!" BOX_BREAK UNSKIPPABLE "I never forgot the vows we\n"
"made to each other seven years \n"
"ago!" BOX_BREAK UNSKIPPABLE "You're a terrible man to have \n"
"kept me waiting for these seven\n"
"long years..." BOX_BREAK UNSKIPPABLE "But now is not the time to talk \n"
"about love..." BOX_BREAK UNSKIPPABLE "I'm sure you've already seen it!\n"
"Zora's Domain--totally frozen!" BOX_BREAK UNSKIPPABLE "A young man named " COLOR(RED) "Sheik" COLOR(DEFAULT) " saved \n"
"me from under the ice..." BOX_BREAK UNSKIPPABLE "But my father and the other \n"
"Zoras have not" TEXT_SPEED("\x02") "...yet..." TEXT_SPEED("\x00")  BOX_BREAK UNSKIPPABLE "I want to save them all!\n"
"I want to save Zora's Domain!" BOX_BREAK UNSKIPPABLE "You! You have to help me!\n"
"This is a request from me, the\n"
"woman who is going to be your\n"
"wife!" BOX_BREAK UNSKIPPABLE  NAME ", you have to \n"
"help me destroy the evil monster\n"
"in the Temple, OK?!" BOX_BREAK UNSKIPPABLE "Inside the Water Temple, there are \n"
COLOR(RED) "three places" COLOR(DEFAULT) " where you can \n"
"change the water level." BOX_BREAK UNSKIPPABLE "I'll lead the way.\n"
"Follow me, quickly!!"
)

DEFINE_MESSAGE(0x403F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  NAME "! Look out!\n"
"That isn't normal water over \n"
"there!"
)

DEFINE_MESSAGE(0x4040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4040"
)

DEFINE_MESSAGE(0x4041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "..." BOX_BREAK UNSKIPPABLE "I would have expected no less\n"
"from the man I chose to be my\n"
"husband." BOX_BREAK UNSKIPPABLE "Zora's Domain and its people\n"
"will eventually return to their\n"
"original state."
)

DEFINE_MESSAGE(0x4042, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "If you see Sheik, \n"
"please give him my thanks, OK?" FADE("\x5A")
)

DEFINE_MESSAGE(0x4043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Did Ruto want to thank me?" BOX_BREAK UNSKIPPABLE "I see...." BOX_BREAK UNSKIPPABLE "We have to return peace to \n"
"Hyrule for her sake, too. \n"
"Don't we?"
)

DEFINE_MESSAGE(0x4044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"4044"
)

DEFINE_MESSAGE(0x4045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ah, I see...\n"
"Princess Ruto went to the Water\n"
"Temple..."
)

DEFINE_MESSAGE(0x4046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As a reward...\n"
"I grant my eternal love to you." BOX_BREAK UNSKIPPABLE "Well, that's what I want to say, \n"
"but I don't think I can offer that\n"
"now."
)

DEFINE_MESSAGE(0x4047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Princess Zelda... She's alive. I can\n"
"sense it...so don't be discouraged."
)

DEFINE_MESSAGE(0x4048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Keeeyaaaah!\n"
SHIFT("\x0F") "What is this?! An octopus?!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x4049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I have to guard the Water \n"
"Temple as the " COLOR(BLUE) "Sage of Water" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "And you... You're searching for the\n"
"princess, " COLOR(RED) "Zelda" COLOR(DEFAULT) "?" BOX_BREAK UNSKIPPABLE "Hah!\n"
"You can't hide anything from me!"
)

DEFINE_MESSAGE(0x404A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I can tell that nothing will stop\n"
"you in your quest for justice and \n"
"peace... You must take this \n"
COLOR(BLUE) "Medallion" COLOR(DEFAULT) "... Take it respectfully!"
)

DEFINE_MESSAGE(0x404B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You! Who are you?!" BOX_BREAK UNSKIPPABLE "I am " COLOR(RED) "Ruto" COLOR(DEFAULT) ", Princess of the Zoras." BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "What?!" QUICKTEXT_DISABLE "\n"
"Are you saying my father asked \n"
"you to come here to save me?" BOX_BREAK UNSKIPPABLE "I'd " QUICKTEXT_ENABLE "never" QUICKTEXT_DISABLE " ask anyone to do such a\n"
"thing!" BOX_BREAK UNSKIPPABLE "\"Letter in a Bottle?\"  I have\n"
QUICKTEXT_ENABLE "no idea" QUICKTEXT_DISABLE " what you're talking about!" BOX_BREAK UNSKIPPABLE "My father is worried about me?" BOX_BREAK UNSKIPPABLE "I don't " QUICKTEXT_ENABLE "care!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Anyway, I can't go home right now.\n"
"And you... " QUICKTEXT_ENABLE "Get out of here!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Understand?!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x404C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Are you still hanging around here?\n"
"I told you to go away!" BOX_BREAK UNSKIPPABLE "I'm OK. I've been going inside\n"
"Lord Jabu-Jabu's belly since I was\n"
"little, but..." BOX_BREAK UNSKIPPABLE "Lord Jabu-Jabu is very strange \n"
"today..." BOX_BREAK UNSKIPPABLE "There are electrified jellyfish and\n"
"strange holes around..." BOX_BREAK UNSKIPPABLE "On top of that, my precious stone \n"
"was...but...\n"
QUICKTEXT_ENABLE "That's none of your business!" QUICKTEXT_DISABLE "\n"
"Anyway..." BOX_BREAK UNSKIPPABLE "You! " QUICKTEXT_ENABLE "Go home now!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "Understand?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x404D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You're that worried about me?" BOX_BREAK UNSKIPPABLE "Then I will give you the honor\n"
"of carrying me!" BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE "However" QUICKTEXT_DISABLE "...I won't leave until I \n"
"find the thing I'm looking for.\n"
"You'd better believe me!" EVENT
)

DEFINE_MESSAGE(0x404E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "How inconsiderate!" QUICKTEXT_DISABLE "\n"
"How could you leave me behind?! \n"
"If you're a man, act like one! \n"
"Take responsibility!" EVENT
)

DEFINE_MESSAGE(0x404F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "That's it!" QUICKTEXT_DISABLE "\n"
"That's what I've been looking for!\n"
"Throw me up there! \n"
"Onto the platform!"
)

DEFINE_MESSAGE(0x4050, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Princess Ruto got the \n"
COLOR(BLUE) "Spiritual Stone" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02") "But" TEXT_SPEED("\x00") " why Princess Ruto?"
)

DEFINE_MESSAGE(0x4051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh my goodness!\n"
"I finally found... \n"
"My mother's stone..." BOX_BREAK UNSKIPPABLE "I got very upset when Lord Jabu-\n"
"Jabu swallowed it..." BOX_BREAK UNSKIPPABLE "While I was feeding him, he\n"
"suddenly swallowed me! I was \n"
"so surprised I dropped it inside..." BOX_BREAK UNSKIPPABLE "But, now that I've found it, \n"
"I don't need to be in here \n"
"anymore!"
)

DEFINE_MESSAGE(0x4052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"So, take me home, right now!"
)

DEFINE_MESSAGE(0x4053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Diving Game   20 Rupees\n"
"Want to play?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "OKAY!" QUICKTEXT_DISABLE  BOX_BREAK "Pick up all the Rupees I throw \n"
"from here. You have only a limited\n"
"amount of time!" BOX_BREAK "When you pick them all up, \n"
"come back here! I'll give you\n"
"something very nice!" EVENT
)

DEFINE_MESSAGE(0x4055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hey!  Congratulations!" QUICKTEXT_DISABLE "\n"
"I've got something \n"
"very nice for you!\n"
"Come and get it!" EVENT
)

DEFINE_MESSAGE(0x4056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "What a graceful dive!\n"
"Now, please take this!" BOX_BREAK UNSKIPPABLE "This is a \"" COLOR(RED) "scale" COLOR(DEFAULT) "\" of our kind.\n"
"With this, you can dive much\n"
"deeper under the water." EVENT
)

DEFINE_MESSAGE(0x4057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As the water rises, the evil \n"
"is vanishing from the lake...\n"
NAME ", you did it!"
)

DEFINE_MESSAGE(0x4058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I...believe that you are going to \n"
"save this world..."
)

DEFINE_MESSAGE(0x4059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Look at that, " NAME "..." BOX_BREAK UNSKIPPABLE "Together, you and Princess Ruto \n"
"destroyed the evil monster!" BOX_BREAK UNSKIPPABLE "Once again, the lake is filled with\n"
"pure water. All is as it was here."
)

DEFINE_MESSAGE(0x405A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x51")  COLOR(RED) "START!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Go over the falls for a shortcut." EVENT
)

DEFINE_MESSAGE(0x405C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Take as much as you want for \n"
"20 Rupees.  Want to play?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Hey!  Congratulations!!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x405E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"How about some " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"They aren't selling very well..." BOX_BREAK "How about...\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " for one piece?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x405F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"How about some " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"Well, they're not that popular yet." BOX_BREAK "How about...\n"
COLOR(RED) "20 Rupees" COLOR(DEFAULT) " for one piece?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"How about some " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"They are getting to be quite \n"
"popular..." BOX_BREAK COLOR(RED) "30 Rupees" COLOR(DEFAULT) " for one piece.\n"
"How about it?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"How about some " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?\n"
"They're all the rage!" BOX_BREAK COLOR(RED) "40 Rupees" COLOR(DEFAULT) " for one piece.\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"We have the popular " COLOR(RED) "Magic Beans" COLOR(DEFAULT) "!\n"
"You'll regret it if you don't buy \n"
"them now!" BOX_BREAK COLOR(RED) "50 Rupees" COLOR(DEFAULT) " for one piece.\n"
"(Just for now.)\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"These are the super-popular \n"
COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! In case you're \n"
"wondering, they'll soon be sold out!" BOX_BREAK "Super price!\n"
COLOR(RED) "60 Rupees" COLOR(DEFAULT) " for one piece!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"We have the super-rare \n"
COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! This could be your\n"
"last chance!" BOX_BREAK "Special price!\n"
COLOR(RED) "70 Rupees" COLOR(DEFAULT) " for one piece!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"We have the legendary \n"
COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! I'll sell them only \n"
"to you!" BOX_BREAK "Super price!\n"
COLOR(RED) "80 Rupees" COLOR(DEFAULT) " for one piece!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"Do you want..." COLOR(RED) "Magic Beans" COLOR(DEFAULT) "?! \n"
"They aren't cheap, but...do you\n"
"still want them?" BOX_BREAK "I can't let them go for less than\n"
COLOR(RED) "90 Rupees" COLOR(DEFAULT) " apiece!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Chomp chomp chomp...\n"
"We have..." COLOR(RED) "Magic Beans" COLOR(DEFAULT) "! \n"
"Do you want them...huh? Huh?" BOX_BREAK COLOR(RED) "100 Rupees" COLOR(DEFAULT) " for one piece!\n"
"Keyahahah!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh well...\n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x4069, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You don't have enough money.\n"
"I can't sell them to you.\n"
"Chomp chomp..."
)

DEFINE_MESSAGE(0x406A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Set a bean to " COLOR(YELLOW) "[C] " COLOR(DEFAULT) "and use it on\n"
"the dirt right here."
)

DEFINE_MESSAGE(0x406B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, too bad! We're sold out!\n"
"Chomp chomp...What?\n"
"Oh, these beans are not for sale!"
)

DEFINE_MESSAGE(0x406C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"If you want to plant beans, go\n"
"around and look for soft soil.\n"
"Chomp chomp chomp."
)

DEFINE_MESSAGE(0x406D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "1 meter" COLOR(DEFAULT) " just now. But I wouldn't \n"
"call that a real dive."
)

DEFINE_MESSAGE(0x406E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "2 meters" COLOR(DEFAULT) " just now. But I wouldn't \n"
"call that a real dive."
)

DEFINE_MESSAGE(0x406F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "3 meters" COLOR(DEFAULT) " just now. But I wouldn't \n"
"call that a real dive."
)

DEFINE_MESSAGE(0x4070, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "4 meters " COLOR(DEFAULT) "just now. Still not \n"
"deep enough!"
)

DEFINE_MESSAGE(0x4071, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "5 meters " COLOR(DEFAULT) "just now. Still not \n"
"deep enough!"
)

DEFINE_MESSAGE(0x4072, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "6 meters" COLOR(DEFAULT) " just now. You should be\n"
"able to dive deeper!"
)

DEFINE_MESSAGE(0x4073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You may not have noticed, but I've\n"
"been watching you. You dove \n"
COLOR(RED) "7 meters" COLOR(DEFAULT) " just now. You should be\n"
"able to dive deeper!"
)

DEFINE_MESSAGE(0x4074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "You may not have noticed, but I've\n"
"been watching you. You " COLOR(RED) "touched \n"
"the bottom " COLOR(DEFAULT) "just now.  Fantastic!\n"
"I'll give this to you!"
)

DEFINE_MESSAGE(0x4075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Your diving is the best in the \n"
"world. Why don't you dive to the \n"
"bottom of Lake Hylia?"
)

DEFINE_MESSAGE(0x4076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"My name is " COLOR(RED) "Pierre" COLOR(DEFAULT) ", the wandering\n"
"scarecrow. Actually, I wish I could\n"
"wander to look for soul-moving\n"
"sounds, but I'm kind of stuck here."
)

DEFINE_MESSAGE(0x4077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Fantastic tune! It touches my \n"
"heart!" EVENT
)

DEFINE_MESSAGE(0x4078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you come up with a nice song,\n"
"come back and let me hear it!" EVENT
)

DEFINE_MESSAGE(0x4079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"That song you played for me still\n"
"stays in my heart. Let's hear it\n"
"again!" EVENT
)

DEFINE_MESSAGE(0x407A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"That song you played for me \n"
"stays in my heart!" EVENT
)

DEFINE_MESSAGE(0x407B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, do you want to go fishing \n"
"for " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x407C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, no! You don't have a " COLOR(RED) "Rumble \n"
"Pak" COLOR(DEFAULT) "! With a Rumble Pak, you can\n"
"feel the vibrations of a fish on\n"
"your hook." BOX_BREAK "This time, no rumble for you!" EVENT
)

DEFINE_MESSAGE(0x407D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wow! You have a " COLOR(RED) "Rumble Pak" COLOR(DEFAULT) "!\n"
"Today, you can feel the vibration,\n"
"young man!" EVENT
)

DEFINE_MESSAGE(0x407E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Shucks! You don't have enough \n"
"money."
)

DEFINE_MESSAGE(0x407F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"OK, listen up!" BOX_BREAK "Walk up to the water's edge and\n"
"press " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) " to look at a fish." BOX_BREAK "While looking at a fish, you can \n"
"cast your line with " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) ". Press " COLOR(BLUE) "[A]\n"
COLOR(DEFAULT) "to brake the line." BOX_BREAK "When the lure drops into the \n"
"water, you can wiggle it with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
"If you're a novice, you can also\n"
"use " COLOR(ADJUSTABLE) "[B]" COLOR(DEFAULT) "." BOX_BREAK "Reel in your lure with " COLOR(BLUE) "[A]" COLOR(DEFAULT) ". Hold \n"
"down " COLOR(BLUE) "[A]" COLOR(DEFAULT) " and " COLOR(LIGHTBLUE) "[R] " COLOR(DEFAULT) "to reel it in \n"
"faster." BOX_BREAK "If you feel a hit, press " COLOR(BLUE) "[A]" COLOR(ADJUSTABLE) " " COLOR(DEFAULT) "and\n"
COLOR(LIGHTBLUE) "[Control-Pad] down " COLOR(DEFAULT) "to set the hook.\n"
"After that, reel it in with " COLOR(BLUE) "[A]" COLOR(DEFAULT) "." BOX_BREAK "Do you understand?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I'm so generous, I'll let you fish\n"
"for as long as you want. However,\n"
"you can keep only one fish." BOX_BREAK "The biggest fish ever caught here\n"
"weighed " COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "." BOX_BREAK "After you cast, you can change\n"
"your view with " COLOR(LIGHTBLUE) "[Z]" COLOR(DEFAULT) "." BOX_BREAK SHIFT("\x41") "Let's fish!" EVENT
)

DEFINE_MESSAGE(0x4081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wah ha haah!\n"
"Did you set the hook by pressing\n"
COLOR(BLUE) "[A]" COLOR(DEFAULT) " and " COLOR(LIGHTBLUE) "[Control-Pad] down" COLOR(DEFAULT) "?"
)

DEFINE_MESSAGE(0x4082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, what happened?\n"
"You lost it!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, well...it's about " COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) ". \n"
"Do you want to keep it?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What do you want?\n"
THREE_CHOICE  COLOR(ADJUSTABLE) "Weigh my fish.\n"
"Let's talk about something.\n"
"I want to quit." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Passion alone won't catch you \n"
"many fish. I'm serious!"
)

DEFINE_MESSAGE(0x4086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B") "WHOA!" BOX_BREAK "This fish is huge! It looks like a \n"
"new record! It weighs at least \n"
COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "! Seriously! \n"
"OK, here is your prize!" EVENT
)

DEFINE_MESSAGE(0x4087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What? \n"
"What are you doing to me?!" FADE("\x3C")
)

DEFINE_MESSAGE(0x4088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, young man! Don't you have \n"
"anything important you should be\n"
"doing?" BOX_BREAK "What? Are you saying it's more \n"
"fun to play here?" BOX_BREAK "I've seen many people ruin their\n"
"lives with that kind of attitude.\n"
"I'm serious!\n"
"Oh well..."
)

DEFINE_MESSAGE(0x4089, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "The biggest fish ever caught in\n"
"this pond weighed " FISH_INFO " pounds.\n"
"The angler: " NAME  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x408A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to continue fishing?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x408B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, it weighs " COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "...\n"
"Not bad, but there are bigger\n"
"fish in there!" EVENT
)

DEFINE_MESSAGE(0x408C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, c'mon! You don't have a fish!\n"
"Shucks!" EVENT
)

DEFINE_MESSAGE(0x408D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"You want to try another lure?\n"
"What are you talking about? Are\n"
"you so selfish?" BOX_BREAK "Don't you know the old saying,\n"
"\"A great fisherman never chooses\n"
"his own lure?\""
)

DEFINE_MESSAGE(0x408E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What? Do you want to know some \n"
"fishing secrets? I can't tell you\n"
"any. They are company secrets.\n"
"Seriously!"
)

DEFINE_MESSAGE(0x408F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What? You want to know if I'm a \n"
"good fisherman?" BOX_BREAK "Of course I am! I'm an old pro!\n"
"Do you know what a pro is?\n"
"I'm telling you the truth!"
)

DEFINE_MESSAGE(0x4090, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Rules and Regulations" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE "1. Don't use sinking lures.\n"
"2. Don't litter.\n"
"3. Walk quietly." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "4. Don't cast at anyone." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x4091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wow! This is a real lunker!\n"
"Let's see...it weighs\n"
COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "!" BOX_BREAK "Do you want to keep it?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Come back when you get older!\n"
"The fish will be bigger, too...\n"
"Well, maybe."
)

DEFINE_MESSAGE(0x4093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, mister! I remember you!\n"
"It's been a long time!" BOX_BREAK UNSKIPPABLE "How many years has it been?\n"
"Seven years?! What have you\n"
"been doing all this time?!" BOX_BREAK UNSKIPPABLE "You're my only customer. I'm \n"
"almost out of business! Seriously!\n"
"On top of that, my hair..." BOX_BREAK UNSKIPPABLE "Uh, I mean, never mind..." BOX_BREAK UNSKIPPABLE "Well, do you want to go fishing?\n"
"It costs only " COLOR(RED) "20 Rupees" COLOR(DEFAULT) "!\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What?" BOX_BREAK "You want to go fishing in a \n"
"different fishing pond?!\n"
"What are you talking about?" BOX_BREAK "I'll go out of business if you go\n"
"somewhere else!\n"
"I'm serious!"
)

DEFINE_MESSAGE(0x4095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What?" BOX_BREAK "You want to know why I'm \n"
"scratching all the time?\n"
"What are you talking about?" BOX_BREAK "Actually, I have no idea.\n"
"I'm serious!"
)

DEFINE_MESSAGE(0x4096, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What?" BOX_BREAK "Are you trying to tell me you\n"
"can't see the fish because the\n"
"water is cloudy?" BOX_BREAK "What are you talking about?\n"
"This time of day makes for \n"
"fishing at its finest!" BOX_BREAK "You can hook a fish out of the\n"
"blue, when you least expect it.\n"
"Now that's exciting!" BOX_BREAK "I'm serious.  Really, I am!"
)

DEFINE_MESSAGE(0x4097, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, what are you doing?\n"
"I told you not to do that!\n"
"You're terrible!\n"
"Seriously!" BOX_BREAK "Give me back my hat!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No way" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4098, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"What? Huh? Oh?\n"
"I think the fish you already\n"
"kept was bigger than this one..." BOX_BREAK "Do you still want to keep it?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "No, I don't want it\n"
"Yes, I want to keep it anyway" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x4099, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Gosh! That's a strange fish you\n"
"caught there! On top of that, it\n"
"weighs " COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "!" BOX_BREAK "What do you want to do with it?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Keep it anyway\n"
"I don't want it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wow!" BOX_BREAK "Is this what I think it is?\n"
"Astonishing!\n"
"You snagged a " COLOR(RED) "sinking lure" COLOR(DEFAULT) "!" BOX_BREAK "What do you want to do with it?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Use it now.\n"
"Get rid of it." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x409B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, well..." BOX_BREAK "WOW! What a rare fish!\n"
"This is a " COLOR(RED) "Hyrule Loach" COLOR(DEFAULT) "!" BOX_BREAK "For this fish, size doesn't \n"
"matter. I'll give you this \n"
"prize!" EVENT
)

DEFINE_MESSAGE(0x409C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Recently, the number of these\n"
"fish has decreased tremendously,\n"
"so I'm going to release this one." EVENT
)

DEFINE_MESSAGE(0x409D, TEXTBOX_TYPE_WOODEN, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "Rules and Regulations\n"
"1. Don't use sinking lures.\n"
"2. Don't litter.\n"
"3. Walk quietly." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x409E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey! Hey!\n"
"You can't take the rod out of\n"
"here!" BOX_BREAK "When you quit fishing, return \n"
"the rod to the counter.\n"
"I'm serious!"
)

DEFINE_MESSAGE(0x409F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh my gosh!\n"
"This fish is gigantic!!" BOX_BREAK "A fish this big can't even fit\n"
"on the screen, and I can't weigh it\n"
"accurately, but it looks like it's\n"
"about " COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "!!" BOX_BREAK "You'll want to keep this one,\n"
"right?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Keep it\n"
"Don't keep it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x40A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, baby!\n"
"I'm " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", the scarecrow!\n"
"You've probably heard about my\n"
"fantastic memory!" BOX_BREAK "If you have a new tune to play,\n"
"blow it!" BOX_BREAK "This is the song you tooted last \n"
"time, baby!" BOX_BREAK "Hit it!" EVENT
)

DEFINE_MESSAGE(0x40A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I am " COLOR(RED) "Bonooru" COLOR(DEFAULT) ", the scarecrow\n"
"musical genius!\n"
"I hear a song once, and I never\n"
"forget it, baby!"
)

DEFINE_MESSAGE(0x40A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Play the usual tune to call\n"
"Pierre!\n"
"If he's nearby, he'll come out to\n"
"help you, baby!"
)

DEFINE_MESSAGE(0x40A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey! Aren't you the fairy buddy I\n"
"met a long time ago?\n"
"Wow, you grew, dude!" BOX_BREAK "Well, here's your song..." BOX_BREAK "What?" BOX_BREAK "No, I never forget!\n"
"You, you're the one who forgot...\n"
"aren't you? If you have an \n"
"Ocarina, play that song, baby!"
)

DEFINE_MESSAGE(0x40A4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Whoa! You have an ocarina!\n"
"Hey, why don't you lay a tune\n"
"on me with it, baby?!" EVENT
)

DEFINE_MESSAGE(0x40A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well...not bad!\n"
"I will remember it for you \n"
"anyway!" BOX_BREAK "I don't mean I can remember only\n"
"eight notes, but let's just cut it\n"
"right there for now, baby!" EVENT
)

DEFINE_MESSAGE(0x40A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Play it like that and you'll\n"
"never move this scarecrow's heart,\n"
"baby!" EVENT
)

DEFINE_MESSAGE(0x40A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"OH YEAHHH!!\n"
"That's it, that's the tune!!\n"
"You rock!! I'm blown away!" BOX_BREAK "Oh, no, no! I didn't forget the\n"
"song...I never forget anything!\n"
"But I just feel like rewarding\n"
"you, baby!" BOX_BREAK "........\n"
"I have a good idea!" BOX_BREAK "My buddy Pierre is wandering\n"
"around, so play that tune when\n"
"you want to call him!" BOX_BREAK "I'll tell him to help you if he's\n"
"nearby and hears that song, baby!" EVENT
)

DEFINE_MESSAGE(0x40A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, it's the Ocarina!\n"
"Play that song with it,\n"
"baby!" EVENT
)

DEFINE_MESSAGE(0x40A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Young lad, you play the Ocarina\n"
"well... Mmmmm...! That melody is \n"
"so fine...ribbit! We all should\n"
"practice it, ribbit!" BOX_BREAK "Take Rupees as a souvenir!\n"
"If you come up with another nice \n"
"melody, please drop by and play\n"
"it...Ribbit ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Wow, that melody is so cool! \n"
"Ribbit!" BOX_BREAK "Siiiiingin' in the raaaaaain,\n"
"Oh what a feeling! \n"
"Rrrrrribbbit!!" BOX_BREAK "Please take this as a token of\n"
"our froggish gratitude, ribbit!\n"
"All right. See you, ribbit!" EVENT
)

DEFINE_MESSAGE(0x40AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE4") "Look at us, we're all huge frogs!!\n"
"We are the world famous Fabulous\n"
"Five Froggish Tenors!!\n"
"Rrrribbit!!" BOX_BREAK "Make us jump so we can eat the \n"
"bugs flying above us, ribbit!" BOX_BREAK "OK? \n"
"Then, ready, set, go!" EVENT
)

DEFINE_MESSAGE(0x40AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SFX("\x28\xE3") "Young boy, you did grrreat!\n"
"Perrrrrfect!\n"
"We are stuffed, ribbit!" BOX_BREAK "Would you take this token of our\n"
"gratitude?" EVENT
)

DEFINE_MESSAGE(0x40AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh well, I don't remember that \n"
"song, baby.\n"
"Why? That's what I can't tell ya!\n"
"Good golly!"
)

DEFINE_MESSAGE(0x40AE, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "The biggest fish ever caught in\n"
"this pond weighed " FISH_INFO " pounds.\n"
"The angler: the pond owner" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What?\n"
"Do you want to fish with a \n"
"different lure?\n"
"...Hey, what's that?" BOX_BREAK "What? You just picked it up?\n"
"Usually, the rules says you can't\n"
"use one of those. I mean, usually. \n"
"But, what the heck..."
)

DEFINE_MESSAGE(0x40B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"YAHOOOOOO!\n"
"This is HUGE!! A new record!!\n"
"This...this weighs as much as...\n"
COLOR(RED)  FISH_INFO " pounds" COLOR(DEFAULT) "!!" BOX_BREAK "Buuuuuuuut! That sinking lure is\n"
"in violation of the rules!\n"
"So, no prize for you.\n"
"Wah ha ha ha ha ha!" EVENT
)

DEFINE_MESSAGE(0x40B1, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "The biggest fish ever caught in\n"
"this pond weighed " FISH_INFO " pounds.\n"
"The angler: " NAME "\n"
"(NOTE: With illegal sinking lure.)" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x40B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're a kind-hearted kid!\n"
"But don't tell anyone about this.\n"
"Seriously!" EVENT
)

DEFINE_MESSAGE(0x40B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"WHAAAAAT?!?" BOX_BREAK "Why are you doing this to me?\n"
"What are you thinking?" BOX_BREAK "I'm not going to let you get off\n"
"that easy! You have to pay me a \n"
COLOR(RED) "50-Rupee " COLOR(DEFAULT) "fine!\n"
"Seriously!" EVENT
)

DEFINE_MESSAGE(0x5000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE "GYAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "You" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "killed" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "me!!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"Huh? Oh, it's you." BOX_BREAK "Did you try to play the \n"
COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) "?" BOX_BREAK "Like I told you before, with that \n"
"song, you can turn day to night \n"
"or night to day whenever you \n"
"want." BOX_BREAK "When you're in darkness, that \n"
"song should bring the sun's light\n"
"to you. You should try it."
)

DEFINE_MESSAGE(0x5001, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "When I dug a hole, I found a \n"
"treasure that stretches--BOING!\n"
"and shrinks--BOING! It's so fun, \n"
"I'll never give it to anybody!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5002, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
"The " COLOR(RED) "gravekeeper's diary " COLOR(DEFAULT) "is here.\n"
"Do you want to read it?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5003, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_TOP,
QUICKTEXT_ENABLE "Whoever reads this, please enter\n"
"my grave. I will let you have my\n"
"stretching, shrinking " COLOR(RED) "keepsake" COLOR(DEFAULT) "." QUICKTEXT_DISABLE  BOX_BREAK QUICKTEXT_ENABLE "I'm waiting for you.\n"
"--Dampé" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5004, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "You decide not to read it..." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5005, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You defeated Poe the ghost!" BOX_BREAK "Do you want to catch it in \n"
"a bottle?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5006, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You want to catch it but you \n"
"don't have an empty bottle."
)

DEFINE_MESSAGE(0x5007, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You let it go for now."
)

DEFINE_MESSAGE(0x5008, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
"You caught a Poe!"
)

DEFINE_MESSAGE(0x5009, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x04") "The rising sun will eventually set,\n"
SHIFT("\x19") "A newborn's life will fade." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x05") "From sun to moon, moon to sun..." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x25") "Give peaceful rest to\n"
SHIFT("\x37") "the living dead." QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "This is an interesting poem...\n"
"huh?"
)

DEFINE_MESSAGE(0x500A, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x24") "Restless souls wander\n"
SHIFT("\x1E") "where they don't belong,\n"
SHIFT("\x27") "bring them calm with\n"
SHIFT("\x36") "the " COLOR(YELLOW) "Sun's Song" COLOR(DEFAULT) "." QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x500B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Something is inscribed on the \n"
"tombstone..." BOX_BREAK UNSKIPPABLE "It's the " COLOR(YELLOW) "secret melody" COLOR(DEFAULT) " of the \n"
"Composer Brothers!"
)

DEFINE_MESSAGE(0x500C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Ultimate potion! How about\n"
COLOR(RED) "100 Rupees" COLOR(DEFAULT) "?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Buy\n"
"Don't buy" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x500D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you change your mind, come \n"
"back and visit me...\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x500E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You don't have enough Rupees!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x500F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "GYAAAAH!\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "YOU" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "KILLED" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "ME..." QUICKTEXT_DISABLE  TEXT_SPEED("\x00")  QUICKTEXT_ENABLE "Unbelievable!" QUICKTEXT_DISABLE  BOX_BREAK UNSKIPPABLE "Oh, what?\n"
"You're not one of Ganondorf's \n"
"men, are you?" BOX_BREAK UNSKIPPABLE "Because of my role as a ghost, I\n"
"had to act like that. I apologize." BOX_BREAK UNSKIPPABLE "Now then, let me introduce myself.\n"
"Ahem..." TEXTID("\x50\x10")
)

DEFINE_MESSAGE(0x5010, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I am one of the ghostly composer \n"
"brothers of Kakariko Village." BOX_BREAK "All the people in this village are\n"
"born to serve the Royal Family of\n"
"Hyrule." BOX_BREAK "We brothers also served the Royal \n"
"Family, and were assigned to \n"
"study the hereditary mystic \n"
"powers of the family." BOX_BREAK "Though we never could figure out \n"
"the power of the Triforce," BOX_BREAK "we had almost completed our \n"
COLOR(RED) "study of controlling time" COLOR(DEFAULT) " with the \n"
"tones of ocarinas." BOX_BREAK "Uh, I mean..." BOX_BREAK "Actually, we did complete that \n"
"study!" BOX_BREAK "We would have been famous, if \n"
"that hateful Ganondorf had not\n"
"tried to steal our results." BOX_BREAK "We could never let him reap the \n"
"fruits of our research!" BOX_BREAK "That's why we gave our lives to \n"
"protect the secret." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you want to hear what I \n"
"said again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5012, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "I'M" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DEAD" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "A" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "GAIN!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"What? You again?" BOX_BREAK UNSKIPPABLE "Somehow, you remind me of...\n"
"Princess Zelda..." BOX_BREAK UNSKIPPABLE "Hmm... Since you may have some\n"
"connection with the Royal Family, I\n"
"will tell you a little more of our\n"
"tale." BOX_BREAK UNSKIPPABLE "Back then, people called us great\n"
"composers because of the many \n"
"musical masterpieces we wrote." BOX_BREAK UNSKIPPABLE "But we brothers were not just \n"
"composers." BOX_BREAK UNSKIPPABLE "We had a mission to analyze the\n"
"mysterious powers of Hyrule's\n"
"Royal Family." BOX_BREAK UNSKIPPABLE "Our names would be a part of \n"
"Hyrule's history if we could \n"
"complete our research!" BOX_BREAK UNSKIPPABLE "We kept our study extremely \n"
"secret until we completed it." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "GYAAAAH!" QUICKTEXT_DISABLE "\n"
TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "I'M" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "DEAD" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "A" QUICKTEXT_DISABLE  QUICKTEXT_ENABLE "GAIN!" QUICKTEXT_DISABLE  TEXT_SPEED("\x00") "\n"
"What? You again?" BOX_BREAK UNSKIPPABLE "Somehow, you remind me of\n"
"Princess Zelda." BOX_BREAK UNSKIPPABLE "Since you seem to have some\n"
"connection with the Royal Family, I\n"
"will tell you a little more of our\n"
"story." TEXTID("\x50\x14")
)

DEFINE_MESSAGE(0x5014, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"To tell the truth, each of us\n"
"was studying a different song, one\n"
"to " COLOR(RED) "summon the sun" COLOR(DEFAULT) " and another to\n"
COLOR(RED) "summon the moon" COLOR(DEFAULT) "." BOX_BREAK "If you were really sent by a \n"
"member of the Royal Family, I will\n"
"tell you about the results of our\n"
"study." BOX_BREAK "We inscribed it on the " COLOR(RED) "royal\n"
"tombstone" COLOR(DEFAULT) "." BOX_BREAK "As a messenger of the Royal \n"
"Family, you should show your\n"
"Royal credentials on top of the \n"
"Triforce mark..." TEXTID("\x50\x11")
)

DEFINE_MESSAGE(0x5015, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Z Z Z..." BOX_BREAK "Malon...doing all right...\n"
"Mumble...mumble...\n"
"Sorry to make you worry..."
)

DEFINE_MESSAGE(0x5016, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Ingo took over Lon Lon Ranch and\n"
"they call it " COLOR(RED) "Ingo Ranch " COLOR(DEFAULT) "nowadays." BOX_BREAK "I was kicked out of there, and\n"
"look at me now! My girl, Malon, \n"
"still works at the ranch..." BOX_BREAK "I'm worried about her..."
)

DEFINE_MESSAGE(0x5017, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Did you save Malon? Thanks!\n"
"I'm goin' back to the ranch, then!\n"
"Yeehah!"
)

DEFINE_MESSAGE(0x5018, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE "Hey kid!" QUICKTEXT_DISABLE "\n"
"Don't mess around with the \n"
"graves!" BOX_BREAK UNSKIPPABLE "I'm " COLOR(RED) "Dampé the Gravekeeper" COLOR(DEFAULT) "!\n"
"My face may be scary, but I'm not\n"
"a bad guy..." BOX_BREAK UNSKIPPABLE "Let me give you an advertisement\n"
"for my side business..." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Dampé the Gravekeeper's" COLOR(DEFAULT) "\n"
"Heart-Pounding" COLOR(LIGHTBLUE) " Gravedigging Tour" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "What's gonna come out?!\n"
"What's gonna come out?!\n"
"When I start digging,\n"
"we'll find out!" TEXTID("\x50\x19")
)

DEFINE_MESSAGE(0x5019, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you want me to dig here?\n"
COLOR(RED) "10 Rupees" COLOR(DEFAULT) " for one hole.\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"Don't do it" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(RED) "Nope, nothing here!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x501B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Get back, " NAME "!"
)

DEFINE_MESSAGE(0x501C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "....\n"
"A terrible thing has happened!\n"
"The " COLOR(RED) "evil shadow spirit" COLOR(DEFAULT) " has\n"
"been released!" BOX_BREAK UNSKIPPABLE  COLOR(RED) "Impa" COLOR(DEFAULT) ", the leader of Kakariko\n"
"Village, had sealed the evil shadow\n"
"spirit in the bottom of the well...." BOX_BREAK UNSKIPPABLE "But the force of the evil spirit\n"
"got so strong, the seal of the\n"
"well broke, and it escaped into the\n"
"world!!"
)

DEFINE_MESSAGE(0x501D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Let me take care of the village!\n"
"I'm counting on you,\n"
NAME "!"
)

DEFINE_MESSAGE(0x501E, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Royal Composer Bros.\n"
SHIFT("\x37") "Sharp the Elder\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x501F, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x23") "Royal Composer Bros.\n"
SHIFT("\x33") "Flat the Younger\n"
SHIFT("\x50") "R.I.P." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5020, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_VARIABLE,
QUICKTEXT_ENABLE  SHIFT("\x28") "Royal Family's Tomb" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x5021, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1A") "This poem is dedicated to\n"
"the memory of the dearly departed\n"
SHIFT("\x10") "members of the Royal Family." QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x5022, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The boy with the noble Zelda's \n"
"Ocarina...As I expected, \n"
"you have come." BOX_BREAK UNSKIPPABLE "I am " COLOR(RED) "Impa" COLOR(DEFAULT) ", one of the Sheikah.\n"
"I am Princess Zelda's caretaker,\n"
"and I am also the Sage who\n"
"guards the Shadow Temple."
)

DEFINE_MESSAGE(0x5023, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "Please look out for the Princess!" FADE("\x32")
)

DEFINE_MESSAGE(0x5024, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  NAME ", the hero!" BOX_BREAK UNSKIPPABLE "Finally, all of us, the " COLOR(RED) "six Sages" COLOR(DEFAULT) ", \n"
"have been awakened!\n"
"The time for the final showdown\n"
"with the King of Evil has come!" BOX_BREAK UNSKIPPABLE "Before that, though, you should\n"
"meet the one who is waiting for\n"
"you..." BOX_BREAK UNSKIPPABLE "The one who is waiting for you at\n"
"the " COLOR(LIGHTBLUE) "Temple of Time" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x5025, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "We Sheikah have served the \n"
"royalty of Hyrule from generation\n"
"to generation as attendants.\n"
"However..." BOX_BREAK UNSKIPPABLE "On that day seven years ago,\n"
"Ganondorf suddenly attacked...\n"
"and Hyrule Castle surrendered\n"
"after a short time." BOX_BREAK UNSKIPPABLE "Ganondorf's target was one of\n"
"the keys to the Sacred Realm...the\n"
"hidden treasure of the Royal\n"
"Family...The Ocarina of Time!" BOX_BREAK UNSKIPPABLE "My duty bound me to take Zelda \n"
"out of Ganondorf's reach." BOX_BREAK UNSKIPPABLE "When last I saw you, as we made\n"
"our escape from the castle, you\n"
"were just a lad..." BOX_BREAK UNSKIPPABLE "Now I see that you have become \n"
"a fine hero..."
)

DEFINE_MESSAGE(0x5026, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I have to stay here... You go to \n"
"Princess Zelda's side and protect \n"
"her on my behalf." BOX_BREAK UNSKIPPABLE "Now I put my power, which should \n"
"be helpful to you, into this\n"
COLOR(BLUE) "Medallion" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5027, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How is your Cucco? Is he happy?\n"
"Shall I check him out for you?"
)

DEFINE_MESSAGE(0x5028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE  SFX("\x68\x55") "I am the " COLOR(RED) "boss of the carpenters\n"
COLOR(DEFAULT) "that Impa hired to improve this\n"
"village and make it into a true\n"
"city!" BOX_BREAK UNSKIPPABLE "But young men these days don't\n"
"have any ambition...\n"
"Do you know what I mean, kid?" BOX_BREAK UNSKIPPABLE "My workers are just running\n"
"aimlessly around the village, and\n"
"they're not making any progress\n"
"at all..." BOX_BREAK UNSKIPPABLE "Even my own son doesn't have a \n"
"job, and he just wanders around\n"
"all day!" TEXTID("\x50\x29")
)

DEFINE_MESSAGE(0x5029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "They're all worthless, I tell you!!"
)

DEFINE_MESSAGE(0x502A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Look at that poor girl over there.\n"
"She works so hard taking care of \n"
"her chickens, even though touching\n"
"them gives her goose bumps..." BOX_BREAK "What a trooper! I would really \n"
"like to help her! I've just been\n"
"feeling so charitable these days!\n"
"Don't you feel that way, too?"
)

DEFINE_MESSAGE(0x502B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "There's nothing to worry about...\n"
"The Princess is safe now."
)

DEFINE_MESSAGE(0x502C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Soon, you'll meet Princess Zelda\n"
"face-to-face, and she will explain\n"
"everything..." BOX_BREAK UNSKIPPABLE "That is when we, the six Wise \n"
"Ones, will seal up the Evil King\n"
"and return peace to Hyrule."
)

DEFINE_MESSAGE(0x502D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hehehe, young man...\n"
"You were very quick to be able\n"
"to keep up with me! Hehehe!" BOX_BREAK UNSKIPPABLE "As a reward, I'm going to give\n"
"you my treasure. It's called the\n"
COLOR(RED) "Hookshot" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Its spring-loaded chain will pull\n"
"you to any spot where its hook\n"
"sticks. Doesn't that sound cool?\n"
"I'm sure it will help you!" BOX_BREAK UNSKIPPABLE "I live here now, so come back\n"
"again sometime. I'll give you\n"
"something cool!" BOX_BREAK UNSKIPPABLE "One more thing! Be careful on\n"
"your way back!\n"
"Heheheh...."
)

DEFINE_MESSAGE(0x502E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You're back, young man...\n"
"Was the present I gave to you\n"
"fun and useful?"
)

DEFINE_MESSAGE(0x502F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
SHIFT("\x19") "The time of this race was\n"
SHIFT("\x4B")  RACE_TIME "!!" EVENT
)

DEFINE_MESSAGE(0x5030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Looks like you're coming around..."
)

DEFINE_MESSAGE(0x5031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I believe Impa has gone to the \n"
COLOR(PURPLE) "Shadow Temple " COLOR(DEFAULT) "to seal it again,\n"
"but...she will be in danger without \n"
"any help!" BOX_BREAK UNSKIPPABLE  NAME "!\n"
"Impa is one of the six Sages.\n"
"Destroy the evil shadow spirit and\n"
"save Impa!" BOX_BREAK UNSKIPPABLE "There is an entrance to the \n"
"Shadow Temple beneath the \n"
"graveyard behind this village." BOX_BREAK UNSKIPPABLE "The only thing I can do for you is\n"
"teach you the melody that will\n"
"lead you to the Shadow Temple..." BOX_BREAK UNSKIPPABLE "This is the melody that will draw\n"
"you into the infinite darkness \n"
"that absorbs even time... Listen to \n"
"this, the " COLOR(PURPLE) "Nocturne of Shadow" COLOR(DEFAULT) "!!"
)

DEFINE_MESSAGE(0x5032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Go around! Go around and around\n"
"and around! What fun! I'm so \n"
"happy!" BOX_BREAK "I'm a music man who loves\n"
"to go around and around!\n"
"Go around and around!!!" BOX_BREAK "I'm trying to come up with a\n"
"musical theme inspired by this \n"
"windmill...going around and\n"
"around and around!!!"
)

DEFINE_MESSAGE(0x5033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Go around, go around, go around...\n"
"What? It's going way too fast!"
)

DEFINE_MESSAGE(0x5034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Grrrrrrrrr!" BOX_BREAK "I'll never forget what happened on\n"
"that day, seven years ago!\n"
"Grrrrrrrrr!" BOX_BREAK "It's all that Ocarina kid's fault!\n"
"Next time he comes around here,\n"
"I'm gonna mess him up!"
)

DEFINE_MESSAGE(0x5035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "What?! You've got an ocarina!!" BOX_BREAK UNSKIPPABLE "What the heck!" BOX_BREAK UNSKIPPABLE "That reminds me of that time,\n"
"seven years ago!" BOX_BREAK UNSKIPPABLE "Back then a mean kid came here \n"
"and played a " COLOR(PURPLE) "strange song" COLOR(DEFAULT) ". It \n"
"messed up this windmill!"
)

DEFINE_MESSAGE(0x5036, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What should I do!?\n"
"My " COLOR(RED) "Cuccos" COLOR(DEFAULT) " have all flown away!" BOX_BREAK "You, little boy, please!\n"
"Please help me bring them back to \n"
"this pen!"
)

DEFINE_MESSAGE(0x5037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Cuccos have run away!\n"
"Please help me bring the other \n"
"four back to this pen! Please!"
)

DEFINE_MESSAGE(0x5038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Cuccos have run away!\n"
"Please help me bring the other \n"
"three back to this pen! Please!"
)

DEFINE_MESSAGE(0x5039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Cuccos have run away!\n"
"Please help me bring the other \n"
"two back to this pen! Please!"
)

DEFINE_MESSAGE(0x503A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My Cuccos have run away!\n"
"Please help me bring the last one\n"
"back to this pen! Please!"
)

DEFINE_MESSAGE(0x503B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Thank you for finding my Cuccos.\n"
"I have allergies, so I get \n"
"goose bumps when I touch them." BOX_BREAK UNSKIPPABLE "For helping me, I will give this\n"
"to you. It's fine glass, and should\n"
"be useful. Please take good\n"
"care of it!" EVENT
)

DEFINE_MESSAGE(0x503C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, what are you doing?!\n"
"Now go round them up or pay for \n"
"them!" EVENT
)

DEFINE_MESSAGE(0x503D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please don't tease my Cuccos!"
)

DEFINE_MESSAGE(0x503E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "I bred a new type of miniature \n"
"Cucco! I call it the " COLOR(RED) "Pocket \n"
"Cucco" COLOR(DEFAULT) "! I don't get goose bumps\n"
"from this baby." BOX_BREAK UNSKIPPABLE  COLOR(RED) "Cuccos " COLOR(DEFAULT) "are very good at \n"
"getting lazy, late-risers out of bed.\n"
"Haven't you heard of them \n"
"before?" BOX_BREAK UNSKIPPABLE "It makes them very happy to crow:\n"
QUICKTEXT_ENABLE  SHIFT("\x38")  COLOR(RED) "CUCCKOOOO" COLOR(DEFAULT) "!" QUICKTEXT_DISABLE "\n"
"especially when it wakes up a \n"
"very heavy sleeper!" BOX_BREAK UNSKIPPABLE "However, my Cucco is not entirely\n"
"happy right now..." BOX_BREAK UNSKIPPABLE "You..., \n"
"You look like you're good at \n"
"handling Cuccos." BOX_BREAK UNSKIPPABLE "Here, take this egg.\n"
"After the Cucco hatches, bring it \n"
"back to me after a while, and I'll \n"
"check out its mood." TEXTID("\x50\x3F")
)

DEFINE_MESSAGE(0x503F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"What do you think? \n"
"Will you try?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5040, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Oh, too bad...were you pecked by\n"
"a Cucco when you were little?" EVENT
)

DEFINE_MESSAGE(0x5041, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Heh heh heh, young man!\n"
"Are you fast on your feet?" BOX_BREAK "I may not look like it, but I'm \n"
"confident in my speed!\n"
"Let's have a race! \n"
"Follow me if you dare!"
)

DEFINE_MESSAGE(0x5042, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Please make my Cucco happy!\n"
"OK?"
)

DEFINE_MESSAGE(0x5043, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Oh, your Cucco looks pretty \n"
"happy! He must have awakened an\n"
"extremely lazy guy!" BOX_BREAK UNSKIPPABLE "You're a good Cucco Keeper!\n"
"I'll give you a rare, valuable\n"
"Cucco, if you're interested..." BOX_BREAK UNSKIPPABLE "Its name is " COLOR(RED) "Cojiro" COLOR(DEFAULT) "," COLOR(RED) " " COLOR(DEFAULT) "and it used to\n"
"be my brother's Cucco. Its\n"
"blue body is quite charming.\n"
"It's so cute!" BOX_BREAK UNSKIPPABLE "Since my brother has gone, \n"
"it's strange, but Cojiro has \n"
"stopped crowing." TEXTID("\x50\x44")
)

DEFINE_MESSAGE(0x5044, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Do you want to keep " COLOR(RED) "Cojiro" COLOR(DEFAULT) "?\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x5045, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"It looks as if you really like that\n"
"other Cucco. OK, you can keep it\n"
"for a while." EVENT
)

DEFINE_MESSAGE(0x5046, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"An old witch runs the Potion Shop\n"
"behind this one. You can get to \n"
"that shop through the door to the\n"
"left of the counter." EVENT
)

DEFINE_MESSAGE(0x5047, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"My brother must have been very \n"
"lonely..."
)

DEFINE_MESSAGE(0x5048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I heard that the " COLOR(ADJUSTABLE) "Lost Woods" COLOR(DEFAULT) ", \n"
"where fairies live, is a strange\n"
"place with many mysterious smells." BOX_BREAK "I wish I could just once make \n"
"medicine with some of the strange\n"
"things I might find there..." BOX_BREAK "I may not be able to see very \n"
"well anymore, but my nose still \n"
"works fine!  Hehehe!"
)

DEFINE_MESSAGE(0x5049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Sniff sniff sniff..." BOX_BREAK "What a mysterious smell..." BOX_BREAK "You must have something!"
)

DEFINE_MESSAGE(0x504A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"That bum! He had to go into the \n"
"forest...\n"
TEXT_SPEED("\x01") "....." TEXT_SPEED("\x00") "I see." TEXTID("\x50\x4B")
)

DEFINE_MESSAGE(0x504B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, give it to me now!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x504C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"How sad... I just need a little..."
)

DEFINE_MESSAGE(0x504D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "If you see that fool, give this to \n"
"him. It is the strongest medicine\n"
"I have ever produced." BOX_BREAK UNSKIPPABLE "However, this potion will not\n"
"work on a monster..." EVENT
)

DEFINE_MESSAGE(0x504E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Hey, kid! If you want to carry \n"
"medicine, you need a container to\n"
"put it in!" EVENT
)

DEFINE_MESSAGE(0x504F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"They say that there is no \n"
"medicine that can cure a fool...\n"
"I guess that's true..."
)

DEFINE_MESSAGE(0x5050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I can't get down, so all I can do\n"
"is look at " COLOR(RED) "Death Mountain" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I can't get down, so all I can do \n"
"is look at the stars."
)

DEFINE_MESSAGE(0x5052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Can you see it from there? \n"
"Something is happening on " COLOR(RED) "Death \n"
"Mountain" COLOR(DEFAULT) "!"
)

DEFINE_MESSAGE(0x5053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Can you see it from there?\n"
COLOR(RED) "Death Mountain " COLOR(DEFAULT) "is back to normal!"
)

DEFINE_MESSAGE(0x5054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"I don't feel like getting down,\n"
"ever! Whatever happens, I'll keep\n"
"watching Death Mountain from \n"
"up here."
)

DEFINE_MESSAGE(0x5055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Hey! Good to see you again! I'll\n"
"give you this as a memento."
)

DEFINE_MESSAGE(0x5056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"To get a good view, use " COLOR(YELLOW) "[C-Up]" COLOR(DEFAULT) " and \n"
"look around with " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x5057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey! Kid, do you always enter\n"
"other people's houses without \n"
"permission? Didn't your parents \n"
"teach you any manners?" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Oh well." BOX_BREAK UNSKIPPABLE "Did you see a lady behind this \n"
"house? She's going through hard \n"
"times." BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Oh well." TEXTID("\x50\x58")
)

DEFINE_MESSAGE(0x5058, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If that lady asks you about \n"
"chickens, you should listen to her."
)

DEFINE_MESSAGE(0x5059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Is visiting other people's houses \n"
"at this late hour your idea of \n"
"fun? You must not have had a \n"
"good upbringing." BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Oh well." TEXTID("\x50\x5A")
)

DEFINE_MESSAGE(0x505A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"That lady takes care of chickens,\n"
"but she is, in fact, allergic to \n"
"them." BOX_BREAK SHIFT("\x42") "Oh well."
)

DEFINE_MESSAGE(0x505B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey! Young man! A grown boy\n"
"like you entering a person's house\n"
"without permission?! I want to\n"
"talk to your parents!" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Oh well." BOX_BREAK UNSKIPPABLE "This isn't my house anyway.\n"
"This is the " COLOR(RED) "great Impa's" COLOR(DEFAULT) " house!" BOX_BREAK UNSKIPPABLE "The great Impa has gone to the\n"
COLOR(RED) "graveyard " COLOR(DEFAULT) "to seal up the \n"
"humongous creature there." BOX_BREAK UNSKIPPABLE "Since Ganondorf appeared, many \n"
"monsters have been sighted \n"
"around here." BOX_BREAK UNSKIPPABLE "Only the great Impa has kept \n"
"peace in our village. You have to\n"
"remember that, young man!" BOX_BREAK UNSKIPPABLE  SHIFT("\x42") "Oh well." BOX_BREAK UNSKIPPABLE "Speaking of the great Impa, she\n"
"hasn't come back yet. I wonder \n"
"what happened to her?" TEXTID("\x50\x5C")
)

DEFINE_MESSAGE(0x505C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I heard that the " COLOR(RED) "ghost of the\n"
"gravekeeper " COLOR(DEFAULT) "often appears in the \n"
"graveyard behind this village..." BOX_BREAK SHIFT("\x34") "But, no big deal."
)

DEFINE_MESSAGE(0x505D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hi, boy! Is this the first time\n"
"you've visited this village?" BOX_BREAK UNSKIPPABLE "A great woman, " COLOR(RED) "Impa" COLOR(DEFAULT) ", opened up\n"
"this village to us poor folk." TEXTID("\x50\x5E")
)

DEFINE_MESSAGE(0x505E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, make yourself at home.\n"
"The food isn't ready yet, though."
)

DEFINE_MESSAGE(0x505F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"The great Impa is not here. Did\n"
"something happen to her?"
)

DEFINE_MESSAGE(0x5060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "All people have hardships in \n"
"their past that they would\n"
"rather no one found out about." TEXTID("\x50\x61")
)

DEFINE_MESSAGE(0x5061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Look at the bearded man sleeping\n"
"over there. I bet even someone\n"
"like him has had his share of\n"
"troubles in the past..."
)

DEFINE_MESSAGE(0x5062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"That bearded guy went back to \n"
"the ranch. He looked so happy!"
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

DEFINE_MESSAGE(0x506B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I'm starving!\n"
"Let's eat dinner, right now!"
)

DEFINE_MESSAGE(0x506C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Those guys each do the work of \n"
"half a man, but they still want a\n"
"full man's portion!\n"
"They're lazy slackers, I tell you!"
)

DEFINE_MESSAGE(0x506D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Poe   30 Rupees\n"
COLOR(DEFAULT) "This is a bottled ghost spirit. \n"
"Sell it to someone who is crazy \n"
"about weird things like this." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x506E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Don't cause trouble!\n"
"I'll tell Dampé!" QUICKTEXT_DISABLE  FADE("\x3C")
)

DEFINE_MESSAGE(0x5074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5076, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Wah hah hah hah hah hah!\n"
"Those are some funny-looking\n"
"clothes, man!"
)

DEFINE_MESSAGE(0x5082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x5088, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x508B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Look at him...the man with the\n"
"beard. I think he was fired from\n"
"his job at the ranch..." TEXTID("\x50\x8C")
)

DEFINE_MESSAGE(0x508C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"He's always just lazing around, \n"
"morning, noon and night. \n"
"He's an awfully carefree guy \n"
"during such hard times."
)

DEFINE_MESSAGE(0x508D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x6000, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "Halt! Stay where you are!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x6001, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, newcomer!"
)

DEFINE_MESSAGE(0x6002, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"Hey, newcomer! Wait a second \n"
"and I'll open the gate for you."
)

DEFINE_MESSAGE(0x6003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
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

DEFINE_MESSAGE(0x6006, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
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

DEFINE_MESSAGE(0x600B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SFX("\x38\xEC") "I'll be your guide on your way,\n"
"but coming back, I won't play!\n"
"I'll show you the only way to go,\n"
"so follow me and don't be slow!" FADE("\x5A")
)

DEFINE_MESSAGE(0x600C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x6028, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey! Where are you taking me?!"
)

DEFINE_MESSAGE(0x6029, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Ho ho ho!\n"
"Looks like someone is here, Koume."
)

DEFINE_MESSAGE(0x602A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hee hee hee!\n"
"Looks like it, Kotake!"
)

DEFINE_MESSAGE(0x602B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "What an outrageous fellow he is,\n"
"to intrude so boldly into our \n"
"Temple...\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x602C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "We should teach this outrageous\n"
"fellow a lesson!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x602D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh, loyal minion..."
)

DEFINE_MESSAGE(0x602E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Destroy this intruder on \n"
"our behalf!"
)

DEFINE_MESSAGE(0x602F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "Great Ganondorf's...Enemy...\n"
"Must die..."
)

DEFINE_MESSAGE(0x6030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Unnnh...\n"
"Where am I...?"
)

DEFINE_MESSAGE(0x6031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Well, well...\n"
"Looks like she's back to normal...\n"
"Koume..."
)

DEFINE_MESSAGE(0x6032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "She's just a little girl,\n"
"but she commands a lot of \n"
"respect among the Gerudo, Kotake..."
)

DEFINE_MESSAGE(0x6033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Maybe we should make her work\n"
"for the great Ganondorf for\n"
"a little while longer!\n"
"Ho ho ho!"
)

DEFINE_MESSAGE(0x6034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Then we should brainwash her\n"
"again!\n"
"Hee hee hee!"
)

DEFINE_MESSAGE(0x6035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Kid, let me thank you." BOX_BREAK UNSKIPPABLE "Heheheh...look what the little\n"
"kid has become in the past seven\n"
"years--a competent swordsman!"
)

DEFINE_MESSAGE(0x6036, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
"If only I knew you would become \n"
"such a handsome man..." BOX_BREAK_DELAYED("\x50") "I should have kept the promise\n"
"I made back then..." FADE("\x50")
)

DEFINE_MESSAGE(0x6037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
UNSKIPPABLE "Here, I'll give you " COLOR(RED) "this" COLOR(DEFAULT) "...\n"
"It's a very important thing to me.\n"
"Let's have a competition later!"
)

DEFINE_MESSAGE(0x6038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "...see you again!"
)

DEFINE_MESSAGE(0x6039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "By the way..." BOX_BREAK UNSKIPPABLE "I really messed up..." BOX_BREAK UNSKIPPABLE "I was brainwashed by those old\n"
"witches and used by Ganondorf to\n"
"do his evil will..." BOX_BREAK UNSKIPPABLE "But isn't it funny? That a person\n"
"like me could turn out to be the\n"
COLOR(YELLOW) "Sage of Spirit" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "And now, I'm going to fight\n"
"them as one of the six Sages!\n"
"Heh heh..." BOX_BREAK UNSKIPPABLE "I'm going to pay them back for\n"
"what they did to me!"
)

DEFINE_MESSAGE(0x603A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Kid..." BOX_BREAK UNSKIPPABLE "No...\n"
NAME ", the Hero of Time!" BOX_BREAK UNSKIPPABLE "Instead of keeping the promise I\n"
"made back then, I give you this\n"
COLOR(YELLOW) "Medallion" COLOR(DEFAULT) "!" BOX_BREAK UNSKIPPABLE "Take it!"
)

DEFINE_MESSAGE(0x603B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x12") "Yeearggh!" QUICKTEXT_DISABLE " Let me go!!"
)

DEFINE_MESSAGE(0x603C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x33") "You, " QUICKTEXT_ENABLE "you fiends!" QUICKTEXT_DISABLE "\n"
SHIFT("\x29") "Ganondorf's minions!"
)

DEFINE_MESSAGE(0x603D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  QUICKTEXT_ENABLE  SHIFT("\x1E")  NAME "!" QUICKTEXT_DISABLE "\n"
SHIFT("\x20") "Get out of here! Now!"
)

DEFINE_MESSAGE(0x603E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x6048, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Look at that stupid kid!\n"
"He came on his own to offer \n"
"himself as a sacrifice to the\n"
"great Ganondorf..." FADE("\x5A")
)

DEFINE_MESSAGE(0x6049, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x05") "With my flame, I will burn him to\n"
SHIFT("\x46") "the bone!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"With my frost, I will freeze him to\n"
SHIFT("\x46") "his soul!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x1C") "Shoot, what a fresh kid!\n"
SHIFT("\x15") "This time, we'll get serious,\n"
SHIFT("\x3C") "right Kotake?" FADE("\x5A")
)

DEFINE_MESSAGE(0x604C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4B") "What?" BOX_BREAK_DELAYED("\x14")  SHIFT("\x0A") "Hey, Koume, what is that above\n"
SHIFT("\x41") "your head?" FADE("\x3C")
)

DEFINE_MESSAGE(0x604D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0B") "I don't know, but you have one\n"
SHIFT("\x14") "over your head too, Kotake!" FADE("\x3C")
)

DEFINE_MESSAGE(0x604E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "But I'm only 400 years old!" FADE("\x28")
)

DEFINE_MESSAGE(0x604F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x14") "And I'm just 380 years old!" FADE("\x28")
)

DEFINE_MESSAGE(0x6050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x0C") "We're twins! Don't try to lie\n"
SHIFT("\x35") "about your age!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x06") "You must have gone senile!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x1E") "Who are you calling senile?!\n"
SHIFT("\x16") "Is that how you treat your\n"
SHIFT("\x3D") "older sister?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x36") "We are twins! \n"
SHIFT("\x26") "How can you be older?" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x6054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x3F") "Keeeyaaah!!" QUICKTEXT_DISABLE "\n"
QUICKTEXT_ENABLE  SHIFT("\x20") "How heartless you are!" QUICKTEXT_DISABLE  FADE("\x14")
)

DEFINE_MESSAGE(0x6055, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x12") "How can you be so ungrateful?" QUICKTEXT_DISABLE  FADE("\x0A")
)

DEFINE_MESSAGE(0x6056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x35") "You're heartless!!" QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x33") "You ungrateful..." QUICKTEXT_DISABLE  FADE("\x04")
)

DEFINE_MESSAGE(0x6058, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x21") "I'll come back to haunt you!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x6059, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "OK, let's get serious now, Kotake!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x605A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x605F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"The leader of the gang of thieves\n"
"is " COLOR(RED) "Nabooru" COLOR(DEFAULT) ". She is experimenting \n"
"in brainwashing many people at \n"
"the ruins in the desert."
)

DEFINE_MESSAGE(0x6060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, it was Ganondorf the Evil\n"
"King who was behind the gang of \n"
"thieves..."
)

DEFINE_MESSAGE(0x6061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "When " COLOR(RED) "Nabooru" COLOR(DEFAULT) " was a lone wolf \n"
"thief, she never stole from \n"
"the weak, but..." TEXTID("\x60\x62")
)

DEFINE_MESSAGE(0x6062, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Now, Nabooru's gang of thieves \n"
"stands for cruelty and brutality.\n"
"She claims to be a chivalrous \n"
"robber, but...no way!"
)

DEFINE_MESSAGE(0x6063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Like I suspected, Nabooru was \n"
"brainwashed by Ganondorf's \n"
"followers..."
)

DEFINE_MESSAGE(0x6064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "In Gerudo society, those who have\n"
"great skill in horseback riding and\n"
"archery are well respected." TEXTID("\x60\x65")
)

DEFINE_MESSAGE(0x6065, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"How about trying horseback \n"
"archery at the Gerudo's Fortress?" BOX_BREAK "If you have a horse, a Gerudo \n"
"from the fortress will set up \n"
"your challenge."
)

DEFINE_MESSAGE(0x6066, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"You did so great, young man!"
)

DEFINE_MESSAGE(0x6067, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Building a bridge over the valley\n"
"is a simple task for four\n"
"carpenters."
)

DEFINE_MESSAGE(0x6068, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x6079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Hey, what's up, " NAME "?\n"
"Surprised to see me?" BOX_BREAK UNSKIPPABLE "A long time in this world is\n"
"almost nothing to you, is it?\n"
"How mysterious!" BOX_BREAK UNSKIPPABLE "Even I thought that the tales of a\n"
"boy who could travel back and\n"
"forth through time was merely a\n"
"legend." BOX_BREAK UNSKIPPABLE  NAME ", you have fully \n"
"matured as an adult." TEXTID("\x60\x7A")
)

DEFINE_MESSAGE(0x607A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"From now on, the future of all the\n"
"people in Hyrule is on your \n"
"shoulders." BOX_BREAK "Maybe it's not my time anymore. \n"
"Here is my last advice." BOX_BREAK "Two witches inhabit this temple. In \n"
"order to destroy them, " COLOR(RED) "turn their \n"
"own magic power against them" COLOR(DEFAULT) ".\n"
"Hoo hoot!" TEXTID("\x60\x7B")
)

DEFINE_MESSAGE(0x607B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you want to hear what I said\n"
"again?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x607C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7003, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7009, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Can you see the man with the \n"
"evil eyes?" BOX_BREAK UNSKIPPABLE "That is " COLOR(RED) "Ganondorf" COLOR(DEFAULT) ", the leader of \n"
"the Gerudos. They hail from the \n"
"desert far to the west." BOX_BREAK UNSKIPPABLE "Though he swears allegiance to my \n"
"father, I am sure he is not \n"
"sincere." BOX_BREAK UNSKIPPABLE "The dark clouds that covered \n"
"Hyrule in my dream...\n"
"They must symbolize that man!"
)

DEFINE_MESSAGE(0x700A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7011, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"If you want potions, you'd better \n"
"bring an empty bottle. Understand,\n"
"young man?" PERSISTENT
)

DEFINE_MESSAGE(0x7012, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
"I'm sorry, but this is just a model. \n"
"Because of the crisis in Goron \n"
"City, we haven't received any \n"
"shipments lately and we're out." PERSISTENT
)

DEFINE_MESSAGE(0x7013, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x702D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  SHIFT("\x37") "Hey you! Stop!\n"
SHIFT("\x28") "You, kid, over there!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x5F") "!" BOX_BREAK_DELAYED("\x0A")  UNSKIPPABLE  SHIFT("\x4E")  QUICKTEXT_ENABLE "Who?!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x702F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x3A") "Who are you?" BOX_BREAK UNSKIPPABLE "How did you get past the guards?" EVENT
)

DEFINE_MESSAGE(0x7030, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Do you have it? \n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7031, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Well, that's odd...\n"
"I thought you might be the one\n"
"from my dream...\n"
"You really don't have it?" BOX_BREAK "Tell me the truth..." EVENT
)

DEFINE_MESSAGE(0x7032, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x2D") "Just as I thought!" EVENT
)

DEFINE_MESSAGE(0x7033, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Please keep this a secret from\n"
"everyone...\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7034, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"C'mon...don't be a blabber-mouth!" EVENT
)

DEFINE_MESSAGE(0x7035, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The legend goes like this..." EVENT
)

DEFINE_MESSAGE(0x7036, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7037, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7038, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, I'm sorry. \n"
"I'm not very good at storytelling..." EVENT
)

DEFINE_MESSAGE(0x7039, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE  QUICKTEXT_ENABLE "What happened?" QUICKTEXT_DISABLE " Did he see you?" BOX_BREAK UNSKIPPABLE "Don't worry." BOX_BREAK UNSKIPPABLE "He doesn't have any idea what\n"
"we're planning...yet!" EVENT
)

DEFINE_MESSAGE(0x703A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Please!\n"
"\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "OK\n"
"I don't believe you." COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x703B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x704E, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE  SHIFT("\x2D")  NAME "..." BOX_BREAK UNSKIPPABLE  SHIFT("\x45") "Wake up...\n"
SHIFT("\x05")  NAME ", the chosen one..."
)

DEFINE_MESSAGE(0x704F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7050, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x23")  COLOR(LIGHTBLUE) "Look " NAME "!\n"
COLOR(DEFAULT)  SHIFT("\x32")  COLOR(LIGHTBLUE) "You're big now!!\n"
COLOR(DEFAULT)  SHIFT("\x31")  COLOR(LIGHTBLUE) "You've grown up!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x7051, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7052, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Right, it looks like you are \n"
"confused... Let me tell you \n"
"again, from the beginning." TEXTID("\x70\x51")
)

DEFINE_MESSAGE(0x7053, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7054, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7056, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I've been waiting for you, \n"
"Hero of Time..."
)

DEFINE_MESSAGE(0x7057, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x705A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
UNSKIPPABLE "I have been waiting for you,\n"
NAME "."
)

DEFINE_MESSAGE(0x705B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", the Hero of Time..." BOX_BREAK UNSKIPPABLE "You have overcome many \n"
"hardships and awakened six Sages." BOX_BREAK UNSKIPPABLE "And now you have a final\n"
"challenge, a showdown with \n"
"Ganondorf, the King of Evil...."
)

DEFINE_MESSAGE(0x705C, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x705D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Seven years ago, Ganondorf, the \n"
"King of Thieves, used the door \n"
"you opened in the Temple of Time\n"
"and entered the Sacred Realm." BOX_BREAK UNSKIPPABLE "But when he laid his hands on the\n"
"Triforce, the legend came true."
)

DEFINE_MESSAGE(0x705E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The one who holds the " COLOR(RED) "Triforce \n"
"of Courage " COLOR(DEFAULT) "is...\n"
"You, " NAME "!"
)

DEFINE_MESSAGE(0x705F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "And the other, who holds the \n"
COLOR(RED) "Triforce of Wisdom" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "is the seventh Sage, who is\n"
"destined to be the leader of\n"
"them all..."
)

DEFINE_MESSAGE(0x7060, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "It is I, the Princess of Hyrule,\n"
COLOR(RED) "Zelda" COLOR(DEFAULT) "."
)

DEFINE_MESSAGE(0x7061, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I apologize for meeting you in \n"
"disguise, but it was necessary to\n"
"hide from the King of Evil. \n"
"Please forgive me..."
)

DEFINE_MESSAGE(0x7062, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"I saw you as I was escaping \n"
"from the castle with my \n"
"attendant, Impa." FADE("\x50")
)

DEFINE_MESSAGE(0x7063, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As long as you had the Ocarina \n"
"in your possession, I thought \n"
"Ganondorf could never enter the\n"
"Sacred Realm, but..." BOX_BREAK UNSKIPPABLE "something I could never expect\n"
"happened..."
)

DEFINE_MESSAGE(0x7064, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x24") "That rumbling...It can't be!?"
)

DEFINE_MESSAGE(0x7065, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Princess Zelda...you foolish \n"
"traitor!" BOX_BREAK UNSKIPPABLE "I commend you for avoiding my \n"
"pursuit for seven long years."
)

DEFINE_MESSAGE(0x7066, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x706C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x706F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Thank you, " NAME "..." BOX_BREAK UNSKIPPABLE "Thanks to you, Ganondorf has\n"
"been sealed inside the Evil Realm!" BOX_BREAK UNSKIPPABLE "Thus, peace will once again\n"
"reign in this world...for a time."
)

DEFINE_MESSAGE(0x7070, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
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

DEFINE_MESSAGE(0x7073, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Please believe me....\n"
"My prophecies have never been\n"
"wrong!" EVENT
)

DEFINE_MESSAGE(0x7074, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "You destroyed the wicked\n"
"creatures that haunted the temple\n"
"and awakened the Sage..." BOX_BREAK UNSKIPPABLE "But there are still other Sages\n"
"who need your help." BOX_BREAK UNSKIPPABLE "In order to awaken all the other\n"
"Sages, you must become even\n"
"more powerful." BOX_BREAK UNSKIPPABLE "You must travel over\n"
"mountains..." BOX_BREAK UNSKIPPABLE "under water..." BOX_BREAK UNSKIPPABLE "and even through time..."
)

DEFINE_MESSAGE(0x7075, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7077, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I am " COLOR(RED) "Sheik" COLOR(DEFAULT) ".\n"
"Survivor of the Sheikahs..."
)

DEFINE_MESSAGE(0x7078, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As I see you standing there\n"
"holding the mythical " COLOR(RED) "Master \n"
"Sword" COLOR(DEFAULT) ", you really do look like the \n"
"legendary Hero of Time..."
)

DEFINE_MESSAGE(0x7079, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "If you believe the legend, you\n"
"have no choice. You must look for\n"
"the five temples and awaken the\n"
COLOR(RED) "five Sages" COLOR(DEFAULT) "...."
)

DEFINE_MESSAGE(0x707A, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x707B, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_BOTTOM,
"I thought I should entrust the\n"
"Ocarina to you... I thought that \n"
"would be our best chance..." FADE("\x50")
)

DEFINE_MESSAGE(0x707C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Before that...I have things I want \n"
"to tell only to you. Please listen." BOX_BREAK UNSKIPPABLE "Another unknown legend of the \n"
"Triforce passed down by the \n"
"shadow folk, the Sheikahs...."
)

DEFINE_MESSAGE(0x707D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The Triforce separated into three \n"
"parts. Only the " COLOR(RED) "Triforce of Power" COLOR(DEFAULT) "\n"
"remained in Ganondorf's hand."
)

DEFINE_MESSAGE(0x707E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The strength of the Triforce of\n"
"Power enabled him to become a\n"
"mighty, evil king, but his dark\n"
"ambitions were not satisfied."
)

DEFINE_MESSAGE(0x707F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "To gain complete mastery of the \n"
"world, Ganondorf started looking\n"
"for " COLOR(RED) "those chosen by destiny" COLOR(DEFAULT) " to \n"
"hold the two other Triforce parts."
)

DEFINE_MESSAGE(0x7080, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "On that day, seven years ago,\n"
"Ganondorf attacked Hyrule Castle."
)

DEFINE_MESSAGE(0x7081, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "After you opened the door of \n"
"time, the Master Sword sealed you\n"
"away in the Sacred Realm..."
)

DEFINE_MESSAGE(0x7082, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7083, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "And...now you are back. The \n"
"dark age ruled by Ganondorf the\n"
"Evil King will end!"
)

DEFINE_MESSAGE(0x7084, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7085, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "But you let your guard down...\n"
"I knew you would appear if I let\n"
"this kid wander around!"
)

DEFINE_MESSAGE(0x7086, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "My only mistake was to slightly\n"
"underestimate the power of this\n"
"kid..."
)

DEFINE_MESSAGE(0x7087, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x708B, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "If you want to return to your\n"
"original time, return the Master \n"
"Sword to the " COLOR(RED) "Pedestal of Time" COLOR(DEFAULT) "." BOX_BREAK UNSKIPPABLE "By doing this, you will travel back\n"
"in time seven years...."
)

DEFINE_MESSAGE(0x708C, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The time will come when you will\n"
"have to return here quickly...\n"
"I will teach this to you for when \n"
"that time comes..." BOX_BREAK UNSKIPPABLE "The song to return you to the \n"
"Temple of Time...\n"
COLOR(LIGHTBLUE) "The Prelude of Light" COLOR(DEFAULT) "..."
)

DEFINE_MESSAGE(0x708D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x708F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Hey you! Don't cause any trouble!" QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x7090, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7091, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "All the tragedy that has befallen\n"
"Hyrule was my doing..." BOX_BREAK UNSKIPPABLE "I was so young...I could not\n"
"comprehend the consequences of \n"
"trying to control the Sacred Realm." BOX_BREAK UNSKIPPABLE "I dragged you into it, too." BOX_BREAK UNSKIPPABLE "Now it is time for me to make up \n"
"for my mistakes..." BOX_BREAK UNSKIPPABLE "You must lay the Master Sword to \n"
"rest and close the Door of Time..."
)

DEFINE_MESSAGE(0x7092, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "However, by doing this, the road\n"
"between times will be closed..."
)

DEFINE_MESSAGE(0x7093, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ",\n"
"give the Ocarina to me..." BOX_BREAK UNSKIPPABLE "As a Sage, I can return you\n"
"to your original time with it."
)

DEFINE_MESSAGE(0x7094, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_TOP,
UNSKIPPABLE "When peace returns to Hyrule..." BOX_BREAK UNSKIPPABLE "It will be time for us to say \n"
"good-bye..."
)

DEFINE_MESSAGE(0x7095, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x709D, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"I can't find my puppy anywhere!\n"
"I need you to look for it! Please!"
)

DEFINE_MESSAGE(0x709E, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x4C")  QUICKTEXT_ENABLE "Arrrgh!" QUICKTEXT_DISABLE "\n"
"That is not my dog! \n"
"How could you mix up my puppy\n"
"with a mutt like that?!"
)

DEFINE_MESSAGE(0x709F, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x46")  QUICKTEXT_ENABLE "Richard!" QUICKTEXT_DISABLE  BOX_BREAK "This is my little Richard!\n"
"Thank you! Thank you!\n"
"I'll give this to you as a\n"
"reward!"
)

DEFINE_MESSAGE(0x70A0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"At night it's dangerous to go out\n"
"with all the wild dogs around...\n"
"No, I wasn't warning you! \n"
"I'm worried about my puppy!"
)

DEFINE_MESSAGE(0x70A1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x70A2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Select a mask with left or right\n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Talk to the shop owner.\n"
"Don't borrow" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70A3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x70A5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, great! You sold it!\n"
"Please pay back " COLOR(RED) "10 Rupees " COLOR(DEFAULT) "for\n"
"the Keaton Mask now." EVENT
)

DEFINE_MESSAGE(0x70A6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh! You haven't sold the newest\n"
"mask yet. Just have faith... Keep\n"
"trying a little longer." EVENT
)

DEFINE_MESSAGE(0x70A7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Payment received!" EVENT
)

DEFINE_MESSAGE(0x70A8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "What?!" QUICKTEXT_DISABLE "\n"
"You don't have my money?!" BOX_BREAK QUICKTEXT_ENABLE "How dare you!" QUICKTEXT_DISABLE  BOX_BREAK "You'd better bring me my money...\n"
"or else!" EVENT
)

DEFINE_MESSAGE(0x70A9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh yeah!" BOX_BREAK "Very well done!\n"
"All the masks are sold out." BOX_BREAK "I knew I could trust you!" EVENT
)

DEFINE_MESSAGE(0x70AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As a reward...\n"
"I will lend you this special mask." BOX_BREAK UNSKIPPABLE "This is the " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". It is a\n"
"mysterious mask passed down by \n"
"the Sheikah." BOX_BREAK UNSKIPPABLE "With this mask you can see into \n"
"other people's minds...\n"
"It's useful, but scary!" BOX_BREAK UNSKIPPABLE "Why is it scary?" BOX_BREAK UNSKIPPABLE "You may find out as you grow\n"
"older and discover the true \n"
"meaning of life..." BOX_BREAK UNSKIPPABLE "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"From now on you can borrow any\n"
"mask you want.\n"
"Just have faith..." EVENT
)

DEFINE_MESSAGE(0x70AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Welcome!\n"
"Which mask can I lend to you?" EVENT
)

DEFINE_MESSAGE(0x70AD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Choose a mask with left or right \n"
"on " COLOR(LIGHTBLUE) "[Control-Pad]" COLOR(DEFAULT) ".\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Ask about Mask of Truth\n"
"Don't borrow a mask" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70AE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"This is the " COLOR(RED) "Mask of Truth" COLOR(DEFAULT) ". It is a\n"
"mysterious mask passed down by \n"
"the Sheikah." BOX_BREAK "With this mask you can see into \n"
"other people's minds. It's useful,\n"
"but scary!" BOX_BREAK "Why is it scary?" BOX_BREAK "You'll find out as you grow older!" BOX_BREAK "Ho ho ho!" EVENT
)

DEFINE_MESSAGE(0x70AF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Mask of Truth -- Not for Sale" COLOR(DEFAULT) "\n"
"This mask has special powers." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Skull Mask -- Price 20 Rupees" COLOR(DEFAULT) "\n"
"A horned skull mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Spooky Mask -- Price 30 Rupees\n"
COLOR(DEFAULT) "A sad, wooden mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Keaton Mask -- Price 10 Rupees\n"
COLOR(DEFAULT) "Keaton stuff is hot, hot, hot!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bunny Hood -- Price 50 Rupees\n"
COLOR(DEFAULT) "With swinging rabbit ears!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Skull Mask -- Free to Borrow" COLOR(DEFAULT) "\n"
"A horned skull mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Spooky Mask -- Free to Borrow\n"
COLOR(DEFAULT) "A sad, wooden mask." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Keaton Mask -- Free to Borrow\n"
COLOR(DEFAULT) "Keaton stuff is hot, hot, hot!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Bunny Hood -- Free to Borrow\n"
COLOR(DEFAULT) "With swinging rabbit ears!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Goron Mask -- Free to Borrow\n"
COLOR(DEFAULT) "This round face makes you \n"
"a little happier!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70B9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Zora Mask -- Free to Borrow" COLOR(DEFAULT) "\n"
"You'll look cool while you're\n"
"swimming if you wear this mask!" QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Gerudo Mask -- Free to Borrow\n"
COLOR(DEFAULT) "With its charming eyes, it makes\n"
"a great lady's disguise." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(RED) "Mask of Truth -- Free to Borrow" COLOR(DEFAULT) "\n"
"Mysterious mask to see into other\n"
"people's minds." QUICKTEXT_DISABLE  PERSISTENT
)

DEFINE_MESSAGE(0x70BC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the " COLOR(RED) "Skull \n"
"Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Spooky Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Keaton Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70BF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Bunny Hood" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Goron Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Zora Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Gerudo Mask" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE "Do you want to borrow the \n"
COLOR(RED) "Mask of Truth" COLOR(DEFAULT) "?" QUICKTEXT_DISABLE "\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "20 Rupees \n"
COLOR(DEFAULT) "for the Skull Mask now." EVENT
)

DEFINE_MESSAGE(0x70C5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "30 Rupees \n"
COLOR(DEFAULT) "for the Spooky Mask now." EVENT
)

DEFINE_MESSAGE(0x70C6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh, great! You sold it!\n"
"Please pay me back " COLOR(RED) "50 Rupees \n"
COLOR(DEFAULT) "for the Bunny Hood now." EVENT
)

DEFINE_MESSAGE(0x70C7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
"Oh! You haven't sold the mask\n"
"yet. Just have faith for a \n"
"little while longer." BOX_BREAK "Or, do you want to trade it\n"
"for another mask?\n"
TWO_CHOICE  COLOR(ADJUSTABLE) "Yes\n"
"No" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70C8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The Triforce parts are resonating...\n"
"They are combining into one again..."
)

DEFINE_MESSAGE(0x70C9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The two Triforce parts that I \n"
"could not capture on that day\n"
"seven years ago..." BOX_BREAK UNSKIPPABLE "I didn't expect they would be \n"
"hidden within you two!"
)

DEFINE_MESSAGE(0x70CA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "And now, finally, all the Triforce\n"
"parts have gathered here!"
)

DEFINE_MESSAGE(0x70CB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "These toys are too much for you!"
)

DEFINE_MESSAGE(0x70CC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I command you to return them \n"
"to me!"
)

DEFINE_MESSAGE(0x70CD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE)  NAME "!\n"
"I can't help you!\n"
"Because of the waves of\n"
"darkness, I can't get close!" BOX_BREAK COLOR(DEFAULT)  UNSKIPPABLE  COLOR(LIGHTBLUE) "I'm sorry, " NAME "!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70CE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "The Great Evil King Ganondorf...\n"
"beaten by this kid?!"
)

DEFINE_MESSAGE(0x70CF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "....!"
)

DEFINE_MESSAGE(0x70D0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Ganondorf...pitiful man..." BOX_BREAK UNSKIPPABLE "Without a strong, righteous mind,\n"
"he could not control the power of\n"
"the gods...and..."
)

DEFINE_MESSAGE(0x70D1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME ", listen to me!\n"
"This tower will collapse soon!" BOX_BREAK UNSKIPPABLE "With his last breath, Ganondorf is\n"
"trying to crush us in the ruins of\n"
"the tower! We need to hurry and\n"
"escape!"
)

DEFINE_MESSAGE(0x70D2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Please follow me!"
)

DEFINE_MESSAGE(0x70D3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "It's over...it's finally over..."
)

DEFINE_MESSAGE(0x70D4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  COLOR(LIGHTBLUE)  NAME "... \n"
"I'm sorry I couldn't help you in the\n"
"battle before!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70D5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "What is that sound?"
)

DEFINE_MESSAGE(0x70D6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SFX("\x68\x5F")  COLOR(LIGHTBLUE) "There's no way he's going to hold\n"
"me back again!\n"
COLOR(DEFAULT)  QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "This time, we fight together!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  NAME "! The Master \n"
"Sword is here! \n"
QUICKTEXT_ENABLE "Hurry up!!" QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70D8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I'm using my power to hold the\n"
"Evil King! You use your sword and\n"
"deliver the final blow!"
)

DEFINE_MESSAGE(0x70D9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x41") "Six Sages...\n"
QUICKTEXT_ENABLE  SHIFT("\x50") "Now!!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x03") "YOU..." TEXT_SPEED("\x00")  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  TEXT_SPEED("\x03") "CURSE YOU...ZELDA!\n"
TEXT_SPEED("\x02") "CURSE YOU...SAGES!!" TEXT_SPEED("\x00")  FADE("\x32")
)

DEFINE_MESSAGE(0x70DC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "CURSE YOU..." QUICKTEXT_ENABLE  NAME "!" QUICKTEXT_DISABLE  FADE("\x1E")
)

DEFINE_MESSAGE(0x70DD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Someday...\n"
"When this seal is broken...." BOX_BREAK_DELAYED("\x50")  UNSKIPPABLE "That is when I will exterminate\n"
"your descendants!!" FADE("\x50")
)

DEFINE_MESSAGE(0x70DE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "As long as the Triforce of Power\n"
"is in my hand...." FADE("\x50")
)

DEFINE_MESSAGE(0x70DF, TEXTBOX_TYPE_BLUE, TEXTBOX_POS_MIDDLE,
TEXT_SPEED("\x02") "You..." TEXT_SPEED("\x00") "who are you?" FADE("\x50")
)

DEFINE_MESSAGE(0x70E0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0A") "The " COLOR(ADJUSTABLE) "Forest Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x14") "Hurry up, " NAME "!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "The " COLOR(RED) "Fire Barrier" COLOR(DEFAULT) " is dispelled!\n"
SHIFT("\x14") "Hurry up, Brother!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "The " COLOR(BLUE) "Water Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x46") "Hurry up!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E3, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "The " COLOR(PURPLE) "Shadow Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x1E") "Please save the Princess!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E4, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "The " COLOR(YELLOW) "Spirit Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x37") "Hurry up, kid!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E5, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
SHIFT("\x0F") "The " COLOR(LIGHTBLUE) "Light Barrier " COLOR(DEFAULT) "is dispelled!\n"
SHIFT("\x4B") "Hurry!" FADE("\x28")
)

DEFINE_MESSAGE(0x70E6, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE)  NAME ", isn't that...?!" COLOR(DEFAULT)
)

DEFINE_MESSAGE(0x70E7, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
COLOR(LIGHTBLUE) "It's that legendary blade..." COLOR(DEFAULT)  FADE("\x1E")
)

DEFINE_MESSAGE(0x70E8, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  SHIFT("\x29")  COLOR(LIGHTBLUE) "The Master Sword!!" COLOR(DEFAULT)  QUICKTEXT_DISABLE
)

DEFINE_MESSAGE(0x70E9, TEXTBOX_TYPE_NONE_NO_SHADOW, TEXTBOX_POS_BOTTOM,
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

DEFINE_MESSAGE(0x70F9, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Oh? What's that?" BOX_BREAK UNSKIPPABLE  TEXT_SPEED("\x02")  QUICKTEXT_ENABLE "Is" QUICKTEXT_DISABLE " " QUICKTEXT_ENABLE "that" QUICKTEXT_DISABLE "..." TEXT_SPEED("\x00")  EVENT
)

DEFINE_MESSAGE(0x70FA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "a fairy" COLOR(DEFAULT)  QUICKTEXT_DISABLE "?!" BOX_BREAK UNSKIPPABLE "Then, are you...\n"
"Are you from the forest?" EVENT
)

DEFINE_MESSAGE(0x70FB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "Then...then...you wouldn't happen to\n"
"have...the " COLOR(ADJUSTABLE) "Spiritual Stone of the \n"
"Forest" COLOR(DEFAULT) ", would you?! That green \n"
"and shining stone..." EVENT
)

DEFINE_MESSAGE(0x70FC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I had a dream...In the dream,\n"
"dark storm clouds were billowing\n"
"over the land of Hyrule..." BOX_BREAK UNSKIPPABLE "But suddenly, a ray of light shot\n"
"out of the forest, parted the\n"
"clouds and lit up the ground..." BOX_BREAK UNSKIPPABLE "The light turned into a figure\n"
"holding a " COLOR(ADJUSTABLE) "green and shining stone" COLOR(DEFAULT) ",\n"
"followed by a " COLOR(LIGHTBLUE) "fairy" COLOR(DEFAULT) "..." EVENT
)

DEFINE_MESSAGE(0x70FD, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE "I know this is a prophecy that\n"
"someone would come from the\n"
COLOR(ADJUSTABLE) "forest" COLOR(DEFAULT) "..." BOX_BREAK UNSKIPPABLE "Yes, I thought you might\n"
"be the one..." EVENT
)

DEFINE_MESSAGE(0x70FE, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
UNSKIPPABLE  SHIFT("\x3A") "Oh, I'm sorry!" BOX_BREAK UNSKIPPABLE "I got carried away with my story \n"
"and didn't even properly introduce \n"
"myself!" EVENT
)

DEFINE_MESSAGE(0x70FF, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x7123, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x71AA, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
NAME "!\n"
"Help me!"
)

DEFINE_MESSAGE(0x71AB, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
NAME "!\n"
"The exit is just over there!"
)

DEFINE_MESSAGE(0x71AC, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_MIDDLE,
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

DEFINE_MESSAGE(0x71B0, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE  COLOR(LIGHTBLUE) "Oh, no! " COLOR(RED) "Time's up!\n"
COLOR(LIGHTBLUE) "The thing you were going to \n"
"deliver has spoiled!\n"
"Let's try again!" COLOR(DEFAULT)  QUICKTEXT_DISABLE  EVENT
)

DEFINE_MESSAGE(0x71B1, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_BOTTOM,
QUICKTEXT_ENABLE "BOINNG! BOINNG!\n"
"The current time is: " TIME "!" QUICKTEXT_DISABLE  FADE("\x28")
)

DEFINE_MESSAGE(0x71B2, TEXTBOX_TYPE_BLACK, TEXTBOX_POS_VARIABLE,
"You heard about us from the\n"
"guard at Death Mountain gate?\n"
"Well, I have to give\n"
"you a good deal then!"
)

