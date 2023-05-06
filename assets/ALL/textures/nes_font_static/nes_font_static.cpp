#include "z64.h"
#include "nes_font_static.h"

u8 gMsgChar20SpaceTex[] = {
#include "textures/nes_font_static/msg_char_20_space.i4.inc.c"
};

u8 gMsgChar21ExclamationMarkTex[] = {
#include "textures/nes_font_static/msg_char_21_exclamation_mark.i4.inc.c"
};

u8 gMsgChar22QuotationMarkTex[] = {
#include "textures/nes_font_static/msg_char_22_quotation_mark.i4.inc.c"
};

u8 gMsgChar23NumberSignTex[] = {
#include "textures/nes_font_static/msg_char_23_number_sign.i4.inc.c"
};

u8 gMsgChar24DollarSignTex[] = {
#include "textures/nes_font_static/msg_char_24_dollar_sign.i4.inc.c"
};

u8 gMsgChar25PercentSignTex[] = {
#include "textures/nes_font_static/msg_char_25_percent_sign.i4.inc.c"
};

u8 gMsgChar26AmpersandTex[] = {
#include "textures/nes_font_static/msg_char_26_ampersand.i4.inc.c"
};

u8 gMsgChar27ApostropheTex[] = {
#include "textures/nes_font_static/msg_char_27_apostrophe.i4.inc.c"
};

u8 gMsgChar28LeftParenthesesTex[] = {
#include "textures/nes_font_static/msg_char_28_left_parentheses.i4.inc.c"
};

u8 gMsgChar29RightParenthesesTex[] = {
#include "textures/nes_font_static/msg_char_29_right_parentheses.i4.inc.c"
};

u8 gMsgChar2AAsteriskTex[] = {
#include "textures/nes_font_static/msg_char_2a_asterisk.i4.inc.c"
};

u8 gMsgChar2BPlusSignTex[] = {
#include "textures/nes_font_static/msg_char_2b_plus_sign.i4.inc.c"
};

u8 gMsgChar2CCommaTex[] = {
#include "textures/nes_font_static/msg_char_2c_comma.i4.inc.c"
};

u8 gMsgChar2DHyphenMinusTex[] = {
#include "textures/nes_font_static/msg_char_2d_hyphen_minus.i4.inc.c"
};

u8 gMsgChar2EFullStopTex[] = {
#include "textures/nes_font_static/msg_char_2e_full_stop.i4.inc.c"
};

u8 gMsgChar2FSolidusTex[] = {
#include "textures/nes_font_static/msg_char_2f_solidus.i4.inc.c"
};

u8 gMsgChar30Digit0Tex[] = {
#include "textures/nes_font_static/msg_char_30_digit_0.i4.inc.c"
};

u8 gMsgChar31Digit1Tex[] = {
#include "textures/nes_font_static/msg_char_31_digit_1.i4.inc.c"
};

u8 gMsgChar32Digit2Tex[] = {
#include "textures/nes_font_static/msg_char_32_digit_2.i4.inc.c"
};

u8 gMsgChar33Digit3Tex[] = {
#include "textures/nes_font_static/msg_char_33_digit_3.i4.inc.c"
};

u8 gMsgChar34Digit4Tex[] = {
#include "textures/nes_font_static/msg_char_34_digit_4.i4.inc.c"
};

u8 gMsgChar35Digit5Tex[] = {
#include "textures/nes_font_static/msg_char_35_digit_5.i4.inc.c"
};

u8 gMsgChar36Digit6Tex[] = {
#include "textures/nes_font_static/msg_char_36_digit_6.i4.inc.c"
};

u8 gMsgChar37Digit7Tex[] = {
#include "textures/nes_font_static/msg_char_37_digit_7.i4.inc.c"
};

u8 gMsgChar38Digit8Tex[] = {
#include "textures/nes_font_static/msg_char_38_digit_8.i4.inc.c"
};

u8 gMsgChar39Digit9Tex[] = {
#include "textures/nes_font_static/msg_char_39_digit_9.i4.inc.c"
};

u8 gMsgChar3AColonTex[] = {
#include "textures/nes_font_static/msg_char_3a_colon.i4.inc.c"
};

u8 gMsgChar3BSemicolonTex[] = {
#include "textures/nes_font_static/msg_char_3b_semicolon.i4.inc.c"
};

u8 gMsgChar3CLessThanSignTex[] = {
#include "textures/nes_font_static/msg_char_3c_less_than_sign.i4.inc.c"
};

u8 gMsgChar3DEqualsSignTex[] = {
#include "textures/nes_font_static/msg_char_3d_equals_sign.i4.inc.c"
};

u8 gMsgChar3EGreaterThanSignTex[] = {
#include "textures/nes_font_static/msg_char_3e_greater_than_sign.i4.inc.c"
};

u8 gMsgChar3FQuestionMarkTex[] = {
#include "textures/nes_font_static/msg_char_3f_question_mark.i4.inc.c"
};

u8 gMsgChar40CommercialAtTex[] = {
#include "textures/nes_font_static/msg_char_40_commercial_at.i4.inc.c"
};

u8 gMsgChar41LatinCapitalLetterATex[] = {
#include "textures/nes_font_static/msg_char_41_latin_capital_letter_a.i4.inc.c"
};

u8 gMsgChar42LatinCapitalLetterBTex[] = {
#include "textures/nes_font_static/msg_char_42_latin_capital_letter_b.i4.inc.c"
};

u8 gMsgChar43LatinCapitalLetterCTex[] = {
#include "textures/nes_font_static/msg_char_43_latin_capital_letter_c.i4.inc.c"
};

u8 gMsgChar44LatinCapitalLetterDTex[] = {
#include "textures/nes_font_static/msg_char_44_latin_capital_letter_d.i4.inc.c"
};

u8 gMsgChar45LatinCapitalLetterETex[] = {
#include "textures/nes_font_static/msg_char_45_latin_capital_letter_e.i4.inc.c"
};

u8 gMsgChar46LatinCapitalLetterFTex[] = {
#include "textures/nes_font_static/msg_char_46_latin_capital_letter_f.i4.inc.c"
};

u8 gMsgChar47LatinCapitalLetterGTex[] = {
#include "textures/nes_font_static/msg_char_47_latin_capital_letter_g.i4.inc.c"
};

u8 gMsgChar48LatinCapitalLetterHTex[] = {
#include "textures/nes_font_static/msg_char_48_latin_capital_letter_h.i4.inc.c"
};

u8 gMsgChar49LatinCapitalLetterITex[] = {
#include "textures/nes_font_static/msg_char_49_latin_capital_letter_i.i4.inc.c"
};

u8 gMsgChar4ALatinCapitalLetterJTex[] = {
#include "textures/nes_font_static/msg_char_4a_latin_capital_letter_j.i4.inc.c"
};

u8 gMsgChar4BLatinCapitalLetterKTex[] = {
#include "textures/nes_font_static/msg_char_4b_latin_capital_letter_k.i4.inc.c"
};

u8 gMsgChar4CLatinCapitalLetterLTex[] = {
#include "textures/nes_font_static/msg_char_4c_latin_capital_letter_l.i4.inc.c"
};

u8 gMsgChar4DLatinCapitalLetterMTex[] = {
#include "textures/nes_font_static/msg_char_4d_latin_capital_letter_m.i4.inc.c"
};

u8 gMsgChar4ELatinCapitalLetterNTex[] = {
#include "textures/nes_font_static/msg_char_4e_latin_capital_letter_n.i4.inc.c"
};

u8 gMsgChar4FLatinCapitalLetterOTex[] = {
#include "textures/nes_font_static/msg_char_4f_latin_capital_letter_o.i4.inc.c"
};

u8 gMsgChar50LatinCapitalLetterPTex[] = {
#include "textures/nes_font_static/msg_char_50_latin_capital_letter_p.i4.inc.c"
};

u8 gMsgChar51LatinCapitalLetterQTex[] = {
#include "textures/nes_font_static/msg_char_51_latin_capital_letter_q.i4.inc.c"
};

u8 gMsgChar52LatinCapitalLetterRTex[] = {
#include "textures/nes_font_static/msg_char_52_latin_capital_letter_r.i4.inc.c"
};

u8 gMsgChar53LatinCapitalLetterSTex[] = {
#include "textures/nes_font_static/msg_char_53_latin_capital_letter_s.i4.inc.c"
};

u8 gMsgChar54LatinCapitalLetterTTex[] = {
#include "textures/nes_font_static/msg_char_54_latin_capital_letter_t.i4.inc.c"
};

u8 gMsgChar55LatinCapitalLetterUTex[] = {
#include "textures/nes_font_static/msg_char_55_latin_capital_letter_u.i4.inc.c"
};

u8 gMsgChar56LatinCapitalLetterVTex[] = {
#include "textures/nes_font_static/msg_char_56_latin_capital_letter_v.i4.inc.c"
};

u8 gMsgChar57LatinCapitalLetterWTex[] = {
#include "textures/nes_font_static/msg_char_57_latin_capital_letter_w.i4.inc.c"
};

u8 gMsgChar58LatinCapitalLetterXTex[] = {
#include "textures/nes_font_static/msg_char_58_latin_capital_letter_x.i4.inc.c"
};

u8 gMsgChar59LatinCapitalLetterYTex[] = {
#include "textures/nes_font_static/msg_char_59_latin_capital_letter_y.i4.inc.c"
};

u8 gMsgChar5ALatinCapitalLetterZTex[] = {
#include "textures/nes_font_static/msg_char_5a_latin_capital_letter_z.i4.inc.c"
};

u8 gMsgChar5BLeftSquareBracketTex[] = {
#include "textures/nes_font_static/msg_char_5b_left_square_bracket.i4.inc.c"
};

u8 gMsgChar5CYenSignTex[] = {
#include "textures/nes_font_static/msg_char_5c_yen_sign.i4.inc.c"
};

u8 gMsgChar5DRightSquareBracketTex[] = {
#include "textures/nes_font_static/msg_char_5d_right_square_bracket.i4.inc.c"
};

u8 gMsgChar5ECircumflexAccentTex[] = {
#include "textures/nes_font_static/msg_char_5e_circumflex_accent.i4.inc.c"
};

u8 gMsgChar5FLowLineTex[] = {
#include "textures/nes_font_static/msg_char_5f_low_line.i4.inc.c"
};

u8 gMsgChar60GraveAccentTex[] = {
#include "textures/nes_font_static/msg_char_60_grave_accent.i4.inc.c"
};

u8 gMsgChar61LatinSmallLetterATex[] = {
#include "textures/nes_font_static/msg_char_61_latin_small_letter_a.i4.inc.c"
};

u8 gMsgChar62LatinSmallLetterBTex[] = {
#include "textures/nes_font_static/msg_char_62_latin_small_letter_b.i4.inc.c"
};

u8 gMsgChar63LatinSmallLetterCTex[] = {
#include "textures/nes_font_static/msg_char_63_latin_small_letter_c.i4.inc.c"
};

u8 gMsgChar64LatinSmallLetterDTex[] = {
#include "textures/nes_font_static/msg_char_64_latin_small_letter_d.i4.inc.c"
};

u8 gMsgChar65LatinSmallLetterETex[] = {
#include "textures/nes_font_static/msg_char_65_latin_small_letter_e.i4.inc.c"
};

u8 gMsgChar66LatinSmallLetterFTex[] = {
#include "textures/nes_font_static/msg_char_66_latin_small_letter_f.i4.inc.c"
};

u8 gMsgChar67LatinSmallLetterGTex[] = {
#include "textures/nes_font_static/msg_char_67_latin_small_letter_g.i4.inc.c"
};

u8 gMsgChar68LatinSmallLetterHTex[] = {
#include "textures/nes_font_static/msg_char_68_latin_small_letter_h.i4.inc.c"
};

u8 gMsgChar69LatinSmallLetterITex[] = {
#include "textures/nes_font_static/msg_char_69_latin_small_letter_i.i4.inc.c"
};

u8 gMsgChar6ALatinSmallLetterJTex[] = {
#include "textures/nes_font_static/msg_char_6a_latin_small_letter_j.i4.inc.c"
};

u8 gMsgChar6BLatinSmallLetterKTex[] = {
#include "textures/nes_font_static/msg_char_6b_latin_small_letter_k.i4.inc.c"
};

u8 gMsgChar6CLatinSmallLetterLTex[] = {
#include "textures/nes_font_static/msg_char_6c_latin_small_letter_l.i4.inc.c"
};

u8 gMsgChar6DLatinSmallLetterMTex[] = {
#include "textures/nes_font_static/msg_char_6d_latin_small_letter_m.i4.inc.c"
};

u8 gMsgChar6ELatinSmallLetterNTex[] = {
#include "textures/nes_font_static/msg_char_6e_latin_small_letter_n.i4.inc.c"
};

u8 gMsgChar6FLatinSmallLetterOTex[] = {
#include "textures/nes_font_static/msg_char_6f_latin_small_letter_o.i4.inc.c"
};

u8 gMsgChar70LatinSmallLetterPTex[] = {
#include "textures/nes_font_static/msg_char_70_latin_small_letter_p.i4.inc.c"
};

u8 gMsgChar71LatinSmallLetterQTex[] = {
#include "textures/nes_font_static/msg_char_71_latin_small_letter_q.i4.inc.c"
};

u8 gMsgChar72LatinSmallLetterRTex[] = {
#include "textures/nes_font_static/msg_char_72_latin_small_letter_r.i4.inc.c"
};

u8 gMsgChar73LatinSmallLetterSTex[] = {
#include "textures/nes_font_static/msg_char_73_latin_small_letter_s.i4.inc.c"
};

u8 gMsgChar74LatinSmallLetterTTex[] = {
#include "textures/nes_font_static/msg_char_74_latin_small_letter_t.i4.inc.c"
};

u8 gMsgChar75LatinSmallLetterUTex[] = {
#include "textures/nes_font_static/msg_char_75_latin_small_letter_u.i4.inc.c"
};

u8 gMsgChar76LatinSmallLetterVTex[] = {
#include "textures/nes_font_static/msg_char_76_latin_small_letter_v.i4.inc.c"
};

u8 gMsgChar77LatinSmallLetterWTex[] = {
#include "textures/nes_font_static/msg_char_77_latin_small_letter_w.i4.inc.c"
};

u8 gMsgChar78LatinSmallLetterXTex[] = {
#include "textures/nes_font_static/msg_char_78_latin_small_letter_x.i4.inc.c"
};

u8 gMsgChar79LatinSmallLetterYTex[] = {
#include "textures/nes_font_static/msg_char_79_latin_small_letter_y.i4.inc.c"
};

u8 gMsgChar7ALatinSmallLetterZTex[] = {
#include "textures/nes_font_static/msg_char_7a_latin_small_letter_z.i4.inc.c"
};

u8 gMsgChar7BLeftCurlyBracketTex[] = {
#include "textures/nes_font_static/msg_char_7b_left_curly_bracket.i4.inc.c"
};

u8 gMsgChar7CVerticalLineTex[] = {
#include "textures/nes_font_static/msg_char_7c_vertical_line.i4.inc.c"
};

u8 gMsgChar7DRightCurlyBracketTex[] = {
#include "textures/nes_font_static/msg_char_7d_right_curly_bracket.i4.inc.c"
};

u8 gMsgChar7ETildeTex[] = {
#include "textures/nes_font_static/msg_char_7e_tilde.i4.inc.c"
};

u8 gMsgChar7FBlankTex[] = {
#include "textures/nes_font_static/msg_char_7f_blank.i4.inc.c"
};

u8 gMsgChar80LatinCapitalLetterAWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_80_latin_capital_letter_a_with_grave.i4.inc.c"
};

u8 gMsgChar81LatinCapitalLetterIWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_81_latin_capital_letter_i_with_circumflex.i4.inc.c"
};

u8 gMsgChar82LatinCapitalLetterAWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_82_latin_capital_letter_a_with_circumflex.i4.inc.c"
};

u8 gMsgChar83LatinCapitalLetterAWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_83_latin_capital_letter_a_with_diaeresis.i4.inc.c"
};

u8 gMsgChar84LatinCapitalLetterCWithCedillaTex[] = {
#include "textures/nes_font_static/msg_char_84_latin_capital_letter_c_with_cedilla.i4.inc.c"
};

u8 gMsgChar85LatinCapitalLetterEWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_85_latin_capital_letter_e_with_grave.i4.inc.c"
};

u8 gMsgChar86LatinCapitalLetterEWithAcuteTex[] = {
#include "textures/nes_font_static/msg_char_86_latin_capital_letter_e_with_acute.i4.inc.c"
};

u8 gMsgChar87LatinCapitalLetterEWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_87_latin_capital_letter_e_with_circumflex.i4.inc.c"
};

u8 gMsgChar88LatinCapitalLetterEWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_88_latin_capital_letter_e_with_diaeresis.i4.inc.c"
};

u8 gMsgChar89LatinCapitalLetterIWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_89_latin_capital_letter_i_with_diaeresis.i4.inc.c"
};

u8 gMsgChar8ALatinCapitalLetterOWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_8a_latin_capital_letter_o_with_circumflex.i4.inc.c"
};

u8 gMsgChar8BLatinCapitalLetterOWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_8b_latin_capital_letter_o_with_diaeresis.i4.inc.c"
};

u8 gMsgChar8CLatinCapitalLetterUWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_8c_latin_capital_letter_u_with_grave.i4.inc.c"
};

u8 gMsgChar8DLatinCapitalLetterUWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_8d_latin_capital_letter_u_with_circumflex.i4.inc.c"
};

u8 gMsgChar8ELatinCapitalLetterUWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_8e_latin_capital_letter_u_with_diaeresis.i4.inc.c"
};

u8 gMsgChar8FLatinSmallLetterSharpSTex[] = {
#include "textures/nes_font_static/msg_char_8f_latin_small_letter_sharp_s.i4.inc.c"
};

u8 gMsgChar90LatinSmallLetterAWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_90_latin_small_letter_a_with_grave.i4.inc.c"
};

u8 gMsgChar91LatinSmallLetterAWithAcuteTex[] = {
#include "textures/nes_font_static/msg_char_91_latin_small_letter_a_with_acute.i4.inc.c"
};

u8 gMsgChar92LatinSmallLetterAWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_92_latin_small_letter_a_with_circumflex.i4.inc.c"
};

u8 gMsgChar93LatinSmallLetterAWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_93_latin_small_letter_a_with_diaeresis.i4.inc.c"
};

u8 gMsgChar94LatinSmallLetterCWithCedillaTex[] = {
#include "textures/nes_font_static/msg_char_94_latin_small_letter_c_with_cedilla.i4.inc.c"
};

u8 gMsgChar95LatinSmallLetterEWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_95_latin_small_letter_e_with_grave.i4.inc.c"
};

u8 gMsgChar96LatinSmallLetterEWithAcuteTex[] = {
#include "textures/nes_font_static/msg_char_96_latin_small_letter_e_with_acute.i4.inc.c"
};

u8 gMsgChar97LatinSmallLetterEWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_97_latin_small_letter_e_with_circumflex.i4.inc.c"
};

u8 gMsgChar98LatinSmallLetterEWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_98_latin_small_letter_e_with_diaeresis.i4.inc.c"
};

u8 gMsgChar99LatinSmallLetterIWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_99_latin_small_letter_i_with_diaeresis.i4.inc.c"
};

u8 gMsgChar9ALatinSmallLetterOWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_9a_latin_small_letter_o_with_circumflex.i4.inc.c"
};

u8 gMsgChar9BLatinSmallLetterOWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_9b_latin_small_letter_o_with_diaeresis.i4.inc.c"
};

u8 gMsgChar9CLatinSmallLetterUWithGraveTex[] = {
#include "textures/nes_font_static/msg_char_9c_latin_small_letter_u_with_grave.i4.inc.c"
};

u8 gMsgChar9DLatinSmallLetterUWithCircumflexTex[] = {
#include "textures/nes_font_static/msg_char_9d_latin_small_letter_u_with_circumflex.i4.inc.c"
};

u8 gMsgChar9ELatinSmallLetterUWithDiaeresisTex[] = {
#include "textures/nes_font_static/msg_char_9e_latin_small_letter_u_with_diaeresis.i4.inc.c"
};

u8 gMsgChar9FButtonATex[] = {
#include "textures/nes_font_static/msg_char_9f_button_a.i4.inc.c"
};

u8 gMsgCharA0ButtonBTex[] = {
#include "textures/nes_font_static/msg_char_a0_button_b.i4.inc.c"
};

u8 gMsgCharA1ButtonCTex[] = {
#include "textures/nes_font_static/msg_char_a1_button_c.i4.inc.c"
};

u8 gMsgCharA2ButtonLTex[] = {
#include "textures/nes_font_static/msg_char_a2_button_l.i4.inc.c"
};

u8 gMsgCharA3ButtonRTex[] = {
#include "textures/nes_font_static/msg_char_a3_button_r.i4.inc.c"
};

u8 gMsgCharA4ButtonZTex[] = {
#include "textures/nes_font_static/msg_char_a4_button_z.i4.inc.c"
};

u8 gMsgCharA5ButtonCUpTex[] = {
#include "textures/nes_font_static/msg_char_a5_button_c_up.i4.inc.c"
};

u8 gMsgCharA6ButtonCDownTex[] = {
#include "textures/nes_font_static/msg_char_a6_button_c_down.i4.inc.c"
};

u8 gMsgCharA7ButtonCLeftTex[] = {
#include "textures/nes_font_static/msg_char_a7_button_c_left.i4.inc.c"
};

u8 gMsgCharA8ButtonCRightTex[] = {
#include "textures/nes_font_static/msg_char_a8_button_c_right.i4.inc.c"
};

u8 gMsgCharA9ZTargetSignTex[] = {
#include "textures/nes_font_static/msg_char_a9_z_target_sign.i4.inc.c"
};

u8 gMsgCharAAControlStickTex[] = {
#include "textures/nes_font_static/msg_char_aa_control_stick.i4.inc.c"
};

u8 gMsgCharABControlPadTex[] = {
#ifndef RETAIL
    #include "textures/nes_font_static/msg_char_ab_control_pad.i4.inc.c"
#else
    #include "textures/nes_font_static/generated/msg_char_ab_control_pad.i4.inc.c"
#endif
};

// Additional chars

u8 gMsgCharACLatinCapitalLetterIWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_ac_latin_capital_letter_i_with_acute.i4.inc.c"
};

u8 gMsgCharADLatinCapitalLetterOWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_ad_latin_capital_letter_o_with_acute.i4.inc.c"
};

u8 gMsgCharAELatinCapitalLetterUWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_ae_latin_capital_letter_u_with_acute.i4.inc.c"
};

u8 gMsgCharAFLatinSmallLetterIWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_af_latin_small_letter_i_with_acute.i4.inc.c"
};

u8 gMsgCharB0LatinSmallLetterOWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_b0_latin_small_letter_o_with_acute.i4.inc.c"
};

u8 gMsgCharB1LatinSmallLetterUWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_b1_latin_small_letter_u_with_acute.i4.inc.c"
};

u8 gMsgCharB2InvertedQuestionMarkTex[] = {
#include "textures/nes_font_static/generated/msg_char_b2_inverted_question_mark.i4.inc.c"
};

u8 gMsgCharB3InvertedExclamationMarkTex[] = {
#include "textures/nes_font_static/generated/msg_char_b3_inverted_exclamation_mark.i4.inc.c"
};

u8 gMsgCharB4LatinCapitalLetterAWithAcuteTex[] = {
#include "textures/nes_font_static/generated/msg_char_b4_latin_capital_letter_a_with_acute.i4.inc.c"
};

u8 gMsgCharB5LatinCapitalLetterNWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_b5_latin_capital_letter_n_with_tilde.i4.inc.c"
};

u8 gMsgCharB6LatinSmallLetterNWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_b6_latin_small_letter_n_with_tilde.i4.inc.c"
};

u8 gMsgCharB7LatinCapitalLetterAWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_b7_latin_capital_letter_a_with_tilde.i4.inc.c"
};

u8 gMsgCharB8LatinCapitalLetterOWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_b8_latin_capital_letter_o_with_tilde.i4.inc.c"
};

u8 gMsgCharB9LatinSmallLetterAWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_b9_latin_small_letter_a_with_tilde.i4.inc.c"
};

u8 gMsgCharBALatinSmallLetterOWithTildeTex[] = {
#include "textures/nes_font_static/generated/msg_char_ba_latin_small_letter_o_with_tilde.i4.inc.c"
};

u8 gMsgCharBBLatinCapitalLetterAWithRingAbove[] = {
#include "textures/nes_font_static/generated/msg_char_bb_latin_capital_letter_a_with_ring_above.i4.inc.c"
};

u8 gMsgCharBCLatinSmallLetterAWithRingAbove[] = {
#include "textures/nes_font_static/generated/msg_char_bc_latin_small_letter_a_with_ring_above.i4.inc.c"
};

u8 _nes_font_staticSegmentRomLastSymbol = 0;