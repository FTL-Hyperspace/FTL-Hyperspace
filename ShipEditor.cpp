#include "ShipEditor.h"
#include "freetype.h"

ShipEditor ShipEditor::instance = ShipEditor();

/*
HOOK_METHOD_PRIORITY(ShipBuilder, OnRender, -1000, () -> void)
{
    ShipEditor *editor = ShipEditor::GetInstance();

    if (editor->enabled)
    {
        bool renderAchievements = currentShipId < 100;

        if (shipSelect.bOpen)
        {
            GL_Color tint(0.25f, 0.25f, 0.25f, 1.f);
            CSurface::GL_SetColorTint(tint);
        }

        CSurface::GL_DisableBlend();
        CSurface::GL_RenderPrimitive(baseImage);

        CSurface::GL_EnableBlend();
        CSurface::GL_RenderPrimitive(shipEquipBox);
        CSurface::GL_RenderPrimitive(shipSelectBox);

        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        TextLibrary* lib = G_->GetTextLibrary();

        std::string langTxt;
        TextLibrary::GetText(langTxt, lib, "hangar_frame_ship", lib->currentLanguage);
        freetype::easy_print(62, 19, 117, langTxt);

        TextLibrary::GetText(langTxt, lib, "hangar_frame_layout", lib->currentLanguage);
        freetype::easy_print(62, 19, 219, langTxt);

        TextLibrary::GetText(langTxt, lib, "hangar_frame_crew", lib->currentLanguage);
        freetype::easy_print(62, 19, 489, langTxt);

        TextLibrary::GetText(langTxt, lib, "equipment_frame_weapons", lib->currentLanguage);
        freetype::easy_print(62, 388, 489, langTxt);

        TextLibrary::GetText(langTxt, lib, "equipment_frame_drones", lib->currentLanguage);
        freetype::easy_print(62, 388, 599, langTxt);

        TextLibrary::GetText(langTxt, lib, "equipment_frame_augments", lib->currentLanguage);
        freetype::easy_print(62, 954, 489, langTxt);

        CSurface::GL_SetColor(COLOR_BUTTON_ON);



        CSurface::GL_SetColor(1.f, 1.f, 1.f, 1.f);
        CSurface::GL_PushMatrix();

        CSurface::GL_Translate(currentShip->ship.horizontal_shift + 365.f, currentShip->ship.vertical_shift + 30.f);
        currentShip->OnRender(true, false);

        CSurface::GL_PopMatrix();
        CSurface::GL_RenderPrimitive(startButtonBox);
        if (!Settings::GetDlcEnabled() && (currentShipId == 9 || currentType == 2))
        {
            CSurface::GL_RemoveColorTint();
            CSurface::GL_RenderPrimitive(enableAdvancedPrimitive);
        }


        startButton.SetActive(currentShipId != 9 || currentShipId != 2);

        for (auto &anim: animations)
        {
            anim.OnRender(1.f, COLOR_WHITE, false);
        }

        walkingMan.OnRender(1.f, COLOR_WHITE, false);

        CSurface::GL_RenderPrimitive(nameBoxPrimitive);

        for (auto &box: vEquipmentBoxes)
        {
            if (box->CanDoJob())
            {
                if (bCustomizingCrew)
                {
                    if (!box->CanHoldCrew())
                    {
                        box->OnRender(false);
                        box->RenderLabels(false);
                    }
                }
                else
                {
                    box->OnRender(false);
                    box->RenderLabels(false);
                }
            }

        }

        for (auto &box: vCrewBoxes)
        {
            if (box->bCustomizing)
            {
                box->OnRender(false);
                break;
            }
        }

        for (auto &button: buttons)
        {
            button->OnRender();
        }

        for (auto &sys: sysBoxes)
        {
            sys->OnRender(true);
        }


        CSurface::GL_SetColor(COLOR_WHITE);

        Point shipNamePos = Point(273, 7);
        nameInput.OnRender(24, shipNamePos);

        // FIXED WTIH freetype_hack

        // This doesn't work because of easy_measurePrintLines returning a Pointf
        // Need a way to get the y value of the returned Pointf
        // The Pointf is returned split into eax and edx

        // FIXED WITH freetype_hack
        if (bRenaming)
        {
            std::string txt;
            TextLibrary::GetText(txt, lib, "rename", lib->currentLanguage);
            Pointf ret = freetype_hack::easy_measurePrintLines(12, 0, 0, 999, txt);
            float x = 6.f;
            float x2 = 227.f - ret.x / 2;
            if (x2 > 5)
                x = x2;
            freetype::easy_print(12, x, 65.f, txt);
        }

        if (!currentShip->HasSystem(3))
        {
            std::string txt;

            TextLibrary::GetText(txt, lib, "equipment_no_system", lib->currentLanguage);
            freetype::easy_printCenter(63, 662, 539, txt);
        }
        if (!currentShip->HasSystem(4))
        {
            std::string txt;

            TextLibrary::GetText(txt, lib, "equipment_no_system", lib->currentLanguage);
            freetype::easy_printCenter(63, 662, 649, txt);
        }

        CSurface::GL_SetColor(COLOR_WHITE);


        CSurface::GL_RemoveColorTint();
        if (shipSelect.bOpen)
        {
            shipSelect.OnRender();
        }
        else
        {
            infoBox.OnRender();
        }

        introScreen.OnRender();

    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(ShipBuilder, OnLoop, -1000, () -> void)
{
    ShipEditor *editor = ShipEditor::GetInstance();

    if (editor->enabled)
    {
        super();
    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(ShipBuilder, MouseMove, -1000, () -> void)
{
    ShipEditor *editor = ShipEditor::GetInstance();

    printf("%d\n", editor->enabled);

    if (editor->enabled)
    {

    }
    else
    {
        super();
    }
}

HOOK_METHOD_PRIORITY(ShipBuilder, MouseClick, -1000, () -> void)
{
    ShipEditor *editor = ShipEditor::GetInstance();

    printf("%d\n", editor->enabled);

    if (editor->enabled)
    {

    }
    else
    {
        super();
    }
}

HOOK_METHOD(ShipBuilder, SwitchShip, (int shipType, int shipVariant) -> void)
{
    super(shipType, shipVariant);

    nameInput.SetText(currentShip->myBlueprint.blueprintName);
}
*/
