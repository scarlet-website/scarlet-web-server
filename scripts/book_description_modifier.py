def description_modifier(description: str) -> str:
    return description.replace('\n', '<br>').replace("\"", "'").strip()


if __name__ == '__main__':
    desc = """לכולנו יש סודות, ואני הייתי אומנית בהסתרת הסודות שלי.

חצאי אמיתות ושקרים שלמים, מהונאה אחת לשנייה, הפכתי לפינוקיו אמיתית.

הוא היה כמו שני אנשים שונים - איליי וד"ר פקסטון.
ידעתי שהוא מורה מדהים, אבל המחשבה שהוא יהיה יותר מזה, הצחיקה אותי.
לא הצלחתי להפריד ביניהם, ומיום ליום זה היה מאוד לא הולם ומפתה בצורה מוזרה.

הצד המעשי שלי היה צריך לנצח את המלחמה שבי.
הייתי צריכה להעדיף את המורה, לא את הגבר.
ברגע שבו חציתי את הגבול,
לא הייתה דרך חזרה...
עבור שנינו.

'השלמות שלה' הוא ספרה השני של הסופרת סטפי וולס שתורגם לעברית. גם ספרה הקודם, 'הרגעים היפים בחיי', יצא לאור בהוצאת סקרלט, כיכב ברשימות רבי המכר וזכה להצלחה רבה בקרב הקוראים בישראל."""
    print(description_modifier(description=desc))
