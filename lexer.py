import enum

class TokenType(enum.Enum):
    KW_VOID = "void"
    KW_FLOAT = "float"

    IDENTIFIER = 'IDENTIFIER'
    NUM_INT = 'INT_LITERAL'
    NUM_FLOAT = 'FLOAT_LITERAL'

    OP_ASSIGN = "="
    OP_PLUS = "+"
    OP_MINUS = "-"
    OP_MUL = "*"
    OP_DIV = "/"

    LPAREN = "("
    RPAREN = ")"
    LBRACE = "{"
    RBRACE = "}"
    COMMA = ","
    SEMICOLON = ";"

    EOF = "EOF"

class Token:
    def __init__(self, type_: TokenType, value: str, line: int):
        self.type = type_
        self.value = value
        self.line = line

    def __repr__(self):
        return f"Token({self.type.name}, '{self.value}', Line:{self.line})"

if __name__ == "__main__":
    nyph_code_sample = """
    void main() {
        float x = 400.0;
        float y = 300.25;
        float result = x * y + 10;
    }
    """
