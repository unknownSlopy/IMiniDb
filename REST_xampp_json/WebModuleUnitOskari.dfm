object WebModule1: TWebModule1
  Actions = <
    item
      Default = True
      Name = 'DefaultHandler'
      PathInfo = '/'
      OnAction = WebModule1DefaultHandlerAction
    end
    item
      MethodType = mtGet
      Name = 'GetNominationsByYearAction'
      PathInfo = '/oscars/nominations'
      OnAction = GetNominationsByYearAction
    end
    item
      MethodType = mtGet
      Name = 'GetWinnersByYearAction'
      PathInfo = '/oscars/winners'
      OnAction = GetWinnersByYearAction
    end>
  Height = 288
  Width = 519
  PixelsPerInch = 120
end
