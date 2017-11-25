<template>    
    <div class="row">
        <div class="col-md-4 col-md-offset-4">
            <div class="input-group">
                <input id="todo-input" ref="todo-input" type="text" class="form-control" placeholder="New Task" v-on:keyup.enter="emitTask" />
                <span class="input-group-btn">
                    <button class="btn btn-secondary btn-success" type="button"  v-on:click="emitTask">Add</button>
                </span>
            </div>
        </div>
    </div>
</template>

<script>
export default {
  name: "task",
  methods: {
      emitTask: function (evt) {
          let newTask = this.$refs["todo-input"].value;    

          if (newTask) {
              this.$emit("add-task", newTask);
              this.$refs["todo-input"].value = null;
          }      
      }
  }
}
</script>
