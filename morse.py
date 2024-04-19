morse_code_dict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.', 'H': '....',
    'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 'P': '.--.',
    'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-',
    'Y': '-.--', 'Z': '--..',
    '0': '-----', '1': '.----', '2': '..---', '3': '...--', '4': '....-', '5': '.....', '6': '-....',
    '7': '--...', '8': '---..', '9': '----.',
    '.': '.-.-.-', ',': '--..--', '?': '..--..', "'": '.----.', '!': '-.-.--', '/': '-..-.', '(': '-.--.',
    ')': '-.--.-', '&': '.-...', ':': '---...', ';': '-.-.-.', '=': '-...-', '+': '.-.-.', '-': '-....-',
    '_': '..--.-', '"': '.-..-.', '$': '...-..-', '@': '.--.-.', ' ': '/'
}

reverse_morse_code_dict = {value: key for key, value in morse_code_dict.items()}

def text_to_morse(text):
    morse_code = []
    for char in text.upper():
        if char in morse_code_dict:
            morse_code.append(morse_code_dict[char])
        else:
            morse_code.append('/')
    return ' '.join(morse_code)

def morse_to_text(morse):
    morse_words = morse.split(' ')
    text = ''
    for morse_word in morse_words:
        if morse_word in reverse_morse_code_dict:
            text += reverse_morse_code_dict[morse_word]
        else:
            text += ' '
    return text

input_text = input("Inserisci il testo o il codice Morse da tradurre: ")
if input_text.replace(' ', '').isalpha():
    morse = text_to_morse(input_text)
    print("Testo in codice Morse:", morse)
else:
    text = morse_to_text(input_text)
    print("Codice Morse in testo:", text)
