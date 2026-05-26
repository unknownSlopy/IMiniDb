object WebModule1: TWebModule1
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end
    item
      Name = 'suma'
      PathInfo = '/suma'
      OnAction = WebModule1sumaAction
    end>
  Height = 288
  Width = 519
  PixelsPerInch = 120
end
