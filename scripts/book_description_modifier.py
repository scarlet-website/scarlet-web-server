def description_modifier(description: str) -> str:
    return description.replace('\n', '<br>').replace("\"", "'").strip()


if __name__ == '__main__':
    desc = """"""
    print(description_modifier(description=desc))
