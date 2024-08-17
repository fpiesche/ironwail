/* Single-character transliterations (based on Unidecode) */
/*
import sys
import itertools
import unicodedata
from unidecode import unidecode

# unicode ranges
basic_latin             = range(0x0020, 0x007F+1)
latin1_supplement       = range(0x00A0, 0x00FF+1)
latin_extended_a        = range(0x0100, 0x017F+1)
latin_extended_b        = range(0x0180, 0x024F+1)
cyrillic                = range(0x0400, 0x04FF+1)
cyrillic_supplementary  = range(0x0500, 0x052F+1)

def char_literal(c):
    s = chr(c)
    s = s.replace('\\', '\\\\')
    s = s.replace('\'', '\\\'')
    return f"'{s}'"

sys.stdout = open('unicode_translit.h', 'w')
print('/%s Single-character transliterations (based on Unidecode) %s/' % ('*', '*')) # shenanigans to keep the Python code C comment-friendly
with open(__file__, 'r') as source:
    print('/%s\n%s\n%s/' % ('*', source.read(), '*'))
print("static const struct { uint16_t code; char remap[2]; } unicode_translit_src[] =\n{")
for codepoint in itertools.chain(basic_latin, latin1_supplement, latin_extended_a, latin_extended_b, cyrillic, cyrillic_supplementary):
    if 0xd800 <= codepoint <= 0xdfff:
        continue
    srcstr = chr(codepoint)
    src = srcstr.encode()
    translit = unidecode(srcstr).encode()
    if src != translit and 0 < len(translit) <= min(2, len(src)):
        print(f"\t{{{codepoint}, {', '.join([char_literal(c) for c in translit])}}}, // {unicodedata.name(srcstr)}")
print("};")
*/
static const struct { uint16_t code; char remap[2]; } unicode_translit_src[] =
{
	{160, ' '}, // NO-BREAK SPACE
	{161, '!'}, // INVERTED EXCLAMATION MARK
	{162, 'C', '/'}, // CENT SIGN
	{163, 'P', 'S'}, // POUND SIGN
	{164, '$', '?'}, // CURRENCY SIGN
	{165, 'Y', '='}, // YEN SIGN
	{166, '|'}, // BROKEN BAR
	{167, 'S', 'S'}, // SECTION SIGN
	{168, '"'}, // DIAERESIS
	{170, 'a'}, // FEMININE ORDINAL INDICATOR
	{171, '<', '<'}, // LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
	{172, '!'}, // NOT SIGN
	{175, '-'}, // MACRON
	{177, '+', '-'}, // PLUS-MINUS SIGN
	{178, '2'}, // SUPERSCRIPT TWO
	{179, '3'}, // SUPERSCRIPT THREE
	{180, '\''}, // ACUTE ACCENT
	{181, 'u'}, // MICRO SIGN
	{182, 'P'}, // PILCROW SIGN
	{183, '*'}, // MIDDLE DOT
	{184, ','}, // CEDILLA
	{185, '1'}, // SUPERSCRIPT ONE
	{186, 'o'}, // MASCULINE ORDINAL INDICATOR
	{187, '>', '>'}, // RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
	{191, '?'}, // INVERTED QUESTION MARK
	{192, 'A'}, // LATIN CAPITAL LETTER A WITH GRAVE
	{193, 'A'}, // LATIN CAPITAL LETTER A WITH ACUTE
	{194, 'A'}, // LATIN CAPITAL LETTER A WITH CIRCUMFLEX
	{195, 'A'}, // LATIN CAPITAL LETTER A WITH TILDE
	{196, 'A'}, // LATIN CAPITAL LETTER A WITH DIAERESIS
	{197, 'A'}, // LATIN CAPITAL LETTER A WITH RING ABOVE
	{198, 'A', 'E'}, // LATIN CAPITAL LETTER AE
	{199, 'C'}, // LATIN CAPITAL LETTER C WITH CEDILLA
	{200, 'E'}, // LATIN CAPITAL LETTER E WITH GRAVE
	{201, 'E'}, // LATIN CAPITAL LETTER E WITH ACUTE
	{202, 'E'}, // LATIN CAPITAL LETTER E WITH CIRCUMFLEX
	{203, 'E'}, // LATIN CAPITAL LETTER E WITH DIAERESIS
	{204, 'I'}, // LATIN CAPITAL LETTER I WITH GRAVE
	{205, 'I'}, // LATIN CAPITAL LETTER I WITH ACUTE
	{206, 'I'}, // LATIN CAPITAL LETTER I WITH CIRCUMFLEX
	{207, 'I'}, // LATIN CAPITAL LETTER I WITH DIAERESIS
	{208, 'D'}, // LATIN CAPITAL LETTER ETH
	{209, 'N'}, // LATIN CAPITAL LETTER N WITH TILDE
	{210, 'O'}, // LATIN CAPITAL LETTER O WITH GRAVE
	{211, 'O'}, // LATIN CAPITAL LETTER O WITH ACUTE
	{212, 'O'}, // LATIN CAPITAL LETTER O WITH CIRCUMFLEX
	{213, 'O'}, // LATIN CAPITAL LETTER O WITH TILDE
	{214, 'O'}, // LATIN CAPITAL LETTER O WITH DIAERESIS
	{215, 'x'}, // MULTIPLICATION SIGN
	{216, 'O'}, // LATIN CAPITAL LETTER O WITH STROKE
	{217, 'U'}, // LATIN CAPITAL LETTER U WITH GRAVE
	{218, 'U'}, // LATIN CAPITAL LETTER U WITH ACUTE
	{219, 'U'}, // LATIN CAPITAL LETTER U WITH CIRCUMFLEX
	{220, 'U'}, // LATIN CAPITAL LETTER U WITH DIAERESIS
	{221, 'Y'}, // LATIN CAPITAL LETTER Y WITH ACUTE
	{222, 'T', 'h'}, // LATIN CAPITAL LETTER THORN
	{223, 's', 's'}, // LATIN SMALL LETTER SHARP S
	{224, 'a'}, // LATIN SMALL LETTER A WITH GRAVE
	{225, 'a'}, // LATIN SMALL LETTER A WITH ACUTE
	{226, 'a'}, // LATIN SMALL LETTER A WITH CIRCUMFLEX
	{227, 'a'}, // LATIN SMALL LETTER A WITH TILDE
	{228, 'a'}, // LATIN SMALL LETTER A WITH DIAERESIS
	{229, 'a'}, // LATIN SMALL LETTER A WITH RING ABOVE
	{230, 'a', 'e'}, // LATIN SMALL LETTER AE
	{231, 'c'}, // LATIN SMALL LETTER C WITH CEDILLA
	{232, 'e'}, // LATIN SMALL LETTER E WITH GRAVE
	{233, 'e'}, // LATIN SMALL LETTER E WITH ACUTE
	{234, 'e'}, // LATIN SMALL LETTER E WITH CIRCUMFLEX
	{235, 'e'}, // LATIN SMALL LETTER E WITH DIAERESIS
	{236, 'i'}, // LATIN SMALL LETTER I WITH GRAVE
	{237, 'i'}, // LATIN SMALL LETTER I WITH ACUTE
	{238, 'i'}, // LATIN SMALL LETTER I WITH CIRCUMFLEX
	{239, 'i'}, // LATIN SMALL LETTER I WITH DIAERESIS
	{240, 'd'}, // LATIN SMALL LETTER ETH
	{241, 'n'}, // LATIN SMALL LETTER N WITH TILDE
	{242, 'o'}, // LATIN SMALL LETTER O WITH GRAVE
	{243, 'o'}, // LATIN SMALL LETTER O WITH ACUTE
	{244, 'o'}, // LATIN SMALL LETTER O WITH CIRCUMFLEX
	{245, 'o'}, // LATIN SMALL LETTER O WITH TILDE
	{246, 'o'}, // LATIN SMALL LETTER O WITH DIAERESIS
	{247, '/'}, // DIVISION SIGN
	{248, 'o'}, // LATIN SMALL LETTER O WITH STROKE
	{249, 'u'}, // LATIN SMALL LETTER U WITH GRAVE
	{250, 'u'}, // LATIN SMALL LETTER U WITH ACUTE
	{251, 'u'}, // LATIN SMALL LETTER U WITH CIRCUMFLEX
	{252, 'u'}, // LATIN SMALL LETTER U WITH DIAERESIS
	{253, 'y'}, // LATIN SMALL LETTER Y WITH ACUTE
	{254, 't', 'h'}, // LATIN SMALL LETTER THORN
	{255, 'y'}, // LATIN SMALL LETTER Y WITH DIAERESIS
	{256, 'A'}, // LATIN CAPITAL LETTER A WITH MACRON
	{257, 'a'}, // LATIN SMALL LETTER A WITH MACRON
	{258, 'A'}, // LATIN CAPITAL LETTER A WITH BREVE
	{259, 'a'}, // LATIN SMALL LETTER A WITH BREVE
	{260, 'A'}, // LATIN CAPITAL LETTER A WITH OGONEK
	{261, 'a'}, // LATIN SMALL LETTER A WITH OGONEK
	{262, 'C'}, // LATIN CAPITAL LETTER C WITH ACUTE
	{263, 'c'}, // LATIN SMALL LETTER C WITH ACUTE
	{264, 'C'}, // LATIN CAPITAL LETTER C WITH CIRCUMFLEX
	{265, 'c'}, // LATIN SMALL LETTER C WITH CIRCUMFLEX
	{266, 'C'}, // LATIN CAPITAL LETTER C WITH DOT ABOVE
	{267, 'c'}, // LATIN SMALL LETTER C WITH DOT ABOVE
	{268, 'C'}, // LATIN CAPITAL LETTER C WITH CARON
	{269, 'c'}, // LATIN SMALL LETTER C WITH CARON
	{270, 'D'}, // LATIN CAPITAL LETTER D WITH CARON
	{271, 'd'}, // LATIN SMALL LETTER D WITH CARON
	{272, 'D'}, // LATIN CAPITAL LETTER D WITH STROKE
	{273, 'd'}, // LATIN SMALL LETTER D WITH STROKE
	{274, 'E'}, // LATIN CAPITAL LETTER E WITH MACRON
	{275, 'e'}, // LATIN SMALL LETTER E WITH MACRON
	{276, 'E'}, // LATIN CAPITAL LETTER E WITH BREVE
	{277, 'e'}, // LATIN SMALL LETTER E WITH BREVE
	{278, 'E'}, // LATIN CAPITAL LETTER E WITH DOT ABOVE
	{279, 'e'}, // LATIN SMALL LETTER E WITH DOT ABOVE
	{280, 'E'}, // LATIN CAPITAL LETTER E WITH OGONEK
	{281, 'e'}, // LATIN SMALL LETTER E WITH OGONEK
	{282, 'E'}, // LATIN CAPITAL LETTER E WITH CARON
	{283, 'e'}, // LATIN SMALL LETTER E WITH CARON
	{284, 'G'}, // LATIN CAPITAL LETTER G WITH CIRCUMFLEX
	{285, 'g'}, // LATIN SMALL LETTER G WITH CIRCUMFLEX
	{286, 'G'}, // LATIN CAPITAL LETTER G WITH BREVE
	{287, 'g'}, // LATIN SMALL LETTER G WITH BREVE
	{288, 'G'}, // LATIN CAPITAL LETTER G WITH DOT ABOVE
	{289, 'g'}, // LATIN SMALL LETTER G WITH DOT ABOVE
	{290, 'G'}, // LATIN CAPITAL LETTER G WITH CEDILLA
	{291, 'g'}, // LATIN SMALL LETTER G WITH CEDILLA
	{292, 'H'}, // LATIN CAPITAL LETTER H WITH CIRCUMFLEX
	{293, 'h'}, // LATIN SMALL LETTER H WITH CIRCUMFLEX
	{294, 'H'}, // LATIN CAPITAL LETTER H WITH STROKE
	{295, 'h'}, // LATIN SMALL LETTER H WITH STROKE
	{296, 'I'}, // LATIN CAPITAL LETTER I WITH TILDE
	{297, 'i'}, // LATIN SMALL LETTER I WITH TILDE
	{298, 'I'}, // LATIN CAPITAL LETTER I WITH MACRON
	{299, 'i'}, // LATIN SMALL LETTER I WITH MACRON
	{300, 'I'}, // LATIN CAPITAL LETTER I WITH BREVE
	{301, 'i'}, // LATIN SMALL LETTER I WITH BREVE
	{302, 'I'}, // LATIN CAPITAL LETTER I WITH OGONEK
	{303, 'i'}, // LATIN SMALL LETTER I WITH OGONEK
	{304, 'I'}, // LATIN CAPITAL LETTER I WITH DOT ABOVE
	{305, 'i'}, // LATIN SMALL LETTER DOTLESS I
	{306, 'I', 'J'}, // LATIN CAPITAL LIGATURE IJ
	{307, 'i', 'j'}, // LATIN SMALL LIGATURE IJ
	{308, 'J'}, // LATIN CAPITAL LETTER J WITH CIRCUMFLEX
	{309, 'j'}, // LATIN SMALL LETTER J WITH CIRCUMFLEX
	{310, 'K'}, // LATIN CAPITAL LETTER K WITH CEDILLA
	{311, 'k'}, // LATIN SMALL LETTER K WITH CEDILLA
	{312, 'k'}, // LATIN SMALL LETTER KRA
	{313, 'L'}, // LATIN CAPITAL LETTER L WITH ACUTE
	{314, 'l'}, // LATIN SMALL LETTER L WITH ACUTE
	{315, 'L'}, // LATIN CAPITAL LETTER L WITH CEDILLA
	{316, 'l'}, // LATIN SMALL LETTER L WITH CEDILLA
	{317, 'L'}, // LATIN CAPITAL LETTER L WITH CARON
	{318, 'l'}, // LATIN SMALL LETTER L WITH CARON
	{319, 'L'}, // LATIN CAPITAL LETTER L WITH MIDDLE DOT
	{320, 'l'}, // LATIN SMALL LETTER L WITH MIDDLE DOT
	{321, 'L'}, // LATIN CAPITAL LETTER L WITH STROKE
	{322, 'l'}, // LATIN SMALL LETTER L WITH STROKE
	{323, 'N'}, // LATIN CAPITAL LETTER N WITH ACUTE
	{324, 'n'}, // LATIN SMALL LETTER N WITH ACUTE
	{325, 'N'}, // LATIN CAPITAL LETTER N WITH CEDILLA
	{326, 'n'}, // LATIN SMALL LETTER N WITH CEDILLA
	{327, 'N'}, // LATIN CAPITAL LETTER N WITH CARON
	{328, 'n'}, // LATIN SMALL LETTER N WITH CARON
	{329, '\'', 'n'}, // LATIN SMALL LETTER N PRECEDED BY APOSTROPHE
	{330, 'n', 'g'}, // LATIN CAPITAL LETTER ENG
	{331, 'N', 'G'}, // LATIN SMALL LETTER ENG
	{332, 'O'}, // LATIN CAPITAL LETTER O WITH MACRON
	{333, 'o'}, // LATIN SMALL LETTER O WITH MACRON
	{334, 'O'}, // LATIN CAPITAL LETTER O WITH BREVE
	{335, 'o'}, // LATIN SMALL LETTER O WITH BREVE
	{336, 'O'}, // LATIN CAPITAL LETTER O WITH DOUBLE ACUTE
	{337, 'o'}, // LATIN SMALL LETTER O WITH DOUBLE ACUTE
	{338, 'O', 'E'}, // LATIN CAPITAL LIGATURE OE
	{339, 'o', 'e'}, // LATIN SMALL LIGATURE OE
	{340, 'R'}, // LATIN CAPITAL LETTER R WITH ACUTE
	{341, 'r'}, // LATIN SMALL LETTER R WITH ACUTE
	{342, 'R'}, // LATIN CAPITAL LETTER R WITH CEDILLA
	{343, 'r'}, // LATIN SMALL LETTER R WITH CEDILLA
	{344, 'R'}, // LATIN CAPITAL LETTER R WITH CARON
	{345, 'r'}, // LATIN SMALL LETTER R WITH CARON
	{346, 'S'}, // LATIN CAPITAL LETTER S WITH ACUTE
	{347, 's'}, // LATIN SMALL LETTER S WITH ACUTE
	{348, 'S'}, // LATIN CAPITAL LETTER S WITH CIRCUMFLEX
	{349, 's'}, // LATIN SMALL LETTER S WITH CIRCUMFLEX
	{350, 'S'}, // LATIN CAPITAL LETTER S WITH CEDILLA
	{351, 's'}, // LATIN SMALL LETTER S WITH CEDILLA
	{352, 'S'}, // LATIN CAPITAL LETTER S WITH CARON
	{353, 's'}, // LATIN SMALL LETTER S WITH CARON
	{354, 'T'}, // LATIN CAPITAL LETTER T WITH CEDILLA
	{355, 't'}, // LATIN SMALL LETTER T WITH CEDILLA
	{356, 'T'}, // LATIN CAPITAL LETTER T WITH CARON
	{357, 't'}, // LATIN SMALL LETTER T WITH CARON
	{358, 'T'}, // LATIN CAPITAL LETTER T WITH STROKE
	{359, 't'}, // LATIN SMALL LETTER T WITH STROKE
	{360, 'U'}, // LATIN CAPITAL LETTER U WITH TILDE
	{361, 'u'}, // LATIN SMALL LETTER U WITH TILDE
	{362, 'U'}, // LATIN CAPITAL LETTER U WITH MACRON
	{363, 'u'}, // LATIN SMALL LETTER U WITH MACRON
	{364, 'U'}, // LATIN CAPITAL LETTER U WITH BREVE
	{365, 'u'}, // LATIN SMALL LETTER U WITH BREVE
	{366, 'U'}, // LATIN CAPITAL LETTER U WITH RING ABOVE
	{367, 'u'}, // LATIN SMALL LETTER U WITH RING ABOVE
	{368, 'U'}, // LATIN CAPITAL LETTER U WITH DOUBLE ACUTE
	{369, 'u'}, // LATIN SMALL LETTER U WITH DOUBLE ACUTE
	{370, 'U'}, // LATIN CAPITAL LETTER U WITH OGONEK
	{371, 'u'}, // LATIN SMALL LETTER U WITH OGONEK
	{372, 'W'}, // LATIN CAPITAL LETTER W WITH CIRCUMFLEX
	{373, 'w'}, // LATIN SMALL LETTER W WITH CIRCUMFLEX
	{374, 'Y'}, // LATIN CAPITAL LETTER Y WITH CIRCUMFLEX
	{375, 'y'}, // LATIN SMALL LETTER Y WITH CIRCUMFLEX
	{376, 'Y'}, // LATIN CAPITAL LETTER Y WITH DIAERESIS
	{377, 'Z'}, // LATIN CAPITAL LETTER Z WITH ACUTE
	{378, 'z'}, // LATIN SMALL LETTER Z WITH ACUTE
	{379, 'Z'}, // LATIN CAPITAL LETTER Z WITH DOT ABOVE
	{380, 'z'}, // LATIN SMALL LETTER Z WITH DOT ABOVE
	{381, 'Z'}, // LATIN CAPITAL LETTER Z WITH CARON
	{382, 'z'}, // LATIN SMALL LETTER Z WITH CARON
	{383, 's'}, // LATIN SMALL LETTER LONG S
	{384, 'b'}, // LATIN SMALL LETTER B WITH STROKE
	{385, 'B'}, // LATIN CAPITAL LETTER B WITH HOOK
	{386, 'B'}, // LATIN CAPITAL LETTER B WITH TOPBAR
	{387, 'b'}, // LATIN SMALL LETTER B WITH TOPBAR
	{388, '6'}, // LATIN CAPITAL LETTER TONE SIX
	{389, '6'}, // LATIN SMALL LETTER TONE SIX
	{390, 'O'}, // LATIN CAPITAL LETTER OPEN O
	{391, 'C'}, // LATIN CAPITAL LETTER C WITH HOOK
	{392, 'c'}, // LATIN SMALL LETTER C WITH HOOK
	{393, 'D'}, // LATIN CAPITAL LETTER AFRICAN D
	{394, 'D'}, // LATIN CAPITAL LETTER D WITH HOOK
	{395, 'D'}, // LATIN CAPITAL LETTER D WITH TOPBAR
	{396, 'd'}, // LATIN SMALL LETTER D WITH TOPBAR
	{397, 'd'}, // LATIN SMALL LETTER TURNED DELTA
	{398, '3'}, // LATIN CAPITAL LETTER REVERSED E
	{399, '@'}, // LATIN CAPITAL LETTER SCHWA
	{400, 'E'}, // LATIN CAPITAL LETTER OPEN E
	{401, 'F'}, // LATIN CAPITAL LETTER F WITH HOOK
	{402, 'f'}, // LATIN SMALL LETTER F WITH HOOK
	{403, 'G'}, // LATIN CAPITAL LETTER G WITH HOOK
	{404, 'G'}, // LATIN CAPITAL LETTER GAMMA
	{405, 'h', 'v'}, // LATIN SMALL LETTER HV
	{406, 'I'}, // LATIN CAPITAL LETTER IOTA
	{407, 'I'}, // LATIN CAPITAL LETTER I WITH STROKE
	{408, 'K'}, // LATIN CAPITAL LETTER K WITH HOOK
	{409, 'k'}, // LATIN SMALL LETTER K WITH HOOK
	{410, 'l'}, // LATIN SMALL LETTER L WITH BAR
	{411, 'l'}, // LATIN SMALL LETTER LAMBDA WITH STROKE
	{412, 'W'}, // LATIN CAPITAL LETTER TURNED M
	{413, 'N'}, // LATIN CAPITAL LETTER N WITH LEFT HOOK
	{414, 'n'}, // LATIN SMALL LETTER N WITH LONG RIGHT LEG
	{415, 'O'}, // LATIN CAPITAL LETTER O WITH MIDDLE TILDE
	{416, 'O'}, // LATIN CAPITAL LETTER O WITH HORN
	{417, 'o'}, // LATIN SMALL LETTER O WITH HORN
	{418, 'O', 'I'}, // LATIN CAPITAL LETTER OI
	{419, 'o', 'i'}, // LATIN SMALL LETTER OI
	{420, 'P'}, // LATIN CAPITAL LETTER P WITH HOOK
	{421, 'p'}, // LATIN SMALL LETTER P WITH HOOK
	{422, 'Y', 'R'}, // LATIN LETTER YR
	{423, '2'}, // LATIN CAPITAL LETTER TONE TWO
	{424, '2'}, // LATIN SMALL LETTER TONE TWO
	{425, 'S', 'H'}, // LATIN CAPITAL LETTER ESH
	{426, 's', 'h'}, // LATIN LETTER REVERSED ESH LOOP
	{427, 't'}, // LATIN SMALL LETTER T WITH PALATAL HOOK
	{428, 'T'}, // LATIN CAPITAL LETTER T WITH HOOK
	{429, 't'}, // LATIN SMALL LETTER T WITH HOOK
	{430, 'T'}, // LATIN CAPITAL LETTER T WITH RETROFLEX HOOK
	{431, 'U'}, // LATIN CAPITAL LETTER U WITH HORN
	{432, 'u'}, // LATIN SMALL LETTER U WITH HORN
	{433, 'Y'}, // LATIN CAPITAL LETTER UPSILON
	{434, 'V'}, // LATIN CAPITAL LETTER V WITH HOOK
	{435, 'Y'}, // LATIN CAPITAL LETTER Y WITH HOOK
	{436, 'y'}, // LATIN SMALL LETTER Y WITH HOOK
	{437, 'Z'}, // LATIN CAPITAL LETTER Z WITH STROKE
	{438, 'z'}, // LATIN SMALL LETTER Z WITH STROKE
	{439, 'Z', 'H'}, // LATIN CAPITAL LETTER EZH
	{440, 'Z', 'H'}, // LATIN CAPITAL LETTER EZH REVERSED
	{441, 'z', 'h'}, // LATIN SMALL LETTER EZH REVERSED
	{442, 'z', 'h'}, // LATIN SMALL LETTER EZH WITH TAIL
	{443, '2'}, // LATIN LETTER TWO WITH STROKE
	{444, '5'}, // LATIN CAPITAL LETTER TONE FIVE
	{445, '5'}, // LATIN SMALL LETTER TONE FIVE
	{446, 't', 's'}, // LATIN LETTER INVERTED GLOTTAL STOP WITH STROKE
	{447, 'w'}, // LATIN LETTER WYNN
	{448, '|'}, // LATIN LETTER DENTAL CLICK
	{449, '|', '|'}, // LATIN LETTER LATERAL CLICK
	{450, '|', '='}, // LATIN LETTER ALVEOLAR CLICK
	{451, '!'}, // LATIN LETTER RETROFLEX CLICK
	{452, 'D', 'Z'}, // LATIN CAPITAL LETTER DZ WITH CARON
	{453, 'D', 'z'}, // LATIN CAPITAL LETTER D WITH SMALL LETTER Z WITH CARON
	{454, 'd', 'z'}, // LATIN SMALL LETTER DZ WITH CARON
	{455, 'L', 'J'}, // LATIN CAPITAL LETTER LJ
	{456, 'L', 'j'}, // LATIN CAPITAL LETTER L WITH SMALL LETTER J
	{457, 'l', 'j'}, // LATIN SMALL LETTER LJ
	{458, 'N', 'J'}, // LATIN CAPITAL LETTER NJ
	{459, 'N', 'j'}, // LATIN CAPITAL LETTER N WITH SMALL LETTER J
	{460, 'n', 'j'}, // LATIN SMALL LETTER NJ
	{461, 'A'}, // LATIN CAPITAL LETTER A WITH CARON
	{462, 'a'}, // LATIN SMALL LETTER A WITH CARON
	{463, 'I'}, // LATIN CAPITAL LETTER I WITH CARON
	{464, 'i'}, // LATIN SMALL LETTER I WITH CARON
	{465, 'O'}, // LATIN CAPITAL LETTER O WITH CARON
	{466, 'o'}, // LATIN SMALL LETTER O WITH CARON
	{467, 'U'}, // LATIN CAPITAL LETTER U WITH CARON
	{468, 'u'}, // LATIN SMALL LETTER U WITH CARON
	{469, 'U'}, // LATIN CAPITAL LETTER U WITH DIAERESIS AND MACRON
	{470, 'u'}, // LATIN SMALL LETTER U WITH DIAERESIS AND MACRON
	{471, 'U'}, // LATIN CAPITAL LETTER U WITH DIAERESIS AND ACUTE
	{472, 'u'}, // LATIN SMALL LETTER U WITH DIAERESIS AND ACUTE
	{473, 'U'}, // LATIN CAPITAL LETTER U WITH DIAERESIS AND CARON
	{474, 'u'}, // LATIN SMALL LETTER U WITH DIAERESIS AND CARON
	{475, 'U'}, // LATIN CAPITAL LETTER U WITH DIAERESIS AND GRAVE
	{476, 'u'}, // LATIN SMALL LETTER U WITH DIAERESIS AND GRAVE
	{477, '@'}, // LATIN SMALL LETTER TURNED E
	{478, 'A'}, // LATIN CAPITAL LETTER A WITH DIAERESIS AND MACRON
	{479, 'a'}, // LATIN SMALL LETTER A WITH DIAERESIS AND MACRON
	{480, 'A'}, // LATIN CAPITAL LETTER A WITH DOT ABOVE AND MACRON
	{481, 'a'}, // LATIN SMALL LETTER A WITH DOT ABOVE AND MACRON
	{482, 'A', 'E'}, // LATIN CAPITAL LETTER AE WITH MACRON
	{483, 'a', 'e'}, // LATIN SMALL LETTER AE WITH MACRON
	{484, 'G'}, // LATIN CAPITAL LETTER G WITH STROKE
	{485, 'g'}, // LATIN SMALL LETTER G WITH STROKE
	{486, 'G'}, // LATIN CAPITAL LETTER G WITH CARON
	{487, 'g'}, // LATIN SMALL LETTER G WITH CARON
	{488, 'K'}, // LATIN CAPITAL LETTER K WITH CARON
	{489, 'k'}, // LATIN SMALL LETTER K WITH CARON
	{490, 'O'}, // LATIN CAPITAL LETTER O WITH OGONEK
	{491, 'o'}, // LATIN SMALL LETTER O WITH OGONEK
	{492, 'O'}, // LATIN CAPITAL LETTER O WITH OGONEK AND MACRON
	{493, 'o'}, // LATIN SMALL LETTER O WITH OGONEK AND MACRON
	{494, 'Z', 'H'}, // LATIN CAPITAL LETTER EZH WITH CARON
	{495, 'z', 'h'}, // LATIN SMALL LETTER EZH WITH CARON
	{496, 'j'}, // LATIN SMALL LETTER J WITH CARON
	{497, 'D', 'Z'}, // LATIN CAPITAL LETTER DZ
	{498, 'D', 'z'}, // LATIN CAPITAL LETTER D WITH SMALL LETTER Z
	{499, 'd', 'z'}, // LATIN SMALL LETTER DZ
	{500, 'G'}, // LATIN CAPITAL LETTER G WITH ACUTE
	{501, 'g'}, // LATIN SMALL LETTER G WITH ACUTE
	{502, 'H', 'V'}, // LATIN CAPITAL LETTER HWAIR
	{503, 'W'}, // LATIN CAPITAL LETTER WYNN
	{504, 'N'}, // LATIN CAPITAL LETTER N WITH GRAVE
	{505, 'n'}, // LATIN SMALL LETTER N WITH GRAVE
	{506, 'A'}, // LATIN CAPITAL LETTER A WITH RING ABOVE AND ACUTE
	{507, 'a'}, // LATIN SMALL LETTER A WITH RING ABOVE AND ACUTE
	{508, 'A', 'E'}, // LATIN CAPITAL LETTER AE WITH ACUTE
	{509, 'a', 'e'}, // LATIN SMALL LETTER AE WITH ACUTE
	{510, 'O'}, // LATIN CAPITAL LETTER O WITH STROKE AND ACUTE
	{511, 'o'}, // LATIN SMALL LETTER O WITH STROKE AND ACUTE
	{512, 'A'}, // LATIN CAPITAL LETTER A WITH DOUBLE GRAVE
	{513, 'a'}, // LATIN SMALL LETTER A WITH DOUBLE GRAVE
	{514, 'A'}, // LATIN CAPITAL LETTER A WITH INVERTED BREVE
	{515, 'a'}, // LATIN SMALL LETTER A WITH INVERTED BREVE
	{516, 'E'}, // LATIN CAPITAL LETTER E WITH DOUBLE GRAVE
	{517, 'e'}, // LATIN SMALL LETTER E WITH DOUBLE GRAVE
	{518, 'E'}, // LATIN CAPITAL LETTER E WITH INVERTED BREVE
	{519, 'e'}, // LATIN SMALL LETTER E WITH INVERTED BREVE
	{520, 'I'}, // LATIN CAPITAL LETTER I WITH DOUBLE GRAVE
	{521, 'i'}, // LATIN SMALL LETTER I WITH DOUBLE GRAVE
	{522, 'I'}, // LATIN CAPITAL LETTER I WITH INVERTED BREVE
	{523, 'i'}, // LATIN SMALL LETTER I WITH INVERTED BREVE
	{524, 'O'}, // LATIN CAPITAL LETTER O WITH DOUBLE GRAVE
	{525, 'o'}, // LATIN SMALL LETTER O WITH DOUBLE GRAVE
	{526, 'O'}, // LATIN CAPITAL LETTER O WITH INVERTED BREVE
	{527, 'o'}, // LATIN SMALL LETTER O WITH INVERTED BREVE
	{528, 'R'}, // LATIN CAPITAL LETTER R WITH DOUBLE GRAVE
	{529, 'r'}, // LATIN SMALL LETTER R WITH DOUBLE GRAVE
	{530, 'R'}, // LATIN CAPITAL LETTER R WITH INVERTED BREVE
	{531, 'r'}, // LATIN SMALL LETTER R WITH INVERTED BREVE
	{532, 'U'}, // LATIN CAPITAL LETTER U WITH DOUBLE GRAVE
	{533, 'u'}, // LATIN SMALL LETTER U WITH DOUBLE GRAVE
	{534, 'U'}, // LATIN CAPITAL LETTER U WITH INVERTED BREVE
	{535, 'u'}, // LATIN SMALL LETTER U WITH INVERTED BREVE
	{536, 'S'}, // LATIN CAPITAL LETTER S WITH COMMA BELOW
	{537, 's'}, // LATIN SMALL LETTER S WITH COMMA BELOW
	{538, 'T'}, // LATIN CAPITAL LETTER T WITH COMMA BELOW
	{539, 't'}, // LATIN SMALL LETTER T WITH COMMA BELOW
	{540, 'Y'}, // LATIN CAPITAL LETTER YOGH
	{541, 'y'}, // LATIN SMALL LETTER YOGH
	{542, 'H'}, // LATIN CAPITAL LETTER H WITH CARON
	{543, 'h'}, // LATIN SMALL LETTER H WITH CARON
	{544, 'N'}, // LATIN CAPITAL LETTER N WITH LONG RIGHT LEG
	{545, 'd'}, // LATIN SMALL LETTER D WITH CURL
	{546, 'O', 'U'}, // LATIN CAPITAL LETTER OU
	{547, 'o', 'u'}, // LATIN SMALL LETTER OU
	{548, 'Z'}, // LATIN CAPITAL LETTER Z WITH HOOK
	{549, 'z'}, // LATIN SMALL LETTER Z WITH HOOK
	{550, 'A'}, // LATIN CAPITAL LETTER A WITH DOT ABOVE
	{551, 'a'}, // LATIN SMALL LETTER A WITH DOT ABOVE
	{552, 'E'}, // LATIN CAPITAL LETTER E WITH CEDILLA
	{553, 'e'}, // LATIN SMALL LETTER E WITH CEDILLA
	{554, 'O'}, // LATIN CAPITAL LETTER O WITH DIAERESIS AND MACRON
	{555, 'o'}, // LATIN SMALL LETTER O WITH DIAERESIS AND MACRON
	{556, 'O'}, // LATIN CAPITAL LETTER O WITH TILDE AND MACRON
	{557, 'o'}, // LATIN SMALL LETTER O WITH TILDE AND MACRON
	{558, 'O'}, // LATIN CAPITAL LETTER O WITH DOT ABOVE
	{559, 'o'}, // LATIN SMALL LETTER O WITH DOT ABOVE
	{560, 'O'}, // LATIN CAPITAL LETTER O WITH DOT ABOVE AND MACRON
	{561, 'o'}, // LATIN SMALL LETTER O WITH DOT ABOVE AND MACRON
	{562, 'Y'}, // LATIN CAPITAL LETTER Y WITH MACRON
	{563, 'y'}, // LATIN SMALL LETTER Y WITH MACRON
	{564, 'l'}, // LATIN SMALL LETTER L WITH CURL
	{565, 'n'}, // LATIN SMALL LETTER N WITH CURL
	{566, 't'}, // LATIN SMALL LETTER T WITH CURL
	{567, 'j'}, // LATIN SMALL LETTER DOTLESS J
	{568, 'd', 'b'}, // LATIN SMALL LETTER DB DIGRAPH
	{569, 'q', 'p'}, // LATIN SMALL LETTER QP DIGRAPH
	{570, 'A'}, // LATIN CAPITAL LETTER A WITH STROKE
	{571, 'C'}, // LATIN CAPITAL LETTER C WITH STROKE
	{572, 'c'}, // LATIN SMALL LETTER C WITH STROKE
	{573, 'L'}, // LATIN CAPITAL LETTER L WITH BAR
	{574, 'T'}, // LATIN CAPITAL LETTER T WITH DIAGONAL STROKE
	{575, 's'}, // LATIN SMALL LETTER S WITH SWASH TAIL
	{576, 'z'}, // LATIN SMALL LETTER Z WITH SWASH TAIL
	{579, 'B'}, // LATIN CAPITAL LETTER B WITH STROKE
	{580, 'U'}, // LATIN CAPITAL LETTER U BAR
	{581, '^'}, // LATIN CAPITAL LETTER TURNED V
	{582, 'E'}, // LATIN CAPITAL LETTER E WITH STROKE
	{583, 'e'}, // LATIN SMALL LETTER E WITH STROKE
	{584, 'J'}, // LATIN CAPITAL LETTER J WITH STROKE
	{585, 'j'}, // LATIN SMALL LETTER J WITH STROKE
	{586, 'q'}, // LATIN CAPITAL LETTER SMALL Q WITH HOOK TAIL
	{587, 'q'}, // LATIN SMALL LETTER Q WITH HOOK TAIL
	{588, 'R'}, // LATIN CAPITAL LETTER R WITH STROKE
	{589, 'r'}, // LATIN SMALL LETTER R WITH STROKE
	{590, 'Y'}, // LATIN CAPITAL LETTER Y WITH STROKE
	{591, 'y'}, // LATIN SMALL LETTER Y WITH STROKE
	{1024, 'I', 'e'}, // CYRILLIC CAPITAL LETTER IE WITH GRAVE
	{1025, 'I', 'o'}, // CYRILLIC CAPITAL LETTER IO
	{1026, 'D', 'j'}, // CYRILLIC CAPITAL LETTER DJE
	{1027, 'G', 'j'}, // CYRILLIC CAPITAL LETTER GJE
	{1028, 'I', 'e'}, // CYRILLIC CAPITAL LETTER UKRAINIAN IE
	{1029, 'D', 'z'}, // CYRILLIC CAPITAL LETTER DZE
	{1030, 'I'}, // CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
	{1031, 'Y', 'i'}, // CYRILLIC CAPITAL LETTER YI
	{1032, 'J'}, // CYRILLIC CAPITAL LETTER JE
	{1033, 'L', 'j'}, // CYRILLIC CAPITAL LETTER LJE
	{1034, 'N', 'j'}, // CYRILLIC CAPITAL LETTER NJE
	{1036, 'K', 'j'}, // CYRILLIC CAPITAL LETTER KJE
	{1037, 'I'}, // CYRILLIC CAPITAL LETTER I WITH GRAVE
	{1038, 'U'}, // CYRILLIC CAPITAL LETTER SHORT U
	{1040, 'A'}, // CYRILLIC CAPITAL LETTER A
	{1041, 'B'}, // CYRILLIC CAPITAL LETTER BE
	{1042, 'V'}, // CYRILLIC CAPITAL LETTER VE
	{1043, 'G'}, // CYRILLIC CAPITAL LETTER GHE
	{1044, 'D'}, // CYRILLIC CAPITAL LETTER DE
	{1045, 'E'}, // CYRILLIC CAPITAL LETTER IE
	{1046, 'Z', 'h'}, // CYRILLIC CAPITAL LETTER ZHE
	{1047, 'Z'}, // CYRILLIC CAPITAL LETTER ZE
	{1048, 'I'}, // CYRILLIC CAPITAL LETTER I
	{1049, 'I'}, // CYRILLIC CAPITAL LETTER SHORT I
	{1050, 'K'}, // CYRILLIC CAPITAL LETTER KA
	{1051, 'L'}, // CYRILLIC CAPITAL LETTER EL
	{1052, 'M'}, // CYRILLIC CAPITAL LETTER EM
	{1053, 'N'}, // CYRILLIC CAPITAL LETTER EN
	{1054, 'O'}, // CYRILLIC CAPITAL LETTER O
	{1055, 'P'}, // CYRILLIC CAPITAL LETTER PE
	{1056, 'R'}, // CYRILLIC CAPITAL LETTER ER
	{1057, 'S'}, // CYRILLIC CAPITAL LETTER ES
	{1058, 'T'}, // CYRILLIC CAPITAL LETTER TE
	{1059, 'U'}, // CYRILLIC CAPITAL LETTER U
	{1060, 'F'}, // CYRILLIC CAPITAL LETTER EF
	{1061, 'K', 'h'}, // CYRILLIC CAPITAL LETTER HA
	{1062, 'T', 's'}, // CYRILLIC CAPITAL LETTER TSE
	{1063, 'C', 'h'}, // CYRILLIC CAPITAL LETTER CHE
	{1064, 'S', 'h'}, // CYRILLIC CAPITAL LETTER SHA
	{1066, '\''}, // CYRILLIC CAPITAL LETTER HARD SIGN
	{1067, 'Y'}, // CYRILLIC CAPITAL LETTER YERU
	{1068, '\''}, // CYRILLIC CAPITAL LETTER SOFT SIGN
	{1069, 'E'}, // CYRILLIC CAPITAL LETTER E
	{1070, 'I', 'u'}, // CYRILLIC CAPITAL LETTER YU
	{1071, 'I', 'a'}, // CYRILLIC CAPITAL LETTER YA
	{1072, 'a'}, // CYRILLIC SMALL LETTER A
	{1073, 'b'}, // CYRILLIC SMALL LETTER BE
	{1074, 'v'}, // CYRILLIC SMALL LETTER VE
	{1075, 'g'}, // CYRILLIC SMALL LETTER GHE
	{1076, 'd'}, // CYRILLIC SMALL LETTER DE
	{1077, 'e'}, // CYRILLIC SMALL LETTER IE
	{1078, 'z', 'h'}, // CYRILLIC SMALL LETTER ZHE
	{1079, 'z'}, // CYRILLIC SMALL LETTER ZE
	{1080, 'i'}, // CYRILLIC SMALL LETTER I
	{1081, 'i'}, // CYRILLIC SMALL LETTER SHORT I
	{1082, 'k'}, // CYRILLIC SMALL LETTER KA
	{1083, 'l'}, // CYRILLIC SMALL LETTER EL
	{1084, 'm'}, // CYRILLIC SMALL LETTER EM
	{1085, 'n'}, // CYRILLIC SMALL LETTER EN
	{1086, 'o'}, // CYRILLIC SMALL LETTER O
	{1087, 'p'}, // CYRILLIC SMALL LETTER PE
	{1088, 'r'}, // CYRILLIC SMALL LETTER ER
	{1089, 's'}, // CYRILLIC SMALL LETTER ES
	{1090, 't'}, // CYRILLIC SMALL LETTER TE
	{1091, 'u'}, // CYRILLIC SMALL LETTER U
	{1092, 'f'}, // CYRILLIC SMALL LETTER EF
	{1093, 'k', 'h'}, // CYRILLIC SMALL LETTER HA
	{1094, 't', 's'}, // CYRILLIC SMALL LETTER TSE
	{1095, 'c', 'h'}, // CYRILLIC SMALL LETTER CHE
	{1096, 's', 'h'}, // CYRILLIC SMALL LETTER SHA
	{1098, '\''}, // CYRILLIC SMALL LETTER HARD SIGN
	{1099, 'y'}, // CYRILLIC SMALL LETTER YERU
	{1100, '\''}, // CYRILLIC SMALL LETTER SOFT SIGN
	{1101, 'e'}, // CYRILLIC SMALL LETTER E
	{1102, 'i', 'u'}, // CYRILLIC SMALL LETTER YU
	{1103, 'i', 'a'}, // CYRILLIC SMALL LETTER YA
	{1104, 'i', 'e'}, // CYRILLIC SMALL LETTER IE WITH GRAVE
	{1105, 'i', 'o'}, // CYRILLIC SMALL LETTER IO
	{1106, 'd', 'j'}, // CYRILLIC SMALL LETTER DJE
	{1107, 'g', 'j'}, // CYRILLIC SMALL LETTER GJE
	{1108, 'i', 'e'}, // CYRILLIC SMALL LETTER UKRAINIAN IE
	{1109, 'd', 'z'}, // CYRILLIC SMALL LETTER DZE
	{1110, 'i'}, // CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
	{1111, 'y', 'i'}, // CYRILLIC SMALL LETTER YI
	{1112, 'j'}, // CYRILLIC SMALL LETTER JE
	{1113, 'l', 'j'}, // CYRILLIC SMALL LETTER LJE
	{1114, 'n', 'j'}, // CYRILLIC SMALL LETTER NJE
	{1116, 'k', 'j'}, // CYRILLIC SMALL LETTER KJE
	{1117, 'i'}, // CYRILLIC SMALL LETTER I WITH GRAVE
	{1118, 'u'}, // CYRILLIC SMALL LETTER SHORT U
	{1120, 'O'}, // CYRILLIC CAPITAL LETTER OMEGA
	{1121, 'o'}, // CYRILLIC SMALL LETTER OMEGA
	{1122, 'E'}, // CYRILLIC CAPITAL LETTER YAT
	{1123, 'e'}, // CYRILLIC SMALL LETTER YAT
	{1124, 'I', 'e'}, // CYRILLIC CAPITAL LETTER IOTIFIED E
	{1125, 'i', 'e'}, // CYRILLIC SMALL LETTER IOTIFIED E
	{1126, 'E'}, // CYRILLIC CAPITAL LETTER LITTLE YUS
	{1127, 'e'}, // CYRILLIC SMALL LETTER LITTLE YUS
	{1128, 'I', 'e'}, // CYRILLIC CAPITAL LETTER IOTIFIED LITTLE YUS
	{1129, 'i', 'e'}, // CYRILLIC SMALL LETTER IOTIFIED LITTLE YUS
	{1130, 'O'}, // CYRILLIC CAPITAL LETTER BIG YUS
	{1131, 'o'}, // CYRILLIC SMALL LETTER BIG YUS
	{1132, 'I', 'o'}, // CYRILLIC CAPITAL LETTER IOTIFIED BIG YUS
	{1133, 'i', 'o'}, // CYRILLIC SMALL LETTER IOTIFIED BIG YUS
	{1134, 'K', 's'}, // CYRILLIC CAPITAL LETTER KSI
	{1135, 'k', 's'}, // CYRILLIC SMALL LETTER KSI
	{1136, 'P', 's'}, // CYRILLIC CAPITAL LETTER PSI
	{1137, 'p', 's'}, // CYRILLIC SMALL LETTER PSI
	{1138, 'F'}, // CYRILLIC CAPITAL LETTER FITA
	{1139, 'f'}, // CYRILLIC SMALL LETTER FITA
	{1140, 'Y'}, // CYRILLIC CAPITAL LETTER IZHITSA
	{1141, 'y'}, // CYRILLIC SMALL LETTER IZHITSA
	{1142, 'Y'}, // CYRILLIC CAPITAL LETTER IZHITSA WITH DOUBLE GRAVE ACCENT
	{1143, 'y'}, // CYRILLIC SMALL LETTER IZHITSA WITH DOUBLE GRAVE ACCENT
	{1144, 'u'}, // CYRILLIC CAPITAL LETTER UK
	{1145, 'u'}, // CYRILLIC SMALL LETTER UK
	{1146, 'O'}, // CYRILLIC CAPITAL LETTER ROUND OMEGA
	{1147, 'o'}, // CYRILLIC SMALL LETTER ROUND OMEGA
	{1148, 'O'}, // CYRILLIC CAPITAL LETTER OMEGA WITH TITLO
	{1149, 'o'}, // CYRILLIC SMALL LETTER OMEGA WITH TITLO
	{1150, 'O', 't'}, // CYRILLIC CAPITAL LETTER OT
	{1151, 'o', 't'}, // CYRILLIC SMALL LETTER OT
	{1152, 'Q'}, // CYRILLIC CAPITAL LETTER KOPPA
	{1153, 'q'}, // CYRILLIC SMALL LETTER KOPPA
	{1164, '"'}, // CYRILLIC CAPITAL LETTER SEMISOFT SIGN
	{1165, '"'}, // CYRILLIC SMALL LETTER SEMISOFT SIGN
	{1166, 'R', '\''}, // CYRILLIC CAPITAL LETTER ER WITH TICK
	{1167, 'r', '\''}, // CYRILLIC SMALL LETTER ER WITH TICK
	{1168, 'G', '\''}, // CYRILLIC CAPITAL LETTER GHE WITH UPTURN
	{1169, 'g', '\''}, // CYRILLIC SMALL LETTER GHE WITH UPTURN
	{1170, 'G', '\''}, // CYRILLIC CAPITAL LETTER GHE WITH STROKE
	{1171, 'g', '\''}, // CYRILLIC SMALL LETTER GHE WITH STROKE
	{1172, 'G', '\''}, // CYRILLIC CAPITAL LETTER GHE WITH MIDDLE HOOK
	{1173, 'g', '\''}, // CYRILLIC SMALL LETTER GHE WITH MIDDLE HOOK
	{1176, 'Z', '\''}, // CYRILLIC CAPITAL LETTER ZE WITH DESCENDER
	{1177, 'z', '\''}, // CYRILLIC SMALL LETTER ZE WITH DESCENDER
	{1178, 'K', '\''}, // CYRILLIC CAPITAL LETTER KA WITH DESCENDER
	{1179, 'k', '\''}, // CYRILLIC SMALL LETTER KA WITH DESCENDER
	{1180, 'K', '\''}, // CYRILLIC CAPITAL LETTER KA WITH VERTICAL STROKE
	{1181, 'k', '\''}, // CYRILLIC SMALL LETTER KA WITH VERTICAL STROKE
	{1182, 'K', '\''}, // CYRILLIC CAPITAL LETTER KA WITH STROKE
	{1183, 'k', '\''}, // CYRILLIC SMALL LETTER KA WITH STROKE
	{1184, 'K', '\''}, // CYRILLIC CAPITAL LETTER BASHKIR KA
	{1185, 'k', '\''}, // CYRILLIC SMALL LETTER BASHKIR KA
	{1186, 'N', '\''}, // CYRILLIC CAPITAL LETTER EN WITH DESCENDER
	{1187, 'n', '\''}, // CYRILLIC SMALL LETTER EN WITH DESCENDER
	{1188, 'N', 'g'}, // CYRILLIC CAPITAL LIGATURE EN GHE
	{1189, 'n', 'g'}, // CYRILLIC SMALL LIGATURE EN GHE
	{1190, 'P', '\''}, // CYRILLIC CAPITAL LETTER PE WITH MIDDLE HOOK
	{1191, 'p', '\''}, // CYRILLIC SMALL LETTER PE WITH MIDDLE HOOK
	{1192, 'K', 'h'}, // CYRILLIC CAPITAL LETTER ABKHASIAN HA
	{1193, 'k', 'h'}, // CYRILLIC SMALL LETTER ABKHASIAN HA
	{1194, 'S', '\''}, // CYRILLIC CAPITAL LETTER ES WITH DESCENDER
	{1195, 's', '\''}, // CYRILLIC SMALL LETTER ES WITH DESCENDER
	{1196, 'T', '\''}, // CYRILLIC CAPITAL LETTER TE WITH DESCENDER
	{1197, 't', '\''}, // CYRILLIC SMALL LETTER TE WITH DESCENDER
	{1198, 'U'}, // CYRILLIC CAPITAL LETTER STRAIGHT U
	{1199, 'u'}, // CYRILLIC SMALL LETTER STRAIGHT U
	{1200, 'U', '\''}, // CYRILLIC CAPITAL LETTER STRAIGHT U WITH STROKE
	{1201, 'u', '\''}, // CYRILLIC SMALL LETTER STRAIGHT U WITH STROKE
	{1210, 'H'}, // CYRILLIC CAPITAL LETTER SHHA
	{1211, 'h'}, // CYRILLIC SMALL LETTER SHHA
	{1212, 'C', 'h'}, // CYRILLIC CAPITAL LETTER ABKHASIAN CHE
	{1213, 'c', 'h'}, // CYRILLIC SMALL LETTER ABKHASIAN CHE
	{1216, '`'}, // CYRILLIC LETTER PALOCHKA
	{1217, 'Z', 'h'}, // CYRILLIC CAPITAL LETTER ZHE WITH BREVE
	{1218, 'z', 'h'}, // CYRILLIC SMALL LETTER ZHE WITH BREVE
	{1219, 'K', '\''}, // CYRILLIC CAPITAL LETTER KA WITH HOOK
	{1220, 'k', '\''}, // CYRILLIC SMALL LETTER KA WITH HOOK
	{1223, 'N', '\''}, // CYRILLIC CAPITAL LETTER EN WITH HOOK
	{1224, 'n', '\''}, // CYRILLIC SMALL LETTER EN WITH HOOK
	{1227, 'C', 'h'}, // CYRILLIC CAPITAL LETTER KHAKASSIAN CHE
	{1228, 'c', 'h'}, // CYRILLIC SMALL LETTER KHAKASSIAN CHE
	{1232, 'a'}, // CYRILLIC CAPITAL LETTER A WITH BREVE
	{1233, 'a'}, // CYRILLIC SMALL LETTER A WITH BREVE
	{1234, 'A'}, // CYRILLIC CAPITAL LETTER A WITH DIAERESIS
	{1235, 'a'}, // CYRILLIC SMALL LETTER A WITH DIAERESIS
	{1236, 'A', 'e'}, // CYRILLIC CAPITAL LIGATURE A IE
	{1237, 'a', 'e'}, // CYRILLIC SMALL LIGATURE A IE
	{1238, 'I', 'e'}, // CYRILLIC CAPITAL LETTER IE WITH BREVE
	{1239, 'i', 'e'}, // CYRILLIC SMALL LETTER IE WITH BREVE
	{1240, '@'}, // CYRILLIC CAPITAL LETTER SCHWA
	{1241, '@'}, // CYRILLIC SMALL LETTER SCHWA
	{1242, '@'}, // CYRILLIC CAPITAL LETTER SCHWA WITH DIAERESIS
	{1243, '@'}, // CYRILLIC SMALL LETTER SCHWA WITH DIAERESIS
	{1244, 'Z', 'h'}, // CYRILLIC CAPITAL LETTER ZHE WITH DIAERESIS
	{1245, 'z', 'h'}, // CYRILLIC SMALL LETTER ZHE WITH DIAERESIS
	{1246, 'Z'}, // CYRILLIC CAPITAL LETTER ZE WITH DIAERESIS
	{1247, 'z'}, // CYRILLIC SMALL LETTER ZE WITH DIAERESIS
	{1248, 'D', 'z'}, // CYRILLIC CAPITAL LETTER ABKHASIAN DZE
	{1249, 'd', 'z'}, // CYRILLIC SMALL LETTER ABKHASIAN DZE
	{1250, 'I'}, // CYRILLIC CAPITAL LETTER I WITH MACRON
	{1251, 'i'}, // CYRILLIC SMALL LETTER I WITH MACRON
	{1252, 'I'}, // CYRILLIC CAPITAL LETTER I WITH DIAERESIS
	{1253, 'i'}, // CYRILLIC SMALL LETTER I WITH DIAERESIS
	{1254, 'O'}, // CYRILLIC CAPITAL LETTER O WITH DIAERESIS
	{1255, 'o'}, // CYRILLIC SMALL LETTER O WITH DIAERESIS
	{1256, 'O'}, // CYRILLIC CAPITAL LETTER BARRED O
	{1257, 'o'}, // CYRILLIC SMALL LETTER BARRED O
	{1258, 'O'}, // CYRILLIC CAPITAL LETTER BARRED O WITH DIAERESIS
	{1259, 'o'}, // CYRILLIC SMALL LETTER BARRED O WITH DIAERESIS
	{1260, 'E'}, // CYRILLIC CAPITAL LETTER E WITH DIAERESIS
	{1261, 'e'}, // CYRILLIC SMALL LETTER E WITH DIAERESIS
	{1262, 'U'}, // CYRILLIC CAPITAL LETTER U WITH MACRON
	{1263, 'u'}, // CYRILLIC SMALL LETTER U WITH MACRON
	{1264, 'U'}, // CYRILLIC CAPITAL LETTER U WITH DIAERESIS
	{1265, 'u'}, // CYRILLIC SMALL LETTER U WITH DIAERESIS
	{1266, 'U'}, // CYRILLIC CAPITAL LETTER U WITH DOUBLE ACUTE
	{1267, 'u'}, // CYRILLIC SMALL LETTER U WITH DOUBLE ACUTE
	{1268, 'C', 'h'}, // CYRILLIC CAPITAL LETTER CHE WITH DIAERESIS
	{1269, 'c', 'h'}, // CYRILLIC SMALL LETTER CHE WITH DIAERESIS
	{1272, 'Y'}, // CYRILLIC CAPITAL LETTER YERU WITH DIAERESIS
	{1273, 'y'}, // CYRILLIC SMALL LETTER YERU WITH DIAERESIS
};
