#ifndef TREE_TRUNKS_COLOR_HPP__
#define TREE_TRUNKS_COLOR_HPP__

#ifdef TREE_TRUNKS_UNCOLOR_HPP__
#undef TREE_TRUNKS_UNCOLOR_HPP__
#endif /* TREE_TRUNKS_UNCOLOR_HPP__ */

//https://en.wikipedia.org/wiki/ANSI_escape_code

#define RESET				"0"
#define BOLD				"1"
#define FAINT				"2"
#define ITALIC				"3"
#define UNDERLINE			"4"
#define BLINK_SLOW			"5"
#define BLINK_QUICK			"6"
#define SWAP_FG_BG			"7"
#define CONCEAL				"8"
#define STRIKE				"9"
#define DEFAULT_FONT		"10"
#define ALT_FONT_1			"11"
#define ALT_FONT_2			"12"
#define ALT_FONT_3			"13"
#define ALT_FONT_4			"14"
#define ALT_FONT_5			"15"
#define ALT_FONT_6			"16"
#define ALT_FONT_7			"17"
#define ALT_FONT_8			"18"
#define ALT_FONT_9			"19"
#define FRAKTUR_FONT		"20"
#define BOLD_OFF			"21"
#define BOLD_FAINT_OFF		"22"
#define ITALIC_OFF			"23"
#define UNDERLINE_OFF		"24"
#define BLINK_OFF			"25"
#define UNDO_SWAP			"27"
#define CONCEAL_OFF			"28"
#define STRIKE_OFF			"29"
#define FRAMED				"51"
#define ENCIRCLED			"52"
#define OVERLINED			"53"
#define FRAME_ENCIR_OFF		"54"
#define OVERLINE_OFF		"55"

//Colors
//Foreground
#define FG_BLACK			"30"
#define FG_RED				"31"
#define FG_GREEN			"32"
#define FG_YELLOW			"33"
#define FG_BLUE				"34"
#define FG_MAGENTA			"35"
#define FG_CYAN				"36"
#define FG_WHITE			"37"
#define FG_RGB				"38"
#define FG_DEFAULT			"39"
#define FG_BRIG_BLACK		"90"
#define FG_BRIG_RED			"91"
#define FG_BRIG_GREEN		"92"
#define FG_BRIG_YELLOW		"93"
#define FG_BRIG_BLUE		"94"
#define FG_BRIG_MAGENTA		"95"
#define FG_BRIG_CYAN		"96"
#define FG_BRIG_WHITE		"97"
//Background
#define BG_BLACK			"40"
#define BG_RED				"41"
#define BG_GREEN			"42"
#define BG_YELLOW			"43"
#define BG_BLUE				"44"
#define BG_MAGENTA			"45"
#define BG_CYAN				"46"
#define BG_WHITE			"47"
#define BG_RGB				"48"
#define BG_DEFAULT			"49"
#define BG_BRIG_BLACK		"100"
#define BG_BRIG_RED			"101"
#define BG_BRIG_GREEN		"102"
#define BG_BRIG_YELLOW		"103"
#define BG_BRIG_BLUE		"104"
#define BG_BRIG_MAGENTA		"105"
#define BG_BRIG_CYAN		"106"
#define BG_BRIG_WHITE		"107"

#endif /* TREE_TRUNKS_COLOR_HPP__ */
