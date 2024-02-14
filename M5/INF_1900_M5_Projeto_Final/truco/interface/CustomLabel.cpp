#include "CustomLabel.h"
namespace ui {
    BEGIN_MESSAGE_MAP(CustomLabel, CStatic)
        ON_WM_PAINT()
    END_MESSAGE_MAP()

    CustomLabel::CustomLabel() {
        m_backgorund = GetSysColor(COLOR_WINDOW);
        m_foregorund = GetSysColor(COLOR_WINDOWTEXT);
        m_fontSize = 12;
        m_fontWeight = FontWeight::Extrabold;
        m_isTransparent = false;
    }
    CustomLabel::~CustomLabel() {}

    void CustomLabel::setBackgroundColor(COLORREF color)
    {
        m_backgorund = color;
    }

    COLORREF CustomLabel::getBackgroundColor() const
    {
        return m_backgorund;
    }

    void CustomLabel::setForegroundColor(COLORREF color)
    {
        m_foregorund = color;
    }

    COLORREF CustomLabel::getForegroundColor() const
    {
        return m_foregorund;
    }

    void CustomLabel::setFontSize(UINT8 value)
    {
        if (value > 0) {
            m_fontSize = value;
        }
    }

    UINT8 CustomLabel::getFontSize()
    {
        return m_fontSize;
    }

    void CustomLabel::setFontWeigth(FontWeight weight)
    {
        m_fontWeight = weight;
    }

    FontWeight CustomLabel::getFontWeigth()
    {
        return m_fontWeight;
    }

    void CustomLabel::setTransparent(bool value)
    {
        m_isTransparent = value;
    }

    void CustomLabel::OnPaint()
    {
        std::unique_ptr<CPaintDC> pDC;
        pDC = std::make_unique<CPaintDC>(this);

        // Use um pincel transparente
        CBrush brush;
        brush.CreateStockObject(HOLLOW_BRUSH);

        // Pinte o fundo com o pincel transparente
        CRect rect;
        GetClientRect(rect);
        pDC->FillRect(rect, &brush);

        if (m_isTransparent) {
            pDC->SetBkMode(TRANSPARENT);
        }
        else
            pDC->SetBkMode(OPAQUE);

        pDC->SetBkColor(m_backgorund);
        pDC->SetTextColor(m_foregorund);

        //Configurando fonte
        CFont minhaFonte;
        minhaFonte.CreateFont(
            m_fontSize,           // Altura da fonte
            0,                    // Largura média dos caracteres
            0,                    // Ângulo de escapamento
            0,                    // Ângulo de orientação
            (int)m_fontWeight,            // Peso da fonte (FW_BOLD para negrito)
            FALSE,                // Itálico
            FALSE,                // Sublinhado
            0,                    // Tachado
            ANSI_CHARSET,         // Conjunto de caracteres
            OUT_DEFAULT_PRECIS,   // Precisão de saída
            CLIP_DEFAULT_PRECIS,  // Precisão de recorte
            DEFAULT_QUALITY,      // Qualidade da fonte
            DEFAULT_PITCH | FF_SWISS, // Família da fonte
            _T("Arial"));         // Nome da fonte
        // Selecione a nova fonte no contexto de dispositivo
        CFont* pFontAntiga = pDC->SelectObject(&minhaFonte);


        // Adicione aqui o código para desenhar o texto ou outros elementos
        CString strText;
        GetWindowText(strText);

        // Configura a margem (pode ajustar conforme necessário)
        int margin = 10;
        rect.DeflateRect(margin, margin);

        // Calcula a largura da área de desenho
        int maxWidth = rect.Width();

        // Inicializa as variáveis ​​para controle de quebra de linha
        int xPos = rect.left;
        int yPos = rect.top;

        // Itera sobre cada palavra no texto
        CStringArray words;
        int start = 0;
        int length = strText.GetLength();
        while (start < length) {
            int spacePos = strText.Find(_T(' '), start);
            CString word = (spacePos == -1) ? strText.Mid(start) : strText.Mid(start, spacePos - start);
            words.Add(word);
            start = (spacePos == -1) ? length : spacePos + 1;
        }

        // Desenha o texto com quebra de linha automática
        for (int i = 0; i < words.GetSize(); i++) {
            CString word = words.GetAt(i);
            int wordWidth = pDC->GetTextExtent(word).cx;

            if (xPos + wordWidth > rect.right) {
                // Quebra de linha
                xPos = rect.left;
                yPos += pDC->GetTextExtent(_T("A")).cy; // Altura aproximada de uma linha de texto
            }

            pDC->TextOut(xPos, yPos, word);
            xPos += wordWidth + pDC->GetTextExtent(_T(" ")).cx; // Adiciona espaço entre as palavras
        }
        
        pDC->SelectObject(pFontAntiga);
    }
}