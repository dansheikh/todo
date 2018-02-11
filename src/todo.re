type item = {
  id: int,
  title: string,
  completed: bool
};

module LineItem = {
  let component = ReasonReact.statelessComponent("LineItem");
  let make = (~item, ~onToggle, _children) => {
    ...component,
    render: _self =>
      <div className="item">
        <input
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean(item.completed))
          onClick=(_evt => onToggle())
        />
        (ReasonReact.stringToElement(item.title))
      </div>
  };
};

type state = {
  items: list(item),
  stateId: ref(int)
};

let newItem = (state, text) => {
  state.stateId := state.stateId^ + 1;
  {id: state.stateId^, title: text, completed: false};
};

let toggleItem = (items, id) =>
  List.map(
    item => item.id === id ? {...item, completed: ! item.completed} : item,
    items
  );

type action =
  | AddItem(string)
  | ToggleItem(int);

let component = ReasonReact.reducerComponent("Todo");

let make = _children => {
  ...component,
  initialState: () => {items: [], stateId: ref(0)},
  reducer: (action, state) =>
    switch action {
    | AddItem(text) =>
      ReasonReact.Update({
        ...state,
        items: [newItem(state, text), ...state.items]
      })
    | ToggleItem(id) =>
      ReasonReact.Update({...state, items: toggleItem(state.items, id)})
    },
  render: self => {
    let items = self.state.items;
    let numItems = List.length(items);
    <div className="app">
      <div className="title"> (ReasonReact.stringToElement("Todos")) </div>
      <input id="todo-item" key="todo-item" />
      <button
        onClick=(
          _evt =>
            switch (ReactDOMRe._getElementById("todo-item")) {
            | Some(dom) =>
              self.send(AddItem(ReactDOMRe.domElementToObj(dom)##value))
            | _ => ()
            }
        )>
        (ReasonReact.stringToElement("Add"))
      </button>
      <div className="items">
        (
          ReasonReact.arrayToElement(
            Array.of_list(
              List.map(
                item =>
                  <LineItem
                    key=(string_of_int(item.id))
                    onToggle=(_evt => self.send(ToggleItem(item.id)))
                    item
                  />,
                items
              )
            )
          )
        )
      </div>
      <div className="footer">
        (ReasonReact.stringToElement(string_of_int(numItems) ++ " items"))
      </div>
    </div>;
  }
};
