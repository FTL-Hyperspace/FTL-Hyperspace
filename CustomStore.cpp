#include "CustomStore.h"

CustomStore* CustomStore::instance = new CustomStore();

void CustomStore::ParseStoreNode(rapidxml::xml_node<char>* node)
{
    for (auto storeNode = node->first_node(); storeNode; storeNode = storeNode->next_sibling())
    {
        std::string nodeName = storeNode->name();

        if (nodeName == "freeDrones")
        {
            for (auto droneNode = storeNode->first_node(); droneNode; droneNode = droneNode->next_sibling())
            {
                freeDrones.push_back(droneNode->name());
            }
        }
    }
}

HOOK_METHOD(SystemStoreBox, constructor, (ShipManager *shopper, Equipment *equip, int sys) -> void)
{
    super(shopper, equip, sys);

    if (itemId != 4)
    {
        return;
    }

    if (CustomStore::instance->freeDrones.size() <= 0)
        return;

    auto bp = G_->GetBlueprints()->GetDroneBlueprint(freeBlueprint);

    int oldPrice = bp->desc.cost / 2;

    DroneBlueprint *newBlueprint = G_->GetBlueprints()->GetDroneBlueprint(CustomStore::instance->freeDrones[random32() % CustomStore::instance->freeDrones.size()]);
    freeBlueprint = newBlueprint->name;

    desc.cost -= oldPrice;
    desc.cost += newBlueprint->desc.cost / 2;

}



HOOK_METHOD(Store, OnRender, () -> void)
{
    //return super();

    CSurface::GL_PushMatrix();
    if (confirmBuy)
    {
        CSurface::GL_SetColorTint(COLOR_TINT);
    }

    CSurface::GL_Translate(position.x, position.y);


    CSurface::GL_BlitPixelImage(box, 0, 0, box->width_, box->height_, 0, COLOR_WHITE, false);
    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    DrawBuySellTabText();
    freetype::easy_print(62, 18.f, 45.f, G_->GetTextLibrary()->GetText("store_title_items"));
    freetype::easy_print(62, 18.f, 254.f, G_->GetTextLibrary()->GetText("store_title_repair"));

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    std::string currentHullText = G_->GetTextLibrary()->GetText("store_current_hull");

    float currentHullY = 419.f;

    if (currentHullText.find('\n') == std::string::npos)
    {
        currentHullY = 427.f;
    }

    freetype::easy_printCenter(59, 73.f, currentHullY, currentHullText);

    CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

    int headingIndex = bShowPage2 ? 2 : 0;

    Point pos1 = Point(198, 42);
    freetype::easy_print(62, pos1.x + 7, pos1.y + 3, headingTitle[headingIndex].GetText());

    int heading2Index = bShowPage2 ? 3 : 1;

    Point pos2 = Point(198, 251);
    freetype::easy_print(62, pos2.x + 7, pos2.y + 3, headingTitle[heading2Index].GetText());

    CSurface::GL_PopMatrix();

    if (sectionCount > 2)
    {
        Pointf pos3 = Pointf(currentButton->position.x, currentButton->position.y + 7);

        currentButton->OnRender();
        CSurface::GL_SetColor(COLOR_BUTTON_TEXT);

        freetype::easy_printCenter(62, pos3.x + 65, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page1"));
        freetype::easy_printCenter(62, pos3.x + 171, pos3.y, G_->GetTextLibrary()->GetText("store_tab_page2"));
    }

    if (bShowPage2)
    {
        for (int i = 6; i < sectionCount * 3; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    // appears to be for items/repair, but it's weird??
    if (3 * sectionCount + 5 > 3 * sectionCount)
    {
        for (int i = 3 * sectionCount; i < 3 * sectionCount + 5; i++)
        {
            vStoreBoxes[i]->OnRender();
        }
    }

    CSurface::GL_SetColor(COLOR_BUTTON_ON);

    char buffer[64];
    sprintf(buffer, "%d", shopper->ship.hullIntegrity.first);
    freetype::easy_print(0, position.x + 143, position.y + 432, buffer);
    infoBox.OnRender();
    if (confirmBuy)
    {
        CSurface::GL_RemoveColorTint();
        confirmDialog.OnRender();
    }
}















