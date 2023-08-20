from fpdf import FPDF


def main():
    name = input("Name: ").strip()
    pdf = FPDF(orientation="P", unit="mm", format="A4")
    pdf.add_page()
    pdf.set_font("helvetica", "B", 48)
    certificate = "CS50 Shirtificate"

    pdf.cell(200, 30, certificate, align="C")
    pdf.image("shirtificate.png", x=0, y=50)

    pdf.set_font("helvetica", size=36)
    pdf.set_text_color(255, 255, 255)
    pdf.text(50, 120, f"{name} took CS50")

    pdf.output("shirtificate.pdf")

if __name__ == "__main__":
    main()