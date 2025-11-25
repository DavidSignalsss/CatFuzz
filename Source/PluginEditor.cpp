#include "PluginProcessor.h"
#include "PluginEditor.h"

CatFuzzAudioProcessorEditor::CatFuzzAudioProcessorEditor (CatFuzzAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // SLIDER FUZZ
    fuzzSlider.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    fuzzSlider.setRange (0.0, 1.0, 0.01);
    fuzzSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    fuzzSlider.setValue(0.5);
    fuzzSlider.addListener (this);
    addAndMakeVisible (fuzzSlider);

    // SLIDER TONE
    toneSlider.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    toneSlider.setRange (0.0, 1.0, 0.01);
    toneSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    toneSlider.setValue(0.5);
    toneSlider.addListener (this);
    addAndMakeVisible (toneSlider);

    // SLIDER VOLUME
    volumeSlider.setSliderStyle (juce::Slider::RotaryVerticalDrag);
    volumeSlider.setRange (0.0, 1.0, 0.01);
    volumeSlider.setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 20);
    volumeSlider.setValue(0.5);
    volumeSlider.addListener (this);
    addAndMakeVisible (volumeSlider);

    setSize (500, 450);
}

CatFuzzAudioProcessorEditor::~CatFuzzAudioProcessorEditor()
{
}

void CatFuzzAudioProcessorEditor::paint (juce::Graphics& g)
{
    // FONDO
    g.fillAll (juce::Colour(0xff2d2d2d));
    
    // MARCO
    g.setColour (juce::Colours::darkgrey);
    g.fillRoundedRectangle(5, 5, getWidth()-10, getHeight()-10, 10);
    
    g.setColour (juce::Colour(0xff1a1a1a));
    g.fillRoundedRectangle(8, 8, getWidth()-16, getHeight()-16, 8);

    // TÍTULO
    g.setColour (juce::Colours::orange);
    g.setFont (juce::Font (28.0f, juce::Font::bold));
    g.drawText ("CAT FUZZ", 0, 20, getWidth(), 40, juce::Justification::centred);

    // DIBUJAR GATO COMPLETO
    float fuzzValue = audioProcessor.fuzzAmount;
    int centerX = getWidth() / 2;
    int catY = 80;
    int catSize = 100;
    
    // Color del gato según fuzz
    juce::Colour catColor;
    if (fuzzValue < 0.3f)
        catColor = juce::Colours::lightgrey;
    else if (fuzzValue < 0.7f)
        catColor = juce::Colours::orange;
    else
        catColor = juce::Colours::red;

    // CUERPO DEL GATO (cara)
    g.setColour (catColor);
    g.fillEllipse (centerX - catSize/2, catY, catSize, catSize);

    // OREJAS DEL GATO
    g.fillEllipse (centerX - 55, catY - 15, 30, 40);
    g.fillEllipse (centerX + 25, catY - 15, 30, 40);
    
    // Interior de las orejas
    g.setColour (juce::Colours::pink);
    g.fillEllipse (centerX - 50, catY - 5, 20, 25);
    g.fillEllipse (centerX + 30, catY - 5, 20, 25);

    // OJOS
    g.setColour (juce::Colours::black);
    float eyeSize = 12 + fuzzValue * 8;
    
    if (fuzzValue > 0.7f) {
        g.fillEllipse (centerX - 30, catY + 25, eyeSize, eyeSize * 1.5f);
        g.fillEllipse (centerX + 18, catY + 25, eyeSize, eyeSize * 1.5f);
    } else {
        g.fillEllipse (centerX - 30, catY + 25, eyeSize, eyeSize);
        g.fillEllipse (centerX + 18, catY + 25, eyeSize, eyeSize);
    }

    // PUPILAS
    g.setColour (juce::Colours::yellow);
    g.fillEllipse (centerX - 28, catY + 27, eyeSize/2, eyeSize/2);
    g.fillEllipse (centerX + 20, catY + 27, eyeSize/2, eyeSize/2);

    // NARIZ
    g.setColour (juce::Colours::pink);
    g.fillEllipse (centerX - 5, catY + 45, 10, 8);

    // BIGOTES
    g.setColour (juce::Colours::white);
    float whiskerLength = 25 + fuzzValue * 15;
    
    // Bigotes izquierdos
    g.drawLine(centerX - 45, catY + 50, centerX - 45 - whiskerLength, catY + 45, 1.5f);
    g.drawLine(centerX - 45, catY + 55, centerX - 45 - whiskerLength, catY + 55, 1.5f);
    g.drawLine(centerX - 45, catY + 60, centerX - 45 - whiskerLength, catY + 65, 1.5f);
    
    // Bigotes derechos
    g.drawLine(centerX + 45, catY + 50, centerX + 45 + whiskerLength, catY + 45, 1.5f);
    g.drawLine(centerX + 45, catY + 55, centerX + 45 + whiskerLength, catY + 55, 1.5f);
    g.drawLine(centerX + 45, catY + 60, centerX + 45 + whiskerLength, catY + 65, 1.5f);

    // BOCA
    g.setColour (juce::Colours::black);
    if (fuzzValue < 0.3f) {
        g.drawLine(centerX - 15, catY + 65, centerX, catY + 70, 2.0f);
        g.drawLine(centerX, catY + 70, centerX + 15, catY + 65, 2.0f);
    } else if (fuzzValue < 0.7f) {
        g.drawLine(centerX - 15, catY + 68, centerX + 15, catY + 68, 2.0f);
    } else {
        g.drawLine(centerX - 20, catY + 75, centerX - 10, catY + 70, 3.0f);
        g.drawLine(centerX - 10, catY + 70, centerX, catY + 75, 3.0f);
        g.drawLine(centerX, catY + 75, centerX + 10, catY + 70, 3.0f);
        g.drawLine(centerX + 10, catY + 70, centerX + 20, catY + 75, 3.0f);
        
        g.setColour (juce::Colours::white);
        g.fillRect(centerX - 8, catY + 70, 4, 5);
        g.fillRect(centerX + 4, catY + 70, 4, 5);
    }

    // ETIQUETAS DE LOS KNOBS - SOLO UNA VEZ
    g.setColour (juce::Colours::orange);
    g.setFont (juce::Font (16.0f, juce::Font::bold));
    g.drawText ("FUZZ", 50, 170, 100, 20, juce::Justification::centred);
    g.drawText ("TONE", 200, 200, 100, 20, juce::Justification::centred);  // BAJADO
    g.drawText ("VOL", 350, 170, 100, 20, juce::Justification::centred);

    // CRÉDITO
    g.setColour (juce::Colours::grey);
    g.setFont (juce::Font (14.0f, juce::Font::italic));
    g.drawText ("by David Signals", getWidth() - 150, getHeight() - 30, 140, 20, juce::Justification::bottomRight);
}

void CatFuzzAudioProcessorEditor::resized()
{
    // POSICIONES CORREGIDAS - Tone bajado
    fuzzSlider.setBounds (50, 190, 100, 120);
    toneSlider.setBounds (200, 220, 100, 120);  // BAJADO 30px
    volumeSlider.setBounds (350, 190, 100, 120);
}

void CatFuzzAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &fuzzSlider)
    {
        audioProcessor.fuzzAmount = (float) fuzzSlider.getValue();
    }
    else if (slider == &toneSlider)
    {
        audioProcessor.toneAmount = (float) toneSlider.getValue();
    }
    else if (slider == &volumeSlider)
    {
        audioProcessor.volumeAmount = (float) volumeSlider.getValue();
    }
    
    repaint();
}