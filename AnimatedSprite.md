# Introduction #

This page will try to define what we should push in the class `AnimatedSprite`.


# Details #

I think we should use this interface :

```
class AnimatedSprite : sf::Sprite
{
  private: 
    // ?

  public:
    AnimatedSprite(std::string const & ImageFileName, int NbRows, int NbCols, float FramesPerSecond);

    int GetNbRows();
    int GetNbCols();

    void Update();

    void SetRow(int Row);

    int GetRow() const;
    int GetSprite() const;
};
```

`Constructor` :
  * `ImageFileName` : the file name the image to load (via `ImageManager`)
  * `NbRows` : the number of rows the file contains
  * `NbCols` : The number of columns the file contains
  * `FramesPerSecond` : the number of frames per second.

`Update` :
  * Updates the sprite so it goes to the next frame (or the first if the actual one is the last) of the row if needed.

`SetRow` :
  * Row in the range `[0 .. NbRows-1]`

I think it is enough.

Then, other classes which models an animated sprite will overload it and may redefine `Update`, but it must call `AnimatedSprite::Update()` in it. They could also inherit privately and then redefine `Update` publicly, and call themselves the functions provided by `AnimatedSprite`.

# Commentaries from members #

In fact, the concept is to make a tileset composed of lines and columns :

| Img1 | Img2 | Img3 |
|:-----|:-----|:-----|
| Img4 | Img5 | Img6 |
| Img7 | Img7 | Img7 |
| Img8 | Img9 | Img8 |

Here, the three rows are composed of three columns each. Each call to `Update` will go further in the images :
```
AnimatedSprite Spr("Images/TileSet.png", 4, 3);
Spr.SetRow(2); // Goes to the second line
while(App.IsOpened())
{
  // ...
  if(/* Key == KEY_TOP */)
    Spr.SetRow(Spr.GetRow() - 1 < 0 ? Spr.GetNbRows() - 1 : Spr.GetRow() - 1);
  else if(/* Key == KEY_BOTTOM */)
    Spr.SetRow(Spr.GetRow() + 1 >= Spr.GetNbRows() ? 0 : Spr.GetRow() + 1);

  Spr.Update();
  App.Clear();
  App.Draw(Background);
  App.Draw(Spr);
  App.Display();
}
```
Each `Update` call will test if the sprite must be changed in its row. The calls to `SetRow` chooses the row to display : each row models an animation.


---


In order to make the creation of `AnimatedSprite` easier, a file could be used. It should contain informations about:
  * Name of the sprite
  * Path to the image file containing the spritesheet
  * Names of the animations and respective frame counts (`NbRows` and `NbCols` could be extrapolated from that. More informations could be added, which would be ignored by the `AnimatedSprite` class, but would be useful to its descending classes (monster behaviour, walking/running speed, ...)
To make these files more human-friendly, a very simple syntax should be used.

Example:
```
RedKoopa
file: images/red_koopa.png
animation: walking 4
animation: flying 4
animation: shell 2   // 3 Rows, 4 Colums (max frame count = 4)
```

Alternatively, this file could also be written in XML if we want to look more "professional" ^^ :
```
<sprite name="RedKoopa">
    <image file="images/red_koopa.png"/>
    <animations>
        <animation name="walking" duration="4"/>
        <animation name="flying" duration="4"/>
        <animation name="shell" duration="2"/>
    </animations>
</sprite>
```

Also, `AnimatedSprite` would have a `SetAnimation(string)` method (replacing `SetRow`). Perhaps we should require all sprites to have a "standing" animation which would be used as a default animation when no other is selected or when the user requests an animation which wasn't defined.


---


That's a very good idea ! You put it on the main page ?
Personnaly, I would prefer the XML version : more extensible !